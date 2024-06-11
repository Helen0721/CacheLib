/**
 * Autogenerated by Thrift for DataTypeBench.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "DataTypeBench_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::facebook::cachelib::datatypebench::StdMap> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).m_ref()...);
  }
};

template <>
struct ForEachField<::facebook::cachelib::datatypebench::StdUnorderedMap> {
  template <typename F, typename... T>
  void operator()([[maybe_unused]] F&& f, [[maybe_unused]] T&&... t) const {
    f(0, static_cast<T&&>(t).m_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
