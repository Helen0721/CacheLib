#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from thrift.py3.reflection cimport (
  MethodSpec as __MethodSpec,
  ArgumentSpec as __ArgumentSpec,
  NumberType as __NumberType,
)

import folly.iobuf as _fbthrift_iobuf

cimport b.types as _b_types
cimport c.types as _c_types

cimport s.types as _s_types


cdef __InterfaceSpec get_reflection__TestService(bint for_clients):
    cdef __InterfaceSpec spec = __InterfaceSpec._fbthrift_create(
        name="TestService",
        annotations={
        },
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="test",
            arguments=(
            ),
            result=None,
            result_kind=__NumberType.NOT_A_NUMBER,
            exceptions=(
                _c_types.E,
            ),
            annotations={
            },
        )
    )
    return spec
