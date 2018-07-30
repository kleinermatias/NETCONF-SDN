/**
 * \file
 * \brief TMP API header.
 * 
 */
#ifndef _TMP_H_
#define _TMP_H_

/**
 * I2C Module Address
 */
#define TMP_BUS 0x04 /* I2C_SENSORS */
/**
 * I2C Module Bus.
 */
#define TMP_SLAVE_ADDRESS 0x4D
/**
 * Remote Temperature 1 Register Address.
 */
#define TMP_REMOTE_1_REG 0x01
/**
 * Remote Temperature 2 Register Address.
 */
#define TMP_REMOTE_2_REG 0x02
/**
 * Remote Temperature 3 Register Address.
 */
#define TMP_REMOTE_3_REG 0x03
/**
 * Remote Temperature 4 Register Address.
 */
#define TMP_REMOTE_4_REG 0x04
/**
 * Remote Temperature 5 Register Address.
 */
#define TMP_REMOTE_5_REG 0x05
/**
 * Remote Temperature 6 Register Address.
 */
#define TMP_REMOTE_6_REG 0x06
/**
 * Local Temperature Register Address
 */
#define TMP_LOCAL_REG 0x07
/**
 * Remote Temperature 7 Register Address.
 */
#define TMP_REMOTE_7_REG 0x08
/**
 * Manufacturer ID Register Address.
 */
#define TMP_MANUFACTURER_ID_REG 0x0a
/**
 * Revision ID Register Address.
 */
#define TMP_REVISION_ID_REG 0x0f
/**
 * Remote 1 Alert High Limit Register Address.
 */
#define TMP_REMOTE_1_ALERT_HIGH_LIMIT_REG 0x11
/**
 * Remote 2 Alert High Limit Register Address.
 */
#define TMP_REMOTE_2_ALERT_HIGH_LIMIT_REG 0x12
/**
 * Remote 3 Alert High Limit Register Address.
 */
#define TMP_REMOTE_3_ALERT_HIGH_LIMIT_REG 0x13
/**
 * Remote 4 Alert High Limit Register Address.
 */
#define TMP_REMOTE_4_ALERT_HIGH_LIMIT_REG 0x14
/**
 * Remote 5 Alert High Limit Register Address.
 */
#define TMP_REMOTE_5_ALERT_HIGH_LIMIT_REG 0x15
/**
 * Remote 6 Alert High Limit Register Address.
 */
#define TMP_REMOTE_6_ALERT_HIGH_LIMIT_REG 0x16
/**
 * Local Alert High Limit Register Address.
 */
#define TMP_LOCAL_ALERT_HIGH_LIMIT_REG 0x17
/**
 * Remote 7 Alert High Limit Register Address.
 */
#define TMP_REMOTE_7_ALERT_HIGH_LIMIT_REG 0x18
/**
 * Local Overt High Limit Register Address.
 */
#define TMP_LOCAL_OVERT_HIGH_LIMIT_REG 0x20
/**
 * Remote 1 Overt High Limit Register Address.
 */
#define TMP_REMOTE_1_OVERT_HIGH_LIMIT_REG 0x21
/**
 * Remote 2 Overt High Limit Register Address.
 */
#define TMP_REMOTE_2_OVERT_HIGH_LIMIT_REG 0x22
/**
 * Remote 3 Overt High Limit Register Address.
 */
#define TMP_REMOTE_3_OVERT_HIGH_LIMIT_REG 0x23
/**
 * Remote 4 Overt High Limit Register Address.
 */
#define TMP_REMOTE_4_OVERT_HIGH_LIMIT_REG 0x24
/**
 * Remote 5 Overt High Limit Register Address.
 */
#define TMP_REMOTE_5_OVERT_HIGH_LIMIT_REG 0x25
/**
 * Remote 6 Overt High Limit Register Address.
 */
#define TMP_REMOTE_6_OVERT_HIGH_LIMIT_REG 0x26
/**
 * Remote 7 Overt High Limit Register Address.
 */
#define TMP_REMOTE_7_OVERT_HIGH_LIMIT_REG 0x27
/**
 * ALERT Low Limits (all channels) Register Address.
 */
#define TMP_ALERT_LOW_LIMITS_REG 0x30
/**
 * Configuration Register Address.
 */
#define TMP_CONFIGURATION_REG 0x41
/**
 * Alert Mask Register Address.
 */
#define TMP_ALERT_MASK_REG 0x42
/**
 * Overt Mask Register Address.
 */
#define TMP_OVERT_MASK_REG 0x43
/**
 * Alert High Status Register Address.
 */
#define TMP_ALERT_HIGH_STATUS_REG 0x44
/**
 * Overt Status Register Address.
 */
#define TMP_OVERT_STATUS_REG 0x45
/**
 * Diode Fault Register Address.
 */
#define TMP_DIODE_FAULT_STATUS_REG 0x46
/**
 * Alert Low Status Register Address.
 */
#define TMP_ALERT_LOW_STATUS_REG 0x47
/**
 * Alert Low Disable Register Address.
 */
#define TMP_ALERT_LOW_DISABLE_REG 0x48
/**
 * Resistance Cancellation Register Address.
 */
#define TMP_RESISTANCE_CANCELLATION_REG 0x4a
/**
 * Transistor Ideality Register Address.
 */
#define TMP_TRANSISTOR_IDEALITY_REG 0x4b
/**
 * Ideality Select Register Address.
 */
#define TMP_IDEALITY_SELECT_REG 0x4c
/**
 * Offset Register Address.
 */
#define TMP_OFFSET_REG 0x4d
/**
 * Offset Select Register Address.
 */
#define TMP_OFFSET_SELECT_REG 0x4e
/**
 * Remote 1 Extended Bits Register Address.
 */
#define TMP_REMOTE_1_EXTENDED_BITS_REG 0x51
/**
 * Remote 2 Extended Bits Register Address.
 */
#define TMP_REMOTE_2_EXTENDED_BITS_REG 0x52
/**
 * Remote 3 Extended Bits Register Address.
 */
#define TMP_REMOTE_3_EXTENDED_BITS_REG 0x53
/**
 * Remote 4 Extended Bits Register Address.
 */
 #define TMP_REMOTE_4_EXTENDED_BITS_REG 0x54
/**
 * Remote 5 Extended Bits Register Address.
 */
#define TMP_REMOTE_5_EXTENDED_BITS_REG 0x55
/**
 * Remote 6 Extended Bits Register Address.
 */
#define TMP_REMOTE_6_EXTENDED_BITS_REG 0x56
/**
 * Local Extended Bits Register Address.
 */
#define TMP_LOCAL_EXTENDED_BITS_REG 0x57
/**
 * Remote 7 Extended Bits Register Address.
 */
#define TMP_REMOTE_7_EXTENDED_BITS_REG 0x58
/**
 * Configuration Mask Register.
 */
#define TMP_CONFIGURATION_REG_MASK 0xe2
/**
 * Stop Bit Position.
 */
#define TMP_STOP_BIT 7
/**
 * Por Bit Position.
 */
#define TMP_POR_BIT 6
/**
 * Timeout Bit Position.
 */
#define TMP_TIMEOUT_BIT 5
/**
 * Extrange Bit Position.
 */
#define TMP_EXTRANGE_BIT 1
/**
 * Transistor Ideality Register Reserved Mask.
 */
#define TMP_TRANSISTOR_IDEALITY_REG_RSVD_MASK 0x1f
/**
 * Extended Bits Register Reserved Mask.
 */
#define TMP_EXTENDED_BITS_REG_RSVD_MASK 0xe0
/**
 * Unreserved Bit Mask.
 */
#define TMP_UNRESERVED_BIT_MASK 0xff

/**Temperature Register*/
typedef struct {
    /*! Main Temperature */
    int main_bits;
    /*! Extended resolution  */
    int extended_bits;
} temp_registers_t;

/**
 * \brief This function gets the celsius temperature of a given channel
 * 
 * \param[in] temp_main_bits_reg The temperature channel. Either: \n TMP_REMOTE_1_REG, TMP_REMOTE_2_REG, TMP_REMOTE_3_REG, TMP_REMOTE_4_REG,\n TMP_REMOTE_5_REG, TMP_REMOTE_6_REG, TMP_REMOTE_7_REG, TMP_LOCAL_REG
 * 
 * \param[out] celsius_temp Extendend Temperature value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_ext_temp(int temp_main_bits_reg, float *celsius_temp);


/**
 * \brief This function gets the main bits of specified register
 * 
 * \param[in] temp_main_bits_reg The temperature channel. Either: \n TMP_REMOTE_1_REG, TMP_REMOTE_2_REG, TMP_REMOTE_3_REG, TMP_REMOTE_4_REG,\n TMP_REMOTE_5_REG, TMP_REMOTE_6_REG, TMP_REMOTE_7_REG, TMP_LOCAL_REG
 * 
 * \param[out] reg_value Function output is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_temp_main_bits_reg(int temp_main_bits_reg, int *reg_value);


/**
 * \brief This function converts temperature to Celsius                
 * 
 * \param[in] main_bits Temperature value to convert to Celsius.
 * 
 * \param[out] celsius_temp Converted Temperature is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_temp_reg_to_celsius(int main_bits, int *celsius_temp);


/**
 * \brief This function converts Celsius to register format            
 * 
 * \param[in] temperature Celsius Temperature to convert in Register Value.
 * 
 * \param[out] temp_reg Register Value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_celsius_to_temp_reg(int temperature, int *temp_reg);


/**
 * \brief This function converts extended temperature to Celsius       
 * 
 * \param[in] main_bits  Temperature value to convert to Celsius.
 * 
 * \param[in] extended_bits Extended Temperature value to convert to Celsius.
 * 
 * \param[out] celsius_temp Converted Temperature is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_ext_temp_regs_to_celsius(int main_bits, int extended_bits, 
            float *celsius_temp);


/**
 * \brief This function converts Celsius to extended register format       
 * 
 * \param[in] temperature Celsius Temperature to convert in Register Value.
 * 
 * \param[out] temp_regs Converted Temperature is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_celsius_to_ext_temp_regs(float temperature, temp_registers_t *temp_regs);


/**
 * \brief This function gets the manufacturer id.
 * 
 * \param[out] manufacturer_id Manufacturer ID is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_manufacturer_id(int *manufacturer_id);


/**
 * \brief This function gets the revision id.
 * 
 * \param[out] revision_id Revision ID is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_get_revision_id(int *revision_id);


/**
 * \brief This function gets the specific alert high limit register.
 * 
 * \param[in] alert_high_limit_reg The Alert High Limit channel. Either \n TMP_REMOTE_1_ALERT_HIGH_LIMIT_REG, TMP_REMOTE_2_ALERT_HIGH_LIMIT_REG, TMP_REMOTE_3_ALERT_HIGH_LIMIT_REG, TMP_REMOTE_4_ALERT_HIGH_LIMIT_REG, \n TMP_REMOTE_5_ALERT_HIGH_LIMIT_REG, TMP_REMOTE_6_ALERT_HIGH_LIMIT_REG, TMP_REMOTE_7_ALERT_HIGH_LIMIT_REG, TMP_LOCAL_ALERT_HIGH_LIMIT_REG
 * 
 * \param[out] reg_value Alert High Limit Value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_get_alert_high_limit_reg(int alert_high_limit_reg, int *reg_value);


/**
 * \brief This function set the specific alert high limit register.
 * 
 * \param[in] alert_high_limit_reg The Alert High Limit channel. Either \n TMP_REMOTE_1_ALERT_HIGH_LIMIT_REG, TMP_REMOTE_2_ALERT_HIGH_LIMIT_REG, TMP_REMOTE_3_ALERT_HIGH_LIMIT_REG, TMP_REMOTE_4_ALERT_HIGH_LIMIT_REG, \n TMP_REMOTE_5_ALERT_HIGH_LIMIT_REG, TMP_REMOTE_6_ALERT_HIGH_LIMIT_REG, TMP_REMOTE_7_ALERT_HIGH_LIMIT_REG, TMP_LOCAL_ALERT_HIGH_LIMIT_REG
 * 
 * \param[in] reg_value Value to set in specified Alert High Limit channel.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_set_alert_high_limit_reg(int alert_high_limit_reg, int reg_value);


/**
 * \brief This function get the specific overt high limit register.
 * 
 * \param[in] overt_high_limit_reg The Overt High Limit channel. Either \n TMP_REMOTE_1_OVERT_HIGH_LIMIT_REG, TMP_REMOTE_2_OVERT_HIGH_LIMIT_REG, TMP_REMOTE_3_OVERT_HIGH_LIMIT_REG, TMP_REMOTE_4_OVERT_HIGH_LIMIT_REG, \n TMP_REMOTE_5_OVERT_HIGH_LIMIT_REG, TMP_REMOTE_6_OVERT_HIGH_LIMIT_REG, TMP_REMOTE_7_OVERT_HIGH_LIMIT_REG, TMP_LOCAL_OVERT_HIGH_LIMIT_REG.
 * 
 * \param[out] reg_value Overt High Limit value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_get_overt_high_limit_reg(int overt_high_limit_reg, int *reg_value);


/**
 * \brief This function set the specific overt high limit register.
 * 
 * \param[in] overt_high_limit_reg The Overt High Limit Channel. Either \n TMP_REMOTE_1_OVERT_HIGH_LIMIT_REG, TMP_REMOTE_2_OVERT_HIGH_LIMIT_REG, TMP_REMOTE_3_OVERT_HIGH_LIMIT_REG, TMP_REMOTE_4_OVERT_HIGH_LIMIT_REG, \n TMP_REMOTE_5_OVERT_HIGH_LIMIT_REG, TMP_REMOTE_6_OVERT_HIGH_LIMIT_REG, TMP_REMOTE_7_OVERT_HIGH_LIMIT_REG, TMP_LOCAL_OVERT_HIGH_LIMIT_REG.
 * 
 * \param[in] reg_value Value to set in specified Overt High Limit Channel.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_set_overt_high_limit_reg(int overt_high_limit_reg, int reg_value);


/**
 * \brief This function get the alert low limit register.
 * 
 * \param[out] alert_low_limit_value   Function output is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_get_alert_low_limit_reg(int *alert_low_limit_value);


/**
 * \brief This function get the alert low limit register.
 * 
 * \param[out] alert_low_limit_value   Function output is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_set_alert_low_limit_reg(int alert_low_limit_value);


/*
 * \brief This function writes one bit 
 *
 * \param[in,out] current_value = current value of a register or data bus Function output is written to this variable.
 * 
 * \param[in] bit_position = position of the bit
 * 
 * \param[in] new_bit_value = new bit value
 *  
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 */
//int tmp_write_one_bit(int bit_position, int bit_value, int *current_value);


/*
 * \brief This function reads one bit 
 *
 * \param[out] current_value = current value of a register or data bus Function output is written to this variable.
 * 
 * \param[in] bit_position = position of the bit
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 */
//int tmp_read_one_bit(int bit_position, int *current_value);


/**
 * \brief This function sets only one bit of a register.
 * 
 * \param[in] register_address  Register Address. 
 * 
 * \param[in] bits_reserved_mask Reserverd Mask.
 * 
 * In this mask the reserved bit are set to logic 0 
 * 
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[in] new_bit_value Value to Set.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_set_only_one_bit_of_register(int register_address, 
            int bits_reserved_mask, int bit_position, int bit_value);


/**
 * \brief This function gets only one bit of a register.
 * 
 * \param[in] register_address Register Address. 
 * 
 * \param[in] bits_reserved_mask Reserverd Mask.
 * 
 * In this mask the reserved bit are set to logic 0
 * 
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[out] bit_value Bit value is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_get_only_one_bit_of_register(int register_address, 
            int bits_reserved_mask, int bit_position, int *bit_value);


/**
 * \brief This function sets a new bit value at a given position in the 
 * configuration register.
 * 
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[in] new_bit_value Bit value is written to this variable.
 *
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_set_configuration_bit(int bit_position, int bit_value);


/**
 * \brief This function gets the current bit value at a given position in the 
 * configuration register.
 * 
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[in] bit_value Function output is written to this variable.
 *
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_get_configuration_bit_status(int bit_position, int *bit_value);


/**
 * \brief This function sets STOP bit to logic 1, the MAX6581 stops converting 
 * and enters standby mode. 
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_enable_stop(void);


/**
 * \brief This function sets STOP bit to logic 0, the MAX6581 starts converting.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_disable_stop(void);


/**
 * \brief This function gets the current STOP bit status 
 * 
 * \param[in] stop_value Stop Value is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_get_stop_status(int *stop_value);


/**
 * \brief This function sets Reset Bit to logic 1 to put the device into its 
 * power-on state. This bit is selfclearing. gets the current STOP bit status 
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_reset_device(void);


/**
 * \brief This function sets Timeout Enable Bit to logic 0 to enable SMBus timeout.
 *
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_enable_timeout(void);


/**
 * \brief This function sets Timeout Enable Bit to logic 1 to disable SMBus 
 * timeout.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_disable_timeout(void);


/**
 * \brief This function gets the current Timeout Enable Bit status. 
 * 
 * \param[out] timeout_value Timeout status is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_get_timeout_status(int *timeout_value);


/**
 * \brief This function sets Extended-Range Enable Bit to logic 1 to set 
 * the temperature and limit data range to -64 ºC to +191 ºC.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_enable_extrange(void);


/**
 * \brief This function sets Extended-Range Enable Bit to logic 0 to set 
 * the temperature and limit data range to 0 ºC to +255 ºC.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_disable_extrange(void);


/**
 * \brief This function gets the current Extended-Range Enable Bit status. 
 * 
 * \param[out] extrange_value Extrange status is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_get_extrange_status(int *extrange_value);


/**
 * \brief This function sets a bit value for the Alert Mask of a given channel.
 * 
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[in] bit_value  Bit Value.
 *
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_set_mask_alert(int bit_position, int bit_value);


/**
 * \brief This function gets the current Alert Mask status of a given channel.
 *
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[out] bit_value Bit value is written to this variable.
 *
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int tmp_get_mask_alert_status(int bit_position, int *bit_value);


/**
 * \brief This function sets a bit value for the Overt Mask of a given channel.
 * 
 * \param[in] bit_position Bit Position to set
 * 
 * \param[in] bit_value   Bit Value to set
 *
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_set_mask_overt(int bit_position, int bit_value);


/**
 * \brief This function gets the current Overt Mask status of a given channel.
 *
 * \param[in] bit_position Bit Position to set
 * 
 * \param[out] bit_value Function output is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_mask_overt_status(int bit_position, int *bit_value);


/**
 * \brief This function gets the current alert high status of a given channel.
 *
 * \param[out] alert_high_status_value Function output is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_alert_high_status_reg(int *alert_high_status_value);


/**
 * \brief This function gets the current overt status register of a given channel.
 *
 * \param[out] overt_status_value Function output is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_overt_status_reg(int *overt_status_value);

/**
 * \brief This function gets the alert status pin.
 *
 * \param[out] overt_status_value Alert Status pin is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_alert_status_pin(unsigned int *alert_status_value);

/**
 * \brief This function gets the overt status pin.
 *
 * \param[out] overt_status_value Overt Status pin is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_overt_status_pin(unsigned int *overt_status_value);

/**
 * \brief This function gets the current diode fault status register.
 *
 * \param[out] diode_fault_status_value Diode fault status is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_diode_fault_status_reg(int *diode_fault_status_value);


/**
 * \brief This function gets the current alert low status register.
 *
 * \param[out] alert_low_status_value Alert Low Status  is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_alert_low_status_reg(int *alert_low_status_value);


/**
 * \brief This function sets a bit value for the alert low of a given channel.
 * 
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[in] bit_value   Bit Value.
 *
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_set_alert_low_disable_bit(int bit_position, int bit_value);


/**
 * \brief This function gets the current alert low disable bit status.
 *
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[out] bit_value Function output is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_alert_low_disable_bit_status(int bit_position, int *bit_value);


/**
 * \brief This function sets a bit value for the resistance cancellation register.
 * 
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[in] bit_value   Bit Value to set.
 *
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 */
int tmp_set_resistance_cancellation_bit(int bit_position, int bit_value);


/**
 * \brief This function gets the current resistance cancellation bit status.
 *
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[out] bit_value bit value is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_resistance_cancellation_bit_status(int bit_position, int *bit_value);


/**
 * \brief This function gets the current transistor ideality register.
 *
 * \param[out] transistor_ideality_value Function output is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_transistor_ideality_reg(int *transistor_ideality_value);


/**
 * \brief This function set the transistor ideality register.
 *
 * \param[in] ideality_value Ideality value is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_set_transistor_ideality_reg(int ideality_value);


/**
 * \brief This function set the ideality select bit.
 *
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[in] bit_value Bit value to set.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_set_ideality_select_bit(int bit_position, int bit_value);


/**
 * \brief This function gets the current ideality select bit status.
 *
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[out] bit_value bit value is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_ideality_select_bit_status(int bit_position, int *bit_value);


/**
 * \brief This function gets the current offset register.
 *
 * \param[out] offset_value Function output is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_offset_reg(int *offset_value);


/**
 * \brief This function set the offset register.
 *
 * \param[out] offset_value Function output is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_set_offset_reg(int offset_value);


/**
 * \brief This function set the offset select bit.
 *
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[in] bit_value Bit value to set.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_set_offset_select_bit(int bit_position, int bit_value);


/**
 * \brief This function gets the current offset select bit status.
 *
 * \param[in] bit_position Bit Position to set.
 * 
 * \param[out] bit_value bit value is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_offset_select_bit_status(int bit_position, int *bit_value);


/**
 * \brief This function gets the current extended bits register status.
 *
 * \param[in] extended_bits_reg Extended Bit Register.
 * 
 * \param[out] reg_value Register Value is written to this variable.
 * 
 * \return  This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int tmp_get_extended_bits_reg(int extended_bits_reg, int *reg_value);


int tmp_read_i2c_bus(unsigned bus, int reg, int *reg_value, const char *error_msg);
int tmp_write_i2c_bus(unsigned bus, int reg, int *reg_value, const char* error_msg);


#endif /* _TMP_H_ */
