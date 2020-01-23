#include "diskio_port.h"
#include "string.h"

//---------------------------------------------| RAM |---------------------------------------------//

unsigned char memory[4096][512];

DWORD get_fattime()
{
    return 0;
}

DSTATUS RAM_disk_status()
{
    return RES_OK;
}

DSTATUS RAM_disk_initialize()
{
    return RES_OK;
}

DRESULT RAM_disk_read(unsigned char * buffer, int sector, int count)
{
    for (int i = 0; i < count; i++)
    {
        memcpy(buffer, &memory[sector + i][0], 512);
        buffer += 512;       
    }

    return RES_OK;
}

DRESULT RAM_disk_write(const unsigned char * buffer, int sector, int count)
{
    for (int i = 0; i < count; i++)
    {
        memcpy(&memory[sector + i][0], buffer, 512);
        buffer += 512;
    }

    return RES_OK;
}

DRESULT RAM_disk_ioctl(unsigned char command, void * buffer)
{
    switch (command)
    {
        case CTRL_SYNC:
            break;
        case GET_SECTOR_COUNT:
            *((unsigned int *) buffer) = 4096;
            break;
        case GET_SECTOR_SIZE:
            *((unsigned int *) buffer) = 512;
        case GET_BLOCK_SIZE:
            *((unsigned int *) buffer) = 64;
            break;
        case CTRL_TRIM:
            break;
        default:
            break;
    }

    return RES_OK;
}

//---------------------------------------------| MMC |---------------------------------------------//

#include "hal.h"

DSTATUS MMC_disk_status()
{
    return RES_OK;
}

DSTATUS MMC_disk_initialize()
{
    h_sd_init();

    return RES_OK;
}

DRESULT MMC_disk_read(unsigned char * buffer, int sector, int count)
{
    h_sd_read(sector * 512, buffer, count * 512);

    return RES_OK;
}

DRESULT MMC_disk_write(const unsigned char * buffer, int sector, int count)
{
    h_sd_write(sector * 512, (void *) buffer, count * 512);

    return RES_OK;
}

DRESULT MMC_disk_ioctl(unsigned char command, void * buffer)  // TODO: poprawic bo jest na sztywno 
{
    switch (command)
    {
        case CTRL_SYNC:
            break;
        case GET_SECTOR_COUNT:
            *((unsigned int *) buffer) = 15366144;
            break;
        case GET_SECTOR_SIZE:
            *((unsigned int *) buffer) = 512;
        case GET_BLOCK_SIZE:
            *((unsigned int *) buffer) = 1;
            break;
        case CTRL_TRIM:
            break;
        default:
            break;
    }

    return RES_OK;
}

//---------------------------------------------| usb |---------------------------------------------//

DSTATUS USB_disk_status()
{
    return RES_OK;
}

DSTATUS USB_disk_initialize()
{
    return RES_OK;
}

DRESULT USB_disk_read(unsigned char * buffer, int sector, int count)
{
    return RES_OK;
}

DRESULT USB_disk_write(const unsigned char * buffer, int sector, int count)
{
    return RES_OK;
}

DRESULT USB_disk_ioctl(unsigned char command, void * buffer)
{
    return RES_OK;
}
