
#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#



cdef shared_ptr[_fbthrift_ctypes.cMyStruct] MyStruct_convert_to_cpp(object inst) except*:
    return (<_fbthrift_ctypes.MyStruct?>inst)._cpp_obj


cdef object MyStruct_from_cpp(const shared_ptr[_fbthrift_ctypes.cMyStruct]& c_struct):
    return _fbthrift_ctypes.MyStruct._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cMyDataItem] MyDataItem_convert_to_cpp(object inst) except*:
    return (<_fbthrift_ctypes.MyDataItem?>inst)._cpp_obj


cdef object MyDataItem_from_cpp(const shared_ptr[_fbthrift_ctypes.cMyDataItem]& c_struct):
    return _fbthrift_ctypes.MyDataItem._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cMyUnion] MyUnion_convert_to_cpp(object inst) except*:
    return (<_fbthrift_ctypes.MyUnion?>inst)._cpp_obj


cdef object MyUnion_from_cpp(const shared_ptr[_fbthrift_ctypes.cMyUnion]& c_struct):
    return _fbthrift_ctypes.MyUnion._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cReservedKeyword] ReservedKeyword_convert_to_cpp(object inst) except*:
    return (<_fbthrift_ctypes.ReservedKeyword?>inst)._cpp_obj


cdef object ReservedKeyword_from_cpp(const shared_ptr[_fbthrift_ctypes.cReservedKeyword]& c_struct):
    return _fbthrift_ctypes.ReservedKeyword._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cUnionToBeRenamed] UnionToBeRenamed_convert_to_cpp(object inst) except*:
    return (<_fbthrift_ctypes.UnionToBeRenamed?>inst)._cpp_obj


cdef object UnionToBeRenamed_from_cpp(const shared_ptr[_fbthrift_ctypes.cUnionToBeRenamed]& c_struct):
    return _fbthrift_ctypes.UnionToBeRenamed._fbthrift_create(c_struct)
