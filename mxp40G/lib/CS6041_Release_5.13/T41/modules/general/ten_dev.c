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
 * ten_dev.c
 * "Device" related code is implemented here.
 *
 * $Id: ten_dev.c,v 1.36 2014/04/02 19:50:53 jccarlis Exp $
 *
 */

#include "tenabo40.h"


/****************************************************************/
/* For MPIF-based high-res timer function (Bugzilla 30990)      */
/****************************************************************/
/* Local global, dev_id of device assigned for MPIF timer.      */
static cs_uint8 ten_dev_udelay_hi_res_dev_id = 0xFF;
/* Public non-API function prototype.                           */
cs_status ten_dev_udelay_hi_res(cs_uint32 usecs);


/****************************************************************/
/* $rtn_hdr_start  DEVICE ADDRESS REGISTRATION                  */
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_register(cs_uint16 dev_id, cs_uint32 base_addr)
/* INPUTS     : o Device Id                                     */
/*              o Base address of the ASIC                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Registers the given address as the base address for the      */
/* specified device. This address will be used in computing     */
/* the actual address of a register within the chip, ie.        */
/* (base_addr + offset), and used in the TEN_REG_READ() and     */
/* TEN_REG_WRITE() macros for register access.                  */
/*                                                              */
/* If this base address is not the physical address (as seen    */
/* by the CPU), then the register access macro's can be         */
/* customized to map it accordingly.                            */
/*                                                              */
/* This API should be called only after the driver has been     */
/* loaded.                                                      */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t **p_pdevcb = NULL;
  ten_dev_cb_t *pdevcb = NULL;

  CS_PRINT("ten_dev_register\n");;
  if (!(TEN_DRVR_IS_LOADED())) {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_NOT_LOADED, NULL);
    return (CS_ERROR);
  }

  if (dev_id >= TEN_MAX_NUM_DEVICES) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_ID_OUT_OF_RANGE, NULL);
    return (CS_ERROR);
  }
  /* Pointer to Device Control Block pointer in the Driver's Control Block */
  p_pdevcb = &(g_pTEN->p_dev_cb_tbl[dev_id]);
  pdevcb = *p_pdevcb;           /* Pointer to the Device's control Block */
  if (pdevcb) {
    /* Device was already registered - unregister first */
    if (ten_dev_unregister(dev_id) != CS_OK) {
      return (CS_ERROR);
    }
  }

  /* Allocate memory for Device's Control Block */
  pdevcb = (ten_dev_cb_t *) CS_MALLOC(sizeof(ten_dev_cb_t));
  if (pdevcb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_MALLOC_FAILED, NULL);
    return (CS_ERROR);
  }

  /* Save pointer to Device Control Block in Driver's Control Block */
  *p_pdevcb = pdevcb;
  CS_MEMSET((void *)pdevcb, 0, sizeof(ten_dev_cb_t));
  pdevcb->state = TEN_DEV_STATE_INVALID;

  /* Register hardware block's semaphores */
  if (CS_SEM_INIT(&pdevcb->sem_mpif) != CS_OK) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_SEM_INIT_FAILED, "for MPIF\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&pdevcb->sem_glb) != CS_OK) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_SEM_INIT_FAILED, "for GLB\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&pdevcb->sem_xcon) != CS_OK) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_SEM_INIT_FAILED, "for XCON\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&pdevcb->sem_fracdiv) != CS_OK) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_SEM_INIT_FAILED, "for FRACDIV\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&pdevcb->sem_gpllx1) != CS_OK) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_SEM_INIT_FAILED, "for GPLLX1\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&pdevcb->sem_irq) != CS_OK) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_SEM_INIT_FAILED, "for IRQ\n");
    return (CS_ERROR);
  }

  if (CS_SEM_INIT(&pdevcb->sem_pdcal) != CS_OK) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_SEM_INIT_FAILED, "for PDCAL\n");
    return (CS_ERROR);
  }
  
  if (CS_SEM_INIT(&pdevcb->sem_dm) != CS_OK) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_SEM_INIT_FAILED, "for DM\n");
    return (CS_ERROR);
  }
  
  if (CS_SEM_INIT(&pdevcb->sem_syncdsync_cb) != CS_OK) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_SEM_INIT_FAILED, "for SYNCDSYNC CONTROL BLOCK\n");
    return (CS_ERROR);
  }
  pdevcb->dev_id = dev_id;
  pdevcb->base_addr = base_addr;
  pdevcb->debug_flag = (cs_uint32) - 1;
  
  /* Bug #42896 - Remove debug message from API "ten_dev_register" */

  g_pTEN->debug_base_address = base_addr;

#ifndef RELEASE_PLATFORM
  cs_lab_dev_register(CS_CHIP_T41, (cs_uint16) dev_id, base_addr);
#endif

  /* Finally, update the state of the device */
  pdevcb->state = TEN_DEV_STATE_REGISTERED;
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start UNREGISTER DEVICE                             */
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_unregister(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Unregisters the device, by setting its state to init state.  */
/* All module and device APIs related to this device should NOT */
/* be called after this.                                        */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 ii;
  ten_dev_cb_t *pdevcb;
  ten_dev_cb_t **p_pdevcb;
  cs_uint32 err_code = 0;

  CS_PRINT("ten_dev_unregister\n");;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, ":dev_id(%d)\n", dev_id);
    return (CS_ERROR);
  }

  /* Pointer to Device Control Block pointer in the Driver's Control Block */
  p_pdevcb = &(g_pTEN->p_dev_cb_tbl[dev_id]);
  /* Pointer to the Device's control Block */
  pdevcb = *p_pdevcb;

  /* need to check if this device is registered */
  if (pdevcb == NULL)
    return (CS_OK);

  for (ii = 0; ii < TEN_MAX_NUM_MODULES; ii++) {
    if (pdevcb->ppcb[ii]) {
      ten_mod_close((dev_id << 8) | ii);
    }
  }

  ten_stats_clean_all(dev_id, TEN_DEVICE);

  CS_SEM_DESTROY(&pdevcb->sem_mpif);
  CS_SEM_DESTROY(&pdevcb->sem_glb);
  CS_SEM_DESTROY(&pdevcb->sem_xcon);
  CS_SEM_DESTROY(&pdevcb->sem_fracdiv);
  CS_SEM_DESTROY(&pdevcb->sem_gpllx1);
  CS_SEM_DESTROY(&pdevcb->sem_irq);
  CS_SEM_DESTROY(&pdevcb->sem_syncdsync_cb);
  CS_SEM_DESTROY(&pdevcb->sem_pdcal);
  CS_SEM_DESTROY(&pdevcb->sem_dm);

  CS_FREE(pdevcb);
  *p_pdevcb = NULL;

  CS_PRINT("T41 device (%d) unregistered!\n", dev_id);

#ifndef RELEASE_PLATFORM
  cs_lab_dev_unregister(CS_CHIP_T41, (cs_uint16) dev_id);
#endif

  return (CS_OK);
}

/****************************************************************/
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_init(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Initializes the device state to ready after verifying the    */
/* JTAG Id of the chip and hard-resetting and configuring any   */
/* HW blocks that are common and shared by all the ports.       */
/*                                                              */
/* It does NOT do any port related initialization.              */
/*                                                              */
/* This API should be called only after the device corresponding*/
/* to this module has been registered.                          */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint32 ii;
  cs_uint32 err_code = 0;

  CS_PRINT("ten_dev_init\n");;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (CS_ERROR);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb == NULL) {
    CS_PRINT("T41 dev-%d, ERROR: pdevcb is NULL\n", dev_id);
    return (CS_ERROR);
  }

  if (pdevcb->state == TEN_DEV_STATE_INVALID) { /* @TODO: Would this be safer if checking for an explicit value? */
    CS_PRINT("T41 dev-%d, ERROR: Device not registered\n", dev_id);
    return (CS_ERROR);
  }

  if (pdevcb->state == TEN_DEV_STATE_INITIALIZED) {
    /* This device has already been initialized, so start it over again */
    cs_uint32 base_addr = pdevcb->base_addr;

    /* re-init'ing the device - do unreg/reg device again */
    if (ten_dev_unregister(dev_id) != CS_OK) return (CS_ERROR);
    if (ten_dev_register(dev_id, base_addr) != CS_OK) return (CS_ERROR);

    /* Need to re-get the pointer because previous structure has been rebuilt */
    pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  }

  /*****************************************
   *   Initialize device data structures   *
   *****************************************/
  for (ii = 0; ii < TEN_MAX_NUM_MODULES; ii++) {
    /* Set Module Control Block pointer */
    pdevcb->ppcb[ii] = NULL;
  }

  if ((!ten_dev_is_ws_in_progress(dev_id)) || (ten_dev_is_ws_method_default(dev_id))) {
    /* Not in Warm Start or Warm Start Top Down (Provision chip with configuration structure) */
    if (ten_dev_init_hw(dev_id) != CS_OK) {
      return (CS_ERROR);
    }
  }
  else {
    /* Warm Start with Bottom-Up method.  Read chip to create configuration structure*/
    /* Restore Device Control Block from Configuration structure */
    if (ten_dev_restore_cb(dev_id) != CS_OK) {
      return (CS_ERROR);
    }
  }

  CS_PRINT("T41 dev-%d initialized:  base addr = 0x%X\n", dev_id, pdevcb->base_addr);

  #ifndef RELEASE_PLATFORM
  cs_lab_dev_init(CS_CHIP_T41, (cs_uint16) dev_id);
  #endif

  pdevcb->state = TEN_DEV_STATE_INITIALIZED;
  
  /* Bugilla #26434, bus error checking control */
  /* Bug #40123 - Fix bus error logging APIs to work on per device basis */
  g_pTEN->ten_bus_error_count[dev_id] = 0; 
  #ifdef TEN_CHECK_FOR_BUS_ERRORS
  g_pTEN->ten_bus_error_ctl[dev_id] = CS_ENABLE;
  #else
  g_pTEN->ten_bus_error_ctl[dev_id] = CS_DISABLE;
  #endif

  /* Bugzilla 30990, Release 5.5, select device for hi-res timer function. */
  if (   (ten_dev_udelay_hi_res_dev_id > TEN_MAX_NUM_DEVICES) /*           */
      && (ten_dev_is_t41_ptr(pdevcb)) ) {                     /*           */
    /* would be a good place to call ten_mpif_init_access_     *           */
    /* times() but we don't know sysclk freq yet               *           */
    ten_dev_udelay_hi_res_dev_id = dev_id;                    /*           */
  }                                                           /*           */
  /* End  Bugzilla 30990                                       *           */


  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  FORCE CHIP TYPE TO T40 OR T41                */
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_override_chiptype(cs_uint16 dev_id, cs_uint16 chip)
/* INPUTS     : o Device Id                                     */
/*              o Chip                                          */
/*                TEN_CHIP_OVERRIDE_T40 fakes T40               */
/*                TEN_CHIP_OVERRIDE_T41 fakes T41               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets overload bits in dev_db.chip_type to forced chip type,  */
/* preserves value read from the chip. Must not be called       */
/* before ten_dev_init()                                        */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 err_code = 0;
  ten_dev_cb_t *pDev = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (CS_ERROR);
  }
  else if ( (chip==TEN_CHIP_OVERRIDE_T40) || (chip==TEN_CHIP_OVERRIDE_T41) || (chip==TEN_CHIP_OVERRIDE_DEF) ) {
    pDev  = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
    pDev->chip_type = (pDev->chip_type & TEN_CHIP_OVERRIDE_MASK) | chip;
    return (CS_OK);
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "Bad chip type. Use <TEN_CHIP_OVERRIDE_T40 | TEN_CHIP_OVERRIDE_T41 | TEN_CHIP_OVERRIDE_DEF>");
    return (CS_ERROR);
  }
}


/****************************************************************/
/* $rtn_hdr_start  PRINT DEVICE CONFIGURATION                   */
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_print_cfg(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Retrieves and prints the current run-time hardware           */
/* configuration for the specified device.                      */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (CS_ERROR);
  }

  cs_bar();
  CS_PRINT_OUTPUT("T41 Device Configuration\n");
  cs_bar();
  CS_PRINT_OUTPUT("dev id      = %02d\n", dev_id);
  CS_PRINT_OUTPUT("warm start  = %s\n",
           (ten_dev_is_ws_in_progress(dev_id) ? "in progress" : "not active"));
  cs_bar();

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PRINT DEVICE STATUS                          */
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_print_status(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Retrieves and prints the current status.                     */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint32 err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (CS_ERROR);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb->state != TEN_DEV_STATE_INITIALIZED) {     /* hwcfg not done */
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": device hw cfg not done yet!\n");
    return (CS_ERROR);
  }

  cs_bar();
  CS_PRINT_OUTPUT("T41 Device Status\n");
  cs_bar();
  CS_PRINT_OUTPUT("dev id = %d\n", dev_id);
  cs_bar();

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start   START WARM START OPERATION                  */
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_start_ws(cs_uint16 dev_id, ten_ws_method_t method)
/* INPUTS     : o Device Id                                     */
/*              o Warm Start Method                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Start warm start operation.                                  */
/*                                                              */
/* While warm start is active, destructive hardware access will */
/* be avoided as long as no change in configuration.            */
/* As a result, traffic is not impacted.                        */
/* After activating warm start, the application software        */
/* should call the initialization sequence normally as it would */
/* for cold start.                                              */
/* It is SW's responsibility to save the driver statistics and  */
/* restore it after warm start.                                 */
/*                                                              */
/* [method] :                                                   */
/*   TEN_WS_METHOD_TOP_DOWN or TEN_WS_METHOD_BOTTOM_UP          */
/*                                                              */
/*   TEN_WS_METHOD_TOP_DOWN is the default and preferred method */
/*   in warm start operation.  Upper layer software needs to    */
/*   prepare configuration from its persistent database and     */
/*   initialize the device.                                     */
/*                                                              */
/*   TEN_WS_METHOD_BOTTOM_UP is intended for debug or lab use.  */
/*   Driver tries to recover the configuration based on current */
/*   running hardware.  At the end of init call, the            */
/*   configuration datastructure will contain recovered         */
/*   configuration.                                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_ws_cb_t *pwsc;
  cs_uint32 err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (CS_ERROR);
  }

  pwsc = &(g_pTEN->ws_ctl);

  pwsc->enbl = TRUE;
  pwsc->method = method;
  CS_PRINT_OUTPUT("\n*****************************\n");
  CS_PRINT_OUTPUT("Started warm-start operation\n");
  CS_PRINT_OUTPUT("****************************\n\n");

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start   STOP WARM START OPERATION                   */
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_stop_ws(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* STOP warm start operation.                                   */
/*                                                              */
/* While warm start is active, destructive hardware access will */
/* be avoided as long as no change in configuration.            */
/* As a result, traffic is not impacted.                        */
/* After activating warm start, the application software        */
/* should call the initialization sequence normally as it would */
/* for cold start.                                              */
/* It is SW's responsibility to save the driver statistics and  */
/* restore it after warm start.                                 */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_ws_cb_t *pwsc;
  cs_uint32 err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (CS_ERROR);
  }

  pwsc = &(g_pTEN->ws_ctl);

  pwsc->enbl = FALSE;
  CS_PRINT_OUTPUT("\n ***************************\n");
  CS_PRINT_OUTPUT("Warm-start operation stopped\n");
  CS_PRINT_OUTPUT("****************************\n\n");

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start   IS WARM START IN PROGRESS                   */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_boolean ten_dev_is_ws_in_progress(cs_uint16 dev_id)
/* INPUTS     :                                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Check if Warm Start is active currently.                     */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_ws_cb_t *pwsc;
  cs_uint32 err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (FALSE);
  }

  pwsc = &(g_pTEN->ws_ctl);

  return (pwsc->enbl);
}

/****************************************************************/
/* $rtn_hdr_start   IS T41 PRESENT                              */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_boolean ten_dev_is_t41(cs_uint16 dev_id)
/* INPUTS     :                                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE (Device is T41) or FALSE (Device is T40)   */
/* DESCRIPTION:                                                 */
/* Check if T41 is active currently.                            */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 err_code = 0;

  /* Bugzilla #25991, fix static analyzer tool issues */

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (FALSE);
  }
  else {
    /* Bugzilla 24980 -- This will be reverted back once chip arrives */
    return (ten_dev_is_t41_ptr(TEN_DEV_ID_TO_DEVCB_PTR(dev_id)));  /* NOTE-ptr arg checked by called function */
  }
}



/***********************************************************
 *        INTERNAL UTILITIES AND FUNCTIONS                 *
 ***********************************************************/

/*****************************************
 *   Initialize device hardware          *
 * All common sections of the chip that  *
 * are shared by all the ports will be   *
 * initialized.                          *
 *****************************************/
cs_status ten_dev_init_hw(cs_uint16 dev_id)
{
  cs_uint32 jtag_id;
  TEN_MPIF_CHIP_ID_LSB_t tmp_chip_id_lsb;
  TEN_MPIF_CHIP_ID_MSB_t tmp_chip_id_msb;
  ten_dev_cb_t *pdevcb;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  tmp_chip_id_lsb.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_LSB));
  tmp_chip_id_msb.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_MSB));

  
  jtag_id = (tmp_chip_id_msb.wrd << 16) | tmp_chip_id_lsb.wrd;

  /* this driver is valid for T40 and T41. SKU and revsion bitfields not checked */ /* Bugzilla 26156, identify T41 */
  if (((jtag_id & TEN_CHIP_ID_MASK)==(TEN_CHIP_ID_CS6041 & TEN_CHIP_ID_MASK) ) ||
      ((jtag_id & TEN_CHIP_ID_MASK)==(TEN_CHIP_ID_CS6001 & TEN_CHIP_ID_MASK) )   ) {
    CS_PRINT("Chip JTAG ID = 0x%08X match.\n", jtag_id);
  }
  else {
    /* Chips JTAG ID is incorrect */
    CS_HNDL_ERROR(dev_id, ETEN_DEV_CHIP_JTAG_ID_MISMATCH, ": Chip's JTAG ID = 0x%08X, masked 0x%08X, expected 0x%08X\n",
                  jtag_id, (jtag_id & TEN_CHIP_ID_MASK), (TEN_CHIP_ID_CS6041 & TEN_CHIP_ID_MASK));
    return (CS_ERROR);
  }


  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb == NULL) {
    CS_PRINT("Tenabo dev-%d, ERROR: pdevcb is NULL\n", dev_id);
    return (CS_ERROR);
  }

 /* For driver compatibility with T40 and T41 */ /* Bugzilla 26156, identify T41 */
  if ( (jtag_id & TEN_CHIP_ID_MASK)==(TEN_CHIP_ID_CS6041 & TEN_CHIP_ID_MASK) ) {
        CS_PRINT("T41 Identified\n");
        pdevcb->chip_type = TEN_CHIP_T41;
  }
  else {
        CS_PRINT("T40 Identified\n");
        pdevcb->chip_type = TEN_CHIP_T40;
  }

  /* Load the Statistics Tables */
  if (ten_dev_init_xcon_stats(dev_id) != CS_OK) {
    return (CS_ERROR);
  }
/* Bugzilla 26512, cfp stats moved to module stats in the hsif block */

/* Bugzilla 24339 Start */
/* Initialize fec control block */
  if (ten_dev_init_fec_cb (dev_id) != CS_OK) {
    return (CS_ERROR);
  }
/* Bugzilla 24339 End */

/* Bugzilla 27270 Start, Amplitude Recentering */
/* Initialize xcon es control block */
  if (ten_dev_init_xcon_es_cb (dev_id) != CS_OK) {
    return (CS_ERROR);
  }
/* Bugzilla 27270 End */

  return (CS_OK);
}

/************************************************************
 * restore dev cb (used only in bottom-up during warm start)
 ************************************************************/
cs_status ten_dev_restore_cb(cs_uint16 dev_id)
{
  cs_uint32 jtag_id;
  ten_dev_cb_t *pdevcb;
  TEN_MPIF_CHIP_ID_LSB_t tmp_chip_id_lsb;
  TEN_MPIF_CHIP_ID_MSB_t tmp_chip_id_msb;
  T41_t *pDev = NULL;

  CS_PRINT("ten_dev_restore_cb\n");

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_chip_id_lsb.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_LSB));
  tmp_chip_id_msb.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_MSB));
  jtag_id = (tmp_chip_id_msb.wrd << 16) | tmp_chip_id_lsb.wrd;

  /* this driver is valid for T40 and T41. SKU and revsion bitfields not checked */ /* Bugzilla 26156, identify T41 */
  if (((jtag_id & TEN_CHIP_ID_MASK)==(TEN_CHIP_ID_CS6041 & TEN_CHIP_ID_MASK) ) ||
      ((jtag_id & TEN_CHIP_ID_MASK)==(TEN_CHIP_ID_CS6001 & TEN_CHIP_ID_MASK) )   ) {
    CS_PRINT("Chip JTAG ID = 0x%08X match.\n", jtag_id);
  }
  else {
    /* Chips JTAG ID is incorrect */
    CS_HNDL_ERROR(dev_id, ETEN_DEV_CHIP_JTAG_ID_MISMATCH, ": Chip's JTAG ID = 0x%08X\n",
               jtag_id);
    return (CS_ERROR);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  if (!pdevcb) {
     return (CS_ERROR);
  }
  return (CS_OK);
}

/******************************************************************
 * Check for Warm Start method is the default TOP_DOWN or not
 ******************************************************************/
cs_boolean ten_dev_is_ws_method_default(cs_uint16 dev_id)
{
  ten_ws_cb_t *pwsc;
  cs_uint32 err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (TRUE);
  }

  pwsc = &(g_pTEN->ws_ctl);

  return ((cs_boolean) (pwsc->method == TEN_WS_METHOD_TOP_DOWN));
}

/*****************************************
 * Print Dev Header
 *****************************************/
void ten_dev_print_header(cs_uint16 dev_id, const cs_char8 *str)
{
  CS_PRINT_OUTPUT("\n");
  CS_PRINT_OUTPUT("*************************************\n");
  CS_PRINT_OUTPUT("* DEVICE-%02d  %s\n", dev_id, str);
  CS_PRINT_OUTPUT("*************************************\n");
}

/*****************************************
 * CHECK FOR VALID DEVICE
 * In the code, use the macro below.
 *****************************************/
cs_boolean TEN_IS_DEVICE_VALID(cs_uint16 dev_id, cs_uint32 * perr_code)
{
  ten_dev_cb_t *pdevcb;

  if (!(TEN_DRVR_IS_LOADED())) {
    *perr_code = ETEN_DRVR_NOT_LOADED;
    return (FALSE);
  }

  if (dev_id >= TEN_MAX_NUM_DEVICES) {
    *perr_code = ETEN_DEV_ID_OUT_OF_RANGE;
    return (FALSE);
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if ((pdevcb == NULL) || (pdevcb->state == TEN_DEV_STATE_INVALID)) {
    *perr_code = ETEN_DEV_NOT_REGD;
    return (FALSE);
  }

  return (TRUE);
}

/*****************************************
 * Get dev semaphore pointer
 *****************************************/
CS_SEM *ten_get_dev_sem_ptr(cs_uint16 dev_id, ten_block_id_t blk_id)
{
  ten_dev_cb_t *pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  switch (blk_id) {
  case TEN_ID_MPIF:
    return (&pdevcb->sem_mpif);
    case TEN_ID_GLB:
      return (&pdevcb->sem_glb);
    case TEN_ID_XCON:
      return (&pdevcb->sem_xcon);
    case TEN_ID_FRACDIV:
      return (&pdevcb->sem_fracdiv);
    case TEN_ID_GPLLX1:
      return (&pdevcb->sem_gpllx1);
    case TEN_ID_IRQ:
      return (&pdevcb->sem_irq);
    case TEN_ID_SYNCDSYNC_CB:
      return (&pdevcb->sem_syncdsync_cb);
    case TEN_ID_PDCAL:
      return (&pdevcb->sem_pdcal);
    case TEN_ID_DM:
      return (&pdevcb->sem_dm); 
    default:
      CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "invalid blk_id %d\n", blk_id);
      return NULL;
  }
}

/*****************************************
 *  TEN_MOD_ID_TO_DEVCB_PTR
 *****************************************/
ten_dev_cb_t *TEN_MOD_ID_TO_DEVCB_PTR(cs_uint16 mod_id)
{
   cs_uint16 temp_dev_id;

   temp_dev_id = TEN_MOD_ID_TO_DEV_ID(mod_id);

   if (temp_dev_id < TEN_MAX_NUM_DEVICES) {
      return (g_pTEN->p_dev_cb_tbl[temp_dev_id]);
   }
   else {
      return (0);
   }
}

/*******************************************************
 *  ten_dev_is_t41
 *  Input arg: device ID
 *  Returns TRUE if device is T41,
 *          FALSE if T40 or type could not be determined.
*******************************************************/
cs_boolean ten_dev_is_t41_hsif_fix(cs_uint16 dev_id)
{
  cs_uint32 err_code = 0;
  cs_char8 *func = "ten_dev_is_t41_hsif_fix";

  CS_PRINT("%s() \n", func);

  /* Bugzilla #25991, fix static analyzer tool issues */
  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (FALSE);
  }
  else {
    return (ten_dev_is_t41_ptr(TEN_DEV_ID_TO_DEVCB_PTR(dev_id)));  /* NOTE-ptr arg checked by called function */
  }
}

/*******************************************************
 *  ten_dev_is_t41_ptr :
 *  Input arg: pointer to device control block
 *  Returns TRUE if device is T41,
 *          FALSE if T40 or type could not be determined.
 *******************************************************/
cs_boolean ten_dev_is_t41_ptr(ten_dev_cb_t *pdevcb)
{
  /* Bugzilla 26463 */
  cs_uint16 overridden_chip_type = 0;
  /* End Bugzilla 26463 */
  if (pdevcb == NULL) {
    CS_PRINT("Tenabo dev-unknown T41, ERROR: pdevcb is NULL\n");
    return (FALSE);
  }
  /* This tool is piggy-backed on Bugzilla 26186, PP40G stats. */
  overridden_chip_type = (~TEN_CHIP_OVERRIDE_MASK) & pdevcb->chip_type;
  if ( overridden_chip_type  != 0) {
    return ( overridden_chip_type == TEN_CHIP_OVERRIDE_T41);  /* <<< Early exit: return overridden chip type */
  }
  return (pdevcb->chip_type == TEN_CHIP_T41);
/* End T41 check */
}


/*******************************************************
 *  ten_dev_udelay_hi_res :
 *  Input arg: time in microseconds
 *  Returns CS_OK if the timer could be started,
 *          CS_ERROR otherwise.
 *******************************************************/
/*******************************************************/
/* This delay utility uses a T41's MPIF miscellaneous  */
/* counter. The first T41 initialized writes its       */
/* device number to static var ten_drvr_udelay_hi_res_ */
/* dev_id.                                             */
/*                                                     */
/* Though this is public, it's not intended to be part */
/* of the API. See instead cs_uint32 ten_mpif_udelay_  */
/* hi_res(cs_uint16 dev_id, cs_uint32 usecs )          */
/*******************************************************/
cs_status ten_dev_udelay_hi_res(cs_uint32 usecs)
{
  if (ten_dev_udelay_hi_res_dev_id > TEN_MAX_NUM_DEVICES) {
    CS_PRINT("ten_dev_udelay_hi_res() Error: No device registered for this timer\n");
    return CS_ERROR;
  }
  ten_mpif_udelay_hi_res(ten_dev_udelay_hi_res_dev_id, usecs);
  return CS_OK;
}


/* Bugzilla 30990, Hi-res micro-second delay timer              */
/****************************************************************/
/* $rtn_hdr_start   UPDATE SYSTEM CLOCK AND ITS DEPENDENCIES    */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_dev_update_sysclock(cs_uint16 dev_id,
                             cs_uint32 freq)
/* INPUTS     : System clock frequency (Hz)                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Updates system clock frequency in the device control block.  */
/* If system clock has changed, functions are called to update  */
/*   or process system clock dependencies.                      */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint32     err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return;
  }

  if ( (freq > TEN_MPIF_SYS_CLOCK_MAX) || (freq < TEN_MPIF_SYS_CLOCK_MIN) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "System clock frequency %d is out of range\n", freq);
    return;
  }

  if (!ten_dev_is_t41(dev_id)) {
    CS_PRINT("ten_dev_update_sysclock-T41 only feature.\n");
    return;
  }
  
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb->sysclock != freq) {
    CS_PRINT("ten_dev_update_sysclock(dev_id=%d, freq=%d)\n",dev_id, freq);
    pdevcb->sysclock = freq;

    /**************************************/
    /*   ADD SYSCLOCK DEPENDENCIES HERE   */
    /**************************************/
    ten_mpif_init_access_times(dev_id, freq);
  }
}


/****************************************************************/
/* $rtn_hdr_start  READ OR SET DEVICE USED FOR UDELAY HI RES    */
/* CATEGORY   : Device                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_dev_udelay_high_res_device(cs_uint16 dev_id,
                                         cs_uint16 set)
/* INPUTS     : o Device Id (0xFF to unset the current device)  */
/*              o Set                                           */
/*                TRUE  (1) to set the selected device          */
/*                FALSE (0) to read without setting             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Device selected, or 0xFF if op failed.          */
/* DESCRIPTION:                                                 */
/* If set is true, validates dev_id and updates ten_dev_udelay_ */
/*   hi_res_dev_id.                                             */
/* If validation fails, sets dev_id to 0xFF.                    */
/* Returns id of selected device.                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  if (set) {
    if ( (dev_id != 0xFF) && (!ten_dev_is_t41(dev_id)) ) {
      CS_PRINT("ten_dev_udelay_hi_res() Error: Invalid device selection.\n");
      dev_id = 0xFF;
    }
    ten_dev_udelay_hi_res_dev_id = dev_id;
  }
  return (ten_dev_udelay_hi_res_dev_id);
}
