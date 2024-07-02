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

#include <gtest/gtest.h>
#include <thrift/lib/cpp2/server/IOUringUtil.h>

using namespace ::testing;
using namespace apache::thrift;

TEST(IOUringUtilTest, test_default_io_uring_executor) {
  auto threadPool = io_uring_util::getDefaultIOUringExecutor();
  EXPECT_TRUE(io_uring_util::validateExecutorSupportsIOUring(threadPool));
}
