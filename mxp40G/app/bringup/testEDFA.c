/*
 *  Description:
     	        Tests ability to read/write to top level global register space
    
     	Applicability:
    		T41 (CS604x)
    
    	Directions for use:
                    Run this script once and check that there were no bus timeouts or other access problems
                This script should only require that the clock input SYS_REFCLK_IN is driven.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testEDFA.h"
#include "../../lib/gpio/gpio.h"
#include "../../lib/edfa/edfa.h"

int main(int argc, char **argv)
{
	int value;
	float f;
	char info[256];
	int stage = 1;

	gpio_write_bit(LTC_BIT_STATUS, 1);
	usleep(250000);
	gpio_write_bit(EDFA_PIN_RESET, 1);
	usleep(250000);

	/*test 1*/
//	edfa_set_echo(0);
//	edfa_get_information();

	/*test 2*/
//	edfa_set_echo(0);
//	edfa_get_baud_rate(&value);

	/*test 3*/
//	edfa_set_echo(0);
//	edfa_get_mode(info);

	/*test 4*/
//	edfa_set_echo(0);
//	edfa_get_information();
//	edfa_get_baud_rate(&value);
//	edfa_get_mode();

	/*test 5*/
//	edfa_set_echo(0);
//	edfa_get_splim(stage);

	/*test 6*/
//	edfa_set_echo(0);
//	edfa_get_amplifier_status();

	/*test 7*/
//	edfa_set_echo(0);
//	edfa_get_input_power();

	edfa_set_echo(0);
	edfa_get_pump_mA();

return 0;
}
