#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

#include "xfi.h"



int main (int argc, char **argv)
{
    initialize();
    
    return 0;
}


void initialize()
{
    // Initial values for chip registers.
    Chips.mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft; 
    Chips.mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;

    module_id_line = TEN_INVALID_MODULE_ID;
    module_id_client = TEN_INVALID_MODULE_ID;       

    dev_id = 0; 



    // Driver loading.
    if (ten_drvr_load() != CS_OK) {
        printf("Error: could not load Cortina driver!\n");      
        //return (-1);
    }

    ten_drvr_ctl_stats_hex_format(1);

    // Device registration.
    if(ten_dev_register(dev_id,(cs_uint32)&Chips) != CS_OK) {
        printf("CS604x device registration failed!\n");
        return;
    }

    // This API is the main entry point to configure the device software.
    if (ten_dev_main_init(dev_id) != CS_OK) {
        printf("CS604x device initialization failed!\n");
        exit(EXIT_SUCCESS);
    }

    module_id_line = ten_mod_main_init(dev_id, TEN_MODULE_A);
    // Initialize one side of the chip, Module A.
    if (module_id_line == TEN_INVALID_MODULE_ID) {
        exit(EXIT_SUCCESS);
    }

    // Initialize the other side of the chip, Module B.
    module_id_client = ten_mod_main_init(dev_id, TEN_MODULE_B);
    if (module_id_client == TEN_INVALID_MODULE_ID) {
        exit(EXIT_SUCCESS);
    }

    // Config top level.
    print_status("Config Top level",
            ten_hl_config_global(
                dev_id,                     //Device ID 
                TEN_GLOBAL_MODE_S_40G,      //Line Mode
                TEN_GLOBAL_MODE_QUAD_10G,   //Client Mode
                0,                          //mbclksel
                1,                          //Multi-Rate Mode not SFI41 Line
                1                           //Multi-Rate Mode not SFI41 Client
                )
            );

    print_status("Initializes the both sides (module A and B) of OHPP for use,and additionally clears the shadow RAM",  
            ten_hl_ohpp_and_shadow_ram_init(dev_id)
            );

    print_status("Write the line and client rates to the appropriate slots of control block",
            ten_cb_rates( dev_id, 44723989430.0, 10709225320.0 )
            );

    /*ten_hl_fracdiv_config( dev_id, 0, 400000000, 349406167 );
      ten_hl_fracdiv_config( dev_id, 1, 400000000, 349406167 );
      ten_hl_fracdiv_config( dev_id, 2, 400000000, 349406167 );
      ten_hl_fracdiv_config( dev_id, 3, 400000000, 349406167 );*/

    print_status("Configures PDCAL block to use the reference specified by slice 0",
            ten_hl_cupll_calibrate_config_t41( dev_id,0));
    print_status("Configures PDCAL block to use the reference specified by slice 1",
            ten_hl_cupll_calibrate_config_t41( dev_id,1));
    print_status("Configures PDCAL block to use the reference specified by slice 2",
            ten_hl_cupll_calibrate_config_t41( dev_id,2));
    print_status("Configures PDCAL block to use the reference specified by slice 3",
            ten_hl_cupll_calibrate_config_t41( dev_id,3));

    print_status("Sets the fields for the XFI_CUPLL_PDCAL register slice 0",
            ten_xfi_cupll_pdcal_t41(module_id_client, 0, 0, 0x080 )
            );
    print_status("Sets the fields for the XFI_CUPLL_PDCAL register slice 1",
            ten_xfi_cupll_pdcal_t41(module_id_client, 1, 0, 0x080 )
            );
    print_status("Sets the fields for the XFI_CUPLL_PDCAL register slice 2",
            ten_xfi_cupll_pdcal_t41(module_id_client, 2, 0, 0x080 )
            );
    print_status("Sets the fields for the XFI_CUPLL_PDCAL registe slice 3r",
            ten_xfi_cupll_pdcal_t41(module_id_client, 3, 0, 0x080 )
            );

    print_status("Configures the line protocol for each slice. Line Module",
            ten_hsif_provision_datapath( module_id_line, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 )
            );
    print_status("Configures the line protocol for each slice. Client Module",
            ten_hsif_provision_datapath( module_id_client, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 )
            );

    print_status("",
            ten_hl_config_cfp_t41( module_id_line, TEN_SLICE_ALL, 6, TEN_HSIF_CFP_DIV_BY_64_REF, TEN_HSIF_CKREFDIV4, 0, 0, 0, 0, 1, 0x01, 0x2A, 0x1B, 0 ));
    print_status("",     
            ten_mpif_global_reset_n40g( dev_id, module_id_line, CS_RX, CS_RESET_DEASSERT ));
    print_status("",
            ten_mpif_global_clock_disable_n40g( dev_id,  module_id_line, CS_RX, CS_RESET_ASSERT ));
    print_status("",        
            ten_n40g_mldrx_mld_es_set_sreset_t41(  module_id_line, TEN_SLICE_ALL, 0 ));
    print_status("",        
            ten_n40g_mldrx_sadeco_release_sreset_t41( module_id_line));
    print_status("",
            ten_n40g_mldrx_sadeco_sdc_on_t41( module_id_line));
    print_status("",
            ten_n40g_rx_otl34_t41( module_id_line));
    print_status("",        
            ten_n40g_mldrx_sadeco_frame_word_length_t41( module_id_line, 0x0FF0 ));

    //XFI Configuration Pag 132
    print_status("Provides top-most level configuration of XFI, including waiting for lock.",
            ten_hl_config_xfi( module_id_client, 0, 5, 0,0, 400000000, 1, 0, 0, 1));
}

void print_status(const char* msg, cs_status status)
{
    if (status == CS_OK) {
        printf("%s : CS_OK\n", msg);
    } else {
        printf("%s : >>>> CS_ERROR\n", msg);
    }
}


