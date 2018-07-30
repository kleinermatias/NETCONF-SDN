#include "hmd.h"
#include "../i2c/i2crw.h"
#include "../bitman/bitman.h"
#include "../gpio/gpio.h"
#include <unistd.h>
//#include <filelock.h>
#include "../utils/filelock.h"
#include "../util/util.h"

int hmd_get_temp_comp_humidity(int *temp_comp_humidity)
{
    int humidity = 0; 
    int temperature = 0; 
    int relative_humidity = 0;
    int linear_humidity = 0;

#ifdef TESTING
    CHECK_PARAM(hmd_get_humidity_mock(&humidity) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_temp_comp_humidity(): hmd_get_humidity()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_get_humidity(&humidity) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_temp_comp_humidity(): hmd_get_humidity()", LOG_LOCAL0);
#endif

#ifdef TESTING    
    CHECK_PARAM(hmd_get_temperature_mock(&temperature) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_temp_comp_humidity(): hmd_get_humidity()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_get_temperature(&temperature) < 0, LOG_ERR, TAG_HMD,
        "Error in hmd_get_temp_comp_humidity(): hmd_get_temperature()", LOG_LOCAL0);
#endif

#ifdef TESTING
    relative_humidity = hmd_convert_to_relative_humidity_mock(humidity);
#else
    relative_humidity = hmd_convert_to_relative_humidity(humidity);
#endif

#ifdef TESTING
    linear_humidity = hmd_apply_linearization_mock(relative_humidity);
#else
    linear_humidity = hmd_apply_linearization(relative_humidity);
#endif

#ifdef TESTING
    *temp_comp_humidity = hmd_apply_temp_compensation_mock(linear_humidity, temperature);
#else
    *temp_comp_humidity = hmd_apply_temp_compensation(linear_humidity, temperature);
#endif

    return 0;
}


int hmd_get_humidity(int *humidity)
{
    int config_reg = 0;
    int ready = 1;

#ifdef TESTING
    CHECK_PARAM(hmd_get_configuration_mock(&config_reg) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_humidity(): hmd_get_configuration()");
#else
    CHECK_PARAM(hmd_get_configuration(&config_reg) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_humidity(): hmd_get_configuration()", LOG_LOCAL0);
#endif 

    CHECK_PARAM(clear_bit((unsigned int*)&config_reg, HMD_TEMP_BIT) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_humidity(): clear_bit(HMD_TEMP_BIT)", LOG_LOCAL0);

    CHECK_PARAM(set_bit((unsigned int*)&config_reg, HMD_START_BIT) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_humidity(): set_bit(HMD_START_BIT)", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(hmd_set_configuration_mock(config_reg) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_humidity(): hmd_set_configuration()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_set_configuration(config_reg) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_humidity(): hmd_set_configuration()", LOG_LOCAL0);
#endif

#ifdef TESTING
    CHECK_PARAM(hmd_is_conversion_ready_mock(&ready) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_humidity(): hmd_is_conversion_ready(1)", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_is_conversion_ready(&ready) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_humidity(): hmd_is_conversion_ready(1)", LOG_LOCAL0);
#endif    

    while (ready) {
        sleep(5);
#ifdef TESTING
        CHECK_PARAM(hmd_is_conversion_ready_mock(&ready) < 0, LOG_ERR, TAG_HMD, 
            "Error in hmd_get_humidity(): hmd_is_conversion_ready(2)", LOG_LOCAL0);
#else
        CHECK_PARAM(hmd_is_conversion_ready(&ready) < 0, LOG_ERR, TAG_HMD, 
            "Error in hmd_get_humidity(): hmd_is_conversion_ready(2)", LOG_LOCAL0);
#endif

    }
	int fd_lock;
	fd_lock = filelock_open("hdm_lock");
	filelock_lock(fd_lock);

    CHECK_PARAM(i2c_read(HMD_BUS, HMD_SLAVE_ADDRESS, HMD_DATAL_REG, 
                 I2C_SMBUS_WORD_DATA, humidity, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_humidity(): i2c_read()", LOG_LOCAL0);

    *humidity = (*humidity / 16);

    CHECK_PARAM(*humidity < 0x180 || *humidity > 0x7C0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_humidity(): humidity out of range", LOG_LOCAL0);

    filelock_close(fd_lock);

    return 0;
}

int hmd_get_temperature(int *temperature)
{
    int config_reg = 0;
    int ready = 1;


#ifdef TESTING
    CHECK_PARAM(hmd_get_configuration_mock(&config_reg) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_temperature(): hmd_get_configuration()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_get_configuration(&config_reg) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_temperature(): hmd_get_configuration()", LOG_LOCAL0);
#endif        

    CHECK_PARAM(set_bit((unsigned int*)&config_reg, HMD_TEMP_BIT) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_temperature(): set_bit(HMD_TEMP_BIT)", LOG_LOCAL0);

    CHECK_PARAM(set_bit((unsigned int*)&config_reg, HMD_START_BIT) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_temperature(): set_bit(HMD_START_BIT)", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(hmd_set_configuration_mock(config_reg) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_temperature(): hmd_set_configuration()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_set_configuration(0x11) < 0, LOG_ERR, TAG_HMD,
        "Error in hmd_get_temperature(): hmd_set_configuration()", LOG_LOCAL0);
#endif

#ifdef TESTING
    CHECK_PARAM(hmd_is_conversion_ready_mock(&ready) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_temperature(): hmd_is_conversion_ready(1)", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_is_conversion_ready(&ready) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_temperature(): hmd_is_conversion_ready(1)", LOG_LOCAL0);
#endif

    while (ready) {
        sleep(5);

#ifdef TESTING
        CHECK_PARAM(hmd_is_conversion_ready_mock(&ready) < 0, LOG_ERR, TAG_HMD, 
            "Error in hmd_get_temperature(): hmd_is_conversion_ready(2)", LOG_LOCAL0);
#else
        CHECK_PARAM(hmd_is_conversion_ready(&ready) < 0, LOG_ERR, TAG_HMD, 
            "Error in hmd_get_temperature(): hmd_is_conversion_ready(2)", LOG_LOCAL0);
#endif
    }

	int fd_lock;
	fd_lock = filelock_open("hdm_lock");
	filelock_lock(fd_lock);

    CHECK_PARAM(i2c_read(HMD_BUS, HMD_SLAVE_ADDRESS, HMD_DATAL_REG, 
                 I2C_SMBUS_WORD_DATA, temperature, 0) < 0, LOG_ERR, TAG_HMD,
        "Error in hmd_get_temperature(): i2c_read()", LOG_LOCAL0);

	filelock_close(fd_lock);

    *temperature = (*temperature / 4);

    if(*temperature < 320 || *temperature > 4800)
    {
    	*temperature = 2240;
    }

    CHECK_PARAM(*temperature < 320 || *temperature > 4800, LOG_ERR, TAG_HMD,
        "Error in hmd_get_temperature(): temperature out of range", LOG_LOCAL0);

    *temperature = ((*temperature / 32) - 50);

    return 0;
}

int hmd_get_temp_status(int *temp_status)
{
#ifdef TESTING
    CHECK_PARAM(hmd_get_configuration_bit_status_mock(HMD_TEMP_BIT, temp_status) < 0, 
        LOG_ERR, TAG_HMD, "Error in hmd_get_temp_status(): hmd_get_configuration_bit_status", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_get_configuration_bit_status(HMD_TEMP_BIT, temp_status) < 0, 
        LOG_ERR, TAG_HMD, "Error in hmd_get_temp_status(): hmd_get_configuration_bit_status", LOG_LOCAL0);
#endif

    return 0;
}

int hmd_get_start_status(int *start_status)
{
#ifdef TESTING
    CHECK_PARAM(hmd_get_configuration_bit_status_mock(HMD_START_BIT, start_status) < 0, 
        LOG_ERR, TAG_HMD, "Error in hmd_get_start_status(): hmd_get_configuration_bit_status", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_get_configuration_bit_status(HMD_START_BIT, start_status) < 0, 
        LOG_ERR, TAG_HMD, "Error in hmd_get_start_status(): hmd_get_configuration_bit_status", LOG_LOCAL0);
#endif

    return 0;
}

int hmd_convert_to_relative_humidity(int humidity)
{
    return (humidity/16)-24;
}

int hmd_apply_linearization(int relative_humidity)
{
    return relative_humidity 
            - (relative_humidity * relative_humidity * HMD_LIN_COEFF_A2 
            + relative_humidity * HMD_LIN_COEFF_A1 + HMD_LIN_COEFF_A0);
}

int hmd_apply_temp_compensation(int linear_humidity, int temperature)
{
    return linear_humidity + (temperature - 30) * (linear_humidity * 
        HMD_COMP_COEFF_Q1 + HMD_COMP_COEFF_Q0);
}

int hmd_set_configuration(int new_config_reg_value)
{
    CHECK_PARAM(new_config_reg_value > 0xFF || new_config_reg_value < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_configuration(): new_config_reg_value out of range", LOG_LOCAL0);

	int fd_lock;
	fd_lock = filelock_open("hdm_lock");
	filelock_lock(fd_lock);

    CHECK_PARAM(i2c_write(HMD_BUS, HMD_SLAVE_ADDRESS, HMD_CONFIG_REG, 
                  I2C_SMBUS_BYTE_DATA, &new_config_reg_value, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_configuration(): i2c_write()", LOG_LOCAL0);

    filelock_close(fd_lock);

    return 0;
}

int hmd_get_configuration(int *conf_reg)
{
	int fd_lock;
	fd_lock = filelock_open("hdm_lock");
	filelock_lock(fd_lock);

    CHECK_PARAM(i2c_read(HMD_BUS, HMD_SLAVE_ADDRESS, HMD_CONFIG_REG, 
                 I2C_SMBUS_BYTE_DATA, conf_reg, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_configuration(): i2c_read()", LOG_LOCAL0);

    filelock_close(fd_lock);

    *conf_reg = (HMD_CONFIG_REG_RSVD_MASK & *conf_reg);
    return 0;
}

int hmd_enable_heater(void)
{
#ifdef TESTING
    CHECK_PARAM(hmd_set_configuration_bit_mock(HMD_HEAT_BIT, 1) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_enable_heater(): hmd_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_set_configuration_bit(HMD_HEAT_BIT, 1) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_enable_heater(): hmd_set_configuration_bit()", LOG_LOCAL0);
#endif  

    return 0;
}

int hmd_disable_heater(void)
{
#ifdef TESTING
    CHECK_PARAM(hmd_set_configuration_bit_mock(HMD_HEAT_BIT, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_disable_heater(): hmd_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_set_configuration_bit(HMD_HEAT_BIT, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_disable_heater(): hmd_set_configuration_bit()", LOG_LOCAL0);
#endif  

    return 0;
}

int hmd_get_heater_status(int *heater_status)
{
#ifdef TESTING
    CHECK_PARAM(hmd_get_configuration_bit_status_mock(HMD_HEAT_BIT, heater_status) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_heater_status(): hmd_get_configuration_bit_status()", LOG_LOCAL0;
#else
    CHECK_PARAM(hmd_get_configuration_bit_status(HMD_HEAT_BIT, heater_status) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_heater_status(): hmd_get_configuration_bit_status()", LOG_LOCAL0);
#endif

    return 0;
}

int hmd_enable_fast_conversion(void)
{
#ifdef TESTING
    CHECK_PARAM(hmd_set_configuration_bit_mock(HMD_FAST_BIT, 1) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_enable_fast_conversion(): hmd_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_set_configuration_bit(HMD_FAST_BIT, 1) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_enable_fast_conversion(): hmd_set_configuration_bit()", LOG_LOCAL0);
#endif

    return 0;
}

int hmd_disable_fast_conversion(void)
{
#ifdef TESTING
    CHECK_PARAM(hmd_set_configuration_bit_mock(HMD_FAST_BIT, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_disable_fast_conversion(): hmd_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_set_configuration_bit(HMD_FAST_BIT, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_disable_fast_conversion(): hmd_set_configuration_bit()", LOG_LOCAL0);
#endif
    
    return 0;
}

int hmd_get_fast_conversion_status(int *fast_conv_status)
{
#ifdef TESTING
    CHECK_PARAM(hmd_get_configuration_bit_status_mock(HMD_FAST_BIT, fast_conv_status) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_fast_conversion_status(): hmd_get_configuration_bit_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_get_configuration_bit_status(HMD_FAST_BIT, fast_conv_status) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_fast_conversion_status(): hmd_get_configuration_bit_status()", LOG_LOCAL0);
#endif

    return 0;
}

int hmd_is_conversion_ready(int *conv_ready)
{
#ifdef TESTING
    CHECK_PARAM(hmd_get_only_one_bit_of_register_mock(HMD_STATUS_REG, 
            HMD_READY_BIT, 0, conv_ready) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_is_conversion_ready(): hmd_get_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_get_only_one_bit_of_register(HMD_STATUS_REG, 
            HMD_READY_BIT, 0, conv_ready) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_is_conversion_ready(): hmd_get_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;
}

int hmd_get_id(int *id_status)
{
	int fd_lock;
	fd_lock = filelock_open("hdm_lock");
	filelock_lock(fd_lock);

    CHECK_PARAM(i2c_read(HMD_BUS, HMD_SLAVE_ADDRESS, 
                 HMD_ID_REG, I2C_SMBUS_BYTE_DATA, id_status, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_id(): i2c_read()", LOG_LOCAL0);

   	filelock_close(fd_lock);

    return 0;
}

int hmd_enable_chip_select(void)
{
    CHECK_PARAM( gpio_write_bit(HMD_CHIP_SELECT, HMD_ENABLED) < 0, 
        LOG_ERR, TAG_HMD, "Error in hmd_enable_chip_select(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int hmd_disable_chip_select(void)
{
    CHECK_PARAM( gpio_write_bit(HMD_CHIP_SELECT, HMD_DISABLED) < 0, 
        LOG_ERR, TAG_HMD, "Error in hmd_disable_chip_select(): gpio_write_bit()", LOG_LOCAL0);

    return 0;
}

int hmd_set_only_one_bit_of_register(int register_address, 
    int bits_reserved_mask, int bit_position, int new_bit_value)
{
    CHECK_PARAM(register_address < HMD_STATUS_REG 
            || register_address > HMD_CONFIG_REG, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_only_one_bit_of_register(): register_address value out of range", LOG_LOCAL0);

    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_only_one_bit_of_register(): bit_position value out of range", LOG_LOCAL0);

    CHECK_PARAM(new_bit_value < 0 || new_bit_value > 1, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_only_one_bit_of_register(): bit_value value out of range", LOG_LOCAL0);

    int reg_value = 0;

	int fd_lock;
	fd_lock = filelock_open("hdm_lock");
	filelock_lock(fd_lock);

    CHECK_PARAM(i2c_read(HMD_BUS, HMD_SLAVE_ADDRESS, register_address, 
                 I2C_SMBUS_BYTE_DATA, &reg_value, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_only_one_bit_of_register(): i2c_read()", LOG_LOCAL0);

    reg_value = bits_reserved_mask & reg_value;

    CHECK_PARAM(set_bit_val((unsigned int*)&reg_value, bit_position, new_bit_value) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_only_one_bit_of_register(): set_bit_val()", LOG_LOCAL0);

    CHECK_PARAM(i2c_write(HMD_BUS, HMD_SLAVE_ADDRESS, register_address, 
                  I2C_SMBUS_BYTE_DATA, &reg_value, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_only_one_bit_of_register(): i2c_write()", LOG_LOCAL0);

    filelock_close(fd_lock);

    return 0;
}

int hmd_get_only_one_bit_of_register(int register_address, 
    int bits_reserved_mask, int bit_position, int *bit_status)
{
    CHECK_PARAM(register_address < HMD_STATUS_REG 
            || register_address > HMD_CONFIG_REG, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_only_one_bit_of_register(): register_address value out of range", LOG_LOCAL0);

    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_only_one_bit_of_register(): bit_position value out of range", LOG_LOCAL0);

    int reg_value = 0;

	int fd_lock;
	fd_lock = filelock_open("hdm_lock");
	filelock_lock(fd_lock);

    CHECK_PARAM(i2c_read(HMD_BUS, HMD_SLAVE_ADDRESS, register_address, 
                 I2C_SMBUS_BYTE_DATA, &reg_value, 0) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_only_one_bit_of_register(): i2c_read()", LOG_LOCAL0);

	filelock_close(fd_lock);

    reg_value = bits_reserved_mask & reg_value;

    CHECK_PARAM(get_bit(reg_value, bit_position, (unsigned int*)bit_status) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_only_one_bit_of_register(): get_bit()", LOG_LOCAL0);

    return 0; 
}

int hmd_set_configuration_bit(int bit_position, int new_bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_configuration_bit(): bit_position value out of range", LOG_LOCAL0);

    CHECK_PARAM(new_bit_value < 0 || new_bit_value > 1, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_configuration_bit(): new_bit_value value out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(hmd_set_only_one_bit_of_register_mock(HMD_CONFIG_REG, 
            HMD_CONFIG_REG_RSVD_MASK, bit_position, new_bit_value) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_configuration_bit(): hmd_set_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_set_only_one_bit_of_register(HMD_CONFIG_REG, 
            HMD_CONFIG_REG_RSVD_MASK, bit_position, new_bit_value) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_set_configuration_bit(): hmd_set_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;
}

int hmd_get_configuration_bit_status(int bit_position, int *bit_status)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_configuration_bit_status(): bit_position value out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(hmd_get_only_one_bit_of_register_mock(HMD_CONFIG_REG, 
            HMD_CONFIG_REG_RSVD_MASK, bit_position, bit_status) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_configuration_bit_status(): hmd_get_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(hmd_get_only_one_bit_of_register(HMD_CONFIG_REG, 
            HMD_CONFIG_REG_RSVD_MASK, bit_position, bit_status) < 0, LOG_ERR, TAG_HMD, 
        "Error in hmd_get_configuration_bit_status(): hmd_get_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;
}
