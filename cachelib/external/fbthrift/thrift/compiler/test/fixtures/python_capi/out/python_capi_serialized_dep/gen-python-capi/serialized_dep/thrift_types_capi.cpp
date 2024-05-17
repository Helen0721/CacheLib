
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT
 *  @generated
 *
 */

#include <folly/python/import.h>
#include <thrift/lib/python/capi/iobuf.h>
#include <thrift/lib/python/types.h>

#include <thrift/compiler/test/fixtures/python_capi/gen-python-capi/serialized_dep/thrift_types_api.h>
#include <thrift/compiler/test/fixtures/python_capi/gen-python-capi/serialized_dep/thrift_types_capi.h>


namespace apache {
namespace thrift {
namespace python {
namespace capi {
namespace {
bool ensure_module_imported() {
  static ::folly::python::import_cache_nocapture import((
      ::import_test__fixtures__python_capi__serialized_dep__thrift_types_capi));
  return import();
}
  static constexpr std::int16_t _fbthrift__MarshalStruct__tuple_pos[4] = {
    1, 2, 3, 4
  };
  static constexpr std::int16_t _fbthrift__MarshalError__tuple_pos[3] = {
    1, 2, 3
  };
} // namespace

ExtractorResult<::test::fixtures::python_capi::SerializedStruct>
Extractor<::test::fixtures::python_capi::SerializedStruct>::operator()(PyObject* obj) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return extractorError<::test::fixtures::python_capi::SerializedStruct>(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  std::unique_ptr<folly::IOBuf> val(
      extract__test__fixtures__python_capi__serialized_dep__SerializedStruct(obj));
  if (!val) {
    CHECK(PyErr_Occurred());
    return extractorError<::test::fixtures::python_capi::SerializedStruct>(
        "Thrift serialize error: SerializedStruct");
  }
  return detail::deserialize_iobuf<::test::fixtures::python_capi::SerializedStruct>(std::move(val));
}


ExtractorResult<::test::fixtures::python_capi::SerializedStruct>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::test::fixtures::python_capi::SerializedStruct>>::operator()(PyObject* fbthrift_data) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return extractorError<::test::fixtures::python_capi::SerializedStruct>(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  auto obj = StrongRef(init__test__fixtures__python_capi__serialized_dep__SerializedStruct(fbthrift_data));
  if (!obj) {
      return extractorError<::test::fixtures::python_capi::SerializedStruct>(
          "Init from fbthrift error: SerializedStruct");
  }
  return Extractor<::test::fixtures::python_capi::SerializedStruct>{}(*obj);
}

int Extractor<::test::fixtures::python_capi::SerializedStruct>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  int result =
      can_extract__test__fixtures__python_capi__serialized_dep__SerializedStruct(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: SerializedStruct");
  }
  return result;
}


PyObject* Constructor<::test::fixtures::python_capi::SerializedStruct>::operator()(
    const ::test::fixtures::python_capi::SerializedStruct& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  auto ptr = construct__test__fixtures__python_capi__serialized_dep__SerializedStruct(
      detail::serialize_to_iobuf(val));
  if (!ptr) {
    CHECK(PyErr_Occurred());
  }
  return ptr;
}


PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::test::fixtures::python_capi::SerializedStruct>>::operator()(
    const ::test::fixtures::python_capi::SerializedStruct& val) {
  auto obj = StrongRef(Constructor<::test::fixtures::python_capi::SerializedStruct>{}(val));
  if (!obj) {
    return nullptr;
  }
  return getThriftData(*obj);
}

ExtractorResult<::test::fixtures::python_capi::SerializedUnion>
Extractor<::test::fixtures::python_capi::SerializedUnion>::operator()(PyObject* obj) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return extractorError<::test::fixtures::python_capi::SerializedUnion>(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  std::unique_ptr<folly::IOBuf> val(
      extract__test__fixtures__python_capi__serialized_dep__SerializedUnion(obj));
  if (!val) {
    CHECK(PyErr_Occurred());
    return extractorError<::test::fixtures::python_capi::SerializedUnion>(
        "Thrift serialize error: SerializedUnion");
  }
  return detail::deserialize_iobuf<::test::fixtures::python_capi::SerializedUnion>(std::move(val));
}


ExtractorResult<::test::fixtures::python_capi::SerializedUnion>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::test::fixtures::python_capi::SerializedUnion>>::operator()(PyObject* fbthrift_data) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return extractorError<::test::fixtures::python_capi::SerializedUnion>(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  auto obj = StrongRef(init__test__fixtures__python_capi__serialized_dep__SerializedUnion(fbthrift_data));
  if (!obj) {
      return extractorError<::test::fixtures::python_capi::SerializedUnion>(
          "Init from fbthrift error: SerializedUnion");
  }
  return Extractor<::test::fixtures::python_capi::SerializedUnion>{}(*obj);
}

int Extractor<::test::fixtures::python_capi::SerializedUnion>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  int result =
      can_extract__test__fixtures__python_capi__serialized_dep__SerializedUnion(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: SerializedUnion");
  }
  return result;
}


PyObject* Constructor<::test::fixtures::python_capi::SerializedUnion>::operator()(
    const ::test::fixtures::python_capi::SerializedUnion& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  auto ptr = construct__test__fixtures__python_capi__serialized_dep__SerializedUnion(
      detail::serialize_to_iobuf(val));
  if (!ptr) {
    CHECK(PyErr_Occurred());
  }
  return ptr;
}


PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::test::fixtures::python_capi::SerializedUnion>>::operator()(
    const ::test::fixtures::python_capi::SerializedUnion& val) {
  auto obj = StrongRef(Constructor<::test::fixtures::python_capi::SerializedUnion>{}(val));
  if (!obj) {
    return nullptr;
  }
  return getThriftData(*obj);
}

ExtractorResult<::test::fixtures::python_capi::SerializedError>
Extractor<::test::fixtures::python_capi::SerializedError>::operator()(PyObject* obj) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return extractorError<::test::fixtures::python_capi::SerializedError>(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  std::unique_ptr<folly::IOBuf> val(
      extract__test__fixtures__python_capi__serialized_dep__SerializedError(obj));
  if (!val) {
    CHECK(PyErr_Occurred());
    return extractorError<::test::fixtures::python_capi::SerializedError>(
        "Thrift serialize error: SerializedError");
  }
  return detail::deserialize_iobuf<::test::fixtures::python_capi::SerializedError>(std::move(val));
}


ExtractorResult<::test::fixtures::python_capi::SerializedError>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::test::fixtures::python_capi::SerializedError>>::operator()(PyObject* fbthrift_data) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return extractorError<::test::fixtures::python_capi::SerializedError>(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  auto obj = StrongRef(init__test__fixtures__python_capi__serialized_dep__SerializedError(fbthrift_data));
  if (!obj) {
      return extractorError<::test::fixtures::python_capi::SerializedError>(
          "Init from fbthrift error: SerializedError");
  }
  return Extractor<::test::fixtures::python_capi::SerializedError>{}(*obj);
}

int Extractor<::test::fixtures::python_capi::SerializedError>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  int result =
      can_extract__test__fixtures__python_capi__serialized_dep__SerializedError(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: SerializedError");
  }
  return result;
}


PyObject* Constructor<::test::fixtures::python_capi::SerializedError>::operator()(
    const ::test::fixtures::python_capi::SerializedError& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  auto ptr = construct__test__fixtures__python_capi__serialized_dep__SerializedError(
      detail::serialize_to_iobuf(val));
  if (!ptr) {
    CHECK(PyErr_Occurred());
  }
  return ptr;
}


PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::test::fixtures::python_capi::SerializedError>>::operator()(
    const ::test::fixtures::python_capi::SerializedError& val) {
  auto obj = StrongRef(Constructor<::test::fixtures::python_capi::SerializedError>{}(val));
  if (!obj) {
    return nullptr;
  }
  return getExceptionThriftData(*obj);
}

ExtractorResult<::test::fixtures::python_capi::MarshalStruct>
Extractor<::test::fixtures::python_capi::MarshalStruct>::operator()(PyObject* obj) {
  int tCheckResult = typeCheck(obj);
  if (tCheckResult != 1) {
      if (tCheckResult == 0) {
        PyErr_SetString(PyExc_TypeError, "Not a MarshalStruct");
      }
      return extractorError<::test::fixtures::python_capi::MarshalStruct>(
          "Marshal error: MarshalStruct");
  }
  StrongRef fbThriftData(getThriftData(obj));
  return Extractor<::apache::thrift::python::capi::ComposedStruct<
      ::test::fixtures::python_capi::MarshalStruct>>{}(*fbThriftData);
}

ExtractorResult<::test::fixtures::python_capi::MarshalStruct>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::test::fixtures::python_capi::MarshalStruct>>::operator()(PyObject* fbThriftData) {
  ::test::fixtures::python_capi::MarshalStruct cpp;
  std::optional<std::string_view> error;
  Extractor<Bytes>{}.extractInto(
      cpp.s_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__MarshalStruct__tuple_pos[0]),
      error);
  Extractor<int32_t>{}.extractInto(
      cpp.i_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__MarshalStruct__tuple_pos[1]),
      error);
  Extractor<Bytes>{}.extractInto(
      cpp.os_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__MarshalStruct__tuple_pos[2]),
      error);
  Extractor<Bytes>{}.extractInto(
      cpp.rs_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__MarshalStruct__tuple_pos[3]),
      error);
  if (error) {
    return folly::makeUnexpected(*error);
  }
  return cpp;
}


int Extractor<::test::fixtures::python_capi::MarshalStruct>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  int result =
      can_extract__test__fixtures__python_capi__serialized_dep__MarshalStruct(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: MarshalStruct");
  }
  return result;
}


PyObject* Constructor<::test::fixtures::python_capi::MarshalStruct>::operator()(
    const ::test::fixtures::python_capi::MarshalStruct& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::test::fixtures::python_capi::MarshalStruct>> ctor;
  StrongRef fbthrift_data(ctor(val));
  if (!fbthrift_data) {
    return nullptr;
  }
  return init__test__fixtures__python_capi__serialized_dep__MarshalStruct(*fbthrift_data);
}

PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::test::fixtures::python_capi::MarshalStruct>>::operator()(
    [[maybe_unused]] const ::test::fixtures::python_capi::MarshalStruct& val) {
  StrongRef fbthrift_data(createStructTuple(4));
  StrongRef _fbthrift__s(
    Constructor<Bytes>{}
    .constructFrom(val.s_ref()));
  if (!_fbthrift__s ||
      setStructField(
          *fbthrift_data,
          _fbthrift__MarshalStruct__tuple_pos[0],
          *_fbthrift__s) == -1) {
    return nullptr;
  }
  StrongRef _fbthrift__i(
    Constructor<int32_t>{}
    .constructFrom(val.i_ref()));
  if (!_fbthrift__i ||
      setStructField(
          *fbthrift_data,
          _fbthrift__MarshalStruct__tuple_pos[1],
          *_fbthrift__i) == -1) {
    return nullptr;
  }
  StrongRef _fbthrift__os(
    Constructor<Bytes>{}
    .constructFrom(val.os_ref()));
  if (_fbthrift__os.isNone()) {
    Py_INCREF(Py_None);
    PyTuple_SET_ITEM(
      *fbthrift_data,
      _fbthrift__MarshalStruct__tuple_pos[2],
      Py_None);
  } else
  if (!_fbthrift__os ||
      setStructField(
          *fbthrift_data,
          _fbthrift__MarshalStruct__tuple_pos[2],
          *_fbthrift__os) == -1) {
    return nullptr;
  }
  StrongRef _fbthrift__rs(
    Constructor<Bytes>{}
    .constructFrom(val.rs_ref()));
  if (!_fbthrift__rs ||
      setStructField(
          *fbthrift_data,
          _fbthrift__MarshalStruct__tuple_pos[3],
          *_fbthrift__rs) == -1) {
    return nullptr;
  }
  return std::move(fbthrift_data).release();
}


ExtractorResult<::test::fixtures::python_capi::MarshalUnion>
Extractor<::test::fixtures::python_capi::MarshalUnion>::operator()(PyObject* obj) {
  int tCheckResult = typeCheck(obj);
  if (tCheckResult != 1) {
      if (tCheckResult == 0) {
        PyErr_SetString(PyExc_TypeError, "Not a MarshalUnion");
      }
      return extractorError<::test::fixtures::python_capi::MarshalUnion>(
          "Marshal error: MarshalUnion");
  }
  StrongRef fbThriftData(getThriftData(obj));
  return Extractor<::apache::thrift::python::capi::ComposedStruct<
      ::test::fixtures::python_capi::MarshalUnion>>{}(*fbThriftData);
}

ExtractorResult<::test::fixtures::python_capi::MarshalUnion>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::test::fixtures::python_capi::MarshalUnion>>::operator()(PyObject* fbThriftData) {
  ::test::fixtures::python_capi::MarshalUnion cpp;
  std::optional<std::string_view> error;
  auto type_tag = Extractor<int64_t>{}(PyTuple_GET_ITEM(fbThriftData, 0));
  if (type_tag.hasError()) {
    return folly::makeUnexpected(type_tag.error());
  }
  switch (*type_tag) {
    case 0:
      break; // union is unset
    case 1:
      Extractor<Bytes>{}.extractInto(
          cpp.s_ref(), PyTuple_GET_ITEM(fbThriftData, 1), error);
      break;
    case 2:
      Extractor<int32_t>{}.extractInto(
          cpp.i_ref(), PyTuple_GET_ITEM(fbThriftData, 1), error);
      break;
  }
  if (error) {
    return folly::makeUnexpected(*error);
  }
  return cpp;
}


int Extractor<::test::fixtures::python_capi::MarshalUnion>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  int result =
      can_extract__test__fixtures__python_capi__serialized_dep__MarshalUnion(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: MarshalUnion");
  }
  return result;
}


PyObject* Constructor<::test::fixtures::python_capi::MarshalUnion>::operator()(
    const ::test::fixtures::python_capi::MarshalUnion& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::test::fixtures::python_capi::MarshalUnion>> ctor;
  StrongRef fbthrift_data(ctor(val));
  if (!fbthrift_data) {
    return nullptr;
  }
  return init__test__fixtures__python_capi__serialized_dep__MarshalUnion(*fbthrift_data);
}

PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::test::fixtures::python_capi::MarshalUnion>>::operator()(
    [[maybe_unused]] const ::test::fixtures::python_capi::MarshalUnion& val) {
  int64_t type_key = static_cast<int64_t>(val.getType());
  StrongRef py_val;
  switch (type_key) {
    case 0:
      Py_INCREF(Py_None);
      py_val = StrongRef(Py_None);
      break;
    case 1:
      py_val = StrongRef(
          Constructor<Bytes>{}
          .constructFrom(val.s_ref()));
      break;
    case 2:
      py_val = StrongRef(
          Constructor<int32_t>{}
          .constructFrom(val.i_ref()));
      break;
  }
  if (!py_val) {
    return nullptr;
  }
  return unionTupleFromValue(type_key, *py_val);
}


ExtractorResult<::test::fixtures::python_capi::MarshalError>
Extractor<::test::fixtures::python_capi::MarshalError>::operator()(PyObject* obj) {
  int tCheckResult = typeCheck(obj);
  if (tCheckResult != 1) {
      if (tCheckResult == 0) {
        PyErr_SetString(PyExc_TypeError, "Not a MarshalError");
      }
      return extractorError<::test::fixtures::python_capi::MarshalError>(
          "Marshal error: MarshalError");
  }
  StrongRef fbThriftData(getExceptionThriftData(obj));
  return Extractor<::apache::thrift::python::capi::ComposedStruct<
      ::test::fixtures::python_capi::MarshalError>>{}(*fbThriftData);
}

ExtractorResult<::test::fixtures::python_capi::MarshalError>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::test::fixtures::python_capi::MarshalError>>::operator()(PyObject* fbThriftData) {
  ::test::fixtures::python_capi::MarshalError cpp;
  std::optional<std::string_view> error;
  Extractor<Bytes>{}.extractInto(
      cpp.msg_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__MarshalError__tuple_pos[0]),
      error);
  Extractor<Bytes>{}.extractInto(
      cpp.os_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__MarshalError__tuple_pos[1]),
      error);
  Extractor<Bytes>{}.extractInto(
      cpp.rs_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__MarshalError__tuple_pos[2]),
      error);
  if (error) {
    return folly::makeUnexpected(*error);
  }
  return cpp;
}


int Extractor<::test::fixtures::python_capi::MarshalError>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module test.fixtures.python_capi.serialized_dep import error");
  }
  int result =
      can_extract__test__fixtures__python_capi__serialized_dep__MarshalError(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: MarshalError");
  }
  return result;
}


PyObject* Constructor<::test::fixtures::python_capi::MarshalError>::operator()(
    const ::test::fixtures::python_capi::MarshalError& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::test::fixtures::python_capi::MarshalError>> ctor;
  StrongRef fbthrift_data(ctor(val));
  if (!fbthrift_data) {
    return nullptr;
  }
  return init__test__fixtures__python_capi__serialized_dep__MarshalError(*fbthrift_data);
}

PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::test::fixtures::python_capi::MarshalError>>::operator()(
    [[maybe_unused]] const ::test::fixtures::python_capi::MarshalError& val) {
  StrongRef fbthrift_data(createStructTuple(3));
  StrongRef _fbthrift__msg(
    Constructor<Bytes>{}
    .constructFrom(val.msg_ref()));
  if (!_fbthrift__msg ||
      setStructField(
          *fbthrift_data,
          _fbthrift__MarshalError__tuple_pos[0],
          *_fbthrift__msg) == -1) {
    return nullptr;
  }
  StrongRef _fbthrift__os(
    Constructor<Bytes>{}
    .constructFrom(val.os_ref()));
  if (_fbthrift__os.isNone()) {
    Py_INCREF(Py_None);
    PyTuple_SET_ITEM(
      *fbthrift_data,
      _fbthrift__MarshalError__tuple_pos[1],
      Py_None);
  } else
  if (!_fbthrift__os ||
      setStructField(
          *fbthrift_data,
          _fbthrift__MarshalError__tuple_pos[1],
          *_fbthrift__os) == -1) {
    return nullptr;
  }
  StrongRef _fbthrift__rs(
    Constructor<Bytes>{}
    .constructFrom(val.rs_ref()));
  if (!_fbthrift__rs ||
      setStructField(
          *fbthrift_data,
          _fbthrift__MarshalError__tuple_pos[2],
          *_fbthrift__rs) == -1) {
    return nullptr;
  }
  return std::move(fbthrift_data).release();
}


} // namespace capi
} // namespace python
} // namespace thrift
} // namespace apache
