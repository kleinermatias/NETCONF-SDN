#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edfatest.h"
#include "../../lib/gpio/gpio.h"
#include "../../lib/edfa/edfa.h"
#include <fcntl.h>

#include <unistd.h>
#include "../../include/util.h"
#include <termios.h>
#include <errno.h>
#include "../../ltc/ltc.h"


//static FILE *fd = 0;


int main(int argc, char **argv)
{
	unsigned int value;
	float f;
	char info[256];
	int stage = 1;
	char test[5]= "ver\n";
	char rdata[512];
	int fd;
	char tty[]="/dev/ttyAL2";
	unsigned int i;

	char file_name[30] = { "edfatest.txt" };

	//Open device file
//	CHECK_PARAM((fd = open(tty, O_RDWR | O_NDELAY | O_NONBLOCK)) < 0, LOG_ERR, TAG_EDFA,"Error in edfa_send_command: Open Failed");
//	fd=open(tty, O_RDWR | O_NONBLOCK);
//	fd=open(tty, O_RDWR | O_NOCTTY | O_NDELAY);
    fd=open(tty, O_RDWR | O_NOCTTY | O_NONBLOCK);
//	ioctl(fd);
//	fdatasync(fd);

	//Set terminal parameters
	edfa_set_terminal(fd);

	edfa_clean_fifo(fd);

	/*
	for(i=0;i<1024;i++)
	{
		rdata[i]='A';
	}
*/

//	fflush(fd);

	latch_optical_modules_enable();
//	gpio_write_bit(LTC_BIT_STATUS, LTC_ENABLE);
	usleep(250000);
//	gpio_write_bit(EDFA_PIN_RESET, 0);
//	usleep(250000);
//	gpio_write_bit(EDFA_PIN_RESET, 1);
//	usleep(250000);
//	gpio_write_bit(EDFA_PIN_SHUTDOWN, 1);
//	usleep(250000);
//	gpio_read_bit(EDFA_PIN_LOSS_INPUT, &value);
//	usleep(250000);
//	printf("Loss-of-input status (0=LOI): %d\n", value);


	printf("Hardware reset...\n");

	edfa_reset_hw();

	printf("Software reset to default values...\n");

	edfa_reset_factory_default_values(fd, rdata);

	printf("Firmware reset...\n");

	edfa_reset_firmware(fd, rdata);


	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

//	fflush(NULL);

	usleep(100000);

/*
	CHECK_PARAM(edfa_set_echo(fd, EDFA_ECHO_OFF, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_echo: edfa_set_echo()");
	usleep(100000);
	printf("edfa_set_echo: %s\n", rdata);
	usleep(100000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}
*/

	CHECK_PARAM(edfa_get_information(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_information: edfa_get_information()");
	usleep(100000);
	printf("edfa_get_information: %s\n", rdata);
	usleep(100000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

/*
	CHECK_PARAM(edfa_get_baud_rate(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_echo: edfa_get_echo()");
	usleep(1000000);
	printf("edfa_get_baud_rate: %s\n", rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}
*/

	/*
	CHECK_PARAM(edfa_set_splim(fd, 1, 4.0, rdata)<0,LOG_ERR, TAG_EDFA, "Error in edfa_set_splim()");
	usleep(1000000);
	printf("edfa_set_splim: %s\n", rdata);
	usleep(500000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}
*/

	CHECK_PARAM(edfa_set_mode_and_val(fd, EDFA_MODE_P, 3.5, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_mode_and_val()");
	usleep(100000);
	printf("edfa_set_mode_and_val: %s\n", rdata);
	usleep(100000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

/*
	CHECK_PARAM(edfa_get_splim(fd, 1, rdata)<0,LOG_ERR, TAG_EDFA, "Error in edfa_get_splim()");
	usleep(1000000);
	printf("edfa_get_splim: %s\n", rdata);
	usleep(500000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}
*/

	CHECK_PARAM(edfa_get_mode(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_mode: edfa_get_mode()");
	usleep(100000);
	printf("edfa_get_mode: %s\n", rdata);
	usleep(100000);

	edfa_clean_data(rdata);
	printf("edfa_get_mode (clean data): %s\n", rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_input_power(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_input_power()");
	usleep(1000000);
	printf("edfa_get_input_power: %s\n", rdata);
	usleep(500000);

	edfa_clean_data(rdata);
	printf("edfa_get_input_power (clean data): %s\n", rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_output_power(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_output_power()");
	usleep(100000);
	printf("edfa_get_output_power: %s\n", rdata);
	usleep(100000);

	edfa_clean_data(rdata);
	printf("edfa_get_output_power (clean data): %s\n", rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_case_temperature(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_case_temp()");
	usleep(100000);
	printf("edfa_get_case_temp: %s\n", rdata);
	usleep(100000);

	edfa_clean_data(rdata);
	printf("edfa_get_case_temp (clean data): %s\n", rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_loss_input_alarm(&value)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_loss_input_alarm()");
	usleep(100000);
	printf("edfa_get_loss_input_alarm (hardware pin): %u\n", value);
	usleep(100000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_alarm_information(fd, EDFA_ALARM_LOS, EDFA_ALARM_PARAM_STA, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_alarm_information()");
	usleep(100000);
	printf("edfa_get_los_alarm (register): %s\n", rdata);
	usleep(100000);

	edfa_clean_data(rdata);
	printf("edfa_get_los_alarm (clean data): %s\n", rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_alarm_information(fd, EDFA_ALARM_LOP, EDFA_ALARM_PARAM_STA, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_alarm_information()");
	usleep(100000);
	printf("edfa_get_lop_alarm: %s\n", rdata);
	usleep(100000);

	edfa_clean_data(rdata);
	printf("edfa_get_lop_alarm (clean data): %s\n", rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_amplifier_status(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_amplifier_status()");
	usleep(100000);
	printf("edfa_get_amplifier_status: %s\n", rdata);
	usleep(100000);

	edfa_clean_data(rdata);
	printf("edfa_get_amplifier_status (clean data): %s\n", rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	printf("End of EDFA test application.\n");

	/*

	CHECK_PARAM(edfa_get_splim(fd, 1, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_mode: edfa_get_splim()");
	usleep(1000000);
	printf("edfa_get_splim: %s\n", rdata);
	usleep(500000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_set_splim(fd, 1, 3.5, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_splim: edfa_set_splim()");
	usleep(1000000);
	printf("edfa_set_splim: %s\n", rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_splim(fd, 1, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_splim: edfa_get_splim()");
	usleep(1000000);
	printf("edfa_get_splim: %s\n", rdata);
	usleep(500000);

//	fflush(fd);
	/*
	CHECK_PARAM(edfa_set_echo(fd, EDFA_ECHO_OFF)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_echo: edfa_set_echo()");
	printf("edfa_set_echo: ECHO OFF\n");

	usleep(500000);

	printf("\n");

//	printf("punto0\n");

	for(i=0; i<1024; i++)
	{
		rdata[i]='\0';
	}

	edfa_get_baud_rate(fd, rdata);
	usleep(500000);
	printf("%s", rdata);
	printf("\n");

	for(i=0; i<1024; i++)
	{
		printf("%c", rdata[i]);
	}

	printf("\n");

	for(i=0; i<1024; i++)
	{
		rdata[i]='\0';
	}

//	edfa_get_information(fd, rdata);
//	usleep(500000);
//	printf("%s", rdata);
//	printf("\n");
//
//	for(i=0; i<1024; i++)
//	{
//		rdata[i]='\0';
//	}

	edfa_get_mode(fd, rdata);
	usleep(500000);
	printf("%s", rdata);
	printf("\n");

	for(i=0; i<1024; i++)
	{
		rdata[i]='\0';
	}

	edfa_get_signal_gain(fd, rdata);
	usleep(500000);
	printf("%s", rdata);
	printf("\n");

	for(i=0; i<1024; i++)
	{
		rdata[i]='\0';
	}

	edfa_set_mode_and_gain(fd, EDFA_MODE_G, 5, rdata);

	edfa_get_mode(fd, rdata);
	usleep(500000);
	printf("%s", rdata);
	printf("\n");

	for(i=0; i<1024; i++)
	{
		rdata[i]='\0';
	}

	edfa_get_signal_gain(fd, rdata);
	usleep(500000);
	printf("%s", rdata);
	printf("\n");


//	edfa_get_information();
*/

	//Close File
	CHECK_PARAM(close(fd)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_send_command: Close Failed");


}
