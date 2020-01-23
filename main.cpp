#ifdef build_platform_host

#define CATCH_CONFIG_MAIN
#include "build.h"
#include "test.h"

#else

#include "build.h"
#include "filesystem.h"
#include "hal.h"

unsigned char buffer[7007204];

int main()
{
    Filesystem filesystem;
    File file;

    auto res = f_mount(&filesystem, "1:");

    res = f_open(&file, "1:/output_file.rbf");

    auto size = f_read(&file, buffer, 7007204);

    h_fpga_bridge_init(3);

    h_fpga_configure(buffer, 7007204);

    while(1);
}

#endif
