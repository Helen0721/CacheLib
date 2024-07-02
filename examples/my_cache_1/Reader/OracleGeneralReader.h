#ifndef ORACLEGENERAL_READER_H
#define ORACLEGENERAL_READER_H

#include <cstdlib>
#include <string.h>
#include <iostream>

struct oracleGeneral_reader_t {
    const char *trace_path;
    size_t file_size;
    void* mapped_file;
    
    uint32_t offset;
    uint32_t obj_size;
    uint64_t total_num_requests;
};

struct bin_request {
  uint32_t timestamp;
  uint64_t obj_id;
  uint32_t obj_size;
  int64_t next_access_vtime;  // -1 if no next access
};

