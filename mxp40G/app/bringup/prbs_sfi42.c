#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include "prbs_sfi42.h"
#include "../../lib/qsfp/qsfp.h"


int optics;
int port;
FILE *fp;


#define SILABS_SLAVE_ADDRESS 0x50
#define SILABS_BUS 0x50

int main (int argc, char **argv)
{
    optics=0;
    const char* const short_opt = "op:" ;
    int next_opt;
    const struct option long_opt[] =
    {
        { "optic", 0, NULL,'o'},
        { "port", 1, NULL,'p'},
        {  NULL,  0, NULL, 0 }
    };
    
   
    if (argc == 1) 
    {
        
    }
    
    while (1) 
    {
        
        next_opt = getopt_long (argc, argv, short_opt, long_opt, NULL);
        if (next_opt == -1) break;

        switch (next_opt) {
            
            case 'o': 
                    optics=1;
            break;
        
            case 'p': 
                    
                    port=atoi(optarg);
                    
                    switch(port) {
                    
                        case 0:
                            port =0;
                        break;
                        case 1:
                            port =1;
                        break;
                        case 2:
                            port =2;
                        break;
                        case 3:
                            port =3;
                        break;
                        default:
                            port =0xFF;
                        break;
                    
                    }
            break;
            
            case '?':
                
                    exit(1);
            break;
                    
            case -1:
                   
                    exit(1);
            break;
                    
            default:    
                    abort();
            break;
        }
    }
    
    if(port==0xFF) {
        printf("XFI %d Normal Operation: %d\n", 0, xfp_set_normal_operation(0));
        printf("XFI %d Normal Operation: %d\n", 1, xfp_set_normal_operation(1));
        printf("XFI %d Normal Operation: %d\n", 2, xfp_set_normal_operation(2));
        printf("XFI %d Normal Operation: %d\n", 3, xfp_set_normal_operation(3));
        
        if (optics) {
            printf("XFI %d Loopback: %d\n", 0, xfp_set_xfi_loopback(0));
            printf("XFI %d Loopback: %d\n", 1,xfp_set_xfi_loopback(1));
            printf("XFI %d Loopback: %d\n", 2,xfp_set_xfi_loopback(2));
            printf("XFI %d Loopback: %d\n", 3,xfp_set_xfi_loopback(3));
        }
        
    
    }
    else
    {
        printf("XFI %d Normal Operation: %d\n", port, xfp_set_normal_operation(port));
        
        if (optics) {
        printf("XFI %d Loopback: %d\n", port,xfp_set_xfi_loopback(port));
        }
    }
    
    
    
    initialize(port);
    
    return 0;
}



int initialize(int port)
{   
    
    /** 9.1 Hard Reset the Device */
    //RSTN pin to a logic low
    
    /** System Reference Clock and Internal Clock Frequencies */
    //SYS_REFCLK_IN Frequency = 400 MHz
    
    /** 9.3 Remove Hard Reset */
    //RSTN pin to a logic high
    
    /** 9.4 Initialize the Device Driver */
    // Driver loading.
    if (ten_drvr_load() != CS_OK) {
        printf("Error: could not load Cortina driver!\n");
        return -1;
    }

    ten_drvr_ctl_stats_hex_format(1);

    // Value initialization.
    Chips.mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft;
    Chips.mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;
    dev_id = 0;
    module_line = dev_id << 8;
    module_client = module_client | 1;

    // Device registration.
    if(ten_dev_register(dev_id,(cs_uint32)&Chips) != CS_OK) {
        printf("Error: CS604x device registration failed!\n");
        return -1;
    }

    // Initialize the device driver
    if (ten_dev_main_init(dev_id) != CS_OK) {
        printf("Error: CS604x device initialization failed!\n");
        return -1;
    }
    printf("Device Chip Id = %08X\n", ten_mpif_get_chip_jtag_id(dev_id));

    /* * * *
     * Scratch pad register = register for read/write tests.
     *  * * */
    print_status("FF - Scratchpad", ten_mpif_scratch_pad2(dev_id, 0xAA55));
    printf("Read scratchpad = %04X\n", ten_mpif_read_scratch_pad2(dev_id));

    module_client = ten_mod_main_init( dev_id, TEN_MODULE_B );
    module_line = ten_mod_main_init( dev_id, TEN_MODULE_A );
    
    /** 9.5 Global Configuration */
    ten_hl_config_global(
            dev_id,                     //Device ID
            TEN_GLOBAL_MODE_S_40G,      //Line Mode
            TEN_GLOBAL_MODE_QUAD_10G,   //Client Mode
            0,                          //mbclksel
            1,                          //Multi-Rate Mode not SFI41 Line
            1                           //Multi-Rate Mode not SFI41 Client
            );
    
    /** 9.6 Initialize OHPP and Shadow Ram */
    ten_hl_ohpp_and_shadow_ram_init(dev_id);
    
    //ten_hl_hsif_power_down_serdes(module_line);
    //ten_hl_hsif_power_down_serdes(module_client);
    
    print_status("FF - Override the default datapath state",
                 ten_hsif_provision_datapath(   module_line, 
                                                TEN_INSTANCE_ALL, 
                                                1, 
                                                1, 
                                                0, 
                                                0, 
                                                0, 
                                                0)
                                            );
   print_status("FF - Override the default datapath state",
                 ten_hsif_provision_datapath(   module_client, 
                                                port, //TEN_INSTANCE_ALL 
                                                1, 
                                                1, 
                                                0, 
                                                0, 
                                                0, 
                                                0)
                                            );
                                            
  /* print_status("FF - Config SFI 5.1",
            ten_hl_config_sfi51(module_line)
            );

    print_status("FF - Controls MR SERDES Powerdown", 
        ten_hl_hsif_powerdown_mr(   module_client,
                                    TEN_SLICE_ALL, 
                                    CS_ENABLE)
                                    );*/
                                    
   print_status("FF - Config XFI Interface",
            ten_hl_hsif_config_xfi (    module_client,
                                        port,//TEN_INSTANCE_ALL
                                        0,
                                        0,
                                        0)
                                    );

    print_status("FF - Override the Default Datapath State",
                 ten_hsif_provision_datapath(   module_client, 
                                                port, //TEN_INSTANCE_ALL
                                                1, 
                                                1, 
                                                0, 
                                                0, 
                                                0, 
                                                0)
                                            );

   print_status("FF - Config the N40G Block",
        ten_hl_n40g_config( module_line, 
                            TEN_N40G_RX_OTU3_ODTU23, 
                            TEN_N40G_TX_ODTU2_OTU3)
                            );

   print_status("FF - Config the N40G FEC",
        ten_hl_config_fec_t41(  module_line,
                                1,
                                0,
                                TEN_FEC_MODE_OTUkV)
                            );
     
   
   print_status("FF - Config PRBS generator",
        ten_hl_config_10g_hsif_kpga(    module_client,
                                        port,//TEN_INSTANCE_ALL
                                        TEN_HSIF_PROTOCOL_XFI,
                                        0,
                                        TEN_HSIF_PRBS_PN31)
                                    );
   //ten_mod_print_blk_stats(module_client,TEN_ID_PP10G);
   
   
   
   while(1)
   {
       fp = fopen ( "/var/log/rsyslog/ber_xfi.txt", "a" );        
	if (fp==NULL) {
        fputs ("File error",stderr); exit (1);
    }
    
       if (port == 0xFF) {
           fprintf(fp, "PRBS CHK 0: %d\n" ,ten_xfi32x1_prbschk_get_status(module_client,0));
           fprintf(fp, "PRBS CHK 1: %d\n" ,ten_xfi32x1_prbschk_get_status(module_client,1));
           fprintf(fp, "PRBS CHK 2: %d\n" ,ten_xfi32x1_prbschk_get_status(module_client,2));
           fprintf(fp, "PRBS CHK 3: %d\n" ,ten_xfi32x1_prbschk_get_status(module_client,3));
           //printf("PRBS CHK 0: %d\n",ten_xfi32x1_prbschk_get_status(module_client,0));
           //printf("PRBS CHK 1: %d\n",ten_xfi32x1_prbschk_get_status(module_client,1));
           //printf("PRBS CHK 2: %d\n",ten_xfi32x1_prbschk_get_status(module_client,2));
           //printf("PRBS CHK 3: %d\n",ten_xfi32x1_prbschk_get_status(module_client,3));
       }
       else {
            fprintf(fp, "PRBS CHK %d: %d\n" ,port, ten_xfi32x1_prbschk_get_status(module_client,port));
       }
       sleep(1);
       //ten_xfi32x1_prbsgen_control(module_client,0xFF,1,0,0,0);
        fclose ( fp );
   }
   
   
    return 0;

}
