  #include <sys/wait.h>
  #include <unistd.h>
  #include <sys/stat.h>
  #include <time.h>
  #include <signal.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <pthread.h>



  #include <xmlstring.h>
  #include <string.h>
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
  #include "alarma-fulgor.h"

  /* module static variables */
  static ncx_module_t *alarma_fulgor_mod;
  static obj_template_t *alarma_fulgor_obj;
  static obj_template_t *alarma_fulgor_state_obj;
  static obj_template_t *alarma_fulgor_activate_obj;
  static obj_template_t *alarma_fulgor_sonido_obj;
  static val_value_t *alarma_fulgor_val;

  /* put your static variables here */

  static boolean alarma_enabled;
  volatile pthread_t alarma_tid;
  static unsigned int hora_alarma;
  static unsigned int minuto_alarma;
  static unsigned int segundo_alarma;

  /********************************************************************
  * FUNCTION y_alarma_fulgor_init_static_vars
  * 
  * initialize module static variables
  * 
  ********************************************************************/
  static void y_alarma_fulgor_init_static_vars (void)
  {
    alarma_fulgor_mod = NULL;
    alarma_fulgor_obj = NULL;
    alarma_fulgor_state_obj = NULL;
    alarma_fulgor_activate_obj = NULL;
    alarma_fulgor_sonido_obj = NULL;
    alarma_fulgor_val = NULL;

    /* init your static variables here */
    alarma_enabled = FALSE;
    hora_alarma = 0;
    minuto_alarma = 0;
    segundo_alarma = 0;

  } /* y_alarma_fulgor_init_static_vars */


  /********************************************************************
  * FUNCTION alarma_fulgor_alarma_fulgor_horas_edit
  * 
  * Edit database object callback
  * Path: /alarma-fulgor/horas
  * Add object instrumentation in COMMIT phase.
  * 
  * INPUTS:
  *     see agt/agt_cb.h for details
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  static status_t alarma_fulgor_alarma_fulgor_horas_edit (
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
      log_debug("\nEnter alarma_fulgor_alarma_fulgor_horas_edit callback for %s phase",
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
      hora_alarma = VAL_UINT8(newval);
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

  } /* alarma_fulgor_alarma_fulgor_horas_edit */


  /********************************************************************
  * FUNCTION alarma_fulgor_alarma_fulgor_minutos_edit
  * 
  * Edit database object callback
  * Path: /alarma-fulgor/minutos
  * Add object instrumentation in COMMIT phase.
  * 
  * INPUTS:
  *     see agt/agt_cb.h for details
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  static status_t alarma_fulgor_alarma_fulgor_minutos_edit (
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
      log_debug("\nEnter alarma_fulgor_alarma_fulgor_minutos_edit callback for %s phase",
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
    minuto_alarma = VAL_UINT8(newval);
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

  } /* alarma_fulgor_alarma_fulgor_minutos_edit */


  /********************************************************************
  * FUNCTION alarma_fulgor_alarma_fulgor_segundos_edit
  * 
  * Edit database object callback
  * Path: /alarma-fulgor/segundos
  * Add object instrumentation in COMMIT phase.
  * 
  * INPUTS:
  *     see agt/agt_cb.h for details
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  static status_t alarma_fulgor_alarma_fulgor_segundos_edit (
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
      log_debug("\nEnter alarma_fulgor_alarma_fulgor_segundos_edit callback for %s phase",
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
    segundo_alarma = VAL_UINT8(newval);
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

  } /* alarma_fulgor_alarma_fulgor_segundos_edit */


  /********************************************************************
  * FUNCTION alarma_fulgor_alarma_fulgor_ringtone_edit
  * 
  * Edit database object callback
  * Path: /alarma-fulgor/ringtone
  * Add object instrumentation in COMMIT phase.
  * 
  * INPUTS:
  *     see agt/agt_cb.h for details
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  static status_t alarma_fulgor_alarma_fulgor_ringtone_edit (
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
      log_debug("\nEnter alarma_fulgor_alarma_fulgor_ringtone_edit callback for %s phase",
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

  } /* alarma_fulgor_alarma_fulgor_ringtone_edit */


  /********************************************************************
  * FUNCTION alarma_fulgor_alarma_fulgor_edit
  * 
  * Edit database object callback
  * Path: /alarma-fulgor
  * Add object instrumentation in COMMIT phase.
  * 
  * INPUTS:
  *     see agt/agt_cb.h for details
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  static status_t alarma_fulgor_alarma_fulgor_edit (
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
      log_debug("\n**************Enter alarma_fulgor_alarma_fulgor_edit callback for %s phase",
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
    if (LOGDEBUG) {
      log_debug("\n************** \n \n \n MENSAJE PARA TODOS TODOS \n \n \n **************");
    }
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
        res = agt_check_cache(&alarma_fulgor_val, newval, curval, editop);
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

  } /* alarma_fulgor_alarma_fulgor_edit */

  /********************************************************************
  * FUNCTION alarma_fulgor_alarma_fulgor_state_horasis_get
  * 
  * Get database object callback
  * Path: /alarma-fulgor-state/horasis
  * Fill in 'dstval' contents
  * 
  * INPUTS:
  *     see ncx/getcb.h for details
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  static status_t alarma_fulgor_alarma_fulgor_state_horasis_get (
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
  {

    if (LOGDEBUG) {
      log_debug("\nEnter alarma_fulgor_alarma_fulgor_state_horasis_get callback");
    }


    status_t res;
    res = NO_ERR;
    
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time( &rawtime );
    info = localtime( &rawtime );
    strftime(buffer,80,"%H", info);
    res = val_set_simval_obj(dstval, dstval->obj, buffer);
    return res;

  } /* alarma_fulgor_alarma_fulgor_state_horasis_get */

  /********************************************************************
  * FUNCTION alarma_fulgor_alarma_fulgor_state_minutosis_get
  * 
  * Get database object callback
  * Path: /alarma-fulgor-state/minutosis
  * Fill in 'dstval' contents
  * 
  * INPUTS:
  *     see ncx/getcb.h for details
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  static status_t alarma_fulgor_alarma_fulgor_state_minutosis_get (
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
  {
    

    if (LOGDEBUG) {
      log_debug("\nEnter alarma_fulgor_alarma_fulgor_state_minutosis_get callback");
    }


    status_t res;
    res = NO_ERR;
    
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time( &rawtime );
    info = localtime( &rawtime );
    strftime(buffer,80,"%M", info);
    res = val_set_simval_obj(dstval, dstval->obj, buffer);

  return res;

  } /* alarma_fulgor_alarma_fulgor_state_minutosis_get */

  /********************************************************************
  * FUNCTION alarma_fulgor_alarma_fulgor_state_segundosis_get
  * 
  * Get database object callback
  * Path: /alarma-fulgor-state/segundosis
  * Fill in 'dstval' contents
  * 
  * INPUTS:
  *     see ncx/getcb.h for details
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  static status_t alarma_fulgor_alarma_fulgor_state_segundosis_get (
    ses_cb_t *scb,
    getcb_mode_t cbmode,
    const val_value_t *virval,
    val_value_t *dstval)
  {
    if (LOGDEBUG) {
      log_debug("\nEnter alarma_fulgor_alarma_fulgor_state_segundosis_get callback");
    }


    status_t res;
    res = NO_ERR;
    
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time( &rawtime );
    info = localtime( &rawtime );
    strftime(buffer,80,"%S", info);
    res = val_set_simval_obj(dstval, dstval->obj, buffer);

    return res;

  } /* alarma_fulgor_alarma_fulgor_state_segundosis_get */

  //Warning: no get-CB generated for top-level operational container 'alarma-fulgor-state'

  /********************************************************************
  * FUNCTION alarma_fulgor_alarma_fulgor_state_mro
  * 
  * Make read-only top-level node
  * Path: /alarma-fulgor-state
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  static status_t
    alarma_fulgor_alarma_fulgor_state_mro (void)
  {
    val_value_t *parentval = NULL, *childval = NULL;
    status_t res = NO_ERR;


    /* add /alarma-fulgor-state */
    res = agt_add_top_container(alarma_fulgor_state_obj, &parentval);
    if (res != NO_ERR) {
      return res;
    }

    /* add /alarma-fulgor-state/horasis */
    childval = agt_make_virtual_leaf(
      parentval->obj,
      y_alarma_fulgor_N_horasis,
      alarma_fulgor_alarma_fulgor_state_horasis_get,
      &res);
    if (childval != NULL) {
      val_add_child(childval, parentval);
    } else {
      return res;
    }

    /* add /alarma-fulgor-state/minutosis */
    childval = agt_make_virtual_leaf(
      parentval->obj,
      y_alarma_fulgor_N_minutosis,
      alarma_fulgor_alarma_fulgor_state_minutosis_get,
      &res);
    if (childval != NULL) {
      val_add_child(childval, parentval);
    } else {
      return res;
    }

    /* add /alarma-fulgor-state/segundosis */
    childval = agt_make_virtual_leaf(
      parentval->obj,
      y_alarma_fulgor_N_segundosis,
      alarma_fulgor_alarma_fulgor_state_segundosis_get,
      &res);
    if (childval != NULL) {
      val_add_child(childval, parentval);
    } else {
      return res;
    }

    return res;

  } /* alarma_fulgor_alarma_fulgor_state_mro */


  /********************************************************************
  * FUNCTION y_alarma_fulgor_alarma_fulgor_activate_validate
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
  static status_t y_alarma_fulgor_alarma_fulgor_activate_validate (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
  {
    status_t res = NO_ERR;
    val_value_t *errorval = NULL;

    val_value_t *comando_val;
    const xmlChar *comando;

    comando_val = val_find_child(
      msg->rpc_input,
      y_alarma_fulgor_M_alarma_fulgor,
      y_alarma_fulgor_N_comando);
    if (comando_val != NULL && comando_val->res == NO_ERR) {
      comando = VAL_STRING(comando_val);
    }

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

  } /* y_alarma_fulgor_alarma_fulgor_activate_validate */



    static void *
oven_thread(void *arg)
{
    int rc;
    rc = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    unsigned int hora;
    unsigned int minuto;
    unsigned int segundo;
    while (alarma_tid) {
        time_t rawtime;
        struct tm *info;
        char buffer[80];
        time( &rawtime );
        info = localtime( &rawtime );
        strftime(buffer,80,"%x - %I:%M%p", info);
        hora=info->tm_hour;
        minuto=info->tm_min;
        segundo=info->tm_sec;
        if(hora==hora_alarma && minuto==minuto_alarma && segundo==segundo_alarma)
        {   
            y_alarma_fulgor_alarma_fulgor_sonido_send((const xmlChar *)"hola?");
            sleep(0.9);
            alarma_tid=0;
            return NULL; 
        }
        sleep(0.9);
    }
    return NULL;
}




  /********************************************************************
  * FUNCTION y_alarma_fulgor_alarma_fulgor_activate_invoke
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
  static status_t y_alarma_fulgor_alarma_fulgor_activate_invoke (
    ses_cb_t *scb,
    rpc_msg_t *msg,
    xml_node_t *methnode)
  {
    status_t res = NO_ERR;

    val_value_t *comando_val;
    const xmlChar *comando;

    comando_val = val_find_child(
      msg->rpc_input,
      y_alarma_fulgor_M_alarma_fulgor,
      y_alarma_fulgor_N_comando);
    if (comando_val != NULL && comando_val->res == NO_ERR) {
      comando = VAL_STRING(comando_val);
    }

    /* remove the next line if scb is used */
    (void)scb;

    /* remove the next line if methnode is used */
    (void)methnode;


    /* invoke your device instrumentation code here */


    if (xmlStrEqual(comando,(const xmlChar *)"activar")) {
      log_debug("\n******ALARMA ACTIVADA******");

      if (alarma_tid == 0) {
       
        pthread_create((pthread_t *)&alarma_tid, NULL, oven_thread, NULL);

        } 

    }
    
    return res;

  } /* y_alarma_fulgor_alarma_fulgor_activate_invoke */


  /********************************************************************
  * FUNCTION y_alarma_fulgor_alarma_fulgor_sonido_send
  * 
  * Send a y_alarma_fulgor_alarma_fulgor_sonido notification
  * Called by your code when notification event occurs
  * 
  ********************************************************************/
  void y_alarma_fulgor_alarma_fulgor_sonido_send (
    y_alarma_fulgor_T_alarma_fulgor_sonido_source *source)
  {
    agt_not_msg_t *notif;
    val_value_t *parmval;
    status_t res = NO_ERR;


    if (LOGDEBUG) {
      log_debug("\nGenerating <alarma-fulgor-sonido> notification");
    }
    
    notif = agt_not_new_notification(alarma_fulgor_sonido_obj);
    if (notif == NULL) {
      log_error("\nError: malloc failed, cannot send "
      "<alarma-fulgor-sonido> notification");
      return;
    }
    
    /* add container source to payload
     * replace following line with real code
     */
    (void)source;

    agt_not_queue_notification(notif);
    
  } /* y_alarma_fulgor_alarma_fulgor_sonido_send */

  /********************************************************************
  * FUNCTION y_alarma_fulgor_init
  * 
  * initialize the alarma-fulgor server instrumentation library
  * 
  * INPUTS:
  *    modname == requested module name
  *    revision == requested version (NULL for any)
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  status_t y_alarma_fulgor_init (
    const xmlChar *modname,
    const xmlChar *revision)
  {
    status_t res = NO_ERR;
    agt_profile_t *agt_profile = agt_get_profile();

    y_alarma_fulgor_init_static_vars();

    /* change if custom handling done */
    if (xml_strcmp(modname, y_alarma_fulgor_M_alarma_fulgor)) {
      return ERR_NCX_UNKNOWN_MODULE;
    }

    if (revision && xml_strcmp(revision, y_alarma_fulgor_R_alarma_fulgor)) {
      return ERR_NCX_WRONG_VERSION;
    }
    res = ncxmod_load_module(
      y_alarma_fulgor_M_alarma_fulgor,
      y_alarma_fulgor_R_alarma_fulgor,
      &agt_profile->agt_savedevQ,
      &alarma_fulgor_mod);
    if (res != NO_ERR) {
      return res;
    }

    alarma_fulgor_obj = ncx_find_object(
      alarma_fulgor_mod,
      y_alarma_fulgor_N_alarma_fulgor);
    if (alarma_fulgor_mod == NULL) {
      return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    alarma_fulgor_state_obj = ncx_find_object(
      alarma_fulgor_mod,
      y_alarma_fulgor_N_alarma_fulgor_state);
    if (alarma_fulgor_mod == NULL) {
      return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    alarma_fulgor_activate_obj = ncx_find_object(
      alarma_fulgor_mod,
      y_alarma_fulgor_N_alarma_fulgor_activate);
    if (alarma_fulgor_mod == NULL) {
      return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    alarma_fulgor_sonido_obj = ncx_find_object(
      alarma_fulgor_mod,
      y_alarma_fulgor_N_alarma_fulgor_sonido);
    if (alarma_fulgor_mod == NULL) {
      return SET_ERROR(ERR_NCX_DEF_NOT_FOUND);
    }
    res = agt_rpc_register_method(
      y_alarma_fulgor_M_alarma_fulgor,
      y_alarma_fulgor_N_alarma_fulgor_activate,
      AGT_RPC_PH_VALIDATE,
      y_alarma_fulgor_alarma_fulgor_activate_validate);
    if (res != NO_ERR) {
      return res;
    }

    res = agt_rpc_register_method(
      y_alarma_fulgor_M_alarma_fulgor,
      y_alarma_fulgor_N_alarma_fulgor_activate,
      AGT_RPC_PH_INVOKE,
      y_alarma_fulgor_alarma_fulgor_activate_invoke);
    if (res != NO_ERR) {
      return res;
    }

    res = agt_cb_register_callback(
      y_alarma_fulgor_M_alarma_fulgor,
      (const xmlChar *)"/alarma-fulgor",
      y_alarma_fulgor_R_alarma_fulgor,
      alarma_fulgor_alarma_fulgor_edit);
    if (res != NO_ERR) {
      return res;
    }

    res = agt_cb_register_callback(
      y_alarma_fulgor_M_alarma_fulgor,
      (const xmlChar *)"/alarma-fulgor/horas",
      y_alarma_fulgor_R_alarma_fulgor,
      alarma_fulgor_alarma_fulgor_horas_edit);
    if (res != NO_ERR) {
      return res;
    }

    res = agt_cb_register_callback(
      y_alarma_fulgor_M_alarma_fulgor,
      (const xmlChar *)"/alarma-fulgor/minutos",
      y_alarma_fulgor_R_alarma_fulgor,
      alarma_fulgor_alarma_fulgor_minutos_edit);
    if (res != NO_ERR) {
      return res;
    }

    res = agt_cb_register_callback(
      y_alarma_fulgor_M_alarma_fulgor,
      (const xmlChar *)"/alarma-fulgor/segundos",
      y_alarma_fulgor_R_alarma_fulgor,
      alarma_fulgor_alarma_fulgor_segundos_edit);
    if (res != NO_ERR) {
      return res;
    }

    res = agt_cb_register_callback(
      y_alarma_fulgor_M_alarma_fulgor,
      (const xmlChar *)"/alarma-fulgor/ringtone",
      y_alarma_fulgor_R_alarma_fulgor,
      alarma_fulgor_alarma_fulgor_ringtone_edit);
    if (res != NO_ERR) {
      return res;
    }

    /* put your module initialization code here */
    
    return res;
  } /* y_alarma_fulgor_init */

  /********************************************************************
  * FUNCTION y_alarma_fulgor_init2
  * 
  * SIL init phase 2: non-config data structures
  * Called after running config is loaded
  * 
  * RETURNS:
  *     error status
  ********************************************************************/
  status_t y_alarma_fulgor_init2 (void)
  {
    status_t res = NO_ERR;

    alarma_fulgor_val = agt_init_cache(
      y_alarma_fulgor_M_alarma_fulgor,
      y_alarma_fulgor_N_alarma_fulgor,
      &res);
    if (res != NO_ERR) {
      return res;
    }

    res = alarma_fulgor_alarma_fulgor_state_mro();
    if (res != NO_ERR) {
      return res;
    }

    /* put your init2 code here */

    return res;
  } /* y_alarma_fulgor_init2 */

  /********************************************************************
  * FUNCTION y_alarma_fulgor_cleanup
  *    cleanup the server instrumentation library
  * 
  ********************************************************************/
  void y_alarma_fulgor_cleanup (void)
  {
    
    agt_rpc_unregister_method(
      y_alarma_fulgor_M_alarma_fulgor,
      y_alarma_fulgor_N_alarma_fulgor_activate);
    agt_cb_unregister_callbacks(
      y_alarma_fulgor_M_alarma_fulgor,
      (const xmlChar *)"/alarma-fulgor");

    agt_cb_unregister_callbacks(
      y_alarma_fulgor_M_alarma_fulgor,
      (const xmlChar *)"/alarma-fulgor/horas");

    agt_cb_unregister_callbacks(
      y_alarma_fulgor_M_alarma_fulgor,
      (const xmlChar *)"/alarma-fulgor/minutos");

    agt_cb_unregister_callbacks(
      y_alarma_fulgor_M_alarma_fulgor,
      (const xmlChar *)"/alarma-fulgor/segundos");

    agt_cb_unregister_callbacks(
      y_alarma_fulgor_M_alarma_fulgor,
      (const xmlChar *)"/alarma-fulgor/ringtone");

    /* put your cleanup code here */
    
  } /* y_alarma_fulgor_cleanup */
