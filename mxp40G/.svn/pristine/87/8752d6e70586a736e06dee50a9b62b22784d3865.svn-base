#include "xfp.h"
#include "../i2c/i2crw.h"
#include "../gpio/gpio.h"
#include "../ltc/ltc.h"
#include "../bitman/bitman.h"
#include <math.h> 
#include <stdio.h>
#include "../util/util.h"
#include <unistd.h>
#include <ctype.h>
#include "../../include/mxp_error.h"

#include "../utils/filelock.h"

typedef struct
{
	unsigned int mod_desel;
	unsigned int tx_dis;
	unsigned int p_down_rst;
	unsigned int mod_abs;
	unsigned int rx_los;
	unsigned int interrupt;
	unsigned int mod_nr;
} xfp_mod_t;

const xfp_mod_t xfp_mod[4] = { { XFP0_MOD_DESEL, XFP0_TX_DIS, XFP0_P_DOWN_RST, XFP0_MOD_ABS, XFP0_RX_LOS, XFP0_INTERRUPT, XFP0_MOD_NR },

		{ XFP1_MOD_DESEL, XFP1_TX_DIS, XFP1_P_DOWN_RST, XFP1_MOD_ABS, XFP1_RX_LOS, XFP1_INTERRUPT, XFP1_MOD_NR },

		{ XFP2_MOD_DESEL, XFP2_TX_DIS, XFP2_P_DOWN_RST, XFP2_MOD_ABS, XFP2_RX_LOS, XFP2_INTERRUPT, XFP2_MOD_NR },

		{ XFP3_MOD_DESEL, XFP3_TX_DIS, XFP3_P_DOWN_RST, XFP3_MOD_ABS, XFP3_RX_LOS, XFP3_INTERRUPT, XFP3_MOD_NR } };

int xfp_set_data_rate(int i2c_bus_name, int data_rate)
{
	int current_value;

	CHECK_PARAM_N(data_rate < 0 || data_rate > 15, LOG_ERR, TAG_XFP, "Error in xfp_set_data_rate(): data rate out of range", i2c_bus_name,LOG_LOCAL0);

	xfp_read(i2c_bus_name, XFP_TIMING_SCTRL_STSF, I2C_SMBUS_BYTE_DATA, &current_value, "xfp_set_data_rate(): ");

	/** Data rate = 9.5 Gb/s + 0.2 * value */
	int new_value = (current_value & 0x0f) | ((data_rate & 0x0f) << 4);

	xfp_write(i2c_bus_name, XFP_TIMING_SCTRL_STSF, I2C_SMBUS_BYTE_DATA, &new_value, "xfp_set_data_rate(): ");

	return 0;
}

int xfp_get_temperature(int i2c_bus_name, float *temperature)
{
	int temp;

	xfp_read(i2c_bus_name, XFP_TEMPERATURE, I2C_SMBUS_WORD_DATA, &temp, "xfp_get_temperature(): ");

	*temperature = (float) temp / 256;

	return 0;
}

int xfp_get_identifier(int i2c_bus_name, int *identifier)
{

	xfp_read(i2c_bus_name, XFP_ID, I2C_SMBUS_BYTE_DATA, identifier, "xfp_get_identifier(): ");
	return 0;
}

int xfp_get_tx_power(int i2c_bus_name, float *tx_power)
{
	int aux;

	xfp_read(i2c_bus_name, XFP_TX_POWER, I2C_SMBUS_WORD_DATA, &aux, "xfp_get_tx_power(): ");

	*tx_power = 10 * log10((aux * 0.1) / 1000);

	return 0;
}

int xfp_get_rx_power(int i2c_bus_name, float *rx_power)
{

	int aux;

	xfp_read(i2c_bus_name, XFP_RX_POWER, I2C_SMBUS_WORD_DATA, &aux, "xfp_get_rx_power():");

	*rx_power = 10 * log10((aux * 0.1) / 1000);

	return 0;
}

void xfp_syslog(int svrt, const char *tag, const char *method, const char *msg, int id)
{
	/*
	openlog(tag, LOG_PID | LOG_CONS, LOG_USER);
	syslog(svrt, "(ID=%d) %s %s", id, method, msg);
	closelog();
	 */
	char method_msg[500] = "";
	int result = sprintf(method_msg,"%s %s", method, msg);
	if(result < 0)
		perror("sprintf xfp_syslog");
	else
		CHECK_PARAM_N(1,svrt,tag,method_msg,id,LOG_LOCAL0);
}

int xfp_check_conditions(int i2c_bus_name, int data_address, int size, int *data, const char *msg)
{
	unsigned int status;

	if (xfp_check_bus(i2c_bus_name, msg) != -1)
	{
		if (xfp_get_communication_status(i2c_bus_name, &status) < 0)
		{
			xfp_syslog(LOG_ERR, TAG_XFP, msg, "xfp_read(): xfp_get_communication_status()", i2c_bus_name);
			return -1;
		}
		if (status == XFP_COMM_DISABLED)
		{
			xfp_syslog(LOG_ERR, TAG_XFP, msg, "xfp_read(): Communication is disabled.", i2c_bus_name);
			return -1;
		}
		if (data_address < 0 || data_address > 0xff)
		{
			xfp_syslog(LOG_ERR, TAG_XFP, msg, "xfp_read(): Data address out of range", i2c_bus_name);
			return -1;
		}
		if (size != I2C_SMBUS_WORD_DATA && size != I2C_SMBUS_BYTE_DATA)
		{
			xfp_syslog(LOG_ERR, TAG_XFP, msg, "xfp_read(): Size out of range.", i2c_bus_name);
			return -1;
		}
		return 0;
	}
	else
		return -1;
}

int xfp_check_bus(int i2c_bus_name, const char * msg)
{
	if (i2c_bus_name < XFP_MOD_0 || i2c_bus_name > XFP_MOD_3)
	{
		xfp_syslog(LOG_ERR, TAG_XFP, msg, "xfp_read(): i2c_bus_name out of range", i2c_bus_name);
		return -1;
	}
	else
		return 0;

}

/*
 * It use one lock for each i2c_bus_name
 */
int xfp_read(int i2c_bus_name, int data_address, int size, int *data, const char *msg)
{
	int status;
	int fd_lock;
	char filelock_name[20];
	sprintf(filelock_name, "xfp_bus_lock_%d", i2c_bus_name);
	fd_lock = filelock_open(filelock_name);

	filelock_lock(fd_lock);

	if (xfp_check_conditions(i2c_bus_name, data_address, size, data, msg) != -1)
	{
		status = 0;
		if (i2c_read(i2c_bus_name, XFP_SLAVE_ADDRESS, data_address, size, data, 0) < 0)
		{
			xfp_syslog(LOG_ERR, TAG_XFP, msg, "xfp_read(): i2c_read()", i2c_bus_name);
			status = -1;
		}
	}
	else {
		status = -1;
	}

	filelock_close(fd_lock);
	return status;
}

/*
 * It use one lock for each i2c_bus_name
 */
int xfp_write(int i2c_bus_name, int data_address, int size, int *data, const char *msg)
{
	int status;
	int fd_lock;
	char filelock_name[20];
	sprintf(filelock_name, "xfp_bus_lock_%d", i2c_bus_name);
	fd_lock = filelock_open(filelock_name);

	filelock_lock(fd_lock);

	if (xfp_check_conditions(i2c_bus_name, data_address, size, data, msg) != -1)
	{
		status = 0;

		if (i2c_write(i2c_bus_name, XFP_SLAVE_ADDRESS, data_address, size, data, 0) < 0)
		{
			xfp_syslog(LOG_ERR, TAG_XFP, msg, "xfp_write(): i2c_write()", i2c_bus_name);
			status = -1;
		}
	}
	else {
		status = -1;
	}

	filelock_close(fd_lock);
	return status;
}

int xfp_get_optical_compatibility(int i2c_bus_name, int *compatibility)
{

	xfp_read(i2c_bus_name, XFP_TRANSCEIVER, I2C_SMBUS_BYTE_DATA, compatibility, "xfp_get_optical_compatibility(): ");
	return 0;
}

int xfp_enable_communication(int i2c_bus_name)
{
	xfp_gpio_write_bit(xfp_mod[i2c_bus_name].mod_desel, XFP_COMM_ENABLED,
			"Error in xfp_enable_communication(): gpio_write_bit()", i2c_bus_name);
	return 0;

}

int xfp_disable_communication(int i2c_bus_name)
{
	xfp_gpio_write_bit(xfp_mod[i2c_bus_name].mod_desel, XFP_COMM_DISABLED,
			"Error in xfp_disable_communication(): gpio_write_bit()", i2c_bus_name);
	return 0;
}

int xfp_get_communication_status(int i2c_bus_name, unsigned int *status)
{

	CHECK_PARAM_N(gpio_read_bit(xfp_mod[i2c_bus_name].mod_desel, status) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_communication_status(): gpio_read_bit()", i2c_bus_name,LOG_LOCAL0);

	return 0;
}

int xfp_enable_laser(int i2c_bus_name)
{
	int latch;

	CHECK_PARAM_N(ltc_enable_latch() < 0, LOG_ERR, TAG_XFP, "Error in xfp_enable_laser(): ltc_enable_latch()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_enable_laser(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_enable_laser(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(i2c_bus_name < XFP_MOD_0 || i2c_bus_name > XFP_MOD_3, LOG_ERR, TAG_XFP, "Error in xfp_enable_laser(): i2c_bus_name out of range", i2c_bus_name,LOG_LOCAL0);

	//Enable TX_DIS pin.
	xfp_gpio_write_bit(xfp_mod[i2c_bus_name].tx_dis, XFP_LASER_ENABLED,
			"Error in xfp_enable_laser(): gpio_write_bit", i2c_bus_name);
	usleep(200);

	return 0;
}

int xfp_mask_bit(int i2c_bus_name)
{
	int data_ff = 0xff;

	xfp_write(i2c_bus_name, 88, I2C_SMBUS_BYTE_DATA, &data_ff, "xfp_mask_bit(): ");

	xfp_write(i2c_bus_name, 92, I2C_SMBUS_BYTE_DATA, &data_ff, "xfp_mask_bit(): ");

	return 0;
}

int xfp_demask_bit(int i2c_bus_name)
{
	int data_00 = 0x00;

	xfp_write(i2c_bus_name, 88, I2C_SMBUS_BYTE_DATA, &data_00, "xfp_demask_bit(): ");

	xfp_write(i2c_bus_name, 92, I2C_SMBUS_BYTE_DATA, &data_00, "xfp_demask_bit(): ");

	return 0;
}

int xfp_disable_laser(int i2c_bus_name)
{
	int latch;
	int xfp_status;
	if (xfp_check_bus(i2c_bus_name, "xfp_disable_laser(): ") != -1)
	{
		CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_disable_laser(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

		CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_disable_laser(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);
		//Disable TX_DIS pin.
		xfp_gpio_write_bit(xfp_mod[i2c_bus_name].tx_dis, XFP_LASER_DISABLED,
				"Error in xfp_enable_laser(): gpio_write_bit", i2c_bus_name);

		usleep(200);
	}
	return 0;
}

int xfp_get_laser_status(int i2c_bus_name, unsigned int *status)
{
	int latch;
	int xfp_status = 255;

	CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

	xfp_read(i2c_bus_name, XFP_CONTROL_STATUS_0, I2C_SMBUS_BYTE_DATA, &xfp_status, "xfp_get_laser_status(): ");

	CHECK_PARAM_N(gpio_read_bit(xfp_mod[i2c_bus_name].tx_dis, status) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): gpio_read_bit()", i2c_bus_name,LOG_LOCAL0);

	*status = *status | (xfp_status & 0x40) >> XFP_CONTROL_STATUS_0_SOFT_TX_DISABLE;

	return 0;
}

int xfp_power_up(int i2c_bus_name)
{
	int latch;

	if (xfp_check_bus(i2c_bus_name, "xfp_power_up(): ") != -1)
	{
		CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_power_up(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

		CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_power_up(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

		xfp_gpio_write_bit(xfp_mod[i2c_bus_name].p_down_rst, XFP_PWR_UP,
				"Error in xfp_power_up(): gpio_write_bit()", i2c_bus_name);
		return 0;
	}
	else
		return -1;
}

int xfp_power_down(int i2c_bus_name)
{
	int latch;

	if (xfp_check_bus(i2c_bus_name, "xfp_power_down(): ") != -1)
	{
		CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_power_down(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

		CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_power_down(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

		xfp_gpio_write_bit(xfp_mod[i2c_bus_name].tx_dis, XFP_LASER_DISABLED, "Error in xfp_power_down(): set_bit()", i2c_bus_name);
		xfp_gpio_write_bit(xfp_mod[i2c_bus_name].p_down_rst, XFP_PWR_DOWN, "Error in xfp_power_down(): set_bit()", i2c_bus_name);

		return 0;
	}
	else
		return -1;
}

int xfp_get_power_status(int i2c_bus_name, unsigned int *status)
{
	int latch;

	if (xfp_check_bus(i2c_bus_name, "xfp_get_power_status(): ") != -1)
	{
		CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_power_status(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

		CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_get_power_status(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

		CHECK_PARAM_N(gpio_read_bit(xfp_mod[i2c_bus_name].p_down_rst, status) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_power_status(): gpio_read_bit()", i2c_bus_name,LOG_LOCAL0);

		return 0;
	}
	else
		return 0;
}

int xfp_get_presence_status(int i2c_bus_name, unsigned int *status)
{

	if (xfp_check_bus(i2c_bus_name, "xfp_get_presence_status(): ") != -1)
	{
		CHECK_PARAM_N(gpio_read_bit(xfp_mod[i2c_bus_name].mod_abs, status) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_presence_status(): gpio_read_bit()", i2c_bus_name,LOG_LOCAL0);

		return 0;
	}

	else
		return -1;
}

int xfp_get_loss_of_signal_status(int i2c_bus_name, unsigned int *status)
{
	if (xfp_check_bus(i2c_bus_name, "xfp_get_loss_of_signal_status(): ") != -1)
	{
		CHECK_PARAM_N(gpio_read_bit(xfp_mod[i2c_bus_name].rx_los, status) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_loss_of_signal_status(): gpio_read_bit()", i2c_bus_name,LOG_LOCAL0);

		return 0;
	}

	else
		return -1;
}

int xfp_reset(int i2c_bus_name)
{
	int latch;

	if (xfp_check_bus(i2c_bus_name, "xfp_reset(): ") != -1)
	{
		CHECK_PARAM_N(ltc_enable_latch() < 0, LOG_ERR, TAG_XFP, "Error in xfp_reset(): ltc_enable_latch()", i2c_bus_name,LOG_LOCAL0);

		CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_reset(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

		CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_reset(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

		xfp_read_interruption_flags(i2c_bus_name);

		xfp_gpio_write_bit(xfp_mod[i2c_bus_name].p_down_rst, 1,
				"Error in xfp_reset(): gpio_write_bit", i2c_bus_name);

		usleep(200);

		xfp_gpio_write_bit(xfp_mod[i2c_bus_name].p_down_rst, 0,
				"Error in xfp_reset(): gpio_write_bit", i2c_bus_name);

		usleep(500000);

		return 0;
	}
	else
		return -1;
}

int xfp_read_interruption(int i2c_bus_name, unsigned int *status)
{
	if (xfp_check_bus(i2c_bus_name, "xfp_read_interruption(): ") != -1)
	{
		CHECK_PARAM_N(gpio_read_bit(xfp_mod[i2c_bus_name].interrupt, status) < 0, LOG_ERR, TAG_XFP, "Error in xfp_read_interruption(): gpio_read_bit()", i2c_bus_name,LOG_LOCAL0);

		return 0;
	}

	else
		return -1;
}

int xfp_print_interruption_flags(int xfp_module)
{
	int j = 0;
	int i = 0;
	int bit = 0;
	int data = 0;

	printf("\nXFP module: %d\n", xfp_module);

	for (j = 0; j < 8; j++)
	{
		xfp_read(xfp_module, j + 80, I2C_SMBUS_BYTE_DATA, &data, "xfp_print_interruption_flags(): ");

		for (i = 0; i < 8; i++)
		{
			bit = (data >> i) & 1;

			if (bit)
				printf(" %s - ", flags_reg_xfp[j][i]);
		}
	}

	printf("\n");

	return 0;
}

int xfp_get_interruption_flags(int xfp_module, unsigned int xfp_interruption_flags[4][7])
{
	int j = 0;
	int i = 0;
	int bit = 0;
	int data = 0;

	for (j = 0; j < 8; j++)
	{
		xfp_read(xfp_module, j + 80, I2C_SMBUS_BYTE_DATA, &data, "xfp_get_interruption_flags(): ");

		for (i = 0; i < 8; i++)
		{
			bit = (data >> i) & 1;

			if (((j + 80 == 80) && (i == 0) && (bit == 1)))
				xfp_interruption_flags[xfp_module][0] = 1;
			if ((j + 80 == 80) && (i == 1) && (bit == 1))
				xfp_interruption_flags[xfp_module][1] = 1;

			if ((j + 80 == 81) && (i == 6) && (bit == 1))
				xfp_interruption_flags[xfp_module][2] = 1;
			if ((j + 80 == 81) && (i == 7) && (bit == 1))
				xfp_interruption_flags[xfp_module][3] = 1;

			if ((j + 80 == 84) && (i == 2) && (bit == 1))
				xfp_interruption_flags[xfp_module][4] = 1;
			if ((j + 80 == 84) && (i == 5) && (bit == 1))
				xfp_interruption_flags[xfp_module][5] = 1;
			if ((j + 80 == 84) && (i == 6) && (bit == 1))
				xfp_interruption_flags[xfp_module][6] = 1;
		}
	}

	return 0;
}

int xfp_read_interruption_flags(int xfp_module)
{
	int j = 0;
	int i = 0;
	int bit = 0;
	int data = 0;

	for (j = 0; j < 8; j++)
	{
		xfp_read(xfp_module, j + 80, I2C_SMBUS_BYTE_DATA, &data, "xfp_read_interruption_flags(): ");
	}

	return 0;
}

int xfp_get_ready_status(int i2c_bus_name, unsigned int *status)
{

	CHECK_PARAM_N(gpio_read_bit(xfp_mod[i2c_bus_name].mod_nr, status) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_ready_status(): gpio_read_bit()", i2c_bus_name,LOG_LOCAL0);

	return 0;
}

int xfp_get_actual_ber(int i2c_bus_name, int *ber)
{
	xfp_read(i2c_bus_name, XFP_ACTUAL_BER, I2C_SMBUS_BYTE_DATA, ber, "xfp_get_actual_ber(): ");

	*ber = 0x4c;
	/*int lsb,msb;

	 lsb = 15;
	 lsb &= current_value; 		// 	get LSB
	 msb = current_value>>4; 	// 	get MSB
	 printf("ber: %fx10E-%f\n",((float)msb/16),(float)lsb);*/

	return 0;
}

int xfp_get_tx_bias(int i2c_bus_name, int *bias)
{

	if (xfp_read(i2c_bus_name, XFP_TX_BIAS, I2C_SMBUS_WORD_DATA, bias, "xfp_get_tx_bias(): ") == 0)
		return 0;
	else
		return -1;
}

int xfp_set_wavelength(int i2c_bus_name, int wavelength) //           <------------controlar wavelength
{

	CHECK_PARAM_N(wavelength < 0 || wavelength > 0xffff, LOG_ERR, TAG_XFP, "Error in xfp_set_wavelength(): wavelength out of range", i2c_bus_name,LOG_LOCAL0);

	if (xfp_write(i2c_bus_name, XFP_WAVELENGTH_SET, I2C_SMBUS_WORD_DATA, &wavelength, "xfp_set_wavelength(): ") == 0)
		return 0;
	else
		return -1;
}

int xfp_get_wavelength(int i2c_bus_name, int *wavelength) //           <------------controlar wavelength
{
	int page;

	CHECK_PARAM_N(xfp_get_page(i2c_bus_name, &page) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_wavelength(): xfp_get_page()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(page != 1, LOG_ERR, TAG_XFP, "Error in xfp_get_wavelength(): page is not 1", i2c_bus_name,LOG_LOCAL0);

	xfp_read(i2c_bus_name, XFP_WAVELENGTH_RD, I2C_SMBUS_WORD_DATA, wavelength, "xfp_get_wavelength(): ");

	*wavelength /= 20;

	return 0;
}

int xfp_get_device_tech(int i2c_bus_name, int *status)
{
	*status = 0;
	return xfp_read(i2c_bus_name, XFP_DEVICE_TECH, I2C_SMBUS_BYTE_DATA, status, "xfp_get_device_tech(): ");
}

int xfp_set_device_tech(int i2c_bus_name, int status)
{
	return xfp_write(i2c_bus_name, XFP_DEVICE_TECH, I2C_SMBUS_BYTE_DATA, &status, "xfp_set_device_tech(): ");
}

int xfp_get_encoding_support(int i2c_bus_name, int *encoding_support)
{
	int page;

	CHECK_PARAM_N(xfp_get_page(i2c_bus_name, &page) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_encoding_support(): xfp_get_page()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(page != 1, LOG_ERR, TAG_XFP, "Error in xfp_get_encoding_support(): page is not 1", i2c_bus_name,LOG_LOCAL0);

	xfp_read(i2c_bus_name, XFP_ENCODING, I2C_SMBUS_WORD_DATA, encoding_support, "xfp_get_encoding_support(): ");

	/*tabla 50:
	 bit 7: 64B/66N
	 bit 6: 8B10B
	 bit 5: SONET
	 bit 4: NRZ
	 bit 3: RZ
	 */
	return 0;
}

int xfp_get_minimum_bit_rate(int i2c_bus_name, int *minimum_bit_rate)
{
	/*
	 Minimum bit rate, units of 100 MBits/s.
	 byte 140
	 The minimum bit rate (BR, minimum) is specified in units of 100 Megabits
	 per second, rounded off to the nearest 100 Megabits per second.
	 The bit rate includes those bits necessary to encode and delimit the signal as well
	 as those bits carrying data information. A value of 0 indicates that the minimum
	 bit rate is not specified and must be determined from the transceiver
	 technology. The actual information transfer rate will depend on the encoding of the data,
	 as defined by the encoding value. Specific CDR rate support is indicated in Byte 164.

	 */
	int page;

	CHECK_PARAM_N(xfp_get_page(i2c_bus_name, &page) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_minimum_bit_rate(): xfp_get_page()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(page != 1, LOG_ERR, TAG_XFP, "Error in xfp_get_maximum_bit_rate(): page is not 1", i2c_bus_name,LOG_LOCAL0);

	xfp_read(i2c_bus_name, XFP_BR_MIN, I2C_SMBUS_WORD_DATA, minimum_bit_rate, "xfp_get_minimum_bit_rate(): ");

	return 0;
}

int xfp_get_maximum_bit_rate(int i2c_bus_name, int *maximum_bit_rate)
{
	/*
	 Maximum bit rate, units of 100 MBits/s.
	 byte 141
	 The minimum bit rate (BR, minimum) is specified in units of 100 Megabits
	 per second, rounded off to the nearest 100 Megabits per second.
	 The bit rate includes those bits necessary to encode and delimit the signal as well
	 as those bits carrying data information. A value of 0 indicates that the minimum
	 bit rate is not specified and must be determined from the transceiver
	 technology. The actual information transfer rate will depend on the encoding of
	 the data, as defined by the encoding value. Specific CDR rate
	 support is indicated in Byte 164.

	 */
	int page;

	CHECK_PARAM_N(xfp_get_page(i2c_bus_name, &page) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_maximum_bit_rate(): xfp_get_page()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(page != 1, LOG_ERR, TAG_XFP, "Error in xfp_get_maximum_bit_rate(): page is not 1", i2c_bus_name,LOG_LOCAL0);

	xfp_read(i2c_bus_name, XFP_BR_MAX, I2C_SMBUS_WORD_DATA, maximum_bit_rate, "xfp_get_maximum_bit_rate(): ");

	return 0;
}

int xfp_set_page(int i2c_bus_name, int page)
{

	CHECK_PARAM_N(page < 0x00 || page > 0xFF, LOG_ERR, TAG_XFP, "Error in xfp_set_page(): Page Out of Range", i2c_bus_name,LOG_LOCAL0);

	xfp_write(i2c_bus_name, XFP_PAGE_SELECT_BYTE, I2C_SMBUS_BYTE_DATA, &page, "xfp_set_page(): ");

	return 0;
}

int xfp_get_page(int i2c_bus_name, int *page)
{

	xfp_read(i2c_bus_name, XFP_PAGE_SELECT_BYTE, I2C_SMBUS_BYTE_DATA, page, "xfp_get_page(): ");

	return 0;
}

int xfp_set_threshold(int i2c_bus_name, int reg_address, int value)
{

	CHECK_PARAM_N(reg_address < XFP_BIAS_HIGH_ALARM || reg_address > XFP_TX_POWER_LOW_WARNING, LOG_ERR, TAG_XFP, "Error in xfp_set_threshold(): reg_address out of range",
			i2c_bus_name,LOG_LOCAL0);

	xfp_write(i2c_bus_name, reg_address, I2C_SMBUS_BYTE_DATA, &value, "xfp_set_threshold(): ");

	return 0;
}

int xfp_get_int_flag(int i2c_bus_name, int reg_address, int bit_pos, int* bit_val)
{

	CHECK_PARAM_N(bit_pos < 0 || bit_pos > 7, LOG_ERR, TAG_XFP, "Error in xfp_get_int_flag(): bit_pos out of range", i2c_bus_name,LOG_LOCAL0);

	int rsvd_mask = 0xFF;

	CHECK_PARAM_N(reg_address < 80 || reg_address > 87, LOG_ERR, TAG_XFP, "Error in xfp_get_int_flag(): reg_address out of range", i2c_bus_name,LOG_LOCAL0);

	if (reg_address == 80 || reg_address == 82)
	{
		rsvd_mask = 0xCF;
	}
	else if (reg_address == 81 || reg_address == 83)
	{
		rsvd_mask = 0xFC;
	}
	else if (reg_address == 85)
	{
		rsvd_mask = 0xE0;
	}

	unsigned int status;

	int reg_value;

	xfp_read(i2c_bus_name, reg_address, I2C_SMBUS_BYTE_DATA, &reg_value, "xfp_get_int_flag(): ");

	reg_value |= rsvd_mask;

	CHECK_PARAM_N(get_bit(reg_value, bit_pos, (unsigned int*)bit_val) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_int_flag(): get_bit()", i2c_bus_name,LOG_LOCAL0);

	return 0;
}

int xfp_set_mask(int i2c_bus_name, int reg_address, int bit_pos, int bit_val)
{
	CHECK_PARAM_N(bit_pos < 0 || bit_pos > 7, LOG_ERR, TAG_XFP, "Error in xfp_set_mask(): bit_pos out of range", i2c_bus_name,LOG_LOCAL0);

	int rsvd_mask = 0xFF;

	CHECK_PARAM_N(reg_address < 88 || reg_address > 95, LOG_ERR, TAG_XFP, "Error in xfp_set_mask(): reg_address out of range", i2c_bus_name,LOG_LOCAL0);

	if (reg_address == 88 || reg_address == 90)
	{
		rsvd_mask = 0xCF;
	}
	else if (reg_address == 89 || reg_address == 91)
	{
		rsvd_mask = 0xFC;
	}
	else if (reg_address == 93)
	{
		rsvd_mask = 0xE0;
	}

	unsigned int status;

	int reg_value;

	xfp_read(i2c_bus_name, reg_address, I2C_SMBUS_BYTE_DATA, &reg_value, "xfp_set_mask(): ");

	reg_value |= rsvd_mask;

	CHECK_PARAM_N(set_bit_val((unsigned int*)&reg_value, bit_pos, bit_val) < 0, LOG_ERR, TAG_XFP, "Error in xfp_set_mask(): set_bit_val()", i2c_bus_name,LOG_LOCAL0);

	xfp_write(i2c_bus_name, reg_address, I2C_SMBUS_BYTE_DATA, &reg_value, "xfp_set_mask(): ");

	return 0;
}

int xfp_get_serial_number(int i2c_bus_name)
{

	int reg_value;
	int i, reg_dir;
	char serial[16];
	reg_dir = 196;

	int latch;

	CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

	memset(serial, '\0', sizeof(char) * 16);
	for (i = 0; i < 16; i++)
	{
		xfp_read(i2c_bus_name, reg_dir, I2C_SMBUS_BYTE_DATA, &reg_value, "xfp_get_serial_number(): ");

		if (isalpha((char)reg_value) || isdigit((char)reg_value))
			serial[i] = (char) reg_value;
		else
			serial[i] = '\0';

		reg_dir++;
	}

	printf("%s", serial);
	return 0;

}

int xfp_get_date_code(int i2c_bus_name)
{

	int reg_value;
	int i, reg_dir;
	char serial[8];
	reg_dir = 212;

	int latch;

	CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

	memset(serial, '\0', sizeof(char) * 8);
	for (i = 0; i < 8; i++)
	{
		xfp_read(i2c_bus_name, reg_dir, I2C_SMBUS_BYTE_DATA, &reg_value, "xfp_get_date_code(): ");

		if (isalpha((char)reg_value) || isdigit((char)reg_value))
			serial[i] = (char) reg_value;
		else
			serial[i] = '\0';

		reg_dir++;
	}

	printf("%c%c-%c%c-%c%c", serial[0], serial[1], serial[2], serial[3], serial[4], serial[5]);
	return 0;

}

int xfp_get_revision_level(int i2c_bus_name)
{

	int reg_value;
	int i, reg_dir;
	char number[2];
	reg_dir = 184;

	int latch;

	CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

	for (i = 0; i < 2; i++)
	{
		number[i] = '\0';
	}

	for (i = 0; i < 2; i++)
	{

		xfp_read(i2c_bus_name, reg_dir, I2C_SMBUS_BYTE_DATA, &reg_value, "xfp_get_revision_level(): ");
		reg_dir++;

		number[i] = (char) reg_value;
		/*if(isalpha((char)reg_value) || isdigit((char)reg_value))
		 number[i] = (char)reg_value;
		 else
		 number[i] = '\0';
		 */
		//printf("%x\n",reg_value);
	}
	printf("%c%c", number[0], number[1]);

	return 0;
}

int xfp_get_part_number(int i2c_bus_name)
{

	int reg_value;
	int i, reg_dir;
	char number[16];
	reg_dir = 168;

	int latch;

	CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

	for (i = 0; i < 16; i++)
	{
		number[i] = '\0';
	}

	for (i = 0; i < 16; i++)
	{

		xfp_read(i2c_bus_name, reg_dir, I2C_SMBUS_BYTE_DATA, &reg_value, "xfp_get_part_number(): ");
		reg_dir++;

		if (isalpha((char)reg_value) || isdigit((char)reg_value) || (char) reg_value == '-')
			number[i] = (char) reg_value;
	}

	printf("%s", number);
	return 0;

}

int xfp_get_vendor_oui(int i2c_bus_name)
{

	int reg_value;
	int i, reg_dir;
	int number[3];
	reg_dir = 165;

	int latch;

	CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

	for (i = 0; i < 3; i++)
	{

		xfp_read(i2c_bus_name, reg_dir, I2C_SMBUS_BYTE_DATA, &reg_value, "xfp_get_vendor(): ");
		reg_dir++;
		number[i] = reg_value;

	}

	printf("%x-%x-%x", number[0], number[1], number[2]);
	return 0;
}

int xfp_get_vendor_name(int i2c_bus_name)
{

	int reg_value;
	int i, reg_dir;
	char number[16];
	reg_dir = 148;

	int latch;

	CHECK_PARAM_N(ltc_get_latch_status(&latch) < 0, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): xfp_get_latch_status()", i2c_bus_name,LOG_LOCAL0);

	CHECK_PARAM_N(latch == LTC_DISABLED, LOG_ERR, TAG_XFP, "Error in xfp_get_laser_status(): Latch is disabled", i2c_bus_name,LOG_LOCAL0);

	for (i = 0; i < 16; i++)
	{
		number[i] = '\0';
	}

	for (i = 0; i < 16; i++)
	{

		xfp_read(i2c_bus_name, reg_dir, I2C_SMBUS_BYTE_DATA, &reg_value, "xfp_get_vendor_name(): ");
		reg_dir++;

		if (isalpha((char)reg_value) || isdigit((char)reg_value) || (char) reg_value == '-')
			number[i] = (char) reg_value;
	}

	printf("%s", number);
	return 0;
}

int xfp_set_xfi_loopback(int i2c_bus_name)
{
	int current_value;

	xfp_read(i2c_bus_name, XFP_TIMING_SCTRL_STSF, I2C_SMBUS_BYTE_DATA, &current_value, "xfp_set_xfi_loopback(): ");

	int new_value = (current_value & 0xF9);
	new_value |= 0x02;

	xfp_write(i2c_bus_name, XFP_TIMING_SCTRL_STSF, I2C_SMBUS_BYTE_DATA, &new_value, "xfp_set_xfi_loopback(): ");

	return 0;
}

int xfp_set_line_loopback(int i2c_bus_name)
{

	int current_value;

	xfp_read(i2c_bus_name, XFP_TIMING_SCTRL_STSF, I2C_SMBUS_BYTE_DATA, &current_value, "xfp_set_line_loopback(): ");

	int new_value = (current_value & 0xF9);
	new_value |= 0x04;

	xfp_write(i2c_bus_name, XFP_TIMING_SCTRL_STSF, I2C_SMBUS_BYTE_DATA, &new_value, "xfp_set_line_loopback(): ");

	return 0;
}

int xfp_set_normal_operation(int i2c_bus_name)
{

	int current_value;

	xfp_read(i2c_bus_name, XFP_TIMING_SCTRL_STSF, I2C_SMBUS_BYTE_DATA, &current_value, "xfp_set_normal_operation(): ");

	int new_value = (current_value & 0xF9);

	xfp_write(i2c_bus_name, XFP_TIMING_SCTRL_STSF, I2C_SMBUS_BYTE_DATA, &new_value, "xfp_set_normal_operation(): ");

	return 0;
}

int xfp_initialize(int i2c_bus_name, int wavelength, int data_rate, int xfi_loopback_enable)
{
	int status;

	if (xfp_get_presence_status(i2c_bus_name, &status) < 0)
		return -1;

	if (status == 1)
		return -1;

	if (xfp_enable_communication(i2c_bus_name) < 0)
		return -1;

	if (xfp_reset(i2c_bus_name) < 0)
		return -1;

	if (xfp_set_wavelength(i2c_bus_name, wavelength) < 0)
		return -1;

	if (xfp_set_data_rate(i2c_bus_name, data_rate) < 0)
		return -1;

	if (xfi_loopback_enable)
	{

		if (xfp_set_xfi_loopback(i2c_bus_name) < 0)
			return -1;
	}
	else
	{

		if (xfp_set_normal_operation(i2c_bus_name) < 0)
			return -1;
	}

	if (xfp_enable_laser(i2c_bus_name) < 0)
	{
		//ver tema del reset
	}

	return 0;
}

void xfp_set_loopback(int enable, int slices[])
{

	int xfp_module;
	for (xfp_module = 1; xfp_module < 5; xfp_module++)
	{
		// If the slice is active or all the slices are
		// active then enable or disable loopback
		if (slices[xfp_module] == 1 || slices[0] == 1)
		{
			if (enable)
			{
				printf("XFP %d enable XFI loopback and laser disable.\n", xfp_module);

				xfp_set_xfi_loopback(xfp_module - 1);

				xfp_disable_laser(xfp_module - 1);
			}
			else
			{
				printf("XFP %d normal operation and enable laser.\n", xfp_module);

				xfp_set_normal_operation(xfp_module - 1);

				xfp_enable_laser(xfp_module - 1);
			}
		}
	}
}

/*
 * Write to gpio tmp_bus. Safe Access (Mutual Exclusion)
 */
int xfp_gpio_write_bit(int port, unsigned value, const char* error_msg, int i2c_bus_name)
{
	//int fd_lock;
	//fd_lock = filelock_open("xfp_gpio_lock");
	//filelock_lock(fd_lock);

	CHECK_PARAM_N(gpio_write_bit(port, value) < 0, LOG_ERR, TAG_XFP, error_msg, i2c_bus_name,LOG_LOCAL0);

	//filelock_close(fd_lock);
}
