#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "cachelib/allocator/CacheAllocator.h"

void simulate_binary(char *cache_size, bin_reader_t *reader,int max_reqs);
void simulate_zstd(char *cache_size, zstd_reader *reader,int max_reqs);

#endif
