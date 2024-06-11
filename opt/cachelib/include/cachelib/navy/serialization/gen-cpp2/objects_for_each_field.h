/**
 * Autogenerated by Thrift for objects.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "objects_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::IndexEntry> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).address_ref()...);
    f(2, static_cast<T&&>(t).sizeHint_ref()...);
    f(3, static_cast<T&&>(t).totalHits_ref()...);
    f(4, static_cast<T&&>(t).currentHits_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::IndexBucket> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).bucketId_ref()...);
    f(1, static_cast<T&&>(t).entries_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::Region> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).regionId_ref()...);
    f(1, static_cast<T&&>(t).lastEntryEndOffset_ref()...);
    f(2, static_cast<T&&>(t).classId_ref()...);
    f(3, static_cast<T&&>(t).numItems_ref()...);
    f(4, static_cast<T&&>(t).pinned_ref()...);
    f(5, static_cast<T&&>(t).priority_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::RegionData> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).regions_ref()...);
    f(1, static_cast<T&&>(t).regionSize_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::FifoPolicyNodeData> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).idx_ref()...);
    f(1, static_cast<T&&>(t).trackTime_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::FifoPolicyData> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).queue_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::AccessStats> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).totalHits_ref()...);
    f(1, static_cast<T&&>(t).currHits_ref()...);
    f(2, static_cast<T&&>(t).numReinsertions_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::AccessStatsPair> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).stats_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::AccessTracker> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).deprecated_data_ref()...);
    f(1, static_cast<T&&>(t).data_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::BlockCacheConfig> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).version_ref()...);
    f(1, static_cast<T&&>(t).cacheBaseOffset_ref()...);
    f(2, static_cast<T&&>(t).cacheSize_ref()...);
    f(3, static_cast<T&&>(t).allocAlignSize_ref()...);
    f(4, static_cast<T&&>(t).deprecated_sizeClasses_ref()...);
    f(5, static_cast<T&&>(t).checksum_ref()...);
    f(6, static_cast<T&&>(t).deprecated_sizeDist_ref()...);
    f(7, static_cast<T&&>(t).holeCount_ref()...);
    f(8, static_cast<T&&>(t).holeSizeTotal_ref()...);
    f(9, static_cast<T&&>(t).reinsertionPolicyEnabled_ref()...);
    f(10, static_cast<T&&>(t).usedSizeBytes_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::navy::serialization::BigHashPersistentData> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).version_ref()...);
    f(1, static_cast<T&&>(t).generationTime_ref()...);
    f(2, static_cast<T&&>(t).itemCount_ref()...);
    f(3, static_cast<T&&>(t).bucketSize_ref()...);
    f(4, static_cast<T&&>(t).cacheBaseOffset_ref()...);
    f(5, static_cast<T&&>(t).numBuckets_ref()...);
    f(6, static_cast<T&&>(t).deprecated_sizeDist_ref()...);
    f(7, static_cast<T&&>(t).usedSizeBytes_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
