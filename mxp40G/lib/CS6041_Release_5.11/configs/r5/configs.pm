# Subroutines that could be made into High Level APIs

use strict;
use warnings FATAL => qw(all); # Promote hidden apish eval warnings to errors

package configs;

use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);
$VERSION = '1.0';
require Exporter;
@ISA = qw(Exporter);
@EXPORT = qw(
    config_get_port0_sfi4_1_ufec_alloc_status
    config_sfi51 config_sfi42_40g config_sfi42_10g
    config_xcon config_clockmux_xfi config_clockmux_mr config_clockmux_mr_40g
    config_waitfor_gpll_lock_40g config_waitfor_gpll_lock
    config_check_xfi_filt_lock config_check_mr_filt_lock
    config_check_sonet_framing_10g
    config_remove_soft_resets config_remove_soft_resets_n40g config_remove_soft_resets_n10g config_remove_soft_resets_pp10g
    autoconfig_fracdiv autoconfig_silab config_cupll config_silab config_sfi42_10g_new
    combine_signal_type_and_fec
    config_pti_10g wait_enter_key
    syncdsync_rx_cfg syncdsync_tx_cfg _floor syncdsync_config_1_to_1_params ten_hl_config_syncdsync
    get_syncdsync_params get_line_client_params get_syncdsync_muxponder_method
    config_release_reset_trans40_wire40 config_release_reset_lb40_kpga40 config_release_reset_lb10_kpga10
    config_release_reset_hsif_kpga40 config_release_reset_hsif_kpga10 config_release_reset_traffic
    config_crosspoint config_release_reset_otu3v_odtu_otu3v config_init_cupll_silabs_initialized
    );
#     config_10ge_pbert

use config_clocks;
use clocks;
use check;
use syncdsync;

my $cupll_silabs_initialized;

sub config_init_cupll_silabs_initialized {
  $cupll_silabs_initialized = 0;
}

sub config_get_port0_sfi4_1_ufec_alloc_status {
    my($module, $slice, $rate, $interface, $fec)=@_;

    my $ufec_in_use = 0;
    my $fec_type = 0;
    my $rev_id;
    my $dev_id;

    $dev_id = main::TEN_MOD_ID_TO_DEV_ID($module);

    if($rev_id = main::ten_mpif_get_chip_rev_id($dev_id) == 1) {
        if ($slice == 0) {
            if($interface == main::TEN_HSIF_PROTOCOL_SFI41) {
                if(($fec != main::TEN_FEC_MODE_GFEC) &&  ($fec != main::TEN_FEC_MODE_ZEROFEC) && ($fec != main::TEN_FEC_MODE_NOFEC)) {
                    if ($rate == 10) {
                        $fec_type = main::TEN_FEC_UFEC_10G;
                    }
                    elsif ($rate == 40) {
                        $fec_type = main::TEN_FEC_UFEC_40G;
                    }

                    $ufec_in_use = main::ten_hl_get_fec_usage_status($module, $slice, $fec_type);
                }
            }
        }
    }
    return $ufec_in_use;
}

##############################################################################
# Clock configuration functions
# Clocks, GPLLs, Fractional Dividers, and Syncdsync
##############################################################################

##############################################################################
# Function:     combine_signal_type_and_fec
#               Generate the hash to access parameters from clocks.pm
##############################################################################
sub combine_signal_type_and_fec {
    my ($signal_type, $fec) = @_;
    my $r = $signal_type;

    print("signal_type = $signal_type\n");
    print("fec         = $fec\n");

    if ($signal_type eq 'oc192_otu2') {
        # Need the speed of the final container
        $signal_type = 'otu2';
    }
    elsif ($signal_type eq 'oc768_otu3') {
        # Need the speed of the final container
        $signal_type = 'otu3';
    }
    $fec = 'nofec' if $fec eq 'deallocate';

    if ($signal_type eq 'otu2') {
      if ($fec eq 'nofec') { $r = 'odu2'; }
      elsif (($fec eq 'ufec7p') || ($fec eq 'ufec7p_sdha') || ($fec eq 'gfec') || ($fec eq '0fec')) { $r = 'otu2'; }
      elsif ($fec eq 'ufec10p') { $r = 'otu2v262'; }
      elsif ($fec eq 'ufec12p') { $r = 'otu2v267'; }
      elsif ($fec eq 'ufec13p') { $r = 'otu2v270'; }
      elsif ($fec eq 'ufec15p') { $r = 'otu2v273'; }
      elsif ($fec eq 'ufec20p') { $r = 'otu2v285'; }
      elsif ($fec eq 'ufec25p') { $r = 'otu2v297'; }
      elsif ($fec eq 'ufec26p') { $r = 'otu2v301'; }
    }
  elsif($signal_type eq 'cbr_1118099736') {
        $r = 'cbr_1118099736';
  }
  elsif($signal_type eq 'cbr_1052329163') {
        $r = 'cbr_1052329163';
  }
    elsif ($signal_type eq 'otu2e') {
      if ($fec eq 'nofec') { $r = 'odu2e10ge'; }
      elsif (($fec eq 'ufec7p') || ($fec eq 'gfec') || ($fec eq '0fec')) { $r = 'otu210geopu2e'; }
      elsif ($fec eq 'ufec10p') { $r = 'otu2v26210ge2e'; }
      elsif ($fec eq 'ufec12p') { $r = 'otu2v26710ge2e'; }
      elsif ($fec eq 'ufec13p') { $r = 'otu2v27010ge2e'; }
      elsif ($fec eq 'ufec15p') { $r = 'otu2v27310ge2e'; }
      elsif ($fec eq 'ufec20p') { $r = 'otu2v28510ge2e'; }
      elsif ($fec eq 'ufec25p') { $r = 'otu2v29710ge2e'; }
      elsif ($fec eq 'ufec26p') { $r = 'otu2v30110ge2e'; }
    }
    elsif ($signal_type eq 'otu1e') {
      if ($fec eq 'nofec') { $r = 'odu1e10ge'; }
      elsif (($fec eq 'ufec7p') || ($fec eq 'gfec') || ($fec eq '0fec')) { $r = 'otu210geopu1e'; }
      elsif ($fec eq 'ufec10p') { $r = 'otu2v26210ge1e'; }
      elsif ($fec eq 'ufec12p') { $r = 'otu2v26710ge1e'; }
      elsif ($fec eq 'ufec13p') { $r = 'otu2v27010ge1e'; }
      elsif ($fec eq 'ufec15p') { $r = 'otu2v27310ge1e'; }
      elsif ($fec eq 'ufec20p') { $r = 'otu2v28510ge1e'; }
      elsif ($fec eq 'ufec25p') { $r = 'otu2v29710ge1e'; }
      elsif ($fec eq 'ufec26p') { $r = 'otu2v30110ge1e'; }
    }
    elsif ($signal_type eq 'otu1f') {
      if($fec eq 'nofec') { $r = 'odu1e10fc'; }
      elsif (($fec eq 'ufec7p') || ($fec eq 'gfec') || ($fec eq '0fec')) { $r = 'otu210gfcopu1e'; }
      elsif ($fec eq 'ufec10p') { $r = 'otu2v26210gfc1e'; }
      elsif ($fec eq 'ufec12p') { $r = 'otu2v26710gfc1e'; }
      elsif ($fec eq 'ufec13p') { $r = 'otu2v27010gfc1e'; }
      elsif ($fec eq 'ufec15p') { $r = 'otu2v27310gfc1e'; }
      elsif ($fec eq 'ufec20p') { $r = 'otu2v28510gfc1e'; }
      elsif ($fec eq 'ufec25p') { $r = 'otu2v29710gfc1e'; }
      elsif ($fec eq 'ufec26p') { $r = 'otu2v30110gfc1e'; }
    }
    elsif ($signal_type eq 'otu3') {
      if($fec eq 'nofec') { $r = 'odu3'; }
      elsif (($fec eq 'ufec7p') || ($fec eq 'gfec') || ($fec eq '0fec')) { $r = 'otu3'; }
      elsif ($fec eq 'ufec10p') { $r = 'otu3v262'; }
      elsif ($fec eq 'ufec12p') { $r = 'otu3v267'; }
      elsif ($fec eq 'ufec13p') { $r = 'otu3v270'; }
      elsif ($fec eq 'ufec15p') { $r = 'otu3v273'; }
      elsif ($fec eq 'ufec20p') { $r = 'otu3v285'; }
      elsif ($fec eq 'ufec25p') { $r = 'otu3v297'; }
      elsif ($fec eq 'ufec26p') { $r = 'otu3v301'; }
    }
    elsif (($signal_type eq 'otu3e') || ($signal_type eq 'otu3e1')) {
      if($fec eq 'nofec') { $r = 'odu34x10ge'; }
      elsif (($fec eq 'ufec7p') || ($fec eq 'gfec') || ($fec eq '0fec')) { $r = 'otu34x10ge'; }
      elsif ($fec eq 'ufec10p') { $r = 'otu3v2624x10ge'; }
      elsif ($fec eq 'ufec12p') { $r = 'otu3v2674x10ge'; }
      elsif ($fec eq 'ufec13p') { $r = 'otu3v2704x10ge'; }
      elsif ($fec eq 'ufec15p') { $r = 'otu3v2734x10ge'; }
      elsif ($fec eq 'ufec20p') { $r = 'otu3v2854x10ge'; }
      elsif ($fec eq 'ufec25p') { $r = 'otu3v2974x10ge'; }
      elsif ($fec eq 'ufec26p') { $r = 'otu3v3014x10ge'; }
      elsif ($fec eq 'ufec18p') { $r = 'otu3v2804x10ge'; }
      elsif ($fec eq 'ufec25p_295') { $r = 'otu3v2954x10ge'; }
    }
    elsif ($signal_type eq 'otu3e2') {
      if($fec eq 'nofec') { $r = 'odu3e2'; }
      elsif (($fec eq 'ufec7p') || ($fec eq 'gfec') || ($fec eq '0fec')) { $r = 'otu3e2'; }
      elsif ($fec eq 'ufec10p') { $r = 'otu3e2v262'; }
      elsif ($fec eq 'ufec12p') { $r = 'otu3e2v267'; }
      elsif ($fec eq 'ufec13p') { $r = 'otu3e2v270'; }
      elsif ($fec eq 'ufec15p') { $r = 'otu3e2v273'; }
      elsif ($fec eq 'ufec20p') { $r = 'otu3e2v285'; }
      elsif ($fec eq 'ufec25p') { $r = 'otu3e2v297'; }
      elsif ($fec eq 'ufec26p') { $r = 'otu3e2v301'; }
      elsif ($fec eq 'ufec18p') { $r = 'otu3e2v280'; }
      elsif ($fec eq 'ufec25p_295') { $r = 'otu3e2v295'; }
    }
    elsif ($signal_type eq 'otu3e3') {
      if (($fec eq 'ufec7p') || ($fec eq 'gfec') || ($fec eq '0fec')) { $r = 'otu3e3'; }
    }
    # Bugzilla 28237 Start
    elsif ($signal_type eq 'otu3e4') {
      if($fec eq 'nofec') { $r = 'odu3e4'; }
      elsif (($fec eq 'ufec7p') || ($fec eq 'gfec') || ($fec eq '0fec')) { $r = 'otu3e4'; }
      elsif ($fec eq 'ufec10p') { $r = 'otu3e4v262'; }
      elsif ($fec eq 'ufec12p') { $r = 'otu3e4v267'; }
      elsif ($fec eq 'ufec13p') { $r = 'otu3e4v270'; }
      elsif ($fec eq 'ufec15p') { $r = 'otu3e4v273'; }
      elsif ($fec eq 'ufec20p') { $r = 'otu3e4v285'; }
      elsif ($fec eq 'ufec25p') { $r = 'otu3e4v297'; }
      elsif ($fec eq 'ufec26p') { $r = 'otu3e4v301'; }
    }
    # Bugzilla 28237 End
    elsif ($signal_type eq 'otu3+') {
      if($fec eq 'nofec') { $r = 'odu3plus'; }
      elsif (($fec eq 'ufec7p') || ($fec eq 'gfec') || ($fec eq '0fec')) { $r = 'otu3plus'; }
    }
    elsif ($signal_type eq 'otu3p2') {
      if($fec eq 'nofec') { $r = 'odu3p2'; }
    }
    elsif ($signal_type eq 'otu3') {
      $r = 'otu3';
    }
    elsif ($signal_type eq 'oc768') {
      $r = 'oc768';
    }
    elsif ($signal_type eq  '40gelan') {
      $r = '40gelan';
    }
    elsif (($signal_type eq '40gep') or ($signal_type eq '40gep_ra')) {
      $r = '40gelan';
    }
    elsif (($signal_type eq '40gesbi') or ($signal_type eq '40gesbi_ra')) {
      $r = '40gelan';
    }
     elsif (($signal_type eq '40ges6466') or ($signal_type eq '40ges6466_ra')) {
      $r = '40gelan';
    }
     elsif (($signal_type eq  '40gex') or ($signal_type eq  '40gex_ra')) {
      $r = '40ge_tc';
    }
    elsif ($signal_type eq  '40ge_tc') {
      $r = '40ge_tc';
    }
    elsif (($signal_type eq '10ge') || ($signal_type eq '10ge6_1') ||
           ($signal_type eq '10ge6_2') || ($signal_type eq '10ge7_1') ||
           ($signal_type eq '10ge7_2') ||($signal_type eq '10ge7_3') ||
           ($signal_type eq '10ge_gfpf') ||  # Bugzilla 29991
           ($signal_type eq '10ge_gfpf_oc192_odu2') || ($signal_type eq '10ge_ra') ||
           ($signal_type eq '10ge_tc') || ($signal_type =~ /pbert_10ge/)) {
      $r = '10gelan';
    }
    elsif ($signal_type eq '10gelanxaui') {
      $r = '10gelanxaui';
    }
    # 1ge uses an 8x refclk to keep the FracDivs up in a usable range
    elsif ($signal_type eq '1ge') { # Bugzilla 38871
      $r = '1ge_8x1_25';
    }
    # 1GFC, 2GFC (and 2GISC), and 4GFC use the same refclk, fracdivs, etc as 8GFC and divide down the clock at the HSIF
    elsif (($signal_type =~ /8gfc/) ||
           ($signal_type =~ /4gfc/) ||
           ($signal_type =~ /2gfc/) ||
           ($signal_type =~ /1gfc/) ||
           ($signal_type =~ /2gisc/)) {
      $r = 'fc800';
    }
    elsif (($signal_type =~ /10gfc_tc/) || ($signal_type eq '10gfc') || ($signal_type eq 'pbert_10gfc')) { # Bug 31054
      $r = 'fc1200';
    }
    elsif (($signal_type eq 'oc192') || ($signal_type eq 'oc192_async'))  {
      $r = 'oc192';
    }
    elsif ($signal_type eq 'cbr40g50188149150') {
      $r = $signal_type;
    }
    elsif ($signal_type eq '2_5g_iba') {
      $r = 'iba10g';
    }
    elsif ($signal_type eq '5g_iba') {
      $r = 'iba10g';
    }
    elsif ($signal_type eq '10g_iba') {
      $r = 'iba10g';
    }
    elsif ($signal_type eq 'fdr10_iba') { # Bugzilla 39242
      $r = '10gelan';
    }
    elsif ($signal_type eq 'null') {
    }
    elsif ($signal_type eq 'invalid') {
      $r = 'invalid';
    }
    else {
      print("combine_signal_type_and_fec()  signal_type $signal_type with fec $fec is an invalid combination\n");
      die;
    }
    print("combine_signal_type_and_fec = $r\n");
    return $r;
}

##############################################################################
# Function:     display_fracidv_settings
##############################################################################
sub display_fracidv_settings {
    my ($module, $ch, $dir, $frac_index, $bps, $lane_rate, $clk_rate)=@_;

    print("*********************************************\n");
    print("*********************************************\n");
    if($dir == 0) {
        print("AUTO PROGRAMMING RX FRAC DIV ($frac_index) for module $module channel $ch\n");
    }
    else {
        print("AUTO PROGRAMMING TX FRAC DIV ($frac_index) for module $module channel $ch\n");
    }
    print("*********************************************\n");
    print("Signal Rate  :   $bps\n");
    if($dir == 0) {
        print("Per Lane Rate: $lane_rate\n");
    }
    print("Frac Div Rate: $clk_rate\n");
    print("*********************************************\n");
    print("*********************************************\n");
}

##############################################################################
# Function:     autoconfig_fracdiv
#               Program the fractional divider
#
# Parameters:
#   module_id
#   slice
#   direction       int - which fractional dividers will be configured
#                     0 - RX (pilot)
#                     1 - TX (protection)
#                     2 - RX & TX
#   mode            int - operation mode of the device
#                     TEN_GLOBAL_MODE_S_40G - 40G
#                     TEN_GLOBAL_MODE_QUAD_10G - 10G
#   signal_type     string - describes the client traffic
#                     oc192
#                     10ge6_1
#                     10ge6_2
#                     10ge7_1
#                     10ge7_2
#                     10ge7_3
#                     10ge_gfpf_oc192_odu2
#                     otu2
#   interface_type    string - sfi5_1, sfi4_2_40g, sfi4_2_10g, xfi
#   k                 int - syncdsync divider value
#   sys_clk           int - System Reference Clock in Hz. See %sysclocks in
#                           config_clocks.pm for supported clocks
#   mux_mode          str - Mode of operation
#                           mux, trans
#   mld_enable        int - Enable MLD
#
# Returns:      Nothing
##############################################################################
sub autoconfig_fracdiv {
  my ($module, $ch, $direction, $mode, $signal_type, $interface_type, $k_divider, $sys_clk, $mux_mode, $mld_enable, $is_dual_mux)=@_;

  my $dev_id = $module >> 8;    # Bugzilla 19905
  my $mod_num = $module & 0xFF;    # Bugzilla 19905

  my $frac_index;
  my $dwidth_scale;
  my $bps;
  my $lane_rate;
  my $clk_rate;
  my $serial_lanes;
  my $rdiv_divider;

  print("*********************************************\n");
  print("autoconfig_fracdiv\n");
  print("    module         : $module\n");
  print("    ch             : $ch\n");
  print("    direction      : $direction\n");
  print("    mode           : $mode\n");
  print("    signal_type    : $signal_type\n");
  print("    interface_type : $interface_type\n");
  print("    k_divider      : $k_divider\n");
  print("    sys_clk        : $sys_clk\n");
  print("    mld_enable     : $mld_enable\n");
  print("    mux_mode       : $mux_mode\n");
#  print("    is_dual_mux    : $is_dual_mux\n");
  print("*********************************************\n");

#   $signal_type = '10gelan' if $signal_type =~ /10ge/;

  # AUTO PROGRAMMING RX FRAC DIV
  if(($direction == 0) || ($direction == 2)) { # RX FRAC DIV for Pilot clock
    $frac_index = (($module & 1) == main::TEN_MODULE_A) ? $ch : $ch+4;   # Bugzilla 30856
    $serial_lanes = ($mode  == main::TEN_GLOBAL_MODE_S_40G) ? 16 : 4;

    if($interface_type eq 'xaui') {
      $dwidth_scale = 10;
      $signal_type='10gelanxaui';
    }
    elsif(($interface_type eq 'sfi4_2') || ($interface_type eq 'sfi4_2_40g') || ($interface_type eq 'sfi4_2_10g')) {
      $dwidth_scale = 64;
    }
    else {
      $dwidth_scale = 8;
    }

    $bps = clocks_get_bps($signal_type);
    if($mld_enable) {
        $bps = $bps/4;
        $lane_rate = $bps / 4;
    }
    else {
        $lane_rate = $bps / $serial_lanes;
    }
    $clk_rate  = int($lane_rate/$dwidth_scale);

    if (($interface_type eq 'sfi5_1') || ($interface_type eq 'sfi4_2_40g')) {
      # 40G non MLD
      for(my $i=0; $i<4; $i++) {
        if($frac_index < 4) {
          # Side A
          display_fracidv_settings($module, $i, 0, $i, $bps, $lane_rate, $clk_rate);
          main::ten_hl_fracdiv_config($dev_id, $i, $sys_clk, $clk_rate);
        }
        else {
          #Side B
          display_fracidv_settings($module, $i, 0, 4+$i, $bps, $lane_rate, $clk_rate);
          main::ten_hl_fracdiv_config($dev_id, 4+$i, $sys_clk, $clk_rate);
        }
      }
    }
    else {
      if($mld_enable) {
        # 40G MLD
        if($frac_index < 4) {
          # Must be MR CFP on side A.  Side A does not support XFI CFP  Instance 4 is the master
          for(my $i=0; $i<4; $i++) {
            display_fracidv_settings($module, $i, 0, $i, $bps, $lane_rate, $clk_rate);
            main::ten_hl_fracdiv_config($dev_id, $i, $sys_clk, $clk_rate);
          }
        } else {
          # Side B
          if ($interface_type eq 'cfp_mr') {
            # MR CFP  Instance 4 is the master
            for(my $i=4; $i<8; $i++) {
              display_fracidv_settings($module, $i-4, 0, $i, $bps, $lane_rate, $clk_rate);
              main::ten_hl_fracdiv_config($dev_id, $i, $sys_clk, $clk_rate);
            }
          } else {
            # XFI CFP  Instance 6 is the master
            display_fracidv_settings($module, 2, 0, 6, $bps, $lane_rate, $clk_rate);
            main::ten_hl_fracdiv_config($dev_id, 6, $sys_clk, $clk_rate);
            display_fracidv_settings($module, 3, 0, 7, $bps, $lane_rate, $clk_rate);
            main::ten_hl_fracdiv_config($dev_id, 7, $sys_clk, $clk_rate);
            display_fracidv_settings($module, 0, 0, 4, $bps, $lane_rate, $clk_rate);
            main::ten_hl_fracdiv_config($dev_id, 4, $sys_clk, $clk_rate);
            display_fracidv_settings($module, 1, 0, 5, $bps, $lane_rate, $clk_rate);
            main::ten_hl_fracdiv_config($dev_id, 5, $sys_clk, $clk_rate);
          }
        }
      }
      else {
        # Must be 10G
        display_fracidv_settings($module, $ch, 0, $frac_index, $bps, $lane_rate, $clk_rate);
        main::ten_hl_fracdiv_config($dev_id, $frac_index, $sys_clk, $clk_rate);
      }
    }
  }



  # AUTO PROGRAMMING TX FRAC DIV
  if(($direction == 1) || ($direction == 2)) { # TX FRAC DIV
    $frac_index = (($module & 1) == main::TEN_MODULE_A) ? $ch+8 : $ch+12;   # Bugzilla 30856
    $rdiv_divider = ($mode == main::TEN_GLOBAL_MODE_QUAD_10G) ? 16*$k_divider : 64*$k_divider;

    if($mux_mode eq 'mux') {
      $bps = clocks_get_bps($signal_type);  # Bugzilla 30823
      $clk_rate  = int($bps/(64*16));
    }
    else {
      # Bugzilla 30823 Start
      if ( $signal_type eq '40gex') {
          $signal_type = '40ge_tc';    # 40117187500 Convert to string know by clock_get_bps
      }
      elsif ($signal_type =~ /40ge/) {
          $signal_type = '40gelan';    # 41250000000 Convert to string know by clock_get_bps
      }
      # Bugzilla 30823 End
      $bps = clocks_get_bps($signal_type);

      if($mld_enable) {
          $bps = $bps/4;
          $clk_rate  = int($bps/(16*$k_divider));
      }
      else {
        $clk_rate  = int($bps/$rdiv_divider);
      }
      if($interface_type eq 'xaui') {
        if ($signal_type =~ /10ge/) {
          $clk_rate = int(12500000000*8/(10*$rdiv_divider));
        }
        else {
          $clk_rate = int($bps*8/(10*$rdiv_divider));
        }
      }
    }

    if (($interface_type eq 'sfi5_1') or ($interface_type eq 'sfi4_2_40g')) {
      # 40G non MLD
      # Bugzilla 30823 Start
      if ($is_dual_mux) {
        for( my $i=0; $i<4; $i++) {
          if($frac_index < 12) {
            # Side A
            display_fracidv_settings($module, $i, 1, 8+$i, $bps, $lane_rate, $clk_rate);
            main::ten_hl_fracdiv_config($dev_id, 8+$i, $sys_clk, $clk_rate);
          }
          else {
            # Side B
            display_fracidv_settings($module, $i, 1, 12+$i, $bps, $lane_rate, $clk_rate);
            main::ten_hl_fracdiv_config($dev_id, 12+$i, $sys_clk, $clk_rate);
          }
        }
      } else {
        if ($frac_index < 12) {
          # Side A
          display_fracidv_settings($module, $ch, 1, 8+$ch, $bps, $lane_rate, $clk_rate);
          main::ten_hl_fracdiv_config($dev_id, 8+$ch, $sys_clk, $clk_rate);
        }
        else {
          # Side B
          display_fracidv_settings($module, $ch, 1, 12+$ch, $bps, $lane_rate, $clk_rate);
          main::ten_hl_fracdiv_config($dev_id, 12+$ch, $sys_clk, $clk_rate);
        }
      }
      # Bugzilla 30823 End
    }
    else {
      if($mld_enable) {
        # 40G MLD
        for( my $i=0; $i<4; $i++) {
          if($frac_index < 12) {
            # Side A
            display_fracidv_settings($module, $i, 1, 8+$i, $bps, $lane_rate, $clk_rate);
            main::ten_hl_fracdiv_config($dev_id, 8+$i, $sys_clk, $clk_rate);
          }
          else {
            # Side B
            display_fracidv_settings($module, $i, 1, 12+$i, $bps, $lane_rate, $clk_rate);
            main::ten_hl_fracdiv_config($dev_id, 12+$i, $sys_clk, $clk_rate);
          }
        }
      }
      else {
        # Must be 10G
        display_fracidv_settings($module, $ch, 1, $frac_index, $bps, $lane_rate, $clk_rate);
        main::ten_hl_fracdiv_config($dev_id, $frac_index, $sys_clk, $clk_rate);
      }
    }

    # Force FRAC_DIV provide clock to RXDIV
    # Bugzilla 30140 Start
    if (($interface_type eq 'xfi') && ($mld_enable)) {
      main::ten_mpif_set_clock_switch_force($dev_id, $mod_num, 2, main::CS_TX, main::CS_ENABLE);
    }
     # Bugzilla 30140 End
    main::ten_mpif_set_clock_switch_force($dev_id, $mod_num, $ch, main::CS_TX, main::CS_ENABLE);
  }
}

###############################################################################
# Function:      config_crosspoint
#               crosspoint configuration for CEB only
#
# Parameters:
#   clock_card,                           int  - 0 = for side A, 1 = for XFI, 2 = for MRB
#   clock_ch,                             int - 0 - 3
#   side for RXDIV                        int - 0=side A,1=side B
#
# Returns:      Nothing
###############################################################################
sub config_crosspoint {
  my ($clock_card, $clock_ch, $side) = @_;
  print("config_crosspoint()  clock_card=$clock_card, clock_ch=$clock_ch, side=$side\n");

  if (main::t40fpga_crosspoint(432,$clock_ch,$clock_card,$side) ==main::CS_ERROR) {
    die("t40fpga_crosspoint failed\n");
  }

  if (main::t40fpga_crosspoint(432,$clock_ch+4,$clock_card,$side)==main::CS_ERROR) {
    die("t40fpga_crosspoint failed\n");
  }
}


# Function:      config_silab
#               Silab configuration
#
# Parameters:
#   client_module, line_module           int - 0 = MODULE_A, 1 = MODULE_B
#   client_ch, $line_ch                  int -0 - 3
#   client_type                          string -oc192, otu2, otu210geopu2e(otu2e), 10gelan, fc800(8gfc),
#                                                fc1200(10gfc), otu210gfcopu1e(otu1f)
#   line_type                                    otu2, otu210geopu2e(otu2e,) otu210gfcopu1e(otu1f)
#   k_divider                            int - 1 - 128
#   client_interface                     string - SFI41, XAUI , SFI42_10G, SFI42_40G, SFI51_40G, XFI
#   line_interface                                SFI41, XAUI , SFI42_10G, SFI42_40G, SFI51_40G
#   client_mode, line_mode               int - 0 = S_40G, 1 = QUAD_10G
#   sync                                 int - 0 = ASYNC, 1 = SYNC
#   dyn_repro                            int - 0 = Initial config, 1 = Dynamic reprovision
#   mode                                 string - mux, trans10, trans40, lb10, lb40, kpga10, kpga40, pbert10
#   line_fec, client_fec                 string - nofec, 0fec, gfec, ufec7p, ufec10p, ufec12p, ufec13p, ufec15p,
#                                                 ufec20p, ufec25p, ufec26p, ufec7p_sdha
#
# Returns:      Nothing
###############################################################################
sub config_silab {
  my ($dev_id, $line_module, $line_ch, $client_module, $client_ch,
      $line_type, $client_type,
      $line_interface, $client_interface,
      $k_divider, $line_mode, $client_mode, $sync, $dyn_repro, $mode,
      $line_fec, $client_fec, $line_cupll, $client_cupll,
      $map_oxuv_enum, $map_odtu_enum) = @_;  # Bugzilla 28006

  print "config_silab()\n";
  #print "line_module: $line_module";
  print "    line Interface:$line_interface\n";
  print "    line mode:$line_mode\n";
  print "    client mode:$client_mode\n";

  # config the crossbar switch for RXDIV/TXDIV for T41 customer EVB
  my $board_type = main::t40fpga_get_board_type($FPGA_SYS_ID);
  # T41 CEB
  if ($board_type==8) {

    if($line_type ne 'invalid') {
      if ($line_module==0) {
        print "Crossbar #1:  ";
        config_crosspoint(0,$line_ch,0);
      }
    }

    if($client_type ne 'invalid') {
      if ($client_module==0) {
        print "Crossbar #2:  ";
        config_crosspoint(0,$client_ch,0);
      }
    }

    if ($line_interface eq 'xfi') {
      print "Crossbar #3:  ";
      config_crosspoint(1,$line_ch,1);
           if ($line_mode==0) {
        print "Crossbar #4:  ";
             config_crosspoint(1,2,1);
           }
    }
    
    if ($client_interface eq 'xfi') {
      print"Crossbar #5:  ";
      config_crosspoint(1,$client_ch,1);
           if ($client_mode==0) {
        print "Crossbar #6:  ";
             config_crosspoint(1,2,1);
           }
    }

    if($line_type ne 'invalid') {
      if (($line_module == 1) && ($line_interface ne 'xfi')) {
        if($client_interface eq 'xfi') {
          print "Crossbar #7:  ";
          config_crosspoint(2,$line_ch,0);
        } 
        else {
          print "Crossbar #8:  ";
          config_crosspoint(2,$line_ch,1);
        }
      } 
    }
    
    if($client_type ne 'invalid') {
      if (($client_module == 1) && ($client_interface ne 'xfi')) {
        if($line_interface eq 'xfi') {
          print "Crossbar #9:  ";
          config_crosspoint(2,$client_ch,0);
        } else {
          print "Crossbar #10:  ";
          config_crosspoint(2,$client_ch,1);
        }
      }
    }
    
    if ($line_type ne 'invalid') {
      if ( ($line_module == 1) and ($line_interface eq 'cfp_mr') and ($client_interface eq 'xfi')) {
        print "Crossbar #15:  ";
          config_crosspoint(2,2,0);
      } 
      elsif ( ($line_module == 1) and ($line_interface eq 'cfp_mr') and ($client_interface ne 'xfi')) {
        print "Crossbar #16:  ";
          config_crosspoint(2,2,1);
        }
        }
      
    if ($client_type ne 'invalid') {
      if (($client_module == 1) && ($client_interface eq 'cfp_mr') and ($line_interface eq 'xfi')) {
          print "Crossbar #17:  ";
          config_crosspoint(2,2,0);
      } 
      elsif (($client_module == 1) && ($client_interface eq 'cfp_mr') and ($line_interface ne 'xfi')) {
        print "Crossbar #18:  ";
        config_crosspoint(2,2,1);
      }
    }

    # For the CEB-based muxponder
    my $t100 = check_t100_option();
    print "\n\nt100 = $t100\n";
    if ($t100 == 1) {
      my $tmp=main::dev_reg_read(432,0,0x6000);
      printf ("tmp: 0x%02X\n", $tmp);
      main::dev_reg_write(432,0,0x6000,0x30|$tmp);
      sleep 2;
    }
  }
  
  # T41 SP; Clock A is used for the CFP_MR interface on Side B
  elsif ($board_type == 9) {
    if ($line_interface eq 'cfp_mr') {
      $line_module = 0;
    }
    if ($client_interface eq 'cfp_mr') {
      $client_module = 0;
    }
  }
  print("************** config_silab **************\n");
  #print("line_module =     = $line_module\n");
  print("    line_ch           = $line_ch\n");
  #print("client_module     = $client_module\n");
  print("    client_ch         = $client_ch\n");
  print("    line_type         = $line_type\n");
  print("    client_type       = $client_type\n");
  print("    line_interface    = $line_interface\n");
  print("    client_interface  = $client_interface\n");
  print("    k_divider         = $k_divider\n");
  print("    line_mode         = $line_mode\n");
  print("    client_mode       = $client_mode\n");
  print("    sync              = $sync\n");
  print("    dyn_repro         = $dyn_repro\n");
  #print("    aggregation       = $aggregation\n");
  print("    mode              = $mode\n");
  print("    line_cupll        = $line_cupll\n");
  print("    client_cupll      = $client_cupll\n");

  # Override passed-in k_divider and fixed 64 k divider for line and/or client if using cleanup PLL
  my $_line_kdiv      = ($line_cupll)   ? $line_cupllProfileCB{cupllSysClkFreq}   : $k_divider;
  my $_client_kdiv    = ($client_cupll) ? $client_cupllProfileCB{cupllSysClkFreq} : $k_divider;
  my $_line_fx_kdiv   = ($line_cupll)   ? $line_cupllProfileCB{cupllSysClkFreq}   : 64;
# my $_client_fx_kdiv = ($client_cupll) ? $client_cupllProfileCB{cupllSysClkFreq} : 64;

  #my $chipid=main::ten_reg_read(0,0);
  my $chipid=main::ten_mpif_get_chip_jtag_id($dev_id);

  # Bugzilla #32626
  # For CUPLL, only configure SiLabs on initial configurations
  my $line_cupll_dr = $line_cupll;
  my $client_cupll_dr = $client_cupll;

  #printf("before cupll_silabs_initialized=%04X\n", $cupll_silabs_initialized);

  if ($line_module ne 'invalid') {
    if ($line_cupll) {
      if ($line_interface eq 'xfi') {
         if ($dyn_repro != 0) {
           if  ($cupll_silabs_initialized & (1<<(($line_module*4)+$line_ch))) {
             # (-1) do *not* config silabs since this is:  XFI, CUPLL, dynamic reconfig and silabs already configured.
             $line_cupll_dr = -1;
           }
         }
         $cupll_silabs_initialized |= 1<<(($line_module*4)+$line_ch);
      }
    }
    else {
      $cupll_silabs_initialized &= ~(1<<(($line_module*4)+$line_ch));
    }
  }

  if ($client_module ne 'invalid') {
    if ($client_cupll) {
      if ($client_interface eq 'xfi') {
         if ($dyn_repro != 0) {
           if  ($cupll_silabs_initialized & (1<<(($client_module*4)+$client_ch))) {
             # (-1) do *not* config silabs since this is:  XFI, CUPLL, dynamic reconfig and silabs already configured.
             $client_cupll_dr = -1;
           }
         }
         $cupll_silabs_initialized |= 1<<(($client_module*4)+$client_ch);
      }
    }
    else {
      $cupll_silabs_initialized &= ~(1<<(($client_module*4)+$client_ch));
    }
  }

  #printf("after cupll_silabs_initialized=%04X\n", $cupll_silabs_initialized);
  #printf("dyn=%d, line_cupll_dr=%d\n", $dyn_repro, $line_cupll_dr);
  #printf("dyn=%d, client_cupll_dr=%d\n", $dyn_repro, $client_cupll_dr);

  if ((($chipid & 0xf000) == 0x4000) ||
      (($chipid & 0xf000) == 0xA000)) {
    if (($client_interface ne 'xfi') && ($sync==0)) {
      $client_module &= 0xFFFE;
      print("override client_module=$client_module\n");
    }
    if (($line_interface ne 'xfi') && ($sync==0)){
      $line_module &= 0xFFFE;
      print("override line_module=$line_module\n");
    }

    if ($sync==1) {
      # T40FPGA (sys_id=432) write 
      main::dev_reg_write( sys_id=>432, stride_id=>0, reg_offset=>0x4400, data=>5 );
    }

  }
  #if($aggregation == 1) {
  if ($mode eq 'mux') {
    # Muxponder
    if($dyn_repro != 1) {
      # Bugzilla 28237/26477 Start
      if($line_interface eq 'xfi') {
        # For Line traffic
        return -1 if (autoconfig_silab($dev_id, $line_module, 2, $line_mode, -1, $line_type, $line_interface, $_line_fx_kdiv, $line_fec, $line_cupll_dr)) == -1;
      } else {

        # Added for the CEB-based muxponder
        my $t100 = check_t100_option();
        if (($board_type == 8) and ($t100 == 1)) {
          print "\n\nSiLabs modification for T41CEB muxponder\n\n";
          print "autoconfig_silab #1\n";
          return -1 if (autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, $client_ch, $line_type, $line_interface, $_line_fx_kdiv, $line_fec, $line_cupll_dr)) == -1;
        }
        else {
        print "autoconfig_silab #2\n";
        return -1 if (autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, -1, $line_type, $line_interface, $_line_fx_kdiv, $line_fec, $line_cupll_dr)) == -1;
      }

      }
      # Bugzilla 28237/26477 End
    }
    if (($client_type eq '10ge7_3') || ($client_type eq '10ge6_1') || ($client_type eq '10ge6_2') || ($client_type eq '10ge_gfpf_oc192_odu2') ||
        ($client_type eq 'pbert_8gfc') || ($client_type eq 'pbert_10gfc') || ($client_type eq '10ge_ra') || ($client_type =~ /pbert_10ge/) ||
        ($client_type eq 'pbert_4gfc') || ($client_type eq 'pbert_2gfc')) {
      # Rob: This is so the autogen process won't crap out due to unsupported mappings
      print "autoconfig_silab #3\n";
      return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
    }
    elsif ($client_type =~ /otu3/) { # Bugzilla 29100
      if($client_interface eq 'xfi') {
        print "autoconfig_silab #4\n";
        return -1 if autoconfig_silab($dev_id, $client_module, 2, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
      }
      else {
        print "autoconfig_silab #5\n";
        return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
      }
    }
    else {
      # Rob: This is so the autogen process won't crap out due to unsupported mappings
      print "autoconfig_silab #6\n";
      if ($client_type ne 'invalid') {
          return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, $line_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
      }
    }
  }
  elsif (($mode eq 'trans40') || ($mode eq 'wire40')) {
    #40G  Transponder
    if($sync == 1) {
      # Synchronous
      if($dyn_repro != 1) {
        # Bugzilla 28454 Start
        if($line_interface eq 'xfi') {
          # For Line traffic
          print "autoconfig_silab #7\n";
          return -1 if autoconfig_silab($dev_id, $line_module, 2, $line_mode, $client_ch, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
        } else {
          print "autoconfig_silab #8\n";
          return -1 if autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, $client_ch, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
        }
        # Bugzilla 28454 End
      }
      # Rob: This is so the autogen process won't crap out due to unsupported mappings
      if($client_interface eq 'xfi') {
          # For Client traffic
          print "autoconfig_silab #9\n";
          return -1 if autoconfig_silab($dev_id, $client_module, 2, $client_mode, $line_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
          # For Client KPGA-Debug only
          #return -1 if autoconfig_silab($dev_id, $client_module, 2, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec) == -1;

      }
      else {
          print "autoconfig_silab #10\n";
          return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, $line_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
      }
    }
    else {
      # Asynchronous
      if($dyn_repro != 1) {
          # Rob: This is so the autogen process won't crap out due to unsupported mappings
          # Bugzilla 28254 Start
          if($line_interface eq 'xfi') {
              print "autoconfig_silab #11\n";
              return -1 if autoconfig_silab($dev_id, $line_module, 2, $line_mode, -1, $line_type, $line_interface, $_line_fx_kdiv, $line_fec, $line_cupll_dr) == -1;
          } else {
              print "autoconfig_silab #12\n";
              return -1 if autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, -1, $line_type, $line_interface, $_line_fx_kdiv, $line_fec, $line_cupll_dr) == -1;
          }
          # Bugzilla 28254 End
      }
        # Rob: This is so the autogen process won't crap out due to unsupported mappings
        if($client_interface eq 'xfi') {
            # Bugzilla 28006 Start
            if (($map_oxuv_enum == main::TEN_MAP_BMP) || ($map_odtu_enum == main::main::TEN_MAP_DONT_CARE)) { # Bugzilla 28176
                # Client side is synchronous
                print "autoconfig_silab #13\n";
                return -1 if autoconfig_silab($dev_id, $client_module, 2, $client_mode, $line_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
            } else {
                print "autoconfig_silab #14\n";
                return -1 if autoconfig_silab($dev_id, $client_module, 2, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
            }
        }
        elsif ($client_interface eq 'cfp_mr') {
            if (($map_oxuv_enum == main::TEN_MAP_BMP) || ($map_odtu_enum == main::main::TEN_MAP_DONT_CARE)) { # Bugzilla 28176
                print "autoconfig_silab #15\n";
                return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, $line_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
            } else {
                print "autoconfig_silab #16\n";
                return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
            }
            # Bugzilla 28006 End
        }
        else {
            print "autoconfig_silab #17\n";
            return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, $line_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        }
    }
  }
  elsif (($mode eq 'trans10') || ($mode eq 'wire10')) {
    # 10G Transponder
    if($sync == 1) {
      if($dyn_repro != 1) {
          # Rob: This is so the autogen process won't crap out due to unsupported mappings
        if($line_interface eq 'sfi4_1') {
          print "autoconfig_silab #18\n";
          return -1 if autoconfig_silab($dev_id, $line_module, 0, $line_mode, $client_ch, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
        }
        elsif ($line_type ne 'invalid') {
          print "autoconfig_silab #19\n";
          return -1 if autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, $client_ch, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
        }
      }
        # Rob: This is so the autogen process won't crap out due to unsupported mappings
        if($client_interface eq 'sfi4_1') {
            print "autoconfig_silab #20\n";
            return -1 if autoconfig_silab($dev_id, $client_module, 0, $client_mode, $line_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        }
        elsif ($client_type ne 'invalid') {
          print "autoconfig_silab #21\n";
          return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, $line_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        }
    }
    else { # 10G Transponder ASYNC
      if(($line_type eq $client_type) || ($client_type eq '10ge6_1') || ($client_type eq '10ge6_2') ||
         ($client_type eq '10ge_gfpf_oc192_odu2') || ($client_type eq '10ge7_3') || ($client_type eq '10ge_ra') ||
         ($client_type eq '10gelanxaui') || ($client_type eq '10ge_gfpf') ||     # Bugzilla 29991
         ($client_type eq 'pbert_8gfc') || ($client_type =~ /gfc_ra/) || ($client_type =~ /gfc_tc_ra/) ||
         ($client_type eq 'pbert_4gfc') || ($client_type eq 'pbert_2gfc') ||
         ($client_type eq 'pbert_10gfc') || ($client_type =~ /pbert_10ge/)) {
        if($dyn_repro != 1) {
            # Rob: This is so the autogen process won't crap out due to unsupported mappings
          if($line_interface eq 'sfi4_1') {
            print "autoconfig_silab #22\n";
            return -1 if autoconfig_silab($dev_id, $line_module, 0, $line_mode, -1, $line_type, $line_interface, $_line_fx_kdiv, $line_fec, $line_cupll_dr) == -1;
          }
          elsif ($line_type ne 'invalid') {
            print "autoconfig_silab #23\n";
            return -1 if autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, -1, $line_type, $line_interface, $_line_fx_kdiv, $line_fec, $line_cupll_dr) == -1;
          }
        }
          # Rob: This is so the autogen process won't crap out due to unsupported mappings
        if($client_interface eq 'sfi4_1') {
          print "autoconfig_silab #24\n";
          return -1 if autoconfig_silab($dev_id, $client_module, 0, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        }
        elsif ($client_type ne 'invalid') {
          print "autoconfig_silab #25\n";
          return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        }
      }
      else { # $line_type != $client_type)
        if($dyn_repro != 1) {
            # Rob: This is so the autogen process won't crap out due to unsupported mappings
          if($line_interface eq 'sfi4_1') {
            print "autoconfig_silab #26\n";
            return -1 if autoconfig_silab($dev_id, $line_module, 0, $line_mode, -1, $line_type, $line_interface, $_line_fx_kdiv, $line_fec, $line_cupll_dr) == -1;
          }
          elsif ($line_type ne 'invalid') {
            print "autoconfig_silab #27\n";
            return -1 if autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, -1, $line_type, $line_interface, $_line_fx_kdiv, $line_fec, $line_cupll_dr) == -1;
          }
        }
          # Rob: This is so the autogen process won't crap out due to unsupported mappings
        if($client_interface eq 'sfi4_1') {
          print "autoconfig_silab #28\n";
          return -1 if autoconfig_silab($dev_id, $client_module, 0, $client_mode, $line_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        }
        elsif ($client_type ne 'invalid') {
          print "autoconfig_silab #29\n";
          return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, $line_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        }
      }
    }
  }
  elsif (($mode eq 'lb10') || ($mode eq 'lb40') ||
         ($mode eq 'cbr_kpga10') || ($mode eq 'cbr_kpga40') ||
         ($mode eq 'hsif_kpga10') || ($mode eq 'hsif_kpga40') ||
         ($mode eq 'kpga10') || ($mode eq 'kpga40') || ($mode eq 'pbert10')) {
    if ($mode eq 'lb10') {
      if ($line_type ne 'invalid') {
        # Must be Synchronous
        print "autoconfig_silab #30\n";
        return -1 if autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, $line_ch, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
      }
      else {
        # Must be Synchronous
        print "autoconfig_silab #31\n";
        return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, $client_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
      }
    }
    elsif ($mode eq 'lb40') {
      if ($line_type ne 'invalid') {
        # Use line side parameters.  Must be Synchronous
        if($line_interface eq 'xfi') {
          # XFI CFP
          print "autoconfig_silab #32\n";
          return -1 if autoconfig_silab($dev_id, $line_module, 2, $line_mode, $line_ch, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
        } else {
          print "autoconfig_silab #33\n";
          return -1 if autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, $line_ch, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
        }
      }
      else {
        # Use client side parameters.  Must be Synchronous
        if($client_interface eq 'xfi') {
          # XFI CFP
          print "autoconfig_silab #34\n";
          return -1 if autoconfig_silab($dev_id, $client_module, 2, $client_mode, $client_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        } else {
          print "autoconfig_silab #35\n";
          return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, $client_ch, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        }
      }
    }
    elsif (($mode eq 'kpga10') || ($mode eq 'pbert10') ||
           ($mode eq 'hsif_kpga10')|| ($mode eq 'cbr_kpga10')) {
      if ($line_type ne 'invalid') {
        # Use line side parameters.  Must be Asynchronous
        if($line_interface eq 'sfi4_1') {
            print "autoconfig_silab #36\n";
            return -1 if autoconfig_silab($dev_id, $line_module, 0, $line_mode, -1, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
        }
        else {
            print "autoconfig_silab #37\n";
            return -1 if autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, -1, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
        }
      }
      else {
        # Use client side parameters.  Must be Asynchronous
        if($client_interface eq 'sfi4_1') {
            print "autoconfig_silab #38\n";
            return -1 if autoconfig_silab($dev_id, $client_module, 0, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        }
        else {
            print "autoconfig_silab #39\n";
            if ($client_type ne 'invalid') {
                return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
            }
        }
      }
    }
    elsif (($mode eq 'kpga40')|| ($mode eq 'hsif_kpga40') || ($mode eq 'cbr_kpga40')) {
      if ($line_type ne 'invalid') {
        # Use line side parameters.  Must be Asynchronous
        if($line_interface eq 'xfi') {
          print "autoconfig_silab #40\n";
          return -1 if autoconfig_silab($dev_id, $line_module, 2, $line_mode, -1, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
        } else {
          print "autoconfig_silab #41\n";
          return -1 if autoconfig_silab($dev_id, $line_module, $line_ch, $line_mode, -1, $line_type, $line_interface, $_line_kdiv, $line_fec, $line_cupll_dr) == -1;
        }
      }
      else {
        # Use client side parameters.  Must be Asynchronous
        if($client_interface eq 'xfi') {
          print "autoconfig_silab #42\n";
          return -1 if autoconfig_silab($dev_id, $client_module, 2, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        } else {
          print "autoconfig_silab #43\n";
          return -1 if autoconfig_silab($dev_id, $client_module, $client_ch, $client_mode, -1, $client_type, $client_interface, $_client_kdiv, $client_fec, $client_cupll_dr) == -1;
        }
      }
    }

  }
  return 0;
}


###############################################################################
# Function:     config_silab_one_side
#               Silab configuration for one side only
#
# Parameters:
#   module_id               int - 0 = MODULE_A, 1 = MODULE_B
#   ch                      int - 0 - 3
#   type                    string - oc192, otu2, otu210geopu2e(otu2e), 10gelan, fc800(8gfc),
#                                    fc1200(10gfc), otu210gfcopu1e(otu1f)
#   k_divider               int - 1 - 128
#   interface               string - SFI41, XAUI , SFI42_10G, SFI42_40G, SFI51_40G
#   client_mode, line_mode  int - 0 = S_40G, 1 = QUAD_10G
#
# Returns:      Nothing
###############################################################################
#sub config_silab_one_side {
#  my ($module_id, $ch, $type, $hsif_interface,
#      $k_divider, $quad_mode, $mode,
#      $fec) = @_;
#
#  print("************** config_silab One Side **************\n");
#  print("module_id  = $module_id\n");
#  print("ch         = $ch\n");
#  print("type       = $type\n");
#  print("hsif_interface  = $hsif_interface\n");
#  print("k_divider  = $k_divider\n");
#  print("mode       = $mode\n");
#  print("mode       = $mode\n");
#
#  if (($mode eq 'lb40') || ($mode eq 'lb10')) {
#    # Must be Synchronous
#      # Rob: This is so the autogen process won't crap out due to unsupported mappings
#      return -1 if autoconfig_silab($module_id, $ch, $quad_mode, $ch, $type, $hsif_interface, $k_divider, $fec) == -1;
#  }
#  elsif (($mode eq 'kpga40') || ($mode eq 'kpga10') || ($mode eq 'pbert10') || ($mode eq 'mux') ||
#         ($mode eq 'hsif_kpga40') || ($mode eq 'hsif_kpga10')) {
#    # Must be Asynchronous
#      # Rob: This is so the autogen process won't crap out due to unsupported mappings
#      return -1 if autoconfig_silab($module_id, $ch, $quad_mode, -1, $type, $hsif_interface, 64, $fec) == -1;
#  }
#  return 0;
#}

###############################################################################
# Function:     ten_hl_config_syncdsync
#               TENABO HIGHLEVEL CONFIG SYNCDSYNC
# NOTE: Please do not remove this function. It has been ported to C but left here
#       for enabling quick debugging of new mappings
#
# Parameters:
#   client_module, line_module    int - 0 = MODULE_A, 1 = MODULE_B
#   client_ch, $line_ch           int - 0 - 3
#   client_type                   string - oc192, otu2, otu210geopu2e(otu2e), 10gelan,
#                                          fc800(8gfc), fc1200(10gfc), otu210gfcopu1e(otu1f)
#   line_type                     string - otu2, otu210geopu2e(otu2e,) otu210gfcopu1e(otu1f)
#   num_just                      int - 0 - 3 (non-aggregation); 1-12 (aggregation)
#   num_pjo                       int - 0 - 6
#   k_divider                     int - 64(async); 16 - 256(sync)
#   client_interface              string - SFI41, SFI42_10G, SFI42_40G, SFI51_40G, XAUI, XFI
#   line_interface                string - SFI41, SFI42_10G, SFI42_40G, SFI51_40G, XAUI
#   mode                          string - mux, trans10, trans40
#   sync                          int - 0 = ASYNC, 1 = SYNC
#
# Returns:      Nothing
###############################################################################
sub ten_hl_config_syncdsync {
  my ($line_module, $line_ch, $client_module, $client_ch,
      $line_type, $client_type,
      $line_interface, $client_interface,
      $k_divider, $mode, $sync,
      $line_fec, $client_fec, #$aggregation,
      $num_just_oxu2, $num_pjo_oxu2, $num_just_oxu3, $num_pjo_oxu3,
      $PLvalue, $QLvalue, $PCvalue, $QCvalue, $line_client_rate_equal,
      $trans_num, $trans_den) = @_;

  my $n1; my $n2; my $m1, my $m2;
  #my $PLvalue, my $QLvalue; my $PCvalue, my $QCvalue;
  my $num; my $denom; my $ac1=0; my $ac2=0; my $ad1=0; my $ad2=0; my $cfg=0; my $cfgpd0=0; my $jcgen=0; my $jc_thresh=0;
  my $trans_num_mult=1; my $trans_den_mult=1;

  #my $num_pjo_odu3=1;  my $num_fs_odu3=0; my $num_c15_odu3=0;  my $num_just_odu3=0;
  #my $num_pjo_odu2=1; my $num_fs_odu2=0; my $num_c15_odu2=0; my $num_just_odu2=0;
  #my $num_pjo_odtu23=1; my $num_fs_odtu23=0; my $num_c15_odtu23=0; my $num_just_odtu23=0;

  my $num_pjo_odu3=1;  my $num_just_odu3=0;
  my $num_pjo_odu2=1; my $num_just_odu2=0;
  my $num_pjo_odtu23=1; my $num_just_odtu23=0;

  my $line_identifier;
  #my $client_identifier;

  #$client_identifier = combine_signal_type_and_fec($client_type, $client_fec);
  $line_identifier  = combine_signal_type_and_fec($line_type, $line_fec);

  #print("client_identifier = $client_identifier\n");
  print("line_identifier   = $line_identifier\n");

  #$PLvalue = clocks_get_P($line_identifier);
  #$QLvalue = clocks_get_Q($line_identifier);
  #$PCvalue = clocks_get_P($client_identifier);
  #$QCvalue = clocks_get_Q($client_identifier);

#if ($line_type eq 'otu3e3') {
#    $PLvalue = 263;
#    $QLvalue = 243;
#}
#elsif (($client_type eq 'oc768') && ($line_type eq 'otu3')) {
#    $PCvalue = 236;
#    #$QCvalue = ?;
#}

  print("P Client = $PCvalue\n");
  print("Q Client = $QCvalue\n");
  print("P Line   = $PLvalue\n");
  print("Q Line   = $QLvalue\n");

  if ($sync == 0) {
    print("\n**********************\n");
    print("method         : ASYNC\n");
    print("**********************\n");
  }
  else {
    print("\n**********************\n");
    print("method         : SYNC\n");
    print("**********************\n");
  }

  print("************** calc_syncdsync_params **************\n");
  print("client module    : $client_module\n");
  print("client ch        : $client_ch\n");
  print("client interface : $client_interface\n");
  print("client type      : $client_type\n");
  print("client fec       : $client_fec\n");

  print("line module      : $line_module\n");
  print("line ch          : $line_ch\n");
  print("line interface   : $line_interface\n");
  print("line type        : $line_type\n");
  print("line fec         : $line_fec\n");

  print("mode             : mode\n");
  print("k_divider        : $k_divider\n");

  if($trans_num) {
      $trans_num_mult = $trans_num;
  }
  if($trans_den) {
      $trans_den_mult = $trans_den;
  }

  #############################
  #40G TRANSPONDER
  #############################
  if (($mode eq 'trans40') || ($mode eq 'wire40')) {
    $num_just_odu3 = $num_just_oxu3;
    $num_pjo_odu3 = $num_pjo_oxu3;
  #if((($line_type eq 'otu3') || ($line_type eq 'otu3e') || ($line_type eq 'otu3e3')) && ($aggregation == 0)) {
    #($num_pjo_odu3, $num_fs_odu3, $num_c15_odu3) = get_syncdsync_oxu3($client_type, $line_type);
    #$num_just_odu3 = $num_fs_odu3 + $num_c15_odu3;

    if(($client_type eq 'oc768') || ($client_type eq '40gelan') || ($client_type eq 'otu3') ||
#       ($client_type eq 'cbr40g41250000000') || ($client_type eq 'cbr40g39813120000') || ($client_type eq 'cbr40g50188149150')) {
       ($client_type eq 'cbr40g50188149150')) {
      if($sync == 1) { # SYNC
        if($client_type eq $line_type) {
          #if(clocks_get_bps($line_identifier) == clocks_get_bps($client_identifier)) {
          if($line_client_rate_equal) {
            #### Client channel RX 1:1 #####
            main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,$k_divider);
            main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
            print("\n");

            #### Line channel RX 1:1 #####
            main::ten_syncdsync_config_1_to_1($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_RX,$k_divider);
            main::ten_syncdsync_config_1_to_1($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_TX,$k_divider);
            print("\n");
          }
          else {
            #### Client channel RX #####
            $m1     = $PLvalue*16*4;           $n2 = 1;
            $n1     = $PCvalue*16*4;           $m2 = 1;

            $num    = $m1 * $m2;
            $denom  = $n1 * $n2 * $k_divider;
            #syncdsync_rx_cfg($client_module,$client_ch,$num,$denom,0,0,0,0,0);
            main::ten_syncdsyncrx_cfg($client_module,$client_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,0,0,0,0,0,0,0);

            #### Line channel TX rdivmux +  Silab #####
            main::ten_syncdsync_config_1_to_1($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_TX,$k_divider);

            #### Line channel RX #####
            $m1     = $PCvalue*16*4;           $n2 = 1;
            $n1     = $PLvalue*16*4;           $m2 = 1;

            $num    = $m1 * $m2;
            $denom  = $n1 * $n2 * $k_divider;
            #syncdsync_rx_cfg($line_module,$line_ch,$num,$denom,0,0,0,0,0);
            main::ten_syncdsyncrx_cfg($line_module,$line_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,0,0,0,0,0,0,0);

            #### Client channel TX :rdivmux + Silab #####
            main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
          }
        }
        else {
          # client_type != line_type

          #### Client channel RX #####
          $m1     = $PLvalue*16*4;           $n2 = 1;
          $n1     = $QLvalue*16*4;           $m2 = 1;

          $num    = $m1 * $m2;
          $denom  = $n1 * $n2 * $k_divider;
          #syncdsync_rx_cfg($client_module,$client_ch,$num,$denom,0,0,0,0,1);
          main::ten_syncdsyncrx_cfg($client_module,$client_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,0,0,0,0,0,0,1);


          # Line TX
          #syncdsync_config_1_to_1_params($line_module, 0, (($client_module & 1) * 4), main::CS_TX, $k_divider);
          main::ten_syncdsync_config_1_to_1($line_module, 0, (($client_module & 1) * 4), main::CS_TX, $k_divider);
          main::ten_syncdsynctx_set_mode($line_module, 0, 1);


          #### Line channel RX #####
          $m1     = $QLvalue*16*4;           $n2 = 1;
          $n1     = $PLvalue*16*4;           $m2 = 1;

          $num    = $m1 * $m2;
          $denom  = $n1 * $n2 * $k_divider;
          #syncdsync_rx_cfg($line_module,$line_ch,$num,$denom,0,0,0,0,1);
          main::ten_syncdsyncrx_cfg($line_module,$line_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,0,0,0,0,0,0,1);


          # Client TX
          #syncdsync_config_1_to_1_params($client_module, 0, (($line_module & 1) * 4), main::CS_TX, $k_divider);
          main::ten_syncdsync_config_1_to_1($client_module, 0, (($line_module & 1) * 4), main::CS_TX, $k_divider);
          main::ten_syncdsynctx_set_mode($client_module, 0, 1);
        }
      }
      else { # ASYNC
        # Client RX
        #syncdsync_config_1_to_1_params($client_module, 0, (($line_module & 1) * 4), main::CS_RX, $k_divider);
        main::ten_syncdsync_config_1_to_1($client_module, 0, (($line_module & 1) * 4), main::CS_RX, $k_divider);
        main::ten_syncdsyncrx_set_mode($client_module, 0, 1);

        # Line TX
        $n1     = $PLvalue*16*4;             $n2 = 1;

        #if ($line_type eq 'otu3e3') {
        #  $m1     = 243*16*4 - $num_just_odu3; $m2 = 1;
        #}
        #else {
        #  $m1     = 238*16*4 - $num_just_odu3; $m2 = 1;
        #}
        $m1     = $PCvalue*16*4 - $num_just_odu3; $m2 = 1;

        $num    = $m1 * $m2;
        $denom  = $n1 * $n2 * $k_divider;
        $ac1    = 1;                         $ac2 = $PLvalue*16;
        $ad1    = 1;                         $ad2 = 4 * $num_pjo_odu3;
        $cfg    = 0x01;  # Mode (0 OPU2, 1 OPU3, 2 ODTU23 1 level, 2 ODTU23 2 level)
        $cfgpd0 = 0x01;

        $jc_thresh = _floor((2 * $k_divider)/((2 * $num_pjo_odu3) + 1));
        $jcgen = ($jc_thresh << 3) | $num_pjo_odu3;
        #syncdsync_tx_cfg($line_module,0,(($client_module & 1) * 4), $num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg,$cfgpd0, $jcgen); # For data path
        #syncdsync_tx_cfg($line_module,3,(($client_module & 1) * 4), $num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg,$cfgpd0, $jcgen); # For SyncDsync

        main::ten_syncdsynctx_cfg($line_module,0,(($client_module & 1) * 4), $num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg,$cfgpd0,$jc_thresh,$num_pjo_odtu23);
        main::ten_syncdsynctx_cfg($line_module,3,(($client_module & 1) * 4), $num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg,$cfgpd0,$jc_thresh,$num_pjo_odtu23);

        # Line RX
        #ten_syncdsync_rx_cfg($line_module,0,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg); # For data path
        #ten_syncdsync_rx_cfg($line_module,3,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg); # For SyncDsync

        main::ten_syncdsyncrx_cfg($line_module,0,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg);
        main::ten_syncdsyncrx_cfg($line_module,3,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg);

        # Client TX
        #syncdsync_config_1_to_1_params($client_module, 0, (($line_module & 1) * 4), main::CS_TX, $k_divider);
        main::ten_syncdsync_config_1_to_1($client_module, 0, (($line_module & 1) * 4), main::CS_TX, $k_divider);
        main::ten_syncdsynctx_set_mode($client_module, 0, 1);
      }
      return;
    }
  }

  #############################
  #40G MUXPONDER
  #############################
  if ($mode eq 'mux') {
    $num_just_odtu23 = $num_just_oxu3;
    $num_pjo_odtu23 = $num_pjo_oxu3;
    $num_just_odu2 = $num_just_oxu2;
    $num_pjo_odu2 = $num_pjo_oxu2;

    print("\n");
    print("40GMUX: num_pjo_odu2    = $num_pjo_odu2\n");
    print("40GMUX: num_just_odu2   = $num_just_odu2 \n");
    print("\n");
    print("40GMUX: num_pjo_odtu23  = $num_pjo_odtu23 \n");
    print("40GMUX: num_just_odtu23 = $num_just_odtu23 \n");
    print("\n");

    ##### OC192 | 10GELAN_GSUP7.1 | 10GFC #####
    if(($client_type eq 'oc192') || ($client_type eq '10ge7_1') || ($client_type eq '10ge7_2') || ($client_type =~ /10gfc_tc/) || # Bug 31054
       ($client_type eq '8gfc_enh') || ($client_type eq 'pbert_8gfc') || ($client_type eq 'pbert_10gfc') ||
       ($client_type =~ /pbert_10ge/) || ($client_type eq 'pbert_4gfc') || ($client_type eq 'pbert_2gfc')) {
      # Client RX
      #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,$k_divider);
      main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,64);

      # Line
      #if($line_type eq 'otu3+') {
      #  $n1     = 255*16*4*4;
      #}
      #elsif (($line_identifier eq 'odu34x10ge') || ($line_identifier eq 'odu3')) {
      #    $n1     = 239*16*4*4;
      #}
      #else {
        $n1     = $PLvalue*16*4*4;
      #}

      #if($client_type eq '10gfc_tc') {
      #  $n2 = 239*16*4*50;
      #}
      #else {
      #  $n2 = 239*16*4;
      #}
      $n2 = 239*16*4*$trans_den_mult;

      $m1     = 238*16*4*4 - $num_just_odtu23;

      #if($client_type eq '10gfc_tc') {
      #  $m2 = (238*16*4-$num_just_odu2)*51;
      #}
      #else {
      #  $m2 = 238*16*4-$num_just_odu2;
      #}
      $m2 = (238*16*4-$num_just_odu2)*$trans_num_mult;

      $num    = $m1 * $m2;
      $denom  = $n1 * $n2 * 64;
      $ac1    = $n1 * $m2;                       $ac2 = $n1 * $n2;
      $ad1    = 4 * $num_pjo_odtu23 * $m2;       $ad2 = ($m1+4) * $num_pjo_odu2;
      $cfg    = 0x03;
      $cfgpd0 = 0x01;
      $jc_thresh = _floor((2 * 64)/((2 * $num_pjo_odtu23) + 1));
      $jcgen = ($jc_thresh << 3) | $num_pjo_odtu23;

      print("\n");
      printf(" n1  = 0x%x\n", $n1);
      printf(" m1  = 0x%x\n", $m1);
      printf(" n2  = 0x%x\n", $n2);
      printf(" m2  = 0x%x\n", $m2);
      printf(" den = 0x%x\n", $denom);
      printf(" num = 0x%x\n", $num);
      printf(" ac1 = 0x%x\n", $ac1);
      printf(" ac2 = 0x%x\n", $ac2);
      printf(" ad1 = 0x%x\n", $ad1);
      printf(" ad2 = 0x%x\n", $ad2);
      print("\n");

      # Line TX
      #syncdsync_tx_cfg($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg,$cfgpd0, $jcgen);
      main::ten_syncdsynctx_cfg($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch, $num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg,$cfgpd0,$jc_thresh,$num_pjo_odtu23);

      $denom  = $n1 * $n2 * $k_divider;

      # Line RX
      #syncdsync_rx_cfg($line_module,$line_ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg);
      main::ten_syncdsyncrx_cfg($line_module,$line_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg);

      # Client TX
      #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
      main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
    }
    ##### OTU2 | OTU2e #####
    elsif (($client_type eq 'otu2') || ($client_type eq 'otu2e') || ($client_type eq 'otu1e')) {
      # Client RX
      $n1 = 1;                                   $n2     = $PCvalue*16*4;
      $m1 = 1;                                   $m2     = 239*16*4;
      $num    = $m1 * $m2;
      $denom  = $n1 * $n2 * 64;

      if($client_fec eq 'nofec') {
        #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,$k_divider);
        main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,64);
      }
      else {
        #syncdsync_rx_cfg($client_module,$client_ch,$num,$denom,0,0,0,0,0);
        main::ten_syncdsyncrx_cfg($client_module,$client_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,0,0,0,0,0,0,0);
      }

      # Line TX
      if($line_type eq 'otu3+') {
        $n1   = 255*16*4*4;
      }
      #elsif (($line_identifier eq 'odu34x10ge') || ($line_identifier eq 'odu3')) {
      #  $n1     = 239*16*4*4;
      #}
      else {
        $n1   = $PLvalue*16*4*4;
      }                                          $n2 = 1;
      $m1     = 238*16*4*4 - $num_just_odtu23;   $m2 = 1;
      $num    = $m1 * $m2;
      $denom  = $n1 * $n2 * 64;
      $ac1    = 0;                               $ac2 = $n1 * $n2;
      $ad1    = 0;                               $ad2 = 4 * $num_pjo_odtu23;
      $cfg    = 0x02;
      $cfgpd0 = 0x01;
      $jc_thresh = _floor((2 * 64)/((2 * $num_pjo_odtu23) + 1));
      $jcgen = ($jc_thresh << 3) | $num_pjo_odtu23;

      # Line TX
      #syncdsync_tx_cfg($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg,$cfgpd0, $jcgen);
      main::ten_syncdsynctx_cfg($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch, $num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg,$cfgpd0,$jc_thresh,$num_pjo_odtu23);

      # Line RX
      #if($line_fec eq 'nofec') {
        #syncdsync_rx_cfg($line_module,$line_ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg);
      #  main::ten_syncdsyncrx_cfg($line_module,$line_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg);
      #}
      #else {
        $denom  = $n1 * $n2 * $k_divider;
        $denom = $denom*239;
        $num = $num*$PCvalue;
        $ac1 = $ac1*$PCvalue;
        $ac2 = $ac2*$PCvalue;
        $ad1 = $ad1*$PCvalue;
        $ad2 = $ad2*$PCvalue;
        #syncdsync_rx_cfg($line_module,$line_ch,$num*$PCvalue,$denom*239,$ac1*$PCvalue,$ac2*$PCvalue,$ad1*$PCvalue,$ad2*$PCvalue,$cfg);
        main::ten_syncdsyncrx_cfg($line_module,$line_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg);
      #}

      # Client TX
      #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
      main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
    }
    ##### 10GELAN_GSUP 7.3/ 10GELAN_GSUP 6.1 #####
    elsif (($client_type eq '10ge7_3') || ($client_type eq '10ge6_1') || ($client_type eq '10ge6_2') ||
           ($client_type eq '10ge_gfpf_oc192_odu2') || ($client_type eq '10ge_ra') || ($client_type eq '10ge_gfpf')) { # Bugzilla 29991
      # Client RX
      #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,$k_divider);
      main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,$k_divider);

      # Line TX
      #syncdsync_config_1_to_1_params($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_TX,$k_divider);
      main::ten_syncdsync_config_1_to_1($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_TX,$k_divider);

      # Line RX
      #syncdsync_config_1_to_1_params($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_RX,$k_divider);
      main::ten_syncdsync_config_1_to_1($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_RX,$k_divider);

      # Client TX
      #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
      main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
    }
    else {
      print("Unsupported OxU3 mapping\n");
      die;
    }
  }
  #########################
  #  10G TRANSPONDER
  #########################
  elsif (($mode eq 'trans10') || ($mode eq 'wire10')) {
    $num_just_odu2 = $num_just_oxu2;
    $num_pjo_odu2 = $num_pjo_oxu2;
  #else {
    if (($client_type eq '10ge6_1') || ($client_type eq '10ge6_2') || ($client_type eq '10ge_ra') ||
        ($client_type eq '10ge7_3') || ($client_type eq '10ge_gfpf_oc192_odu2') || ($client_type eq '10ge_gfpf')) {  # Bugzilla 29991
      return;
    }

    #($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, $line_type);
    #$num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;

    print("\n");
    print("40GMUX: num_pjo_odu2   = $num_pjo_odu2\n");
    print("40GMUX: num_just_odu2  = $num_just_odu2 \n");
    print("\n");

    #######################################
    # OxU2 SYNCHRONOUS  MAPPING
    #######################################
    if($sync == 1) { # SYNC
      if($client_type eq $line_type) {
        #if(clocks_get_bps($line_identifier) == clocks_get_bps($client_identifier)) {
        if($line_client_rate_equal) {
          #### Client channel RX 1:1 #####
          #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,$k_divider);
          #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
          main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,$k_divider);
          main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
          print("\n");

          #### Line channel RX 1:1 #####
          #syncdsync_config_1_to_1_params($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_RX,$k_divider);
          #syncdsync_config_1_to_1_params($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_TX,$k_divider);
          main::ten_syncdsync_config_1_to_1($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_RX,$k_divider);
          main::ten_syncdsync_config_1_to_1($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_TX,$k_divider);
          print("\n");
        }
        else {
          #### Client channel RX #####
          $m1     = $PLvalue*16*4;           $n2 = 1;
          $n1     = $PCvalue*16*4;           $m2 = 1;

          $num    = $m1 * $m2;
          $denom  = $n1 * $n2 * $k_divider;
          #syncdsync_rx_cfg($client_module,$client_ch,$num,$denom,0,0,0,0,0);
          main::ten_syncdsyncrx_cfg($client_module,$client_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,0,0,0,0,0,0,0);

          #### Line channel TX rdivmux +  Silab #####
          #syncdsync_config_1_to_1_params($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_TX,$k_divider);
          main::ten_syncdsync_config_1_to_1($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_TX,$k_divider);

          #### Line channel RX #####
          $m1     = $PCvalue*16*4;           $n2 = 1;
          $n1     = $PLvalue*16*4;           $m2 = 1;

          $num    = $m1 * $m2;
          $denom  = $n1 * $n2 * $k_divider;
          #syncdsync_rx_cfg($line_module,$line_ch,$num,$denom,0,0,0,0,0);
          main::ten_syncdsyncrx_cfg($line_module,$line_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,0,0,0,0,0,0,0);

          #### Client channel TX :rdivmux + Silab #####
          #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
          main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
        }
      }
      else { # Client and line type differ
        #### Client channel RX #####
        #if($client_type eq '10gfc_tc') {
        #  $m1     = 250*16*4;             $n2 = 1;
        #}
        #else {
        $m1     = $PLvalue*16*4*$trans_den;        $n2 = 1;
        #}

        #if($line_type eq 'otu1f') {  # or OTU1e
        #  $n1     = 238*16*4;             $m2 = 1;
        #}
        #else {
        #  $n1     = 237*16*4;             $m2 = 1;
        #}
        $n1     = $QLvalue*16*4*$trans_num;        $m2 = 1;

        $num    = $m1 * $m2;
        $denom  = $n1 * $n2 * $k_divider;
        #syncdsync_rx_cfg($client_module,$client_ch,$num,$denom,0,0,0,0,0);
        main::ten_syncdsyncrx_cfg($client_module,$client_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,0,0,0,0,0,0,0);

        #### Line channel TX rdivmux +  Silab #####
        #syncdsync_config_1_to_1_params($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_TX,$k_divider);
        main::ten_syncdsync_config_1_to_1($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,main::CS_TX,$k_divider);

        #### Line channel RX #####
        #if($line_type eq 'otu1f') {  # or OTU1e
        #  $m1     = 238*16*4;             $n2 = 1;
        #}
        #else {
        #  $m1     = 237*16*4;             $n2 = 1;
        #}
        $m1     = $QLvalue*16*4*$trans_num;        $n2 = 1;

        #if($client_type eq '10gfc_tc') {
        #  $n1     = 250*16*4;             $m2 = 1;
        #}
        #else {
        $n1     = $PLvalue*16*4*$trans_den;        $m2 = 1;
        #}

        $num    = $m1 * $m2;
        $denom  = $n1 * $n2 * $k_divider;
        #syncdsync_rx_cfg($line_module,$line_ch,$num,$denom,0,0,0,0,0);
        main::ten_syncdsyncrx_cfg($line_module,$line_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,0,0,0,0,0,0,0);

        #### Client channel TX :rdivmux + Silab #####
        #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
        main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
      }
    }
    #######################################
    # 0xU2 ASYNCHRONOUS  MAPPING
    #######################################
    else { # ASYNC
      if($client_type eq $line_type) {
        print("************** calc_syncdsync_params: line_type = client_type **************\n");
        print("num_just_odu2    : $num_just_odu2\n");
        print("num_pjo_odu2     : $num_pjo_odu2\n");

        $num_just_odu2 = 64;
        #### Client channel RX #####
        $n1     = $PCvalue*16*4;        $n2 = 1;
        $m1     = 238*16*4 - $num_just_odu2; $m2 = 1;
        $num    = $m1 * $m2;
        $denom  = $n1 * $n2 * 64;
        $ac1    = 0;                    $ac2 = $n1;
        $ad1    = 0;                    $ad2 = 1;
        $cfg    = 0x00;
        #syncdsync_rx_cfg($client_module,$client_ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg);
        main::ten_syncdsyncrx_cfg($client_module,$client_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg);

        #### Line channel TX #####
        $n1     = $PLvalue*16*4;        $n2 = 1;
        $m1     = 238*16*4 - $num_just_odu2; $m2 = 1;
        $num    = $m1;
        $denom  = $n1 * $n2 * 64;
        $ac1    = 0;                    $ac2 = $n1;
        $ad1    = 0;                    $ad2 = 1;
        $cfg    = 0x00;
        $cfgpd0 = 0x01;
        $jc_thresh = _floor((2 * 64)/((2 * $num_pjo_odu2) + 1));
        $jcgen = ($jc_thresh << 3) | $num_pjo_odu2  ;
        #syncdsync_tx_cfg($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg,$cfgpd0, $jcgen);
        main::ten_syncdsynctx_cfg($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch, $num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg,$cfgpd0,$jc_thresh,$num_pjo_odu2);

        #### Line channel RX #####
        $n1     = $PLvalue*16*4;        $n2 = 1;
        $m1     = 238*16*4 - $num_just_odu2; $m2 = 1;
        $num    = $m1 * $m2;
        $denom  = $n1 * $n2 * 64;
        $ac1    = 0;                    $ac2 = $n1;
        $ad1    = 0;                    $ad2 = 1;
        $cfg    = 0x00;
        #syncdsync_rx_cfg($line_module,$line_ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg);
        main::ten_syncdsyncrx_cfg($line_module,$line_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg);

        #### Client channel TX #####
        $n1     = $PCvalue*16*4;         $n2 = 1;
        $m1     = 238*16*4 - $num_just_odu2; $m2 = 1;
        $num    = $m1 * $m2;
        $denom  = $n1 * $n2 * 64;
        $ac1    = 0;                    $ac2 = $n1;
        $ad1    = 0;                    $ad2 = 1;
        $cfg    = 0x00;
        $cfgpd0 = 0x01;
        $jc_thresh = _floor((2 * 64)/((2 * $num_pjo_odu2) + 1));
        $jcgen = ($jc_thresh << 3) | $num_pjo_odu2  ;
        #syncdsync_tx_cfg($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg,$cfgpd0, $jcgen);
        main::ten_syncdsynctx_cfg($client_module,$client_ch,(($line_module & 1) * 4) + $client_ch, $num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg,$cfgpd0,$jc_thresh,$num_pjo_odu2);
      }
      else {
        #### Client channel RX 1:1 #####
        #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,$k_divider);
        main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_RX,64);
        print("\n");

        #### Line channel TX #####
        $n1     = $PLvalue*16*4;         $n2 = 1;
        $m1     = 238*16*4 - $num_just_odu2; $m2 = 1;

        if($client_type eq 'otu2e') {
          $num    = $m1 * $m2 * $trans_num_mult;
          $denom  = $n1 * $n2 * $trans_den_mult * 64;
        }
        else {
          $num    = $m1 * $m2;
          $denom  = $n1 * $n2 * 64;
        }

        $ac1    = 0;                        $ac2 = $n1;
        $ad1    = 0;                        $ad2 = $num_pjo_odu2;
        $cfg    = 0x00;
        $cfgpd0 = 0x01;
        $jc_thresh = _floor((2 * 64)/((2 * $num_pjo_odu2) + 1));
        $jcgen = ($jc_thresh << 3) | $num_pjo_odu2  ;

        print("\n");
        printf(" n1  = 0x%x\n", $n1);
        printf(" m1  = 0x%x\n", $m1);
        printf(" n2  = 0x%x\n", $n2);
        printf(" m2  = 0x%x\n", $m2);
        printf(" den = 0x%x\n", $denom);
        printf(" num = 0x%x\n", $num);
        printf(" ac1 = 0x%x\n", $ac1);
        printf(" ac2 = 0x%x\n", $ac2);
        printf(" ad1 = 0x%x\n", $ad1);
        printf(" ad2 = 0x%x\n", $ad2);
        print("\n");

        #syncdsync_tx_cfg($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg,$cfgpd0, $jcgen);
        main::ten_syncdsynctx_cfg($line_module,$line_ch,(($client_module & 1) * 4) + $client_ch, $num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg,$cfgpd0,$jc_thresh,$num_pjo_odtu23);
        print("\n");

        if($client_type eq 'otu2e') {
          $denom  = $n1 * $n2 * $trans_den_mult * $k_divider;
        }
        else {
          $denom  = $n1 * $n2 * $k_divider;
        }

        #### Line channel RX #####
        #syncdsync_rx_cfg($line_module,$line_ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg);
        main::ten_syncdsyncrx_cfg($line_module,$line_ch,$num>>32,$num&0xFFFF_FFFF,$denom>>32,$denom&0xFFFF_FFFF,$ac1>>32,$ac1&0xFFFF_FFFF,$ac2>>32,$ac2&0xFFFF_FFFF,$ad1,$ad2,$cfg);
        print("\n");

        #### Client channel TX : Silab #####
        #syncdsync_config_1_to_1_params($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
        main::ten_syncdsync_config_1_to_1($client_module,$client_ch,(($line_module & 1) * 4) + $line_ch,main::CS_TX,$k_divider);
      }
    }
  }
}

###############################################################################
#  Provision syncdsync for 1:1 mapping
###############################################################################
sub syncdsync_config_1_to_1_params {

  my ($module,$ch,$rxdivmux,$dir,$k_divider) = @_;

  my $num_pjo = 1;
  my $jcgen; my $jc_thresh;
  my $num; my $denom; my $ac1; my $ac2; my $ad1; my $ad2; my $cfg; my $cfgpd0;

  print("Entered 1_to_1 function\n");
  $num    = 1;
  $denom  = $k_divider;
  $ac1    = 0;                  $ac2 = 1;
  $ad1    = 0;                  $ad2 = 1;
  $cfg    = 0;
  $cfgpd0 = 1;
  $jc_thresh = _floor((2 * $k_divider)/((2 * $num_pjo) + 1));
  $jcgen = ($jc_thresh << 3) | $num_pjo  ;

  if($dir == main::CS_RX) {
    syncdsync_rx_cfg($module,$ch,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg);
  }
  else {
    syncdsync_tx_cfg($module,$ch,$rxdivmux,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg,$cfgpd0, $jcgen);
  }
}

###############################################################################
#  Enable the RDIV mux to connect syncdsyncs from client to line
###############################################################################
sub syncdsync_enable_rdvimux {
  my ($module,$ch,$rxdivmux) = @_;
  my $dev_id = $module >> 8;    # Bugzilla 19905
  my $mod_num = $module & 0xFF;    # Bugzilla 19905

  main::ten_mpif_global_reset_syncdsync($dev_id, $mod_num, $ch, main::CS_TX, main::CS_RESET_ASSERT);
  main::ten_mpif_global_reset_syncdsync($dev_id, $mod_num, $ch, main::CS_TX, main::CS_RESET_DEASSERT);

  print "syncdsync_enable_rdvimux: $module, $ch, $rxdivmux\n";
  main::ten_syncdsynctx_set_configuration_rx_div_mux($module, $ch, $rxdivmux);
}

###############################################################################
#  Debug function to print syncdsync parameters
###############################################################################
sub syncdsync_print_params {
  my($module, $ch, $dir, $num, $den, $ac1, $ac2, $ad1, $ad2, $cfg, $cfgpd0, $jc_thresh, $num_pjo, $print_en)=@_;

  if($print_en == 1) {
    print("Module          = $module\n");
    print("Channel         = $ch\n");
    printf("Numerator      = 0x%x\n", $num);
    printf("Denominator    = 0x%x\n", $den);
    printf("ac1            = 0x%x\n", $ac1);
    printf("ac2            = 0x%x\n", $ac2);
    printf("ad1            = 0x%x\n", $ad1);
    printf("ad2            = 0x%x\n", $ad2);
    printf("RX/TX cfg:mode = 0x%x\n", $cfg);
    if($dir == 1) { # TX
      printf("TX cfgpd0      = 0x%x\n", $cfgpd0);
      printf("TX jc thresh   = 0x%x\n", $jc_thresh);
    }
    printf("Number of PJOs = 0x%x\n", $num_pjo);
  }
  print("\n");
}

###############################################################################
#  Configure RX side of the syncdsync block
###############################################################################
sub syncdsync_rx_cfg {
  my ($module_id,$slice,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg ) = @_;
  my $dev_id = $module_id >> 8;    # Bugzilla 19905
  my $mod_num = $module_id & 0xFF;    # Bugzilla 19905

  my $chan=($module_id eq main::TEN_MODULE_A) ? $slice : $slice+4;

  print("***********************************************************\n");
  print ("syncdsync_rx_cfg() module_id = $module_id, chan = $chan\n");
  printf("                   num = 0x%X, denom = 0x%X\n", $num, $denom);
  printf("                   ac1 = 0x%X, ac2 = 0x%X, ad1 = 0x%X, ad2 = 0x%X, cfg = 0x%X\n", $ac1, $ac2, $ad1, $ad2, $cfg);
  print("***********************************************************\n");

  main::ten_mpif_global_reset_syncdsync($dev_id, $mod_num, $slice, main::CS_RX, main::CS_RESET_TOGGLE);
  main::ten_syncdsyncrx_control_sreset($module_id, $slice, main::CS_RESET_ASSERT);

  # Denominator Splitting
   my $denom_lower_hex = reg_splitter($denom,32);
   my $denom_middle_hex = reg_splitter($denom,16);
   my $denom_upper_hex = reg_splitter($denom,0);

  # Numerator Splitting
   my $num_lower_hex = reg_splitter($num,32);
   my $num_middle_hex = reg_splitter($num,16);
   my $num_upper_hex = reg_splitter($num,0);

  # AC1 Splitting
   my $ac1_lower_hex = reg_splitter($ac1,32);
   my $ac1_middle_hex = reg_splitter($ac1,16);
   my $ac1_upper_hex = reg_splitter($ac1,0);

  # AC2 Splitting
   my $ac2_lower_hex = reg_splitter($ac2,32);
   my $ac2_middle_hex = reg_splitter($ac2,16);
   my $ac2_upper_hex = reg_splitter($ac2,0);

  # AD1 Splitting
   my $ad1_lower_hex = reg_splitter($ad1,32);
   my $ad1_upper_hex = reg_splitter($ad1,16);

  # AD2 Splitting
   my $ad2_lower_hex = reg_splitter($ad2,32);
   my $ad2_upper_hex = reg_splitter($ad2,16);

  # CFG
   my $cfg_hex = reg_splitter($cfg,32);

  # Register write
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_NUMERATOR2+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$num_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_NUMERATOR1+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$num_middle_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_NUMERATOR0+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$num_lower_hex , 15, 0);
  main::ten_syncdsyncrx_set_numerator($module_id, $slice, $num_upper_hex, $num_middle_hex, $num_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_DENOMINATOR2+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$denom_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_DENOMINATOR1+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$denom_middle_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_DENOMINATOR0+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$denom_lower_hex , 15, 0);
  main::ten_syncdsyncrx_set_denominator($module_id, $slice, $denom_upper_hex, $denom_middle_hex, ,$denom_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_AC12+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$ac1_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_AC11+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$ac1_middle_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_AC10+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$ac1_lower_hex , 15, 0);
  main::ten_syncdsyncrx_set_ac1($module_id, $slice, $ac1_upper_hex, $ac1_middle_hex, $ac1_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_AC22+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$ac2_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_AC21+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$ac2_middle_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_AC20+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$ac2_lower_hex , 15, 0);
  main::ten_syncdsyncrx_set_ac2($module_id, $slice, $ac2_upper_hex, $ac2_middle_hex, $ac2_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_AD11+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$ad1_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_AD10+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$ad1_lower_hex , 15, 0);
  main::ten_syncdsyncrx_set_ad1($module_id, $slice, $ad1_upper_hex, $ad1_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_AD21+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$ad2_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_AD20+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$ad2_lower_hex , 15, 0);
  main::ten_syncdsyncrx_set_ad2($module_id, $slice, $ad2_upper_hex, $ad2_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCRX_CFGRX_CFG+(main::TEN_SYNCDSYNCRX_STRIDE * $chan),$cfg_hex , 4, 3);
  main::ten_syncdsyncrx_set_mode($module_id, $slice, $cfg_hex);

  main::ten_syncdsyncrx_control_sreset($module_id, $slice, main::CS_RESET_DEASSERT);
}

###############################################################################
#  Configure TX side of the syncdsync block
###############################################################################
sub syncdsync_tx_cfg {
  my ($module_id,$slice,$rxdivmux,$num,$denom,$ac1,$ac2,$ad1,$ad2,$cfg,$cfgpd0,$cfgjcgen) = @_;
  my $dev_id = $module_id >> 8;    # Bugzilla 19905
  my $mod_num = $module_id & 0xFF;    # Bugzilla 19905

  my $chan=($module_id eq main::TEN_MODULE_A) ? $slice : $slice+4;

  print ("**********************************************************************\n");
  print ("syncdsync_tx_cfg() module_id = $module_id, chan = $chan\n");
  printf("                   num = 0x%X, denom = 0x%X\n", $num, $denom);
  printf("                   ac1 = 0x%X, ac2 = 0x%X, ad1 = 0x%X, ad2 = 0x%X\n", $ac1, $ac2, $ad1, $ad2);
  printf("                   cfg = 0x%X, cfgpd0 = 0x%X, cfgjcgen = 0x%X, rxdivmux = %d\n", $cfg, $cfgpd0, $cfgjcgen, $rxdivmux);
  print ("***********************************************************************\n");

  main::ten_mpif_global_reset_syncdsync($dev_id, $mod_num, $slice, main::CS_TX, main::CS_RESET_TOGGLE);

  main::ten_syncdsynctx_control_sreset($module_id, $slice, main::CS_RESET_ASSERT);

  # Denominator Splitting
   my $denom_lower_hex = reg_splitter($denom,32);
   my $denom_middle_hex = reg_splitter($denom,16);
   my $denom_upper_hex = reg_splitter($denom,0);

  # Numerator Splitting
   my $num_lower_hex = reg_splitter($num,32);
   my $num_middle_hex = reg_splitter($num,16);
   my $num_upper_hex = reg_splitter($num,0);


  # AC1 Splitting
   my $ac1_lower_hex = reg_splitter($ac1,32);
   my $ac1_middle_hex = reg_splitter($ac1,16);
   my $ac1_upper_hex = reg_splitter($ac1,0);

  # AC2 Splitting
  my $ac2_lower_hex = reg_splitter($ac2,32);
  my $ac2_middle_hex = reg_splitter($ac2,16);
  my $ac2_upper_hex = reg_splitter($ac2,0);

  # AD1 Splitting
  my $ad1_lower_hex = reg_splitter($ad1,32);
  my $ad1_upper_hex = reg_splitter($ad1,16);

  # AD2 Splitting
  my $ad2_lower_hex = reg_splitter($ad2,32);
  my $ad2_upper_hex = reg_splitter($ad2,16);

  # CFG
  my $cfg_hex = reg_splitter($cfg,32);

  # CFGPD
  my $cfgpd0_hex = reg_splitter($cfgpd0,32);

  # CFGJCGEN
  my $cfgjcgen_hex = reg_splitter($cfgjcgen,32);

  # Register write
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_NUMERATOR2+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$num_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_NUMERATOR1+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$num_middle_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_NUMERATOR0+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$num_lower_hex , 15, 0);
  main::ten_syncdsynctx_set_numerator($module_id, $slice, $num_upper_hex, $num_middle_hex, $num_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_DENOMINATOR2+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$denom_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_DENOMINATOR1+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$denom_middle_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_DENOMINATOR0+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$denom_lower_hex , 15, 0);
  main::ten_syncdsynctx_set_denominator($module_id, $slice, $denom_upper_hex, $denom_middle_hex, $denom_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_AC12+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$ac1_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_AC11+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$ac1_middle_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_AC10+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$ac1_lower_hex , 15, 0);
  main::ten_syncdsynctx_set_ac1($module_id, $slice, $ac1_upper_hex, $ac1_middle_hex, $ac1_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_AC22+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$ac2_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_AC21+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$ac2_middle_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_AC20+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$ac2_lower_hex , 15, 0);
  main::ten_syncdsynctx_set_ac2($module_id, $slice, $ac2_upper_hex, $ac2_middle_hex, $ac2_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_AD11+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$ad1_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_AD10+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$ad1_lower_hex , 15, 0);
  main::ten_syncdsynctx_set_ad1($module_id, $slice, $ad1_upper_hex, $ad1_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_AD21+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$ad2_upper_hex , 15, 0);
  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_AD20+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$ad2_lower_hex , 15, 0);
  main::ten_syncdsynctx_set_ad2($module_id, $slice, $ad2_upper_hex, $ad2_lower_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_CFG+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$cfg_hex , 5, 4);
  main::ten_syncdsynctx_set_mode($module_id, $slice, $cfg_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_CFGPD0+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$cfgpd0_hex , 0, 0);
  main::ten_syncdsynctx_cfgtx_cfgpd0($module_id, $slice, $cfgpd0_hex);

  # tenabo_bf_write($dev_id,main::TEN_SYNCDSYNCTX_CFGTX_CFGJCGEN+(main::TEN_SYNCDSYNCTX_STRIDE * $chan),$cfgjcgen_hex , 15, 0);
  main::ten_syncdsynctx_jcgen_configuration($module_id, $slice, ($cfgjcgen_hex>>3) & 0x3ff, $cfgjcgen_hex & 0x7);

  main::ten_syncdsynctx_set_configuration_rx_div_mux($module_id, $slice, $rxdivmux);
  main::ten_syncdsynctx_control_sreset($module_id, $slice, main::CS_RESET_DEASSERT);
}

# This is the version that supports 32-bit Perl
sub reg_splitter {
  my ($value,$word_index) = @_;
  my $word_int;

  # this can't handle values greater than 2^32
  # for 32 bit compiled-perl.  sprintf caps at
  # 0xFFFFFFFF.
  #
  #my $a48bit_st = sprintf("%048b",$value);
  #my $word_st = substr($a48bit_st,$word_index,16);
  #my $word_int = oct("0b".$word_st);
  if ($value >= 281474976710656) {
    printf("value greater than 48 bits\n");
    return "0x0";
  }
  my $upper = int($value / 4294967296);
  $value -= $upper * 4294967296;
  my $middle = int($value / 65536);
  $value -= $middle * 65536;
  my $lower = $value;
  if ($word_index == 0) {
    $word_int = $upper;
  }
  elsif ($word_index == 16) {
    $word_int = $middle;
  }
  else {
    $word_int = $lower;
  }
  return $word_int;
  # my $word_hex = ("0x".sprintf("%lx",$word_int));
  # return $word_hex;
}

sub _floor {
  my $y = shift();
  return int(($y < 0) ? $y-.5 : $y);
#  return (($y < 0) ? $y-.5 : $y);
}

###############################################################################
#
###############################################################################
sub get_syncdsync_muxponder_method {
  my ($line_type, $client_type, $mode, $map_oxuv, $map_odtu)=@_;  # Bugzilla 27167
print ("get_syncdsync_muxponder_method() = map_oxuv=$map_oxuv, map_odtu=$map_odtu\n");

  my $mux_method = main::TEN_MUX_BOTH_1TO1;

  if (($mode eq 'lb10') || ($mode eq 'lb40') ||
      ($mode eq 'cbr_kpga10') || ($mode eq 'cbr_kpga40') ||
      ($mode eq 'kpga10') || ($mode eq 'kpga40') || ($mode eq 'pbert10')) {
    # Loopback or pattern generator
    $mux_method = main::TEN_MUX_BOTH_1TO1;
    return $mux_method;
  }

  if(($line_type eq 'otu3') || ($line_type eq 'otu3+') || ($line_type eq 'otu3p2') ||
     ($line_type eq 'otu3e') || ($line_type eq 'otu3e1') || ($line_type eq 'otu3e2') || ($line_type eq 'otu3e4')) {        # Bugzilla 28237
    if(($client_type eq 'oc192') || ($client_type eq '10ge7_1') || ($client_type =~ /10gfc_tc/) || # Bug 31054
       ($client_type eq '10ge7_2') || ($client_type eq '8gfc_enh') || ($client_type eq 'pbert_8gfc') ||
       ($client_type eq '8gfc') || ($client_type eq 'pbert_10gfc') || ($client_type eq 'oc192_async') ||
       ($client_type eq '2_5g_iba') || ($client_type eq '5g_iba') || ($client_type eq '10g_iba') ||
       ($client_type =~ /pbert_10ge/) ||
       ($client_type eq '4gfc') || ($client_type eq '2gfc') || ($client_type eq '2gisc') || # Bug 38779
       ($client_type eq '1gfc') || ($client_type eq '1ge') or # Bug 38871
       ($client_type eq 'fdr10_iba')) { # Bugzilla 39242
      $mux_method = main::TEN_MUX_1TO1_ASYNC_2LEVEL;
    }
    elsif (($client_type eq 'otu2') || ($client_type eq 'otu2e') || ($client_type eq 'otu1e')) {
      $mux_method = main::TEN_MUX_SYNC_ASYNC_1LEVEL;
    }
    elsif ($client_type =~ /gfc_ra/) {
      # $mux_method = main::TEN_MUX_1TO1_ASYNC_1LEVEL;
      $mux_method = main::TEN_MUX_SYNC_ASYNC_1LEVEL;
    }
    # Bugzilla 28006 Start
    # Bugzilla 27167 Start
    elsif (($line_type =~ /otu3/) && ($client_type =~ /otu3/)) {
      if($mode eq 'mux') {
        $mux_method = main::TEN_ASYNC_ASYNC_1LEVEL;
      } else {
        if ($map_odtu == main::TEN_MAP_DONT_CARE) {
          # map_odtu is not specified, so can only use map_oxuv
          if ($map_oxuv == main::TEN_MAP_BMP) {
            # Assume both sides are BMP/sync
            $mux_method = main::TEN_MUX_BOTH_1TO1;
          } else {
            # Assume Client side is BMP and line side is async
            $mux_method = main::TEN_MUX_SYNC_ASYNC_1LEVEL;
          }
        } else {
          # map_oxuv and map_odtu are specified
          if ($map_oxuv == main::TEN_MAP_BMP) {
            if ($map_odtu == main::TEN_MAP_BMP) {
              $mux_method = main::TEN_MUX_BOTH_1TO1;
            } else {
              $mux_method = main::TEN_MUX_SYNC_ASYNC_1LEVEL;
            }
          } else {
            # Both must be async
            $mux_method = main::TEN_ASYNC_ASYNC_1LEVEL;
          }
        }
      }
    }
    # Bugzilla 27167 End
    # Bugzilla 28006 End
    elsif ($client_type eq 'oc768') {     # Bugzilla 31435
      $mux_method = main::TEN_MUX_1TO1_ASYNC_1LEVEL;
    }
    elsif ($client_type =~ /40ge/) {
      $mux_method = main::TEN_MUX_1TO1_ASYNC_1LEVEL;
    }
    else {
      $mux_method = main::TEN_MUX_BOTH_1TO1;
    }
  }

  if ($mux_method == main::TEN_MUX_1TO1_ASYNC_2LEVEL) {
    print ("method = TEN_1TO1_ASYNC_2LEVEL ($mux_method)\n");
  }
  elsif ($mux_method == main::TEN_MUX_SYNC_ASYNC_1LEVEL) {
    print ("method = TEN_SYNC_ASYNC_1LEVEL ($mux_method)\n");
  }
  elsif ($mux_method == main::TEN_MUX_1TO1_ASYNC_1LEVEL) {
    print ("method = TEN_1TO1_ASYNC_1LEVEL ($mux_method)\n");
  }
  elsif ($mux_method == main::TEN_MUX_BOTH_1TO1) {
    print ("method = TEN_BOTH_1TO1 ($mux_method)\n");
  }
  elsif ($mux_method == main::TEN_ASYNC_ASYNC_1LEVEL) {
    print ("method = TEN_ASYNC_ASYNC_1LEVEL ($mux_method)\n");
  }
  elsif ($mux_method == main::TEN_1TO1_ASYNC_1TO1_1LEVEL) {
    print ("method = TEN_1TO1_ASYNC_1TO1_1LEVEL ($mux_method)\n");
  }
  elsif ($mux_method == main::TEN_ASYNC_ASYNCX4_1LEVEL) {
    print ("method = TEN_ASYNC_ASYNCX4_1LEVEL ($mux_method)\n");
  } else {
    print("method = $mux_method\n");
  }

  return $mux_method;
}

###################################################################################
# Function:     autoconfig_silab
#               Automatically configure Silab
#
# Parameters:
#   Module                  int - 0 = MODULE_A, 1 = MODULE_B
#   ch                      int - 0 - 3
#   mode                    int - 0 = S_40G, 1 = QUAD_10G
#   line clk source         int - -1 = fixed clk,  0-3 = synthesized clock
#   interface_type          string - XFI, SFI41, XAUI, SFI42_10G, SFI42_40G, SFI51_40G
#
# Returns:      Nothing
###################################################################################
sub autoconfig_silab {
  my ($dev_id, $module, $ch, $mode, $line_clk_src, $signal_type, $interface_type, $k_divider, $fec, $cupll)=@_;

  my $fin_fout;
  my $clksrc;
  my $ratehash;
  my $ret_code;
  my @settings;

  $signal_type = combine_signal_type_and_fec($signal_type, $fec);

  if ($mode == main::TEN_GLOBAL_MODE_QUAD_10G || $ch == 0 || $ch == 2) {
    my $divider = 1;
    my $rdiv_divider = ($mode == main::TEN_GLOBAL_MODE_QUAD_10G) ? 16*$k_divider : 64*$k_divider;

    if ($module == main::TEN_MODULE_B && $interface_type eq 'xfi') {
      if ($cupll) {
        # get divider from profile
        $divider = $k_divider;
      }
      elsif ($mode == main::TEN_GLOBAL_MODE_S_40G) {
        $divider = 64*$k_divider*4/64;
      }
      else {
        $divider = 64*$k_divider/64;
      }
    }
    elsif ($interface_type eq 'sfi4_1') {
      #$divider = 16*$k_divider/64;
      $divider = 16;
    }
    elsif ($interface_type eq 'sfi4_2_10g') {
      $divider = 128;
    }
    elsif ($interface_type eq 'sfi4_2_40g') {
      $divider = 512;
    }
    elsif ($interface_type eq 'sfi5_1') {
      #$divider = 64*$k_divider/64;
      $divider = 64;
    }
    elsif ($interface_type eq 'xaui') {
      # With varying k, one solution is to keep refclk fixed; in which case the multipier would be a constant
      # $divider = 80*$k_divider/64;
      $divider = 80;
      $signal_type='10gelanxaui';
      $rdiv_divider=$rdiv_divider*10/8;
    }
    elsif ($interface_type eq 'cfp_mr') {
      if ($cupll) {
        # get divider from profile
        $divider = $k_divider;
      }
      else {
        $divider = 64;
      }
    }
    else {
      print("ERROR BAD INTERFACE type!\n");
    }

    print("************** autoconfig_silab() **************\n");
    print("    module          :$module\n");
    print("    ch              :$ch\n");
    print("    mode            :$mode\n");
    print("    signal_type     :$signal_type\n");
    print("    interface_type  :$interface_type\n");
    print("    line_clksrc     :$line_clk_src\n");
    print("    divider         :$divider \n");
    print("    k_divider       :$k_divider \n");
    print("    rdiv_divider    :$rdiv_divider \n");
    print("    cupll           :$cupll \n");

    # Bugzilla  #32626
    # For CUPLL, only configure SiLabs on initial configurations
    if ($cupll == -1) {
      print("CUPLL/dynamic reconfig, exit\n");
      
      if ($line_clk_src == -1) {
          # For CUPLL Local Clock config, set MPIF_RXDIV_CFG0.mode=2,
          # "RXDIV from internal pilot, after divider & mux, see RXDIV_CFGi.pilot and PILOT_DIVi"
          # 4 = Divide by 32
          main::ten_mpif_pilot_div($dev_id,($module*4+$ch), 4);
          # Select source pilot
          main::ten_mpif_rxdiv_cfg0_pilot_t41($dev_id,($module*4+$ch), ($module*4+$ch));
          # 2 = RXDIV from internal pilot, after divider & mux, see RXDIV_CFGi.pilot and PILOT_DIVi
          main::ten_mpif_rxdiv_cfg0_mode_t41($dev_id, ($module*4+$ch), 2);
        }
        else {
          # 0 = RXDIV from RX controllable divider & protection mux, t40 mode
          main::ten_mpif_rxdiv_cfg0_mode_t41($dev_id, ($module*4+$ch), 0);
        }
      
      return 0;
    }
    
    if ($cupll == 1) {
      ($ret_code, $fin_fout, @settings) = clocks_get_settings_cupll($signal_type,$divider);
      $clksrc = 2;
    }
    elsif ($line_clk_src == -1) {
      # Fixed clock
      ($ret_code, $fin_fout, @settings) = clocks_get_settings_lr($signal_type,$divider);
      $clksrc = 2;
    } else {
      # Derived Clock from RxDiv
      ($ret_code, $fin_fout, @settings) = clocks_get_settings_rdiv($signal_type,$divider,$rdiv_divider);
     $clksrc = 1;
    }

    my $bps = clocks_get_bps($signal_type);

    if ($ret_code == 1) {
      die("autoconfig_silab: Unable to obtain settings for line rate = $signal_type divider = $divider");
    } else {
      print("**************************************\n");
      print("**************************************\n");
      printf("AUTO PROGRAMMING CLOCK for channel = %d\n", $ch+$module*4);
      print("**************************************\n");
      print("   Line Rate: $signal_type ($bps bps) \n");
      print("   Divider:   $divider                \n");
      print("   Rate plan: $fin_fout               \n");
      print("**************************************\n");
      print("**************************************\n");

      if ((main::t40fpga_get_board_type($FPGA_SYS_ID)==8) && (($module==1) && ($interface_type ne 'xfi'))) {
          if (!main::ten_dev_is_ws_in_progress($dev_id)) {
             print ("Program the 3rd clock card\n");
             tb_program_clock(3, 2**$ch, $clksrc, $interface_type, @settings);
             tb_program_clock(3, 4, $clksrc, $interface_type, @settings);
          }
      } 
      else {
        if (!main::ten_dev_is_ws_in_progress($dev_id)) {
           print("Program the clock card\n");
           tb_program_clock($module, 2**$ch, $clksrc, $interface_type, @settings);
        }

        # Bugzilla 31479 Start
        if (($cupll == 1) && ($line_clk_src == -1)) {
          # For CUPLL Local Clock config, set MPIF_RXDIV_CFG0.mode=2,
          # "RXDIV from internal pilot, after divider & mux, see RXDIV_CFGi.pilot and PILOT_DIVi"
          # 4 = Divide by 32
          main::ten_mpif_pilot_div($dev_id,($module*4+$ch), 4);
          # Select source pilot
          main::ten_mpif_rxdiv_cfg0_pilot_t41($dev_id,($module*4+$ch), ($module*4+$ch));
          # 2 = RXDIV from internal pilot, after divider & mux, see RXDIV_CFGi.pilot and PILOT_DIVi
          main::ten_mpif_rxdiv_cfg0_mode_t41($dev_id, ($module*4+$ch), 2);
        }
        else {
          # 0 = RXDIV from RX controllable divider & protection mux, t40 mode
          main::ten_mpif_rxdiv_cfg0_mode_t41($dev_id, ($module*4+$ch), 0);
        }
        # Bugzilla 31479 End
      }
    }
  }

  if (!main::ten_dev_is_ws_in_progress($dev_id)) {
      tb_ical($module, $ch);
  }
  
  sleep 10; # was 5

}

# Bugzilla 31209 Start
###############################################################################
## Function:     config_fec_40g
##               Enable a FEC (GFEC or 7% UFEC)
##
## Parameters:
##   module_id
##   fec_type    'gfec' or 'ufec7p' or '0fec' (which does nothing)
##
## Returns:      Nothing
###############################################################################
#sub config_fec_40g {
#    my ($module_id, $fec_type) = @_;
#    print("config_fec_40g() module_id = $module_id, fec_type = $fec_type\n");
#
#    if ($fec_type eq 'gfec') {
#        config_fec($module_id, 0, main::TEN_FEC_GFEC_40G, main::TEN_HL_MPIF_FEC_EN_GFEC, main::TEN_FEC_ACTIVE, 0);
#    }
#    elsif ($fec_type eq 'ufec7p') {
#        config_fec($module_id, ($module_id & 1), main::TEN_FEC_UFEC_40G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV);
#    }
#    elsif ($fec_type eq 'ufec10p') {
#        config_fec($module_id, ($module_id & 1), main::TEN_FEC_UFEC_40G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_262);
#    }
#    elsif ($fec_type eq 'ufec12p') {
#        config_fec($module_id, ($module_id & 1), main::TEN_FEC_UFEC_40G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_267);
#    }
#    elsif ($fec_type eq 'ufec13p') {
#        config_fec($module_id, ($module_id & 1), main::TEN_FEC_UFEC_40G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_270);
#    }
#    elsif ($fec_type eq 'ufec15p') {
#        config_fec($module_id, ($module_id & 1), main::TEN_FEC_UFEC_40G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_273);
#    }
#    elsif ($fec_type eq 'ufec20p') {
#        config_fec($module_id, ($module_id & 1), main::TEN_FEC_UFEC_40G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_285);
#    }
#    elsif ($fec_type eq 'ufec25p') {
#        config_fec($module_id, ($module_id & 1), main::TEN_FEC_UFEC_40G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_297);
#    }
#    elsif ($fec_type eq 'ufec26p') {
#        config_fec($module_id, ($module_id & 1), main::TEN_FEC_UFEC_40G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_301);
#    }
#    elsif ($fec_type  eq 'nofec') {
#        #/* Configure scrambler/descrambler for GFEC */
#        main::ten_n40g_otnr4x_descrambling ($module_id, 0, 1, 1);
#        main::ten_n40g_otnt4x_scrambling ($module_id, 1, 0);
#
#        #/* Bypass FEC */
#        main::ten_n40g_otnt4x_ocfg ($module_id, 0, 0);
#        main::ten_n40g_otnr4x_ocfg ($module_id, 0, 0);
#
#        #/* Set number of FEC columns to 0 and frame size for no FEC columns */
#        main::ten_n40g_otnr4x_set_ncols ($module_id, 238);
#        main::ten_n40g_otnr4x_set_nparb_npar ($module_id, 0, 0);
#        main::ten_n40g_otnt4x_set_ncols ($module_id, 238);
#        main::ten_n40g_otnt4x_set_nparb_npar ($module_id, 0, 0);
#    }
#    elsif ($fec_type  eq '0fec') {
#        #/* Configure scrambler/descrambler for GFEC */
#        main::ten_n40g_otnr4x_descrambling ($module_id, 0, 1, 1);
#        main::ten_n40g_otnt4x_scrambling ($module_id, 1, 0);
#
#        #/* Bypass FEC */
#        main::ten_n40g_otnt4x_ocfg ($module_id, 0, 0);
#        main::ten_n40g_otnr4x_ocfg ($module_id, 0, 0);
#    }
#}

###############################################################################
## Function:     config_fec_10g
##               Enable a FEC (GFEC or 7% UFEC)
##
## Parameters:
##   module_id
##   slice
##   fec_type    'gfec' or 'ufec7p' or '0fec' (which does nothing)
##
## Returns:      Nothing
###############################################################################
#sub config_fec_10g {
#    my ($module_id, $slice, $fec_type) = @_;
#
#    print("config_fec_10g()  module_id = $module_id, slice = $slice, fec_type = $fec_type\n");
#
#
#    if ($fec_type eq 'gfec') {
#        config_fec($module_id, $slice, main::TEN_FEC_GFEC_10G, main::TEN_HL_MPIF_FEC_EN_GFEC, main::TEN_FEC_ACTIVE, 0);
#    }
#    elsif ($fec_type eq 'ufec7p') {
#        config_fec($module_id, $slice, main::TEN_FEC_UFEC_10G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV);
#    }
#    elsif ($fec_type eq 'ufec7p_sdha') {
#        config_fec($module_id, $slice, main::TEN_FEC_UFEC_10G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_SDH_A);
#    }
#    elsif ($fec_type eq 'ufec10p') {
#        config_fec($module_id, $slice, main::TEN_FEC_UFEC_10G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_262);
#    }
#    elsif ($fec_type eq 'ufec12p') {
#        config_fec($module_id, $slice, main::TEN_FEC_UFEC_10G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_267);
#    }
#    elsif ($fec_type eq 'ufec13p') {
#        config_fec($module_id, $slice, main::TEN_FEC_UFEC_10G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_270);
#    }
#    elsif ($fec_type eq 'ufec15p') {
#        config_fec($module_id, $slice, main::TEN_FEC_UFEC_10G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_273);
#    }
#    elsif ($fec_type eq 'ufec20p') {
#        config_fec($module_id, $slice, main::TEN_FEC_UFEC_10G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_285);
#    }
#    elsif ($fec_type eq 'ufec25p') {
#        config_fec($module_id, $slice, main::TEN_FEC_UFEC_10G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_297);
#    }
#    elsif ($fec_type eq 'ufec26p') {
#        config_fec($module_id, $slice, main::TEN_FEC_UFEC_10G, main::TEN_HL_MPIF_FEC_EN_UFEC, main::TEN_FEC_ACTIVE, main::TEN_FEC_MODE_OTUkV_301);
#    }
#    elsif ($fec_type  eq 'nofec') {
#        #/* Configure scrambler/descrambler for GFEC */
#        main::ten_n10g_otnr_descrambling($module_id, $slice, 0, 1);
#        main::ten_n10g_otnt_scrambling($module_id, $slice, 1, 0);
#
#        #/* Bypass FEC */
#        main::ten_n10g_otnt_ocfg($module_id, $slice, 0, 0);
#        main::ten_n10g_otnr_ocfg($module_id, $slice, 0, 0);
#
#        #/* Set number of FEC columns to 0 and frame size for no FEC columns */
#        main::ten_n10g_otnr_set_frame_format($module_id, $slice, 238, 3, 0, 0);
#        main::ten_n10g_otnt_set_frame_format($module_id, $slice, 238, 3, 0, 0);
#    }
#    elsif ($fec_type  eq '0fec') {
#        #/* Configure scrambler/descrambler for GFEC */
#        main::ten_n10g_otnr_descrambling($module_id, $slice, 0, 1);
#        main::ten_n10g_otnt_scrambling($module_id, $slice, 1, 0);
#
#        #/* Bypass FEC */
#        main::ten_n10g_otnt_ocfg($module_id, $slice, 0, 0);
#        main::ten_n10g_otnr_ocfg($module_id, $slice, 0, 0);
#    }
#}

###############################################################################
## Function:     config_fec
##               Enable or disable a FEC (GFEC or UFEC at any %)
##
## Parameters:
##   module_id
##   slice
##   fec_type    the 'fec_type' parameter for ten_hl_mpif_fec_init
##                   TEN_FEC_GFEC_40G
##                   TEN_FEC_UFEC_40G
##                   TEN_FEC_GFEC_10G
##                   TEN_FEC_UFEC_10G
##   fec_en      the 'fec_en" parameter for ten_hl_mpif_fec_init
##                   TEN_HL_MPIF_FEC_EN_GFEC for GFEC
##                   TEN_HL_MPIF_FEC_EN_UFEC for UFEC
##   action      the 'action' parameter for ten_hl_fec_config
##                   TEN_FEC_ACTIVE
##   overhead    the 'overhead' parameter for ten_hl_fec_config
##                   0 for GFEC or a disabled or bypassed FEC
##                   TEN_FEC_MODE_OTUkV      7% UFEC
##                   TEN_FEC_MODE_OTUkV_262  10% UFEC
##                   TEN_FEC_MODE_OTUkV_273  15% UFEC
##                   TEN_FEC_MODE_OTUkV_285  20% UFEC
##                   TEN_FEC_MODE_OTUkV_297  25% UFEC
##
## Returns:      Nothing
###############################################################################
#sub config_fec {
#    my ($module_id, $slice, $fec_type, $fec_en, $action, $overhead) = @_;
#    print("config_fec() module_id = $module_id, slice = $slice, fec_type = $fec_type, fec_en = $fec_en, action = $action, overhead = $overhead\n");
#
#    main::ten_hl_mpif_fec_init($module_id, $slice, $fec_type, $fec_en);
#    if ($fec_en > 0) {
#        main::ten_hl_fec_config($module_id, $slice, $fec_type, $action, $overhead);
#    }
#    else {
#        main::ten_hl_fec_config($module_id, $slice, $fec_type, main::TEN_FEC_BYPASS, 0);
#    }
#}

## fec_type comes from the $fec array
#sub deallocate_fec {
#    my ($module_id, $slice) = @_;
#    my $fec_type = get_fec(($module_id & 1) * 4 + $slice);
#    if ($fec_type eq '10gfec') {
#        print "deallocate_fec: Deallocating 10G GFEC for $module_id, $slice\n";
#        config_fec($module_id, $slice, main::TEN_FEC_GFEC_10G, 0, main::TEN_FEC_BYPASS, 0);
#    }
#    elsif ($fec_type eq '10ufec') {
#        print "deallocate_fec: Deallocating 10G UFEC for $module_id, $slice\n";
#        config_fec($module_id, $slice, main::TEN_FEC_UFEC_10G, 0, main::TEN_FEC_BYPASS, 0);
#    }
#    ### TODO: Complete for 40G
#}
# Bugzilla 31209 End

##############################################################################
# Function:      tenabo_pbert_config
#                Config PBERT
#
# Parameters:
#    slice      int - <0-7>
#    profile    int - <0|2|4>
#    min        int - min packet length
#    max        int - max packet length
#    ifg        int - ifg
#
# Returns:
##############################################################################
sub config_pbert {
    my ($module_id, $slice, $profile, $min, $max, $ifg) = @_;
    my $dev_id = $module_id >> 8;
    my $max1;
    my $max2;

    main::ten_xcon_select_bert($dev_id, $slice, main::XCON_PBERT);
    main::ten_xcon_set_pbert_mode($dev_id, $slice, main::XCON_TRAFFIC_FRAME, $profile);
    main::ten_xcon_set_pbert_protocol($dev_id, $slice, 0, 0,main::XCON_DA_UCAST);
    main::ten_xcon_control_pbert_frame_payload($dev_id, $slice, main::XCON_PAYLOAD_PRBS, main::CS_ENABLE);
    main::ten_xcon_control_pbert_unit_len($dev_id, $slice, main::XCON_UNIT_LEN_RANDOM, 0x7ff, $min, $max);
    main::ten_xcon_pbert_control_traffic($dev_id, $slice, 0);
    main::ten_xcon_pbert_control_ifg($dev_id, $slice,0, $ifg);
    main::ten_xcon_pbert_select_fixed_pattern($dev_id, $slice, main::XCON_FIXED_PATTERN_01, 0x00, 0x11);
    main::ten_xcon_pbert_select_fixed_pattern($dev_id, $slice, main::XCON_FIXED_PATTERN_23, 0x22, 0x33);
    main::ten_xcon_pbert_select_fixed_pattern($dev_id, $slice, main::XCON_FIXED_PATTERN_45, 0x08, 0x00);
    main::ten_xcon_pbert_select_fixed_pattern($dev_id, $slice, main::XCON_FIXED_PATTERN_67, 0x00, 0x00);
    if ($max > 1518 && $profile <= 4) {
        main::ten_pp10g_mac_rx_maxlen($module_id, $slice, $max);
    }
    if ($max > 1518 && ($profile == 5 || $profile == 6)) {
        main::ten_pp10g_gfp_rx_maxlen($module_id,$slice, $max);
    }
    if ($max > 1518) {
        $max1 = $max & 0x0000_ffff;
        $max2 = ($max & 0x0003_0000) >> 16;
        main::ten_pp10g_xgadj_tx_maxframe($module_id, $slice, $max2, $max1);
    }
}

###############################################################################
# Get line client parameters
###############################################################################
sub get_line_client_params {
    my ($line_type, $client_type, $line_fec, $client_fec, $mode, $sync, $xcon_client_type) = @_;  # Bugzilla 27167

    my $trans_num=1; my $trans_den=1;
    my $line_client_rate_equal;
    my $line_client_same;
    my $line_identifier; my $client_identifier;
    my $PLvalue, my $QLvalue; my $PCvalue, my $QCvalue; my $jc_thresh=0;

    # Change odu traffic typs to otu for comparison
    $xcon_client_type =~ s/odu/otu/; # Bugzilla 28176


print("get_line_client_params()  line_type = $line_type, client_type = $client_type, line_fec = $line_fec,\n");
print("                          client_fec = $client_fec, mode = $mode, sync = $sync\n");

    $client_identifier = combine_signal_type_and_fec($client_type, $client_fec);
    $line_identifier  = combine_signal_type_and_fec($line_type, $line_fec);

print("get_line_client_params()  client_identifier = $client_identifier\n");
print("                          line_identifier = $line_identifier\n");

    $PLvalue = clocks_get_P($line_identifier);
    $QLvalue = clocks_get_Q($line_identifier);
    $PCvalue = clocks_get_P($client_identifier);
    $QCvalue = clocks_get_Q($client_identifier);

    # Bugzilla 30650 Start
    # Convert -1 to 0xFFFF so that when PERL passes parameter to C, it is insured to be 0xFFFF
    if ($PLvalue == -1) {$PLvalue=0xFFFF;}
    if ($QLvalue == -1) {$QLvalue=0xFFFF;}
    if ($PCvalue == -1) {$PCvalue=0xFFFF;}
    if ($QCvalue == -1) {$QCvalue=0xFFFF;}
    # Bugzilla 30650 End


print("get_line_client_params()  PLvalue = $PLvalue, QLvalue = $QLvalue\n");
print("                          PCvalue = $PCvalue, QCvalue = $QCvalue\n");

    if(clocks_get_bps($line_identifier) == clocks_get_bps($client_identifier)) {
        $line_client_rate_equal = 1;
    }
    else {
        $line_client_rate_equal = 0;
    }

    if($line_type eq $client_type) {
      $line_client_same = 1;
    }
    else {
      $line_client_same = 0;
    }
    
    if (($line_type eq 'otu3+') and ($line_fec eq 'nofec')) {
      $PLvalue = 239;
    }
    elsif (($line_type eq 'otu3+') and ($line_fec ne 'nofec')) {
      $PLvalue = 255;
    }
    elsif(($line_type eq 'otu3e') || ($line_type eq 'otu3e1')) {
      $QCvalue = 239;
    }

    if($mode eq 'trans40') {
      # Bugzilla 27167 Start
      if (($line_type =~ /otu3/) && ($client_type =~ /otu3/)) {
        if ($xcon_client_type ne $client_type) {
          if ($line_type eq 'otu3+') {
            $QLvalue = 236;  # Value in table is incorrect for this mode
          }
        }
        elsif (($line_type eq 'otu3+') and ($client_type eq 'otu3')) {
          # ODU3 accross the cross connect
          $PLvalue = 255;
          $QLvalue = 226;
          $PCvalue = 255;
          $QCvalue = 239;
        }
        # Bugzilla 29481 Start
        elsif (($line_type eq 'otu3e2') and ($client_type eq 'otu3')) {
          # ODU3 accross the cross connect
          $PLvalue = 255;
          $QLvalue = 239;
          $PCvalue = 255;
          $QCvalue = 239;
        }
        # Bugzilla 29481 End
      }
      # Bugzilla 27167 End
      elsif ($line_type eq 'otu3e3') {
        $PCvalue = 243;
        $PLvalue = 263;
      }
      elsif ($sync == 0) {
        # Async mode
        $PCvalue = 238;
      }
    }

    print("line_type              = $line_type\n");
    print("client_type            = $client_type\n");
    print("line_identifier        = $line_identifier\n");
    print("client_identifier      = $client_identifier\n");
    print("line_client_rate_equal = $line_client_rate_equal\n");
    print("line_client_same       = $line_client_same\n");

    return ($PLvalue, $QLvalue, $PCvalue, $QCvalue, $line_client_same, $line_client_rate_equal);
}

###############################################################################
# Get syncdsync parameters
# Parameter list
#       mode    mux, trans10, trans40
###############################################################################
sub get_syncdsync_params {
    my ($line_type, $client_type, $mode, $sync, $xcon_client_type, $pre_line, $pre_client,
        $map_oxuv_enum, $map_odtu_enum, $ra_10ge_odu2e_mode) = @_; # Bugzilla 28006

    print("get_syncdsync_params()\n");
    print("    line_type          = $line_type\n");
    print("    client_type        = $client_type\n");
    print("    pre_line           = $pre_line\n");
    print("    pre_client         = $pre_client\n");
    print("    xcon_client_type   = $xcon_client_type\n");
    print("    map_oxuv_enum      = $map_oxuv_enum\n");
    print("    map_odtu_enum      = $map_odtu_enum\n");
    print("    sync               = $sync\n");
    print("    ra_10ge_odu2e_mode = $ra_10ge_odu2e_mode\n");
    
    my $num_just_odu2=0; my $num_pjo_odu2=1; my $num_fs_odu2=0; my $num_c15_odu2=0;
    my $num_just_odu3=0; my $num_pjo_odu3=1; my $num_fs_odu3=0; my $num_c15_odu3=0;
    my $num_just_odtu23=0; my $num_pjo_odtu23=1; my $num_fs_odtu23=0; my $num_c15_odtu23=0;
    my $num_just_odu3_client=0; my $num_pjo_odu3_client=1; my $num_fs_odu3_client=0; my $num_c15_odu3_client=0;
    my $num_fs1=0; my $num_fs2=0;

    if (($mode eq 'trans10') || ($mode eq 'lb10') || ($mode eq 'kpga10') || ($mode eq 'cbr_kpga10') ||
        ($mode eq 'hsif_kpga10') || ($mode eq 'pbert10') || ($mode eq 'wire10')) {
      if (($client_type ne 'pbert_8gfc') && ($client_type !~ /gfc_ra/) &&
          ($client_type ne 'pbert_4gfc') && ($client_type ne 'pbert_2gfc') &&
          ($client_type ne 'pbert_10gfc') && ($client_type !~ /pbert_10ge/)){
        ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, $line_type, $map_oxuv_enum);
        $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
      }
    }
    elsif (($mode eq 'trans40') || ($mode eq 'lb40') || ($mode eq 'kpga40') ||
           ($mode eq 'hsif_kpga40') || ($mode eq 'cbr_kpga40') || ($mode eq 'wire40')) {
        if($sync) {
            ($num_pjo_odu3, $num_fs_odu3, $num_c15_odu3) = get_syncdsync_oxu3($client_type, $line_type, $map_oxuv_enum);
            $num_just_odu3 = $num_fs_odu3 + $num_c15_odu3;
        }
        else {
            if($client_type =~ /otu3/) {
                # Bugzilla 27167 Start
                # Bugzilla 28006 Start
                # Mapping on line and client sides may be different
                if ($xcon_client_type =~ /40ge/) {
                    # Client in payload is 40GE, so use pre_line and pre_client
                    ($num_pjo_odu3_client, $num_fs_odu3_client, $num_c15_odu3_client) = get_syncdsync_oxu3($pre_client, $client_type, $map_oxuv_enum);
                    $num_just_odu3_client = $num_fs_odu3_client==0 ? $num_c15_odu3_client : $num_fs_odu3_client;

                    ($num_pjo_odu3, $num_fs_odu3, $num_c15_odu3) = get_syncdsync_oxu3($pre_line, $line_type, $map_odtu_enum);
                    $num_just_odu3 = $num_fs_odu3==0 ? $num_c15_odu3 : $num_fs_odu3;
                } else {
                    ($num_pjo_odu3_client, $num_fs_odu3_client, $num_c15_odu3_client) = get_syncdsync_oxu3($xcon_client_type, $client_type, $map_oxuv_enum);
                    $num_just_odu3_client = $num_fs_odu3_client==0 ? $num_c15_odu3_client : $num_fs_odu3_client;

                    ($num_pjo_odu3, $num_fs_odu3, $num_c15_odu3) = get_syncdsync_oxu3($xcon_client_type, $line_type, $map_odtu_enum);
                    $num_just_odu3 = $num_fs_odu3==0 ? $num_c15_odu3 : $num_fs_odu3;
                }
                # Bugzilla 278006 End
                # Bugzilla 27167 End
            }
            else {
                # Bugzilla 28254 Start
                if ($xcon_client_type =~ /40ge/) {
                    # Client is 40GE, so use pre_line
                    ($num_pjo_odu3, $num_fs_odu3, $num_c15_odu3) = get_syncdsync_oxu3($pre_line, $line_type, $map_oxuv_enum);
                    $num_just_odu3 = $num_fs_odu3==0 ? $num_c15_odu3 : $num_fs_odu3;
                } else {
                    ($num_pjo_odu3, $num_fs_odu3, $num_c15_odu3) = get_syncdsync_oxu3($client_type, $line_type, $map_oxuv_enum);
                    $num_just_odu3 = $num_fs_odu3 + $num_c15_odu3;
                }
                # Bugzilla 28254 End
            }
        }
    }
    elsif ($mode eq 'mux') {
        if($client_type eq 'otu3') {
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu3('odu2', $client_type, $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
            ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', $line_type, $map_odtu_enum);
            $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        # Bugzilla 29100 Start
        if($client_type eq 'otu3e2') {
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu3('odu2e', $client_type, $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
            ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2e', $line_type, $map_odtu_enum);
            $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        # Bugzilla 29100 End
        if(($client_type eq 'oc192') || ($client_type eq 'oc192_async'))  {
            if($client_type eq 'oc192_async')  {
              $client_type = 'oc192';
              $line_type .= 'dj';
            }
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        if($client_type eq 'oc192_async') {
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
            ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', 'otu3dj', $map_odtu_enum);
            $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        if($client_type eq '10ge7_1') {
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2e', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2e', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        if($client_type eq '10ge7_2') {
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu1e', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu1e', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        if($client_type eq '10ge7_3') {
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        if($client_type eq '10ge6_1') {
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        if($client_type eq '10ge6_2') {
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        if($client_type eq '10ge_gfpf_oc192_odu2') {
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        if($client_type eq '10ge_ra') {
            if ($ra_10ge_odu2e_mode eq 1) {
              ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2e', $map_oxuv_enum);
            }
            else {
              ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2', $map_oxuv_enum);
            }
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
              if ($ra_10ge_odu2e_mode eq 1) {
                  ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2e', $line_type, $map_odtu_enum);
              }
              else {              
                  ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', $line_type, $map_odtu_enum);
              }
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        if($client_type eq 'otu2') {
            $num_pjo_odu2 = 1;
            if(($map_odtu_enum == main::TEN_MAP_CUST_PROP) || ($map_odtu_enum == main::TEN_MAP_CUST_PROP_DT)) {
              ($num_pjo_odtu23, $num_fs1, $num_fs2) = get_syncdsync_cust_oxu3('odu2', $line_type);
            }
            else {
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
            }
        }
        if($client_type eq 'otu2e') {
            $num_pjo_odu2 = 1;
            if(($map_odtu_enum == main::TEN_MAP_CUST_PROP) || ($map_odtu_enum == main::TEN_MAP_CUST_PROP_DT)) {
              ($num_pjo_odtu23, $num_fs1, $num_fs2) = get_syncdsync_cust_oxu3('odu2e', $line_type);
            }
            else {
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2e', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
            }
        }
        if($client_type eq 'otu1e') {
            $num_pjo_odu2 = 1;
            if(($map_odtu_enum == main::TEN_MAP_CUST_PROP) || ($map_odtu_enum == main::TEN_MAP_CUST_PROP_DT)) {
              ($num_pjo_odtu23, $num_fs1, $num_fs2) = get_syncdsync_cust_oxu3('odu1e', $line_type);
            }
            else {
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu1e', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
            }
        }
        if($client_type =~ /10gfc_tc/) { # Bug 31054
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2e', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
              ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2e', $line_type, $map_odtu_enum);
              $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
        }
        if( ($client_type =~ /gfc_enh/) ||
           (($client_type =~ /gfc/) && ($map_oxuv_enum == main::TEN_MAP_GMP_LO)) || # Bug 38520
            ($client_type eq '2gisc') || ($client_type eq '1ge') ) {                # Bug 39003
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
            if ($line_type eq 'otu3p2') {
                # Special case to make it fit
                ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', 'otu3p2dj', $map_odtu_enum);
                $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
            } else {
                ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', $line_type, $map_odtu_enum);
                $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
            }
        }
        # Bugzilla 38565 Start
        if($client_type =~ /iba/) {
            ($num_pjo_odu2, $num_fs_odu2, $num_c15_odu2) = get_syncdsync_oxu2($client_type, 'otu2e', $map_oxuv_enum);
            $num_just_odu2 = $num_fs_odu2==0 ? $num_c15_odu2 : $num_fs_odu2;
            if ($line_type eq 'otu3p2') {
                # Special case to make it fit
                ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2', 'otu3p2dj', $map_odtu_enum);
                $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
            } else {
                ($num_pjo_odtu23, $num_fs_odtu23, $num_c15_odtu23) = get_syncdsync_oxu3('odu2e', $line_type, $map_odtu_enum);
                $num_just_odtu23 = $num_fs_odtu23==0 ? $num_c15_odtu23 : $num_fs_odtu23;
            }
        }
        # Bugzilla 38565 End
    }
    else {
      print("Incorrect map type; must be mux|trans10|trans40");
      die;
    }
    if(($mode eq 'mux') or ($mode eq 'trans10') or ($mode eq 'wire10')) {
        return ($num_just_odu2, $num_pjo_odu2, $num_just_odtu23, $num_pjo_odtu23, $num_just_odu3_client, $num_pjo_odu3_client, $num_fs1, $num_fs2);   # Bugzilla 27995
    }
    else {
        return ($num_just_odu2, $num_pjo_odu2, $num_just_odu3, $num_pjo_odu3, $num_just_odu3_client, $num_pjo_odu3_client);
    }
}

##############################################################################
# Function: wait_enter_key
#           Wait for the Enter key to be pressed
##############################################################################
sub wait_enter_key {

    print ("Press Enter to continue\n");

    while (<STDIN>) {
        #if($_ ne ""){
        #    last;
        #}
        if($_ eq "\n"){
            last;
        }
        else{
            #misc_info("Invalid entry.  Press enter to continue\n");
            print("Invalid entry.  Press enter to continue\n");
        }
    }
}

##############################################################################
# Function:     config_release_reset_trans40_wire40
#               Release reset sequence for 40G transponder and 40G Wire configs
#
# Parameters:
#   dev_id                int - Device ID returned by ten_dev_main_init
#   mod_line              int - 0 = MODULE_A, 1 = MODULE_B
#   mod_client            int - 0 = MODULE_A, 1 = MODULE_B
#   client_type           str - cbr40g50188149150, 40gelan, oc768
#   client_fec_type       str - ufec7p, ufec7p_sdhaufec10p, ufec12p, ufec13p,
#                               ufec15p, ufec20p, ufec25p, ufec26p, gfec, 0fec,
#                               nofec
#   sync                  int - 0 = ASYNC, 1 = SYNC
#   provision_line        int - 1 = Initial config, 0 = Dynamic reprovisiontrans40
#   gpllx1_inst_line      int - 1 = RX MODULE_A
#   gpllx1_inst_client    int - 9 = RX MODULE_B
#   term_type             str - ocx : trans, transregen, rsregen, msregen
#                               otu : transparent, section, full
#
# Returns:      Error Code
##############################################################################
 sub config_release_reset_trans40_wire40 {
     my ($dev_id, $mod_line, $mod_client, $client_type, $client_fec_type, $sync,
         $provision_line, $provision_client,$gpllx1_inst_line, $gpllx1_inst_client, $term_type,    # Bugzilla 29609
         $hsif_client, $hsif_line, $deskew_ctrl, $xcon_client_type) = @_;  # Bugzilla 28006

    my $mod_a = ($dev_id << 8) | main::TEN_MODULE_A;
    my $mod_b = ($dev_id << 8) | main::TEN_MODULE_B;

    if ($client_type ne 'null') {
        # Remove SW resets
        # Bugzilla 29609 Start
        if ($provision_line) {
            main::ten_n40g_set_global_resets($mod_line, main::CS_RESET_DEASSERT, main::TEN_N40G_GLOBAL_RESETS_ALL );
        }
        if ($provision_client) {
            main::ten_n40g_set_global_resets($mod_client, main::CS_RESET_DEASSERT, main::TEN_N40G_GLOBAL_RESETS_ALL );
        }
        # Bugzilla 29609 End

        # Take N10G blocks out of software reset
        for (my $i=0; $i<4; $i++) {
            main::ten_n10g_set_global_resets ($mod_line, $i, main::CS_RESET_DEASSERT, main::TEN_N10G_GLOBAL_RESETS_ALL);
            main::ten_n10g_set_global_resets ($mod_client, $i, main::CS_RESET_DEASSERT, main::TEN_N10G_GLOBAL_RESETS_ALL);
        }

        # PP10G TX block is in reset
        main::ten_xcon_datapath_reset ($dev_id, main::CS_RESET_DEASSERT);

        # Bring all XCON data paths out of software reset
        for (my $i=0; $i<8; $i++) {
            main::ten_xcon_es_reset ($dev_id, $i, main::CS_RESET_DEASSERT);
        }

        # PP10G RX block is in reset

        # Take SyncDstbc slot 0 and 3 for Monolithic
        main::ten_hl_resets_block ($mod_line, 0, main::CS_RESET_DEASSERT, main::TEN_HL_RESETS_BLOCK_SYNCDSYNC);
        main::ten_hl_resets_block ($mod_client, 0, main::CS_RESET_DEASSERT, main::TEN_HL_RESETS_BLOCK_SYNCDSYNC);

        if ($sync == 0) {
            main::ten_hl_resets_block ($mod_line, 3, main::CS_RESET_DEASSERT, main::TEN_HL_RESETS_BLOCK_SYNCDSYNC);
        }

        # Bugzilla 31850 Start
        if ($hsif_client eq 'xfi') {
            main::ten_syncdsynctx_control_sreset($mod_client, 2, main::CS_RESET_DEASSERT);
        }
        # Bugzilla 31850 End

        # Support CFP MRA with protection switch to MRB
        if ((($mod_line&1) == 0) and ($hsif_line eq 'cfp_mr')) {
          printf("CFP A line\n");
          main::ten_mpif_global_reset_syncdsync($dev_id, main::TEN_MODULE_B, main::TEN_SLICE_ALL, main::CS_TX_AND_RX,
                                            main::CS_RESET_DEASSERT);
          main::ten_hl_resets_block (($dev_id <<8) | main::TEN_MODULE_B, 0, main::CS_RESET_DEASSERT, main::TEN_HL_RESETS_BLOCK_SYNCDSYNC);
          main::ten_mpif_global_reset_hsif ($dev_id, main::TEN_MODULE_B, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);
        }

        # Support CFP MRA with protection switch to MRB
        if ((($mod_client&1) == 0) and ($hsif_client eq 'cfp_mr')) {
          printf("CFP A client\n");
          main::ten_mpif_global_reset_syncdsync($dev_id, main::TEN_MODULE_B, main::TEN_SLICE_ALL, main::CS_TX_AND_RX,
                                            main::CS_RESET_DEASSERT);
          main::ten_hl_resets_block(($dev_id <<8) | main::TEN_MODULE_B, 0, main::CS_RESET_DEASSERT, main::TEN_HL_RESETS_BLOCK_SYNCDSYNC);
          main::ten_mpif_global_reset_hsif ($dev_id, main::TEN_MODULE_B, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);
        }

        # Remove PP40G Resets
        if (($client_type eq '40gep') or ($client_type eq '40gep_ra') or
            ($client_type eq '40gesbi') or ($client_type eq '40gesbi_ra') or
            ($client_type eq '40gex') or ($client_type eq '40gex_ra') or
            ($client_type eq '40ges6466') or ($client_type eq '40ges6466_ra') or
            ($xcon_client_type =~ /40ge/)) { # Bugzilla 28006
          main::ten_pp40g_pcs_tx_control_sreset_t41($mod_line, main::CS_RESET_DEASSERT);
          main::ten_pp40g_pcs_tx_control_sreset_t41($mod_client, main::CS_RESET_DEASSERT);

          main::ten_pp40g_mac_rx_control_sreset_t41($mod_line, main::CS_RESET_DEASSERT);
          main::ten_pp40g_rs_rx_control_sreset_t41($mod_line, main::CS_RESET_DEASSERT);
          main::ten_pp40g_pcs_rx_control_sreset_t41($mod_line, main::CS_RESET_DEASSERT);
          main::ten_pp40g_lif_rx_control_sreset_t41($mod_line, main::CS_RESET_DEASSERT);
          main::ten_pp40g_pm_control_sreset_t41($mod_line, main::CS_RESET_DEASSERT);

          main::ten_pp40g_mac_rx_control_sreset_t41($mod_client, main::CS_RESET_DEASSERT);
          main::ten_pp40g_rs_rx_control_sreset_t41($mod_client, main::CS_RESET_DEASSERT);
          main::ten_pp40g_pcs_rx_control_sreset_t41($mod_client, main::CS_RESET_DEASSERT);
          main::ten_pp40g_lif_rx_control_sreset_t41($mod_client, main::CS_RESET_DEASSERT);
          main::ten_pp40g_pm_control_sreset_t41($mod_client, main::CS_RESET_DEASSERT);
        }

        main::ten_mpif_set_clock_switch_force ($dev_id, main::TEN_MODULE_A_AND_B, main::TEN_SLICE_ALL, main::CS_TX_AND_RX, main::CS_DISABLE);

        # Only reset CUPLL if XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_FRAC_CTRL.STXP_FRAC_EN for slice 2 (offset 0x800) == 1
        ####    if (tenabo_bf_read($dev_id,main::TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_STXP0_FRAC_CTRL+0x800,0,0) == 1) {
        if (main::ten_xfi32x1_get_stxp0_frac_ctrl_frac_en(($dev_id<<8)|main::TEN_MODULE_B, 2) == 1) {
          main::ten_cupll_reset_t41($mod_client, 2, main::TEN_XFI_CUPLL_RESET_CUPLL_DIG, main::CS_RESET_TOGGLE);
        }

        main::ten_mpif_global_reset_hsif ($dev_id, main::TEN_MODULE_A_AND_B, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);

        # Wait for First SERDES lock
        if($hsif_line eq 'xfi') {
            for(my $i=0; $i<4; $i++) {
                if (check_xfi_filt_lock ($mod_line, $i) != main::CS_OK) {
                    print("Script continuing with WARNING, config_release_reset_trans40_wire40: First xfi_filt_lock failed on Line side (Side $mod_line)\n");
                }
            }
        }
        elsif ($hsif_line eq 'cfp_mr') {
            if (check_cfp_mr_filt_lock_40g($mod_line)) {
                print("Script continuing with WARNING, config_release_reset_trans40_wire40: First cfp_mr_filt_lock failed on Line side (Side $mod_line)\n");
            }
        }
        else {
          if (check_mr_filt_lock_40g ($mod_line)) {
              print("Script continuing with WARNING, config_release_reset_trans40_wire40: First mr_filt_lock failed on Line side (Side $mod_line)\n");
          }
        }

        if($hsif_client eq 'xfi') {
            for(my $i=0; $i<4; $i++) {
                if (check_xfi_filt_lock ($mod_client, $i) != main::CS_OK) {
                    print("Script continuing with WARNING, config_release_reset_trans40_wire40: First xfi_filt_lock failed on Client side (Side $mod_client)\n");
                }
            }
        }
        elsif ($hsif_client eq 'cfp_mr') {
            if (check_cfp_mr_filt_lock_40g($mod_client)) {
                print("Script continuing with WARNING, config_release_reset_trans40_wire40: First cfp_mr_filt_lock failed on Client side (Side $mod_client)\n");
            }
        }
        else {
            if (check_mr_filt_lock_40g ($mod_client)) {
                print("Script continuing with WARNING, config_release_reset_trans40_wire40: First mr_filt_lock failed on Client side (Side $mod_client)\n");
            }
        }

        #sleep(5);

        ###### Reset the optical module - a glitch during the change of SiLabs modes
        ######        may lock up the optical module TX
        if (!main::ten_dev_is_ws_in_progress($dev_id)) {
          main::dev_reg_write ( 432, 0, 0x5000, 0x80a );
          main::dev_reg_write ( 432, 0, 0x5400, 0x80a );
          #sleep (5);
          sleep (1);  # Bugzilla 28977
          main::dev_reg_write ( 432, 0, 0x5000, 0x803 );
          main::dev_reg_write ( 432, 0, 0x5400, 0x803 );
          sleep (1);  # Bugzilla 28977
        }
        ################################################################################
        #misc_info("wait for GPLL lock");
        ################################################################################
        #if (config_waitfor_gpll_lock != 0) {
        #  return misc_exit;
        #}
        main::ten_hl_gpllx1_waitfor_gpll_lock_40g($dev_id, $gpllx1_inst_line);
        main::ten_hl_gpllx1_waitfor_gpll_lock_40g($dev_id, $gpllx1_inst_client);

        # Wait for Second SERDES lock
        if($hsif_line eq 'xfi') {
            for(my $i=0; $i<4; $i++) {
                if (check_xfi_filt_lock ($mod_line, $i) != main::CS_OK) {
                    print("Script continuing with WARNING, config_release_reset_trans40_wire40: Second xfi_filt_lock failed on Line side (Side $mod_line)\n");
                }
            }
        }
        elsif ($hsif_line eq 'cfp_mr') {
            if (check_cfp_mr_filt_lock_40g($mod_line)) {
                print("Script continuing with WARNING, config_release_reset_trans40_wire40: Second cfp_mr_filt_lock failed on Line side (Side $mod_line)\n");
            }
        }
        else {
          if (check_mr_filt_lock_40g ($mod_line)) {
              print("Script continuing with WARNING, config_release_reset_trans40_wire40: Second mr_filt_lock failed on Line side (Side $mod_line)\n");
          }
        }

        if($hsif_client eq 'xfi') {
            for(my $i=0; $i<4; $i++) {
                if (check_xfi_filt_lock ($mod_client, $i) != main::CS_OK) {
                    print("Script continuing with WARNING, config_release_reset_trans40_wire40: Second xfi_filt_lock failed on Client side (Side $mod_client)\n");
                }
            }
        }
        elsif ($hsif_client eq 'cfp_mr') {
            if (check_cfp_mr_filt_lock_40g($mod_client)) {
                print("Script continuing with WARNING, config_release_reset_trans40_wire40: Second cfp_mr_filt_lock failed on Client side (Side $mod_client)\n");
            }
        }
        else {
            if (check_mr_filt_lock_40g ($mod_client)) {
                print("Script continuing with WARNING, config_release_reset_trans40_wire40: Second mr_filt_lock failed on Client side (Side $mod_client)\n");
            }
        }

        #if (($client_type ne '40gep') and ($client_type ne '40gep_ra') and
        #    ($client_type ne '40gesbi') and ($client_type ne '40gesbi_ra') and
        #    ($client_type ne '40gex') and ($client_type ne '40gex_ra') and
        #    ($client_type ne '40ges6466') and ($client_type ne '40ges6466_ra')) {
        if ($deskew_ctrl == main::TEN_SADECO_DESKEW) { # Bugzilla 28006
          ####################################################################################
          #misc_info("Toggle Sadeco soft reset now that N10G and N40G TX blocks are configured and clocked");
          ####################################################################################
          # Toggle Soft reset now that N10G and N40G TX blocks are configured and clocked
          main::ten_xcon_sadeco_reset ($dev_id, $mod_line,   main::XCON_BLOCK_RESET, main::CS_RESET_TOGGLE);
          main::ten_xcon_sadeco_reset ($dev_id, $mod_client, main::XCON_BLOCK_RESET, main::CS_RESET_TOGGLE);

          # Reset Afifo's to sync their fill level
          main::ten_xcon_sadeco_reset ($dev_id, $mod_line,   main::XCON_FIFO_RESET, main::CS_RESET_TOGGLE);
          main::ten_xcon_sadeco_reset ($dev_id, $mod_client, main::XCON_FIFO_RESET, main::CS_RESET_TOGGLE);

          # Wait for SADECO 0 to be in SYNC
          if (main::ten_xcon_sadeco_sadstat ($dev_id, $mod_line) != 1) {
              failure("SADECO Line Side is not in SYNC");
              print ("SADECO Line Side is not in SYNC\n");
              #return 1;
          }

          sleep 2;

          #if (($client_type eq 'cbr40g41250000000') or ($client_type eq 'cbr40g50188149150') or ($client_type eq 'cbr40g39813120000') or
          if (($client_type eq 'cbr40g50188149150') or
              #(($client_type eq '40gelan') and ($term_type eq 'trans')) or
              ($client_type eq '40gelan') or
              (($client_type eq 'oc768') and ($term_type eq 'trans'))) {
              #(($client_type eq 'oc768') and ($term_type eq 'trans')) or
              # (($client_type eq 'otu3') and ($sync == 0) )) {
              print ("Apply Async Unframed SADECO Workaround\n");

              # Must apply anync unframed sadeco workaround
              if (check_n40g_otn_inframe($mod_line)) {
                  failure("Line side N40g is not in frame so ten_hl_n40g_async_dewrap_generic_40g_client_sw_workaround() can not be run!!!");
                  #return 1;
              }
              ###############################################################################
              # misc_info("Software work-around - turns SADECO Resyncing off");
              ###############################################################################
              print ("ten_hl_n40g_async_dewrap_generic_40g_client_sw_workaround() !\n");
              main::ten_hl_n40g_async_dewrap_generic_40g_client_sw_workaround ($mod_line, $mod_client);
          }

          # Clear SADECO interrupts
          ####    main::ten_reg_write ($dev_id, main::TEN_XCON_SADECO_SADINT,           0xffff);
          ####    main::ten_reg_write ($dev_id, main::TEN_XCON_SADECO_SADINT + (0x40),  0xffff);
          main::ten_xcon_sadeco_sadint($dev_id, main::TEN_MODULE_A, 1, 0xF, 1);
          main::ten_xcon_sadeco_sadint($dev_id, main::TEN_MODULE_B, 1, 0xF, 1);
          sleep 2;

          ################################################################################
          # misc_info("check for SADECO 1 in SYNC");
          ################################################################################
          if (main::ten_xcon_sadeco_sadstat ($dev_id, $mod_client) != 1) {
              failure("SADECO Client Side is not in SYNC");
              print ("ADECO Client Side is not in SYNC\n");
              #return 1;
          }

          #####    if (tenabo_bf_read($dev_id,main::main::TEN_XCON_SADECO_SADINT,0,0) == 0) {
          if (main::ten_xcon_get_sadeco_sadint_synci($dev_id, main::TEN_MODULE_A) == 0) {
              print ("SADECO Side A staying in Sync\n");
          }
          else {
              failure("SADECO Side A not staying in Sync!");
              print ("SADECO Side A not staying in Sync!\n");
              #return 1;
          }
        # Bugzilla 28977 Start
        } 
        elsif ($deskew_ctrl == main::TEN_PP40G_BYPASS_DESKEW) {
          # Clock and enable PP40 Bypass Deskew
          main::ten_pp40g_misc_pp40g_deskew_en_t41 ($mod_line);
          main::ten_pp40g_misc_pp40g_deskew_en_t41 ($mod_client);

          # Reset the XCON Elastic Stores
          main::ten_xcon_glb_pp40g_config_t41 ($dev_id, main::TEN_MODULE_A_AND_B, main::XCON_GLB_PP40G_CFG_RESET, 1);  # Bugzilla 28977
          main::ten_xcon_glb_pp40g_config_t41 ($dev_id, main::TEN_MODULE_A_AND_B, main::XCON_GLB_PP40G_CFG_RESET, 0);

          sleep 1;

          # Recenter the XCON Elastic Stores
          main::ten_xcon_glb_pp40g_config_t41 ($dev_id, main::TEN_MODULE_A_AND_B, main::XCON_GLB_PP40G_CFG_RECENTER, 1);  # Bugzilla 28977
          main::ten_xcon_glb_pp40g_config_t41 ($dev_id, main::TEN_MODULE_A_AND_B, main::XCON_GLB_PP40G_CFG_RECENTER, 0);


          if (main::ten_pp40g_misc_intstatus_rx_dsk_syncs_t41 (($dev_id<<8) | main::TEN_MODULE_A) == 0) {
              failure("DESKEW Side A not staying in Sync!");
          }
          else {
              print ("DESKEW Side A in Sync\n");
          }

          if (main::ten_pp40g_misc_intstatus_rx_dsk_syncs_t41 (($dev_id<<8) | main::TEN_MODULE_B) == 0) {
              failure("DESKEW Side B not staying in Sync!");
          }
          else {
              print ("DESKEW Side B in Sync\n");
          }

          # Clear Bypass Deskew interrupts
          ####    main::ten_reg_write ($dev_id, main::TEN_PP40G_MISC_INTERRUPT, 0xffff);
          ####    main::ten_reg_write ($dev_id, main::TEN_PP40G_MISC_INTERRUPT + main::TEN_PP40G_STRIDE, 0xffff);
          main::ten_pp40g_misc_interrupt_rx_dsk_synci_t41(($dev_id<<8) | main::TEN_MODULE_A, 1);
          main::ten_pp40g_misc_interrupt_rx_dsk_synci_t41(($dev_id<<8) | main::TEN_MODULE_B, 1);

          # Clear N40G TX Deskew interrupts
          main::ten_n40g_gbl4x_gblint (($dev_id<<8) | main::TEN_MODULE_A, main::TEN_INT_CLEAR, main::TEN_N40G_GBL4X_GBLINT_TXDSKERR);
          main::ten_n40g_gbl4x_gblint (($dev_id<<8) | main::TEN_MODULE_B, main::TEN_INT_CLEAR, main::TEN_N40G_GBL4X_GBLINT_TXDSKERR);

        }
        # Bugzilla 28977 End

        ###############################################################################
        # misc_info("Select software toggle for global timing source");
        ###############################################################################
        main::ten_n40g_sdfr_select_global_timing_source ($mod_line, 6);   # Selects one of the eight global timing sources   EOFCFG = SW = 6

        if ($client_fec_type =~ /ufec/) {
            main::ten_ufec_select_global_timing_source ($mod_client, ($mod_client & 1), 6);   # Selects one out of eight different statistics timing generators
        }
        # Global Statistics unit 0 Time Interval Base
        ## tenabo_bf_write ($dev_id, main::TEN_GLB_MISC_GSTI01, 0x17D7, 15, 0);
        ## tenabo_bf_write ($dev_id, main::TEN_GLB_MISC_GSTI00, 0x8400, 15, 0);
        main::ten_glb_misc_set_gsti($dev_id, 0, 0x17D7, 0x8400);

        ## tenabo_bf_write ($dev_id, main::TEN_MPIF_GLOBAL_RESET_COMMON, 0, 5, 5); # Hard reset top level XLOS & GSTI logic on system clock
        main::ten_mpif_global_reset_common($dev_id, main::CS_RESET_DEASSERT, main::TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS);
        sleep 1;
    }
}

##############################################################################
# Function:     config_release_reset_lb40_kpga40_cbrkpga40
#               Release reset sequence for 40G Loopback and 40G KPGA configs
#
# Parameters:
#   dev_id                int - Device ID returned by ten_dev_main_init
#   module_id_lb_kpga     int - Value returned by ten_mod_main_init for Module A
#   line_type             str - Any string but 'invalid'
#   mode                  str - kpga40, cbrkpga40
#   gpllx1_inst_line      int - 1 = RX MODULE_A
#   gpllx1_inst_client    int - 9 = RX MODULE_B
#
# Returns:      Error Code
##############################################################################
sub config_release_reset_lb40_kpga40 {
    my($dev_id, $module_id_lb_kpga, $line_type, $mode,
       $gpllx1_inst_line, $gpllx1_inst_client, $hsif, $deskew_ctrl) = @_;

    print("config_release_reset_lb40_kpga40($dev_id, $module_id_lb_kpga, $line_type, $mode, $gpllx1_inst_line, $gpllx1_inst_client, $hsif)\n");
    main::ten_print("config_release_reset_lb40_kpga40($dev_id, $module_id_lb_kpga, $line_type, $mode, $gpllx1_inst_line, $gpllx1_inst_client, $hsif)\n");

    my $module_lb_kpga = (($module_id_lb_kpga & 1) == 0) ? main::TEN_MODULE_A : main::TEN_MODULE_B;

    main::ten_n40g_set_global_resets ($module_id_lb_kpga, main::CS_RESET_DEASSERT, main::TEN_N40G_GLOBAL_RESETS_ALL);

    # Take N10G blocks out of software reset
    for (my $i=0; $i<4; $i++) {
        main::ten_n10g_set_global_resets ($module_id_lb_kpga, $i, main::CS_RESET_DEASSERT, main::TEN_N10G_GLOBAL_RESETS_ALL);
    }

    # PP10G TX block is in reset
    main::ten_xcon_datapath_reset ($dev_id, main::CS_RESET_DEASSERT);

    # Bring all XCON data paths out of software reset
    for (my $i=0; $i<8; $i++) {
        main::ten_xcon_es_reset ($dev_id, $i, main::CS_RESET_DEASSERT);
    }

    # PP10G RX block is in reset

    # Take SyncDstbc slot 0 and 3 for Monolithic
    # fix bus errors, take this out of hard reset
    main::ten_mpif_global_reset_syncdsync($dev_id, $module_lb_kpga, main::TEN_SLICE_ALL, main::CS_TX_AND_RX,
                                          main::CS_RESET_DEASSERT);

    main::ten_hl_resets_block ($module_id_lb_kpga, 0, main::CS_RESET_DEASSERT, main::TEN_HL_RESETS_BLOCK_SYNCDSYNC);

    # Support CFP MRA with protection switch to MRB
    if ((($module_id_lb_kpga&1) == 0) and ($hsif eq 'cfp_mr')) {
      main::ten_mpif_global_reset_syncdsync($dev_id, main::TEN_MODULE_B, main::TEN_SLICE_ALL, main::CS_TX_AND_RX,
                                            main::CS_RESET_DEASSERT);
      main::ten_hl_resets_block (($dev_id <<8) | main::TEN_MODULE_B, 0, main::CS_RESET_DEASSERT, main::TEN_HL_RESETS_BLOCK_SYNCDSYNC);

      main::ten_mpif_global_reset_hsif ($dev_id, main::TEN_MODULE_B, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);
    }

    main::ten_mpif_set_clock_switch_force ($dev_id, $module_lb_kpga, main::TEN_SLICE_ALL, main::CS_TX_AND_RX, main::CS_DISABLE);
    main::ten_mpif_global_reset_hsif ($dev_id, $module_lb_kpga, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);

    # Wait for First SERDES lock
    if($hsif eq 'xfi') {
        for(my $i=0; $i<4; $i++) {
            if (check_xfi_filt_lock ($module_id_lb_kpga, $i) != main::CS_OK) {
                failure("First xfi_filt_lock failed on Client side (Side $module_id_lb_kpga)");
                #return 1;
            }
        }
    }
    elsif ($hsif eq 'cfp_mr') {
        if (check_cfp_mr_filt_lock_40g ($module_id_lb_kpga)) {
            failure("First cfp_mr_filt_lock failed on Client side (Side $module_id_lb_kpga)");
            #return 1;
        }
    }
    else {
        if (check_mr_filt_lock_40g ($module_id_lb_kpga)) {
            failure("config_release_reset_lb40_kpga40: First mr_filt_lock failed on Client side (Side $module_id_lb_kpga)");
            #return 1;
        }
    }


    #sleep(30);

    ###### Reset the optical module - a glitch during the change of SiLabs modes
    ######        may lock up the optical module TX
    main::dev_reg_write ( 432, 0, 0x5000, 0x80a );
    main::dev_reg_write ( 432, 0, 0x5400, 0x80a );
    #sleep (5);
    sleep (1);   # Bugzilla 28977
    main::dev_reg_write ( 432, 0, 0x5000, 0x803 );
    main::dev_reg_write ( 432, 0, 0x5400, 0x803 );
    sleep (1);  # Bugzilla 28977

    ################################################################################
    #misc_info("wait for GPLL lock");
    ################################################################################
    #if (config_waitfor_gpll_lock != 0) {
    #  return misc_exit;
    #}
    if (($line_type ne 'invalid')) {
        main::ten_hl_gpllx1_waitfor_gpll_lock_40g($dev_id, $gpllx1_inst_line);
    } else {
        main::ten_hl_gpllx1_waitfor_gpll_lock_40g($dev_id, $gpllx1_inst_client);
    }

    # Wait for Second SERDES lock
    if($hsif eq 'xfi') {
        for(my $i=0; $i<4; $i++) {
            if (check_xfi_filt_lock ($module_id_lb_kpga, $i) != main::CS_OK) {
                failure("Second xfi_filt_lock failed on Client side (Side $module_id_lb_kpga)");
                #return 1;
            }
        }
    }
    elsif ($hsif eq 'cfp_mr') {
        if (check_cfp_mr_filt_lock_40g($module_id_lb_kpga)) {
            failure("Second cfp_mr_filt_lock failed on Client side (Side $module_id_lb_kpga)");
            #return 1;
        }
    }
    else {
        if (check_mr_filt_lock_40g ($module_id_lb_kpga)) {
            failure("Second mr_filt_lock failed on Client side (Side $module_id_lb_kpga)");
            #return 1;
        }
    }



    if ($mode eq 'lb40') {
        if ($deskew_ctrl == main::TEN_SADECO_DESKEW) { # Bugzilla 28977
            ####################################################################################
            #misc_info("Toggle Soft reset now that traffic is flowing and sync afifo's SADECO");
            ####################################################################################
            # Toggle Soft reset now that traffic is flowing and sync afifo's SADEC
            main::ten_xcon_sadeco_reset ($dev_id, $module_lb_kpga, main::XCON_BLOCK_RESET, main::CS_RESET_TOGGLE);
            # Reset Afifo's to sync their fill level
            main::ten_xcon_sadeco_reset ($dev_id, $module_lb_kpga, main::XCON_FIFO_RESET, main::CS_RESET_TOGGLE);

            # Wait for SADECO on Client side to be in SYNC
            if (main::ten_xcon_sadeco_sadstat ($dev_id, $module_lb_kpga) != 1) {
                failure("SADECO Client Side is not in SYNC!!!!!!!");
                #return 1;
            }

            sleep 2;

            # Clear SADECO interrupts
            ####    main::ten_reg_write ($dev_id, main::TEN_XCON_SADECO_SADINT,           0xffff);
            ####    main::ten_reg_write ($dev_id, main::TEN_XCON_SADECO_SADINT + (0x40),  0xffff);
            main::ten_xcon_sadeco_sadint($dev_id, main::TEN_MODULE_A, 1, 0xF, 1);
            main::ten_xcon_sadeco_sadint($dev_id, main::TEN_MODULE_B, 1, 0xF, 1);
            sleep 2;

            if (main::ten_xcon_sadeco_sadstat ($dev_id, $module_lb_kpga) != 1) {
                failure("SADECO Client Side is not in SYNC");
                #return 1;
            }

            ####    if (tenabo_bf_read ($dev_id, main::main::TEN_XCON_SADECO_SADINT, 0, 0) == 0) {
            if (main::ten_xcon_get_sadeco_sadint_synci($dev_id, main::TEN_MODULE_A) == 0) {
                print ("SADECO Side A is staying in Sync\n");
            }
            else {
                failure("SADECO Side A is not staying in Sync!");
                #return 1;
            }
        # Bugzilla 28977 Start
        }
        else {    #???????????  What about TEN_PP40G_DESKEW

          # Clock and enable PP40 Bypass Deskew
          main::ten_pp40g_misc_pp40g_deskew_en_t41 ($module_lb_kpga);

          # Reset the XCON Elastic Stores
          main::ten_xcon_glb_pp40g_config_t41 ($dev_id, $module_lb_kpga, main::XCON_GLB_PP40G_CFG_RESET, 1);
          main::ten_xcon_glb_pp40g_config_t41 ($dev_id, $module_lb_kpga, main::XCON_GLB_PP40G_CFG_RESET, 0);

          sleep 1;

          # Recenter the XCON Elastic Stores
          main::ten_xcon_glb_pp40g_config_t41 ($dev_id, $module_lb_kpga, main::XCON_GLB_PP40G_CFG_RECENTER, 1);
          main::ten_xcon_glb_pp40g_config_t41 ($dev_id, $module_lb_kpga, main::XCON_GLB_PP40G_CFG_RECENTER, 0);


          if (main::ten_pp40g_misc_intstatus_rx_dsk_syncs_t41 ($module_lb_kpga) == 0) {
              failure("DESKEW Side $module_lb_kpga not staying in Sync!");
          } else {
              print ("DESKEW Side $module_lb_kpga in Sync\n");
          }

          # Clear Bypass Deskew interrupts
          ####    main::ten_reg_write ($dev_id, main::TEN_PP40G_MISC_INTERRUPT, 0xffff);
          ####    main::ten_reg_write ($dev_id, main::TEN_PP40G_MISC_INTERRUPT + main::TEN_PP40G_STRIDE, 0xffff);
          main::ten_pp40g_misc_interrupt_rx_dsk_synci_t41(($dev_id<<8) | main::TEN_MODULE_A, 1);
          main::ten_pp40g_misc_interrupt_rx_dsk_synci_t41(($dev_id<<8) | main::TEN_MODULE_B, 1);

          # Clear N40G TX Deskew interrupts
          main::ten_n40g_gbl4x_gblint ($module_lb_kpga, main::TEN_INT_CLEAR, main::TEN_N40G_GBL4X_GBLINT_TXDSKERR);
        }
        # Bugzilla 28977 End
    }

    ###############################################################################
    # misc_info("Select software toggle for global timing source");
    ###############################################################################
    main::ten_n40g_sdfr_select_global_timing_source ($module_id_lb_kpga, 6);   # Selects one of the eight global timing sources   EOFCFG = SW = 6

    ####    tenabo_bf_write ($dev_id, main::TEN_GLB_MISC_GSTI01, 0x17D7, 15, 0);
    ####    tenabo_bf_write ($dev_id, main::TEN_GLB_MISC_GSTI00, 0x8400, 15, 0);
    main::ten_glb_misc_set_gsti($dev_id, 0, 0x17D7, 0x8400);

    ####    tenabo_bf_write ($dev_id, main::TEN_MPIF_GLOBAL_RESET_COMMON, 0, 5, 5); # Hard reset top level XLOS & GSTI logic on system clock
    main::ten_mpif_global_reset_common($dev_id, main::CS_RESET_DEASSERT, main::TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS);

    sleep 1;
}


##############################################################################
# Function:     config_release_reset_lb10_kpga10_cbrkpga10
#               Release reset sequence for 10G Loopback and 10G KPGA configs
#
# Parameters:
#   dev_id                    int - Device ID returned by ten_dev_main_init
#   module_id_lb_kpga         int - Value returned by ten_mod_main_init for Module A
#   slice_lb_kpga             int - 0 - 3
#   lb_kpga_traffic_type_enum str - TEN_TRAFFIC_TYPE_NONE `               = 0
#                                   TEN_TRAFFIC_TYPE_OTU2                 = 5
#                                   TEN_TRAFFIC_TYPE_OTU2E                = 6
#                                   TEN_TRAFFIC_TYPE_OTU1F                = 7
#                                   TEN_TRAFFIC_TYPE_OC192                = 8
#                                   TEN_TRAFFIC_TYPE_10GE_WAN             = 9
#                                   TEN_TRAFFIC_TYPE_10GE_6_2             = 10
#                                   TEN_TRAFFIC_TYPE_10GE_7_1             = 11
#                                   TEN_TRAFFIC_TYPE_10GE_7_3             = 12
#                                   TEN_TRAFFIC_TYPE_10GFC                = 13
#                                   TEN_TRAFFIC_TYPE_8GFC                 = 14
#                                   TEN_TRAFFIC_TYPE_4GFC                 = 15
#                                   TEN_TRAFFIC_TYPE_2GFC                 = 16
#                                   TEN_TRAFFIC_TYPE_1GFC                 = 17
#                                   TEN_TRAFFIC_TYPE_5GB_IB               = 18
#                                   TEN_TRAFFIC_TYPE_10GE                 = 20
#                                   TEN_TRAFFIC_TYPE_10GE_6_1             = 26
#                                   TEN_TRAFFIC_TYPE_10GE_7_2             = 27
#                                   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28
#                                   TEN_TRAFFIC_TYPE_OTU1E                = 29
#                                   TEN_TRAFFIC_TYPE_10GE_RA              = 30
#                                   TEN_TRAFFIC_TYPE_OC192_OTU2           = 31
#                                   TEN_TRAFFIC_TYPE_10GE_TC              = 33
#   notest                    int - 1 = Do not use checkers
#   hsif_lb_kpga              str - sfi4_2, sfi5_1, xaui
#
# Returns:      Error Code
##############################################################################
sub config_release_reset_lb10_kpga10 {
    my($dev_id, $module_id_lb_kpga, $slice_lb_kpga,
       $lb_kpga_traffic_type_enum, $notest, $hsif_lb_kpga) = @_;

    print("config_release_reset_lb10_kpga10($dev_id, $module_id_lb_kpga, $slice_lb_kpga, $lb_kpga_traffic_type_enum, $notest, $hsif_lb_kpga)\n");

    my $module_lb_kpga = (($module_id_lb_kpga & 1) == 0) ? main::TEN_MODULE_A : main::TEN_MODULE_B;

    main::ten_hl_config_remove_module_soft_resets ($module_id_lb_kpga, $slice_lb_kpga, $lb_kpga_traffic_type_enum);

    # Support CFP MRA with protection switch to MRB
    if ((($module_id_lb_kpga&1) ==  main::TEN_MODULE_A) and ($hsif_lb_kpga eq 'cfp_mr')) {
 #     main::ten_mpif_global_reset_syncdsync($dev_id, main::TEN_MODULE_B, $slice_lb_kpga, main::CS_TX_AND_RX,
 #                                           main::CS_RESET_DEASSERT);
 #     main::ten_hl_resets_block (main::TEN_MODULE_B, 0, main::CS_RESET_DEASSERT, main::TEN_HL_RESETS_BLOCK_SYNCDSYNC);

      main::ten_mpif_global_reset_hsif ($dev_id, main::TEN_MODULE_B, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);
    }

    main::ten_mpif_set_clock_switch_force ($dev_id, $module_lb_kpga, $slice_lb_kpga, main::CS_TX_AND_RX, main::CS_DISABLE);
    main::ten_mpif_global_reset_hsif ($dev_id, $module_lb_kpga, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);

    # To allow time for SERDES lock after switching the clocks
    print ("\nProvisioning complete ... sleeping\n");
    if ($notest == 0) {
      sleep 5;
    }

    # wait for SERDES lock
    if ($notest == 0) {
        if ($hsif_lb_kpga eq 'xfi') {
            if (check_xfi_filt_lock ($module_id_lb_kpga, $slice_lb_kpga) != main::CS_OK) {
                failure("Check for XFI lock in config_release_reset_lb10_kpga10 failed (Module $module_id_lb_kpga, Slice $slice_lb_kpga");
                return 1;
            }
        }
        elsif ($hsif_lb_kpga eq 'cfp_mr') {
          if ( ((main::ten_cfp32x1_txlockd0_filt_lock_t41($module_id_lb_kpga, $slice_lb_kpga)) == 0) ||
               ((main::ten_cfp32x1_rxlockd0_filt_lock_t41($module_id_lb_kpga, $slice_lb_kpga)) == 0) ) {
            failure("Check for CPF_MR lock in config_release_reset_lb10_kpga10 failed (Module $module_id_lb_kpga, Slice $slice_lb_kpga)");
            #return 1;
          }
        }
        else { # MR
             if (check_mr_filt_lock ($module_id_lb_kpga, $slice_lb_kpga) != main::CS_OK) {
                failure("Check for MR lock in config_release_reset_lb10_kpga10 failed (Module $module_id_lb_kpga, Slice $slice_lb_kpga");
                return 1;
            }
        }
    }
}

##############################################################################
# Function:     config_release_reset_hsif_kpga40
#               Release reset sequence for HSIF KPGA 40G Loopback
#
# Parameters:
#   dev_id                    int - Device ID returned by ten_dev_main_init
#   module_id_lb_kpga         int - Value returned by ten_mod_main_init
#   gpllx1_inst_lb_kpga       int - 1 = RX MODULE_A
#                                   9 = RX MODULE_B
#
# Returns:      Error Code
##############################################################################
sub config_release_reset_hsif_kpga40 {
  my($dev_id, $module_id_lb_kpga, $gpllx1_inst_lb_kpga, $hsif) = @_ ;

    print("config_release_reset_hsif_kpga40($dev_id, $module_id_lb_kpga, $gpllx1_inst_lb_kpga, $hsif)\n");

    my $module_lb_kpga = (($module_id_lb_kpga & 1) == 0) ? main::TEN_MODULE_A : main::TEN_MODULE_B;

    main::ten_mpif_set_clock_switch_force ($dev_id, $module_lb_kpga, main::TEN_SLICE_ALL, main::CS_TX_AND_RX, main::CS_DISABLE);

    if ((($module_id_lb_kpga&1) ==  main::TEN_MODULE_A) and ($hsif eq 'cfp_mr')) {
      main::ten_mpif_global_reset_hsif($dev_id, main::TEN_MODULE_B, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);
    }
    else {
      main::ten_mpif_global_reset_hsif($dev_id, $module_lb_kpga, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);
    }

    # Wait for First SERDES lock
    if ($hsif eq 'xfi') {
        for(my $i=0; $i<4; $i++) {
            if (check_xfi_filt_lock ($module_id_lb_kpga, $i) != main::CS_OK) {
                failure("First xfi_filt_lock failed on Client side (Side $module_id_lb_kpga) slice $i");
            }
        }
    }
    elsif ($hsif eq 'cfp_mr') {
        if (check_cfp_mr_filt_lock_40g ($module_id_lb_kpga)) {
            failure("First cfp_mr_filt_lock failed on Client side (Side $module_id_lb_kpga)");
        }
    }
    else {
        if (check_mr_filt_lock_40g ($module_id_lb_kpga)) {
            failure("config_release_reset_hsif_kpga40: First mr_filt_lock failed on Client side (Side $module_id_lb_kpga)");
        }
    }

    ###### Reset the optical module - a glitch during the change of SiLabs modes
    ######        may lock up the optical module TX
    main::dev_reg_write ( 432, 0, 0x5000, 0x80a );
    main::dev_reg_write ( 432, 0, 0x5400, 0x80a );
    sleep (5);
    main::dev_reg_write ( 432, 0, 0x5000, 0x803 );
    main::dev_reg_write ( 432, 0, 0x5400, 0x803 );

    ################################################################################
    #misc_info("wait for GPLL lock");
    ################################################################################
    main::ten_hl_gpllx1_waitfor_gpll_lock_40g ($dev_id, $gpllx1_inst_lb_kpga);

    # Wait for Second SERDES lock
    if($hsif eq 'xfi') {
        for(my $i=0; $i<4; $i++) {
            if (check_xfi_filt_lock ($module_id_lb_kpga, $i) != main::CS_OK) {
                failure("Second xfi_filt_lock failed on Client side (Side $module_id_lb_kpga)");
                return 1;
            }
        }
    }
    elsif ($hsif eq 'cfp_mr') {
        if (check_cfp_mr_filt_lock_40g($module_id_lb_kpga)) {
            failure("Second cfp_mr_filt_lock failed on Client side (Side $module_id_lb_kpga)");
            return 1;
        }
    }
    else {
        if (check_mr_filt_lock_40g ($module_id_lb_kpga)) {
            failure("Second mr_filt_lock failed on Client side (Side $module_id_lb_kpga)");
            return 1;
        }
    }
}

##############################################################################
# Function:     config_release_reset_hsif_kpga10
#               Release reset sequence for HSIF KPGA 10G Loopback
#
# Parameters:
#   dev_id                    int - Device ID returned by ten_dev_main_init
#   module_id_lb_kpga         int - Value returned by ten_mod_main_init for Module A
#   slice_lb_kpga             int - 0 - 3
#   notest                    int - 1 = Do not use checkers
#   hsif_lb_kpga              str - sfi4_2, xaui
#
# Returns:      Error Code
##############################################################################
sub config_release_reset_hsif_kpga10 {
  my ($dev_id, $module_id_lb_kpga, $slice_lb_kpga,
      $notest, $hsif_lb_kpga) = @_;

    print("config_release_reset_hsif_kpga10($dev_id, $module_id_lb_kpga, $slice_lb_kpga, $notest, $hsif_lb_kpga)\n");

    my $module_lb_kpga = (($module_id_lb_kpga & 1) == 0) ? main::TEN_MODULE_A : main::TEN_MODULE_B;

    main::ten_mpif_set_clock_switch_force ($dev_id, $module_lb_kpga, $slice_lb_kpga, main::CS_TX_AND_RX, main::CS_DISABLE);

    if ((($module_id_lb_kpga&1) ==  main::TEN_MODULE_A) and ($hsif_lb_kpga eq 'cfp_mr')) {
      main::ten_mpif_global_reset_hsif ($dev_id, main::TEN_MODULE_B, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);
    }
    else {
      main::ten_mpif_global_reset_hsif ($dev_id, $module_lb_kpga, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);
    }

    # To allow time for SERDES lock after switching the clocks
    print ("\nProvisioning complete ... sleeping\n");
    if ($notest == 0) {
      sleep 5;
    }

    ###############################################################################
    # wait for SERDES lock
    if ($notest == 0) {
        if ($hsif_lb_kpga eq 'xfi') {
            if (check_xfi_filt_lock ($module_id_lb_kpga, $slice_lb_kpga) != main::CS_OK) {
                failure("Check for XFI hsif_lb_kpga SERDES lock failed on module $module_id_lb_kpga slice $slice_lb_kpga");
                return 1;
            }
        }
        elsif ($hsif_lb_kpga eq 'cfp_mr') {
          if ( ((main::ten_cfp32x1_txlockd0_filt_lock_t41($module_id_lb_kpga, $slice_lb_kpga)) == 0) ||
               ((main::ten_cfp32x1_rxlockd0_filt_lock_t41($module_id_lb_kpga, $slice_lb_kpga)) == 0) ) {
            failure("Check for CPF_MR lock in config_release_reset_hsif_kpga10 failed (Module $module_id_lb_kpga, Slice $slice_lb_kpga)");
                return 1;
            }
        }
        else {
            if (check_mr_filt_lock ($module_id_lb_kpga, $slice_lb_kpga) != main::CS_OK) {
                failure("Check for MR hsif_lb_kpga SERDES lock failed on module $module_id_lb_kpga slice $slice_lb_kpga");
                return 1;
            }
        }
    }
 }

 ##############################################################################
# Function:     config_release_reset_traffic
#               Release reset sequence for traffic configurations
#
# Parameters:
#   dev_id                    int - Device ID returned by ten_dev_main_init
#   mod_line                  int - 0 = MODULE_A, 1 = MODULE_B
#   mod_client                int - 0 = MODULE_A, 1 = MODULE_B
#   slice_line                int - 0 - 3
#   slice_client              int - 0 - 3
#                                   Used to identify 10G line slice for aggregation
#   provision_line            int - 1 = Initial config, 0 = Dynamic reprovision
#   hsif_line                 int - sfi4_2, sfi5_1, xaui      : for module A
#                                   xfi, sfi4_2, sfi5_1, xaui : for module B
#   linerate                  int - 10, 40
#   client_traffic_type_enum  int - TEN_TRAFFIC_TYPE_NONE                 = 0
#                                   TEN_TRAFFIC_TYPE_DISABLE              = 0
#                                   TEN_TRAFFIC_TYPE_OTU3                 = 1
#                                   TEN_TRAFFIC_TYPE_OTU3E                = 2
#                                   TEN_TRAFFIC_TYPE_OTU3E1               = 2
#                                   TEN_TRAFFIC_TYPE_OTU3P                = 3
#                                   TEN_TRAFFIC_TYPE_ODTU23               = 4
#                                   TEN_TRAFFIC_TYPE_OTU2                 = 5
#                                   TEN_TRAFFIC_TYPE_OTU2E                = 6
#                                   TEN_TRAFFIC_TYPE_OTU1F                = 7
#                                   TEN_TRAFFIC_TYPE_OC192                = 8
#                                   TEN_TRAFFIC_TYPE_10GE_WAN             = 9
#                                   TEN_TRAFFIC_TYPE_10GE_6_2             = 10
#                                   TEN_TRAFFIC_TYPE_10GE_7_1             = 11
#                                   TEN_TRAFFIC_TYPE_10GE_7_3             = 12
#                                   TEN_TRAFFIC_TYPE_10GFC                = 13
#                                   TEN_TRAFFIC_TYPE_8GFC                 = 14
#                                   TEN_TRAFFIC_TYPE_4GFC                 = 15
#                                   TEN_TRAFFIC_TYPE_2GFC                 = 16
#                                   TEN_TRAFFIC_TYPE_1GFC                 = 17
#                                   TEN_TRAFFIC_TYPE_5GB_IB               = 18
#                                   TEN_TRAFFIC_TYPE_OTU3_NOFEC           = 19
#                                   TEN_TRAFFIC_TYPE_10GE                 = 20
#                                   TEN_TRAFFIC_TYPE_40GELAN              = 21
#                                   TEN_TRAFFIC_TYPE_OC768                = 22
#                                   TEN_TRAFFIC_TYPE_OTU3E3               = 23
#                                   TEN_TRAFFIC_TYPE_CBR40G_50188149150   = 24
#                                   TEN_TRAFFIC_TYPE_OTU3P2               = 25
#                                   TEN_TRAFFIC_TYPE_10GE_6_1             = 26
#                                   TEN_TRAFFIC_TYPE_10GE_7_2             = 27
#                                   TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2 = 28
#                                   TEN_TRAFFIC_TYPE_OTU1E                = 29
#                                   TEN_TRAFFIC_TYPE_10GE_RA              = 30
#                                   TEN_TRAFFIC_TYPE_OC192_OTU2           = 31
#                                   TEN_TRAFFIC_TYPE_OC768_OTU3           = 32
#                                   TEN_TRAFFIC_TYPE_10GE_TC              = 33
#                                   TEN_TRAFFIC_TYPE_OTU2F                = 34
#                                   TEN_TRAFFIC_TYPE_OTU3E2               = 35
#                                   TEN_TRAFFIC_TYPE_OTU2P                = 36
#                                   TEN_TRAFFIC_TYPE_ODUFLEX              = 37
#                                   TEN_TRAFFIC_TYPE_ODTU                 = 38
#                                   TEN_TRAFFIC_TYPE_10G_IB               = 39
#                                   TEN_TRAFFIC_TYPE_12_5G_IB             = 40
#                                   TEN_TRAFFIC_TYPE_SERIAL_40GE          = 41
#                                   TEN_TRAFFIC_TYPE_PARALLEL_40GE        = 42
#                                   TEN_TRAFFIC_TYPE_TC_40GE              = 43
#                                   TEN_TRAFFIC_TYPE_S64_66_40GE          = 44
#                                   TEN_TRAFFIC_TYPE_BYPASS               = 45
#                                   TEN_TRAFFIC_TYPE_10GFC_TC             = 46
#                                   TEN_TRAFFIC_TYPE_2GISC                = 59
#                                   TEN_TRAFFIC_TYPE_1GE                  = 63
#   aggregation               int - 1 For Muxponder Applications
#   notest                    int - 1 = Do not use checkers
#
# Returns:      Error Code
##############################################################################
sub config_release_reset_traffic {
  my ($dev_id, $mod_line, $mod_client, $slice_line, $slice_client,
      $provision_line, $provision_client, $hsif_line, $linerate, $clientrate, $client_traffic_type_enum,
      $aggregation, $notest, $mode, $line_cupll, $client_cupll, $slice_line_cupll, $slice_client_cupll) = @_ ;

    print("config_release_reset_traffic()  dev_id = $dev_id,\n");
    print("    line: mod = $mod_line, client: mod = $mod_client, slice = $slice_line, slice = $slice_client,\n");
    print("    provision_line = $provision_line, provision_client = $provision_client, hsif = $hsif_line, linerate = $linerate,\n");
    print("    clientrate = $clientrate, traffic_type_enum = $client_traffic_type_enum,\n");
    print("    aggregation = $aggregation, notest = $notest, mode = $mode,\n");
    print("    cupll: line_cupll = $line_cupll, client_cupll = $client_cupll, slice_line_cupll = $slice_line_cupll, slice_client_cupll = $slice_client_cupll\n");

    my $mod_a = ($dev_id << 8) | main::TEN_MODULE_A;
    my $mod_b = ($dev_id << 8) | main::TEN_MODULE_B;
    my $slice = $aggregation ? $slice_client : $slice_line;

    # Remove SW resets
    if ($provision_line) {
        if ($linerate == 40) {
            main::ten_n40g_set_global_resets($mod_a, main::CS_RESET_DEASSERT, main::TEN_N40G_GLOBAL_RESETS_ALL );
            main::ten_n40g_set_global_resets($mod_b, main::CS_RESET_DEASSERT, main::TEN_N40G_GLOBAL_RESETS_ALL );
        }
    }

    main::ten_hl_config_remove_soft_resets($mod_line, $slice_line, $mod_client, $slice_client,
                                     $client_traffic_type_enum,
                                     $aggregation);

    # Release hsif reset and set clock switch force only for relevant block module/slices.
    if ($provision_line) {
        main::ten_mpif_global_reset_hsif( $dev_id, $mod_line, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT );
        if ($linerate == 40) {
            main::ten_mpif_set_clock_switch_force ($dev_id, $mod_line, main::TEN_SLICE_ALL, main::CS_RX, main::CS_DISABLE);  # Bugzilla 30823
            main::ten_mpif_set_clock_switch_force ($dev_id, $mod_line, main::TEN_SLICE_ALL, main::CS_TX, main::CS_DISABLE); # Bugzilla 30823
        }
        else {
            main::ten_mpif_set_clock_switch_force( $dev_id, $mod_line, $slice_line, main::CS_RX, main::CS_DISABLE); # Bugzilla 30823
            main::ten_mpif_set_clock_switch_force($dev_id, $mod_line, $slice_line, main::CS_TX, main::CS_DISABLE); # Bugzilla 30823
        }
    }

    if ($provision_client) {
        main::ten_mpif_global_reset_hsif( $dev_id, $mod_client, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT );
        if ($clientrate == 40) {
            main::ten_mpif_set_clock_switch_force ($dev_id, $mod_client, main::TEN_SLICE_ALL, main::CS_RX, main::CS_DISABLE); # Bugzilla 30823
            main::ten_mpif_set_clock_switch_force ($dev_id, $mod_client, main::TEN_SLICE_ALL, main::CS_TX, main::CS_DISABLE); # Bugzilla 30823

        }
        # Bug 30823 comment 7 start
        # If this is a muxponder then switch the clock on both the line and client sides
        elsif ($linerate == 40) { # client_rate is assumed to be 10 due to the if above
            main::ten_mpif_set_clock_switch_force($dev_id, $mod_client, $slice_client, main::CS_RX, main::CS_DISABLE); # Bugzilla 30823
            main::ten_mpif_set_clock_switch_force($dev_id, main::TEN_MODULE_A_AND_B, $slice_client, main::CS_TX, main::CS_DISABLE); # Bugzilla 30823
        }
        # Bug 30823 comment 7 end
        else {
            main::ten_mpif_set_clock_switch_force($dev_id, $mod_client, $slice_client, main::CS_RX, main::CS_DISABLE); # Bugzilla 30823
            main::ten_mpif_set_clock_switch_force($dev_id, $mod_client, $slice_client, main::CS_TX, main::CS_DISABLE); # Bugzilla 30823

        }
        # Clear use of fractional divider as TX protection clock for all 8 ports
        # main::ten_mpif_set_clock_switch_force ($dev_id, main::TEN_MODULE_A_AND_B, main::TEN_SLICE_ALL, main::CS_TX, main::CS_DISABLE); # Bugzilla 30823
    }

    if ($mode ne 'wire10') {
      # Bug 24799 start
      main::ten_hl_syncdsync_reset($mod_client, $slice_client);
      main::ten_syncdsynctx_set_configuration_init_force($mod_client, $slice_client, main::CS_RESET_TOGGLE);
      if($provision_line == 1) {
          if ($aggregation == 1) {
              main::ten_hl_syncdsync_reset($mod_line, $slice);
              main::ten_syncdsynctx_set_configuration_init_force($mod_line, $slice, main::CS_RESET_TOGGLE);
          }
          else {
              main::ten_hl_syncdsync_reset($mod_line, $slice_line);
              main::ten_syncdsynctx_set_configuration_init_force($mod_line, $slice_line, main::CS_RESET_TOGGLE);
          }
      }
    # Bug 24799 end
    }

    # Bug 31352: CUPLL settle_force and digital reset moved to the end of the script
    #  and digital reset toggled always instead of just 8GFC
    # If using CUPLL force settle according to programmed timer value
    if ($line_cupll) {
      print ("\nResetting and Forcing line-side CUPLL settle\n");
      main::ten_cupll_reset_t41($mod_line, $slice_line_cupll, main::TEN_XFI_CUPLL_RESET_CUPLL_DIG, main::CS_RESET_TOGGLE);
      main::ten_mpif_cupll_settle_force_t41($dev_id, $slice_line_cupll, 2, main::CS_ENABLE);
      main::ten_mpif_cupll_settle_force_t41($dev_id, $slice_line_cupll, 2, main::CS_DISABLE);
    }
    if ($client_cupll) {
      print ("\nResetting and Forcing client-side CUPLL settle\n");
      main::ten_cupll_reset_t41($mod_client, $slice_client_cupll, main::TEN_XFI_CUPLL_RESET_CUPLL_DIG, main::CS_RESET_TOGGLE);
      main::ten_mpif_cupll_settle_force_t41($dev_id, $slice_client_cupll, 2, main::CS_ENABLE);
      main::ten_mpif_cupll_settle_force_t41($dev_id, $slice_client_cupll, 2, main::CS_DISABLE);
    }

    # To allow time for SERDES lock after switching the clocks
    print ("\nProvisioning complete ... sleeping\n");
    if ($notest == 0) {
      sleep 5;
    }

    # wait for SERDES lock
    if ($notest == 0) {
        if ($provision_line) {
            if ($linerate == 40) {
              if ($hsif_line eq 'xfi') {
                  for(my $i=0; $i<4; $i++) {
                      if (check_xfi_filt_lock ($mod_line, $i) != main::CS_OK) {
                          failure("Check for $hsif_line 40G SERDES lock failed on port $slice_line");
                          return 1;
                      }
                  }
              }
              elsif ($hsif_line eq 'cfp_mr') {
                  if (check_cfp_mr_filt_lock_40g ($mod_line)) {
                      failure("Check for $hsif_line 40G SERDES lock failed on port $slice_line");
                      return 1;
                  }
              }
              else {
                if (check_mr_filt_lock_40g ($mod_line)) {
                    failure("Check for $hsif_line 40G SERDES lock failed on port $slice_line");
                    return 1;
                }
              }
            }
            else {
                if ($hsif_line eq 'sfi4_1') {
                  # no MR filt lock check for SFI41 mode
                }
                elsif ($hsif_line eq 'xfi') {
                    if (check_xfi_filt_lock($mod_line, $slice_line) != main::CS_OK) {
                        failure("Check for XFI SERDES lock failed on module $mod_line slice $slice_line");
                        return 1;
                    }
                }
                elsif ($hsif_line eq 'cfp_mr') {
                  if ((main::ten_cfp32x1_txlockd0_filt_lock_t41($mod_b, $slice_line) == 0) ||
                      (main::ten_cfp32x1_rxlockd0_filt_lock_t41($mod_b, $slice_line) == 0)) {
                      failure("Check for CFP MR SERDES lock failed on module $mod_b slice $slice_line");
                      return 1;
                  }
                }
                else {
                    if (check_mr_filt_lock($mod_line, $slice_line) != main::CS_OK) {
                        failure("Check for $hsif_line MR SERDES lock failed on module $mod_line slice $slice_line");
                        return 1;
                    }
                }
            }
        }
    }
}


##############################################################################
# Function:     config_release_reset_otu3v_odtu_otu3v
#               Release reset sequence for dual muxponder
#
# Parameters:
#   dev_id                int - Device ID returned by ten_dev_main_init
#   mod_line              int - 0 = MODULE_A, 1 = MODULE_B
#   mod_client            int - 0 = MODULE_A, 1 = MODULE_B
#   client_type           str - cbr40g50188149150, 40gelan, oc768
#   client_fec_type       str - ufec7p, ufec7p_sdhaufec10p, ufec12p, ufec13p,
#                               ufec15p, ufec20p, ufec25p, ufec26p, gfec, 0fec,
#                               nofec
#   sync                  int - 0 = ASYNC, 1 = SYNC
#   provision_line        int - 1 = Initial config, 0 = Dynamic reprovisiontrans40
#   gpllx1_inst_line      int - 1 = RX MODULE_A
#   gpllx1_inst_client    int - 9 = RX MODULE_B
#   term_type             str - ocx : trans, transregen, rsregen, msregen
#                               otu : transparent, section, full
#
# Returns:      Error Code
##############################################################################
sub config_release_reset_otu3v_odtu_otu3v {
    my ($dev_id, $mod_line, $mod_client, $client_type, $client_fec_type, $sync,
         $provision_line, $gpllx1_inst_line, $gpllx1_inst_client, $term_type, $hsif_client) = @_;

    my $mod_a = ($dev_id << 8) | main::TEN_MODULE_A;
    my $mod_b = ($dev_id << 8) | main::TEN_MODULE_B;
    my $i;

    # Remove SW resets
    main::ten_n40g_set_global_resets($mod_a, main::CS_RESET_DEASSERT, main::TEN_N40G_GLOBAL_RESETS_ALL );
    main::ten_n40g_set_global_resets($mod_b, main::CS_RESET_DEASSERT, main::TEN_N40G_GLOBAL_RESETS_ALL );

    # Take N10G blocks out of software reset
    for ($i=0; $i<4; $i++) {
        main::ten_n10g_set_global_resets ($mod_line, $i, main::CS_RESET_DEASSERT, main::TEN_N10G_GLOBAL_RESETS_ALL);
        main::ten_n10g_set_global_resets ($mod_client, $i, main::CS_RESET_DEASSERT, main::TEN_N10G_GLOBAL_RESETS_ALL);
    }

    # Bring all XCON data paths out of software reset
    for ($i=0; $i<8; $i++) {
        main::ten_xcon_es_reset ($dev_id, $i, main::CS_RESET_DEASSERT);
    }
    main::ten_xcon_datapath_reset ($dev_id, main::CS_RESET_DEASSERT);

    for ($i=0; $i<4; $i++) {
      main::ten_hl_resets_block ($mod_line, $i, main::CS_RESET_DEASSERT, main::TEN_HL_RESETS_BLOCK_SYNCDSYNC);
      main::ten_hl_resets_block ($mod_client, $i, main::CS_RESET_DEASSERT, main::TEN_HL_RESETS_BLOCK_SYNCDSYNC);
    }

    main::ten_mpif_set_clock_switch_force ($dev_id, main::TEN_MODULE_A_AND_B, main::TEN_SLICE_ALL, main::CS_TX_AND_RX, main::CS_DISABLE);

    main::ten_mpif_global_reset_hsif ($dev_id, main::TEN_MODULE_A_AND_B, main::CS_TX_AND_RX, main::CS_RESET_DEASSERT);

    # Wait for First SERDES lock
    if (check_mr_filt_lock_40g ($mod_line)) {
        failure("config_release_reset_otu3v_odtu_otu3v: First mr_filt_lock failed on Line side (Side $mod_line)");
        #return 1;
    }

    if($hsif_client eq 'xfi') {
        for($i=0; $i<4; $i++) {
            if (check_xfi_filt_lock ($mod_client, $i) != main::CS_OK) {
                failure("First xfi_filt_lock failed on Client side (Side $mod_client)");
                #return 1;
            }
        }
    }
    elsif ($hsif_client eq 'cfp_mr') {
        if (check_cfp_mr_filt_lock_40g($mod_client)) {
            failure("First cfp_mr_filt_lock failed on Client side (Side $mod_client)");
            #return 1;
        }
    }
    else {
        if (check_mr_filt_lock_40g ($mod_client)) {
            failure("config_release_reset_otu3v_odtu_otu3v: First mr_filt_lock failed on Client side (Side $mod_client)");
            #return 1;
        }
    }

    sleep(5);

    ###### Reset the optical module - a glitch during the change of SiLabs modes
    ######        may lock up the optical module TX
    main::dev_reg_write ( 432, 0, 0x5000, 0x80a );
    main::dev_reg_write ( 432, 0, 0x5400, 0x80a );
    sleep (5);
    main::dev_reg_write ( 432, 0, 0x5000, 0x803 );
    main::dev_reg_write ( 432, 0, 0x5400, 0x803 );

    ################################################################################
    #misc_info("wait for GPLL lock");
    ################################################################################
    main::ten_hl_gpllx1_waitfor_gpll_lock_40g($dev_id, $gpllx1_inst_line);
    main::ten_hl_gpllx1_waitfor_gpll_lock_40g($dev_id, $gpllx1_inst_client);

    # Wait for Second SERDES lock
    if (check_mr_filt_lock_40g ($mod_line)) {
        failure("Second mr_filt_lock failed on Line side (Side $mod_line)");
        #return 1;
    }

    if($hsif_client eq 'xfi') {
        for($i=0; $i<4; $i++) {
            if (check_xfi_filt_lock ($mod_client, $i) != main::CS_OK) {
                failure("Second xfi_filt_lock failed on Client side (Side $mod_client)");
                #return 1;
            }
        }
    }
    elsif ($hsif_client eq 'cfp_mr') {
        if (check_cfp_mr_filt_lock_40g($mod_client)) {
            failure("Second cfp_mr_filt_lock failed on Client side (Side $mod_client)");
            #return 1;
        }
    }
    else {
        if (check_mr_filt_lock_40g ($mod_client)) {
            failure("Second mr_filt_lock failed on Client side (Side $mod_client)");
            #return 1;
        }
    }

    ###############################################################################
    # misc_info("Select software toggle for global timing source");
    ###############################################################################
    main::ten_n40g_sdfr_select_global_timing_source ($mod_line, 6);   # Selects one of the eight global timing sources   EOFCFG = SW = 6

    if ($client_fec_type =~ /ufec/) {
        main::ten_ufec_select_global_timing_source ($mod_client, 0, 6);   # Selects one out of eight different statistics timing generators
    }
    # Global Statistics unit 0 Time Interval Base
    ####    tenabo_bf_write ($dev_id, main::TEN_GLB_MISC_GSTI01, 0x17D7, 15, 0);
    ####    tenabo_bf_write ($dev_id, main::TEN_GLB_MISC_GSTI00, 0x8400, 15, 0);
    main::ten_glb_misc_set_gsti($dev_id, 0, 0x17D7, 0x8400);

    ####    tenabo_bf_write ($dev_id, main::TEN_MPIF_GLOBAL_RESET_COMMON, 0, 5, 5); # Hard reset top level XLOS & GSTI logic on system clock
    main::ten_mpif_global_reset_common($dev_id, main::CS_RESET_DEASSERT, main::TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS);

    sleep 1;
}


1;
