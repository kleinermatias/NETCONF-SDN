/**
 * \file
 * \brief XFP API header.
 * 
 */
#include "../gpio/gpio.h"

#ifndef _XFP_H
#define _XFP_H

/**
 * Name of the XFP 0. 
 */
#define XFP_MOD_0	0x00
/**
 * Name of the XFP 1. 
 */
#define XFP_MOD_1	0x01
/**
 * Name of the XFP 2. 
 */
#define XFP_MOD_2	0x02
/**
 * Name of the XFP 3. 
 */
#define XFP_MOD_3	0x03

/**
 * XFP Slave Address. 
 */
#define XFP_SLAVE_ADDRESS	0x50

/* Low Memory */

/**
 * Identifier Register.
 */
#define XFP_ID 0

/**
 * Timing Control Value.
 */
#define XFP_TIMING_SCTRL_STSF 1
/**
 * High Temperature Alarm Register.
 */
#define XFP_TEMP_HIGH_ALARM 2
/**
 * Low Temperature Alarm Register.
 */
#define XFP_TEMP_LOW_ALARM 4
/**
 * High Temperature Warning Register.
 */
#define XFP_TEMP_HIGH_WARNING 6
/**
 * Low Temperature Warning Register.
 */
#define XFP_TEMP_LOW_WARNING 8
/**
 * High Bias Alarm Register.
 */
#define XFP_BIAS_HIGH_ALARM 18
/**
 * Low Bias Alarm Register.
 */
#define XFP_BIAS_LOW_ALARM 20
/**
 * High Bias Warning Register.
 */
#define XFP_BIAS_HIGH_WARNING 22
/**
 * Low Bias Warning Register.
 */
#define XFP_BIAS_LOW_WARNING 24
/**
 * High TX Power Alarm Register.
 */
#define XFP_TX_POWER_HIGH_ALARM 26
/**
 * Low TX Power Alarm Register.
 */
#define XFP_TX_POWER_LOW_ALARM 28
/**
 * High TX Power Warning Register.
 */
#define XFP_TX_POWER_HIGH_WARNING 30
/**
 * Low TX Power Warning Register.
 */
#define XFP_TX_POWER_LOW_WARNING 32
/**
 * High RX Power Alarm Register.
 */
#define XFP_RX_POWER_HIGH_ALARM 34
/**
 * Low RX Power Alarm Register.
 */
#define XFP_RX_POWER_LOW_ALARM 36
/**
 * High RX Power Warning Register.
 */
#define XFP_RX_POWER_HIGH_WARNING 38
/**
 * Low RX Power Warning Register.
 */
#define XFP_RX_POWER_LOW_WARNING 40
/* AUX 1 and 2 Alarms from 42 to 57 */

/* BER Control Fields */
/**
 * Acceptable BER Register.
 */
#define XFP_ACCEPTABLE_BER 70
/**
 * Actual BER Register.
 */
#define XFP_ACTUAL_BER 71

/* Wavelength Control Fields */
/**
 * Wavelength Set Register.
 */
#define XFP_WAVELENGTH_SET 72
/**
 * Wavelength Error Register.
 */
#define XFP_WAVELENGTH_ERROR 74
/**
 * Device Technology Register.
 */
#define XFP_DEVICE_TECH 147
/**
 * Vendor Name Register.
 * 148-163 16 Bytes
 */
#define XFP_VENDOR_NAME 148
 /**
 * CDR Support Register.
 */
#define XFP_CDR_SUPPORT 164
/**
 * Organizationally Unique Identifier OUI field.
 * 3 bytes
 */
#define XFP_OUI_VENDOR 165
/**
 * Part Number provided by vendor (ASCII)
 * 16 bytes
 */
#define XFP_PN_VENDOR 168
/**
 * Vendor Revision Number (ASCII)
 * 2 bytes
 */
#define XFP_RN_VENDOR 184
/* FEC Control Fields */
/**­
 * Amplitude Adjustment Register.
 */
#define AMPLITUDE_ADJUSTMENT 76
/**­
 * Phase Adjustment Register.
 */
#define PHASE_ADJUSTMENT 77
/* RSVD 78 AND 79 */

/* Latched Interrupt Flag Fields */
/**­
 * Latched TX Alarm Register.
 */
#define L_TEMP_TX_BIAS_POWER_ALARM 80
/**­
 * Latched RX Alarm Register.
 */
#define L_RX_POWER_AUX12_ALARM 81
/**­
 * Latched TX Warning Register.
 */
#define L_TEMP_TX_BIAS_POWER_WARNING 82
/**­
 * Latched TX Warning Register.
 */
#define L_RX_POWER_AUX12_WARNING 83
/**­
 * Latched Fault Status Register.
 */
#define L_FAULT_STATUS 84
/**­
 * Latched Other Fault Status Register.
 */
#define L_OTHER_FAULT_STATUS 85
/**­
 * VCC Alarm Register.
 */
#define L_VCC_ALARM 86
/**­
 * VCC Warning Register.
 */
#define L_VCC_WARNING 87

/* Interrupt Masking Bits */
/**­
 * Masking TX Alarms Register.
 */
#define M_TEMP_TX_BIAS_POWER_ALARM 88
/**­
 * Masking RX Alarms Register.
 */
#define M_RX_POWER_AUX12_ALARM 89
/**­
 * Masking TX Warnings Register.
 */
#define M_TEMP_TX_BIAS_POWER_WARNING 90
/**­
 * Masking RX Warnings Register.
 */
#define M_RX_POWER_AUX12_WARNING 91
/**­
 * Masking Fault Status Register.
 */
#define M_FAULT_STATUS 92
/**­
 * Masking Other Fault Status Register.
 */
#define M_OTHER_FAULT_STATUS 93
/**­
 * Masking VCC Alarm Register.
 */
#define M_VCC_ALARM 94
/**­
 * Masking VCC Warning Register.
 */
#define M_VCC_WARNING 95

/* A/D Values */
/**­
 * Temperature Register.
 */
#define XFP_TEMPERATURE 96
/**­
 * Bias Register.
 */
#define XFP_TX_BIAS 100
/**­
 * TX Power Register.
 */
#define XFP_TX_POWER 102
/**­
 * RX Power Register.
 */
#define XFP_RX_POWER 104

/* 
 * General Control/Status Bits 
 */
/**­
 * Control Status 0 Register.
 */
#define XFP_CONTROL_STATUS_0 110
/**­
 * TX Disable State Bit.
 */
#define XFP_CONTROL_STATUS_0_TX_DISABLE_STATE   7
/**­
 * Soft TX Disable Bit.
 */
#define XFP_CONTROL_STATUS_0_SOFT_TX_DISABLE    6
/**­
 * MOD_NR State Bit.
 */
#define XFP_CONTROL_STATUS_0_MOD_NR_STATE       5
/**­
 * P_DOWN State Bit.
 */
#define XFP_CONTROL_STATUS_0_P_DOWN_STATE       4
/**­
 * Soft P_Down State Bit.
 */
#define XFP_CONTROL_STATUS_0_SOFT_P_DOWN        3
/**­
 * Interrupt Bit.
 */
#define XFP_CONTROL_STATUS_0_INTERRUPT_N        2
/**­
 * RX_LOS Bit.
 */
#define XFP_CONTROL_STATUS_0_RX_LOS             1
/**­
 * Data Not Ready Bit.
 */
#define XFP_CONTROL_STATUS_0_DATA_NOT_READY     0

/**­
 * Control Status 1 Register.
 */
#define XFP_CONTROL_STATUS_1 111
/**­
 * TX_NR State Bit.
 */
#define XFP_CONTROL_STATUS_1_TX_NR_STATE        7
/**­
 * TX_Fault State Bit.
 */
#define XFP_CONTROL_STATUS_1_TX_FAULT_STATE     6
/**­
 * TX_CDR Not Locked Bit.
 */
#define XFP_CONTROL_STATUS_1_TX_CDR_NOT_LOCKED  5
/**­
 * RX_NR State Bit.
 */
#define XFP_CONTROL_STATUS_1_RX_NR_STATE        4
/**­
 * RX_CDR Not Locked Bit.
 */
#define XFP_CONTROL_STATUS_1_RX_CDR_NOT_LOCKED  3


/* Packet Error Checking */


/* Password and Table Select Entry Bytes */
/**­
 * Page Selection Register.
 */
#define XFP_PAGE_SELECT_BYTE 127

/* Serial ID: Data Fields - Page 01 */
/**­
 * Electronic Compatibility or Optical Compatibility Register.
 */
#define XFP_TRANSCEIVER 131 // to 138
/**­
 * Serial Encoding Register.
 */
#define XFP_ENCODING 139
/**­
 * Minimum Bit Rate Register.
 */
#define XFP_BR_MIN 140
/**­
 * Maximum Bit Rate Register.
 */
#define XFP_BR_MAX 141
/**­
 * Laser Wavelength Register.
 */
#define XFP_WAVELENGTH_RD 186
/**­
 * Laser Wavelength Value.
 */
#define XFP_WL_1550NM 31000
/**­
 * Laser Wavelength Value.
 */
#define XFP_WL_1310NM 26200
/**­
 * Laser Wavelength Value.
 */
#define XFP_WL_830NM 16600
/** 
 * ITU G.709(OTU-2)  OC-192 Over FEC  10.70 Gigabaud
 * Data Rate = 9.5Gb/s + 0.2 * Value
 * Data Rate = 10.7 ---> Value = 6
 */
#define XFP_DATARATE_CTRL 0x60 
/**­
 * Communication Disabled Status.
 */
#define XFP_COMM_DISABLED 1
/**­
 * Communication Enabled Status.
 */
#define XFP_COMM_ENABLED 0
/**­
 * Laser Disabled Status.
 */
#define XFP_LASER_DISABLED 1
/**­
 * Laser Enabled Status.
 */
#define XFP_LASER_ENABLED 0
/**­
 * Module Power Up Status.
 */
#define XFP_PWR_UP 0
/**­
 * Module Power Down Status.
 */
#define XFP_PWR_DOWN 1
/**­
 * Maximum Case Temperature.
 */
#define XFP_MCT 190

/* Power Supply Related Fields 192-195 */
/**-
 * Maximum Power Dissipation Register.
 */
#define XFP_MPD 192
/**-
 * Maximum Total Power Dissipation in Power Down Mode Register.
 */
#define XFP_MTPD 193
/**-
 * Maximum Current Required by 5v and 3.3v Supply.
 */
#define XFP_MCR_5V_3V3 194
/**-
 * Maximum Current Required by 1.8v and -5.2v Supply.
 */
#define XFP_MCR_1V8_N5V2 195
/**-
 * Serial Number provided by vendor (ASCII).
 * 16 Bytes
 */
#define XFP_SN_VENDOR 196
/**-
 * Vendor's Manufacturing date code.
 * 8 Bytes
 */
#define XFP_MDC_VENDOR 212
/**-
 * Diagnostic Monitoring Type Register.
 * Bit 4 Module Report to FEC BER.
 * Bit 3 Received power measurement type.
 */
#define XFP_DMT 220
/**-
 * Enhanced Options Register.
 * Bit 6 Optional Soft TX_DISABLE implemented.
 * Bit 5 Optional Soft P_down implemented.
 * Bit 2 Active FEC control functions implemented.
 * Bit 1 Wavelength tunability implemented.
 * Bit 0 Optional CMU Support Mode.
 */
#define XFP_ENHANCED_OPTIONS 221
/**-
 * Auxiliary Monitoring Register.
 * Bits 7-4 Aux A/D 1.
 * Bits 3-0 Aux A/D 2.
 */
#define XFP_AUX_MONITORING 222

static const unsigned int xfp_led_red[] = {LED_XFP_1_RED, LED_XFP_2_RED, LED_XFP_3_RED, LED_XFP_4_RED};
static const unsigned int xfp_led_green[] = {LED_XFP_1_GREEN, LED_XFP_2_GREEN, LED_XFP_3_GREEN, LED_XFP_4_GREEN};

static const char flags_reg_xfp[8][8][40] = {	{"Low TX Power alarm.","High TX Power alarm.","Low TX Bias alarm.","High TX Bias alarm.","Reserved","Reserved","Low Temperature alarm.","High Temperature alarm."}, // Description register 80.
												{"Reserved","Reserved","Low AUX2 monitor alarm.","High AUX2 monitor alarm.","Low AUX1 monitor alarm.","High AUX1 monitor alarm.","Low RX Power alarm.","High RX Power alarm."},// Description register 81.
												{"Low TX Power warning.","High TX Power warning","Low TX Bias warning.","High TX Bias warning.","Reserved","Reserved","Low Temperature warning","High Temperature warning."},// Description register 82.
												{"Reserved","Reserved","Low AUX2 monitor warning.","High AUX2 monitor warning.","Low AUX1 monitor warning.","High AUX1 monitor warning.","Low RX Power warning.","High RX Power warning."},// Description register 83.
												{"Reset Complete Flag.","Mirror of MOD_NR pin.","RX CDR Loss of Lock.","Mirror of RX_LOS pin.","RX_NR Status.","TX CDR Loss of Lock","Laser Fault condition.","TX_NR Status."},// Description register 84.
												{"Reserved","Reserved","Reserved","Reserved","Reserved","Wavelength Unlocked Condition.","TEC Fault.","APD Supply Fault."},// Description register 85.
												{"Vee5 Low Alarm Flag.","Vee5 High Alarm Flag.","VCC2 Low Alarm Flag.","VCC2 High Alarm Flag.","VCC3 Low Alarm Flag.","VCC3 High Alarm Flag.","VCC5 Low Alarm Flag.","VCC5 High Alarm Flag."},// Description register 86.
												{"Vee5 Low Warning Alarm Flag.","Vee5 High Warning Alarm Flag.","VCC2 Low Warning Alarm Flag.","VCC2 High Warning Alarm Flag.","VCC3 Low Warning Alarm Flag.","VCC3 High Warning Alarm Flag.","VCC5 Low Warning Alarm Flag.","VCC5 High Warning Alarm Flag."}// Description register 87.
											};

/**
 * \brief This function set the XFP module data rate.
 *
 * \param[in] i2c_bus_name  Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int xfp_set_data_rate(int i2c_bus_name, int data_rate);


/**
 * \brief This function return XFP module temperature.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] temperature Temperature value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int xfp_get_temperature(int i2c_bus_name, float *temperature);


/**
 * \brief This function return xfp module identifier. Byte: 0
 *	
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \param[out] identifier  Identifier value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int xfp_get_identifier(int i2c_bus_name, int *identifier);


/**
 * \brief This function return output optical power. Bytes: 102-103 msb-lsb.  In dBm
 *	
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] tx_power Tx power value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int xfp_get_tx_power(int i2c_bus_name, float *tx_power);


/**
 * \brief This function return the input optical power in dBm.
 *	
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \param[out] rx_power Rx power value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 * 
 */
int xfp_get_rx_power(int i2c_bus_name, float *rx_power);


/**
 * \brief This function allows read a byte or word in the position data_address.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[in] data_address XFP Register Address
 * 
 * \param[in] size  Size to read. Either 2 (byte) or 3 (word).
 * 
 * \param[out] data Read data is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_read(int i2c_bus_name, int data_address, int size, int *data, const char *msg);


/**
 * \brief This function allows write a byte or word in the position data_address.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[in] data_address XFP Register Address
 * 
 * \param[in] value Value to write
 * 
 * \param[in] size Size to write. Either 2 (byte) or 3 (word).
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_write(int i2c_bus_name, int data_address, int size, int *data, const char *msg);

/**
 * \brief This function gets the XFP optical compatibility
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] compatibility Compatibility value is written in this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_optical_compatibility(int i2c_bus_name, int *compatibility);

/**
 * \brief This function allows to xfp module answer to bus i2c.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_enable_communication(int i2c_bus_name);


/**
 * \brief This function disable to xfp module answer to bus i2c.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_disable_communication(int i2c_bus_name);



/**
 * \brief This function return the state of the mod_desel signal
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \param[inout] status Communication status is stored in this variable.
 * 
 * \return the state of the mod_desel signal = 0 enable - 1 disable
 */
int xfp_get_communication_status(int i2c_bus_name, unsigned int *status);


/**
 * \brief This function turn-on the laser of module xfp.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_enable_laser(int i2c_bus_name);

int xfp_mask_bit(int i2c_bus_name);

int xfp_demask_bit(int i2c_bus_name);


/**
 * \brief This function turn-off the laser of module xfp.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_disable_laser(int i2c_bus_name);


/**
 * \brief This function return the status of laser of module xfp.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] status Function output is written to this variable.
 *
 * \return the state of the xfp_tx_dis signal = 0 enable - 1 disable
 */
int xfp_get_laser_status(int i2c_bus_name, unsigned int *status);


/**
 * \brief This function send a one signal of reset to module xfp.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_reset(int i2c_bus_name);


/**
 * \brief This function places the module in Normal Operation mode.
 *
 * XFP_P_DOWN_RST is a multifunction pin for module Power Down and Reset.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_power_up(int i2c_bus_name);


/**
 * \brief This function places the module in the standby (Low Power) mode.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_power_down(int i2c_bus_name);


/**
 * \brief This function returns the power status mode of module xfp.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] status Power status is written to this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int xfp_get_power_status(int i2c_bus_name, unsigned int *status);


/**
 * \brief This function reads the signal that indicates whether the module is present or not.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] status Pressence status is written to this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_presence_status(int i2c_bus_name, unsigned int *status);


/**
 * \brief This function indicates whether the module xfp indicates insufficient optical power.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] status Function output is written to this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int xfp_get_loss_of_signal_status(int i2c_bus_name, unsigned int *status);


/**
 * \brief This function reads the signal that indicates if the module presents interrupts.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] status Interruption status is written to this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int xfp_read_interruption(int i2c_bus_name, unsigned int *status);


/**
 * \brief This function returns the status ready  of module xfp.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] status Ready status is written to this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 *
 */
int xfp_get_ready_status(int i2c_bus_name, unsigned int *status);


/**
 * \brief This function returns the Actual BER Reported by the FEC to the Module
 * 
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] ber Function output is written to this variable.
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_actual_ber(int i2c_bus_name, int *ber);


/**
 * \brief This function get the tx bias
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] bias Bias value is written to this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_tx_bias(int i2c_bus_name, int *bias);

/**
 * \brief This function set the xfp module wavelength.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[in] wavelength Wavelength value to set. Either XFP_WL_1550NM, XFP_WL_1310NM or XFP_WL_830NM.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_set_wavelength(int i2c_bus_name, int wavelength);


/**
 * \brief This function get the xfp module wavelength
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] wavelength Function output is written to this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_wavelength(int i2c_bus_name, int *wavelength);

int xfp_get_device_tech(int i2c_bus_name, int *status);
int xfp_set_device_tech(int i2c_bus_name, int status);

/**
 * \brief This function get the encoding support
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] encoding_support Function output is written to this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_encoding_support(int i2c_bus_name, int *encoding_support);


/**
 * \brief This function get the minimum bit rate
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] minimum_bit_rate Minimum bit rate value is written to this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_minimum_bit_rate(int i2c_bus_name, int *minimum_bit_rate);


/**
 * \brief This function get the maximum bit rate
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] maximum_bit_rate Maximum bit rate value is written to this variable.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_maximum_bit_rate(int i2c_bus_name, int *maximum_bit_rate);

/**
 * \brief This function is used for change the page number of the upper 
 * multipage memory space  
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[in] page  Page number.  Either 0, 1, 2 or 3
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_set_page(int i2c_bus_name, int page);

/**
 * \brief This function is used for gets actual page. 
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[out] page  Page number.  Either 0, 1, 2 or 3
 * 
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_page(int i2c_bus_name, int* page);
/**
 * \brief This function sets the threshold level.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[in] reg_address Register Address.
 * 
 * \param[in] value Value to set.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_set_threshold(int i2c_bus_name, int reg_address, int value);
/**
 * \brief This function gets a specified interruption flag.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_int_flag(int i2c_bus_name, int reg_address, int bit_pos, int* bit_val);
/**
 * \brief This function gets a specified mask.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 * 
 * \param[in] reg_address Register Address.
 * 
 * \param[in] bit_pos  Bit position.
 * 
 * \param[in] bit_val  Bit value to set.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_set_mask(int i2c_bus_name, int reg_address, int bit_pos, int bit_val); 
/**
 * \brief Prints the xfp module serial number.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_serial_number(int i2c_bus_name);
/**
 * \brief Prints the xfp module date code.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_date_code(int i2c_bus_name);
/**
 * \brief Prints the xfp module revision level.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_revision_level(int i2c_bus_name);
/**
 * \brief Prints the XFP module part number.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_part_number(int i2c_bus_name);
/**
 * \brief Prints the XFP vendor organizationally unique Identifier.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_vendor_oui(int i2c_bus_name);
/**
 * \brief This function prints the XFP vendor name.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_get_vendor_name(int i2c_bus_name);

/**
 * \brief This function sets the XFI Loopback.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_set_xfi_loopback(int i2c_bus_name);

/**
 * \brief This function sets the Line Loopback.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_set_line_loopback(int i2c_bus_name);

/**
 * \brief This function sets the normal operation over the Line side and XFI interface.
 *
 * \param[in] i2c_bus_name Name of XFP module. Either XFP_MOD_0, XFP_MOD_1, XFP_MOD_2 or XFP_MOD_3.
 *
 * \return This function returns -1 if an error occurs, 0 otherwise.
 */
int xfp_set_normal_operation(int i2c_bus_name);

int xfp_print_interruption_flags(int xfp_module);

int xfp_get_interruption_flags(int xfp_module, unsigned int xfp_interruption_flags[4][7]);

int xfp_read_interruption_flags(int xfp_module);

int xfp_initialize(int i2c_bus_name, int wavelength, int data_rate, int xfi_loopback_enable);

// Enables or disables the electric loopback in all xfp modules.
void xfp_set_loopback(int enable, int slices[]);

// Function to log info into the syslog
void xfp_syslog(int svrt, const char *tag, const char *method, const char *msg, int id);

// Checks to ensure the communication
int xfp_check_conditions (int i2c_bus_name, int data_address, int size, int *data, const char *msg);

// Check the bus condition
int xfp_check_bus(int i2c_bus_name, const char * msg);

int xfp_gpio_write_bit(int port, unsigned value, const char* error_msg, int i2c_bus_name);

#endif /* _XFP_H */
