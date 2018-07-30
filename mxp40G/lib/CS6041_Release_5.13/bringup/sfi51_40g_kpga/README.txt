This script outputs a 40G OTU3 GFEC signal on Module B SFI5.1.  The payload is sourced from the 
internal KPG with a PRBS31 non-inverted pattern. It should be run with the SFI5.1 module looped back to 
itself.  The KPA status can be checked in register 0x8127 N40G_GBLR4X_KPASTAT.  Bits 1:0 PSTAT should
read 2'b11, for PRBS31. It can also be checked against an OTU3 tester which should detect the PRBS31
sequence.

A SYSCLK of 425 MHz is assumed.  Please contact your Cortina AE for any other rates you may need.
