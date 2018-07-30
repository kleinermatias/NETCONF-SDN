#ifndef HL_TXP_H_
#define HL_TXP_H_

#include "txp.h"
#include "stdio.h"
#include "unistd.h"
#include "../gpio/gpio.h"
#include "../mxml-2.9/mxml.h"
#include <math.h>

typedef struct txp_severity
{
	unsigned int eol;
	unsigned int mod_temp;
	unsigned int txooa;
	unsigned int tx_lof;
	unsigned int tx_dsc;
	unsigned int ls_wav;
	unsigned int ls_bias;
	unsigned int ls_temp;
	unsigned int tx_lock;
	unsigned int ls_pow;
	unsigned int mod_bias;
	unsigned int latched_tx_fifo;
	unsigned int rx_pow;
	unsigned int rx_los;
	unsigned int rx_lock;
	unsigned int rxs;
	unsigned int prbs_err;
	unsigned int psummary;
	unsigned int p5vanalog;
	unsigned int n5v2analog;
	unsigned int p3p3vanalog;
	unsigned int p3p3vdigital;
	unsigned int lvdigital;
	unsigned int n5p2vdigital;

} Txp_severity;

typedef struct txp_struct
{
	float txp_temperature[4];
	int txp_loss;
	int txp_interrupt;
	float txp_tx_power;
	float txp_rx_power;
	float txp_ber_estimate;
	float txp_chromatic_dispersion;
	union tx_alarm_status txp_tx_alarm;
	union rx_alarm_status txp_rx_alarm;
	union power_alarm_status txp_power_alarm;
	union dsp_status_union txp_dspstat;
	union mean_squared_error txp_mse;
	union laser_itu_channel txp_tx_laser_itu_channel;
	union laser_itu_channel txp_rx_laser_itu_channel;
	union bulk_cd_compensation txp_bulk_cd;
	Txp_severity severity;

} Txp;

// Prints hardware information of the transponder
void hl_txp_hardware_information(void);

// Updates the txp part of the alarm configuration file with the information of the txp struct.
// txp_struct: is the txp struct
// alarms: main node for alarm information in the configuration file
void hl_txp_update_alarm_configuration(Txp txp_struct, mxml_node_t *alarms);

// Load data of the alarms of the txp module
// txp_struct: is the txp struct
// alarm_name: name of the alarm
// alarm_value: value of the alarm
void hl_txp_load_alarm_data(Txp *txp_struct, char *alarm_name, int alarm_value);

// Load default parameters for txp alarm configuration
// txp_struct: is the txp struct
void hl_txp_load_default_alarms_parameters(Txp *txp_struct);

void hl_txp_config_40g_otu3(int line_loopback, int dloop, int lsen);

int hl_txp_set_tx_rx_laser_itu_channel(float channel);

int hl_txp_set_bulk_cd_compensation(int min_bulk_cd_comp, int max_bulk_cd_comp);

int hl_txp_get_estimated_chromatic_dispersion(int* estimated_cd);

int hl_txp_get_chromatic_dispersion(float* cd);

#endif /* HL_TXP_H_ */
