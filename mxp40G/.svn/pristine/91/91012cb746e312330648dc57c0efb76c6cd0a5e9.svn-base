#include "txp.h"
#include "../util/util.h"
#include "../i2c/i2crw.h"
#include "../gpio/gpio.h"
#include "../ltc/ltc.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "../utils/utils.h"
#include "../utils/filelock.h"

#ifdef TESTING
extern int n_call;
extern int m_call;
#endif

struct tm start_oclaro_reset_time;
struct tm end_oclaro_reset_time;
struct tm diff_time;
int debug_txp = 1;

int txp_set_laser_itu_channel(float channel)
{
	union laser_itu_channel laser_itu;
	int reply_data_length = 3;
	unsigned char request_data[3];
	unsigned char reply_data[reply_data_length];
	int i = 0;

	laser_itu.fields.band = 0x43; //MI 5000XM supports only C-band
	laser_itu.fields.channel_integer = (int) channel;
	laser_itu.fields.channel_fractional = fabsf((channel - laser_itu.fields.channel_integer)) / 0.0625;

	for (i = 0; i < 3; i++)
	{
		request_data[i] = laser_itu.data[2 - i];
	}

	txp_enter_protected_mode();

	txp_full_transaction (0x49, request_data, 3, reply_data, reply_data_length);

	txp_exit_protected_mode();

	if (debug_txp)
	{
		printf("Band: %c\n", laser_itu.fields.band);
		printf("Channel integer: %d\n", laser_itu.fields.channel_integer);
		printf("Channel fractional: %d\n", laser_itu.fields.channel_fractional);
	}

	return txp_status(reply_data[0], "set_laser_itu_channel");
}

int txp_read_laser_itu_channel(union laser_itu_channel *laser_itu)
{
	int reply_data_length = 6;
	unsigned char *request_data;
	unsigned char reply_data[reply_data_length];
	int i = 0;

	txp_full_transaction (0x4A, request_data, 0, reply_data, reply_data_length);

	for (i = 0; i < reply_data_length - 3; i++)
	{
		laser_itu->data[2 - i] = reply_data[i + 2];
	}

	laser_itu->fields.channel = laser_itu->fields.channel_integer + (laser_itu->fields.channel_fractional / 0.0625);

	if (debug_txp)
	{
		printf("-----------READ LASER ITU CHANNEL------------\n");
		printf("Band: %c\n", laser_itu->fields.band);
		printf("Channel: %.2f\n", laser_itu->fields.channel);
		printf("------------------------------------------------\n");
	}

	return txp_status(reply_data[0], "read_laser_itu_channel");
}

int txp_set_receive_itu_channel(float channel)
{
	union laser_itu_channel laser_itu;
	int reply_data_length = 3;
	unsigned char request_data[4];
	unsigned char reply_data[reply_data_length];
	int i = 0;

	laser_itu.fields.band = 0x43; //MI 5000XM supports only C-band
	laser_itu.fields.channel_integer = (int) channel;
	laser_itu.fields.channel_fractional = fabsf((channel - laser_itu.fields.channel_integer)) / 0.0625;

	request_data[0] = 0x49;

	for (i = 0; i < 3; i++)
	{
		request_data[i + 1] = laser_itu.data[2 - i];
	}

	txp_enter_vendor_protected_mode();

	txp_full_transaction (0xF0, request_data, 4, reply_data, reply_data_length);

	txp_exit_protected_mode();

	if (debug_txp)
	{
		printf("Band: %c\n", laser_itu.fields.band);
		printf("Channel integer: %d\n", laser_itu.fields.channel_integer);
		printf("Channel fractional: %d\n", laser_itu.fields.channel_fractional);
	}

	return txp_status(reply_data[0], "set_receive_itu_channel");
}

int txp_read_receiver_itu_channel(union laser_itu_channel *laser_itu)
{
	int reply_data_length = 6;
	unsigned char request_data[1];
	unsigned char reply_data[reply_data_length];
	int i = 0;

	request_data[0] = 0x4A;

	txp_full_transaction (0xF0, request_data, 1, reply_data, reply_data_length);

	for (i = 0; i < reply_data_length - 3; i++)
	{
		laser_itu->data[2 - i] = reply_data[i + 2];
	}

	laser_itu->fields.channel = laser_itu->fields.channel_integer + (laser_itu->fields.channel_fractional / 0.0625);

	if (debug_txp)
	{
		printf("--------------READ RECEIVER ITU CHANNEL------------\n");
		printf("Band: %c\n", laser_itu->fields.band);
		printf("Channel: %.2f\n", laser_itu->fields.channel);
		printf("---------------------------------------------------\n");
	}

	return txp_status(reply_data[0], "read_receiver_itu_channel");
}

int txp_read_laser_itu_channel_spacing(float *spacing)
{
	int reply_data_length = 4;
	unsigned char *request_data;
	unsigned char reply_data[reply_data_length];

	txp_full_transaction (0xA6, request_data, 0, reply_data, reply_data_length);

	*spacing = ((reply_data[2] >> 4) & 0xF) + ((reply_data[2] & 0xF) / 0.0625);

	return txp_status(reply_data[0], "read_laser_itu_channel_spacing");
}

int txp_read_power_rail_monitor(struct power_rails *power_values)
{

	int reply_data_length = 15;
	unsigned char request_data[1];
	unsigned char reply_data[reply_data_length];
	int i = 0;

	request_data[0] = 0x0D;
	request_data[1] = 0;

	txp_full_transaction (0xF1, request_data, 2, reply_data, reply_data_length);

	power_values->voltage_3v3 = 0;
	power_values->current_3v3 = 0;
	power_values->voltage_5v = 0;
	power_values->current_5v = 0;
	power_values->voltage_n5v2 = 0;
	power_values->current_n5v2 = 0;

	for (i = 0; i < reply_data_length - 3; i++)
	{
		power_values->data[i] = reply_data[i + 2];

		if (i >= 0 & i <= 1)
		{
			power_values->voltage_3v3 += power_values->data[i] << 8 * (1 - i);
		}
		if (i >= 2 & i <= 3)
		{
			power_values->current_3v3 += power_values->data[i] << 8 * (3 - i);
		}
		if (i >= 4 & i <= 5)
		{
			power_values->voltage_5v += power_values->data[i] << 8 * (5 - i);
		}
		if (i >= 6 & i <= 7)
		{
			power_values->current_5v += power_values->data[i] << 8 * (7 - i);
		}
		if (i >= 8 & i <= 9)
		{
			power_values->voltage_n5v2 += power_values->data[i] << 8 * (9 - i);
		}
		if (i >= 10 & i <= 11)
		{
			power_values->current_n5v2 += power_values->data[i] << 8 * (11 - i);
		}
	}

	if (debug_txp)
	{
		printf("-------- POWER STATUS LEVELS --------------\n");
		printf("Voltage of 3.3V [mV]: %u\n", power_values->voltage_3v3);
		printf("Current of 3.3V [mA]: %u\n", power_values->current_3v3);
		printf("Voltage of 5V [mV]: %u\n", power_values->voltage_5v);
		printf("Current of 5V [mA]: %u\n", power_values->current_5v);
		printf("Voltage of -5.2V [mV]: -%u\n", power_values->voltage_n5v2);
		printf("Current of -5.2V [mA]: %u\n", power_values->current_n5v2);
		printf("--------------------------------------------\n");
	}
	return 0;
}

int txp_read_prbs_error_counters(unsigned char sel, union error_prbs_counters_union *error_prbs_counters)
{
	//PARA PRBS Ingress counter 	-> sel=0x04
	//PARA PRBS Egress counter 		-> sel=0x05
	//PARA Flags				 	-> sel=0x06

	int reply_data_length = 21;
	unsigned char request_data[1];
	unsigned char reply_data[reply_data_length];
	int i = 0;

	request_data[0] = 0x69;
	request_data[1] = sel;

	txp_full_transaction (0xF0, request_data, 2, reply_data, reply_data_length);

	error_prbs_counters->fields.bit_count = 0;
	error_prbs_counters->fields.bit_error = 0;
	error_prbs_counters->fields.bit_error_ones = 0;

	for (i = 0; i < reply_data_length - 3; i++)
	{
		error_prbs_counters->data[i] = reply_data[i + 2];

		if (i >= 0 & i <= 5)
		{
			error_prbs_counters->fields.bit_count += error_prbs_counters->data[i] << 8 * (5 - i);
		}
		if (i >= 6 & i <= 11)
		{
			error_prbs_counters->fields.bit_error += error_prbs_counters->data[i] << 8 * (11 - i);
		}
		if (i >= 12 & i <= 17)
		{
			error_prbs_counters->fields.bit_error_ones += error_prbs_counters->data[i] << 8 * (17 - i);
		}
	}

	if (debug_txp)
	{
		if (sel == 0x06)
		{
			printf("Egress PRBS counter in sync: %x\n", error_prbs_counters->fields.Egress_PRBS_sync);
			printf("Latched error detected: %x\n", error_prbs_counters->fields.Latched_error_detect_1);
			printf("Ingress PRBS counter in sync: %x\n", error_prbs_counters->fields.Ingress_PRBS_sync);
			printf("Latched error detected: %x\n", error_prbs_counters->fields.Latched_error_detect_2);
			printf("----------------------------------------------\n");
		}
		else
		{
			if (sel == 0x04)
			{
				printf("--------INGRESS PRBS ERROR COUNTER------------\n");
			}

			else if (sel == 0x05)
			{
				printf("--------EGRESS PRBS ERROR COUNTER------------\n");
			}

			printf("BIT COUNT SINCE LAST READ: %llu\n", error_prbs_counters->fields.bit_count);
			printf("BIT ERROR COUNT SINCE LAST READ: %llu\n", error_prbs_counters->fields.bit_error);
			printf("BIT ERROR COUNT BY ONES SINCE LAST READ: %llu\n", error_prbs_counters->fields.bit_error_ones);
			printf("INSTANTANEOUS BER: %.3e\n", (double) ((error_prbs_counters->fields.bit_error / error_prbs_counters->fields.bit_count)));
			printf("----------------------------------------------\n");
		}
	}
	return 0;
}

int txp_read_dsp_status(union dsp_status_union *dspstat)
{
	int reply_data_length = 7;
	unsigned char request_data[1];
	unsigned char reply_data[reply_data_length];
	int i = 0;

	request_data[0] = 0x50;

	txp_full_transaction (0xF0, request_data, 1, reply_data, reply_data_length);

	for (i = 0; i < reply_data_length - 3; i++)
	{
		dspstat->data[i] = reply_data[i + 2];
	}

	if (debug_txp)
	{
		printf("--------READ DSP STATUS REGISTER--------------\n");
		printf("DSP RUNNING: %X\n", dspstat->fields.GO);
		printf("DSP ALGORITHMS CONVERGED: %X\n", dspstat->fields.CONVERGED);
		printf("MSE BELOW THRESHOLD: %X\n", dspstat->fields.MSEBLTHR);
		printf("BCD ENABLED: %X\n", dspstat->fields.BCDEN);
		printf("COARSE CARRIER LOCK OK: %X\n", dspstat->fields.LOCK);
		printf("COLLISION OK: %X\n", dspstat->fields.COLLISION);
		printf("DSP INITIALIZED: %X\n", dspstat->fields.DSPINIT);
		printf("RESERVED: 0x%X\n", dspstat->fields.RES);
		printf("PRESENCE OF LIGHT: %X\n", dspstat->fields.POL);
		printf("LOCAL OSCILLATOR RUNNING: %X\n", dspstat->fields.OSC);
		printf("TRANSMIT LASER RUNNING: 0x%X\n", dspstat->fields.TXLASER);
		printf("FFU1: 0x%X\n", dspstat->fields.FFU1);
		printf("FFU2: 0x%X\n", dspstat->fields.FFU2);
		printf("FFU3: 0x%X\n", dspstat->fields.FFU3);
		printf("----------------------------------------------\n");
	}

	return 0;
}

int txp_read_tx_alarm_status_register(union tx_alarm_status *tx_alarm)
{
	unsigned char *request_data;
	unsigned char reply_data[6];
	int i = 0;

	txp_full_transaction (0x80, request_data, 0, reply_data, 6);

	for (i = 0; i < 3; i++)
	{
		tx_alarm->data[i] = reply_data[i + 2];
	}

	return 0;
}

void txp_print_tx_alarm_status_register(union tx_alarm_status *tx_alarm)
{
	printf("--------------------TX ALARM STATUS REGISTER--------------------------------\n");
	printf("EOL ALM (Laser end of life alarm): \t\t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.eolalm]);
	printf("Mod TEMP ALM (Modulator Temperature Alarm): \t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.modtempalm]);
	printf("TxOOA (SFI-5 DESKEW alarm): \t\t\t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.txooa]);
	printf("TxLOF ALM (Loss of Frame alarm): \t\t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.txlofalm]);
	printf("Tx DSC ERR (Latching SFI-5 DESKEW Channel error): \t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.txdscerr]);
	printf("Ls WAV ALM (Laser Wavelength Alarm): \t\t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.lswavalm]);
	printf("Tx ALM INT (Tx summary alarm): \t\t\t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.txalmint]);
	printf("Ls BIAS ALM (Laser bias current alarm): \t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.lsbiasalm]);
	printf("Ls TEMP ALM (Laser temperature alarm): \t\t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.lstempalm]);
	printf("Tx LOCK ERR (Loss of TxPLL lock indicator): \t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.txlockerr]);
	printf("Ls POW ALM (Laser power alarm): \t\t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.lspowalm]);
	printf("Mod BIAS ALM (Modulator bias alarm): \t\t\t\t%s\n", status_alarm_rx_tx[tx_alarm->fields.modbiasalm]);
	printf("LATCHED TxFIFO ERR (Historical Mux FIFO error indicator): \t%s\n", status_alarm_rx_tx[tx_alarm->fields.latchedtxfifoerr]);
	printf("----------------------------------------------------------------------------\n");
}

int txp_read_first_laser_itu_channel(union laser_itu_channel laser_itu)
{
	return 0;
}

int txp_read_last_laser_itu_channel(union laser_itu_channel laser_itu)
{
	return 0;
}

int txp_set_tx_command_register(union tx_command_reg_union *tx_command_register)
{

	unsigned char request_data[3];
	unsigned char reply_data[3];
	request_data[0] = tx_command_register->data[0];
	request_data[1] = tx_command_register->data[1];
	request_data[2] = tx_command_register->data[2];

	txp_full_transaction (0x40, request_data, 3, reply_data, 3);

	return 0;
}

int txp_read_tx_command_register2(union tx_command_reg2_union *tx_commandregister_2)
{
	int reply_data_length = 7;
	unsigned char request_data[1];
	unsigned char reply_data[reply_data_length];
	int i = 0;

	request_data[0] = 0x41;

	txp_full_transaction (0xF0, request_data, 1, reply_data, reply_data_length);

	for (i = 0; i < reply_data_length - 3; i++)
	{
		tx_commandregister_2->data[i] = reply_data[i + 2];
	}
	if (debug_txp)
	{
		printf("--------READ TX COMMAND REGISTER 2---------\n");
		printf("TXPLL ENABLE: %X\n", tx_commandregister_2->fields.TXPLLENABLE);
		printf("TX SLOW RAMP: %X\n", tx_commandregister_2->fields.TXSLOWRAMP);
		printf("FFU1: %X\n", tx_commandregister_2->fields.FFU1);
		printf("OTUFRAMED: %X\n", tx_commandregister_2->fields.OTUFRAMED);
		printf("DQPSK: %X\n", tx_commandregister_2->fields.DQPSK);
		printf("SFI5 MAPPING: 0x%X\n", tx_commandregister_2->fields.SFI5MAPPING);
		printf("PRBS EXT: 0x%X\n", tx_commandregister_2->fields.PRBSEXT);
		printf("PRBS FRAME: %X\n", tx_commandregister_2->fields.PRBSFRAME);
		printf("FFU2: %X\n", tx_commandregister_2->fields.FFU2);
		printf("Tx Alarm Shut: 0x%X\n", tx_commandregister_2->fields.TxAlarmShutdown);
		printf("FFU3: 0x%X\n", tx_commandregister_2->fields.FFU3);
		printf("FFU4: %X\n", tx_commandregister_2->fields.FFU4);
		printf("Modulator Bias Selector: %X\n", tx_commandregister_2->fields.ModulatorBiasSelector);
		printf("None: 0x%X\n", tx_commandregister_2->fields.None);
		printf("FFU5: 0x%X\n", tx_commandregister_2->fields.FFU5);
		printf("----------------------------------------------\n");
	}
	return 0;
}

int txp_read_rx_command_register2(union rx_command_reg2_union *rx_command_register_2)
{
	unsigned char reply_data_length = 7;
	unsigned char request_data[1];
	unsigned char reply_data[reply_data_length];
	int i = 0;

	request_data[0] = 0x45;

	txp_full_transaction (0xF0, request_data, 1, reply_data, reply_data_length);

	for (i = 0; i < reply_data_length - 3; i++)
	{
		rx_command_register_2->data[i] = reply_data[i + 2];
	}

	if (debug_txp)
	{
		printf("--------READ RX COMMAND REGISTER 2---------\n");
		printf("RX PLL ENABLE: %X\n", rx_command_register_2->fields.RXPLLENABLE);
		printf("USER FRAMING: 0x%X\n", rx_command_register_2->fields.USERFRAMING);
		printf("OTU FRAMED: %X\n", rx_command_register_2->fields.OTUFRAMED);
		printf("DQPSK: %X\n", rx_command_register_2->fields.DQPSK);
		printf("SFI5 MAPPING: 0x%X\n", rx_command_register_2->fields.SFI5MAPPING);
		printf("PRBS EXT: 0x%X\n", rx_command_register_2->fields.PRBSEXT);
		printf("PRBS FRAME: %X\n", rx_command_register_2->fields.PRBSFRAME);
		printf("FFU1: %X\n", rx_command_register_2->fields.FFU1);
		printf("ORT: %X\n", rx_command_register_2->fields.ORT);
		printf("LOS GO INHIBIT: %X\n", rx_command_register_2->fields.LOS_GO_INHIBIT);
		printf("DQPSK Slicer Decision Mode: %X\n", rx_command_register_2->fields.DQPSK_Slicer_Dec_Mode);
		printf("AUTO RX RESET: %X\n", rx_command_register_2->fields.AUTORXRESET);
		printf("FFU2: %X\n", rx_command_register_2->fields.FFU2);
		printf("PMD C0 MODE ENABLE: %X\n", rx_command_register_2->fields.PMD_C0_MODE_ENABLE);
		printf("FFU3: %X\n", rx_command_register_2->fields.FFU3);
		printf("Rapid Automatic Rx Reset: %X\n", rx_command_register_2->fields.Rapid_Automatic_RX_Reset);
		printf("FFU4: 0x%X\n", rx_command_register_2->fields.FFU4);
		printf("FFU5: 0x%X\n", rx_command_register_2->fields.FFU5);
		printf("----------------------------------------------\n");
	}
	return 0;
}

int txp_set_tx_command_register2(union tx_command_reg2_union *tx_command_register_2)
{
	unsigned char request_data[5];
	unsigned char reply_data[3];

	request_data[0] = 0x40;
	request_data[1] = tx_command_register_2->data[0];
	request_data[2] = tx_command_register_2->data[1];
	request_data[3] = tx_command_register_2->data[2];
	request_data[4] = tx_command_register_2->data[3];

	txp_full_transaction (0xF0, request_data, 5, reply_data, 3);

	return 0;
}

int txp_set_rx_command_register2(union rx_command_reg2_union *rx_command_register_2)
{
	unsigned char request_data[5];
	unsigned char reply_data[3];

	request_data[0] = 0x44;
	request_data[1] = rx_command_register_2->data[0];
	request_data[2] = rx_command_register_2->data[1];
	request_data[3] = rx_command_register_2->data[2];
	request_data[4] = rx_command_register_2->data[3];

	txp_full_transaction (0xF0, request_data, 5, reply_data, 3);

	return 0;
}

int txp_set_rx_command_register(union rx_command_reg_union *rx_command_register)
{
	unsigned char request_data[3];
	unsigned char reply_data[3];

	request_data[0] = rx_command_register->data[0];
	request_data[1] = rx_command_register->data[1];
	request_data[2] = rx_command_register->data[2];

	txp_full_transaction (0x44, request_data, 3, reply_data, 3);

	return 0;
}

int txp_read_rx_command_register(union rx_command_reg_union *rx_command_reg)
{
	unsigned char reply_data_length = 6;
	unsigned char *request_data;
	unsigned char reply_data[reply_data_length];
	int i = 0;

	txp_full_transaction (0x45, request_data, 0, reply_data, reply_data_length);

	for (i = 0; i < reply_data_length - 3; i++)
	{
		rx_command_reg->data[i] = reply_data[i + 2];
	}

	if (debug_txp)
	{
		printf("--------READ RX STATUS REGISTER---------\n");
		printf("FFU1: 0x%X\n", rx_command_reg->fields.FFU1);
		printf("RX MUTE: %X\n", rx_command_reg->fields.rxmute);
		printf("RX DIAG LOOP EN: %X\n", rx_command_reg->fields.rxdloopenb);
		printf("SELF CLEAR RESET: %X\n", rx_command_reg->fields.scrxreset);
		printf("PRBS EN: %X\n", rx_command_reg->fields.prbsen);
		printf("PRBS PAT0: %X\n", rx_command_reg->fields.prbspat0);
		printf("PRBS PAT1: %X\n", rx_command_reg->fields.prbspat1);
		printf("FFU2: 0x%X\n", rx_command_reg->fields.FFU2);
		printf("RX RATE SEL0: %X\n", rx_command_reg->fields.rxratesel0);
		printf("RX RATE SEL1: %X\n", rx_command_reg->fields.rxratesel1);
		printf("RX REF SEL: %X\n", rx_command_reg->fields.rxrefsel);
		printf("RX LOCK REF: %X\n", rx_command_reg->fields.rxlckref);
		printf("RX MON CLK: %X\n", rx_command_reg->fields.rxmonclksel);
		printf("RX RESET: %X\n", rx_command_reg->fields.rxreset);
		printf("RX MUTE RXDCK: %X\n", rx_command_reg->fields.rxmuterxdck);
		printf("RX MUTE MON CLK: %X\n", rx_command_reg->fields.rxmutemonclk);
		printf("-----------------------------------------\n");
	}

	return 0;
}

int txp_read_tx_command_register(union tx_command_reg_union *tx_command_reg)
{
	unsigned char reply_data_length = 6;
	unsigned char *request_data;
	unsigned char reply_data[reply_data_length];
	int i = 0;

	txp_full_transaction (0x41, request_data, 0, reply_data, reply_data_length);

	for (i = 0; i < reply_data_length - 3; i++)
	{
		tx_command_reg->data[i] = reply_data[i + 2];
	}

	if (debug_txp)
	{
		printf("--------READ TX STATUS REGISTER---------\n");
		printf("PRBS EN: %X\n", tx_command_reg->fields.prbsen);
		printf("PRBS PAT0: %X\n", tx_command_reg->fields.prbspat0);
		printf("PRBS PAT1: %X\n", tx_command_reg->fields.prbspat1);
		printf("TX DESKEW EN: %X\n", tx_command_reg->fields.txdeskewen);
		printf("FFU1: 0x%X\n", tx_command_reg->fields.FFU1);
		printf("TX DCK SEL: %X\n", tx_command_reg->fields.txdcksel);
		printf("TX LINE TIM SEL: %X\n", tx_command_reg->fields.txlinetimsel);
		printf("TX LINE LOOP EN: %X\n", tx_command_reg->fields.txlloopenb);
		printf("TX RESET: %X\n", tx_command_reg->fields.txreset);
		printf("TX FIFO RES: %X\n", tx_command_reg->fields.txfifores);
		printf("AUTO TX FIFO RES: %X\n", tx_command_reg->fields.autotxfifores);
		printf("SELF CL TX RESET: %X\n", tx_command_reg->fields.sctxreset);
		printf("TX MUTE MON CLK: %X\n", tx_command_reg->fields.txmutemonclk);
		printf("LS ENABLE: %X\n", tx_command_reg->fields.lsenable);
		printf("TX RATE SEL0: %X\n", tx_command_reg->fields.txratesel0);
		printf("TX RATE SEL1: %X\n", tx_command_reg->fields.txratesel1);
		printf("TX REF SEL: %X\n", tx_command_reg->fields.txrefsel);
		printf("TX SRC CKSEL: %X\n", tx_command_reg->fields.TxSRCCKSEL);
		printf("FFU2: 0x%X\n", tx_command_reg->fields.FFU2);
		printf("----------------------------------------\n");
	}
	return 0;
}

int txp_read_unit_part_number(unsigned char *part_number)
{
	unsigned char request_data[19];
	unsigned char reply_data[19];
	int i = 0;

	/*
	 *  CMD = 0xAA
	 */

	txp_full_transaction (0xAA, request_data, 0, reply_data, 19);

	/*
	 * reply_data[19] = STS 0x10 [DATA1 - DATA16] CHK
	 */

	for (i = 0; i < 16; i++)
	{
		part_number[i] = reply_data[i + 2];
	}

	return 0;
}

int txp_read_unit_serial_number(unsigned char *serial_number)
{
	unsigned char request_data[19];
	unsigned char reply_data[19];
	int i = 0;

	/*
	 *  CMD = 0xA8
	 */

	txp_full_transaction (0xA8, request_data, 0, reply_data, 19);

	/*
	 * reply_data[19] = STS 0x10 [DATA1 - DATA16] CHK
	 */

	for (i = 0; i < 16; i++)
	{
		serial_number[i] = reply_data[i + 2];
	}

	return 0;
}

int txp_read_transponder_temperature_monitor(float *temp)
{
	unsigned char reply_data_length = 6;
	unsigned char *request_data;
	unsigned char reply_data[6];
	int i = 0;
	union temperature_40g_monitor_union t_40g_m_u;

	txp_full_transaction (0x66, request_data, 0, reply_data, reply_data_length);

	t_40g_m_u.temperature_40g_data[3] = 0;

	for (i = 0; i < reply_data_length - 3; i++)
	{
		t_40g_m_u.temperature_40g_data[2 - i] = reply_data[i + 2];
	}

	*temp = (float) ((t_40g_m_u.temperature_40g) / 1000);

	return 0;
}

int txp_read_transmit_laser_transponder_temperature_monitor(float *temp)
{
	unsigned char reply_data_length = 6;
	unsigned char *request_data;
	unsigned char reply_data[6];
	int i = 0;
	union temperature_40g_monitor_union t_40g_m_u;

	txp_full_transaction (0x62, request_data, 0, reply_data, reply_data_length);

	t_40g_m_u.temperature_40g_data[3] = 0;

	for (i = 0; i < reply_data_length - 3; i++)
	{
		t_40g_m_u.temperature_40g_data[2 - i] = reply_data[i + 2];
	}

	*temp = (float) (t_40g_m_u.temperature_40g / 1000);

	return 0;
}

int txp_read_receive_laser_transponder_temperature_monitor(float *temp)
{
	unsigned char reply_data_length = 6;
	unsigned char request_data[1];
	unsigned char reply_data[6];
	union temperature_40g_monitor_union t_40g_m_u;
	int i = 0;

	request_data[0] = 0x62;

	txp_full_transaction (0xF0, request_data, 1, reply_data, reply_data_length);

	t_40g_m_u.temperature_40g_data[3] = 0;

	for (i = 0; i < reply_data_length - 3; i++)
	{
		t_40g_m_u.temperature_40g_data[2 - i] = reply_data[i + 2];
	}

	*temp = (t_40g_m_u.temperature_40g / 1000);

	return 0;
}

int txp_read_error_checker_error_count(unsigned short *checker_error_count)
{
	unsigned char reply_data_length = 5;
	unsigned char *request_data;
	unsigned char reply_data[5];
	int i = 0;

	txp_full_transaction (0x69, request_data, 0, reply_data, reply_data_length);

	for (i = 0; i < reply_data_length - 3; i++)
	{
		checker_error_count[i] = reply_data[i + 2];
	}
	printf("PRBS ERROR COUNT: %u\n", checker_error_count);

	return 0;
}

int txp_read_rx_alarm_status_register(union rx_alarm_status *rx_alarm)
{
	unsigned char *request_data;
	unsigned char reply_data[5];
	int i = 0;

	txp_full_transaction (0x81, request_data, 0, reply_data, 5);

	for (i = 0; i < 2; i++)
	{
		rx_alarm->data[i] = reply_data[i + 2];
	}

	return 0;
}

void txp_print_rx_alarm_status_register(union rx_alarm_status *rx_alarm)
{
	printf("------------------RX ALARM STATUS REGISTER------------------\n");
	printf("RxALM INT union (RX summary alarm): \t\t%s\n", status_alarm_rx_tx[rx_alarm->fields.rxalmint]);
	printf("RxPOWALM (Loss average optical power alarm): \t%s\n", status_alarm_rx_tx[rx_alarm->fields.rxpowalm]);
	printf("RxLOS (Loss AC (modulated) power alarm): \t%s\n", status_alarm_rx_tx[rx_alarm->fields.rxlos]);
	printf("RxLOCKERR (Loss of RxPLL lock indicator): \t%s\n", status_alarm_rx_tx[rx_alarm->fields.rxlockerr]);
	printf("RXS (SFI-5 DEMUX status): \t\t\t%s\n", status_alarm_rx_tx[rx_alarm->fields.rxs]);
	printf("PRBSERRDET (PRBS error checker): \t\t%s\n", status_alarm_rx_tx[rx_alarm->fields.prbserrdet]);
	printf("------------------------------------------------------------\n");
}

int txp_read_power_supply_alarm_status_register(union power_alarm_status *power_alarm)
{
	unsigned char *request_data;
	unsigned char reply_data[4];
	int i = 0;

	txp_full_transaction (0x82, request_data, 0, reply_data, 4);

	for (i = 0; i < 1; i++)
	{
		power_alarm->data[i] = reply_data[i + 2];
	}

	if (debug_txp)
	{
		printf("--------READ POWER SUPPLY ALARM STATUS REGISTER-------\n");
		printf("PSUMMARY: %X\n", power_alarm->fields.psummary);
		printf("P5VANALOG: %X\n", power_alarm->fields.p5vanalog);
		printf("N5V2ANALOG: %X\n", power_alarm->fields.n5v2analog);
		printf("P3P3VANALOG: %X\n", power_alarm->fields.p3p3vanalog);
		printf("P3P3VDIGITAL: %X\n", power_alarm->fields.p3p3vdigital);
		printf("LVDIGITAL: %X\n", power_alarm->fields.lvdigital);
		printf("N5P2VDIGITAL: %X\n", power_alarm->fields.n5p2vdigital);
		printf("FFU: %X\n", power_alarm->fields.ffu);
		printf("-------------------------------------------------------\n");
	}

	return 0;
}

int txp_read_ber_estimate(float *value)
{
	unsigned char request_data[1] =
	{ 0x70 };
	unsigned char reply_data[7];
	int i = 0;
	union ber_estimate ber;

	txp_full_transaction (0xF0, request_data, 1, reply_data, 7);

	for (i = 0; i < 4; i++)
	{
		ber.fields[i] = reply_data[i + 2];
	}

	*value = ber.data;

	return 0;
}

int txp_read_mean_squared_error(union mean_squared_error *mse)
{
	unsigned char request_data[1] =
	{ 0x72 };
	unsigned char reply_data[11];
	int i = 0;

	txp_full_transaction (0xF0, request_data, 1, reply_data, 11);

	for (i = 0; i < 8; i++)
	{
		mse->data[7 - i] = reply_data[i + 2];
	}

	return txp_status(reply_data[0], "read_mean_squared_error");
}

int txp_trans_request(unsigned char cmd, unsigned char *request_data, int request_data_length)
{
	int data_length = 3 + request_data_length;
	unsigned char data[data_length];
	int i = 0;
	int j = 0;

	data[0] = cmd;
	data[1] = request_data_length;

	for (i = 0; i < request_data_length; i++)
	{
		data[i + 2] = request_data[i];
	}

	txp_cmd_check_byte(data);

	i2c_write_block_data(OCLARO_BUS, OCLARO_ADDRESS, data, data_length);

	return 0;
}

int txp_trans_reply(unsigned char *reply_data, int reply_data_length)
{
	i2c_read_block_data(OCLARO_BUS, OCLARO_ADDRESS, reply_data, reply_data_length);

	txp_reply_check_byte(reply_data);

	return 0;
}

int txp_cmd_check_byte(unsigned char *data)
{
	CHECK_PARAM(data == NULL, LOG_ERR, TAG_TXP, "Error in cmd_check_byte(): Null Pointer!", LOG_LOCAL0);

	int i = 0;
	unsigned char data_chk = (OCLARO_ADDRESS << 1);

	for (i = 0; i <= data[1] + 1; i++)
	{
		data_chk ^= data[i];
	}

	data_chk -= 1;

	data[data[1] + 2] = data_chk;

	return 0;
}

int txp_reply_check_byte(unsigned char *data)
{
	int i = 0;
	unsigned char data_chk = ((OCLARO_ADDRESS << 1)) + 1;

	for (i = 0; i <= data[1] + 1; i++)
	{
		data_chk ^= data[i];
	}

	data_chk -= 1;

//    CHECK_PARAM( data[data[1]+2] != data_chk, LOG_ERR, TAG_TXP, "Error in reply_check_byte(): Check Byte Error");

	return 0;
}

int txp_read_loss_input_alarm(int *status)
{
	CHECK_PARAM( gpio_read_bit(MOD_40G_LOS, status) < 0, LOG_ERR, TAG_TXP, "Error in read_loss_input_alarm: gpio_read_bit()", LOG_LOCAL0);

	return 0;
}

int txp_read_interrupt_input_alarm(int *status)
{
	CHECK_PARAM( gpio_read_bit(MOD_40G_STAT_INT, status) < 0, LOG_ERR, TAG_TXP, "Error in read_loss_input_alarm: gpio_read_bit()", LOG_LOCAL0);

	return 0;
}

int txp_read_transmit_laser_power_monitor(float *power)
{
	unsigned char reply_data_length = 6;
	unsigned char *request_data;
	unsigned char reply_data[6];
	int i = 0;
	union char_int_union c_i_union;

	txp_full_transaction (0x61, request_data, 0, reply_data, reply_data_length);

	c_i_union.value_char[3] = 0;

	for (i = 0; i < reply_data_length - 3; i++)
	{
		c_i_union.value_char[2 - i] = reply_data[i + 2];
	}

	*power = 10 * log10((double) (c_i_union.value_int / 1000.0));

	return 0;
}

int txp_read_receiver_laser_power_monitor(float *power)
{
	unsigned char reply_data_length = 6;
	unsigned char *request_data;
	unsigned char reply_data[6];
	int i = 0;
	union char_int_union c_i_union;

	txp_full_transaction (0x64, request_data, 0, reply_data, reply_data_length);

	c_i_union.value_char[3] = 0;

	for (i = 0; i < reply_data_length - 3; i++)
	{
		c_i_union.value_char[2 - i] = reply_data[i + 2];
	}

	*power = 10 * log10(((double) (c_i_union.value_int / 1000.0) / 1000.0));

	return 0;
}

int txp_read_fine_cd_compensation(int* fine_cd)
{
	int reply_data_length = 6;
	unsigned char request_data[1];
	unsigned char reply_data[reply_data_length];
	int i = 0;
	*fine_cd = 0;

	request_data[0] = 0x54;

	txp_full_transaction (0xF0, request_data, 1, reply_data, reply_data_length);

	for (i = 0; i < reply_data_length - 3; i++)
	{
		*fine_cd |= (reply_data[i + 2] << (2 - i) * 8);
	}

	//Convert 24 bits signed value to 32 bits signed value
	if (*fine_cd & 0x800000)
	{
		*fine_cd |= 0xFF000000;
	}

	if (debug_txp)
	{
		printf("--------READ FINE CD COMPENSATION--------------\n");
		printf("FINE CD COMPENSATION: %d\n", *fine_cd);
		printf("----------------------------------------------\n");
	}

	return txp_status(reply_data[0], "read_fine_cd_compensation");
}

int txp_read_bulk_cd_compensation(union bulk_cd_compensation *bulk_cd)
{
	int reply_data_length = 14;
	unsigned char request_data[1];
	unsigned char reply_data[reply_data_length];
	int i = 0;

	request_data[0] = 0x4C;

	txp_full_transaction (0xF0, request_data, 1, reply_data, reply_data_length);

	for (i = 0; i < reply_data_length - 3; i++)
	{
		bulk_cd->data[10 - i] = reply_data[i + 2];
	}

	if (debug_txp)
	{
		printf("--------READ BULK CD COMPENSATION--------------\n");
		printf("MINIMUM COMPENSATION: %d\n", bulk_cd->fields.minimum_compensation);
		printf("MAXIMUM COMPENSATION: %d\n", bulk_cd->fields.maximum_compensation);
		printf("STEP SIZE: %d\n", bulk_cd->fields.step_size);
		printf("CD BULK [ps/nm]: %d\n", bulk_cd->fields.cd_bulk);
		printf("----------------------------------------------\n");
	}

	return txp_status(reply_data[0], "read_bulk_cd_compensation");
}

int txp_set_bulk_cd_compensation(int minimum_compesation, int maximum_compesation, unsigned int step_size)
{
	int request_data_length = 9;
	unsigned char request_data[request_data_length];
	unsigned char reply_data[3];
	union bulk_cd_compensation bulk_cd;
	int i;

	bulk_cd.fields.minimum_compensation = minimum_compesation;
	bulk_cd.fields.maximum_compensation = maximum_compesation;
	bulk_cd.fields.step_size = step_size;

	txp_enter_vendor_protected_mode();

	request_data[0] = 0x4B;

	for (i = 1; i < request_data_length; i++)
	{
		request_data[i] = bulk_cd.data[11 - i];
	}

	txp_full_transaction (0xF0, request_data, 9, reply_data, 3);

	txp_exit_protected_mode();

	return txp_status(reply_data[0], "set_bulk_cd_compensation");
}

int txp_enter_protected_mode()
{
	unsigned char *request_data;
	unsigned char reply_data[3];

	txp_full_transaction (0xC3, request_data, 0, reply_data, 3);

	return txp_status(reply_data[0], "enter_protected_mode");
}

int txp_enter_vendor_protected_mode()
{
	unsigned char request_data[8] =
	{ 0x66, 0x69, 0x73, 0x68, 0x73, 0x74, 0x69, 0x78 };
	unsigned char reply_data[3];

	txp_full_transaction (0xC3, request_data, 8, reply_data, 3);

	return txp_status(reply_data[0], "enter_vendor_protected_mode");
}

int txp_exit_protected_mode()
{
	unsigned char *request_data;
	unsigned char reply_data[3];

	txp_full_transaction (0xC4, request_data, 0, reply_data, 3);

	return txp_status(reply_data[0], "exit_protected_mode");
}

/*
 * This function will cause all configurable parameters to be set to their default
 * values and the firmware to reboot and reinitialize the module hardware.
 */

int txp_reg_reset()
{
	char buffer_time[80];
	//The REG_RESET_L pin must be asserted for at least 40 milliseconds and no more than 4 seconds.
	gpio_write_bit(MOD_40G_REG_RESET_LATCH, 1); //reset
	sleep(1);
	gpio_write_bit(MOD_40G_REG_RESET_LATCH, 0); //normal operation
	sleep(1);
	//sleep(60);

	// Get the initial time to wait the 60 seconds in the OCLARO Module
	get_time(&start_oclaro_reset_time);
	get_string_from_time(&start_oclaro_reset_time, buffer_time);

	printf("40G Module: Registers Reset Start ...\n");
	return 0;
}

int txp_reset_time(void)
{
	char buffer_time[80];
	int reset_status = 0 ;

	get_time(&end_oclaro_reset_time);
	get_time_difference(&end_oclaro_reset_time, &start_oclaro_reset_time, &diff_time);
	get_string_from_time(&diff_time, buffer_time);

	int seconds = (diff_time.tm_mday * 24 * 3600) + (diff_time.tm_hour * 3600) + (diff_time.tm_min * 60) + diff_time.tm_sec;

	if (seconds < 60){
		reset_status = 0;
	}
	else {
		printf("40G Module: Registers Reset Finished.\n");
		//printf("Reset Time: %s\n", buffer_time);
		reset_status = 1;
	}

	return reset_status;
}

int txp_mod_reset()
{
	gpio_write_bit(MOD_40G_MOD_RESET_LATCH, 1); //reset
	sleep(5);
	gpio_write_bit(MOD_40G_MOD_RESET_LATCH, 0); //normal operation
	sleep(1);

	printf("40G Module: Reset.\n");
	return 0;
}

void txp_reset()
{

	gpio_write_bit(MOD_40G_LATCH_ENABLE, 1);
	gpio_write_bit(MOD_40G_Tx_LINETIMSEL_LATCH, 1);
	gpio_write_bit(MOD_40G_LS_ENABLE_LATCH, 0);
	gpio_write_bit(MOD_40G_MOD_RESET_LATCH, 0);
	gpio_write_bit(MOD_40G_REG_RESET_LATCH, 0);

	txp_mod_reset();
	txp_reg_reset();

}

/*
 * mode = 0 -> line timing mode
 * mode = 1 -> normal operation
 */
void txp_hw_sel_line_timing_mode(unsigned int mode)
{
	gpio_write_bit(MOD_40G_Tx_LINETIMSEL_LATCH, !mode); // normal
}

unsigned int txp_status(unsigned char sts, char *msg)
{
	sts = sts & 0x7F;

	if (sts != 0)
	{
		printf("Error in %s command: Code: %X\n", msg, sts);
	}

	return sts;
}

void txp_enable_debug(int enable)
{
	debug_txp = enable;
}

void txp_full_transaction (unsigned char cmd, unsigned char *request_data, int request_data_length, unsigned char *reply_data, int reply_data_length)
{
	//sem_wait(&shm_semaphores->txp.sem_id);
	//printf("Take full_transaction semaphore \n");

	int fd_lock;
	fd_lock = filelock_open("txp_full_transaction");

	filelock_lock(fd_lock);
	//printf("critical region\n");

	txp_trans_request(cmd, request_data, request_data_length);
    txp_trans_reply(reply_data, reply_data_length);

    //close() automatically releases the file lock.
	filelock_close(fd_lock);

    //sem_post(&shm_semaphores->txp.sem_id);
    //printf("Release full_transaction semaphore \n");
}

