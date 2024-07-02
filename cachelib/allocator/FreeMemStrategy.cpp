/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "cachelib/allocator/FreeMemStrategy.h"

#include <folly/logging/xlog.h>

#include <algorithm>
#include <functional>

#include "cachelib/allocator/Util.h"

namespace facebook::cachelib {

FreeMemStrategy::FreeMemStrategy(Config config)
    : RebalanceStrategy(FreeMem), config_(std::move(config)) {
    
    std::cout << "MFS::MFS(Config config): ";
    printf("minSlabs:%u,numFreeSlabs:%u,maxUnAllocatedSlabs:%zu \n",
	config.minSlabs,config.numFreeSlabs,config.maxUnAllocatedSlabs);
}

// The list of allocation classes to be rebalanced is determined by:
//
// 0. Filter out classes that have below minSlabThreshold_
//
// 1. Filter out classes that have just gained a slab recently
//
// 2. Pick the class we find with the most free memory past the threshold
RebalanceContext FreeMemStrategy::pickVictimAndReceiverImpl(
    const CacheBase& cache, PoolId pid, const PoolStats& poolStats) {
  
  std::cout<< "FMS-pickVAndRImpl...";

  const auto& pool = cache.getPool(pid);
  if (pool.getUnAllocatedSlabMemory() >
      config_.maxUnAllocatedSlabs * Slab::kSize) {
    return kNoOpContext;
  }

  // ignore allocation classes that have fewer than the threshold of slabs.
  const auto victims = filterByNumEvictableSlabs(
      poolStats, std::move(poolStats.getClassIds()), config_.minSlabs);

  if (victims.empty()) {
    XLOG(DBG, "Rebalancing: No victims available");
    std::cout << "FMS-No victims available" <<std::endl;
    return kNoOpContext;
  }

  RebalanceContext ctx;
  ctx.victimClassId = pickVictimByFreeMem(
      victims, poolStats, config_.getFreeMemThreshold(), getPoolState(pid));
  
  std::cout << "FMS-v: " << static_cast<int>(ctx.victimClassId) << ". ";

  if (ctx.victimClassId == Slab::kInvalidClassId) {
    std::cout <<std::endl << std::flush ;
    return kNoOpContext;
  }

  
  XLOGF(DBG, "Rebalancing: victimAC = {}", static_cast<int>(ctx.victimClassId));
 
  std::cout << "FMS-picked." << std::endl << std::flush;

  return ctx;
}
} // namespace facebook::cachelib
