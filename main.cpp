#ifdef build_platform_host

#define CATCH_CONFIG_MAIN
#include "build.h"
#include "test.h"

#else

#include "build.h"
#include "filesystem.h"
#include "hal.h"

// #define rbf_size 7007204
#define rbf_size 2159408

unsigned char buffer_sd[rbf_size];
unsigned char buffer_qspi[rbf_size];

int main()
{
    while(1);

    auto res_qspi = h_qspi_init();

    res_qspi = h_qspi_read(0x00940000, rbf_size, buffer_qspi);
    

    Filesystem filesystem;
    File file;

    auto res = f_mount(&filesystem, "1:");

    res = f_open(&file, "1:/output_file.rbf");

    auto size = f_read(&file, buffer_sd, rbf_size);


    auto res_cmp = memcmp(buffer_qspi, buffer_sd, rbf_size);

    auto res_config  = h_fpga_configure(buffer_qspi, rbf_size);

    auto res_init = h_fpga_init();

    // h_fpga_bridge_init(3);


    while(1);
}

#endif
