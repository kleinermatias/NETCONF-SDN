/*
 * hl_xfp.c
 *
 *  Created on: Aug 11, 2015
 *      Author: Guille
 */
#include "hl_xfp.h"

int hl_xfp_setup(int module_id, int loopback, int protocol)
{
	unsigned int status;
	unsigned int data_rate;

	switch (protocol)
	{
	case 0: // OTU2
		data_rate = 0x06;
		break;
	case 1: // XGE
		data_rate = 0x04;
		break;
	case 2: // OC192
		data_rate = 0x02;
		break;
	default:
		data_rate = 0x04;
		break;
	}

	xfp_enable_communication(module_id);

	xfp_get_presence_status(module_id, &status);

	printf("XFI %d Normal Operation: %d\n", module_id + 1, xfp_set_normal_operation(module_id));

	xfp_set_data_rate(module_id, data_rate);

	if (status == 0)
	{
		printf("XFP %d is present.\n", module_id + 1);
	}
	else
	{
		printf("XFP %d is not present.\n", module_id + 1);
	}

	if (loopback)
	{
		printf("XFP %d enable XFI loopback and laser disable.\n", module_id + 1);

		xfp_set_xfi_loopback(module_id);

		xfp_disable_laser(module_id);
	}
	else
	{
		printf("XFP %d normal operation and enable laser.\n", module_id + 1);

		xfp_mask_bit(module_id);
		sleep(2);
		xfp_read_interruption_flags(module_id);
		sleep(2);
		xfp_disable_laser(module_id);
		sleep(2);
		xfp_enable_laser(module_id);
		sleep(2);
		xfp_read_interruption_flags(module_id);
		sleep(2);
		xfp_demask_bit(module_id);
	}

	return 0;
}

void hl_xfp_hardware_information()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("Modulo nro %i\n", i + 1);
		printf("Número de serie: ");
		xfp_get_serial_number(i);
		printf("\n");
		printf("Número de parte: ");
		xfp_get_part_number(i);
		printf("\n\n");
	}
}

void hl_xfp_update_alarm_configuration(Xfp xfp_struct, mxml_node_t *alarms)
{
	mxml_node_t *xfp = mxmlNewElement(alarms, "xfp");

	int i;
	for (i = 0; i < 4; i++)
	{
		char xfp_number[5];
		sprintf(xfp_number, "%d", i);

		mxml_node_t *xfp_mod = mxmlNewElement(xfp, xfp_number);

		mxml_node_t *node;

		node = mxmlNewElement(xfp_mod, "presence");
		mxmlNewInteger(node, xfp_struct.severity[i].presence);
		node = mxmlNewElement(xfp_mod, "rx_loss");
		mxmlNewInteger(node, xfp_struct.severity[i].rx_loss);
		node = mxmlNewElement(xfp_mod, "ready");
		mxmlNewInteger(node, xfp_struct.severity[i].ready);
		node = mxmlNewElement(xfp_mod, "tx_power");
		mxmlNewInteger(node, xfp_struct.severity[i].tx_power);
		node = mxmlNewElement(xfp_mod, "rx_power");
		mxmlNewInteger(node, xfp_struct.severity[i].rx_power);
		node = mxmlNewElement(xfp_mod, "temperature");
		mxmlNewInteger(node, xfp_struct.severity[i].temperature);
		node = mxmlNewElement(xfp_mod, "low_tx_power");
		mxmlNewInteger(node, xfp_struct.severity[i].low_tx_power);
		node = mxmlNewElement(xfp_mod, "high_tx_power");
		mxmlNewInteger(node, xfp_struct.severity[i].high_tx_power);
		node = mxmlNewElement(xfp_mod, "low_rx_power");
		mxmlNewInteger(node, xfp_struct.severity[i].low_rx_power);
		node = mxmlNewElement(xfp_mod, "high_rx_power");
		mxmlNewInteger(node, xfp_struct.severity[i].high_rx_power);
		node = mxmlNewElement(xfp_mod, "rx_cdr_loss_of_lock");
		mxmlNewInteger(node, xfp_struct.severity[i].rx_cdr_loss_of_lock);
		node = mxmlNewElement(xfp_mod, "tx_cdr_loss_of_lock");
		mxmlNewInteger(node, xfp_struct.severity[i].tx_cdr_loss_of_lock);
		node = mxmlNewElement(xfp_mod, "laser_fault");
		mxmlNewInteger(node, xfp_struct.severity[i].laser_fault);
	}
}

void hl_xfp_load_alarm_data(Xfp *xfp_struct, mxml_node_t *current_xfp_node)
{
	int i = atoi(current_xfp_node->value.opaque);

	mxml_node_t *current_alarm;

	// Search for module alarms
	for (current_alarm = mxmlGetFirstChild(current_xfp_node); current_alarm != NULL; current_alarm = mxmlGetNextSibling(current_alarm))
	{
		// get the name of the alarm
		char *alarm_name = current_alarm->value.opaque;

		// Get the configuration value of the alarm
		int alarm_value = atoi(mxmlGetText(current_alarm, 0));

		if (strcmp(alarm_name, "high_rx_power") == 0)
		{
			xfp_struct->severity[i].high_rx_power = alarm_value;
		}
		else if (strcmp(alarm_name, "high_tx_power") == 0)
		{
			xfp_struct->severity[i].high_tx_power = alarm_value;
		}
		else if (strcmp(alarm_name, "laser_fault") == 0)
		{
			xfp_struct->severity[i].laser_fault = alarm_value;
		}
		else if (strcmp(alarm_name, "low_rx_power") == 0)
		{
			xfp_struct->severity[i].low_rx_power = alarm_value;
		}
		else if (strcmp(alarm_name, "low_tx_power") == 0)
		{
			xfp_struct->severity[i].low_tx_power = alarm_value;
		}
		else if (strcmp(alarm_name, "presence") == 0)
		{
			xfp_struct->severity[i].presence = alarm_value;
		}
		else if (strcmp(alarm_name, "ready") == 0)
		{
			xfp_struct->severity[i].ready = alarm_value;
		}
		else if (strcmp(alarm_name, "rx_cdr_loss_of_lock") == 0)
		{
			xfp_struct->severity[i].rx_cdr_loss_of_lock = alarm_value;
		}
		else if (strcmp(alarm_name, "rx_loss") == 0)
		{
			xfp_struct->severity[i].rx_loss = alarm_value;
		}
		else if (strcmp(alarm_name, "rx_power") == 0)
		{
			xfp_struct->severity[i].rx_power = alarm_value;
		}
		else if (strcmp(alarm_name, "temperature") == 0)
		{
			xfp_struct->severity[i].temperature = alarm_value;
		}
		else if (strcmp(alarm_name, "tx_cdr_loss_of_lock") == 0)
		{
			xfp_struct->severity[i].tx_cdr_loss_of_lock = alarm_value;
		}
		else if (strcmp(alarm_name, "tx_power") == 0)
		{
			xfp_struct->severity[i].tx_power = alarm_value;
		}
	}
}

void hl_xfp_load_default_alarms_parameters(Xfp *xfp_struct)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		xfp_struct->severity[i].high_rx_power = 1;
		xfp_struct->severity[i].high_tx_power = 1;
		xfp_struct->severity[i].laser_fault = 1;
		xfp_struct->severity[i].low_rx_power = 1;
		xfp_struct->severity[i].low_tx_power = 1;
		xfp_struct->severity[i].presence = 1;
		xfp_struct->severity[i].ready = 1;
		xfp_struct->severity[i].rx_cdr_loss_of_lock = 1;
		xfp_struct->severity[i].rx_loss = 1;
		xfp_struct->severity[i].rx_power = 1;
		xfp_struct->severity[i].temperature = 1;
		xfp_struct->severity[i].tx_cdr_loss_of_lock = 1;
		xfp_struct->severity[i].tx_power = 1;
	}
}
