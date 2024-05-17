/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# *     http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "folly/init/Init.h"
#include <cstdlib>

#include <iostream>

#include "/disk/CacheLib/examples/my_cache_1/Reader/BinaryReader.h"
#include "/disk/CacheLib/examples/my_cache_1/Reader/ZstdReader.h"
#include "/disk/CacheLib/examples/my_cache_1/Simulator.h"

int main(int argc, char** argv) {
  folly::init(&argc, &argv);

  if (argc < 3){
    printf("Not enough args\n");
    exit(1);
  }

  const char* data_path = argv[1];
  if (access(data_path, F_OK) == -1) {
    printf("Data file %s does not exist.\n", data_path);
    exit(1);
  }
  int max_reqs = std::atoi(argv[2]);
  char *cache_size = argv[3];
  
  int path_len = std::strlen(data_path);
  if (path_len>=3 && std::strcmp(data_path + path_len - 3, "bin") == 0){
    bin_reader_t *reader = binary_reader_setup(data_path);
    simulate_binary(cache_size,reader,max_reqs);
  }
  else if (path_len >= 4 && std::strcmp(data_path + path_len - 3, "zst") == 0) {
    zstd_reader *reader =create_zstd_reader(data_path);
    simulate_zstd(cache_size,reader,max_reqs);
  }
}
