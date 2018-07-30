This script outputs a 10G OTU2 GFEC signal on Module A SFI4.2 port 0.  The payload is sourced from the 
internal KPG with a PRBS31 non-inverted pattern. It should be run with the SFI4.2 port 0 looped back to 
itself.  The KPA status can be checked in register 0x11098 N10G_GBLR_GBLRStatus.  Bits 2:1 PSTAT should
read 2'b11, for PRBS31. It can also be checked against an OTU2 tester which should detect the PRBS31
sequence.

A SYSCLK of 425 MHz is assumed.  Please contact your Cortina AE for any other rates you may need.
