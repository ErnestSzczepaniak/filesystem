#ifndef _diskio_port_h
#define _diskio_port_h

#include "ff.h" //! ff przed diskio
#include "diskio.h"

DSTATUS RAM_disk_status();
DSTATUS RAM_disk_initialize();
DRESULT RAM_disk_read(unsigned char * buffer, int sector, int count);
DRESULT RAM_disk_write(const unsigned char * buffer, int sector, int count);
DRESULT RAM_disk_ioctl(unsigned char command, void * buffer);

DSTATUS MMC_disk_status();
DSTATUS MMC_disk_initialize();
DRESULT MMC_disk_read(unsigned char * buffer, int sector, int count);
DRESULT MMC_disk_write(const unsigned char * buffer, int sector, int count);
DRESULT MMC_disk_ioctl(unsigned char command, void * buffer);

DSTATUS USB_disk_status();
DSTATUS USB_disk_initialize();
DRESULT USB_disk_read(unsigned char * buffer, int sector, int count);
DRESULT USB_disk_write(const unsigned char * buffer, int sector, int count);
DRESULT USB_disk_ioctl(unsigned char command, void * buffer);

#endif