#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
cimport cython as __cython
from cython.operator cimport dereference as deref
from libcpp.memory cimport unique_ptr, shared_ptr
from thrift.py3.types cimport (
    assign_unique_ptr,
    assign_shared_ptr,
    assign_shared_const_ptr,
    bytes_to_string,
    make_unique,
)
cimport thrift.py3.types
from thrift.py3.types cimport (
    reset_field as __reset_field,
    StructFieldsSetter as __StructFieldsSetter
)

from thrift.py3.types cimport const_pointer_cast, BadEnum as _fbthrift_BadEnum


@__cython.auto_pickle(False)
cdef class __Val_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __Val_FieldsSetter _fbthrift_create(_module_types.cVal* struct_cpp_obj):
        cdef __Val_FieldsSetter __fbthrift_inst = __Val_FieldsSetter.__new__(__Val_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"strVal")] = __Val_FieldsSetter._set_field_0
        __fbthrift_inst._setters[__cstring_view(<const char*>"intVal")] = __Val_FieldsSetter._set_field_1
        __fbthrift_inst._setters[__cstring_view(<const char*>"typedefValue")] = __Val_FieldsSetter._set_field_2
        return __fbthrift_inst

    cdef void set_field(__Val_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __Val_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field strVal
        if _fbthrift_value is None:
            __reset_field[_module_types.cVal](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, str):
            raise TypeError(f'strVal is not a { str !r}.')
        deref(self._struct_cpp_obj).strVal_ref().assign(cmove(bytes_to_string(_fbthrift_value.encode('utf-8'))))

    cdef void _set_field_1(self, _fbthrift_value) except *:
        # for field intVal
        if _fbthrift_value is None:
            __reset_field[_module_types.cVal](deref(self._struct_cpp_obj), 1)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'intVal is not a { int !r}.')
        _fbthrift_value = <cint32_t> _fbthrift_value
        deref(self._struct_cpp_obj).intVal_ref().assign(_fbthrift_value)

    cdef void _set_field_2(self, _fbthrift_value) except *:
        # for field typedefValue
        if _fbthrift_value is None:
            __reset_field[_module_types.cVal](deref(self._struct_cpp_obj), 2)
            return
        deref(self._struct_cpp_obj).typedefValue_ref().assign(deref(_module_types.Map__i16_string(_fbthrift_value)._cpp_obj))


@__cython.auto_pickle(False)
cdef class __NonCopyableStruct_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __NonCopyableStruct_FieldsSetter _fbthrift_create(_module_types.cNonCopyableStruct* struct_cpp_obj):
        cdef __NonCopyableStruct_FieldsSetter __fbthrift_inst = __NonCopyableStruct_FieldsSetter.__new__(__NonCopyableStruct_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        __fbthrift_inst._setters[__cstring_view(<const char*>"num")] = __NonCopyableStruct_FieldsSetter._set_field_0
        return __fbthrift_inst

    cdef void set_field(__NonCopyableStruct_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __NonCopyableStruct_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

    cdef void _set_field_0(self, _fbthrift_value) except *:
        # for field num
        if _fbthrift_value is None:
            __reset_field[_module_types.cNonCopyableStruct](deref(self._struct_cpp_obj), 0)
            return
        if not isinstance(_fbthrift_value, int):
            raise TypeError(f'num is not a { int !r}.')
        _fbthrift_value = <cint64_t> _fbthrift_value
        deref(self._struct_cpp_obj).num_ref().assign(_fbthrift_value)

