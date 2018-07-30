/*
 *  Description:
     	        Tests ability to read/write to top level global register space
    
     	Applicability:
    		T41 (CS604x)
    
    	Directions for use:
                    Run this script once and check that there were no bus timeouts or other access problems
                This script should only require that the clock input SYS_REFCLK_IN is driven.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test41.h"
#include "tenabo40.h"
#include "../../lib/gpio/gpio.h"
#include "../../lib/CS6041_Release_5.13/T41/t41_registers.h"
#include "../../lib/cs6041/cs6041.h"
#include "math.h"
#include <fcntl.h>
#include <unistd.h>

unsigned int check_value(unsigned int address, unsigned short data_w, unsigned short data_r)
{
	if(data_w != data_r)
	{
		printf("Error. Address: %#04x .Read value: %#04x. Expected value: %#04x\n", address, data_r, data_w);
		
		return 0;
	}
	
	return 1;
}

unsigned int tenabo_read_default(unsigned int address, unsigned short default_value)
{
	unsigned short data_r;
	
	data_r = register_read(address);
  
  	if(default_value != data_r)
	{
		printf("Data read at address %#04x equals %#04x, but default is %#04x\n", address, data_r, default_value);
	}
	else
	{
		//printf("Data read at address %#04x equals %#04x, which equals default\n", address, data_r);
	}

	return 0;
}
unsigned int tenabo_write_read(unsigned int address, unsigned short data_w)
{
	unsigned short data_r;
	
	register_write(address, data_w);
	
	data_r = register_read(address);
  
	if(data_w != data_r)
	{
		printf("Data read at address %#04x equals %#04x, but expected is %#04x\n", address, data_r, data_w);
	}
	else
	{
		//printf("Data read at address %#04x equals %#04x, which equals expected\n", address, data_r);
	}

	return 0;
}

//##############################################################################
//# Routine:      tenabo_bf_write
//#
//# bitfield write.
//#
//# Parameter:
//#    reg - register offset
//#
//#    val - value
//#
//#    mbp - most significant bit field position
//#
//#    lbp - least significant bit field position
//#
//# Returns:
//#
//#    0: OK
//#    -1: ERROR
//#
unsigned int tenabo_bf_write(unsigned int address, unsigned short val, unsigned short mbp, unsigned short lbp)
{
	unsigned short size;
	unsigned short oldval;
	unsigned short newval;
	unsigned short mask;
	
	if(mbp < lbp)
	{
		return -1;
	}
    size = mbp - lbp + 1;
	
    if (val >= 0 && val < pow(2, size))
    {
        oldval = register_read(address);
		mask = pow(2, size) - 1;
        mask = ~(mask << lbp);
        newval = (oldval & mask) |(val << lbp);
        return register_write(address, newval);
    }
    else 
	{
        printf("illegal value to write\n");
        return -1;
    }
	
    return 0;
}

void bringup_register_global()
{
	unsigned short data_w;
	unsigned short data_r;
	unsigned int data;
	unsigned int chk;
	
	printf("Starting bringup register global test\n");
	
	//############################
	//#Bringup - takes place of ten_hl_config_global( 0x0, 0x1, 0x1, 0x1, 0x1, 0x1 );
	//############################
	register_write(0x00003, 0x00BE );
	register_write(0x00012, 0x0000 );
	register_write(0x00026, 0x0000 );
	register_write(0x00012, 0x0000 );
	register_write(0x00A02, 0x4206 );
	register_write(0x00A05, 0x0033 );
	register_write(0x00A00, 0x0000 );
	register_write(0x00A09, 0x0000 );
	register_write(0x00A0A, 0x0000 );
	register_write(0x00A0C, 0x8000 );
	register_write(0x00A0C, 0x0000 );
	register_write(0x00013, 0x0000 );
	register_write(0x00011, 0x0000 );
	register_write(0x00004, 0x000F );
	register_write(0x00005, 0x00FF );
	register_write(0x00006, 0x00FF );
	register_write(0x00007, 0x00FF );
	register_write(0x00013, 0x0000 );
	register_write(0x00021, 0x00F0 );
	register_write(0x00021, 0xF0F0 );
	register_write(0x00021, 0xF0F0 );
	register_write(0x00022, 0xFFFF );
	register_write(0x00023, 0x0000 );
	register_write(0x00002, 0x000F );
	register_write(0x0006C, 0x0000 );
	register_write(0x01001, 0x0044 );
	register_write(0x01002, 0x0044 );
	register_write(0x01003, 0x0044 );
	register_write(0x01004, 0x0044 );
	register_write(0x00016, 0xFF00 );
	register_write(0x02001, 0x0044 );
	register_write(0x02002, 0x0044 );
	register_write(0x02003, 0x0044 );
	register_write(0x02004, 0x0044 );
	register_write(0x00017, 0xFF00 );
	register_write(0x00011, 0x0000 );
	register_write(0x00A41, 0x0000 );
	register_write(0x00A81, 0x0000 );
	register_write(0x00AC1, 0x0000 );
	register_write(0x00B01, 0x0000 );
	register_write(0x00B41, 0x0000 );
	register_write(0x00B81, 0x0000 );
	register_write(0x00BC1, 0x0000 );
	register_write(0x00C01, 0x0000 );
	register_write(0x00C41, 0x0000 );
	register_write(0x00C81, 0x0000 );
	register_write(0x00CC1, 0x0000 );
	register_write(0x00D01, 0x0000 );
	register_write(0x00D41, 0x0000 );
	register_write(0x00D81, 0x0000 );
	register_write(0x00DC1, 0x0000 );
	register_write(0x00E01, 0x0000 );
	register_write(0x01001, 0x0011 );
	register_write(0x01002, 0x0011 );
	register_write(0x01003, 0x0011 );
	register_write(0x01004, 0x0011 );
	register_write(0x00016, 0xFFFF );
	register_write(0x02001, 0x0011 );
	register_write(0x02002, 0x0011 );
	register_write(0x02003, 0x0011 );
	register_write(0x02004, 0x0011 );
	register_write(0x00017, 0xFFFF );
	register_write(0x00A41, 0x0000 );
	register_write(0x00A81, 0x0000 );
	register_write(0x00AC1, 0x0000 );
	register_write(0x00B01, 0x0000 );
	register_write(0x00B41, 0x0000 );
	register_write(0x00B81, 0x0000 );
	register_write(0x00BC1, 0x0000 );
	register_write(0x00C01, 0x0000 );
	register_write(0x00C41, 0x0000 );
	register_write(0x00C81, 0x0000 );
	register_write(0x00CC1, 0x0000 );
	register_write(0x00D01, 0x0000 );
	register_write(0x00D41, 0x0000 );
	register_write(0x00D81, 0x0000 );
	register_write(0x00DC1, 0x0000 );
	register_write(0x00E01, 0x0000 );
	register_write(0x00011, 0x0000 );
	
	//###############################################################################
	//#GLB_MISC register access
	//#Read CHIP ID
	data_r = register_read(0x00000); //#MPIF_CHIP_ID_LSB
	data = register_read(0x00001); //#MPID_CHIP_ID_MSB

	data = (data << 16) | data_r;
	
	printf("Chip ID: %#04x\n", data);
	
	//#Write and read back scratch pad registers
	register_read(0x00065); //#TEN_MPIF_SCRATCH_PAD1
	register_read(0x00066); //#TEN_MPIF_SCRATCH_PAD2
	register_write(0x00065, 0x55aa); //#TEN_MPIF_SCRATCH_PAD1
	register_write(0x00066, 0xaa55); //#TEN_MPIF_SCRATCH_PAD2
	data_r = register_read(0x00065); //#TEN_MPIF_SCRATCH_PAD1
	check_value(0x00065, 0x55aa, data_r);
	data_r = register_read(0x00066); //#TEN_MPIF_SCRATCH_PAD2
	check_value(0x00066, 0xaa55, data_r);

	//#Read and then Release chip reset
	data_r = register_read(0x00003); //# Should return 0x00BF
	check_value(0x00003, 0x00BF, data_r);
	register_write(0x00003, 0x00BE); //#MPIF_GLOBAL_RESET_COMMON 
	
	//###############################################################################
	//# GPLL and SYSPLL registers
	//###############################################################################
	register_write(0x00011 , 0x0000); //#MPIF_GLOBAL_RESET_GPLL
	data_r = register_read(0x000012); //# Should return 0x0001
	check_value(0x000012, 0x0001, data_r);
	register_write(0x00012 , 0x0000); //#MPIF_GLOBAL_RESET_SYSPLL deassert
	data_r = register_read(0x000012); //# Should return 0x0000
	check_value(0x000012, 0x0000, data_r);

	//###############################################################################
	//# Confirm SYSPLL is locked
	//###############################################################################
	data_r = register_read(0x00a02); //# Should read default of 0x1001
	check_value(0x00a02, 0x1001, data_r);
	
	//#Only run one of the two lines below
	register_write(0x00a02, 0x4206 ); //# If SYSREFCLK_IN is in high range
	//#ten_reg_write ( $dev_id, 0x00a02, 0x4008 ); # If SYSREFCLK_IN is in low range

	//#VCO Coarse tune start
	data_r = register_read(0x00a0c); //#Should read 0x0000
	check_value(0x00a0c, 0x0000, data_r);
	register_write(0x00a0c, 0x8000 ); //#Start coarse tuning algorithm
	// Wait at least 10 ms
	usleep(100000); // Wait 100 ms
	usleep(100000); // Wait 100 ms
	register_write(0x00a0c, 0x0000 );

	//#Check that SYSPLL is locked
	data_r = register_read(0x00a19); //# Status register should read 0x0049 for lock
	chk = check_value(0x00a19, 0x0049, data_r);
	
	if(chk == 1)
	{
		printf("PLL locked!!\n");
	}
	else
	{
		printf("Error: PLL not locked. Please enable the SYS_CLOCK\n");
	}
	
	register_write(0x00a18, 0x007F ); //# Clear all interrupt bits
	data_r = register_read(0x00a18 ); //# Expect 0x0000. Interrupts should not have fired, indicating lock is stable
	check_value(0x00a18, 0x0000, data_r);
	data_r = register_read(0x00a18 ); //# Expect 0x0000. Interrupts should not have fired, indicating lock is stable
	check_value(0x00a18, 0x0000, data_r);
	
	printf("End bringup register global test\n");
	
}

void bringup_register_block()
{
	unsigned int bypass_TB_RESET = 0;
	unsigned int bypass_GLB_MISC = 0; //#no reset check, only reset by pin
	unsigned int bypass_SYNCDSYNC = 0; 
	unsigned int bypass_SPOH = 0;
	unsigned int bypass_HSIF = 0; //#no reset check due to clock cfg
	unsigned int bypass_XFIDSP = 0; //#no reset check due reset from SDS
	unsigned int bypass_XCON = 0;
	unsigned int bypass_GFEC40G = 0;
	unsigned int bypass_GFEC10G = 0;
	unsigned int bypass_UFEC = 0; 
	unsigned int bypass_N40G = 0; 
	unsigned int bypass_OHPP = 0; 
	unsigned int bypass_N10G = 0; 
	unsigned int bypass_PP10G = 0;
	unsigned int bypass_PP40G = 0;
	unsigned int bypass_CUPLL = 0;
	unsigned int bypass_CFP = 0;
	unsigned int bypass_DEFAULTS = 0;

	unsigned int dev_id = 0;
	unsigned int sysrefclk = 425;
	unsigned int sysclk_freq = sysrefclk * 1000000;
	
	unsigned short data_w;
	unsigned short data_r;
	unsigned int data;
	unsigned int chk;
	
	//############################
	//#Bringup - takes place of ten_hl_config_global( 0x0, 0x1, 0x1, 0x1, 0x1, 0x1 );
	//############################
	register_write(0x00003, 0x00BE );
	register_write(0x00012, 0x0000 );
	register_write(0x00026, 0x0000 );
	register_write(0x00012, 0x0000 );
	register_write(0x00A02, 0x4206 );
	register_write(0x00A05, 0x0033 );
	register_write(0x00A00, 0x0000 );
	register_write(0x00A09, 0x0000 );
	register_write(0x00A0A, 0x0000 );
	register_write(0x00A0C, 0x8000 );
	register_write(0x00A0C, 0x0000 );
	register_write(0x00013, 0x0000 );
	register_write(0x00011, 0x0000 );
	register_write(0x00004, 0x000F );
	register_write(0x00005, 0x00FF );
	register_write(0x00006, 0x00FF );
	register_write(0x00007, 0x00FF );
	register_write(0x00013, 0x0000 );
	register_write(0x00021, 0x00F0 );
	register_write(0x00021, 0xF0F0 );
	register_write(0x00021, 0xF0F0 );
	register_write(0x00022, 0xFFFF );
	register_write(0x00023, 0x0000 );
	register_write(0x00002, 0x000F );
	register_write(0x0006C, 0x0000 );
	register_write(0x01001, 0x0044 );
	register_write(0x01002, 0x0044 );
	register_write(0x01003, 0x0044 );
	register_write(0x01004, 0x0044 );
	register_write(0x00016, 0xFF00 );
	register_write(0x02001, 0x0044 );
	register_write(0x02002, 0x0044 );
	register_write(0x02003, 0x0044 );
	register_write(0x02004, 0x0044 );
	register_write(0x00017, 0xFF00 );
	register_write(0x00011, 0x0000 );
	register_write(0x00A41, 0x0000 );
	register_write(0x00A81, 0x0000 );
	register_write(0x00AC1, 0x0000 );
	register_write(0x00B01, 0x0000 );
	register_write(0x00B41, 0x0000 );
	register_write(0x00B81, 0x0000 );
	register_write(0x00BC1, 0x0000 );
	register_write(0x00C01, 0x0000 );
	register_write(0x00C41, 0x0000 );
	register_write(0x00C81, 0x0000 );
	register_write(0x00CC1, 0x0000 );
	register_write(0x00D01, 0x0000 );
	register_write(0x00D41, 0x0000 );
	register_write(0x00D81, 0x0000 );
	register_write(0x00DC1, 0x0000 );
	register_write(0x00E01, 0x0000 );
	register_write(0x01001, 0x0011 );
	register_write(0x01002, 0x0011 );
	register_write(0x01003, 0x0011 );
	register_write(0x01004, 0x0011 );
	register_write(0x00016, 0xFFFF );
	register_write(0x02001, 0x0011 );
	register_write(0x02002, 0x0011 );
	register_write(0x02003, 0x0011 );
	register_write(0x02004, 0x0011 );
	register_write(0x00017, 0xFFFF );
	register_write(0x00A41, 0x0000 );
	register_write(0x00A81, 0x0000 );
	register_write(0x00AC1, 0x0000 );
	register_write(0x00B01, 0x0000 );
	register_write(0x00B41, 0x0000 );
	register_write(0x00B81, 0x0000 );
	register_write(0x00BC1, 0x0000 );
	register_write(0x00C01, 0x0000 );
	register_write(0x00C41, 0x0000 );
	register_write(0x00C81, 0x0000 );
	register_write(0x00CC1, 0x0000 );
	register_write(0x00D01, 0x0000 );
	register_write(0x00D41, 0x0000 );
	register_write(0x00D81, 0x0000 );
	register_write(0x00DC1, 0x0000 );
	register_write(0x00E01, 0x0000 );
	register_write(0x00011, 0x0000 );
	
	//###############################################################################
	//# GLB_MISC registers  
	//###############################################################################
	printf("GLB_MISC registers\n");
	register_write(0x00003, 0x0000);//#MPIF_GLOBAL_RESET_COMMON
	register_write(0x00015, 0x0000);//#MPIF_GLOBAL_CLOCK_DISABLE_COMMON

	//###############################################################################
	//# GPLL and SYSPLL registers
	//###############################################################################
	printf("GPLL and SYSPLL registers\n");
	register_write(0x00011 , 0x0000); //#MPIF_GLOBAL_RESET_GPLL
	register_write(0x00012 , 0x0000); //#MPIF_GLOBAL_RESET_SYSPLL

	//###############################################################################
	//# Confirm SYSPLL is locked
	//###############################################################################
	printf("Confirm SYSPLL is locked\n");
	register_read(0x00a19);
	data_r = register_read(0x00a02); //# Should read default of 0x1001
	check_value(0x00a02, 0x1001, data_r);
	
	//#Only run one of the two lines below
	register_write(0x00a02, 0x4206 ); //# If SYSREFCLK_IN is in high range
	//#ten_reg_write ( $dev_id, 0x00a02, 0x4008 ); # If SYSREFCLK_IN is in low range

	//#VCO Coarse tune start
	data_r = register_read(0x00a0c ); //#Should read 0x0000
	check_value(0x00a0c, 0x0000, data_r);
	
	register_write(0x00a0c, 0x8000 ); //#Start coarse tuning algorithm
	//# Wait at least 10 ms
	usleep(100000); // Wait 100 ms
	usleep(100000); // Wait 100 ms
	register_write(0x00a0c, 0x0000 );

	//#Check that SYSPLL is locked
	data_r = register_read(0x00a19 ); //# Status register should read 0x0049 for lock
	chk = check_value(0x00a19, 0x0049, data_r);
	
	if(chk == 1)
	{
		printf("PLL locked!!\n");
	}
	else
	{
		printf("Error: PLL not locked. Please enable the SYS_CLOCK\n");
	}

	register_write(0x00a18, 0x007F ); //# Clear all interrupt bits
	data_r = register_read(0x00a18 ); //# Expect 0x0000. Interrupts should not have fired, indicating lock is stable
	check_value(0x00a18, 0x0000, data_r);
	data_r = register_read(0x00a18 ); //# Expect 0x0000. Interrupts should not have fired, indicating lock is stable
	check_value(0x00a18, 0x0000, data_r);
	
	//###############################################################################
	//# SYNCDSYNC registers
	//###############################################################################
	printf("SYNCDSYNC registers\n");
	register_write(0x00010 , 0x0000); //#MPIF_GLOBAL_RESET_SYNCDSYNC

	//###############################################################################
	//# SPOH registers 
	//###############################################################################

	//###############################################################################
	//# HSIF registers
	//###############################################################################
	printf("HSIF registers\n");
	register_write(0x00016 , 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A
	register_write(0x00017 , 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B
	register_write(0x00004, 0x0000); //# MPIF_GLOBAL_RESET_HSIF

	//###############################################################################
	//# MR SERDES registers already covered by init  
	//###############################################################################

	//###############################################################################
	//# XFI SERDES registers already covered by init
	//###############################################################################

	//###############################################################################
	//# XFI DSP registers 
	//###############################################################################
	printf("XFI DSP registers\n");
	register_write(0x00013, 0x0000); //# MPIF_GLOBAL_RESET_XFI_DSP
	register_write(0x00013, 0xffff); //# MPIF_GLOBAL_RESET_XFI_DSP
	register_write(0x00013, 0x0000); //# MPIF_GLOBAL_RESET_XFI_DSP

	//###############################################################################
	//# XCON registers 
	//###############################################################################

	//###############################################################################	
	//# GFEC40G registers
	//###############################################################################
	printf("GFEC40G registers\n");
	register_write(0x00018, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_GFEC
	register_write(0x00009, 0x0000); //# MPIF_GLOBAL_RESET_GFEC

	//###############################################################################
	//# GFEC10G registers - enables included above in GFEC40G
	//###############################################################################

	//###############################################################################
	//# UFEC registers  
	//###############################################################################
	printf("UFEC registers\n");
	register_write(0x00019, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_UFEC
	register_write(0x0000a, 0x0000); //# MPIF_GLOBAL_RESET_UFEC

	//###############################################################################
	//# N40G registers
	//###############################################################################
	printf("N40G registers\n");
	register_write(0x0001a, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_N40G_A
	register_write(0x0001b, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_N40G_B
	register_write(0x0000b, 0x0000); //# MPIF_GLOBAL_RESET_N40G

	//###############################################################################
	//# OHPP registers
	//###############################################################################

	//###############################################################################
	//# N10G registers
	//###############################################################################
	printf("N10G registers\n");
	register_write( 0x0001c, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_N10G_A
	register_write(0x0001d, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_N10G_B
	register_write(0x0000c, 0x0000); //# MPIF_GLOBAL_RESET_N10G_A
	register_write(0x0000d, 0x0000); //# MPIF_GLOBAL_RESET_N10G_B


	//###############################################################################
	//# PP10G registers
	//###############################################################################
	printf("PP10G registers\n");
	register_write(0x0001e, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A
	register_write(0x0001f, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B
	register_write(0x0000e, 0x0000); //# MPIF_GLOBAL_RESET_PP10G_A
	register_write(0x0000f, 0x0000); //# MPIF_GLOBAL_RESET_PP10G_B

	int i;
	
	for (i=0; i<=7; i++) 
	{
		register_write(0x19101 + i*1024, 0x07ff); //#  PP10G_MISC_CLKEN_LINE_RX
		register_write(0x19102 + i*1024, 0x007f); //#  PP10G_MISC_CLKEN_LINE_TX
		register_write(0x19103 + i*1024, 0x0001); //#  PP10G_MISC_CLKEN_SYS_RX
		register_write(0x19104 + i*1024, 0x0003); //#  PP10G_MISC_CLKEN_SYS_TX
		register_write(0x19100 + i*1024, 0x0000); //#  PP10G_MISC_RESET
	}
  
	//###############################################################################
	//# PP40G registers
	//###############################################################################
	printf("PP40G registers\n");
	register_write(0x0010a, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_PP40G
	register_write(0x00100, 0x0000); //# MPIF_GLOBAL_RESET_PP40G

	//###############################################################################
	//# CUPLL registers
	//###############################################################################
	printf("CUPLL registers\n");
	register_write(0x0010c, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_CUPLL
	register_write(0x00102, 0x0000); //# MPIF_GLOBAL_RESET_CUPLL
 
	//###############################################################################
	//# CFP registers
	//###############################################################################
	printf("CFP registers\n");
	register_write(0x0010b, 0x0000); //# MPIF_GLOBAL_CLOCK_DISABLE_CFP
	register_write(0x00101, 0x0000); //# MPIF_GLOBAL_RESET_SDS_CFP
	
	//###############################################################################
	//# Do test reads to a register in each block 
	//# 1.) Read and check default value
	//# 2.) Write to a different value
	//# 3.) Read back the value written
	//###############################################################################
	
	if (bypass_DEFAULTS != 1) 
	{
	  tenabo_read_default(TEN_MPIF_SCRATCH_PAD1, 0x0000); 
	  tenabo_read_default(TEN_MPIF_SCRATCH_PAD2, 0x0000); 
	}
	
	tenabo_write_read(TEN_MPIF_SCRATCH_PAD1, 0x55aa); 
	tenabo_write_read(TEN_MPIF_SCRATCH_PAD2, 0xaa55); 
	tenabo_write_read(TEN_MPIF_SCRATCH_PAD1, 0x0000); 
	tenabo_write_read(TEN_MPIF_SCRATCH_PAD2, 0x0000); 

	tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 0, 0);
	tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 8, 8);
	tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 6, 6);
	
	//###############################################################################
	printf("GLB_MISC registers\n");  
	//###############################################################################

	if (bypass_GLB_MISC != 1) 
	{
		tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 5, 5);

		if (bypass_DEFAULTS != 1) 
		{
			tenabo_read_default(TEN_GLB_MISC_GSTI01, TEN_GLB_MISC_GSTI01_dft);  
			tenabo_read_default(TEN_GLB_MISC_GSTI00, TEN_GLB_MISC_GSTI00_dft);  
			tenabo_read_default(TEN_GLB_MISC_GSTI, TEN_GLB_MISC_GSTI_dft);  
			tenabo_read_default(TEN_GLB_MISC_MRA1_LOSAF0, TEN_GLB_MISC_MRA1_LOSAF0_dft);  
			tenabo_read_default(TEN_GLB_MISC_MRB1_LOSAF0, TEN_GLB_MISC_MRB1_LOSAF0_dft);  
			tenabo_read_default(TEN_GLB_MISC_XFI1_LOSAF0, TEN_GLB_MISC_XFI1_LOSAF0_dft);  
		}

		tenabo_write_read(TEN_GLB_MISC_GSTI01, TEN_GLB_MISC_GSTI01 & 0xffff);  
		tenabo_write_read(TEN_GLB_MISC_GSTI00, ~TEN_GLB_MISC_GSTI00 & 0xffff);  
		tenabo_write_read(TEN_GLB_MISC_GSTI, TEN_GLB_MISC_GSTI & 0xffff);  
		tenabo_write_read(TEN_GLB_MISC_MRA1_LOSAF0, ~TEN_GLB_MISC_MRA1_LOSAF0 & 0xffff);  
		tenabo_write_read(TEN_GLB_MISC_MRB1_LOSAF0, TEN_GLB_MISC_MRB1_LOSAF0 & 0xffff);  
		tenabo_write_read(TEN_GLB_MISC_XFI1_LOSAF0, ~TEN_GLB_MISC_XFI1_LOSAF0 & 0xffff);  

		tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 5, 5);
	}
	
	//###############################################################################
	printf("SYNCDSYNC registers\n");  
	//###############################################################################

	if (bypass_SYNCDSYNC != 1) 
	{
		register_write(TEN_MPIF_GLOBAL_RESET_SYNCDSYNC, 0x0000);

		for (i=0; i<=7; i++) 
		{
			if (bypass_DEFAULTS != 1) 
			{
				tenabo_read_default(TEN_SYNCDSYNCRX_CFGMONRX_INTE+i*64, TEN_SYNCDSYNCRX_CFGMONRX_INTE_dft);  
				tenabo_read_default(TEN_SYNCDSYNCTX_CFGMONTX_INTE+i*64, TEN_SYNCDSYNCTX_CFGMONTX_INTE_dft); 
			}
			
			tenabo_write_read(TEN_SYNCDSYNCRX_CFGMONRX_INTE+i*64, TEN_SYNCDSYNCRX_CFGMONRX_INTE & 0x000f);  
			tenabo_write_read(TEN_SYNCDSYNCTX_CFGMONTX_INTE+i*64, TEN_SYNCDSYNCTX_CFGMONTX_INTE & 0x000f); 

			tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_SYNCDSYNC , 0x1, i, i);
			tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_SYNCDSYNC , 0x0, i, i);
			tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_SYNCDSYNC , 0x1, i+8, i+8);
			tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_SYNCDSYNC , 0x0, i+8, i+8);
			tenabo_read_default(TEN_SYNCDSYNCRX_CFGMONRX_INTE+i*64, TEN_SYNCDSYNCRX_CFGMONRX_INTE_dft);  
			tenabo_read_default(TEN_SYNCDSYNCTX_CFGMONTX_INTE+i*64, TEN_SYNCDSYNCTX_CFGMONTX_INTE_dft); 
		}
	}
	
	//###############################################################################
	printf("FRAC_DIV registers already covered by init\n");  
	//###############################################################################

	//###############################################################################
	printf("GPLL registers already covered by init\n");  
	//###############################################################################

	//###############################################################################
	printf("SPOH registers\n");  
	//###############################################################################

	if (bypass_SPOH != 1) 
	{
		tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 2, 2);
		tenabo_bf_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON , 0x0, 1, 1);

		if (bypass_DEFAULTS != 1) 
		{
			tenabo_read_default(TEN_SPOH_Enable, TEN_SPOH_Enable_dft);  
			tenabo_read_default(TEN_SPOH_RDIREIMappingA, TEN_SPOH_RDIREIMappingA_dft); 
		}
		
		tenabo_write_read(TEN_SPOH_Enable, TEN_SPOH_Enable & 0xffff );  
		tenabo_write_read(TEN_SPOH_RDIREIMappingA, TEN_SPOH_RDIREIMappingA & 0x7777 ); 

		tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 2, 2);
		tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 2, 2);
		tenabo_read_default(TEN_SPOH_Enable, TEN_SPOH_Enable_dft);  
		tenabo_read_default(TEN_SPOH_RDIREIMappingA, TEN_SPOH_RDIREIMappingA_dft); 
	}

	//###############################################################################
	printf("HSIF registers\n");  
	//###############################################################################

	if (bypass_HSIF != 1) 
	{
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A, 0x0000); 
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B, 0x0000); 

		register_write(TEN_MPIF_GLOBAL_RESET_HSIF, 0x0000); 

		for (i=0; i<=1; i++) 
		{

			if (bypass_DEFAULTS != 1) 
			{
				tenabo_read_default(TEN_HSIF_PROTOCOL_Intenable +i*4096, TEN_HSIF_PROTOCOL_Intenable_dft );  
				tenabo_read_default(TEN_HSIF_PROTOCOL_SPARE+i*4096, TEN_HSIF_PROTOCOL_SPARE_dft);  

				//tenabo_read_default(TEN_HSIF_SFI5_TESTPORT+i*4096, TEN_HSIF_SFI5_TESTPORT_dft);  
				tenabo_read_default(TEN_HSIF_SFI5_RX_DESKEW_CFG_TOP+i*4096, TEN_HSIF_SFI5_RX_DESKEW_CFG_TOP_dft);  

				tenabo_read_default(TEN_HSIF_SFI42_STD_INTENABLE+i*4096, TEN_HSIF_SFI42_STD_INTENABLE_dft);  
				tenabo_read_default(TEN_HSIF_SFI42_IS_THR0+i*4096, TEN_HSIF_SFI42_IS_THR0_dft);  
			}
			
			tenabo_write_read(TEN_HSIF_PROTOCOL_Intenable +i*4096, TEN_HSIF_PROTOCOL_Intenable & 0x3f3f );  
			tenabo_write_read(TEN_HSIF_PROTOCOL_SPARE+i*4096, TEN_HSIF_PROTOCOL_SPARE & 0xffff );  

			//tenabo_write_read(TEN_HSIF_SFI5_TESTPORT+i*4096, TEN_HSIF_SFI5_TESTPORT & 0xffff );  
			tenabo_write_read(TEN_HSIF_SFI5_RX_DESKEW_CFG_TOP+i*4096, TEN_HSIF_SFI5_RX_DESKEW_CFG_TOP & 0x00ff );  

			tenabo_write_read(TEN_HSIF_SFI42_STD_INTENABLE+i*4096, TEN_HSIF_SFI42_STD_INTENABLE & 0xffff );  
			tenabo_write_read(TEN_HSIF_SFI42_IS_THR0+i*4096, TEN_HSIF_SFI42_IS_THR0 & 0x03ff );  

		}
	}
	
	//###############################################################################
	printf("MR SERDES registers already covered by init\n");  
	//###############################################################################

	//###############################################################################
	printf("XFI SERDES registers already covered by init\n");  
	//###############################################################################

	//###############################################################################
	printf("XFI DSP registers\n");  
	//###############################################################################

	if (bypass_XFIDSP != 1) 
	{
		register_write(TEN_MPIF_GLOBAL_RESET_XFI_DSP, 0x0000); 
		register_write(TEN_MPIF_GLOBAL_RESET_XFI_DSP, 0xffff); 
		register_write(TEN_MPIF_GLOBAL_RESET_XFI_DSP, 0x0000); 

		for (i=0; i<=3; i++) 
		{
			if (bypass_DEFAULTS != 1) 
			{
			}
		}
	
	}
	//###############################################################################
	printf("XCON registers\n");  
	//###############################################################################

	if (bypass_XCON != 1) 
	{
		tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 1, 1);
		tenabo_bf_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON , 0x0, 0, 0);

		if (bypass_DEFAULTS != 1) 
		{
			tenabo_read_default(TEN_XCON_GLB_TOP_INTENABLE, TEN_XCON_GLB_TOP_INTENABLE_dft);  

			tenabo_read_default(TEN_XCON_SADECO_SADCFG1, TEN_XCON_SADECO_SADCFG1_dft);   
			tenabo_read_default(TEN_XCON_SADECO_SADCFG1, TEN_XCON_SADECO_SADCFG1_dft);  

			for (i=0; i<=7; i++) 
			{
				tenabo_read_default(TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER+i*64, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft);  
				tenabo_read_default(TEN_XCON_CBERT_INTERRUPTE+i*64, TEN_XCON_CBERT_INTERRUPTE_dft);   

				tenabo_read_default(TEN_XCON_PBERT_RX_FPAT01+i*32, TEN_XCON_PBERT_RX_FPAT01_dft);   
				tenabo_read_default(TEN_XCON_PBERT_TX_FPAT23+i*32, TEN_XCON_PBERT_TX_FPAT23_dft);   
			}
		}
		tenabo_write_read(TEN_XCON_GLB_TOP_INTENABLE, TEN_XCON_GLB_TOP_INTENABLE_dft & 0x003f );  

		tenabo_write_read(TEN_XCON_SADECO_SADCFG1, TEN_XCON_SADECO_SADCFG1 & 0x1fff );   
		tenabo_write_read(TEN_XCON_SADECO_SADCFG1+64, TEN_XCON_SADECO_SADCFG1 & 0x1fff );  

		for (i=0; i<=7; i++) 
		{
			tenabo_write_read(TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER+i*64, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER & 0x1fff );  
			tenabo_write_read(TEN_XCON_CBERT_INTERRUPTE+i*64, TEN_XCON_CBERT_INTERRUPTE & 0x000f );   

			tenabo_write_read(TEN_XCON_PBERT_RX_FPAT01+i*32, TEN_XCON_PBERT_RX_FPAT01 & 0xffff );   
			tenabo_write_read(TEN_XCON_PBERT_TX_FPAT23+i*32, TEN_XCON_PBERT_TX_FPAT23 & 0xffff );   
		}

		tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 1, 1);
		tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 1, 1);
		tenabo_read_default(TEN_XCON_GLB_TOP_INTENABLE, TEN_XCON_GLB_TOP_INTENABLE_dft);  

		tenabo_read_default(TEN_XCON_SADECO_SADCFG1, TEN_XCON_SADECO_SADCFG1_dft);   
		tenabo_read_default(TEN_XCON_SADECO_SADCFG1, TEN_XCON_SADECO_SADCFG1_dft);  

		for (i=0; i<=7; i++) 
		{
			tenabo_read_default(TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER+i*64, TEN_XCON_ES_CIRCUIT_THRESHOLD_LOWER_dft);  
			tenabo_read_default(TEN_XCON_CBERT_INTERRUPTE+i*64, TEN_XCON_CBERT_INTERRUPTE_dft);   

			tenabo_read_default(TEN_XCON_PBERT_RX_FPAT01+i*32, TEN_XCON_PBERT_RX_FPAT01_dft);   
			tenabo_read_default(TEN_XCON_PBERT_TX_FPAT23+i*32, TEN_XCON_PBERT_TX_FPAT23_dft);   
		}

		tenabo_bf_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON , 0x1, 0, 0);
	}
	
	//###############################################################################
	printf("GFEC40G registers\n");  
	//###############################################################################

	unsigned short reset_cfg;
	
	if (bypass_GFEC40G != 1) 
	{
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC, 0x0000); 

		for (i=0; i<=1; i++) 
		{
			reset_cfg = (i==0) ? 0x0005 : 0x000a ;
			register_write(TEN_MPIF_GLOBAL_RESET_GFEC, reset_cfg);  
			register_write(TEN_MPIF_GLOBAL_RESET_GFEC, reset_cfg ^ 0xffff);  

			reset_cfg = (i==0) ? 0x0005 : 0x000a ;
			register_write(TEN_MPIF_GLOBAL_RESET_GFEC, reset_cfg);  
			register_write(TEN_MPIF_GLOBAL_RESET_GFEC, reset_cfg ^ 0xffff);  
		}

		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC, 0xffff);  
	}

	//###############################################################################
	printf("GFEC10G registers\n");  
	//###############################################################################

	if (bypass_GFEC10G != 1) 
	{
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC, 0x0000);  
		register_write(TEN_MPIF_GLOBAL_RESET_GFEC, 0x0000);  

		for (i=0; i<=2; i++) 
		{
			reset_cfg = (i==0) ? 0x0090 : (i==1) ? 0x0120 : 0x0240 ;
			register_write(TEN_MPIF_GLOBAL_RESET_GFEC, reset_cfg);  
			register_write(TEN_MPIF_GLOBAL_RESET_GFEC, reset_cfg ^ 0xffff);    

			reset_cfg = (i==0) ? 0x0090 : (i==1) ? 0x0120 : 0x0240 ;
			register_write(TEN_MPIF_GLOBAL_RESET_GFEC, reset_cfg);  
			register_write(TEN_MPIF_GLOBAL_RESET_GFEC, reset_cfg ^ 0xffff);  
		}

		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC, 0xffff);  
	}

	//###############################################################################
	printf("UFEC registers\n");  
	//###############################################################################

	if (bypass_UFEC != 1) 
	{
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_UFEC, 0x0000);  
		register_write(TEN_MPIF_GLOBAL_RESET_UFEC, 0x0000);  

		for (i=0; i<=3; i++) 
		{
			reset_cfg = (i==0) ? 0x0011 : (i==1) ? 0x0022 : (i==2) ? 0x0044 : 0x0088 ;
			register_write(TEN_MPIF_GLOBAL_RESET_UFEC, reset_cfg);  
			register_write(TEN_MPIF_GLOBAL_RESET_UFEC, reset_cfg ^ 0xffff);  

			reset_cfg = (i==0) ? 0x0011 : (i==1) ? 0x0022 : (i==2) ? 0x0044 : 0x0088 ;
			register_write(TEN_MPIF_GLOBAL_RESET_UFEC, reset_cfg);  
			register_write(TEN_MPIF_GLOBAL_RESET_UFEC, reset_cfg ^ 0xffff);  
		}

		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_UFEC, 0xffff);
	}

	//###############################################################################
	printf("N40G registers\n");  
	//###############################################################################

	if (bypass_N40G != 1) 
	{
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_A, 0x0000);  
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_B, 0x0000);  
		register_write(TEN_MPIF_GLOBAL_RESET_N40G, 0x0000);  

		for (i=0; i<=1; i++) 
		{
			reset_cfg = (i==0) ? 0x0015 : 0x002a ;
			register_write(TEN_MPIF_GLOBAL_RESET_N40G, reset_cfg);  
			register_write(TEN_MPIF_GLOBAL_RESET_N40G, reset_cfg ^ 0xffff );  

			if (bypass_DEFAULTS != 1) 
			{
				tenabo_read_default(TEN_N40G_GBL4X_SWRST+i*4096, TEN_N40G_GBL4X_SWRST_dft);  
			}

			tenabo_write_read(TEN_N40G_GBL4X_SWRST+i*4096, TEN_N40G_GBL4X_SWRST & 0x0177 );  

			reset_cfg = (i==0) ? 0x0015 : 0x002a ;
			register_write(TEN_MPIF_GLOBAL_RESET_N40G, reset_cfg);  
			register_write(TEN_MPIF_GLOBAL_RESET_N40G, reset_cfg ^ 0xffff );  
			tenabo_read_default(TEN_N40G_GBL4X_SWRST+i*4096, TEN_N40G_GBL4X_SWRST_dft);  
		}

		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_A, 0xffff);  
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_B, 0xffff);  
	}

	//###############################################################################
	printf("OHPP registers\n");  
	//###############################################################################

	if (bypass_OHPP != 1) 
	{

		tenabo_bf_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON , 0x0, 3, 2);

		for (i=0; i<=1; i++) 
		{
			if (i==0) 
			{
				tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 3, 3);
				tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 3, 3);
			} 
			else 
			{
				tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 4, 4);
				tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 4, 4);
			}

			if (bypass_DEFAULTS != 1) 
			{
				tenabo_read_default(TEN_OHPP_SFU_GSFU1DBS+i*16384, TEN_OHPP_SFU_GSFU1DBS_dft); 
			}

			tenabo_write_read(TEN_OHPP_SFU_GSFU1DBS+i*16384, TEN_OHPP_SFU_GSFU1DBS & 0x1fff ); 

			if (i==0) 
			{
				tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 3, 3);
				tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 3, 3);
			} 
			else 
			{
				tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x1, 4, 4);
				tenabo_bf_write(TEN_MPIF_GLOBAL_RESET_COMMON , 0x0, 4, 4);
			}

			tenabo_read_default(TEN_OHPP_SFU_GSFU1DBS+i*16384, TEN_OHPP_SFU_GSFU1DBS_dft); 

		}

		tenabo_bf_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON , 0x3, 3, 2);
	}

	//###############################################################################
	printf("N10G registers\n");  
	//###############################################################################

	if (bypass_N10G != 1) 
	{

		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_A, 0x0000);
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_B, 0x0000);

		for (i=0; i<=7; i++) 
		{
			reset_cfg = (i==0 | i==4) ? 0x0111 : (i==1 | i==5) ? 0x0222 : (i==2 | i==6) ? 0x0444 : 0x0888 ;
			if (i<=3) 
			{
				register_write(TEN_MPIF_GLOBAL_RESET_N10G_A, reset_cfg);  
				register_write(TEN_MPIF_GLOBAL_RESET_N10G_A, reset_cfg ^ 0xffff );  
				register_write(TEN_MPIF_GLOBAL_RESET_N10G_B, 0xffff);  
			} 
			else 
			{
				register_write(TEN_MPIF_GLOBAL_RESET_N10G_B, reset_cfg);  
				register_write(TEN_MPIF_GLOBAL_RESET_N10G_B, reset_cfg ^ 0xffff );  
				register_write(TEN_MPIF_GLOBAL_RESET_N10G_A, 0xffff);  
			}

			if (bypass_DEFAULTS != 1) 
			{
				tenabo_read_default(TEN_N10G_GBL_CFG   +i*4096, TEN_N10G_GBL_CFG_dft);
			}

			tenabo_write_read(TEN_N10G_GBL_CFG   +i*4096, TEN_N10G_GBL_CFG & 0x017f);

			if (i<=3) 
			{
				register_write(TEN_MPIF_GLOBAL_RESET_N10G_A, reset_cfg);  
				register_write(TEN_MPIF_GLOBAL_RESET_N10G_A, reset_cfg ^ 0xffff );  
			} 
			else 
			{
				register_write(TEN_MPIF_GLOBAL_RESET_N10G_B, reset_cfg);  
				register_write(TEN_MPIF_GLOBAL_RESET_N10G_B, reset_cfg ^ 0xffff );  
			}
			tenabo_read_default(TEN_N10G_GBL_CFG   +i*4096, TEN_N10G_GBL_CFG_dft   );
		}

		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_A, 0xffff); 
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_B, 0xffff); 
	}
	
	//###############################################################################
	printf("PP10G registers\n");  
	//###############################################################################

	if (bypass_PP10G != 1) 
	{

		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A, 0x0000);  
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B, 0x0000);  

		for (i=0; i<=7; i++) 
		{
			register_write(TEN_PP10G_MISC_CLKEN_LINE_RX+i*1024, 0x01ff);  
			register_write(TEN_PP10G_MISC_CLKEN_LINE_TX+i*1024, 0x007f);  
			register_write(TEN_PP10G_MISC_CLKEN_SYS_RX +i*1024, 0x0001);  
			register_write(TEN_PP10G_MISC_CLKEN_SYS_TX +i*1024, 0x0003);  
			register_write(TEN_PP10G_MISC_RESET	 +i*1024, 0x0000);  
		} 

		for (i=0; i<=7; i++) 
		{

			reset_cfg = (i==0 | i==4) ? 0x0111 : (i==1 | i==5) ? 0x0222 : (i==2 | i==6) ? 0x0444 : 0x0888 ;
			if (i<=3) 
			{
				register_write(TEN_MPIF_GLOBAL_RESET_PP10G_A, reset_cfg);  
				register_write(TEN_MPIF_GLOBAL_RESET_PP10G_A, reset_cfg ^ 0xffff );  
				register_write(TEN_MPIF_GLOBAL_RESET_PP10G_B, 0xffff );  
			} 
			else 
			{
				register_write(TEN_MPIF_GLOBAL_RESET_PP10G_B, reset_cfg);  
				register_write(TEN_MPIF_GLOBAL_RESET_PP10G_B, reset_cfg ^ 0xffff );  
				register_write(TEN_MPIF_GLOBAL_RESET_PP10G_A, 0xffff );  
			}

			if (bypass_DEFAULTS != 1) 
			{
				//tenabo_read_default(TEN_PP10G_MISC_SPARE+i*1024, TEN_PP10G_MISC_SPARE_dft);  

				tenabo_read_default(TEN_PP10G_MAC_RX_MAXLEN+i*1024, TEN_PP10G_MAC_RX_MAXLEN_dft);  
				tenabo_read_default(TEN_PP10G_MAC_TX_INTENABLE+i*1024, TEN_PP10G_MAC_TX_INTENABLE_dft);  

				tenabo_read_default(TEN_PP10G_XGADJ_RX_INTENABLE+i*1024, TEN_PP10G_XGADJ_RX_INTENABLE_dft);  
				tenabo_read_default(TEN_PP10G_XGADJ_TX_INTENABLE+i*1024, TEN_PP10G_XGADJ_TX_INTENABLE_dft);  

				tenabo_read_default(TEN_PP10G_PM_INTENABLE+i*1024, TEN_PP10G_PM_INTENABLE_dft);  
			}

			//tenabo_write_read(TEN_PP10G_MISC_SPARE+i*1024, TEN_PP10G_MISC_SPARE_dft);  

			tenabo_write_read(TEN_PP10G_MAC_RX_MAXLEN+i*1024, TEN_PP10G_MAC_RX_MAXLEN_dft);  
			tenabo_write_read(TEN_PP10G_MAC_TX_INTENABLE+i*1024, TEN_PP10G_MAC_TX_INTENABLE_dft);  

			tenabo_write_read(TEN_PP10G_XGADJ_RX_INTENABLE+i*1024, TEN_PP10G_XGADJ_RX_INTENABLE_dft);  
			tenabo_write_read(TEN_PP10G_XGADJ_TX_INTENABLE+i*1024, TEN_PP10G_XGADJ_TX_INTENABLE_dft);  

			tenabo_write_read(TEN_PP10G_PM_INTENABLE+i*1024, TEN_PP10G_PM_INTENABLE_dft);  

			if (i<=3) 
			{
				register_write(TEN_MPIF_GLOBAL_RESET_PP10G_A, reset_cfg);  
				register_write(TEN_MPIF_GLOBAL_RESET_PP10G_A, reset_cfg ^ 0xffff );  
			} 
			else 
			{
				register_write(TEN_MPIF_GLOBAL_RESET_PP10G_B, reset_cfg);  
				register_write(TEN_MPIF_GLOBAL_RESET_PP10G_B, reset_cfg ^ 0xffff );  
			}
			//tenabo_read_default(TEN_PP10G_MISC_SPARE+i*1024, TEN_PP10G_MISC_SPARE_dft);  

			tenabo_read_default(TEN_PP10G_MAC_RX_MAXLEN+i*1024, TEN_PP10G_MAC_RX_MAXLEN_dft);  
			tenabo_read_default(TEN_PP10G_MAC_TX_INTENABLE+i*1024, TEN_PP10G_MAC_TX_INTENABLE_dft);  

			tenabo_read_default(TEN_PP10G_XGADJ_RX_INTENABLE+i*1024, TEN_PP10G_XGADJ_RX_INTENABLE_dft);  
			tenabo_read_default(TEN_PP10G_XGADJ_TX_INTENABLE+i*1024, TEN_PP10G_XGADJ_TX_INTENABLE_dft);  

			tenabo_read_default(TEN_PP10G_PM_INTENABLE+i*1024, TEN_PP10G_PM_INTENABLE_dft);  
		}

		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A, 0xffff);  
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B, 0xffff);  
	}

	//###############################################################################
	printf("PP40G registers\n");  
	//###############################################################################

	if (bypass_PP40G != 1) 
	{
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP40G, 0x0000); 
		register_write(TEN_MPIF_GLOBAL_RESET_PP40G, 0x0000); 

		for (i=0; i<=1; i++) 
		{
			register_write(TEN_PP40G_MISC_RESET + i*256, 0x0000); 
  
			if (bypass_DEFAULTS != 1) 
			{
				tenabo_read_default(TEN_PP40G_MISC_RX_INTENABLE +i*256, TEN_PP40G_MISC_RX_INTENABLE_dft );  
			}
			tenabo_write_read(TEN_PP40G_MISC_RX_INTENABLE +i*256, 0x001f );  
		}
	}

	//###############################################################################
	printf("CUPLL registers\n");  
	//###############################################################################

	if (bypass_CUPLL != 1) 
	{
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_CUPLL, 0x0000); 
		//register_write(MPIF_GLOBAL_RESET_CUPLL, 0x0000); 

		for (i=0; i<=3; i++) 
		{
  
			if (bypass_DEFAULTS != 1) 
			{
				tenabo_read_default(TEN_XFI_CUPLL_LOCKDET_INTENABLE +i*64, TEN_XFI_CUPLL_LOCKDET_INTENABLE_dft );  
			}
			tenabo_write_read(TEN_XFI_CUPLL_LOCKDET_INTENABLE +i*64, 0x0003 );  
		}
	} 

	//###############################################################################
	printf("CFP registers\n");  
	//###############################################################################

	if (bypass_CUPLL != 1) 
	{
		register_write(TEN_MPIF_GLOBAL_CLOCK_DISABLE_CFP, 0x0000); 
		//register_write(MPIF_GLOBAL_RESET_SDS_CFP, 0x0000); 

		for (i=0; i<=3; i++) 
		{
	  
			if (bypass_DEFAULTS != 1) 
			{
				tenabo_read_default(TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTENABLE +i*128, TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTENABLE_dft );  
			}
			tenabo_write_read(TEN_CFP32X1_SDS_COMMON_RXLOCKD0_INTENABLE +i*128,  0x000f );  
		}
	}
}

int main(int argc, char **argv)
{
	int dev_id=0;
    
    //gpio_init_ports(47,47,"out");
    gpio_write_bit(26,1);
	  
	if(argc == 2)
	{
		if(strcmp(argv[1],"reset") == 0)
		{
			
			printf("Action: %s \n", argv[1]);
			
			cs6041_reset();
		} 
		
		if(strcmp(argv[1],"com_test") == 0)
		{
			time_t start, end;
			struct tm *ts_start;
			char buffer_start[80];
		    struct tm *ts_end;
		    char buffer_end[80];

			printf("Action: %s \n", argv[1]);

			unsigned int i;
			unsigned long int address = 0x65;
			unsigned long int data_w = 0xBCBC;
			unsigned short data_r;
			unsigned int status_write;
			unsigned int error_count = 0;

			open_upie();

			start = time(0);

			for(i = 0; i < 10000; i++)
			{
				status_write = parallel_write(address, data_w);

				data_r = parallel_read(address);

				if(data_w != data_r)
				{
					error_count++;
					printf("Address: %#04x, data_w: %#08x, data_r: %#08x\n", address, data_w, data_r);
				}

				data_w--;
			}

			end = time(0);

			ts_start = localtime(&start);
			strftime(buffer_start, sizeof(buffer_start), "\n start:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_start);
			printf("%s\n", buffer_start);

			ts_end = localtime(&end);
			strftime(buffer_end, sizeof(buffer_end), " end:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_end);
			printf("%s\n", buffer_end);

			close_upie();

			printf("\n Error count in communication reliability test: %d of: %d \n\n", error_count, 10000);
		}

		if(strcmp(argv[1],"gpio_test") == 0)
		{

		}

		if(strcmp(argv[1],"init") == 0)
		{
			cs_uint16 dev_id = 0;
			cs_uint8 module_num = 0;
			cs_uint32 module_id;
			unsigned int address = 0x78;
			T41_t Chip;

			reset(); 
			bringup_register_global();

			//Driver instantation
			//printf("FF - Loading T41 Driver\n");
			print_status("FF - T41 Driver loaded", ten_drvr_load());	//The driver is loaded

			//Device regsitration
			//printf("FF - Registering Device #1\n");
			print_status("FF - Device #1 registered", ten_dev_register(dev_id, (cs_uint32)&Chip));

			print_status("FF - Device #1 init", ten_dev_main_init(dev_id));

			//printf("Read. Address: %#04x - Value: %#04x\n", address, ten_reg_read(dev_id, address));

			//Module registration
			print_status("FF - Module #1 init", ten_mod_main_init(dev_id, module_num));

			printf("Read Scractch Pad1 = %04x \n", ten_mpif_read_scratch_pad1(dev_id));
			printf("Write Scractch Pad1 \n", ten_mpif_scratch_pad1(dev_id,0xFEFE));
			printf("Read Scractch Pad1 = %04x \n", ten_mpif_read_scratch_pad1(dev_id));

			printf("Start Test\n");

			//init();

				printf("TEN HL CONFIG GLOBAL\n");
	 ten_hl_config_global(
            dev_id,                     //Device ID
            TEN_GLOBAL_MODE_S_40G,      //Line Mode
            TEN_GLOBAL_MODE_QUAD_10G,   //Client Mode
            1,                          //mbclksel
            1,                          //Multi-Rate Mode not SFI41 Line
            1                           //Multi-Rate Mode not SFI41 Client
            );
			
		}
		if(strcmp(argv[1],"bringup_register_global") == 0)
		{
			bringup_register_global();
		}
		
		if(strcmp(argv[1],"bringup_register_block") == 0)
		{
			bringup_register_block();
		}
	}
	else if(argc == 3)
	{
		if(strcmp(argv[1],"read") == 0)
		{
			unsigned long int address;

			address = (unsigned long int)strtol(argv[2], NULL, 16);

			open_upie();

			printf("Read operation - Address: %#08x - Value: %#08x\n", address, parallel_read(address));

			close_upie();
		}
	}
	else if(argc == 4)
	{
		if(strcmp(argv[1],"write") == 0)
		{
			unsigned long int address;
			unsigned long int data_w;

			address = (unsigned long int)strtol(argv[2], NULL, 16);
			data_w = (unsigned long int)strtol(argv[3], NULL, 16);

			open_upie();
			
			printf("Write operation - status: %d\n", parallel_write(address, data_w));
			
			close_upie();
		}
	}
	else
	{
		printf("Wrong command. Options: ./test41 reset | ./test41 read address | ./test41 write address value\n");
		printf("./test41 com_test | ./test41 bringup_register_global | ./test41 bringup_register_block\n");
	}
	
    return 0;
}
