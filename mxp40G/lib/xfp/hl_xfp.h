/*
 * hl_xfp.h
 *
 *  Created on: Aug 11, 2015
 *      Author: Guille
 */

#ifndef HL_XFP_H_
#define HL_XFP_H_

#include "xfp.h"
#include "stdio.h"
#include "unistd.h"
#include "../mxml-2.9/mxml.h"

typedef struct xfp_severity
{
	unsigned int presence;
	unsigned int rx_loss;
	unsigned int ready;
	unsigned int tx_power;
	unsigned int rx_power;
	unsigned int temperature;
	unsigned int low_tx_power;
	unsigned int high_tx_power;
	unsigned int low_rx_power;
	unsigned int high_rx_power;
	unsigned int rx_cdr_loss_of_lock;
	unsigned int tx_cdr_loss_of_lock;
	unsigned int laser_fault;

} Xfp_severity;

typedef struct xfp_struct
{
	unsigned int xfp_presence[4];
	unsigned int xfp_rx_loss[4];
	unsigned int xfp_ready[4];
	unsigned int xfp_interrupt[4];
	float xfp_tx_power[4];
	float xfp_rx_power[4];
	float xfp_temperature[4];
	unsigned int xfp_interruption_flags[4][7];
	Xfp_severity severity[4];

} Xfp;

int hl_xfp_setup(int module_id, int loopback, int protocol);

// Prints hardware information of the xfp modules
void hl_xfp_hardware_information(void);

// Updates the xfp part of the alarm configuration file with the information of the xfp struct.
// xfp_struct: is the xfp struct
// alarms: main node for alarm information in the configuration file
void hl_xfp_update_alarm_configuration(Xfp xfp_struct, mxml_node_t *alarms);

// Load data of the alarms of the xfp module
// xfp_struct: is the xfp struct
// current_xfp_node: is a xfp node
void hl_xfp_load_alarm_data(Xfp *xfp_struct, mxml_node_t *current_xfp_node);

// Load default parameters for xfp alarm configuration
// xfp_struct: is the xfp struct
void hl_xfp_load_default_alarms_parameters(Xfp *xfp_struct);

#endif /* HL_XFP_H_ */
