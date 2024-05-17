/*
 * Code taken from https://github.com/1a1a11a/libCacheSim
 */


#pragma once

#include <stdio.h>
#include <zstd.h>

//#ifdef __cplusplus
//extern "C" {

#ifndef ZSTD_READER_H
#define ZSTD_READER_H
#include <cstdlib>
#include <string.h>
#include <iostream>
typedef enum { ERR, OK, MY_EOF } rstatus;
//static char *rstatus_str[3] = {"ERR", "OK", "MY_EOF"};

struct zstd_reader {
  FILE *ifile;
  ZSTD_DStream *zds;

  size_t buff_in_sz;
  void *buff_in;
  size_t buff_out_sz;
  void *buff_out;

  size_t buff_out_read_pos;

  ZSTD_inBuffer input;
  ZSTD_outBuffer output;

  rstatus status;
} ;

struct zstd_request{
	uint32_t clock_time;
	uint64_t obj_id;
	uint32_t obj_size;
	int64_t next_access_vtime;
};



zstd_reader* create_zstd_reader(const char *trace_path);

void free_zstd_reader(zstd_reader *reader);

size_t zstd_reader_read_line(zstd_reader *reader, char **line_start,
                             char **line_end);

/* read n_byte from reader, decompress if needed, data_start points to the new
 * data */
size_t zstd_reader_read_bytes(zstd_reader *reader, size_t n_byte,
                              char **data_start);

void print_one_zstd_request(zstd_request *obj);



#endif

//#ifdef __cplusplus
//}
//#endif
