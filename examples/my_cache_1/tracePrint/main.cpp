#include <cstdlib>
#include <iostream>
#include <cstring>
#include "../Reader/BinaryReader.h"
#include "../Reader/ZstdReader.h"


int main(int argc, char** argv) {

  if (argc < 3){
    printf("Not enough args, %d\n",argc);
    int i = 0;
    while(i<argc){
       printf("arg[%d] is %s\n",i,argv[i]);
       i+=1;
    }
    printf("arg1: data_path; arg2: max_reqs\n");
    exit(1);
  }

  const char* data_path = argv[1];
  
  int max_reqs = std::atoi(argv[2]);
  
  int path_len = std::strlen(data_path);

  if ( (path_len>=3 && std::strcmp(data_path + path_len - 3, "bin") == 0) ||
   	(path_len>=13 && std::strcmp(data_path + path_len - 13, "oracleGeneral") == 0)
     ){
    	bin_reader_t *reader = binary_reader_setup(data_path);
	int num_reqs = 0;
	int num_hits = 0;
	
	bin_request *req = (bin_request*) malloc(sizeof(bin_request));        	

	while(reader->offset < reader->total_num_requests){
		read_one_binary_request(reader, req);
				
		if (req->obj_size == 0) continue;

		print_one_binary_request(req);
		num_reqs += 1;
		
		if (max_reqs!=0 && reader->offset > max_reqs) break;
		
	}
	std::cout <<"num_requests:"<< num_reqs << std::endl; 
    }
} 
