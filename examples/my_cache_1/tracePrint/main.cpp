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

  if ((path_len>=3 && std::strcmp(data_path + path_len - 3, "bin") == 0) ||
     (path_len>=13 && std::strcmp(data_path + path_len - 13, "oracleGeneral") == 0))
{
    	bin_reader_t *reader = binary_reader_setup(data_path);
	int num_reqs = 0;
	int num_zero_len_reqs = 0;
	
	std::cout << "parsed file size: " << reader->file_size << ", file start address: " << reader->mapped_file; 
	std::cout << ", parsed num reqs:" << reader->total_num_requests << std::endl;
	
	bin_request *req = (bin_request*) malloc(sizeof(bin_request));
	
	while((char *)reader->file_offset < (char *)reader->mapped_file + reader->file_size){
		read_one_binary_request(reader, req);
		num_reqs += 1;
				
		if (req->obj_size == 0) {
			num_zero_len_reqs += 1;
			continue;
		}

		print_one_binary_request(req);
			
				
		if (max_reqs!=0 && num_reqs > max_reqs) break;
		
	}
	std::cout <<"num_requests: "<< num_reqs << ", num zero reqs: "<<num_zero_len_reqs << std::endl;	
}
  
  else if (path_len >= 4 && std::strcmp(data_path + path_len - 3, "zst") == 0) {
	zstd_reader *reader =create_zstd_reader(data_path);
	int num_reqs = 0;
	int num_zero_len_reqs = 0;

	zstd_request *req = (zstd_request *)malloc(sizeof(zstd_request));
	char *record = (char *)malloc(1024 * 1024 * 16);
	
	while(true){
		size_t n = zstd_reader_read_bytes(reader, 24, &record);

		if (reader->status == MY_EOF) {std::cout<<"EOF"<<std::endl; break;}
	        if (reader->status == ERR) {std::cout<<"ERR."<<num_reqs<<std::endl;;break;}
		if (n==0) continue;
		
		req->clock_time = *(uint32_t *)record;
		req->obj_id = *(uint64_t *)(record + sizeof(uint32_t));
		req->obj_size = *(uint32_t *)(record + sizeof(uint32_t) + sizeof(uint64_t));
		req->next_access_vtime = *(int64_t *)(record + sizeof(uint32_t) + sizeof(uint64_t) + sizeof(uint32_t));


		if (req->obj_size == 0) {
			num_zero_len_reqs += 1;
			continue;
		}
		
		print_one_zstd_request(req)
		num_reqs += 1;
		if (max_reqs!=0 && num_reqs >= max_reqs) break;
	}
		std::cout <<"num_requests: "<< num_reqs << ", num zero reqs: "<<num_zero_len_reqs << std::endl;

   }
} 
