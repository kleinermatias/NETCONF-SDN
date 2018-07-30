#!/usr/bin/perl

# change CFP STXP_REF_SEL_MODE = 0 (XFI SERDES Mode)
#  allows to use fractional divider as Tx reference

# CFP32X1_SDS_COMMON_STXP0_TX_SPARE.STXP_REF_SEL_MODE = 0
ten_reg_write(0, 0x1b22c, 0x00f0);
# CFP32X1_SDS_COMMON_STXP2_TX_SPARE.STXP_REF_SEL_MODE = 0
ten_reg_write(0, 0x1b32c, 0x00f0);


# Change CFP32X1_SDS_COMMON_STXP0_TX_CONFIG to use frac div for Tx reference
#  REGISTER SPEC ERROR:  use STXP_LPTIME_SEL[1:0] = '10' to select frac div as Tx reference
ten_reg_write(0, 0x1b224, 0x8902);
ten_reg_write(0, 0x1b324, 0x8902);

# Change CFP32X1_SDS_COMMON_STXP0_TX_CLKDIV_CTRL for div ratios for ~300MHz frac div (k=32)
ten_reg_write(0, 0x1b226, 0x3501);
ten_reg_write(0, 0x1b326, 0x3501);


# Change Rx divider to k=32 
# Change CFP32X1_SDS_COMMON_SRX0_RX_CLKDIV_CTRL
ten_reg_write(0, 0x1b201, 0x3101);
ten_reg_write(0, 0x1b281, 0x3101);
ten_reg_write(0, 0x1b301, 0x3101);
ten_reg_write(0, 0x1b381, 0x3101);

# assert CFP Rx lock to pilot
# Set also DATA_LOCK and DATA_FILTLOCK (bit 7) to zero so that loss of data amplitude (DATA_DET=0) does not report lock failure
ten_reg_write(0, 0x1b218, 0x2009);
ten_reg_write(0, 0x1b298, 0x2009);
ten_reg_write(0, 0x1b318, 0x2009);
ten_reg_write(0, 0x1b398, 0x2009);

# apply Tx to Rx parallel data loopback
ten_reg_write(0, 0x1b256, 0x0009);
ten_reg_write(0, 0x1b2d6, 0x0009);
ten_reg_write(0, 0x1b356, 0x0009);
ten_reg_write(0, 0x1b3d6, 0x0009);

# set HSIF_PROTOCOL_PSWTCH_OK_CTRL.datadet_en  This causes A-side N40G to ignore MRB DATA_DETs.
#Write address 0x02008 to 0xf0ff
ten_reg_write(0, 0x02008, 0xf0f0);

# set HSIF_PROTOCOL_OK_CTRL.datadet_en  This causes B-side N40G to ignore MRB DATA_DETs.
ten_reg_write(0, 0x02007, 0xf0f0);

#######################################################################
#  Test case
#  On T41 CEB with software release 5.6
#   disable clock to MRB_TX_CLKREF input:   dev_reg_write(432,0,0x4400,0x0100)
#		traffic fails (because CFP clock is lost
#	physically remove CFP (4x10G) loopback card from T41 CEB to interrupt 4x10G data lanes
#   run this script:  traffic passes
#	This proves this script enables loopback without CFP reference clock and without data paths
#
#######################################################################
