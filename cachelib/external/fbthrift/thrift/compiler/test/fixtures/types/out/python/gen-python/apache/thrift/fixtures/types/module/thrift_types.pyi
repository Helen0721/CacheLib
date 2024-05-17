#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations


import typing as _typing

import folly.iobuf as _fbthrift_iobuf
import thrift.python.types as _fbthrift_python_types
import thrift.python.exceptions as _fbthrift_python_exceptions

import apache.thrift.fixtures.types.included.thrift_types

class _fbthrift_compatible_with_has_bitwise_ops:
    pass


class has_bitwise_ops(_fbthrift_python_types.Enum, int, _fbthrift_compatible_with_has_bitwise_ops):
    none: has_bitwise_ops = ...
    zero: has_bitwise_ops = ...
    one: has_bitwise_ops = ...
    two: has_bitwise_ops = ...
    three: has_bitwise_ops = ...
    def _to_python(self) -> has_bitwise_ops: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.has_bitwise_ops": ...  # type: ignore
    def _to_py_deprecated(self) -> int: ...

class _fbthrift_compatible_with_is_unscoped:
    pass


class is_unscoped(_fbthrift_python_types.Enum, int, _fbthrift_compatible_with_is_unscoped):
    hello: is_unscoped = ...
    world: is_unscoped = ...
    def _to_python(self) -> is_unscoped: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.is_unscoped": ...  # type: ignore
    def _to_py_deprecated(self) -> int: ...

class _fbthrift_compatible_with_MyForwardRefEnum:
    pass


class MyForwardRefEnum(_fbthrift_python_types.Enum, int, _fbthrift_compatible_with_MyForwardRefEnum):
    ZERO: MyForwardRefEnum = ...
    NONZERO: MyForwardRefEnum = ...
    def _to_python(self) -> MyForwardRefEnum: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.MyForwardRefEnum": ...  # type: ignore
    def _to_py_deprecated(self) -> int: ...


class _fbthrift_compatible_with_empty_struct:
    pass


class empty_struct(_fbthrift_python_types.Struct, _fbthrift_compatible_with_empty_struct):
    def __init__(
        self,
    ) -> None: ...

    def __call__(
        self,
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[None]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.empty_struct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.empty_struct": ...  # type: ignore


class _fbthrift_compatible_with_decorated_struct:
    pass


class decorated_struct(_fbthrift_python_types.Struct, _fbthrift_compatible_with_decorated_struct):
    field: _typing.Final[str] = ...
    def __init__(
        self, *,
        field: _typing.Optional[str]=...
    ) -> None: ...

    def __call__(
        self, *,
        field: _typing.Optional[str]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.decorated_struct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.decorated_struct": ...  # type: ignore


class _fbthrift_compatible_with_ContainerStruct:
    pass


class ContainerStruct(_fbthrift_python_types.Struct, _fbthrift_compatible_with_ContainerStruct):
    fieldB: _typing.Final[_typing.Sequence[int]] = ...
    fieldC: _typing.Final[_typing.Sequence[int]] = ...
    fieldD: _typing.Final[_typing.Sequence[int]] = ...
    fieldE: _typing.Final[_typing.Sequence[int]] = ...
    fieldF: _typing.Final[_typing.AbstractSet[int]] = ...
    fieldG: _typing.Final[_typing.Mapping[int, str]] = ...
    fieldH: _typing.Final[_typing.Mapping[int, str]] = ...
    fieldA: _typing.Final[_typing.Sequence[int]] = ...
    def __init__(
        self, *,
        fieldB: _typing.Optional[_typing.Sequence[int]]=...,
        fieldC: _typing.Optional[_typing.Sequence[int]]=...,
        fieldD: _typing.Optional[_typing.Sequence[int]]=...,
        fieldE: _typing.Optional[_typing.Sequence[int]]=...,
        fieldF: _typing.Optional[_typing.AbstractSet[int]]=...,
        fieldG: _typing.Optional[_typing.Mapping[int, str]]=...,
        fieldH: _typing.Optional[_typing.Mapping[int, str]]=...,
        fieldA: _typing.Optional[_typing.Sequence[int]]=...
    ) -> None: ...

    def __call__(
        self, *,
        fieldB: _typing.Optional[_typing.Sequence[int]]=...,
        fieldC: _typing.Optional[_typing.Sequence[int]]=...,
        fieldD: _typing.Optional[_typing.Sequence[int]]=...,
        fieldE: _typing.Optional[_typing.Sequence[int]]=...,
        fieldF: _typing.Optional[_typing.AbstractSet[int]]=...,
        fieldG: _typing.Optional[_typing.Mapping[int, str]]=...,
        fieldH: _typing.Optional[_typing.Mapping[int, str]]=...,
        fieldA: _typing.Optional[_typing.Sequence[int]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Sequence[int], _typing.Sequence[int], _typing.Sequence[int], _typing.Sequence[int], _typing.AbstractSet[int], _typing.Mapping[int, str], _typing.Mapping[int, str], _typing.Sequence[int]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.ContainerStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.ContainerStruct": ...  # type: ignore


class _fbthrift_compatible_with_CppTypeStruct:
    pass


class CppTypeStruct(_fbthrift_python_types.Struct, _fbthrift_compatible_with_CppTypeStruct):
    fieldA: _typing.Final[_typing.Sequence[int]] = ...
    def __init__(
        self, *,
        fieldA: _typing.Optional[_typing.Sequence[int]]=...
    ) -> None: ...

    def __call__(
        self, *,
        fieldA: _typing.Optional[_typing.Sequence[int]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Sequence[int]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.CppTypeStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.CppTypeStruct": ...  # type: ignore


class _fbthrift_compatible_with_VirtualStruct:
    pass


class VirtualStruct(_fbthrift_python_types.Struct, _fbthrift_compatible_with_VirtualStruct):
    MyIntField: _typing.Final[int] = ...
    def __init__(
        self, *,
        MyIntField: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        MyIntField: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.VirtualStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.VirtualStruct": ...  # type: ignore


class _fbthrift_compatible_with_MyStructWithForwardRefEnum:
    pass


class MyStructWithForwardRefEnum(_fbthrift_python_types.Struct, _fbthrift_compatible_with_MyStructWithForwardRefEnum):
    a: _typing.Final[MyForwardRefEnum] = ...
    b: _typing.Final[MyForwardRefEnum] = ...
    def __init__(
        self, *,
        a: _typing.Optional[_fbthrift_compatible_with_MyForwardRefEnum]=...,
        b: _typing.Optional[_fbthrift_compatible_with_MyForwardRefEnum]=...
    ) -> None: ...

    def __call__(
        self, *,
        a: _typing.Optional[_fbthrift_compatible_with_MyForwardRefEnum]=...,
        b: _typing.Optional[_fbthrift_compatible_with_MyForwardRefEnum]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[MyForwardRefEnum, MyForwardRefEnum]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.MyStructWithForwardRefEnum": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyStructWithForwardRefEnum": ...  # type: ignore


class _fbthrift_compatible_with_TrivialNumeric:
    pass


class TrivialNumeric(_fbthrift_python_types.Struct, _fbthrift_compatible_with_TrivialNumeric):
    a: _typing.Final[int] = ...
    b: _typing.Final[bool] = ...
    def __init__(
        self, *,
        a: _typing.Optional[int]=...,
        b: _typing.Optional[bool]=...
    ) -> None: ...

    def __call__(
        self, *,
        a: _typing.Optional[int]=...,
        b: _typing.Optional[bool]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, bool]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.TrivialNumeric": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.TrivialNumeric": ...  # type: ignore


class _fbthrift_compatible_with_TrivialNestedWithDefault:
    pass


class TrivialNestedWithDefault(_fbthrift_python_types.Struct, _fbthrift_compatible_with_TrivialNestedWithDefault):
    z: _typing.Final[int] = ...
    n: _typing.Final[TrivialNumeric] = ...
    def __init__(
        self, *,
        z: _typing.Optional[int]=...,
        n: _typing.Optional[_fbthrift_compatible_with_TrivialNumeric]=...
    ) -> None: ...

    def __call__(
        self, *,
        z: _typing.Optional[int]=...,
        n: _typing.Optional[_fbthrift_compatible_with_TrivialNumeric]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, TrivialNumeric]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.TrivialNestedWithDefault": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.TrivialNestedWithDefault": ...  # type: ignore


class _fbthrift_compatible_with_ComplexString:
    pass


class ComplexString(_fbthrift_python_types.Struct, _fbthrift_compatible_with_ComplexString):
    a: _typing.Final[str] = ...
    b: _typing.Final[_typing.Mapping[str, int]] = ...
    def __init__(
        self, *,
        a: _typing.Optional[str]=...,
        b: _typing.Optional[_typing.Mapping[str, int]]=...
    ) -> None: ...

    def __call__(
        self, *,
        a: _typing.Optional[str]=...,
        b: _typing.Optional[_typing.Mapping[str, int]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, _typing.Mapping[str, int]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.ComplexString": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.ComplexString": ...  # type: ignore


class _fbthrift_compatible_with_ComplexNestedWithDefault:
    pass


class ComplexNestedWithDefault(_fbthrift_python_types.Struct, _fbthrift_compatible_with_ComplexNestedWithDefault):
    z: _typing.Final[str] = ...
    n: _typing.Final[ComplexString] = ...
    def __init__(
        self, *,
        z: _typing.Optional[str]=...,
        n: _typing.Optional[_fbthrift_compatible_with_ComplexString]=...
    ) -> None: ...

    def __call__(
        self, *,
        z: _typing.Optional[str]=...,
        n: _typing.Optional[_fbthrift_compatible_with_ComplexString]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, ComplexString]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.ComplexNestedWithDefault": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.ComplexNestedWithDefault": ...  # type: ignore


class _fbthrift_compatible_with_MinPadding:
    pass


class MinPadding(_fbthrift_python_types.Struct, _fbthrift_compatible_with_MinPadding):
    small: _typing.Final[int] = ...
    big: _typing.Final[int] = ...
    medium: _typing.Final[int] = ...
    biggish: _typing.Final[int] = ...
    tiny: _typing.Final[int] = ...
    def __init__(
        self, *,
        small: _typing.Optional[int]=...,
        big: _typing.Optional[int]=...,
        medium: _typing.Optional[int]=...,
        biggish: _typing.Optional[int]=...,
        tiny: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        small: _typing.Optional[int]=...,
        big: _typing.Optional[int]=...,
        medium: _typing.Optional[int]=...,
        biggish: _typing.Optional[int]=...,
        tiny: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, int, int, int, int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.MinPadding": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MinPadding": ...  # type: ignore


class _fbthrift_compatible_with_MinPaddingWithCustomType:
    pass


class MinPaddingWithCustomType(_fbthrift_python_types.Struct, _fbthrift_compatible_with_MinPaddingWithCustomType):
    small: _typing.Final[int] = ...
    big: _typing.Final[int] = ...
    medium: _typing.Final[int] = ...
    biggish: _typing.Final[int] = ...
    tiny: _typing.Final[int] = ...
    def __init__(
        self, *,
        small: _typing.Optional[int]=...,
        big: _typing.Optional[int]=...,
        medium: _typing.Optional[int]=...,
        biggish: _typing.Optional[int]=...,
        tiny: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        small: _typing.Optional[int]=...,
        big: _typing.Optional[int]=...,
        medium: _typing.Optional[int]=...,
        biggish: _typing.Optional[int]=...,
        tiny: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, int, int, int, int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.MinPaddingWithCustomType": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MinPaddingWithCustomType": ...  # type: ignore


class _fbthrift_compatible_with_MyStruct:
    pass


class MyStruct(_fbthrift_python_types.Struct, _fbthrift_compatible_with_MyStruct):
    MyIntField: _typing.Final[int] = ...
    MyStringField: _typing.Final[str] = ...
    majorVer: _typing.Final[int] = ...
    data: _typing.Final[MyDataItem] = ...
    def __init__(
        self, *,
        MyIntField: _typing.Optional[int]=...,
        MyStringField: _typing.Optional[str]=...,
        majorVer: _typing.Optional[int]=...,
        data: _typing.Optional[_fbthrift_compatible_with_MyDataItem]=...
    ) -> None: ...

    def __call__(
        self, *,
        MyIntField: _typing.Optional[int]=...,
        MyStringField: _typing.Optional[str]=...,
        majorVer: _typing.Optional[int]=...,
        data: _typing.Optional[_fbthrift_compatible_with_MyDataItem]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, str, int, MyDataItem]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.MyStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyStruct": ...  # type: ignore


class _fbthrift_compatible_with_MyDataItem:
    pass


class MyDataItem(_fbthrift_python_types.Struct, _fbthrift_compatible_with_MyDataItem):
    def __init__(
        self,
    ) -> None: ...

    def __call__(
        self,
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[None]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.MyDataItem": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyDataItem": ...  # type: ignore


class _fbthrift_compatible_with_Renaming:
    pass


class Renaming(_fbthrift_python_types.Struct, _fbthrift_compatible_with_Renaming):
    foo: _typing.Final[int] = ...
    def __init__(
        self, *,
        foo: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        foo: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.Renaming": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.Renaming": ...  # type: ignore


class _fbthrift_compatible_with_AnnotatedTypes:
    pass


class AnnotatedTypes(_fbthrift_python_types.Struct, _fbthrift_compatible_with_AnnotatedTypes):
    binary_field: _typing.Final[bytes] = ...
    list_field: _typing.Final[_typing.Sequence[_typing.Mapping[int, str]]] = ...
    def __init__(
        self, *,
        binary_field: _typing.Optional[bytes]=...,
        list_field: _typing.Optional[_typing.Sequence[_typing.Mapping[int, str]]]=...
    ) -> None: ...

    def __call__(
        self, *,
        binary_field: _typing.Optional[bytes]=...,
        list_field: _typing.Optional[_typing.Sequence[_typing.Mapping[int, str]]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[bytes, _typing.Sequence[_typing.Mapping[int, str]]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.AnnotatedTypes": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.AnnotatedTypes": ...  # type: ignore


class _fbthrift_compatible_with_ForwardUsageRoot:
    pass


class ForwardUsageRoot(_fbthrift_python_types.Struct, _fbthrift_compatible_with_ForwardUsageRoot):
    ForwardUsageStruct: _typing.Final[_typing.Optional[ForwardUsageStruct]] = ...
    ForwardUsageByRef: _typing.Final[_typing.Optional[ForwardUsageByRef]] = ...
    def __init__(
        self, *,
        ForwardUsageStruct: _typing.Optional[_fbthrift_compatible_with_ForwardUsageStruct]=...,
        ForwardUsageByRef: _typing.Optional[_fbthrift_compatible_with_ForwardUsageByRef]=...
    ) -> None: ...

    def __call__(
        self, *,
        ForwardUsageStruct: _typing.Optional[_fbthrift_compatible_with_ForwardUsageStruct]=...,
        ForwardUsageByRef: _typing.Optional[_fbthrift_compatible_with_ForwardUsageByRef]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[ForwardUsageStruct, ForwardUsageByRef]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.ForwardUsageRoot": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.ForwardUsageRoot": ...  # type: ignore


class _fbthrift_compatible_with_ForwardUsageStruct:
    pass


class ForwardUsageStruct(_fbthrift_python_types.Struct, _fbthrift_compatible_with_ForwardUsageStruct):
    foo: _typing.Final[_typing.Optional[ForwardUsageRoot]] = ...
    def __init__(
        self, *,
        foo: _typing.Optional[_fbthrift_compatible_with_ForwardUsageRoot]=...
    ) -> None: ...

    def __call__(
        self, *,
        foo: _typing.Optional[_fbthrift_compatible_with_ForwardUsageRoot]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[ForwardUsageRoot]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.ForwardUsageStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.ForwardUsageStruct": ...  # type: ignore


class _fbthrift_compatible_with_ForwardUsageByRef:
    pass


class ForwardUsageByRef(_fbthrift_python_types.Struct, _fbthrift_compatible_with_ForwardUsageByRef):
    foo: _typing.Final[_typing.Optional[ForwardUsageRoot]] = ...
    def __init__(
        self, *,
        foo: _typing.Optional[_fbthrift_compatible_with_ForwardUsageRoot]=...
    ) -> None: ...

    def __call__(
        self, *,
        foo: _typing.Optional[_fbthrift_compatible_with_ForwardUsageRoot]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[ForwardUsageRoot]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.ForwardUsageByRef": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.ForwardUsageByRef": ...  # type: ignore


class _fbthrift_compatible_with_IncompleteMap:
    pass


class IncompleteMap(_fbthrift_python_types.Struct, _fbthrift_compatible_with_IncompleteMap):
    field: _typing.Final[_typing.Optional[_typing.Mapping[int, IncompleteMapDep]]] = ...
    def __init__(
        self, *,
        field: _typing.Optional[_typing.Mapping[int, _fbthrift_compatible_with_IncompleteMapDep]]=...
    ) -> None: ...

    def __call__(
        self, *,
        field: _typing.Optional[_typing.Mapping[int, _fbthrift_compatible_with_IncompleteMapDep]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Mapping[int, IncompleteMapDep]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.IncompleteMap": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.IncompleteMap": ...  # type: ignore


class _fbthrift_compatible_with_IncompleteMapDep:
    pass


class IncompleteMapDep(_fbthrift_python_types.Struct, _fbthrift_compatible_with_IncompleteMapDep):
    def __init__(
        self,
    ) -> None: ...

    def __call__(
        self,
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[None]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.IncompleteMapDep": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.IncompleteMapDep": ...  # type: ignore


class _fbthrift_compatible_with_CompleteMap:
    pass


class CompleteMap(_fbthrift_python_types.Struct, _fbthrift_compatible_with_CompleteMap):
    field: _typing.Final[_typing.Optional[_typing.Mapping[int, CompleteMapDep]]] = ...
    def __init__(
        self, *,
        field: _typing.Optional[_typing.Mapping[int, _fbthrift_compatible_with_CompleteMapDep]]=...
    ) -> None: ...

    def __call__(
        self, *,
        field: _typing.Optional[_typing.Mapping[int, _fbthrift_compatible_with_CompleteMapDep]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Mapping[int, CompleteMapDep]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.CompleteMap": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.CompleteMap": ...  # type: ignore


class _fbthrift_compatible_with_CompleteMapDep:
    pass


class CompleteMapDep(_fbthrift_python_types.Struct, _fbthrift_compatible_with_CompleteMapDep):
    def __init__(
        self,
    ) -> None: ...

    def __call__(
        self,
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[None]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.CompleteMapDep": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.CompleteMapDep": ...  # type: ignore


class _fbthrift_compatible_with_IncompleteList:
    pass


class IncompleteList(_fbthrift_python_types.Struct, _fbthrift_compatible_with_IncompleteList):
    field: _typing.Final[_typing.Optional[_typing.Sequence[IncompleteListDep]]] = ...
    def __init__(
        self, *,
        field: _typing.Optional[_typing.Sequence[_fbthrift_compatible_with_IncompleteListDep]]=...
    ) -> None: ...

    def __call__(
        self, *,
        field: _typing.Optional[_typing.Sequence[_fbthrift_compatible_with_IncompleteListDep]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Sequence[IncompleteListDep]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.IncompleteList": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.IncompleteList": ...  # type: ignore


class _fbthrift_compatible_with_IncompleteListDep:
    pass


class IncompleteListDep(_fbthrift_python_types.Struct, _fbthrift_compatible_with_IncompleteListDep):
    def __init__(
        self,
    ) -> None: ...

    def __call__(
        self,
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[None]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.IncompleteListDep": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.IncompleteListDep": ...  # type: ignore


class _fbthrift_compatible_with_CompleteList:
    pass


class CompleteList(_fbthrift_python_types.Struct, _fbthrift_compatible_with_CompleteList):
    field: _typing.Final[_typing.Optional[_typing.Sequence[CompleteListDep]]] = ...
    def __init__(
        self, *,
        field: _typing.Optional[_typing.Sequence[_fbthrift_compatible_with_CompleteListDep]]=...
    ) -> None: ...

    def __call__(
        self, *,
        field: _typing.Optional[_typing.Sequence[_fbthrift_compatible_with_CompleteListDep]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Sequence[CompleteListDep]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.CompleteList": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.CompleteList": ...  # type: ignore


class _fbthrift_compatible_with_CompleteListDep:
    pass


class CompleteListDep(_fbthrift_python_types.Struct, _fbthrift_compatible_with_CompleteListDep):
    def __init__(
        self,
    ) -> None: ...

    def __call__(
        self,
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[None]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.CompleteListDep": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.CompleteListDep": ...  # type: ignore


class _fbthrift_compatible_with_AdaptedList:
    pass


class AdaptedList(_fbthrift_python_types.Struct, _fbthrift_compatible_with_AdaptedList):
    field: _typing.Final[_typing.Optional[_typing.Sequence[AdaptedListDep]]] = ...
    def __init__(
        self, *,
        field: _typing.Optional[_typing.Sequence[_fbthrift_compatible_with_AdaptedListDep]]=...
    ) -> None: ...

    def __call__(
        self, *,
        field: _typing.Optional[_typing.Sequence[_fbthrift_compatible_with_AdaptedListDep]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Sequence[AdaptedListDep]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.AdaptedList": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.AdaptedList": ...  # type: ignore


class _fbthrift_compatible_with_AdaptedListDep:
    pass


class AdaptedListDep(_fbthrift_python_types.Struct, _fbthrift_compatible_with_AdaptedListDep):
    field: _typing.Final[AdaptedList] = ...
    def __init__(
        self, *,
        field: _typing.Optional[_fbthrift_compatible_with_AdaptedList]=...
    ) -> None: ...

    def __call__(
        self, *,
        field: _typing.Optional[_fbthrift_compatible_with_AdaptedList]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[AdaptedList]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.AdaptedListDep": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.AdaptedListDep": ...  # type: ignore


class _fbthrift_compatible_with_DependentAdaptedList:
    pass


class DependentAdaptedList(_fbthrift_python_types.Struct, _fbthrift_compatible_with_DependentAdaptedList):
    field: _typing.Final[_typing.Optional[_typing.Sequence[DependentAdaptedListDep]]] = ...
    def __init__(
        self, *,
        field: _typing.Optional[_typing.Sequence[_fbthrift_compatible_with_DependentAdaptedListDep]]=...
    ) -> None: ...

    def __call__(
        self, *,
        field: _typing.Optional[_typing.Sequence[_fbthrift_compatible_with_DependentAdaptedListDep]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Sequence[DependentAdaptedListDep]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.DependentAdaptedList": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.DependentAdaptedList": ...  # type: ignore


class _fbthrift_compatible_with_DependentAdaptedListDep:
    pass


class DependentAdaptedListDep(_fbthrift_python_types.Struct, _fbthrift_compatible_with_DependentAdaptedListDep):
    field: _typing.Final[_typing.Optional[int]] = ...
    def __init__(
        self, *,
        field: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        field: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.DependentAdaptedListDep": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.DependentAdaptedListDep": ...  # type: ignore


class _fbthrift_compatible_with_AllocatorAware:
    pass


class AllocatorAware(_fbthrift_python_types.Struct, _fbthrift_compatible_with_AllocatorAware):
    aa_list: _typing.Final[_typing.Sequence[int]] = ...
    aa_set: _typing.Final[_typing.AbstractSet[int]] = ...
    aa_map: _typing.Final[_typing.Mapping[int, int]] = ...
    aa_string: _typing.Final[str] = ...
    not_a_container: _typing.Final[int] = ...
    aa_unique: _typing.Final[int] = ...
    aa_shared: _typing.Final[int] = ...
    def __init__(
        self, *,
        aa_list: _typing.Optional[_typing.Sequence[int]]=...,
        aa_set: _typing.Optional[_typing.AbstractSet[int]]=...,
        aa_map: _typing.Optional[_typing.Mapping[int, int]]=...,
        aa_string: _typing.Optional[str]=...,
        not_a_container: _typing.Optional[int]=...,
        aa_unique: _typing.Optional[int]=...,
        aa_shared: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        aa_list: _typing.Optional[_typing.Sequence[int]]=...,
        aa_set: _typing.Optional[_typing.AbstractSet[int]]=...,
        aa_map: _typing.Optional[_typing.Mapping[int, int]]=...,
        aa_string: _typing.Optional[str]=...,
        not_a_container: _typing.Optional[int]=...,
        aa_unique: _typing.Optional[int]=...,
        aa_shared: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Sequence[int], _typing.AbstractSet[int], _typing.Mapping[int, int], str, int, int, int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.AllocatorAware": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.AllocatorAware": ...  # type: ignore


class _fbthrift_compatible_with_AllocatorAware2:
    pass


class AllocatorAware2(_fbthrift_python_types.Struct, _fbthrift_compatible_with_AllocatorAware2):
    not_a_container: _typing.Final[int] = ...
    box_field: _typing.Final[_typing.Optional[int]] = ...
    def __init__(
        self, *,
        not_a_container: _typing.Optional[int]=...,
        box_field: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        not_a_container: _typing.Optional[int]=...,
        box_field: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.AllocatorAware2": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.AllocatorAware2": ...  # type: ignore


class _fbthrift_compatible_with_TypedefStruct:
    pass


class TypedefStruct(_fbthrift_python_types.Struct, _fbthrift_compatible_with_TypedefStruct):
    i32_field: _typing.Final[int] = ...
    IntTypedef_field: _typing.Final[int] = ...
    UintTypedef_field: _typing.Final[int] = ...
    def __init__(
        self, *,
        i32_field: _typing.Optional[int]=...,
        IntTypedef_field: _typing.Optional[int]=...,
        UintTypedef_field: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        i32_field: _typing.Optional[int]=...,
        IntTypedef_field: _typing.Optional[int]=...,
        UintTypedef_field: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, int, int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.TypedefStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.TypedefStruct": ...  # type: ignore


class _fbthrift_compatible_with_StructWithDoubleUnderscores:
    pass


class StructWithDoubleUnderscores(_fbthrift_python_types.Struct, _fbthrift_compatible_with_StructWithDoubleUnderscores):
    _StructWithDoubleUnderscores__field: _typing.Final[int] = ...
    def __init__(
        self, *,
        _StructWithDoubleUnderscores__field: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        _StructWithDoubleUnderscores__field: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_py3(self) -> "apache.thrift.fixtures.types.module.types.StructWithDoubleUnderscores": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.StructWithDoubleUnderscores": ...  # type: ignore

TBinary = bytes
IntTypedef = int
UintTypedef = int
SomeListOfTypeMap_2468 = _typing.List[_typing.Mapping[int, str]]
TBinary_8623 = bytes
i32_9314 = int
list_i32_9187 = _typing.List[int]
map_i32_i32_9565 = _typing.Dict[int, int]
map_i32_string_1261 = _typing.Dict[int, str]
set_i32_7070 = _typing.Set[int]
set_i32_7194 = _typing.Set[int]
string_5252 = str


class _fbthrift_SomeService_bounce_map_args(_fbthrift_python_types.Struct):
    m: _typing.Final[_typing.Mapping[int, str]] = ...

    def __init__(
        self, *,
        m: _typing.Optional[_typing.Mapping[int, str]]=...
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[
        str,
        _typing.Union[None, _typing.Mapping[int, str]]]]: ...


class _fbthrift_SomeService_bounce_map_result(_fbthrift_python_types.Struct):
    success: _typing.Final[_typing.Mapping[int, str]]

    def __init__(
        self, *, success: _typing.Optional[_typing.Mapping[int, str]] = ...
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[
        str,
        _typing.Union[
            _typing.Mapping[int, str],
        ]]]: ...


class _fbthrift_SomeService_binary_keyed_map_args(_fbthrift_python_types.Struct):
    r: _typing.Final[_typing.Sequence[int]] = ...

    def __init__(
        self, *,
        r: _typing.Optional[_typing.Sequence[int]]=...
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[
        str,
        _typing.Union[None, _typing.Sequence[int]]]]: ...


class _fbthrift_SomeService_binary_keyed_map_result(_fbthrift_python_types.Struct):
    success: _typing.Final[_typing.Mapping[bytes, int]]

    def __init__(
        self, *, success: _typing.Optional[_typing.Mapping[bytes, int]] = ...
    ) -> None: ...

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[
        str,
        _typing.Union[
            _typing.Mapping[bytes, int],
        ]]]: ...
