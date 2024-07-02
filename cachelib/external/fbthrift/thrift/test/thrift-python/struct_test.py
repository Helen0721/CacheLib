# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import dataclasses
import importlib
import types
import typing
import unittest

import thrift.python.mutable_serializer as mutable_serializer

import thrift.python.serializer as immutable_serializer

from parameterized import parameterized

from thrift.python.mutable_types import (
    MutableStruct,
    MutableStructMeta,
    MutableStructOrUnion,
)
from thrift.python.types import (
    Struct as ImmutableStruct,
    StructMeta as ImmutableStructMeta,
    StructOrUnion as ImmutableStructOrUnion,
)

from thrift.test.thrift_python.struct_test.thrift_mutable_types import (  # @manual=//thrift/test/thrift-python:struct_test_thrift-python-types
    TestStruct as TestStructMutable,
    TestStructAllThriftPrimitiveTypes as TestStructAllThriftPrimitiveTypesMutable,
    TestStructAllThriftPrimitiveTypesWithDefaultValues as TestStructAllThriftPrimitiveTypesWithDefaultValuesMutable,
    TestStructWithDefaultValues as TestStructWithDefaultValuesMutable,
)

from thrift.test.thrift_python.struct_test.thrift_types import (
    TestStruct as TestStructImmutable,
    TestStructAllThriftPrimitiveTypes as TestStructAllThriftPrimitiveTypesImmutable,
    TestStructAllThriftPrimitiveTypesWithDefaultValues as TestStructAllThriftPrimitiveTypesWithDefaultValuesImmutable,
    TestStructWithDefaultValues as TestStructWithDefaultValuesImmutable,
)

max_byte = 2**7 - 1
max_i16 = 2**15 - 1
max_i32 = 2**31 - 1
max_i64 = 2**63 - 1


def _thrift_serialization_round_trip(
    test, module, control: typing.Union[MutableStructOrUnion, ImmutableStructOrUnion]
) -> None:
    for proto in module.Protocol:
        encoded = module.serialize(control, protocol=proto)
        test.assertIsInstance(encoded, bytes)

        decoded = module.deserialize(type(control), encoded, protocol=proto)
        test.assertIsInstance(decoded, type(control))
        test.assertEqual(control, decoded)


class ThriftPython_ImmutableStruct_Test(unittest.TestCase):
    def setUp(self) -> None:
        # Disable maximum printed diff length.
        self.maxDiff = None

    def test_creation(self) -> None:
        # Field initialization at instantiation time
        w_new = TestStructImmutable(unqualified_string="hello, world!")
        self.assertEqual(w_new.unqualified_string, "hello, world!")

    def test_call(self) -> None:
        w = TestStructImmutable(unqualified_string="hello, world!")

        # Call operator: create a copy, with new values.
        # Original instance is unchanged.
        w2 = w(unqualified_string="foobar")
        self.assertIsNot(w, w2)
        self.assertEqual(w2.unqualified_string, "foobar")
        self.assertEqual(w.unqualified_string, "hello, world!")
        self.assertNotEqual(w, w2)

        # Call operator with no values given: returns self
        # Note: this is equivalent to returning a copy of self in the immutable
        # domain (since their contents cannot change).
        w3 = w()
        self.assertIs(w, w3)

    def test_default_values(self) -> None:
        # Custom default values:
        # Newly created instance has custom default values for non-optional
        # fields, but custom default values for optional fields are ignored.
        self.assertEqual(
            TestStructWithDefaultValuesImmutable(),
            TestStructWithDefaultValuesImmutable(
                unqualified_integer=42,
                optional_integer=None,
                unqualified_struct=TestStructImmutable(unqualified_string="hello"),
                optional_struct=None,
            ),
        )

        # Intrinsic default values:
        # optional struct field is None
        self.assertIsNone(
            TestStructWithDefaultValuesImmutable().optional_struct_intrinsic_default
        )

        # unqualified struct field is default-initialized
        self.assertEqual(
            TestStructImmutable(),
            TestStructWithDefaultValuesImmutable().unqualified_struct_intrinsic_default,
        )

    def test_type_safety(self) -> None:
        # Field type is validated on instantiation
        with self.assertRaisesRegex(
            TypeError,
            (
                "Cannot create internal string data representation. Expected "
                "type <class 'str'>, got: <class 'int'>."
            ),
        ):
            TestStructImmutable(unqualified_string=42)

    def test_equality_and_hashability(self) -> None:
        # Equality
        w_new = TestStructImmutable(unqualified_string="hello, world!")
        self.assertEqual(w_new, w_new)
        w_new2 = TestStructImmutable(unqualified_string="hello, world!")
        self.assertEqual(w_new, w_new2)
        self.assertIsNot(w_new, w_new2)

        # Immutable types are hashable, with proper semantics.
        self.assertEqual(hash(w_new), hash(w_new2))
        self.assertIn(w_new, {w_new2})

        mapping = {w_new: 123}
        self.assertIn(w_new, mapping)
        self.assertIn(w_new2, mapping)
        self.assertEqual(mapping[w_new], 123)
        self.assertEqual(mapping[w_new2], 123)

        mapping[w_new2] = 456
        self.assertEqual(mapping[w_new], 456)
        self.assertEqual(mapping[w_new2], 456)

    def test_ordering(self) -> None:
        self.assertLess(
            TestStructImmutable(unqualified_string="a"),
            TestStructImmutable(unqualified_string="b"),
        )
        self.assertLess(
            TestStructImmutable(unqualified_string="a", optional_string="z"),
            TestStructImmutable(unqualified_string="b", optional_string="a"),
        )
        self.assertGreater(
            TestStructImmutable(unqualified_string="b", optional_string="z"),
            TestStructImmutable(unqualified_string="b", optional_string="a"),
        )

    def test_subclass(self) -> None:
        types.new_class(
            "TestImmutableSubclass",
            bases=(TestStructImmutable,),
            exec_body=lambda ns: ns.update(_fbthrift_SPEC=()),
        )

    def test_base_classes(self) -> None:
        self.assertIsInstance(TestStructImmutable(), ImmutableStruct)
        self.assertIsInstance(TestStructImmutable(), ImmutableStructOrUnion)

    def test_type(self) -> None:
        self.assertEqual(type(TestStructImmutable), ImmutableStructMeta)
        self.assertEqual(type(TestStructImmutable()), TestStructImmutable)

    def test_iteration(self) -> None:
        # Iterating over the class yields tuples of (field_name, None).
        self.assertSetEqual(
            set(TestStructImmutable),
            {("unqualified_string", None), ("optional_string", None)},
        )

        # Iterating over an instance yields (field_name, field_value) tuples.
        self.assertSetEqual(
            set(TestStructImmutable(unqualified_string="hello")),
            {("unqualified_string", "hello"), ("optional_string", None)},
        )

    def test_del_attribute(self) -> None:
        w = TestStructImmutable(unqualified_string="hello, world!")

        # Attributes of immutable types cannot be deleted.
        #
        # Note the interesting (and somewhat inconsistent) current behavior:
        # Calling `del` prior to accessing an attribute raises an AttributeError
        # (at the cinder level), but doing so after accessing it is a silent
        # no-op.
        with self.assertRaisesRegex(AttributeError, "unqualified_string"):
            del w.unqualified_string
        self.assertEqual(w.unqualified_string, "hello, world!")
        del w.unqualified_string  # silent no-op
        self.assertEqual(w.unqualified_string, "hello, world!")

        # However, a new instance of the object can be created with a specific
        # attribute "deleted", by explicitly assigning it the "None" value:
        w_cleared = w(unqualified_string=None)
        self.assertEqual(w_cleared.unqualified_string, "")

        # "Deleting" a field (by creating a new instance) resets it to its
        # *standard default value*, i.e. the custom default value if provided
        # (see thrift/doc/idl/index.md#default-values).
        w_default_values = TestStructWithDefaultValuesImmutable(unqualified_integer=123)
        self.assertEqual(w_default_values.unqualified_integer, 123)
        w_default_values_cleared = w_default_values(unqualified_integer=None)
        self.assertEqual(w_default_values_cleared.unqualified_integer, 42)

    def test_type_hints(self) -> None:
        # thrift-python immutable structs do not include type hints directly
        # (although a separate .pyi interface is generated to allow tooling to
        # do static type checking)
        self.assertEqual(typing.get_type_hints(TestStructImmutable), {})

    def test_serialization_round_trip(self) -> None:
        s = TestStructAllThriftPrimitiveTypesImmutable(
            unqualified_string="Hello world!",
            optional_string="Hello optional!",
            unqualified_i32=19,
            optional_i32=23,
            unqualified_double=2.1,
            optional_double=1.3,
            unqualified_bool=True,
            optional_bool=False,
        )
        _thrift_serialization_round_trip(self, immutable_serializer, s)

        s_default_value = TestStructAllThriftPrimitiveTypesWithDefaultValuesImmutable()
        _thrift_serialization_round_trip(self, immutable_serializer, s_default_value)


class ThriftPython_MutableStruct_Test(unittest.TestCase):
    def setUp(self) -> None:
        # Disable maximum printed diff length.
        self.maxDiff = None

    def test_creation_and_assignment(self) -> None:
        w = TestStructMutable()
        self.assertEqual(w.unqualified_string, "")
        w.unqualified_string = "hello, world!"
        self.assertEqual(w.unqualified_string, "hello, world!")

        w2 = TestStructMutable(unqualified_string="hello")
        self.assertEqual(w2.unqualified_string, "hello")
        w2.unqualified_string += ", world!"
        self.assertEqual(w2.unqualified_string, "hello, world!")

    def test_call(self) -> None:
        # DO_BEFORE(aristidis,20240520): Support call operator for mutable types
        with self.assertRaises(TypeError):
            w = TestStructMutable(unqualified_string="hello, world!")

            # Call operator: create a (deep) copy, with new values.
            # Original instance is unchanged.
            w2 = w(unqualified_string="foobar")
            self.assertIsNot(w, w2)
            self.assertEqual(w2.unqualified_string, "foobar")
            self.assertEqual(w.unqualified_string, "hello, world!")
            self.assertNotEqual(w, w2)

            # Call operator with no values given: returns (deep) copy of self
            # Note the difference with immutable types (which return self).
            w3 = w()
            self.assertIsNot(w, w3)
            self.assertEqual(w, w3)

    def test_default_values(self) -> None:
        # Intrinsic default values:
        # optional struct field is None
        self.assertIsNone(
            TestStructWithDefaultValuesMutable().optional_struct_intrinsic_default
        )

        self.assertEqual(
            TestStructMutable(),
            TestStructWithDefaultValuesMutable().unqualified_struct_intrinsic_default,
        )

    def test_equality_and_hashability(self) -> None:
        # Equality
        w_mutable = TestStructMutable(unqualified_string="hello, world!")
        self.assertEqual(w_mutable, w_mutable)

        w_mutable2 = TestStructMutable(unqualified_string="hello, world!")
        self.assertEqual(w_mutable.unqualified_string, w_mutable2.unqualified_string)
        self.assertEqual(w_mutable, w_mutable2)

        # Instances are not hashable
        with self.assertRaisesRegex(TypeError, "unhashable type: 'TestStruct'"):
            hash(w_mutable)

        with self.assertRaisesRegex(TypeError, "unhashable type: 'TestStruct'"):
            {w_mutable}

        # List and Tuple membership tests use equality (not hashing).
        self.assertIn(w_mutable, [w_mutable2])
        self.assertIn(w_mutable, (w_mutable2,))

        w_mutable2.unqualified_string = "changed value"
        self.assertNotIn(w_mutable, [w_mutable2])
        self.assertNotIn(w_mutable, (w_mutable2,))

    def test_ordering(self) -> None:
        # DO_BEFORE(aristidis, 20240515): ordering for mutable thrift-python
        with self.assertRaisesRegex(
            TypeError,
            "'<' not supported between instances of 'TestStruct' and 'TestStruct'",
        ):
            self.assertLess(
                TestStructMutable(unqualified_string="a"),
                TestStructMutable(unqualified_string="b"),
            )

    def test_subclass(self) -> None:
        with self.assertRaisesRegex(
            TypeError, "Inheriting from thrift-python data types is forbidden:"
        ):
            types.new_class("TestSubclass2", bases=(TestStructMutable,))

    def test_base_classes(self) -> None:
        self.assertIsInstance(TestStructMutable(), MutableStruct)
        self.assertIsInstance(TestStructMutable(), MutableStructOrUnion)

    def test_type(self) -> None:
        self.assertEqual(type(TestStructMutable), MutableStructMeta)
        self.assertEqual(type(TestStructMutable()), TestStructMutable)

    def test_iteration(self) -> None:
        # Iterating over the class yields tuples of (field_name, None).
        self.assertSetEqual(
            set(TestStructMutable),
            {("unqualified_string", None), ("optional_string", None)},
        )

        # Iterating over an instance yields (field_name, field_value) tuples.
        self.assertSetEqual(
            set(TestStructMutable(unqualified_string="hello")),
            {("unqualified_string", "hello"), ("optional_string", None)},
        )

    def test_del_attribute(self) -> None:
        w = TestStructMutable(unqualified_string="hello", optional_string="world")

        # Deleting an attribute on a (mutable) thrift-python instance raises
        # `AttributeError`
        with self.assertRaises(AttributeError):
            del w.unqualified_string

        with self.assertRaises(AttributeError):
            del w.optional_string

        self.assertEqual(w.unqualified_string, "hello")
        self.assertEqual(w.optional_string, "world")

        with self.assertRaises(AttributeError):
            del w.unqualified_string

        with self.assertRaises(AttributeError):
            del w.optional_string

    def test_type_hints(self) -> None:
        # Similar to thrift-python immutable structs, mutable structs do not
        # include type hints directly
        self.assertEqual(typing.get_type_hints(TestStructMutable), {})

    def test_to_immutable(self) -> None:
        # DO_BEFORE(aristidis,20240521): Fix _to_immutable() support
        with self.assertRaises(TypeError):
            w_mutable = TestStructMutable(unqualified_string="hello")
            w_immutable = w_mutable._to_immutable()
            self.assertIsNot(w_mutable, w_immutable)

            # Even though their contents are the same, the mutable and immutable
            # instance are not "equal":
            self.assertEqual(
                w_mutable.unqualified_string, w_immutable.unqualified_string
            )
            self.assertNotEqual(w_mutable, w_immutable)

            # The newly obtained immutable object however is equal to a new
            # TestStructImmutable instance (with the same contents)
            self.assertEqual(
                w_immutable, TestStructImmutable(unqualified_string="hello")
            )

            w_mutable.unqualified_string = "hello, world!"
            self.assertNotEqual(
                w_mutable.unqualified_string, w_immutable.unqualified_string
            )

            # Check that converting to immutable validates field types
            w_mutable.unqualified_string = 42
            with self.assertRaisesRegex(
                TypeError,
                (
                    "TypeError: Cannot create internal string data representation. "
                    "Expected type <class 'str'>, got: <class 'int'>."
                ),
            ):
                w_mutable._to_immutable()

    def _assert_field_behavior(
        self,
        struct,
        field_name: str,
        expected_default_value,
        value,
        invalid_value,
        overflow_value=None,
    ):
        """
        This function is a helper function used to assert the behavior of a
        specific field in a structure.
            field_name (str): The name of the field to be tested.
            expected_default_value: The expected default value of the field.
            value: The value to be set for the field.
            invalid_value: A value of an incorrect type that, when set,
                should raise a TypeError.
            overflow_value (optional): A value that, when set, should raise
                an `OverflowError`. This is typically used for integral types.
        """
        # Check for the `expected_default_value`. The unqualified field should
        # never be `None`
        if expected_default_value is not None:
            self.assertIsNotNone(getattr(struct, field_name))
            self.assertEqual(expected_default_value, getattr(struct, field_name))
        else:  # OPTIONAL
            self.assertIsNone(getattr(struct, field_name))

        # Set the `value`, read it back
        setattr(struct, field_name, value)
        self.assertEqual(value, getattr(struct, field_name))

        # TODO: How to reset field to standard default value?
        struct._do_not_use_resetFieldToStandardDefault(field_name)
        if expected_default_value is not None:
            self.assertIsNotNone(getattr(struct, field_name))
            self.assertEqual(expected_default_value, getattr(struct, field_name))
        else:  # OPTIONAL
            self.assertIsNone(getattr(struct, field_name))

        # `del struct.field_name` raises a `AttributeError`
        with self.assertRaises(AttributeError):
            delattr(struct, field_name)

        # Assigning `None` raises a `TypeError`
        with self.assertRaises(TypeError):
            setattr(struct, field_name, None)

        # Value with wrong type raises `TypeError`
        with self.assertRaises(TypeError):
            setattr(struct, field_name, invalid_value)

        # For integral types check `OverflowError`
        if overflow_value is not None:
            with self.assertRaises(OverflowError):
                setattr(struct, field_name, overflow_value)

    @parameterized.expand(
        [
            # (field_name, expected_default_value, value, invalid_value, overflow_value")
            ("unqualified_bool", False, True, "Not Bool", None),
            ("optional_bool", None, True, "Not Bool", None),
            ("unqualified_byte", 0, max_byte, "Not Byte", max_byte + 1),
            ("optional_byte", None, max_byte, "Not Byte", max_byte + 1),
            ("unqualified_i16", 0, max_i16, "Not i16", max_i16 + 1),
            ("optional_i16", None, max_i16, "Not i16", max_i16 + 1),
            ("unqualified_i32", 0, max_i32, "Not i32", max_i32 + 1),
            ("optional_i32", None, max_i32, "Not i32", max_i32 + 1),
            ("unqualified_i64", 0, max_i64, "Not i64", max_i64 + 1),
            ("optional_i64", None, max_i64, "Not i64", max_i64 + 1),
            ("unqualified_float", 0.0, 1.0, "Not float", None),
            ("optional_float", None, 1.0, "Not float", None),
            ("unqualified_double", 0.0, 99.12, "Not double", None),
            ("optional_double", None, 99.12, "Not double", None),
            ("unqualified_string", "", "str-value", 999, None),
            ("optional_string", None, "str-value", 999, None),
        ]
    )
    def test_create_and_assign_for_all_primitive_types(
        self, field_name, expected_default_value, value, invalid_value, overflow_value
    ):
        s = TestStructAllThriftPrimitiveTypesMutable()
        self._assert_field_behavior(
            s,
            field_name=field_name,
            expected_default_value=expected_default_value,
            value=value,
            invalid_value=invalid_value,
            overflow_value=overflow_value,
        )

    @parameterized.expand(
        [
            # (field_name, expected_default_value, value, invalid_value, overflow_value")
            # `expected_default_value` is from IDL
            ("unqualified_bool", True, True, "Not Bool", None),
            ("unqualified_byte", 32, max_byte, "Not Byte", max_byte + 1),
            ("unqualified_i16", 512, max_i16, "Not i16", max_i16 + 1),
            ("unqualified_i32", 2048, max_i32, "Not i32", max_i32 + 1),
            ("unqualified_i64", 999, max_i64, "Not i64", max_i64 + 1),
            ("unqualified_float", 1.0, 1.0, "Not float", None),
            ("unqualified_double", 1.231, 99.12, "Not double", None),
            ("unqualified_string", "thrift-python", "str-value", 999, None),
        ]
    )
    def test_create_and_assign_for_all_primitive_types_with_default_values(
        self, field_name, expected_default_value, value, invalid_value, overflow_value
    ):
        s = TestStructAllThriftPrimitiveTypesWithDefaultValuesMutable()
        self._assert_field_behavior(
            s,
            field_name=field_name,
            expected_default_value=expected_default_value,
            value=value,
            invalid_value=invalid_value,
            overflow_value=overflow_value,
        )

    def test_create_and_assign_for_i32(self) -> None:
        # This is the singular version of `test_create_and_assign_for_all_types`
        # for the i32 type. It's more readable since it doesn't use the
        # `verify_{qualified,optional}_helper` functions.
        s = TestStructAllThriftPrimitiveTypesMutable(unqualified_i32=11)

        # Check the value assigned during initialization
        self.assertEqual(11, s.unqualified_i32)

        # Set the value and read it back
        s.unqualified_i32 = 23
        self.assertEqual(23, s.unqualified_i32)

        # `del struct.field_name` raises a `AttributeError`
        with self.assertRaises(AttributeError):
            del s.unqualified_i32

        # Assigning `None` raises a `TypeError`
        with self.assertRaises(TypeError):
            s.unqualified_i32 = None

        # Assigning a value of the wrong type raises a `TypeError`
        with self.assertRaises(TypeError):
            s.unqualified_i32 = "This is not an integer"

        # Boundary check for integral types
        with self.assertRaises(OverflowError):
            s.unqualified_i32 = 2**31

        s = TestStructAllThriftPrimitiveTypesWithDefaultValuesMutable()
        # from IDL: i32 unqualified_i32 = 2048;

        # Check the value from IDL during initialization
        self.assertEqual(2048, s.unqualified_i32)

        # Set the value and read it back
        s.unqualified_i32 = 32
        self.assertEqual(32, s.unqualified_i32)

        # `del struct.field_name` raises a `AttributeError`
        with self.assertRaises(AttributeError):
            del s.unqualified_i32

        # Assigning `None` raises a `TypeError`
        with self.assertRaises(TypeError):
            s.unqualified_i32 = None

        # Assigning a value of the wrong type raises a `TypeError`
        with self.assertRaises(TypeError):
            s.unqualified_i32 = "This is not an integer"

        # Boundary check for integral types
        with self.assertRaises(OverflowError):
            s.unqualified_i32 = -(2**31 + 1)

    def test_serialization_round_trip(self) -> None:
        s = TestStructAllThriftPrimitiveTypesMutable()
        s.unqualified_string = "Hello world!"
        s.optional_string = "Hello optional!"
        s.unqualified_i32 = 19
        s.optional_i32 = 23
        s.unqualified_double = 2.1
        s.optional_double = 1.3
        s.unqualified_bool = True
        s.optional_bool = False
        _thrift_serialization_round_trip(self, mutable_serializer, s)

        s_default_value = TestStructAllThriftPrimitiveTypesWithDefaultValuesMutable()
        _thrift_serialization_round_trip(self, mutable_serializer, s_default_value)
