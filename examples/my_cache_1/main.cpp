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


#include "Reader/BinaryReader.h"
#include "Reader/ZstdReader.h"
#include "Simulator.h"


int main(int argc, char** argv) { 
  if (argc < 6){
    printf("Not enough args, %d\n",argc);
    int i = 0;
    while(i<argc){
       printf("arg[%d] is %s\n",i,argv[i]);
       i+=1;
    }
    printf("arg1: data_path; arg2: max_reqs; arg3: cache_size; arg4: reb; arg5: rebParams; arg6: num_threads; arg7: ampF\n");
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

  int ampF = 0;
  char *cacheStats_path = nullptr;

  if (argc >= 7) {
    int num_threads = std::stoi(argv[6]);
    if (num_threads>=0){
    	zstd_reader *reader =create_zstd_reader(data_path);
    	std::cout << "Simulating multi-threaded cache with " << num_threads << " threads" << std::endl; 
    	simulate_zstd_con(cache_size,rebalanceStrategy,rebParams,reader,max_reqs,num_threads);
    	return 0;
     }
  }

  
  if (argc >= 8) {
    ampF = std::atoi(argv[7]);
    std::cout << "Amplication factor: " << ampF << std::endl;
  } 

  if (argc >= 9){
    cacheStats_path=argv[8];
    std::cout << "Saving cache stats to " << cacheStats_path;
  }

  int path_len = std::strlen(data_path);
  if ( (path_len>=3 && std::strcmp(data_path + path_len - 3, "bin") == 0) ||
   	(path_len>=13 && std::strcmp(data_path + path_len - 13, "oracleGeneral") == 0)
     ){
    bin_reader_t *reader = binary_reader_setup(data_path);
    simulate_binary(cache_size,rebalanceStrategy,rebParams,reader,max_reqs,ampF,cacheStats_path);
  }
  else if (path_len >= 4 && std::strcmp(data_path + path_len - 3, "zst") == 0)
   {
    zstd_reader *reader =create_zstd_reader(data_path);
    simulate_zstd(cache_size,rebalanceStrategy,rebParams,reader,max_reqs,ampF,cacheStats_path);
  }
 }
