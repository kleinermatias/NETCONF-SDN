#ifndef HL_EDFA_H_
#define HL_EDFA_H_

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unistd.h"
#include "edfa.h"
#include "unistd.h"
#include "../mxml-2.9/mxml.h"

typedef struct edfa_severity
{
	unsigned int output_power;
	unsigned int input_power;
	unsigned int temperature;
	unsigned int los;
	unsigned int lop;
	unsigned int amp_status;

} Edfa_severity;

typedef struct edfa_struct
{
	char edfa_output_power[100];
	char edfa_input_power[100];
	char edfa_temperature[100];
	char edfa_los[100];
	char edfa_lop[100];
	char edfa_amp_status[100];
	Edfa_severity severity;

} Edfa;

// Prints hardware information of edfa module
void edfa_hardware_information(void);

// Updates the edfa part of the alarm configuration file with the information of the edfa struct.
// monitor: is the monitor struct
// alarms: main node for alarm information in the configuration file
void update_edfa_alarm_configuration(Edfa edfa_struct, mxml_node_t *alarms);

// Load data of the alarms of the edfa module
// xfp_struct: is the xfp struct
// alarm_name: name of the alarm
// alarm_value: value of the alarm
void load_edfa_alarm_data(Edfa *edfa_struct, char *alarm_name, int alarm_value);

// Load default parameters for edfa alarm configuration
// edfa_struct: is the edfa struct
void load_default_edfa_alarms_parameters(Edfa *edfa_struct);

#endif /* HL_EDFA_H_ */
