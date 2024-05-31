#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "cachelib/allocator/CacheAllocator.h"

void simulate_binary(char *cache_size, char *rebalanceStrategy, bin_reader_t *reader,int max_reqs);
void simulate_zstd(char *cache_size, char *rebalanceStrategy, zstd_reader *reader,int max_reqs);

#endif
