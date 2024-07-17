#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <iostream>
#include <regex>

#include "cachelib/allocator/CacheAllocator.h"
#include "../Reader/ZstdReader.h"

namespace facebook {
namespace cachelib_examples {

using Cache = cachelib::SieveAllocator; // LruAllocator, Lru2QAllocator, TinyLFUAllocator, or SieveAllocator
using CacheConfig = typename Cache::Config;
using CacheKey = typename Cache::Key;
using CacheReadHandle = typename Cache::ReadHandle;
using PoolStats = cachelib::PoolStats;

// Global cache object and a default cache pool
std::unique_ptr<Cache> gCache_;
cachelib::PoolId defaultPool_;

// uniform object sizes

std::string prefix = "EmptyFiller";
bool use_uniform_obj_size = true;
uint32_t uniform_obj_size = 100000;
unsigned long base_size = (unsigned long)1024 * (unsigned long)1024;


void saveCacheStats(){
	PoolStats pool_stats = gCache_->getPoolStats(defaultPool_);
	auto cacheStats = pool_stats.cacheStats;
	auto classIds = pool_stats.getClassIds();
	auto numClasses = classIds.size();

	for (auto cid : classIds){
		auto class_stats = cacheStats.at(cid);
		uint32_t class_size = class_stats.allocSize;
		uint64_t total_alloc_attemtps = class_stats.allocAttempts;
		uint64_t total_evict_attempts = class_stats.evictionAttempts;
		uint64_t total_numHits = class_stats.numHits;
  		uint64_t total_allocFailures =class_stats.allocFailures;
		if (total_alloc_attemtps == 0) continue;
		std::cout << "class alloc size: " << class_size << ", ";
		std::cout << "total_alloc_attemtps: " << total_alloc_attemtps << ", ";
		std::cout << "total_evict_attempts: " << total_evict_attempts << ", ";
		std::cout << "total_numHits: " << total_numHits << ", ";
		std::cout << "total_allocFailures: " << total_allocFailures << "." << std::endl;
	}
	
	std::cout << "\n" << std::endl << std::flush;
}






CacheReadHandle get(CacheKey key) { return gCache_->find(key); }

/*CacheKey should be of the type folly::StringPiece */
bool put(CacheKey key, const std::string& value, size_t value_size) {	
  auto handle = gCache_->allocate(defaultPool_, key, value_size);
  if (!handle) {
    return false; // cache may fail to evict due to too many pending writes
  }
  //std::memcpy(handle->getMemory(), value.data(), value.size());
  gCache_->insertOrReplace(handle);
  return true;
}

void initializeCache(unsigned long cache_size) {		
	//std::cout << "Initializing Cache with size " << cache_size << "..." << std::flush; 
	//std::set<uint32_t> allocSizes;
	//allocSizes.insert(2*uniform_obj_size);

	CacheConfig cache_config;
	cache_config
		.setCacheSize(cache_size)
		.setCacheName("My Use Case")
		.setAccessConfig({})	
		.validate(); // will throw if bad config 

	gCache_ = std::make_unique<Cache>(cache_config);
  	defaultPool_= gCache_->addPool("default", gCache_->getCacheMemoryStats().ramCacheSize); 
		
	gCache_->stopPoolRebalancer(std::chrono::seconds(0));
	//std::cout << "Cache Initialized with size " << cache_size << ", slab rebalancing stopped." << std::endl;

}

bool processTrace(const char* trace,const char* ans){
	int num_reqs = (int) std::strlen(trace);

	char * key_ = (char *)malloc(2);
	memset((void *)key_,0,2);
	
	int num_hits = 0;

	for (int i = 0; i < num_reqs; i++){
		memcpy((void *)key_,trace + i,1);
		printf("key: %s\n",key_);
		std::string key(key_);
		
		auto handle = get(key);
		if (handle) num_hits += 1;
		else {
			
			if (!put(key,prefix,uniform_obj_size)) {std::cout<<"alloc failed. "<<std::endl;}
		}

	}	
	auto hit_ratio = (float)num_hits / (float)num_reqs;	
	std::cout <<"num_requests: "<< num_reqs <<", hit ratio:"<< hit_ratio <<std::endl;
	free(key_);
	return 0;
}

} // namespace cachelib_examples
} // namespace facebook


void simulate_zstd(zstd_reader *reader,int max_reqs,unsigned long cache_size){
	using namespace facebook::cachelib_examples;
	
	initializeCache(cache_size);
	int num_hits = 0;
	int num_reqs = 0;
	int num_zero_len_reqs = 0;
	zstd_request *req = (zstd_request *)malloc(sizeof(zstd_request));
	char *record = (char *)malloc(1024 * 1024 * 16);
	
	uint32_t start_time = -1;
	bool should_trunc_file = true;	
	
	int print_mod = 1000000;
	
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

		if (start_time == -1) start_time = req->clock_time;
		
		
		char id_buf[50];
		memset(id_buf, 0, 50);
		sprintf(id_buf,"%lu",req->obj_id);
		std::string str(id_buf);
		std::string key = str; 				
		/*	
		std::cout << num_reqs << ": ";
	        std::cout << "req clcok_time " << req->clock_time << ", id " << req->obj_id << ", ";
		std::cout << "size 1, op invalid, valid 1\n"; 	
		*/
		auto handle = get(key);
		if (handle){
			num_hits += 1;
		}
		else {	
			int obj_size = uniform_obj_size;
			if (obj_size == 0) obj_size = req->obj_size;
			if (!put(key,prefix, obj_size)) {std::cout<<"alloc failed. "; print_one_zstd_request(req);}
		}	
		num_reqs += 1;
		//printf("\n");
		if (max_reqs!=0 && num_reqs >= max_reqs) break;	
	}
	
	double throughput = (req->clock_time - start_time==0)? 0 : (double) num_reqs / (double)(req->clock_time - start_time);
	float hit_ratio = ((float)num_hits) / ((float)num_reqs);

	std::cout <<"num_requests: "<< num_reqs << ", num zero reqs: "<<num_zero_len_reqs<< ",time:"<< (req->clock_time-start_time)<< std::endl;	
	std::cout <<"hit ratio:"<< hit_ratio <<",throughput:"<<throughput <<"reqs/sec,"<<std::endl;
	saveCacheStats();
	
	free(req);
	free(reader); 
}

int main(int argc, char** argv){
	using namespace facebook::cachelib_examples;
	
	char *trace_ = "aaaabbbb";
	
	if (argc < 2) {printf("not enough args. arg1: opt, arg2: traces\n");return 0;}
		
	int opt = std::stoi(argv[1]);
	if (opt == 1){
		const char* data_path = argv[2];
  		if (access(data_path, F_OK) == -1) {
    			printf("Data file %s does not exist.\n", data_path);
    			exit(1);
  		}
		zstd_reader *reader =create_zstd_reader(data_path);
		unsigned long cache_size = (unsigned long)10 * base_size;
		
		int max_reqs = 10;
		std::cout << "argv[3]:" << argv[3] << ". ";
		if (argc > 3) max_reqs = std::atoi(argv[3]);
		if (argc > 4) cache_size  = base_size * (unsigned long)(std::atoi(argv[4]));
		if (argc > 5) uniform_obj_size = (uint32_t) std::stoi(argv[5]);
		simulate_zstd(reader,max_reqs,cache_size);
	}
	else if (opt==2){
		if (argc > 3) {
			uniform_obj_size = (uint32_t) std::stoi(argv[3]);
		}
		unsigned long cache_size = (unsigned long)10 * base_size;
		if (argc > 4) cache_size  = base_size * (unsigned long)(std::atoi(argv[4]));
		initializeCache(cache_size);
	
		const char* trace = argv[2];	
		processTrace(trace,nullptr);		
 	}
	
	return 0;
}

