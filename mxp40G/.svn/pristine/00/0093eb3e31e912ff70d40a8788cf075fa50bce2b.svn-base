The logs for this script were created by first running the kpga_otu3_gfec_cfp_mr_b_k_64.log.apish setup script to enable traffic, and
then cfp_mr_parallel_Tx_to_Rx_loopback_frac_div.pl to enable the parallel loopback to itself.  

If you wish to just have Tx traffic generated on the CFP_MR interface (such as to check against a tester) and not looped back to itself, 
you can stop running the logs after the first part of the configuration has been run.

This script outputs a 40G OTU3 GFEC signal on Module B attached to the CFP MR interface which is then looped back to itself
internally.  It enables loopback without CFP reference clock and without data paths.  The payload is sourced from the internal
KPG with a PRBS31 non-inverted pattern. The KPA status can be checked in register 0x08127 N40G_GBLR4X_KPASTAT.  
Bits 1:0 PSTAT should read 2'b11, for PRBS31. 

This loopback script replaces Tx reference clock with pilot clock from fractional divider
Note: fractional divider clock will have elevated jitter. But this clock is sufficient to drive Tx-to-Rx parallel loopback. 

Jitter with this loopback may be excessive for the serial lanes to work.

This loopback is tested to work on T41 CEB with or without the loopback card plugged in (without loopback card proves it does not 
depend on applied Rx in any way), and without a clock at the MRB_TX_CLKREF input.

CFP serdes does not include Tx-to-Rx loopback of serial lanes as our other serdes interfaces such as XFI and MR do. Therefore this 
Tx-to-Rx parallel data loopback within the HSIF block is the farthest out loopback that can be run.


A SYSCLK of 425 MHz is assumed.  Please contact your Cortina AE for any other rates you may need.
