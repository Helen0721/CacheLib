#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

import folly.iobuf as _fbthrift_iobuf
import thrift.py3.types
import thrift.py3.client
import thrift.py3.common
import typing as _typing
from types import TracebackType

import s.types as _s_types
import b.types as _b_types
import c.types as _c_types


_TestServiceT = _typing.TypeVar('_TestServiceT', bound='TestService')


class TestService(thrift.py3.client.Client):

    async def test(
        self,
        rpc_options: _typing.Optional[thrift.py3.common.RpcOptions]=None
    ) -> None: ...

