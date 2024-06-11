/**
 * Autogenerated by Thrift for /disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/metadata.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/lib/thrift/gen-cpp2/metadata_metadata.h"
#include <thrift/lib/cpp2/visitation/visit_union.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitUnion<::apache::thrift::metadata::ThriftConstValue> {

  template <typename F, typename T>
  decltype(auto) operator()([[maybe_unused]] F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::cv_bool:
      return f(0, *static_cast<T&&>(t).cv_bool_ref());
    case Union::Type::cv_integer:
      return f(1, *static_cast<T&&>(t).cv_integer_ref());
    case Union::Type::cv_double:
      return f(2, *static_cast<T&&>(t).cv_double_ref());
    case Union::Type::cv_string:
      return f(3, *static_cast<T&&>(t).cv_string_ref());
    case Union::Type::cv_map:
      return f(4, *static_cast<T&&>(t).cv_map_ref());
    case Union::Type::cv_list:
      return f(5, *static_cast<T&&>(t).cv_list_ref());
    case Union::Type::cv_struct:
      return f(6, *static_cast<T&&>(t).cv_struct_ref());
    case Union::Type::__EMPTY__:
      return decltype(f(0, *static_cast<T&&>(t).cv_bool_ref()))();
    }
  }
};
template <>
struct VisitUnion<::apache::thrift::metadata::ThriftType> {

  template <typename F, typename T>
  decltype(auto) operator()([[maybe_unused]] F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
    case Union::Type::t_primitive:
      return f(0, *static_cast<T&&>(t).t_primitive_ref());
    case Union::Type::t_list:
      return f(1, *static_cast<T&&>(t).t_list_ref());
    case Union::Type::t_set:
      return f(2, *static_cast<T&&>(t).t_set_ref());
    case Union::Type::t_map:
      return f(3, *static_cast<T&&>(t).t_map_ref());
    case Union::Type::t_enum:
      return f(4, *static_cast<T&&>(t).t_enum_ref());
    case Union::Type::t_struct:
      return f(5, *static_cast<T&&>(t).t_struct_ref());
    case Union::Type::t_union:
      return f(6, *static_cast<T&&>(t).t_union_ref());
    case Union::Type::t_typedef:
      return f(7, *static_cast<T&&>(t).t_typedef_ref());
    case Union::Type::t_stream:
      return f(8, *static_cast<T&&>(t).t_stream_ref());
    case Union::Type::t_sink:
      return f(9, *static_cast<T&&>(t).t_sink_ref());
    case Union::Type::__EMPTY__:
      return decltype(f(0, *static_cast<T&&>(t).t_primitive_ref()))();
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
