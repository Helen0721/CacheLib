#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "cachelib/allocator/CacheAllocator.h"

void simulate_binary(char *cache_size, 
		char *rebalanceStrategy,
		char* rebParams,
		bin_reader_t *reader,
		size_t max_reqs,
		int ampF,
		char* cacheStats_path_ 
		);
void simulate_zstd(char *cache_size, 
		char *rebalanceStrategy,
		char* rebParams,
		zstd_reader *reader,
		size_t max_reqs, 
		int ampF,
		char* cacheStats_path_
		);

void simulate_zstd_con(char *cache_size, 
		char *rebalanceStrategy,
		char* rebParams,
		zstd_reader *reader,
		size_t max_reqs, 
		int num_threads
		);
#endif
