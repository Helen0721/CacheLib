/**
 * Autogenerated by Thrift for objects.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/visitation/visit_by_thrift_field_metadata.h>
#include "objects_metadata.h"

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitByFieldId<::facebook::cachelib::serialization::SListObject> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 2:
      return f(0, static_cast<T&&>(t).size_ref());
    case 3:
      return f(1, static_cast<T&&>(t).compressedHead_ref());
    case 4:
      return f(2, static_cast<T&&>(t).compressedTail_ref());
    default:
      throwInvalidThriftId(fieldId, "::facebook::cachelib::serialization::SListObject");
    }
  }
};

template <>
struct VisitByFieldId<::facebook::cachelib::serialization::DListObject> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).compressedHead_ref());
    case 2:
      return f(1, static_cast<T&&>(t).compressedTail_ref());
    case 3:
      return f(2, static_cast<T&&>(t).size_ref());
    default:
      throwInvalidThriftId(fieldId, "::facebook::cachelib::serialization::DListObject");
    }
  }
};

template <>
struct VisitByFieldId<::facebook::cachelib::serialization::MultiDListObject> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).lists_ref());
    default:
      throwInvalidThriftId(fieldId, "::facebook::cachelib::serialization::MultiDListObject");
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
