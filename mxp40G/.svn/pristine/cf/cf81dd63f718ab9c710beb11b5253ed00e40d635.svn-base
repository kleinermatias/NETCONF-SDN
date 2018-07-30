/***********************************************************************/
/* This file contains information proprietary to Cortina Systems, Inc. */
/* (Cortina). Any use or disclosure, in whole or in part, of this      */
/* information to any unauthorized party, for any purposes other than  */
/* that for which it is provided is expressly prohibited except as     */
/* authorized by Cortina in writing. Cortina reserves its rights to    */
/* pursue both civil and criminal penalties for copying or disclosure  */
/* of this material without authorization. Cortina Systems (R),        */
/* Cortina (TM) and the Cortina Systems Earth Logo are the trademarks  */
/* or registered trademarks of Cortina Systems, Inc. and its           */
/* subsidiaries in the U.S. and other countries. Any other product     */
/* and company names are the trademarks of their respective owners.    */
/* Copyright (C) 2006-2013 Cortina Systems, Inc. All rights reserved.  */
/***********************************************************************/
/*
 * ten_module.c
 * "Port" related code is implemented here.
 *
 * $Id: ten_module.c,v 1.9 2013/02/22 20:48:25 jccarlis Exp $
 *
 */

#include "tenabo40.h"

cs_status ten_mod_init_data(cs_uint16 module_id);

/***********************************************
 *  Initialize Port Hardware                   *
 ***********************************************/
cs_status ten_mod_init_hw(cs_uint16 module_id)
{
  cs_uint16 dev_id;
  ten_mod_cb_t *ppcb;

  CS_PRINT("ten_mod_init_hw\n");;

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);

  if (!ppcb) {
    return (CS_ERROR);
  }

  ppcb->state = TEN_MOD_STATE_HW_INIT_DONE;
  return (CS_OK);
}

/******************************************
 * restore port cb (used during warm start)
 ******************************************/
cs_status ten_port_restore_cb(cs_uint16 module_id)
{
  ten_mod_cb_t *ppcb;

  CS_PRINT("ten_port_restore_cb\n");;

  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  if (!ppcb)
  {
    return (CS_ERROR);
  }
  ppcb->state = TEN_MOD_STATE_HW_INIT_DONE;
  return (CS_OK);
}

/****************************************************************/
/* MODULE OPEN                                                  */
/* CATEGORY   : Module                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mod_open(cs_uint16 dev_id, cs_uint8 module_num)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/* OUTPUTS    : o Default Configuration                         */
/* RETURNS    : Module Id/Handle                                */
/* DESCRIPTION:                                                 */
/* This API, upon successful completion, will create a valid    */
/* module handle (aka mod_id).                                  */
/*                                                              */
/* The port_handle(or module_id) created by the driver should be*/
/* used in further invocations of the port-level APIs.          */
/*                                                              */
/* On successful assignment of the Port-Id, memory for the Port */
/* Control Block (PCB) will be dynamically allocated and        */
/* returned to the user.                                        */
/*                                                              */
/* This API is part of the low level initialization sequence    */  
/* that is automatically called when using the high level       */
/* function ten_mod_main_init.  It is exposed for those users   */ 
/* who want to customize the initialization process.            */
/*                                                              */
/****************************************************************/
{
  cs_uint32 err_code = 0;
  cs_uint16 module_id = TEN_INVALID_MODULE_ID;
  ten_mod_cb_t *ppcb;
  ten_dev_cb_t *pdcb;

  CS_PRINT("ten_mod_open\n");;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (TEN_INVALID_MODULE_ID);
  }
  pdcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  /* also check if the device has been initialized! */
  if (pdcb->state != TEN_DEV_STATE_INITIALIZED) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_NOT_INITED, NULL);
    return (TEN_INVALID_MODULE_ID);
  }

  if (module_num >= TEN_MAX_NUM_MODULES) {
    CS_PRINT("module-%d greater than %d\n", module_num, TEN_MAX_NUM_MODULES);
    return (TEN_INVALID_MODULE_ID);
  }

  if (pdcb->ppcb[module_num]) {
    /* This port is already in use */
    CS_PRINT("Dev-%d ERROR: module-%d already in use!\n", dev_id, module_num);
    return (TEN_INVALID_MODULE_ID);
  }

  /* Allocate memory for the Port control block for this device */
  ppcb = (ten_mod_cb_t *) CS_MALLOC(sizeof(ten_mod_cb_t));
  if (ppcb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_MALLOC_FAILED, NULL);
    return (TEN_INVALID_MODULE_ID);
  }
  pdcb->ppcb[module_num] = ppcb;
  module_id = ((dev_id << 8) | module_num);

  /* Clear memory for the Port Control Block */
  CS_MEMSET((void *)ppcb, 0, sizeof(ten_mod_cb_t));

  /* copy some essential info into the port cb */
  ppcb->mod_id = module_id;
  ppcb->state = TEN_MOD_STATE_OPENED;

  CS_PRINT("module-id (module handle) = 0x%04X successfully opened\n", module_id);
  return (module_id);
}

/****************************************************************/
/* $rtn_hdr_start  MODULE CLOSE                                 */
/* CATEGORY   : Module                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_mod_close(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This API deletes the module instance specified. It frees up  */
/* all the data-structures that were dynamically allocated.     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 err_code = 0;
  ten_mod_cb_t *ppcb;
  ten_dev_cb_t *pdcb;
  cs_uint16 dev_id;
  cs_uint8 mod_num;

  CS_PRINT("ten_mod_close\n");;

  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_HNDL_ERROR(module_id, err_code, NULL);
    return (CS_ERROR);
  }

  pdcb = TEN_MOD_ID_TO_DEVCB_PTR(module_id);
  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);

  /* shut down the slice upon port close */
  /* drop the corresponding api chan as well */
  mod_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);

  ten_stats_clean_all(module_id, TEN_MOD);

  /* Destroy port semaphores          */
  CS_SEM_DESTROY(&ppcb->sem_syncdsync);
  CS_SEM_DESTROY(&ppcb->sem_spoh);
  CS_SEM_DESTROY(&ppcb->sem_hsif);
  CS_SEM_DESTROY(&ppcb->sem_xfi32x1);
  CS_SEM_DESTROY(&ppcb->sem_n40g);
  CS_SEM_DESTROY(&ppcb->sem_ohpp);
  CS_SEM_DESTROY(&ppcb->sem_n10g);
  CS_SEM_DESTROY(&ppcb->sem_pp10g);
  CS_SEM_DESTROY(&ppcb->sem_gfec10g);
  CS_SEM_DESTROY(&ppcb->sem_gfec40g);
  CS_SEM_DESTROY(&ppcb->sem_ufec);
  CS_SEM_DESTROY(&ppcb->sem_pp40g);
  CS_SEM_DESTROY(&ppcb->sem_cfp32x1);

  if (!pdcb) {
    CS_HNDL_ERROR(module_id, err_code, NULL);
    return (CS_ERROR);
  }

  /* Finally, delete the module_id and de-allocate the Port PCB */
  if (mod_num == TEN_MODULE_A) {
    CS_FREE(pdcb->ppcb[TEN_MODULE_A]);
    pdcb->ppcb[TEN_MODULE_A] = NULL;
  }
  else {
    CS_FREE(pdcb->ppcb[TEN_MODULE_B]);
    pdcb->ppcb[TEN_MODULE_B] = NULL;
  }  

  CS_PRINT("module id 0x%04X closed.\n", module_id);
  return (CS_OK);
}

/****************************************************************/
/* CATEGORY   : Module                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_mod_init(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This initializes the specified port hardware and software    */
/* data structures with the given configuration.                */
/*                                                              */
/* The [module_id] is an unique value in the system and         */
/* this is the driver created port-handle when the port was     */
/* opened.                                                      */
/*                                                              */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint32 err_code = 0;

  CS_PRINT("ten_mod_init\n");;

  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_HNDL_ERROR(module_id, err_code, NULL);
    return (CS_ERROR);
  }

  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);

  if (ten_mod_init_data(module_id) != CS_OK) {
    return (CS_ERROR);
  }

  /* Load the Statistics Tables */
  if (ten_mod_init_syncdsync_stats(module_id) != CS_OK) {
    return (CS_ERROR);
  }
  
  if (ten_mod_init_hsif_stats(module_id) != CS_OK) {
    return (CS_ERROR);
  }
  
  if (ten_mod_init_gfec_40g_stats(module_id) != CS_OK) {
    return (CS_ERROR);
  }
 
  if (ten_mod_init_gfec_10g_stats(module_id) != CS_OK) {
    return (CS_ERROR);
  }
  
  if (ten_mod_init_ufec_stats(module_id) != CS_OK) {
    return (CS_ERROR);
  }
 
  if (ten_mod_init_n40g_stats(module_id) != CS_OK) {
    return (CS_ERROR);
  }

  if (ten_mod_init_n10g_stats(module_id) != CS_OK) {
    return (CS_ERROR);
  }
  
  if (ten_mod_init_pp10g_stats(module_id) != CS_OK) {
    return (CS_ERROR);
  }
  
  /* If T41 register PP40G blocks */
  if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    if (ten_mod_init_pp40g_stats(module_id) != CS_OK) {
      return (CS_ERROR);
    }
  /* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
  }
  
  if ((!ten_dev_is_ws_in_progress(dev_id)) || (ten_dev_is_ws_method_default(dev_id))) {
    /* Not in Warm Start or Warm Start Top Down (Provision chip with parameters memory) */
    if (ten_mod_init_hw(module_id) != CS_OK) {
      return (CS_ERROR);
    }
  }
  else {
    /* Restore Port Control Block from Configuration structure */
    if (ten_port_restore_cb(module_id) != CS_OK) {
      return (CS_ERROR);
    }
  }
  
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PRINT MODULE CONFIGURATION                   */
/* CATEGORY   : Module                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_mod_print_cfg(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Retrieves and prints the current run-time hardware           */
/* configuration for the specified modules.                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 err_code = 0;
  cs_status status = CS_OK;

  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_HNDL_ERROR(module_id, err_code, NULL);
    return (CS_ERROR);
  }

  cs_bar();
  CS_PRINT_OUTPUT("Tenabo Module Configuration\n");
  cs_bar();
  CS_PRINT_OUTPUT("module id          = 0x%04X\n", module_id);
  CS_PRINT_OUTPUT("warm start         = %s\n",
           (ten_dev_is_ws_in_progress(TEN_MOD_ID_TO_DEV_ID(module_id)) ?
            "in progress" : "not active"));
  cs_bar();
  return (status);
}

/****************************************************************/
/* $rtn_hdr_start  PRINT MODULE STATUS                          */
/* CATEGORY   : Module                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_mod_print_status(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Retrieves and prints the current status.                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 devId;
  cs_uint8 portNum;
  cs_uint32 err_code = 0;
  cs_status status = CS_OK;

  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_HNDL_ERROR(module_id, err_code, NULL);
    return (CS_ERROR);
  }

  devId = TEN_MOD_ID_TO_DEV_ID(module_id);
  portNum = TEN_MOD_ID_TO_MOD_NUM(module_id);

  cs_bar();
  CS_PRINT_OUTPUT("Tenabo Module Status\n");
  cs_bar();

  CS_PRINT_OUTPUT("module id = 0x%X\n", module_id);
  cs_bar();
  return (status);
}

/*****************************************************************
 *  INTERNAL FUNCTIONS AND UTILITIES                             *
 *****************************************************************/

/************************************************
 * Initialize Port Data-structures              *
 * This is called from port initialization code *
 * after the port has been opened. The port CB  *
 * has already been allocated when the port was *
 * opened and this function just initializes it.*
 ************************************************/
cs_status ten_mod_init_data(cs_uint16 module_id)
{
  ten_mod_cb_t *ppcb;

  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  if (!ppcb) {
    return (CS_ERROR);
  }

  /* Initialize the port semaphores */
  if (CS_SEM_INIT(&ppcb->sem_syncdsync) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_SEM_INIT_FAILED, "for SEM SYNCDSYNCTX\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&ppcb->sem_spoh) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_SEM_INIT_FAILED, "for SEM SPOH\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&ppcb->sem_hsif) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_SEM_INIT_FAILED, "for SEM HSIF\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&ppcb->sem_xfi32x1) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_SEM_INIT_FAILED, "for SEM XFI32X1\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&ppcb->sem_n40g) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_SEM_INIT_FAILED, "for SEM N40G\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&ppcb->sem_ohpp) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_SEM_INIT_FAILED, "for SEM OHPP\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&ppcb->sem_n10g) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_SEM_INIT_FAILED, "for SEM N10G\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&ppcb->sem_pp10g) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_SEM_INIT_FAILED, "for SEM PP10G\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&ppcb->sem_gfec10g) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_SEM_INIT_FAILED, "for GFEC10G\n");
    return (CS_ERROR);
  }
  
  if (CS_SEM_INIT(&ppcb->sem_gfec40g) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_SEM_INIT_FAILED, "for GFEC40G\n");
    return (CS_ERROR);
  }
  
  if (CS_SEM_INIT(&ppcb->sem_ufec) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_SEM_INIT_FAILED, "for UFEC\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&ppcb->sem_pp40g) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_SEM_INIT_FAILED, "for PP40G\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&ppcb->sem_cfp32x1) != CS_OK) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_SEM_INIT_FAILED, "for CFP32X1\n");
    return (CS_ERROR);
  }

  ppcb->state = TEN_MOD_STATE_DATA_INIT_DONE;
  return (CS_OK);
}

/*****************************************
 * Check for warm start status
 *****************************************/
cs_boolean ten_port_is_ws_in_progress(cs_uint16 module_id)
{
  ten_ws_cb_t *pwsc;
  cs_uint32 err_code = 0;

  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_HNDL_ERROR(module_id, err_code, NULL);
    return (FALSE);
  }
  pwsc = &(g_pTEN->ws_ctl);
  return (pwsc->enbl);
}

/*****************************************
 * CHECK FOR VALID module_id.
 *****************************************/
cs_boolean TEN_IS_MOD_VALID(cs_uint16 module_id, cs_uint32 * perr_code)
{
  cs_uint8 module_num = TEN_MOD_ID_TO_MOD_NUM(module_id);
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  ten_mod_cb_t *ppcb;

  /* verify that device is valid before checking for port validity */
  if (!(TEN_IS_DEVICE_VALID(dev_id, perr_code))) {
    *perr_code = ETEN_MOD_INVALID_USER_ARG;
    return (FALSE);
  }
  if (module_num >= TEN_MAX_NUM_MODULES) {
    *perr_code = ETEN_MOD_ID_OUT_OF_RANGE;
    return (FALSE);
  }

  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  if ((ppcb == NULL) || (ppcb->state == TEN_MOD_STATE_INVALID)) {
    *perr_code = ETEN_MOD_NOT_OPEN;
    return (FALSE);
  }

  return (TRUE);
}

/*****************************************
 * ten_get_port_sem_ptr
 *****************************************/
CS_SEM *ten_get_port_sem_ptr(cs_uint16 module_id, ten_block_id_t blk_id)
{
  ten_mod_cb_t *p = TEN_MOD_ID_TO_PCB_PTR(module_id);
  
  if (!p) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "Null Pointer.\n");
    return (NULL);   
  }    
  
  switch (blk_id) {
    case TEN_ID_SYNCDSYNC:
      return (&p->sem_syncdsync);
    case TEN_ID_SPOH:
      return (&p->sem_spoh);
    case TEN_ID_HSIF:
      return (&p->sem_hsif);
    case TEN_ID_XFI32X1:
      return (&p->sem_xfi32x1);
    /* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
    case TEN_ID_CFP32X1:
      return (&p->sem_cfp32x1);
    case TEN_ID_N40G:
      return (&p->sem_n40g);
    case TEN_ID_OHPP:
      return (&p->sem_ohpp);
    case TEN_ID_N10G:
      return (&p->sem_n10g);
    case TEN_ID_PP10G:
      return (&p->sem_pp10g);
    case TEN_ID_PP40G:
      return (&p->sem_pp40g);
    case TEN_ID_GFEC_10G:
      return (&p->sem_gfec10g);
    case TEN_ID_GFEC_40G:
      return (&p->sem_gfec40g);
    case TEN_ID_UFEC:
      return (&p->sem_ufec);
    default:
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "invalid block id %d\n", blk_id);
      return (NULL);              /* error */
  }
}

/*****************************************
 * TEN_MOD_ID_TO_PCB_PTR
 *****************************************/
ten_mod_cb_t *TEN_MOD_ID_TO_PCB_PTR(cs_uint16 module_id)
{
   cs_uint8 temp_port_num;
   ten_dev_cb_t *temp_dev_cb_ptr;

   temp_port_num = TEN_MOD_ID_TO_MOD_NUM(module_id);

   if (temp_port_num < TEN_MAX_NUM_MODULES) {
      temp_dev_cb_ptr = TEN_MOD_ID_TO_DEVCB_PTR(module_id);
      if (temp_dev_cb_ptr) {
        return (temp_dev_cb_ptr->ppcb[temp_port_num]);
     }
     else {
       return (0);
     }
   }
   else {
     return (0);
   }
}



