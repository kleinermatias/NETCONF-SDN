Log was created from the full.pl call within the autogen, not the batch of the
autogen itself since 5.6 autogen is incorrect.

This script outputs an 40G OTU3 GFEC signal on Module B CFP OTL3.4.  The payload is sourced from the 
internal KPG with a PRBS31 non-inverted pattern. It should be run with the CFP port looped back to 
itself.  The KPA status can be checked in register 0x08127 N40G_GBLR4X_KPASTAT.  Bits 1:0 PSTAT should
read 2'b11, for PRBS31. It can also be checked against an OTU3 tester which should detect the PRBS31
sequence.

A SYSCLK of 425 MHz is assumed.  Please contact your Cortina AE for any other rates you may need.
