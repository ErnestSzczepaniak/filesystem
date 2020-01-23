#include "filesystem.h"

Result f_open(File * file, const char * path)
{
#ifdef build_platform_host
    file->open(path, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    return file->good() ? true : false;
#else
    return fs_open(file, path, FA_READ | FA_WRITE);
#endif
}

Result f_close(File * file)
{
#ifdef build_platform_host
    file->close();
    return !file->is_open() ? true : false;
#else
    return fs_close(file);
#endif
}

int f_read(File * file, void * buffer, int size)
{
#ifdef build_platform_host

#else
    UINT read;
    fs_read(file, buffer, size, &read);
    return read;
#endif
}

int f_write(File * file, void * buffer, int size)
{
#ifdef build_platform_host

#else
    UINT write;
    fs_write(file, (const void *) buffer, size, &write);
    return write;
#endif
}

Result f_seek(File * file, int offset)
{
#ifdef build_platform_host

#else
    return fs_lseek(file, offset);
#endif
}

int f_tell(File * file)
{
#ifdef build_platform_host

#else
    return fs_tell(file);
#endif
}

int f_size(File * file)
{
#ifdef build_platform_host

#else
    return fs_size(file);
#endif
}

Result f_mkdir(const char * path)
{
#ifdef build_platform_host

#else
    return fs_mkdir(path);
#endif
}

Result f_rmdir(const char * path)
{
#ifdef build_platform_host

#else
    return fs_rmdir(path);
#endif
}

Result f_mkfs(const char * path, void * buffer, int size)
{
#ifdef build_platform_host

#else
    return fs_mkfs(path, FM_ANY, 512, buffer, size);
#endif
}

Result f_mount(Filesystem * filesystem, const char * path)
{
#ifdef build_platform_host

#else
    return fs_mount(filesystem, path, 1);
#endif
}
