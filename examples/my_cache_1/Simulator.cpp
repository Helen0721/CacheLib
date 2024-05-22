#include "cachelib/allocator/CacheAllocator.h"
#include "cachelib/allocator/LruTailAgeStrategy.h"
#include "cachelib/allocator/MarginalHitsStrategy.h"
#include "cachelib/allocator/FreeMemStrategy.h"
#include "cachelib/allocator/HitsPerSlabStrategy.h"
#include "folly/init/Init.h"
#include <cstdlib>
#include <string.h>
#include <iostream>
#include "/disk/CacheLib/examples/my_cache_1/Reader/BinaryReader.h"
#include "/disk/CacheLib/examples/my_cache_1/Reader/ZstdReader.h"
#include "/disk/CacheLib/examples/my_cache_1/Simulator.h"

namespace facebook {
namespace cachelib_examples {

using Cache = cachelib::LruAllocator; // LruAllocator, Lru2QAllocator, or TinyLFUAllocator
using CacheConfig = typename Cache::Config;
using CacheKey = typename Cache::Key;
using CacheReadHandle = typename Cache::ReadHandle;

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


void initializeCache(char* cache_size) {
  unsigned long size = convertCacheSize(cache_size);

  if (size == 0) exit(1);	
  CacheConfig config;
  config
      .setCacheSize(size)
      .setCacheName("My Use Case")
      .setAccessConfig(
          {25 /* bucket power */, 10 /* lock power */}) // assuming caching 20
                                                        // million items
      .validate(); // will throw if bad config
  
  
  gCache_ = std::make_unique<Cache>(config);
  defaultPool_=
      gCache_->addPool("default", gCache_->getCacheMemoryStats().ramCacheSize);

  config.configureChainedItems();

  auto ratio = 0.1;
  auto kLruTailAgeStrategyMinSlabs = 10;
  cachelib::LruTailAgeStrategy::Config cfg(ratio, kLruTailAgeStrategyMinSlabs);
  cfg.slabProjectionLength = 0; // dont project or estimate tail age
  cfg.numSlabsFreeMem = 10;     // ok to have ~40 MB free memory in unused allocations
  auto rebalanceStrategy = std::make_shared<cachelib::LruTailAgeStrategy>(cfg);

  // every 5 seconds, re-evaluate the eviction ages and rebalance the cache.
  config.enablePoolRebalancing(std::move(rebalanceStrategy), std::chrono::seconds(5));

  std::cout<< "Cache Initialized. size: "<< cache_size << std::endl;
}

void destroyCache() { gCache_.reset(); }

CacheReadHandle get(CacheKey key) { return gCache_->find(key); }

bool put_ChainedItem(CacheKey key, const std::string& value){
  std::cout << "put_ChainedItem.. for value size:"<<value.size() <<std::endl;
  size_t chunkSize = 1024 * 1024;
  // For simplicity, we'll split the user data into 1MB chunks
  size_t numChunks = value.size() / chunkSize + 1;
  std::cout << "numChunks:" << numChunks;

  //struct CustomParentItem {
  //  size_t numChunks;
    //void* dataPtr[];  // an array of pointers to the chunks
  //};

  size_t parentItemSize = sizeof(size_t); 	//sizeof(CustomParentItem) + numChunks * sizeof(void*);

  std::cout << ". parentItemSize:" << parentItemSize; 

  // for simplicity, assume this fits into 1MB
  assert(parentItemSize < chunkSize);

  auto parentItemHandle =
	gCache_->allocate(defaultPool_, key, parentItemSize);

  if (!parentItemHandle) return false;

  // CustomParentItem* parentItem = malloc(sizeof(CustomParentItem));
  //parentItem->numChunks = numChunks;

  std::memcpy(parentItemHandle->getMemory(), &numChunks, parentItemSize);

  std::cout << " .parentItem copied. " <<std::endl;

  // Now split user data into chunks and cache them
  for (size_t i = 0; i < numChunks; ++i) {
	 std::cout << "allocating..";
	 auto chainedItemHandle =
		  gCache_->allocateChainedItem(parentItemHandle, chunkSize);

  	// For simplicity, assume we always have enough memory
  	if (!chainedItemHandle) return false;

	std::cout << "chained item allocated. ";

  	// Compute user data offset and copy data over
  	uint8_t* dataOffset = (uint8_t*) (void *)value.data() + chunkSize * i;
  	std::memcpy(chainedItemHandle->getMemory(), dataOffset, chunkSize);
	
	std::cout << "data copied. ";

  	// Add this chained item to the parent item
  	gCache_->addChainedItem(parentItemHandle, std::move(chainedItemHandle));
	std::cout << "chained item added. " << std::endl;
  }

  // Now, make parent item visible to others
  gCache_->insertOrReplace(parentItemHandle);
  return true;
}

/*CacheKey should be of the type folly::StringPiece */
bool put(CacheKey key, const std::string& value) {
  if(value.size() >= 4000000) return put_ChainedItem(key, value);
	
  auto handle = gCache_->allocate(defaultPool_, key, value.size());
  if (!handle) {
    return false; // cache may fail to evict due to too many pending writes
  }
  std::memcpy(handle->getMemory(), value.data(), value.size());
  gCache_->insertOrReplace(handle);
  return true;
}

} // namespace cachelib_examples
} // namespace facebook


void simulate_binary(char *cache_size, bin_reader_t *reader,int max_reqs){

	using namespace facebook::cachelib_examples;
	
	initializeCache(cache_size);
	int num_hits = 0;
	
	bin_request *req = (bin_request*) malloc(sizeof(bin_request));
	uint32_t start_time = -1;
        		
	char* value_all = (char *) malloc(1024 * 1024 * 8);

	while(reader->offset < reader->total_num_requests){
		read_one_binary_request(reader, req);
		std::string key = std::to_string(req->obj_id);
		
		auto handle = get(key);
		if (handle) num_hits += 1;
		else {
			std::string prefix(value_all,req->obj_size);
			if (!put(key,prefix)) {std::cout<<"alloc failed. "; print_one_binary_request(req);}
		}
		if (start_time == -1) start_time = req->timestamp;

		if (reader->offset % 1000 == 0 && (req->timestamp - start_time !=0)){
			float hit_ratio = ((float)num_hits) / ((float)reader->total_num_requests);
			std::cout<<"hit ratio:"<< hit_ratio <<",time:"<<(req->timestamp - start_time) <<std::endl;
		}

		if (max_reqs!=0 && reader->offset > max_reqs) break;
	}

	double throughput = (req->timestamp-start_time==0)? 0 : (double) reader->total_num_requests / (req->timestamp - start_time);
	float hit_ratio = ((float)num_hits) / ((float)reader->total_num_requests);
	
	std::cout<<"hit ratio:"<< hit_ratio <<",time:"<<(req->timestamp - start_time) <<std::endl;
	std::cout <<"num_requests:"<<reader->total_num_requests<<",throughput:"<<throughput <<"reqs/sec,"<<std::endl;

	free(req);
	free(value_all);
	free(reader);
 	destroyCache();
}

void simulate_zstd(char* cache_size, zstd_reader *reader,int max_reqs){
	using namespace facebook::cachelib_examples;
	
	initializeCache(cache_size);
	int num_hits = 0;
	int num_reqs = 0;

	zstd_request *req = (zstd_request *)malloc(sizeof(zstd_request));

	uint32_t start_time = -1;	

	char* value_all = (char *) malloc(1024 * 1024 * 8);
	char *record;
	
	std::string prefix(value_all,1024 * 1024 * 4);

	/*
	 test for Chained Item implementation.
	zstd_reader_read_bytes(reader, 24, &record);
	
	std::string key = std::to_string(req->obj_id);

	auto chained_res = put(key,prefix);
	if (!chained_res) {std::cout<< "chained item alloc failed" << std::endl; return;}
	auto chained_handle = get(key);
	if (!chained_handle) {std::cout<< "chained item find failed" << std::endl; return;}	
	*/

	std::cout<<"time,id,size"<<std::endl;

	while(true){
		size_t n = zstd_reader_read_bytes(reader, 24, &record);

		if (reader->status == MY_EOF) {std::cout<<"EOF"<<std::endl; break;}
	        if (reader->status == ERR) {std::cout<<"ERR."<<num_reqs<<std::endl;;break;}
		if (n==0) continue;
		
		req->clock_time = *(uint32_t *)record;
		req->obj_id = *(uint64_t *)(record + 4);
		req->obj_size = *(uint32_t *)(record + 12);
		req->next_access_vtime = *(int64_t *)(record + 16);

		if (req->obj_size == 0) continue;

		if (start_time == -1) start_time = req->clock_time;
		
		std::string key = std::to_string(req->obj_id);
		

		//print_one_zstd_request(req);

		auto handle = get(key);
		if (handle) num_hits += 1;
		else {
			std::string prefix(value_all,req->obj_size);
			if (!put(key,prefix)) {std::cout<<"alloc failed. "; print_one_zstd_request(req);}
		}

		num_reqs += 1;
		if (max_reqs!=0 && num_reqs >= max_reqs) break;
		
		if (num_reqs % 100000 == 0 && (req->clock_time - start_time !=0) ){
			float hit_ratio = ((float)num_hits) / ((float)num_reqs);
			std::cout<<"hit ratio:"<< hit_ratio <<",time:"<<(req->clock_time - start_time) <<std::endl;
		}
	}
	
	double throughput = (req->clock_time - start_time==0)? 0 : (double) num_reqs / (double)(req->clock_time - start_time);
	float hit_ratio = ((float)num_hits) / ((float)num_reqs);
	
	std::cout<<"hit ratio:"<< hit_ratio <<",time:"<< (req->clock_time-start_time) <<std::endl;

	std::cout <<"num_requests:"<<num_reqs<<",throughput:"<<throughput <<"reqs/sec,"<<std::endl;

	free(req);
	free(value_all);
	free(reader);
 	//destroyCache();		somehow doesn't work with ChainedItem reset.

}



