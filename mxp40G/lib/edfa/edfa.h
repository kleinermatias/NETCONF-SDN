/**
 * \file
 * \brief EDFA API header.
 * 
 */
#ifndef _EDFA_H
#define _EDFA_H


/**
 * Echo value ON. 
 */
#define EDFA_ECHO_ON 1
/**
 * Echo value OFF. 
 */
#define EDFA_ECHO_OFF 0
/**
 * Baud Rate value 9600. 
 */
#define EDFA_BAUD_9600 9600
/**
 * Baud Rate value 19200. 
 */
#define EDFA_BAUD_19200 19200
/**
 * Baud Rate value 38400. 
 */
#define EDFA_BAUD_38400 38400
/**
 * Baud Rate value 57600. 
 */
#define EDFA_BAUD_57600 57600
/**
 * Baud Rate value 115200. 
 */
#define EDFA_BAUD_115200 115200
/**
 * Gain Control Mode.
 */
#define EDFA_MODE_G 0
/**
 * Output Power Control Mode.
 */
#define EDFA_MODE_P 1
/**
 * Manual Control Mode.
 */
#define EDFA_MODE_M 2
/**
 * Disable Mode.
 */
#define EDFA_MODE_D 3
/**
 * Pump disabled in gain control, power control, and manual control modes.
 */
#define EDFA_LOS_MODE_A 0
/**
 * Pump idled in gain control mode, pump disabled in power control and manual control modes.
 */
#define EDFA_LOS_MODE_I 1
/**
 * No effect in gain control mode, pump disabled in power control and manual control modes.
 */
#define EDFA_LOS_MODE_P 2
/**
 * No effect in any mode.
 */
#define EDFA_LOS_MODE_N 3
/**
 * Pump current in mA.
 */
#define EDFA_PUMP_ILD 0
/**
 * Pump end-of-life current in mA.
 */
#define EDFA_PUMP_EOL 1
/**
 * Pump temperature in degrees C.
 */
#define EDFA_PUMP_TMP 2
/**
 * All Pump Value.
 */
#define EDFA_PUMP_ALL 3
/**
 * Normal Alarm Mode.
 */
#define EDFA_ALARM_MODE_NORMAL 0
/**
 * Latching Alarm Mode.
 */
#define EDFA_ALARM_MODE_STICKY 1
/**
 * Pump Overcurrent Alarm.
 */
#define EDFA_ALARM_ILD 0
/**
 * Pump Temperature Alarm.
 */
#define EDFA_ALARM_TMP 1
/**
 * High case temperature alarm.
 */
#define EDFA_ALARM_MTH 2
/**
 * Low case temperature alarm.
 */
#define EDFA_ALARM_MTL 3
/**
 * Loss of input power alarm.
 */
#define EDFA_ALARM_LOS 4
/**
 * Loss of output power/gain alarm.
 */
#define EDFA_ALARM_LOP 5
/**
 * All Alarms.
 */
#define EDFA_ALARM_ALL 6
/**
 * Current status Alarm Value.
 */
#define EDFA_ALARM_PARAM_STA 0
/**
 * Latching (sticky) status Alarm Value.
 */
#define EDFA_ALARM_PARAM_SST 1
/**
 * Threshold status Alarm Value.
 */
#define EDFA_ALARM_PARAM_THR 2
/**
 * Hysteresis (relative to threshold) Status Alarm value.
 */
#define EDFA_ALARM_PARAM_HYS 3
/**
 *  All Status Alarms Values.
 */
#define EDFA_ALARM_PARAM_ALL 4
/**
 * Maximum Gain Value.
 */
#define EDFA_RANGE_GAIN_MAX 30
/**
 * Minimum Gain Value.
 */
#define EDFA_RANGE_GAIN_MIN 1
/**
 * Maximum Output Power Value.
 */
#define EDFA_RANGE_POUT_MAX  10
/**
 *  Minimum Output Power Value.
 */
#define EDFA_RANGE_POUT_MIN -10
/**
 * Minimum Input Loss Alarm Threshold Value.
 */
#define EDFA_RANGE_LOS_THR_MIN -33
/**
 * Maximum Input Loss Alarm Threshold Value.
 */
#define EDFA_RANGE_LOS_THR_MAX 0
/**
 * Minimum Input Loss Alarm Hysteresis Value.
 */
#define EDFA_RANGE_LOS_HYS_MIN 1
/**
 * Minimum Temperature Alarm Threshold Value.
 */
#define EDFA_RANGE_TMP_THR_MIN -10
/**
 * Maximum Temperature Alarm Threshold Value.
 */
#define EDFA_RANGE_TMP_THR_MAX 75

#define EDFA_COMMAND_ECHO_ON "echo on\n"

#define EDFA_COMMAND_ECHO_OFF "echo off\n"

/* Macro to check edfa pout value*/
#define CHECK_EDFA_POUT(value) ((value >= -1.5 && value <= 16) ? 1 : 0)

#define EDFA_POUT_RANGE_ERROR "Error. The value of edfa pout is out of range. Range: -1.5 dBm a 16 dBm.\n"

/**
 * \brief Sets terminal parameters.
 *
 * \param[in] fd  File Descriptor
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
/*int edfa_set_terminal(int fd);*/
int edfa_set_term(int fd);

/**
 * \brief Sets Read operation Blocking.
 *
 * \param[in] fd  File Descriptor
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 * 
 */

/*TODO*/
int edfa_set_term_test1(int fd);


int edfa_set_blocking (int fd);

/**
 * \brief Sets communication parameters.
 *
 * \param[in] fd  File Descriptor
 * 
 * \param[in] speed  Baud rate
 * 
 * \param[in] parity Parity.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int edfa_set_interface_attribs (int fd, int speed, int parity);
/**
 * \brief Send Command to EDFA module.
 *
 * \param[in] data_to_be_send  Data to be send.
 *
 * \param[in] data_to_be_received  Data to be received.
 *
 * \param[in] size  Size of data.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int edfa_clean_fifo (int fd);

int edfa_trx(int fd, char *data_to_be_sent, int size, char *data_to_be_received);

int edfa_trx_unsafe(int fd, char *data_to_be_sent, int size, char *data_to_be_received);

int edfa_send_command(int fd, char *data_to_be_sent, int size, char *data_to_be_received);

/**
 * \brief This function displays serial number and version information.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int edfa_get_information(int fd, char *data_to_be_received);

/**
 * \brief Sets the echoing of the command line to “ON” or “OFF”.
 *
 * \param[in] echo  Echo Value. Either EDFA_ECHO_ON or EDFA_ECHO_OFF.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int edfa_get_echo(int fd, char *data_to_be_received) ;

/**
 * \brief Sets the baud rate to baud.
 *
 * \param[in] baud  Baud Rate Value. Either EDFA_BAUD_115200, EDFA_BAUD_19200, EDFA_BAUD_38400, EDFA_BAUD_57600 or EDFA_BAUD_9600.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_echo(int fd, int echo, char *data_to_be_received);
/**
 * \brief Gets the echoing of the command line.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 * 
 */

int edfa_get_echo(int fd, char *data_to_be_received) ;

/**
 * \brief Sets the baud rate to baud.
 *
 * \param[in] baud  Baud Rate Value. Either EDFA_BAUD_115200, EDFA_BAUD_19200, EDFA_BAUD_38400, EDFA_BAUD_57600 or EDFA_BAUD_9600.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_baud_rate(int fd, int baud, char *data_to_be_received);

/**
 * \brief Gets the current Baud Rate.
 *
 * The change takes effect only after the prompt, in response to the command, is sent.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_baud_rate(int fd, char *data_to_be_received);

/**
 * \brief Sets the amplifier control mode to mode with gain/output R/W power gain.
 *
 *
 * \param[in] mode  Either EDFA_MODE_G or EDFA_MODE_P.
 *
 * \param[in] gain
 *                  Gain. Between EDFA_RANGE_GAIN_MIN and EDFA_RANGE_GAIN_MAX.\n
 *                  Output power. Between EDFA_RANGE_POUT_MIN and EDFA_RANGE_POUT_MAX.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_mode_and_val(int fd, int mode, float val, char *data_to_be_received);

/**
 * \brief Sets the amplifier control mode.
 *
 *
 * \param[in] mode  Either EDFA_MODE_M or EDFA_MODE_D.
 *
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_mode(int fd, int mode, char *data_to_be_received);

/**
 * \brief  Gets the current mode (and required gain/output power) is displayed.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_mode(int fd, char *data_to_be_received);

/**
 * \brief  Sets output power limit for the EDFA. When the module is in AGC mode, the gain value is automatically reduced
 *          so maximum output power is not above the set value. If the output power exceeds the maximum output power allowed
 *          the amplifier will reduce the power till it reaches maximum power allowed.
 *
 * \param[in] stage
 *
 * \param[in] value
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_splim(int fd, int stage, float value, char*data_to_be_received);

/**
 * \brief  Gets the actual output power limit for the EDFA.
 *
 * \param[in] stage stage number
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_splim(int fd, int stage, char *data_to_be_received);

/**
 * \brief  Sets gain limit for the EDFA. When the module is in power control mode, the power is automatically reduced so maximum gain is not above the set value.
 *          If the gain exceeds the maximum gain allowed , the amplifier will reduce the gain till it reaches maximum gain allowed.

 *
 * \param[in] stage
 *
 * \param[in] value
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_sglim(int fd, int stage, float value, char *data_to_be_received);

/**
 * \brief  Gets the actual gain limit for the EDFA.
 *
 *
 * \param[in] stage stage number
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_sglim(int fd, int stage, char *data_to_be_received);

/**
 * \brief  Gets the input power.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_input_power(int fd, char *data_to_be_received);

/**
 * \brief  Gets the total output power.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_output_power(int fd, char *data_to_be_received);

/**
 * \brief  Gets the signal output power.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_signal_power(int fd, char *data_to_be_received);

/**
 * \brief  Gets the signal gain.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_signal_gain(int fd, char *data_to_be_received);

/**
 * \brief  Gets case temperature in degrees C.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_case_temperature(int fd, char *data_to_be_received);

/**
 * \brief  Gets the status of the pump.
 *
 * \param[in] param   Either EDFA_ALARM_ILD, EDFA_ALARM_EOL or EDFA_ALARM_TMP.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_pump_status(int fd, int param, char *data_to_be_received);

/**
 * \brief  Sets pump current to mA.
 *
 * \param[in] mA.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_pump_mA(int fd, float mA, char *data_to_be_received);

/**
 * \brief  Gets pump current.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_pump_mA(int fd, char *data_to_be_received);

/**
 * \brief  Displays information about alarms.
 *
 * \param[in] alrm Either EDFA_ALARM_ILD, EDFA_ALARM_TMP, EDFA_ALARM_MTH, EDFA_ALARM_MTL, EDFA_ALARM_LOS, EDFA_ALARM_LOP or EDFA_ALARM_ALL.
 *
 *
 * \param[in] parameter Either EDFA_ALARM_PARAM_STA, EDFA_ALARM_PARAM_SST, EDFA_ALARM_PARAM_THR, EDFA_ALARM_PARAM_HYS or EDFA_ALARM_PARAM_ALL.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_alarm_information(int fd, int alrm, int parameter, char *data_to_be_received);

/**
 * \brief  Sets threshold level for the specified alarm.
 *
 * \param[in] alrm Either EDFA_ALARM_ILD, EDFA_ALARM_TMP, EDFA_ALARM_MTH, EDFA_ALARM_MTL, EDFA_ALARM_LOS or EDFA_ALARM_LOP.
 *
 * \param[in] level  Specifies the threshold level.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_threshold_level(int fd, int alrm, float level, char *data_to_be_received);

/**
 * \brief  Sets hysteresis level for the specified alarm.
 *
 * \param[in] alrm Either EDFA_ALARM_ILD, EDFA_ALARM_TMP, EDFA_ALARM_MTH, EDFA_ALARM_MTL, EDFA_ALARM_LOS or EDFA_ALARM_LOP.
 *
 * \param[in] level Specifies the hysteresis level.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_hysteresis_level(int fd, int alrm, float level, char *data_to_be_received);

/**
 * \brief  Reset the latching status of alarm.
 *
 * \param[in] alrm Either EDFA_ALARM_ILD, EDFA_ALARM_TMP, EDFA_ALARM_MTH, EDFA_ALARM_MTL, EDFA_ALARM_LOS, EDFA_ALARM_LOP or EDFA_ALARM_ALL.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_reset_alarm_status(int fd, int alrm, char *data_to_be_received);

/**
 * \brief  Lists all alarms whose status is on ('S' or 'N') and erases all R latching alarms ('S').
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_list_all_alarm(int fd, char *data_to_be_received);

/**
 * \brief  Sets alarm status mode to normal (N) or latching (S – sticky) mode.
 *
 * \param[in] mode Either EDFA_ALARM_MODE_NORMAL or EDFA_ALARM_MODE_STICKY.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_alarm_mode(int fd, int mode, char *data_to_be_received);

/**
 * \brief  Gets alarm status.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_alarm_mode(int fd, char *data_to_be_received);

/**
 * \brief  Displays amplifier status one or more of the following: \n
 *
 *      RDIS: Amplifier disabled due to amplifier disable input or alarm \n
 *      LIM: Amplifier gain or output power limited by SGLIM/SPLIM \n
 *      OK: Amplifier is operating normally \n
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_amplifier_status(int fd, char *data_to_be_received);

/**
 * \brief  Determines the behavior of the amplifier on input LOS.
 *
 * param[int] mode   Alarm Mode. Either EDFA_LOS_MODE_A, EDFA_LOS_MODE_I, EDFA_LOS_MODE_P or EDFA_LOS_MODE_N.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int edfa_set_los_mode(int fd, int mode, char *data_to_be_received);

/**
 * \brief  Gets LOS mode.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_los_mode(int fd, char *data_to_be_received);

/**
 * \brief   Set-point for current in-case of loss (in mA).
 *
 * param[in] mA
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_set_los_mA(int fd, int mA, char *data_to_be_received);

/**
 * \brief  Resets all settings to factory default values. Changes take effect only after reset or after power on of the amplifier (with no reset command).
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_reset_factory_default_values(int fd, char *data_to_be_received);

/**
 * \brief  Resets the firmware
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_reset_firmware(int fd, char *data_to_be_received);
/**
 * \brief  Gets loss of Input alarm through GPIO ports.
 *
 * \param[in] status loss status is written in this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_get_loss_input_alarm(unsigned int *status);
/**
 * \brief  Resets Module through GPIO ports.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_reset_hw(void);
/**
 * \brief  Shutdown Module through GPIO ports.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int edfa_shutdown(int fd, char *data_to_be_received);

int edfa_clean_data(char data[]);

int edfa_set_terminal(int fd);

int hl_edfa_set_pout (float power);

int hl_edfa_init(float pout);

#endif /* _EDFA_H */
