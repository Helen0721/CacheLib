#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from thrift.py3.reflection cimport (
  InterfaceSpec as __InterfaceSpec,
)


cdef __InterfaceSpec get_reflection__MyService(bint for_clients)

cdef extern from "thrift/compiler/test/fixtures/interactions/gen-cpp2/module_handlers.h" namespace "::cpp2":
    cdef cppclass cMyServiceSvIf "::cpp2::MyServiceSvIf":
        pass
