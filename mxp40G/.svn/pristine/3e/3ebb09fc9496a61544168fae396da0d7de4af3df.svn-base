#include "xfi_10g_kpg_kpa.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main() {

    // Dynamic reprovisioning:
    // Set to '0' for the initial config of a board (resets board and chip)
    // Set to '1' to dynamically reprovision a client (keeps the line-side up)
    // Set to '2' to dynamically reprovision line and client (resets both line and client first, not for a muxponder!)
    // Set to '3' to dynamically reprovision the initial traffic in another chip (resets chip but not board)
     int dyn_repro = 0 ;
     int auxclk    = 0 ;
     

    // Set the sysrefclk frequency in MHz
    int  sysrefclk = 425;

    // Set this to '0' to use internal fan-out clock distribution
    // The Cortina T41 Customer EVB requires this to be 0 for the CFP/XFI interface
    int  xfi_clk_dist = 0;//( (  board_type == 8 ) && 0 ) ? 0 : 1;

    // For KPGA modes these can be changed to the desired pattern
    int  hsif_kpga = TEN_HSIF_PRBS_PN31;
    int  kpga      = TEN_KPG_PN31;

    // The following variables will also be used throughout the script:
    int  module;
    int  sysclk_freq;
    int  mbclksel;
    int  provision_line;
    int  provision_client;
    int  slice;
    int  dir;
    int  inv;
    int  fracdiv_module;
    int  fracdiv_slice;
    int  inst;
    int  silab_mod_line;
    int  silab_mod_client;
    int  silab_slice_line;
    int  silab_slice_client;
    int  silab_module;
    int  silab_slice;
    int  gpllx1_inst_line;
    int  gpllx1_inst_client;
    int  rdiv_divider;
    int  tmp_mod_line;
    int  tmp_mod_client;
    int  ar_mod;
    int  ar_slice;

    int  mod_hsif;
    int  slice_hsif;
    int  clock_ch;
    int  clock_card;
    int  side;
    int  mr_optical_module_type;
    int  tmp_slice_line;
    int  tmp_slice_line2;
    int  tmp_slice_client;
    int  tmp_slice_client2;
    int  config_cfp_mr_clock_client;
    int  config_cfp_mr_clock_line;

    // Device ID
    int  dev_id =0;

    // Module IDs of Sides A and B
    int mod_a =  dev_id << 8;
    int mod_b = (  dev_id << 8 ) | 1;

    // Module ID of the line
    int  mod_line = (  dev_id << 8 ) | 1;


    // Slice of the line
    int slice_line = 0;

    // Module ID of the client
    int  mod_client = (  dev_id << 8 ) | 0;

    // Slice of the client
    int slice_client = 0;



    // A local variable for iterators
    int  i;

    sysclk_freq =  sysrefclk * 1000000;
    provision_line   =  dyn_repro != 1;
    provision_client = 0;

    if ( (  dyn_repro == 0 ) || (  dyn_repro == 3 ) ) {

        // Hard-reset the CS604x device and set the sysrefclk
         //tb_init(  sysclk_freq,  dev_id,  dyn_repro == 3 ? 1 : 0 );
         mbclksel =  sysclk_freq > 200000000 ? 1 : 0;

        // Initialize the device driver
        ten_dev_main_init( dev_id);
        mod_a = ten_mod_main_init(  dev_id, TEN_MODULE_A );
        mod_b = ten_mod_main_init(  dev_id, TEN_MODULE_B );
        ten_hl_config_global(  dev_id, TEN_GLOBAL_MODE_S_40G, TEN_GLOBAL_MODE_QUAD_10G ,  mbclksel, 1, 1 );
        ten_hl_ohpp_and_shadow_ram_init( dev_id);
    }

 
    sysclk_freq =  sysclk_freq > 200000000 ?  sysclk_freq :  sysclk_freq * 4;
    gpllx1_inst_line = 9;
    
    slice = 0 ?  slice_client :  slice_line;
    ten_cb_rates(  dev_id, 10709225320, 0 ); //Ver estooo

    if ( provision_line) { //provision_line == 1 
         fracdiv_module =  mod_line;
         fracdiv_slice  =  slice_line;
         inst           = ( (  fracdiv_module & 1 ) == TEN_MODULE_A ) ?  fracdiv_slice :  fracdiv_slice + 4;
        ten_hl_fracdiv_config(  dev_id,  inst,  sysclk_freq, 334663291 );
    }

     silab_mod_client   =  mod_client;
     silab_mod_line     =  mod_line;
     silab_slice_line   =  slice_line;
     silab_slice_client =  slice_client;


    silab_module =  silab_mod_line;
    silab_slice  =  silab_slice_line;

    // Clocks on the different Cortina EVBs are programmed differently.
    // This code will check the board type and program the SiLabs appropriately.
    
    ten_mpif_rxdiv_cfg0_mode_t41(  dev_id, (  silab_module * 4 +  silab_slice ), 0 );
        


    tmp_slice_line2   =  slice_line;
    tmp_slice_client2 =  slice_client;

    if ( (  dyn_repro == 0 ) || (  dyn_repro == 3 ) ) {
        if (   ( ( ( (  slice_client == 1 ) || (  slice_client == 3 ) ) && ( 'disabled' == 'cfp_mr' ) ) )
            || ( ( ( (  slice_line == 1 ) || (  slice_line == 3 ) ) && ( 'xfi' == 'cfp_mr' ) ) ) )
        {
             if  (slice_line == 1)
                tmp_slice_line2   = 0; 
             
             if  (slice_line == 3)
                tmp_slice_line2   = 2;
             
             if  (slice_client == 1)
                tmp_slice_client2 = 0;
             
             if  (slice_client == 3)
                tmp_slice_client2 = 2;
             
             silab_mod_line    =  tmp_mod_line;
             silab_slice_line  =  tmp_slice_line2;
             silab_mod_client  =  tmp_mod_client;
             silab_slice_client =  tmp_slice_client2;

            
             silab_module =  silab_mod_line;
             silab_slice  =  silab_slice_line;

            // Clocks on the different Cortina EVBs are programmed differently.
            // This code will check the board type and program the SiLabs appropriately.
            
               
            //tb_program_clock(silab_module, pow(2,silab_slice), 2, 'xfi', 5, 6, 5, 510, 316, 10,  dev_id );
                
            ten_mpif_rxdiv_cfg0_mode_t41(  dev_id, (  silab_module * 4 +  silab_slice ), 0 );
            
          
        }
    }

    if ( (  dyn_repro == 0 ) || (  dyn_repro == 3 ) ) {
        ten_hsif_provision_datapath(  mod_a, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 );
        ten_hsif_provision_datapath(  mod_b, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 );
    }

    // This code controls the CFP laser on Cortina EVBs
    if (  dyn_repro == 0 ) {
        if ( ten_dev_is_t41( dev_id) ) {
        }
    }
    
    tmp_slice_line   =  slice_line;
    tmp_slice_client = 5;

   /* if ( 'disabled' == 'cfp_mr' ) {
        if (  slice_client == 1 ) {  tmp_slice_client = 0;  config_cfp_mr_clock_client = 1; }
        if (  slice_client == 3 ) {  tmp_slice_client = 2;  config_cfp_mr_clock_client = 1; }
        if ( 'xfi' == 'cfp_mr' ) {
            if (  slice_line == 1 ) {  tmp_slice_line = 0;  config_cfp_mr_clock_line = 1; }
            if (  slice_line == 3 ) {  tmp_slice_line = 2;  config_cfp_mr_clock_line = 1; }
        }
    }*/

if ( ( provision_line) && ( config_cfp_mr_clock_line) ) {

    // This is to invert the SERDES lanes for the Cortina EVB; change as necessary
     //dir                    =  evb_xfi{ board_type}[ tmp_slice_line][0];
     //inv                    =  evb_xfi{ board_type}[ tmp_slice_line][1];
     mod_hsif               =  mod_line;
     slice_hsif             =  tmp_slice_line;
     /*mr_optical_module_type = t40fpga_msa_detect( 432,  mod_hsif & 1 );

    if (
        (  mr_optical_module_type == 0 ) ||     // msa_loopback = 0
        (  mr_optical_module_type == 1 ) ||     // msa_bridge = 1
        (  mr_optical_module_type == 2 ) ||     // msa_breakout = 2
        (  mr_optical_module_type == 4 ) ||     // msa_sfi41_loopback = 4
        (  mr_optical_module_type == 10 ) ||    // msa_fpga_loopback = 10
        (  mr_optical_module_type == 12 ) ||    // msa_none = 12
        (  mr_optical_module_type == 0xFF )
      )
    {                                           // msa_error = 0xFF
                                                // Optical module is not pressent, so there will be no loss of signal indication
                                                // 10G lane OK status signal will NOT take external LOS into consideration.
        ten_hsif_set_ok_ctrl(  mod_hsif, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );

    }
    else {

        // This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been
        // changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin,
        // generated by the FPGA which in turn gets a signal from the optical module. It causes
        // the dewrapper to disable justifications and N10G to go in and out of frame.
        // This needs to be fixed in the FPGA
        ten_glb_misc_xlos_inv_mr(  mod_hsif,  slice_hsif, 1 );
    }*/
    ten_hl_config_xfi_t41(  mod_hsif,  slice_hsif, 5,  dir,  inv,  sysclk_freq, 1, 0,  auxclk, 1, TEN_HSIF_XFI_DIV_BY_64_REF,  xfi_clk_dist, 0, 0 );
    
    
}
     tmp_slice_line             =  slice_line;
     tmp_slice_client           = 5;
     config_cfp_mr_clock_client = 1;
     config_cfp_mr_clock_line   = 1;
     
    if ( ( provision_line) && ( config_cfp_mr_clock_line) ) {

        // This is to invert the SERDES lanes for the Cortina EVB; change as necessary
         //dir                    =  evb_xfi{ board_type}[ tmp_slice_line][0];
         //inv                    =  evb_xfi{ board_type}[ tmp_slice_line][1];
         mod_hsif               =  mod_line;
         slice_hsif             =  tmp_slice_line;
        // mr_optical_module_type = t40fpga_msa_detect( 432,  mod_hsif & 1 );

        if (
            (  mr_optical_module_type == 0 ) ||     // msa_loopback = 0
            (  mr_optical_module_type == 1 ) ||     // msa_bridge = 1
            (  mr_optical_module_type == 2 ) ||     // msa_breakout = 2
            (  mr_optical_module_type == 4 ) ||     // msa_sfi41_loopback = 4
            (  mr_optical_module_type == 10 ) ||    // msa_fpga_loopback = 10
            (  mr_optical_module_type == 12 ) ||    // msa_none = 12
            (  mr_optical_module_type == 0xFF )
          )
        {                                           // msa_error = 0xFF
                                                    // Optical module is not pressent, so there will be no loss of signal indication
                                                    // 10G lane OK status signal will NOT take external LOS into consideration.
            ten_hsif_set_ok_ctrl(  mod_hsif, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );

        }
        else {

            // This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been
            // changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin,
            // generated by the FPGA which in turn gets a signal from the optical module. It causes
            // the dewrapper to disable justifications and N10G to go in and out of frame.
            // This needs to be fixed in the FPGA
            ten_glb_misc_xlos_inv_mr(  mod_hsif,  slice_hsif, 1 );
        }
        
                //ten_xfi32x1_invert(  module,  slice, CS_TX, 0 );
                //ten_xfi32x1_invert(  module,  slice, CS_RX, 1 );
       
    }
    
    if ( !ten_dev_is_t41( dev_id) ) {
        ten_hl_syncdsync_threadsafe_datapath_config(  mod_line,  slice,  mod_client,  slice_client, 5, 0, 3, 64, 13, 16 );
    }
    else {
        ten_hl_syncdsync_datapath_config_t41(  mod_line,  slice,  mod_client,  slice_client, 13, 16, 5, 3, 64, 255, 0, 4 );
    }
    
    if ( (  dyn_repro == 0 ) || (  dyn_repro == 3 ) ) {
        ten_mpif_global_clock_disable_common(  dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON );
        ten_mpif_global_reset_common(  dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON );
        ten_mpif_global_reset_common(  dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS );
    }
    
    ten_hl_config_otu2_kpga(  mod_line,  slice_line, 5,  dyn_repro,  kpga, 1 );
    ten_hl_config_fec_t41(  mod_line,  slice_line, TEN_SLICE_10G, 13 );
    ten_hl_n10g_config_lof_from_traffic(  mod_line,  slice_line, 5, 13 );
    ten_hl_n10g_config_lom_from_traffic(  mod_line,  slice_line, 5, 13 );
    
    if ( provision_line) {
        ten_hsif_set_ok_ctrl(  mod_line, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );
    }
    
    if ( provision_client) {
        ten_hsif_set_ok_ctrl(  mod_client, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );
    }

    // The following clockmux code is written for CS604x only in order to simplify it

    // The following clockmux code is written for CS604x only in order to simplify it
    if ( provision_line) {
        ten_hl_xfi_config_clockmux_t41(  mod_line,  slice_line,  auxclk, 64, 1, 0 );
        ten_mpif_clock_select_gpll_in(  dev_id,  mod_line & 1,  slice_line, CS_TX, 0 );
         gpllx1_inst_line = (  mod_line & 1 ) == TEN_MODULE_A ? 1 : 9;
        ten_hl_gpllx1_waitfor_gpll_lock(  dev_id,  gpllx1_inst_line +  slice_line );
    }
    if ( provision_line) {
        gpllx1_inst_line = (  mod_line & 1 ) == TEN_MODULE_A ? 1 : 9;
        ten_hl_gpllx1_waitfor_gpll_lock(  dev_id,  gpllx1_inst_line +  slice_line );
    }

    module = ( (  mod_line & 1 ) == 0 ) ? TEN_MODULE_A : TEN_MODULE_B;
    ten_hl_config_remove_module_soft_resets(  mod_line,  slice_line, 5 );
    ten_mpif_set_clock_switch_force(  dev_id,  module,  slice_line, CS_TX_AND_RX, CS_DISABLE );
    ten_mpif_global_reset_hsif(  dev_id,  module, CS_TX_AND_RX, CS_RESET_DEASSERT );
    
    return 0;

}
