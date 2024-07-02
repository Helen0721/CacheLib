/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

namespace py3 thrift.test.thrift_python

struct TestStruct {
  1: string unqualified_string;
  2: optional string optional_string;
}

struct TestStructWithDefaultValues {
  1: i32 unqualified_integer = 42;

  2: optional i32 optional_integer = 43;

  3: TestStruct unqualified_struct = TestStruct{unqualified_string = "hello"};

  4: optional TestStruct optional_struct = TestStruct{
    unqualified_string = "world",
  };

  5: TestStruct unqualified_struct_intrinsic_default;

  6: optional TestStruct optional_struct_intrinsic_default;
}

struct TestStructAllThriftPrimitiveTypes {
  1: bool unqualified_bool;
  2: optional bool optional_bool;

  3: byte unqualified_byte;
  4: optional byte optional_byte;

  5: i16 unqualified_i16;
  6: optional i16 optional_i16;

  7: i32 unqualified_i32;
  8: optional i32 optional_i32;

  9: i64 unqualified_i64;
  10: optional i64 optional_i64;

  11: float unqualified_float;
  12: optional float optional_float;

  13: double unqualified_double;
  14: optional double optional_double;

  15: string unqualified_string;
  16: optional string optional_string;
}

struct TestStructAllThriftPrimitiveTypesWithDefaultValues {
  1: bool unqualified_bool = true;

  2: byte unqualified_byte = 32;

  3: i16 unqualified_i16 = 512;

  4: i32 unqualified_i32 = 2048;

  5: i64 unqualified_i64 = 999;

  6: float unqualified_float = 1.0;

  7: double unqualified_double = 1.231;

  8: string unqualified_string = "thrift-python";
}
