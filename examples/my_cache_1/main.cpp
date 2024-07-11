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
#include <regex>

#include "Reader/BinaryReader.h"
#include "Reader/ZstdReader.h"
#include "Simulator.h"


bool matchesFormat(const char *input_) {
    std::string str(input_);
    const std::string input = str;

    // Define the regex pattern
   std::regex pattern(R"(data/w(8[0-9]|9[0-9]|10[0-6])\.oracleGeneral\.bin\.zst)");

    // Check if the input matches the pattern
    return std::regex_match(input, pattern);
}


int main(int argc, char** argv) {
  folly::init(&argc, &argv);

  if (argc < 6){
    printf("Not enough args, %d\n",argc);
    int i = 0;
    while(i<argc){
       printf("arg[%d] is %s\n",i,argv[i]);
       i+=1;
    }
    printf("arg1: data_path; arg2: max_reqs; arg3: cache_size; arg4: reb; arg5: rebParams; arg6: sleep_sec\n");
    exit(1);
  }

  const char* data_path = argv[1];
  if (access(data_path, F_OK) == -1) {
    printf("Data file %s does not exist.\n", data_path);
    exit(1);
  }
  int max_reqs = std::atoi(argv[2]);
  char *cache_size = argv[3];
  char *rebalanceStrategy = argv[4];
  char *rebParams = argv[5];
  char *cacheStats_path = NULL;
  int sleep_sec = 0;
 if (argc >= 7) {
    cacheStats_path = argv[6]; 
    std::cout << "Saving cache stats to " << cacheStats_path << std::endl;
  }

  if (argc >= 7) {
    sleep_sec = std::atoi(argv[6]);
    std::cout << "Will sleep " << sleep_sec <<  " sec every 100000 requests" << std::endl;
  }

  int path_len = std::strlen(data_path);
  if ( (path_len>=3 && std::strcmp(data_path + path_len - 3, "bin") == 0) ||
   	(path_len>=13 && std::strcmp(data_path + path_len - 13, "oracleGeneral") == 0)
     ){
    bin_reader_t *reader = binary_reader_setup(data_path);
    simulate_binary(cache_size,rebalanceStrategy,rebParams,reader,max_reqs,sleep_sec,cacheStats_path);
  }
  else if (path_len >= 4 && std::strcmp(data_path + path_len - 3, "zst") == 0)
   {
    zstd_reader *reader =create_zstd_reader(data_path);
    simulate_zstd(cache_size,rebalanceStrategy,rebParams,reader,max_reqs,sleep_sec,cacheStats_path);
  }
 }
