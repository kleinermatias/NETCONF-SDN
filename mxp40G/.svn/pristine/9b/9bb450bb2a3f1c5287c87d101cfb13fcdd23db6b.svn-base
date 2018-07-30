#include "ltc.h"
#include "../gpio/gpio.h"
#include "../util/util.h"


int ltc_enable_latch() 
{
    CHECK_PARAM(gpio_write_bit(LTC_BIT_STATUS, LTC_ENABLED) < 0,
        LOG_ERR, TAG_LTC, "Error in ltc_enable_latch(): gpio_write_bit()", LOG_LOCAL0);

    return 0;    
}

int ltc_disable_latch() 
{
    CHECK_PARAM(gpio_write_bit(LTC_BIT_STATUS, LTC_DISABLED) < 0,
        LOG_ERR, TAG_LTC, "Error in ltc_disable_latch(): gpio_write_bit()", LOG_LOCAL0);

    return 0;    
}

int ltc_get_latch_status(int *latch_value) 
{
     CHECK_PARAM(gpio_read_bit(LTC_BIT_STATUS, (unsigned int*)latch_value) < 0, LOG_ERR, TAG_LTC, 
        "Error in ltc_get_latch_status(): gpio_read_bit()", LOG_LOCAL0);

    return 0;
}

int latch_optical_modules_enable()
{
    CHECK_PARAM(gpio_write_bit(LTC_BIT_STATUS, LTC_ENABLED) < 0,
    		LOG_ERR, TAG_LTC, "Error in latch_optical_modules_enable(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int latch_optical_modules_disable()
{
	CHECK_PARAM(gpio_write_bit(LTC_BIT_STATUS, LTC_DISABLED) < 0,
			LOG_ERR, TAG_LTC, "Error in latch_optical_modules_disable(): gpio_write_bit()", LOG_LOCAL0);

	return 0;
}

int latch_optical_modules_status(int *latch_value)
{
     CHECK_PARAM(gpio_read_bit(LTC_BIT_STATUS, (unsigned int*)latch_value) < 0, LOG_ERR, TAG_LTC,
        "Error in latch_optical_modules_status(): gpio_read_bit()", LOG_LOCAL0);

    return 0;
}

int latch_txp_enable()
{
    CHECK_PARAM(gpio_write_bit(MOD_40G_LATCH_ENABLE, LTC_ENABLED) < 0,
    		LOG_ERR, TAG_LTC, "Error in latch_txp_enable(): gpio_write_bit()", LOG_LOCAL0);

    return 0;

}

int latch_txp_disable()
{
    CHECK_PARAM(gpio_write_bit(MOD_40G_LATCH_ENABLE, LTC_DISABLED) < 0,
    		LOG_ERR, TAG_LTC, "Error in latch_txp_disable(): gpio_write_bit()", LOG_LOCAL0);

	return 0;
}

int latch_txp_status(int *latch_value)
{
     CHECK_PARAM(gpio_read_bit(MOD_40G_LATCH_ENABLE, (unsigned int*)latch_value) < 0, LOG_ERR, TAG_LTC,
        "Error in latch_txp_status(): gpio_read_bit()", LOG_LOCAL0);

    return 0;
}
