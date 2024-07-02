/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <Python.h>

#include <limits>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <folly/Optional.h>
#include <folly/python/error.h>

#include <thrift/lib/cpp2/protocol/TableBasedSerializer.h>

namespace apache {
namespace thrift {
namespace python {

inline PyObject* const* toPyObjectPtr(const void* object) {
  return static_cast<PyObject* const*>(object);
}

inline PyObject** toPyObjectPtr(void* object) {
  return static_cast<PyObject**>(object);
}

inline const PyObject* toPyObject(const void* object) {
  return static_cast<const PyObject*>(object);
}

inline PyObject* toPyObject(void* object) {
  return static_cast<PyObject*>(object);
}

#define THRIFT_PY3_STRINGIFY_LINE(LINE) #LINE
#define THRIFT_PY3_ERROR_LOCATION(LINE) \
  "Python error occurred at " __FILE__ ":" THRIFT_PY3_STRINGIFY_LINE(LINE) ": "
#define THRIFT_PY3_CHECK_ERROR() \
  folly::python::handlePythonError(THRIFT_PY3_ERROR_LOCATION(__LINE__))

#define THRIFT_PY3_CHECK_POSSIBLE_ERROR() \
  do {                                    \
    if (PyErr_Occurred()) {               \
      THRIFT_PY3_CHECK_ERROR();           \
    }                                     \
  } while (false)

template <typename T, typename V>
inline T convInt(V v) {
  if (v >= std::numeric_limits<T>::min() &&
      v <= std::numeric_limits<T>::max()) {
    return static_cast<T>(v);
  }
  LOG(FATAL) << "int out of range";
}

PyObject* createUnionTuple();

/***
 * Returns a new "struct tuple" whose field elements are uninitialized.
 *
 * The returned tuple has `numFields + 1` elements.
 *
 * The first element is a bytearray of `numFields` bytes, all of which are
 * initialized to 0. It is typically meant to be used as an array of isset
 * flags.
 *
 * The remaining `numFields` elements of the tuple are uninitialized.
 *
 * See also: `createStructTupleWithDefaultValues()`.
 */
PyObject* createStructTuple(int16_t numFields);

/**
 * Returns a new "struct tuple" associated with an immutable Thrift struct,
 * all elements initialized with default values.
 *
 * As in `createStructTuple()`, the first element of the tuple is a
 * 0-initialized bytearray with `numFields` bytes (to be used as isset flags).
 *
 * However, the remaining elements (1 through `numFields + 1`) are initialized
 * with the appropriate default value for the corresponding field (see below).
 * The order corresponds to the order of fields in the given `structInfo` (i.e.,
 * the insertion order, NOT the field ids).
 *
 * The default value for optional fields is always `Py_None`. For other fields,
 * the default value is either specified by the user or the following "standard"
 * value for the corresponding type:
 *   * `0L` for integral numbers.
 *   * `0d` for floating-point numbers.
 *   * `false` for booleans.
 *   * `""` (i.e., the empty string) for strings and `binary` fields (or an
 *      empty `IOBuf` if  applicable).
 *   * empty tuple for lists and maps.
 *   * empty `frozenset` for sets.
 *   * recursively default-initialized instance for structs and unions.
 *
 * All values in the returned tuple are stored in the "internal data"
 * representation (as opposed to the "Python value" representation - see the
 * various `*TypeInfo` Python classes). For example, `false` is actually
 * `Py_False`.
 */
PyObject* createImmutableStructTupleWithDefaultValues(
    const detail::StructInfo& structInfo);

/**
 * Returns a new "struct tuple" associated with an mutable Thrift struct,
 * all elements initialized with default values.
 *
 * This function is very similar to its immutable counterpart. Please see the
 * `createImmutableStructTupleWithDefaultValues()` documentation for more
 * details.
 *
 * The following list only highlights the difference for the "standard" value
 * for the corresponding type:
 *   * In the mutable version, the standard value for lists is an empty `list`.
 */
PyObject* createMutableStructTupleWithDefaultValues(
    const detail::StructInfo& structInfo);

/**
 * Sets the "isset" flag of the `index`-th field of the given struct tuple
 * `object` to the given `value`.
 *
 * @param object Pointer to a "struct tuple" (see `createStructTuple() above).
 *        This is assumed to be a `PyTupleObject`, whose memory holds the
 *        elements (starting with the "isset" bytearray) after a header
 *        consisting of `PyVarObject`. The memory immediately after the
 *        `sizeof(PyVarObject)` bytes is expected to correspond to a
 *        `PyBytesObject` that holds the isset flags bytearray (see above).
 *        If the bytearray is not properly initialized, or `index` is invalid
 *        (i.e., negative or greather than the number of fields), behavior is
 *        undefined.
 *
 * @throws if unable to read a bytearray from the expected isset flags bytearray
 *         (see `object` param documentation above).
 */
void setStructIsset(void* object, int16_t index, bool value);

/*
 * Returns a new "struct tuple" with all its elements set to `None`
 * (i.e., `Py_None`).
 *
 * As in `createStructTuple()`, the first element of the tuple is a
 * 0-initialized bytearray with `numFields` bytes (to be used as isset flags).
 *
 * However, the remaining elements (1 through `numFields + 1`) are set to `None`
 *
 */
PyObject* createStructTupleWithNones(const detail::StructInfo& structInfo);

/**
 * Populates unset fields of a immutable Thrift struct's "struct tuple" with
 * default values.
 *
 * The `object` should be a valid `tuple` created by `createStructTuple()`
 *
 * Iterates through the elements (from 1 to `numFields + 1`). If a field
 * is unset, it gets populated with the corresponding default value.
 *
 * Throws on error
 *
 */
void populateImmutableStructTupleUnsetFieldsWithDefaultValues(
    PyObject* object, const detail::StructInfo& structInfo);

/**
 * Populates unset fields of a mutable Thrift struct's "struct tuple" with
 * default values.
 *
 * This function is very similar to its immutable counterpart. Please see the
 * `populateImmutableStructTupleUnsetFieldsWithDefaultValues()` documentation.
 * The only difference is the "standard" value for the corresponding type.
 *
 * See `getStandard{Mutable,Immutable}DefaultValueForType()` documentation.
 *
 * Throws on error
 */
void populateMutableStructTupleUnsetFieldsWithDefaultValues(
    PyObject* object, const detail::StructInfo& structInfo);

/**
 * Resets the field at `index` of the "struct tuple" with the default value.
 *
 * Throws on error
 */
void resetFieldToStandardDefault(
    PyObject* tuple, const detail::StructInfo& structInfo, int index);

struct PyObjectDeleter {
  void operator()(PyObject* p) { Py_XDECREF(p); }
};

using UniquePyObjectPtr = std::unique_ptr<PyObject, PyObjectDeleter>;

/**
 * Sets the Python object pointed to by `object` to the given `value` (releasing
 * the previous one, if any).
 *
 * @params object double pointer to a `PyObject` (i.e., `PyObject**`).
 *
 * @return the newly set Python object pointer, i.e. the pointer previously held
 *         by the `value` parameter (and now pointed to by `object`).
 */
inline PyObject* setPyObject(void* object, UniquePyObjectPtr value) {
  PyObject** pyObjPtr = toPyObjectPtr(object);
  PyObject* oldObject = *pyObjPtr;
  *pyObjPtr = value.release();
  Py_XDECREF(oldObject);
  return *pyObjPtr;
}

inline UniquePyObjectPtr primitiveCppToPython(bool value) {
  PyObject* ret = value ? Py_True : Py_False;
  Py_INCREF(ret);
  return UniquePyObjectPtr{ret};
}

inline UniquePyObjectPtr primitiveCppToPython(std::int32_t value) {
  if (UniquePyObjectPtr ret{PyLong_FromLong(value)}) {
    return ret;
  }
  THRIFT_PY3_CHECK_ERROR();
}

inline UniquePyObjectPtr primitiveCppToPython(std::int8_t value) {
  return primitiveCppToPython(static_cast<std::int32_t>(value));
}

inline UniquePyObjectPtr primitiveCppToPython(std::int16_t value) {
  return primitiveCppToPython(static_cast<std::int32_t>(value));
}

inline UniquePyObjectPtr primitiveCppToPython(std::int64_t value) {
  if (UniquePyObjectPtr ret{PyLong_FromLongLong(value)}) {
    return ret;
  }
  THRIFT_PY3_CHECK_ERROR();
}

inline UniquePyObjectPtr primitiveCppToPython(float value) {
  if (UniquePyObjectPtr ret{PyFloat_FromDouble(value)}) {
    return ret;
  }
  THRIFT_PY3_CHECK_ERROR();
}

inline UniquePyObjectPtr primitiveCppToPython(double value) {
  if (UniquePyObjectPtr ret{PyFloat_FromDouble(value)}) {
    return ret;
  }
  THRIFT_PY3_CHECK_ERROR();
}

template <typename PrimitiveType>
detail::ThriftValue primitivePythonToCpp(PyObject* object);

template <>
inline detail::ThriftValue primitivePythonToCpp<bool>(PyObject* object) {
  DCHECK(object == Py_True || object == Py_False);
  return detail::ThriftValue{object == Py_True};
}

template <typename T>
inline detail::ThriftValue pyLongToCpp(PyObject* object) {
  auto value = PyLong_AsLong(object);
  if (value == -1) {
    THRIFT_PY3_CHECK_POSSIBLE_ERROR();
  }
  return detail::ThriftValue{convInt<T>(value)};
}

template <>
inline detail::ThriftValue primitivePythonToCpp<std::int8_t>(PyObject* object) {
  return pyLongToCpp<std::int8_t>(object);
}

template <>
inline detail::ThriftValue primitivePythonToCpp<std::int16_t>(
    PyObject* object) {
  return pyLongToCpp<std::int16_t>(object);
}

template <>
inline detail::ThriftValue primitivePythonToCpp<std::int32_t>(
    PyObject* object) {
  return pyLongToCpp<std::int32_t>(object);
}

template <>
inline detail::ThriftValue primitivePythonToCpp<std::int64_t>(
    PyObject* object) {
  auto value = PyLong_AsLongLong(object);
  if (value == -1) {
    THRIFT_PY3_CHECK_POSSIBLE_ERROR();
  }
  return detail::ThriftValue{convInt<std::int64_t>(value)};
}

template <>
inline detail::ThriftValue primitivePythonToCpp<double>(PyObject* object) {
  auto value = PyFloat_AsDouble(object);
  if (value == -1.0) {
    THRIFT_PY3_CHECK_POSSIBLE_ERROR();
  }
  return detail::ThriftValue{value};
}

template <>
inline detail::ThriftValue primitivePythonToCpp<float>(PyObject* object) {
  auto value = PyFloat_AsDouble(object);
  if (value == -1.0) {
    THRIFT_PY3_CHECK_POSSIBLE_ERROR();
  }
  return detail::ThriftValue{static_cast<float>(value)};
}

template <typename PrimitiveType, protocol::TType Type>
struct PrimitiveTypeInfo {
  static detail::OptionalThriftValue get(
      const void* object, const detail::TypeInfo& /* typeInfo */) {
    PyObject* pyObj = *toPyObjectPtr(object);
    return folly::make_optional<detail::ThriftValue>(
        primitivePythonToCpp<PrimitiveType>(pyObj));
  }

  static void set(void* object, PrimitiveType value) {
    setPyObject(object, primitiveCppToPython(value));
  }

  static const detail::TypeInfo typeInfo;
};

template <typename PrimitiveType, protocol::TType Type>
const detail::TypeInfo PrimitiveTypeInfo<PrimitiveType, Type>::typeInfo{
    /* .type */ Type,
    /* .get */ get,
    /* .set */ reinterpret_cast<detail::VoidFuncPtr>(set),
    /* .typeExt */ nullptr,
};

extern const detail::TypeInfo& boolTypeInfo;
extern const detail::TypeInfo& byteTypeInfo;
extern const detail::TypeInfo& i16TypeInfo;
extern const detail::TypeInfo& i32TypeInfo;
extern const detail::TypeInfo& i64TypeInfo;
extern const detail::TypeInfo& doubleTypeInfo;
extern const detail::TypeInfo& floatTypeInfo;
extern const detail::TypeInfo stringTypeInfo;
extern const detail::TypeInfo binaryTypeInfo;
extern const detail::TypeInfo iobufTypeInfo;

detail::OptionalThriftValue getStruct(
    const void* object, const detail::TypeInfo& /* typeInfo */);
inline void* setContainer(void* object) {
  if (!setPyObject(object, UniquePyObjectPtr{PyTuple_New(0)})) {
    THRIFT_PY3_CHECK_ERROR();
  }
  return object;
}

inline void* setFrozenSet(void* object) {
  if (!setPyObject(object, UniquePyObjectPtr{PyFrozenSet_New(nullptr)})) {
    THRIFT_PY3_CHECK_ERROR();
  }
  return object;
}

class ListTypeInfo {
 public:
  static std::uint32_t size(const void* object) {
    return PyTuple_GET_SIZE(toPyObject(object));
  }

  static void clear(void* object) { setContainer(object); }

  static void read(
      const void* context,
      void* object,
      std::uint32_t listSize,
      void (*reader)(const void* /*context*/, void* /*val*/));
  static size_t write(
      const void* context,
      const void* object,
      size_t (*writer)(const void* /*context*/, const void* /*val*/));

  static void consumeElem(
      const void* context,
      void* object,
      void (*reader)(const void* /*context*/, void* /*val*/));

  explicit ListTypeInfo(const detail::TypeInfo* valInfo)
      : ext_{
            /* .valInfo */ valInfo,
            /* .size */ size,
            /* .clear */ clear,
            /* .consumeElem */ consumeElem,
            /* .readList */ read,
            /* .writeList */ write,
        },
        typeinfo_{
            protocol::TType::T_LIST,
            getStruct,
            reinterpret_cast<detail::VoidFuncPtr>(setContainer),
            &ext_,
        } {}
  inline const detail::TypeInfo* get() const { return &typeinfo_; }

 private:
  const detail::ListFieldExt ext_;
  const detail::TypeInfo typeinfo_;
};

class SetTypeInfo {
 public:
  static std::uint32_t size(const void* object) {
    return PySet_GET_SIZE(toPyObject(object));
  }

  static void clear(void* object) { setFrozenSet(object); }

  static void read(
      const void* context,
      void* object,
      std::uint32_t setSize,
      void (*reader)(const void* /*context*/, void* /*val*/));

  static size_t write(
      const void* context,
      const void* object,
      bool protocolSortKeys,
      size_t (*writer)(const void* /*context*/, const void* /*val*/));

  static void consumeElem(
      const void* context,
      void* object,
      void (*reader)(const void* /*context*/, void* /*val*/));

  explicit SetTypeInfo(const detail::TypeInfo* valInfo)
      : ext_{
            /* .valInfo */ valInfo,
            /* .size */ size,
            /* .clear */ clear,
            /* .consumeElem */ consumeElem,
            /* .readSet */ read,
            /* .writeSet */ write,
        },
        typeinfo_{
            protocol::TType::T_SET,
            getStruct,
            reinterpret_cast<detail::VoidFuncPtr>(setFrozenSet),
            &ext_,
        } {}
  const detail::TypeInfo* get() const { return &typeinfo_; }

 private:
  const detail::SetFieldExt ext_;
  const detail::TypeInfo typeinfo_;
};

class MapTypeInfo {
 public:
  static std::uint32_t size(const void* object) {
    return PyTuple_GET_SIZE(toPyObject(object));
  }

  static void clear(void* object) { setContainer(object); }

  static void read(
      const void* context,
      void* object,
      std::uint32_t mapSize,
      void (*keyReader)(const void* context, void* key),
      void (*valueReader)(const void* context, void* val));

  static size_t write(
      const void* context,
      const void* object,
      bool protocolSortKeys,
      size_t (*writer)(
          const void* context, const void* keyElem, const void* valueElem));

  static void consumeElem(
      const void* context,
      void* object,
      void (*keyReader)(const void* /*context*/, void* /*val*/),
      void (*valueReader)(const void* /*context*/, void* /*val*/));

  explicit MapTypeInfo(
      const detail::TypeInfo* keyInfo, const detail::TypeInfo* valInfo)
      : ext_{
            /* .keyInfo */ keyInfo,
            /* .valInfo */ valInfo,
            /* .size */ size,
            /* .clear */ clear,
            /* .consumeElem */ consumeElem,
            /* .readSet */ read,
            /* .writeSet */ write,
        },
        typeinfo_{
            protocol::TType::T_MAP,
            getStruct,
            reinterpret_cast<detail::VoidFuncPtr>(setContainer),
            &ext_,
        } {}
  const detail::TypeInfo* get() const { return &typeinfo_; }

 private:
  const detail::MapFieldExt ext_;
  const detail::TypeInfo typeinfo_;
};

using FieldValueMap = std::unordered_map<int16_t, PyObject*>;

class DynamicStructInfo {
 public:
  DynamicStructInfo(const char* name, int16_t numFields, bool isUnion = false);

  // DynamicStructInfo is non-copyable
  DynamicStructInfo(const DynamicStructInfo&) = delete;
  void operator=(const DynamicStructInfo&) = delete;

  ~DynamicStructInfo();

  /**
   * Returns the underlying `StructInfo`, populated with all field infos and
   * values added via the `addField*()` methods.
   */
  const detail::StructInfo& getStructInfo() const { return *structInfo_; }

  /**
   * Adds information for a new field to the underlying `StructInfo`.
   *
   * The order of `FieldInfo` in the underlying `StructInfo` corresponds to the
   * order in which this method is called. Calling this method more than the
   * `numFields` value specified at construction time results in undefined
   * behavior.
   */
  void addFieldInfo(
      detail::FieldID id,
      detail::FieldQualifier qualifier,
      const char* name,
      const detail::TypeInfo* typeInfo);

  /**
   * Sets the value for the field with the given `index`.
   *
   * The given `fieldValue` will be included in the underlying
   * `StructInfo::customExt`, at the given `index`. It is expected to be in the
   * "internal data" representation (see `to_internal_data()` methods in the
   * various `*TypeInfo` classes in Python).
   *
   * If `fieldValue` is `nullptr`, behavior is undefined.
   */
  void addFieldValue(int16_t index, PyObject* fieldValue);

  bool isUnion() const { return structInfo_->unionExt != nullptr; }

 private:
  /**
   * Pointer to a region of memory that holds a `StructInfo` followed by
   * `numFields` instances of `FieldInfo` (accessible through
   * `structInfo->fieldInfos`).
   *
   * ------------------------------------------------
   * | StructInfo    |  FieldInfo | ... | FieldInfo |
   * ------------------------------------------------
   * ^                      (numFields times)
   *
   * The `customExt` field of this StructInfo points to `fieldValues_`.
   */
  detail::StructInfo* structInfo_;

  std::string name_;

  /**
   * Names of the fields added via `addFieldInfo()`, in the order they were
   * added.
   *
   * The same order is used for the corresponding `FieldInfo` entries in
   * `structInfo_`.
   */
  std::vector<std::string> fieldNames_;

  /**
   * Default values (if any) for each field (indexed by field position in
   * `fieldNames_`).
   *
   * If present, values are in the "internal data" representation (as opposed to
   * the "Python value" representation - see the various `*TypeInfo` Python
   * classes).
   */
  FieldValueMap fieldValues_;
};

detail::TypeInfo createImmutableStructTypeInfo(
    const DynamicStructInfo& dynamicStructInfo);

namespace capi {
/**
 * Retrieves internal _fbthrift_data from `StructOrUnion`. On import failure,
 * returns nullptr. Caller is responsible for clearing Err indicator on failure.
 * Do not use externally; use capi interface instead.
 */
PyObject* FOLLY_NULLABLE getThriftData(PyObject* structOrUnion);
/**
 * Retrieves internal _fbthrift_data from `GeneratedError`. On import failure,
 * returns nullptr. Caller is responsible for clearing Err indicator on failure.
 * Do not use externally; use capi interface instead.
 */
PyObject* FOLLY_NULLABLE getExceptionThriftData(PyObject* generatedError);

/**
 * Sets index + 1 field of struct_tuple to `value` and records that is set
 * in the isset array at field 0. Returns 0 on success and -1 on failure.
 * Only for use with fresh struct_tuple (i.e., no set field values)
 */
int setStructField(PyObject* struct_tuple, int16_t index, PyObject* value);
/**
 * Creates a union tuple of size 2.
 * Sets index 0 of union_tuple to python int created from type_key
 * Sets index 1 of union_tuple to value.
 * Returns nullptr on failure, union tuple on success.
 */
PyObject* unionTupleFromValue(int64_t type_key, PyObject* value);

} // namespace capi

} // namespace python
} // namespace thrift
} // namespace apache
