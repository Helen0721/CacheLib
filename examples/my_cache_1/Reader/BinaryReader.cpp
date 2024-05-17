#include "/disk/CacheLib/examples/my_cache_1/Reader/BinaryReader.h"

#include "folly/init/Init.h"
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
  reader->offset = 0;
  reader->total_num_requests = (reader->file_size) / (reader->obj_size);  

  close(fd);
  return reader;
}

void read_one_binary_request(bin_reader_t *reader, bin_request* obj){
  char *start = (char *)reader->mapped_file + reader->offset * reader->obj_size;

  memcpy(&(obj->timestamp), start, sizeof(uint32_t));
  start += sizeof(uint32_t);
  memcpy(&(obj->obj_id), start, sizeof(uint64_t));
  start += sizeof(uint64_t);
  memcpy(&(obj->obj_size),start, sizeof(uint32_t));
  start += sizeof(uint32_t);
  memcpy(&(obj->next_access_vtime), start, sizeof(uint64_t));

  ++reader->offset;
  return;
}


void print_one_binary_request(bin_request *obj){
  std::cout<< "time:"<<obj->timestamp <<"obj_id:" << obj->obj_id <<",size:"<<obj->obj_size <<",nt:"<<obj->next_access_vtime<<std::endl;
}
