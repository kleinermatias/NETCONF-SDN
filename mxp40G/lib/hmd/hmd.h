/**
 * \file
 * \brief HMD API header.
 */
#ifndef _HMD_H_
#define _HMD_H_

/**
 * I2C Module Bus.
 */
#define HMD_BUS 0x06 /* I2C_SENSORS */

/**
 * I2C Module Slave Address.
 */
#define HMD_SLAVE_ADDRESS	0x40

/**
 * Chip Enable Value.
 */
#define HMD_ENABLED  0 /* Chip Select - Active Low Signal */

/**
 * Chip Disable Value.
 */
#define HMD_DISABLED 1

/**
 * Status Register.
 */
#define HMD_STATUS_REG 0
/**
 * Ready bit position.
 */
#define HMD_READY_BIT 0
/**
 * High data Register Address.
 */
#define HMD_DATAH_REG 2
/**
 * Low data Register Addres.
 */
#define HMD_DATAL_REG 1
/**
 * Configuration Register Addres.
 */
#define HMD_CONFIG_REG 3
/**
 * Start bit position.
 */
#define HMD_START_BIT 0
/**
 * Heat bit position.
 */
#define HMD_HEAT_BIT 1
/**
 * Temp bit position.
 */
#define HMD_TEMP_BIT 4
/**
 * Fast bit position.
 */
#define HMD_FAST_BIT 5
/**
 * Configuration Reserver Mask Register Addres.
 */
#define HMD_CONFIG_REG_RSVD_MASK 0x33

/**
 * Identifier Register Addres.
 */
#define HMD_ID_REG	17

/**
 * Linearization Coefficients A0
 */
#define HMD_LIN_COEFF_A0 -4.7844
/**
 * Linearization Coefficients A1
 */
#define HMD_LIN_COEFF_A1 0.4008
/**
 * Linearization Coefficients A2
 */
#define HMD_LIN_COEFF_A2 -0.00393

/**
 * Compensation Coefficients Q0
 */
#define HMD_COMP_COEFF_Q0 0.1973
/**
 * Compensation Coefficients Q1
 */
#define HMD_COMP_COEFF_Q1 0.00237


int hmd_get_temp_comp_humidity(int *temp_comp_humidity);

/**
 * \brief This function returns the humidity.
 *
 * \param[out] humidity  Humidity of the board Value is written in this variable.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_get_humidity(int *humidity);

/**
 * \brief This function returns the temperature of the board
 *
 * \param[out] temperature  Temperature of the board is written in this variable.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_get_temperature(int *temperature);

/**
 * \brief This function returns the status of TEMP bit in the Configuration Registers
 *
 * \param[out] temp_status  TEMP bit status is written in this variable.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_get_temp_status(int *temp_status);

/**
 * \brief This function returns the status of START bit in the Configuration Registers
 *
 * \param[out] start_status  START bit status is written in this variable.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_get_start_status(int *start_status); 

/**
 * \brief This function returns the relative humidity of the board
 * 
 * \param[in] humidity  humidity of the board
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_convert_to_relative_humidity(int humidity);

/**
 * \brief This function returns the linear humidity of the board
 * 
 * \param[in] relative_humidity relative humidity of the board
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_apply_linearization(int relative_humidity);

/**
 * \brief This function returns the temperature compensated humidity of the board
 * 
 * \param[in] linear_humidity linear humidity of the board
 * 
 * \param[in] temperature temperature of the board
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_apply_temp_compensation(int linear_humidity, int temperature);

/**
 * \brief This function writes the Configuration Register
 * 
 * \param[in] new_config_reg_value  New value for the Configuration Register.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_set_configuration(int new_config_reg_value);

/**
 * \brief This function gets the current value of the Configuration Register
 *
 * \param[out] conf_reg  Configuration value is written in this variable.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_get_configuration(int *conf_reg);

/**
 * \brief This function enables the heater
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_enable_heater(void);

/**
 * \brief This function disables the heater
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_disable_heater(void);

/**
 * \brief This function gets the current HEAT bit status of the Configuration Register
 *
 * \param[out] heater_status HEAT bit status
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_get_heater_status(int *heater_status);

/**
 * \brief This function enables fast conversion mode
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_enable_fast_conversion(void);

/**
 * \brief This function disables fast conversion mode
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_disable_fast_conversion(void);

/**
 * \brief This function gets the FAST bit status of the Configuration register
 *
 * \param[out] fast_conv_status FAST bit status
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_get_fast_conversion_status(int *fast_conv_status);

/**
 * \brief This function gets the READY bit status which indicates that conversion is ready
 *
 * \param[out] conv_ready  READY bit status
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_is_conversion_ready(int *conv_ready);

/**
 * \brief This function gets the identifier
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_get_id(int *id_status);

/**
 * \brief This function enables the chip select
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_enable_chip_select(void);

/**
 * \brief This function disables the chip select
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */ 
int hmd_disable_chip_select(void);

/**
 * \brief This function sets only one bit from a given Register
 *
 * \param[in] register_address The register address of the Register which contains the bit that will be set
 * 
 * \param[in] bits_reserved_mask The mask which indicates the reserved bit with 0s
 * 
 * \param[in] bit_position The location of the bit that will be set
 * 
 * \param[in] new_bit_value The value of the bit that will be set
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_set_only_one_bit_of_register(int register_address, 
    int bits_reserved_mask, int bit_position, int new_bit_value);

/**
 * \brief This function gets only one bit from a given Register
 *
 * \param[in] register_address  The register address of the Register which contains the bit that will be read
 * 
 * \param[in] bits_reserved_mask  The mask which indicates the reserved bit with 0s
 * 
 * \param[in] bit_position The location of the bit that will be read
 * 
 * \param[out] bit_status The value of the bit that will be read
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_get_only_one_bit_of_register(int register_address, 
    int bits_reserved_mask, int bit_position, int *bit_status);

/**
 * \brief This function sets only one bit from the Configuration Register
 *
 * \param[in] bit_position  The location of the bit that will be set.
 * 
 * \param[in] new_bit_value  The value of the bit that will be set.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_set_configuration_bit(int bit_position, int new_bit_value);

/**
 * \brief This function gets only one bit from the Configuration Register
 *
 * \param[in] bit_position  The location of the bit that will be get.
 * 
 * \param[out] bit_status   Bit Value is written in this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int hmd_get_configuration_bit_status(int bit_position, int *bit_status);

#endif /* _HMD_H_ */
