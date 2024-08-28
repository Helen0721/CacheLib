#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <iostream>
#include <regex>
#include <atomic>
#include <memory>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <future>

#include "cachelib/allocator/CacheAllocator.h"
#include "cachelib/allocator/LruTailAgeStrategy.h"
#include "cachelib/allocator/MarginalHitsStrategy.h"
#include "cachelib/allocator/FreeMemStrategy.h"
#include "cachelib/allocator/HitsPerSlabStrategy.h"
#include "cachelib/allocator/PoolRebalancer.h"
#include "cachelib/common/TestUtils.h"
#include "folly/init/Init.h"

#include "Reader/BinaryReader.h"
#include "Reader/ZstdReader.h"
#include "Simulator.h"
#include "parseRebParams.h"

namespace facebook {
namespace cachelib_examples {

using Cache = cachelib::Lru2QAllocator; // LruAllocator, Lru2QAllocator, TinyLFUAllocator, or SieveAllocator
using CacheConfig = typename Cache::Config;
using CacheKey = typename Cache::Key;
using CacheReadHandle = typename Cache::ReadHandle;
using PoolStats = cachelib::PoolStats;
using GlobalCacheStats = cachelib::GlobalCacheStats;
using CacheMemoryStats = cachelib::CacheMemoryStats;


// Global cache object and a default cache pool
std::unique_ptr<Cache> gCache_;
cachelib::PoolId defaultPool_;

size_t value_all_size = (size_t)10 * (size_t)1024 * (size_t)1024 * (size_t)1024;
std::string prefix = "EmptyFiller";
uint32_t uniform_obj_size = 100000;

void saveCacheStats(char* cacheStats_path_, bool clear_file, double timestamp, int num_reqs_so_far){
	if (!cacheStats_path_) return;

	const char* cacheStats_path = cacheStats_path_;
	int old_stdout;
        if((old_stdout = dup(STDOUT_FILENO)) < 0){
	       	perror("dup error");
		exit(errno);
	}
	int f1;
	int mode_flag = 0660;		/*-rw-r-----*/
	
	int open_flag;
	if (clear_file) {
		std::cout << "Openning " << cacheStats_path << " with O_TRUNC flag" <<std::endl;
		open_flag = O_CREAT|O_RDWR|O_TRUNC;
	}
	else {
		std::cout << "Openning " << cacheStats_path << " with O_APPEND flag" <<std::endl;
		open_flag = O_CREAT|O_RDWR|O_APPEND;
	}


        if( (f1 = open(cacheStats_path,open_flag,mode_flag)) < 0){
		perror("open error");
		exit(errno);
	}
	
	

	int d1;
	//int dup2(int oldfd, int newfd);
	//The file descriptor newfd refers to the same open file description as oldfd.	
	if ( (d1 = dup2(f1,STDOUT_FILENO)) < 0){
		perror("dup2 error in changing stdout");
		exit(errno);
	}

	std::cout << "time: " << timestamp << "num_reqs: " << num_reqs_so_far  << std::endl;

	PoolStats pool_stats = gCache_->getPoolStats(defaultPool_);
	auto cacheStats = pool_stats.cacheStats;
	auto classIds = pool_stats.getClassIds();
	auto numClasses = classIds.size();
	
	GlobalCacheStats global_stats = gCache_->getGlobalCacheStats();
	
	/*Try before and after amplification, the distribution of these numbers. */
	/*Compare with libCacheSim. Find one that lru has similiar miss ratios. uniform obj size and no slab rebalancing. Also try obj size */

	std::cout << "Evict Fails---AC: " << global_stats.numEvictionFailureFromAccessContainer; 
  	std::cout << ", Prnt AC: " << global_stats.numEvictionFailureFromParentAccessContainer;
  
  	std::cout << ", Cncrrnt: " << global_stats.numEvictionFailureFromConcurrentFill;
  	std::cout << ", Prnt Cncrrnt: " << global_stats.numEvictionFailureFromParentAccessContainer;
  
  	std::cout << ", Mv: " << global_stats.numEvictionFailureFromMoving;
  	std::cout << ", Prnt MV: " << global_stats.numEvictionFailureFromParentMoving<< std::endl; 
	
	CacheMemoryStats memory_stats =  gCache_->getCacheMemoryStats();
	
	std::cout << "configuredRamCacheSize: " << memory_stats.configuredRamCacheSize << std::endl;

	for (auto cid : classIds){
		auto class_stats = cacheStats.at(cid);
		uint32_t class_size = class_stats.allocSize;
		uint64_t total_alloc_attemtps = class_stats.allocAttempts;
		uint64_t total_evict_attempts = class_stats.evictionAttempts;
		uint64_t total_numHits = class_stats.numHits;
  		uint64_t total_allocFailures =class_stats.allocFailures;
		if (total_alloc_attemtps > 0){
			std::cout << "class alloc size: " << class_size << ", ";
			std::cout << "total_alloc_attemtps: " << total_alloc_attemtps << ", ";
			std::cout << "total_evict_attempts: " << total_evict_attempts << ", ";
			std::cout << "total_numHits: " << total_numHits << ", ";
			std::cout << "total_allocFailures: " << total_allocFailures << "." << std::endl;
		}
	}
	
	std::cout << "\n" << std::endl << std::flush;

	int d2;
	if ( (d2 = dup2(old_stdout,STDOUT_FILENO)) < 0){
		perror("dup2 error in changing back stdout");
		exit(errno);
	}

	close(f1);
	close(old_stdout);

}

bool matches_CloudPhysics_format(const char *input_) {
    std::string str(input_);
    const std::string input = str;

    // Define the regex pattern
   std::regex pattern(R"(w(8[0-9]|9[0-9]|10[0-6])\.oracleGeneral\.bin\.zst)");

    // Check if the input matches the pattern
    return std::regex_search(input, pattern);
}

/*Since we can't know the total number of requests for zstd traces, 
 * these are pre-caculated total number of reqs * 0.1*/
int32_t get_stop_reb_reqs_threshold(const char* tracePath){
	if (strstr(tracePath, "meta_kvcache_traces_1")!=nullptr) return (uint32_t) 335173084 * 0.1;
	else if (strstr(tracePath, "wiki_2019t.oracleGeneral.zst")!=nullptr) return (uint32_t) 207646002 * 0.1;
	else if (strstr(tracePath, "w06.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 69392150 * 0.1;
	else if (strstr(tracePath, "w80.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 5256246 * 0.1;
	else if (strstr(tracePath, "w81.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 5026619 * 0.1;
	else if (strstr(tracePath, "w82.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 4926610 * 0.1;
	else if (strstr(tracePath, "w83.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3880481 * 0.1;
	else if (strstr(tracePath, "w84.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 4814234 * 0.1;
	else if (strstr(tracePath, "w85.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 4790048 * 0.1;
	else if (strstr(tracePath, "w86.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 4749563 * 0.1;
	else if (strstr(tracePath, "w87.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3788806 * 0.1;
	else if (strstr(tracePath, "w88.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 4711053 * 0.1;
	else if (strstr(tracePath, "w89.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3625918 * 0.1;
	else if (strstr(tracePath, "w90.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 4493515 * 0.1;
	else if (strstr(tracePath, "w91.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 4316605 * 0.1;
	else if (strstr(tracePath, "w92.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 4284658 * 0.1;
	else if (strstr(tracePath, "w93.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3351357 * 0.1;
	else if (strstr(tracePath, "w94.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 4118188 * 0.1;
	else if (strstr(tracePath, "w95.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3937240 * 0.1;
	else if (strstr(tracePath, "w96.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3787344 * 0.1;
	else if (strstr(tracePath, "w97.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3768450 * 0.1;
	else if (strstr(tracePath, "w98.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3664418 * 0.1;
	else if (strstr(tracePath, "w99.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3660840 * 0.1;
	else if (strstr(tracePath, "w100.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3645877 * 0.1;
	else if (strstr(tracePath, "w101.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3587707 * 0.1;
	else if (strstr(tracePath, "w102.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3558215 * 0.1;
	else if (strstr(tracePath, "w103.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3442094 * 0.1;
	else if (strstr(tracePath, "w104.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3395553 * 0.1;
	else if (strstr(tracePath, "w105.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3375344 * 0.1;
	else if (strstr(tracePath, "w106.oracleGeneral.bin.zst")!=nullptr) return (uint32_t) 3275919 * 0.1;
	else std::cout<<"cachesim doesn't know the threshold to disable slab rebalancing for trace " << tracePath << std::endl;
	exit(1);
	return -1;
}


		
unsigned long convertCacheSize(char *cache_size){
  unsigned long base_size = 1024 * 1024; 	// 1MB
				
  int s_len = std::strlen(cache_size);
  
  if (s_len < 3) {
      std::cout << "invalid size: " << cache_size << std::endl;
      return 0;
  }

  int num_len = s_len - 2;
  char numb_s[num_len + 1];
  numb_s[num_len] = '\0';
  strncpy(numb_s, cache_size, num_len);
  unsigned long number = (unsigned long)atoi(numb_s);

  if (std::strcmp(cache_size + s_len - 2, "GB") == 0){
    return base_size * 1024 * number;
  }
  else if (std::strcmp(cache_size + s_len - 2, "MB") == 0){
    return base_size * number;
  }

  
  std::cout << "invalid size: " << cache_size << std::endl;
  return 0;
}

void initializeCache(char* cache_size, char* rebalanceStrategy, char* rebParams) {
  unsigned long size = convertCacheSize(cache_size);  
  


  if (size == 0) exit(1);	
  CacheConfig cache_config;
  cache_config
      .setCacheSize(size)
      .setCacheName("My Use Case")
      .setAccessConfig({29 /* bucket power */, 20 /* lock power */}) // assuming caching 20
                                                        // million items
      .configureChainedItems({22,20},20)
      .validate(); // will throw if bad config 
   
  std::string str(rebalanceStrategy);
  std::string rebalanceStrategy_str = str;

  int interval = 1;

  if (rebalanceStrategy_str == "LruTailAge"){
	printf("LruTailAge Rebalancing init. ");
	auto tailAgeDifferenceRatio = 0.1;
	auto minTailAgeDifference = 100;
  	unsigned int minSlabs = 1;
	auto numSlabsFreeMem = 3;
	auto slabProjectionLength = 1;
	
	parseParams_LruTailAge(rebParams,&interval,
				&tailAgeDifferenceRatio,
			        &minTailAgeDifference,	
				&minSlabs,
				&numSlabsFreeMem, 
				&slabProjectionLength
				);	

  	cachelib::LruTailAgeStrategy::Config cfg(tailAgeDifferenceRatio, minSlabs);
	cfg.minTailAgeDifference = minTailAgeDifference;
	cfg.minSlabs = minSlabs;
	cfg.slabProjectionLength = slabProjectionLength; // dont project or estimate tail age
  	cfg.numSlabsFreeMem = numSlabsFreeMem;     // ok to have ~40 MB free memory in unused allocations

	cache_config.enablePoolRebalancing(
			std::make_shared<cachelib::LruTailAgeStrategy>(cfg),
			std::chrono::seconds(interval)
	);
  }

  else if(rebalanceStrategy_str == "MarginalHits"){ 
	  std::cout << "Marginal Hits Rebalancing init. " << std::flush;
	  
	  double movingAverageParam = 0.3;
	  unsigned int minSlabs = 1;
	  unsigned int maxFreeMemSlabs = 1;

	  parseParams_MarginalHits(rebParams,&interval,
			  &movingAverageParam,
			  &minSlabs,
			  &maxFreeMemSlabs
			  );
	  
	  cachelib::MarginalHitsStrategy::Config mhConfig(movingAverageParam,minSlabs,maxFreeMemSlabs);
 
	  cache_config.enableTailHitsTracking(); 
	  cache_config.enablePoolRebalancing(std::make_shared<cachelib::MarginalHitsStrategy>(mhConfig),
          				std::chrono::seconds{interval}
	  				);
          
  }else if (rebalanceStrategy_str == "HitsPerSlab"){
	  printf("Hits Per Slab Rebalancing init. ");
	  int minDiff = 100;
	  unsigned int minSlabs = 1;
	  double diffRatio = 0.1;
	  int numSlabsFreeMem = 3;
	  int minLruTailAge = 0;
	  int maxLruTailAge = 0;

	  parseParams_HitsPerSlab(rebParams,&interval,
			  &minDiff,
			  &minSlabs,
			  &diffRatio,
			  &numSlabsFreeMem,
			  &minLruTailAge,
			  &maxLruTailAge
			  );  

	  cachelib::HitsPerSlabStrategy::Config hpsConfig(diffRatio,minSlabs,minLruTailAge);
	  hpsConfig.minDiff = minDiff;
	  hpsConfig.numSlabsFreeMem = numSlabsFreeMem;
	  hpsConfig.maxLruTailAge = maxLruTailAge;
	  cache_config.enablePoolRebalancing(
			  std::make_shared<cachelib::HitsPerSlabStrategy>(hpsConfig),
			  std::chrono::seconds{interval}
			  		);
  } else if (rebalanceStrategy_str == "FreeMem"){
	  printf("FreeMem Rebalancing init. ");
	  
	  unsigned int minSlabs = 0;
	  int numSlabsFreeMem = 3;
	  size_t maxUnAllocatedSlabs = 1000;
	  parseParams_FreeMem(rebParams,&interval,
			  &minSlabs,
			  &numSlabsFreeMem,
			  &maxUnAllocatedSlabs
			  );

	  cachelib::FreeMemStrategy::Config fmConfig(minSlabs,numSlabsFreeMem,maxUnAllocatedSlabs);
	  cache_config.enablePoolRebalancing(
			  std::make_shared<cachelib::FreeMemStrategy>(fmConfig),
                          std::chrono::seconds{interval}
			  		);
  }

  gCache_ = std::make_unique<Cache>(cache_config);
  defaultPool_=
      gCache_->addPool("default", gCache_->getCacheMemoryStats().ramCacheSize); 

  printf("Cache Initialized. size: %ld (%s)\n", size,cache_size);
  
  std::cout << "Stoping slab rebalancing..." << std::endl;
  gCache_->stopPoolRebalancer(std::chrono::seconds(0));

}

void destroyCache() { gCache_.reset(); }


CacheReadHandle get(CacheKey key) { return gCache_->find(key); }

bool put_ChainedItem(CacheKey key, const std::string& value, size_t value_size){
  
  size_t chunkSize = 1024 * 1024;
  // For simplicity, we'll split the user data into 1MB chunks
  size_t numChunks = value_size / chunkSize + 1;
 
  size_t parentItemSize = sizeof(size_t); 	
  // for simplicity, assume this fits into 1MB
  assert(parentItemSize < chunkSize);

  auto parentItemHandle =
	gCache_->allocate(defaultPool_, key, parentItemSize);

  if (!parentItemHandle) return false;

  //std::memcpy(parentItemHandle->getMemory(), &numChunks, parentItemSize);
 
  // Now, make parent item visible to others
  gCache_->insertOrReplace(parentItemHandle);

  // char *start = (char *) value.data();
  // char *dataOffset = (char *)value.data();

  // Now split user data into chunks and cache them
  for (size_t i = 0; i < numChunks; ++i) {
	 auto chainedItemHandle = gCache_->allocateChainedItem(parentItemHandle, chunkSize);

  	if (!chainedItemHandle) return false;

	// size_t copy_size = std::min(((size_t)start + value.size()) -  (size_t) dataOffset, (size_t) chunkSize); 

	// Turn off copying efficiency. 
  	// std::memcpy(chainedItemHandle->getMemory(), dataOffset, copy_size);
	// dataOffset += copy_size;
	
  	// Add this chained item to the parent item
  	gCache_->addChainedItem(parentItemHandle, std::move(chainedItemHandle));
  }
  return true;
}

/*CacheKey should be of the type folly::StringPiece */
bool put(CacheKey key, const std::string& value, size_t value_size) {
  if(value_size >= 4000000) return put_ChainedItem(key, value, value_size);
	
  auto handle = gCache_->allocate(defaultPool_, key, value_size);
  if (!handle) {
    return false; // cache may fail to evict due to too many pending writes
  }
  //std::memcpy(handle->getMemory(), value.data(), value.size());
  gCache_->insertOrReplace(handle);
  return true;
}

} // namespace cachelib_examples
} // namespace facebook

void simulate_binary(char *cache_size,char *rebalanceStrategy, char* rebParams, bin_reader_t *reader,size_t max_reqs, int ampF, char *cacheStats_path_){

	using namespace facebook::cachelib_examples;
	
	initializeCache(cache_size, rebalanceStrategy, rebParams);
	size_t num_reqs = 0;
	size_t num_hits = 0;
	size_t num_zero_len_reqs = 0;	

	bin_request *req = (bin_request*) malloc(sizeof(bin_request));	

        std::cout << "parsed file size: " << reader->file_size << ", parsed num reqs:" << reader->total_num_requests << std::endl;
	bool should_trunc_file = true;
		
	bool reb_stopped = false;

	auto start_time = std::chrono::high_resolution_clock::now();

	while((char *)reader->file_offset < (char *)reader->mapped_file + reader->file_size){
			read_one_binary_request(reader, req);		
			uint64_t curr_id = req->obj_id;
		
		/*	
		for (size_t i = 0; i <= ampF; ++i) {
			if (max_reqs!=0 && num_reqs > max_reqs) break;

			size_t curr_id = 0;

			if (i == 0) curr_id = base_id;

			//for all i, make sure that base_id is maller than curr_id = (base_id % 1000000000) + 1000000000*i

			else curr_id = base_id + 1000000000 * i;	
			
		*/
			
			std::string key = std::to_string(curr_id);	
			
			if (req->obj_size == 0) {
				num_zero_len_reqs += 1;
				continue;	
			}	
			
			//print_one_binary_request(req);
		
			auto handle = get(key);
			if (handle) num_hits += 1;
			else {
			
				if (!put(key,prefix,req->obj_size)) {}
				//if (!put(key,prefix,uniform_obj_size)) {}
				//std::cout<<"alloc failed. "; print_one_binary_request(req);}
			}
			if (num_reqs % 100000000 == 0 && num_reqs > 1){
				auto curr_time = std::chrono::high_resolution_clock::now();
   				std::chrono::duration<double> duration = curr_time - start_time;		

				double throughput = (double) num_reqs /(double)(duration.count());
				std::cout << "num_hits: " << num_hits << ", num_reqs: " << num_reqs << std::endl;		
				double hit_ratio = ((double)num_hits) / ((double)num_reqs);
				printf("hit ratio: %f, time: %f, throughput: %f reqs/sec\n",hit_ratio,duration.count(),throughput);
					
			}
			num_reqs += 1;
		//}
		
		if (max_reqs!=0 && num_reqs > max_reqs) break;
	        
		/* 
		if (num_reqs >= stop_reb_reqs_threshold && !reb_stopped) {
			std::cout << "Stoping slab rebalancing..." << std::endl;
			gCache_->stopPoolRebalancer(std::chrono::seconds(0));
			reb_stopped = true;
		}
		*/	
	}		
	
	auto curr_time = std::chrono::high_resolution_clock::now();
   	

	std::cout <<"num_requests: "<< num_reqs << ", num zero reqs: "<<num_zero_len_reqs<< std::endl;
	std::chrono::duration<double> duration = curr_time - start_time;			

	double throughput = (double) num_reqs /(double)(duration.count());		
	float hit_ratio = ((float)num_hits) / ((float)num_reqs);
	printf("hit ratio: %f, time: %f, throughput: %f reqs/sec\n",hit_ratio,duration.count(),throughput);
	
	saveCacheStats(cacheStats_path_,true/*should_trunc_file*/,duration.count(),num_reqs);

	free(req);
	free(reader);
}

void simulate_zstd(char* cache_size,char* rebalanceStrategy,char* rebParams, zstd_reader *reader,size_t max_reqs, int sleep_sec, char* cacheStats_path_){
	using namespace facebook::cachelib_examples;
	
	initializeCache(cache_size, rebalanceStrategy, rebParams);
	size_t num_hits = 0;
	size_t num_reqs = 0;
	size_t num_zero_len_reqs = 0;
	zstd_request *req = (zstd_request *)malloc(sizeof(zstd_request));
	char *record = (char *)malloc(1024 * 1024 * 16);
	
	auto start_time = std::chrono::high_resolution_clock::now();
	
	/*
	bool should_trunc_file = true;			
	int stop_reb_reqs_threshold = get_stop_reb_reqs_threshold(reader->trace_path);
	std::cout << "Reqs threshold to stop slab rebalancing: " << stop_reb_reqs_threshold << std::endl;
	if (stop_reb_reqs_threshold < 0) return;
	bool reb_stopped = false;
	

	int print_mod = 1000000;
	if ((strstr(reader->trace_path, "w06.oracleGeneral.bin.zst")==nullptr) && 
		matches_CloudPhysics_format(reader->trace_path)) {
		print_mod = 10000;
		std::cout << "print_mod is re-adjusted to " << print_mod << std::endl;
	}
	*/

	while(true){
		size_t n = zstd_reader_read_bytes(reader, 24, &record);

		if (reader->status == MY_EOF) {std::cout<<"EOF"<<std::endl;break;}
	        if (reader->status == ERR) {std::cout<<"ERR."<<num_reqs<<std::endl;;break;}
		if (n==0) continue;
		
		req->clock_time = *(uint32_t *)record;
		req->obj_id = *(uint64_t *)(record + sizeof(uint32_t));
		req->obj_size = *(uint32_t *)(record + sizeof(uint32_t) + sizeof(uint64_t));
		req->next_access_vtime = *(int64_t *)(record + sizeof(uint32_t) + sizeof(uint64_t) + sizeof(uint32_t));


		if (req->obj_size == 0) {
			num_zero_len_reqs += 1;
			continue;
		}
		
		std::string key = std::to_string(req->obj_id);

		auto handle = get(key);
		if (handle){
			num_hits += 1;
		}
		else {
			if (req->obj_size >= value_all_size) {
				std::cout << "value_all size too small. "<< req->obj_size << std::flush;
				continue;
			}
			if (!put(key,prefix,req->obj_size)) {}	
			//if (!put(key,prefix,uniform_obj_size)) {}
		}
		num_reqs += 1;
		//print_one_zstd_request(req);
		if (max_reqs!=0 && num_reqs >= max_reqs) break;
		
		/*
		if (num_reqs % print_mod == 0 && num_reqs >= print_mod  ){
			if (sleep_sec > 0) {
				std::cout << "sleeping..." << std::endl;
				sleep(sleep_sec);
			}
			float hit_ratio = ((float)num_hits) / ((float)num_reqs);
			std::cout<<"hit ratio:"<< hit_ratio <<",time:"<<(req->clock_time - start_time) <<std::endl;
			saveCacheStats(cacheStats_path_,should_trunc_file,req->clock_time - start_time,num_reqs);
			if (should_trunc_file) should_trunc_file = false;
		}
		
		if (num_reqs >= stop_reb_reqs_threshold && !reb_stopped) {
			std::cout << "Stoping slab rebalancing..." << std::endl;
			gCache_->stopPoolRebalancer(std::chrono::seconds(0));
			reb_stopped = true;
		}
		*/
	}
	auto end_time = std::chrono::high_resolution_clock::now();

    	// Calculate the duration
    	std::chrono::duration<double> duration = end_time - start_time;	
	
	double throughput = (double) num_reqs / (double)(duration.count());
	float hit_ratio = ((float)num_hits) / ((float)num_reqs);
	
	saveCacheStats(cacheStats_path_,true/*should_trunc_file*/,duration.count(),num_reqs);

	std::cout <<"num_requests: "<< num_reqs << ", num zero reqs: "<<num_zero_len_reqs<< ", time: "<< (duration.count())<< std::endl;	
	std::cout <<"hit ratio: "<< hit_ratio <<", throughput: "<<throughput <<" reqs/sec"<<std::endl;

	
	free(req);
	free(reader); 
}


/*
 * Main thread that reads a request, puts it into a queue, and let other threads fetch from the queue
 * */

struct thread_stats{
	int served_reqs;
	int num_hits;
};

struct Node {
    zstd_request *request;
    Node* next;

    Node(zstd_request *req) : request(req), next(nullptr) {}
};

class ConcurrentQueue {
private:
    Node* head_;
    Node* tail_;
    size_t size_;
    bool all_reqs_added;
    std::mutex mtx;

public:
    ConcurrentQueue() : head_(nullptr), tail_(nullptr),size_(0),all_reqs_added(false){}

    ~ConcurrentQueue() {
        while (head_) {
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
        }
    }
    
    /*Push at tail*/
    void push(zstd_request *req) {
        Node* new_node = new Node(req);

        std::lock_guard<std::mutex> lock(mtx);

        if (!tail_) {
            // Queue is empty
            head_ = new_node;
            tail_ = new_node;
        } else {
            tail_->next = new_node;
            tail_ = new_node;
        }  
	size_++;	
    }

    /*Pop from head*/
   zstd_request* pop() {
        std::lock_guard<std::mutex> lock(mtx);

        if (!head_) {
            // Queue is empty
            return nullptr;
        }

        zstd_request* req = head_->request;
        Node* old_head = head_;
        head_ = head_->next;

        if (!head_) {
            tail_ = nullptr; // If the queue is now empty, reset the tail
        }
	size_--;

        delete old_head; // Free the memory of the old head node
        return req;
    }

    size_t get_size(){
	std::lock_guard<std::mutex> lock(mtx);
	return size_;
    }

    void set_all_reqs_added(){
	std::lock_guard<std::mutex> lock(mtx);
	all_reqs_added = true;
    }

    bool has_added_all_reqs(){
	std::lock_guard<std::mutex> lock(mtx);
	return all_reqs_added;
    }

};

thread_stats *worker(ConcurrentQueue& req_queue){
	using namespace facebook::cachelib_examples;
	
	int num_reqs = 0;
	int num_hits = 0;
	char id_buf[50];
	
	while (true){
		zstd_request* req = req_queue.pop();
		if (!req) {
			if (req_queue.has_added_all_reqs()) {
				req = req_queue.pop();
				if (!req) break;
			}
			else {continue;}
		}
	
		memset(id_buf, 0, 50);
		sprintf(id_buf,"%lu",req->obj_id);
		std::string str(id_buf);
		std::string key = str; 				

		auto handle = get(key);
		if (!handle){
			if (req->obj_size >= value_all_size) {
				std::cout << "value_all size too small. "<< req->obj_size << std::flush;
				continue;
			}
			if (!put(key,prefix,uniform_obj_size)) {std::cout<<"alloc failed. "; print_one_zstd_request(req);}
		} else{
			num_hits += 1;
		}

		num_reqs += 1;	
		free(req);	
	}
	//std::cout << "thread " << std::this_thread::get_id() << " served " << num_reqs << std::endl << std::flush;
	thread_stats *stats = (thread_stats*) malloc(sizeof(thread_stats));
	
	stats->served_reqs = num_reqs;
	stats->num_hits = num_hits;

	return stats;	 
}


void simulate_zstd_con(char* cache_size,char* rebalanceStrategy,char* rebParams, zstd_reader *reader,size_t max_reqs, int num_threads){
	using namespace facebook::cachelib_examples;
	
	initializeCache(cache_size, rebalanceStrategy, rebParams);	
	size_t num_reqs_added = 0;
	size_t num_zero_len_reqs = 0;	
	char *record = (char *)malloc(1024 * 1024 * 16);
	
	bool should_trunc_file = true;	
        
	/*	
	int stop_reb_reqs_threshold = get_stop_reb_reqs_threshold(reader->trace_path);
	std::cout << "Reqs threshold to stop slab rebalancing: " << stop_reb_reqs_threshold << std::endl;
	if (stop_reb_reqs_threshold < 0) return;
	bool reb_stopped = false;
	*/

	size_t print_mod = 1000000;
	if ((strstr(reader->trace_path, "w06.oracleGeneral.bin.zst")==nullptr) && 
		matches_CloudPhysics_format(reader->trace_path)) {
		print_mod = 10000;
		std::cout << "print_mod is re-adjusted to " << print_mod << std::endl;
	}
	
	std::vector<std::future<thread_stats*>> futures;
	std::vector<std::thread> threads;
	ConcurrentQueue req_queue;
        
	auto start_time = std::chrono::high_resolution_clock::now();
	
	while(true){
		size_t n = zstd_reader_read_bytes(reader, 24, &record);

		if (reader->status == MY_EOF) {std::cout<<"EOF"<<std::endl;break;}
	        if (reader->status == ERR) {std::cout<<"ERR."<<num_reqs_added<<std::endl;;break;}
		if (n==0) continue;
		
		zstd_request *req = (zstd_request *)malloc(sizeof(zstd_request));

		req->clock_time = *(uint32_t *)record;
		req->obj_id = *(uint64_t *)(record + sizeof(uint32_t));
		req->obj_size = *(uint32_t *)(record + sizeof(uint32_t) + sizeof(uint64_t));
		req->next_access_vtime = *(int64_t *)(record + sizeof(uint32_t) + sizeof(uint64_t) + sizeof(uint32_t));

		
		if (req->obj_size == 0) {
			num_zero_len_reqs += 1;
			continue;
		}	

		req_queue.push(req);
		num_reqs_added += 1;
		if (max_reqs!=0 && num_reqs_added >= max_reqs) break;

		if (threads.empty() && num_reqs_added > 1000){	
    			for (int i = 0; i < num_threads; ++i) {
        			//threads.emplace_back(worker, std::ref(req_queue));
				std::packaged_task<thread_stats*(ConcurrentQueue&)> task(worker);
        			futures.push_back(task.get_future());
        			threads.emplace_back(std::move(task), std::ref(req_queue));
    			}
		}
		
	}
	
	req_queue.set_all_reqs_added();

	thread_stats *stats_master_thread = worker(std::ref(req_queue));	

	for (auto& t : threads) {
        	t.join();
    	}
	
	auto end_time = std::chrono::high_resolution_clock::now();
    	// Calculate the duration
    	std::chrono::duration<double> duration = end_time - start_time;	
	
	int num_reqs_served = stats_master_thread->served_reqs;
	int num_hits = stats_master_thread->num_hits;
	
	free(stats_master_thread);

	std::cout << "Master thread served " << num_reqs_served << " requests." << std::endl;

	// Retrieve and print results
    	for (int i = 0; i < num_threads; ++i) {
		//int requests_served_by_thread = futures[i].get();
		thread_stats* stats_by_thread = futures[i].get();
		if (stats_by_thread==nullptr) {
			std::cout << "Thread " << (i+1) << " returned null stats" << std::endl;
			return;
		}
        	std::cout << "Thread " << (i+1) << " served " << stats_by_thread->served_reqs << " requests." << std::endl;
		//num_reqs_served += requests_served_by_thread;
		num_reqs_served += stats_by_thread->served_reqs;
		num_hits += stats_by_thread->num_hits;

		free(stats_by_thread);

    	}

	double throughput = (double) num_reqs_served / (double)(duration.count());
	float hit_ratio = ((float)num_hits) / ((float)num_reqs_served);	

	std::cout << "Served " << num_reqs_served << " requests in total. num zero reqs: "<<num_zero_len_reqs<< ",time:"<<(duration.count())<< std::endl;	
	std::cout <<"hit ratio: "<< hit_ratio <<", throughput: "<<throughput <<" reqs/sec,"<<std::endl;
	
	free(reader);			
}



