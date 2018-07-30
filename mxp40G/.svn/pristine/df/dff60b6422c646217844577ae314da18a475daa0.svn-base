
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test_leds.h"
#include "../../lib/gpio/gpio.h"
#include "../../lib/led/led.h"
#include "../../lib/xfp/xfp.h"

int main(int argc, char **argv)
{
	int led_status = 0;
	int i;
	int xfp_module;

	for(i = LED_QSFP_GREEN; i <= LED_XFP_1_RED; i++)
	{
		set_led_status(i, led_status);
		sleep(1);
	}

	for(xfp_module = XFP_MOD_0; xfp_module <= XFP_MOD_3; xfp_module++)
	{
		set_led_status(xfp_led_green[xfp_module], led_status);
		set_led_status(xfp_led_red[xfp_module], !led_status);

		sleep(1);
	}

	set_led_status(LED_QSFP_GREEN, led_status);
	set_led_status(LED_QSFP_RED, !led_status);

	for(xfp_module = XFP_MOD_0; xfp_module <= XFP_MOD_3; xfp_module++)
	{
		set_led_status(xfp_led_green[xfp_module], !led_status);
		set_led_status(xfp_led_red[xfp_module], led_status);

		sleep(1);
	}

	set_led_status(LED_QSFP_GREEN, !led_status);
	set_led_status(LED_QSFP_RED, led_status);

	return 0;
}
