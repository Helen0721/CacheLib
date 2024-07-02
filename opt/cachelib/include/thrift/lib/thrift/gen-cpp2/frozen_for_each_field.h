/**
 * Autogenerated by Thrift for /disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/frozen.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/lib/thrift/gen-cpp2/frozen_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::apache::thrift::frozen::schema::Field> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).layoutId_ref()...);
    f(1, static_cast<T&&>(t).offset_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::frozen::schema::Layout> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).size_ref()...);
    f(1, static_cast<T&&>(t).bits_ref()...);
    f(2, static_cast<T&&>(t).fields_ref()...);
    f(3, static_cast<T&&>(t).typeName_ref()...);
  }
};

template <>
struct ForEachField<::apache::thrift::frozen::schema::Schema> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).fileVersion_ref()...);
    f(1, static_cast<T&&>(t).relaxTypeChecks_ref()...);
    f(2, static_cast<T&&>(t).layouts_ref()...);
    f(3, static_cast<T&&>(t).rootLayout_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
