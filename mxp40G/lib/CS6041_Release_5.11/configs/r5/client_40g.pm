# Subroutines that could be made into High Level APIs

use strict;
use warnings FATAL => qw(all); # Promote hidden apish eval warnings to errors

package client_40g;

use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);
$VERSION = '1.0';
require Exporter;
@ISA = qw(Exporter);
@EXPORT = qw(
    config_otu3 config_8gfc_dj_odtu23 config_pbert_8gfc_odtu23 provision_hsif
);

use configs;            # High-level functions that could be ported to C
use clocks;
use config_clocks;      # Board-specific FPGA and clocking functions
use syncdsync;
use check;              # Traffic test functions for automated test scripts

##############################################################################
#
# Function:      config_pbert
#
# Config PBERT
#
# Parameters:
#
#	 slice - <0-7>
#
#    profile - <0|2|4>
#
#    min - min packet length
#
#    max - max packet length
#
#    ifg - ifg
#
# Returns:
#
sub config_pbert {
  my ($slice,$profile,$min,$max,$ifg) = @_;
  my $module_id = ($slice <4) ? main::TEN_MODULE_A : main::TEN_MODULE_B;
  my $dev_id = $module_id >> 8;
  my $max1;
  my $max2;

  main::ten_xcon_select_bert($dev_id,$slice,main::XCON_PBERT);

  main::ten_xcon_set_pbert_mode($dev_id,$slice,main::XCON_TRAFFIC_FRAME,$profile);
  
  main::ten_xcon_set_pbert_protocol($dev_id,$slice,0,0,main::XCON_DA_UCAST);

  main::ten_xcon_control_pbert_frame_payload($dev_id,$slice,main::XCON_PAYLOAD_PRBS,main::CS_ENABLE);
                                               
  main::ten_xcon_control_pbert_unit_len($dev_id,$slice,main::XCON_UNIT_LEN_RANDOM,0x7ff,$min,$max);

  main::ten_xcon_pbert_control_traffic($dev_id,$slice,0); 

  main::ten_xcon_pbert_control_ifg($dev_id,$slice,0,$ifg); 

  main::ten_xcon_pbert_select_fixed_pattern($dev_id,$slice,main::XCON_FIXED_PATTERN_01,0x00,0x11);

  main::ten_xcon_pbert_select_fixed_pattern($dev_id,$slice,main::XCON_FIXED_PATTERN_23,0x22,0x33);

  main::ten_xcon_pbert_select_fixed_pattern($dev_id,$slice,main::XCON_FIXED_PATTERN_45,0x08,0x00);

  main::ten_xcon_pbert_select_fixed_pattern($dev_id,$slice,main::XCON_FIXED_PATTERN_67,0x00,0x00);

  my $sl;
  if($slice < 4) { $sl = $slice;} else { $sl = $slice -4;} 
  if($max > 1518 && $profile <=4) {
    main::ten_pp10g_mac_rx_maxlen($module_id,$sl,$max);
  }
  if($max > 1518 && ($profile == 5 || $profile == 6)) {
    main::ten_pp10g_gfp_rx_maxlen($module_id,$sl,$max);
  }
  if($max > 1518) {
    $max1 = $max & 0x0000_ffff;
    $max2 = ($max & 0x0003_0000) >> 16;
    main::ten_pp10g_xgadj_tx_maxframe($module_id,$sl,$max2,$max1);
  }
}



sub config_8gfc_dj_odtu23 {
  my ($module_id_line, $slice_line, $module_id_client, $slice_client,
      $line_traffic_type, $dyn_repro, $sysclk) = @_;

  my $dev_id = $module_id_line >> 8;

  printf("config_8gfc_dj_odtu23:  0x%04X, sl=%d, 0x%04X, sl=%d\n, dyn=%d, sysclk=%d\n",
         $module_id_line, $slice_line, $module_id_client, 
         $slice_client, $dyn_repro, $sysclk);

  main::ten_hl_n10g_config($module_id_line, $slice_line, 
                           main::TEN_N10G_RX_ODU2J_8GFC, 
                           main::TEN_N10G_TX_8GFC_ODU2J, $dyn_repro);
  
  # Is this done elsewhere? KH
  main::ten_n10g_set_otnr_odwfs($module_id_line, $slice_line, 2278);
  main::ten_n10g_otnt_set_wrpfs($module_id_line, $slice_line, 2278);

  if ($line_traffic_type == main::TEN_TRAFFIC_TYPE_OTU3) {
      main::ten_hl_n40g_cfg_async_odtu23($module_id_line, $slice_line, main::CS_TX_AND_RX, 0, 0);

      # Hysteresis value for DT Just.
      if    ( $slice_line == 0 ) { main::ten_n40g_otnt4x_set_wrp0dh0($module_id_line, 0x1D82 ); }
      elsif ( $slice_line == 1 ) { main::ten_n40g_otnt4x_set_wrp1dh0($module_id_line, 0x1D82 ); }
      elsif ( $slice_line == 2 ) { main::ten_n40g_otnt4x_set_wrp2dh0($module_id_line, 0x1D82 ); }
      elsif ( $slice_line == 3 ) { main::ten_n40g_otnt4x_set_wrp3dh0($module_id_line, 0x1D82 ); }
  }
  elsif ($line_traffic_type == main::TEN_TRAFFIC_TYPE_OTU3P2) {
      #main::ten_hl_n40g_cfg_async_odtu23($module_id_line, $slice_line, main::CS_TX_AND_RX, 3084, 0);
      main::ten_hl_n40g_cfg_async_odtu23($module_id_line, $slice_line, main::CS_TX_AND_RX, 3082, 0);

      # Hysteresis value for DT Just.
      if    ( $slice_line == 0 ) { main::ten_n40g_otnt4x_set_wrp0dh0($module_id_line, 0x105A ); }
      elsif ( $slice_line == 1 ) { main::ten_n40g_otnt4x_set_wrp1dh0($module_id_line, 0x105A ); }
      elsif ( $slice_line == 2 ) { main::ten_n40g_otnt4x_set_wrp2dh0($module_id_line, 0x105A ); }
      elsif ( $slice_line == 3 ) { main::ten_n40g_otnt4x_set_wrp3dh0($module_id_line, 0x105A ); }
  }

  main::ten_hl_n10g_config($module_id_client, $slice_client, 
                           main::TEN_N10G_RX_BYPASS, main::TEN_N10G_TX_BYPASS, 0);

  main::ten_hl_pp10g_config($module_id_line, $slice_line, 
                            main::TEN_PP10G_RX_8FC, main::TEN_PP10G_TX_8FC);
                            
  main::ten_hl_pp10g_config($module_id_client, $slice_client, 
                            main::TEN_PP10G_RX_8FC, main::TEN_PP10G_TX_8FC);
    
  ##/* Bugzilla #19353, fix bus errors */
  main::ten_hl_ohpp_control_oduk_oci($module_id_line, $slice_line, main::CS_DISABLE);

  ##/* Bugzilla #19353, fix bus errors */
  main::ten_pp10g_set_pcs_rx_ber_timer($module_id_line, $slice_line, $sysclk * 125);  
  main::ten_pp10g_set_pcs_rx_ber_timer($module_id_client, $slice_client, $sysclk * 125);  

  # /* Line side OTU scrambling done in N40G block */
  main::ten_n10g_otnt_scrambling($module_id_line, $slice_line, 0, 0);
  main::ten_n10g_otnr_descrambling($module_id_line, $slice_line, 0, 0);
  
  #PTI setting for 8GFC
  main::ten_n10g_otnt_set_pti_byte($module_id_line, $slice_line, 0x02);
  main::ten_n10g_set_expected_pti_byte($module_id_line, $slice_line, 0x02);

  main::ten_n10g_otnt_set_ptie($module_id_line, $slice_line,  1); #Enable PTI insertion
                               
  main::ten_n10g_otnt_bipmsk($module_id_line, $slice_line, 0x7F);
                            
  # Set TDELON/TDELOFF for 3ms
  main::ten_n10g_otnr_lofcfg_tdelon_tdeloff($module_id_line, $slice_line, 492*239/255, 492*239/255);
  main::ten_n40g_otnr4x_lofcfg_tdelon_tdeloff($module_id_line, 495, 495);

  main::ten_n10g_gblr_set_xsel($module_id_line, $slice_line, 0x2);
  # Set STM 64
  main::ten_n10g_otnr_set_stm64md($module_id_line, $slice_line, 0);
  main::ten_n10g_otnt_set_stm64md($module_id_line, $slice_line, 0);

  # Configure XCON
  main::ten_xcon_es_select_source($dev_id, $slice_line, $slice_client+4, 
                                  main::XCON_N10G);
                                  
  main::ten_xcon_es_select_source($dev_id, $slice_client+4, $slice_line,
                                  main::XCON_N10G);

  main::ten_xcon_config_es_mode($dev_id, $slice_line, main::XCON_FP, 
                                main::XCON_NO_GFP, main::XCON_MODE_CUT_THRU, 
                                main::XCON_MODE_CCT);
                                
  main::ten_xcon_config_es_mode($dev_id, $slice_client+4, main::XCON_FP, 
                                main::XCON_NO_GFP, main::XCON_MODE_CUT_THRU, 
                                main::XCON_MODE_CCT);

  # Disable Deskew function aligning 4 incoming stream by FP since not full aggr
  my $rtn = main::ten_n40g_set_dsbldskw($module_id_line, 1);   #DSBLDSKW
  if ($rtn != 0) {
    misc_info("Failed to set DSBLDSKW bit");
  }
}



sub config_pbert_8gfc_odtu23 {
  my ($module_id_line, $slice_line, $module_id_client, $slice_client,
      $line_traffic_type, $dyn_repro, $sysclk) = @_;

  my $dev_id = $module_id_line >> 8;

  my $pbert_prof = 7;
  my $min_size = 64;
  my $max_size = 1518;
  my $pbert_ifg = 5;

  my $pbert_slice = ($module_id_client == 0) ? $slice_client : $slice_client+4;

  printf("config_pbert_8gfc_odtu23:  0x%04X, sl=%d, 0x%04X, sl=%d\n, dyn=%d sysclk=%d\n",
         $module_id_line, $slice_line, $module_id_client, 
         $slice_client, $dyn_repro, $sysclk);

  main::ten_hl_n10g_config($module_id_line, $slice_line, 
                           main::TEN_N10G_RX_ODU2J_8GFC, 
                           main::TEN_N10G_TX_8GFC_ODU2J, $dyn_repro);
  

  # Is this done elsewhere? KH
  main::ten_n10g_set_otnr_odwfs($module_id_line, $slice_line, 2278);
  main::ten_n10g_otnt_set_wrpfs($module_id_line, $slice_line, 2278);

  if ($line_traffic_type == main::TEN_TRAFFIC_TYPE_OTU3) {
      main::ten_hl_n40g_cfg_async_odtu23($module_id_line, $slice_line, main::CS_TX_AND_RX, 0, 0);

      # Hysteresis value for DT Just.
      if    ( $slice_line == 0 ) { main::ten_n40g_otnt4x_set_wrp0dh0($module_id_line, 0x1D82 ); }
      elsif ( $slice_line == 1 ) { main::ten_n40g_otnt4x_set_wrp1dh0($module_id_line, 0x1D82 ); }
      elsif ( $slice_line == 2 ) { main::ten_n40g_otnt4x_set_wrp2dh0($module_id_line, 0x1D82 ); }
      elsif ( $slice_line == 3 ) { main::ten_n40g_otnt4x_set_wrp3dh0($module_id_line, 0x1D82 ); }
  }
  elsif ($line_traffic_type == main::TEN_TRAFFIC_TYPE_OTU3P2) {
      #main::ten_hl_n40g_cfg_async_odtu23($module_id_line, $slice_line, main::CS_TX_AND_RX, 3084, 0);
      main::ten_hl_n40g_cfg_async_odtu23($module_id_line, $slice_line, main::CS_TX_AND_RX, 3082, 0);

      # Hysteresis value for DT Just.
      if    ( $slice_line == 0 ) { main::ten_n40g_otnt4x_set_wrp0dh0($module_id_line, 0x105A ); }
      elsif ( $slice_line == 1 ) { main::ten_n40g_otnt4x_set_wrp1dh0($module_id_line, 0x105A ); }
      elsif ( $slice_line == 2 ) { main::ten_n40g_otnt4x_set_wrp2dh0($module_id_line, 0x105A ); }
      elsif ( $slice_line == 3 ) { main::ten_n40g_otnt4x_set_wrp3dh0($module_id_line, 0x105A ); }
  }

  main::ten_hl_n10g_config($module_id_client, $slice_client, 
                           main::TEN_N10G_RX_BYPASS, main::TEN_N10G_TX_BYPASS, 0);

  main::ten_hl_pp10g_config($module_id_line, $slice_line, 
                            main::TEN_PP10G_RX_8FC, main::TEN_PP10G_TX_8FC);
                            
  main::ten_hl_pp10g_config($module_id_client, $slice_client, 
                            main::TEN_PP10G_RX_8FC, main::TEN_PP10G_TX_8FC);    
  ##/* Bugzilla #19353, fix bus errors */
  main::ten_hl_ohpp_control_oduk_oci($module_id_line, $slice_line, main::CS_DISABLE);

  ##/* Bugzilla #19353, fix bus errors */
  main::ten_pp10g_set_pcs_rx_ber_timer($module_id_line, $slice_line, $sysclk * 125);  
  main::ten_pp10g_set_pcs_rx_ber_timer($module_id_client, $slice_client, $sysclk * 125);  

  # /* Line side OTU scrambling done in N40G block */
  main::ten_n10g_otnt_scrambling($module_id_line, $slice_line, 0, 0);
  main::ten_n10g_otnr_descrambling($module_id_line, $slice_line, 0, 0);
  
  #PTI setting for 8GFC
  main::ten_n10g_otnt_set_pti_byte($module_id_line, $slice_line, 0x02);
  main::ten_n10g_set_expected_pti_byte($module_id_line, $slice_line, 0x02);

  main::ten_n10g_otnt_set_ptie($module_id_line, $slice_line,  1); #Enable PTI insertion
                               
  main::ten_n10g_otnt_bipmsk($module_id_line, $slice_line, 0x7F);
                            
  # Set TDELON/TDELOFF for 3ms
  main::ten_n10g_otnr_lofcfg_tdelon_tdeloff($module_id_line, $slice_line, 492*239/255, 492*239/255);
  main::ten_n40g_otnr4x_lofcfg_tdelon_tdeloff($module_id_line, 495, 495);

  main::ten_n10g_gblr_set_xsel($module_id_line, $slice_line, 0x2);
  # Set STM 64
  main::ten_n10g_otnr_set_stm64md($module_id_line, $slice_line, 0);
  main::ten_n10g_otnt_set_stm64md($module_id_line, $slice_line, 0);

  # Configure XCON
  main::ten_xcon_es_select_read_source($dev_id, $pbert_slice, main::XCON_PBERT);

  main::ten_xcon_es_select_source($dev_id, $slice_line, $slice_client+4, 
                                  main::XCON_PP10G);
                                  
  main::ten_xcon_es_select_source($dev_id, $slice_client+4, $slice_client+4,
                                  main::XCON_PP10G);

  main::ten_xcon_config_es_mode($dev_id, $slice_line, main::XCON_FP, 
                                main::XCON_NO_GFP, main::XCON_MODE_STORE_FWD, 
                                main::XCON_MODE_PKT);
                                
  main::ten_xcon_config_es_mode($dev_id, $slice_client+4, main::XCON_FP, 
                                main::XCON_NO_GFP, main::XCON_MODE_STORE_FWD, 
                                main::XCON_MODE_PKT);

  main::ten_xcon_select_es_packet_centering($dev_id, $slice_line, 
                                            main::XCON_RECENTER_LOWER, main::CS_DISABLE);
  main::ten_xcon_select_es_packet_centering($dev_id, $slice_line, 
                                            main::XCON_RECENTER_UPPER, main::CS_DISABLE);
  main::ten_xcon_select_es_packet_centering($dev_id, $slice_line, 
                                            main::XCON_AUTO_CENTER, main::CS_DISABLE);
  main::ten_xcon_select_es_packet_centering($dev_id, $slice_client+4,
                                            main::XCON_RECENTER_LOWER, main::CS_DISABLE);
  main::ten_xcon_select_es_packet_centering($dev_id, $slice_client+4, 
                                            main::XCON_RECENTER_UPPER, main::CS_DISABLE);
  main::ten_xcon_select_es_packet_centering($dev_id, $slice_client+4, 
                                            main::XCON_AUTO_CENTER, main::CS_DISABLE);

  main::ten_pp10g_xgadj_rx_rate_control3($module_id_line, $slice_line, 8);

  main::ten_n10g_set_pktie($module_id_line, $slice_line, 1);
  main::ten_n10g_set_pktie($module_id_client, $slice_client, 1);

  # Disable Deskew function aligning 4 incoming stream by FP since not full aggr
  my $rtn = main::ten_n40g_set_dsbldskw($module_id_line, 1);   #DSBLDSKW
  if ($rtn != 0) {
    misc_info("Failed to set DSBLDSKW bit");
  }

  config_pbert($pbert_slice, $pbert_prof, $min_size, $max_size, $pbert_ifg);
}



##############################################################################
#
# Function: provision_hsif
#
# Provision HSIF
#
# Parameter:
#
#    module -      Line Module:  0 for A, 1 for B
#    traffic_type -          Trafic type
#
##############################################################################
sub provision_hsif {

    my ($module, $hsif_type, $linerate, $slice, $traffic_type, $sysclk_freq, $sync, 
        $auxclk, $eds, $xfi_dir, $xfi_invert, $mode, $xfi_clk_dist, $use_xaui_prot,
        $cfp_mrb1_mrb3_mode, $k) = @_;

    print ("\n");
    print ("provision_hsif:  module = $module, hsif_type = $hsif_type, linerate = $linerate, slice = $slice,\n");
    print ("                 traffic_type = $traffic_type\n");
    print ("                 sysclk_freq = $sysclk_freq\n");
    print ("                 sync = $sync\n");
    print ("                 auxclk = $auxclk\n");
    print ("                 eds = $eds, xfi_dir = $xfi_dir, xfi_invert = $xfi_invert\n");
    print ("                 mode = $mode\n");
    print ("                 xfi_clock_distribution = $xfi_clk_dist\n");
    print ("                 use_xaui_protection_switch_mode = $use_xaui_prot\n");
    print ("                 cfp_mrb1_mrb3_mode = $cfp_mrb1_mrb3_mode\n");
    print ("                 k_value = $k\n");

    my $dev_id = $module >> 8;

    if ($traffic_type == main::TEN_TRAFFIC_TYPE_OC192_OTU2) {
        # Need the speed of the final container
        $traffic_type = main::TEN_TRAFFIC_TYPE_OTU2;
    }

    my $mr_optical_module_type = main::t40fpga_msa_detect(432, $module&1);
    if (($mr_optical_module_type == 0) ||   # msa_loopback = 0
        ($mr_optical_module_type == 1) ||   # msa_bridge = 1
        ($mr_optical_module_type == 2) ||   # msa_breakout = 2
        ($mr_optical_module_type == 4) ||   # msa_sfi41_loopback = 4
        ($mr_optical_module_type == 10) ||   # msa_fpga_loopback = 10
        ($mr_optical_module_type == 12) ||   # msa_none = 12
        ($mr_optical_module_type == 0xFF)) {   # msa_error = 0xFF
        # Optical module is not present, so there will be no loss of signal indication
        # 10G lane OK status signal will NOT take external LOS into consideration.
        main::ten_hsif_set_ok_ctrl ($module, main::TEN_SLICE_ALL, main::TEN_HSIF_OK_CTRL_XLOS_EN, 0);
    } 
    else {
        # This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been 
        # changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin, 
        # generated by the FPGA which in turn gets a signal from the optical module. It causes 
        # the dewrapper to disable justifications and N10G to go in and out of frame. 
        # This needs to be fixed in the FPGA
        main::ten_glb_misc_xlos_inv_mr ($module, $slice, 1);
    }                       
                           
    # These routines will call failure if the waitfor_vcotune test fails, so that the
    # test case will end gracefully and the regression run continue
    
    if ($hsif_type == main::TEN_HSIF_PROTOCOL_SFI51) {
      print ("                 TEN_HSIF_PROTOCOL_SFI51\n");
      if ($mode == main::TEN_40G_TRANSPONDER) {
        if (main::ten_hl_config_sfi51_40g_transponder($module, $sync) != main::CS_OK) {
          failure("ten_hl_config_sfi51_40g_transponder call failed for Side $module\n");
          #return 1;
        }
       } 
       else {
         if (main::ten_hl_config_sfi51($module) != main::CS_OK) {
          failure("ten_hl_config_sfi51 call failed for Side $module\n");
          #return 1;
        }
       }
       ####  this is already done in autoconfig_silab
       #### tb_ical_40g($module);
        
        my $address;
        if ($module == 0) {
            $address = 0x5000;
        } else {
            $address = 0x5400;
        }
        # Reset the optical module to make sure that the laser will turn on
        # AND that it will transmit at the right frequency
        if (!main::ten_dev_is_ws_in_progress($dev_id)) {
          main::dev_reg_write ( 432, 0, $address, 0x80a );
          sleep (2);
          main::dev_reg_write ( 432, 0, $address, 0x803 );
        }
    }

    elsif ($hsif_type == main::TEN_HSIF_PROTOCOL_SFI42_40G) { 
         print ("                 TEN_HSIF_PROTOCOL_SFI42_40G\n");

    #    if ($linerate == 40) {
          if ($mode == main::TEN_40G_TRANSPONDER) {
            if (main::ten_hl_config_sfi42_40g_transponder($module, main::TEN_HSIF_CKREFDIV1, 1, 0, $sync) != main::CS_OK) {
              failure("ten_hl_config_sfi42_40g  call failed for Side $module\n");
              return 1;
            }
          }
          else {
            if (main::ten_hl_config_sfi42_40g($module, main::TEN_HSIF_CKREFDIV1, 1, 0) != main::CS_OK) {
              failure("ten_hl_config_sfi42_40g  call failed for Side $module\n");
              return 1;
            }
          }
          ####  this is already done in autoconfig_silab
          ####  tb_ical_40g($module);
    #    }
    }

    elsif ($hsif_type == main::TEN_HSIF_PROTOCOL_SFI42_10G) {
        print ("                 TEN_HSIF_PROTOCOL_SFI42_10G\n");
          if (main::ten_hl_config_sfi42_10g($module, $slice, $traffic_type, $sysclk_freq, $sync, $eds ) != main::CS_OK) {
            failure("ten_hl_config_sfi42_10g  call failed for Side $module traffic_type $traffic_type\n");
            return 1;
          }
          ####  this is already done in autoconfig_silab
          ####  tb_ical($module, $slice);
    }
    
    elsif ($hsif_type == main::TEN_HSIF_PROTOCOL_SFI41) {
        print ("                 TEN_HSIF_PROTOCOL_SFI41\n");
        if ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU2) {
            # FPGA write to enable SFI4.1 optic module to work with OTU2 rate.
            main::dev_reg_write(432, 0, 0x6801, 0x6E);
        }
        elsif ($traffic_type == main::TEN_TRAFFIC_TYPE_OC192) {
            # FPGA write to enable SFI4.1 optic module to work with OC-192 rate.
            main::dev_reg_write(432, 0, 0x6801, 0x6F);
        }
        #elsif ($traffic_type == main::TEN_TRAFFIC_TYPE_10GE) {
        else {
            # FPGA write to enable SFI4.1 optic module to work with 10GE rate.
            main::dev_reg_write(432, 0, 0x6801, 0x6C);
        }
 
        my $launch_data_rxclk;
        my $launch_data_txclk;
        if (($module&0x1) == main::TEN_MODULE_A) {
          $launch_data_rxclk = 1;
          $launch_data_txclk = 1;
        }
        else {
          $launch_data_rxclk = 0;
          $launch_data_txclk = 0;
        }

        #if (main::ten_hl_config_sfi41($module, $slice, 1) != main::CS_OK) {
        if (main::ten_hl_config_sfi41_v2($module, $slice, 1, $launch_data_txclk, $launch_data_rxclk) != main::CS_OK) {
            failure("Failed to provision SFI41 on slice $slice\n");
            return 1;
        }
        ####  this is already done in autoconfig_silab
        ####  tb_ical($module, $slice);
    }
    
    elsif ($hsif_type == main::TEN_HSIF_PROTOCOL_XFI) {
         
        print ("                 TEN_HSIF_PROTOCOL_XFI\n");
                  
        if ($module == 0) {
           failure("             Cannot have XFI on Module A\n");
           return 1;
        }
        
        if ($linerate == 40) {
              # Bugailla 28237/26477 Start
              my @xfi_40g_ports;
              if ($xfi_clk_dist == 0) {
                # Internal fan-out
                #@xfi_40g_ports=qw(2 0 1 3);
                @xfi_40g_ports=qw(0 1 2 3);   # Still some issues with internal fan out and slice 2 muxponder on side B
              } else {  
                # External fan-out
                #@xfi_40g_ports=qw(2 0 1 3);
                @xfi_40g_ports=qw(0 1 2 3);  
              }
              # Bugailla 28237/26477 End

              foreach my $slice_client (@xfi_40g_ports) {  
                $xfi_dir = main::CS_TX_AND_RX;
                if (main::t40fpga_get_board_type($FPGA_SYS_ID) == 8) {
                  # CEB
                  if (main::t40fpga_get_ceb_daughtercard_type ( 432, 0 ) == 1) {
                    # CFP card
                    if (($slice_client == 0) || ($slice_client == 2)) {
                      $xfi_invert = 0;
                    } 
                    else {
                      $xfi_invert = 1;
                    }
                  } 
                  else {
                    # loopback card
                    $xfi_invert = 0;
                  }
                } 
                elsif ((main::t40fpga_get_board_type($FPGA_SYS_ID) == 4) || 
                         (main::t40fpga_get_board_type($FPGA_SYS_ID) == 6)) {
                  print("CFP/XFP board\n");
                  if (($slice_client == 0) || ($slice_client == 2)) {
                    $xfi_dir = main::CS_TX_AND_RX;
                    $xfi_invert = 1;
                  } 
                  else {
                    $xfi_dir = main::CS_TX;
                    $xfi_invert = 0;
                  }
                }
                elsif (main::t40fpga_get_board_type($FPGA_SYS_ID) == 5) {
                  print("SFP+ board\n");
                  if (($slice_client == 1) || ($slice_client == 3)) {
                    $xfi_dir = main::CS_TX;
                    $xfi_invert = 1;
                  }
                }
                elsif (main::t40fpga_get_board_type($FPGA_SYS_ID) == 9) {
                  print("SP board\n");
                  $xfi_dir = main::CS_RX;
                  $xfi_invert = 1;
                }
                else {
                  if (($slice_client == 0) || ($slice_client == 2)) {
                    $xfi_invert = 0;
                  } 
                  else {
                    $xfi_invert = 1;
                  }
                }
            
                # 40G XFI
                if (main::ten_hl_config_xfi_t41($module,
                        $slice_client,
                        $traffic_type,
                        $xfi_dir,
                        $xfi_invert,
                        $sysclk_freq,
                        1,
                        $sync,
                        $auxclk,
                        1,   # Bugzilla 19983  : Must wait for VCO Tune
                        main::TEN_HSIF_XFI_DIV_BY_64_REF, 
                        $xfi_clk_dist, $k, 0) != main::CS_OK) {
                       failure("Failed to provision XFI 40G Slice $slice_client\n");
                #  return 1;
                }
               
                # Bugzilla 31024 code removed

                # Bugzilla 27628 Code removed                
                # Bugzilla 28529 Start   Code temporarily added back in
                main::ten_mpif_global_reset_n40g($dev_id, $module, main::CS_RX, main::CS_RESET_DEASSERT);
                main::ten_mpif_global_clock_disable_n40g($dev_id, $module, main::CS_RX, main::CS_RESET_ASSERT);

                main::ten_n40g_mldrx_mld_es_release_sreset_t41($module, $slice_client);             
                #main::ten_reg_write($dev_id, main::TEN_N40G_MLDRX_MLD_ES_RESET + (($module & 1) * main::TEN_N40G_STRIDE) + (0x40 * $slice_client), 0);

                main::ten_n40g_mldrx_sadeco_release_sreset_t41($module);
                main::ten_n40g_mldrx_sadeco_sdc_on_t41($module);

                if (($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3) or 
                    ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3E) or 
                    ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3E1) or 
                    ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3E2) or 
                    ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3E3) or 
                    ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3E4) or # Bugailla 28237
                    ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3P) or 
                    ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3P2) or
                    ($traffic_type == main::TEN_TRAFFIC_TYPE_OC768_OTU3)) {
                    main::ten_n40g_rx_otl34_t41($module);
                    main::ten_n40g_mldrx_sadeco_frame_word_length_t41($module, 0x0FF0);
                } elsif ($traffic_type == main::TEN_TRAFFIC_TYPE_OC768) {
                    main::ten_n40g_rx_stl256_t41($module);
                    main::ten_n40g_mldrx_sadeco_frame_word_length_t41($module, 0x97e0);
                } 
                # Bugzilla 28529 End   Code temporarily added back in

                # Preemphasis
                ## main::ten_reg_write($dev_id, 0x3022+($slice_client*0x400), 0x2e);
                ## main::ten_reg_write($dev_id, 0x3023+($slice_client*0x400), 0xc21e);
                main::ten_xfi32x1_stx0_tx_output_ctrl($module, $slice_client, 
                                                      0,     # stx_drv_lower_cm  
                                                      0x2E,  # stx_level         
                                                      2,     # stx_pre_peak      
                                                      0x1E); # stx_post_peak    
                                                      
                #  bugzilla #27455, set xfi xlos broadcast FOR CFP XFI and CFP MR
                main::ten_hsif_misc_xfi_xlos_broadcast($module, 1);
            }
        }
        else {
          # 10G XFI
          if (main::ten_hl_config_xfi_t41($module,
                        $slice,
                        $traffic_type,
                        $xfi_dir,
                        $xfi_invert,
                        $sysclk_freq,
                        1,
                        $sync,
                        $auxclk,
                        1,   # Bugzilla 19983  : Must wait for VCO Tune
                        main::TEN_HSIF_XFI_DIV_BY_64_REF, 
                        $xfi_clk_dist, 0, 0) != main::CS_OK) {
            print("Failed to provision XFI on slice $slice\n");
            # failure("Failed to provision XFI on slice $slice\n");
            # return 1;
          }
          
          my $_type = main::t40fpga_get_board_type($FPGA_SYS_ID);
          print ("board type is $_type  ");
            
          if ($_type == 4) {
             print("XFP board\n");
          }
          elsif ($_type == 5) {
             print("SFP+ board\n");
          }
          elsif ($_type == 6) {
             print("CFP board\n");
          }
          elsif ($_type == 7) {
             print("QSFP board\n");
          }
          elsif ( $_type == 8) {
            print("CEB (Customer Evaluation Board)\n");
            if (main::t40fpga_get_ceb_daughtercard_type( 432, 0 ) == 0) {
              print("Invalid daughtercard\n");
            }
            elsif (main::t40fpga_get_ceb_daughtercard_type( 432, 0 ) == 1) {
              print("CFP daughtercard\n");
            }
            elsif (main::t40fpga_get_ceb_daughtercard_type( 432, 0 ) == 2) {
              print("QSFP daughtercard\n");
            }
            if (main::t40fpga_get_ceb_daughtercard_type( 432, 0 ) == 3) {
              # QUAD XFP
              print ("QUAD (4x) XFP\n");
              if ($slice==0 || $slice==2) {
                main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 0);
                main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 1);
              } 
              else {
                main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 1);
                main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 0);
              }    
            # Bugzilla 31024 Start
            }
             elsif (main::t40fpga_get_ceb_daughtercard_type( 432, 0 ) == 4) {
              print("CXP daughtercard\n");
            }
            elsif (main::t40fpga_get_ceb_daughtercard_type (432, 0) == 5) {
              # SFP+ card
              print ("QUAD SFP+\n");
              if ($slice==0 || $slice==2) {
                main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 0);
                main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 1);
              }
              else {
                main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 1);
                main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 0);
              }
            # Bugzilla 31024 End
            } 
            elsif (main::t40fpga_get_ceb_daughtercard_type (432, 0) == 11) {
              print("Breakout daughtercard\n");
              main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 0);
              main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 0);
            }
            elsif (main::t40fpga_get_ceb_daughtercard_type (432, 0) == 12) {
              print("Long Bridge daughtercard\n");
              main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 0);
              main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 0);
            }
            elsif (main::t40fpga_get_ceb_daughtercard_type (432, 0) == 13) {
              print("Short Bridge  daughtercard\n");
              main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 0);
              main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 0);
            }
            elsif (main::t40fpga_get_ceb_daughtercard_type (432, 0) == 14) {
              print("Loopback daughtercard\n");
              main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 0);
              main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 0);
            }
            elsif (main::t40fpga_get_ceb_daughtercard_type (432, 0) == 15) {
              print("None - no daughtercard\n");
              main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 0);
              main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 0);
            }
            else {
              print("Unsupported daughtercard\n");
            }
          }
          elsif ($_type == 9) {
            print("SP board\n");
            if ($slice==0 || $slice==2) {
              main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 0);
              main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 1);
            }
            else {
              main::ten_xfi32x1_invert($module, $slice, main::CS_TX, 1);
              main::ten_xfi32x1_invert($module, $slice, main::CS_RX, 0);
            }
          }   
        }
    }
    elsif ($hsif_type == main::TEN_HSIF_PROTOCOL_XAUI) {
        print ("                 TEN_HSIF_PROTOCOL_XAUI\n");
        if (main::ten_hl_config_xaui($module, $slice, 1, $use_xaui_prot ? 3 : 0) != main::CS_OK) {
           failure("Failed to provision XAUI on slice $slice\n");
           return 1;
        }
        ####  this is already done in autoconfig_silab
        ####
        ####if ($use_xaui_prot == 3) {
        ####  tb_ical($module | 0x0001, $slice);
        ####}
        ####else {
        ####  tb_ical($module, $slice);
        ####}
    }
    elsif ($hsif_type == main::TEN_HSIF_PROTOCOL_CFP) {
        
        my $cfp_slice;
        my $cfp_mr_tx_inv = 0;
        my $cfp_mr_rx_inv = 0;
        my $cfp_mr_daughtercard = 0;
        my $cfp_mr_auxclk = 0;
        
        # Cortina Systems Boards, use these settings:
        my $cfp_stx_tx_output_ctrl_drv_lower_cm = 0x01;
        my $cfp_stx_tx_output_ctrl_level        = 0x2A;
        my $cfp_stx_tx_output_ctrl_post_peak    = 0x1B;
        
        # Non Cortina Systems Boards, use these settings
        # Settings below, which provide about 4.5-5dB pre-emphasis:
        # CFP32X1_SDS_COMMON_STX0_TX_OUTPUT_CTRLA = 0x0024
        # CFP32X1_SDS_COMMON_STX0_TX_OUTPUT_CTRLB = 0xC014
        # $cfp_stx_tx_output_ctrl_drv_lower_cm = 0;
        # $cfp_stx_tx_output_ctrl_level        = 0x24;
        # $cfp_stx_tx_output_ctrl_post_peak    = 0x14;
        
        if ($linerate == 40) {
          print("                 TEN_HSIF_PROTOCOL_CFP_MR 40G\n");
          $cfp_slice = main::TEN_SLICE_ALL;
          $cfp_mr_auxclk = $cfp_mrb1_mrb3_mode;
        }
        else {
          print("                 TEN_HSIF_PROTOCOL_CFP_MR 10G\n");
          $cfp_slice = $slice;
          $cfp_mr_auxclk = $auxclk;
        }
  
        my $_type = main::t40fpga_get_board_type($FPGA_SYS_ID);
        print ("board type = $_type  ");
       
        if ($_type == 4) {
           print("XFP board\n");
        }
        elsif ($_type == 5) {
           print("SFP+ board\n");
        }
        elsif ($_type == 6) {
           print("CFP board\n");
        }
        elsif ($_type == 7) {
           print("QSFP board\n");
        }
        elsif ( $_type == 8) {
          print("CEB (Customer Evaluation Board)\n");
          $cfp_mr_daughtercard = main::t40fpga_get_ceb_daughtercard_type( 432, 1 );
          printf("daughtercard = %d  ", $cfp_mr_daughtercard );
        
          if ($cfp_mr_daughtercard == 0) {
            print("Invalid daughtercard\n");
          }
          elsif ($cfp_mr_daughtercard == 1) {
            print("CFP daughtercard\n");
          }
          elsif ($cfp_mr_daughtercard == 2) {
            print("QSFP daughtercard\n");
          }
          elsif ($cfp_mr_daughtercard == 3) {
            print ("QUAD (4x) XFP daughtercard\n");
            $cfp_mr_tx_inv = 0;
            $cfp_mr_rx_inv = 1;
          }
          elsif ($cfp_mr_daughtercard == 4) {
            print("CXP daughtercard\n");
          }
          elsif ($cfp_mr_daughtercard == 5) {
            print ("QUAD (4x) SFP+ daughtercard\n");
            if ($slice==0 || $slice==2) {
              $cfp_mr_tx_inv = 0;
              $cfp_mr_rx_inv = 1;
            } 
            else {
              $cfp_mr_tx_inv = 0;
              $cfp_mr_rx_inv = 1;
            }    
          } 
          elsif ($cfp_mr_daughtercard == 11) {
            print("Breakout daughtercard\n");
          }
          elsif ($cfp_mr_daughtercard == 12) {
            print("Long Bridge daughtercard\n");
          }
          elsif ($cfp_mr_daughtercard == 13) {
            print("Short Bridge  daughtercard\n");
          }
          elsif ($cfp_mr_daughtercard == 14) {
            print("Loopback daughtercard\n");
          }
          elsif ($cfp_mr_daughtercard == 15) {
            print("None - no daughtercard\n");
          }
          else {
            print("Unsupported daughtercard\n");
          }
        }
        elsif ($_type == 9) {
           print("SP board\n");
            # Invert CFP TX lanes 0,1
            if ($slice==0 || $slice==1) {
              $cfp_mr_tx_inv = 1;
              $cfp_mr_rx_inv = 0;
            }
            else {
              $cfp_mr_tx_inv = 0;
              $cfp_mr_rx_inv = 0;
            }
            # from john heaven
            #main::ten_reg_write(0, 0x1b255, 0xc);
            #main::ten_reg_write(0, 0x1b2d5, 0xc);

            # swap CFP TX lanes 0,1
            #main::ten_reg_write(0, 0x200f, 0x1);
            #main::ten_reg_write(0, 0x2011, 0x0);
        }
        else {
           print("Unsupported Board\n");
           $cfp_stx_tx_output_ctrl_drv_lower_cm = 0;
           $cfp_stx_tx_output_ctrl_level        = 0x24;
           $cfp_stx_tx_output_ctrl_post_peak    = 0x14;
        }
        
        if (main::ten_hl_config_cfp_t41($module,                           #  module_id
                                        $cfp_slice,                        #  slice
                                        $traffic_type,                     #  traffic
                                        main::TEN_HSIF_CFP_DIV_BY_64_REF,  #  div
                                        main::TEN_HSIF_CKREFDIV4,          #  ckrefdiv
                                        $cfp_mr_rx_inv,                    #  rx_bitinv
                                        $cfp_mr_tx_inv,                    #  tx_bitinv
                                        0,                                 #  prot
                                        $cfp_mr_auxclk,                    #  aux_clk, 0=normal, 1=40G MRB1/3 mode, 2=10G config extra clock
                                        1,                                 #  wait_for_vcotune
                                        $cfp_stx_tx_output_ctrl_drv_lower_cm,
                                        $cfp_stx_tx_output_ctrl_level,
                                        $cfp_stx_tx_output_ctrl_post_peak,
                                        0)                                 #  cfp_srx_rx_misc_srx_eqadj
                                        != main::CS_OK) {
          print("Failed to provision CFP on slice $cfp_slice\n");
          return 0;
        }
        
        if ($_type == 9) {
           print("SP board swap CFP TX lanes 0,1\n");
           # from john heaven
           # swap CFP TX lanes 0,1
           ## main::ten_reg_write(0, 0x200f, 0x1);
           ## main::ten_reg_write(0, 0x2011, 0x0);
           main::ten_hsif_set_tx_laneswap($module | main::TEN_MODULE_B, 0, 1);
           main::ten_hsif_set_tx_laneswap($module | main::TEN_MODULE_B, 1, 0);
        }
         
        if ($linerate == 40) {
          main::ten_mpif_global_reset_n40g($dev_id, $module, main::CS_RX, main::CS_RESET_DEASSERT);
          main::ten_mpif_global_clock_disable_n40g($dev_id, $module, main::CS_RX, main::CS_RESET_ASSERT);
          
          main::ten_n40g_mldrx_mld_es_set_sreset_t41($module, main::TEN_SLICE_ALL, 0);
          main::ten_n40g_mldrx_sadeco_release_sreset_t41($module);
          main::ten_n40g_mldrx_sadeco_sdc_on_t41($module);
          
          if (($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3) or 
              ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3E) or 
              ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3E1) or 
              ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3E2) or 
              ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3E3) or 
              ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3E4) or  # Bugzilla 28237
              ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3P) or 
              ($traffic_type == main::TEN_TRAFFIC_TYPE_OTU3P2) or
              ($traffic_type == main::TEN_TRAFFIC_TYPE_OC768_OTU3)) {
              main::ten_n40g_rx_otl34_t41($module);
              main::ten_n40g_mldrx_sadeco_frame_word_length_t41($module, 0x0FF0);
          }
          elsif ($traffic_type == main::TEN_TRAFFIC_TYPE_OC768) {
              main::ten_n40g_rx_stl256_t41($module);
              main::ten_n40g_mldrx_sadeco_frame_word_length_t41($module, 0x97e0);
          }  
        }
        # Bugzilla 28529 End   Code temporarily added back in
    }
    else {
       failure("Invalid hsif_type $hsif_type selection.\n");
       return 1;
    }
    return 0;
}

1;
