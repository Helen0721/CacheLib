#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
import typing as _typing

import folly.iobuf as _fbthrift_iobuf
import thrift.py3.builder


import module_structs.types as _module_structs_types


_fbthrift_struct_type__Foo = _module_structs_types.Foo
class Foo_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__Foo

    def __init__(self):
        self.value: _typing.Optional[int] = None

    def __iter__(self):
        yield "value", self.value

