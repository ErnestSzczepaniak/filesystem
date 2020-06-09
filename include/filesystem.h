#ifndef _filesystem_h
#define _filesystem_h

#ifdef build_platform_host
#include <fstream>
typedef std::fstream File;
typedef bool Filesystem_result;
typedef int Filesystem;
#else
#include "ff.h"
typedef FIL File;
typedef FRESULT Filesystem_result;
typedef FATFS Filesystem;
#endif

Filesystem_result f_open(File * file, const char * path);
Filesystem_result f_close(File * file);
int f_read(File * file, void * buffer, int size);
int f_write(File * file, void * buffer, int size);
Filesystem_result f_seek(File * file, int offset);
int f_tell(File * file);
int f_size(File * file);
Filesystem_result f_mkdir(const char * path);
Filesystem_result f_rmdir(const char * path);
Filesystem_result f_mkfs(const char * path, void * buffer, int size);
Filesystem_result f_mount(Filesystem * filesystem, const char * path);

#endif