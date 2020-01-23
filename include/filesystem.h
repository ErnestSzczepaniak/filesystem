#ifndef _filesystem_h
#define _filesystem_h

#ifdef build_platform_host
#include <fstream>
typedef std::fstream File;
typedef bool Result;
typedef int Filesystem;
#else
#include "ff.h"
typedef FIL File;
typedef FRESULT Result;
typedef FATFS Filesystem;
#endif

Result f_open(File * file, const char * path);
Result f_close(File * file);
int f_read(File * file, void * buffer, int size);
int f_write(File * file, void * buffer, int size);
Result f_seek(File * file, int offset);
int f_tell(File * file);
int f_size(File * file);
Result f_mkdir(const char * path);
Result f_rmdir(const char * path);
Result f_mkfs(const char * path, void * buffer, int size);
Result f_mount(Filesystem * filesystem, const char * path);

#endif