#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../lib/gpio/gpio.h"
#include "../../lib/txp/txp.h"
#include "oclarotest.h"
#include "../../lib/clk/clk.h"

int main (int argc, char **argv)
{

	/* CLOCK INIT */

	clk_set_osc_684_28_mhz(1);
	clk_set_mux_a(1);
	clk_set_mux_b(0);
//
//	/* LATCH ENABLE 40G */
//
	gpio_write_bit(MOD_40G_LATCH_ENABLE,1);
//
//
//	/* OCLARO MODULE PIN INIT// LATCH INVERTER

	/*MOD_40G_Tx_LINETIMSEL_LATCH		90	out	1  low level for normal operation
	MOD_40G_LS_ENABLE_LATCH			89	out	0  low level for normal operation -- laser on
	MOD_40G_MOD_RESET_LATCH			88	out	0  low level reset -- 1 normal operation
	MOD_40G_REG_RESET_LATCH			87	out	0  low level reset -- 1 normal operation
	*/

	gpio_write_bit(MOD_40G_Tx_LINETIMSEL_LATCH, 0);	//normal operation
	gpio_write_bit(MOD_40G_LS_ENABLE_LATCH, 1);     //laser encendido

	/* RESET */

	//gpio_write_bit(MOD_40G_MOD_RESET_LATCH, 1);
	//gpio_write_bit(MOD_40G_REG_RESET_LATCH, 1);

	/* NORMAL OPERATION */

	gpio_write_bit(MOD_40G_MOD_RESET_LATCH, 0); // normal op
	gpio_write_bit(MOD_40G_REG_RESET_LATCH, 0);	//normal op

	union tx_command_reg_union tx_command_register_write;
	read_tx_command_register(&tx_command_register_write);


//	/*TX REGISTER DEFAULT VALUES */
	tx_command_register_write.fields.prbsen 		=1;
	tx_command_register_write.fields.prbspat0		=1;
	tx_command_register_write.fields.prbspat1		=1;
	tx_command_register_write.fields.txdeskewen 	=1;
//	tx_command_register_write.fields.txdcksel 		=0;
	tx_command_register_write.fields.txlinetimsel	=0;// normal op
	tx_command_register_write.fields.txlloopenb 	=1;
	tx_command_register_write.fields.txreset		=1;
	tx_command_register_write.fields.txfifores		=1;
	tx_command_register_write.fields.autotxfifores	=1;
	tx_command_register_write.fields.sctxreset 		=1;
	tx_command_register_write.fields.txmutemonclk 	=1;
	tx_command_register_write.fields.lsenable 		=0;
	tx_command_register_write.fields.txratesel0 	=0;
	tx_command_register_write.fields.txratesel1 	=1;
	tx_command_register_write.fields.txrefsel 		=0;
//	tx_command_register_write.fields.TxSRCCKSEL 	=1;

	set_tx_command_register(&tx_command_register_write);
	read_tx_command_register(&tx_command_register_write);
//
//
	union rx_command_reg_union data_rx;
	read_rx_command_register(&data_rx);

//	/*RX REGISTER - VALORES POR DEFAULT*/
//
	data_rx.fields.rxmute		=1;
	data_rx.fields.rxdloopenb  	=1;
	data_rx.fields.scrxreset	=1;
	data_rx.fields.prbsen		=1;
	data_rx.fields.prbspat0		=1;
	data_rx.fields.prbspat1		=1;
	data_rx.fields.rxratesel0	=0;
	data_rx.fields.rxratesel1	=1;
	data_rx.fields.rxrefsel		=0;
	data_rx.fields.rxlckref		=1;
	data_rx.fields.rxmonclksel	=0;
	data_rx.fields.rxreset		=1;
	data_rx.fields.rxmuterxdck	=1;
	data_rx.fields.rxmutemonclk	=1;

	set_rx_command_register(&data_rx);
	read_rx_command_register(&data_rx);
//
//
	union dsp_status_union dsp_status_read;
	read_dsp_status(&dsp_status_read);

//	union laser_itu_channel laser;
//	read_rx_laser_itu_channel(&laser);
//	read_laser_itu_channel(&laser);

//LEER PRBS

	unsigned short error_count;
//	read_error_checker_error_count(&error_count);

	union rx_alarm_status rx_alarm;
	read_rx_alarm_status_register(&rx_alarm);

	union tx_alarm_status tx_alarm;
	read_tx_alarm_status_register(&tx_alarm);

//	union power_alarm_status power_alarm;
//	read_power_supply_alarm_status_register(&power_alarm);
//
	union tx_command_reg2_union tx_command_register_2_read;
//	read_tx_command_register2(&tx_command_register_2_read);

	union tx_command_reg2_union tx_command_register_2_write;

//	/* DEFAULT VALUES FOR TX REGISTER2 */
	tx_command_register_2_write.fields.TXPLLENABLE			=0;
	tx_command_register_2_write.fields.TXSLOWRAMP			=1;
//	tx_command_register_2_write.fields.FFU1					=1;
	tx_command_register_2_write.fields.OTUFRAMED			=1;
	tx_command_register_2_write.fields.DQPSK				=1;
	tx_command_register_2_write.fields.SFI5MAPPING			=0x7;
	tx_command_register_2_write.fields.PRBSEXT				=0x3;
	tx_command_register_2_write.fields.PRBSFRAME			=0;
//	tx_command_register_2_write.fields.FFU2					=1;
	tx_command_register_2_write.fields.TxAlarmShutdown		=0x3;
//	tx_command_register_2_write.fields.FFU3					=0x3;
//	tx_command_register_2_write.fields.FFU4					=1;
	tx_command_register_2_write.fields.ModulatorBiasSelector=1;
//	tx_command_register_2_write.fields.None					=0x3F;
//	tx_command_register_2_write.fields.FFU5					=0xFF;

//	set_tx_command_register2(&tx_command_register_2_write);
//	read_tx_command_register2(&tx_command_register_2_read);

//
	union rx_command_reg2_union rx_command_register_2_read;
//	read_rx_command_register2(&rx_command_register_2_read);

	union rx_command_reg2_union rx_command_register_2_write;

//	/* DEFAULT VALUES FOR RX REGISTER2 */
	rx_command_register_2_write.fields.RXPLLENABLE				=0;
	rx_command_register_2_write.fields.USERFRAMING				=0x3;
	rx_command_register_2_write.fields.OTUFRAMED				=1;
	rx_command_register_2_write.fields.DQPSK					=1;
	rx_command_register_2_write.fields.SFI5MAPPING				=0x7;
	rx_command_register_2_write.fields.PRBSEXT					=0x3;
	rx_command_register_2_write.fields.PRBSFRAME				=0;
//	rx_command_register_2_write.fields.FFU1						=1;
	rx_command_register_2_write.fields.ORT						=1;
	rx_command_register_2_write.fields.LOS_GO_INHIBIT			=1;
	rx_command_register_2_write.fields.DQPSK_Slicer_Dec_Mode	=1;
	rx_command_register_2_write.fields.AUTORXRESET				=1;
//	rx_command_register_2_write.fields.FFU2						=1;
	rx_command_register_2_write.fields.PMD_C0_MODE_ENABLE		=1;
//	rx_command_register_2_write.fields.FFU3						=1;
	rx_command_register_2_write.fields.Rapid_Automatic_RX_Reset	=1;
//	rx_command_register_2_write.fields.FFU4						=0xF;
//	rx_command_register_2_write.fields.FFU5						=0xFF;

//	set_rx_command_register2(&rx_command_register_2_write);
//	read_rx_command_register2(&rx_command_register_2_read);

	union error_prbs_counters_union prbs_counters;

	read_prbs_error_counters(4, &prbs_counters);
	read_prbs_error_counters(5, &prbs_counters);
	read_prbs_error_counters(6, &prbs_counters);

	struct power_rails power_values;
//	read_power_rail_monitor(&power_values);

//	set_tx_command_register(&tx_command_register_write);
//	read_tx_command_register(&tx_command_register_write);

	return 0;

}
