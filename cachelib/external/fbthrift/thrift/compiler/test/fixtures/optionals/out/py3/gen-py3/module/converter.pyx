
#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#



cdef shared_ptr[_fbthrift_ctypes.cColor] Color_convert_to_cpp(object inst) except*:
    return (<_fbthrift_ctypes.Color?>inst)._cpp_obj


cdef object Color_from_cpp(const shared_ptr[_fbthrift_ctypes.cColor]& c_struct):
    return _fbthrift_ctypes.Color._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cVehicle] Vehicle_convert_to_cpp(object inst) except*:
    return (<_fbthrift_ctypes.Vehicle?>inst)._cpp_obj


cdef object Vehicle_from_cpp(const shared_ptr[_fbthrift_ctypes.cVehicle]& c_struct):
    return _fbthrift_ctypes.Vehicle._fbthrift_create(c_struct)
cdef shared_ptr[_fbthrift_ctypes.cPerson] Person_convert_to_cpp(object inst) except*:
    return (<_fbthrift_ctypes.Person?>inst)._cpp_obj


cdef object Person_from_cpp(const shared_ptr[_fbthrift_ctypes.cPerson]& c_struct):
    return _fbthrift_ctypes.Person._fbthrift_create(c_struct)
