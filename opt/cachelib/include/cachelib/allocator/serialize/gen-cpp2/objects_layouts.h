/**
 * Autogenerated by Thrift for objects.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/frozen/Frozen.h>
#include "objects_types.h"
#include "cachelib/allocator/datastruct/serialize/gen-cpp2/objects_layouts.h"
namespace apache { namespace thrift { namespace frozen {


FROZEN_TYPE(::facebook::cachelib::serialization::CacheAllocatorMetadata,
  FROZEN_FIELD_REQ(allocatorVersion, 1, ::std::int64_t)
  FROZEN_FIELD(cacheCreationTime, 2, ::std::int64_t)
  FROZEN_FIELD_REQ(accessType, 3, ::std::int64_t)
  FROZEN_FIELD_REQ(mmType, 4, ::std::int64_t)
  FROZEN_FIELD(fragmentationSize, 5, ::std::map<::std::int8_t, ::std::map<::std::int8_t, ::std::int64_t>>)
  FROZEN_FIELD(compactCachePools, 6, ::std::vector<::std::int8_t>)
  FROZEN_FIELD(numPermanentItems, 7, ::std::int64_t)
  FROZEN_FIELD(numChainedParentItems, 8, ::std::int64_t)
  FROZEN_FIELD(numChainedChildItems, 9, ::std::int64_t)
  FROZEN_FIELD(ramFormatVersion, 10, ::std::int64_t)
  FROZEN_FIELD(numAbortedSlabReleases, 11, ::std::int64_t)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(allocatorVersion, ::std::int64_t)
    FROZEN_VIEW_FIELD(cacheCreationTime, ::std::int64_t)
    FROZEN_VIEW_FIELD_REQ(accessType, ::std::int64_t)
    FROZEN_VIEW_FIELD_REQ(mmType, ::std::int64_t)
    FROZEN_VIEW_FIELD(fragmentationSize, ::std::map<::std::int8_t, ::std::map<::std::int8_t, ::std::int64_t>>)
    FROZEN_VIEW_FIELD(compactCachePools, ::std::vector<::std::int8_t>)
    FROZEN_VIEW_FIELD(numPermanentItems, ::std::int64_t)
    FROZEN_VIEW_FIELD(numChainedParentItems, ::std::int64_t)
    FROZEN_VIEW_FIELD(numChainedChildItems, ::std::int64_t)
    FROZEN_VIEW_FIELD(ramFormatVersion, ::std::int64_t)
    FROZEN_VIEW_FIELD(numAbortedSlabReleases, ::std::int64_t))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(allocatorVersion)
    FROZEN_SAVE_FIELD(cacheCreationTime)
    FROZEN_SAVE_FIELD(accessType)
    FROZEN_SAVE_FIELD(mmType)
    FROZEN_SAVE_FIELD(fragmentationSize)
    FROZEN_SAVE_FIELD(compactCachePools)
    FROZEN_SAVE_FIELD(numPermanentItems)
    FROZEN_SAVE_FIELD(numChainedParentItems)
    FROZEN_SAVE_FIELD(numChainedChildItems)
    FROZEN_SAVE_FIELD(ramFormatVersion)
    FROZEN_SAVE_FIELD(numAbortedSlabReleases))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(allocatorVersion, 1)
    FROZEN_LOAD_FIELD(cacheCreationTime, 2)
    FROZEN_LOAD_FIELD(accessType, 3)
    FROZEN_LOAD_FIELD(mmType, 4)
    FROZEN_LOAD_FIELD(fragmentationSize, 5)
    FROZEN_LOAD_FIELD(compactCachePools, 6)
    FROZEN_LOAD_FIELD(numPermanentItems, 7)
    FROZEN_LOAD_FIELD(numChainedParentItems, 8)
    FROZEN_LOAD_FIELD(numChainedChildItems, 9)
    FROZEN_LOAD_FIELD(ramFormatVersion, 10)
    FROZEN_LOAD_FIELD(numAbortedSlabReleases, 11)));

FROZEN_TYPE(::facebook::cachelib::serialization::NvmCacheMetadata,
  FROZEN_FIELD(nvmFormatVersion, 1, ::std::int64_t)
  FROZEN_FIELD(creationTime, 2, ::std::int64_t)
  FROZEN_FIELD(safeShutDown, 3, bool)
  FROZEN_FIELD(encryptionEnabled, 4, bool)
  FROZEN_FIELD(truncateAllocSize, 5, bool)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD(nvmFormatVersion, ::std::int64_t)
    FROZEN_VIEW_FIELD(creationTime, ::std::int64_t)
    FROZEN_VIEW_FIELD(safeShutDown, bool)
    FROZEN_VIEW_FIELD(encryptionEnabled, bool)
    FROZEN_VIEW_FIELD(truncateAllocSize, bool))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(nvmFormatVersion)
    FROZEN_SAVE_FIELD(creationTime)
    FROZEN_SAVE_FIELD(safeShutDown)
    FROZEN_SAVE_FIELD(encryptionEnabled)
    FROZEN_SAVE_FIELD(truncateAllocSize))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(nvmFormatVersion, 1)
    FROZEN_LOAD_FIELD(creationTime, 2)
    FROZEN_LOAD_FIELD(safeShutDown, 3)
    FROZEN_LOAD_FIELD(encryptionEnabled, 4)
    FROZEN_LOAD_FIELD(truncateAllocSize, 5)));

FROZEN_TYPE(::facebook::cachelib::serialization::CompactCacheMetadataObject,
  FROZEN_FIELD_REQ(keySize, 1, ::std::int64_t)
  FROZEN_FIELD_REQ(valueSize, 2, ::std::int64_t)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(keySize, ::std::int64_t)
    FROZEN_VIEW_FIELD_REQ(valueSize, ::std::int64_t))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(keySize)
    FROZEN_SAVE_FIELD(valueSize))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(keySize, 1)
    FROZEN_LOAD_FIELD(valueSize, 2)));

FROZEN_TYPE(::facebook::cachelib::serialization::CompactCacheAllocatorObject,
  FROZEN_FIELD_REQ(chunks, 1, ::std::vector<::std::int64_t>)
  FROZEN_FIELD_REQ(ccMetadata, 2, ::facebook::cachelib::serialization::CompactCacheMetadataObject)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(chunks, ::std::vector<::std::int64_t>)
    FROZEN_VIEW_FIELD_REQ(ccMetadata, ::facebook::cachelib::serialization::CompactCacheMetadataObject))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(chunks)
    FROZEN_SAVE_FIELD(ccMetadata))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(chunks, 1)
    FROZEN_LOAD_FIELD(ccMetadata, 2)));

FROZEN_TYPE(::facebook::cachelib::serialization::CompactCacheAllocatorManagerObject,
  FROZEN_FIELD_REQ(allocators, 1, ::std::map<::std::string, ::facebook::cachelib::serialization::CompactCacheAllocatorObject>)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(allocators, ::std::map<::std::string, ::facebook::cachelib::serialization::CompactCacheAllocatorObject>))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(allocators))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(allocators, 1)));

FROZEN_TYPE(::facebook::cachelib::serialization::MMLruConfig,
  FROZEN_FIELD_REQ(lruRefreshTime, 1, ::std::int32_t)
  FROZEN_FIELD_REQ(updateOnWrite, 2, bool)
  FROZEN_FIELD_REQ(lruInsertionPointSpec, 3, ::std::int32_t)
  FROZEN_FIELD(updateOnRead, 4, bool)
  FROZEN_FIELD(tryLockUpdate, 5, bool)
  FROZEN_FIELD(lruRefreshRatio, 6, double)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(lruRefreshTime, ::std::int32_t)
    FROZEN_VIEW_FIELD_REQ(updateOnWrite, bool)
    FROZEN_VIEW_FIELD_REQ(lruInsertionPointSpec, ::std::int32_t)
    FROZEN_VIEW_FIELD(updateOnRead, bool)
    FROZEN_VIEW_FIELD(tryLockUpdate, bool)
    FROZEN_VIEW_FIELD(lruRefreshRatio, double))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(lruRefreshTime)
    FROZEN_SAVE_FIELD(updateOnWrite)
    FROZEN_SAVE_FIELD(lruInsertionPointSpec)
    FROZEN_SAVE_FIELD(updateOnRead)
    FROZEN_SAVE_FIELD(tryLockUpdate)
    FROZEN_SAVE_FIELD(lruRefreshRatio))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(lruRefreshTime, 1)
    FROZEN_LOAD_FIELD(updateOnWrite, 2)
    FROZEN_LOAD_FIELD(lruInsertionPointSpec, 3)
    FROZEN_LOAD_FIELD(updateOnRead, 4)
    FROZEN_LOAD_FIELD(tryLockUpdate, 5)
    FROZEN_LOAD_FIELD(lruRefreshRatio, 6)));

FROZEN_TYPE(::facebook::cachelib::serialization::MMLruObject,
  FROZEN_FIELD_REQ(config, 1, ::facebook::cachelib::serialization::MMLruConfig)
  FROZEN_FIELD(evictions, 5, ::std::int64_t)
  FROZEN_FIELD_REQ(insertionPoint, 6, ::std::int64_t)
  FROZEN_FIELD_REQ(tailSize, 7, ::std::int64_t)
  FROZEN_FIELD_REQ(lru, 8, ::facebook::cachelib::serialization::DListObject)
  FROZEN_FIELD_REQ(compressedInsertionPoint, 9, ::std::int64_t)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(config, ::facebook::cachelib::serialization::MMLruConfig)
    FROZEN_VIEW_FIELD(evictions, ::std::int64_t)
    FROZEN_VIEW_FIELD_REQ(insertionPoint, ::std::int64_t)
    FROZEN_VIEW_FIELD_REQ(tailSize, ::std::int64_t)
    FROZEN_VIEW_FIELD_REQ(lru, ::facebook::cachelib::serialization::DListObject)
    FROZEN_VIEW_FIELD_REQ(compressedInsertionPoint, ::std::int64_t))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(config)
    FROZEN_SAVE_FIELD(evictions)
    FROZEN_SAVE_FIELD(insertionPoint)
    FROZEN_SAVE_FIELD(tailSize)
    FROZEN_SAVE_FIELD(lru)
    FROZEN_SAVE_FIELD(compressedInsertionPoint))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(config, 1)
    FROZEN_LOAD_FIELD(evictions, 5)
    FROZEN_LOAD_FIELD(insertionPoint, 6)
    FROZEN_LOAD_FIELD(tailSize, 7)
    FROZEN_LOAD_FIELD(lru, 8)
    FROZEN_LOAD_FIELD(compressedInsertionPoint, 9)));

FROZEN_TYPE(::facebook::cachelib::serialization::MMLruCollection,
  FROZEN_FIELD_REQ(pools, 1, ::std::map<::std::int32_t, ::std::map<::std::int32_t, ::facebook::cachelib::serialization::MMLruObject>>)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(pools, ::std::map<::std::int32_t, ::std::map<::std::int32_t, ::facebook::cachelib::serialization::MMLruObject>>))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(pools))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(pools, 1)));

FROZEN_TYPE(::facebook::cachelib::serialization::MM2QConfig,
  FROZEN_FIELD_REQ(lruRefreshTime, 1, ::std::int32_t)
  FROZEN_FIELD_REQ(updateOnWrite, 2, bool)
  FROZEN_FIELD_REQ(hotSizePercent, 3, ::std::int32_t)
  FROZEN_FIELD_REQ(coldSizePercent, 4, ::std::int32_t)
  FROZEN_FIELD(updateOnRead, 5, bool)
  FROZEN_FIELD(tryLockUpdate, 6, bool)
  FROZEN_FIELD(rebalanceOnRecordAccess, 7, bool)
  FROZEN_FIELD(lruRefreshRatio, 8, double)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(lruRefreshTime, ::std::int32_t)
    FROZEN_VIEW_FIELD_REQ(updateOnWrite, bool)
    FROZEN_VIEW_FIELD_REQ(hotSizePercent, ::std::int32_t)
    FROZEN_VIEW_FIELD_REQ(coldSizePercent, ::std::int32_t)
    FROZEN_VIEW_FIELD(updateOnRead, bool)
    FROZEN_VIEW_FIELD(tryLockUpdate, bool)
    FROZEN_VIEW_FIELD(rebalanceOnRecordAccess, bool)
    FROZEN_VIEW_FIELD(lruRefreshRatio, double))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(lruRefreshTime)
    FROZEN_SAVE_FIELD(updateOnWrite)
    FROZEN_SAVE_FIELD(hotSizePercent)
    FROZEN_SAVE_FIELD(coldSizePercent)
    FROZEN_SAVE_FIELD(updateOnRead)
    FROZEN_SAVE_FIELD(tryLockUpdate)
    FROZEN_SAVE_FIELD(rebalanceOnRecordAccess)
    FROZEN_SAVE_FIELD(lruRefreshRatio))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(lruRefreshTime, 1)
    FROZEN_LOAD_FIELD(updateOnWrite, 2)
    FROZEN_LOAD_FIELD(hotSizePercent, 3)
    FROZEN_LOAD_FIELD(coldSizePercent, 4)
    FROZEN_LOAD_FIELD(updateOnRead, 5)
    FROZEN_LOAD_FIELD(tryLockUpdate, 6)
    FROZEN_LOAD_FIELD(rebalanceOnRecordAccess, 7)
    FROZEN_LOAD_FIELD(lruRefreshRatio, 8)));

FROZEN_TYPE(::facebook::cachelib::serialization::MM2QObject,
  FROZEN_FIELD_REQ(config, 1, ::facebook::cachelib::serialization::MM2QConfig)
  FROZEN_FIELD(tailTrackingEnabled, 13, bool)
  FROZEN_FIELD(evictions, 11, ::std::int64_t)
  FROZEN_FIELD_REQ(lrus, 12, ::facebook::cachelib::serialization::MultiDListObject)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(config, ::facebook::cachelib::serialization::MM2QConfig)
    FROZEN_VIEW_FIELD(tailTrackingEnabled, bool)
    FROZEN_VIEW_FIELD(evictions, ::std::int64_t)
    FROZEN_VIEW_FIELD_REQ(lrus, ::facebook::cachelib::serialization::MultiDListObject))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(config)
    FROZEN_SAVE_FIELD(tailTrackingEnabled)
    FROZEN_SAVE_FIELD(evictions)
    FROZEN_SAVE_FIELD(lrus))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(config, 1)
    FROZEN_LOAD_FIELD(tailTrackingEnabled, 13)
    FROZEN_LOAD_FIELD(evictions, 11)
    FROZEN_LOAD_FIELD(lrus, 12)));

FROZEN_TYPE(::facebook::cachelib::serialization::MM2QCollection,
  FROZEN_FIELD_REQ(pools, 1, ::std::map<::std::int32_t, ::std::map<::std::int32_t, ::facebook::cachelib::serialization::MM2QObject>>)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(pools, ::std::map<::std::int32_t, ::std::map<::std::int32_t, ::facebook::cachelib::serialization::MM2QObject>>))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(pools))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(pools, 1)));

FROZEN_TYPE(::facebook::cachelib::serialization::MMTinyLFUConfig,
  FROZEN_FIELD_REQ(lruRefreshTime, 1, ::std::int32_t)
  FROZEN_FIELD_REQ(updateOnWrite, 2, bool)
  FROZEN_FIELD_REQ(windowToCacheSizeRatio, 3, ::std::int32_t)
  FROZEN_FIELD_REQ(tinySizePercent, 4, ::std::int32_t)
  FROZEN_FIELD(updateOnRead, 5, bool)
  FROZEN_FIELD(tryLockUpdate, 6, bool)
  FROZEN_FIELD(lruRefreshRatio, 7, double)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(lruRefreshTime, ::std::int32_t)
    FROZEN_VIEW_FIELD_REQ(updateOnWrite, bool)
    FROZEN_VIEW_FIELD_REQ(windowToCacheSizeRatio, ::std::int32_t)
    FROZEN_VIEW_FIELD_REQ(tinySizePercent, ::std::int32_t)
    FROZEN_VIEW_FIELD(updateOnRead, bool)
    FROZEN_VIEW_FIELD(tryLockUpdate, bool)
    FROZEN_VIEW_FIELD(lruRefreshRatio, double))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(lruRefreshTime)
    FROZEN_SAVE_FIELD(updateOnWrite)
    FROZEN_SAVE_FIELD(windowToCacheSizeRatio)
    FROZEN_SAVE_FIELD(tinySizePercent)
    FROZEN_SAVE_FIELD(updateOnRead)
    FROZEN_SAVE_FIELD(tryLockUpdate)
    FROZEN_SAVE_FIELD(lruRefreshRatio))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(lruRefreshTime, 1)
    FROZEN_LOAD_FIELD(updateOnWrite, 2)
    FROZEN_LOAD_FIELD(windowToCacheSizeRatio, 3)
    FROZEN_LOAD_FIELD(tinySizePercent, 4)
    FROZEN_LOAD_FIELD(updateOnRead, 5)
    FROZEN_LOAD_FIELD(tryLockUpdate, 6)
    FROZEN_LOAD_FIELD(lruRefreshRatio, 7)));

FROZEN_TYPE(::facebook::cachelib::serialization::MMTinyLFUObject,
  FROZEN_FIELD_REQ(config, 1, ::facebook::cachelib::serialization::MMTinyLFUConfig)
  FROZEN_FIELD(evictions, 2, ::std::int64_t)
  FROZEN_FIELD_REQ(lrus, 3, ::facebook::cachelib::serialization::MultiDListObject)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(config, ::facebook::cachelib::serialization::MMTinyLFUConfig)
    FROZEN_VIEW_FIELD(evictions, ::std::int64_t)
    FROZEN_VIEW_FIELD_REQ(lrus, ::facebook::cachelib::serialization::MultiDListObject))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(config)
    FROZEN_SAVE_FIELD(evictions)
    FROZEN_SAVE_FIELD(lrus))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(config, 1)
    FROZEN_LOAD_FIELD(evictions, 2)
    FROZEN_LOAD_FIELD(lrus, 3)));

FROZEN_TYPE(::facebook::cachelib::serialization::MMTinyLFUCollection,
  FROZEN_FIELD_REQ(pools, 1, ::std::map<::std::int32_t, ::std::map<::std::int32_t, ::facebook::cachelib::serialization::MMTinyLFUObject>>)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(pools, ::std::map<::std::int32_t, ::std::map<::std::int32_t, ::facebook::cachelib::serialization::MMTinyLFUObject>>))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(pools))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(pools, 1)));

FROZEN_TYPE(::facebook::cachelib::serialization::MMSieveConfig,
  FROZEN_FIELD_REQ(lruRefreshTime, 1, ::std::int32_t)
  FROZEN_FIELD_REQ(updateOnWrite, 2, bool)
  FROZEN_FIELD(updateOnRead, 3, bool)
  FROZEN_FIELD(tryLockUpdate, 4, bool)
  FROZEN_FIELD(lruRefreshRatio, 5, double)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(lruRefreshTime, ::std::int32_t)
    FROZEN_VIEW_FIELD_REQ(updateOnWrite, bool)
    FROZEN_VIEW_FIELD(updateOnRead, bool)
    FROZEN_VIEW_FIELD(tryLockUpdate, bool)
    FROZEN_VIEW_FIELD(lruRefreshRatio, double))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(lruRefreshTime)
    FROZEN_SAVE_FIELD(updateOnWrite)
    FROZEN_SAVE_FIELD(updateOnRead)
    FROZEN_SAVE_FIELD(tryLockUpdate)
    FROZEN_SAVE_FIELD(lruRefreshRatio))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(lruRefreshTime, 1)
    FROZEN_LOAD_FIELD(updateOnWrite, 2)
    FROZEN_LOAD_FIELD(updateOnRead, 3)
    FROZEN_LOAD_FIELD(tryLockUpdate, 4)
    FROZEN_LOAD_FIELD(lruRefreshRatio, 5)));

FROZEN_TYPE(::facebook::cachelib::serialization::MMSieveObject,
  FROZEN_FIELD_REQ(config, 1, ::facebook::cachelib::serialization::MMLruConfig)
  FROZEN_FIELD(evictions, 5, ::std::int64_t)
  FROZEN_FIELD_REQ(lru, 6, ::facebook::cachelib::serialization::DListObject)
  FROZEN_FIELD_REQ(compressedHand, 7, ::std::int64_t)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(config, ::facebook::cachelib::serialization::MMLruConfig)
    FROZEN_VIEW_FIELD(evictions, ::std::int64_t)
    FROZEN_VIEW_FIELD_REQ(lru, ::facebook::cachelib::serialization::DListObject)
    FROZEN_VIEW_FIELD_REQ(compressedHand, ::std::int64_t))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(config)
    FROZEN_SAVE_FIELD(evictions)
    FROZEN_SAVE_FIELD(lru)
    FROZEN_SAVE_FIELD(compressedHand))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(config, 1)
    FROZEN_LOAD_FIELD(evictions, 5)
    FROZEN_LOAD_FIELD(lru, 6)
    FROZEN_LOAD_FIELD(compressedHand, 7)));

FROZEN_TYPE(::facebook::cachelib::serialization::MMSieveCollection,
  FROZEN_FIELD_REQ(pools, 1, ::std::map<::std::int32_t, ::std::map<::std::int32_t, ::facebook::cachelib::serialization::MMLruObject>>)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(pools, ::std::map<::std::int32_t, ::std::map<::std::int32_t, ::facebook::cachelib::serialization::MMLruObject>>))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(pools))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(pools, 1)));

FROZEN_TYPE(::facebook::cachelib::serialization::ChainedHashTableObject,
  FROZEN_FIELD_REQ(bucketsPower, 1, ::std::int32_t)
  FROZEN_FIELD_REQ(locksPower, 2, ::std::int32_t)
  FROZEN_FIELD(numKeys, 3, ::std::int64_t)
  FROZEN_FIELD(hasherMagicId, 4, ::std::int32_t)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(bucketsPower, ::std::int32_t)
    FROZEN_VIEW_FIELD_REQ(locksPower, ::std::int32_t)
    FROZEN_VIEW_FIELD(numKeys, ::std::int64_t)
    FROZEN_VIEW_FIELD(hasherMagicId, ::std::int32_t))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(bucketsPower)
    FROZEN_SAVE_FIELD(locksPower)
    FROZEN_SAVE_FIELD(numKeys)
    FROZEN_SAVE_FIELD(hasherMagicId))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(bucketsPower, 1)
    FROZEN_LOAD_FIELD(locksPower, 2)
    FROZEN_LOAD_FIELD(numKeys, 3)
    FROZEN_LOAD_FIELD(hasherMagicId, 4)));

FROZEN_TYPE(::facebook::cachelib::serialization::MMTTLBucketObject,
  FROZEN_FIELD(expirationTime, 4, ::std::int64_t)
  FROZEN_FIELD(creationTime, 5, ::std::int64_t)
  FROZEN_FIELD_REQ(dList, 6, ::facebook::cachelib::serialization::DListObject)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD(expirationTime, ::std::int64_t)
    FROZEN_VIEW_FIELD(creationTime, ::std::int64_t)
    FROZEN_VIEW_FIELD_REQ(dList, ::facebook::cachelib::serialization::DListObject))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(expirationTime)
    FROZEN_SAVE_FIELD(creationTime)
    FROZEN_SAVE_FIELD(dList))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(expirationTime, 4)
    FROZEN_LOAD_FIELD(creationTime, 5)
    FROZEN_LOAD_FIELD(dList, 6)));

FROZEN_TYPE(::facebook::cachelib::serialization::TTLBucketCollection,
  FROZEN_FIELD_REQ(buckets, 1, ::std::map<::std::int64_t, ::facebook::cachelib::serialization::MMTTLBucketObject>)
  FROZEN_FIELD(minEpoch, 2, ::std::int64_t)
  FROZEN_FIELD(maxTTL, 3, ::std::int64_t)
  FROZEN_FIELD(interval, 4, ::std::int64_t)
  FROZEN_VIEW(
    FROZEN_VIEW_FIELD_REQ(buckets, ::std::map<::std::int64_t, ::facebook::cachelib::serialization::MMTTLBucketObject>)
    FROZEN_VIEW_FIELD(minEpoch, ::std::int64_t)
    FROZEN_VIEW_FIELD(maxTTL, ::std::int64_t)
    FROZEN_VIEW_FIELD(interval, ::std::int64_t))
  FROZEN_SAVE_INLINE(
    FROZEN_SAVE_FIELD(buckets)
    FROZEN_SAVE_FIELD(minEpoch)
    FROZEN_SAVE_FIELD(maxTTL)
    FROZEN_SAVE_FIELD(interval))
  FROZEN_LOAD_INLINE(
    FROZEN_LOAD_FIELD(buckets, 1)
    FROZEN_LOAD_FIELD(minEpoch, 2)
    FROZEN_LOAD_FIELD(maxTTL, 3)
    FROZEN_LOAD_FIELD(interval, 4)));

}}} // apache::thrift::frozen
