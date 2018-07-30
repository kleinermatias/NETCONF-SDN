#ifndef HL_CONFIGS_H_
#define HL_CONFIGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../../lib/clk/clk.h"
#include "../../lib/utils/utils.h"
#include "tenabo40.h"
#include "cs_types.h"
#include "../../lib/mxml-2.9/mxml.h"
#include "../../lib/txp/hl_txp.h"
#include "definitions.h"

#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN
#define MAX_DEVICE  2

// Struct with parameters for traffic scripts configuration
typedef struct traffic_config
{
	int module;
	int traffic[4];
	int generation_time;
	int console_output;
	int line_fec;
	int client_fec;
	int fec_monitor;
} Traffic;

// Struct with parameters for network configuration
typedef struct network_config
{
	unsigned int eth_auto;
	char ip[16];
	char netmask[16];
	char broadcast[16];
	char gateway[16];
} Network;

// Struct with parameters for muxponder configuration
typedef struct mxp_config
{
	unsigned int xfp_loopback[4];
	unsigned int slice_protocol[4];
	unsigned int cs6041_line_fec;
	unsigned int cs6041_client_fec;

	int txp_diagnostic_loopback;
	int txp_line_loopback;
	int txp_laser_enable;
	int txp_min_bulk_cd_comp;
	int txp_max_bulk_cd_comp;
	int txp_channel;

	float edfa_pout;
	int fec_monitor;

	Network network[1];

	int gcc;
} Muxponder;

// Struct with parameters for loopback configuration
typedef struct loopback_config
{
	char module[100];
	char loopback[100];
	char side[100];
	int slices[5];
	int enable;
} Loopback;

void *thread_function(void *arg);

// Full Muxponder configuration
void mxp_configuration(Muxponder mxp);

// Muxponder Reconfiguration
void mxp_reconfiguration(Muxponder mxp);

// Load the muxponder configuration struct from the configuration file
// mxp: is a reference to the muxponder configuration struct to load
void load_configuration_file(Muxponder *mxp);

// Updates the configuration file with the information of the
// muxponder struct.
// mxp: is the muxponder configuration struct
void update_initial_configuration_file(Muxponder mxp);

// Load default muxponder configuration values for all modules
// mxp: is a reference to the muxponder configuration struct to load
void load_default_configuration_parameters(Muxponder *mxp);

// Load muxponder configuration values
// mxp: is a reference to the muxponder configuration struct to load
// config_node: xml node to provide configuration information
void load_configuration_data(Muxponder *mxp, mxml_node_t *config_node);

// Load the muxponder configuration parameters
// network: network structs to load
// network_node: xml node to provide network parameters
void load_muxponder_configuration_data(Muxponder *mxp, mxml_node_t *current_node);

// Load ethernet network parameters into a network struct
// network: is a network struct to load
// network_node: xml node to provide network parameters
void load_eth_parameters(Network *network, mxml_node_t *network_node);

// Set the network configuration
// mxp: is the muxponder configuration struct
// eth_port: is the eth port to configure
void network_configuration(Muxponder mxp, int eth_port);

// Load the alarm configuration struct from the configuration file
// monitor: is a reference to the monitor configuration struct to load
void load_alarm_configuration(Monitor *monitor);

// Load data of the alarms of a module (xfp, txp,..)
// monitor: is a reference to the monitor configuration struct to load
// module_alarms is the information about the configuration of the alarms of the module
void load_alarm_data(Monitor *monitor, mxml_node_t *module_alarms);

// Load traffic processor severity alarm data
// tp_defects_struct: struct with traffic processor parameters
// current_tp_node: xml node of traffic processor
void load_tp_alarm_data(TP_defects *tp_defects_struct, mxml_node_t *current_tp_node);

// Load traffic processor severity line parameters
// tp_defects_struct: struct with traffic processor parameters
// current_tp_node: xml node of traffic processor
void load_tp_line_alarm_data(TP_defects *tp_defects_struct, mxml_node_t *current_tp_node);

// Load traffic processor severity client parameters
// tp_defects_struct: struct with traffic processor parameters
// current_tp_node: xml node of traffic processor
void load_tp_client_alarm_data(TP_defects *tp_defects_struct, mxml_node_t *current_tp_node);

// Load default severity values for traffic processor
// tp_defects_struct: struct with traffic processor parameters
void load_default_tp_alarms_parameters(TP_defects *tp_defects_struct);

// tp_defects_struct: struct with traffic processor parameters
// alarms: xml node for severity alarms
void update_tp_alarm_configuration(TP_defects tp_defects_struct, mxml_node_t *alarms);

// Load default alarm configuration values for all modules
// monitor: is a reference to the monitor configuration struct to load
void load_default_alarm_configuration(Monitor *monitor);

// Updates the alarm configuration file with the information of the Monitor struct.
// monitor: is the monitor struct
void update_alarm_configuration_file(Monitor monitor);

#endif /* HL_CONFIGS_H_ */
