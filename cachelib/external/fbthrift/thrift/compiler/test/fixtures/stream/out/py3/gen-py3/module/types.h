/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#pragma once

#include <functional>
#include <folly/Range.h>

#include <thrift/lib/py3/enums.h>
#include "thrift/compiler/test/fixtures/stream/gen-cpp2/module_data.h"
#include "thrift/compiler/test/fixtures/stream/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/stream/gen-cpp2/module_metadata.h"
namespace thrift {
namespace py3 {



template<>
inline void reset_field<::cpp2::FooStreamEx>(
    ::cpp2::FooStreamEx& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
inline void reset_field<::cpp2::FooEx>(
    ::cpp2::FooEx& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
inline void reset_field<::cpp2::FooEx2>(
    ::cpp2::FooEx2& obj, uint16_t index) {
  switch (index) {
  }
}

template<>
inline const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::cpp2::FooStreamEx>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
inline const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::cpp2::FooEx>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}

template<>
inline const std::unordered_map<std::string_view, std::string_view>& PyStructTraits<
    ::cpp2::FooEx2>::namesmap() {
  static const folly::Indestructible<NamesMap> map {
    {
    }
  };
  return *map;
}
} // namespace py3
} // namespace thrift
