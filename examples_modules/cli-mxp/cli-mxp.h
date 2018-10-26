#ifndef _H_cli_mxp
#define _H_cli_mxp
/* 
 * Copyright (c) 2008-2012, Andy Bierman, All Rights Reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *

*** Generated by yangdump 2.11-0

  Combined SIL header
  module cli-mxp
  revision 2018-06-24
  namespace http://fulgor.com/ns/cli-mxp

 */

#include <xmlstring.h>

#include "dlq.h"
#include "ncxtypes.h"
#include "op.h"
#include "status.h"
#include "val.h"

#ifdef __cplusplus
extern "C" {
#endif

#define y_cli_mxp_M_cli_mxp (const xmlChar *)"cli-mxp"
#define y_cli_mxp_R_cli_mxp (const xmlChar *)"2018-06-24"

#define y_cli_mxp_N_EOL_ALM (const xmlChar *)"EOL_ALM"
#define y_cli_mxp_N_INFO (const xmlChar *)"INFO"
#define y_cli_mxp_N_LATCHED_TXFIFO_ERR (const xmlChar *)"LATCHED_TXFIFO_ERR"
#define y_cli_mxp_N_LS_BIAS_ALM (const xmlChar *)"LS_BIAS_ALM"
#define y_cli_mxp_N_LS_POW_ALM (const xmlChar *)"LS_POW_ALM"
#define y_cli_mxp_N_LS_TEMP_ALM (const xmlChar *)"LS_TEMP_ALM"
#define y_cli_mxp_N_LS_WAV_ALM (const xmlChar *)"LS_WAV_ALM"
#define y_cli_mxp_N_MOD_BIAS_ALM (const xmlChar *)"MOD_BIAS_ALM"
#define y_cli_mxp_N_MOD_TEMP_ALM (const xmlChar *)"MOD_TEMP_ALM"
#define y_cli_mxp_N_PRBS_ERR_DET (const xmlChar *)"PRBS_ERR_DET"
#define y_cli_mxp_N_RXALM_INT (const xmlChar *)"RXALM_INT"
#define y_cli_mxp_N_RXPOW_ALM (const xmlChar *)"RXPOW_ALM"
#define y_cli_mxp_N_RXS (const xmlChar *)"RXS"
#define y_cli_mxp_N_RX_LOCK_ERR (const xmlChar *)"RX_LOCK_ERR"
#define y_cli_mxp_N_RX_LOS (const xmlChar *)"RX_LOS"
#define y_cli_mxp_N_TX_ALM_INT (const xmlChar *)"TX_ALM_INT"
#define y_cli_mxp_N_TX_DSC_ERR (const xmlChar *)"TX_DSC_ERR"
#define y_cli_mxp_N_TX_LOCK_ERR (const xmlChar *)"TX_LOCK_ERR"
#define y_cli_mxp_N_TX_LOF_ALM (const xmlChar *)"TX_LOF_ALM"
#define y_cli_mxp_N_TX_OOA (const xmlChar *)"TX_OOA"
#define y_cli_mxp_N_board_humidity_state (const xmlChar *)"board_humidity_state"
#define y_cli_mxp_N_brctl_showstp_br0 (const xmlChar *)"brctl_showstp_br0"
#define y_cli_mxp_N_canal (const xmlChar *)"canal"
#define y_cli_mxp_N_cd_compensacion (const xmlChar *)"cd_compensacion"
#define y_cli_mxp_N_configuracion (const xmlChar *)"configuracion"
#define y_cli_mxp_N_device_boardId (const xmlChar *)"device_boardId"
#define y_cli_mxp_N_device_hwVersion (const xmlChar *)"device_hwVersion"
#define y_cli_mxp_N_device_manufacturer (const xmlChar *)"device_manufacturer"
#define y_cli_mxp_N_device_swVersion (const xmlChar *)"device_swVersion"
#define y_cli_mxp_N_device_neighbors (const xmlChar *)"deviceneighbors"
#define y_cli_mxp_N_edfa_output_power_config (const xmlChar *)"edfa_output_power_config"
#define y_cli_mxp_N_edfa_output_power_state (const xmlChar *)"edfa_output_power_state"
#define y_cli_mxp_N_fpga_temperature_state (const xmlChar *)"fpga_temperature_state"
#define y_cli_mxp_N_interrupt (const xmlChar *)"interrupt"		
#define y_cli_mxp_N_loss (const xmlChar *)"loss"
#define y_cli_mxp_N_mux_apply_config (const xmlChar *)"mux-apply-config"
#define y_cli_mxp_N_mux_config (const xmlChar *)"mux-config"
#define y_cli_mxp_N_mux_notify (const xmlChar *)"mux-notify"
#define y_cli_mxp_N_mux_notify_activate (const xmlChar *)"mux-notify-activate"
#define y_cli_mxp_N_mux_notify_deactivate (const xmlChar *)"mux-notify-deactivate"
#define y_cli_mxp_N_mux_optical_line_status (const xmlChar *)"mux-optical-line-status"
#define y_cli_mxp_N_mux_settings (const xmlChar *)"mux-settings"
#define y_cli_mxp_N_mux_state (const xmlChar *)"mux-state"
#define y_cli_mxp_N_mux_state_TX_RX_alarms (const xmlChar *)"mux-state-TX-RX-alarms"
#define y_cli_mxp_N_mux_state_misc (const xmlChar *)"mux-state-misc"
#define y_cli_mxp_N_potencia (const xmlChar *)"potencia"
#define y_cli_mxp_N_respuesta_mux_apply_config (const xmlChar *)"respuesta-mux-apply-config"
#define y_cli_mxp_N_respuesta_mux_settings (const xmlChar *)"respuesta-mux-settings"
#define y_cli_mxp_N_rx_laser_itu_band (const xmlChar *)"rx_laser_itu_band"
#define y_cli_mxp_N_rx_laser_itu_channel (const xmlChar *)"rx_laser_itu_channel"
#define y_cli_mxp_N_temp_around (const xmlChar *)"temp_around"
#define y_cli_mxp_N_temp_case (const xmlChar *)"temp_case"
#define y_cli_mxp_N_temp_rx_laser (const xmlChar *)"temp_rx_laser"
#define y_cli_mxp_N_temp_tx_laser (const xmlChar *)"temp_tx_laser"
#define y_cli_mxp_N_time_notify_config (const xmlChar *)"time_notify_config"
#define y_cli_mxp_N_tipo_fec_cliente (const xmlChar *)"tipo_fec_cliente"
#define y_cli_mxp_N_tipo_fec_linea (const xmlChar *)"tipo_fec_linea"
#define y_cli_mxp_N_tipo_trafico (const xmlChar *)"tipo_trafico"
#define y_cli_mxp_N_tx_laser_itu_band (const xmlChar *)"tx_laser_itu_band"		
#define y_cli_mxp_N_tx_laser_itu_channel (const xmlChar *)"tx_laser_itu_channel"
#define y_cli_mxp_N_xfp_rx_power (const xmlChar *)"xfp_rx_power"
#define y_cli_mxp_N_xfp_tx_power (const xmlChar *)"xfp_tx_power"


/* leaf-list /mux-config/deviceneighbors */
typedef struct y_cli_mxp_T_mux_config_deviceneighbors_ {
  dlq_hdr_t qhdr;
  xmlChar *deviceneighbors;
} y_cli_mxp_T_mux_config_deviceneighbors;

/* container /mux-config */
typedef struct y_cli_mxp_T_mux_config_ {
  xmlChar *configuracion;
  xmlChar *tipo_trafico;
  xmlChar *tipo_fec_linea;
  xmlChar *tipo_fec_cliente;
  xmlChar *canal;
  xmlChar *potencia;
  xmlChar *cd_compensacion;
  int64 edfa_output_power_config;
  int16 time_notify_config;
  dlq_hdr_t deviceneighbors;
} y_cli_mxp_T_mux_config;

/* container /mux-state */
typedef struct y_cli_mxp_T_mux_state_ {

  /* revision OCTUBRE 2018 */
  xmlChar *device_manufacturer;		
  xmlChar *device_swVersion;		
  xmlChar *device_hwVersion;		
  xmlChar *device_boardId;
  /* revision OCTUBRE 2018 */

  int64 fpga_temperature_state;
  int16 board_humidity_state;
  int64 edfa_output_power_state;
  int64 xfp_tx_power;
  int64 xfp_rx_power;
} y_cli_mxp_T_mux_state;

/* container /mux-state-misc */
typedef struct y_cli_mxp_T_mux_state_misc_ {
  xmlChar *temp_around;
  xmlChar *temp_case;
  xmlChar *temp_tx_laser;
  xmlChar *temp_rx_laser;
  xmlChar *loss;
  xmlChar *interrupt;
  xmlChar *tx_laser_itu_band;
  xmlChar *tx_laser_itu_channel;
  xmlChar *rx_laser_itu_band;
  xmlChar *rx_laser_itu_channel;
} y_cli_mxp_T_mux_state_misc;

/* container /mux-state-TX-RX-alarms */
typedef struct y_cli_mxp_T_mux_state_TX_RX_alarms_ {
  xmlChar *EOL_ALM;
  xmlChar *MOD_TEMP_ALM;
  xmlChar *TX_OOA;
  xmlChar *TX_LOF_ALM;
  xmlChar *TX_DSC_ERR;
  xmlChar *LS_WAV_ALM;
  xmlChar *TX_ALM_INT;
  xmlChar *LS_BIAS_ALM;
  xmlChar *LS_TEMP_ALM;
  xmlChar *TX_LOCK_ERR;
  xmlChar *LS_POW_ALM;
  xmlChar *MOD_BIAS_ALM;
  xmlChar *LATCHED_TXFIFO_ERR;
  xmlChar *RXALM_INT;
  xmlChar *RXPOW_ALM;
  xmlChar *RX_LOS;
  xmlChar *RX_LOCK_ERR;
  xmlChar *RXS;
  xmlChar *PRBS_ERR_DET;
} y_cli_mxp_T_mux_state_TX_RX_alarms;

/* container /mux-optical-line-status */
typedef struct y_cli_mxp_T_mux_optical_line_status_ {
  xmlChar *brctl_showstp_br0;
} y_cli_mxp_T_mux_optical_line_status;

/* container /mux-notify-activate/input */
typedef struct y_cli_mxp_T_mux_notify_activate_input_ {
} y_cli_mxp_T_mux_notify_activate_input;

/* container /mux-notify-activate/output */
typedef struct y_cli_mxp_T_mux_notify_activate_output_ {
} y_cli_mxp_T_mux_notify_activate_output;

/* rpc /mux-notify-activate */
typedef struct y_cli_mxp_T_mux_notify_activate_ {
  y_cli_mxp_T_mux_notify_activate_input input;
  y_cli_mxp_T_mux_notify_activate_output output;
} y_cli_mxp_T_mux_notify_activate;

/* container /mux-notify-deactivate/input */
typedef struct y_cli_mxp_T_mux_notify_deactivate_input_ {
} y_cli_mxp_T_mux_notify_deactivate_input;

/* container /mux-notify-deactivate/output */
typedef struct y_cli_mxp_T_mux_notify_deactivate_output_ {
} y_cli_mxp_T_mux_notify_deactivate_output;

/* rpc /mux-notify-deactivate */
typedef struct y_cli_mxp_T_mux_notify_deactivate_ {
  y_cli_mxp_T_mux_notify_deactivate_input input;
  y_cli_mxp_T_mux_notify_deactivate_output output;
} y_cli_mxp_T_mux_notify_deactivate;

/* container /mux-apply-config/output */
typedef struct y_cli_mxp_T_mux_apply_config_output_ {
  xmlChar *respuesta_mux_apply_config;
} y_cli_mxp_T_mux_apply_config_output;

/* container /mux-apply-config/input */
typedef struct y_cli_mxp_T_mux_apply_config_input_ {
} y_cli_mxp_T_mux_apply_config_input;

/* rpc /mux-apply-config */
typedef struct y_cli_mxp_T_mux_apply_config_ {
  y_cli_mxp_T_mux_apply_config_output output;
  y_cli_mxp_T_mux_apply_config_input input;
} y_cli_mxp_T_mux_apply_config;

/* container /mux-settings/output */
typedef struct y_cli_mxp_T_mux_settings_output_ {
  xmlChar *respuesta_mux_settings;
} y_cli_mxp_T_mux_settings_output;

/* container /mux-settings/input */
typedef struct y_cli_mxp_T_mux_settings_input_ {
} y_cli_mxp_T_mux_settings_input;

/* rpc /mux-settings */
typedef struct y_cli_mxp_T_mux_settings_ {
  y_cli_mxp_T_mux_settings_output output;
  y_cli_mxp_T_mux_settings_input input;
} y_cli_mxp_T_mux_settings;

/* notification /mux-notify */
typedef struct y_cli_mxp_T_mux_notify_ {
  xmlChar *INFO;
} y_cli_mxp_T_mux_notify;


/********************************************************************
* FUNCTION y_cli_mxp_mux_notify_send
* 
* Send a y_cli_mxp_mux_notify notification
* Called by your code when notification event occurs
* 
********************************************************************/
extern void y_cli_mxp_mux_notify_send (
  const xmlChar *INFO);

/********************************************************************
* FUNCTION y_cli_mxp_init
* 
* initialize the cli-mxp server instrumentation library
* 
* INPUTS:
*    modname == requested module name
*    revision == requested version (NULL for any)
* 
* RETURNS:
*     error status
********************************************************************/
extern status_t y_cli_mxp_init (
  const xmlChar *modname,
  const xmlChar *revision);

/********************************************************************
* FUNCTION y_cli_mxp_init2
* 
* SIL init phase 2: non-config data structures
* Called after running config is loaded
* 
* RETURNS:
*     error status
********************************************************************/
extern status_t y_cli_mxp_init2 (void);

/********************************************************************
* FUNCTION y_cli_mxp_cleanup
*    cleanup the server instrumentation library
* 
********************************************************************/
extern void y_cli_mxp_cleanup (void);

#ifdef __cplusplus
} /* end extern 'C' */
#endif

#endif