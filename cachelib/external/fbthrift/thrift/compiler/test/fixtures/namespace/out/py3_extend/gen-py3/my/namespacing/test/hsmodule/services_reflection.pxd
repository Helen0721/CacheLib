#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from thrift.py3.reflection cimport (
  InterfaceSpec as __InterfaceSpec,
)


cdef __InterfaceSpec get_reflection__HsTestService(bint for_clients)

cdef extern from "thrift/compiler/test/fixtures/namespace/gen-cpp2/hsmodule_handlers.h" namespace "::cpp2":
    cdef cppclass cHsTestServiceSvIf "::cpp2::HsTestServiceSvIf":
        pass
