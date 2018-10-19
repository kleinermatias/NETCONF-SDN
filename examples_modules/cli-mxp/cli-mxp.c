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
#include <sys/stat.h>   /* For mode constants */
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


/* put your static variables here */
Monitor *pt_monitor_struct;
int shmfd;
float edfa_output_power_conf;
float value_notify_conf;
float value_rx_power_notify_conf;
int time_notify_conf;
volatile pthread_t alarma_tid;
const xmlChar *tipo_trafico_var;
const xmlChar *tipo_fec_linea_var;
const xmlChar *tipo_fec_cliente_var;
static char alarms[2][100] = { "Alarm", "--" };
static char general_status[2][100] = { "Yes", "No" };

static int eolalm_anterior = 0;
static int modtempalm_anterior = 0;
static int txooa_anterior = 0;
static int txlofalm_anterior = 0;
static int txdscerr_anterior = 0;
static int lswavalm_anterior = 0;
static int txalmint_anterior = 0;
static int lsbiasalm_anterior = 0;
static int lstempalm_anterior = 0;
static int txlockerr_anterior = 0;
static int lspowalm_anterior = 0;
static int modbiasalm_anterior = 0;
static int latchedtxfifoerr_anterior = 0;
static int rxalmint_anterior = 0;
static int rxpowalm_anterior = 0;
static int rxlos_anterior = 0;
static int rxlockerr_anterior = 0;
static int rxs_anterior = 0;
static int prbserrdet_anterior = 0;


struct Device_info {
    char  device_manufacturer[50];
    char  device_swVersion[50];
    char  device_hwVersion[50];
    char  device_boardId[50];
} device_info;  

static void *
alarmas_thread(void *arg)
{
    int rc;
    rc = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    while (alarma_tid) {
        
        if(atof(pt_monitor_struct->edfa_struct.edfa_output_power) > value_notify_conf)
        {   
            y_cli_mxp_mux_notify_send((const xmlChar *)"[WARNING] pout");
        }

        if(pt_monitor_struct->txp_struct.txp_rx_power < value_rx_power_notify_conf)
        {   
            y_cli_mxp_mux_notify_send((const xmlChar *)"[WARNING] rx_power");
        }

        if( (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.eolalm != eolalm_anterior )
        {   
            if( eolalm_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] EOL ALM");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] EOL ALM");
            }   
        }

        if( (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modtempalm != modtempalm_anterior )
        {    
            if( modtempalm_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Mod TEMP ALM");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Mod TEMP ALM");
            }
        }

        if( (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txooa != txooa_anterior )
        {   
            if( txooa_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] TxOOA");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] TxOOA");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlofalm != txlofalm_anterior)
        {   
            if( txlofalm_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx LOF ALM");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx LOF ALM");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txdscerr != txdscerr_anterior)
        {   
            if( txdscerr_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx DSC ERR");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx DSC ERR");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lswavalm != lswavalm_anterior)
        {   
            if( lswavalm_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Ls WAV ALM");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Ls WAV ALM");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txalmint != txalmint_anterior)
        {   
            if( txalmint_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx ALM INT");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx ALM INT");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lsbiasalm != lsbiasalm_anterior)
        {   
            if( lsbiasalm_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Ls BIAS ALM");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Ls BIAS ALM");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lstempalm != lstempalm_anterior)
        {   
            if( lstempalm_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Ls TEMP ALM");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Ls TEMP ALM");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlockerr != txlockerr_anterior)
        {   
            if( txlockerr_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Tx LOCK ERR");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Tx LOCK ERR");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lspowalm != lspowalm_anterior)
        {   
            if( lspowalm_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Ls POW ALM");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Ls POW ALM");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modbiasalm != modbiasalm_anterior)
        {   
            if( modbiasalm_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Mod BIAS ALM");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Mod BIAS ALM");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.latchedtxfifoerr != latchedtxfifoerr_anterior)
        {   
            if( latchedtxfifoerr_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] LATCHED TxFIFO ERR");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] LATCHED TxFIFO ERR");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxalmint != rxalmint_anterior)
        {   
            if( rxalmint_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] RxALM INT");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] RxALM INT");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxpowalm != rxpowalm_anterior)
        {   
            if( rxpowalm_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Rx POW ALM");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Rx POW ALM");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlos != rxlos_anterior)
        {   
            if( rxlos_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Rx LOS");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Rx LOS");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlockerr != rxlockerr_anterior)
        {   
            if( rxlockerr_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] Rx LOCK ERR");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] Rx LOCK ERR");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxs != rxs_anterior)
        {   
            if( rxs_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] RXS");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] RXS");
            }
        }

        if((int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.prbserrdet != prbserrdet_anterior)
        {   
            if( prbserrdet_anterior == 0) {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[ALARM] PRBS ERR DET");
            }
            else {
              y_cli_mxp_mux_notify_send((const xmlChar *)"[--] PRBS ERR DET");
            }
        }

        eolalm_anterior =             (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.eolalm;
        modtempalm_anterior =         (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modtempalm;
        txooa_anterior =              (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txooa;
        txlofalm_anterior =           (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlofalm;
        txdscerr_anterior =           (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txdscerr;
        lswavalm_anterior =           (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lswavalm;
        txalmint_anterior =           (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txalmint;
        lsbiasalm_anterior =          (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lsbiasalm;
        lstempalm_anterior =          (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lstempalm;
        txlockerr_anterior =          (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlockerr;
        lspowalm_anterior =           (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lspowalm;
        modbiasalm_anterior =         (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modbiasalm;
        latchedtxfifoerr_anterior =   (int)pt_monitor_struct->txp_struct.txp_tx_alarm.fields.latchedtxfifoerr;
        rxalmint_anterior =           (int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxalmint;
        rxpowalm_anterior =           (int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxpowalm;
        rxlos_anterior =              (int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlos;
        rxlockerr_anterior =          (int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlockerr;
        rxs_anterior =                (int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxs;
        prbserrdet_anterior =         (int)pt_monitor_struct->txp_struct.txp_rx_alarm.fields.prbserrdet;
        
        sleep(10);
        //sleep(time_notify_conf);
    }
    return NULL;
}

// reverses a string 'str' of length 'len'
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
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
        str[i++] = (x%10) + '0';
        x = x/10;
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
        res[i] = '.';  // add dot
 
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
static void y_cli_mxp_init_static_vars (void)
{
  cli_mxp_mod = NULL;
  mux_config_obj = NULL;
  mux_state_obj = NULL;
  mux_state_misc_obj = NULL;		
  mux_state_TX_RX_alarms_obj = NULL;
  mux_optical_line_status_obj = NULL;
  mux_notify_activate_obj = NULL;
  mux_notify_deactivate_obj = NULL;
  mux_apply_config_obj = NULL;
  mux_settings_obj = NULL;
  mux_notify_obj = NULL;
  mux_config_val = NULL;

  /* init your static variables here */
  edfa_output_power_conf=0.0;
  
  /* PRUEBA */
  FILE* fp;
  char aux_buf[1024];

  if ((fp = fopen("/root/usrapp/deviceDescription.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
  }
 
 
  fgets(aux_buf, sizeof(aux_buf), fp);
  aux_buf[strlen(aux_buf) - 1] = '\0'; 
  strcpy( device_info.device_manufacturer, aux_buf);

  fgets(aux_buf, sizeof(aux_buf), fp);
  aux_buf[strlen(aux_buf) - 1] = '\0';
  strcpy( device_info.device_swVersion, aux_buf); 

  fgets(aux_buf, sizeof(aux_buf), fp);
  aux_buf[strlen(aux_buf) - 1] = '\0';
  strcpy( device_info.device_hwVersion, aux_buf); 

  fgets(aux_buf, sizeof(aux_buf), fp);
  aux_buf[strlen(aux_buf) - 1] = '\0';
  strcpy( device_info.device_boardId, aux_buf);

  fclose(fp);
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
static status_t cli_mxp_mux_config_configuracion_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_configuracion_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop) {
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

  if (res != NO_ERR) {
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
static status_t cli_mxp_mux_config_tipo_trafico_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_tipo_trafico_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    tipo_trafico_var = VAL_STRING(newval);
    switch (editop) {
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

  if (res != NO_ERR) {
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
static status_t cli_mxp_mux_config_tipo_fec_linea_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_tipo_fec_linea_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    tipo_fec_linea_var = VAL_STRING(newval);
    switch (editop) {
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

  if (res != NO_ERR) {
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
static status_t cli_mxp_mux_config_tipo_fec_cliente_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_tipo_fec_cliente_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    tipo_fec_cliente_var = VAL_STRING(newval);
    switch (editop) {
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

  if (res != NO_ERR) {
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
static status_t cli_mxp_mux_config_canal_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_canal_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop) {
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

  if (res != NO_ERR) {
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
static status_t cli_mxp_mux_config_potencia_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_potencia_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop) {
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

  if (res != NO_ERR) {
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
static status_t cli_mxp_mux_config_cd_compensacion_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_cd_compensacion_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop) {
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

  if (res != NO_ERR) {
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
static status_t cli_mxp_mux_config_edfa_output_power_config_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_edfa_output_power_config_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    edfa_output_power_conf = VAL_DEC64(newval)/10.00;



    switch (editop) {
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

  if (res != NO_ERR) {
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
* FUNCTION cli_mxp_mux_config_time_notify_config_edit
* 
* Edit database object callback
* Path: /mux-config/time_notify_config
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_time_notify_config_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_time_notify_config_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    time_notify_conf = VAL_INT(newval);
    printf("%s\n", "A VERRRRRRRRR··························· :");
    printf("%d\n", time_notify_conf);

    switch (editop) {
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

  if (res != NO_ERR) {
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

} /* cli_mxp_mux_config_time_notify_config_edit */


/********************************************************************
* FUNCTION cli_mxp_mux_config_value_notify_config_edit
* 
* Edit database object callback
* Path: /mux-config/value_notify_config
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_value_notify_config_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_value_notify_config_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    value_notify_conf = VAL_DEC64(newval)/10.00;

    switch (editop) {
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

  if (res != NO_ERR) {
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

} /* cli_mxp_mux_config_value_notify_config_edit */

/********************************************************************
* FUNCTION cli_mxp_mux_config_value_rx_power_notify_config_edit
* 
* Edit database object callback
* Path: /mux-config/value_rx_power_notify_config
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_value_rx_power_notify_config_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_value_rx_power_notify_config_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */

    value_rx_power_notify_conf = atof(VAL_STRING(newval));
    

    switch (editop) {
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

  if (res != NO_ERR) {
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

} /* cli_mxp_mux_config_value_rx_power_notify_config_edit */


/********************************************************************
* FUNCTION cli_mxp_mux_config_deviceneighbors_edit
* 
* Edit database object callback
* Path: /mux-config/deviceneighbors
* Add object instrumentation in COMMIT phase.
* 
* INPUTS:
*     see agt/agt_cb.h for details
* 
* RETURNS:
*     error status
********************************************************************/
static status_t cli_mxp_mux_config_deviceneighbors_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_deviceneighbors_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop) {
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

  if (res != NO_ERR) {
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

} /* cli_mxp_mux_config_deviceneighbors_edit */

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
static status_t cli_mxp_mux_config_edit (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  agt_cbtyp_t cbtyp,
  op_editop_t editop,
  val_value_t *newval,
  val_value_t *curval)
{
  status_t res = NO_ERR;
  val_value_t *errorval = (curval) ? curval : newval;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_config_edit callback for %s phase",
      agt_cbtype_name(cbtyp));
  }

  switch (cbtyp) {
  case AGT_CB_VALIDATE:
    /* description-stmt validation here */
    break;
  case AGT_CB_APPLY:
    /* database manipulation done here */
    break;
  case AGT_CB_COMMIT:
    /* device instrumentation done here */
    switch (editop) {
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

    if (res == NO_ERR) {
      res = agt_check_cache(&mux_config_val, newval, curval, editop);
    }
    
    break;
  case AGT_CB_ROLLBACK:
    /* undo device instrumentation here */
    break;
  default:
    res = SET_ERROR(ERR_INTERNAL_VAL);
  }

  if (res != NO_ERR) {
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
static status_t cli_mxp_mux_state_fpga_temperature_state_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *fpga_temperatures;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_fpga_temperature_state_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the fpga_temperature_state var here, change zero */


  char buff[20];

  float fpga_temperatur=pt_monitor_struct->general_struct.fpga_temperature;
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
static status_t cli_mxp_mux_state_board_humidity_state_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *board_humidity_state;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_board_humidity_state_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
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
static status_t cli_mxp_mux_state_edfa_output_power_state_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_edfa_output_power_state_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
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
static status_t cli_mxp_mux_state_xfp_tx_power_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *tx_power;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_xfp_tx_power_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }


  /* set the xfp_tx_power var here */

  float tx_powe=pt_monitor_struct->txp_struct.txp_tx_power;
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
static status_t cli_mxp_mux_state_xfp_rx_power_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *rx_power;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_xfp_rx_power_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the xfp_rx_power var here */

  float rx_powe=pt_monitor_struct->txp_struct.txp_rx_power;
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
static status_t cli_mxp_mux_state_device_manufacturer_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *device_manufacturer;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_device_manufacturer_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
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
static status_t cli_mxp_mux_state_device_swVersion_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *device_swVersion;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_device_swVersion_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
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
static status_t cli_mxp_mux_state_device_hwVersion_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *device_hwVersion;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_device_hwVersion_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
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
static status_t cli_mxp_mux_state_device_boardId_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *device_boardId;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_device_boardId_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
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
static status_t cli_mxp_mux_state_misc_temp_around_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_misc_temp_around_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the temp_around var here, change EMPTY_STRING */
  const xmlChar *temp_around_c;
  float temp_around=pt_monitor_struct->txp_struct.txp_temperature[0];
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
static status_t cli_mxp_mux_state_misc_temp_case_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_misc_temp_case_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the temp_case var here, change EMPTY_STRING */
  const xmlChar *temp_case_c;
  float temp_case=pt_monitor_struct->txp_struct.txp_temperature[1];
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
static status_t cli_mxp_mux_state_misc_temp_tx_laser_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_misc_temp_tx_laser_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the temp_tx_laser var here, change EMPTY_STRING */
  const xmlChar *temp_tx_laser_c;
  float temp_tx_laser=pt_monitor_struct->txp_struct.txp_temperature[2];
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
static status_t cli_mxp_mux_state_misc_temp_rx_laser_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_misc_temp_rx_laser_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the temp_rx_laser var here, change EMPTY_STRING */
  const xmlChar *temp_rx_laser_c;
  float temp_rx_laser=pt_monitor_struct->txp_struct.txp_temperature[3];
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
static status_t cli_mxp_mux_state_misc_loss_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *loss;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_misc_loss_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the loss var here, change EMPTY_STRING */
  int loss_int = pt_monitor_struct->txp_struct.txp_loss;
  loss=(const xmlChar *)general_status[loss_int];
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
static status_t cli_mxp_mux_state_misc_interrupt_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *interrupt;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_misc_interrupt_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the interrupt var here, change EMPTY_STRING */
  int interrupt_int = pt_monitor_struct->txp_struct.txp_interrupt;
  interrupt=(const xmlChar *)general_status[interrupt_int];
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
static status_t cli_mxp_mux_state_misc_tx_laser_itu_band_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *tx_laser_itu_band;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_misc_tx_laser_itu_band_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
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
static status_t cli_mxp_mux_state_misc_tx_laser_itu_channel_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_misc_tx_laser_itu_channel_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the tx_laser_itu_channel var here, change EMPTY_STRING */
  const xmlChar *tx_laser_itu_channel;
  float tx_laser_itu_channel_float=pt_monitor_struct->txp_struct.txp_tx_laser_itu_channel.fields.channel;
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
static status_t cli_mxp_mux_state_misc_rx_laser_itu_band_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *rx_laser_itu_band;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_misc_rx_laser_itu_band_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
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
static status_t cli_mxp_mux_state_misc_rx_laser_itu_channel_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_misc_rx_laser_itu_channel_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the rx_laser_itu_channel var here, change EMPTY_STRING */
  const xmlChar *rx_laser_itu_channel;
  float rx_laser_itu_channel_float=pt_monitor_struct->txp_struct.txp_rx_laser_itu_channel.fields.channel;
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
  cli_mxp_mux_state_misc_mro (void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;


  /* add /mux-state-misc */
  res = agt_add_top_container(mux_state_misc_obj, &parentval);
  if (res != NO_ERR) {
    return res;
  }

  /* add /mux-state-misc/temp_around */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_temp_around,
    cli_mxp_mux_state_misc_temp_around_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-misc/temp_case */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_temp_case,
    cli_mxp_mux_state_misc_temp_case_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-misc/temp_tx_laser */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_temp_tx_laser,
    cli_mxp_mux_state_misc_temp_tx_laser_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-misc/temp_rx_laser */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_temp_rx_laser,
    cli_mxp_mux_state_misc_temp_rx_laser_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-misc/loss */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_loss,
    cli_mxp_mux_state_misc_loss_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-misc/interrupt */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_interrupt,
    cli_mxp_mux_state_misc_interrupt_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-misc/tx_laser_itu_band */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_tx_laser_itu_band,
    cli_mxp_mux_state_misc_tx_laser_itu_band_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-misc/tx_laser_itu_channel */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_tx_laser_itu_channel,
    cli_mxp_mux_state_misc_tx_laser_itu_channel_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-misc/rx_laser_itu_band */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_rx_laser_itu_band,
    cli_mxp_mux_state_misc_rx_laser_itu_band_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-misc/rx_laser_itu_channel */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_rx_laser_itu_channel,
    cli_mxp_mux_state_misc_rx_laser_itu_channel_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
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
static status_t cli_mxp_mux_state_TX_RX_alarms_EOL_ALM_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *EOL_ALM;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_EOL_ALM_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the EOL_ALM var here, change EMPTY_STRING */
  int EOL_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.eolalm;
  EOL_ALM=(const xmlChar *)alarms[EOL_ALM_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_MOD_TEMP_ALM_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *MOD_TEMP_ALM;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_MOD_TEMP_ALM_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the MOD_TEMP_ALM var here, change EMPTY_STRING */
  int MOD_TEMP_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modtempalm;
  MOD_TEMP_ALM=(const xmlChar *)alarms[MOD_TEMP_ALM_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_TX_OOA_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *TX_OOA;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_TX_OOA_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the TX_OOA var here, change EMPTY_STRING */
  int TX_OOA_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txooa;
  TX_OOA=(const xmlChar *)alarms[TX_OOA_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_TX_LOF_ALM_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *TX_LOF_ALM;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_TX_LOF_ALM_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the TX_LOF_ALM var here, change EMPTY_STRING */
  int TX_LOF_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlofalm;
  TX_LOF_ALM=(const xmlChar *)alarms[TX_LOF_ALM_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_TX_DSC_ERR_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *TX_DSC_ERR;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_TX_DSC_ERR_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the TX_DSC_ERR var here, change EMPTY_STRING */
  int TX_DSC_ERR_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txdscerr;
  TX_DSC_ERR=(const xmlChar *)alarms[TX_DSC_ERR_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_LS_WAV_ALM_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LS_WAV_ALM;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_LS_WAV_ALM_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LS_WAV_ALM var here, change EMPTY_STRING */
  int LS_WAV_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lswavalm;
  LS_WAV_ALM=(const xmlChar *)alarms[LS_WAV_ALM_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_TX_ALM_INT_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *TX_ALM_INT;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_TX_ALM_INT_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the TX_ALM_INT var here, change EMPTY_STRING */
  int TX_ALM_INT_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txalmint;
  TX_ALM_INT=(const xmlChar *)alarms[TX_ALM_INT_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_LS_BIAS_ALM_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LS_BIAS_ALM;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_LS_BIAS_ALM_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LS_BIAS_ALM var here, change EMPTY_STRING */
  int LS_BIAS_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lsbiasalm;
  LS_BIAS_ALM=(const xmlChar *)alarms[LS_BIAS_ALM_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_LS_TEMP_ALM_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LS_TEMP_ALM;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_LS_TEMP_ALM_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LS_TEMP_ALM var here, change EMPTY_STRING */
  int LS_TEMP_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lstempalm;
  LS_TEMP_ALM=(const xmlChar *)alarms[LS_TEMP_ALM_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_TX_LOCK_ERR_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *TX_LOCK_ERR;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_TX_LOCK_ERR_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the TX_LOCK_ERR var here, change EMPTY_STRING */
  int TX_LOCK_ERR_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.txlockerr;
  TX_LOCK_ERR=(const xmlChar *)alarms[TX_LOCK_ERR_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_LS_POW_ALM_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LS_POW_ALM;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_LS_POW_ALM_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LS_POW_ALM var here, change EMPTY_STRING */
  int LS_POW_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.lspowalm;
  LS_POW_ALM=(const xmlChar *)alarms[LS_POW_ALM_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_MOD_BIAS_ALM_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *MOD_BIAS_ALM;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_MOD_BIAS_ALM_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the MOD_BIAS_ALM var here, change EMPTY_STRING */
  int MOD_BIAS_ALM_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.modbiasalm;
  MOD_BIAS_ALM=(const xmlChar *)alarms[MOD_BIAS_ALM_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_LATCHED_TXFIFO_ERR_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *LATCHED_TXFIFO_ERR;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_LATCHED_TXFIFO_ERR_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the LATCHED_TXFIFO_ERR var here, change EMPTY_STRING */
  int LATCHED_TXFIFO_ERR_int = pt_monitor_struct->txp_struct.txp_tx_alarm.fields.latchedtxfifoerr;
  LATCHED_TXFIFO_ERR=(const xmlChar *)alarms[LATCHED_TXFIFO_ERR_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_RXALM_INT_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *RXALM_INT;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_RXALM_INT_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the RXALM_INT var here, change EMPTY_STRING */
  int RXALM_INT_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxalmint;
  RXALM_INT=(const xmlChar *)alarms[RXALM_INT_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_RXPOW_ALM_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *RXPOW_ALM;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_RXPOW_ALM_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the RXPOW_ALM var here, change EMPTY_STRING */
  int RXPOW_ALM_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxpowalm;
  RXPOW_ALM=(const xmlChar *)alarms[RXPOW_ALM_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_RX_LOS_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *RX_LOS;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_RX_LOS_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the RX_LOS var here, change EMPTY_STRING */
  int RX_LOS_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlos;
  RX_LOS=(const xmlChar *)alarms[RX_LOS_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_RX_LOCK_ERR_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *RX_LOCK_ERR;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_RX_LOCK_ERR_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the RX_LOCK_ERR var here, change EMPTY_STRING */
  int RX_LOCK_ERR_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxlockerr;
  RX_LOCK_ERR=(const xmlChar *)alarms[RX_LOCK_ERR_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_RXS_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *RXS;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_RXS_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the RXS var here, change EMPTY_STRING */
  int RXS_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.rxs;
  RXS=(const xmlChar *)alarms[RXS_int];
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
static status_t cli_mxp_mux_state_TX_RX_alarms_PRBS_ERR_DET_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *PRBS_ERR_DET;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_state_TX_RX_alarms_PRBS_ERR_DET_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
    return ERR_NCX_OPERATION_NOT_SUPPORTED;
  }

  /* set the PRBS_ERR_DET var here, change EMPTY_STRING */
  int PRBS_ERR_DET_int = pt_monitor_struct->txp_struct.txp_rx_alarm.fields.prbserrdet;
  PRBS_ERR_DET=(const xmlChar *)alarms[PRBS_ERR_DET_int];
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
  cli_mxp_mux_state_TX_RX_alarms_mro (void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;


  /* add /mux-state-TX-RX-alarms */
  res = agt_add_top_container(mux_state_TX_RX_alarms_obj, &parentval);
  if (res != NO_ERR) {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/EOL_ALM */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_EOL_ALM,
    cli_mxp_mux_state_TX_RX_alarms_EOL_ALM_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/MOD_TEMP_ALM */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_MOD_TEMP_ALM,
    cli_mxp_mux_state_TX_RX_alarms_MOD_TEMP_ALM_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/TX_OOA */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_TX_OOA,
    cli_mxp_mux_state_TX_RX_alarms_TX_OOA_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/TX_LOF_ALM */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_TX_LOF_ALM,
    cli_mxp_mux_state_TX_RX_alarms_TX_LOF_ALM_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/TX_DSC_ERR */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_TX_DSC_ERR,
    cli_mxp_mux_state_TX_RX_alarms_TX_DSC_ERR_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/LS_WAV_ALM */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_LS_WAV_ALM,
    cli_mxp_mux_state_TX_RX_alarms_LS_WAV_ALM_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/TX_ALM_INT */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_TX_ALM_INT,
    cli_mxp_mux_state_TX_RX_alarms_TX_ALM_INT_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/LS_BIAS_ALM */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_LS_BIAS_ALM,
    cli_mxp_mux_state_TX_RX_alarms_LS_BIAS_ALM_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/LS_TEMP_ALM */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_LS_TEMP_ALM,
    cli_mxp_mux_state_TX_RX_alarms_LS_TEMP_ALM_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/TX_LOCK_ERR */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_TX_LOCK_ERR,
    cli_mxp_mux_state_TX_RX_alarms_TX_LOCK_ERR_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/LS_POW_ALM */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_LS_POW_ALM,
    cli_mxp_mux_state_TX_RX_alarms_LS_POW_ALM_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/MOD_BIAS_ALM */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_MOD_BIAS_ALM,
    cli_mxp_mux_state_TX_RX_alarms_MOD_BIAS_ALM_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/LATCHED_TXFIFO_ERR */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_LATCHED_TXFIFO_ERR,
    cli_mxp_mux_state_TX_RX_alarms_LATCHED_TXFIFO_ERR_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/RXALM_INT */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_RXALM_INT,
    cli_mxp_mux_state_TX_RX_alarms_RXALM_INT_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/RXPOW_ALM */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_RXPOW_ALM,
    cli_mxp_mux_state_TX_RX_alarms_RXPOW_ALM_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/RX_LOS */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_RX_LOS,
    cli_mxp_mux_state_TX_RX_alarms_RX_LOS_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/RX_LOCK_ERR */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_RX_LOCK_ERR,
    cli_mxp_mux_state_TX_RX_alarms_RX_LOCK_ERR_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/RXS */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_RXS,
    cli_mxp_mux_state_TX_RX_alarms_RXS_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state-TX-RX-alarms/PRBS_ERR_DET */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_PRBS_ERR_DET,
    cli_mxp_mux_state_TX_RX_alarms_PRBS_ERR_DET_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  return res;

} /* cli_mxp_mux_state_TX_RX_alarms_mro */

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
static status_t cli_mxp_mux_optical_line_status_brctl_showstp_br0_get (
  ses_cb_t *scb,
  getcb_mode_t cbmode,
  const val_value_t *virval,
  val_value_t *dstval)
{
  status_t res = NO_ERR;
  const xmlChar *brctl_showstp_br0;

  if (LOGDEBUG) {
    log_debug("\nEnter cli_mxp_mux_optical_line_status_brctl_showstp_br0_get callback");
  }


  /* remove the next line if scb is used */
  (void)scb;

  /* remove the next line if virval is used */
  (void)virval;

  if (cbmode != GETCB_GET_VALUE) {
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
  while (fgets(buf, sizeof(buf), f) != NULL) {
        strlength = strlen(buf);
        temp = realloc(response, size + strlength);
        
        response = temp;
        strcpy(response + size - 1, buf);
        size += strlength;
  }

  brctl_showstp_br0 =  (const xmlChar *)response;
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
  cli_mxp_mux_state_mro (void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;


  /* add /mux-state */
  res = agt_add_top_container(mux_state_obj, &parentval);
  if (res != NO_ERR) {
    return res;
  }

  /* add /mux-state/fpga_temperature_state */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_fpga_temperature_state,
    cli_mxp_mux_state_fpga_temperature_state_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state/board_humidity_state */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_board_humidity_state,
    cli_mxp_mux_state_board_humidity_state_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state/edfa_output_power_state */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_edfa_output_power_state,
    cli_mxp_mux_state_edfa_output_power_state_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state/xfp_tx_power */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_xfp_tx_power,
    cli_mxp_mux_state_xfp_tx_power_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state/xfp_rx_power */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_xfp_rx_power,
    cli_mxp_mux_state_xfp_rx_power_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state/device_manufacturer */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_device_manufacturer,
    cli_mxp_mux_state_device_manufacturer_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state/device_swVersion */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_device_swVersion,
    cli_mxp_mux_state_device_swVersion_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state/device_hwVersion */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_device_hwVersion,
    cli_mxp_mux_state_device_hwVersion_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
    return res;
  }

  /* add /mux-state/device_boardId */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_device_boardId,
    cli_mxp_mux_state_device_boardId_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
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
  cli_mxp_mux_optical_line_status_mro (void)
{
  val_value_t *parentval = NULL, *childval = NULL;
  status_t res = NO_ERR;


  /* add /mux-optical-line-status */
  res = agt_add_top_container(mux_optical_line_status_obj, &parentval);
  if (res != NO_ERR) {
    return res;
  }

  /* add /mux-optical-line-status/brctl_showstp_br0 */
  childval = agt_make_virtual_leaf(
    parentval->obj,
    y_cli_mxp_N_brctl_showstp_br0,
    cli_mxp_mux_optical_line_status_brctl_showstp_br0_get,
    &res);
  if (childval != NULL) {
    val_add_child(childval, parentval);
  } else {
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
static status_t y_cli_mxp_mux_notify_activate_validate (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  xml_node_t *methnode)
{
  status_t res = NO_ERR;
  val_value_t *errorval = NULL;


  if (res != NO_ERR) {
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
static status_t y_cli_mxp_mux_notify_activate_invoke (
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
  

  if (alarma_tid == 0) {
    log_debug("\n******ALARMA ACTIVADA******");
    pthread_create((pthread_t *)&alarma_tid, NULL, alarmas_thread, NULL);
    } 
    
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
static status_t y_cli_mxp_mux_notify_deactivate_validate (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  xml_node_t *methnode)
{
  status_t res = NO_ERR;
  val_value_t *errorval = NULL;


  if (res != NO_ERR) {
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
static status_t y_cli_mxp_mux_notify_deactivate_invoke (
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
  
  if (alarma_tid != 0) {
  /* the oven should be turned off but is on (stop the oven thread) */
    void *resp;
    int rc = pthread_cancel(alarma_tid);
    rc = pthread_join(alarma_tid, &resp);
    if (resp == PTHREAD_CANCELED){
      printf("Thread was canceled\n");
      alarma_tid=0;
      log_debug("\n******ALARMA DESCTIVADA******");
    }
  }


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
static status_t y_cli_mxp_mux_apply_config_validate (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  xml_node_t *methnode)
{
  status_t res = NO_ERR;
  val_value_t *errorval = NULL;


  if (res != NO_ERR) {
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
static status_t y_cli_mxp_mux_apply_config_invoke (
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
  strcpy (str,"muxponder ");
  strcat (str,"--configuracion ");
  strcat (str,"--");
  strcat (str, tipo_trafico_var);
  strcat (str," --");
  strcat (str, tipo_fec_linea_var);
  strcat (str," --");
  strcat (str, tipo_fec_cliente_var);
  printf("\n COMANDO : %s\n", str);
  system_status = system(str);

  val_value_t *respuesta_mux_apply;
  /* respuesta rpc */
  if(system_status == -1) {
     respuesta_mux_apply = val_make_string(cli_mxp_mod->nsid, y_cli_mxp_N_respuesta_mux_apply_config, "ERROR");
  }
  else {
    respuesta_mux_apply = val_make_string(cli_mxp_mod->nsid, y_cli_mxp_N_respuesta_mux_apply_config, "OK");
  }

  dlq_enque(respuesta_mux_apply, &msg->rpc_dataQ);
  msg->rpc_data_type = RPC_DATA_YANG;

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
static status_t y_cli_mxp_mux_settings_validate (
  ses_cb_t *scb,
  rpc_msg_t *msg,
  xml_node_t *methnode)
{
  status_t res = NO_ERR;
  val_value_t *errorval = NULL;


  if (res != NO_ERR) {
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
static status_t y_cli_mxp_mux_settings_invoke (
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

  strcpy (str,"settings ");
  strcat (str,"--potencia ");
  strcat (str,buff);
  printf("\n COMANDO : %s\n", str);
  system_status = system(str);


  val_value_t *respuesta_mux_settings;
  /* respuesta rpc */
  if(system_status == -1) {
    respuesta_mux_settings = val_make_string(cli_mxp_mod->nsid, y_cli_mxp_N_respuesta_mux_settings, "ERROR");
  }
  else {
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
void y_cli_mxp_mux_notify_send (
  const xmlChar *INFO)
{
  agt_not_msg_t *notif;
  val_value_t *parmval;
  status_t res = NO_ERR;


  if (LOGDEBUG) {
    log_debug("\nGenerating <mux-notify> notification");
  }
  
  notif = agt_not_new_notification(mux_notify_obj);
  if (notif == NULL) {
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
  if (parmval == NULL) {
    log_error(
      "\nError: make leaf failed (%s), cannot send "
      "<mux-notify> notification",
      get_error_string(res));
  } else {
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
status_t y_cli_mxp_init (
  const xmlChar *modname,
  const xmlChar *revision)
{
  status_t res = NO_ERR;
  agt_profile_t *agt_profile = agt_get_profile();

  y_cli_mxp_init_static_vars();

  /* change if custom handling done */
  if (xml_strcmp(modname, y_cli_mxp_M_cli_mxp)) {
    return ERR_NCX_UNKNOWN_MODULE;
  }

  if (revision && xml_strcmp(revision, y_cli_mxp_R_cli_mxp)) {
    return ERR_NCX_WRONG_VERSION;
  }
  res = ncxmod_load_module(
    y_cli_mxp_M_cli_mxp,
    y_cli_mxp_R_cli_mxp,
    &agt_profile->agt_savedevQ,
    &cli_mxp_mod);
  if (res != NO_ERR) {
    return res;
  }

  mux_config_obj = ncx_find_object(
    cli_mxp_mod,
    y_cli_mxp_N_mux_config);
  if (cli_mxp_mod == NULL) {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_obj = ncx_find_object(
    cli_mxp_mod,
    y_cli_mxp_N_mux_state);
  if (cli_mxp_mod == NULL) {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_state_misc_obj = ncx_find_object(
    cli_mxp_mod,
    y_cli_mxp_N_mux_state_misc);
  if (cli_mxp_mod == NULL) {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
    mux_state_TX_RX_alarms_obj = ncx_find_object(
    cli_mxp_mod,
    y_cli_mxp_N_mux_state_TX_RX_alarms);
  if (cli_mxp_mod == NULL) {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_optical_line_status_obj = ncx_find_object(		
    cli_mxp_mod,		
    y_cli_mxp_N_mux_optical_line_status);		
  if (cli_mxp_mod == NULL) {		
      return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);		
  }
  mux_notify_activate_obj = ncx_find_object(
    cli_mxp_mod,
    y_cli_mxp_N_mux_notify_activate);
  if (cli_mxp_mod == NULL) {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_notify_deactivate_obj = ncx_find_object(
    cli_mxp_mod,
    y_cli_mxp_N_mux_notify_deactivate);
  if (cli_mxp_mod == NULL) {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_apply_config_obj = ncx_find_object(
    cli_mxp_mod,
    y_cli_mxp_N_mux_apply_config);
  if (cli_mxp_mod == NULL) {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_settings_obj = ncx_find_object(
    cli_mxp_mod,
    y_cli_mxp_N_mux_settings);
  if (cli_mxp_mod == NULL) {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  mux_notify_obj = ncx_find_object(
    cli_mxp_mod,
    y_cli_mxp_N_mux_notify);
  if (cli_mxp_mod == NULL) {
    return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
  }
  res = agt_rpc_register_method(
    y_cli_mxp_M_cli_mxp,
    y_cli_mxp_N_mux_notify_activate,
    AGT_RPC_PH_VALIDATE,
    y_cli_mxp_mux_notify_activate_validate);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_rpc_register_method(
    y_cli_mxp_M_cli_mxp,
    y_cli_mxp_N_mux_notify_activate,
    AGT_RPC_PH_INVOKE,
    y_cli_mxp_mux_notify_activate_invoke);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_rpc_register_method(
    y_cli_mxp_M_cli_mxp,
    y_cli_mxp_N_mux_notify_deactivate,
    AGT_RPC_PH_VALIDATE,
    y_cli_mxp_mux_notify_deactivate_validate);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_rpc_register_method(
    y_cli_mxp_M_cli_mxp,
    y_cli_mxp_N_mux_notify_deactivate,
    AGT_RPC_PH_INVOKE,
    y_cli_mxp_mux_notify_deactivate_invoke);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_rpc_register_method(
    y_cli_mxp_M_cli_mxp,
    y_cli_mxp_N_mux_apply_config,
    AGT_RPC_PH_VALIDATE,
    y_cli_mxp_mux_apply_config_validate);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_rpc_register_method(
    y_cli_mxp_M_cli_mxp,
    y_cli_mxp_N_mux_apply_config,
    AGT_RPC_PH_INVOKE,
    y_cli_mxp_mux_apply_config_invoke);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_rpc_register_method(
    y_cli_mxp_M_cli_mxp,
    y_cli_mxp_N_mux_settings,
    AGT_RPC_PH_VALIDATE,
    y_cli_mxp_mux_settings_validate);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_rpc_register_method(
    y_cli_mxp_M_cli_mxp,
    y_cli_mxp_N_mux_settings,
    AGT_RPC_PH_INVOKE,
    y_cli_mxp_mux_settings_invoke);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/configuracion",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_configuracion_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/tipo_trafico",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_tipo_trafico_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/tipo_fec_linea",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_tipo_fec_linea_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/tipo_fec_cliente",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_tipo_fec_cliente_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/canal",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_canal_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/potencia",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_potencia_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/cd_compensacion",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_cd_compensacion_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/edfa_output_power_config",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_edfa_output_power_config_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/time_notify_config",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_time_notify_config_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/value_notify_config",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_value_notify_config_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/value_rx_power_notify_config",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_value_rx_power_notify_config_edit);
  if (res != NO_ERR) {
    return res;
  }

  res = agt_cb_register_callback(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/deviceneighbors",
    y_cli_mxp_R_cli_mxp,
    cli_mxp_mux_config_deviceneighbors_edit);
  if (res != NO_ERR) {
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

  pt_monitor_struct = (Monitor *) mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
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
status_t y_cli_mxp_init2 (void)
{
  status_t res = NO_ERR;

  mux_config_val = agt_init_cache(
    y_cli_mxp_M_cli_mxp,
    y_cli_mxp_N_mux_config,
    &res);
  if (res != NO_ERR) {
    return res;
  }

  res = cli_mxp_mux_optical_line_status_mro();
  if (res != NO_ERR) {
    return res;
  }

  res = cli_mxp_mux_state_mro();
  if (res != NO_ERR) {
    return res;
  }

  res = cli_mxp_mux_state_TX_RX_alarms_mro();
  if (res != NO_ERR) {
    return res;
  }

  res = cli_mxp_mux_state_misc_mro();
  if (res != NO_ERR) {
    return res;
  }

  /* put your init2 code here */

  return res;
} /* y_cli_mxp_init2 */

/********************************************************************
* FUNCTION y_cli_mxp_cleanup
*    cleanup the server instrumentation library
* 
********************************************************************/
void y_cli_mxp_cleanup (void)
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
    (const xmlChar *)"/mux-config/time_notify_config");

  agt_cb_unregister_callbacks(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/value_notify_config");

  agt_cb_unregister_callbacks(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/value_rx_power_notify_config");

  agt_cb_unregister_callbacks(
    y_cli_mxp_M_cli_mxp,
    (const xmlChar *)"/mux-config/deviceneighbors");

  /* put your cleanup code here */
  if (close(shmfd) != 0){
    printf("Error closing the SHM \n");
  }

} /* y_cli_mxp_cleanup */

/* END cli_mxp.c */
