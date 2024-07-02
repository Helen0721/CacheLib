// automatically @generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SERIALIZATIONBENCHMARK_APACHE_THRIFT_BENCHMARKS_H_
#define FLATBUFFERS_GENERATED_SERIALIZATIONBENCHMARK_APACHE_THRIFT_BENCHMARKS_H_

#include "flatbuffers/flatbuffers.h"

namespace apache {
namespace thrift {
namespace benchmarks {

struct StringToUByteMap;
struct StringToUByteMapBuilder;

struct FBStruct1;
struct FBStruct1Builder;

struct StringToUByteMap FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef StringToUByteMapBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_KEY = 4,
    VT_VALUE = 6
  };
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(VT_KEY);
  }
  bool KeyCompareLessThan(const StringToUByteMap *o) const {
    return *key() < *o->key();
  }
  int KeyCompareWithValue(const char *val) const {
    return strcmp(key()->c_str(), val);
  }
  uint8_t value() const {
    return GetField<uint8_t>(VT_VALUE, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_KEY) &&
           verifier.VerifyString(key()) &&
           VerifyField<uint8_t>(verifier, VT_VALUE) &&
           verifier.EndTable();
  }
};

struct StringToUByteMapBuilder {
  typedef StringToUByteMap Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(StringToUByteMap::VT_KEY, key);
  }
  void add_value(uint8_t value) {
    fbb_.AddElement<uint8_t>(StringToUByteMap::VT_VALUE, value, 0);
  }
  explicit StringToUByteMapBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<StringToUByteMap> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<StringToUByteMap>(end);
    fbb_.Required(o, StringToUByteMap::VT_KEY);
    return o;
  }
};

inline flatbuffers::Offset<StringToUByteMap> CreateStringToUByteMap(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    uint8_t value = 0) {
  StringToUByteMapBuilder builder_(_fbb);
  builder_.add_key(key);
  builder_.add_value(value);
  return builder_.Finish();
}

inline flatbuffers::Offset<StringToUByteMap> CreateStringToUByteMapDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr,
    uint8_t value = 0) {
  auto key__ = key ? _fbb.CreateString(key) : 0;
  return apache::thrift::benchmarks::CreateStringToUByteMap(
      _fbb,
      key__,
      value);
}

struct FBStruct1 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef FBStruct1Builder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_FIELD_1 = 4,
    VT_FIELD_2 = 6,
    VT_FIELD_3 = 8,
    VT_FIELD_4 = 10
  };
  int32_t field_1() const {
    return GetField<int32_t>(VT_FIELD_1, 0);
  }
  const flatbuffers::String *field_2() const {
    return GetPointer<const flatbuffers::String *>(VT_FIELD_2);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *field_3() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_FIELD_3);
  }
  const flatbuffers::Vector<flatbuffers::Offset<apache::thrift::benchmarks::StringToUByteMap>> *field_4() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<apache::thrift::benchmarks::StringToUByteMap>> *>(VT_FIELD_4);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_FIELD_1) &&
           VerifyOffset(verifier, VT_FIELD_2) &&
           verifier.VerifyString(field_2()) &&
           VerifyOffset(verifier, VT_FIELD_3) &&
           verifier.VerifyVector(field_3()) &&
           verifier.VerifyVectorOfStrings(field_3()) &&
           VerifyOffset(verifier, VT_FIELD_4) &&
           verifier.VerifyVector(field_4()) &&
           verifier.VerifyVectorOfTables(field_4()) &&
           verifier.EndTable();
  }
};

struct FBStruct1Builder {
  typedef FBStruct1 Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_field_1(int32_t field_1) {
    fbb_.AddElement<int32_t>(FBStruct1::VT_FIELD_1, field_1, 0);
  }
  void add_field_2(flatbuffers::Offset<flatbuffers::String> field_2) {
    fbb_.AddOffset(FBStruct1::VT_FIELD_2, field_2);
  }
  void add_field_3(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> field_3) {
    fbb_.AddOffset(FBStruct1::VT_FIELD_3, field_3);
  }
  void add_field_4(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<apache::thrift::benchmarks::StringToUByteMap>>> field_4) {
    fbb_.AddOffset(FBStruct1::VT_FIELD_4, field_4);
  }
  explicit FBStruct1Builder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<FBStruct1> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<FBStruct1>(end);
    return o;
  }
};

inline flatbuffers::Offset<FBStruct1> CreateFBStruct1(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t field_1 = 0,
    flatbuffers::Offset<flatbuffers::String> field_2 = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> field_3 = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<apache::thrift::benchmarks::StringToUByteMap>>> field_4 = 0) {
  FBStruct1Builder builder_(_fbb);
  builder_.add_field_4(field_4);
  builder_.add_field_3(field_3);
  builder_.add_field_2(field_2);
  builder_.add_field_1(field_1);
  return builder_.Finish();
}

inline flatbuffers::Offset<FBStruct1> CreateFBStruct1Direct(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t field_1 = 0,
    const char *field_2 = nullptr,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *field_3 = nullptr,
    std::vector<flatbuffers::Offset<apache::thrift::benchmarks::StringToUByteMap>> *field_4 = nullptr) {
  auto field_2__ = field_2 ? _fbb.CreateString(field_2) : 0;
  auto field_3__ = field_3 ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*field_3) : 0;
  auto field_4__ = field_4 ? _fbb.CreateVectorOfSortedTables<apache::thrift::benchmarks::StringToUByteMap>(field_4) : 0;
  return apache::thrift::benchmarks::CreateFBStruct1(
      _fbb,
      field_1,
      field_2__,
      field_3__,
      field_4__);
}

}  // namespace benchmarks
}  // namespace thrift
}  // namespace apache

#endif  // FLATBUFFERS_GENERATED_SERIALIZATIONBENCHMARK_APACHE_THRIFT_BENCHMARKS_H_
