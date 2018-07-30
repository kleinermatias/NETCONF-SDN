#include "hl_txp.h"
int debug_hl_txp = 0;

void hl_txp_hardware_information()
{
	unsigned char serial_number[20];
	txp_read_unit_serial_number(serial_number);
	printf("Número de serie: %s", serial_number);
	printf("\n");
	unsigned char part_number[20];
	txp_read_unit_part_number(part_number);
	printf("Número de parte: %s", part_number);
	printf("\n\n");
}

void hl_txp_update_alarm_configuration(Txp txp_struct, mxml_node_t *alarms)
{
	mxml_node_t *txp = mxmlNewElement(alarms, "txp");

	mxml_node_t *node;

	node = mxmlNewElement(txp, "eol");
	mxmlNewInteger(node, txp_struct.severity.eol);
	node = mxmlNewElement(txp, "mod_temp");
	mxmlNewInteger(node, txp_struct.severity.mod_temp);
	node = mxmlNewElement(txp, "txooa");
	mxmlNewInteger(node, txp_struct.severity.txooa);
	node = mxmlNewElement(txp, "tx_lof");
	mxmlNewInteger(node, txp_struct.severity.tx_lof);
	node = mxmlNewElement(txp, "tx_dsc");
	mxmlNewInteger(node, txp_struct.severity.tx_dsc);
	node = mxmlNewElement(txp, "ls_wav");
	mxmlNewInteger(node, txp_struct.severity.ls_wav);
	node = mxmlNewElement(txp, "ls_bias");
	mxmlNewInteger(node, txp_struct.severity.ls_bias);
	node = mxmlNewElement(txp, "ls_temp");
	mxmlNewInteger(node, txp_struct.severity.ls_temp);
	node = mxmlNewElement(txp, "tx_lock");
	mxmlNewInteger(node, txp_struct.severity.tx_lock);
	node = mxmlNewElement(txp, "ls_pow");
	mxmlNewInteger(node, txp_struct.severity.ls_pow);
	node = mxmlNewElement(txp, "mod_bias");
	mxmlNewInteger(node, txp_struct.severity.mod_bias);
	node = mxmlNewElement(txp, "latched_tx_fifo");
	mxmlNewInteger(node, txp_struct.severity.latched_tx_fifo);
	node = mxmlNewElement(txp, "rx_pow");
	mxmlNewInteger(node, txp_struct.severity.rx_pow);
	node = mxmlNewElement(txp, "rx_los");
	mxmlNewInteger(node, txp_struct.severity.rx_los);
	node = mxmlNewElement(txp, "rx_lock");
	mxmlNewInteger(node, txp_struct.severity.rx_lock);
	node = mxmlNewElement(txp, "rxs");
	mxmlNewInteger(node, txp_struct.severity.rxs);
	node = mxmlNewElement(txp, "prbs_err");
	mxmlNewInteger(node, txp_struct.severity.prbs_err);
	node = mxmlNewElement(txp, "psummary");
	mxmlNewInteger(node, txp_struct.severity.psummary);
	node = mxmlNewElement(txp, "p5vanalog");
	mxmlNewInteger(node, txp_struct.severity.p5vanalog);
	node = mxmlNewElement(txp, "n5v2analog");
	mxmlNewInteger(node, txp_struct.severity.n5v2analog);
	node = mxmlNewElement(txp, "p3p3vanalog");
	mxmlNewInteger(node, txp_struct.severity.p3p3vanalog);
	node = mxmlNewElement(txp, "p3p3vdigital");
	mxmlNewInteger(node, txp_struct.severity.p3p3vdigital);
	node = mxmlNewElement(txp, "lvdigital");
	mxmlNewInteger(node, txp_struct.severity.lvdigital);
	node = mxmlNewElement(txp, "n5p2vdigital");
	mxmlNewInteger(node, txp_struct.severity.n5p2vdigital);
}

void hl_txp_load_alarm_data(Txp *txp_struct, char *alarm_name, int alarm_value)
{
	if(strcmp(alarm_name, "eol") == 0)
	{
        txp_struct->severity.eol = alarm_value;
	}
	else if(strcmp(alarm_name, "mod_temp") == 0)
	{
        txp_struct->severity.mod_temp = alarm_value;
	}
	else if(strcmp(alarm_name, "txooa") == 0)
	{
        txp_struct->severity.txooa = alarm_value;
	}
	else if(strcmp(alarm_name, "tx_lof") == 0)
	{
        txp_struct->severity.tx_lof = alarm_value;
	}
	else if(strcmp(alarm_name, "tx_dsc") == 0)
	{
        txp_struct->severity.tx_dsc = alarm_value;
	}
	else if(strcmp(alarm_name, "ls_wav") == 0)
	{
        txp_struct->severity.ls_wav = alarm_value;
	}
	else if(strcmp(alarm_name, "ls_bias") == 0)
	{
        txp_struct->severity.ls_bias = alarm_value;
	}
	else if(strcmp(alarm_name, "ls_temp") == 0)
	{
        txp_struct->severity.ls_temp = alarm_value;
	}
	else if(strcmp(alarm_name, "tx_lock") == 0)
	{
        txp_struct->severity.tx_lock = alarm_value;
	}
	else if(strcmp(alarm_name, "ls_pow") == 0)
	{
        txp_struct->severity.ls_pow = alarm_value;
	}
	else if(strcmp(alarm_name, "mod_bias") == 0)
	{
        txp_struct->severity.mod_bias = alarm_value;
	}
	else if(strcmp(alarm_name, "latched_tx_fifo") == 0)
	{
        txp_struct->severity.latched_tx_fifo = alarm_value;
	}
	else if(strcmp(alarm_name, "rx_pow") == 0)
	{
        txp_struct->severity.rx_pow = alarm_value;
	}
	else if(strcmp(alarm_name, "rx_los") == 0)
	{
        txp_struct->severity.rx_los = alarm_value;
	}
	else if(strcmp(alarm_name, "rx_lock") == 0)
	{
        txp_struct->severity.rx_lock = alarm_value;
	}
	else if(strcmp(alarm_name, "rxs") == 0)
	{
        txp_struct->severity.rxs = alarm_value;
	}
	else if(strcmp(alarm_name, "prbs_err") == 0)
	{
        txp_struct->severity.prbs_err = alarm_value;
	}
	else if(strcmp(alarm_name, "psummary") == 0)
	{
        txp_struct->severity.psummary = alarm_value;
	}
	else if(strcmp(alarm_name, "p5vanalog") == 0)
	{
        txp_struct->severity.p5vanalog = alarm_value;
	}
	else if(strcmp(alarm_name, "n5v2analog") == 0)
	{
        txp_struct->severity.n5v2analog = alarm_value;
	}
	else if(strcmp(alarm_name, "p3p3vanalog") == 0)
	{
        txp_struct->severity.p3p3vanalog = alarm_value;
	}
	else if(strcmp(alarm_name, "lvdigital") == 0)
	{
        txp_struct->severity.lvdigital = alarm_value;
	}
	else if(strcmp(alarm_name, "n5p2vdigital") == 0)
	{
        txp_struct->severity.n5p2vdigital = alarm_value;
	}
}

void hl_txp_load_default_alarms_parameters(Txp *txp_struct)
{
	txp_struct->severity.eol = 1;
	txp_struct->severity.latched_tx_fifo = 1;
	txp_struct->severity.ls_bias = 1;
	txp_struct->severity.ls_pow = 1;
	txp_struct->severity.ls_temp = 1;
	txp_struct->severity.ls_wav = 1;
	txp_struct->severity.lvdigital = 1;
	txp_struct->severity.mod_bias = 1;
	txp_struct->severity.mod_temp = 1;
	txp_struct->severity.n5p2vdigital = 1;
	txp_struct->severity.n5v2analog = 1;
	txp_struct->severity.p3p3vanalog = 1;
	txp_struct->severity.p3p3vdigital = 1;
	txp_struct->severity.p5vanalog = 1;
	txp_struct->severity.prbs_err = 1;
	txp_struct->severity.psummary = 1;
	txp_struct->severity.rx_lock = 1;
	txp_struct->severity.rx_los = 1;
	txp_struct->severity.rx_pow = 1;
	txp_struct->severity.rxs = 1;
	txp_struct->severity.tx_dsc = 1;
	txp_struct->severity.tx_lock = 1;
	txp_struct->severity.tx_lof = 1;
	txp_struct->severity.txooa = 1;
}

void hl_txp_config_40g_otu3(int line_loopback, int dloop, int lsen)
{
	unsigned int line_timing_mode = 1; //normal operation

	/* LATCH ENABLE 40G */
	gpio_write_bit(MOD_40G_LATCH_ENABLE, 1);

	txp_hw_sel_line_timing_mode(line_timing_mode);

	gpio_write_bit(MOD_40G_LS_ENABLE_LATCH, 1); //laser encendido

	/* OCLARO MODULE PIN INIT// LATCH INVERTER
	 MOD_40G_Tx_LINETIMSEL_LATCH		90	out	1  low level for normal operation
	 MOD_40G_LS_ENABLE_LATCH			89	out	0  low level for normal operation -- laser on
	 MOD_40G_MOD_RESET_LATCH			88	out	0  low level reset -- 1 normal operation
	 MOD_40G_REG_RESET_LATCH			87	out	0  low level reset -- 1 normal operation*/

	printf("Configuring OClaro module...\n");

	union tx_command_reg_union tx_command_register_write;
	txp_read_tx_command_register(&tx_command_register_write);

	//	/*TX REGISTER FINAL VALUES */
	tx_command_register_write.fields.prbsen = 1;
	tx_command_register_write.fields.prbspat0 = 1;
	tx_command_register_write.fields.prbspat1 = 1;
	tx_command_register_write.fields.txdeskewen = 1;
//	tx_command_register_write.fields.txdcksel 		=0;
	tx_command_register_write.fields.txlinetimsel = line_timing_mode; // normal op
	tx_command_register_write.fields.txlloopenb = (!(line_loopback == 1));
	tx_command_register_write.fields.txreset = 1; // manual MUX reset
	tx_command_register_write.fields.txfifores = 1; // TX FIFO normal operation
	tx_command_register_write.fields.autotxfifores = 0; // Auto FIFO reset enabled
	tx_command_register_write.fields.sctxreset = 0; // self-clearing MUX reset enabled
	tx_command_register_write.fields.txmutemonclk = 1;
	tx_command_register_write.fields.lsenable = (!(lsen == 1)); // laser enable
	tx_command_register_write.fields.txratesel0 = 0;
	tx_command_register_write.fields.txratesel1 = 1;
	tx_command_register_write.fields.txrefsel = 0;
//	tx_command_register_write.fields.TxSRCCKSEL 	=1;

	txp_set_tx_command_register(&tx_command_register_write);
	txp_read_tx_command_register(&tx_command_register_write);

	union rx_command_reg_union data_rx;
	txp_read_rx_command_register(&data_rx);

//	/*RX REGISTER RESET */
	data_rx.fields.rxmute = 1;
	data_rx.fields.rxdloopenb = (!(dloop == 1)); // diagnostic loopback
	data_rx.fields.scrxreset = 0; // self-clearing DMUX reset enabled
	data_rx.fields.prbsen = 1;
	data_rx.fields.prbspat0 = 1;
	data_rx.fields.prbspat1 = 1;
	data_rx.fields.rxratesel0 = 0;
	data_rx.fields.rxratesel1 = 1;
	data_rx.fields.rxrefsel = 0;
	data_rx.fields.rxlckref = 1;
	data_rx.fields.rxmonclksel = 0;
	data_rx.fields.rxreset = 1; // manual DMUX reset activated
	data_rx.fields.rxmuterxdck = 1;
	data_rx.fields.rxmutemonclk = 1;

	txp_set_rx_command_register(&data_rx);
	txp_read_rx_command_register(&data_rx);

}

int hl_txp_set_tx_rx_laser_itu_channel(float channel)
{
	unsigned char laser_status;
	union tx_command_reg_union tx_command_register_write;

	if (CHECK_CHANNEL(channel))
	{
		txp_enable_debug(0);
		txp_read_tx_command_register(&tx_command_register_write);
		laser_status = tx_command_register_write.fields.lsenable;
		tx_command_register_write.fields.lsenable = 1; //laser disable
		txp_set_tx_command_register(&tx_command_register_write);
		txp_set_laser_itu_channel(channel);
		txp_set_receive_itu_channel(channel);
		tx_command_register_write.fields.lsenable = laser_status; //set the initial status
		txp_set_tx_command_register(&tx_command_register_write);
		return 0;
	}
	else
	{
		printf(CHANNEL_RANGE_ERROR);
		return -1;
	}

}

int hl_txp_set_bulk_cd_compensation(int min_bulk_cd_comp, int max_bulk_cd_comp)
{
	int step_size = 100; //Allowed range 100 to 1300 ps/nm
	unsigned int min_step_size;
	int minimum_compensation; //Allowed range -55000 to 55000 ps/nm. This value must be between -127 times the step size and +127 times
							  //the step size, and less than or equal to the maximum compensation value
	int maximum_compensation; //Allowed range -55000 to 55000 ps/nm. This value must be between -127 times the step size and +127 times
							  //the step size, and greater than or equal to the minimum compensation value.

	int cd_value;
	float multiplier;

	if (CHECK_CD_COMPENSATION(min_bulk_cd_comp,max_bulk_cd_comp) == 1)
	{

		if (abs(min_bulk_cd_comp) > abs(max_bulk_cd_comp))
		{
			cd_value = min_bulk_cd_comp;
		}
		else
		{
			cd_value = max_bulk_cd_comp;
		}

		multiplier = cd_value / step_size;

		while (((multiplier < -127.0) | (multiplier > 127.0)) && step_size <= 1300)
		{
			step_size += 1;
			multiplier = cd_value / step_size;
		}

		min_step_size = step_size;

		while ((((min_bulk_cd_comp % step_size) != 0) || ((max_bulk_cd_comp % step_size) != 0)) && (step_size <= 1300))
		{
			step_size += 1;
		}

		if (step_size > 1300)
		{
			step_size = min_step_size;
		}

		if ((min_bulk_cd_comp == 0) && (max_bulk_cd_comp == 0))
		{
			step_size = 0; //chromatic dispersion disabled
		}

		txp_set_bulk_cd_compensation(min_bulk_cd_comp, max_bulk_cd_comp, (unsigned int) step_size);

		return 0;
	}
	else
	{
		printf(CD_COMPENSATION_RANGE_ERROR);
		return -1;
	}
}

int hl_txp_get_estimated_chromatic_dispersion(int* estimated_cd)
{
	union bulk_cd_compensation bulk_cd;
	int fine_cd;

	txp_read_bulk_cd_compensation(&bulk_cd);

	txp_read_fine_cd_compensation(&fine_cd);

	*estimated_cd = fine_cd - bulk_cd.fields.cd_bulk;

	if (debug_hl_txp)
	{
		printf("--------HL GET ESTIMATED CHROMATIC DISPERSION-------\n");
		printf("ESTIMATED CHROMATIC COMPENSATION: %d\n", *estimated_cd);
		printf("----------------------------------------------------\n");
	}

	return 0;
}

int hl_txp_get_chromatic_dispersion(float* cd)
{
	int estimated_cd;
	float rate = 43.793920000;

	hl_txp_get_estimated_chromatic_dispersion(&estimated_cd);

	*cd = (2 - (pow(rate, 2) / pow(43.018413559, 2))) * estimated_cd;

	if (debug_hl_txp)
	{
		printf("------------HL GET CHROMATIC DISPERSION-------------\n");
		printf("CHROMATIC COMPENSATION: %f\n", *cd);
		printf("----------------------------------------------------\n");
	}

	return 0;
}
