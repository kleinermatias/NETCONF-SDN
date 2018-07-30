#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

#include "loopback.h"


int main (int argc, char **argv)
{

    initialize();
    
    return 0;
}



int initialize()
{
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
    module_id_line = dev_id << 8;
    module_id_client = module_id_client | 1;

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

    module_id_client = ten_mod_main_init( dev_id, TEN_MODULE_A );
    module_id_line = ten_mod_main_init( dev_id, TEN_MODULE_B );

    ten_hl_config_global( dev_id, 0, 1, 0, 1, 1 );
    ten_hl_ohpp_and_shadow_ram_init(dev_id);

    // Config top level.
    ten_hl_config_global(
            dev_id,                     //Device ID
            TEN_GLOBAL_MODE_S_40G,      //Line Mode
            TEN_GLOBAL_MODE_QUAD_10G,   //Client Mode
            0,                          //mbclksel
            1,                          //Multi-Rate Mode not SFI41 Line
            1                           //Multi-Rate Mode not SFI41 Client
            );

    // -- Parameters -- ten_hsif_provision_datapath --
    // module_id: line or client
    // instance: specified as 0-3 | TEN_INSTANCE_ALL
    // tx_xfiselect: 
    //      1: XFI
    //      0: protocol selected by rx_mrprotocol (default)
    // rx_xfiselect: 
    //      1: XFI
    //      0: protocol selected by rx_mrprotocol (default)
    // tx_pswtchen: 
    //      1: disable
    //      0: enable (data is driven from remote interface)
    // tx_mrprotocol: 
    //      XAUI
    //      SFI4.2 (40G)
    //      SFI4.2 (10G)
    //      SFI4.1
    //      SFI5 (default)
    //      disabled
    // rx_pswtchen: 
    //      1: disable
    //      0: enable (data is driven from remote interface)
    // rx_mrprotocol: 
    //      XAUI
    //      SFI4.2 (40G)
    //      SFI4.2 (10G)
    //      SFI4.1
    //      SFI5 (default)
    //      disabled   
    print_status("FF - Override the default datapath state",
                 ten_hsif_provision_datapath(
                    module_id_line, TEN_INSTANCE_ALL, 1, 1, 0, 0, 0, 0));
   
    print_status("FF - Override the Default Datapath State",
                 ten_hsif_provision_datapath(
                    module_id_client, TEN_INSTANCE_ALL, 1, 1, 0, 0, 0, 0));
    // rx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled

    // -- Parameters -- ten_hl_hsif_powerdown_mr --
    // module_id
    // slice
    // ctl
    print_status("FF - Controls MR SERDES Powerdown", ten_hl_hsif_powerdown_mr( module_id_client,TEN_SLICE_ALL, CS_ENABLE));

    // -- Parameters -- ten_hl_n40g_config --
    // module_id: 
    //      module_id_a
    //      module_id_b
    // mode_rx: 
    //      (table, row) = (9, 2) -> TEN_N40G_RX_OTU3_ODTU23 (=7)
    // mode_tx: 
    //      (table, row) = (10, 2) -> TEN_N40G_TX_ODTU2_OTU3 (=11)
    print_status("FF - Config the N40G Block",ten_hl_n40g_config(module_id_line, TEN_N40G_RX_OTU3_ODTU23, TEN_N40G_TX_ODTU2_OTU3));

    //Serial Tx to Rx Loopback x 4
   //ten_hl_hsif_control_loopback(module_id_client,0xFF,TEN_HSIF_LOOPBACK_XFI_SERIAL_TX2RX,CS_ENABLE);
    
        //Parallel Tx to Rx Loopback x 4
       // ten_hl_hsif_control_loopback(module_id_client,0xFF,TEN_HSIF_LOOPBACK_XFI_RX2TX,CS_ENABLE);
    
        //Facility Loopback x 4
        //ten_hl_hsif_control_loopback(module_id_client,0xFF,TEN_HSIF_LOOPBACK_FACILITY_XFI,CS_ENABLE);
        
        //Far End Loopback x 4
       // ten_hl_hsif_control_loopback(module_id_line,0xFF,TEN_HSIF_LOOPBACK_FAR_END,CS_ENABLE);
    
   ten_hl_hsif_control_loopback(module_id_line,0xFF,TEN_HSIF_LOOPBACK_FAR_END,CS_ENABLE);
   
   ten_xfi32x1_prbsgen_config(module_id_client,0xFF,1,1,1,1);
   
   while(1)
   {
       printf("%d\n",ten_xfi32x1_prbschk_get_status(module_id_client,0));
       printf("%d\n",ten_xfi32x1_prbschk_get_status(module_id_client,1));
       printf("%d\n",ten_xfi32x1_prbschk_get_status(module_id_client,2));
       printf("%d\n",ten_xfi32x1_prbschk_get_status(module_id_client,3));
       sleep(1);
       ten_xfi32x1_prbsgen_control(module_id_client,0xff,1,0,0,0);
   }
    return 0;

}

void print_status(const char *msg, cs_status status)
{
    if (status == CS_OK) {
        printf("%s : OK\n", msg);
    } else {
        printf("%s : ERROR\n", msg);
    }
}

void print_defects(const char* msg, cs_status status)
{
    if (status == CS_OK) {
        printf("%s 0\n", msg);
    } else {
        printf("%s 1\n", msg);
    }
}


void eth10g (
    cs_uint16 dev_id,
    cs_uint8  slice_line,
    cs_uint8  slice_client,
    cs_uint16 sysrefclk,        /* freq in MHz */
    cs_uint8  dyn_repro,        /* 0 = static, 1 = DR client only, 2 = DR line and client */
    cs_uint8  auxclk,           /* 0 = don't use auxclk, 1 = use auxclk */
    cs_uint8  xfi_clk_dist )    /* 0 = internal fan-out clock distribution, 1 otherwise */
{
    cs_uint16 module;
    cs_uint32 sysclk_freq;
    cs_uint8  mbclksel;
    cs_uint8  provision_line;
    cs_uint8  provision_client;
    cs_uint8  slice;
    cs_uint8  dir;
    cs_uint8  inv;
    cs_uint16 fracdiv_module;
    cs_uint8  fracdiv_slice;
    cs_uint8  inst;
    cs_uint16 silab_mod_line;
    cs_uint16 silab_mod_client;
    cs_uint16 silab_module;
    cs_uint8  silab_slice;
    cs_uint8  gpllx1_inst_line;
    cs_uint8  gpllx1_inst_client;
    cs_uint32 rdiv_divider;
    cs_uint16 tmp_mod_line;
    cs_uint16 tmp_mod_client;
    cs_uint16 ar_mod;
    cs_uint16 ar_slice;
    cs_uint32 clk_rate;
    cs_uint16 mod_hsif;
    cs_uint8  slice_hsif;
    cs_uint8  clock_ch;
    cs_uint8  clock_card;
    cs_uint8  side;
    cs_uint8  mr_optical_module_type;
    int       i;

    cs_uint16 mod_a = dev_id << 8;
    cs_uint16 mod_b = mod_a | 1;

    /* Default KPGA patterns that can be changed or turned into a parameter */
    cs_uint16 hsif_kpga = TEN_HSIF_PRBS_PN31;
    cs_uint16 kpga = TEN_KPG_PN31;

    cs_uint16 mod_line = ( dev_id << 8 ) | 0;
    cs_uint16 mod_client = ( dev_id << 8 ) | 1;
    sysclk_freq = sysrefclk * 1000000;

    provision_line   = dyn_repro != 1;
    provision_client = 1;

    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {

        /*  Hard-reset the CS604x device and set the sysrefclk */
        //tb_init(sysclk_freq, &mbclksel);
        ten_dev_register(dev_id, (cs_uint32) &Chips);
        /*  Initialize the device driver */
        if (ten_dev_main_init(dev_id) != CS_OK) {
            printf("CS604x device initialization failed; provisioning aborted\n");
            return;
        }

        mod_a = ten_mod_main_init( dev_id, TEN_MODULE_A );
        mod_b = ten_mod_main_init( dev_id, TEN_MODULE_B );

        /*  ten_drvr_ctl_logging(1); */

        /*  Reset the EVB */
        //tb_reset(sysclk_freq);
        ten_hl_config_global( dev_id, 0, 1, mbclksel, 1, 1 );
        ten_hl_ohpp_and_shadow_ram_init(dev_id);
        ten_hl_hsif_power_down_serdes(mod_a);
        ten_hl_hsif_power_down_serdes(mod_b);
    } else {
        if (provision_client) {
            ten_mpif_clock_select_gpll_in( dev_id, mod_client & 1, slice_client, CS_TX, 1 );
        }
        if (provision_line) {
            ten_mpif_clock_select_gpll_in( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 1 );
        }
    }
    /* This will enable logging
       ten_drvr_ctl_logging (CS_ENABLE);
     */
    sysclk_freq        = sysclk_freq > 200000000 ? sysclk_freq : sysclk_freq * 4;
    gpllx1_inst_line   = 1;
    gpllx1_inst_client = 9;
    
    /*
       if (t100) {
       if ( board_type == 11 ) {
       t40fpga_write_reg( 432, 0x4802, 0x0020 );
       }
       else if ( board_type == 8 ) {
       t40fpga_crosspoint( 432, 0, 2, 3 );
       }
       }
     */

    slice = 1 ? slice_client : slice_line;
    ten_cb_rates( dev_id, 43018413560.0, 10312500000.0 );
    
    if (provision_line) {
        fracdiv_module = mod_line;
        fracdiv_slice  = slice_line;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice : fracdiv_slice + 4;
        ten_hl_fracdiv_config( dev_id, 0, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 1, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 2, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 3, sysclk_freq, 336081355 );
    }
    
    if (provision_client) {
        fracdiv_module = mod_line;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice + 8 : fracdiv_slice + 12;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 10070800 );
        ten_mpif_set_clock_switch_force( dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE );
    }
    
    if (provision_client) {
        fracdiv_module = mod_client;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice : fracdiv_slice + 4;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 322265625 );
        fracdiv_module = mod_client;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice + 8 : fracdiv_slice + 12;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 10070800 );
        ten_mpif_set_clock_switch_force( dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE );
    }
    
    ten_mpif_global_reset_sds_xfi_mpif( dev_id, slice_client, CS_RESET_TOGGLE );
    silab_mod_client   = mod_client;
    silab_mod_line     = mod_line;
    cs_uint8 silab_slice_line   = slice_line;
    cs_uint8 silab_slice_client = slice_client;

    if ( dyn_repro != 1 ) {
        silab_module = silab_mod_line;
        silab_slice  = silab_slice_line;
    }

    silab_module = silab_mod_client;
    silab_slice  = silab_slice_client;

    /*  Clocks on the different Cortina EVBs are programmed differently. */
    /*  This code will check the board type and program the SiLabs appropriately. */

    //tb_ical( silab_module, silab_slice );
    TEN_MDELAY(5000);
    ten_set_cb_cupll_calc_t41( dev_id, 10312500000.0, 1, 64, 400000000, 800 );
    ten_hl_cupll_config_t41( mod_client, slice_client );
    
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_hl_cupll_calibrate_config_t41( dev_id, slice_client );
    }
    ten_xfi_cupll_pdcal_t41( mod_client, slice_client, 0, 0x080 );
    
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_hsif_provision_datapath( mod_a, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 );
        ten_hsif_provision_datapath( mod_b, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 );
    }

    if (provision_line) {
        tmp_mod_line = mod_line;
        ten_hsif_set_clk_40g( tmp_mod_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1 );
        ten_hsif_set_clk_40g( tmp_mod_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1 );
    }
    
    
    /*  This is to invert the SERDES lanes for the Cortina EVB; change as necessary. #1 */

    //  dir = evb_xfi{xfi_board_type}[slice_line][0];
    //inv = evb_xfi{xfi_board_type}[slice_line][1];
    if (provision_line) {
        mod_hsif               = mod_line;
        slice_hsif             = slice_line;
        //mr_optical_module_type = t40fpga_msa_detect( 432, mod_hsif & 1 );

        if (
                ( mr_optical_module_type == 0 ) ||  /*  msa_loopback = 0 */
                ( mr_optical_module_type == 1 ) ||  /*  msa_bridge = 1 */
                ( mr_optical_module_type == 2 ) ||  /*  msa_breakout = 2 */
                ( mr_optical_module_type == 4 ) ||  /*  msa_sfi41_loopback = 4 */
                ( mr_optical_module_type == 10 ) || /*  msa_fpga_loopback = 10 */
                ( mr_optical_module_type == 12 ) || /*  msa_none = 12 */
                ( mr_optical_module_type == 0xFF )  /*  msa_error = 0xFF */
           ) {                                           
            /*  Optical module is not present, so there will be no loss of signal indication */
            /*  10G lane OK status signal will NOT take external LOS into consideration. */
            ten_hsif_set_ok_ctrl( mod_hsif, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );

        } else {

            /*  This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been */
            /*  changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin, */
            /*  generated by the FPGA which in turn gets a signal from the optical module. It causes */
            /*  the dewrapper to disable justifications and N10G to go in and out of frame. */
            /*  This needs to be fixed in the FPGA */
            ten_glb_misc_xlos_inv_mr( mod_hsif, slice_hsif, 1 );
        }

        ten_hl_config_sfi51(mod_hsif);

        /*  Reset the optical module */
        //dev_reg_write( 432, 0, 20480, 0x80a );
        TEN_MDELAY(2000);
        //dev_reg_write( 432, 0, 20480, 0x803 );

    }

    if (provision_client) {

        /*  This is to invert the SERDES lanes for the Cortina EVB; change as necessary. #4 */
        // dir                    = evb_xfi{xfi_board_type}[slice_client][0];
        // inv                    = evb_xfi{xfi_board_type}[slice_client][1];
        mod_hsif               = mod_client;
        slice_hsif             = slice_client;
        // mr_optical_module_type = t40fpga_msa_detect( 432, mod_hsif & 1 );

        if (
                ( mr_optical_module_type == 0 ) ||  /*  msa_loopback = 0 */
                ( mr_optical_module_type == 1 ) ||  /*  msa_bridge = 1 */
                ( mr_optical_module_type == 2 ) ||  /*  msa_breakout = 2 */
                ( mr_optical_module_type == 4 ) ||  /*  msa_sfi41_loopback = 4 */
                ( mr_optical_module_type == 10 ) || /*  msa_fpga_loopback = 10 */
                ( mr_optical_module_type == 12 ) || /*  msa_none = 12 */
                ( mr_optical_module_type == 0xFF )  /*  msa_error = 0xFF */
           ) {                                           
            /*  Optical module is not present, so there will be no loss of signal indication */
            /*  10G lane OK status signal will NOT take external LOS into consideration. */
            ten_hsif_set_ok_ctrl( mod_hsif, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );

        } else {

            /*  This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been */
            /*  changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin, */
            /*  generated by the FPGA which in turn gets a signal from the optical module. It causes */
            /*  the dewrapper to disable justifications and N10G to go in and out of frame. */
            /*  This needs to be fixed in the FPGA */
            ten_glb_misc_xlos_inv_mr( mod_hsif, slice_hsif, 1 );
        }

        ten_hl_config_xfi_t41( mod_hsif, slice_hsif, 12, dir, inv, sysclk_freq, 1, 0, auxclk, 1, TEN_HSIF_XFI_DIV_BY_64_REF, xfi_clk_dist, 0, 0 );
    }

    ten_syncdsync_thread_set_cb_transcode( dev_id, slice_client, 1, 1 );
    
    if ( !ten_dev_is_t41(dev_id) ) {
        ten_syncdsync_thread_set_cb_40g_muxponder( dev_id, slice_client, 0, 1, 0, 2, 255, 236, 65535, 65535 );
    } else {
        ten_syncdsync_set_cb_40g_muxponder_t41( dev_id, slice_client, 0, 1, 0, 2, 255, 236, 65535, 65535, 10312500000, 10037273920, 43018413560 );
    }

    if ( !ten_dev_is_t41(dev_id) ) {
        ten_hl_syncdsync_threadsafe_datapath_config( mod_line, slice, mod_client, slice_client, 1, 0, 3, 64, 13, 16 );
    } else {
        ten_hl_syncdsync_datapath_config_t41( mod_line, slice, mod_client, slice_client, 13, 16, 1, 3, 64, 0, 1, 4 );
    }

    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_mpif_global_clock_disable_common( dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON );
        ten_mpif_global_reset_common( dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON );
        ten_mpif_global_reset_common( dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS );
    }

    ten_hl_config_10ge_otu3v_t41( mod_line, slice, slice_client, dyn_repro, 1, 13, 12, sysrefclk, 0, 0, 0, 1, 4, TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4, 2 );
    ten_n40g_gblr4x_set_kpasel( mod_line, 1 );

    /*  Set the unused channels to 'idle' */
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 0 ) ) {
        for ( i = 0 ; i < 4 ; i++ ) {
            if ( i != slice_client ) {
                ten_hl_config_aggregation_idle( mod_line, i, mod_client, i );
            }
        }
    }

    if (provision_line) {
        ten_hsif_set_ok_ctrl( mod_line, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );
    }

    if (provision_client) {
        ten_hsif_set_ok_ctrl( mod_client, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );
    }

    /*  The following clockmux code is written for CS604x only in order to simplify it */
    if (provision_client) {
        ten_hl_xfi_config_clockmux_t41( mod_client, slice_client, auxclk, 64, 1, 1 );
        ten_mpif_clock_select_gpll_in( dev_id, mod_client & 1, slice_client, CS_TX, 0 );    /*  Bugzilla 30856 */
        ten_hl_gpllx1_waitfor_gpll_lock( dev_id, gpllx1_inst_client + slice_client );
    }

    /*  The following clockmux code is written for CS604x only in order to simplify it */
    if (provision_line) {
        ten_hl_mr_40g_config_clockmux(mod_line);
        ten_mpif_clock_select_gpll_in( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 0x0 );
        ten_hl_gpllx1_waitfor_gpll_lock_40g( dev_id, gpllx1_inst_line );
    }
    gpllx1_inst_client = ( mod_client & 1 ) == TEN_MODULE_A ? 1 : 9;
    ten_hl_gpllx1_waitfor_gpll_lock( dev_id, gpllx1_inst_client + slice_client );
    
    if (provision_line) {
        ten_n40g_set_global_resets( mod_a, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL );
        ten_n40g_set_global_resets( mod_b, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL );
    }
    ten_hl_config_remove_soft_resets( mod_line, slice_line, mod_client, slice_client, 12, 1 );
    
    if (provision_line) {
        ten_mpif_global_reset_hsif( dev_id, mod_line & 1, CS_TX_AND_RX, CS_RESET_DEASSERT );
        ten_mpif_set_clock_switch_force( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_RX, CS_DISABLE );
        ten_mpif_set_clock_switch_force( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, CS_DISABLE );
    }
    
    if (provision_client) {
        ten_mpif_global_reset_hsif( dev_id, mod_client & 1, CS_TX_AND_RX, CS_RESET_DEASSERT );
        ten_mpif_set_clock_switch_force( dev_id, mod_client,        slice_client, CS_RX, CS_DISABLE );
        ten_mpif_set_clock_switch_force( dev_id, TEN_MODULE_A_AND_B, slice_client, CS_TX, CS_DISABLE );
    }
    ten_hl_syncdsync_reset( mod_client, slice_client );
    ten_syncdsynctx_set_configuration_init_force( mod_client, slice_client, CS_RESET_TOGGLE );
    
    if (provision_line) {
        ten_hl_syncdsync_reset( mod_line, slice );
        ten_syncdsynctx_set_configuration_init_force( mod_line, slice, CS_RESET_TOGGLE );
    }
    ten_cupll_reset_t41( mod_client, slice_client, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE );
    ten_mpif_cupll_settle_force_t41( dev_id, slice_client, 2, CS_ENABLE );
    ten_mpif_cupll_settle_force_t41( dev_id, slice_client, 2, CS_DISABLE );
}

int otu2_gfec_transparent_bmp_amp_xfi_b_ccupll_400_otu3_gfec_sfi5_1_a_k_64(
    cs_uint16 dev_id,
    cs_uint8  slice_line,
    cs_uint8  slice_client,
    cs_uint16 sysrefclk,        /* freq in MHz */
    cs_uint8  dyn_repro,        /* 0 = static, 1 = DR client only, 2 = DR line and client */
    cs_uint8  auxclk,           /* 0 = don't use auxclk, 1 = use auxclk */
    cs_uint8  xfi_clk_dist )    /* 0 = internal fan-out clock distribution, 1 otherwise */
{
    cs_uint16 module;
    cs_uint32 sysclk_freq;
    cs_uint8  mbclksel;
    cs_uint8  provision_line;
    cs_uint8  provision_client;
    cs_uint8  slice;
    cs_uint8  dir;
    cs_uint8  inv;
    cs_uint16 fracdiv_module;
    cs_uint8  fracdiv_slice;
    cs_uint8  inst;
    cs_uint16 silab_mod_line;
    cs_uint16 silab_mod_client;
    cs_uint16 silab_module;
    cs_uint8  silab_slice;
    cs_uint8  gpllx1_inst_line;
    cs_uint8  gpllx1_inst_client;
    cs_uint32 rdiv_divider;
    cs_uint16 tmp_mod_line;
    cs_uint16 tmp_mod_client;
    cs_uint16 ar_mod;
    cs_uint16 ar_slice;
    cs_uint32 clk_rate;
    cs_uint16 mod_hsif;
    cs_uint8  slice_hsif;
    cs_uint8  clock_ch;
    cs_uint8  clock_card;
    cs_uint8  side;
    cs_uint8  mr_optical_module_type;
    int       i, t100, board_type;


    t100 = board_type = 0;
    cs_uint16 mod_a = dev_id << 8;
    cs_uint16 mod_b = mod_a | 1;

    // Default KPGA patterns that can be changed or turned into a parameter
    cs_uint16 hsif_kpga = TEN_HSIF_PRBS_PN31;
    cs_uint16 kpga = TEN_KPG_PN31;

    cs_uint16 mod_line = ( dev_id << 8 ) | 0;
    cs_uint16 mod_client = ( dev_id << 8 ) | 1;
    sysclk_freq = sysrefclk * 1000000;

    provision_line   = dyn_repro != 1;
    provision_client = 1;

    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_dev_register(dev_id, (cs_uint32)&Chips);

        // Initialize the device driver
        if (ten_dev_main_init(dev_id) != CS_OK) {
            printf("Error: CS604x device initialization failed!\n");
            return -1;
        }

        mod_a = ten_mod_main_init( dev_id, TEN_MODULE_A );
        mod_b = ten_mod_main_init( dev_id, TEN_MODULE_B );

        ten_hl_config_global( dev_id, 0, 1, mbclksel, 1, 1 );
        ten_hl_ohpp_and_shadow_ram_init(dev_id);
        ten_hl_hsif_power_down_serdes(mod_a);
        ten_hl_hsif_power_down_serdes(mod_b);
    } else {
        if (provision_client) {
            ten_mpif_clock_select_gpll_in( dev_id, mod_client & 1, slice_client, CS_TX, 1 );
        }
        if (provision_line) {
            ten_mpif_clock_select_gpll_in( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 1 );
        }
    }
    
    sysclk_freq        = sysclk_freq > 200000000 ? sysclk_freq : sysclk_freq * 4;
    gpllx1_inst_line   = 1;
    gpllx1_inst_client = 9;
    
    slice = 1 ? slice_client : slice_line;
    if (provision_line) {
        fracdiv_module = mod_line;
        fracdiv_slice  = slice_line;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice : fracdiv_slice + 4;
        ten_hl_fracdiv_config( dev_id, 0, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 1, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 2, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 3, sysclk_freq, 336081355 );
    }

    if (provision_client) {
        fracdiv_module = mod_line;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice + 8 : fracdiv_slice + 12;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 9802025 );
        ten_mpif_set_clock_switch_force( dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE );
    }

    if (provision_client) {
        fracdiv_module = mod_client;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice : fracdiv_slice + 4;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 334663291 );
        fracdiv_module = mod_client;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice + 8 : fracdiv_slice + 12;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 10458227 );
        ten_mpif_set_clock_switch_force( dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE );
    }

    ten_mpif_global_reset_sds_xfi_mpif( dev_id, slice_client, CS_RESET_TOGGLE );
    silab_mod_client   = mod_client;
    silab_mod_line     = mod_line;
    cs_uint8 silab_slice_line   = slice_line;
    cs_uint8 silab_slice_client = slice_client;

    if ( dyn_repro != 1 ) {
        silab_module = silab_mod_line;
        silab_slice  = silab_slice_line;

        ten_mpif_rxdiv_cfg0_mode_t41( dev_id, ( silab_module * 4 + silab_slice ), 0 );
        TEN_MDELAY(5000);
    
        silab_module = silab_mod_client;
        silab_slice  = silab_slice_client;
    }

    /*  Clocks on the different Cortina EVBs are programmed differently. */
    /*  This code will check the board type and program the SiLabs appropriately. */
    if ( !(( board_type == 8 ) && ( silab_module == 1 ) && ( 5 != 5 )) ) {
        ten_mpif_rxdiv_cfg0_mode_t41( dev_id, ( silab_module * 4 + silab_slice ), 0 );
    }
    
    TEN_MDELAY(5000);
    ten_set_cb_cupll_calc_t41( dev_id, 10709225320.0, 1, 64, 400000000, 800 );
    ten_hl_cupll_config_t41( mod_client, slice_client );
    
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_hl_cupll_calibrate_config_t41( dev_id, slice_client );
    }
    
    ten_xfi_cupll_pdcal_t41( mod_client, slice_client, 0, 0x080 );
    
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_hsif_provision_datapath( mod_a, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 );
        ten_hsif_provision_datapath( mod_b, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 );
    }
    
    if (provision_line) {
        tmp_mod_line = mod_line;
        ten_hsif_set_clk_40g( tmp_mod_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1 );
        ten_hsif_set_clk_40g( tmp_mod_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1 );
    }

    if (provision_line) {
        mod_hsif               = mod_line;
        slice_hsif             = slice_line;
        if (
                ( mr_optical_module_type == 0 ) ||  //  msa_loopback = 0
                ( mr_optical_module_type == 1 ) ||  //  msa_bridge = 1
                ( mr_optical_module_type == 2 ) ||  //  msa_breakout = 2
                ( mr_optical_module_type == 4 ) ||  //  msa_sfi41_loopback = 4
                ( mr_optical_module_type == 10 ) || //  msa_fpga_loopback = 10
                ( mr_optical_module_type == 12 ) || //  msa_none = 12
                ( mr_optical_module_type == 0xFF )  //  msa_error = 0xFF
           ) {                                           
            // Optical module is not present, so there will be no loss of signal indication */
            // 10G lane OK status signal will NOT take external LOS into consideration. */
            ten_hsif_set_ok_ctrl( mod_hsif, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );

        } else {
            // This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been
            // changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin,
            // generated by the FPGA which in turn gets a signal from the optical module. It causes
            // the dewrapper to disable justifications and N10G to go in and out of frame.
            // This needs to be fixed in the FPGA
            ten_glb_misc_xlos_inv_mr( mod_hsif, slice_hsif, 1 );
        }

        ten_hl_config_sfi51(mod_hsif);

        TEN_MDELAY(2000);
    }

    if (provision_client) {

        /*  This is to invert the SERDES lanes for the Cortina EVB; change as necessary. #4 */
        // dir                    = evb_xfi{xfi_board_type}[slice_client][0];
        // inv                    = evb_xfi{xfi_board_type}[slice_client][1];
        mod_hsif               = mod_client;
        slice_hsif             = slice_client;
        // mr_optical_module_type = t40fpga_msa_detect( 432, mod_hsif & 1 );

        if (
                ( mr_optical_module_type == 0 ) ||     /*  msa_loopback = 0 */
                ( mr_optical_module_type == 1 ) ||     /*  msa_bridge = 1 */
                ( mr_optical_module_type == 2 ) ||     /*  msa_breakout = 2 */
                ( mr_optical_module_type == 4 ) ||     /*  msa_sfi41_loopback = 4 */
                ( mr_optical_module_type == 10 ) ||    /*  msa_fpga_loopback = 10 */
                ( mr_optical_module_type == 12 ) ||    /*  msa_none = 12 */
                ( mr_optical_module_type == 0xFF )
           ) {                                           /*  msa_error = 0xFF */
            /*  Optical module is not present, so there will be no loss of signal indication */
            /*  10G lane OK status signal will NOT take external LOS into consideration. */
            ten_hsif_set_ok_ctrl( mod_hsif, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );

        } else {

            /*  This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been */
            /*  changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin, */
            /*  generated by the FPGA which in turn gets a signal from the optical module. It causes */
            /*  the dewrapper to disable justifications and N10G to go in and out of frame. */
            /*  This needs to be fixed in the FPGA */
            ten_glb_misc_xlos_inv_mr( mod_hsif, slice_hsif, 1 );
        }
        ten_hl_config_xfi_t41( mod_hsif, slice_hsif, 5, dir, inv, sysclk_freq, 1, 0, auxclk, 1, TEN_HSIF_XFI_DIV_BY_64_REF, xfi_clk_dist, 0, 0 );
    }

    ten_syncdsync_thread_set_cb_transcode( dev_id, slice_client, 1, 1 );
    
    if ( !ten_dev_is_t41(dev_id) ) {
        ten_syncdsync_thread_set_cb_40g_muxponder( dev_id, slice_client, 0, 1, 0, 2, 255, 236, 255, 237 );
    } else {
        ten_syncdsync_set_cb_40g_muxponder_t41( dev_id, slice_client, 0, 1, 0, 2, 255, 236, 255, 237, 10709225320, 10037273920, 43018413560 );
    }

    if ( !ten_dev_is_t41(dev_id) ) {
        ten_hl_syncdsync_threadsafe_datapath_config( mod_line, slice, mod_client, slice_client, 1, 0, 1, 64, 13, 13 );
    } else {
        ten_hl_syncdsync_datapath_config_t41( mod_line, slice, mod_client, slice_client, 13, 13, 1, 1, 64, 0, 1, 4 );
    }

    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_mpif_global_clock_disable_common( dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON );
        ten_mpif_global_reset_common( dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON );
        ten_mpif_global_reset_common( dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS );
    }
    
    ten_hl_config_otu2v_otu3v_t41( mod_line, slice, slice_client, dyn_repro, 1, 13, 5, 13, 0, 0, 0, 0, 0, 1, 4, 255 );

    /* ## The following code is used to enable the interrupt and register a handler for OTN Loss Of Frame */
    /* ## It is commented out so that customers can implement interrupt handler registration in their own way */
    /*  ten_n10g_otnr_intr_handler_enable (mod_line, slice, TEN_N10G_OTNR_INTR_ILOF); */
    /*  ten_n10g_otnr_intr_handler_enable (mod_client, slice_client, TEN_N10G_OTNR_INTR_ILOF); */
    ar_mod   = mod_client & 1;
    ar_slice = slice_client;
    ar_mod   = mod_line & 1;
    ar_slice = 0;
    ten_n40g_gblr4x_set_kpasel( mod_line, 1 );

    /*  Set the unused channels to 'idle' */
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 0 ) ) {
        for ( i = 0 ; i < 4 ; i++ ) {
            if ( i != slice_client ) {
                ten_hl_config_aggregation_idle( mod_line, i, mod_client, i );
            }
        }
    }

    if (provision_line) {
        ten_hsif_set_ok_ctrl( mod_line, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );
    }
    
    if (provision_client) {
        ten_hsif_set_ok_ctrl( mod_client, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );
    }

    /*  The following clockmux code is written for CS604x only in order to simplify it */
    if (provision_client) {
        ten_hl_xfi_config_clockmux_t41( mod_client, slice_client, auxclk, 64, 1, 1 );
        ten_mpif_clock_select_gpll_in( dev_id, mod_client & 1, slice_client, CS_TX, 0 );    /*  Bugzilla 30856 */
        ten_hl_gpllx1_waitfor_gpll_lock( dev_id, gpllx1_inst_client + slice_client );
    }

    /*  The following clockmux code is written for CS604x only in order to simplify it */
    if (provision_line) {
        ten_hl_mr_40g_config_clockmux(mod_line);
        ten_mpif_clock_select_gpll_in( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 0x0 );
        ten_hl_gpllx1_waitfor_gpll_lock_40g( dev_id, gpllx1_inst_line );
    }
    
    gpllx1_inst_client = ( mod_client & 1 ) == TEN_MODULE_A ? 1 : 9;
    ten_hl_gpllx1_waitfor_gpll_lock( dev_id, gpllx1_inst_client + slice_client );
    
    if (provision_line) {
        ten_n40g_set_global_resets( mod_a, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL );
        ten_n40g_set_global_resets( mod_b, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL );
    }
    
    ten_hl_config_remove_soft_resets( mod_line, slice_line, mod_client, slice_client, 5, 1 );
    
    if (provision_line) {
        ten_mpif_global_reset_hsif( dev_id, mod_line & 1, CS_TX_AND_RX, CS_RESET_DEASSERT );
        ten_mpif_set_clock_switch_force( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_RX, CS_DISABLE );
        ten_mpif_set_clock_switch_force( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, CS_DISABLE );
    }
    
    if (provision_client) {
        ten_mpif_global_reset_hsif( dev_id, mod_client & 1, CS_TX_AND_RX, CS_RESET_DEASSERT );
        ten_mpif_set_clock_switch_force( dev_id, mod_client,        slice_client, CS_RX, CS_DISABLE );
        ten_mpif_set_clock_switch_force( dev_id, TEN_MODULE_A_AND_B, slice_client, CS_TX, CS_DISABLE );
    }
    
    ten_hl_syncdsync_reset( mod_client, slice_client );
    ten_syncdsynctx_set_configuration_init_force( mod_client, slice_client, CS_RESET_TOGGLE );
    
    if (provision_line) {
        ten_hl_syncdsync_reset( mod_line, slice );
        ten_syncdsynctx_set_configuration_init_force( mod_line, slice, CS_RESET_TOGGLE );
    }
    
    ten_cupll_reset_t41( mod_client, slice_client, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE );
    ten_mpif_cupll_settle_force_t41( dev_id, slice_client, 2, CS_ENABLE );
    ten_mpif_cupll_settle_force_t41( dev_id, slice_client, 2, CS_DISABLE );
}



