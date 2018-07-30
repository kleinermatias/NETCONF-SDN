#ifndef CS6041_H_
#define CS6041_H_

#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN

#include "tenabo40.h"
#include "cs_types.h"

#include "unistd.h"
#include "../hl_configs/hl_configs.h"

#include "../utils/filelock.h"



/* Initialize the Device Driver and Register the Driver*/
void cs6041_init(cs_uint16 dev_id, T41_t *Chips, cs_uint16 *module_line, cs_uint16 *module_client);

// Reset Cortina's Chip CS6041 to avoid overheat
unsigned int cs6041_protect_action(FILE *file, unsigned int condition);

// Reset Reset Cortina's Chip CS6041
void cs6041_reset(void);

// General Traffic Configuration for Client Side (OTU2 || XGE)
void general_client_traffic_config_line_otu3(cs_uint16 dev_id, cs_uint16 mod_a, cs_uint16 mod_b, cs_uint8 slice_line, cs_uint8 slice_client, cs_uint32 sysclk_freq, cs_uint8 dyn_repro,
		Muxponder mxp);

// OC192 Traffic Type Configuration
void oc192_msregen_bmp_amp_xfi_b_ccupll_400_otu3_gfec_sfi5_1_a_k_64(cs_uint16 dev_id, cs_uint16 mod_a, cs_uint16 mod_b, cs_uint8 slice_line, cs_uint8 slice_client,
		cs_uint32 sysclk_freq, /* freq in Hz */
		cs_uint8 dyn_repro, Muxponder mxp); /* 0 = static, 1 = DR client only, 2 = DR line and client */

// Initialize the cortina chip for traffic generation.
int traffic_initialize(Traffic parameters);

// Main function for pbert configuration.
void pbert_traffic_control(Traffic parameters);

// Evaluates if all the slices configurated for traffic are receiving
// pbert data without errors.
void wait_for_synchronization(int module, int traffic[4]);

// Injection of Pbert errors.
void pbert_error_injection(int module, int traffic[4]);

// Evaluates all the pbert counters needed for the report of results.
cs_status check_pbert_counters(cs_uint16 dev_id, cs_uint16 module_id, cs_uint8 slice, int addHeader, int timeCount, FILE *fp, int console_output, int number_of_slices,
		char table_data[]);

// Configuration of xcon to use Pbert as generator/analyzer.
void hl_xcon_pbert_config(int dev_id, int module_id, int slice);

// Enable or Disable the Pbert Generator.
void hl_xcon_pbert_generator_control(int dev_id, int module_id, int slice, cs_ctl_t status);

// Evaluates the reception of pbert data needed for synchronization.
void read_rx_pbert_counters(cs_uint16 dev_id, cs_uint16 module_id, cs_uint8 slice, cs_uint64 *rx_good_unit, cs_uint64 *rx_error_unit);

// Reports pbert information for one slice in table format.
void slice_data(int slice, char rxU[], char txU[], char errU[], char format[][100], char table_data[]);

// Initial configuration of pbert for half/half test
//void pbert_config_half_half_test(int protocol, int ports[5], int gen_time);
void pbert_config_half_half_test(int protocol, int ports[5], Traffic parameters);

// Enables or disables a loopback in module A or module B.
// Loopbacks available are farend and facility.
void set_cs6041_loopback(int module, int loopback, int enable, int slices[]);

void cs6041_fecstats_init(int module);

// Prints hardware information of the processor module.
void cs6041_hardware_information(void);

// Print the Status of Cortina Module.
void print_status(const char *msg, cs_status status);

// Print defects of Cortina Module.
void print_defects(const char *msg, cs_status status);

void cs6041_init_gcc_tx_rx(cs_uint16 dev_id, cs_uint16 module_line, int gcc);

#endif /* CS6041_H_ */
