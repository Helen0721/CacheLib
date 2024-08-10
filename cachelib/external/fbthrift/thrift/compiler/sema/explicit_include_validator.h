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

#pragma once

#include <memory>
#include <string>
#include <vector>

#include <thrift/compiler/ast/t_named.h>
#include <thrift/compiler/ast/t_type.h>
#include <thrift/compiler/sema/ast_validator.h>
#include <thrift/compiler/sema/diagnostic_context.h>

namespace apache::thrift::compiler {

/**
 * Transitive includes "work" in thrift C++, but they invite vexing
 * bugs if multiple transitive includes have the same module name. In other
 * langauges without transitive includes, they cause compilation errors (e.g.,
 * Rust). Thrift-python C API doesn't leak field types in headers, so transitive
 * includes cause confusing compilation errors re: template specialization not
 * found.
 *
 * This validator does not yet check any constants, e.g., as field default
 * values. Leaving this for a follow-on by a thrift language owner who would
 * benefit.
 */

void validate_explicit_include(
    diagnostic_context& ctx,
    const t_named& src,
    const t_type& type,
    diagnostic_level level);

void add_explicit_include_validators(
    ast_validator& validator,
    diagnostic_level level = diagnostic_level::warning);

} // namespace apache::thrift::compiler
