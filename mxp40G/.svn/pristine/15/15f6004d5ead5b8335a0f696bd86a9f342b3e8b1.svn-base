#include "fan.h"
#include "../gpio/gpio.h"
#include "../util/util.h"

int fan_get_alert(unsigned int fan_id, unsigned int *status) 
{
    CHECK_PARAM(((fan_id < FAN5_ALERT) || (fan_id > FAN1_ALERT)), LOG_ERR, TAG_FAN,
        "Error in fan_get_alert(): fan_id out of range", LOG_LOCAL0);
  
    CHECK_PARAM(gpio_read_bit(fan_id, status) < 0, LOG_ERR, TAG_FAN,
        "Error in fan_get_alert: gpio_read_bit", LOG_LOCAL0);

    return 0;
}

int fan_clear(unsigned int fan_id) 
{
    CHECK_PARAM(FAN1_CLEAR < fan_id || FAN5_CLEAR > fan_id, LOG_ERR, TAG_FAN, 
        "Error in fan_clear(): fan_id out of range", LOG_LOCAL0);
 
    CHECK_PARAM(gpio_write_bit(fan_id, 1) < 0, LOG_ERR, TAG_FAN, 
        "Error in fan_clear(): gpio_write_bit()", LOG_LOCAL0);
    
    return 0;
}
