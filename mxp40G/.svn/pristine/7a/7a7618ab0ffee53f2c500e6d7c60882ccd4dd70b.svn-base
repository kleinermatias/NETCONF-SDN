#!/usr/bin/perl

########################################################################################################
#   filename:  bringup_register_global_rw.pl
#
#	Description:
# 	        Tests ability to read/write to top level global register space
#
# 	Applicability:
#		T41 (CS604x)
#
#	Directions for use:
#                Run this script once and check that there were no bus timeouts or other access problems
#                This script should only require that the clock input SYS_REFCLK_IN is driven.
#	  
#
#	Revision History:
#		Rev 1.0: March 15, 2012
#		- First release
#		
########################################################################################################
my $dev_id = 0;

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
#GLB_MISC register access
#Read CHIP ID
ten_reg_read($dev_id, 0x00000); #MPIF_CHIP_ID_LSB
ten_reg_read($dev_id, 0x00001); #MPID_CHIP_ID_MSB

#Write and read back scratch pad registers
ten_reg_read($dev_id, 0x00065); #TEN_MPIF_SCRATCH_PAD1
ten_reg_read($dev_id, 0x00066); #TEN_MPIF_SCRATCH_PAD2
ten_reg_write($dev_id, 0x00065, 0x55aa); #TEN_MPIF_SCRATCH_PAD1
ten_reg_write($dev_id, 0x00066, 0xaa55); #TEN_MPIF_SCRATCH_PAD2
ten_reg_read($dev_id, 0x00065); #TEN_MPIF_SCRATCH_PAD1
ten_reg_read($dev_id, 0x00066); #TEN_MPIF_SCRATCH_PAD2

#Read and then Release chip reset
ten_reg_read($dev_id, 0x00003); # Should return 0x00BF
ten_reg_write($dev_id, 0x00003, 0x00BE); #MPIF_GLOBAL_RESET_COMMON 

###############################################################################
# GPLL and SYSPLL registers
###############################################################################
ten_reg_write($dev_id, 0x00011 , 0x0000); #MPIF_GLOBAL_RESET_GPLL
ten_reg_read($dev_id, 0x000012); # Should return 0x0001
ten_reg_write($dev_id, 0x00012 , 0x0000); #MPIF_GLOBAL_RESET_SYSPLL deassert
ten_reg_read($dev_id, 0x000012); # Should return 0x0000

###############################################################################
# Confirm SYSPLL is locked
###############################################################################
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
