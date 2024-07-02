/**
 * Autogenerated by Thrift for /disk/CacheLib/cachelib/external/fbthrift/thrift/lib/thrift/any_rep.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/lib/thrift/gen-cpp2/any_rep_types.h"

#include <thrift/lib/cpp2/gen/module_types_tcc.h>


namespace apache {
namespace thrift {
namespace detail {

template <>
struct TccStructTraits<::apache::thrift::type::AnyStruct> {
  static void translateFieldName(
      std::string_view _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype) noexcept;
};
template <>
struct TccStructTraits<::apache::thrift::type::SemiAnyStruct> {
  static void translateFieldName(
      std::string_view _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype) noexcept;
};

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache::thrift::type {

template <class Protocol_>
void AnyStruct::readNoXfer(Protocol_* iprot) {
  __fbthrift_clear_terse_fields();

  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;


  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          1,
          apache::thrift::protocol::T_STRUCT))) {
    goto _advance_failure;
  }
_readField_type:
  {
    _readState.beforeSubobject(iprot);
    ::apache::thrift::op::decode<::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Type>, ::apache::thrift::type::struct_t<::apache::thrift::type::TypeStruct>>>(*iprot, this->__fbthrift_field_type);
    _readState.afterSubobject(iprot);
    
  }
 this->__isset.set(0, true);

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          1,
          2,
          apache::thrift::protocol::T_STRUCT))) {
    goto _advance_failure;
  }
_readField_protocol:
  {
    _readState.beforeSubobject(iprot);
    ::apache::thrift::op::decode<::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Protocol>, ::apache::thrift::type::union_t<::apache::thrift::type::ProtocolUnion>>>(*iprot, this->__fbthrift_field_protocol);
    _readState.afterSubobject(iprot);
    
  }
 this->__isset.set(1, true);

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          2,
          3,
          apache::thrift::protocol::T_STRING))) {
    goto _advance_failure;
  }
_readField_data:
  {
    ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::binary, ::apache::thrift::type::ByteBuffer>::readWithContext(*iprot, this->__fbthrift_field_data, _readState);
    
  }
 this->__isset.set(2, true);

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          3,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _advance_failure;
  }

_end:
  _readState.readStructEnd(iprot);

  return;

  goto _advance_failure; // Avoid compiler warnings about unused labels.
  _advance_failure:
  _readState.afterAdvanceFailure(iprot);
_loop:
  if (_readState.atStop()) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<AnyStruct>>();
  }

  switch (_readState.fieldId) {
    case 1:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRUCT))) {
        goto _readField_type;
      } else {
        goto _skip;
      }
    }
    case 2:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRUCT))) {
        goto _readField_protocol;
      } else {
        goto _skip;
      }
    }
    case 3:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRING))) {
        goto _readField_data;
      } else {
        goto _skip;
      }
    }
    default:
    {
_skip:
      _readState.skip(iprot);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t AnyStruct::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("AnyStruct");
  {
    xfer += prot_->serializedFieldSize("type", apache::thrift::protocol::T_STRUCT, 1);
    xfer += ::apache::thrift::op::serialized_size<false, ::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Type>, ::apache::thrift::type::struct_t<::apache::thrift::type::TypeStruct>>>(*prot_, this->__fbthrift_field_type);
  }
  {
    xfer += prot_->serializedFieldSize("protocol", apache::thrift::protocol::T_STRUCT, 2);
    xfer += ::apache::thrift::op::serialized_size<false, ::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Protocol>, ::apache::thrift::type::union_t<::apache::thrift::type::ProtocolUnion>>>(*prot_, this->__fbthrift_field_protocol);
  }
  {
    xfer += prot_->serializedFieldSize("data", apache::thrift::protocol::T_STRING, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::binary, ::apache::thrift::type::ByteBuffer>::serializedSize<false>(*prot_, this->__fbthrift_field_data);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t AnyStruct::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("AnyStruct");
  {
    xfer += prot_->serializedFieldSize("type", apache::thrift::protocol::T_STRUCT, 1);
    xfer += ::apache::thrift::op::serialized_size<true, ::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Type>, ::apache::thrift::type::struct_t<::apache::thrift::type::TypeStruct>>>(*prot_, this->__fbthrift_field_type);
  }
  {
    xfer += prot_->serializedFieldSize("protocol", apache::thrift::protocol::T_STRUCT, 2);
    xfer += ::apache::thrift::op::serialized_size<true, ::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Protocol>, ::apache::thrift::type::union_t<::apache::thrift::type::ProtocolUnion>>>(*prot_, this->__fbthrift_field_protocol);
  }
  {
    xfer += prot_->serializedFieldSize("data", apache::thrift::protocol::T_STRING, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::binary, ::apache::thrift::type::ByteBuffer>::serializedSize<true>(*prot_, this->__fbthrift_field_data);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t AnyStruct::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("AnyStruct");
  bool previousFieldHasValue = true;
  {
    constexpr int16_t kPrevFieldId = 0;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_STRUCT, 1, kPrevFieldId>(*prot_, "type", previousFieldHasValue);
    previousFieldHasValue = true;
    xfer += ::apache::thrift::op::encode<::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Type>, ::apache::thrift::type::struct_t<::apache::thrift::type::TypeStruct>>>(*prot_, this->__fbthrift_field_type);
    xfer += prot_->writeFieldEnd();
  }
  {
    constexpr int16_t kPrevFieldId = 1;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_STRUCT, 2, kPrevFieldId>(*prot_, "protocol", previousFieldHasValue);
    previousFieldHasValue = true;
    xfer += ::apache::thrift::op::encode<::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Protocol>, ::apache::thrift::type::union_t<::apache::thrift::type::ProtocolUnion>>>(*prot_, this->__fbthrift_field_protocol);
    xfer += prot_->writeFieldEnd();
  }
  {
    constexpr int16_t kPrevFieldId = 2;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_STRING, 3, kPrevFieldId>(*prot_, "data", previousFieldHasValue);
    previousFieldHasValue = true;
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::binary, ::apache::thrift::type::ByteBuffer>::write(*prot_, this->__fbthrift_field_data);
    xfer += prot_->writeFieldEnd();
  }
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void AnyStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t AnyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t AnyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t AnyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void AnyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t AnyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t AnyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t AnyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


template <class Protocol_>
void SemiAnyStruct::readNoXfer(Protocol_* iprot) {
  __fbthrift_clear_terse_fields();

  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;


  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          1,
          apache::thrift::protocol::T_STRUCT))) {
    goto _advance_failure;
  }
_readField_type:
  {
    _readState.beforeSubobject(iprot);
    ::apache::thrift::op::decode<::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Type>, ::apache::thrift::type::struct_t<::apache::thrift::type::TypeStruct>>>(*iprot, this->__fbthrift_field_type);
    _readState.afterSubobject(iprot);
    
  }
 this->__isset.set(0, true);

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          1,
          2,
          apache::thrift::protocol::T_STRUCT))) {
    goto _advance_failure;
  }
_readField_protocol:
  {
    _readState.beforeSubobject(iprot);
    ::apache::thrift::op::decode<::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Protocol>, ::apache::thrift::type::union_t<::apache::thrift::type::ProtocolUnion>>>(*iprot, this->__fbthrift_field_protocol);
    _readState.afterSubobject(iprot);
    
  }
 this->__isset.set(1, true);

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          2,
          3,
          apache::thrift::protocol::T_STRING))) {
    goto _advance_failure;
  }
_readField_data:
  {
    ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::binary, ::apache::thrift::type::ByteBuffer>::readWithContext(*iprot, this->__fbthrift_field_data, _readState);
    
  }
 this->__isset.set(2, true);

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          3,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _advance_failure;
  }

_end:
  _readState.readStructEnd(iprot);

  return;

  goto _advance_failure; // Avoid compiler warnings about unused labels.
  _advance_failure:
  _readState.afterAdvanceFailure(iprot);
_loop:
  if (_readState.atStop()) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<SemiAnyStruct>>();
  }

  switch (_readState.fieldId) {
    case 1:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRUCT))) {
        goto _readField_type;
      } else {
        goto _skip;
      }
    }
    case 2:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRUCT))) {
        goto _readField_protocol;
      } else {
        goto _skip;
      }
    }
    case 3:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_STRING))) {
        goto _readField_data;
      } else {
        goto _skip;
      }
    }
    default:
    {
_skip:
      _readState.skip(iprot);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t SemiAnyStruct::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("SemiAnyStruct");
  {
    xfer += prot_->serializedFieldSize("type", apache::thrift::protocol::T_STRUCT, 1);
    xfer += ::apache::thrift::op::serialized_size<false, ::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Type>, ::apache::thrift::type::struct_t<::apache::thrift::type::TypeStruct>>>(*prot_, this->__fbthrift_field_type);
  }
  {
    xfer += prot_->serializedFieldSize("protocol", apache::thrift::protocol::T_STRUCT, 2);
    xfer += ::apache::thrift::op::serialized_size<false, ::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Protocol>, ::apache::thrift::type::union_t<::apache::thrift::type::ProtocolUnion>>>(*prot_, this->__fbthrift_field_protocol);
  }
  {
    xfer += prot_->serializedFieldSize("data", apache::thrift::protocol::T_STRING, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::binary, ::apache::thrift::type::ByteBuffer>::serializedSize<false>(*prot_, this->__fbthrift_field_data);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t SemiAnyStruct::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("SemiAnyStruct");
  {
    xfer += prot_->serializedFieldSize("type", apache::thrift::protocol::T_STRUCT, 1);
    xfer += ::apache::thrift::op::serialized_size<true, ::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Type>, ::apache::thrift::type::struct_t<::apache::thrift::type::TypeStruct>>>(*prot_, this->__fbthrift_field_type);
  }
  {
    xfer += prot_->serializedFieldSize("protocol", apache::thrift::protocol::T_STRUCT, 2);
    xfer += ::apache::thrift::op::serialized_size<true, ::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Protocol>, ::apache::thrift::type::union_t<::apache::thrift::type::ProtocolUnion>>>(*prot_, this->__fbthrift_field_protocol);
  }
  {
    xfer += prot_->serializedFieldSize("data", apache::thrift::protocol::T_STRING, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::binary, ::apache::thrift::type::ByteBuffer>::serializedSize<true>(*prot_, this->__fbthrift_field_data);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t SemiAnyStruct::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("SemiAnyStruct");
  bool previousFieldHasValue = true;
  {
    constexpr int16_t kPrevFieldId = 0;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_STRUCT, 1, kPrevFieldId>(*prot_, "type", previousFieldHasValue);
    previousFieldHasValue = true;
    xfer += ::apache::thrift::op::encode<::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Type>, ::apache::thrift::type::struct_t<::apache::thrift::type::TypeStruct>>>(*prot_, this->__fbthrift_field_type);
    xfer += prot_->writeFieldEnd();
  }
  {
    constexpr int16_t kPrevFieldId = 1;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_STRUCT, 2, kPrevFieldId>(*prot_, "protocol", previousFieldHasValue);
    previousFieldHasValue = true;
    xfer += ::apache::thrift::op::encode<::apache::thrift::type::adapted<::apache::thrift::InlineAdapter<::apache::thrift::type::Protocol>, ::apache::thrift::type::union_t<::apache::thrift::type::ProtocolUnion>>>(*prot_, this->__fbthrift_field_protocol);
    xfer += prot_->writeFieldEnd();
  }
  {
    constexpr int16_t kPrevFieldId = 2;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_STRING, 3, kPrevFieldId>(*prot_, "data", previousFieldHasValue);
    previousFieldHasValue = true;
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::binary, ::apache::thrift::type::ByteBuffer>::write(*prot_, this->__fbthrift_field_data);
    xfer += prot_->writeFieldEnd();
  }
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void SemiAnyStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t SemiAnyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t SemiAnyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t SemiAnyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void SemiAnyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t SemiAnyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t SemiAnyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t SemiAnyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


} // namespace apache::thrift::type
