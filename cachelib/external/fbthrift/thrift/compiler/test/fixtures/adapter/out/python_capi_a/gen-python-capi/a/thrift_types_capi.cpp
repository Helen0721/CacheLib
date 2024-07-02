
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

#include <thrift/compiler/test/fixtures/adapter/gen-python-capi/a/thrift_types_api.h>
#include <thrift/compiler/test/fixtures/adapter/gen-python-capi/a/thrift_types_capi.h>

#include "thrift/compiler/test/fixtures/adapter/gen-python-capi/b/thrift_types_capi.h"
#include "thrift/compiler/test/fixtures/adapter/gen-python-capi/c/thrift_types_capi.h"

namespace apache {
namespace thrift {
namespace python {
namespace capi {
namespace {
bool ensure_module_imported() {
  static ::folly::python::import_cache_nocapture import((
      ::import_a__thrift_types_capi));
  return import();
}
  static constexpr std::int16_t _fbthrift__MyStruct__tuple_pos[3] = {
    1, 2, 3
  };
} // namespace

ExtractorResult<::cpp2::MyStruct>
Extractor<::cpp2::MyStruct>::operator()(PyObject* obj) {
  int tCheckResult = typeCheck(obj);
  if (tCheckResult != 1) {
      if (tCheckResult == 0) {
        PyErr_SetString(PyExc_TypeError, "Not a MyStruct");
      }
      return extractorError<::cpp2::MyStruct>(
          "Marshal error: MyStruct");
  }
  StrongRef fbThriftData(getThriftData(obj));
  return Extractor<::apache::thrift::python::capi::ComposedStruct<
      ::cpp2::MyStruct>>{}(*fbThriftData);
}

ExtractorResult<::cpp2::MyStruct>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::cpp2::MyStruct>>::operator()(PyObject* fbThriftData) {
  ::cpp2::MyStruct cpp;
  std::optional<std::string_view> error;
  Extractor<::apache::thrift::python::capi::ComposedStruct<::cpp2::B>>{}.extractInto(
      cpp.a_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__MyStruct__tuple_pos[0]),
      error);
  Extractor<::apache::thrift::python::capi::ComposedStruct<::cpp2::C1>>{}.extractInto(
      cpp.b_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__MyStruct__tuple_pos[1]),
      error);
  Extractor<::apache::thrift::python::capi::ComposedStruct<::cpp2::C2>>{}.extractInto(
      cpp.c_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__MyStruct__tuple_pos[2]),
      error);
  if (error) {
    return folly::makeUnexpected(*error);
  }
  return cpp;
}


int Extractor<::cpp2::MyStruct>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module a import error");
  }
  int result =
      can_extract__a__MyStruct(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: MyStruct");
  }
  return result;
}


PyObject* Constructor<::cpp2::MyStruct>::operator()(
    const ::cpp2::MyStruct& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::MyStruct>> ctor;
  StrongRef fbthrift_data(ctor(val));
  if (!fbthrift_data) {
    return nullptr;
  }
  return init__a__MyStruct(*fbthrift_data);
}

PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::MyStruct>>::operator()(
    [[maybe_unused]] const ::cpp2::MyStruct& val) {
  StrongRef fbthrift_data(createStructTuple(3));
  StrongRef _fbthrift__a(
    Constructor<::apache::thrift::python::capi::ComposedStruct<::cpp2::B>>{}
    .constructFrom(val.a_ref()));
  if (!_fbthrift__a ||
      setStructField(
          *fbthrift_data,
          _fbthrift__MyStruct__tuple_pos[0],
          *_fbthrift__a) == -1) {
    return nullptr;
  }
  StrongRef _fbthrift__b(
    Constructor<::apache::thrift::python::capi::ComposedStruct<::cpp2::C1>>{}
    .constructFrom(val.b_ref()));
  if (!_fbthrift__b ||
      setStructField(
          *fbthrift_data,
          _fbthrift__MyStruct__tuple_pos[1],
          *_fbthrift__b) == -1) {
    return nullptr;
  }
  StrongRef _fbthrift__c(
    Constructor<::apache::thrift::python::capi::ComposedStruct<::cpp2::C2>>{}
    .constructFrom(val.c_ref()));
  if (!_fbthrift__c ||
      setStructField(
          *fbthrift_data,
          _fbthrift__MyStruct__tuple_pos[2],
          *_fbthrift__c) == -1) {
    return nullptr;
  }
  return std::move(fbthrift_data).release();
}


} // namespace capi
} // namespace python
} // namespace thrift
} // namespace apache
