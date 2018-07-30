/*
 * power_supply.c
 *
 *  Created on: Jul 10, 2015
 *      Author: Guille
 */
#include "power_supply.h"
#include "../gpio/gpio.h"
#include "../util/util.h"

int ps_get_status(unsigned int ps_id, unsigned int *status)
{
    CHECK_PARAM(((ps_id < STDBY_48V_TWO) || (ps_id > STDBY_48V_ONE)), LOG_ERR, TAG_FAN,
        "Error in ps_get_status(): ps_id out of range", LOG_LOCAL0);

    CHECK_PARAM(gpio_read_bit(ps_id, status) < 0, LOG_ERR, TAG_FAN,
        "Error in ps_get_status: gpio_read_bit", LOG_LOCAL0);

    return 0;
}



