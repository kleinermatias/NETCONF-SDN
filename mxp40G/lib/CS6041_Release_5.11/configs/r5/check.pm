# Checker functions for test scripts

use strict;
use base 'Exporter';
use warnings FATAL => qw(all); # Promote hidden apish eval warnings to errors

package check;
use Data::Dumper;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);
use config_clocks;      # Board-specific FPGA and clocking functions

$VERSION = '1.0';
require Exporter;
@ISA = qw(Exporter);
@EXPORT = qw(
    tenabo_bf_read tenabo_bf_write
    check_args
    check_all
    check_sonet_framing_10g check_sonet_pointer_n10g
    check_n40g_otn_inframe
    check_xfi_filt_lock check_mr_filt_lock check_mr_filt_lock_40g
    failure check_hsif_skew check_cfp_mr_filt_lock_40g
    check_pbert_counters
    check_pbert_40g_counters
    check_pbert_40g_loop_fe
    check_pbert_40g_counters_both_rx
    validate_line_client
    validate_hsif_traffic_type
    validate_sync_vs_async
    validate_timeslots
    validate_cleanup_pll_args
    recenter_get_api_args setup_amp_recenter
    check_t100_option
    %ten_40ge_rx_pre_enum
    %ten_40ge_tx_pre_enum
    %ten_xcon_client_enum
);

# Prototypes
sub recenter_parse_args($);
sub recenter_get_api_args($$);

# These bools are set in the while block, and post processed to check for validity. The intent
# is to allow T40 parms async and sync to continue working with T41 parms map_oxuv and map_odtu.
# Rules are described in post-loop processing.
my $drtu_needs_map  = 0;  # two levels of mapping required?
my $drtu_needs_dtj  = 0;  # deterministic justification required?
my $t100_support = 0;

# Map line and client rate strings to 10 or 40 gig
my %linerate = (
   'invalid'               => 10,
   'none'                  => 10,
   'null'                  => 10,
   '10ge'                  => 10,
   '10ge6_1'               => 10,
   '10ge6_2'               => 10,
   '10ge7_1'               => 10,
   '10ge7_2'               => 10,
   '10ge7_3'               => 10,
   '10ge_gfpf_oc192_odu2'  => 10,
   '10ge_ra'               => 10,
   '10ge_tc'               => 10,
   '10gfc'                 => 10,
   '10gfc_tc_ra'           => 10,
   '10gfc_tc'              => 10,
   '10gfc_tc_g709'         => 10, # Bug 31054
   'oc192'                 => 10,
   'oc192_async'           => 10,
   'oc192_otu2'            => 10,
   'otu1f'                 => 10,
   'otu2'                  => 10,
   'otu2e'                 => 10,
   'otu1e'                 => 10,
   'cbr_1118099736'        => 10,
   'cbr_1052329163'        => 10,
   'otu3'                  => 40,
   'otu3+'                 => 40,
   'otu3p2'                => 40,
   'otu3e'                 => 40,
   'otu3e1'                => 40,
   'otu3e2'                => 40,
   'otu3e3'                => 40,
   'otu3e4'                => 40,  # Bugzilla 28237
   'oc768'                 => 40,
   'oc768_otu3'            => 40,
   '40gelan'               => 40,
   '40ge_tc'               => 40,
#   'cbr40g39813120000'     => 40,
#   'cbr40g41250000000'     => 40,
   'cbr40g50188149150'     => 40,

   '40gep'                 => 40,
   '40gesbi'               => 40,
   '40ges6466'             => 40,
   '40gex'                 => 40,
   '40gep_ra'              => 40,
   '40gesbi_ra'            => 40,
   '40ges6466_ra'          => 40,
   '40gex_ra'              => 40,
   
   '8gfc'                  => 10,
   '4gfc'                  => 10,
   '2gfc'                  => 10,
   '2gisc'                 => 10,
   '8gfc_ra'               => 10,
   '4gfc_ra'               => 10,
   '2gfc_ra'               => 10,
   '1gfc_ra'               => 10,
   '8gfc_enh'              => 10,
   '4gfc_enh'              => 10,
   '2gfc_enh'              => 10,
   '1gfc_enh'              => 10,
   'pbert_2gfc'            => 10,
   'pbert_4gfc'            => 10,
   'pbert_8gfc'            => 10,
   'pbert_10gfc'           => 10,
   'pbert_10ge'            => 10,
   '2_5g_iba'              => 10,
   '5g_iba'                => 10,
   '10g_iba'               => 10,
   '10ge_gfpf'             => 10,   # Bugzilla 29991
   '1ge'                   => 10,   # Bugzilla 38871
   'fdr10_iba'             => 10    # Bugzilla 39242
);

# Map fec type strings to enums
my %fec_type_enum = (
    'ufec7p'       => main::TEN_FEC_MODE_OTUkV,
    'ufec7p_sdha'  => main::TEN_FEC_MODE_OTUkV_SDH_A,
    'ufec10p'      => main::TEN_FEC_MODE_OTUkV_262,
    'ufec12p'      => main::TEN_FEC_MODE_OTUkV_267,
    'ufec13p'      => main::TEN_FEC_MODE_OTUkV_270,
    'ufec15p'      => main::TEN_FEC_MODE_OTUkV_273,
    'ufec20p'      => main::TEN_FEC_MODE_OTUkV_285,
    'ufec25p'      => main::TEN_FEC_MODE_OTUkV_297,
    'ufec26p'      => main::TEN_FEC_MODE_OTUkV_301,
    'gfec'         => main::TEN_FEC_MODE_GFEC,
    '0fec'         => main::TEN_FEC_MODE_ZEROFEC,
    'nofec'        => main::TEN_FEC_MODE_NOFEC,
    'deallocate'   => main::TEN_FEC_MODE_DEALLOCATE,
    'ufec7p_263'   => main::TEN_FEC_MODE_OTUkV_263,
    'ufec18p'      => main::TEN_FEC_MODE_OTUkV_280,
    'ufec25p_295'  => main::TEN_FEC_MODE_OTUkV_295
);

# Map traffic type strings to enums
my %traffic_type_enum = (
    'none'                 => main::TEN_TRAFFIC_TYPE_NONE,
    'null'                 => main::TEN_TRAFFIC_TYPE_NONE,
    'otu3'                 => main::TEN_TRAFFIC_TYPE_OTU3,
    'otu3e'                => main::TEN_TRAFFIC_TYPE_OTU3E,
    'otu3+'                => main::TEN_TRAFFIC_TYPE_OTU3P,
    'odtu23'               => main::TEN_TRAFFIC_TYPE_ODTU23,
    'otu2'                 => main::TEN_TRAFFIC_TYPE_OTU2,
    'otu2e'                => main::TEN_TRAFFIC_TYPE_OTU2E,
    'otu1e'                => main::TEN_TRAFFIC_TYPE_OTU1E,
    'otu1f'                => main::TEN_TRAFFIC_TYPE_OTU1F,
    'oc192'                => main::TEN_TRAFFIC_TYPE_OC192,
    'oc192_async'          => main::TEN_TRAFFIC_TYPE_OC192,
    'oc192_otu2'           => main::TEN_TRAFFIC_TYPE_OC192_OTU2,
    '10ge_wan'             => main::TEN_TRAFFIC_TYPE_10GE_WAN,
    '10ge6_1'              => main::TEN_TRAFFIC_TYPE_10GE_6_1,
    '10ge6_2'              => main::TEN_TRAFFIC_TYPE_10GE_6_2,
    '10ge7_1'              => main::TEN_TRAFFIC_TYPE_10GE_7_1,
    '10ge7_2'              => main::TEN_TRAFFIC_TYPE_10GE_7_2,
    '10ge7_3'              => main::TEN_TRAFFIC_TYPE_10GE_7_3,
    '10ge_gfpf_oc192_odu2' => main::TEN_TRAFFIC_TYPE_10GE_GFPF_OC192_ODU2,
    '10ge_ra'              => main::TEN_TRAFFIC_TYPE_10GE_RA,
    '10ge_tc'              => main::TEN_TRAFFIC_TYPE_10GE_TC,
    '10gfc'                => main::TEN_TRAFFIC_TYPE_10GFC,
    '10gfc_tc_ra'          => main::TEN_TRAFFIC_TYPE_10GFC_TC_RA,
    '10gfc_tc'             => main::TEN_TRAFFIC_TYPE_10GFC_TC,
    '10gfc_tc_g709'        => main::TEN_TRAFFIC_TYPE_10GFC_TC_G709, # Bug 31054
    '8gfc'                 => main::TEN_TRAFFIC_TYPE_8GFC,
    '4gfc'                 => main::TEN_TRAFFIC_TYPE_4GFC,
    '2gfc'                 => main::TEN_TRAFFIC_TYPE_2GFC,
    '2gisc'                => main::TEN_TRAFFIC_TYPE_2GISC,
    '8gfc_ra'              => main::TEN_TRAFFIC_TYPE_8GFC_RA,
    '4gfc_ra'              => main::TEN_TRAFFIC_TYPE_4GFC_RA,
    '2gfc_ra'              => main::TEN_TRAFFIC_TYPE_2GFC_RA,
    '1gfc_ra'              => main::TEN_TRAFFIC_TYPE_1GFC_RA,
    '8gfc_enh'             => main::TEN_TRAFFIC_TYPE_8GFC_ENH,
    '4gfc_enh'             => main::TEN_TRAFFIC_TYPE_4GFC_ENH,
    '2gfc_enh'             => main::TEN_TRAFFIC_TYPE_2GFC_ENH,
    '1gfc_enh'             => main::TEN_TRAFFIC_TYPE_1GFC_ENH,
    '5gb_ib'               => main::TEN_TRAFFIC_TYPE_5GB_IB,
    '10ge'                 => main::TEN_TRAFFIC_TYPE_10GE,
    '40gelan'              => main::TEN_TRAFFIC_TYPE_40GELAN,
    '40ge_tc'              => main::TEN_TRAFFIC_TYPE_TC_40GE,
     
    '40gep'                => main::TEN_TRAFFIC_TYPE_PARALLEL_40GE,
    '40gesbi'              => main::TEN_TRAFFIC_TYPE_SERIAL_40GE,
    '40ges6466'            => main::TEN_TRAFFIC_TYPE_S64_66_40GE,
    '40gex'                => main::TEN_TRAFFIC_TYPE_TC_40GE, 
    '40gep_ra'             => main::TEN_TRAFFIC_TYPE_PARALLEL_40GE,
    '40gesbi_ra'           => main::TEN_TRAFFIC_TYPE_SERIAL_40GE,
    '40ges6466_ra'         => main::TEN_TRAFFIC_TYPE_S64_66_40GE,
    '40gex_ra'             => main::TEN_TRAFFIC_TYPE_TC_40GE, 
    
    'cbr40g50188149150'    => main::TEN_TRAFFIC_TYPE_CBR40G_50188149150,
    'oc768'                => main::TEN_TRAFFIC_TYPE_OC768,
    'oc768_otu3'           => main::TEN_TRAFFIC_TYPE_OC768_OTU3,
    'otu3e1'               => main::TEN_TRAFFIC_TYPE_OTU3E1,
    'otu3e2'               => main::TEN_TRAFFIC_TYPE_OTU3E2,
    'otu3e3'               => main::TEN_TRAFFIC_TYPE_OTU3E3,
    'pbert_2gfc'           => main::TEN_TRAFFIC_TYPE_2GFC,
    'pbert_4gfc'           => main::TEN_TRAFFIC_TYPE_4GFC,
    'pbert_8gfc'           => main::TEN_TRAFFIC_TYPE_8GFC,
    'pbert_10gfc'          => main::TEN_TRAFFIC_TYPE_10GFC,
    'otu3p2'               => main::TEN_TRAFFIC_TYPE_OTU3P2,
    'pbert_10ge'           => main::TEN_TRAFFIC_TYPE_10GE,
    'otu3e4'               => main::TEN_TRAFFIC_TYPE_OTU3E4,  # Bugzilla 28237
    '10ge_gfpf'            => main::TEN_TRAFFIC_TYPE_10GE_GFPF,  # Bugzilla 29991
    '2_5g_iba'             => main::TEN_TRAFFIC_TYPE_10G_IB,
    '5g_iba'               => main::TEN_TRAFFIC_TYPE_10G_IB,
    '10g_iba'              => main::TEN_TRAFFIC_TYPE_10G_IB,
    '1ge'                  => main::TEN_TRAFFIC_TYPE_1GE, # Bugzilla 38871
    'fdr10_iba'            => main::TEN_TRAFFIC_TYPE_FDR10_IB, # Bugzilla 39242
);

# Map OC termination strings to enums
my %oc_term_enum = (
    'trans'      => main::TEN_OC192_TERM_TRANSPARENT_CBR10,
    'transregen' => main::TEN_OC192_TERM_TRANSPARENT_REGENERATOR,
    'rsregen'    => main::TEN_OC192_TERM_RS_LAYER_REGENERATOR,
    'msregen'    => main::TEN_OC192_TERM_MS_LAYER_REGENERATOR,
);

# Map OTU termination strings to enums
my %otu_term_enum = (
    'transparent' => main::TEN_OTU_TERM_TRANSPARENT,
    'section'     => main::TEN_OTU_TERM_SECTION,
    'full'        => main::TEN_OTU_TERM_FULL,
);

# Map transponder/muxponder type strings to enums
my %mode_enum = (
    'trans40'       => main::TEN_40G_TRANSPONDER,
    'trans10'       => main::TEN_10G_TRANSPONDER,
    'mux'           => main::TEN_40G_MUXPONDER,
    'lb10'          => main::TEN_10G_LOOPBACK,
    'lb40'          => main::TEN_40G_LOOPBACK,
    'kpga10'        => main::TEN_10G_KPGA,
    'kpga40'        => main::TEN_40G_KPGA,
    'pbert10'       => main::TEN_10G_PBERT,
    'hsif_kpga10'   => main::TEN_10G_HSIF_KPGA,
    'hsif_kpga40'   => main::TEN_40G_HSIF_KPGA,
    'cbr_kpga10'   => main::TEN_10G_CBR_KPGA,
    'cbr_kpga40'   => main::TEN_40G_CBR_KPGA,
    'wire10'        => main::TEN_10G_WIRE,
    'wire40'        => main::TEN_40G_WIRE,
);

# Map HSIF type strings to enums
my %hsif_enum = (
    'disabled'=> main::TEN_HSIF_PROTOCOL_DISABLED,
    'sfi5_1' => main::TEN_HSIF_PROTOCOL_SFI51,
    'sfi4_1' => main::TEN_HSIF_PROTOCOL_SFI41,
    'xfi'    => main::TEN_HSIF_PROTOCOL_XFI,
    'sfi4_2' => main::TEN_HSIF_PROTOCOL_SFI42_10G,
    'xaui'   => main::TEN_HSIF_PROTOCOL_XAUI,
    'cfp_mr' => main::TEN_HSIF_PROTOCOL_CFP,
);
    #'sfi4_2' => TEN_HSIF_PROTOCOL_SFI42_40G,

# Map 10GE Rate Adapt type strings to enums
my %ten_ge_flow_enum = (
    'preemptive' => main::TEN_PP10G_FLOW_ETH_4_P,
    'reactive'   => main::TEN_PP10G_FLOW_ETH_4,
);

# Map GFP frame format to enums
my %gfp_frame_format_enum = (
    '28blk_5sblk'   => main::TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4,
    '28blk_11sblk'  => main::TEN_28_BLOCKS_11_SUPERBLOCKS_CRC4,
    '32blk_4sblk'   => main::TEN_32_BLOCKS_4_SUPERBLOCKS_NOCRC,
    '32blk_8sblk'   => main::TEN_32_BLOCKS_8_SUPERBLOCKS_NOCRC,
);

my %ten_kpg_enum = (
  'fixed'  => main::TEN_KPG_FIXED_PATTERN,
  'prbs11' => main::TEN_KPG_PN11,
  'prbs23' => main::TEN_KPG_PN23,
  'prbs31' => main::TEN_KPG_PN31,
);

my %ten_hsif_kpga_pattern_enum = (
  'prbs31' => main::TEN_HSIF_PRBS_PN31,
  'prbs23' => main::TEN_HSIF_PRBS_PN23,
  'prbs15' => main::TEN_HSIF_PRBS_PN15,
  'prbs7'  => main::TEN_HSIF_PRBS_PN7,
  'prbs9'  => main::TEN_HSIF_PRBS_PN9,
);

my %ten_map_enum = (
  'bmp'          => main::TEN_MAP_BMP,
  'amp'          => main::TEN_MAP_AMP,
  'amp_dt'       => main::TEN_MAP_AMP_DT,
  'amp_prop'     => main::TEN_MAP_AMP_PROP,    # Cortina
  'amp_prop_dt'  => main::TEN_MAP_AMP_PROP_DT, # Cortina
  'gmp_lo'       => main::TEN_MAP_GMP_LO,
  'gmp_ho'       => main::TEN_MAP_GMP_HO,
  'gmp_ho_dt'    => main::TEN_MAP_GMP_HO_DT,
  'dont_care'    => main::TEN_MAP_DONT_CARE,
#  'bmp' => main::TEN_ASYNC_MODE,
#  'amp' => main::TEN_SYNC_MODE,
);

our %ten_xcon_client_enum = (
    'odu1e'      => main::TEN_TRAFFIC_TYPE_OTU1E,
    'odu1f'      => main::TEN_TRAFFIC_TYPE_OTU1F,
    'odu2'       => main::TEN_TRAFFIC_TYPE_OTU2,
    'odu2e'      => main::TEN_TRAFFIC_TYPE_OTU2E,
    'oc768'      => main::TEN_TRAFFIC_TYPE_OC768,
    '40ges6466'  => main::TEN_TRAFFIC_TYPE_S64_66_40GE,  # 40GE PCS
    '40ge_tc'    => main::TEN_TRAFFIC_TYPE_TC_40GE,      # Must be a CBR accross XCON
    'odu3'       => main::TEN_TRAFFIC_TYPE_OTU3,
    'odu3e1'     => main::TEN_TRAFFIC_TYPE_OTU3E1,
    'odu3e2'     => main::TEN_TRAFFIC_TYPE_OTU3E2,
    'odu3e4'     => main::TEN_TRAFFIC_TYPE_OTU3E4,    # Bugzilla 28237
    'oc192'      => main::TEN_TRAFFIC_TYPE_OC192,     # Bugzilla 28444 Start
    '10ge6_1'    => main::TEN_TRAFFIC_TYPE_10GE_6_1,
    '10ge6_2'    => main::TEN_TRAFFIC_TYPE_10GE_6_2,
    '10ge7_1'    => main::TEN_TRAFFIC_TYPE_10GE_7_1,
    '10ge_ra'    => main::TEN_TRAFFIC_TYPE_10GE_RA,
    '10ge7_2'    => main::TEN_TRAFFIC_TYPE_10GE_7_2,
    '10ge7_3'    => main::TEN_TRAFFIC_TYPE_10GE_7_3,
    '8gfc'       => main::TEN_TRAFFIC_TYPE_8GFC,
    '10gfc'      => main::TEN_TRAFFIC_TYPE_10GFC,
    '10gfc_tc_ra' => main::TEN_TRAFFIC_TYPE_10GFC_TC_RA,
    '10gfc_tc'   => main::TEN_TRAFFIC_TYPE_10GFC_TC,  # Bugzilla 28444 End
    '10gfc_tc_g709' => main::TEN_TRAFFIC_TYPE_10GFC_TC_G709, # Bug 31054
    '5g_iba'     => main::TEN_TRAFFIC_TYPE_5GB_IB,
    '10g_iba'    => main::TEN_TRAFFIC_TYPE_10G_IB,
    '4gfc'       => main::TEN_TRAFFIC_TYPE_4GFC,
    '2gfc'       => main::TEN_TRAFFIC_TYPE_2GFC,
    '2gisc'      => main::TEN_TRAFFIC_TYPE_2GFC,
    '1ge'        => main::TEN_TRAFFIC_TYPE_1GE, # Bugzilla 38871
    'fdr10_iba'  => main::TEN_TRAFFIC_TYPE_FDR10_IB # Bugzilla 39242
);

# Bugzilla 28006 Start
our %ten_40ge_rx_pre_enum = (
    '40gep_ra'     => main::TEN_PP40G_RX_40GEP_XCON_RA,  
    '40gep'        => main::TEN_PP40G_RX_40GEP_XCON,  
    '40gesbi_ra'   => main::TEN_PP40G_RX_40GESBI_XCON_RA,  
    '40gesbi'      => main::TEN_PP40G_RX_40GESBI_XCON,  
    '40ges6466_ra' => main::TEN_PP40G_RX_40GES6466_XCON_RA,  
    '40ges6466'    => main::TEN_PP40G_RX_40GES6466_XCON,  
    '40gex_ra'     => main::TEN_PP40G_RX_40GEX_XCON_RA,  
    '40gex'        => main::TEN_PP40G_RX_40GEX_XCON,  
);

our %ten_40ge_tx_pre_enum = (
    '40gep_ra'     => main::TEN_PP40G_TX_XCON_40GEP_RA,  
    '40gep'        => main::TEN_PP40G_TX_XCON_40GEP,  
    '40gesbi_ra'   => main::TEN_PP40G_TX_XCON_40GESBI_RA,  
    '40gesbi'      => main::TEN_PP40G_TX_XCON_40GESBI,  
    '40ges6466_ra' => main::TEN_PP40G_TX_XCON_40GES6466_RA,  
    '40ges6466'    => main::TEN_PP40G_TX_XCON_40GES6466,  
    '40gex_ra'     => main::TEN_PP40G_TX_XCON_40GEX_RA,  
    '40gex'        => main::TEN_PP40G_TX_XCON_40GEX,  
);
# Bugzilla 28006 End

# Bugzilla 28977 Start
my %deskew_type_enum = (
    'sadeco'       => main::TEN_SADECO_DESKEW,        # Deskew in XCON's SADECO
    'bypass'       => main::TEN_PP40G_BYPASS_DESKEW,  # Deskew in bypass of PP40G block
    'pp40g'        => main::TEN_PP40G_DESKEW,         # Deskew in PP40G block
);
# Bugzilla 28977 End



my $odtu_map_string =
"                              <bmp>                 Synchronour Mapping (BMP)\n" .
"                              <amp>                 Asynchronour Mapping (AMP)\n" .
"                              <amp_dt>              AMP Deterministic\n" .
"                              <amp_prop>            AMP Proprietary (Cortina Enhanced) \n" .
"                              <amp_prop_dt>         AMP Proprietary Deterministic\n" .
"                              <gmp_lo>              GMP Low Order\n" .
"                              <gmp_ho>              GMP High Order\n" .
"                              <gmp_ho_dt>           GMP High Order Deterministic\n";

my $oxuv_map_string =
"                              <bmp>                 Synchronour Mapping (BMP)\n" .
"                              <amp>                 Asynchronour Mapping (AMP)\n" .
"                              <amp_prop>            AMP Proprietary (Cortina Enhanced)\n" . 
"                              <gmp_lo>              GMP Low Order\n" .
"                              <gmp_ho>              GMP High Order\n";


### NOTE: State information from one config to another is kept in this
###       array. This is for validate_fec.
#my @fec = qw( invalid );     # Bugzilla 31209
my $initial_configuration = 0; # Indicate that initial configuration has not occured

sub module_only {
    my ($module_id) = @_;
    return sprintf "Module %s", ($module_id & 1) ? 'B' : 'A';
}

sub module_slice {
    my ($module_id, $slice) = @_;
    return sprintf "Module %s Port %d (%d)", ($module_id & 1) ? 'B' : 'A', $slice+1, ($module_id & 1) * 4 + $slice;
}

    # printf "check_sonet_framing_10g  %s ... ", module_slice($module_id, $slice);
    # printf "check_sonet_pointer_n10g %s ... ", module_slice($module_id, $slice);
    # printf "check_n40g_otn_inframe   %s ... ", module_only($module_id);
    # printf "check_n40g_pti_byte      %s ... ", module_only($module_id);
    # printf "check_pp10g_pcs_insync   %s ... ", module_slice($module_id, $slice);

##############################################################################
#
# Function:      tenabo_bf_read
#
# bitfield read
#
# Parameter:
#
#    dev - dev_id
#
#    reg - register offset
#
#    mbp - most significant bit field position
#
#    lbp - least significant bit field position
#
# Returns:
#
#    val or -1
#
sub tenabo_bf_read{
    my ($dev_id, $reg, $mbp, $lbp) = @_;

    return -1 unless defined $mbp;
    return -1 unless defined $lbp;
    return -1 unless $mbp >= $lbp;
    my $size = $mbp - $lbp + 1;
    my $val = main::ten_reg_read($dev_id, eval($reg));
    my $mask = 2**$size - 1;
    $mask = $mask << $lbp;
    my $bfval = ($val & $mask) >> $lbp;
    return $bfval;
}

##############################################################################
#
# Routine:      tenabo_bf_write
#
# bitfield write.
#
# Parameter:
#
#    dev - dev_id
#
#    reg - register offset
#
#    val - value
#
#    mbp - most significant bit field position
#
#    lbp - least significant bit field position
#
# Returns:
#
#    0: OK
#    -1: ERROR
#
sub tenabo_bf_write {
    my ($dev_id, $reg, $val, $mbp, $lbp) = @_;

    return -1 unless defined $mbp;
    return -1 unless defined $lbp;
    return -1 unless $mbp >= $lbp;
    my $size=$mbp-$lbp+1;
    $val=eval($val);
    if ($val >=0 && $val < (2**$size)) {
        my $oldval = main::ten_reg_read($dev_id, eval($reg));
        my $mask = 2**$size-1;
        $mask = ~($mask << $lbp);
        my $newval = $oldval & $mask |($val <<$lbp);
        if (main::ten_reg_write($dev_id,eval($reg),$newval) != main::CS_OK) {
            return -1;
        }
    }
    else {
        print "illegal value to write\n";
        return -1;
    }
    return 0;
}

# This function returns 0 if SONET is in frame or 1 on error
sub check_sonet_framing_10g {
    my ($module_id, $slice) = @_;
    printf "check_sonet_framing_10g  %s ... ", module_slice($module_id, $slice);
    for (my $i=1; $i<=10; $i++) {
        if (main::ten_n10g_get_sdfr_rx_status( $module_id, $slice, main::TEN_SDFR_SDFSTAT_OOFS ) == 0) {
            print "Pass\n";
            return 0;
        }
        sleep 1;
    }
    print "FAIL *\n";
    return 1;
}

# This function returns 0 if there's a valid SONET pointer or 1 on error
sub check_sonet_pointer_n10g {
    my ($module_id, $slice)   = @_;
    printf "check_sonet_pointer_n10g %s ... ", module_slice($module_id, $slice);
    # for (my $i=0; $i<10; $i++) {
        my $pis0_sts1 = main::ten_n10g_sohr_get_pis0($module_id, $slice, 0) & 7;
        if ($pis0_sts1 == 0) {
            print "Pass\n";
            return 0;
        }
        elsif ($pis0_sts1 == 1) {
            # print "N10G SONET pointer state is LOP, PIS0[2:0] status = 1\n";
        }
        elsif ($pis0_sts1 == 2) {
            print "FAIL *\n\tN10G SONET pointer state is CONC, PIS0[2:0] status = 2\n";
            return 1;
        }
        elsif ($pis0_sts1 == 4) {
            # print "N10G SONET pointer state is AIS, PIS0[2:0] status = 4\n";
        }
        else {
            print "FAIL *\n\tN10G SONET pointer state is UNDEFINED, PIS0[2:0] status = $pis0_sts1\n";
            return 1;
        }
        sleep 1;
    # }
    # print "FAIL after 10 tries\n";
    print "FAIL *\n";
    return 1;
}



##############################################################################
#
# Function:      check_sonet_framing_40g
#
# Check N40G SONET in frame status
#
# Parameters:
#
#
#	 ch - <0-1>
#
# Returns:
#    1: locked 0: NOT locked
#
sub check_sonet_framing_40g {
    #my ($ch)   = @_;
    my ($module_id)   = @_;

    printf "check_sonet_framing_40g  %s ... ", module_only($module_id);
    #my $module_id = ($ch == main::TEN_MODULE_A) ? main::TEN_MODULE_A : main::TEN_MODULE_B;
    my $oof = 1;
    for(my $i=0; $i<50; $i++) {
        $oof = main::ten_n40g_get_sdfr_rx_status ($module_id, main::TEN_SDFR_SDFSTAT_OOFS);
        #print("$i:N40G SONET OOF status = $oof");

        if($oof==0) {
          print("N40G SONET in frame\n");
          return 0;
        }

        sleep 1;
    }
    print "FAIL *\n";
    return 1;
}




# This function returns CS_OK if both the TX and RX SERDES are locked
sub check_xfi_filt_lock {
    my ($module_id, $slice) = @_;
    my $count = 0;
    $count += main::ten_hl_hsif_check_xfi_filt_lock( $module_id, $slice, main::CS_TX );
    $count += main::ten_hl_hsif_check_xfi_filt_lock( $module_id, $slice, main::CS_RX );
    return $count == 2 ? main::CS_OK : main::CS_ERROR;
}

# This function returns 0 on locked or 1 on not locked
sub check_mr_filt_lock {
    my ($module_id, $slice) = @_;
    my $count = 0;
    # These are expected to return '1'
    #if (main::ten_hl_hsif_check_mr_filt_lock( $module_id, $slice, main::CS_TX ) &&
    #    main::ten_hl_hsif_check_mr_filt_lock( $module_id, $slice, main::CS_RX )) {
    #    return 0;
    #}
    if (main::ten_hl_hsif_check_mr_filt_lock ($module_id, $slice, main::CS_RX) == 0) {
        print ("check_mr_filt_lock(Side $module_id slice $slice)  RX lock failed\n");
        return 1;
    }
    if (main::ten_hl_hsif_check_mr_filt_lock ($module_id, $slice, main::CS_TX) == 0) {
        print ("check_mr_filt_lock(Side $module_id slice $slice)  TX lock failed\n");
        return 1;
    }

    return 0;  # MR Filter lock detected

    #print ("check_mr_filt_lock(Side $module_id) FAILED!!\n");
    #return 1;
}

# Should return 0 on a PASS
sub check_cfp_mr_filt_lock_40g {
    my $module_id = shift;
    my $fail = 0;
    
    if (main::ten_cfp32x1_txlockd0_filt_lock_t41($module_id, main::TEN_SLICE_ALL) == 0) {
      return 1;
    }
    
    if (main::ten_cfp32x1_rxlockd0_filt_lock_t41($module_id, main::TEN_SLICE_ALL) == 0) {
      return 1;
    }
    
    return (0);
}

# Should return 0 on a PASS
sub check_mr_filt_lock_40g {
    my $module_id = shift;
    my $fail = 0;
    # These are expected to return '0'
    return check_mr_filt_lock($module_id, 0) ||
           check_mr_filt_lock($module_id, 1) ||
           check_mr_filt_lock($module_id, 2) ||
           check_mr_filt_lock($module_id, 3);
}

# Returns 0 when in frame
sub check_n40g_otn_inframe {
    my $module_id = shift;
    my $dev_id = $module_id >> 8;
    my $module = $module_id & 1;
    printf "Check_n40g_otn_inframe   %s ... ", module_only($module_id);
    for (my $i=0; $i<10; $i++) {
        ####    if (tenabo_bf_read($dev_id, main::TEN_N40G_OTNR4X_OFSTAT + main::TEN_N40G_STRIDE * $module, 7, 7)) {
        if (main::ten_n40g_otnr4x_get_ofstat($module_id, main::TEN_N40G_OTNR4X_STATUS_SIF)) {
            print "OTN N40G Pass is in frame\n";
            return 0;
        }
        sleep 1;
    }
    print "FAIL!  OTN N40G is NOT in frame!\n";
    return 1;
}

# Returns 0 when in frame
sub check_n10g_otn_inframe {
    my ($module_id, $slice) = @_;
    my $dev_id = $module_id >> 8;
    my $module = $module_id & 1;
    printf "check_n10g_otn_inframe   %s ... ", module_slice($module_id, $slice);
    for (my $i=0; $i<10; $i++) {
        if (main::ten_n10g_get_otu_framer_status($module_id, $slice, main::TEN_NX0G_OTNR_OFSTAT_SIF)) {
            print "Pass\n";
            return 0;
        }
        sleep 1;
    }
    print "FAIL *\n";
    return 1;
}

####################################################################################
#
# Function:      check_n40g_kpa_sync
#
# Check 40G KPA
#
# Parameters:
#
#	 slice - <0-1>
#
#    pattern - <prbs11|prbs23|prbs31>
#
# Returns: 0 when pattern detected, 1 otherwise
#
sub check_n40g_kpa_sync {
	my ($module_id, $pattern) = @_;

    printf "Check_n40g_kpa_sync      %s ... ", module_only($module_id);
	for (my $i = 0; $i < 10; $i++) {
		my $pat = main::ten_n40g_get_kpa_status($module_id) & 3;
		#print("$i: PRBS Status = $pat\n");

		if ($pat == $pattern) {
            print ("KPA pattern detected\n");
			return 0;
		}
        sleep 1;
	}
    print "FAIL!  KPA pattern NOT detected!\n";
	return 1;
}

####################################################################################
#
# Function:      check_n10g_kpa_sync
#
# Check 10G KPA
#
# Parameters:
#
#	 module_id - <0-1>
#	 slice - <0-3>
#    pattern - <prbs11|prbs23|prbs31>
#
# Returns: 0 when pattern detected, 1 otherwise
#
sub check_n10g_kpa_sync {
	my ($module_id, $slice, $pattern) = @_;

    printf "Check_n10g_kpa_sync      %s ... ", module_slice($module_id, $slice);
	for (my $i = 0; $i < 10; $i++) {
		my $pat = main::ten_n10g_get_global_pstat_status($module_id, $slice) & 3;
		#print("$i: PRBS Status = $pat\n");

		if ($pat == $pattern) {
            print ("KPA pattern detected\n");
			return 0;
		}
        sleep 1;
	}

    print "FAIL!  KPA pattern NOT detected!\n";
	return 1;
}

# Returns 0 when the received PTI byte matches the expected value
sub check_n40g_pti_byte {
    my $module_id = shift;
    printf "check_n40g_pti_byte      %s ... ", module_only($module_id);
    if (main::ten_n40g_compare_pti_byte($module_id)) {
        print "Pass\n";
        return 0;
    }
    print "FAIL *\n";
    return 1;
}

# Returns 0 when the received PTI byte matches the expected value
sub check_n10g_pti_byte {
    my ($module_id, $slice) = @_;
    printf "check_n10g_pti_byte      %s ... ", module_slice($module_id, $slice);
    if (main::ten_n10g_compare_pti_byte($module_id, $slice)) {
        print "Pass\n";
        return 0;
    }
    print "FAIL *\n";
    return 1;
}

sub check_pp10g_pcs_insync{
    my ($module_id, $slice) = @_;
    printf "check_pp10g_pcs_insync   %s ... ", module_slice($module_id, $slice);
    if (main::ten_pp10g_pcs_rx_status($module_id, $slice, main::TEN_PP10G_PCS_RX_SYNCDETS)) {
        print "Pass\n";
        return 0;
    }
    print "FAIL *\n";
    return 1;
}

sub check_pp10g_egpcs_insync{
    my ($module_id, $slice) = @_;
    printf "check_pp10g_egpcs_insync %s ... ", module_slice($module_id, $slice);
    if (main::ten_pp10g_egpcs_rx_intstatus($module_id, $slice)) {
        print "Pass\n";
        return 0;
    }
    print "FAIL *\n";
    return 1;
}

sub check_pp10g_xaui_insync{
    my ($module_id, $slice) = @_;
    printf "check_pp10g_xaui_insync  %s ... ", module_slice($module_id, $slice);
    if (main::ten_pp10g_xaui_rx_check_insync($module_id, $slice)) {
        print "Pass\n";
        return 0;
    }
    print "FAIL *\n";
    return 1;
}

sub check_pp40g_pcs_xdc_insync{
    my ($module_id, $slice) = @_;
    printf "check_pp40g_pcs_xdc_insync   %d ... ", $module_id;
    if (main::ten_pp40g_pcs_rx_intstatus_t41($module_id, main::TEN_PP40G_PCS_RX_INTSTATUS_SELECT_XDCBLOCKLOCKS)) {
        print "Pass\n";
        return 0;
    }
    print "FAIL *\n";
    return 1;
}

sub check_pp40g_pcs_mono_insync{
    my ($module_id, $slice) = @_;
    printf "check_pp40g_pcs_xdc_insync   %d ... ", $module_id;
    if (main::ten_pp40g_pcs_rx_intstatus_t41($module_id, main::TEN_PP40G_PCS_RX_INTSTATUS_SELECT_MONOBLOCKLOCKS)) {
        print "Pass\n";
        return 0;
    }
    print "FAIL *\n";
    return 1;
}

sub check_pp40g_pcs_lane_insync{
    my ($module_id, $slice) = @_;
    printf "check_pp40g_pcs_xdc_insync   %d ... ", $module_id;
    if (main::ten_pp40g_pcs_rx_intstatus_t41($module_id, main::TEN_PP40G_PCS_RX_INTSTATUS_SELECT_LANEBLOCKLOCKXS)) {
        print "Pass\n";
        return 0;
    }
    print "FAIL *\n";
    return 1;
}

sub check_pbert_counters{
    my ($module_id, $slice) = @_;
    my $dev_id = $module_id >> 8;
    my $pbert_slice = ($module_id == 0) ? $slice : $slice+4;
    my $show_counts = 0;
    my $long_test = 0;
    my $return_code = 1;

    printf "check_pbert_counters     %s ... ", module_slice($module_id, $slice);

    main::ten_xcon_pbert_control_generator($dev_id, $pbert_slice, main::CS_DISABLE);

    main::ten_xcon_pbert_rx_reset($dev_id, $pbert_slice, main::CS_RESET_TOGGLE);
    main::ten_xcon_pbert_tx_reset($dev_id, $pbert_slice, main::CS_RESET_TOGGLE);

    main::ten_pp10g_pm_clear($module_id, $slice,1);
    main::ten_dev_clear_stats($dev_id);

    main::ten_xcon_pbert_control_generator($dev_id, $pbert_slice, main::CS_ENABLE);

    if ($long_test == 1) {
      sleep 900;
    }
    else {
      sleep 30;
    }

    main::ten_xcon_pbert_control_generator($dev_id, $pbert_slice, main::CS_DISABLE);

    my $fail =0;
    my $tx_unit = int(main::ten_dev_read_stat($dev_id, main::TEN_ID_XCON, $pbert_slice, main::TEN_XCON_PBERT_GOOD_UCNT_STAT,main::CS_TX));
    my $tx_octet = int(main::ten_dev_read_stat($dev_id, main::TEN_ID_XCON, $pbert_slice, main::TEN_XCON_PBERT_GOOD_UOCNT_STAT,main::CS_TX));
    my $rx_good_unit = int(main::ten_dev_read_stat($dev_id, main::TEN_ID_XCON, $pbert_slice, main::TEN_XCON_PBERT_GOOD_UCNT_STAT,main::CS_RX));
    my $rx_good_octet = int(main::ten_dev_read_stat($dev_id, main::TEN_ID_XCON, $pbert_slice, main::TEN_XCON_PBERT_GOOD_UOCNT_STAT,main::CS_RX));
    my $rx_error_unit = int(main::ten_dev_read_stat($dev_id, main::TEN_ID_XCON, $pbert_slice, main::TEN_XCON_PBERT_RX_UERRCNT_STAT,main::CS_RX));
    my $rx_error_octet = int(main::ten_dev_read_stat($dev_id, main::TEN_ID_XCON, $pbert_slice, main::TEN_XCON_PBERT_RX_UOERRCNT_STAT,main::CS_RX));

    if ($tx_unit == 0) {
      $fail++;
    }
    if ($tx_unit != $rx_good_unit) {
      $fail++;
    }
    if ($tx_octet != $rx_good_octet) {
      $fail++;
    }
    if ($rx_error_unit != 0) {
      $fail++;
    }
    if ($rx_error_octet != 0) {
      $fail++;
    }

    main::ten_xcon_pbert_rx_reset($dev_id, $pbert_slice, main::CS_RESET_TOGGLE);
    main::ten_xcon_pbert_tx_reset($dev_id, $pbert_slice, main::CS_RESET_TOGGLE);

    main::ten_xcon_pbert_control_generator($dev_id, $pbert_slice, main::CS_ENABLE);

    if ($fail == 0) {
        print "Pass\n";
        $return_code = 0;
    }
    else {
      print "FAIL *\n\n";
    }

    if (($fail != 0) || ($show_counts != 0)) {
      printf("\n ==========================================================================\n");
      printf(" PBert                                RX(%d)                      TX(%d)       \n",$slice,$slice);
      printf(" ==========================================================================\n");
      printf(" UNITS:                               %8d                    %8d        \n",$rx_good_unit,$tx_unit);
      printf(" UNIT OCTETS:                         %8d                    %8d        \n",$rx_good_octet,$tx_octet);
      printf(" ERROR UNITS:                         %8d                         N/A        \n",$rx_error_unit);
      printf(" ERROR UNIT OCTETS:                   %8d                         N/A        \n\n\n",$rx_error_octet);
    }

    return $return_code;
}

sub check_pbert_40g_counters{
    my ($module_id) = @_;
    my $show_counts = 0;
    my $long_test = 0;
    my $return_code = 1;

    printf "check_pbert_40_counters      %d ... ", $module_id;

    main::ten_pp40g_pbert_control_generator_t41($module_id, main::CS_DISABLE);

    main::ten_mod_clear_blk_stats ($module_id, main::TEN_ID_PP40G);

    main::ten_pp40g_pbert_control_generator_t41($module_id, main::CS_ENABLE);

    if ($long_test == 1) {
      sleep 900;
    }
    else {
      sleep 5;
    }

    main::ten_pp40g_pbert_control_generator_t41($module_id, main::CS_DISABLE);

    my $fail =0;

    my $tx_unit = int(main::ten_mod_read_stat($module_id, main::TEN_ID_PP40G, 0, main::TEN_PP40G_PBERT40G_TX_FRMCNT,main::CS_TX));
    my $tx_octet = int(main::ten_mod_read_stat($module_id, main::TEN_ID_PP40G, 0, main::TEN_PP40G_PBERT40G_TX_FRMOCTCNT,main::CS_TX));
    my $rx_good_unit = int(main::ten_mod_read_stat($module_id, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_GOOD_FRAMES,main::CS_RX));
    my $rx_good_octet = int(main::ten_mod_read_stat($module_id, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_GOOD_OCTETS,main::CS_RX));
    my $rx_error_unit = int(main::ten_mod_read_stat($module_id, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_ERR_FRAMES,main::CS_RX));
    my $rx_error_octet = int(main::ten_mod_read_stat($module_id, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_BAD_OCTETS,main::CS_RX));

    if ($tx_unit == 0) {
      $fail++;
    }
    if ($tx_unit != $rx_good_unit) {
      $fail++;
    }
    if ($tx_octet != $rx_good_octet) {
      $fail++;
    }
    if ($rx_error_unit != 0) {
      $fail++;
    }
    if ($rx_error_octet != 0) {
      $fail++;
    }

    # Leave PBERT running
    main::ten_pp40g_pbert_control_generator_t41($module_id, main::CS_ENABLE);

    if ($fail == 0) {
        print "Pass\n";
        $return_code = 0;
    }
    else {
      print "FAIL *\n\n";
    }

    if (($fail != 0) || ($show_counts != 0)) {
      printf("\n =====================================================================\n");
      printf(" PBert\t\t\tRX\t\t\tTX\n");
      printf(" =====================================================================\n");
      printf(" GOOD FRAMES: \t\t%12d\t\t%12d\n",$rx_good_unit,$tx_unit);
      printf(" GOOD OCTETS: \t\t%12d\t\t%12d\n",$rx_good_octet,$tx_octet);
      printf(" ERROR FRAMES:\t\t%12d\t\tN/A\n",$rx_error_unit);
      printf(" ERROR OCTETS:\t\t%12d \t\tN/A\n\n\n",$rx_error_octet);
    }

    return $return_code;
}

sub check_pbert_40g_loop_fe{
    my ($mod_line, $mod_client) = @_;

    main::ten_pp40g_pbert_enable_t41($mod_client, main::CS_DISABLE);
    main::ten_pp40g_pbert_enable_t41($mod_line,   main::CS_ENABLE);
    check_pbert_40g_counters_both_rx($mod_line);
    main::ten_pp40g_pbert_enable_t41($mod_line,   main::CS_DISABLE);
    main::ten_pp40g_pbert_enable_t41($mod_client, main::CS_ENABLE);
    check_pbert_40g_counters_both_rx($mod_client);
    main::ten_pp40g_pbert_enable_t41($mod_line,   main::CS_ENABLE);
    main::ten_pp40g_pbert_enable_t41($mod_client, main::CS_ENABLE);
}

sub check_pbert_40g_counters_both_rx{
    my ($module_id) = @_;
    my $show_counts = 0;
    my $long_test = 0;
    my $return_code = 1;

    printf "check_pbert_40g_counters     %d ... ", $module_id;

    main::ten_pp40g_pbert_control_generator_t41($module_id, main::CS_DISABLE);

    main::ten_mod_clear_blk_stats ($module_id, main::TEN_ID_PP40G);

    main::ten_pp40g_pbert_control_generator_t41($module_id, main::CS_ENABLE);

    if ($long_test == 1) {
      sleep 900;
    }
    else {
      sleep 30;
    }

    main::ten_pp40g_pbert_control_generator_t41($module_id, main::CS_DISABLE);

    my $fail =0;

    my $module_id_other;
    
    my $tx_unit = int(main::ten_mod_read_stat($module_id, main::TEN_ID_PP40G, 0, main::TEN_PP40G_PBERT40G_TX_FRMCNT,main::CS_TX));
    my $tx_octet = int(main::ten_mod_read_stat($module_id, main::TEN_ID_PP40G, 0, main::TEN_PP40G_PBERT40G_TX_FRMOCTCNT,main::CS_TX));
    my $rx_good_unit_0 = int(main::ten_mod_read_stat(0, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_GOOD_FRAMES,main::CS_RX));
    my $rx_good_unit_1 = int(main::ten_mod_read_stat(1, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_GOOD_FRAMES,main::CS_RX));
    my $rx_good_octet_0 = int(main::ten_mod_read_stat(0, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_GOOD_OCTETS,main::CS_RX));
    my $rx_good_octet_1 = int(main::ten_mod_read_stat(1, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_GOOD_OCTETS,main::CS_RX));
    my $rx_error_unit_0 = int(main::ten_mod_read_stat(0, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_ERR_FRAMES,main::CS_RX));
    my $rx_error_unit_1 = int(main::ten_mod_read_stat(1, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_ERR_FRAMES,main::CS_RX));
    my $rx_error_octet_0 = int(main::ten_mod_read_stat(0, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_BAD_OCTETS,main::CS_RX));
    my $rx_error_octet_1 = int(main::ten_mod_read_stat(1, main::TEN_ID_PP40G, 0, main::TEN_cntr_id_MAC40G_RX_BAD_OCTETS,main::CS_RX));

    if ($tx_unit == 0) {
      $fail++;
    }
    if (($tx_unit != $rx_good_unit_0) or ($tx_unit != $rx_good_unit_1)) {
      $fail++;
    }
    if (($tx_octet != $rx_good_octet_0) or ($tx_octet != $rx_good_octet_1)) {
      $fail++;
    }
    if (($rx_error_unit_0 != 0) or ($rx_error_unit_1 != 0)) {
      $fail++;
    }
    if (($rx_error_octet_0 != 0) or ($rx_error_octet_1 != 0)) {
      $fail++;
    }

    # Leave PBERT running
    main::ten_pp40g_pbert_control_generator_t41($module_id, main::CS_ENABLE);

    if ($fail == 0) {
        print "Pass\n";
        $return_code = 0;
    }
    else {
      print "FAIL *\n\n";
    }

    if (($fail != 0) || ($show_counts != 0)) {
      printf("\n =================================================================================================\n");
      printf(" PBert\t\t\tRX(0)\t\t\tRX(1)\t\t\tTX\n");
      printf(" =================================================================================================\n");
      printf(" GOOD FRAMES: \t\t%12d\t\t%12d\t\t%12d\n",$rx_good_unit_0,$rx_good_unit_1,$tx_unit);
      printf(" GOOD OCTETS: \t\t%12d\t\t%12d\t\t%12d\n",$rx_good_octet_0,$rx_good_octet_1,$tx_octet);
      printf(" ERROR FRAMES:\t\t%12d\t\t%12d\t\tN/A\n",$rx_error_unit_0,$rx_error_unit_1);
      printf(" ERROR OCTETS:\t\t%12d\t\t%12d\t\tN/A\n\n\n",$rx_error_octet_0,$rx_error_octet_1);
    }

    return $return_code;
}

# Checks for Loss of Frame Delineation
sub check_pp10g_gfp_insync{
    my ($module_id, $slice) = @_;
    printf "check_pp10g_gfp_insync   %s ... ", module_slice($module_id, $slice);
    if (main::ten_pp10g_gfp_rx_get_status($module_id, $slice, main::TEN_PP10G_GFP_RX_STATUS_LFDS) == 0) {
        print "Pass\n";
        return 0;
    }
    print "FAIL *\n";
    return 1;
}


sub check_all {
    my ($mod_line, $slice_line, $mod_client, $slice_client, $aggr, 
        $mod_client_int, $slice_client_int, $sfi41_ufec_alloc, %args) = @_;
    my $fail = 0;
    print "\nBeginning tests...\n\n";
    # Look for bus errors
    # Look for 'Bus Error' in the server logs

    my $dev_id;
    if ((defined $mod_line) and ($mod_line ne 'invalid')) {
        $dev_id = $mod_line >> 8;
    } else {
        $dev_id = $mod_client >> 8;
    }

    ### TODO: This returns CS_ERROR on a bus error
    ### Increment $fail on a bus error
    ## bus errors are printed out inline in log, so this always returns CS_OK.
    ## main::ten_dev_print_bus_error_info($dev_id);


    if ($args{mode} eq 'hsif_kpga40') {
        if ($args{hsif_lb_kpga_enum} ==  main::TEN_HSIF_PROTOCOL_CFP) {
            if (main::ten_hl_hsif_cfp_check_kpga_t41 ($args{module_id_lb_kpga}, main::TEN_SLICE_ALL) != main::CS_OK) {
                printf ("HSIF KPGA failed %s!\n", module_only($args{module_id_lb_kpga}) );
                $fail++;
                        #main::ten_hl_hsif_cfp_check_kpga_t41 ($args{module_id_lb_kpga}, main::TEN_SLICE_ALL);
            } else {
                printf ("HSIF KPGA passed %s\n", module_only($args{module_id_lb_kpga}) );
            }                                                                          
        }
        elsif ($args{hsif_lb_kpga_enum} ==  main::TEN_HSIF_PROTOCOL_XFI) {
            if (main::ten_hl_hsif_xfi_check_kpga ($args{module_id_lb_kpga}, main::TEN_SLICE_ALL) != main::CS_OK) {
                printf ("HSIF KPGA failed %s!\n", module_only($args{module_id_lb_kpga}) );
                $fail++;
                        #main::ten_hl_hsif_cfp_check_kpga_t41 ($args{module_id_lb_kpga}, main::TEN_SLICE_ALL);
            } else {
                printf ("HSIF KPGA passed %s\n", module_only($args{module_id_lb_kpga}) );
            }                                                                          
        } else {
            my $prbs_out_of_sync_0;
            my $prbs_out_of_sync_1;
            my $prbs_out_of_sync_2;
            my $prbs_out_of_sync_3;
        
            #$prbs_out_of_sync = main::ten_hsif_mr10_sds_common_prbchk0_intstatus ($args{module_id_lb_kpga}, main::TEN_SLICE_ALL, main::TEN_INSTANCE_ALL);
            $prbs_out_of_sync_0 = main::ten_hsif_mr10_sds_common_prbchk0_intstatus ($args{module_id_lb_kpga}, 0, main::TEN_INSTANCE_ALL);
            print ("HSIF PRBS 0 prbs_out_of_sync = $prbs_out_of_sync_0\n");
            $prbs_out_of_sync_1 = main::ten_hsif_mr10_sds_common_prbchk0_intstatus ($args{module_id_lb_kpga}, 1, main::TEN_INSTANCE_ALL);
            print ("HSIF PRBS 1 prbs_out_of_sync = $prbs_out_of_sync_1\n");
            $prbs_out_of_sync_2 = main::ten_hsif_mr10_sds_common_prbchk0_intstatus ($args{module_id_lb_kpga}, 2, main::TEN_INSTANCE_ALL);
            print ("HSIF PRBS 2 prbs_out_of_sync = $prbs_out_of_sync_2\n");
            #$prbs_out_of_sync = main::ten_hsif_mr10_sds_common_prbchk0_intstatus ($args{module_id_lb_kpga}, 3, main::TEN_INSTANCE_ALL);
            $prbs_out_of_sync_3 = (main::ten_hsif_mr10_sds_common_prbchk0_intstatus ($args{module_id_lb_kpga}, 3, main::TEN_INSTANCE_ALL) & 0xF);
            print ("HSIF PRBS 3 prbs_out_of_sync = $prbs_out_of_sync_3\n");

            if (($prbs_out_of_sync_0) || ($prbs_out_of_sync_1) || ($prbs_out_of_sync_2) || ($prbs_out_of_sync_3)){
                print ("HSIF PRBS is OUT of sync!\n");
                main::ten_mod_read_stat ($args{module_id_lb_kpga}, main::TEN_ID_HSIF, 0, 0, main::CS_RX);
                $fail++;
            } else {
                print ("HSIF PRBS is IN sync!\n");
            }
        }
        return $fail;
    }

    elsif ($args{mode} eq 'hsif_kpga10') {
        my $prbs_out_of_sync;
        if ($args{hsif_lb_kpga} eq 'xfi') {
            if (main::ten_xfi32x1_prbschk_get_status ($args{module_id_lb_kpga}, $args{slice_lb_kpga})) {
                print ("XFI $args{slice_lb_kpga} HSIF PRBS is IN sync\n");
            } else {
                print ("XFI $args{slice_lb_kpga} HSIF PRBS is NOT in sync\n");
                $fail++;
            }
        }
        elsif ($args{hsif_lb_kpga_enum} ==  main::TEN_HSIF_PROTOCOL_CFP) {
            if (main::ten_hl_hsif_cfp_check_kpga_t41 ($args{module_id_lb_kpga}, $args{slice_lb_kpga}) != main::CS_OK) {
                printf("CPF_MR HSIF KPGA failed %s!\n", $args{slice_lb_kpga});
                $fail++;
            } 
            else {
                printf("CFP_MR HSIF KPGA passed\n");
                #printf("CFP_MR HSIF KPGA passed %s %s.\n", $args{module_id_lb_kpga}, $args{slice_lb_kpga}) );
            }                                                                          
        }
        else {
            $prbs_out_of_sync = main::ten_hsif_mr10_sds_common_prbchk0_intstatus ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, main::TEN_INSTANCE_ALL);
            if ($prbs_out_of_sync) {
                print ("MR $args{slice_lb_kpga} HSIF PRBS is OUT of sync!\n");
                $fail++;
            } 
            else {
                print ("MR $args{slice_lb_kpga} HSIF PRBS is IN sync!\n");
            }
        }
        return $fail;
    }

    # Check the client XFI port
    if (($args{client} ne 'null') &&
        ($args{client} ne 'invalid') &&
        ($args{pbert_40g_test} ne 'loop_fe') &&
        ($args{pbert_40g_test} ne 'line')) {
        if ($args{hsif_client} eq 'xfi') {
            ### TODO: Doesn't handle SFI-4.1 yet
            printf "check_xfi_filt_lock      %s ... ", module_slice($mod_client, $slice_client);
            if (check_xfi_filt_lock($mod_client, $slice_client) != main::CS_OK) {
                print "FAIL *\n";
                $fail++;
            }
            else {
                print "Pass\n";
            }
            
            if ($args{clientrate} == 40) {
                if (main::ten_hsif_xfi_check_lockd0 ($mod_client, main::TEN_SLICE_ALL) != main::CS_OK) {
                    printf "%s XFI Failed!!\n", module_slice($mod_client, $slice_client);
                }
            }
        }
    }
    if ($args{linerate} == 10) {
        if ($args{line_port} >= 4) {
            if ($args{hsif_line} eq 'xfi') {
                printf "check_xfi_filt_lock      %s ... ", module_slice($mod_line, $slice_line);
                if (check_xfi_filt_lock($mod_line, $slice_line) != main::CS_OK) {
                    print "FAIL *\n";
                    $fail++;
                }
                else {
                    print "Pass\n";
                }
            }
        }
    }

    # Checks for unframed mode
    if ($args{mode} eq 'cbr_kpga10') {
        $fail += check_n10g_kpa_sync ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{kpga_pattern_enum});
        return $fail;
    }
    elsif ($args{mode} eq 'cbr_kpga40') {
        $fail += check_n40g_kpa_sync ($args{module_id_lb_kpga}, $args{kpga_pattern_enum});
        return $fail;
    }
    elsif (($args{mode} eq 'wire10') || ($args{mode} eq 'wire40')) {
        # No further tests for wire mode
        return $fail;
    }

    # Check for SONET in frame and with a valid pointer
    #if (($args{client} eq 'oc192') || ($args{client} eq 'oc192_async')) {
    if ($args{client} =~ /oc192/) {
        if ($args{client} ne '10ge_gfpf_oc192_odu2') {
        # These functions return 1 on error
        $fail += check_sonet_framing_10g($mod_client, $slice_client);
        if ((! exists $args{check_sonet_pointer_n10g}) or ($args{check_sonet_pointer_n10g} != 0))  {
            # This will fail with OC192 in transparent mode, so this test is disabled for that config
            $fail += check_sonet_pointer_n10g($mod_client, $slice_client);
        }
      }
    }
    elsif ($args{client} =~ 'oc768') {
        $fail += check_sonet_framing_40g ($mod_client);
    }

    # OTN
    if ($args{client} eq 'otu2') {
        $fail += check_n10g_otn_inframe($mod_client, $slice_client);
    }
    elsif ($args{client} eq 'cbr_1118099736') {
	    $fail += check_n10g_otn_inframe($mod_client, $slice_client);
	}
    elsif ($args{client} eq 'cbr_1052329163') {
	    $fail += check_n10g_otn_inframe($mod_client, $slice_client);
	}
    elsif ($args{client} eq 'otu2e') {
        $fail += check_n10g_otn_inframe($mod_client, $slice_client);
    }
    elsif ($args{client} eq 'otu1e') {
        $fail += check_n10g_otn_inframe($mod_client, $slice_client);
    }
    elsif ($args{client} eq 'otu1f') {
        $fail += check_n10g_otn_inframe($mod_client, $slice_client);
    }
    elsif ($args{client} =~ /otu3/) {
        #$fail += check_n40g_otn_inframe($mod_client);
        if ($args{clientrate} == 40) {
            $fail += check_n40g_otn_inframe($mod_client);
            if (($args{line} !~ /otu3/) && ($args{mode} ne 'lb40')) {
                $fail += check_n40g_pti_byte($mod_client);
            }
        }
    }


    # 10GE
    elsif ($args{client} eq '10ge') {
      if ($args{hsif_client_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
        $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
      }
      else {
        $fail += check_pp10g_xaui_insync($mod_client, $slice_client);
      }
    }
    elsif ($args{client} eq '10ge6_1') {
      if ($args{hsif_client_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
        $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
      }
      else {
        $fail += check_pp10g_xaui_insync($mod_client, $slice_client);
      }
    }
    elsif ($args{client} eq '10ge6_2') {
        $fail += check_pp10g_gfp_insync($mod_line, $aggr ? $slice_client : $slice_line);
        if ($args{hsif_client_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
          $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
        }
        else {
          $fail += check_pp10g_xaui_insync($mod_client, $slice_client);
        }
    }
    elsif ($args{client} eq '10ge7_1') {
        if ($args{hsif_client_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
          $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
        }
        else {
          $fail += check_pp10g_xaui_insync($mod_client, $slice_client);
        }
    }
    elsif ($args{client} eq '10ge7_2') {
        if ($args{hsif_client_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
          $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
        }
        else {
          $fail += check_pp10g_xaui_insync($mod_client, $slice_client);
        }
    }
    elsif ($args{client} eq '10ge7_3') {
        $fail += check_pp10g_gfp_insync($mod_line, $aggr ? $slice_client : $slice_line);
        if ($args{hsif_client_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
          $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
        }
        else {
          $fail += check_pp10g_xaui_insync($mod_client, $slice_client);
        }
    }
    elsif ($args{client} eq '10ge_ra') {
        if ($args{hsif_client_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
          $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
        }
        else {
          $fail += check_pp10g_xaui_insync($mod_client, $slice_client);
        }
    }
    elsif ($args{client} eq '10ge_gfpf_oc192_odu2') {
        $fail += check_pp10g_gfp_insync($mod_line, $aggr ? $slice_client : $slice_line);
        if ($args{hsif_client_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
          $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
        }
        else {
          $fail += check_pp10g_xaui_insync($mod_client, $slice_client);
        }
    }
    elsif ($args{client} eq '10ge_tc') {
        $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
        $fail += check_pp10g_pcs_insync($mod_line, $slice_line);
        $fail += check_n10g_otn_inframe($mod_line, $slice_line);
        $fail += check_pp10g_gfp_insync($mod_line, $slice_line);
    }
    elsif ($args{client} eq '10ge_pbert') {
        $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
    }
    elsif ($args{client} eq '1ge') { # Bugzilla 38871
        if ($args{hsif_client_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
        }
        else {
          $fail += check_pp10g_xaui_insync($mod_client, $slice_client);
        }
    }
     elsif (($args{client} eq 'pbert_8gfc') ||
            ($args{client} eq 'pbert_4gfc') ||
            ($args{client} eq 'pbert_2gfc')) {
        $fail += check_pp10g_egpcs_insync($mod_client, $slice_client);
        $fail += check_pbert_counters($mod_client, $slice_client);
    }
    elsif ($args{client} eq 'pbert_10gfc') {
        $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
        $fail += check_pbert_counters($mod_client, $slice_client);
    }
    elsif ($args{client} =~ /pbert_10ge/) {
        $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
        $fail += check_pbert_counters($mod_client, $slice_client);
    }
   elsif (($args{client} =~ /10gfc_tc/) ||  # Bug 31054
          ($args{client} eq 'fdr10_iba')) { # Bug 39242
        $fail += check_pp10g_pcs_insync($mod_client, $slice_client);
    }
    elsif (($args{client} =~ /8gfc/) ||
           ($args{client} =~ /4gfc/) ||
           ($args{client} =~ /2gfc/) ||
           ($args{client} =~ /1gfc/) ||
           ($args{client} =~ /2gisc/) ) {
        $fail += check_pp10g_egpcs_insync($mod_client, $slice_client);
    }
    # 40GE
    elsif ($args{client} eq '40ge_tc') {
        if ($args{pbert_40g_test} ne 'line') {
            $fail += check_pp40g_pcs_xdc_insync($mod_client);
        }
        if ($args{pbert_40g_test} eq 'loop_fe') {
            main::check_pbert_40g_loop_fe($mod_line, $mod_client);
        }
    }
    elsif (($args{client} eq '40gex') or ($args{client} eq '40gex_ra')) {
        if ($args{pbert_40g_test} ne 'line') {
            $fail += check_pp40g_pcs_xdc_insync($mod_client);
        }
        if ($args{pbert_40g_test} eq 'loop_fe') {
            main::check_pbert_40g_loop_fe($mod_line, $mod_client);

        }
    }
    elsif (($args{client} eq '40gep') or ($args{client} eq '40gep_ra')) {
        if ($args{pbert_40g_test} ne 'line') {
            $fail += check_pp40g_pcs_lane_insync($mod_client);
        }
        if ($args{pbert_40g_test} eq 'loop_fe') {
            main::check_pbert_40g_loop_fe($mod_line, $mod_client);

        }
    }
    elsif (($args{client} eq '40gesbi') or ($args{client} eq '40gesbi_ra')) {
        if ($args{pbert_40g_test} ne 'line') {
            $fail += check_pp40g_pcs_mono_insync($mod_client);
        }
        if ($args{pbert_40g_test} eq 'loop_fe') {
            main::check_pbert_40g_loop_fe($mod_line, $mod_client);

        }
    }
    elsif (($args{client} eq '40ges6466') or ($args{client} eq '40ges6466_ra')) {
        if ($args{pbert_40g_test} ne 'line') {
            $fail += check_pp40g_pcs_mono_insync($mod_client);
        }
        if ($args{pbert_40g_test} eq 'loop_fe') {
            main::check_pbert_40g_loop_fe($mod_line, $mod_client);

        }
    }

    # Check the line side
    if (($args{line} =~ /otu3/) && (($args{client} !~/pbert/) && ($args{client} ne 'null'))) { # Bugzilla 29609
        if ($args{linerate} == 40) {
            $fail += check_n40g_otn_inframe($mod_line);
            if (($args{client} !~ /otu3/) && ($args{mode} ne 'lb40')) {
                $fail += check_n40g_pti_byte($mod_line);
            }
        }
        # Bugzilla 29100 Start
        if (($args{mode} eq 'mux') && (defined $slice_client)) {
            if ($args{clientrate} == 40) {
                # Dual muxponder
                for (my $slice=0; $slice<4; $slice++) {
                    $fail += check_n10g_otn_inframe($mod_line, $slice);
                    $fail += check_n10g_otn_inframe($mod_client, $slice);
                }
            } else {
                $fail += check_n10g_otn_inframe($mod_line, $slice_client);
            }
            # Bugzilla 29100 End
            # The PTI byte is passed through so we don't know what it should be
            if (($args{client} ne 'otu2') && ($args{client} ne 'otu2e') && ($args{client} ne 'otu1e') && 
			    ($args{mode} ne 'lb10') && ($args{client} ne 'otu3')) {
                $fail += check_n10g_pti_byte($mod_line, $slice_client);
            }
            #if (($args{client} eq '10ge7_1') || ($args{client} eq '10ge7_3') || ($args{client} eq '10gfc_tc')) {
            if (($args{client} eq '10ge7_1') || ($args{client} =~ /10gfc/)) { # Bug 31054
                $fail += check_n10g_otn_inframe($mod_line, $slice_client);
                $fail += check_pp10g_pcs_insync($mod_line, $slice_client);
            }
        }
    }
    if (($args{line} eq 'otu2') && ($args{client} !~/pbert/)) {
#    if (($args{line} eq 'otu2') && ($args{client} !~/pbert/) && ($args{dyn_repro} != main::TEN_REPRO_LINE_AND_CLIENT)) {
        $fail += check_n10g_otn_inframe($mod_line, $slice_line);
    }
    elsif (($args{line} eq 'otu2e') && ($args{client} !~/pbert/)) {
        if($sfi41_ufec_alloc) {
            $fail += check_n10g_otn_inframe($mod_client_int, $slice_client_int);
        }
        else {
            $fail += check_n10g_otn_inframe($mod_line, $slice_line);
        }
    }
    elsif (($args{line} eq 'cbr_1118099736') && ($args{client} !~/pbert/)) {
        $fail += check_n10g_otn_inframe($mod_line, $slice_line);
    }
    elsif (($args{line} eq 'cbr_1052329163') && ($args{client} !~/pbert/)) {
        $fail += check_n10g_otn_inframe($mod_line, $slice_line);
    }	
    elsif (($args{line} eq 'otu1e') && ($args{client} !~/pbert/)) {
        if($sfi41_ufec_alloc) {
            $fail += check_n10g_otn_inframe($mod_client_int, $slice_client_int);
        }
        else {
            $fail += check_n10g_otn_inframe($mod_line, $slice_line);
        }
    }
    elsif (($args{line} eq 'otu1f') && ($args{client} !~/pbert/)) {
        $fail += check_n10g_otn_inframe($mod_line, $slice_line);
    }
    # 10GE
    elsif ($args{line} eq '10ge') {
      if ($args{hsif_line_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
        $fail += check_pp10g_pcs_insync($mod_line, $slice_line);
      }
      else {
        $fail += check_pp10g_xaui_insync($mod_line, $slice_line);
      }
    }
    elsif ($args{line} =~ 'oc192') {
        # Check for SONET in frame and with a valid pointer
        # These functions return 1 on error
        $fail += check_sonet_framing_10g($mod_line, $slice_line);
        if ((! exists $args{check_sonet_pointer_n10g}) or ($args{check_sonet_pointer_n10g} != 0))  {
            # This will fail with OC192 in transparent mode, so this test is disabled for that config
            $fail += check_sonet_pointer_n10g($mod_line, $slice_line);
        }
    }
    elsif ($args{line} =~ 'oc768') {
        $fail += check_sonet_framing_40g ($mod_line);
    }
    elsif ($args{line} eq '10ge_ra') { # Bugzilla 37022
        if ($args{hsif_line_enum} != main::TEN_HSIF_PROTOCOL_XAUI) {
          $fail += check_pp10g_pcs_insync($mod_line, $slice_line);
        }
        else {
          $fail += check_pp10g_xaui_insync($mod_line, $slice_line);
        }
    }


    if (($args{mode} eq 'trans40') && ($args{client} ne 'null')) {  # Bugzilla 29609
        ###############################################################################
        # misc_info("Trigger a stats update to clear sync garbage");
        ###############################################################################
        if (main::ten_glb_misc_gsti_update ($dev_id, 1, 0)) {   # Global Statistics Time Interval
            print("Failed to trigger stats update.\n");
            #return 1;
            $fail += 1;
        }

        ###############################################################################
        print("running traffic for a while...\n");
        ###############################################################################
        sleep 10;

        ###############################################################################
        # misc_info("Trigger a stats update");
        ###############################################################################
        if (main::ten_glb_misc_gsti_update($dev_id, 1, 0)) {
            print ("Failed to trigger stats update.\n");
            $fail += 1;
            #return 1;
        }

        ###############################################################################
        # misc_info("check for N40G RX A OTN in frame");
        ###############################################################################
        if (check_n40g_otn_inframe ($mod_line)) {
          print ("Line side N40G OTN is not in frame\n");
          return 1;
        }

        if ($args{deskew_ctrl} == main::TEN_SADECO_DESKEW) { # Bugzilla 28977
          ##############################################################################
          # misc_info("check for SADECO 1 in SYNC");
          ##############################################################################
          if (main::ten_xcon_sadeco_sadstat ($dev_id, $mod_client) != 1) {
              print ("SADECO Cient is not in SYNC\n");
              $fail += 1;
              #return 1;
          }
          if (main::ten_xcon_sadeco_sadstat ($dev_id, $mod_line) != 1) {
              print ("SADECO Line is not in SYNC\n");
              $fail += 1;
              #return 1;
          }

          # Check for Sadeco interrupt on Side A
          ####    if (tenabo_bf_read ($dev_id, main::TEN_XCON_SADECO_SADINT, 0, 0) == 0) {
          if (main::ten_xcon_get_sadeco_sadint_synci($dev_id, main::TEN_MODULE_A) == 0) {
              print ("SADECO Side A is staying in Sync\n");
          } 
          else {
              print ("SADECO Side A is not staying in Sync!\n");
              $fail += 1;
          }
          # Check for Sadeco interrupt on Side B
          ####    if (tenabo_bf_read ($dev_id, main::TEN_XCON_SADECO_SADINT + (0x40), 0, 0) == 0) {
          if (main::ten_xcon_get_sadeco_sadint_synci($dev_id, main::TEN_MODULE_B) == 0) {
              print ("SADECO Side B is staying in Sync\n");
          } 
          else {
              print ("SADECO Side B is not staying in Sync!\n");
              $fail += 1;
              #return 1;
          }
        }
        # Bugzilla 28977 Start
        elsif ($args{deskew_ctrl} == main::TEN_PP40G_BYPASS_DESKEW) {
          if (main::ten_pp40g_misc_intstatus_rx_dsk_syncs_t41(($dev_id<<8)|main::TEN_MODULE_A) == 0) {
              failure("DESKEW Side A not staying in Sync!");
          } else {
              print ("DESKEW Side A in Sync\n");
          }
          if (main::ten_pp40g_misc_intstatus_rx_dsk_syncs_t41 (($dev_id<<8)|main::TEN_MODULE_B) == 0) {
              failure("DESKEW Side B not staying in Sync!");
          } else {
              print ("DESKEW Side B in Sync\n");
          }
          
          #my $rx_dsk_syncl_A = main::ten_reg_read ($dev_id, main::TEN_PP40G_MISC_INTERRUPT);
          #if ($rx_dsk_syncl_A & 0x100) {
          #  print ("DESKEW Side A is not staying in Sync!\n");
          #}
          if (main::ten_pp40g_get_misc_interrupt_rx_dsk_synci_t41(($dev_id<<8)|main::TEN_MODULE_A) == 1) {
            print ("DESKEW Side A is not staying in Sync!\n");
          }
          
          #my $rx_dsk_syncl_B = main::ten_reg_read ($dev_id, main::TEN_PP40G_MISC_INTERRUPT + main::TEN_PP40G_STRIDE);
          #if ($rx_dsk_syncl_B & 0x100) {
          #  print ("DESKEW Side B is not staying in Sync!\n");
          #}
          if (main::ten_pp40g_get_misc_interrupt_rx_dsk_synci_t41(($dev_id<<8)|main::TEN_MODULE_B) == 1) {
            print ("DESKEW Side B is not staying in Sync!\n");
          }
          
          my $txdskerrA = main::ten_n40g_gbl4x_gblint(($dev_id<<8)|main::TEN_MODULE_A, main::TEN_INT_READ, main::TEN_N40G_GBL4X_GBLINT_TXDSKERR);
          my $txdskerrB = main::ten_n40g_gbl4x_gblint(($dev_id<<8)|main::TEN_MODULE_B, main::TEN_INT_READ, main::TEN_N40G_GBL4X_GBLINT_TXDSKERR);
          print ("TXDSKERR Side A = $txdskerrA\n");
          print ("TXDSKERR Side B = $txdskerrB\n");
        }
        # Bugzilla 28977 End

        sleep 1;
        ###############################################################################
        # misc_info("Check N40G A OTN BIP-8 Counters");
        ###############################################################################
        for (my $j=0; $j<=7; $j=$j+1) {
            my $rddata1 = 0;
            my $rddata0 = 0;
            my $rddata = 0;
            my $tcm_bit = 0;

            #$rddata1 = main::ten_reg_read ($dev_id, main::TEN_N40G_OOHR_BIP0ERC1 + (0x1000 * ($mod_line & 1)) + $j*2);
            #$rddata0 = main::ten_reg_read ($dev_id, main::TEN_N40G_OOHR_BIP0ERC0 + (0x1000 * ($mod_line & 1)) + $j*2);
            
            if ($j == 0) {
              $rddata = main::ten_mod_read_stat($mod_line, main::TEN_ID_N40G, 0, main::TEN_N40G_OOHR_BIP0ERC1_STAT, main::CS_RX);
            }
            elsif ($j == 1) {
              $rddata = main::ten_mod_read_stat($mod_line, main::TEN_ID_N40G, 0, main::TEN_N40G_OOHR_BIP1ERC1_STAT, main::CS_RX);
            }
            elsif ($j == 2) {
              $rddata = main::ten_mod_read_stat($mod_line, main::TEN_ID_N40G, 0, main::TEN_N40G_OOHR_BIP2ERC1_STAT, main::CS_RX);
            }
            elsif ($j == 3) {
              $rddata = main::ten_mod_read_stat($mod_line, main::TEN_ID_N40G, 0, main::TEN_N40G_OOHR_BIP3ERC1_STAT, main::CS_RX);
            }
            elsif ($j == 4) {
              $rddata = main::ten_mod_read_stat($mod_line, main::TEN_ID_N40G, 0, main::TEN_N40G_OOHR_BIP4ERC1_STAT, main::CS_RX);
            }
            elsif ($j == 5) {
              $rddata = main::ten_mod_read_stat($mod_line, main::TEN_ID_N40G, 0, main::TEN_N40G_OOHR_BIP5ERC1_STAT, main::CS_RX);
            }
            elsif ($j == 6) {
              $rddata = main::ten_mod_read_stat($mod_line, main::TEN_ID_N40G, 0, main::TEN_N40G_OOHR_BIP6ERC1_STAT, main::CS_RX);
            }
            elsif ($j == 7) {
              $rddata = main::ten_mod_read_stat($mod_line, main::TEN_ID_N40G, 0, main::TEN_N40G_OOHR_BIP7ERC1_STAT, main::CS_RX);
            }
            $rddata1 = $rddata >> 16;
            $rddata0 = $rddata & 0xFFFF;

            $tcm_bit = ($args{line_tcm_bits} >> $j) & 1;

            if (($j==0) || ($j==7) || ($tcm_bit)) {
                if ($rddata1 == 0) {
                    #print ("TEN_N40G_OOHR_BIP0ERC1 BIP $j Counter 1 = 0 as EXPECTED\n");
                } else {
                    print ("Line Side NON-ZERO TEN_N40G_OOHR_BIP0ERC1 BIP $j Counter 1: $rddata1\n");
                    $fail += 1;
                }

                if ($rddata0 == 0) {
                    #print ("TEN_N40G_OOHR_BIP0ERC0 BIP $j Counter 0 = 0 as EXPECTED\n");
                } else {
                    print ("Line Side NON-ZERO TEN_N40G_OOHR_BIP0ERC0 BIP $j Counter 0: $rddata0\n");
                    $fail += 1;
                }
            }
        }
    }
    #elsif (($args{mode} eq 'kpga40') || ($args{mode} eq 'cbr_kpga40')) {
    elsif ($args{mode} eq 'kpga40') {
        $fail += check_n40g_kpa_sync ($args{module_id_lb_kpga}, $args{kpga_pattern_enum});
    }
    #elsif (($args{mode} eq 'kpga10') || ($args{mode} eq 'cbr_kpga10')) {
    elsif ($args{mode} eq 'kpga10') {
        $fail += check_n10g_kpa_sync ($args{module_id_lb_kpga}, $args{slice_lb_kpga}, $args{kpga_pattern_enum});
    }

    return $fail;
}

###############################################################################
#
# Internal functions that shouldn't be ported to C
#
###############################################################################

sub failure {
    my ($failure_reason)=@_;
    print "\nScript FAILED  $failure_reason\n";
    main::ten_print("Script FAILED  $failure_reason\n");
}

##############################################################################
# On line help
##############################################################################
my $_sysclockStr = sysclocksStr('help'); # Get valid sysclk args and additional info for sysclk help

my $Usage = "$0
    -help | -h          To print this help message
  ###################
  # Global options: #
  ###################
    -dev_id             int - ID of device to be provisioned 
                              <0-2>
    -sysclk             int - System Reference Clock in MHz
                              $_sysclockStr
                              
    -dr                 str - Dynamically reprovision the client. 
                              -line must be specified and it must be the same as when 
                               the 40G was initialized or traffic will be disrupted
                               
    -drl                str - Dynamically reprovision the line and client 
                              (10G transponder only)
                              
    -mode               str - Mode of operation
                              <mux|trans|lb|kpga|hsif_kpga|cbr_kpga|kpga|wire>
                              Modes:
                              Mode        Side A      Side B      Description
                              -----------------------------------------------------------
                              mux         40G         4x10G   40G <-> 10G muxponder
                              -----------------------------------------------------------
                              trans       40G          40G    40G transponder
                                      or 4x10G        4x10G   4x10G <-> 4x10G transponder
                              -----------------------------------------------------------
                              lb              2x40G           40G xcon loopback
                                        or 40G or 4x10G       40G and 10G xcon loopback
                                            or 8x10G          10G xcon loopback
                              -----------------------------------------------------------
                              kpga            2x40G           40G kpga
                                        or 40G or 4x10G       40G and 10G kpga
                                            or 8x10G          10G kpga
                              -----------------------------------------------------------
                              hsif_kpga       2x40G           40G hsif_kpga
                                        or 40G or 4x10G       40G and 10G hsif_kpga
                                            or 8x10G          10G hsif_kpga
                              -----------------------------------------------------------
                              cbr_kpga        2x40G           40G cbr_kpga
                                        or 40G or 4x10G       40G and 10G cbr_kpga
                                            or 8x10G          10G cbr_kpga
                              -----------------------------------------------------------
                              wire        40G          40G    40G wire
                                        or 4x10G      4x10G   4x10G <-> 4x10G wire
                              
    -read               str - Name of file containing custom API calls in perl to be read
                              and executed after the main config and before releasing
                              from reset. The file should be in local directory \"custom\".

    -monitor            int - Enable passive monitoring of wire mode lines and clients
                              OR 10GEWAN (OC192)
                              <0=no monitoring
                               1=wire mode lines and clients
                               2=10GEWAN (OC192)>

    -recenter           str - XCON Elastic Store Amplitude recentering, configure and
                              activation. The \"typical\", \"wide\", and \"narrow\"
                              qualifiers simplify API access by directing how tight to
                              set API arguments in general terms. Narrow is used only for
                              the smallest and best-known demands on ES. Typical will
                              cover many but not all OTU2 fec gaps. Wide is for larger or
                              unknown ES demands.
                              -----------------------------------------------------------
                              amp           ES recentering is based on measured elastic
                              amp_typical   store min/max depths. <amp> is shorthand for
                              amp_wide      <amp_typical>. Typical, wide, and narrow 
                              amp_narrow    qualifiers provide corresponding ES margins
                                            and measurement durations.
                              -----------------------------------------------------------
                              fpa           ES recentering coincides with the next frame
                              fpa_typical   pulse. Recenter parameters affect elastic
                              fpa_wide      store start depth and upper and lower
                              fpa_narrow    thresholds. <fpa> is shorthand for
                                            <fpa_typical>. Typical, wide, and narrow
                                            qualifiers provide corresponding ES start
                                            depth and upper/lower ES thresholds.
                              
  ###################
  # HSIF options:   #
  ###################     
    -hsif_line          str - Host Interface type on Side A (default: disabled)
                              <sfi4_2|sfi5_1|xaui|cfp_mr>      for module A and
                              <xfi|sfi4_2|sfi5_1|xaui|cfp_mr>  for module B
                              
    -hsif_client        str - Host Interface type on Side B (default: disabled)
                              <sfi4_2|sfi5_1|xaui|cfp_mr>      for module A and
                              <xfi|sfi4_2|sfi5_1|xaui|cfp_mr>  for module B
                              
    -eds                int - Enhanced Deskew               (default: 1)
                              <0|1>
                              NOTE: -eds;0 sets the SFI-4.2 interface to standard deskew
                              
    -auxclk             str - (for XFI only, use for aux tx ref clk)

    -client_cupll       int - Specify which clean-up PLL the client uses. Ignored if 
                              client_cupll_profile is 'none'.
                              < 4-7 >
    -client_cupll_profile
                        str - Specify which clean-up PLL profile the client uses. Default
                              is 'none'. Can be numeric (0-999) or string (e.g. 
                              rxdiv_clk_311). The cupll profile id or name is one of the
                              keys used to index into the table of cleanup PLL profiles 
                              in file cupll_profiles.txt.

    -line_cupll         int - Specify which clean-up PLL the line uses. Ignored if 
                              line_cupll_profile is 'none'.
                              < 4-7 >
                              
    -line_cupll_profile str - Specify which clean-up PLL profile the line uses. Default
                              is 'none'. Can be numeric (0-999) or string (e.g. rxdiv_
                              clk_311). The cupll profile id or name is one of the keys 
                              used to index into the table of cleanup PLL profiles in 
                              file cupll_profiles.txt.

######################
# Line-side options: #
######################
    -line               str - Traffic Type on the line side (default: invalid)
                              <otu1f>             Overclocked OTU1(OTU1f) with 10GFC Client
                              <otu1e>             Overclocked OTU1(OTU1e) with 10GE Client
                                                  (G.Sup43 7.2)
                              <otu2>              OTU2
							  <cbr_1118099736>    OTU3e4/4 or OTU4/10
							  <cbr_1052329163>    ODU3e4/4 or OTU4/10
                              <otu2e>             Overclocked OTU2(OTU2e) with 10GE Client
                                                  (G.Sup43 7.1)
                              <10ge>              10G Ethernet LAN (for mapping into OTU2e)
                              <otu3>              OTU3
                              <otu3+>             OTU3+
                              <otu3e/otu3e1>      Overclocked OTU3 with 4xODU2e(10GE Client)
                                                  based on 16 frame multiframe (16 TS)
                              <otu3e2>            Overclocked OTU3 with 4xODU2e(10GE Client)
                                                  based on 32 frame multiframe (32 TS)
                              <otu3e4>            overclocked OTU3 based on 2/5 bandrate of
                                                  OTU4                    
                              <oc768>             40G SONET
                              <oc768_otu3>        KPGA inside 40G SONET inside OTU3
                              <10gfc>             10G Fibre Channel
                              <8gfc>              8G  Fiber Channel GMP LO
                              <8gfc_ra>           8G  Fiber Channel Rate Adapt
                              <4gfc_ra>           4G  Fiber Channel Rate Adapt
                              <2gfc_ra>           2G  Fiber Channel Rate Adapt
                              <1gfc_ra>           1G  Fiber Channel Rate Adapt
                              <oc192>             10G SONET
                              <oc192_otu2>        KPGA inside 10G SONET inside OTU2
                              <10ge>              10G Ethernet LAN

    -line_port          int - Line port identifier
                              <0-7>
                              Side A Port 1 = 0   Side B Port 1 = 4
                              Side A Port 2 = 1   Side B Port 2 = 5
                              Side A Port 3 = 2   Side B Port 3 = 6
                              Side A Port 4 = 3   Side B Port 4 = 7
                              
    -line_fec           str - Line FEC - Forward Error Correction  (default: gfec)
                              <gfec>   G.709 RS FEC (7%)   
                              <0fec>   Allocate FEC columns but do not enable FEC (7%) 
                              <nofec>  FEC Disable        
                            - Ultra FEC (7%,10%,12%,13%,15%,20%,25%,26%)
                                 <ufec7p_sdha>    Additional FEC redundancy in 16 of the 32 
                                                  fixed stuff columns
                                 <ufec7p_sdhb>    Additional FEC redundancy in all 32 fixed 
                                                  stuff column
                                 <ufec7p|ufec10p|ufec12p|ufec13p|ufec15p|ufec20p|ufec25p|ufec26p|ufec7p_263|ufec18p|ufec25p_295>
  
#########################
#  Client-side options: #
#########################
    -client             str - Traffic Type on the client side (default: invalid)
                              <null>                No client traffic
                              <oc192>               10G SONET
                              <oc192_otu2>          KPGA inside 10G SONET inside OTU2
                              <otu1f>               Overclocked OTU1(OTU1f) with 10GFC Client
                              <otu2>                OTU2
							  <cbr_1118099736>      OTU3e4/4 or OTU4/10
							  <cbr_1052329163>      ODU3e4/4 or ODU4/10
                              <otu2e>               Overclocked OTU2(OTU2e) with 10GE Client
                              <10ge>                10G Ethernet LAN (for mapping into OTU2e)
                              <10ge6_1>             10G Ethernet LAN (G.Sup43 6.1)
                              <10ge6_2>             10G Ethernet LAN (G.Sup43 6.2 - GFP-S into OPU2)
                              <10ge7_1>             10G Ethernet LAN (G.Sup43 7.1 - CBR10G into OPU2e)
                              <10ge7_2>             10G Ethernet LAN (G.Sup43 7.2 - CBR10G into OPU1e)
                              <10ge7_3>             10G Ethernet LAN (G.Sup43 7.3 / Transparent GFP-F into OPU2)
                              <10ge_gfpf_oc192_odu2 10G Ethernet LAN (GFPF into oc192 into OPU2)
                              <10ge_gfpf>           10G Ethernet LAN GFP-F
                              <10ge_ra>             10G Ethernet LAN Rate Adaptation
                              <10ge_tc>             Time Transparent 10G Ethernet through 512/513 transcoding
                              <1ge>                 1G Ethernet LAN (for mapping into ODU2)
                              <1gfc_ra>             1G Fiber Channel Rate Adaptation
                              <2gfc_ra>             2G Fiber Channel Rate Adaptation
                              <4gfc_ra>             4G Fiber Channel Rate Adaptation
                              <8gfc_ra>             8G Fiber Channel Rate Adaptation
                              <1gfc_enh>            1G Fiber Channel Cortina Enhanced Mapping 
                              <2gfc_enh>            2G Fiber Channel Cortina Enhanced Mapping
                              <4gfc_enh>            4G Fiber Channel Cortina Enhanced Mapping
                              <8gfc_enh>            8G Fiber Channel Cortina Enhanced Mapping
                              <2gisc>               2G Inter-System Channel
                              <2gfc>                2G Fiber Channel GMP LO
                              <4gfc>                4G Fiber Channel GMP LO
                              <8gfc>                8G Fiber Channel GMP LO
                              <10gfc>               10G Fibre Channel
                              <10gfc_tc>            10G Fibre Channel 512/513 transcoding
                              <10gfc_tc_g709>       10G Fibre Channel 512/513 transcoding (standard xcode remap)
                              <10gfc_tc_ra>         10G Fibre Channel 512/513 transcoding with Rate Adjust for fixed clocks
                              <otu3>                40G OTN
                              <otu3+>               OTU3+
                              <otu3e/otu3e1>        Overclocked OTU3 with 4xODU2e(10GE Client)
                                                    based on 16 frame multiframe (16 TS)
                              <otu3e2>              Overclocked OTU3 with 4xODU2e(10GE Client)
                                                    based on 32 frame multiframe (32 TS)
                              <otu3e4>              overclocked OTU3 based on 2/5 bandrate of
                                                    OTU4                    
                              <40gelan>             40G Ethernet LAN (for mapping into OTU3e)

                              <40gep>               40G Ethernet LAN Parallel 
                              <40gesbi>             40G Ethernet LAN Serial
                              <40ges6466>           40G Ethernet LAN 64/66
                              <40gex>               40G Ethernet LAN X
                              <40gep_ra>            40G Ethernet LAN Parallel 
                              <40gesbi_ra>          40G Ethernet LAN Serial
                              <40ges6466_ra>        40G Ethernet LAN 64/66
                              <40gex_ra>            40G Ethernet LAN X
                              
                              <oc768>               40G SONET
                              <oc768_otu3>          KPGA inside 40G SONET inside OTU3
                              <2_5g_iba>            2_5G INFINIBAND
                              <5g_iba>              5G INFINIBAND
                              <10g_iba>             10G INFINIBAND
                              <fdr10_iba>           FDR-10 (10.3125 Gbps) INFINIBAND
                              
    -client_port        int - Client port identifier    (default: 4)
                              Side A Port 1 = 0   Side B Port 1 = 4
                              Side A Port 2 = 1   Side B Port 2 = 5
                              Side A Port 3 = 2   Side B Port 3 = 6
                              Side A Port 4 = 3   Side B Port 4 = 7     
                              
    -client_fec         str - client FEC - Forward Error Correction  (default: gfec)
                              See explanation above for -line_fec
                              
    -term               str - OC192 termination                  (default: )
                              <trans>               Transparent
                              <transregen>          Transparent Regenerator
                              <rsregen>             RS Layer Regenrator
                              <msregen>             MS Layer Regenrator
                              
    -term_otu           str - OTU termination                  (default: )
                              <transparent>         Transparent
                              <section>             Section Layer
                              
    -sync               str - Synchronous Mapping  (10G/40G Transponder)
    
    -async              str - Asynchronous Mapping (40G Muxponder; 10G/40G Transponder)
    
    -map_oxuv           str - First level of mapping (mux) / Transponder Mapping
$oxuv_map_string

    -map_odtu           str - Second level of mapping (mux)
$odtu_map_string
                              
    -k_value            int - An arbitrary constant used by the controllable divider 
                             (syncdsync) ot generate a divided clock (RXDIV) with a 
                             frequency that is proportional to the incoming signal rate
                             <16|32|64> or              (default: 64)
    
    -gfp_frame_format   str -GFP frame format for 10GE 512/513b transcode mapping into OTU2
                             Datasheet Section 2.8.1.4.3  (default: 28blk_5sblk)
                              <28blk_5sblk>         28 blocks and 5 super blocks
                              <28blk_11sblk>        28 blocks and 11 super blocks
                              <32blk_4sblk>         32 blocks and 4 super blocks
                              <32blk_8sblk>         32 blocks and 8 super blocks
                              
    -line_tcm           int - Tandem connection index on line side
                              <1-6>
    
    -client_tcm         int - Tandem connection index on line side
                              <1-6>
                              
    -10ge_flow          str - Select the flow control method. Only applicable to 10ge6_1 10ge_ra
                              (default: reactive)
                              <preemptive>          Pause frames are transmitted periodically
                              <reactive>            Pause frames are triggered by the Elastic 
                                                    Store fill level  

    -xcon_client         int - Signal type at the cross connect
                               For 40G muxponder with 40G traffic on both sides to identify the
                               demapped signal going across crossconnect.
                               <odu1e|odu1f|odu2|odu2e>
                              
    -oduflex_enbl        int - Enable ODUFlex capability
                               <0|1>
                               
    -oduflex_line_port   int - ODUFlex Line Port
                               TBD

    -oduflex_client_port int - ODUFlex Client Port
                               TBD

    -timeslots           int - Number of timeslots
                               For -mode;mux GMP       : 1-8
                                             AMP/AMP_DT: 4  or 8                               
                               For 40G Transponder     : 16 or 32

    -ts_mask             int - Mask showing which of 8 timeslots are
                               used for an oduflex client
                               0x01..0xFF

    -hold_in_reset       int - Hold in reset to allow register override
                               <0|1>
                               
    -pre_line/           str - PP40G Pre Line/Client
    -pre_client                <40gep>
                               <40gesbi>
                               <40ges6466>
                               <40gex>
                               <40gep_ra>
                               <40gesbi_ra>
                               <40ges6466_ra>
                               <40gex_ra>
                               
    -line_hsif_loopback/ int - HSIF Loopback Type
    -client_hsif_loopback      NOTE:  Also use -notest for script to PASS
                               TEN_HSIF_LOOPBACK_NONE             = 0
                               TEN_HSIF_LOOPBACK_FACILITY         = 1 (MR40G)
                               TEN_HSIF_LOOPBACK_FACILITY_EXT     = 2
                               TEN_HSIF_LOOPBACK_FACILITY_MR10G   = 3 (MR10G)
                               TEN_HSIF_LOOPBACK_FAR_END          = 4
                               TEN_HSIF_LOOPBACK_MR_TX2RX         = 5
                               TEN_HSIF_LOOPBACK_MR_RX2TX         = 6
                               TEN_HSIF_LOOPBACK_XFI_TX2RX        = 7
                               TEN_HSIF_LOOPBACK_XFI_RX2TX        = 8
                               TEN_HSIF_LOOPBACK_MR_SERIAL        = 9 (TX2RX)
                               TEN_HSIF_LOOPBACK_FACILITY_XFI     = 10
                               TEN_HSIF_LOOPBACK_XFI_SERIAL_TX2RX = 11
                               TEN_HSIF_LOOPBACK_CFP_TX2RX        = 12
                               TEN_HSIF_LOOPBACK_CFP_RX2TX        = 13
                               TEN_HSIF_LOOPBACK_FACILITY_CFP     = 14
                               TEN_HSIF_LOOPBACK_CFP_SERIAL_TX2RX = 15
                               
    -bus_error_check     int - Perform bus error checks
                               <0|1>
                               0 = do not perform bus error check
                               1 = perform bus error check
                         
    -xfi_clock_distribution    int - XFI clock distribution 
                               <0|1>
                               0 = internal
                               1 = external
                               
    -cfp_mrb1_mrb3             int - CFP clock distribution 
                               <0|1>
                               0 = normal mode
                               1 = MRB1/MRB3 mode
                               
                               
    -ra_10ge_odu2e_mode        int - OTU2E rate for 10ge_ra muxponder
                               0=odu2 rate
                               1=odu2e rate
                               
#################
# KPGA options: #
#################
    - kpga_pattern      str - KPGA Pattern
                              <prbs11|prbs23|prbs31>
                              
    - hsif_kpga_pattern str - HSIF KPGA Pattern
                              <prbs7|prbs9|prbs15|prbs23|prbs31>

#################
# Test options: #
#################
    -notest                 - Do not perform end-of-script checks
                              <no arguments>

    -pbert_40g_test         - For 40GE clients, generate pbert_40g traffic with PP40G's,
                              and compare pbert TX counts with pp40g RX counts
                              <line|client|loop_fe>

    -chip               str - <t40|t41|default>
                              Overrides the chip type from software's perspective,
                              causing ten_dev_is_t41() to return the specified type. The 
                              override sticks until 
                                a) full.pl is called with no chip option or \"default\"
                                   option,
                                b) API ten_dev_override_chiptype(dev_id, TEN_CHIP_
                                   OVERRIDE_DEF) is called,
                                c) The driver is initialized.
                              To see the override state, dump the device control block. 
                              Chip types 0x80 for 0x81 look like a T40. Chip types 0xC0 
                              and 0xC1 look like a T41. 

EXAMPLE COMMAND LINES:
[1] LOOPBACK
  batch (full.pl, '-mode;lb;-sysclk;425;-hsif_line;sfi5_1;-line_port;0;-line;otu3;-line_fec;gfec;-term_otu;transparent')
[2] TRAFFIC
  batch (full.pl, '-mode;mux;-sysclk;425;-line_port;0;-line;otu3;-line_fec;gfec;-client_port;4;-client;otu2;-client_fec;gfec;-hsif_A;sfi5_1;-hsif_B;xfi')

\n";

sub validate_client {
    my $client = shift;
    if (($client eq 'none') or      # Don't change it (default for $dyn_repro == 1)
        ($client eq 'null') or      # Null traffic (default for $dyn_repro == 0)
        ($client eq 'cbr10g') or
        #($client eq 'cbr40g39813120000') or   # Constant Bit Rate for OC-768
        #($client eq 'cbr40g41250000000') or   # Constant Bit Rate for 40GE
        ($client eq 'cbr40g50188149150') or   # Custom Constant Bit Rate
        ($client eq 'oc192') or
        ($client eq 'oc192_async') or
        ($client eq 'oc192_otu2') or
        # ($client eq '10ge_pbert') or
        ($client eq 'otu1f') or
        ($client eq 'otu2') or
		($client eq 'cbr_1118099736') or
		($client eq 'cbr_1052329163') or
        ($client eq 'otu2e') or
        ($client eq 'otu1e') or
        ($client eq '10ge') or
        ($client eq '10ge6_1') or
        ($client eq '10ge6_2') or
        ($client eq '10ge7_1') or
        ($client eq '10ge7_2') or
        ($client eq '10ge7_3') or
        ($client eq '10ge_gfpf_oc192_odu2') or
        ($client eq '10ge_gfpf') or    # Bugzilla 29991
        ($client eq '10ge_ra') or
        ($client eq '10ge_tc') or
        ($client eq '10gfc') or
        ($client eq '10gfc_tc') or
        ($client eq '10gfc_tc_ra') or
        ($client eq '10gfc_tc_g709') or # Bug 31054
        ($client eq '8gfc') or
        ($client eq '4gfc') or
        ($client eq '2gfc') or
        ($client eq '1gfc') or
        ($client eq '2gisc') or
        ($client eq '8gfc_ra') or
        ($client eq '4gfc_ra') or
        ($client eq '2gfc_ra') or
        ($client eq '1gfc_ra') or
        ($client eq '8gfc_enh') or
        ($client eq '4gfc_enh') or
        ($client eq '2gfc_enh') or
        ($client eq '1gfc_enh') or
        ($client eq 'pbert_2gfc') or
        ($client eq 'pbert_4gfc') or
        ($client eq 'pbert_8gfc') or
        ($client eq 'pbert_10gfc') or
        ($client eq 'pbert_10ge') or
        ($client eq 'otu3') or
        ($client eq 'otu3e') or
        ($client eq 'otu3e2') or    # Bugzilla 29100
        ($client eq 'otu3e3') or
        ($client eq 'otu3e4') or    # Bugzilla 28237
        ($client eq 'otu3+') or
        ($client eq 'otu3p2') or
        ($client eq 'oc768') or
        ($client eq 'oc768_otu3') or
        ($client eq '40gelan') or
        ($client eq '40ge_tc') or
        
        ($client eq '40gep') or
        ($client eq '40gesbi') or
        ($client eq '40ges6466') or
        ($client eq '40gex') or
        ($client eq '40gep_ra') or
        ($client eq '40gesbi_ra') or
        ($client eq '40ges6466_ra') or
        ($client eq '40gex_ra') or
        
        ($client eq '2_5g_iba') or  
        ($client eq '5g_iba') or  
        ($client eq '10g_iba') or
        ($client eq '1ge') or     # Bugzilla 38871   
        ($client eq 'fdr10_iba')) { # Bugzilla 39242
        return;
    }
    else {
        die "ERROR: Invalid client '$client'";
        # 'exit' kills apish
#       exit;
    }
}

sub validate_line {
    my $line = shift;
    if (($line eq 'none') or      # Don't change it (default for $dyn_repro == 1)
        ($line eq 'null') or      # Null traffic (default for $dyn_repro == 0)
        #($line eq 'cbr10g') or
        ($line eq 'cbr40g50188149150') or   # Custom Constant Bit Rate
        ($line eq 'oc192') or
        ($line eq 'oc192_otu2') or
        ($line eq 'otu1f') or
        ($line eq 'otu2') or
		($line eq 'cbr_1118099736') or
		($line eq 'cbr_1052329163') or
        ($line eq 'otu2e') or
        ($line eq 'otu2e_div2') or # Bugzilla half_rate
        ($line eq 'otu2e_div4') or # Bugzilla half_rate
        ($line eq 'otu1e') or
        ($line eq '10ge') or
        #($line eq '10ge6_1') or
        #($line eq '10ge6_2') or
        #($line eq '10ge7_1') or
        #($line eq '10ge7_2') or
        #($line eq '10ge7_3') or
        #($line eq '10ge_gfpf_oc192_odu2') or
        ($line eq '10ge_ra') or # Bugzilla 37022
        ($line eq '10gfc') or
        #($line eq '10gfc_tc') or
        ($line eq '8gfc') or
        ($line eq '8gfc_enh') or
        ($line eq '8gfc_ra') or
        ($line eq '4gfc_ra') or
        ($line eq '2gfc_ra') or
        ($line eq '1gfc_ra') or
        ($line eq 'otu3') or
        ($line eq 'otu3+') or
        ($line eq 'otu3p2') or
        ($line eq 'otu3e') or
        ($line eq 'otu3e1') or
        ($line eq 'otu3e2') or
        ($line eq 'otu3e3') or
        ($line eq 'otu3e4') or    # Bugzilla 28237
        ($line eq 'oc768') or
        ($line eq 'oc768_otu3') or
        
        ($line eq '40gelan') or
        ($line eq '40ge_tc') or
        ($line eq '40gep') or
        ($line eq '40gesbi') or
        ($line eq '40ges6466') or
        ($line eq '40gex') or
        ($line eq '40gep_ra') or
        ($line eq '40gesbi_ra') or
        ($line eq '40ges6466_ra') or
        ($line eq '40gex_ra') or
        ($line eq '2_5g_iba') or  # Bugzilla 38565
        ($line eq '5g_iba') or  
        ($line eq '10g_iba') or
        ($line eq 'fdr10_iba')) { # Bugzilla 39242
        return;
    }
    else {
        die "ERROR: Invalid Line '$line'";
    }
}

# Bugzilla 31209 Start
## Returns the type of FEC applied to the port
## Returns one of: none, 10gfec, 10ufec, 40gfec, 40ufec
#sub get_fec {
#    my $port = shift;
#    my $fec = $fec[$port];
#    $fec =~ s/ deallocate//;
#    return $fec;
#}
#
## FEC checking
## NOTE: State information is kept for this
#sub validate_fec {
#    my %args = @_;
#
##     print "Validate_fec: Before (1)\n", Dumper \@fec;
#    # Clean-up pending deallocations
#    for my $i (0..7) {
#        $fec[$i] = 'none' if $fec[$i] =~ /deallocate/;
#    }
##     print "Validate_fec: Before (2)\n", Dumper \@fec;
##     print "Validate_fec: $args{line}, $args{line_fec}, $args{client}, $args{client_fec}\n";
#    if ($args{line} ne 'invalid') {
#        if ($args{line} =~ /otu/) {
#            my $f = sprintf("%d%s", $args{linerate}, $args{line_fec});
#            $f =~ s/ufec.*/ufec/;
#            if (($args{client} eq 'null') and ($args{dyn_repro} == main::TEN_REPRO_LINE_AND_CLIENT)) {
#                $fec[$args{line_port}] .= ' deallocate';
#            }
#            else {
#                $fec[$args{line_port}] = $f;
#            }
#        }
#        else {
#            $fec[$args{line_port}] = 'none';
#        }
#    }
#
#    if ($args{client} eq 'null') {
#        $fec[$args{client_port}] .= ' deallocate';
#    }
#    if ($args{client} =~ /otu/) {
#        my $f = sprintf("%d%s", $args{clientrate}, $args{client_fec});
#        $f =~ s/ufec.*/ufec/;
#        $fec[$args{client_port}] = $f;
#    }
##     else {
##         $fec[$args{client_port}] = 'none'
##     }
#
#    # This implements the "NO" cells from Table 1 of the CS6001 data sheet
#    if (($fec[0] eq '40ufec') and ($fec[4] eq '10ufec')) {
#        die "Side A 40G UFEC conflicts with Side B 10G UFEC on port 1 (4)";
#    }
#
#    foreach my $i (0..3) {
#        my $port_a = $i + 1;
#        my $port_b = $port_a + 4;
#        if (($fec[$i] eq '10ufec') and ($fec[$i + 4] eq '10ufec')) {
#            die "Side A 10G UFEC on port $port_a conflicts with Side B 10G UFEC on port $port_a ($port_b)";
#        }
#        if (($i > 0) and ($fec[$i] eq '10gfec') and ($fec[$i + 4] eq '10gfec')) {
#            die "Side A 10G GFEC on port $port_a conflicts with Side B 10G GFEC on port $port_a ($port_b)";
#        }
#    }
#
#    if (($fec[1] eq '10ufec') and ($fec[4] eq '40ufec')) {
#        die "Side A 10G UFEC on port 1 (0) conflicts with Side B 40G UFEC";
#    }
#    print "validate_fec:\n", Dumper \@fec;
#}
# Bugzilla 31209 End


##############################################################################
#
# Routine:      validate_line_client
#
# Validate the Line-Client pair.
#
# Parameter:
#
#    %args - pointer to args hash table
#
# Returns:
#
#    0: OK
#    1: ERROR
#
##############################################################################
sub validate_line_client {
    my %args = @_;

    if (($args{mode} eq 'mux') || ($args{mode} eq 'trans10') || ($args{mode} eq 'trans40')) {

        if ((($args{dyn_repro} == main::TEN_INITIAL_CONFIG) and (!defined $args{line_port})) or
            (($args{dyn_repro} == main::TEN_REPRO_LINE_AND_CLIENT) and (!defined $args{line_port}))) {
            print ("-line_port must be specified\n");
            return (1);
        }

        if ($args{client} eq '10ge6_2') {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3e') && ($args{line} ne 'otu3e2') && ($args{line} ne 'otu3+') &&  
                    ($args{line} ne 'otu3p2') && ($args{line} ne 'otu3') && ($args{line} ne 'otu3e4')) {  # Bugzilla 28237
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with OTU3e/OTU3e2/OTU3+/OTU3p2/OTU3/OTU3e4\n");
                    return (1);
                }
            } else {
                if ($args{line} ne 'otu2') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OTU2\n");
                    return (1);
                }
            }
        }
        if ($args{client} eq '10ge7_1') {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3e') && ($args{line} ne 'otu3e2') && ($args{line} ne 'otu3+') && ($args{line} ne 'otu3p2') && ($args{line} ne 'otu3e4') ) { # Bugzilla 28237
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with OTU3e/OTU3+/OTU3p2/OTU3e2/OTU3e4\n");
                    return (1);
                }
            } else {
                if ($args{line} ne 'otu2e') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OTU2e\n");
                    return (1);
                }
            }
        }
        if ($args{client} eq '10ge7_2') {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3e') && ($args{line} ne 'otu3+') && ($args{line} ne 'otu3p2')) {
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with OTU3e/OTU3+/OTU3p2\n");
                    return (1);
                }
            } else {
                if ($args{line} ne 'otu1e') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OTU1e\n");
                    return (1);
                }
            }
        }
        if ($args{client} eq '10ge7_3') {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3') && ($args{line} ne 'otu3e') && ($args{line} ne 'otu3e2') && ($args{line} ne 'otu3+') && 
                    ($args{line} ne 'otu3p2') && ($args{line} ne 'otu3e4')) { # Bugilla 28237
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with OTU3/OTU3e/OTU3e2/OTU3e4/OTU3+/OTU3p2\n");
                    return (1);
                }
            } else {
                if ($args{line} ne 'otu2') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OTUu2\n");
                    return (1);
                }
            }
        }
        if ($args{client} eq '10ge_gfpf_oc192_odu2') {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3') && ($args{line} ne 'otu3e') && ($args{line} ne 'otu3+') && 
                    ($args{line} ne 'otu3p2')  && ($args{line} ne 'otu3e4')) {
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with OTU3/OTU3e/OTU3+/OTU3p2/OTU3e4\n");
                    return (1);
                }
            } else {
                if ($args{line} ne 'otu2') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OTU2\n");
                    return (1);
                }
            }
        }
        # Bugzilla 29991 Start
        if ($args{client} eq '10ge_gfpf') {
            if ($args{line} ne 'oc192') {
                print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OC192\n");
                return (1);
            }
        }
        # Bugzilla 29991 End
        if ($args{client} eq '10ge_ra') {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3') && ($args{line} ne 'otu3e') && ($args{line} ne 'otu3e2') && ($args{line} ne 'otu3+') && 
                    ($args{line} ne 'otu3p2') && ($args{line} ne 'otu3e4')) { # Bugilla 28237
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with OTU3/OTU3e/OTU3e2/OTU3e4/OTU3+/OTU3p2\n");
                    return (1);
                }
            } else {
                if (($args{line} ne 'otu2') && ($args{line} ne 'otu2e') && ($args{line} ne '10ge_ra')) { # Bugzilla 37022
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OTU2\n");
                    return (1);
                }
            }
        }
        if ($args{client} eq 'oc192') {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3') && ($args{line} ne 'otu3e')  && ($args{line} ne 'otu3e2') && 
                    ($args{line} ne 'otu3+') && ($args{line} ne 'otu3p2') && ($args{line} ne 'otu3e4')) { # Bugzilla 28237
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with OTU3/OTU3e/OTU3+/OTU3p2\n");
                    return (1);
                }
            } else {
                if (($args{line} ne 'otu2') && ($args{line} ne 'otu2e') && ($args{line} ne 'otu1e') && ($args{line} ne 'oc192')) {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OTU2/OTU2E/OTU1E/OC192\n");
                    return (1);
                }
            }
        }
        if ($args{client} eq 'oc192_async') {
            if ($args{linerate} == 40) {
                if ($args{line} ne 'otu3') {
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with OTU3\n");
                    return (1);
                }
            } else {
                   print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OTU3 only\n");
                   return (1);
            }
        }
        if ($args{client} eq 'otu2') {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3') && ($args{line} ne 'otu3e') && ($args{line} ne 'otu3e2') && 
                    ($args{line} ne 'otu3+') && ($args{line} ne 'otu3p2') && ($args{line} ne 'otu3e4')) {   # Bugzilla 28237
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with OTU3/OTU3e/OTU3e2/OTU3e4/OTU3+/OTU3p2\n");
                    return (1);
                }
            } else {
                if ($args{line} ne 'otu2') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OTU2\n");
                    return (1);
                }
            }
        }
        if ($args{client} eq 'otu2e') {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3e') && ($args{line} ne 'otu3+') && ($args{line} ne 'otu3p2') && 
                    ($args{line} ne 'otu3e2') && ($args{line} ne 'otu3e4')) {     # Bugzilla 28237
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with OTU3e/OTU3+/OTU3p2/OTU3e4\n");
                    return (1);
                }
            } else {
                if ($args{line} ne 'otu2e') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with OTU2e\n");
                    return (1);
                }
            }
        }
        if ($args{client} eq 'otu1f') {
            if ($args{linerate} == 40) {
                #if (($args{line} ne 'otu3e') && ($args{line} ne 'otu3+') && ($args{line} ne 'otu3p2')) {
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is not supported\n");
                    return (1);
                #}
            } else {
                if ($args{line} ne 'otu1f') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with otu1f\n");
                    return (1);
                }
            }
        }
        if ($args{client} eq 'otu1e') {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3p2') && ($args{line} ne 'otu3e')) {
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with otu3p2\n");
                    return (1);
                }
            } else {
                if ($args{line} ne 'otu1e') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is not supported\n");
                    return (1);
                }
            }
        }
        if ($args{client} eq '10gfc_tc_ra') {
            if ($args{line} ne 'otu2e') {
                print ("$args{client} and $args{line} is not supported.  $args{client} is supported with otu2e\n");
                return (1);
            }
        }
        if (($args{client} eq '10gfc_tc') || ($args{client} eq '10gfc_tc_g709')) { # Bug 31054
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3e') && ($args{line} ne 'otu3e2') && ($args{line} ne 'otu3p2') && ($args{line} ne 'otu3e4') &&   # Bugzilla 28237
                    ($args{line} ne 'otu3+')) { #Bugzilla 39003
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with otu3e/otu3e2/otu3e4/otu3p2\n");
                    return (1);
                }
            } else {
                if ($args{line} ne 'otu2e') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with otu2e\n");
                    return (1);
                }
            }
        }
        if ($args{client} =~ /gfc_enh/) {
            if ($args{linerate} == 40) {
                if (($args{line} ne 'otu3p2') && ($args{line} ne 'otu3') && ($args{line} ne 'otu3+') && ($args{line} ne 'otu3e')) {
                    print ("$args{client} and $args{line} is not supported.  $args{client}_odtu23 is supported with otu3/otu3e/otu3p2/otu3+\n");
                    return (1);
                }
            } else {
                 if (($args{line} ne 'otu2') && ($args{line} ne 'otu2e')
                    ){
                     print ("$args{client} and $args{line} is not supported.  $args{client} is supported with otu2/otu2e\n");
                     return (1);
                 }
            }
        }
        if ($args{client} eq '10ge_tc') {
            if ($args{linerate} == 40) {
                print ("$args{client} and $args{line} is not supported. Supported only with otu2e line\n");
            } else {
                if ($args{line} ne 'otu2e') {
                    print ("$args{client} and $args{line} is not supported.  $args{client} is supported with otu2e\n");
                    return (1);
                }
            }
        }
        if (($args{line} eq 'oc192_otu2') || ($args{client} eq 'oc192_otu2')) {
            print ("oc192_otu2 is not supported in $args{mode} mode.\n");
            return (1);
        }     
    }
    elsif (($args{mode} =~ /lb/) || ($args{mode} =~ /kpga/)) {
        if (($args{line} eq 'invalid') && ($args{client} eq 'invalid')) {
            print ("Both line and client have not been specified.  One must be specified\n");
            return (1);
        }
        elsif (($args{line} ne 'invalid') && ($args{client} ne 'invalid')) {
            print ("Both line and client have been specified.  Only one may be specified\n");
            return (1);
        }
    }
    elsif ($args{mode} eq 'wire10') {
        if (($args{client} =~ /otu2/) || ($args{client} =~ /otu1/) || ($args{client} =~ /oc192/)) {
            if ($args{client} ne $args{line}) {
                print ("$args{client} != $args{line}! They must be the same in wire mode\n");
                return (1);
            }
        }
    }
    elsif ($args{mode} eq 'wire40') {
        if (($args{client} =~ /otu3/) || ($args{client} =~ /oc768/)) {
            if ($args{client} ne $args{line}) {
                print ("$args{client} != $args{line}! They must be the same in wire mode\n");
                return (1);
            }
        }
    }


    return (0);
}



##############################################################################
#
# Routine:      validate_hsif_traffic_type
#
# Validate the hsif-traffic type pairing.
#
# Parameter:
#
#    %args - pointer to args hash table
#
# Returns:
#
#    0: OK
#    1: ERROR
#
##############################################################################
sub validate_hsif_traffic_type {
    my %args = @_;

    if ($args{line} ne 'invalid') {
        if ($args{linerate} == 40) {
            if (($args{hsif_line} eq 'xfi') || ($args{hsif_line} eq  'cfp_mr')){
                $args{mld_line_enabled} = 1;
                if (($args{hsif_line} eq 'xfi') and ($args{line_port} < 4)){
                    print "Side A does not support xfi\n";
                    return (1, $args{mld_line_enabled}, $args{mld_client_enabled});
                }
            }
            elsif (($args{hsif_line} eq 'sfi5_1') || ($args{hsif_line} eq 'sfi4_2')) {
                $args{mld_line_enabled} = 0;
            }
            #elsif (($args{hsif_line} ne 'sfi5_1') and ($args{hsif_line} ne 'sfi4_2')) {
            else {
                print "hsif_line = $args{hsif_line}.  40G Line HSIF required to be 'sfi5_1', 'sfi4_2', 'xfi' or 'cfp_mr'.\n";
                return (1, $args{mld_line_enabled}, $args{mld_client_enabled});
            }
        } else {
            if (($args{hsif_line} eq 'xfi') and ($args{line_port} < 4)){
                print "Side A does not support xfi\n";
                return (1, $args{mld_line_enabled}, $args{mld_client_enabled});
            }
            elsif ($args{hsif_line} eq 'xaui') {
                if (($args{line} ne '10ge') and
                    ($args{line} ne '10ge6_1') and
                    ($args{line} ne '10ge6_2') and
                    ($args{line} ne '10ge7_1') and
                    ($args{line} ne '10ge7_2') and
                    ($args{line} ne '10ge7_3') and
                    ($args{line} ne '10ge_gfpf_oc192_odu2') and
                    ($args{line} ne '10ge_gfpf') and         # Bugzilla 29991
                    ($args{line} ne '10ge_ra')) {
                    print "line = $args{line}.  xaui only supports 10ge rates\n";
                    return (1, $args{mld_line_enabled}, $args{mld_client_enabled});
                }
            }
            elsif (($args{hsif_line} ne 'sfi4_2') and ($args{hsif_line} ne 'sfi4_1') and 
                   ($args{hsif_line} ne 'xfi') and ($args{hsif_line} ne 'cfp_mr')) {
                print "hsif_line = $args{hsif_line}.  10G Line HSIF required to be 'sfi4_2', 'sfi4_1', 'xfi', or 'cfp_mr'.\n";
                return (1, $args{mld_line_enabled}, $args{mld_client_enabled});
            }
        }
    }

    if (($args{client} ne 'invalid') and ($args{client} ne 'null')) {
        if ($args{clientrate} == 40) {
            if (($args{hsif_client} eq 'xfi') || ($args{hsif_client} eq 'cfp_mr')){
                $args{mld_client_enabled} = 1;
                if (($args{hsif_client} eq 'xfi') and ($args{client_port} < 4)){
                    print "Side A does not support xfi\n";
                    return (1, $args{mld_line_enabled}, $args{mld_client_enabled});
                }
            }
            elsif (($args{hsif_client} eq 'sfi5_1') || ($args{hsif_client} eq 'sfi4_2')) {
                $args{mld_client_enabled} = 0;
            }
            #elsif (($args{hsif_client} ne 'sfi5_1') and ($args{hsif_client} ne 'sfi4_2')) {
            else {
                print "hsif_client = $args{hsif_client}.  40G Client HSIF required to be 'sfi5_1', 'sfi4_2', 'xfi' or 'cfp_mr'\n";
                return (1, $args{mld_line_enabled}, $args{mld_client_enabled});
            }
        } else {
            if (($args{hsif_client} eq 'xfi') and ($args{client_port} < 4)){
                print "Side A does not support xfi\n";
                return (1, $args{mld_line_enabled}, $args{mld_client_enabled});
            }
            elsif ($args{hsif_client} eq 'xaui') {
                if (($args{client} ne '10ge') and
                    ($args{client} ne '10ge6_1') and
                    ($args{client} ne '10ge6_2') and
                    ($args{client} ne '10ge7_1') and
                    ($args{client} ne '10ge7_2') and
                    ($args{client} ne '10ge7_3') and
                    ($args{client} ne '10ge_gfpf_oc192_odu2') and
                    ($args{client} ne '10ge_gfpf') and    # Bugzilla 29991
                    ($args{client} ne '10ge_ra')) {
                    print "client = $args{client}.  xaui only supports 10ge rates\n";
                    return (1, $args{mld_line_enabled}, $args{mld_client_enabled});
                }
            }
            elsif (($args{hsif_client} ne 'sfi4_2') and ($args{hsif_client} ne 'sfi4_1') and 
                   ($args{hsif_client} ne 'xfi')  and ($args{hsif_client} ne 'cfp_mr')) {
                print "hsif_client = $args{hsif_client}.  10G Client HSIF required to be 'sfi4_2', 'sfi4_1', 'xfi' or 'cfp_mr'.\n";
                return (1, $args{mld_line_enabled}, $args{mld_client_enabled});
            }
        }
    }

    return (0, $args{mld_line_enabled}, $args{mld_client_enabled});
}

# Command-line argument processing
sub check_args {
    my $no_check = shift;
    $no_check = 0 unless defined $no_check;
    my $invalid = 0;
    $t100_support = 0;     # Bugzilla 32386
    # Default command line options
    my %args;
    if ($no_check == 0) {
        %args = (
            sysclk                    => 400,
            dyn_repro                 => main::TEN_INITIAL_CONFIG,                      # 0 for initial config; 1 to repro client; 2 to repro line/client
            mode                      => '',
            hsif_A                    => 'disabled',
            hsif_B                    => 'disabled',
            hsif_line                 => 'disabled',
            hsif_line_enum            => main::TEN_HSIF_PROTOCOL_DISABLED,
            line                      => 'invalid',
            line_traffic_type_enum    => main::TEN_TRAFFIC_TYPE_OTU3E,
            line_port                 => 0,
            line_fec                  => 'deallocate',
            line_fec_enum             => main::TEN_FEC_MODE_DEALLOCATE,
            hsif_client               => 'disabled',
            hsif_client_enum          => main::TEN_HSIF_PROTOCOL_DISABLED,
            client                    => 'invalid',
            client_traffic_type_enum  => main::TEN_TRAFFIC_TYPE_NONE,
            client_port               => 4,
            client_fec                => 'deallocate',
            client_fec_enum           => main::TEN_FEC_MODE_DEALLOCATE,
            term                      => 'transregen',
            oc_term_enum              => main::TEN_OC192_TERM_TRANSPARENT_REGENERATOR,
            mode_enum                 => main::TEN_40G_MUXPONDER,
            sync                      => 3,                                             # async
            map_oxuv_enum             => main::TEN_MAP_DONT_CARE,                       # 'uninitialized'
            map_odtu_enum             => main::TEN_MAP_DONT_CARE,                       # 'uninitialized'
            auxclk                    => 0,                                             # XFI aux tx ref clk = 1
            notest                    => 0,
            eds                       => 1,                                             # Enhanced deskew for SFI-4.2
            term_otu                  => 'section',                                     # OTU overhead termination (transparent of section termination)
            term_otu_enum             =>  main::TEN_OTU_TERM_SECTION,
            line_tcm                  => [0, 0, 0, 0, 0, 0, 0],                         # TCM termination
            client_tcm                => [0, 0, 0, 0, 0, 0, 0],
            line_tcm_bits             => 0,                                             # TCM termination
            client_tcm_bits           => 0,                                             # TCM termination
            k_value                   => 64,
            ten_ge_flow               => 'reactive',
            ten_ge_flow_enum          => main::TEN_PP10G_FLOW_ETH_4,
            gfp_frame_format          => '28blk_5sblk',
            gfp_frame_format_enum     => main::TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4,
            help                      => 0,
            kpga_pattern              => 'prbs23',
            kpga_pattern_enum         => main::TEN_KPG_PN23,
            hsif_kpga_pattern         => 'prbs31',
            hsif_kpga_pattern_enum    => main::TEN_HSIF_PRBS_PN31,
            reset_t40                 => 0,
            mld_line_enabled          => 0,                                             # Multilane Deskew
            mld_client_enabled        => 0,                                             # Multilane Deskew
            xcon_client_enum          => main::TEN_TRAFFIC_TYPE_NONE,    # Bugzilla 28176
            xcon_client_type          => 'invalid',                      # Bugzilla 28176
            oduflex_enbl              => 0,
            oduflex_line_port         => 0,
            oduflex_client_port       => 0,
            timeslots                 => 0xFF,  # 8 time slots for AMP 1.25G time slots
            ts_mask                   => 0xFF,  # 8 time slots for AMP 1.25G time slots
            exists_async              => 0,
            exists_sync               => 0,
            exists_map_oxuv           => 0,
            exists_map_odtu           => 0,
            hold_in_reset             => 0,
            pbert_40g_test            => 0,
            pre_line                  => 'none',
            pre_client                => 'none',
            pre_line_rx_enum          => main::TEN_PP40G_RX_DISABLE, # Bugzilla 28006
            pre_line_tx_enum          => main::TEN_PP40G_RX_DISABLE, # Bugzilla 28006
            pre_client_rx_enum        => main::TEN_PP40G_RX_DISABLE, # Bugzilla 28006
            pre_client_tx_enum        => main::TEN_PP40G_RX_DISABLE, # Bugzilla 28006
            chip                      => 'default',
            client_hsif_loopback      => 0,
            line_hsif_loopback        => 0,
            bus_error_check           => 1,
            xfi_clock_distribution    => 1,
            line_cupll_profile        => 'none',
            line_cupll                => 0,
            client_cupll_profile      => 'none',
            client_cupll              => 0,
            read                      => 'none',
            deskew_ctrl               => main::TEN_SADECO_DESKEW, # Deskew at XCON  # Bugzilla 28006
            monitor                   => 1,
            recenter_type             => 'default',               # Bugzilla 27270, Amplitude Recentering
            dev_id                    => 0,               # Bugzilla 30856
            t100                      => 0,
            cfp_mrb1_mrb3             => 0,
            ra_10ge_odu2e_mode        => 0
        );
    }
    
    $drtu_needs_map  = 0;
    $drtu_needs_dtj  = 0;

    while (my $arg = shift @ARGV) {
        if ($arg eq '-help' || $arg eq '-h') {
            print "$Usage\n\n";
            $args{help} = 1;
            return %args;
        }
        elsif ($arg eq '-sysclk') {
            $args{sysclk} = shift @ARGV;
            $args{sysclk} = eval($args{sysclk});
            ### TODO: check to make sure it is higher than the data rate
            unless (exists $sysclocks{$args{sysclk}}) {
                my $errstr = sysclocksStr('error');
                die "Invalid -sysclk $args{sysclk}\n  Use $errstr.\n";
            }
        }
        elsif ($arg eq '-dr') {
            # See if the base configuration has been run before by checking the FEC state info
            #if ($fec[0] eq 'invalid') {
            if ($initial_configuration == 0) {    # Bugzilla 31209
                die "A run without the -dr or -drl parameter must be executed before a dynamic reprovisioning run";
            }
            $args{dyn_repro} = main::TEN_REPRO_CLIENT;
        }
        elsif ($arg eq '-drl') {
            # See if the base configuration has been run before by checking the FEC state info
            #if ($fec[0] eq 'invalid') {
            if ($initial_configuration == 0) {    # Bugzilla 31209
                die "A run without the -dr or -drl parameter must be executed before a dynamic reprovisioning run";
            }
            $args{dyn_repro} = main::TEN_REPRO_LINE_AND_CLIENT;
        }
        elsif ($arg eq '-mode') {
            $args{mode} = shift @ARGV;
            if (($args{mode} ne 'mux') and
                ($args{mode} ne 'trans') and
                ($args{mode} ne 'hsif_kpga') and
                ($args{mode} ne 'cbr_kpga') and
                ($args{mode} ne 'kpga') and
                ($args{mode} ne 'wire') and
                ($args{mode} ne 'lb')) {
                #($args{mode} ne 'pbert')) {
                die "Invalid -mode $args{mode}. <mux|trans|lb|kpga|hsif_kpga|cbr_kpga|wire>\n";
            }
        }
        elsif ($arg eq '-hsif_A') {
            $args{hsif_A} = shift @ARGV;
            if ($args{hsif_A} ne 'sfi4_2' && $args{hsif_A} ne 'sfi5_1' &&
                $args{hsif_A} ne 'xaui' && $args{hsif_A} ne 'sfi4_1' && $args{hsif_A} ne 'cfp_mr') {
                die "Invalid -hsif_A $args{hsif_A}.  <sfi4_2|sfi5_1|xaui|sfi4_1|cfp_mr>\n";
            }
        }
        elsif ($arg eq '-hsif_B') {
            $args{hsif_B} = shift @ARGV;
            if ($args{hsif_B} ne 'xfi' and $args{hsif_B} ne 'sfi4_2' and
                $args{hsif_B} ne 'sfi5_1' and $args{hsif_B} ne 'xaui' and
                $args{hsif_A} ne 'sfi4_1' && $args{hsif_A} ne 'cfp_mr') {
                die "Invalid -hsif_B $args{hsif_B}.  <xfi|sfi4_2|sfi5_1|xaui|sfi4_1|cfp_mr>\n";
            }
        }
        elsif ($arg eq '-hsif_line') {
            $args{hsif_line} = shift @ARGV;
            unless (exists $hsif_enum{$args{hsif_line}}) {
                die "Invalid -hsif_line $args{hsif_line}.  <sfi5_1>|sfi4_2|sfi4_1|xfi|xaui|cfp_mr>\n";
            }
            $args{hsif_line_enum} = $hsif_enum{$args{hsif_line}};
        }
        elsif ($arg eq '-hsif_client') {
            $args{hsif_client} = shift @ARGV;
            unless (exists $hsif_enum{$args{hsif_client}}) {
                die "Invalid -hsif_client $args{hsif_client}.  <sfi5_1>|sfi4_2|sfi4_1|xfi|xaui|cfp_mr>\n";
            }
            $args{hsif_client_enum} = $hsif_enum{$args{hsif_client}};
        }
        elsif ($arg eq '-line') {
            $args{line} = shift @ARGV;
            validate_line($args{line});
			if(($args{line} ne 'cbr_1118099736') && ($args{line} ne 'cbr_1052329163')){
				$args{line_traffic_type_enum} = $traffic_type_enum{$args{line}};
			}
			else {
			    $args{line_traffic_type_enum} = main::TEN_TRAFFIC_TYPE_OTU2;
			}
        }
        elsif ($arg eq '-line_port') {
            $args{line_port} = shift @ARGV;
            $args{line_port} = eval($args{line_port});
            if (($args{line_port} < 0) or ($args{line_port} > 7)) {
                die "-line_port must be 0 to 7\n";
            }
        }
        elsif ($arg eq '-line_fec') {
            $args{line_fec} = shift @ARGV;
            unless (exists $fec_type_enum{$args{line_fec}}) {
                die "Invalid -line_fec $args{line_fec}.  <ufec7p|ufec7p_sdha|ufec10p|ufec12p|ufec13p|ufec15p|ufec20p|ufec25p|ufec26p|ufec_7p_263|ufec_18p|ufec_25p_295|gfec|0fec|nofec>\n";
            }
            $args{line_fec_enum} = $fec_type_enum{$args{line_fec}};
        }
        elsif ($arg eq '-client') {
            $args{client} = shift @ARGV;
            validate_client($args{client});
      if((exists $args{client}) && ($args{client} ne 'cbr_1118099736') && (exists $args{line}) && ($args{line} ne 'cbr_1052329163')){
                $args{client_traffic_type_enum} = $traffic_type_enum{$args{client}};
			}
			else {
			    $args{client_traffic_type_enum} = main::TEN_TRAFFIC_TYPE_OTU2;
			}

            $drtu_needs_dtj = ($args{client_traffic_type_enum} == main::TEN_TRAFFIC_TYPE_10GE_6_1 or
                               $args{client_traffic_type_enum} == main::TEN_TRAFFIC_TYPE_10GE_6_2 or
                               $args{client_traffic_type_enum} == main::TEN_TRAFFIC_TYPE_10GE_7_3 or
                               $args{client_traffic_type_enum} == main::TEN_TRAFFIC_TYPE_8GFC );
        }
        elsif ($arg eq '-client_port') {
            $args{client_port} = shift @ARGV;
            $args{client_port} = eval($args{client_port});
            if ((! defined $args{client_port}) or ($args{client_port} < 0) or ($args{client_port} > 7)) {
                die "-client_port must be 0 to 7\n";
            }
        }
        elsif ($arg eq '-client_fec') {
            $args{client_fec} = shift @ARGV;
            unless (exists $fec_type_enum{$args{client_fec}}) {
                die "Invalid -client_fec $args{client_fec}.  <ufec7p|ufec10p|ufec12p|ufec13p|ufec15p|ufec20p|ufec25p|ufec26p|ufec7p_263|ufec18p|ufec25p_295|gfec|nofec|0fec>\n";
            }
            $args{client_fec_enum} = $fec_type_enum{$args{client_fec}};
        }
        elsif ($arg eq '-term') {
            $args{term} = shift @ARGV;
            unless (exists $oc_term_enum{$args{term}}) {
                die "Invalid -term $args{term}.  <trans|transregen|rsregen|msregen>\n";
            }
            $args{oc_term_enum} = $oc_term_enum{$args{term}};
        }
        elsif ($arg eq '-sync') {
            $args{sync} = 1;
            $args{exists_sync} = 1;
        }
        elsif ($arg eq '-async') {
            $args{sync} = 0;
            $args{exists_async} = 1;
        }
        elsif ($arg eq '-auxclk') {
            $args{auxclk} = 1;
        }
        elsif ($arg eq '-notest') {
            $args{notest} = 1;
        }
        elsif ($arg eq '-id') {
            $args{id} = shift @ARGV;
        }
        elsif ($arg eq '-eds') {
            $args{eds} = shift @ARGV;
        }
        elsif ($arg eq '-term_otu') {
            $args{term_otu} = shift @ARGV;
            #if ($args{term_otu} ne 'transparent' && $args{term_otu} ne 'section' && $args{term_otu} ne 'full') {
            unless (exists $otu_term_enum{$args{term_otu}}) {
                die "Invalid -term_otu $args{term_otu}.  <transparent|section|full>\n";
            }
            $args{term_otu_enum} =  $otu_term_enum{$args{term_otu}};
        }
        elsif ($arg eq '-line_tcm') {
            my $tcm = shift @ARGV;
            $tcm = eval($tcm);
            if (($tcm < 1) || ($tcm > 6)) {
                die "Invalid -line_tcm $tcm.  <1-6>\n";
            } else {
                #$args{line_tcm[$tcm]} = 1;
                $args{line_tcm}->[$tcm] = 1;
                $args{line_tcm_bits} |= (1 << $tcm);
            }
        }
        elsif ($arg eq '-client_tcm') {
            my $tcm = shift @ARGV;
            $tcm = eval($tcm);
            if (($tcm < 1) || ($tcm > 6)) {
                die "Invalid -client_tcm $tcm.  <1-6>\n";
            } else {
                #$args{client_tcm[$tcm]} = 1;
                $args{client_tcm}->[$tcm] = 1;
                $args{client_tcm_bits} |= (1 << $tcm);
            }
        }
        elsif ($arg eq '-k_value') {
            $args{k_value} = shift @ARGV;
            if ($args{k_value} != 16 && $args{k_value} != 32 && $args{k_value} != 64) {
                die "Invalid -k_value $args{k_value}.  <16|32|64\n";
            }
        }
        elsif ($arg eq '-10ge_flow') {
            $args{ten_ge_flow} = shift @ARGV;
            unless (exists $ten_ge_flow_enum{$args{ten_ge_flow}}) {
                die "Invalid -10ge flow control $args{ten_ge_flow}.  <preemptive|reactive>\n";
            }
            $args{ten_ge_flow_enum} = $ten_ge_flow_enum{$args{ten_ge_flow}};
        }
        elsif ($arg eq '-gfp_frame_format') {
            $args{gfp_frame_format} = shift @ARGV;
            unless (exists $gfp_frame_format_enum{$args{gfp_frame_format}}) {
                die "Invalid -gfp frame format $args{gfp_frame_format}.  <28blk_5sblk|28blk_11sblk|32blk_4sblk|32blk_8sblk>\n";
            }
            $args{gfp_frame_format_enum} = $gfp_frame_format_enum{$args{gfp_frame_format}};
        }
        elsif ($arg eq '-kpga_pattern') {
            $args{kpga_pattern} = shift @ARGV;
            unless (exists $ten_kpg_enum{$args{kpga_pattern}}) {
                die "Invalid -kpga_pattern flow control $args{kpga_pattern}.  <fixed,prbs11,prbs23,prbs31>\n";
            }
            $args{kpga_pattern_enum} = $ten_kpg_enum{$args{kpga_pattern}};
        }
        elsif ($arg eq '-hsif_kpga_pattern') {
            $args{hsif_kpga_pattern} = shift @ARGV;
            unless (exists $ten_hsif_kpga_pattern_enum{$args{hsif_kpga_pattern}}) {
                die "Invalid -hsif_kpga_pattern flow control $args{hsif_kpga_pattern}.  <prbs31,prbs23,prbs15,prbs7,prbs9>\n";
            }
            $args{hsif_kpga_pattern_enum} = $ten_hsif_kpga_pattern_enum{$args{hsif_kpga_pattern}};
        }
        elsif ($arg eq '-reset') {
            $args{reset_t40} = 1;
        }
        elsif ($arg eq '-map_oxuv') {
            my $map_oxuv = shift @ARGV;
            unless (exists $ten_map_enum{$map_oxuv}) {
                die "Invalid -map_oxuv $map_oxuv\n";
            }
            $args{map_oxuv_enum} = $ten_map_enum{$map_oxuv};
            $args{exists_map_oxuv} = 1;
        }
        elsif ($arg eq '-map_odtu') {
            my $map_odtu = shift @ARGV;
            unless (exists $ten_map_enum{$map_odtu}) {
                die "Invalid -map_odtu $map_odtu\n";
            }
            $args{map_odtu_enum} = $ten_map_enum{$map_odtu};
            $args{exists_map_odtu} = 1;
        }
        elsif ($arg eq '-oduflex_line_port') {
            $args{oduflex_line_port} = shift @ARGV;
            if (($args{oduflex_line_port} < 0) or ($args{oduflex_line_port} > 7)) {
                die "-oduflex_line_port must be 0 to 7\n";
            }
        }
        elsif ($arg eq '-oduflex_client_port') {
            $args{oduflex_client_port} = shift @ARGV;
            if (($args{oduflex_client_port} < 0) or ($args{oduflex_client_port} > 7)) {
                die "-oduflex_client_port must be 0 to 7\n";
            }
        }
        elsif ($arg eq '-oduflex_enbl') {
            $args{oduflex_enbl} = shift @ARGV;
            if (($args{oduflex_enbl} < 0) or ($args{oduflex_enbl} > 1)) {
                die "-oduflex enable must be 0 or 1\n";
            }
        }
        elsif ($arg eq '-xcon_client_type') {
            my $xcon_client_type = shift @ARGV;
            $args{xcon_client_type} = $xcon_client_type;
            unless (exists $ten_xcon_client_enum{$xcon_client_type}) {
                die "Invalid -xcon_client_type $xcon_client_type\n";
            }
            $args{xcon_client_enum} = $ten_xcon_client_enum{$xcon_client_type};
        }
        elsif ($arg eq '-timeslots') {
            $args{timeslots} = shift @ARGV;
            if (($args{timeslots} != 16) and ($args{timeslots} != 32) and (($args{timeslots} < 1) or ($args{timeslots} > 8))) {
                die "-timeslots must be 1 to 8, 16 or 32\n";
            }
        }
        elsif ($arg eq '-ts_mask') {
            $args{ts_mask} = shift @ARGV;
            $args{ts_mask} = eval($args{ts_mask});  # Convert to a number
            if (($args{ts_mask} > 0xFF) or ($args{ts_mask} < 0x01)) {
                die "-ts_mask must be 0x01..0xFF\n";
            }
        }
        elsif ($arg eq '-hold_in_reset') {
            $args{hold_in_reset} = shift @ARGV;
            if (($args{hold_in_reset} < 0) or ($args{hold_in_reset} > 1)) {
                die "-hold_in_reset must be 0 or 1\n";
            }
        }
        elsif ($arg eq '-pbert_40g_test') {
            $args{pbert_40g_test} = shift @ARGV;
            if (($args{pbert_40g_test} ne 'line') and
                ($args{pbert_40g_test} ne 'client') and
                ($args{pbert_40g_test} ne 'loop_fe') ) {
                die "Invalid -pbert_40g_test $args{pbert_40g_test}. <line|client|loop_fe>\n";
            }        }
        # Bugzilla 28006 Start
        elsif ($arg eq '-pre_line') {
            $args{pre_line} = shift @ARGV;
            unless (exists $ten_40ge_rx_pre_enum{$args{pre_line}}) {
                die "Invalid -pre_line $args{pre_line} invalid selection.\n";
            }
            $args{pre_line_rx_enum} = $ten_40ge_rx_pre_enum{$args{pre_line}};
            $args{pre_line_tx_enum} = $ten_40ge_tx_pre_enum{$args{pre_line}};
        }
        elsif ($arg eq '-pre_client') {
            $args{pre_client} = shift @ARGV;
            unless (exists $ten_40ge_rx_pre_enum{$args{pre_client}}) {
                die "Invalid -pre_client $args{pre_client} invalid selection.\n";
            }
            $args{pre_client_rx_enum} = $ten_40ge_rx_pre_enum{$args{pre_client}};
            $args{pre_client_tx_enum} = $ten_40ge_tx_pre_enum{$args{pre_client}};
        }
        # Bugzilla 28006 End
        elsif ($arg eq '-chip') {
            # See if the base configuration has been run before by checking the FEC state info
            $args{chip} = shift @ARGV;
            if (($args{chip} ne 't40') and
                ($args{chip} ne 't41') and
                ($args{chip} ne 'default') ) {
                die "Invalid -chip $args{chip}. <t40|t41|default>\n";
            }
        }
        elsif ($arg eq '-client_hsif_loopback') {
          $args{client_hsif_loopback} = shift @ARGV;
          if ($args{client_hsif_loopback} >= main::TEN_HSIF_LOOPBACK_MAX) {
              die "Invalid -client_hsif_loopback $args{client_hsif_loopback}.\n";
          }
        }
        elsif ($arg eq '-line_hsif_loopback') {
          $args{line_hsif_loopback} = shift @ARGV;
          if ($args{line_hsif_loopback} >= main::TEN_HSIF_LOOPBACK_MAX) {
              die "Invalid -line_hsif_loopback $args{line_hsif_loopback}.\n";
          }
        }
        elsif ($arg eq '-bus_error_check') {
            $args{bus_error_check} = shift @ARGV;
            if (($args{bus_error_check} < 0) or ($args{bus_error_check} > 1)) {
                die "-bus_error_check must be 0 or 1\n";
            }
        }
        elsif ($arg eq '-xfi_clock_distribution') {
            $args{xfi_clock_distribution} = shift @ARGV;
            if (($args{xfi_clock_distribution} < 0) or ($args{xfi_clock_distribution} > 1)) {
                die "-xfi_clock_distribution must be 0 or 1\n";
            }
        }
        elsif ($arg eq '-line_cupll_profile') {
            $args{line_cupll_profile} = shift @ARGV;
            if (  ( ($args{line_cupll_profile} ne 'none') and
                   !($args{line_cupll_profile} =~ /^\w{3,}$/) and
                   !($args{line_cupll_profile} =~ /^[0-9]{1,3}$/) )
               or ($args{line_cupll_profile} =~ /^[0-9]{4,}$/)     ) {
                die "Invalid -line_cupll_profile $args{line_cupll_profile}. < \"none\" | [profile name] | 0-999 >\n";
            }
        }
        elsif ($arg eq '-line_cupll') {
            $args{line_cupll} = shift @ARGV;
            if (($args{line_cupll} < 4) or
                ($args{line_cupll} > 7) ) {
                die "Invalid -line_cupll $args{line_cupll}. <0|1|2|3>\n";
            }
        }
        elsif ($arg eq '-client_cupll_profile') {
            $args{client_cupll_profile} = shift @ARGV;
            if (  ( ($args{client_cupll_profile} ne 'none') and
                   !($args{client_cupll_profile} =~ /^\w{3,}$/) and
                   !($args{client_cupll_profile} =~ /^[0-9]{1,3}$/) )
               or ($args{client_cupll_profile} =~ /^[0-9]{4,}$/)     ) {
                die "Invalid -client_cupll_profile $args{client_cupll_profile}. < \"none\" | [profile name] | 0-999 >\n";
            }
        }
        elsif ($arg eq '-client_cupll') {
            $args{client_cupll} = shift @ARGV;
            if (($args{client_cupll} < 4) or
                ($args{client_cupll} >7) ) {
                die "Invalid -client_cupll $args{client_cupll}. <0|1|2|3>\n";
            }
        }
        elsif ($arg eq '-read') {
            my $_path   = shift @ARGV;
            $_path      =~ s/^custom\///;
            $_path      = "custom\/" . $_path;
            $args{read} = $_path;
            unless (-e $_path ) {
                die "Invalid -read argument, could't find file ${_path}\n";
            }
        }
        # Bugzilla 28977 Start
        elsif ($arg eq '-deskew') {
            my $deskew = shift @ARGV;
            unless (exists $deskew_type_enum{$deskew}) {
                die "Invalid -deskew $deskew.  <pp40g|bypass|sadeco>\n";
            }
            $args{deskew_ctrl} = $deskew_type_enum{$deskew};
        }
        # Bugzilla 28977 End
        elsif ($arg eq '-monitor') {
            $args{monitor} = shift @ARGV;
            if (($args{monitor} < 0) or ($args{monitor} > 2)) {
                die "-monitor must be 0, 1 or 2\n";
            }
        }
        elsif ($arg eq '-recenter') {       # Bugzilla 27270 Amplitude Recentering
            my $recenter = shift @ARGV;
            die "-recenter argument missing values. See help.\n" unless $recenter;
            $args{recenter_type} = $recenter;
        }
        # Bugzilla 30856 Start
        elsif ($arg eq '-dev_id') {
            $args{dev_id} = shift @ARGV;
            $args{dev_id} = eval($args{dev_id});
            if (($args{dev_id} < 0) or ($args{dev_id} > 2)) {
                die "-dev_id must be 0 to 2\n";
            }
        }
        # Bugzilla 30856 End
        elsif ($arg eq '-t100') {
            $args{t100} = 1;
            $t100_support = 1;
        }  
        elsif ($arg eq '-cfp_mrb1_mrb3') {
            $args{cfp_mrb1_mrb3} = shift @ARGV;
            if (($args{cfp_mrb1_mrb3} < 0) or ($args{cfp_mrb1_mrb3} > 1)) {
                die "-cfp_mrb1_mrb3 must be 0 or 1\n";
            }
        }
        elsif ($arg eq '-ra_10ge_odu2e_mode') {
            $args{ra_10ge_odu2e_mode} = shift @ARGV;
             if (($args{ra_10ge_odu2e_mode} < 0) or ($args{ra_10ge_odu2e_mode} > 1)) {
                die "-ra_10ge_odu2e_mode must be 0 or 1\n";
             }
        }
        else {
            print "Invalid flag: '$arg'\n";
            $invalid = 1;
        }
    }
    # end while args

    if ($invalid == 1) {
        return 0;
    }

    return %args if $no_check;
    return %args if $args{reset_t40};


    # Clear the state information that is saved for the FEC configuration
    if ($args{dyn_repro} == main::TEN_INITIAL_CONFIG) {
        #@fec = qw( none none none none none none none none);
        $initial_configuration = 1;     # Indicate that initial configuration has been done  # Bugzilla 31209
    }

    if (not defined ( $linerate{$args{line}} ) or ( $linerate{$args{line}} != 10 and $linerate{$args{line}} != 40 ) ) {
      die "Line rate could not be found for line type $args{line}\n";
    }
    else {
        $args{linerate} = $linerate{$args{line}};
    }
    if (not defined ( $linerate{$args{client}} ) or ( $linerate{$args{client}} != 10 and $linerate{$args{client}} != 40 ) ) {
      die "Line rate could not be found for client type $args{client}\n";
    }
    else {
        $args{clientrate} = $linerate{$args{client}};
    }

    if (($args{line} eq 'invalid') && ($args{client} eq 'invalid')) {
        die "line = $args{line}, client = $args{client}.  Must have a valid Line or Client";
    }


    # Figure out the complete mode specification
    if ($args{mode} eq '') {
        die "-mode must be 'mux' for muxponder, 'trans' for transponder or 'lb' for xcon looback";
    }
    elsif ($args{mode} eq 'trans') {
        $args{mode} = $args{linerate} == 40 ? 'trans40' : 'trans10';
        $args{mode_enum} = $mode_enum{$args{mode}};
        #if ($args{sync} == 2) {
        #    # sync mode was not specified, so set to default
        #     if (($args{client} eq '10ge6_2') || ($args{client} eq '10ge7_3)) {
        #        $args{sync} == 0;
        #     } else {
        #        $args{sync} == 1;
        #    }
        #}
    }
    elsif ($args{mode} eq 'wire') {
        $args{mode} = $args{linerate} == 40 ? 'wire40' : 'wire10';
        $args{mode_enum} = $mode_enum{$args{mode}};
    }
    elsif ($args{mode} eq 'mux') {
        $args{mode_enum} = $mode_enum{$args{mode}};
        #if ($args{sync} == 2) {
        #    # sync mode was not specified, so set to default
        #    $args{sync} == 0;
        #}
    }
    elsif ($args{mode} eq 'lb') {
        if ($args{line} ne 'invalid') {
            # line must be the one being looped back
            $args{mode} = $args{linerate} == 40 ? 'lb40' : 'lb10';
            $args{mode_enum} = $mode_enum{$args{mode}};
        } else {
            # Asume Client is valid
            $args{mode} = $args{clientrate} == 40 ? 'lb40' : 'lb10';
            $args{mode_enum} = $mode_enum{$args{mode}};
        }
    }
    elsif ($args{mode} eq 'kpga') {
        if ($args{line} ne 'invalid') {
            # line must be the one being provisioned for KPGA
            $args{mode} = $args{linerate} == 40 ? 'kpga40' : 'kpga10';
            $args{mode_enum} = $mode_enum{$args{mode}};
        } else {
            # Asume Client is valid
            $args{mode} = $args{clientrate} == 40 ? 'kpga40' : 'kpga10';
            $args{mode_enum} = $mode_enum{$args{mode}};
        }
    }
    elsif ($args{mode} eq 'cbr_kpga') {
        if ($args{line} ne 'invalid') {
            # line must be the one being provisioned for KPGA
            $args{mode} = $args{linerate} == 40 ? 'cbr_kpga40' : 'cbr_kpga10';
            $args{mode_enum} = $mode_enum{$args{mode}};
        } else {
            # Asume Client is valid
            $args{mode} = $args{clientrate} == 40 ? 'cbr_kpga40' : 'cbr_kpga10';
            $args{mode_enum} = $mode_enum{$args{mode}};
        }
    }
    elsif ($args{mode} eq 'hsif_kpga') {
        if ($args{line} ne 'invalid') {
            # line must be the one being provisioned for KPGA
            $args{mode} = $args{linerate} == 40 ? 'hsif_kpga40' : 'hsif_kpga10';
            $args{mode_enum} = $mode_enum{$args{mode}};
        } else {
            # Asume Client is valid
            $args{mode} = $args{clientrate} == 40 ? 'hsif_kpga40' : 'hsif_kpga10';
            $args{mode_enum} = $mode_enum{$args{mode}};
        }
    }
    elsif ($args{mode} eq 'pbert') {
        # T40 only supports 10G PBERT
        #$args{mode} = $args{linerate} == 40 ? 'pbert40' : 'pbert10';
        $args{mode} = 'pbert10';
        $args{mode_enum} = $mode_enum{$args{mode}};
    }
    else {
        die "-mode $args{mode} isn't supported yet\n";
    }
    
    if ($args{recenter_type} ne 'default') {
        my $recenter = $args{recenter_type};
        $args{recenter_type} = 'default';
        
        my $recenter_type;
        my $recenter_mrgns;
        ($recenter_type, $recenter_mrgns) = recenter_parse_args($recenter);
        
        die "In \'-recenter;${recenter}\', \'$recenter\' is invalid.\n" unless $recenter_type;
    
        if ($recenter_mrgns) {
            if ($recenter_mrgns =~ /\<\<\<bad$/) {
                $recenter_mrgns =~ s/\<\<\<bad$//;
                die "In \'-recenter;${recenter}\', \'$recenter_mrgns\' is invalid.\n";
            }
            $args{recenter_type}  = $recenter_type;
            $args{recenter_mrgns} = $recenter_mrgns;
        }
    }


#     # Fix-up depending on whether dynamic reprovisioning is enabled or not
#     # 'invalid' means the user didn't specify a disposition for the port
#     # When dynamically reprovisioning traffic, change it to 'none' to leave the port as-is,
#     # or when setting up the initial traffic change it to 'null' to make it 'null' traffic
#     for (my $port=1; $port<=4; $port++) {
#         if ($args{client}[$port] eq 'invalid') {
#             $args{client}[$port] = $args{dyn_repro} ? 'none' : 'null';
#         }
#     }
    # The line port must be specified if synamic reprovisioning isn't active

    return %args;
}

####################################################################################
# tenabo_get_skew
####################################################################################
# Parameters:
#
#        protocol -  sfi5 (1) sfi42_10g (4) and sfi42_40g (5) supported
#        ch       -  based on protocol.  0-7 for 10g, 0-1 for 40g

# Returns:
#
#       max lane to lane skew
#
sub tenabo_get_skew {
  my ($protocol, $ch, $eds) = @_;

  if (!defined($eds)) {$eds=1;} # extended deskew by default if not specified

  my $module_id  = ($protocol == 5 || $protocol == 1) ? $ch : ($ch >= 4);
  my $first_ch   = ($protocol == 5 || $protocol == 1) ? 0 : $ch%4;
  my $last_ch    = ($protocol == 5 || $protocol == 1) ? 3 : $ch%4;

  ################################################################################
  if ($protocol == 5 || $protocol == 4) { # sfi42

    my @sfi42_syncloc0;
    my @sfi42_syncloc1;
    my @sfi42_syncloc2;
    my @sfi42_syncloc3;

    for (my $slc=$first_ch; $slc <= $last_ch; $slc++) {
      $sfi42_syncloc0[$slc] = tenabo_bf_read(0,main::TEN_HSIF_SFI42_SYNCLOC0_0+$slc*main::TEN_HSIF_SFI42_SYNCLOC0_0_STRIDE+$module_id*main::TEN_HSIF_STRIDE,15,0);
      $sfi42_syncloc1[$slc] = tenabo_bf_read(0,main::TEN_HSIF_SFI42_SYNCLOC0_1+$slc*main::TEN_HSIF_SFI42_SYNCLOC0_1_STRIDE+$module_id*main::TEN_HSIF_STRIDE,15,0);
      $sfi42_syncloc2[$slc] = tenabo_bf_read(0,main::TEN_HSIF_SFI42_SYNCLOC0_2+$slc*main::TEN_HSIF_SFI42_SYNCLOC0_2_STRIDE+$module_id*main::TEN_HSIF_STRIDE,15,0);
      $sfi42_syncloc3[$slc] = tenabo_bf_read(0,main::TEN_HSIF_SFI42_SYNCLOC0_3+$slc*main::TEN_HSIF_SFI42_SYNCLOC0_3_STRIDE+$module_id*main::TEN_HSIF_STRIDE,15,0);
    }

    my $loc_mask = 0xF;
    my $seg_mask = 0x70;
    my $eds_mask = 0x700;
    my @pos;
    my @relpos;
    my @offset;
    my @reloffset;
    my @relskew;
    my @syncloc;
    my $min_skew = 0;
    my $max_skew = 0;
    my $ref_lane = ($protocol == 5) ? 3 : ($first_ch*4)+3;

    for (my $slc=$first_ch; $slc <= $last_ch; $slc++) {
      $syncloc[0+4*$slc] = $sfi42_syncloc0[$slc];
      $syncloc[1+4*$slc] = $sfi42_syncloc1[$slc];
      $syncloc[2+4*$slc] = $sfi42_syncloc2[$slc];
      $syncloc[3+4*$slc] = $sfi42_syncloc3[$slc];
    }

    $pos[$ref_lane]    = ($syncloc[$ref_lane] & $loc_mask) + (($syncloc[$ref_lane] & $seg_mask) >> 4)*11;
    $offset[$ref_lane] = (($syncloc[$ref_lane] & $eds_mask) >> 8);

    for (my $ln=$last_ch*4+3; $ln >= $first_ch*4; $ln--) {
      $pos[$ln]       = ($syncloc[$ln] & $loc_mask) + (($syncloc[$ln] & $seg_mask) >> 4)*11;
      $relpos[$ln]    = ($pos[$ln] <= $pos[$ref_lane]) ? $pos[$ref_lane]-$pos[$ln] : 66-($pos[$ln]-$pos[$ref_lane]);
      if ($eds == 1) {
        $offset[$ln]    = (($syncloc[$ln] & $eds_mask) >> 8);
        $reloffset[$ln] = $offset[$ref_lane] - $offset[$ln];
        $relskew[$ln]   = 66*$reloffset[$ln]+$relpos[$ln];
      } else {
        if ($ln == $ref_lane) {$relskew[$ln] = 0;}
        else {
          $relskew[$ln]  = $relpos[$ln]-32;
        }
      }

      printf("tenabo_get_skew: lane $ln  relpos = %d  relskew = %d\n",$relpos[$ln],$relskew[$ln]);

      if ($relskew[$ln] > $max_skew) {$max_skew = $relskew[$ln];}
      if ($relskew[$ln] < $min_skew) {$min_skew = $relskew[$ln];}
    }

    my $wc_skew = $max_skew - $min_skew;
    return $wc_skew;
  }
  ################################################################################
  elsif ($protocol == 1) { # SFI5

    # SFI5 Pre-reads
    my @sfi5_offset ;

    for (my $lane=0; $lane < 16; $lane++) {
      ####    $sfi5_offset[$lane] = tenabo_bf_read(0,main::TEN_HSIF_SFI5_RX_DESKEW_OFFSET0+$lane*main::TEN_HSIF_SFI5_RX_DESKEW_OFFSET0_STRIDE+$module_id*main::TEN_HSIF_STRIDE,9,0);
      $sfi5_offset[$lane] = main::ten_hsif_sfi5_get_rx_deskew_offset0($module_id, $lane);
    }

    my @sfi5_skew ;
    my @sfi5_dir ;
    my @sfi5_skewbyte ;
    my @sfi5_skewbit ;
    my $max_skew = -99;
    my $min_skew = 99;

    for (my $lane=0; $lane < 16; $lane++) {
      $sfi5_dir[$lane] = (($sfi5_offset[$lane] & 0x0300)==0x0200) ? "pos" : (($sfi5_offset[$lane] & 0x0300)==0x0100) ? "neg" : (($sfi5_offset[$lane] & 0x0300)==0x0000) ? "none" : "?";
      $sfi5_skewbyte[$lane] = ($sfi5_offset[$lane] & 0x00f0)>>4;
      $sfi5_skewbit[$lane] = ($sfi5_offset[$lane] & 0x0007);
      $sfi5_skew[$lane] = ($sfi5_dir[$lane] eq "pos")  ? ($sfi5_skewbyte[$lane]*-8 + $sfi5_skewbit[$lane])*-1 :
              ($sfi5_dir[$lane] eq "neg")  ? ($sfi5_skewbyte[$lane]*8  + $sfi5_skewbit[$lane])*-1 :
              ($sfi5_dir[$lane] eq "none") ? ($sfi5_skewbyte[$lane]*8  + $sfi5_skewbit[$lane]) :
                65 ;
      if ($sfi5_skew[$lane] > $max_skew) {$max_skew = $sfi5_skew[$lane];}
      if ($sfi5_skew[$lane] < $min_skew) {$min_skew = $sfi5_skew[$lane];}

    }

    return $max_skew - $min_skew;
  }
  ################################################################################
  else {
    return 0;
  }

}

sub check_hsif_skew {
    my ($protocol, $ch, $eds) = @_;
    printf "check_hsif_skew: Worst-case observed skew = %d\n", tenabo_get_skew($protocol, $ch, $eds);
}


##############################################################################
#
# Routine:      validate_sync_vs_async
#
# Examine Sync Vs Async mode
#
# Parameter:
#
#    %args - pointer to args hash table
#
# Returns:
#   $ret_value, $sync, $map_oxuv, $map_odtu
#
##############################################################################
sub validate_sync_vs_async {
    my (%args) = @_;

    print ("\n");
    print ("validate_sync_vs_async()  args{mode} = $args{mode}\n");
    print ("                          args{sync} = $args{sync}\n");
    print ("                          args{client} = $args{client}\n");
    print ("                          args{map_oxuv_enum} = $args{map_oxuv_enum}\n");
    print ("                          args{map_odtu_enum} = $args{map_odtu_enum}\n");

    if(($args{exists_map_oxuv} == 1) || ($args{exists_map_odtu} == 1)) {
        # print("Checklist for T41 will be updated in a later release after valid combinations are tested\n");

        # Fix sync/BMP for 10ge7_1 and 10ge7_2
        if (($args{client} eq '10ge7_2') or ($args{client} eq '10ge7_1')) {
            #if (($args{sync} != 1) and ($args{map_oxuv_enum} != main::TEN_MAP_BMP)) {
            #    print ("\nWARNING! Must be -sync or -map_oxuv;TEN_MAP_BMP with -client $args{client}.  Auto-correcting.");
            #}
            if (($args{map_oxuv_enum} == main::TEN_MAP_AMP) or ($args{map_oxuv_enum} == main::TEN_MAP_AMP_PROP)) {
                $args{sync} = 0;
                $args{map_oxuv_enum} = main::TEN_MAP_AMP_PROP;
            }
            else {
                $args{sync} = 1;
                $args{map_oxuv_enum} = main::TEN_MAP_BMP;
            }
        }
        
        if ($args{mode} eq 'mux') {
            # Must be async
            $args{sync} = 0;
            # Bugzilla 29905 Start
            if ( (($args{client} eq '10ge7_2') or ($args{client} eq '10ge7_1')) && ($args{line} =~ /otu3/)) {
                 if ($args{map_oxuv_enum} == main::TEN_MAP_DONT_CARE) {
                     $args{map_oxuv_enum} = main::TEN_MAP_BMP;
                 }
                 if ($args{map_odtu_enum} == main::TEN_MAP_DONT_CARE) {
                     $args{map_odtu_enum} = main::TEN_MAP_AMP;
                 }
            }
            # Bugzilla 29905 End
        }
        elsif (($args{mode} eq 'trans10') || ($args{mode} eq 'trans40')) {
            # Bugzilla 27167 Start
            if ($args{map_odtu_enum} == main::TEN_MAP_DONT_CARE) {
                # map_odtu is not specified, so can only use map_oxuv
                if ($args{map_oxuv_enum} == main::TEN_MAP_BMP) {
                    # Assume both sides are BMP/sync
                    $args{sync} = 1;
                    $args{map_odtu_enum} = main::TEN_MAP_BMP;   # Bugzilla 28977
                } else {
                    $args{sync} = 0;
                    #$args{map_odtu_enum} = main::TEN_MAP_AMP;   # Bugzilla 28977
                }
            } else {
                if (($args{map_oxuv_enum} == main::TEN_MAP_BMP) && ($args{map_odtu_enum} == main::TEN_MAP_BMP)) {
                    # Assume both sides are sync
                    $args{sync} = 1;
                } else { 
                    $args{sync} = 0;
                }
            }
            # Bugzilla 27167 End
        }
        elsif ($args{mode} =~ /lb/) {
            if ($args{map_oxuv_enum} == main::TEN_MAP_BMP) {
                $args{sync} = 1;
            } else {
                print ("\nMust be Sync/BMP in lb mode.");
                return (1, 0, 1, 0);
            }
        }
        elsif ($args{mode} =~ /wire/) {
            if ($args{map_oxuv_enum} == main::TEN_MAP_BMP) {
                $args{sync} = 1;
            } else {
                print ("\nMust be Sync/BMP in wire mode.");
                return (1, 0, 1, 0);
            }
        }
        elsif ($args{mode} =~ /kpga/) {
            if ($args{map_oxuv_enum} == main::TEN_MAP_BMP) {
                print ("\nMust be Aync in kpga mode.");
                return (1, 0, 1, 0);
            } else {
                $args{sync} = 0;
            }
        }
        # Bugzilla 28237 Start
        #if ($args{client} eq '10ge7_3') {
        #    if (($args{map_odtu_enum} == main::TEN_MAP_AMP_PROP_DT) || ($args{map_odtu_enum} == main::TEN_MAP_GMP_HO_DT) || 
        #        ($args{map_odtu_enum} == main::TEN_MAP_AMP_DT)) {
        #        return (0, $args{sync}, $args{map_oxuv_enum}, $args{map_odtu_enum});
        #    }
        #    
        #
        #    print ("Must be deterministic with -client $args{client}\n");
        #    return (1, 0, 1, 0);
        #}
        # Bugzilla 28237 End

        return (0, $args{sync}, $args{map_oxuv_enum}, $args{map_odtu_enum});
    }
    
    if(($args{exists_sync} == 0) && ($args{exists_async} == 0)) {   
      $args{sync} = 3;
    }
    
    if ($args{sync} == 3) {
        # Sync vs Async was not specified, so pick best default
        if ($args{mode} =~ /lb/) {
            $args{sync} = 1;
            $args{map_oxuv_enum} = main::TEN_MAP_BMP;
        }
        elsif ($args{mode} =~ /kpga/) {
            $args{sync} = 0;
            $args{map_oxuv_enum} = main::TEN_MAP_AMP;
        }
        elsif ($args{mode} =~ /wire/) {
            $args{sync} = 1;
            $args{map_oxuv_enum} = main::TEN_MAP_BMP;
        }
        elsif ($args{client} =~ /pbert_10ge/) {
            $args{sync} = 0;
            $args{map_oxuv_enum} = main::TEN_MAP_AMP;
        }
        elsif (($args{client} eq '10ge') && ($args{line} eq '10ge')) {
          if (($args{hsif_client} eq 'xaui') || ($args{hsif_line} eq 'xaui') || ($args{hsif_A} eq 'xaui') || ($args{hsif_B} eq 'xaui')) {
            $args{sync} = 0;
            $args{map_oxuv_enum} = main::TEN_MAP_AMP;
          }
          else {
            $args{sync} = 1;
            $args{map_oxuv_enum} = main::TEN_MAP_BMP;
          }
        }
        elsif ($args{client} =~ /10ge/) {
            if (($args{line} eq 'otu2e') || ($args{line} eq 'otu1e')) {
                $args{sync} = 1;
                $args{map_oxuv_enum} = main::TEN_MAP_BMP;
            }
            # Bugzilla 29905 Start
            elsif (($args{client} eq '10ge7_2') && ($args{line} =~ /otu3/)) {
                $args{sync} = 0;
                $args{map_oxuv_enum} = main::TEN_MAP_BMP;  # 10ge to odu1e
                $args{map_odtu_enum} = main::TEN_MAP_AMP;  # odu1e to odtu23
            # Bugzilla 29905 End
            } else {
                $args{sync} = 0;
                $args{map_oxuv_enum} = main::TEN_MAP_AMP;
            }
        }
        elsif ($args{line} eq $args{client}) {
            $args{sync} = 1;
            $args{map_oxuv_enum} = main::TEN_MAP_BMP;
        }
        elsif (($args{line} eq 'otu3e') and ($args{client} eq '40gelan')) {
            $args{sync} = 0;
            $args{map_oxuv_enum} = main::TEN_MAP_AMP;
        }
        elsif (($args{line} eq 'otu3') and ($args{client} eq '40ge_tc')) {
            $args{sync} = 0;
            $args{map_oxuv_enum} = main::TEN_MAP_AMP_PROP;
        }
        elsif (($args{line} eq 'otu3') and ($args{client} eq 'oc768')) {
            $args{sync} = 1;
            $args{map_oxuv_enum} = main::TEN_MAP_BMP;
        }
        elsif (($args{line} eq 'otu3p') and ($args{client} eq 'oc768')) {
            $args{sync} = 0;
            $args{map_oxuv_enum} = main::TEN_MAP_AMP_PROP;
        }
        elsif ($args{line} eq 'otu3e3') {
            $args{sync} = 0;
            $args{map_oxuv_enum} = main::TEN_MAP_AMP;
        }
        elsif ($args{mode} eq 'mux') {
            # Force Async mode
            $args{sync} = 0;
            $args{map_oxuv_enum} = main::TEN_MAP_BMP;
            $args{map_odtu_enum} = main::TEN_MAP_AMP;
        }
        else {
            # Default to async mode
            $args{sync} = 0;
            $args{map_oxuv_enum} = main::TEN_MAP_AMP;
        }
    }
    else {
        # Sync vs Async was specified, so make sure it is valid
        if (($args{line} eq 'otu3e3') and ($args{sync} != 0)) {
            $args{map_oxuv_enum} = main::TEN_MAP_AMP;
            print ("Must be Async with -line $args{line}\n");
            return (1, 0, 1, 0);
        }
        if (($args{line} eq 'otu3e') and ($args{client} eq '40gelan')  and ($args{sync} != 0)) {
            $args{map_oxuv_enum} = main::TEN_MAP_AMP;
            print ("Must be Async with -line OTU3e and -client 40GELAN\n");
            return (1, 0, 1, 0);
        }
        if (($args{line} eq 'otu3') and ($args{client} eq '40ge_tc')  and ($args{sync} != 0)) {
            $args{map_oxuv_enum} = main::TEN_MAP_AMP;
            print ("Must be Async with -line OTU3 and -client 40GE_TC\n");
            return (1, 0, 1, 0);
        }
        if (($args{line} eq 'otu3') and ($args{client} eq 'otu3') and ($args{sync} == 0)) {
            print ("Must be Sync with -line OTU3 and -client OTU3\n");
            return (1, 0, 1, 0);
        }
    
        # Fix 10GE traffic
        if (($args{client} eq '10ge') && ($args{line} eq '10ge')) {
            if (($args{hsif_client} eq 'xaui') || ($args{hsif_line} eq 'xaui')) {
                $args{map_oxuv_enum} = main::TEN_MAP_AMP;
                if ($args{sync} != 0) {
                    print ("\nMust be -async with -line 10ge and -client 10ge with either hsif being XAUI.");
                    return (1, 0, 1, 0);
                }
            }
            else {
                if ($args{sync} != 1) {
                    $args{map_oxuv_enum} = main::TEN_MAP_AMP;
                    print ("\nAllow async with -line 10ge and -client 10ge.");
                }
                else {
                    return (0, 1, 1, 0);
                }
            }
        }
        elsif (($args{client} =~ /10ge/) && ($args{client} ne '10ge_tc')) {
            if (($args{line} eq 'otu2e') || ($args{line} eq 'otu1e')) {

                $args{map_oxuv_enum} = main::TEN_MAP_BMP;
                if (($args{client} =~ /10ge_ra/) && ($args{line} eq 'otu2e')) {
                   $args{map_oxuv_enum} = main::TEN_MAP_AMP;
                   print ("\n10ge_ra into otu2e, AMP");
                }
                elsif ($args{sync} != 1) {
                    print ("\nWARNING! Must be -sync with -line $args{line} and -client $args{client}.  Auto-correcting.");
                    $args{sync} = 1;
                }
            } else {
                if ($args{sync} != 0) {
                    $args{sync} = 0;
                    print ("\nWARNING! Must be -async with -line $args{line} and -client $args{client}.  Auto-correcting.");
                }
                $args{map_oxuv_enum} = main::TEN_MAP_AMP;
            }
        }
        elsif ($args{client} eq '10ge_tc') {
            if ($args{sync} == 0) {
               $args{map_oxuv_enum} = main::TEN_MAP_AMP;
            }
            elsif ($args{map_oxuv_enum} == main::TEN_MAP_AMP) {
                $args{sync} = 0;
            } else {
                print ("\nMust be async with -line $args{line} and -client $args{client}.");
                return (1, 0, 1, 0);
            }
        }
        elsif (($args{client} eq '40gep') || ($args{client} eq '40gesbi')) {
            if ($args{sync} == 0) {
               $args{map_oxuv_enum} = main::TEN_MAP_GMP_LO;
            }
            elsif ($args{map_oxuv_enum} == main::TEN_MAP_GMP_LO) {
                $args{sync} = 0;
            } else {
                print ("\nMust be async with -line $args{line} and -client $args{client}.");
                return (1, 0, 1, 0);
            }
        }
        else {
            #  Map cases that do not have restrictions
            if ($args{sync} == 0) {
               $args{map_oxuv_enum} = main::TEN_MAP_AMP;
            }
            elsif ($args{sync} == 1) {
                $args{map_oxuv_enum} = main::TEN_MAP_BMP;
                $args{map_odtu_enum} = main::TEN_MAP_BMP;
            }
            elsif ($args{map_oxuv_enum} == main::TEN_MAP_AMP) {
                $args{sync} = 0;
            } else {
                $args{sync} = 1; 
            }
        }
        
        if ($args{mode} eq 'mux') {
            if ($args{sync} != 0) {
                print ("\nMust be Async for -mode $args{mode}.");
                return (1, 0);
            }
            $args{map_oxuv_enum} = main::TEN_MAP_BMP;
            $args{map_odtu_enum} = main::TEN_MAP_AMP;
        }
        
    }

    #print ("validate_sync_vs_async()  args{sync} = $args{sync}\n");
    return (0, $args{sync}, $args{map_oxuv_enum}, $args{map_odtu_enum} );
}




##############################################################################
#
# Routine:      validate_timeslots
#
# Examine number of time slots Vs mapping mode
#
# Parameter:
#
#    %args - pointer to args hash table
#
# Returns:
#   $ret_value, $timeslots
#
##############################################################################
sub validate_timeslots {
    my (%args) = @_;

    print ("validate_timeslots()  args{timeslots} = $args{timeslots}\n");
    printf("                      args{ts_mask}   = %x\n", $args{ts_mask});
    print ("                      args{map_oxuv_enum} = $args{map_oxuv_enum}\n");
    print ("                      args{map_odtu_enum} = $args{map_odtu_enum}\n");

    # $timeslots gets overwritten by a $temp_ts_mask ones count if oduflex
    my $temp_ts_mask = $args{ts_mask};
    if ($args{oduflex_enbl} == 1) {
      $args{timeslots} = 0;
      for (my $i=0; $i<8 ;$i++) {
        if ($temp_ts_mask & 0x01) {
          $args{timeslots}++
        }
        $temp_ts_mask = $temp_ts_mask>>1;
      }
    }

    if ($args{timeslots} == 0xFF) {
        # Number of time slots not specified
        if (($args{map_oxuv_enum} == main::TEN_MAP_GMP_LO) ||    
            ($args{map_oxuv_enum} == main::TEN_MAP_GMP_HO) ||
            ($args{map_oxuv_enum} == main::TEN_MAP_GMP_HO_DT) ||
            ($args{map_odtu_enum} == main::TEN_MAP_GMP_LO) ||    
            ($args{map_odtu_enum} == main::TEN_MAP_GMP_HO) ||
            ($args{map_odtu_enum} == main::TEN_MAP_GMP_HO_DT)) {
            # GMP always has 1.25G timeslots    
            if ($args{mode} eq 'trans40') {
                $args{timeslots} = 32;
            } else {
                $args{timeslots} = 8;
            }    
        } else {
            # Assume 2.5G timeslots
            if ($args{mode} eq 'trans40') {
                $args{timeslots} = 16;
            } else {
                $args{timeslots} = 4;
            }
        }
        return (0, $args{timeslots} );
    } else {
        # Number of time slots was specifed
        if (($args{map_oxuv_enum} == main::TEN_MAP_GMP_LO) ||    
            ($args{map_oxuv_enum} == main::TEN_MAP_GMP_HO) ||
            ($args{map_oxuv_enum} == main::TEN_MAP_GMP_HO_DT) ||
            ($args{map_odtu_enum} == main::TEN_MAP_GMP_LO) ||    
            ($args{map_odtu_enum} == main::TEN_MAP_GMP_HO) ||
            ($args{map_odtu_enum} == main::TEN_MAP_GMP_HO_DT)) {
            # GMP always has 1.25G timeslots and can not have more than 8 timeslots
            if ($args{mode} eq 'trans40') {
                if ($args{timeslots} != 32) {
                    print ("validate_timeslots()  -mode=trans40, timeslots=$args{timeslots}, map_oxuv_enum=$args{map_oxuv_enum} and map_odtu_enum=$args{map_odtu_enum} is invalid\n");
                    return (1, $args{timeslots} );
                }
            } else {
                if (($args{timeslots} > 8) || ($args{timeslots} < 1)) {
                    print ("validate_timeslots()  timeslots=$args{timeslots}, map_oxuv_enum=$args{map_oxuv_enum} and map_odtu_enum=$args{map_odtu_enum} is invalid\n");
                    return (1, $args{timeslots} );
                }
            }
        } 
        elsif (($args{map_oxuv_enum} == main::TEN_MAP_AMP) ||    
               ($args{map_oxuv_enum} == main::TEN_MAP_AMP_DT) ||
               ($args{map_odtu_enum} == main::TEN_MAP_AMP) ||
               ($args{map_odtu_enum} == main::TEN_MAP_AMP_DT)) {
            # AMP can have 1.25G or 2.5G timeslots
            if ($args{mode} eq 'trans40') {
                if (($args{timeslots} != 32) && ($args{timeslots} != 16)) {
                    print ("validate_timeslots()  -mode=trans40, timeslots=$args{timeslots}, map_oxuv_enum=$args{map_oxuv_enum} and map_odtu_enum=$args{map_odtu_enum} is invalid\n");
                    return (1, $args{timeslots} );
                }
            } else {
                if (($args{timeslots} != 8) && ($args{timeslots} != 4)) {
                    print ("validate_timeslots()  timeslots=$args{timeslots}, map_oxuv_enum=$args{map_oxuv_enum} and map_odtu_enum=$args{map_odtu_enum} is invalid\n");
                    return (1, $args{timeslots} );
                }
            }
        }
        else {
            # Must be 2.5G timeslots
            if ($args{mode} eq 'trans40') {
                if ($args{timeslots} != 16) {
                    # All other mapping procedures have 2.5G time slots
                    print ("validate_timeslots()  timeslots=$args{timeslots}, map_oxuv_enum=$args{map_oxuv_enum} and map_odtu_enum=$args{map_odtu_enum} is invalid\n");
                    return (1, $args{timeslots} );
                }
            } else {
                if ($args{timeslots} != 4) {
                    # All other mapping procedures have 2.5G time slots
                    print ("validate_timeslots()  timeslots=$args{timeslots}, map_oxuv_enum=$args{map_oxuv_enum} and map_odtu_enum=$args{map_odtu_enum} is invalid\n");
                    return (1, $args{timeslots} );
                }
            }
        }    
    }

    return (0, $args{timeslots} );
}

####################################################################################
# validate_cleanup_pll_args
####################################################################################
# Parameters:
#       none 
# Returns:
#       0 if failed, nz otherwise
#
# Rules:
#   Range checks have been done by check_args()
#   if line and client profiles                      (both can't use the same cupll)
#       line_cupll <> client_cupll
#   if line profile
#       line is xfi or multirate                     (cupll only valid for these interfaces)
#       if client is xfi                             (can't use this serdes if client uses it for xfi)
#           line_cupll <> client port - 4
#   if client profile
#       client is xfi or multirate                   (cupll only valid for these interfaces)
#       if line is xfi                               (can't use this serdes if client uses it for xfi)
#           client_cupll <> line port - 4
sub validate_cleanup_pll_args {
    my (%_args) = @_;
    my $line = $_args{line_cupll};
    my $client = $_args{client_cupll};
    my $lineprof = $_args{line_cupll_profile};
    my $clientprof = $_args{client_cupll_profile};
    
    return (0, "line and client can't use the same cleanup pll")     if $lineprof ne 'none' and $clientprof ne 'none' and $line==$client;
    
    if ($lineprof ne 'none') {
        return (0, "line can't use pll since not xfi or multi-rate")   if $_args{hsif_line}   ne 'xfi' and $_args{hsif_line} ne 'cfp_mr';
        return (0, "invalid line_cupll, conflict with client XFI")     if $_args{hsif_client} eq 'xfi' and $line == ($_args{client_port});
    }
    
    if ($clientprof ne 'none') {
        return (0, "client can't use pll since not xfi or multi-rate") if $_args{hsif_client} ne 'xfi' and $_args{hsif_client} ne 'cfp_mr';
        return (0, "invalid client_cupll, conflict with line XFI")     if $_args{hsif_line}   eq 'xfi' and $client == ($_args{line_port});
    }
    return(1, "ok");
}

###############################################################################
# Amplitude recenter subs and data       # Bugzilla 27270 Amplitude Recentering
###############################################################################
my %recenter_parameters = (
    'iml' => '',
    'amp' => { 'narrow'=> { 'margin_lower' =>  5,  'margin_upper' =>  10, 
                            'correct_lower'=>  2,  'correct_upper'=>   0,   'duration' => 2 },
              'typical'=> { 'margin_lower' => 10,  'margin_upper' =>  15,   
                            'correct_lower'=>  5,  'correct_upper'=>   0,   'duration' =>10 },
                 'wide'=> { 'margin_lower' => 90,  'margin_upper' => 100,   
                            'correct_lower'=> 15,  'correct_upper'=>   0,   'duration' =>75 } },
    
    'fpa' => { 'narrow'=> { 'static_depth' => 35,  'circuit_th_lower'=>  2, 'circuit_th_upper' =>100 },
              'typical'=> { 'static_depth' => 75,  'circuit_th_lower'=> 10, 'circuit_th_upper' =>160 },
                 'wide'=> { 'static_depth' =>150,  'circuit_th_lower'=> 35, 'circuit_th_upper' =>260 } },
    'default' => ''
);

##############################################################################
# Function:     recenter_parse_args()
#               Parse recenter arg into type and margins. Best used for
#               parameter validation and status prints.
#
# Returns:      Empty set if type doesn't exist or is invalid.
#               Set containing (type) if type is 'iml' or 'default'.
#               Set containing (type, 'typical') type parameter exists and
#                   margins parameter doesn't.
#               Set containing (type, margins) if both exist and are good.
#               Set containing (type, margins'<<<bad' if the margins parameter
#                   exists but is not found in the table.
##############################################################################
sub recenter_parse_args($)
{
    my $arg = shift;
    my $type;
    my $margins;
    my @parsed;
    
    return @parsed unless $arg;
    
    ($type, $margins) = split(/_/, $arg);
    $type    = "" unless $type;
    $margins = "" unless $margins;
    
    if ($type and exists( $recenter_parameters{$type} ) ) {
        if ($type eq 'iml' or $type eq 'default') {
            push (@parsed, 'default');
        }
        else {
            push (@parsed, $type);
            $margins = 'typical' unless $margins;
            $margins .= '<<<bad' unless exists ( $recenter_parameters{$type}{$margins});
            push (@parsed, $margins);
        }
    }
    else {
        push (@parsed, "");
    }
    return @parsed;
}

##############################################################################
# Function:     recenter_get_api_args( recenter type, recenter margins)
#
# Returns:      Hash of API recenter parameters keyed by c parm name.
#               Empty set if type doesn't exist or is invalid.
##############################################################################
sub recenter_get_api_args($$)
{
  my $type    = shift;
  my $margins = shift;
  my %myret;
  
  if (defined ($type) and exists ($recenter_parameters{$type}) ) {
      if (defined ($margins) and exists ($recenter_parameters{$type}{$margins}) ) {
          %myret = %{$recenter_parameters{$type}{$margins}};
      }
  }
  return %myret;
}

##############################################################################
# Function:     setup_amp_recenter (device, mod, slice, is40g (0|1), 
#                                   type, margins, sysclk_freq )
#               Calls APIs as required to set up amplitude recentering
# Returns:      Nothing
##############################################################################
sub setup_amp_recenter($$$$$$$)
{
    my $dev_    = shift;
    my $mod_    = shift;
    my $slice_  = shift;
    my $is40g_  = shift;     # MUST be 0 for no, 1 for yes. This and $type_ are used to choose which
    my $type_   = shift;     # of 4 amplitude recentering types to pass to amplitude recenter APIs.
    my $mrgns_  = shift;
    my $freq_   = shift;
    my $es_num_ = $mod_*4;
    my $autorc_ = 0x4000;    # Pseudo-constant for auto-recovery. In release 5.5 the type arg in the API
                             # is overloaded to indicate what action to take when a recovery event is
                             # handled. 'Auto' indicates that a full amplitude recenter should be run.
    $es_num_   += $slice_ unless $is40g_;
    if ($type_ ne 'default') {          
        my %api_args = recenter_get_api_args($type_, $mrgns_);
        if (keys %api_args) {
            if ($type_ eq 'amp') {
                main::ten_xcon_es_write_cb_t41($dev_, $es_num_, (main::TEN_XCON_ES_RECENTER_AMP_10G + $is40g_) | $autorc_,
                                      $api_args{margin_lower},  $api_args{margin_upper}, $api_args{correct_lower},
                                      $api_args{correct_upper}, $api_args{duration},     $freq_ );
                print "Measured Amplitude";
            }
            elsif ($type_ eq 'fpa') {
                main::ten_xcon_es_write_cb_t41($dev_, $es_num_, (main::TEN_XCON_ES_RECENTER_FPA_10G + $is40g_) | $autorc_,
                                      $api_args{static_depth}, $api_args{circuit_th_lower}, $api_args{circuit_th_upper}, 0,0,0 );
                print "Frame Pulse Aligned";
            }
            print " ES Recentering with ${mrgns_} margins set up for device $dev_ module $mod_ slice $slice_\n";
            if ($is40g_) { main::ten_xcon_es_setup_amp_recntr_from_cb_40g_t41($dev_, $mod_   ); }
            else         { main::ten_xcon_es_setup_amp_recntr_from_cb_10g_t41($dev_, $es_num_); }
        }
    }
}
# End Bugzilla 27270 Amplitude Recentering

##############################################################################
# Function:     check_t100_option
# Returns:      True or false
##############################################################################
## Bugzilla 31661 Start
sub check_t100_option
{
    return $t100_support;
}
## Bugzilla 31661 End

1;
