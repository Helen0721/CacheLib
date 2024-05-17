
#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from cpython.ref cimport PyObject
from libcpp.utility cimport move as __move
from folly.iobuf cimport (
    from_unique_ptr as __IOBuf_from_unique_ptr,
    IOBuf as __IOBuf,
)
from thrift.python.serializer import (
    deserialize as __deserialize,
    Protocol as __Protocol,
    serialize_iobuf as __serialize_iobuf,
)
import test.fixtures.python_capi.serialized_dep.thrift_types as __thrift_types

cdef api int can_extract__test__fixtures__python_capi__serialized_dep__SerializedStruct(object __obj) except -1:
    return 1 if isinstance(__obj, __thrift_types.SerializedStruct) else 0

cdef api __cIOBuf* extract__test__fixtures__python_capi__serialized_dep__SerializedStruct(object __obj) except NULL:
    cdef __IOBuf __buf = __serialize_iobuf(__obj, protocol=__Protocol.BINARY)
    return __buf._ours.release()

cdef api object construct__test__fixtures__python_capi__serialized_dep__SerializedStruct(__unique_ptr[__cIOBuf] __s):
    return __deserialize(
        __thrift_types.SerializedStruct,
        __IOBuf_from_unique_ptr(__move(__s)),
        protocol=__Protocol.BINARY
    )

cdef api object init__test__fixtures__python_capi__serialized_dep__SerializedStruct(object data):
    return __thrift_types.SerializedStruct._fbthrift_create(data)

cdef api int can_extract__test__fixtures__python_capi__serialized_dep__SerializedUnion(object __obj) except -1:
    return 1 if isinstance(__obj, __thrift_types.SerializedUnion) else 0

cdef api __cIOBuf* extract__test__fixtures__python_capi__serialized_dep__SerializedUnion(object __obj) except NULL:
    cdef __IOBuf __buf = __serialize_iobuf(__obj, protocol=__Protocol.BINARY)
    return __buf._ours.release()

cdef api object construct__test__fixtures__python_capi__serialized_dep__SerializedUnion(__unique_ptr[__cIOBuf] __s):
    return __deserialize(
        __thrift_types.SerializedUnion,
        __IOBuf_from_unique_ptr(__move(__s)),
        protocol=__Protocol.BINARY
    )

cdef api object init__test__fixtures__python_capi__serialized_dep__SerializedUnion(object data):
    return __thrift_types.SerializedUnion._fbthrift_create(data)

cdef api int can_extract__test__fixtures__python_capi__serialized_dep__SerializedError(object __obj) except -1:
    return 1 if isinstance(__obj, __thrift_types.SerializedError) else 0

cdef api __cIOBuf* extract__test__fixtures__python_capi__serialized_dep__SerializedError(object __obj) except NULL:
    cdef __IOBuf __buf = __serialize_iobuf(__obj, protocol=__Protocol.BINARY)
    return __buf._ours.release()

cdef api object construct__test__fixtures__python_capi__serialized_dep__SerializedError(__unique_ptr[__cIOBuf] __s):
    return __deserialize(
        __thrift_types.SerializedError,
        __IOBuf_from_unique_ptr(__move(__s)),
        protocol=__Protocol.BINARY
    )

cdef api object init__test__fixtures__python_capi__serialized_dep__SerializedError(object data):
    return __thrift_types.SerializedError._fbthrift_create(data)

cdef api int can_extract__test__fixtures__python_capi__serialized_dep__MarshalStruct(object __obj) except -1:
    return 1 if isinstance(__obj, __thrift_types.MarshalStruct) else 0


cdef api object init__test__fixtures__python_capi__serialized_dep__MarshalStruct(object data):
    return __thrift_types.MarshalStruct._fbthrift_create(data)

cdef api int can_extract__test__fixtures__python_capi__serialized_dep__MarshalUnion(object __obj) except -1:
    return 1 if isinstance(__obj, __thrift_types.MarshalUnion) else 0


cdef api object init__test__fixtures__python_capi__serialized_dep__MarshalUnion(object data):
    return __thrift_types.MarshalUnion._fbthrift_create(data)

cdef api int can_extract__test__fixtures__python_capi__serialized_dep__MarshalError(object __obj) except -1:
    return 1 if isinstance(__obj, __thrift_types.MarshalError) else 0


cdef api object init__test__fixtures__python_capi__serialized_dep__MarshalError(object data):
    return __thrift_types.MarshalError._fbthrift_create(data)

