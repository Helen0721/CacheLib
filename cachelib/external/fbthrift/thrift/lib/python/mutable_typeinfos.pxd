# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from libc.stdint cimport int16_t

cdef extern from "<thrift/lib/cpp2/protocol/TableBasedSerializer.h>" namespace "::apache::thrift::detail":
    cdef struct cTypeInfo "::apache::thrift::detail::TypeInfo":
        pass
    cdef struct cStructInfo "::apache::thrift::detail::StructInfo":
        pass
    cpdef enum class FieldQualifier "::apache::thrift::detail::FieldQualifier":
        Unqualified
        Optional
        Terse

cdef extern from "<thrift/lib/python/types.h>" namespace "::apache::thrift::python":
    cdef cppclass cDynamicStructInfo "::apache::thrift::python::DynamicStructInfo":
        cDynamicStructInfo(const char* name, int16_t numFields, bint isUnion)
        const cStructInfo& getStructInfo()
        void addFieldInfo(int16_t id, FieldQualifier qualifier, const char* name, const cTypeInfo* typeInfo) except+
        void addFieldValue(int16_t index, object fieldValue) except+
        bint isUnion()

cdef extern from "<thrift/lib/python/types.h>" namespace "::apache::thrift::python":
    cdef cTypeInfo createImmutableStructTypeInfo(const cDynamicStructInfo& structInfo) except+

from thrift.python.types cimport TypeInfoBase

cdef class MutableStructTypeInfo(TypeInfoBase):
    cdef cTypeInfo cpp_obj
    cdef object _mutable_struct_class
    cdef const cTypeInfo* get_cTypeInfo(self)
    cdef to_internal_data(self, object)
    cdef to_python_value(self, object)
