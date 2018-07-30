#include "tmp.h"
#include "../i2c/i2crw.h"
#include "../gpio/gpio.h"
#include "../bitman/bitman.h"
#include "../util/util.h"
//#include <filelock.h>
#include "../utils/filelock.h"

int tmp_get_ext_temp(int temp_main_bits_reg, float *celsius_temp)
{
    int main_bits;
    int extended_bits;

    CHECK_PARAM((temp_main_bits_reg < TMP_REMOTE_1_REG) || (temp_main_bits_reg > TMP_REMOTE_7_REG), LOG_ERR, TAG_TMP,
    		"Error in tmp_get_ext_temp(): channel out of range", LOG_LOCAL0);

	tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, temp_main_bits_reg, &main_bits,
			  "Error in tmp_get_ext_temp(): i2c_read(1)");
    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS,  temp_main_bits_reg|0x50, &extended_bits,
			  "Error in tmp_get_ext_temp(): i2c_read(2)");

    extended_bits &= TMP_EXTENDED_BITS_REG_RSVD_MASK;     

    if (main_bits > 0xff)
    {
        *celsius_temp = 191.0;
        LOG_AND_EXIT(LOG_ERR, TAG_TMP, "Error in tmp_get_ext_temp(): main bits out of range", LOG_LOCAL0);
    }
    
    if (extended_bits > 0xff)
    {
        *celsius_temp = 0.875;
        LOG_AND_EXIT(LOG_ERR, TAG_TMP, "Error in tmp_get_ext_temp(): extended bits out of range", LOG_LOCAL0);
    }

    *celsius_temp = main_bits + ((extended_bits >> 5) & 0x7) * 0.125;

    return 0;
}

int tmp_get_temp_main_bits_reg(int temp_main_bits_reg, int *reg_value)
{
    CHECK_PARAM((temp_main_bits_reg < TMP_REMOTE_1_REG) 
            || (temp_main_bits_reg > TMP_REMOTE_7_REG), LOG_ERR, TAG_TMP, 
        "Error in tmp_get_temp_main_bits_reg(): channel out of range", LOG_LOCAL0);

    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS,  temp_main_bits_reg, reg_value,
    		"Error in tmp_get_temp_main_bits_reg(): i2c_read()");

	return 0;
}

int tmp_temp_reg_to_celsius(int main_bits, int *celsius_temp)
{
    if (main_bits > 0xfe)
    {
        *celsius_temp = 254;
        LOG_AND_EXIT(LOG_ERR, TAG_TMP, 
            "Error in tmp_temp_reg_to_celsius(): main bits out of range", LOG_LOCAL0);
    } 
    else if (main_bits < 0)
    {
        *celsius_temp = 0;
        LOG_AND_EXIT(LOG_ERR, TAG_TMP, 
            "Error in tmp_temp_reg_to_celsius(): main bits out of range", LOG_LOCAL0);
    }

    *celsius_temp = main_bits;
    return 0;
}

int tmp_celsius_to_temp_reg(int temperature, int *temp_reg)
{
    if (temperature > 254)
    {       
        *temp_reg = 0xfe;
        LOG_AND_EXIT(LOG_ERR, TAG_TMP, 
            "Error in tmp_celsius_to_temp_reg(): over temperature", LOG_LOCAL0);
    } 
    else if (temperature < 0) 
    {
        *temp_reg = 0x00;
        LOG_AND_EXIT(LOG_ERR, TAG_TMP, 
            "Error in tmp_celsius_to_temp_reg(): under temperature", LOG_LOCAL0);
    }

    *temp_reg = temperature; 
    return 0;
}

int tmp_ext_temp_regs_to_celsius(int main_bits, int extended_bits, 
            float *celsius_temp)
{
    if (main_bits > 0xff)
    {
        *celsius_temp = 191.0;
        LOG_AND_EXIT(LOG_ERR, TAG_TMP, 
            "Error in tmp_ext_temp_regs_to_celsius(): main bits out of range", LOG_LOCAL0);
    }
    
    if (extended_bits > 0xff)
    {
        *celsius_temp = 0.875;
        LOG_AND_EXIT(LOG_ERR, TAG_TMP, 
            "Error in tmp_ext_temp_regs_to_celsius(): extended bits out of range", LOG_LOCAL0);
    }

    *celsius_temp = -64 + main_bits + (extended_bits >> 5) * 0.125;
    return 0;
}

int tmp_celsius_to_ext_temp_regs(float temperature, temp_registers_t *temp_regs)
{
    if (temperature > 191.875) 
    {
        temp_regs->main_bits = 0xff;
        temp_regs->extended_bits = 0xe0;
        LOG_AND_EXIT(LOG_ERR, TAG_TMP, 
            "Error in tmp_celsius_to_ext_temp_regs(): over temperature", LOG_LOCAL0);
    } 
    else if (temperature < -64.875)
    {
        temp_regs->main_bits = 0x00;
        temp_regs->extended_bits = 0xe0;
        LOG_AND_EXIT(LOG_ERR, TAG_TMP, 
            "Error in tmp_celsius_to_ext_temp_regs(): over temperature", LOG_LOCAL0);
        return -1;
    }

    int decimal, fractional;
    temperature += 64;
    decimal = (int) temperature;
    fractional = (int)((temperature - decimal) / 0.125) << 5;

    temp_regs->main_bits = decimal;
    temp_regs->extended_bits = fractional;  
    return 0;
}

int tmp_get_manufacturer_id(int *manufacturer_id)
{
    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, TMP_MANUFACTURER_ID_REG, manufacturer_id,
    		"Error in tmp_get_manufacturer_id(): i2c_read()");
    return 0;
}

int tmp_get_revision_id(int *revision_id)
{
    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, TMP_REVISION_ID_REG, revision_id,
    		"Error in tmp_get_revision_id(): i2c_read()");
    return 0;
}

int tmp_get_alert_high_limit_reg(int alert_high_limit_reg, int *reg_value)
{
    CHECK_PARAM(alert_high_limit_reg < TMP_REMOTE_1_ALERT_HIGH_LIMIT_REG 
            || alert_high_limit_reg > TMP_REMOTE_7_ALERT_HIGH_LIMIT_REG, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_alert_high_limit_reg(): Alert High Limit Out of range", LOG_LOCAL0);

    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, alert_high_limit_reg, reg_value,
    		"Error in tmp_get_alert_high_limit_reg(): i2c_read()");

    return 0;
}

int tmp_set_alert_high_limit_reg(int alert_high_limit_reg, int reg_value)
{
    CHECK_PARAM(alert_high_limit_reg < TMP_REMOTE_1_ALERT_HIGH_LIMIT_REG 
            || alert_high_limit_reg > TMP_REMOTE_7_ALERT_HIGH_LIMIT_REG, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_alert_high_limit_reg(): Alert High Limit Out of range", LOG_LOCAL0);

    CHECK_PARAM(reg_value > 0xFF || reg_value < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_alert_high_limit_reg(): Limit out of range", LOG_LOCAL0);
    
    tmp_write_i2c_bus(TMP_SLAVE_ADDRESS, alert_high_limit_reg, &reg_value,
    		"Error in tmp_set_alert_high_limit_reg(): i2c_write()");


	return 0;
}

int tmp_get_overt_high_limit_reg(int overt_high_limit_reg, int *reg_value)
{
    CHECK_PARAM(overt_high_limit_reg < TMP_LOCAL_OVERT_HIGH_LIMIT_REG
            || overt_high_limit_reg > TMP_REMOTE_7_OVERT_HIGH_LIMIT_REG, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_overt_high_limit_reg(): Channel out of range", LOG_LOCAL0);

    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, overt_high_limit_reg, reg_value,
    		 "Error in tmp_get_overt_high_limit_reg(): i2c_read()");
	return 0;
}

int tmp_set_overt_high_limit_reg(int overt_high_limit_reg, int reg_value)
{
    CHECK_PARAM(overt_high_limit_reg < TMP_LOCAL_OVERT_HIGH_LIMIT_REG
            || overt_high_limit_reg > TMP_REMOTE_7_OVERT_HIGH_LIMIT_REG, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_overt_high_limit_reg(): Channel out of range", LOG_LOCAL0);

    CHECK_PARAM(reg_value > 0xFF || reg_value < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_overt_high_limit_reg(): Limit out of range", LOG_LOCAL0);

    tmp_write_i2c_bus(TMP_SLAVE_ADDRESS, overt_high_limit_reg, &reg_value,
    		"Error in tmp_set_overt_high_limit_reg(): i2c_write()");

   return 0;
}

int tmp_get_alert_low_limit_reg(int *alert_low_limit_value)
{
    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, TMP_ALERT_LOW_LIMITS_REG, alert_low_limit_value,
    		"Error in tmp_get_alert_low_limit_reg(): i2c_read()");
    return 0;
}

int tmp_set_alert_low_limit_reg(int alert_low_limit_value)
{
    CHECK_PARAM(alert_low_limit_value > 0xFF || alert_low_limit_value < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_alert_low_limit_reg(): Low Limit out of range", LOG_LOCAL0);

    tmp_write_i2c_bus(TMP_SLAVE_ADDRESS, TMP_ALERT_LOW_LIMITS_REG, &alert_low_limit_value,
    		"Error in tmp_set_alert_low_limit_reg(): i2c_write()");

    return 0;
}

/*
int tmp_write_one_bit(int bit_position, int bit_value, int *current_value)
{
    CHECK_PARAM(bit_position > 31 || bit_position < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_write_one_bit(): bit_position is out of range");

    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_TMP, 
        "Error in tmp_write_one_bit(): bit_value value out of range");

    int one = 1;
    one = one << bit_position;
    int cero = ~one & 0xFFFF;
    *current_value &= cero;
    *current_value |= (bit_value << bit_position);    
    return 0;
}*/
/*
int tmp_read_one_bit(int bit_position, int *current_value)
{
    CHECK_PARAM(bit_position > 31 || bit_position < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_read_one_bit(): bit_position is out of range");
  
    *current_value = (*current_value >> bit_position) & 0x01;
    return 0;
}*/

int tmp_set_only_one_bit_of_register(int register_address, 
            int bits_reserved_mask, int bit_position, int bit_value)
{
    int reg_value = 0;
   
    CHECK_PARAM(register_address < TMP_REMOTE_1_REG 
            || register_address > TMP_REMOTE_7_EXTENDED_BITS_REG, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_only_one_bit_of_register(): register_address value out of range", LOG_LOCAL0);

    CHECK_PARAM(bit_position > 31 || bit_position < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_only_one_bit_of_register(): bit_position is out of range", LOG_LOCAL0);
    
    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_only_one_bit_of_register(): bit_value value out of range", LOG_LOCAL0);

    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, register_address, &reg_value,
    		"Error in tmp_set_only_one_bit_of_register(): i2c_read()");
    
    reg_value &= bits_reserved_mask;

    if(bit_value==0)
        CHECK_PARAM(clear_bit(&reg_value,bit_position) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_only_one_bit_of_register(): clear_bit()", LOG_LOCAL0);
    else
        CHECK_PARAM(set_bit(&reg_value,bit_position) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_only_one_bit_of_register(): clear_bit()", LOG_LOCAL0);
        
/*
#ifdef TESTING
    CHECK_PARAM(tmp_write_one_bit_mock(bit_position, bit_value, &reg_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_only_one_bit_of_register(): tmp_write_one_bit()");
#else
    CHECK_PARAM(tmp_write_one_bit(bit_position, bit_value, &reg_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_only_one_bit_of_register(): tmp_write_one_bit()");
#endif
*/
    CHECK_PARAM(i2c_write(TMP_BUS, TMP_SLAVE_ADDRESS, register_address,
            I2C_SMBUS_BYTE_DATA,&reg_value, 0) < 0, LOG_ERR, TAG_TMP,
        "Error in tmp_set_only_one_bit_of_register(): i2c_write()", LOG_LOCAL0);


    return 0;
}

int tmp_get_only_one_bit_of_register(int register_address, 
            int bits_reserved_mask, int bit_position, int *bit_value)
{   
    CHECK_PARAM(register_address < TMP_REMOTE_1_REG 
            || register_address > TMP_REMOTE_7_EXTENDED_BITS_REG, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_only_one_bit_of_register(): register_address value out of range", LOG_LOCAL0);

    CHECK_PARAM(bit_position > 31 || bit_position < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_only_one_bit_of_register(): bit_position is out of range", LOG_LOCAL0);

    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, register_address, bit_value,
    		 "Error in tmp_get_only_one_bit_of_register(): i2c_read()");

    *bit_value &= bits_reserved_mask;
    
    CHECK_PARAM(get_bit((unsigned int)bit_value,(unsigned int)bit_position,
        (unsigned int*)&bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_only_one_bit_of_register(): get_bit()", LOG_LOCAL0);
    
/*    
#ifdef TESTING
    CHECK_PARAM(tmp_read_one_bit_mock(bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_only_one_bit_of_register(): tmp_read_one_bit()");
#else
    CHECK_PARAM(tmp_read_one_bit(bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_only_one_bit_of_register(): tmp_read_one_bit()");
#endif
*/
    return 0;
}

int tmp_set_configuration_bit(int bit_position, int bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_configuration_bit(): bit_position is out of range", LOG_LOCAL0);
    
    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_configuration_bit(): bit_value is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_set_only_one_bit_of_register_mock(TMP_CONFIGURATION_REG, 
            TMP_CONFIGURATION_REG_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_configuration_bit(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_only_one_bit_of_register(TMP_CONFIGURATION_REG, 
            TMP_CONFIGURATION_REG_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_configuration_bit(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;      
}

int tmp_get_configuration_bit_status(int bit_position, int *bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_configuration_bit_status(): bit_position is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_get_only_one_bit_of_register_mock(TMP_CONFIGURATION_REG, 
            TMP_CONFIGURATION_REG_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_configuration_bit_status(): tmp_get_only_one_bit_of_register", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_get_only_one_bit_of_register(TMP_CONFIGURATION_REG, 
            TMP_CONFIGURATION_REG_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_configuration_bit_status(): tmp_get_only_one_bit_of_register", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_enable_stop()
{
#ifdef TESTING
    CHECK_PARAM(tmp_set_configuration_bit_mock(TMP_STOP_BIT, 1) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_enable_stop(): tmp_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_configuration_bit(TMP_STOP_BIT, 1) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_enable_stop(): tmp_set_configuration_bit()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_disable_stop()
{
#ifdef TESTING
    CHECK_PARAM(tmp_set_configuration_bit_mock(TMP_STOP_BIT, 0) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_disable_stop(): tmp_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_configuration_bit(TMP_STOP_BIT, 0) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_disable_stop(): tmp_set_configuration_bit()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_get_stop_status(int *stop_value)
{
#ifdef TESTING
    CHECK_PARAM(tmp_get_configuration_bit_status_mock(TMP_STOP_BIT, stop_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_stop_status(): tmp_get_configuration_bit_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_get_configuration_bit_status(TMP_STOP_BIT, stop_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_stop_status(): tmp_get_configuration_bit_status()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_reset_device()
{
#ifdef TESTING
    CHECK_PARAM(tmp_set_configuration_bit_mock(TMP_POR_BIT, 1) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_reset_device(): tmp_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_configuration_bit(TMP_POR_BIT, 1) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_reset_device(): tmp_set_configuration_bit()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_enable_timeout()
{
#ifdef TESTING
    CHECK_PARAM(tmp_set_configuration_bit_mock(TMP_TIMEOUT_BIT, 0) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_enable_timeout(): tmp_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_configuration_bit(TMP_TIMEOUT_BIT, 0) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_enable_timeout(): tmp_set_configuration_bit()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_disable_timeout()
{
#ifdef TESTING
    CHECK_PARAM(tmp_set_configuration_bit_mock(TMP_TIMEOUT_BIT, 0) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_disable_timeout(): tmp_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_configuration_bit(TMP_TIMEOUT_BIT, 0) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_disable_timeout(): tmp_set_configuration_bit()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_get_timeout_status(int *timeout_value)
{
#ifdef TESTING
    CHECK_PARAM(tmp_get_configuration_bit_status_mock(TMP_TIMEOUT_BIT, timeout_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_timeout_status(): tmp_get_configuration_bit_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_get_configuration_bit_status(TMP_TIMEOUT_BIT, timeout_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_timeout_status(): tmp_get_configuration_bit_status()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_enable_extrange()
{
#ifdef TESTING
    CHECK_PARAM(tmp_set_configuration_bit_mock(TMP_EXTRANGE_BIT, 1) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_enable_extrange(): tmp_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_configuration_bit(TMP_EXTRANGE_BIT, 1) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_enable_extrange(): tmp_set_configuration_bit()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_disable_extrange()
{
#ifdef TESTING
    CHECK_PARAM(tmp_set_configuration_bit_mock(TMP_EXTRANGE_BIT, 0) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_disable_extrange(): tmp_set_configuration_bit()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_configuration_bit(TMP_EXTRANGE_BIT, 0) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_disable_extrange(): tmp_set_configuration_bit()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_get_extrange_status(int *extrange_value)
{
#ifdef TESTING
    CHECK_PARAM(tmp_get_configuration_bit_status_mock(TMP_EXTRANGE_BIT, extrange_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_extrange_status(): tmp_get_configuration_bit_status()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_get_configuration_bit_status(TMP_EXTRANGE_BIT, extrange_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_extrange_status(): tmp_get_configuration_bit_status()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_set_mask_alert(int bit_position, int bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_mask_alert(): bit_position is out of range", LOG_LOCAL0);
    
    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_mask_alert(): bit_value is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_set_only_one_bit_of_register_mock(TMP_ALERT_MASK_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_mask_alert(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_only_one_bit_of_register(TMP_ALERT_MASK_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_mask_alert(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_get_mask_alert_status(int bit_position, int *bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_mask_alert_status(): bit_position is out of range", LOG_LOCAL0);
   
#ifdef TESTING
    CHECK_PARAM(tmp_get_only_one_bit_of_register_mock(TMP_ALERT_MASK_REG, 
        TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_mask_alert_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_get_only_one_bit_of_register(TMP_ALERT_MASK_REG, 
        TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_mask_alert_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_set_mask_overt(int bit_position, int bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_mask_overt(): bit_position is out of range", LOG_LOCAL0);
    
    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_mask_overt(): bit_value is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_set_only_one_bit_of_register_mock(TMP_OVERT_MASK_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_mask_overt(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_only_one_bit_of_register(TMP_OVERT_MASK_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_mask_overt(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_get_mask_overt_status(int bit_position, int *bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_overt_mask_status(): bit_position is out of range", LOG_LOCAL0);
 
#ifdef TESTING
    CHECK_PARAM(tmp_get_only_one_bit_of_register_mock(TMP_OVERT_MASK_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_overt_mask_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_get_only_one_bit_of_register(TMP_OVERT_MASK_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_overt_mask_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_get_alert_high_status_reg(int *alert_high_status_value)
{
    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, TMP_ALERT_HIGH_STATUS_REG, alert_high_status_value,
    		 "Error in tmp_get_alert_high_status_reg(): i2c_read()");
   	return 0;
}

int tmp_get_overt_status_reg(int *overt_status_value)
{
    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, TMP_OVERT_STATUS_REG, overt_status_value,
    		"Error in tmp_get_overt_status_reg(): i2c_read()");
    return 0;
}

int tmp_get_overt_status_pin(unsigned int *overt_status_value)
{
    CHECK_PARAM(gpio_read_bit(TMP_OVERT_PIN,overt_status_value)< 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_overt_status_pin(): gpio_read_bit()", LOG_LOCAL0);

    return 0;
}

int tmp_get_alert_status_pin(unsigned int *alert_status_value)
{
    CHECK_PARAM(gpio_read_bit(TMP_ALERT_PIN,alert_status_value)< 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_alert_status_pin(): gpio_read_bit()", LOG_LOCAL0);

    return 0;
}


int tmp_get_diode_fault_status_reg(int *diode_fault_status_value)
{
    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, TMP_DIODE_FAULT_STATUS_REG, diode_fault_status_value,
    		"Error in tmp_get_diode_fault_status_reg(): i2c_read()");
    return 0;
}

int tmp_get_alert_low_status_reg(int *alert_low_status_value)
{
    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, TMP_ALERT_LOW_STATUS_REG, alert_low_status_value,
    		"Error in temp_get_alert_low_status_reg(): i2c_read()");
	return 0;
}

int tmp_set_alert_low_disable_bit(int bit_position, int bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_alert_low_disable_bit(): bit_position is out of range", LOG_LOCAL0);
    
    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_alert_low_disable_bit(): bit_value is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_set_only_one_bit_of_register_mock(TMP_ALERT_LOW_DISABLE_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_alert_low_disable_bit(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_only_one_bit_of_register(TMP_ALERT_LOW_DISABLE_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_alert_low_disable_bit(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#endif

	return 0;
}

int tmp_get_alert_low_disable_bit_status(int bit_position, int *bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_alert_low_disable_bit_status(): bit_position is out of range", LOG_LOCAL0);
    
#ifdef TESTING
    CHECK_PARAM(tmp_get_only_one_bit_of_register_mock(TMP_ALERT_LOW_DISABLE_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_alert_low_disable_bit_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_get_only_one_bit_of_register(TMP_ALERT_LOW_DISABLE_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_alert_low_disable_bit_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#endif

	return 0;
}

int tmp_set_resistance_cancellation_bit(int bit_position, int bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_resistance_cancellation_bit(): bit_position is out of range", LOG_LOCAL0);
    
    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_resistance_cancellation_bit(): bit_value is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_set_only_one_bit_of_register_mock(TMP_RESISTANCE_CANCELLATION_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_resistance_cancellation_bit(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_only_one_bit_of_register(TMP_RESISTANCE_CANCELLATION_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_resistance_cancellation_bit(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;
    
}

int tmp_get_resistance_cancellation_bit_status(int bit_position, int *bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_resistance_cancellation_bit_status(): bit_position is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_get_only_one_bit_of_register_mock(TMP_RESISTANCE_CANCELLATION_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_resistance_cancellation_bit_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_get_only_one_bit_of_register(TMP_RESISTANCE_CANCELLATION_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_resistance_cancellation_bit_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;    
}

int tmp_get_transistor_ideality_reg(int *transistor_ideality_value)
{
    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, TMP_TRANSISTOR_IDEALITY_REG, transistor_ideality_value,
    		"Error in tmp_get_transistor_ideality_reg(): i2c_read()");

    *transistor_ideality_value &= TMP_TRANSISTOR_IDEALITY_REG_RSVD_MASK;
    return 0;
}

int tmp_set_transistor_ideality_reg(int ideality_value)
{
    CHECK_PARAM(ideality_value > 0x1f || ideality_value < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_transistor_ideality_reg(): ideality_value out of range", LOG_LOCAL0);

    tmp_write_i2c_bus(TMP_SLAVE_ADDRESS, TMP_TRANSISTOR_IDEALITY_REG, &ideality_value,
    		"Error in tmp_set_transistor_ideality_reg(): i2c_write()");

    return 0;
}

int tmp_set_ideality_select_bit(int bit_position, int bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_ideality_select_bit(): bit_position is out of range", LOG_LOCAL0);
    
    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_ideality_select_bit(): bit_value is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_set_only_one_bit_of_register_mock(TMP_IDEALITY_SELECT_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_ideality_select_bit(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_only_one_bit_of_register(TMP_IDEALITY_SELECT_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_ideality_select_bit(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_get_ideality_select_bit_status(int bit_position, int *bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_ideality_select_bit_status(): bit_position is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_get_only_one_bit_of_register_mock(TMP_IDEALITY_SELECT_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_ideality_select_bit_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_get_only_one_bit_of_register(TMP_IDEALITY_SELECT_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_ideality_select_bit_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#endif
    return 0;
}

int tmp_get_offset_reg(int *offset_value)
{
   tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, TMP_OFFSET_REG, offset_value,
      "Error in tmp_get_offset_reg(): i2c_read()");

    return 0;
}

int tmp_set_offset_reg(int offset_value)
{
    CHECK_PARAM(offset_value > 0xff || offset_value < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_offset_reg(): offset_value out of range", LOG_LOCAL0);

     tmp_write_i2c_bus(TMP_SLAVE_ADDRESS, TMP_OFFSET_REG, &offset_value,
    		"Error in tmp_set_offset_reg(): i2c_write()");

    return 0;
}

int tmp_set_offset_select_bit(int bit_position, int bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_offset_select_bit(): bit_position is out of range", LOG_LOCAL0);
    
    CHECK_PARAM(bit_value < 0 || bit_value > 1, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_offset_select_bit(): bit_value is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_set_only_one_bit_of_register_mock(TMP_OFFSET_SELECT_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_offset_select_bit(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_set_only_one_bit_of_register(TMP_OFFSET_SELECT_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_set_offset_select_bit(): tmp_set_only_one_bit_of_register()", LOG_LOCAL0);
#endif

    return 0;
}

int tmp_get_offset_select_bit_status(int bit_position, int *bit_value)
{
    CHECK_PARAM(bit_position < 0 || bit_position > 7, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_offset_select_bit_status(): bit_position is out of range", LOG_LOCAL0);

#ifdef TESTING
    CHECK_PARAM(tmp_get_only_one_bit_of_register_mock(TMP_OFFSET_SELECT_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_offset_select_bit_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#else
    CHECK_PARAM(tmp_get_only_one_bit_of_register(TMP_OFFSET_SELECT_REG, 
            TMP_UNRESERVED_BIT_MASK, bit_position, bit_value) < 0, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_offset_select_bit_status(): tmp_get_only_one_bit_of_register()", LOG_LOCAL0);
#endif
    return 0;
}

int tmp_get_extended_bits_reg(int extended_bits_reg, int *reg_value)
{
    CHECK_PARAM(extended_bits_reg < TMP_REMOTE_1_EXTENDED_BITS_REG 
        || extended_bits_reg > TMP_REMOTE_7_EXTENDED_BITS_REG, LOG_ERR, TAG_TMP, 
        "Error in tmp_get_extended_bits_reg(): extended_bits_reg value out of range", LOG_LOCAL0);

    tmp_read_i2c_bus(TMP_SLAVE_ADDRESS, extended_bits_reg, reg_value,
    		"Error in tmp_get_extended_bits_reg(): i2c_read()");

    *reg_value &= TMP_EXTENDED_BITS_REG_RSVD_MASK;     
    return 0; 
}

/*
 * Read to i2c tmp_bus. Safe Access (Mutual Exclusion)
 */
int tmp_read_i2c_bus(unsigned bus, int reg, int *reg_value, const char* error_msg)
{
	 int fd_lock;
	 fd_lock = filelock_open("tmp_lock");
	 filelock_lock(fd_lock);

	 CHECK_PARAM(i2c_read(TMP_BUS, bus, reg,
	            I2C_SMBUS_BYTE_DATA, reg_value,0) < 0, LOG_ERR, TAG_TMP,
	            error_msg, LOG_LOCAL0);

	 filelock_close(fd_lock);

	 return 0;
}

/*
 * Write to i2c tmp_bus. Safe Access (Mutual Exclusion)
 */
int tmp_write_i2c_bus(unsigned bus, int reg, int *reg_value, const char* error_msg)
{
	 int fd_lock;
	 fd_lock = filelock_open("tmp_lock");
	 filelock_lock(fd_lock);

	 CHECK_PARAM(i2c_write(TMP_BUS, bus, reg,
	            I2C_SMBUS_BYTE_DATA, reg_value,0) < 0, LOG_ERR, TAG_TMP,
	            error_msg, LOG_LOCAL0);

	 filelock_close(fd_lock);

	 return 0;
}
