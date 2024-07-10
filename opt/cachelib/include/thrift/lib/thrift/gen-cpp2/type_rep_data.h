/**
 * Autogenerated by Thrift for /disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/type_rep.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/lib/thrift/gen-cpp2/type_rep_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::apache::thrift::type::ProtocolUnion::Type> {
  using type = ::apache::thrift::type::ProtocolUnion::Type;
  static constexpr const std::size_t size = 3;
  static constexpr std::array<type, size> values = { {
      type::standard,
      type::custom,
      type::id,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "standard"sv,
      "custom"sv,
      "id"sv,
  }};
};

template <> struct TStructDataStorage<::apache::thrift::type::ProtocolUnion> {
  static constexpr const std::size_t fields_size = 3;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<std::string_view, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::apache::thrift::type::TypeStruct> {
  static constexpr const std::size_t fields_size = 2;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  static const std::array<std::string_view, fields_size> storage_names;
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

}} // apache::thrift
