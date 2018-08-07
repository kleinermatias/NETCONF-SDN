
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
#include<stdio.h>
#include<math.h>
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

static void *
oven_thread(void *arg)
{
    int rc;
    rc = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    while (alarma_tid) {
        if(atof(pt_monitor_struct->edfa_struct.edfa_output_power) > value_notify_conf)
        {   
            y_cli_mxp_mux_notify_send((const xmlChar *)"hola?");
        }
        sleep(time_notify_conf);
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
  mux_notify_activate_obj = NULL;
  mux_notify_deactivate_obj = NULL;
  mux_apply_config_obj = NULL;
  mux_settings_obj = NULL;
  mux_notify_obj = NULL;
  mux_config_val = NULL;

  /* init your static variables here */
  edfa_output_power_conf=0.0;
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
    printf("%s\n", "A VERRRRRRR");
    printf("%lf\n", VAL_DOUBLE(newval));
    //value_rx_power_notify_conf = atof(VAL_STRING(newval));
    //printf("SSSSSSSSSSSSSSSSSSSSSSSSSSSSsFloat value = %f\n", value_rx_power_notify_conf);

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
  printf(buf);
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
  printf(buf);
  rx_power = (const xmlChar *)buf;
  res = val_set_simval_obj(
    dstval,
    dstval->obj,
    rx_power);

  return res;

} /* cli_mxp_mux_state_xfp_rx_power_get */

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

  return res;

} /* cli_mxp_mux_state_mro */


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
    pthread_create((pthread_t *)&alarma_tid, NULL, oven_thread, NULL);
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
      printf("main(): thread was canceled\n");
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

  strcpy (str,"muxponder ");
  strcat (str,"--configuracion ");
  strcat (str,"--");
  strcat (str, tipo_trafico_var);
  strcat (str," --");
  strcat (str, tipo_fec_linea_var);
  strcat (str," --");
  strcat (str, tipo_fec_cliente_var);
  printf("\n COMANDO : %s\n", str);
  system(str);

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

  ftoa(edfa_output_power_conf, buff, 2);

  strcpy (str,"settings ");
  strcat (str,"--potencia ");
  strcat (str,buff);
  printf("\n COMANDO : %s\n", str);
  system(str);

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
  const xmlChar *ringtone)
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
  
  /* add ringtone to payload */
  parmval = agt_make_leaf(
    mux_notify_obj,
    y_cli_mxp_N_ringtone,
    ringtone,
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

  res = cli_mxp_mux_state_mro();
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

  /* put your cleanup code here */
  if (close(shmfd) != 0){
    printf("Error closing the SHM \n");
  }

} /* y_cli_mxp_cleanup */

/* END cli_mxp.c */
