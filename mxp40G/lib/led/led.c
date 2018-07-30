#include "led.h"
#include "../gpio/gpio.h"
#include "../util/util.h"

int led_turn_on(unsigned int led_id) 
{
    CHECK_PARAM(led_id > 15, LOG_ERR, TAG_LED, 
        "Error in led_turn_on(): led_id out of range", LOG_LOCAL0);
  
    CHECK_PARAM( gpio_write_bit(led_id,1) < 0, 
         LOG_ERR, TAG_LED, "Error in led_turn_on(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int led_turn_off(unsigned int led_id)
{
    CHECK_PARAM(led_id > 15, LOG_ERR, TAG_LED, "Error in led_turn_off(): led_id out of range", LOG_LOCAL0);

    CHECK_PARAM( gpio_write_bit(led_id,0) < 0, LOG_ERR, TAG_LED, "Error in led_turn_off(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int led_turn_on_all(void)
{   
    CHECK_PARAM(gpio_write_bus(LED_BASE_ADDRESS,15,1) < 0, 
         LOG_ERR, TAG_LED, "Error in led_turn_on_all(): gpio_write_bus()", LOG_LOCAL0);

    return 0;
}

int led_turn_off_all(void)
{
    CHECK_PARAM(gpio_write_bus(LED_BASE_ADDRESS,15,0) < 0, 
         LOG_ERR, TAG_LED, "Error in led_turn_off_all(): gpio_write_bus()", LOG_LOCAL0);

    return 0;
}

int set_led_status(unsigned int led_id, unsigned int value)
{
	CHECK_PARAM(((led_id < LED_QSFP_GREEN) || (led_id > LED_POWER_2)), LOG_ERR, TAG_LED, "Error in set_led_status(): led_id out of range", LOG_LOCAL0);

	if(value > 0)
	{
		value = 1;
	}
	else
	{
		value = 0;
	}

	CHECK_PARAM( gpio_write_bit(led_id, value) < 0, LOG_ERR, TAG_LED, "Error in set_led_status(): gpio_write_bit()", LOG_LOCAL0);

	return 0;
}
