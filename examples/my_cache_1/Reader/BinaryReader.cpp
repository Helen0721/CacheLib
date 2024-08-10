#include "BinaryReader.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <cstdlib>
#include <string.h>
#include <chrono>
#include <iostream>


bin_reader_t *binary_reader_setup(const char *trace_path) {
  int fd;
  struct stat st;

  if ((fd = open(trace_path, O_RDONLY)) < 0){
    std::cout << "fail to open trace " << trace_path << std::endl;
    exit(1);
  }

  if ((fstat(fd,&st))<0){
    close(fd);
    std::cout << "unable to fstat " << trace_path << std::endl;
    exit(1);
  }

  bin_reader_t *reader = (bin_reader_t *)malloc(sizeof(bin_reader_t));

  reader->trace_path = trace_path;
  reader->file_size = st.st_size;
  reader->mapped_file = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);

  if ((reader->mapped_file) == MAP_FAILED) {
      close(fd);
      reader->mapped_file = NULL;
      std::cout << "unable to malloc " << st.st_size << " bytes of memory " << trace_path <<std::endl;
      exit(1);
  
  }

  reader->obj_size = 24;
  reader->file_offset = reader->mapped_file;
  reader->total_num_requests = (reader->file_size) / (reader->obj_size);  

  close(fd);
  return reader;
}

void read_one_binary_request(bin_reader_t *reader, bin_request* obj){
  char *start = (char *)reader->file_offset;

  memcpy(&(obj->timestamp), start, sizeof(uint32_t));
  start += sizeof(uint32_t);
  memcpy(&(obj->obj_id), start, sizeof(uint64_t));
  start += sizeof(uint64_t);
  memcpy(&(obj->obj_size),start, sizeof(uint32_t));
  start += sizeof(uint32_t);
  memcpy(&(obj->next_access_vtime), start, sizeof(int64_t));
  if (obj->next_access_vtime == -1) obj->next_access_vtime = INT64_MAX;
  
  reader->file_offset = (void *) ((char *)reader->file_offset + reader->obj_size);
  return;
}


void print_one_binary_request(bin_request *obj){
  if (obj->next_access_vtime == -1) {
  	std::cout<<obj->timestamp<<","<<obj->obj_id<<"," <<obj->obj_size << ",9223372036854775807" <<std::endl;
  }
  else{
	printf("%u,%lu,%u,%ld\n",obj->timestamp,obj->obj_id,obj->obj_size,obj->next_access_vtime);
	//std::cout<<obj->timestamp<<","<<obj->obj_id<<"," <<obj->obj_size << ","<<obj->next_access_vtime <<std::endl;
  }
  }
