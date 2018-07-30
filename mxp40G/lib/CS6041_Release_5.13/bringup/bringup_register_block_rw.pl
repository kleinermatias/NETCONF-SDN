#!/usr/bin/perl

########################################################################################################
#   filename:  bringup_register_block_rw.pl
#
#	Description:
# 	        Tests ability to read/write to each block's register space
#
# 	Applicability:
#		T41 (CS604x)
#
#	Directions for use:
#                Run this script once and check that there were no bus timeouts or other access problems
#                This script should only require that the clock input SYS_REFCLK_IN is driven.
#	         It checks register defaults, and read and write access for a few registers in each
#                sub-block of the T41. 
#
#	Revision History:
#		Rev 1.0: March 15, 2012
#		- First release
#		
########################################################################################################

use check;
use configs;
use config_clocks;

my $bypass_TB_RESET = 0;
my $bypass_GLB_MISC = 0; #no reset check, only reset by pin
my $bypass_SYNCDSYNC = 0; 
my $bypass_SPOH = 0;
my $bypass_HSIF = 0; #no reset check due to clock cfg
my $bypass_XFIDSP = 0; #no reset check due reset from SDS
my $bypass_XCON = 0;
my $bypass_GFEC40G = 0;
my $bypass_GFEC10G = 0;
my $bypass_UFEC = 0; 
my $bypass_N40G = 0; 
my $bypass_OHPP = 0; 
my $bypass_N10G = 0; 
my $bypass_PP10G = 0;
my $bypass_PP40G = 0;
my $bypass_CUPLL = 0;
my $bypass_CFP = 0;
my $bypass_DEFAULTS = 0;

my $dev_id = 0;
my $sysrefclk = 425;
my $sysclk_freq = $sysrefclk * 1000000;

tb_init( $sysclk_freq, $dev_id, $dyn_repro == 3 ? 1 : 0 );
ten_dev_main_init($dev_id);

my $mod_a = ten_mod_main_init( $dev_id, 0 );
my $mod_b = ten_mod_main_init( $dev_id, 1 );

$mbclksel = $sysclk_freq > 200000000 ? 1 : 0;
#ten_hl_config_global( $dev_id, 1, 1, $mbclksel, 1, 1 );

############################
#Bringup - takes place of ten_hl_config_global( 0x0, 0x1, 0x1, 0x1, 0x1, 0x1 );
############################
ten_reg_write($dev_id, 0x00003, 0x00BE );
ten_reg_write($dev_id, 0x00012, 0x0000 );
ten_reg_write($dev_id, 0x00026, 0x0000 );
ten_reg_write($dev_id, 0x00012, 0x0000 );
ten_reg_write($dev_id, 0x00A02, 0x4206 );
ten_reg_write($dev_id, 0x00A05, 0x0033 );
ten_reg_write($dev_id, 0x00A00, 0x0000 );
ten_reg_write($dev_id, 0x00A09, 0x0000 );
ten_reg_write($dev_id, 0x00A0A, 0x0000 );
ten_reg_write($dev_id, 0x00A0C, 0x8000 );
ten_reg_write($dev_id, 0x00A0C, 0x0000 );
ten_reg_write($dev_id, 0x00013, 0x0000 );
ten_reg_write($dev_id, 0x00011, 0x0000 );
ten_reg_write($dev_id, 0x00004, 0x000F );
ten_reg_write($dev_id, 0x00005, 0x00FF );
ten_reg_write($dev_id, 0x00006, 0x00FF );
ten_reg_write($dev_id, 0x00007, 0x00FF );
ten_reg_write($dev_id, 0x00013, 0x0000 );
ten_reg_write($dev_id, 0x00021, 0x00F0 );
ten_reg_write($dev_id, 0x00021, 0xF0F0 );
ten_reg_write($dev_id, 0x00021, 0xF0F0 );
ten_reg_write($dev_id, 0x00022, 0xFFFF );
ten_reg_write($dev_id, 0x00023, 0x0000 );
ten_reg_write($dev_id, 0x00002, 0x000F );
ten_reg_write($dev_id, 0x0006C, 0x0000 );
ten_reg_write($dev_id, 0x01001, 0x0044 );
ten_reg_write($dev_id, 0x01002, 0x0044 );
ten_reg_write($dev_id, 0x01003, 0x0044 );
ten_reg_write($dev_id, 0x01004, 0x0044 );
ten_reg_write($dev_id, 0x00016, 0xFF00 );
ten_reg_write($dev_id, 0x02001, 0x0044 );
ten_reg_write($dev_id, 0x02002, 0x0044 );
ten_reg_write($dev_id, 0x02003, 0x0044 );
ten_reg_write($dev_id, 0x02004, 0x0044 );
ten_reg_write($dev_id, 0x00017, 0xFF00 );
ten_reg_write($dev_id, 0x00011, 0x0000 );
ten_reg_write($dev_id, 0x00A41, 0x0000 );
ten_reg_write($dev_id, 0x00A81, 0x0000 );
ten_reg_write($dev_id, 0x00AC1, 0x0000 );
ten_reg_write($dev_id, 0x00B01, 0x0000 );
ten_reg_write($dev_id, 0x00B41, 0x0000 );
ten_reg_write($dev_id, 0x00B81, 0x0000 );
ten_reg_write($dev_id, 0x00BC1, 0x0000 );
ten_reg_write($dev_id, 0x00C01, 0x0000 );
ten_reg_write($dev_id, 0x00C41, 0x0000 );
ten_reg_write($dev_id, 0x00C81, 0x0000 );
ten_reg_write($dev_id, 0x00CC1, 0x0000 );
ten_reg_write($dev_id, 0x00D01, 0x0000 );
ten_reg_write($dev_id, 0x00D41, 0x0000 );
ten_reg_write($dev_id, 0x00D81, 0x0000 );
ten_reg_write($dev_id, 0x00DC1, 0x0000 );
ten_reg_write($dev_id, 0x00E01, 0x0000 );
ten_reg_write($dev_id, 0x01001, 0x0011 );
ten_reg_write($dev_id, 0x01002, 0x0011 );
ten_reg_write($dev_id, 0x01003, 0x0011 );
ten_reg_write($dev_id, 0x01004, 0x0011 );
ten_reg_write($dev_id, 0x00016, 0xFFFF );
ten_reg_write($dev_id, 0x02001, 0x0011 );
ten_reg_write($dev_id, 0x02002, 0x0011 );
ten_reg_write($dev_id, 0x02003, 0x0011 );
ten_reg_write($dev_id, 0x02004, 0x0011 );
ten_reg_write($dev_id, 0x00017, 0xFFFF );
ten_reg_write($dev_id, 0x00A41, 0x0000 );
ten_reg_write($dev_id, 0x00A81, 0x0000 );
ten_reg_write($dev_id, 0x00AC1, 0x0000 );
ten_reg_write($dev_id, 0x00B01, 0x0000 );
ten_reg_write($dev_id, 0x00B41, 0x0000 );
ten_reg_write($dev_id, 0x00B81, 0x0000 );
ten_reg_write($dev_id, 0x00BC1, 0x0000 );
ten_reg_write($dev_id, 0x00C01, 0x0000 );
ten_reg_write($dev_id, 0x00C41, 0x0000 );
ten_reg_write($dev_id, 0x00C81, 0x0000 );
ten_reg_write($dev_id, 0x00CC1, 0x0000 );
ten_reg_write($dev_id, 0x00D01, 0x0000 );
ten_reg_write($dev_id, 0x00D41, 0x0000 );
ten_reg_write($dev_id, 0x00D81, 0x0000 );
ten_reg_write($dev_id, 0x00DC1, 0x0000 );
ten_reg_write($dev_id, 0x00E01, 0x0000 );
ten_reg_write($dev_id, 0x00011, 0x0000 );

###############################################################################
# GLB_MISC registers  
###############################################################################
ten_reg_write($dev_id, 0x00003, 0x0000);#MPIF_GLOBAL_RESET_COMMON
ten_reg_write($dev_id, 0x00015, 0x0000);#MPIF_GLOBAL_CLOCK_DISABLE_COMMON

###############################################################################
# GPLL and SYSPLL registers
###############################################################################
ten_reg_write($dev_id, 0x00011 , 0x0000); #MPIF_GLOBAL_RESET_GPLL
ten_reg_write($dev_id, 0x00012 , 0x0000); #MPIF_GLOBAL_RESET_SYSPLL

###############################################################################
# Confirm SYSPLL is locked
###############################################################################
ten_reg_read( $dev_id, 0x00a19 );
ten_reg_read( $dev_id, 0x00a02 ); # Should read default of 0x1001

#Only run one of the two lines below
ten_reg_write( $dev_id, 0x00a02, 0x4206 ); # If SYSREFCLK_IN is in high range
#ten_reg_write ( $dev_id, 0x00a02, 0x4008 ); # If SYSREFCLK_IN is in low range

#VCO Coarse tune start
ten_reg_read( $dev_id, 0x00a0c ); #Should read 0x0000
ten_reg_write( $dev_id, 0x00a0c, 0x8000 ); #Start coarse tuning algorithm
sleep 1; # Wait at least 10 ms
ten_reg_write( $dev_id, 0x00a0c, 0x0000 );

#Check that SYSPLL is locked
ten_reg_read( $dev_id, 0x00a19 ); # Status register should read 0x0049 for lock

ten_reg_write( $dev_id, 0x00a18, 0x007F ); # Clear all interrupt bits
ten_reg_read( $dev_id, 0x00a18 ); # Expect 0x0000. Interrupts should not have fired, indicating lock is stable
ten_reg_read( $dev_id, 0x00a18 ); # Expect 0x0000. Interrupts should not have fired, indicating lock is stable



###############################################################################
# SYNCDSYNC registers
###############################################################################
ten_reg_write($dev_id, 0x00010 , 0x0000); #MPIF_GLOBAL_RESET_SYNCDSYNC

###############################################################################
# SPOH registers 
###############################################################################

###############################################################################
# HSIF registers
###############################################################################
ten_reg_write($dev_id, 0x00016 , 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A
ten_reg_write($dev_id, 0x00017 , 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B
ten_reg_write($dev_id, 0x00004, 0x0000); # MPIF_GLOBAL_RESET_HSIF

###############################################################################
# MR SERDES registers already covered by init  
###############################################################################



###############################################################################
# XFI SERDES registers already covered by init
###############################################################################



###############################################################################
# XFI DSP registers 
###############################################################################
ten_reg_write($dev_id, 0x00013, 0x0000); # MPIF_GLOBAL_RESET_XFI_DSP
ten_reg_write($dev_id, 0x00013, 0xffff); # MPIF_GLOBAL_RESET_XFI_DSP
ten_reg_write($dev_id, 0x00013, 0x0000); # MPIF_GLOBAL_RESET_XFI_DSP

###############################################################################
# XCON registers 
###############################################################################

###############################################################################
# GFEC40G registers
###############################################################################
ten_reg_write($dev_id, 0x00018, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_GFEC
ten_reg_write($dev_id, 0x00009, 0x0000); # MPIF_GLOBAL_RESET_GFEC


###############################################################################
# GFEC10G registers - enables included above in GFEC40G
###############################################################################


###############################################################################
# UFEC registers  
###############################################################################
ten_reg_write($dev_id, 0x00019, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_UFEC
ten_reg_write($dev_id, 0x0000a, 0x0000); # MPIF_GLOBAL_RESET_UFEC


###############################################################################
# N40G registers
###############################################################################
ten_reg_write($dev_id, 0x0001a, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_N40G_A
ten_reg_write($dev_id, 0x0001b, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_N40G_B
ten_reg_write($dev_id, 0x0000b, 0x0000); # MPIF_GLOBAL_RESET_N40G


###############################################################################
# OHPP registers
###############################################################################

    
###############################################################################
# N10G registers
###############################################################################
ten_reg_write($dev_id, 0x0001c, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_N10G_A
ten_reg_write($dev_id, 0x0001d, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_N10G_B
ten_reg_write($dev_id, 0x0000c, 0x0000); # MPIF_GLOBAL_RESET_N10G_A
ten_reg_write($dev_id, 0x0000d, 0x0000); # MPIF_GLOBAL_RESET_N10G_B


###############################################################################
# PP10G registers
###############################################################################
ten_reg_write($dev_id, 0x0001e, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A
ten_reg_write($dev_id, 0x0001f, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B
ten_reg_write($dev_id, 0x0000e, 0x0000); # MPIF_GLOBAL_RESET_PP10G_A
ten_reg_write($dev_id, 0x0000f, 0x0000); # MPIF_GLOBAL_RESET_PP10G_B

  for (my $i=0; $i<=7; $i++) {
    ten_reg_write($dev_id, 0x19101 +$i*1024, 0x07ff); #  PP10G_MISC_CLKEN_LINE_RX
    ten_reg_write($dev_id, 0x19102 +$i*1024, 0x007f); #  PP10G_MISC_CLKEN_LINE_TX
    ten_reg_write($dev_id, 0x19103 +$i*1024, 0x0001); #  PP10G_MISC_CLKEN_SYS_RX
    ten_reg_write($dev_id, 0x19104 +$i*1024, 0x0003); #  PP10G_MISC_CLKEN_SYS_TX
    ten_reg_write($dev_id, 0x19100 +$i*1024, 0x0000); #  PP10G_MISC_RESET
  }
  
###############################################################################
# PP40G registers
###############################################################################
ten_reg_write($dev_id, 0x0010a, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_PP40G
ten_reg_write($dev_id, 0x00100, 0x0000); # MPIF_GLOBAL_RESET_PP40G

###############################################################################
# CUPLL registers
###############################################################################
ten_reg_write($dev_id, 0x0010c, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_CUPLL
ten_reg_write($dev_id, 0x00102, 0x0000); # MPIF_GLOBAL_RESET_CUPLL
 
###############################################################################
# CFP registers
###############################################################################
ten_reg_write($dev_id, 0x0010b, 0x0000); # MPIF_GLOBAL_CLOCK_DISABLE_CFP
ten_reg_write($dev_id, 0x00101, 0x0000); # MPIF_GLOBAL_RESET_SDS_CFP

###############################################################################
# Do test reads to a register in each block 
# 1.) Read and check default value
# 2.) Write to a different value
# 3.) Read back the value written
###############################################################################
sub tenabo_read_default{
  my ($dev_id,$addr,$default) = @_;
  my $rd_data = ten_reg_read($dev_id, $addr);
  
  my $hexaddr = sprintf("%x", $addr); 
  my $hexrd_data = sprintf("%x", $rd_data); 
  my $hexdefault = sprintf("%x", $default);
  
  if ($rd_data != $default) {
    print("Data read at address 0x$hexaddr equals 0x$hexrd_data, but default is 0x$hexdefault\n");
  }
  else {
    print("Data read at address 0x$hexaddr equals 0x$hexrd_data, which equals default\n");  
  }
  return 0;
}
sub tenabo_write_read{
  my ($dev_id,$addr,$data) = @_;
  ten_reg_write($dev_id, $addr, $data);
  my $rd_data = ten_reg_read($dev_id, $addr);
  
  my $hexaddr = sprintf("%x", $addr); 
  my $hexrd_data = sprintf("%x", $rd_data); 
  my $hexdata = sprintf("%x", $data);
  
  if ($rd_data != $data) {
    print("Data read at address 0x$hexaddr equals 0x$hexrd_data, but expected is 0x$hexdata\n");
  }
  else {
    print("Data read at address 0x$hexaddr equals 0x$hexrd_data, which equals expected\n");  
  }  
  return 0;
}

if ($bypass_DEFAULTS != 1) {
  tenabo_read_default($dev_id, TEN_MPIF_SCRATCH_PAD1, 0x0000); 
  tenabo_read_default($dev_id, TEN_MPIF_SCRATCH_PAD2, 0x0000); 
}
tenabo_write_read($dev_id, TEN_MPIF_SCRATCH_PAD1, 0x55aa); 
tenabo_write_read($dev_id, TEN_MPIF_SCRATCH_PAD2, 0xaa55); 
tenabo_write_read($dev_id, TEN_MPIF_SCRATCH_PAD1, 0x0000); 
tenabo_write_read($dev_id, TEN_MPIF_SCRATCH_PAD2, 0x0000); 

tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 0, 0);
tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 8, 8);
tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 6, 6);

###############################################################################
print("**********GLB_MISC registers\n");  
###############################################################################

if ($bypass_GLB_MISC != 1) {
  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 5, 5);

  if ($bypass_DEFAULTS != 1) {
    tenabo_read_default($dev_id, TEN_GLB_MISC_GSTI01	, TEN_GLB_MISC_GSTI01_dft);  
    tenabo_read_default($dev_id, TEN_GLB_MISC_GSTI00	, TEN_GLB_MISC_GSTI00_dft);  
    tenabo_read_default($dev_id, TEN_GLB_MISC_GSTI	, TEN_GLB_MISC_GSTI_dft);  
    tenabo_read_default($dev_id, TEN_GLB_MISC_MRA1_LOSAF0, TEN_GLB_MISC_MRA1_LOSAF0_dft);  
    tenabo_read_default($dev_id, TEN_GLB_MISC_MRB1_LOSAF0, TEN_GLB_MISC_MRB1_LOSAF0_dft);  
    tenabo_read_default($dev_id, TEN_GLB_MISC_XFI1_LOSAF0, TEN_GLB_MISC_XFI1_LOSAF0_dft);  
  }

  tenabo_write_read($dev_id, TEN_GLB_MISC_GSTI01	, TEN_GLB_MISC_GSTI01 & 0xffff);  
  tenabo_write_read($dev_id, TEN_GLB_MISC_GSTI00	, ~TEN_GLB_MISC_GSTI00 & 0xffff);  
  tenabo_write_read($dev_id, TEN_GLB_MISC_GSTI	, TEN_GLB_MISC_GSTI & 0xffff);  
  tenabo_write_read($dev_id, TEN_GLB_MISC_MRA1_LOSAF0, ~TEN_GLB_MISC_MRA1_LOSAF0 & 0xffff);  
  tenabo_write_read($dev_id, TEN_GLB_MISC_MRB1_LOSAF0, TEN_GLB_MISC_MRB1_LOSAF0 & 0xffff);  
  tenabo_write_read($dev_id, TEN_GLB_MISC_XFI1_LOSAF0, ~TEN_GLB_MISC_XFI1_LOSAF0 & 0xffff);  

  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 5, 5);
}

###############################################################################
print("**********SYNCDSYNC registers\n");  
###############################################################################


if ($bypass_SYNCDSYNC != 1) {
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_SYNCDSYNC, 0x0000);

  for (my $i=0; $i<=7; $i++) {
    if ($bypass_DEFAULTS != 1) {
      tenabo_read_default($dev_id, TEN_SYNCDSYNCRX_CFGMONRX_INTE+$i*64, TEN_SYNCDSYNCRX_CFGMONRX_INTE_dft);  
      tenabo_read_default($dev_id, TEN_SYNCDSYNCTX_CFGMONTX_INTE+$i*64, TEN_SYNCDSYNCTX_CFGMONTX_INTE_dft); 
    }
    tenabo_write_read($dev_id, TEN_SYNCDSYNCRX_CFGMONRX_INTE+$i*64, TEN_SYNCDSYNCRX_CFGMONRX_INTE & 0x000f);  
    tenabo_write_read($dev_id, TEN_SYNCDSYNCTX_CFGMONTX_INTE+$i*64, TEN_SYNCDSYNCTX_CFGMONTX_INTE & 0x000f); 

    tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_SYNCDSYNC , 0x1, $i, $i);
    tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_SYNCDSYNC , 0x0, $i, $i);
    tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_SYNCDSYNC , 0x1, $i+8, $i+8);
    tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_SYNCDSYNC , 0x0, $i+8, $i+8);
    tenabo_read_default($dev_id, TEN_SYNCDSYNCRX_CFGMONRX_INTE+$i*64, TEN_SYNCDSYNCRX_CFGMONRX_INTE_dft);  
    tenabo_read_default($dev_id, TEN_SYNCDSYNCTX_CFGMONTX_INTE+$i*64, TEN_SYNCDSYNCTX_CFGMONTX_INTE_dft); 
  }
}
###############################################################################
print("FRAC_DIV registers already covered by init\n");  
###############################################################################

###############################################################################
print("GPLL registers already covered by init\n");  
###############################################################################

###############################################################################
print("**********SPOH registers\n");  
###############################################################################

if ($bypass_SPOH != 1) {
  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 2, 2);
  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON , 0x0, 1, 1);

  if ($bypass_DEFAULTS != 1) {
    tenabo_read_default($dev_id, TEN_SPOH_Enable, TEN_SPOH_Enable_dft);  
    tenabo_read_default($dev_id, TEN_SPOH_RDIREIMappingA, TEN_SPOH_RDIREIMappingA_dft); 
  }
  tenabo_write_read($dev_id, TEN_SPOH_Enable, TEN_SPOH_Enable & 0xffff );  
  tenabo_write_read($dev_id, TEN_SPOH_RDIREIMappingA, TEN_SPOH_RDIREIMappingA & 0x7777 ); 

  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 2, 2);
  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 2, 2);
  tenabo_read_default($dev_id, TEN_SPOH_Enable, TEN_SPOH_Enable_dft);  
  tenabo_read_default($dev_id, TEN_SPOH_RDIREIMappingA, TEN_SPOH_RDIREIMappingA_dft); 
}

###############################################################################
print("**********HSIF registers\n");  
###############################################################################

if ($bypass_HSIF != 1) {
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A, 0x0000); 
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B, 0x0000); 

  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_HSIF, 0x0000); 

  for (my $i=0; $i<=1; $i++) {

  if ($bypass_DEFAULTS != 1) {
    tenabo_read_default($dev_id, TEN_HSIF_PROTOCOL_Intenable +$i*4096, TEN_HSIF_PROTOCOL_Intenable_dft );  
    tenabo_read_default($dev_id, TEN_HSIF_PROTOCOL_SPARE+$i*4096, TEN_HSIF_PROTOCOL_SPARE_dft);  

    tenabo_read_default($dev_id, TEN_HSIF_SFI5_TESTPORT+$i*4096, TEN_HSIF_SFI5_TESTPORT_dft);  
    tenabo_read_default($dev_id, TEN_HSIF_SFI5_RX_DESKEW_CFG_TOP+$i*4096, TEN_HSIF_SFI5_RX_DESKEW_CFG_TOP_dft);  

    tenabo_read_default($dev_id, TEN_HSIF_SFI42_STD_INTENABLE+$i*4096, TEN_HSIF_SFI42_STD_INTENABLE_dft);  
    tenabo_read_default($dev_id, TEN_HSIF_SFI42_IS_THR0+$i*4096, TEN_HSIF_SFI42_IS_THR0_dft);  
  }
  tenabo_write_read($dev_id, TEN_HSIF_PROTOCOL_Intenable +$i*4096, TEN_HSIF_PROTOCOL_Intenable & 0x3f3f );  
  tenabo_write_read($dev_id, TEN_HSIF_PROTOCOL_SPARE+$i*4096, TEN_HSIF_PROTOCOL_SPARE & 0xffff );  

  tenabo_write_read($dev_id, TEN_HSIF_SFI5_TESTPORT+$i*4096, TEN_HSIF_SFI5_TESTPORT & 0xffff );  
  tenabo_write_read($dev_id, TEN_HSIF_SFI5_RX_DESKEW_CFG_TOP+$i*4096, TEN_HSIF_SFI5_RX_DESKEW_CFG_TOP & 0x00ff );  

  tenabo_write_read($dev_id, TEN_HSIF_SFI42_STD_INTENABLE+$i*4096, TEN_HSIF_SFI42_STD_INTENABLE & 0xffff );  
  tenabo_write_read($dev_id, TEN_HSIF_SFI42_IS_THR0+$i*4096, TEN_HSIF_SFI42_IS_THR0 & 0x03ff );  

  }
}

###############################################################################
print("MR SERDES registers already covered by init\n");  
###############################################################################

###############################################################################
print("XFI SERDES registers already covered by init\n");  
###############################################################################

###############################################################################
print("**********XFI DSP registers\n");  
###############################################################################

if ($bypass_XFIDSP != 1) {
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_XFI_DSP, 0x0000); 
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_XFI_DSP, 0xffff); 
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_XFI_DSP, 0x0000); 

  for (my $i=0; $i<=3; $i++) {
  if ($bypass_DEFAULTS != 1) {
  }
  }
}

###############################################################################
print("**********XCON registers\n");  
###############################################################################

if ($bypass_XCON != 1) {
  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 1, 1);
  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON , 0x0, 0, 0);

  if ($bypass_DEFAULTS != 1) {
    tenabo_read_default($dev_id, TEN_XCON_GLB_TOP_INTENABLE, TEN_XCON_GLB_TOP_INTENABLE_dft);  

    tenabo_read_default($dev_id, TEN_XCON_SADECO_SADCFG1, TEN_XCON_SADECO_SADCFG1_dft);   
    tenabo_read_default($dev_id, TEN_XCON_SADECO_SADCFG1, TEN_XCON_SADECO_SADCFG1_dft);  

    for (my $i=0; $i<=7; $i++) {
      tenabo_read_default($dev_id, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER+$i*64, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft);  
      tenabo_read_default($dev_id, TEN_XCON_CBERT_INTERRUPTE+$i*64, TEN_XCON_CBERT_INTERRUPTE_dft);   

      tenabo_read_default($dev_id, TEN_XCON_PBERT_RX_FPAT01+$i*32, TEN_XCON_PBERT_RX_FPAT01_dft);   
      tenabo_read_default($dev_id, TEN_XCON_PBERT_TX_FPAT23+$i*32, TEN_XCON_PBERT_TX_FPAT23_dft);   
    }
  }
  tenabo_write_read($dev_id, TEN_XCON_GLB_TOP_INTENABLE, TEN_XCON_GLB_TOP_INTENABLE_dft & 0x003f );  

  tenabo_write_read($dev_id, TEN_XCON_SADECO_SADCFG1, TEN_XCON_SADECO_SADCFG1 & 0x1fff );   
  tenabo_write_read($dev_id, TEN_XCON_SADECO_SADCFG1+64, TEN_XCON_SADECO_SADCFG1 & 0x1fff );  

  for (my $i=0; $i<=7; $i++) {
    tenabo_write_read($dev_id, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER+$i*64, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER & 0x1fff );  
    tenabo_write_read($dev_id, TEN_XCON_CBERT_INTERRUPTE+$i*64, TEN_XCON_CBERT_INTERRUPTE & 0x000f );   

    tenabo_write_read($dev_id, TEN_XCON_PBERT_RX_FPAT01+$i*32, TEN_XCON_PBERT_RX_FPAT01 & 0xffff );   
    tenabo_write_read($dev_id, TEN_XCON_PBERT_TX_FPAT23+$i*32, TEN_XCON_PBERT_TX_FPAT23 & 0xffff );   
  }

  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 1, 1);
  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 1, 1);
  tenabo_read_default($dev_id, TEN_XCON_GLB_TOP_INTENABLE, TEN_XCON_GLB_TOP_INTENABLE_dft);  

  tenabo_read_default($dev_id, TEN_XCON_SADECO_SADCFG1, TEN_XCON_SADECO_SADCFG1_dft);   
  tenabo_read_default($dev_id, TEN_XCON_SADECO_SADCFG1, TEN_XCON_SADECO_SADCFG1_dft);  

  for (my $i=0; $i<=7; $i++) {
    tenabo_read_default($dev_id, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER+$i*64, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft);  
    tenabo_read_default($dev_id, TEN_XCON_CBERT_INTERRUPTE+$i*64, TEN_XCON_CBERT_INTERRUPTE_dft);   

    tenabo_read_default($dev_id, TEN_XCON_PBERT_RX_FPAT01+$i*32, TEN_XCON_PBERT_RX_FPAT01_dft);   
    tenabo_read_default($dev_id, TEN_XCON_PBERT_TX_FPAT23+$i*32, TEN_XCON_PBERT_TX_FPAT23_dft);   
  }

  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON , 0x1, 0, 0);
}

###############################################################################
print("**********GFEC40G registers\n");  
###############################################################################

if ($bypass_GFEC40G != 1) {
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC, 0x0000); 

  for (my $i=0; $i<=1; $i++) {
    my $reset_cfg = ($i==0) ? 0x0005 : 0x000a ;
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_GFEC, $reset_cfg);  
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_GFEC, $reset_cfg ^ 0xffff);  

    my $reset_cfg = ($i==0) ? 0x0005 : 0x000a ;
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_GFEC, $reset_cfg);  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_GFEC, $reset_cfg ^ 0xffff);  
  }

  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC, 0xffff);  
}

###############################################################################
print("**********GFEC10G registers\n");  
###############################################################################

if ($bypass_GFEC10G != 1) {
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC, 0x0000);  
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_GFEC, 0x0000);  

  for (my $i=0; $i<=2; $i++) {
    my $reset_cfg = ($i==0) ? 0x0090 : ($i==1) ? 0x0120 : 0x0240 ;
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_GFEC, $reset_cfg);  
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_GFEC, $reset_cfg ^ 0xffff);    

    my $reset_cfg = ($i==0) ? 0x0090 : ($i==1) ? 0x0120 : 0x0240 ;
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_GFEC, $reset_cfg);  
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_GFEC, $reset_cfg ^ 0xffff);  
  }

  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC, 0xffff);  
}

###############################################################################
print("**********UFEC registers\n");  
###############################################################################

if ($bypass_UFEC != 1) {
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_UFEC, 0x0000);  
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_UFEC, 0x0000);  

  for (my $i=0; $i<=3; $i++) {
    my $reset_cfg = ($i==0) ? 0x0011 : ($i==1) ? 0x0022 : ($i==2) ? 0x0044 : 0x0088 ;
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_UFEC, $reset_cfg);  
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_UFEC, $reset_cfg ^ 0xffff);  

    my $reset_cfg = ($i==0) ? 0x0011 : ($i==1) ? 0x0022 : ($i==2) ? 0x0044 : 0x0088 ;
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_UFEC, $reset_cfg);  
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_UFEC, $reset_cfg ^ 0xffff);  
  }

  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_UFEC, 0xffff);
}

###############################################################################
print("**********N40G registers\n");  
###############################################################################

if ($bypass_N40G != 1) {
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_A, 0x0000);  
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_B, 0x0000);  
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N40G, 0x0000);  

  for (my $i=0; $i<=1; $i++) {
    my $reset_cfg = ($i==0) ? 0x0015 : 0x002a ;
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N40G, $reset_cfg);  
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N40G, $reset_cfg ^ 0xffff );  

    if ($bypass_DEFAULTS != 1) {
      tenabo_read_default($dev_id, TEN_N40G_GBL4X_SWRST+$i*4096, TEN_N40G_GBL4X_SWRST_dft);  
    }

    tenabo_write_read($dev_id, TEN_N40G_GBL4X_SWRST+$i*4096, TEN_N40G_GBL4X_SWRST & 0x0177 );  

    my $reset_cfg = ($i==0) ? 0x0015 : 0x002a ;
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N40G, $reset_cfg);  
    ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N40G, $reset_cfg ^ 0xffff );  
    tenabo_read_default($dev_id, TEN_N40G_GBL4X_SWRST+$i*4096, TEN_N40G_GBL4X_SWRST_dft);  
  }

  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_A, 0xffff);  
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_B, 0xffff);  
}

###############################################################################
print("**********OHPP registers\n");  
###############################################################################

if ($bypass_OHPP != 1) {

  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON , 0x0, 3, 2);

  for (my $i=0; $i<=1; $i++) {
    if ($i==0) {
      tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 3, 3);
      tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 3, 3);
    } else {
      tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 4, 4);
      tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 4, 4);
    }

    if ($bypass_DEFAULTS != 1) {
      tenabo_read_default($dev_id, TEN_OHPP_SFU_GSFU1DBS+$i*16384, TEN_OHPP_SFU_GSFU1DBS_dft); 
    }

    tenabo_write_read($dev_id, TEN_OHPP_SFU_GSFU1DBS+$i*16384, TEN_OHPP_SFU_GSFU1DBS & 0x1fff ); 

    if ($i==0) {
      tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 3, 3);
      tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 3, 3);
    } else {
      tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 4, 4);
      tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 4, 4);
    }

    tenabo_read_default($dev_id, TEN_OHPP_SFU_GSFU1DBS+$i*16384, TEN_OHPP_SFU_GSFU1DBS_dft); 

  }

  tenabo_bf_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON , 0x3, 3, 2);
}

###############################################################################
print("**********N10G registers\n");  
###############################################################################

if ($bypass_N10G != 1) {

  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_A, 0x0000);
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_B, 0x0000);

  for (my $i=0; $i<=7; $i++) {
    my $reset_cfg = ($i==0 | $i==4) ? 0x0111 : ($i==1 | $i==5) ? 0x0222 : ($i==2 | $i==6) ? 0x0444 : 0x0888 ;
    if ($i<=3) {
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N10G_A, $reset_cfg);  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N10G_A, $reset_cfg ^ 0xffff );  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N10G_B, 0xffff);  
    } else {
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N10G_B, $reset_cfg);  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N10G_B, $reset_cfg ^ 0xffff );  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N10G_A, 0xffff);  
    }

    if ($bypass_DEFAULTS != 1) {
      tenabo_read_default($dev_id, TEN_N10G_GBL_CFG   +$i*4096, TEN_N10G_GBL_CFG_dft);
    }

    tenabo_write_read($dev_id, TEN_N10G_GBL_CFG   +$i*4096, TEN_N10G_GBL_CFG & 0x017f);

    if ($i<=3) {
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N10G_A, $reset_cfg);  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N10G_A, $reset_cfg ^ 0xffff );  
    } else {
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N10G_B, $reset_cfg);  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_N10G_B, $reset_cfg ^ 0xffff );  
    }
    tenabo_read_default($dev_id, TEN_N10G_GBL_CFG   +$i*4096, TEN_N10G_GBL_CFG_dft   );
  }

  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_A, 0xffff); 
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_B, 0xffff); 
}

###############################################################################
print("**********PP10G registers\n");  
###############################################################################

if ($bypass_PP10G != 1) {

  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A, 0x0000);  
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B, 0x0000);  

  for (my $i=0; $i<=7; $i++) {
    ten_reg_write($dev_id, TEN_PP10G_MISC_CLKEN_LINE_RX+$i*1024, 0x01ff);  
    ten_reg_write($dev_id, TEN_PP10G_MISC_CLKEN_LINE_TX+$i*1024, 0x007f);  
    ten_reg_write($dev_id, TEN_PP10G_MISC_CLKEN_SYS_RX +$i*1024, 0x0001);  
    ten_reg_write($dev_id, TEN_PP10G_MISC_CLKEN_SYS_TX +$i*1024, 0x0003);  
    ten_reg_write($dev_id, TEN_PP10G_MISC_RESET	 +$i*1024, 0x0000);  
  } 

  for (my $i=0; $i<=7; $i++) {

    my $reset_cfg = ($i==0 | $i==4) ? 0x0111 : ($i==1 | $i==5) ? 0x0222 : ($i==2 | $i==6) ? 0x0444 : 0x0888 ;
    if ($i<=3) {
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP10G_A, $reset_cfg);  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP10G_A, $reset_cfg ^ 0xffff );  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP10G_B, 0xffff );  
    } else {
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP10G_B, $reset_cfg);  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP10G_B, $reset_cfg ^ 0xffff );  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP10G_A, 0xffff );  
    }

    if ($bypass_DEFAULTS != 1) {
      tenabo_read_default($dev_id, TEN_PP10G_MISC_SPARE+$i*1024, TEN_PP10G_MISC_SPARE_dft);  

      tenabo_read_default($dev_id, TEN_PP10G_MAC_RX_MAXLEN+$i*1024, TEN_PP10G_MAC_RX_MAXLEN_dft);  
      tenabo_read_default($dev_id, TEN_PP10G_MAC_TX_INTENABLE+$i*1024, TEN_PP10G_MAC_TX_INTENABLE_dft);  

      tenabo_read_default($dev_id, TEN_PP10G_XGADJ_RX_INTENABLE+$i*1024, TEN_PP10G_XGADJ_RX_INTENABLE_dft);  
      tenabo_read_default($dev_id, TEN_PP10G_XGADJ_TX_INTENABLE+$i*1024, TEN_PP10G_XGADJ_TX_INTENABLE_dft);  

      tenabo_read_default($dev_id, TEN_PP10G_PM_INTENABLE+$i*1024, TEN_PP10G_PM_INTENABLE_dft);  
    }

    tenabo_write_read($dev_id, TEN_PP10G_MISC_SPARE+$i*1024, TEN_PP10G_MISC_SPARE_dft);  

    tenabo_write_read($dev_id, TEN_PP10G_MAC_RX_MAXLEN+$i*1024, TEN_PP10G_MAC_RX_MAXLEN_dft);  
    tenabo_write_read($dev_id, TEN_PP10G_MAC_TX_INTENABLE+$i*1024, TEN_PP10G_MAC_TX_INTENABLE_dft);  

    tenabo_write_read($dev_id, TEN_PP10G_XGADJ_RX_INTENABLE+$i*1024, TEN_PP10G_XGADJ_RX_INTENABLE_dft);  
    tenabo_write_read($dev_id, TEN_PP10G_XGADJ_TX_INTENABLE+$i*1024, TEN_PP10G_XGADJ_TX_INTENABLE_dft);  

    tenabo_write_read($dev_id, TEN_PP10G_PM_INTENABLE+$i*1024, TEN_PP10G_PM_INTENABLE_dft);  

    if ($i<=3) {
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP10G_A, $reset_cfg);  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP10G_A, $reset_cfg ^ 0xffff );  
    } else {
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP10G_B, $reset_cfg);  
      ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP10G_B, $reset_cfg ^ 0xffff );  
    }
    tenabo_read_default($dev_id, TEN_PP10G_MISC_SPARE+$i*1024, TEN_PP10G_MISC_SPARE_dft);  

    tenabo_read_default($dev_id, TEN_PP10G_MAC_RX_MAXLEN+$i*1024, TEN_PP10G_MAC_RX_MAXLEN_dft);  
    tenabo_read_default($dev_id, TEN_PP10G_MAC_TX_INTENABLE+$i*1024, TEN_PP10G_MAC_TX_INTENABLE_dft);  

    tenabo_read_default($dev_id, TEN_PP10G_XGADJ_RX_INTENABLE+$i*1024, TEN_PP10G_XGADJ_RX_INTENABLE_dft);  
    tenabo_read_default($dev_id, TEN_PP10G_XGADJ_TX_INTENABLE+$i*1024, TEN_PP10G_XGADJ_TX_INTENABLE_dft);  

    tenabo_read_default($dev_id, TEN_PP10G_PM_INTENABLE+$i*1024, TEN_PP10G_PM_INTENABLE_dft);  
  }

  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A, 0xffff);  
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B, 0xffff);  
}


###############################################################################
print("**********PP40G registers\n");  
###############################################################################

if ($bypass_PP40G != 1) {
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP40G, 0x0000); 
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_RESET_PP40G, 0x0000); 

  for (my $i=0; $i<=1; $i++) {
    ten_reg_write($dev_id, TEN_PP40G_MISC_RESET + $i*256, 0x0000); 
  
    if ($bypass_DEFAULTS != 1) {
      tenabo_read_default($dev_id, TEN_PP40G_MISC_RX_INTENABLE +$i*256, TEN_PP40G_MISC_RX_INTENABLE_dft );  
    }
    tenabo_write_read($dev_id, TEN_PP40G_MISC_RX_INTENABLE +$i*256, 0x001f );  
  }
}

###############################################################################
print("**********CUPLL registers\n");  
###############################################################################

if ($bypass_CUPLL != 1) {
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_CUPLL, 0x0000); 
  ten_reg_write($dev_id, MPIF_GLOBAL_RESET_CUPLL, 0x0000); 

  for (my $i=0; $i<=3; $i++) {
  
    if ($bypass_DEFAULTS != 1) {
      tenabo_read_default($dev_id, TEN_XFI_CUPLL_LOCKDET_INTENABLE +$i*64, TEN_XFI_CUPLL_LOCKDET_INTENABLE_dft );  
    }
    tenabo_write_read($dev_id, TEN_XFI_CUPLL_LOCKDET_INTENABLE +$i*64, 0x0003 );  
  }
} 

###############################################################################
print("**********CFP registers\n");  
###############################################################################

if ($bypass_CUPLL != 1) {
  ten_reg_write($dev_id, TEN_MPIF_GLOBAL_CLOCK_DISABLE_CFP, 0x0000); 
  ten_reg_write($dev_id, MPIF_GLOBAL_RESET_SDS_CFP, 0x0000); 

  for (my $i=0; $i<=3; $i++) {
  
    if ($bypass_DEFAULTS != 1) {
      tenabo_read_default($dev_id, TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTENABLE +$i*128, TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTENABLE_dft );  
    }
    tenabo_write_read($dev_id, TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTENABLE +$i*128,  0x000f );  
  }
} 
