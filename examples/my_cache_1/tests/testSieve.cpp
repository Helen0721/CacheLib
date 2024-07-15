#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <iostream>
#include <regex>

#include "cachelib/allocator/CacheAllocator.h"
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
uint32_t uniform_obj_size = 1000;


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

void initializeCache() {
  
	unsigned long size = 10 * 1024 * 1024;
	std::cout << "Initializing Cache..." << std::flush; 
	
	CacheConfig cache_config;
	cache_config
		.setCacheSize(size)
		.setCacheName("My Use Case")
		.setAccessConfig({})	
		.validate(); // will throw if bad config 

	gCache_ = std::make_unique<Cache>(cache_config);
  	defaultPool_= gCache_->addPool("default", gCache_->getCacheMemoryStats().ramCacheSize); 

  	std::cout<< "Cache Initialized" << std::endl << std::flush;
		
	gCache_->stopPoolRebalancer(std::chrono::seconds(0));
	std::cout << "Slab rebalancing stopped." << std::endl;

}

} // namespace cachelib_examples
} // namespace facebook

int main(int argc, char** argv){
	using namespace facebook::cachelib_examples;
	
	char *trace_ = "aaaabbbb";

	if (argc > 1) uniform_obj_size = (uint32_t) std::stoi(argv[1]);
	if (argc > 2) trace_ = argv[2];
	
	const char* trace = trace_;

	initializeCache();
	
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
	return 0;
}

