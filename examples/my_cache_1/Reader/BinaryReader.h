#ifndef BINARY_READER_H
#define BINARY_READER_H

#include <cstdlib>
#include <string.h>
#include <iostream>

struct bin_reader_t {
    const char *trace_path;
    size_t file_size;
    void* mapped_file;
    
    void* file_offset;
    uint32_t obj_size;
    uint64_t total_num_requests;
};

struct bin_request {
  uint32_t timestamp;
  uint64_t obj_id;
  uint32_t obj_size;
  int64_t next_access_vtime;  // -1 if no next access
};

bin_reader_t *binary_reader_setup(const char *trace_path);
void read_one_binary_request(bin_reader_t *reader, bin_request* obj);
void print_one_binary_request(bin_request *obj);
#endif
