/**
 * Autogenerated by Thrift for /disk/CacheLib/cachelib/external/fbthrift/thrift/annotation/python.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/visitation/visit_by_thrift_field_metadata.h>
#include "thrift/annotation/gen-cpp2/python_metadata.h"

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitByFieldId<::facebook::thrift::annotation::python::Py3Hidden> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    default:
      throwInvalidThriftId(fieldId, "::facebook::thrift::annotation::python::Py3Hidden");
    }
  }
};

template <>
struct VisitByFieldId<::facebook::thrift::annotation::python::Flags> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    default:
      throwInvalidThriftId(fieldId, "::facebook::thrift::annotation::python::Flags");
    }
  }
};

template <>
struct VisitByFieldId<::facebook::thrift::annotation::python::Name> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).name_ref());
    default:
      throwInvalidThriftId(fieldId, "::facebook::thrift::annotation::python::Name");
    }
  }
};

template <>
struct VisitByFieldId<::facebook::thrift::annotation::python::Adapter> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).name_ref());
    case 2:
      return f(1, static_cast<T&&>(t).typeHint_ref());
    default:
      throwInvalidThriftId(fieldId, "::facebook::thrift::annotation::python::Adapter");
    }
  }
};

template <>
struct VisitByFieldId<::facebook::thrift::annotation::python::UseCAPI> {
  template <typename F, typename T>
  void operator()([[maybe_unused]] F&& f, int32_t fieldId, [[maybe_unused]] T&& t) const {
    switch (fieldId) {
    case 1:
      return f(0, static_cast<T&&>(t).serialize_ref());
    default:
      throwInvalidThriftId(fieldId, "::facebook::thrift::annotation::python::UseCAPI");
    }
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
