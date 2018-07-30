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
 * ten_callback.c
 *
 * Provides mechanism for users of T40 APIs to register
 * their callback functions.
 *
 */

#include "tenabo40.h"

ten_register_reg_write_t register_write_ptr = NULL;
ten_register_reg_read_t register_read_ptr = NULL;
ten_register_swerr_t register_swerr_ptr = NULL;
ten_register_shadow_ram_t register_shadow_ram_ptr = NULL;
ten_register_udelay_hi_res_t register_udelay_hr_ptr = NULL;

/********************************************************************/
/* $rtn_hdr_start  CALLBACK INITIALIZE                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_init_callbacks(void)
/* INPUTS     : ----                                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Initializes all callback functions to NULL.                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  register_write_ptr      = NULL;
  register_read_ptr       = NULL;
  register_swerr_ptr      = NULL;
  register_shadow_ram_ptr = NULL;
  ten_register_udelay_hi_res(ten_drvr_udelay_hi_res);
  
  #if 0 /* for testing purposes only */
  ten_verifyShadowRamWritten();
  ten_verifyErrorHandler();
  ten_verify_reg_read();
  ten_verify_reg_write();
  #endif
  
  return (CS_OK); 
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK REGISTER REG WRITE FUNCTION             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_register_reg_write(ten_register_reg_write_t reg_write_cb)
/* INPUTS     : o Reg write callback function                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Registers reg write callback function.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   cs_status rc = CS_ERROR;

   if (reg_write_cb)
   {
     register_write_ptr = reg_write_cb;
     rc = CS_OK;
   }
   return rc;
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK REGISTER REG READ FUNCTION              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_register_reg_read(ten_register_reg_read_t reg_read_cb)
/* INPUTS     : o Reg read callback function                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Registers a reg read callback function.                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   cs_status rc = CS_ERROR;

   if (reg_read_cb)
   {
      register_read_ptr = reg_read_cb;
      rc = CS_OK;
   }
   return rc;
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK REGISTER HI RES USEC DELAY FUNCTION     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_register_udelay_hi_res(ten_register_udelay_hi_res_t udelay_hr_cb)
/* INPUTS     : o usec delay callback function                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Registers a high-resolution usec delay callback function.        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   cs_status rc = CS_ERROR;
   if (ten_is_registered_udelay_hi_res() ) {
     CS_PRINT("Error: ten_udelay_hi_res_cb() is already registered. Unregister it first and try again.\n");
     return rc;
   }

   if (udelay_hr_cb)
   {
      register_udelay_hr_ptr = udelay_hr_cb;
      rc = CS_OK;
   }
   return rc;
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK IS REGISTERED, HI RES USEC DELAY?       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_is_registered_udelay_hi_res(void)
/* INPUTS     : ----                                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE (1) if registered, FALSE (0) otherwise          */
/* DESCRIPTION:                                                     */
/* The high-resolution usec delay callback must be initialzed to    */
/* a functioning default. This function is called prior to          */
/* initializing the callback to ensure that a previous registration */
/* is not overwritten. This is required because by default the T41  */
/* driver registers the first registered T41 device's MPIF udelay   */
/* function. If it finds that a callback is already registered, it  */
/* does nothing.                                                    */
/*                                                                  */
/* Note that this scheme works well for initialization,             */
/* single-device drivers, and testing, but will not work in         */
/* multi-device drivers if the registered device is in reset.       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   return (register_udelay_hr_ptr != NULL);
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK REGISTER SOFTWARE ERROR FUNCTION        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_register_swerr(ten_register_swerr_t swerr_cb)
/* INPUTS     : o SW Error callback function                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Registers a software error callback function.                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   cs_status rc = CS_ERROR;

   if (swerr_cb)
   {
     register_swerr_ptr = swerr_cb;
     rc = CS_OK;
   } 
   return rc;
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK REGISTER SHADOW RAM FUNCTION            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_register_shadow_ram(ten_register_shadow_ram_t reg_shadow_ram_cb)
/* INPUTS     : o Shadow ram callback function                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Registers a shadow ram callback function.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   cs_status rc = CS_ERROR;

   if (reg_shadow_ram_cb)
   {
     register_shadow_ram_ptr = reg_shadow_ram_cb;
     rc = CS_OK;
   }

   return rc;
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK REG WRITE FUNCTION                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
void ten_reg_write_cb(volatile cs_uint16* address, cs_uint16 value)
/* INPUTS     : o Pointer to Address                                */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : ----                                                */
/* DESCRIPTION:                                                     */
/* Callback function for reg write.                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   if (register_write_ptr)
   {
      (*register_write_ptr)(address, value);
   }
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK REG READ FUNCTION                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
void ten_reg_read_cb(volatile cs_uint16* address, cs_uint16 value)
/* INPUTS     : o Pointer to Address                                */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : ----                                                */
/* DESCRIPTION:                                                     */
/* Callback function for reg read.                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   if (register_read_ptr)
   {
      (*register_read_ptr)(address, value); 
   }
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK HI RES USEC DELAY FUNCTION              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
void ten_udelay_hi_res_cb(cs_uint32 usecs)
/* INPUTS     : o Pointer to Address                                */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : ----                                                */
/* DESCRIPTION:                                                     */
/* Callback function for high resolution usec delay.                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   if (register_udelay_hr_ptr)
   {
      (*register_udelay_hr_ptr)(usecs); 
   }
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK SOFTWARE ERROR FUNCTION                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
void ten_swerr_cb(cs_uint16 id, 
                  cs_uint16 errorNumber,
                  cs_char8* errorString_p)
/* INPUTS     : o ID                                                */
/*              o Error Number                                      */
/*              o Error String                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : ----                                                */
/* DESCRIPTION:                                                     */
/* Callback function for software error.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   if (register_swerr_ptr)
   {
      (*register_swerr_ptr)(id, errorNumber, errorString_p);
   }
}

/********************************************************************/
/* $rtn_hdr_start  CALLBACK REG WRITE FUNCTION                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
void ten_shadow_ram_cb(cs_uint16 module_id,
                       cs_uint16 bank,
                       cs_uint16 *shadowRam_p, 
                       cs_uint16 shadowRamSize)
/* INPUTS     : o Module Id                                         */
/*              o Bank                                              */
/*              o Pointer to ShadowRam                              */
/*              o Shadow Ram Size                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : ----                                                */
/* DESCRIPTION:                                                     */
/* Callback function for shadow RAM.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
   if (register_shadow_ram_ptr)
   {
      (*register_shadow_ram_ptr)(module_id, bank, shadowRam_p, shadowRamSize);
   }
}

/***************************************************************/
/* $rtn_hdr_start  CALLBACK UNREGISTER REG WRITE FUNCTION      */
/* CATEGORY   : API                                            */
/* ACCESS     : Public                                         */
/* BLOCK      : GENERAL                                        */
/* CHIP       : Tenabo                                         */
cs_status ten_unregister_reg_write(void)
/* INPUTS     : ----                                           */
/* OUTPUTS    : ----                                           */
/* RETURNS    : CS_OK or CS_ERROR                              */
/* DESCRIPTION:                                                */
/* Unregisters reg write callback function.                    */
/*                                                             */
/* $rtn_hdr_end                                                */
/***************************************************************/
{
  register_write_ptr = NULL;
  return (CS_OK);
}

/***************************************************************/
/* $rtn_hdr_start  CALLBACK UNREGISTER REG READ FUNCTION       */
/* CATEGORY   : API                                            */
/* ACCESS     : Public                                         */
/* BLOCK      : GENERAL                                        */
/* CHIP       : Tenabo                                         */
cs_status ten_unregister_reg_read(void)
/* INPUTS     : ----                                           */
/* OUTPUTS    : ----                                           */
/* RETURNS    : CS_OK or CS_ERROR                              */
/* DESCRIPTION:                                                */
/* Unregisters reg read  callback function.                    */
/*                                                             */
/* $rtn_hdr_end                                                */
/***************************************************************/
{
  register_read_ptr = NULL;
  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  CALLBACK UNREGISTER HI RES USEC DELAY FUNCTION   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : GENERAL                                             */
/* CHIP       : Tenabo                                              */
cs_status ten_unregister_udelay_hi_res(void)
/* INPUTS     : ----                                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Unegisters a high-resolution usec delay callback function.       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  register_udelay_hr_ptr = NULL;
  return (CS_OK);
}

/***************************************************************/
/* $rtn_hdr_start  CALLBACK UNREGISTER SOFTWARE ERROR FUNCTION */
/* CATEGORY   : API                                            */
/* ACCESS     : Public                                         */
/* BLOCK      : GENERAL                                        */
/* CHIP       : Tenabo                                         */
cs_status ten_unregister_swerr(void)
/* INPUTS     : ----                                           */
/* OUTPUTS    : ----                                           */
/* RETURNS    : CS_OK or CS_ERROR                              */
/* DESCRIPTION:                                                */
/* Unregisters software error callback function.               */
/*                                                             */
/* $rtn_hdr_end                                                */
/***************************************************************/
{
  register_swerr_ptr = NULL;
  return (CS_OK);
}

/***************************************************************/
/* $rtn_hdr_start  CALLBACK UNREGISTER SHADOW RAM FUNCTION     */
/* CATEGORY   : API                                            */
/* ACCESS     : Public                                         */
/* BLOCK      : GENERAL                                        */
/* CHIP       : Tenabo                                         */
cs_status ten_unregister_shadow_ram(void)
/* INPUTS     : ----                                           */
/* OUTPUTS    : ----                                           */
/* RETURNS    : CS_OK or CS_ERROR                              */
/* DESCRIPTION:                                                */
/* Unregisters shadow RAM callback function.                   */
/*                                                             */
/* $rtn_hdr_end                                                */
/***************************************************************/
{
  register_shadow_ram_ptr = NULL;
  return (CS_OK);
}

/* Debug function: Test register write callback                     */
cs_status ten_my_reg_write(volatile cs_uint16* addr, cs_uint16 value)
{
  CS_PRINT("my reg write called addr=%p, value=0x%x\n", addr, value);
  return (CS_OK);
}

/* Debug function: Test register write callback                     */
void ten_verify_reg_write()
{
   ten_register_reg_write(ten_my_reg_write);
}

/* Debug function: Test register read callback                      */
cs_status ten_my_reg_read(volatile cs_uint16* addr, cs_uint16 value)
{
  CS_PRINT("my reg read called addr=%p, value=0x%x\n", addr, value);
  return (CS_OK);
}

/* Debug function: Test register read callback                      */
void ten_verify_reg_read()
{
   ten_register_reg_read(ten_my_reg_read);
}

/* Debug function: the function to be called back for SWErr         */
void ten_notifyErrorHandler(cs_uint16 id, 
                            cs_uint16 errorNumber,
                            cs_char8* errorString_p)
{
  CS_PRINT("ID                = %d,\n", id);
  CS_PRINT("errorNumber       = %d,\n", errorNumber);
  CS_PRINT("errorString_p     = %s,\n", errorString_p);
}

/* Debug function: the function to register SWErr callback         */
void ten_verifyErrorHandler()
{
  ten_register_swerr(ten_notifyErrorHandler);
}

/* Debug function: Test SWErr callback                              */
void ten_call_swerr_cb()
{
   cs_uint32 id = 2;
   cs_uint32 errCode = 3;

   /*(*register_swerr_ptr)(id, errCode);*/
   ten_error_handler(id, errCode, NULL);
}

/* Debug function: the function to be called back for Shadow RAM    */
void ten_notifyShadowRamWritten(cs_uint16 module_id,
                                cs_uint16 bank,
                                cs_uint16 *shadowRam_p, 
                                cs_uint16 shadowRamSize)
{
  CS_PRINT("Module ID       = %d,\n", module_id);
  CS_PRINT("Bank            = %d,\n", bank);
  CS_PRINT("shadowRam_p     = %p,\n", shadowRam_p);
  CS_PRINT("shadowRamSize   = %d,\n", shadowRamSize);
}

/* Debug function: the function to register Shadow RAM callback     */
void ten_verifyShadowRamWritten()
{
  ten_register_shadow_ram(ten_notifyShadowRamWritten);
}

