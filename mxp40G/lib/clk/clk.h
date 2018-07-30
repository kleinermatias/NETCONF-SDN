/**
 * \file
 * \brief CLK API header.
 * 
 */
#ifndef _CLK_H_
#define _CLK_H_

/**
 * CLK Bus Address. 
 */
#define CLK_BUS 0x03 /* UNKNOWN */

/**
 * CLK Slave Address. 
 */
#define CLK_SLAVE_ADDRESS  0x30

/**
 * Reset pulse DOWN value. 
 */
#define CLK_RESET_PULSE_DOWN 0

/**
 * Reset pulse UP value. 
 */
#define CLK_RESET_PULSE_UP 1

/**
 * Reset Init second value. 
 */
#define CLK_T_RESET_INIT 1 //uSecond

/**
 * CLK input 1 Selected.
 */
#define CLK_CKIN1 0

/**
 * CLK intput 2 Selected.
 */
#define CLK_CKIN2 1

/**
 * CLK PLL Locked value. 
 */
#define CLK_PLL_LOCKED 0

/**
 * CLK PLL Unlocked value. 
 */
#define CLK_PLL_UNLOCKED 1

/**
 * CLK Input 0. 
 */
#define CLK_INPUT_0 0 

/**
 * CLK Input 1. 
 */
#define CLK_INPUT_1 1

/**
 * CLK Input 2 Present. 
 */
#define CLK_CKIN2_PRESENT 0

/**
 * CLK Input 2 LOS and FOS enable. 
 */
#define CLK_LOS_FOS_ON_CKIN2 1

/**
 * CLK Input 2 Present. 
 */
#define CLK_CKIN1_PRESENT 0

/**
 * CLK Input 1 LOS and FOS enable. 
 */
#define CLK_LOS_FOS_ON_CKIN1 1

/**
 * CLK disabled value.
 */
#define CLK_DISABLED 0

/**
 * CLK enabled value.
 */
#define CLK_ENABLED 1

#define MUX_SELECT_IN0 0

#define MUX_SELECT_IN1 1

/**
 * \brief This function allows read a byte in the position data_address.
 *
 * \param[in] data_address Register Address.
 * 
 * \param[in] size Size Data to read. I2C_SMBUS_BYTE_DATA.
 *  
 * \param[out] data Read data is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int clk_read(int data_address, int size, int *data);

/**
 * \brief This function allows Write a byte in the position data_address.
 *
 * \param[in] data_address Register Address.
 * 
 * \param[in] size Size Data to write. I2C_SMBUS_BYTE_DATA.
 *  
 * \param[in] data Data to write.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int clk_write(int data_address, int size, int *data);

/**
 * \brief This function Select active CLK Module.
 * 
 * \param[in] cl_ac Active Clock. Either CLK_CKIN1 or CLK_CKIN2.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int clk_set_clock_select_active_clock(unsigned int cl_ac);

/**
 * \brief This function gets the LOS of Lock Indicator.
 * 
 * \param[out] status LOS status is written in this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int clk_get_pll_los_of_lock_indicator(unsigned int *status);

/**
 * \brief This function gets the Clock 2Invalid indicator Pin status.
 * 
 * \param[out] status Invalid indicator status is written in this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int clk_get_ckin2_invalid_indicator(unsigned int *status);

/**
 * \brief This function sets the 400mhz oscillator mode.
 * 
 * \param[out] mode Oscillator mode. Either CLK_OSC_400MHZ_NORMAL or CLK_OSC_400MHZ_HIHG_IMPEDANCE.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int clk_set_osc_400_mhz(unsigned int enable);

int clk_set_mux_b(unsigned int value);

/**
 * \brief This function selects multiplexer Inputs.
 * 
 * \param[out] input Clock Input. Either CLK_INPUT_0 or CLK_INPUT_1.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int clk_set_select_multiplexer_input(unsigned int input);

/**
 * \brief This function sets the 648mhz oscillator mode.
 * 
 * \param[out] mode Oscillator mode. Either CLK_OSC_648MHZ_NORMAL or CLK_OSC_648MHZ_HIHG_IMPEDANCE.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int clk_set_osc_684_28_mhz(unsigned int enable);

int clk_set_mux_a(unsigned int value);

/**
 * \brief This function gets the 100mhz diff n pin status.
 * 
 * \param[out] status 100mhz diff n status is written in this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int clk_get_100mhz_diff_n(unsigned int *status);

/**
 * \brief This function gets the 100mhz diff p pin status.
 * 
 * \param[out] status 100mhz diff p status is written in this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int clk_get_100mhz_diff_p(unsigned int *status);

#endif /* _CLK_H_ */
