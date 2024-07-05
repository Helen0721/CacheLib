#include "cachelib/allocator/CacheAllocator.h"
#include "cachelib/allocator/LruTailAgeStrategy.h"
#include "cachelib/allocator/MarginalHitsStrategy.h"
#include "cachelib/allocator/FreeMemStrategy.h"
#include "cachelib/allocator/HitsPerSlabStrategy.h"
#include "cachelib/allocator/PoolRebalancer.h"
#include "cachelib/common/TestUtils.h"
#include "folly/init/Init.h"
#include <cstdlib>
#include <string.h>
#include <iostream>
#include "Reader/BinaryReader.h"
#include "Reader/ZstdReader.h"
#include "Simulator.h"
#include "parseRebParams.h"

namespace facebook {
namespace cachelib_examples {

using Cache = cachelib::SieveAllocator; // LruAllocator, Lru2QAllocator, TinyLFUAllocator, or SieveAllocator
using CacheConfig = typename Cache::Config;
using CacheKey = typename Cache::Key;
using CacheReadHandle = typename Cache::ReadHandle;
size_t value_all_size = (size_t)10 * (size_t)1024 * (size_t)1024 * (size_t)1024;
//char* value_all = (char *) malloc(value_all_size);
std::string prefix = "EmptyFiller";
// Global cache object and a default cache pool
std::unique_ptr<Cache> gCache_;
cachelib::PoolId defaultPool_;

		
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

  std::cout << "Initializing Cache..." << std::flush;

  if (size == 0) exit(1);	
  CacheConfig cache_config;
  cache_config
      .setCacheSize(size)
      .setCacheName("My Use Case")
      .setAccessConfig(
          {25 /* bucket power */, 10 /* lock power */}) // assuming caching 20
                                                        // million items
      .configureChainedItems()
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

  std::cout<< "Cache Initialized. size: "<< cache_size << std::endl << std::flush;
  
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


void simulate_binary(char *cache_size,char *rebalanceStrategy, char* rebParams, bin_reader_t *reader,int max_reqs, int sleep_sec){

	using namespace facebook::cachelib_examples;
	
	initializeCache(cache_size, rebalanceStrategy, rebParams);
	int num_reqs = 0;
	int num_hits = 0;
	size_t obj_size = 1000;
	int num_zero_len_reqs = 0;

	bin_request *req = (bin_request*) malloc(sizeof(bin_request));
	uint32_t start_time = -1;
        std::cout << "parsed file size: " << reader->file_size << ", parsed num reqs:" << reader->total_num_requests << std::endl;

	while((char *)reader->file_offset < (char *)reader->mapped_file + reader->file_size){
		read_one_binary_request(reader, req);
		std::string key = std::to_string(req->obj_id);
		
		if (req->obj_size == 0) {
			num_zero_len_reqs += 1;
			continue;
		}

		num_reqs += 1;
		//print_one_binary_request(req);
		
		auto handle = get(key);
		if (handle) num_hits += 1;
		else {
			
			if (!put(key,prefix,req->obj_size)) {std::cout<<"alloc failed. "; print_one_binary_request(req);}
		}
		if (start_time == -1) start_time = req->timestamp;

		if (num_reqs % 1000000 == 0 && (req->timestamp - start_time !=0)){
			if (sleep_sec > 0) {
				std::cout << "sleeping...";
				sleep(sleep_sec);
			}
			float hit_ratio = ((float)num_hits) / ((float)reader->total_num_requests);
			std::cout<<"hit ratio:"<< hit_ratio <<",time:"<<(req->timestamp - start_time) <<std::endl;
		}
		
		if (max_reqs!=0 && num_reqs > max_reqs) break;
		
	}
	
	double throughput = (req->timestamp-start_time==0)? 0 : (double) reader->total_num_requests / (req->timestamp - start_time);
	float hit_ratio = ((float)num_hits) / ((float)reader->total_num_requests);
	
	std::cout <<"num_requests: "<< num_reqs << ", num zero reqs: "<<num_zero_len_reqs << std::endl;
	std::cout <<"hit ratio:"<< hit_ratio <<",throughput:"<<throughput <<"reqs/sec,"<<std::endl;

	free(req);
	free(reader);
}

void simulate_zstd(char* cache_size,char* rebalanceStrategy,char* rebParams, zstd_reader *reader,int max_reqs, int sleep_sec){
	using namespace facebook::cachelib_examples;
	
	initializeCache(cache_size, rebalanceStrategy, rebParams);
	int num_hits = 0;
	int num_reqs = 0;
	int num_zero_len_reqs = 0;
	zstd_request *req = (zstd_request *)malloc(sizeof(zstd_request));
	char *record = (char *)malloc(1024 * 1024 * 16);
	
	uint32_t start_time = -1;	

	while(true){
		size_t n = zstd_reader_read_bytes(reader, 24, &record);

		if (reader->status == MY_EOF) {std::cout<<"EOF"<<std::endl; break;}
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

		if (start_time == -1) start_time = req->clock_time;
		
		
		char id_buf[50];
		memset(id_buf, 0, 50);
		sprintf(id_buf,"%lu",req->obj_id);
		std::string str(id_buf);
		std::string key = str; 				

		auto handle = get(key);
		if (handle){
			num_hits += 1;
		}
		else {
			if (req->obj_size >= value_all_size) {
				std::cout << "value_all size too small. "<< req->obj_size << std::flush;
				continue;
			}
			//std::string prefix(value_all,req->obj_size);
			if (!put(key,prefix, req->obj_size)) {std::cout<<"alloc failed. "; print_one_zstd_request(req);}
		}
		
		num_reqs += 1;
		if (max_reqs!=0 && num_reqs >= max_reqs) break;
		
		if (num_reqs % 1000000 == 0 && (req->clock_time - start_time !=0) ){
			if (sleep_sec > 0) {
				std::cout << "sleeping..." << std::endl;
				sleep(sleep_sec);
			}
			float hit_ratio = ((float)num_hits) / ((float)num_reqs);
			std::cout<<"hit ratio:"<< hit_ratio <<",time:"<<(req->clock_time - start_time) <<std::endl;
		}
		
	}
	
	double throughput = (req->clock_time - start_time==0)? 0 : (double) num_reqs / (double)(req->clock_time - start_time);
	float hit_ratio = ((float)num_hits) / ((float)num_reqs);
	
	std::cout <<"num_requests: "<< num_reqs << ", num zero reqs: "<<num_zero_len_reqs<< ",time:"<< (req->clock_time-start_time)<< std::endl;	
	std::cout <<"num_requests:"<<num_reqs <<",throughput:"<<throughput <<"reqs/sec,"<<std::endl;

	free(req);
	free(reader); 
	free(record);
}



