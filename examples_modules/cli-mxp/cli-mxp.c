#include <xmlstring.h>
#include "procdefs.h"
#include "agt.h"
#include "agt_cb.h"
#include "agt_not.h"
#include "agt_rpc.h"
#include "agt_timer.h"
#include "agt_util.h"
#include "dlq.h"
#include "ncx.h"
#include "ncx_feature.h"
#include "ncxmod.h"
#include "ncxtypes.h"
#include "rpc.h"
#include "ses.h"
#include "status.h"
#include "val.h"
#include "val_util.h"
#include "xml_util.h"
#include "cli-mxp.h"

/* module static variables */
static ncx_module_t *cli_mxp_mod;
static obj_template_t *mux_config_obj;
static obj_template_t *mux_state_obj;
static obj_template_t *mux_state_misc_obj;
static obj_template_t *mux_state_TX_RX_alarms_obj;
static obj_template_t *mux_state_power_obj;
static obj_template_t *mux_state_dsp_obj;
static obj_template_t *mux_state_edfa_obj;
static obj_template_t *mux_state_temp_hum_obj;
static obj_template_t *mux_state_XFP1_obj;
static obj_template_t *mux_state_XFP2_obj;
static obj_template_t *mux_state_XFP3_obj;
static obj_template_t *mux_state_XFP4_obj;
static obj_template_t *mux_optical_line_status_obj;
static obj_template_t *mux_notify_activate_obj;
static obj_template_t *mux_notify_deactivate_obj;
static obj_template_t *mux_apply_config_obj;
static obj_template_t *mux_settings_obj;
static obj_template_t *mux_notify_obj;
static val_value_t *mux_config_val;

/* mux includes */
#include "../../mxp40G/lib/hl_configs/definitions.h"
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/* put your static variables here */
sem_t mutex;
Monitor *pt_monitor_struct;
Monitor pt_monitor_struct_anterior = {0};

int shmfd;
int rpc_in_progress = 0;
float edfa_output_power_conf;
static pthread_t alarma_tid;
const xmlChar *tipo_trafico_var;
const xmlChar *tipo_fec_linea_var;
const xmlChar *tipo_fec_cliente_var;
static char alarms[2][100] = {"Alarm", "--"}; //al reve para xfp
static char general_status[2][100] = {"Yes", "No"};

static int warning_config_actual = 0;
static int warning_config_anterior = 0;
static int flag_xfp[4][7] = {0};

//los uso para enviar las notificaciones netconf
char buffa[100];
char buffb[100];

static int initial_polling_alarms = 0;

struct Device_info
{
  char device_manufacturer[50];
  char device_swVersion[50];
  char device_hwVersion[50];
  char device_boardId[50];
} device_info;

static void *
alarmas_thread(void *arg)
{
  int rc;
  rc = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

  while (alarma_tid)
  {
    sem_wait(&mutex);

    sleep(1);
    
    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.eolalm != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.eolalm))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.eolalm = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.eolalm;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.eolalm == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] EOL ALM");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] EOL ALM");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modtempalm != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.modtempalm))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.modtempalm = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modtempalm;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modtempalm == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Mod TEMP ALM");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Mod TEMP ALM");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txooa != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.txooa))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.txooa = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txooa;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txooa == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] TxOOA");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] TxOOA");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlofalm != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.txlofalm))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.txlofalm = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlofalm;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlofalm == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx LOF ALM");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx LOF ALM");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txdscerr != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.txdscerr))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.txdscerr = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txdscerr;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txdscerr == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx DSC ERR");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx DSC ERR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lswavalm != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.lswavalm))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.lswavalm = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lswavalm;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lswavalm == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Ls WAV ALM");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Ls WAV ALM");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txalmint != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.txalmint))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.txalmint = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txalmint;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txalmint == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx ALM INT");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx ALM INT");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lsbiasalm != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.lsbiasalm))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.lsbiasalm = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lsbiasalm;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lsbiasalm == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Ls BIAS ALM");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Ls BIAS ALM");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lstempalm != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.lstempalm))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.lstempalm = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lstempalm;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lstempalm == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Ls TEMP ALM");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Ls TEMP ALM");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlockerr != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.txlockerr))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.txlockerr = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlockerr;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlockerr == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx LOCK ERR");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx LOCK ERR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lspowalm != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.lspowalm))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.lspowalm = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lspowalm;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lspowalm == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Ls POW ALM");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Ls POW ALM");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modbiasalm != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.modbiasalm))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.modbiasalm = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modbiasalm;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modbiasalm == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Mod BIAS ALM");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Mod BIAS ALM");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.latchedtxfifoerr != pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.latchedtxfifoerr))
    {
      pt_monitor_struct_anterior.txp_struct.txp_tx_alarm.fields.latchedtxfifoerr = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.latchedtxfifoerr;
      if (pt_monitor_struct->txp_struct.txp_tx_alarm.fields.latchedtxfifoerr == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] LATCHED TxFIFO ERR");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] LATCHED TxFIFO ERR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxalmint != pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.rxalmint))
    {
      pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.rxalmint = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxalmint;
      if (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxalmint == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] RxALM INT");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] RxALM INT");
      }
    }

    sleep(1); //duermo por alarmas

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxpowalm != pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.rxpowalm))
    {
      pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.rxpowalm = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxpowalm;
      if (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxpowalm == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Rx POW ALM");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Rx POW ALM");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlos != pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.rxlos))
    {
      pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.rxlos = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlos;
      if (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlos == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Rx LOS");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Rx LOS");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlockerr != pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.rxlockerr))
    {
      pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.rxlockerr = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlockerr;
      if (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlockerr == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Rx LOCK ERR");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Rx LOCK ERR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxs != pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.rxs))
    {
      pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.rxs = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxs;
      if (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxs == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] RXS");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] RXS");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.prbserrdet != pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.prbserrdet))
    {
      pt_monitor_struct_anterior.txp_struct.txp_rx_alarm.fields.prbserrdet = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.prbserrdet;
      if (pt_monitor_struct->txp_struct.txp_rx_alarm.fields.prbserrdet == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] PRBS ERR DET");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] PRBS ERR DET");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_power_alarm.fields.psummary != pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.psummary))
    {
      pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.psummary = pt_monitor_struct->txp_struct.txp_power_alarm.fields.psummary;
      if (pt_monitor_struct->txp_struct.txp_power_alarm.fields.psummary == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] PSUMMARY");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] PSUMMARY");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_power_alarm.fields.p5vanalog != pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.p5vanalog))
    {
      pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.p5vanalog = pt_monitor_struct->txp_struct.txp_power_alarm.fields.p5vanalog;
      if (pt_monitor_struct->txp_struct.txp_power_alarm.fields.p5vanalog == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] P5VANALOG");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] P5VANALOG");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_power_alarm.fields.n5v2analog != pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.n5v2analog))
    {
      pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.n5v2analog = pt_monitor_struct->txp_struct.txp_power_alarm.fields.n5v2analog;
      if (pt_monitor_struct->txp_struct.txp_power_alarm.fields.n5v2analog == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] N5V2ANALOG");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] N5V2ANALOG");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_power_alarm.fields.p3p3vanalog != pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.p3p3vanalog))
    {
      pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.p3p3vanalog = pt_monitor_struct->txp_struct.txp_power_alarm.fields.p3p3vanalog;
      if (pt_monitor_struct->txp_struct.txp_power_alarm.fields.p3p3vanalog == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] P3P3VANALOG");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] P3P3VANALOG");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_power_alarm.fields.p3p3vdigital != pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.p3p3vdigital))
    {
      pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.p3p3vdigital = pt_monitor_struct->txp_struct.txp_power_alarm.fields.p3p3vdigital;
      if (pt_monitor_struct->txp_struct.txp_power_alarm.fields.p3p3vdigital == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] P3P3VDIGITAL");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] P3P3VDIGITAL");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_power_alarm.fields.lvdigital != pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.lvdigital))
    {
      pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.lvdigital = pt_monitor_struct->txp_struct.txp_power_alarm.fields.lvdigital;
      if (pt_monitor_struct->txp_struct.txp_power_alarm.fields.lvdigital == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] LVDIGITAL");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] LVDIGITAL");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->txp_struct.txp_power_alarm.fields.n5p2vdigital != pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.n5p2vdigital))
    {
      pt_monitor_struct_anterior.txp_struct.txp_power_alarm.fields.n5p2vdigital = pt_monitor_struct->txp_struct.txp_power_alarm.fields.n5p2vdigital;
      if (pt_monitor_struct->txp_struct.txp_power_alarm.fields.n5p2vdigital == 0)
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] N5P2VDIGITAL");
      }
      else
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] N5P2VDIGITAL");
      }
    }


    sleep(1); //duermo por alarmas

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][0] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][0]))
    {
      if (((flag_xfp[0][0] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][0] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][0]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Low Tx Power Alarm XFP1");
        flag_xfp[0][0] = 1;
      }
      else if (((flag_xfp[0][0] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][0] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][0]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Low Tx Power Alarm XFP1");
        flag_xfp[0][0] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][1] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][1]))
    {
      if (((flag_xfp[0][1] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][1] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][1]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] High Tx Power Alarm XFP1");
        flag_xfp[0][1] = 1;
      }
      else if (((flag_xfp[0][1] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][1] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][1]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] High Tx Power Alarm XFP1");
        flag_xfp[0][1] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][2] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][2]))
    {
      if (((flag_xfp[0][2] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][2] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][2]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Low Rx Power Alarm XFP1");
        flag_xfp[0][2] = 1;
      }
      else if (((flag_xfp[0][2] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][2] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][2]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Low Rx Power Alarm XFP1");
        flag_xfp[0][2] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][3] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][3]))
    {
      if (((flag_xfp[0][3] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][3] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][3]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] High Rx Power Alarm XFP1");
        flag_xfp[0][3] = 1;
      }
      else if (((flag_xfp[0][3] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][3] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][3]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] High Rx Power Alarm XFP1");
        flag_xfp[0][3] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][4] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][4]))
    {
      if (((flag_xfp[0][4] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][4] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][4]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Rx CDR Loss of Lock XFP1");
        flag_xfp[0][4] = 1;
      }
      else if (((flag_xfp[0][4] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][4] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][4]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Rx CDR Loss of Lock XFP1");
        flag_xfp[0][4] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][5] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][5]))
    {
      if (((flag_xfp[0][5] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][5] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][5]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx CDR Loss of Lock XFP1");
        flag_xfp[0][5] = 1;
      }
      else if (((flag_xfp[0][5] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][5] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][5]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx CDR Loss of Lock XFP1");
        flag_xfp[0][5] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][6] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][6]))
    {
      if (((flag_xfp[0][6] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][6] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][6]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Laser Fault XFP1");
        flag_xfp[0][6] = 1;
      }
      else if (((flag_xfp[0][6] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][6] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[0][6]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Laser Fault XFP1");
        flag_xfp[0][6] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][0] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][0]))
    {
      if (((flag_xfp[1][0] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][0] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][0]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Low Tx Power Alarm XFP2");
        flag_xfp[1][0] = 1;
      }
      else if (((flag_xfp[1][0] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][0] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][0]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Low Tx Power Alarm XFP2");
        flag_xfp[1][0] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][1] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][1]))
    {
      if (((flag_xfp[1][1] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][1] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][1]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] High Tx Power Alarm XFP2");
        flag_xfp[1][1] = 1;
      }
      else if (((flag_xfp[1][1] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][1] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][1]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] High Tx Power Alarm XFP2");
        flag_xfp[1][1] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][2] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][2]))
    {
      if (((flag_xfp[1][2] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][2] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][2]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Low Rx Power Alarm XFP2");
        flag_xfp[1][2] = 1;
      }
      else if (((flag_xfp[1][2] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][2] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][2]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Low Rx Power Alarm XFP2");
        flag_xfp[1][2] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][3] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][3]))
    {
      if (((flag_xfp[1][3] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][3] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][3]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] High Rx Power Alarm XFP2");
        flag_xfp[1][3] = 1;
      }
      else if (((flag_xfp[1][3] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][3] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][3]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] High Rx Power Alarm XFP2");
        flag_xfp[1][3] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][4] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][4]))
    {
      if (((flag_xfp[1][4] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][4] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][4]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Rx CDR Loss of Lock XFP2");
        flag_xfp[1][4] = 1;
      }
      else if (((flag_xfp[1][4] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][4] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][4]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Rx CDR Loss of Lock XFP2");
        flag_xfp[1][4] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][5] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][5]))
    {
      if (((flag_xfp[1][5] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][5] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][5]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx CDR Loss of Lock XFP2");
        flag_xfp[1][5] = 1;
      }
      else if (((flag_xfp[1][5] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][5] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][5]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx CDR Loss of Lock XFP2");
        flag_xfp[1][5] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][6] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][6]))
    {
      if (((flag_xfp[1][6] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][6] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][6]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Laser Fault XFP2");
        flag_xfp[1][6] = 1;
      }
      else if (((flag_xfp[1][6] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][6] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[1][6]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Laser Fault XFP2");
        flag_xfp[1][6] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][0] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][0]))
    {
      if (((flag_xfp[2][0] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][0] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][0]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Low Tx Power Alarm XFP3");
        flag_xfp[2][0] = 1;
      }
      else if (((flag_xfp[2][0] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][0] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][0]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Low Tx Power Alarm XFP3");
        flag_xfp[2][0] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][1] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][1]))
    {
      if (((flag_xfp[2][1] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][1] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][1]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] High Tx Power Alarm XFP3");
        flag_xfp[2][1] = 1;
      }
      else if (((flag_xfp[2][1] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][1] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][1]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] High Tx Power Alarm XFP3");
        flag_xfp[2][1] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][2] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][2]))
    {
      if (((flag_xfp[2][2] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][2] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][2]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Low Rx Power Alarm XFP3");
        flag_xfp[2][2] = 1;
      }
      else if (((flag_xfp[2][2] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][2] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][2]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Low Rx Power Alarm XFP3");
        flag_xfp[2][2] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][3] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][3]))
    {
      if (((flag_xfp[2][3] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][3] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][3]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] High Rx Power Alarm XFP3");
        flag_xfp[2][3] = 1;
      }
      else if (((flag_xfp[2][3] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][3] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][3]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] High Rx Power Alarm XFP3");
        flag_xfp[2][3] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][4] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][4]))
    {
      if (((flag_xfp[2][4] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][4] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][4]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Rx CDR Loss of Lock XFP3");
        flag_xfp[2][4] = 1;
      }
      else if (((flag_xfp[2][4] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][4] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][4]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Rx CDR Loss of Lock XFP3");
        flag_xfp[2][4] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][5] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][5]))
    {
      if (((flag_xfp[2][5] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][5] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][5]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx CDR Loss of Lock XFP3");
        flag_xfp[2][5] = 1;
      }
      else if (((flag_xfp[2][5] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][5] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][5]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx CDR Loss of Lock XFP3");
        flag_xfp[2][5] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][6] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][6]))
    {
      if (((flag_xfp[2][6] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][6] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][6]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Laser Fault XFP3");
        flag_xfp[2][6] = 1;
      }
      else if (((flag_xfp[2][6] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][6] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[2][6]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Laser Fault XFP3");
        flag_xfp[2][6] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][0] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][0]))
    {
      if (((flag_xfp[3][0] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][0] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][0]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Low Tx Power Alarm XFP4");
        flag_xfp[3][0] = 1;
      }
      else if (((flag_xfp[3][0] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][0] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][0]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Low Tx Power Alarm XFP4");
        flag_xfp[3][0] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][1] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][1]))
    {
      if (((flag_xfp[3][1] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][1] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][1]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] High Tx Power Alarm XFP4");
        flag_xfp[3][1] = 1;
      }
      else if (((flag_xfp[3][1] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][1] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][1]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] High Tx Power Alarm XFP4");
        flag_xfp[3][1] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][2] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][2]))
    {
      if (((flag_xfp[3][2] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][2] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][2]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Low Rx Power Alarm XFP4");
        flag_xfp[3][2] = 1;
      }
      else if (((flag_xfp[3][2] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][2] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][2]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Low Rx Power Alarm XFP4");
        flag_xfp[3][2] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][3] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][3]))
    {
      if (((flag_xfp[3][3] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][3] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][3]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] High Rx Power Alarm XFP4");
        flag_xfp[3][3] = 1;
      }
      else if (((flag_xfp[3][3] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][3] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][3]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] High Rx Power Alarm XFP4");
        flag_xfp[3][3] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][4] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][4]))
    {
      if (((flag_xfp[3][4] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][4] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][4]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Rx CDR Loss of Lock XFP4");
        flag_xfp[3][4] = 1;
      }
      else if (((flag_xfp[3][4] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][4] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][4]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Rx CDR Loss of Lock XFP4");
        flag_xfp[3][4] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][5] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][5]))
    {
      if (((flag_xfp[3][5] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][5] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][5]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx CDR Loss of Lock XFP4");
        flag_xfp[3][5] = 1;
      }
      else if (((flag_xfp[3][5] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][5] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][5]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx CDR Loss of Lock XFP4");
        flag_xfp[3][5] = 0;
      }
      else
      {
        printf("ERROR");
      }
    }

    if ((initial_polling_alarms == 1) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][6] != pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][6]))
    {
      if (((flag_xfp[3][6] == 1) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][6] > pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][6]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Laser Fault XFP4");
        flag_xfp[3][6] = 1;
      }
      else if (((flag_xfp[3][6] == 0) && (initial_polling_alarms == 1)) || (pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][6] < pt_monitor_struct_anterior.xfp_struct.xfp_interruption_flags[3][6]))
      {
        usleep(100000);
        y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Laser Fault XFP4");
        flag_xfp[3][6] = 0;
      }
      else
      {
        printf("\n ERROR :\n");
      }
    }

    initial_polling_alarms = 0;
    memcpy(&pt_monitor_struct_anterior, pt_monitor_struct, sizeof(Monitor));

    if (rpc_in_progress)
    {
      printf("\n Duermo el hilo :\n");
      sleep(95);
      printf("\n Abro mem compartida :\n");
      
      shmfd = shm_open(SHMOBJ_PATH, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
      if (shmfd < 0)
      {
        printf("\n ERROR POR ACA :\n");
        printf("Error in SHM_OPEN () \n");
        perror("In shm_open()");
        exit(1);
      }

      ftruncate(shmfd, SHM_SIZE);

      pt_monitor_struct = (Monitor *)mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
      if (pt_monitor_struct == NULL)
      {
        printf("\n ERROR POR ACA2 :\n");
        printf("Error in mmap() \n");
        perror("In mmap()");
        exit(1);
      }
      
      initial_polling_alarms = 1;
      rpc_in_progress = 0;
      pt_monitor_struct_anterior = {0};
    }

    if ((warning_config_actual != warning_config_anterior) && (warning_config_actual != 0))
    {
      strcpy(buffa, "[WARNING] mux-notify xmlns; Inconsistent config with neighbor ");
      sprintf(buffb, "%d", warning_config_actual);
      strcat(buffa, buffb);
      y_cli_mxp_mux_notify_send((const xmlChar *)buffa);
      warning_config_actual = 0;
      warning_config_anterior = 0;
    }

    
    warning_config_anterior = warning_config_actual;
    sem_post(&mutex);
    sleep(1);
  }
  
  return NULL;
}

// reverses a string 'str' of length 'len'
void reverse(char *str, int len)
{
  int i = 0, j = len - 1, temp;
  while (i < j)
  {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

// Converts a given integer x to string str[].  d is the number
// of digits required in output. If d is more than the number
// of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
  int i = 0;
  while (x)
  {
    str[i++] = (x % 10) + '0';
    x = x / 10;
  }

  // If number of digits required is more, then
  // add 0s at the beginning
  while (i < d)
    str[i++] = '0';

  reverse(str, i);
  str[i] = '\0';
  return i;
}

// Converts a floating point number to string.
void ftoa(float n, char *res, int afterpoint)
{
  // Extract integer part
  int ipart = (int)n;

  // Extract floating part
  float fpart = n - (float)ipart;

  // convert integer part to string
  int i = intToStr(ipart, res, 0);

  // check for display option after point
  if (afterpoint != 0)
  {
    res[i] = '.'; // add dot

    // Get the value of fraction part upto given no.
    // of points after dot. The third parameter is needed
    // to handle cases like 233.007
    fpart = fpart * pow(10, afterpoint);

    intToStr((int)fpart, res + i + 1, afterpoint);
  }
}

/********************************************************************
* FUNCTION y_cli_mxp_init_static_vars
* 
* initialize module static variables
* 
********************************************************************/
static void y_cli_mxp_init_static_vars(void)
{
  cli_mxp_mod = NULL;
  mux_config_obj = NULL;
  mux_state_obj = NULL;
  mux_state_misc_obj = NULL;
  mux_state_TX_RX_alarms_obj = NULL;
  mux_state_power_obj = NULL;
  mux_state_dsp_obj = NULL;
  mux_state_edfa_obj = NULL;
  mux_state_temp_hum_obj = NULL;
  mux_state_XFP1_obj = NULL;
  mux_state_XFP2_obj = NULL;
  mux_state_XFP3_obj = NULL;
  mux_state_XFP4_obj = NULL;
  mux_optical_line_status_obj = NULL;
  mux_notify_activate_obj = NULL;
  mux_notify_deactivate_obj = NULL;
  mux_apply_config_obj = NULL;
  mux_settings_obj = NULL;
  mux_notify_obj = NULL;
  mux_config_val = NULL;

  /* init your static variables here */
  edfa_output_power_conf = 0.0;
  sem_init(&mutex, 0, 1);

  /* PRUEBA */
  FILE *fp;
  char aux_buf[1024];

  if ((fp = fopen("/root/usrapp/deviceDescription.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
  }

  fgets(aux_buf, sizeof(aux_buf), fp);
  aux_buf[strlen(aux_buf) - 1] = '\0';
  strcpy(device_info.device_manufacturer, aux_buf);

  fgets(aux_buf, sizeof(aux_buf), fp);
  aux_buf[strlen(aux_buf) - 1] = '\0';
  strcpy(device_info.device_swVersion, aux_buf);

  fgets(aux_buf, sizeof(aux_buf), fp);
  aux_buf[strlen(aux_buf) - 1] = '\0';
  strcpy(device_info.device_hwVersion, aux_buf);

  fgets(aux_buf, sizeof(aux_buf), fp);
  aux_buf[strlen(aux_buf) - 1] = '\0';
  strcpy(device_info.device_boardId, aux_buf);

  fclose(fp);
  rpc_in_progress = 0;
  /* PRUEBA */

} /* y_cli_mxp_init_static_vars */

/********************************************************************
* FUNCTION cli_mxp_mux_config_configuracion_edit
* 
* Edit database object callback
* Path: /mux-config/configuracion
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_configuracion_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_configuracion_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_configuracion_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_tipo_trafico_edit
* 
* Edit database object callback
* Path: /mux-config/tipo_trafico
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_tipo_trafico_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_tipo_trafico_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    tipo_trafico_var = VAL_STRING(newval);
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_tipo_trafico_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_tipo_fec_linea_edit
* 
* Edit database object callback
* Path: /mux-config/tipo_fec_linea
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_tipo_fec_linea_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_tipo_fec_linea_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    tipo_fec_linea_var = VAL_STRING(newval);
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_tipo_fec_linea_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_tipo_fec_cliente_edit
* 
* Edit database object callback
* Path: /mux-config/tipo_fec_cliente
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_tipo_fec_cliente_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_tipo_fec_cliente_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    tipo_fec_cliente_var = VAL_STRING(newval);
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_tipo_fec_cliente_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_canal_edit
* 
* Edit database object callback
* Path: /mux-config/canal
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_canal_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_canal_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_canal_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_potencia_edit
* 
* Edit database object callback
* Path: /mux-config/potencia
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_potencia_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_potencia_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_potencia_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_cd_compensacion_edit
* 
* Edit database object callback
* Path: /mux-config/cd_compensacion
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_cd_compensacion_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_cd_compensacion_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_cd_compensacion_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_edfa_output_power_config_edit
* 
* Edit database object callback
* Path: /mux-config/edfa_output_power_config
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_edfa_output_power_config_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_edfa_output_power_config_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    edfa_output_power_conf = VAL_DEC64(newval) / 10.00;

    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_edfa_output_power_config_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_warning_config_edit
* 
* Edit database object callback
* Path: /mux-config/warning_config
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_warning_config_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_warning_config_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    warning_config_actual = VAL_INT(newval);

    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_warning_config_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_ports_port_edit
* 
* Edit database object callback
* Path: /mux-config/ports/port
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_ports_port_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_ports_port_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_ports_port_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_ports_neighbor_edit
* 
* Edit database object callback
* Path: /mux-config/ports/neighbor
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_ports_neighbor_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_ports_neighbor_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_ports_neighbor_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_ports_port_neighbor_edit
* 
* Edit database object callback
* Path: /mux-config/ports/port_neighbor
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_ports_port_neighbor_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_ports_port_neighbor_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_ports_port_neighbor_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_ports_edit
* 
* Edit database object callback
* Path: /mux-config/ports
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_ports_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_ports_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_ports_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_edit
* 
* Edit database object callback
* Path: /mux-config
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_edit(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    agt_cbtyp_t cbtyp,
    op_editop_t editop,
    val_value_t *newval,
    val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_config_edit callback for %s phase",
              agt_cbtype_name(cbtyp));
  }

  switch (cbtyp)
  {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop)
    {
    case OP_EDITOP_LOAD:
      break;
    case OP_EDITOP_MERGE:
      break;
    case OP_EDITOP_REPLACE:
      break;
    case OP_EDITOP_CREATE:
      break;
    case OP_EDITOP_DELETE:
      break;
    default:
      res = SET_ERROR(ERR_INTERNAL_VAL);
    }

    if (res == NO_ERR)
    {
      res = agt_check_cache(&mux_config_val, newval, curval, editop);
    }

    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_CONTENT,
        res,
        NULL,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* cli_mxp_mux_config_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_state_fpga_temperature_state_get
* 
* Get database object callback
* Path: /mux-state/fpga_temperature_state
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_fpga_temperature_state_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *fpga_temperatures;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_fpga_temperature_state_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the fpga_temperature_state var here, change zero */

  char buff[20];

  float fpga_temperatur = pt_monitor_struct->general_struct.fpga_temperature;
  ftoa(fpga_temperatur, buff, 2);

  /* set the fpga_temperature var here, change zero */
  fpga_temperatures = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      fpga_temperatures);

  return res;

} /* cli_mxp_mux_state_fpga_temperature_state_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_board_humidity_state_get
* 
* Get database object callback
* Path: /mux-state/board_humidity_state
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_board_humidity_state_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *board_humidity_state;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_board_humidity_state_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the board_humidity_state var here, change zero */
  /* set the fpga_temperature var here, change zero */

  char buff[16];
  sprintf(buff, "%d", pt_monitor_struct->general_struct.board_humidity);
  board_humidity_state = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      board_humidity_state);

  return res;

} /* cli_mxp_mux_state_board_humidity_state_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_edfa_output_power_state_get
* 
* Get database object callback
* Path: /mux-state/edfa_output_power_state
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_edfa_output_power_state_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_edfa_output_power_state_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the edfa_output_power_state var here, change zero */
  const xmlChar *edfa_output_power_state;

  /* set the fpga_temperature var here, change zero */
  edfa_output_power_state = (const xmlChar *)pt_monitor_struct->edfa_struct.edfa_output_power;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      edfa_output_power_state);

  return res;

} /* cli_mxp_mux_state_edfa_output_power_state_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_xfp_tx_power_get
* 
* Get database object callback
* Path: /mux-state/xfp_tx_power
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_xfp_tx_power_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *tx_power;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_xfp_tx_power_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the xfp_tx_power var here */

  float tx_powe = pt_monitor_struct->txp_struct.txp_tx_power;
  char buf[30];
  sprintf(buf, "%.2f", tx_powe);
  //printf(buf);
  tx_power = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      tx_power);

  return res;

} /* cli_mxp_mux_state_xfp_tx_power_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_xfp_rx_power_get
* 
* Get database object callback
* Path: /mux-state/xfp_rx_power
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_xfp_rx_power_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *rx_power;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_xfp_rx_power_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the xfp_rx_power var here */

  float rx_powe = pt_monitor_struct->txp_struct.txp_rx_power;
  char buf[30];
  sprintf(buf, "%.2f", rx_powe);
  //printf(buf);
  rx_power = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      rx_power);

  return res;

} /* cli_mxp_mux_state_xfp_rx_power_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_device_manufacturer_get
* 
* Get database object callback
* Path: /mux-state/device_manufacturer
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_device_manufacturer_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *device_manufacturer;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_device_manufacturer_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the device_manufacturer var here, change EMPTY_STRING */

  device_manufacturer = (const xmlChar *)device_info.device_manufacturer;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      device_manufacturer);

  return res;

} /* cli_mxp_mux_state_device_manufacturer_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_device_swVersion_get
* 
* Get database object callback
* Path: /mux-state/device_swVersion
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_device_swVersion_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *device_swVersion;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_device_swVersion_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the device_swVersion var here, change EMPTY_STRING */
  device_swVersion = (const xmlChar *)device_info.device_swVersion;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      device_swVersion);

  return res;

} /* cli_mxp_mux_state_device_swVersion_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_device_hwVersion_get
* 
* Get database object callback
* Path: /mux-state/device_hwVersion
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_device_hwVersion_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *device_hwVersion;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_device_hwVersion_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the device_hwVersion var here, change EMPTY_STRING */
  device_hwVersion = (const xmlChar *)device_info.device_hwVersion;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      device_hwVersion);

  return res;

} /* cli_mxp_mux_state_device_hwVersion_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_device_boardId_get
* 
* Get database object callback
* Path: /mux-state/device_boardId
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_device_boardId_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *device_boardId;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_device_boardId_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the device_boardId var here, change EMPTY_STRING */
  device_boardId = (const xmlChar *)device_info.device_boardId;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      device_boardId);

  return res;

} /* cli_mxp_mux_state_device_boardId_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_temp_around_get
* 
* Get database object callback
* Path: /mux-state-misc/temp_around
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_misc_temp_around_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_misc_temp_around_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the temp_around var here, change EMPTY_STRING */
  const xmlChar *temp_around_c;
  float temp_around = pt_monitor_struct->txp_struct.txp_temperature[0];
  char buf[30];
  sprintf(buf, "%.2f", temp_around);
  temp_around_c = (const xmlChar *)buf;

  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      temp_around_c);

  return res;

} /* cli_mxp_mux_state_misc_temp_around_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_temp_case_get
* 
* Get database object callback
* Path: /mux-state-misc/temp_case
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_misc_temp_case_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_misc_temp_case_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the temp_case var here, change EMPTY_STRING */
  const xmlChar *temp_case_c;
  float temp_case = pt_monitor_struct->txp_struct.txp_temperature[1];
  char buf[30];
  sprintf(buf, "%.2f", temp_case);
  temp_case_c = (const xmlChar *)buf;

  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      temp_case_c);

  return res;

} /* cli_mxp_mux_state_misc_temp_case_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_temp_tx_laser_get
* 
* Get database object callback
* Path: /mux-state-misc/temp_tx_laser
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_misc_temp_tx_laser_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_misc_temp_tx_laser_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the temp_tx_laser var here, change EMPTY_STRING */
  const xmlChar *temp_tx_laser_c;
  float temp_tx_laser = pt_monitor_struct->txp_struct.txp_temperature[2];
  char buf[30];
  sprintf(buf, "%.2f", temp_tx_laser);
  temp_tx_laser_c = (const xmlChar *)buf;

  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      temp_tx_laser_c);

  return res;

} /* cli_mxp_mux_state_misc_temp_tx_laser_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_temp_rx_laser_get
* 
* Get database object callback
* Path: /mux-state-misc/temp_rx_laser
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_misc_temp_rx_laser_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_misc_temp_rx_laser_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the temp_rx_laser var here, change EMPTY_STRING */
  const xmlChar *temp_rx_laser_c;
  float temp_rx_laser = pt_monitor_struct->txp_struct.txp_temperature[3];
  char buf[30];
  sprintf(buf, "%.2f", temp_rx_laser);
  temp_rx_laser_c = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      temp_rx_laser_c);

  return res;

} /* cli_mxp_mux_state_misc_temp_rx_laser_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_loss_get
* 
* Get database object callback
* Path: /mux-state-misc/loss
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_misc_loss_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *loss;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_misc_loss_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the loss var here, change EMPTY_STRING */
  int loss_int = pt_monitor_struct->txp_struct.txp_loss;
  loss = (const xmlChar *)general_status[loss_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      loss);

  return res;

} /* cli_mxp_mux_state_misc_loss_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_interrupt_get
* 
* Get database object callback
* Path: /mux-state-misc/interrupt
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_misc_interrupt_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *interrupt;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_misc_interrupt_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the interrupt var here, change EMPTY_STRING */
  int interrupt_int = pt_monitor_struct->txp_struct.txp_interrupt;
  interrupt = (const xmlChar *)general_status[interrupt_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      interrupt);

  return res;

} /* cli_mxp_mux_state_misc_interrupt_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_tx_laser_itu_band_get
* 
* Get database object callback
* Path: /mux-state-misc/tx_laser_itu_band
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_misc_tx_laser_itu_band_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *tx_laser_itu_band;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_misc_tx_laser_itu_band_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the tx_laser_itu_band var here, change EMPTY_STRING */
  char buf[30];
  sprintf(buf, "%c", pt_monitor_struct->txp_struct.txp_tx_laser_itu_channel.fields.band);
  tx_laser_itu_band = (const xmlChar *)buf;

  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      tx_laser_itu_band);

  return res;

} /* cli_mxp_mux_state_misc_tx_laser_itu_band_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_tx_laser_itu_channel_get
* 
* Get database object callback
* Path: /mux-state-misc/tx_laser_itu_channel
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_misc_tx_laser_itu_channel_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_misc_tx_laser_itu_channel_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the tx_laser_itu_channel var here, change EMPTY_STRING */
  const xmlChar *tx_laser_itu_channel;
  float tx_laser_itu_channel_float = pt_monitor_struct->txp_struct.txp_tx_laser_itu_channel.fields.channel;
  char buf[30];
  sprintf(buf, "%.2f", tx_laser_itu_channel_float);
  tx_laser_itu_channel = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      tx_laser_itu_channel);

  return res;

} /* cli_mxp_mux_state_misc_tx_laser_itu_channel_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_rx_laser_itu_band_get
* 
* Get database object callback
* Path: /mux-state-misc/rx_laser_itu_band
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_misc_rx_laser_itu_band_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *rx_laser_itu_band;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_misc_rx_laser_itu_band_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the rx_laser_itu_band var here, change EMPTY_STRING */
  char buf[30];
  sprintf(buf, "%c", pt_monitor_struct->txp_struct.txp_rx_laser_itu_channel.fields.band);
  rx_laser_itu_band = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      rx_laser_itu_band);

  return res;

} /* cli_mxp_mux_state_misc_rx_laser_itu_band_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_rx_laser_itu_channel_get
* 
* Get database object callback
* Path: /mux-state-misc/rx_laser_itu_channel
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_misc_rx_laser_itu_channel_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_misc_rx_laser_itu_channel_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the rx_laser_itu_channel var here, change EMPTY_STRING */
  const xmlChar *rx_laser_itu_channel;
  float rx_laser_itu_channel_float = pt_monitor_struct->txp_struct.txp_rx_laser_itu_channel.fields.channel;
  char buf[30];
  sprintf(buf, "%.2f", rx_laser_itu_channel_float);
  rx_laser_itu_channel = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      rx_laser_itu_channel);

  return res;

} /* cli_mxp_mux_state_misc_rx_laser_itu_channel_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_misc_mro
* 
* Make read-only top-level node
* Path: /mux-state-misc
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_misc_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state-misc */
  res = agt_add_top_container(mux_state_misc_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state-misc/temp_around */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_temp_around,
      cli_mxp_mux_state_misc_temp_around_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-misc/temp_case */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_temp_case,
      cli_mxp_mux_state_misc_temp_case_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-misc/temp_tx_laser */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_temp_tx_laser,
      cli_mxp_mux_state_misc_temp_tx_laser_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-misc/temp_rx_laser */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_temp_rx_laser,
      cli_mxp_mux_state_misc_temp_rx_laser_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-misc/loss */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_loss,
      cli_mxp_mux_state_misc_loss_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-misc/interrupt */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_interrupt,
      cli_mxp_mux_state_misc_interrupt_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-misc/tx_laser_itu_band */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_tx_laser_itu_band,
      cli_mxp_mux_state_misc_tx_laser_itu_band_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-misc/tx_laser_itu_channel */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_tx_laser_itu_channel,
      cli_mxp_mux_state_misc_tx_laser_itu_channel_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-misc/rx_laser_itu_band */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_rx_laser_itu_band,
      cli_mxp_mux_state_misc_rx_laser_itu_band_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-misc/rx_laser_itu_channel */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_rx_laser_itu_channel,
      cli_mxp_mux_state_misc_rx_laser_itu_channel_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_misc_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_EOL_ALM_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/EOL_ALM
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_EOL_ALM_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *EOL_ALM;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_EOL_ALM_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the EOL_ALM var here, change EMPTY_STRING */
  int EOL_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.eolalm;
  EOL_ALM = (const xmlChar *)alarms[EOL_ALM_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      EOL_ALM);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_EOL_ALM_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_MOD_TEMP_ALM_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/MOD_TEMP_ALM
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_MOD_TEMP_ALM_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *MOD_TEMP_ALM;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_MOD_TEMP_ALM_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the MOD_TEMP_ALM var here, change EMPTY_STRING */
  int MOD_TEMP_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modtempalm;
  MOD_TEMP_ALM = (const xmlChar *)alarms[MOD_TEMP_ALM_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      MOD_TEMP_ALM);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_MOD_TEMP_ALM_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_TX_OOA_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/TX_OOA
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_TX_OOA_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *TX_OOA;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_TX_OOA_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the TX_OOA var here, change EMPTY_STRING */
  int TX_OOA_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txooa;
  TX_OOA = (const xmlChar *)alarms[TX_OOA_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      TX_OOA);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_TX_OOA_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_TX_LOF_ALM_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/TX_LOF_ALM
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_TX_LOF_ALM_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *TX_LOF_ALM;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_TX_LOF_ALM_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the TX_LOF_ALM var here, change EMPTY_STRING */
  int TX_LOF_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlofalm;
  TX_LOF_ALM = (const xmlChar *)alarms[TX_LOF_ALM_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      TX_LOF_ALM);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_TX_LOF_ALM_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_TX_DSC_ERR_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/TX_DSC_ERR
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_TX_DSC_ERR_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *TX_DSC_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_TX_DSC_ERR_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the TX_DSC_ERR var here, change EMPTY_STRING */
  int TX_DSC_ERR_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txdscerr;
  TX_DSC_ERR = (const xmlChar *)alarms[TX_DSC_ERR_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      TX_DSC_ERR);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_TX_DSC_ERR_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_LS_WAV_ALM_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/LS_WAV_ALM
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_LS_WAV_ALM_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LS_WAV_ALM;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_LS_WAV_ALM_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LS_WAV_ALM var here, change EMPTY_STRING */
  int LS_WAV_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lswavalm;
  LS_WAV_ALM = (const xmlChar *)alarms[LS_WAV_ALM_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      LS_WAV_ALM);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_LS_WAV_ALM_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_TX_ALM_INT_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/TX_ALM_INT
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_TX_ALM_INT_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *TX_ALM_INT;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_TX_ALM_INT_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the TX_ALM_INT var here, change EMPTY_STRING */
  int TX_ALM_INT_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txalmint;
  TX_ALM_INT = (const xmlChar *)alarms[TX_ALM_INT_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      TX_ALM_INT);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_TX_ALM_INT_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_LS_BIAS_ALM_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/LS_BIAS_ALM
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_LS_BIAS_ALM_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LS_BIAS_ALM;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_LS_BIAS_ALM_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LS_BIAS_ALM var here, change EMPTY_STRING */
  int LS_BIAS_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lsbiasalm;
  LS_BIAS_ALM = (const xmlChar *)alarms[LS_BIAS_ALM_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      LS_BIAS_ALM);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_LS_BIAS_ALM_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_LS_TEMP_ALM_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/LS_TEMP_ALM
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_LS_TEMP_ALM_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LS_TEMP_ALM;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_LS_TEMP_ALM_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LS_TEMP_ALM var here, change EMPTY_STRING */
  int LS_TEMP_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lstempalm;
  LS_TEMP_ALM = (const xmlChar *)alarms[LS_TEMP_ALM_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      LS_TEMP_ALM);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_LS_TEMP_ALM_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_TX_LOCK_ERR_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/TX_LOCK_ERR
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_TX_LOCK_ERR_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *TX_LOCK_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_TX_LOCK_ERR_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the TX_LOCK_ERR var here, change EMPTY_STRING */
  int TX_LOCK_ERR_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlockerr;
  TX_LOCK_ERR = (const xmlChar *)alarms[TX_LOCK_ERR_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      TX_LOCK_ERR);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_TX_LOCK_ERR_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_LS_POW_ALM_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/LS_POW_ALM
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_LS_POW_ALM_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LS_POW_ALM;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_LS_POW_ALM_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LS_POW_ALM var here, change EMPTY_STRING */
  int LS_POW_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lspowalm;
  LS_POW_ALM = (const xmlChar *)alarms[LS_POW_ALM_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      LS_POW_ALM);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_LS_POW_ALM_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_MOD_BIAS_ALM_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/MOD_BIAS_ALM
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_MOD_BIAS_ALM_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *MOD_BIAS_ALM;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_MOD_BIAS_ALM_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the MOD_BIAS_ALM var here, change EMPTY_STRING */
  int MOD_BIAS_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modbiasalm;
  MOD_BIAS_ALM = (const xmlChar *)alarms[MOD_BIAS_ALM_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      MOD_BIAS_ALM);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_MOD_BIAS_ALM_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_LATCHED_TXFIFO_ERR_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/LATCHED_TXFIFO_ERR
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_LATCHED_TXFIFO_ERR_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LATCHED_TXFIFO_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_LATCHED_TXFIFO_ERR_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LATCHED_TXFIFO_ERR var here, change EMPTY_STRING */
  int LATCHED_TXFIFO_ERR_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.latchedtxfifoerr;
  LATCHED_TXFIFO_ERR = (const xmlChar *)alarms[LATCHED_TXFIFO_ERR_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      LATCHED_TXFIFO_ERR);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_LATCHED_TXFIFO_ERR_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_RXALM_INT_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/RXALM_INT
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_RXALM_INT_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *RXALM_INT;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_RXALM_INT_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the RXALM_INT var here, change EMPTY_STRING */
  int RXALM_INT_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxalmint;
  RXALM_INT = (const xmlChar *)alarms[RXALM_INT_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      RXALM_INT);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_RXALM_INT_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_RXPOW_ALM_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/RXPOW_ALM
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_RXPOW_ALM_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *RXPOW_ALM;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_RXPOW_ALM_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the RXPOW_ALM var here, change EMPTY_STRING */
  int RXPOW_ALM_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxpowalm;
  RXPOW_ALM = (const xmlChar *)alarms[RXPOW_ALM_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      RXPOW_ALM);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_RXPOW_ALM_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_RX_LOS_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/RX_LOS
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_RX_LOS_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *RX_LOS;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_RX_LOS_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the RX_LOS var here, change EMPTY_STRING */
  int RX_LOS_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlos;
  RX_LOS = (const xmlChar *)alarms[RX_LOS_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      RX_LOS);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_RX_LOS_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_RX_LOCK_ERR_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/RX_LOCK_ERR
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_RX_LOCK_ERR_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *RX_LOCK_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_RX_LOCK_ERR_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the RX_LOCK_ERR var here, change EMPTY_STRING */
  int RX_LOCK_ERR_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlockerr;
  RX_LOCK_ERR = (const xmlChar *)alarms[RX_LOCK_ERR_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      RX_LOCK_ERR);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_RX_LOCK_ERR_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_RXS_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/RXS
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_RXS_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *RXS;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_RXS_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the RXS var here, change EMPTY_STRING */
  int RXS_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxs;
  RXS = (const xmlChar *)alarms[RXS_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      RXS);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_RXS_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_PRBS_ERR_DET_get
* 
* Get database object callback
* Path: /mux-state-TX-RX-alarms/PRBS_ERR_DET
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_TX_RX_alarms_PRBS_ERR_DET_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *PRBS_ERR_DET;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_PRBS_ERR_DET_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the PRBS_ERR_DET var here, change EMPTY_STRING */
  int PRBS_ERR_DET_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.prbserrdet;
  PRBS_ERR_DET = (const xmlChar *)alarms[PRBS_ERR_DET_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      PRBS_ERR_DET);

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_PRBS_ERR_DET_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_TX_RX_alarms_mro
* 
* Make read-only top-level node
* Path: /mux-state-TX-RX-alarms
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_TX_RX_alarms_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state-TX-RX-alarms */
  res = agt_add_top_container(mux_state_TX_RX_alarms_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/EOL_ALM */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_EOL_ALM,
      cli_mxp_mux_state_TX_RX_alarms_EOL_ALM_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/MOD_TEMP_ALM */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_MOD_TEMP_ALM,
      cli_mxp_mux_state_TX_RX_alarms_MOD_TEMP_ALM_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/TX_OOA */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_TX_OOA,
      cli_mxp_mux_state_TX_RX_alarms_TX_OOA_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/TX_LOF_ALM */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_TX_LOF_ALM,
      cli_mxp_mux_state_TX_RX_alarms_TX_LOF_ALM_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/TX_DSC_ERR */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_TX_DSC_ERR,
      cli_mxp_mux_state_TX_RX_alarms_TX_DSC_ERR_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/LS_WAV_ALM */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_LS_WAV_ALM,
      cli_mxp_mux_state_TX_RX_alarms_LS_WAV_ALM_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/TX_ALM_INT */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_TX_ALM_INT,
      cli_mxp_mux_state_TX_RX_alarms_TX_ALM_INT_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/LS_BIAS_ALM */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_LS_BIAS_ALM,
      cli_mxp_mux_state_TX_RX_alarms_LS_BIAS_ALM_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/LS_TEMP_ALM */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_LS_TEMP_ALM,
      cli_mxp_mux_state_TX_RX_alarms_LS_TEMP_ALM_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/TX_LOCK_ERR */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_TX_LOCK_ERR,
      cli_mxp_mux_state_TX_RX_alarms_TX_LOCK_ERR_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/LS_POW_ALM */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_LS_POW_ALM,
      cli_mxp_mux_state_TX_RX_alarms_LS_POW_ALM_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/MOD_BIAS_ALM */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_MOD_BIAS_ALM,
      cli_mxp_mux_state_TX_RX_alarms_MOD_BIAS_ALM_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/LATCHED_TXFIFO_ERR */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_LATCHED_TXFIFO_ERR,
      cli_mxp_mux_state_TX_RX_alarms_LATCHED_TXFIFO_ERR_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/RXALM_INT */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_RXALM_INT,
      cli_mxp_mux_state_TX_RX_alarms_RXALM_INT_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/RXPOW_ALM */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_RXPOW_ALM,
      cli_mxp_mux_state_TX_RX_alarms_RXPOW_ALM_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/RX_LOS */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_RX_LOS,
      cli_mxp_mux_state_TX_RX_alarms_RX_LOS_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/RX_LOCK_ERR */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_RX_LOCK_ERR,
      cli_mxp_mux_state_TX_RX_alarms_RX_LOCK_ERR_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/RXS */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_RXS,
      cli_mxp_mux_state_TX_RX_alarms_RXS_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/PRBS_ERR_DET */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_PRBS_ERR_DET,
      cli_mxp_mux_state_TX_RX_alarms_PRBS_ERR_DET_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_state_power_PSUMMARY_get
* 
* Get database object callback
* Path: /mux-state-power/PSUMMARY
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_power_PSUMMARY_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *PSUMMARY;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_power_PSUMMARY_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the PSUMMARY var here, change EMPTY_STRING */
  int PSUMMARY_int = pt_monitor_struct->txp_struct.txp_power_alarm.fields.psummary;
  PSUMMARY = (const xmlChar *)alarms[PSUMMARY_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      PSUMMARY);

  return res;

} /* cli_mxp_mux_state_power_PSUMMARY_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_power_P5VANALOG_get
* 
* Get database object callback
* Path: /mux-state-power/P5VANALOG
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_power_P5VANALOG_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *P5VANALOG;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_power_P5VANALOG_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the P5VANALOG var here, change EMPTY_STRING */
  int P5VANALOG_int = pt_monitor_struct->txp_struct.txp_power_alarm.fields.p5vanalog;
  P5VANALOG = (const xmlChar *)alarms[P5VANALOG_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      P5VANALOG);

  return res;

} /* cli_mxp_mux_state_power_P5VANALOG_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_power_N5V2ANALOG_get
* 
* Get database object callback
* Path: /mux-state-power/N5V2ANALOG
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_power_N5V2ANALOG_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *N5V2ANALOG;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_power_N5V2ANALOG_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the N5V2ANALOG var here, change EMPTY_STRING */
  int N5V2ANALOG_int = pt_monitor_struct->txp_struct.txp_power_alarm.fields.n5v2analog;
  N5V2ANALOG = (const xmlChar *)alarms[N5V2ANALOG_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      N5V2ANALOG);

  return res;

} /* cli_mxp_mux_state_power_N5V2ANALOG_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_power_P3P3VANALOG_get
* 
* Get database object callback
* Path: /mux-state-power/P3P3VANALOG
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_power_P3P3VANALOG_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *P3P3VANALOG;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_power_P3P3VANALOG_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the P3P3VANALOG var here, change EMPTY_STRING */
  int P3P3VANALOG_int = pt_monitor_struct->txp_struct.txp_power_alarm.fields.p3p3vanalog;
  P3P3VANALOG = (const xmlChar *)alarms[P3P3VANALOG_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      P3P3VANALOG);

  return res;

} /* cli_mxp_mux_state_power_P3P3VANALOG_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_power_P3P3VDIGITAL_get
* 
* Get database object callback
* Path: /mux-state-power/P3P3VDIGITAL
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_power_P3P3VDIGITAL_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *P3P3VDIGITAL;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_power_P3P3VDIGITAL_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the P3P3VDIGITAL var here, change EMPTY_STRING */
  int P3P3VDIGITAL_int = pt_monitor_struct->txp_struct.txp_power_alarm.fields.p3p3vdigital;
  P3P3VDIGITAL = (const xmlChar *)alarms[P3P3VDIGITAL_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      P3P3VDIGITAL);

  return res;

} /* cli_mxp_mux_state_power_P3P3VDIGITAL_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_power_LVDIGITAL_get
* 
* Get database object callback
* Path: /mux-state-power/LVDIGITAL
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_power_LVDIGITAL_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LVDIGITAL;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_power_LVDIGITAL_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LVDIGITAL var here, change EMPTY_STRING */
  int LVDIGITAL_int = pt_monitor_struct->txp_struct.txp_power_alarm.fields.lvdigital;
  LVDIGITAL = (const xmlChar *)alarms[LVDIGITAL_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      LVDIGITAL);

  return res;

} /* cli_mxp_mux_state_power_LVDIGITAL_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_power_N5P2VDIGITAL_get
* 
* Get database object callback
* Path: /mux-state-power/N5P2VDIGITAL
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_power_N5P2VDIGITAL_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *N5P2VDIGITAL;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_power_N5P2VDIGITAL_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the N5P2VDIGITAL var here, change EMPTY_STRING */
  int N5P2VDIGITAL_int = pt_monitor_struct->txp_struct.txp_power_alarm.fields.n5p2vdigital;
  N5P2VDIGITAL = (const xmlChar *)alarms[N5P2VDIGITAL_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      N5P2VDIGITAL);

  return res;

} /* cli_mxp_mux_state_power_N5P2VDIGITAL_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_power_mro
* 
* Make read-only top-level node
* Path: /mux-state-power
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_power_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state-power */
  res = agt_add_top_container(mux_state_power_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state-power/PSUMMARY */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_PSUMMARY,
      cli_mxp_mux_state_power_PSUMMARY_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-power/P5VANALOG */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_P5VANALOG,
      cli_mxp_mux_state_power_P5VANALOG_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-power/N5V2ANALOG */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_N5V2ANALOG,
      cli_mxp_mux_state_power_N5V2ANALOG_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-power/P3P3VANALOG */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_P3P3VANALOG,
      cli_mxp_mux_state_power_P3P3VANALOG_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-power/P3P3VDIGITAL */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_P3P3VDIGITAL,
      cli_mxp_mux_state_power_P3P3VDIGITAL_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-power/LVDIGITAL */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_LVDIGITAL,
      cli_mxp_mux_state_power_LVDIGITAL_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-power/N5P2VDIGITAL */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_N5P2VDIGITAL,
      cli_mxp_mux_state_power_N5P2VDIGITAL_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_power_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_DSP_running_get
* 
* Get database object callback
* Path: /mux-state-dsp/DSP_running
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_DSP_running_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *DSP_running;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_DSP_running_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the DSP_running var here, change EMPTY_STRING */
  DSP_running = (const xmlChar *)general_status[!pt_monitor_struct->txp_struct.txp_dspstat.fields.GO];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      DSP_running);

  return res;

} /* cli_mxp_mux_state_dsp_DSP_running_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_CONVERGED_get
* 
* Get database object callback
* Path: /mux-state-dsp/CONVERGED
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_CONVERGED_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *CONVERGED;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_CONVERGED_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the CONVERGED var here, change EMPTY_STRING */
  CONVERGED = (const xmlChar *)general_status[!pt_monitor_struct->txp_struct.txp_dspstat.fields.CONVERGED];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      CONVERGED);

  return res;

} /* cli_mxp_mux_state_dsp_CONVERGED_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_MSE_below_threshold_get
* 
* Get database object callback
* Path: /mux-state-dsp/MSE_below_threshold
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_MSE_below_threshold_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *MSE_below_threshold;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_MSE_below_threshold_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the MSE_below_threshold var here, change EMPTY_STRING */
  MSE_below_threshold = (const xmlChar *)general_status[!pt_monitor_struct->txp_struct.txp_dspstat.fields.MSEBLTHR];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      MSE_below_threshold);

  return res;

} /* cli_mxp_mux_state_dsp_MSE_below_threshold_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_BCD_Enabled_get
* 
* Get database object callback
* Path: /mux-state-dsp/BCD_Enabled
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_BCD_Enabled_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *BCD_Enabled;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_BCD_Enabled_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the BCD_Enabled var here, change EMPTY_STRING */
  BCD_Enabled = (const xmlChar *)general_status[!pt_monitor_struct->txp_struct.txp_dspstat.fields.BCDEN];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      BCD_Enabled);

  return res;

} /* cli_mxp_mux_state_dsp_BCD_Enabled_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_Coarse_Carrier_Lock_get
* 
* Get database object callback
* Path: /mux-state-dsp/Coarse_Carrier_Lock
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_Coarse_Carrier_Lock_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Coarse_Carrier_Lock;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_Coarse_Carrier_Lock_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Coarse_Carrier_Lock var here, change EMPTY_STRING */
  Coarse_Carrier_Lock = (const xmlChar *)general_status[!pt_monitor_struct->txp_struct.txp_dspstat.fields.LOCK];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Coarse_Carrier_Lock);

  return res;

} /* cli_mxp_mux_state_dsp_Coarse_Carrier_Lock_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_Collision_get
* 
* Get database object callback
* Path: /mux-state-dsp/Collision
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_Collision_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Collision;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_Collision_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Collision var here, change EMPTY_STRING */
  Collision = (const xmlChar *)general_status[!pt_monitor_struct->txp_struct.txp_dspstat.fields.COLLISION];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Collision);

  return res;

} /* cli_mxp_mux_state_dsp_Collision_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_DSP_Initialized_get
* 
* Get database object callback
* Path: /mux-state-dsp/DSP_Initialized
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_DSP_Initialized_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *DSP_Initialized;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_DSP_Initialized_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the DSP_Initialized var here, change EMPTY_STRING */
  DSP_Initialized = (const xmlChar *)general_status[!pt_monitor_struct->txp_struct.txp_dspstat.fields.DSPINIT];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      DSP_Initialized);

  return res;

} /* cli_mxp_mux_state_dsp_DSP_Initialized_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_Presence_of_light_get
* 
* Get database object callback
* Path: /mux-state-dsp/Presence_of_light
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_Presence_of_light_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Presence_of_light;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_Presence_of_light_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Presence_of_light var here, change EMPTY_STRING */
  Presence_of_light = (const xmlChar *)general_status[!pt_monitor_struct->txp_struct.txp_dspstat.fields.POL];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Presence_of_light);

  return res;

} /* cli_mxp_mux_state_dsp_Presence_of_light_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_Local_Oscillator_running_get
* 
* Get database object callback
* Path: /mux-state-dsp/Local_Oscillator_running
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_Local_Oscillator_running_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Local_Oscillator_running;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_Local_Oscillator_running_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Local_Oscillator_running var here, change EMPTY_STRING */
  Local_Oscillator_running = (const xmlChar *)general_status[!pt_monitor_struct->txp_struct.txp_dspstat.fields.OSC];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Local_Oscillator_running);

  return res;

} /* cli_mxp_mux_state_dsp_Local_Oscillator_running_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_Transmit_Laser_running_get
* 
* Get database object callback
* Path: /mux-state-dsp/Transmit_Laser_running
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_Transmit_Laser_running_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Transmit_Laser_running;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_Transmit_Laser_running_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Transmit_Laser_running var here, change EMPTY_STRING */
  Transmit_Laser_running = (const xmlChar *)general_status[!pt_monitor_struct->txp_struct.txp_dspstat.fields.TXLASER];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Transmit_Laser_running);

  return res;

} /* cli_mxp_mux_state_dsp_Transmit_Laser_running_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_MSE_XI_get
* 
* Get database object callback
* Path: /mux-state-dsp/MSE_XI
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_MSE_XI_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *MSE_XI;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_MSE_XI_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the MSE_XI var here, change EMPTY_STRING */
  int MSE_XI_int = pt_monitor_struct->txp_struct.txp_mse.fields.mse_xi;
  char buf[30];
  sprintf(buf, "%d", MSE_XI_int);
  MSE_XI = (const xmlChar *)buf;

  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      MSE_XI);

  return res;

} /* cli_mxp_mux_state_dsp_MSE_XI_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_MSE_XQ_get
* 
* Get database object callback
* Path: /mux-state-dsp/MSE_XQ
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_MSE_XQ_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *MSE_XQ;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_MSE_XQ_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the MSE_XQ var here, change EMPTY_STRING */
  int MSE_XQ_int = pt_monitor_struct->txp_struct.txp_mse.fields.mse_xq;
  char buf[30];
  sprintf(buf, "%d", MSE_XQ_int);
  MSE_XQ = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      MSE_XQ);

  return res;

} /* cli_mxp_mux_state_dsp_MSE_XQ_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_MSE_YI_get
* 
* Get database object callback
* Path: /mux-state-dsp/MSE_YI
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_MSE_YI_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *MSE_YI;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_MSE_YI_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the MSE_YI var here, change EMPTY_STRING */
  int MSE_YI_int = pt_monitor_struct->txp_struct.txp_mse.fields.mse_yi;
  char buf[30];
  sprintf(buf, "%d", MSE_YI_int);
  MSE_YI = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      MSE_YI);

  return res;

} /* cli_mxp_mux_state_dsp_MSE_YI_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_MSE_YQ_get
* 
* Get database object callback
* Path: /mux-state-dsp/MSE_YQ
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_MSE_YQ_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *MSE_YQ;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_MSE_YQ_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the MSE_YQ var here, change EMPTY_STRING */
  int MSE_YQ_int = pt_monitor_struct->txp_struct.txp_mse.fields.mse_yq;
  char buf[30];
  sprintf(buf, "%d", MSE_YQ_int);
  MSE_YQ = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      MSE_YQ);

  return res;

} /* cli_mxp_mux_state_dsp_MSE_YQ_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_BER_Estimate_get
* 
* Get database object callback
* Path: /mux-state-dsp/BER_Estimate
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_BER_Estimate_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *BER_Estimate;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_BER_Estimate_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the BER_Estimate var here, change EMPTY_STRING */
  float BER_Estimate_int = pt_monitor_struct->txp_struct.txp_ber_estimate;
  char buf[30];
  sprintf(buf, "%.4e", BER_Estimate_int);
  BER_Estimate = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      BER_Estimate);

  return res;

} /* cli_mxp_mux_state_dsp_BER_Estimate_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_Min_Bulk_CD_Compensation_ps_nm_get
* 
* Get database object callback
* Path: /mux-state-dsp/Min_Bulk_CD_Compensation_ps_nm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_Min_Bulk_CD_Compensation_ps_nm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Min_Bulk_CD_Compensation_ps_nm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_Min_Bulk_CD_Compensation_ps_nm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Min_Bulk_CD_Compensation_ps_nm var here, change EMPTY_STRING */
  int Min_Bulk_CD_Compensation_ps_nm_int = pt_monitor_struct->txp_struct.txp_bulk_cd.fields.minimum_compensation;
  char buf[30];
  sprintf(buf, "%d", Min_Bulk_CD_Compensation_ps_nm_int);
  Min_Bulk_CD_Compensation_ps_nm = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Min_Bulk_CD_Compensation_ps_nm);

  return res;

} /* cli_mxp_mux_state_dsp_Min_Bulk_CD_Compensation_ps_nm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_Max_Bulk_CD_Compensation_ps_nm_get
* 
* Get database object callback
* Path: /mux-state-dsp/Max_Bulk_CD_Compensation_ps_nm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_Max_Bulk_CD_Compensation_ps_nm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Max_Bulk_CD_Compensation_ps_nm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_Max_Bulk_CD_Compensation_ps_nm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Max_Bulk_CD_Compensation_ps_nm var here, change EMPTY_STRING */
  int Max_Bulk_CD_Compensation_ps_nm_int = pt_monitor_struct->txp_struct.txp_bulk_cd.fields.maximum_compensation;
  char buf[30];
  sprintf(buf, "%d", Max_Bulk_CD_Compensation_ps_nm_int);
  Max_Bulk_CD_Compensation_ps_nm = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Max_Bulk_CD_Compensation_ps_nm);

  return res;

} /* cli_mxp_mux_state_dsp_Max_Bulk_CD_Compensation_ps_nm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_Step_Size_ps_nm_get
* 
* Get database object callback
* Path: /mux-state-dsp/Step_Size_ps_nm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_Step_Size_ps_nm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Step_Size_ps_nm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_Step_Size_ps_nm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Step_Size_ps_nm var here, change EMPTY_STRING */
  int Step_Size_ps_nm_int = pt_monitor_struct->txp_struct.txp_bulk_cd.fields.step_size;
  char buf[30];
  sprintf(buf, "%d", Step_Size_ps_nm_int);
  Step_Size_ps_nm = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Step_Size_ps_nm);

  return res;

} /* cli_mxp_mux_state_dsp_Step_Size_ps_nm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_CD_Compensation_ps_nm_get
* 
* Get database object callback
* Path: /mux-state-dsp/CD_Compensation_ps_nm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_dsp_CD_Compensation_ps_nm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *CD_Compensation_ps_nm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_dsp_CD_Compensation_ps_nm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the CD_Compensation_ps_nm var here, change EMPTY_STRING */
  float CD_Compensation_ps_nm_float = pt_monitor_struct->txp_struct.txp_chromatic_dispersion;
  char buf[30];
  sprintf(buf, "%.3f", CD_Compensation_ps_nm_float);
  CD_Compensation_ps_nm = (const xmlChar *)buf;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      CD_Compensation_ps_nm);

  return res;

} /* cli_mxp_mux_state_dsp_CD_Compensation_ps_nm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_dsp_mro
* 
* Make read-only top-level node
* Path: /mux-state-dsp
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_dsp_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state-dsp */
  res = agt_add_top_container(mux_state_dsp_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state-dsp/DSP_running */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_DSP_running,
      cli_mxp_mux_state_dsp_DSP_running_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/CONVERGED */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_CONVERGED,
      cli_mxp_mux_state_dsp_CONVERGED_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/MSE_below_threshold */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_MSE_below_threshold,
      cli_mxp_mux_state_dsp_MSE_below_threshold_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/BCD_Enabled */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_BCD_Enabled,
      cli_mxp_mux_state_dsp_BCD_Enabled_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/Coarse_Carrier_Lock */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Coarse_Carrier_Lock,
      cli_mxp_mux_state_dsp_Coarse_Carrier_Lock_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/Collision */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Collision,
      cli_mxp_mux_state_dsp_Collision_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/DSP_Initialized */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_DSP_Initialized,
      cli_mxp_mux_state_dsp_DSP_Initialized_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/Presence_of_light */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Presence_of_light,
      cli_mxp_mux_state_dsp_Presence_of_light_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/Local_Oscillator_running */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Local_Oscillator_running,
      cli_mxp_mux_state_dsp_Local_Oscillator_running_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/Transmit_Laser_running */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Transmit_Laser_running,
      cli_mxp_mux_state_dsp_Transmit_Laser_running_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/MSE_XI */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_MSE_XI,
      cli_mxp_mux_state_dsp_MSE_XI_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/MSE_XQ */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_MSE_XQ,
      cli_mxp_mux_state_dsp_MSE_XQ_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/MSE_YI */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_MSE_YI,
      cli_mxp_mux_state_dsp_MSE_YI_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/MSE_YQ */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_MSE_YQ,
      cli_mxp_mux_state_dsp_MSE_YQ_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/BER_Estimate */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_BER_Estimate,
      cli_mxp_mux_state_dsp_BER_Estimate_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/Min_Bulk_CD_Compensation_ps_nm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Min_Bulk_CD_Compensation_ps_nm,
      cli_mxp_mux_state_dsp_Min_Bulk_CD_Compensation_ps_nm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/Max_Bulk_CD_Compensation_ps_nm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Max_Bulk_CD_Compensation_ps_nm,
      cli_mxp_mux_state_dsp_Max_Bulk_CD_Compensation_ps_nm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/Step_Size_ps_nm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Step_Size_ps_nm,
      cli_mxp_mux_state_dsp_Step_Size_ps_nm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-dsp/CD_Compensation_ps_nm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_CD_Compensation_ps_nm,
      cli_mxp_mux_state_dsp_CD_Compensation_ps_nm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_dsp_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_state_edfa_POUT_get
* 
* Get database object callback
* Path: /mux-state-edfa/POUT
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_edfa_POUT_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *POUT;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_edfa_POUT_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the POUT var here, change EMPTY_STRING */
  POUT = (const xmlChar *)pt_monitor_struct->edfa_struct.edfa_output_power;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      POUT);

  return res;

} /* cli_mxp_mux_state_edfa_POUT_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_edfa_PIN_get
* 
* Get database object callback
* Path: /mux-state-edfa/PIN
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_edfa_PIN_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *PIN;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_edfa_PIN_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the PIN var here, change EMPTY_STRING */
  PIN = (const xmlChar *)pt_monitor_struct->edfa_struct.edfa_input_power;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      PIN);

  return res;

} /* cli_mxp_mux_state_edfa_PIN_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_edfa_Temp_get
* 
* Get database object callback
* Path: /mux-state-edfa/Temp
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_edfa_Temp_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Temp;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_edfa_Temp_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Temp var here, change EMPTY_STRING */
  Temp = (const xmlChar *)pt_monitor_struct->edfa_struct.edfa_temperature;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Temp);

  return res;

} /* cli_mxp_mux_state_edfa_Temp_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_edfa_LOS_get
* 
* Get database object callback
* Path: /mux-state-edfa/LOS
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_edfa_LOS_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LOS;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_edfa_LOS_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LOS var here, change EMPTY_STRING */
  LOS = (const xmlChar *)pt_monitor_struct->edfa_struct.edfa_los;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      LOS);

  return res;

} /* cli_mxp_mux_state_edfa_LOS_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_edfa_LOP_get
* 
* Get database object callback
* Path: /mux-state-edfa/LOP
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_edfa_LOP_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LOP;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_edfa_LOP_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LOP var here, change EMPTY_STRING */
  LOP = (const xmlChar *)pt_monitor_struct->edfa_struct.edfa_lop;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      LOP);

  return res;

} /* cli_mxp_mux_state_edfa_LOP_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_edfa_Amp_stat_get
* 
* Get database object callback
* Path: /mux-state-edfa/Amp_stat
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_edfa_Amp_stat_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Amp_stat;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_edfa_Amp_stat_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Amp_stat var here, change EMPTY_STRING */
  Amp_stat = (const xmlChar *)pt_monitor_struct->edfa_struct.edfa_amp_status;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Amp_stat);

  return res;

} /* cli_mxp_mux_state_edfa_Amp_stat_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_edfa_mro
* 
* Make read-only top-level node
* Path: /mux-state-edfa
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_edfa_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state-edfa */
  res = agt_add_top_container(mux_state_edfa_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state-edfa/POUT */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_POUT,
      cli_mxp_mux_state_edfa_POUT_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-edfa/PIN */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_PIN,
      cli_mxp_mux_state_edfa_PIN_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-edfa/Temp */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Temp,
      cli_mxp_mux_state_edfa_Temp_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-edfa/LOS */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_LOS,
      cli_mxp_mux_state_edfa_LOS_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-edfa/LOP */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_LOP,
      cli_mxp_mux_state_edfa_LOP_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-edfa/Amp_stat */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Amp_stat,
      cli_mxp_mux_state_edfa_Amp_stat_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_edfa_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_state_temp_hum_T41_Around_get
* 
* Get database object callback
* Path: /mux-state-temp-hum/T41_Around
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_temp_hum_T41_Around_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *T41_Around;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_temp_hum_T41_Around_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the T41_Around var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->general_struct.cs6041_temperature[0]);
  T41_Around = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      T41_Around);

  return res;

} /* cli_mxp_mux_state_temp_hum_T41_Around_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_temp_hum_T41_TS0_get
* 
* Get database object callback
* Path: /mux-state-temp-hum/T41_TS0
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_temp_hum_T41_TS0_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *T41_TS0;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_temp_hum_T41_TS0_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the T41_TS0 var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->general_struct.cs6041_temperature[1]);
  T41_TS0 = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      T41_TS0);

  return res;

} /* cli_mxp_mux_state_temp_hum_T41_TS0_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_temp_hum_T41_TS1_get
* 
* Get database object callback
* Path: /mux-state-temp-hum/T41_TS1
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_temp_hum_T41_TS1_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *T41_TS1;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_temp_hum_T41_TS1_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the T41_TS1 var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->general_struct.cs6041_temperature[2]);
  T41_TS1 = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      T41_TS1);

  return res;

} /* cli_mxp_mux_state_temp_hum_T41_TS1_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_temp_hum_T41_TS2_get
* 
* Get database object callback
* Path: /mux-state-temp-hum/T41_TS2
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_temp_hum_T41_TS2_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *T41_TS2;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_temp_hum_T41_TS2_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the T41_TS2 var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->general_struct.cs6041_temperature[3]);
  T41_TS2 = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      T41_TS2);

  return res;

} /* cli_mxp_mux_state_temp_hum_T41_TS2_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_temp_hum_FPGA_get
* 
* Get database object callback
* Path: /mux-state-temp-hum/FPGA
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_temp_hum_FPGA_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *FPGA;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_temp_hum_FPGA_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the FPGA var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->general_struct.fpga_temperature);
  FPGA = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      FPGA);

  return res;

} /* cli_mxp_mux_state_temp_hum_FPGA_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_temp_hum_BOARD_TEMP_get
* 
* Get database object callback
* Path: /mux-state-temp-hum/BOARD_TEMP
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_temp_hum_BOARD_TEMP_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *BOARD_TEMP;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_temp_hum_BOARD_TEMP_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the BOARD_TEMP var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%d", pt_monitor_struct->general_struct.board_temperature);
  BOARD_TEMP = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      BOARD_TEMP);

  return res;

} /* cli_mxp_mux_state_temp_hum_BOARD_TEMP_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_temp_hum_BOARD_HUM_get
* 
* Get database object callback
* Path: /mux-state-temp-hum/BOARD_HUM
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_temp_hum_BOARD_HUM_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *BOARD_HUM;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_temp_hum_BOARD_HUM_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the BOARD_HUM var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%d", pt_monitor_struct->general_struct.board_humidity);
  BOARD_HUM = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      BOARD_HUM);

  return res;

} /* cli_mxp_mux_state_temp_hum_BOARD_HUM_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_temp_hum_mro
* 
* Make read-only top-level node
* Path: /mux-state-temp-hum
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_temp_hum_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state-temp-hum */
  res = agt_add_top_container(mux_state_temp_hum_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state-temp-hum/T41_Around */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_T41_Around,
      cli_mxp_mux_state_temp_hum_T41_Around_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-temp-hum/T41_TS0 */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_T41_TS0,
      cli_mxp_mux_state_temp_hum_T41_TS0_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-temp-hum/T41_TS1 */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_T41_TS1,
      cli_mxp_mux_state_temp_hum_T41_TS1_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-temp-hum/T41_TS2 */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_T41_TS2,
      cli_mxp_mux_state_temp_hum_T41_TS2_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-temp-hum/FPGA */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_FPGA,
      cli_mxp_mux_state_temp_hum_FPGA_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-temp-hum/BOARD_TEMP */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_BOARD_TEMP,
      cli_mxp_mux_state_temp_hum_BOARD_TEMP_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-temp-hum/BOARD_HUM */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_BOARD_HUM,
      cli_mxp_mux_state_temp_hum_BOARD_HUM_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_temp_hum_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Presence_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Presence
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Presence_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Presence;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Presence_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Presence var here, change EMPTY_STRING */
  int Presence_int = pt_monitor_struct->xfp_struct.xfp_presence[0];
  Presence = (const xmlChar *)general_status[Presence_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Presence);

  return res;

} /* cli_mxp_mux_state_XFP1_Presence_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Loss_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Loss
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Loss_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Loss;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Loss_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Loss var here, change EMPTY_STRING */
  int Loss_int = pt_monitor_struct->xfp_struct.xfp_rx_loss[0];
  Loss = (const xmlChar *)general_status[!Loss_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Loss);

  return res;

} /* cli_mxp_mux_state_XFP1_Loss_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Ready_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Ready
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Ready_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Ready;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Ready_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Ready var here, change EMPTY_STRING */
  int Ready_int = pt_monitor_struct->xfp_struct.xfp_ready[0];
  Ready = (const xmlChar *)general_status[Ready_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Ready);

  return res;

} /* cli_mxp_mux_state_XFP1_Ready_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Interrupt_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Interrupt
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Interrupt_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Interrupt;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Interrupt_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Interrupt var here, change EMPTY_STRING */
  int Interrupt_int = pt_monitor_struct->xfp_struct.xfp_interrupt[0];
  Interrupt = (const xmlChar *)general_status[Interrupt_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Interrupt);

  return res;

} /* cli_mxp_mux_state_XFP1_Interrupt_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Tx_Power_dBm_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Tx_Power_dBm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Tx_Power_dBm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Tx_Power_dBm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Tx_Power_dBm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Tx_Power_dBm var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_tx_power[0]);
  Tx_Power_dBm = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Tx_Power_dBm);

  return res;

} /* cli_mxp_mux_state_XFP1_Tx_Power_dBm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Rx_Power_dBm_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Rx_Power_dBm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Rx_Power_dBm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Rx_Power_dBm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Rx_Power_dBm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Rx_Power_dBm var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_rx_power[0]);
  Rx_Power_dBm = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Rx_Power_dBm);

  return res;

} /* cli_mxp_mux_state_XFP1_Rx_Power_dBm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Temp_c_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Temp_c
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Temp_c_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Temp_c;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Temp_c_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Temp_c var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_temperature[0]);
  Temp_c = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Temp_c);

  return res;

} /* cli_mxp_mux_state_XFP1_Temp_c_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Low_Tx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Low_Tx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Low_Tx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Low_Tx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Low_Tx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Low_Tx_Power_Alarm var here, change EMPTY_STRING */
  int Low_Tx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][0];
  Low_Tx_Power_Alarm = (const xmlChar *)alarms[!Low_Tx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Low_Tx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP1_Low_Tx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_High_Tx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP1/High_Tx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_High_Tx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *High_Tx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_High_Tx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the High_Tx_Power_Alarm var here, change EMPTY_STRING */
  int High_Tx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][1];
  High_Tx_Power_Alarm = (const xmlChar *)alarms[!High_Tx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      High_Tx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP1_High_Tx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Low_Rx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Low_Rx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Low_Rx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Low_Rx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Low_Rx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Low_Rx_Power_Alarm var here, change EMPTY_STRING */
  int Low_Rx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][2];
  Low_Rx_Power_Alarm = (const xmlChar *)alarms[!Low_Rx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Low_Rx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP1_Low_Rx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_High_Rx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP1/High_Rx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_High_Rx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *High_Rx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_High_Rx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the High_Rx_Power_Alarm var here, change EMPTY_STRING */
  int High_Rx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][3];
  High_Rx_Power_Alarm = (const xmlChar *)alarms[!High_Rx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      High_Rx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP1_High_Rx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Rx_CDR_Loss_of_Lock_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Rx_CDR_Loss_of_Lock
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Rx_CDR_Loss_of_Lock_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Rx_CDR_Loss_of_Lock;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Rx_CDR_Loss_of_Lock_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Rx_CDR_Loss_of_Lock var here, change EMPTY_STRING */
  int Rx_CDR_Loss_of_Lock_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][4];
  Rx_CDR_Loss_of_Lock = (const xmlChar *)alarms[!Rx_CDR_Loss_of_Lock_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Rx_CDR_Loss_of_Lock);

  return res;

} /* cli_mxp_mux_state_XFP1_Rx_CDR_Loss_of_Lock_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Tx_CDR_Loss_of_Lock_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Tx_CDR_Loss_of_Lock
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Tx_CDR_Loss_of_Lock_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Tx_CDR_Loss_of_Lock;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Tx_CDR_Loss_of_Lock_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Tx_CDR_Loss_of_Lock var here, change EMPTY_STRING */
  int Tx_CDR_Loss_of_Lock_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][5];
  Tx_CDR_Loss_of_Lock = (const xmlChar *)alarms[!Tx_CDR_Loss_of_Lock_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Tx_CDR_Loss_of_Lock);

  return res;

} /* cli_mxp_mux_state_XFP1_Tx_CDR_Loss_of_Lock_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_Laser_Fault_get
* 
* Get database object callback
* Path: /mux-state-XFP1/Laser_Fault
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP1_Laser_Fault_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Laser_Fault;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP1_Laser_Fault_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Laser_Fault var here, change EMPTY_STRING */
  int Laser_Fault_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[0][6];
  Laser_Fault = (const xmlChar *)alarms[!Laser_Fault_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Laser_Fault);

  return res;

} /* cli_mxp_mux_state_XFP1_Laser_Fault_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP1_mro
* 
* Make read-only top-level node
* Path: /mux-state-XFP1
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_XFP1_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state-XFP1 */
  res = agt_add_top_container(mux_state_XFP1_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state-XFP1/Presence */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Presence,
      cli_mxp_mux_state_XFP1_Presence_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Loss */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Loss,
      cli_mxp_mux_state_XFP1_Loss_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Ready */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Ready,
      cli_mxp_mux_state_XFP1_Ready_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Interrupt */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Interrupt,
      cli_mxp_mux_state_XFP1_Interrupt_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Tx_Power_dBm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Tx_Power_dBm,
      cli_mxp_mux_state_XFP1_Tx_Power_dBm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Rx_Power_dBm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Rx_Power_dBm,
      cli_mxp_mux_state_XFP1_Rx_Power_dBm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Temp_c */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Temp_c,
      cli_mxp_mux_state_XFP1_Temp_c_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Low_Tx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Low_Tx_Power_Alarm,
      cli_mxp_mux_state_XFP1_Low_Tx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/High_Tx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_High_Tx_Power_Alarm,
      cli_mxp_mux_state_XFP1_High_Tx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Low_Rx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Low_Rx_Power_Alarm,
      cli_mxp_mux_state_XFP1_Low_Rx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/High_Rx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_High_Rx_Power_Alarm,
      cli_mxp_mux_state_XFP1_High_Rx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Rx_CDR_Loss_of_Lock */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Rx_CDR_Loss_of_Lock,
      cli_mxp_mux_state_XFP1_Rx_CDR_Loss_of_Lock_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Tx_CDR_Loss_of_Lock */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Tx_CDR_Loss_of_Lock,
      cli_mxp_mux_state_XFP1_Tx_CDR_Loss_of_Lock_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP1/Laser_Fault */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Laser_Fault,
      cli_mxp_mux_state_XFP1_Laser_Fault_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_XFP1_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Presence_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Presence
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Presence_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Presence;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Presence_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Presence var here, change EMPTY_STRING */
  int Presence_int = pt_monitor_struct->xfp_struct.xfp_presence[1];
  Presence = (const xmlChar *)general_status[Presence_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Presence);

  return res;

} /* cli_mxp_mux_state_XFP2_Presence_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Loss_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Loss
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Loss_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Loss;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Loss_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Loss var here, change EMPTY_STRING */
  int Loss_int = pt_monitor_struct->xfp_struct.xfp_rx_loss[1];
  Loss = (const xmlChar *)general_status[!Loss_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Loss);

  return res;

} /* cli_mxp_mux_state_XFP2_Loss_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Ready_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Ready
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Ready_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Ready;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Ready_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Ready var here, change EMPTY_STRING */
  int Ready_int = pt_monitor_struct->xfp_struct.xfp_ready[1];
  Ready = (const xmlChar *)general_status[Ready_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Ready);

  return res;

} /* cli_mxp_mux_state_XFP2_Ready_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Interrupt_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Interrupt
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Interrupt_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Interrupt;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Interrupt_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Interrupt var here, change EMPTY_STRING */
  int Interrupt_int = pt_monitor_struct->xfp_struct.xfp_interrupt[1];
  Interrupt = (const xmlChar *)general_status[Interrupt_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Interrupt);

  return res;

} /* cli_mxp_mux_state_XFP2_Interrupt_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Tx_Power_dBm_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Tx_Power_dBm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Tx_Power_dBm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Tx_Power_dBm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Tx_Power_dBm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Tx_Power_dBm var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_tx_power[1]);
  Tx_Power_dBm = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Tx_Power_dBm);

  return res;

} /* cli_mxp_mux_state_XFP2_Tx_Power_dBm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Rx_Power_dBm_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Rx_Power_dBm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Rx_Power_dBm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Rx_Power_dBm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Rx_Power_dBm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Rx_Power_dBm var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_rx_power[1]);
  Rx_Power_dBm = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Rx_Power_dBm);

  return res;

} /* cli_mxp_mux_state_XFP2_Rx_Power_dBm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Temp_c_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Temp_c
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Temp_c_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Temp_c;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Temp_c_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Temp_c var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_temperature[1]);
  Temp_c = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Temp_c);

  return res;

} /* cli_mxp_mux_state_XFP2_Temp_c_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Low_Tx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Low_Tx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Low_Tx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Low_Tx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Low_Tx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Low_Tx_Power_Alarm var here, change EMPTY_STRING */
  int Low_Tx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][0];
  Low_Tx_Power_Alarm = (const xmlChar *)alarms[!Low_Tx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Low_Tx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP2_Low_Tx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_High_Tx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP2/High_Tx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_High_Tx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *High_Tx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_High_Tx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the High_Tx_Power_Alarm var here, change EMPTY_STRING */
  int High_Tx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][1];
  High_Tx_Power_Alarm = (const xmlChar *)alarms[!High_Tx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      High_Tx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP2_High_Tx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Low_Rx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Low_Rx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Low_Rx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Low_Rx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Low_Rx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Low_Rx_Power_Alarm var here, change EMPTY_STRING */
  int Low_Rx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][2];
  Low_Rx_Power_Alarm = (const xmlChar *)alarms[!Low_Rx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Low_Rx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP2_Low_Rx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_High_Rx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP2/High_Rx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_High_Rx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *High_Rx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_High_Rx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the High_Rx_Power_Alarm var here, change EMPTY_STRING */
  int High_Rx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][3];
  High_Rx_Power_Alarm = (const xmlChar *)alarms[!High_Rx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      High_Rx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP2_High_Rx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Rx_CDR_Loss_of_Lock_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Rx_CDR_Loss_of_Lock
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Rx_CDR_Loss_of_Lock_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Rx_CDR_Loss_of_Lock;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Rx_CDR_Loss_of_Lock_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Rx_CDR_Loss_of_Lock var here, change EMPTY_STRING */
  int Rx_CDR_Loss_of_Lock_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][4];
  Rx_CDR_Loss_of_Lock = (const xmlChar *)alarms[!Rx_CDR_Loss_of_Lock_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Rx_CDR_Loss_of_Lock);

  return res;

} /* cli_mxp_mux_state_XFP2_Rx_CDR_Loss_of_Lock_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Tx_CDR_Loss_of_Lock_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Tx_CDR_Loss_of_Lock
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Tx_CDR_Loss_of_Lock_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Tx_CDR_Loss_of_Lock;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Tx_CDR_Loss_of_Lock_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Tx_CDR_Loss_of_Lock var here, change EMPTY_STRING */
  int Tx_CDR_Loss_of_Lock_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][5];
  Tx_CDR_Loss_of_Lock = (const xmlChar *)alarms[!Tx_CDR_Loss_of_Lock_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Tx_CDR_Loss_of_Lock);

  return res;

} /* cli_mxp_mux_state_XFP2_Tx_CDR_Loss_of_Lock_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_Laser_Fault_get
* 
* Get database object callback
* Path: /mux-state-XFP2/Laser_Fault
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP2_Laser_Fault_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Laser_Fault;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP2_Laser_Fault_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Laser_Fault var here, change EMPTY_STRING */
  int Laser_Fault_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[1][6];
  Laser_Fault = (const xmlChar *)alarms[!Laser_Fault_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Laser_Fault);

  return res;

} /* cli_mxp_mux_state_XFP2_Laser_Fault_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP2_mro
* 
* Make read-only top-level node
* Path: /mux-state-XFP2
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_XFP2_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state-XFP2 */
  res = agt_add_top_container(mux_state_XFP2_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state-XFP2/Presence */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Presence,
      cli_mxp_mux_state_XFP2_Presence_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Loss */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Loss,
      cli_mxp_mux_state_XFP2_Loss_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Ready */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Ready,
      cli_mxp_mux_state_XFP2_Ready_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Interrupt */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Interrupt,
      cli_mxp_mux_state_XFP2_Interrupt_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Tx_Power_dBm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Tx_Power_dBm,
      cli_mxp_mux_state_XFP2_Tx_Power_dBm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Rx_Power_dBm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Rx_Power_dBm,
      cli_mxp_mux_state_XFP2_Rx_Power_dBm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Temp_c */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Temp_c,
      cli_mxp_mux_state_XFP2_Temp_c_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Low_Tx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Low_Tx_Power_Alarm,
      cli_mxp_mux_state_XFP2_Low_Tx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/High_Tx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_High_Tx_Power_Alarm,
      cli_mxp_mux_state_XFP2_High_Tx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Low_Rx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Low_Rx_Power_Alarm,
      cli_mxp_mux_state_XFP2_Low_Rx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/High_Rx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_High_Rx_Power_Alarm,
      cli_mxp_mux_state_XFP2_High_Rx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Rx_CDR_Loss_of_Lock */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Rx_CDR_Loss_of_Lock,
      cli_mxp_mux_state_XFP2_Rx_CDR_Loss_of_Lock_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Tx_CDR_Loss_of_Lock */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Tx_CDR_Loss_of_Lock,
      cli_mxp_mux_state_XFP2_Tx_CDR_Loss_of_Lock_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP2/Laser_Fault */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Laser_Fault,
      cli_mxp_mux_state_XFP2_Laser_Fault_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_XFP2_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Presence_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Presence
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Presence_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Presence;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Presence_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Presence var here, change EMPTY_STRING */
  int Presence_int = pt_monitor_struct->xfp_struct.xfp_presence[2];
  Presence = (const xmlChar *)general_status[Presence_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Presence);

  return res;

} /* cli_mxp_mux_state_XFP3_Presence_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Loss_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Loss
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Loss_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Loss;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Loss_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Loss var here, change EMPTY_STRING */
  int Loss_int = pt_monitor_struct->xfp_struct.xfp_rx_loss[2];
  Loss = (const xmlChar *)general_status[!Loss_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Loss);

  return res;

} /* cli_mxp_mux_state_XFP3_Loss_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Ready_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Ready
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Ready_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Ready;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Ready_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Ready var here, change EMPTY_STRING */
  int Ready_int = pt_monitor_struct->xfp_struct.xfp_ready[2];
  Ready = (const xmlChar *)general_status[Ready_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Ready);

  return res;

} /* cli_mxp_mux_state_XFP3_Ready_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Interrupt_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Interrupt
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Interrupt_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Interrupt;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Interrupt_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Interrupt var here, change EMPTY_STRING */
  int Interrupt_int = pt_monitor_struct->xfp_struct.xfp_interrupt[2];
  Interrupt = (const xmlChar *)general_status[Interrupt_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Interrupt);

  return res;

} /* cli_mxp_mux_state_XFP3_Interrupt_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Tx_Power_dBm_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Tx_Power_dBm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Tx_Power_dBm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Tx_Power_dBm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Tx_Power_dBm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Tx_Power_dBm var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_tx_power[2]);
  Tx_Power_dBm = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Tx_Power_dBm);

  return res;

} /* cli_mxp_mux_state_XFP3_Tx_Power_dBm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Rx_Power_dBm_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Rx_Power_dBm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Rx_Power_dBm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Rx_Power_dBm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Rx_Power_dBm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Rx_Power_dBm var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_rx_power[2]);
  Rx_Power_dBm = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Rx_Power_dBm);

  return res;

} /* cli_mxp_mux_state_XFP3_Rx_Power_dBm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Temp_c_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Temp_c
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Temp_c_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Temp_c;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Temp_c_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Temp_c var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_temperature[2]);
  Temp_c = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Temp_c);

  return res;

} /* cli_mxp_mux_state_XFP3_Temp_c_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Low_Tx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Low_Tx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Low_Tx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Low_Tx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Low_Tx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Low_Tx_Power_Alarm var here, change EMPTY_STRING */
  int Low_Tx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][0];
  Low_Tx_Power_Alarm = (const xmlChar *)alarms[!Low_Tx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Low_Tx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP3_Low_Tx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_High_Tx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP3/High_Tx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_High_Tx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *High_Tx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_High_Tx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the High_Tx_Power_Alarm var here, change EMPTY_STRING */
  int High_Tx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][1];
  High_Tx_Power_Alarm = (const xmlChar *)alarms[!High_Tx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      High_Tx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP3_High_Tx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Low_Rx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Low_Rx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Low_Rx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Low_Rx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Low_Rx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Low_Rx_Power_Alarm var here, change EMPTY_STRING */
  int Low_Rx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][2];
  Low_Rx_Power_Alarm = (const xmlChar *)alarms[!Low_Rx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Low_Rx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP3_Low_Rx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_High_Rx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP3/High_Rx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_High_Rx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *High_Rx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_High_Rx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the High_Rx_Power_Alarm var here, change EMPTY_STRING */
  int High_Rx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][3];
  High_Rx_Power_Alarm = (const xmlChar *)alarms[!High_Rx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      High_Rx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP3_High_Rx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Rx_CDR_Loss_of_Lock_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Rx_CDR_Loss_of_Lock
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Rx_CDR_Loss_of_Lock_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Rx_CDR_Loss_of_Lock;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Rx_CDR_Loss_of_Lock_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Rx_CDR_Loss_of_Lock var here, change EMPTY_STRING */
  int Rx_CDR_Loss_of_Lock_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][4];
  Rx_CDR_Loss_of_Lock = (const xmlChar *)alarms[!Rx_CDR_Loss_of_Lock_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Rx_CDR_Loss_of_Lock);

  return res;

} /* cli_mxp_mux_state_XFP3_Rx_CDR_Loss_of_Lock_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Tx_CDR_Loss_of_Lock_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Tx_CDR_Loss_of_Lock
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Tx_CDR_Loss_of_Lock_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Tx_CDR_Loss_of_Lock;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Tx_CDR_Loss_of_Lock_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Tx_CDR_Loss_of_Lock var here, change EMPTY_STRING */
  int Tx_CDR_Loss_of_Lock_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][5];
  Tx_CDR_Loss_of_Lock = (const xmlChar *)alarms[!Tx_CDR_Loss_of_Lock_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Tx_CDR_Loss_of_Lock);

  return res;

} /* cli_mxp_mux_state_XFP3_Tx_CDR_Loss_of_Lock_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_Laser_Fault_get
* 
* Get database object callback
* Path: /mux-state-XFP3/Laser_Fault
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP3_Laser_Fault_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Laser_Fault;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP3_Laser_Fault_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Laser_Fault var here, change EMPTY_STRING */
  int Laser_Fault_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[2][6];
  Laser_Fault = (const xmlChar *)alarms[!Laser_Fault_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Laser_Fault);

  return res;

} /* cli_mxp_mux_state_XFP3_Laser_Fault_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP3_mro
* 
* Make read-only top-level node
* Path: /mux-state-XFP3
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_XFP3_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state-XFP3 */
  res = agt_add_top_container(mux_state_XFP3_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state-XFP3/Presence */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Presence,
      cli_mxp_mux_state_XFP3_Presence_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Loss */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Loss,
      cli_mxp_mux_state_XFP3_Loss_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Ready */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Ready,
      cli_mxp_mux_state_XFP3_Ready_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Interrupt */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Interrupt,
      cli_mxp_mux_state_XFP3_Interrupt_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Tx_Power_dBm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Tx_Power_dBm,
      cli_mxp_mux_state_XFP3_Tx_Power_dBm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Rx_Power_dBm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Rx_Power_dBm,
      cli_mxp_mux_state_XFP3_Rx_Power_dBm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Temp_c */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Temp_c,
      cli_mxp_mux_state_XFP3_Temp_c_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Low_Tx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Low_Tx_Power_Alarm,
      cli_mxp_mux_state_XFP3_Low_Tx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/High_Tx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_High_Tx_Power_Alarm,
      cli_mxp_mux_state_XFP3_High_Tx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Low_Rx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Low_Rx_Power_Alarm,
      cli_mxp_mux_state_XFP3_Low_Rx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/High_Rx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_High_Rx_Power_Alarm,
      cli_mxp_mux_state_XFP3_High_Rx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Rx_CDR_Loss_of_Lock */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Rx_CDR_Loss_of_Lock,
      cli_mxp_mux_state_XFP3_Rx_CDR_Loss_of_Lock_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Tx_CDR_Loss_of_Lock */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Tx_CDR_Loss_of_Lock,
      cli_mxp_mux_state_XFP3_Tx_CDR_Loss_of_Lock_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP3/Laser_Fault */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Laser_Fault,
      cli_mxp_mux_state_XFP3_Laser_Fault_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_XFP3_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Presence_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Presence
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Presence_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Presence;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Presence_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Presence var here, change EMPTY_STRING */
  int Presence_int = pt_monitor_struct->xfp_struct.xfp_presence[3];
  Presence = (const xmlChar *)general_status[Presence_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Presence);

  return res;

} /* cli_mxp_mux_state_XFP4_Presence_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Loss_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Loss
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Loss_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Loss;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Loss_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Loss var here, change EMPTY_STRING */
  int Loss_int = pt_monitor_struct->xfp_struct.xfp_rx_loss[3];
  Loss = (const xmlChar *)general_status[!Loss_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Loss);

  return res;

} /* cli_mxp_mux_state_XFP4_Loss_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Ready_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Ready
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Ready_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Ready;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Ready_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Ready var here, change EMPTY_STRING */
  int Ready_int = pt_monitor_struct->xfp_struct.xfp_ready[3];
  Ready = (const xmlChar *)general_status[Ready_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Ready);

  return res;

} /* cli_mxp_mux_state_XFP4_Ready_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Interrupt_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Interrupt
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Interrupt_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Interrupt;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Interrupt_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Interrupt var here, change EMPTY_STRING */
  int Interrupt_int = pt_monitor_struct->xfp_struct.xfp_interrupt[3];
  Interrupt = (const xmlChar *)general_status[Interrupt_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Interrupt);

  return res;

} /* cli_mxp_mux_state_XFP4_Interrupt_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Tx_Power_dBm_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Tx_Power_dBm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Tx_Power_dBm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Tx_Power_dBm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Tx_Power_dBm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Tx_Power_dBm var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_tx_power[3]);
  Tx_Power_dBm = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Tx_Power_dBm);

  return res;

} /* cli_mxp_mux_state_XFP4_Tx_Power_dBm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Rx_Power_dBm_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Rx_Power_dBm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Rx_Power_dBm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Rx_Power_dBm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Rx_Power_dBm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Rx_Power_dBm var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_rx_power[3]);
  Rx_Power_dBm = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Rx_Power_dBm);

  return res;

} /* cli_mxp_mux_state_XFP4_Rx_Power_dBm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Temp_c_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Temp_c
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Temp_c_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Temp_c;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Temp_c_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Temp_c var here, change EMPTY_STRING */
  char buff[16];
  sprintf(buff, "%.2f", pt_monitor_struct->xfp_struct.xfp_temperature[3]);
  Temp_c = (const xmlChar *)buff;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Temp_c);

  return res;

} /* cli_mxp_mux_state_XFP4_Temp_c_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Low_Tx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Low_Tx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Low_Tx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Low_Tx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Low_Tx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Low_Tx_Power_Alarm var here, change EMPTY_STRING */
  int Low_Tx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][0];
  Low_Tx_Power_Alarm = (const xmlChar *)alarms[!Low_Tx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Low_Tx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP4_Low_Tx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_High_Tx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP4/High_Tx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_High_Tx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *High_Tx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_High_Tx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the High_Tx_Power_Alarm var here, change EMPTY_STRING */
  int High_Tx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][1];
  High_Tx_Power_Alarm = (const xmlChar *)alarms[!High_Tx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      High_Tx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP4_High_Tx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Low_Rx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Low_Rx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Low_Rx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Low_Rx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Low_Rx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Low_Rx_Power_Alarm var here, change EMPTY_STRING */
  int Low_Rx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][2];
  Low_Rx_Power_Alarm = (const xmlChar *)alarms[!Low_Rx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Low_Rx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP4_Low_Rx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_High_Rx_Power_Alarm_get
* 
* Get database object callback
* Path: /mux-state-XFP4/High_Rx_Power_Alarm
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_High_Rx_Power_Alarm_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *High_Rx_Power_Alarm;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_High_Rx_Power_Alarm_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the High_Rx_Power_Alarm var here, change EMPTY_STRING */
  int High_Rx_Power_Alarm_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][3];
  High_Rx_Power_Alarm = (const xmlChar *)alarms[!High_Rx_Power_Alarm_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      High_Rx_Power_Alarm);

  return res;

} /* cli_mxp_mux_state_XFP4_High_Rx_Power_Alarm_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Rx_CDR_Loss_of_Lock_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Rx_CDR_Loss_of_Lock
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Rx_CDR_Loss_of_Lock_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Rx_CDR_Loss_of_Lock;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Rx_CDR_Loss_of_Lock_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Rx_CDR_Loss_of_Lock var here, change EMPTY_STRING */
  int Rx_CDR_Loss_of_Lock_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][4];
  Rx_CDR_Loss_of_Lock = (const xmlChar *)alarms[!Rx_CDR_Loss_of_Lock_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Rx_CDR_Loss_of_Lock);

  return res;

} /* cli_mxp_mux_state_XFP4_Rx_CDR_Loss_of_Lock_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Tx_CDR_Loss_of_Lock_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Tx_CDR_Loss_of_Lock
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Tx_CDR_Loss_of_Lock_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Tx_CDR_Loss_of_Lock;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Tx_CDR_Loss_of_Lock_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Tx_CDR_Loss_of_Lock var here, change EMPTY_STRING */
  int Tx_CDR_Loss_of_Lock_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][5];
  Tx_CDR_Loss_of_Lock = (const xmlChar *)alarms[!Tx_CDR_Loss_of_Lock_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Tx_CDR_Loss_of_Lock);

  return res;

} /* cli_mxp_mux_state_XFP4_Tx_CDR_Loss_of_Lock_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_Laser_Fault_get
* 
* Get database object callback
* Path: /mux-state-XFP4/Laser_Fault
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_state_XFP4_Laser_Fault_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *Laser_Fault;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_state_XFP4_Laser_Fault_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the Laser_Fault var here, change EMPTY_STRING */
  int Laser_Fault_int = pt_monitor_struct->xfp_struct.xfp_interruption_flags[3][6];
  Laser_Fault = (const xmlChar *)alarms[!Laser_Fault_int];
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      Laser_Fault);

  return res;

} /* cli_mxp_mux_state_XFP4_Laser_Fault_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_XFP4_mro
* 
* Make read-only top-level node
* Path: /mux-state-XFP4
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_XFP4_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state-XFP4 */
  res = agt_add_top_container(mux_state_XFP4_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state-XFP4/Presence */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Presence,
      cli_mxp_mux_state_XFP4_Presence_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Loss */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Loss,
      cli_mxp_mux_state_XFP4_Loss_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Ready */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Ready,
      cli_mxp_mux_state_XFP4_Ready_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Interrupt */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Interrupt,
      cli_mxp_mux_state_XFP4_Interrupt_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Tx_Power_dBm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Tx_Power_dBm,
      cli_mxp_mux_state_XFP4_Tx_Power_dBm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Rx_Power_dBm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Rx_Power_dBm,
      cli_mxp_mux_state_XFP4_Rx_Power_dBm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Temp_c */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Temp_c,
      cli_mxp_mux_state_XFP4_Temp_c_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Low_Tx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Low_Tx_Power_Alarm,
      cli_mxp_mux_state_XFP4_Low_Tx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/High_Tx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_High_Tx_Power_Alarm,
      cli_mxp_mux_state_XFP4_High_Tx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Low_Rx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Low_Rx_Power_Alarm,
      cli_mxp_mux_state_XFP4_Low_Rx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/High_Rx_Power_Alarm */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_High_Rx_Power_Alarm,
      cli_mxp_mux_state_XFP4_High_Rx_Power_Alarm_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Rx_CDR_Loss_of_Lock */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Rx_CDR_Loss_of_Lock,
      cli_mxp_mux_state_XFP4_Rx_CDR_Loss_of_Lock_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Tx_CDR_Loss_of_Lock */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Tx_CDR_Loss_of_Lock,
      cli_mxp_mux_state_XFP4_Tx_CDR_Loss_of_Lock_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state-XFP4/Laser_Fault */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_Laser_Fault,
      cli_mxp_mux_state_XFP4_Laser_Fault_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_XFP4_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_optical_line_status_brctl_showstp_br0_get
* 
* Get database object callback
* Path: /mux-optical-line-status/brctl_showstp_br0
* Fill in 'dstval' contents
* 
* INPUTS:
*     see ncx/getcb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_optical_line_status_brctl_showstp_br0_get(
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *brctl_showstp_br0;

  if (LOGDEBUG)
  {
    log_debug("\nEnter cli_mxp_mux_optical_line_status_brctl_showstp_br0_get callback");
  }

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE)
  {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the brctl_showstp_br0 var here, change EMPTY_STRING */
  FILE *f = NULL;
  unsigned int strlength;
  char buf[100] = {0};
  char *response = NULL;
  char *temp = NULL;
  unsigned int size = 1;
  f = popen("brctl showstp br0", "r");
  while (fgets(buf, sizeof(buf), f) != NULL)
  {
    strlength = strlen(buf);
    temp = realloc(response, size + strlength);

    response = temp;
    strcpy(response + size - 1, buf);
    size += strlength;
  }

  brctl_showstp_br0 = (const xmlChar *)response;
  res = val_set_simval_obj(
      dstval,
      dstval->obj,
      brctl_showstp_br0);

  return res;

} /* cli_mxp_mux_optical_line_status_brctl_showstp_br0_get */

/********************************************************************
* FUNCTION cli_mxp_mux_state_mro
* 
* Make read-only top-level node
* Path: /mux-state
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_state_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-state */
  res = agt_add_top_container(mux_state_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-state/fpga_temperature_state */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_fpga_temperature_state,
      cli_mxp_mux_state_fpga_temperature_state_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state/board_humidity_state */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_board_humidity_state,
      cli_mxp_mux_state_board_humidity_state_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state/edfa_output_power_state */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_edfa_output_power_state,
      cli_mxp_mux_state_edfa_output_power_state_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state/xfp_tx_power */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_xfp_tx_power,
      cli_mxp_mux_state_xfp_tx_power_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state/xfp_rx_power */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_xfp_rx_power,
      cli_mxp_mux_state_xfp_rx_power_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state/device_manufacturer */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_device_manufacturer,
      cli_mxp_mux_state_device_manufacturer_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state/device_swVersion */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_device_swVersion,
      cli_mxp_mux_state_device_swVersion_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state/device_hwVersion */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_device_hwVersion,
      cli_mxp_mux_state_device_hwVersion_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  /* add /mux-state/device_boardId */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_device_boardId,
      cli_mxp_mux_state_device_boardId_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_mro */

/********************************************************************
* FUNCTION cli_mxp_mux_optical_line_status_mro
* 
* Make read-only top-level node
* Path: /mux-optical-line-status
* 
* RETURNS:
*     error status
********************************************************************/
static status_t
cli_mxp_mux_optical_line_status_mro(void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;

  /* add /mux-optical-line-status */
  res = agt_add_top_container(mux_optical_line_status_obj, &parentval);
  if (res != NO_ERR)
  {
    return res;
  }

  /* add /mux-optical-line-status/brctl_showstp_br0 */
  childval = agt_make_virtual_leaf(
      parentval->obj,
      y_cli_mxp_N_brctl_showstp_br0,
      cli_mxp_mux_optical_line_status_brctl_showstp_br0_get,
      &res);
  if (childval != NULL)
  {
    val_add_child(childval, parentval);
  }
  else
  {
    return res;
  }

  return res;

} /* cli_mxp_mux_optical_line_status_mro */

/********************************************************************
* FUNCTION y_cli_mxp_mux_notify_activate_validate
* 
* RPC validation phase
* All YANG constraints have passed at this point.
* Add description-stmt checks in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cli_mxp_mux_notify_activate_validate(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
  status_t res = NO_ERR;
  val_value_t *errorval = NULL;

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_OPERATION,
        res,
        methnode,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* y_cli_mxp_mux_notify_activate_validate */

/********************************************************************
* FUNCTION y_cli_mxp_mux_notify_activate_invoke
* 
* RPC invocation phase
* All constraints have passed at this point.
* Call device instrumentation code in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cli_mxp_mux_notify_activate_invoke(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
  status_t res = NO_ERR;

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if msg is used */
  (void)msg;

  /* remove the next line if methnode is used */
  (void)methnode;

  /* invoke your device instrumentation code here */

  initial_polling_alarms = 1;
  /*
  if (alarma_tid == 0) {
    log_debug("\n******ALARMA ACTIVADA******");
    pthread_create((pthread_t *)&alarma_tid, NULL, alarmas_thread, NULL);
    } 
  */

  return res;

} /* y_cli_mxp_mux_notify_activate_invoke */

/********************************************************************
* FUNCTION y_cli_mxp_mux_notify_deactivate_validate
* 
* RPC validation phase
* All YANG constraints have passed at this point.
* Add description-stmt checks in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cli_mxp_mux_notify_deactivate_validate(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
  status_t res = NO_ERR;
  val_value_t *errorval = NULL;

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_OPERATION,
        res,
        methnode,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* y_cli_mxp_mux_notify_deactivate_validate */

/********************************************************************
* FUNCTION y_cli_mxp_mux_notify_deactivate_invoke
* 
* RPC invocation phase
* All constraints have passed at this point.
* Call device instrumentation code in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cli_mxp_mux_notify_deactivate_invoke(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
  status_t res = NO_ERR;

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if msg is used */
  (void)msg;

  /* remove the next line if methnode is used */
  (void)methnode;

  /* invoke your device instrumentation code here */

  /* the oven should be turned off but is on (stop the oven thread) */
  /**
  if (alarma_tid != 0) {
  
    void *resp;
    int rc = pthread_cancel(alarma_tid);
    rc = pthread_join(alarma_tid, &resp);
    if (resp == PTHREAD_CANCELED){
      printf("Thread was canceled\n");
      alarma_tid=0;
      log_debug("\n******ALARMA DESCTIVADA******");
    }
  }
**/

  return res;

} /* y_cli_mxp_mux_notify_deactivate_invoke */

/********************************************************************
* FUNCTION y_cli_mxp_mux_apply_config_validate
* 
* RPC validation phase
* All YANG constraints have passed at this point.
* Add description-stmt checks in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cli_mxp_mux_apply_config_validate(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
  status_t res = NO_ERR;
  val_value_t *errorval = NULL;

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_OPERATION,
        res,
        methnode,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* y_cli_mxp_mux_apply_config_validate */

/********************************************************************
* FUNCTION y_cli_mxp_mux_apply_config_invoke
* 
* RPC invocation phase
* All constraints have passed at this point.
* Call device instrumentation code in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cli_mxp_mux_apply_config_invoke(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
  status_t res = NO_ERR;

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if msg is used */
  (void)msg;

  /* remove the next line if methnode is used */
  (void)methnode;

  /* invoke your device instrumentation code here */



///ACA MANDO MENDASE

  val_value_t *respuesta_mux_apply;
  /* respuesta rpc */
  //if (system_status == -1)
  //{
    //respuesta_mux_apply = val_make_string(cli_mxp_mod->nsid, y_cli_mxp_N_respuesta_mux_apply_config, "ERROR");
  //}
  //else
  //{
    respuesta_mux_apply = val_make_string(cli_mxp_mod->nsid, y_cli_mxp_N_respuesta_mux_apply_config, "OK");
  //}

  dlq_enque(respuesta_mux_apply, &msg->rpc_dataQ);
  msg->rpc_data_type = RPC_DATA_YANG;


/////



  char str[80];
  char buff[80];
  int system_status;
  strcpy(str, "cd /mxp/app/cli && ./muxponder ");
  strcat(str, "--configuracion ");
  strcat(str, "--");
  strcat(str, tipo_trafico_var);
  strcat(str, " --");
  strcat(str, tipo_fec_linea_var);
  strcat(str, " --");
  strcat(str, tipo_fec_cliente_var);
  printf("\n COMANDO : %s\n", str);

  sem_wait(&mutex);
  
  if (close(shmfd) != 0)
  {
    printf("\n ERROR cerrando mem compartida \n");
  }
  else{
    printf("\n OK cerrando mem compartida \n");
  }

  rpc_in_progress = 1;

  //kill monitor, debido al error de no poder leer mientras escribe en memoria compartida.
  system("killall monitor");
  //system_status = system(str);

  int pid = fork();
  if (pid < 0)
  {
    perror("fork");
    exit(1);
  }

  if (pid == 0)
  {
    // proceso hijo
    sleep(4);
    system_status = system(str);
    printf("\n Listo... \n");
    sleep(1);
    char *args[]={"/mxp/app/cli/monitor",NULL}; 
    execv(args[0],args);
    exit(0);
  }

  else
  {
    signal(SIGCHLD,SIG_IGN); 
    printf("\n SIGUE EL PADRE");
    //initial_polling_alarms = 1;
  }

  sem_post(&mutex);
  return res;

} /* y_cli_mxp_mux_apply_config_invoke */

/********************************************************************
* FUNCTION y_cli_mxp_mux_settings_validate
* 
* RPC validation phase
* All YANG constraints have passed at this point.
* Add description-stmt checks in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cli_mxp_mux_settings_validate(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
  status_t res = NO_ERR;
  val_value_t *errorval = NULL;

  if (res != NO_ERR)
  {
    agt_record_error(
        scb,
        &msg->mhdr,
        NCX_LAYER_OPERATION,
        res,
        methnode,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval,
        (errorval) ? NCX_NT_VAL : NCX_NT_NONE,
        errorval);
  }
  return res;

} /* y_cli_mxp_mux_settings_validate */

/********************************************************************
* FUNCTION y_cli_mxp_mux_settings_invoke
* 
* RPC invocation phase
* All constraints have passed at this point.
* Call device instrumentation code in this function.
* 
* INPUTS:
*     see agt/agt_rpc.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t y_cli_mxp_mux_settings_invoke(
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
{
  status_t res = NO_ERR;

  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if msg is used */
  (void)msg;

  /* remove the next line if methnode is used */
  (void)methnode;

  /* invoke your device instrumentation code here */

  char str[80];
  char buff[80];
  int system_status;

  ftoa(edfa_output_power_conf, buff, 2);

  strcpy(str, "cd /mxp/app/cli && ./settings ");
  strcat(str, "--potencia ");
  strcat(str, buff);
  printf("\n COMANDO : %s\n", str);
  system_status = system(str);

  val_value_t *respuesta_mux_settings;
  /* respuesta rpc */
  if (system_status == -1)
  {
    respuesta_mux_settings = val_make_string(cli_mxp_mod->nsid, y_cli_mxp_N_respuesta_mux_settings, "ERROR");
  }
  else
  {
    respuesta_mux_settings = val_make_string(cli_mxp_mod->nsid, y_cli_mxp_N_respuesta_mux_settings, "OK");
  }
  dlq_enque(respuesta_mux_settings, &msg->rpc_dataQ);
  msg->rpc_data_type = RPC_DATA_YANG;

  return res;

} /* y_cli_mxp_mux_settings_invoke */

/********************************************************************
* FUNCTION y_cli_mxp_mux_notify_send
* 
* Send a y_cli_mxp_mux_notify notification
* Called by your code when notification event occurs
* 
********************************************************************/
void y_cli_mxp_mux_notify_send(
    const xmlChar *INFO)
{
  agt_not_msg_t *notif;
  val_value_t *parmval;
  status_t res = NO_ERR;

  if (LOGDEBUG)
  {
    log_debug("\nGenerating <mux-notify> notification");
  }

  notif = agt_not_new_notification(mux_notify_obj);
  if (notif == NULL)
  {
    log_error("\nError: malloc failed, cannot send "
              "<mux-notify> notification");
    return;
  }

  /* add INFO to payload */
  parmval = agt_make_leaf(
      mux_notify_obj,
      y_cli_mxp_N_INFO,
      INFO,
      &res);
  if (parmval == NULL)
  {
    log_error(
        "\nError: make leaf failed (%s), cannot send "
        "<mux-notify> notification",
        get_error_string(res));
  }
  else
  {
    agt_not_add_to_payload(notif, parmval);
  }
  agt_not_queue_notification(notif);

} /* y_cli_mxp_mux_notify_send */

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
status_t y_cli_mxp_init(
    const xmlChar *modname,
    const xmlChar *revision)
{
  status_t res = NO_ERR;
  agt_profile_t *agt_profile = agt_get_profile();

  y_cli_mxp_init_static_vars();

  /* change if custom handling done */
  if (xml_strcmp(modname, y_cli_mxp_M_cli_mxp))
  {
    return ERR_NCX_UNKNOWN_MODULE;
  }

  if (revision && xml_strcmp(revision, y_cli_mxp_R_cli_mxp))
  {
    return ERR_NCX_WRONG_VERSION;
  }
  res = ncxmod_load_module(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_R_cli_mxp,
      &agt_profile->agt_savedevQ,
      &cli_mxp_mod);
  if (res != NO_ERR)
  {
    return res;
  }

  mux_config_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_config);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_misc_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state_misc);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_TX_RX_alarms_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state_TX_RX_alarms);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_power_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state_power);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_dsp_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state_dsp);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_edfa_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state_edfa);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_temp_hum_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state_temp_hum);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_XFP1_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state_XFP1);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_XFP2_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state_XFP2);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_XFP3_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state_XFP3);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_XFP4_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_state_XFP4);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_optical_line_status_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_optical_line_status);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_notify_activate_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_notify_activate);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_notify_deactivate_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_notify_deactivate);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_apply_config_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_apply_config);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_settings_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_settings);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_notify_obj = ncx_find_object(
      cli_mxp_mod,
      y_cli_mxp_N_mux_notify);
  if (cli_mxp_mod == NULL)
  {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  res = agt_rpc_register_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_notify_activate,
      AGT_RPC_PH_VALIDATE,
      y_cli_mxp_mux_notify_activate_validate);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_rpc_register_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_notify_activate,
      AGT_RPC_PH_INVOKE,
      y_cli_mxp_mux_notify_activate_invoke);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_rpc_register_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_notify_deactivate,
      AGT_RPC_PH_VALIDATE,
      y_cli_mxp_mux_notify_deactivate_validate);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_rpc_register_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_notify_deactivate,
      AGT_RPC_PH_INVOKE,
      y_cli_mxp_mux_notify_deactivate_invoke);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_rpc_register_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_apply_config,
      AGT_RPC_PH_VALIDATE,
      y_cli_mxp_mux_apply_config_validate);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_rpc_register_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_apply_config,
      AGT_RPC_PH_INVOKE,
      y_cli_mxp_mux_apply_config_invoke);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_rpc_register_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_settings,
      AGT_RPC_PH_VALIDATE,
      y_cli_mxp_mux_settings_validate);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_rpc_register_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_settings,
      AGT_RPC_PH_INVOKE,
      y_cli_mxp_mux_settings_invoke);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/configuracion",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_configuracion_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/tipo_trafico",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_tipo_trafico_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/tipo_fec_linea",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_tipo_fec_linea_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/tipo_fec_cliente",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_tipo_fec_cliente_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/canal",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_canal_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/potencia",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_potencia_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/cd_compensacion",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_cd_compensacion_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/edfa_output_power_config",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_edfa_output_power_config_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/warning_config",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_warning_config_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/ports",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_ports_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/ports/port",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_ports_port_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/ports/neighbor",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_ports_neighbor_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  res = agt_cb_register_callback(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/ports/port_neighbor",
      y_cli_mxp_R_cli_mxp,
      cli_mxp_mux_config_ports_port_neighbor_edit);
  if (res != NO_ERR)
  {
    return res;
  }

  /* put your module initialization code here */
  shmfd = shm_open(SHMOBJ_PATH, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
  if (shmfd < 0)
  {
    printf("Error in SHM_OPEN () \n");
    perror("In shm_open()");
    exit(1);
  }

  ftruncate(shmfd, SHM_SIZE);

  pt_monitor_struct = (Monitor *)mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
  if (pt_monitor_struct == NULL)
  {
    printf("Error in mmap() \n");
    perror("In mmap()");
    exit(1);
  }

  return res;
} /* y_cli_mxp_init */

/********************************************************************
* FUNCTION y_cli_mxp_init2
* 
* SIL init phase 2: non-config data structures
* Called after running config is loaded
* 
* RETURNS:
*     error status
********************************************************************/
status_t y_cli_mxp_init2(void)
{
  status_t res = NO_ERR;

  mux_config_val = agt_init_cache(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_config,
      &res);
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_optical_line_status_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_TX_RX_alarms_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_XFP1_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_XFP2_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_XFP3_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_XFP4_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_dsp_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_edfa_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_misc_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_power_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  res = cli_mxp_mux_state_temp_hum_mro();
  if (res != NO_ERR)
  {
    return res;
  }

  /* put your init2 code here */

  if (alarma_tid == 0)
  {
    pthread_create((pthread_t *)&alarma_tid, NULL, alarmas_thread, NULL);
    log_debug("\n******ALARMA ACTIVADA******");
  }

  return res;
} /* y_cli_mxp_init2 */

/********************************************************************
* FUNCTION y_cli_mxp_cleanup
*    cleanup the server instrumentation library
* 
********************************************************************/
void y_cli_mxp_cleanup(void)
{

  agt_rpc_unregister_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_notify_activate);

  agt_rpc_unregister_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_notify_deactivate);

  agt_rpc_unregister_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_apply_config);

  agt_rpc_unregister_method(
      y_cli_mxp_M_cli_mxp,
      y_cli_mxp_N_mux_settings);
  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/configuracion");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/tipo_trafico");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/tipo_fec_linea");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/tipo_fec_cliente");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/canal");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/potencia");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/cd_compensacion");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/edfa_output_power_config");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/warning_config");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/ports");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/ports/port");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/ports/neighbor");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/ports/port_neighbor");

  agt_cb_unregister_callbacks(
      y_cli_mxp_M_cli_mxp,
      (const xmlChar *)"/mux-config/deviceneighbors");

  /* put your cleanup code here */
  if (close(shmfd) != 0)
  {
    printf("Error closing the SHM \n");
  }

} /* y_cli_mxp_cleanup */

/* END cli_mxp.c */
