
#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#



cdef shared_ptr[_fbthrift_ctypes.cTypeUri] TypeUri_convert_to_cpp(object inst) except*:
    return (<_fbthrift_ctypes.TypeUri?>inst)._cpp_obj


cdef object TypeUri_from_cpp(const shared_ptr[_fbthrift_ctypes.cTypeUri]& c_struct):
    return _fbthrift_ctypes.TypeUri._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cTypeName] TypeName_convert_to_cpp(object inst) except*:
    return (<_fbthrift_ctypes.TypeName?>inst)._cpp_obj


cdef object TypeName_from_cpp(const shared_ptr[_fbthrift_ctypes.cTypeName]& c_struct):
    return _fbthrift_ctypes.TypeName._fbthrift_create(c_struct)
