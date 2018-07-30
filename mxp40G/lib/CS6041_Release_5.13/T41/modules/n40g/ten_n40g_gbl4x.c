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
 * ten_n40g_gbl4x.c
 *
 * N40G related code is implemented here.
 *
 * $Id: ten_n40g_gbl4x.c,v 1.15 2014/04/04 17:38:52 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N40G SET GLOBAL SOFT (LOGIC) RESETS          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_global_resets(cs_uint16 module_id, 
                                     cs_reset_action_t act,
                                     cs_uint16 bitfield)
/* INPUTS     : o Module Id                                     */
/*              o Reset Action                                  */
/*              o Bitfield                                      */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a soft reset on the specified (masked on)           */
/* selections. The selections that are masked off will not be   */
/* affected.                                                    */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   CS_RESET_DEASSERT                                          */
/*   CS_RESET_ASSERT                                            */
/*   CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* The [bitfield] parameter is specified as:                    */
/*   TEN_N40G_GLOBAL_RESETS_RSTTX  = 0x0001,                    */
/*   TEN_N40G_GLOBAL_RESETS_RSTOT  = 0x0002,                    */
/*   TEN_N40G_GLOBAL_RESETS_RSTST  = 0x0004,                    */
/*   TEN_N40G_GLOBAL_RESETS_RSTRX  = 0x0010,                    */
/*   TEN_N40G_GLOBAL_RESETS_RSTOR  = 0x0020,                    */
/*   TEN_N40G_GLOBAL_RESETS_RSTSR  = 0x0040,                    */
/*   TEN_N40G_GLOBAL_RESETS_RSTSYS = 0x0100,                    */
/*   TEN_N40G_GLOBAL_RESETS_ALL    = 0x0177                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBL4X_SWRST_t tmp_n40g_gbl4x_swrst;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_set_global_resets";  

  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, "%s  act = 0x%04X\n", func, act);
      return (CS_ERROR);
  }
  if (bitfield > TEN_N40G_GLOBAL_RESETS_ALL) {
    CS_HNDL_ERROR(module_id, ETEN_DEV_RANGE_ERR, "%s  bitfield = 0x%04X\n", func, bitfield);
      return (CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s, %s, bitfield=0x%X\n", func, ten_module_strings[module_id&1], ten_reset_act_strings[act], bitfield);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G); 
  tmp_n40g_gbl4x_swrst.wrd = bitfield;
  ten_reset_action(TEN_N40G_REG_ADDR(pDev, module_id, SWRST), tmp_n40g_gbl4x_swrst.wrd, act);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/* Bugzilla 29751 Start */
/****************************************************************/
/* $rtn_hdr_start  N40G ACCESS GLOBAL INTERRUPT REGISTER        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_n40g_gbl4x_gblint (cs_uint16 module_id, 
                                 cs_uint16 action,
                                 cs_uint16 bitfield)
/* INPUTS     : o Module Id                                     */
/*              o Reset Action                                  */
/*              o Bitfield                                      */
/*                                                              */
/* OUTPUTS    : o return_value                                  */
/* RETURNS    :                                                 */
/* DESCRIPTION:                                                 */
/* Read or clear individual interupt in the n40g_gbl4x_gblint   */
/* register                                                     */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [action] parameter specifies what is to be done to this  */
/* register and is one of the following:                        */
/*   TEN_INT_READ   = 0                                         */
/*   TEN_INT_CLEAR	= 1                                         */
/*                                                              */
/* The [bitfield] parameter is specified as:                    */
/*   TEN_N40G_GBL4X_GBLINT_SMECCSGL         = 0x0001            */
/*   TEN_N40G_GBL4X_GBLINT_SMECCDBL         = 0x0002            */
/*   TEN_N40G_GBL4X_GBLINT_TXDSKERR         = 0x0004            */
/*   TEN_NX0G_GBL4X_GBLINT_ALL				= 0x0007            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_GBL4X_GBLINT_t tmp_n40g_gbl4x_gblint;
  T41_t *pDev = NULL;
  cs_uint16 return_value = 0;
  cs_char8 *func = "ten_n40g_gbl4x_gblint";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, return_value);

  if (action > TEN_INT_CLEAR) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() action %d out of range.  s/b 0.1.", func, action);
    return (return_value);
  }


  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  if (action == TEN_INT_READ) {
    /* Read interrupt status */
    tmp_n40g_gbl4x_gblint.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GBLINT));
    switch (bitfield) {
      case TEN_N40G_GBL4X_GBLINT_SMECCSGL:
        return_value = tmp_n40g_gbl4x_gblint.bf.SMECCSGL;
        break;
        
      case TEN_N40G_GBL4X_GBLINT_SMECCDBL:
        return_value = tmp_n40g_gbl4x_gblint.bf.SMECCDBL;
        break;

      case TEN_N40G_GBL4X_GBLINT_TXDSKERR:
        return_value = tmp_n40g_gbl4x_gblint.bf.TXDSKERR;
        break;

      case TEN_NX0G_GBL4X_GBLINT_ALL:
      default:
        /* Return whole register */
        return_value = tmp_n40g_gbl4x_gblint.wrd;
        break;
    }
  } else {
    /* Clear interrupt status (Write 1 to clear) */
    tmp_n40g_gbl4x_gblint.wrd = bitfield;
    TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GBLINT), tmp_n40g_gbl4x_gblint.wrd);
  }

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  return (return_value);
}
/* Bugzilla 29751 End */

/* Bugzilla 43359 Start */
/****************************************************************/
/* $rtn_hdr_start  N40G SYNCHRONIZATION CONFIGURATION REGISTER  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_gbl4x_synccfg (cs_uint16 module_id, 
                                  cs_uint16 period,
                                  cs_uint16 enable)
/* INPUTS     : o Module Id                                     */
/*              o Period                                        */
/*              o Enable                                        */
/*                                                              */
/* OUTPUTS    : o return_value                                  */
/* RETURNS    :                                                 */
/* DESCRIPTION:                                                 */
/* Enable common frame reference to be generated to all 4 N10G  */
/* blocks for synchronization of TX frames at a specified frame */
/* reference period                                             */
/*                                                              */
/* The [period] parameter specifies the period of the common    */
/* internal frame reference and is configured as 16 x number of */
/* total OxUj columns (NCOLS)                                   */
/*                                                              */
/* The [enable] parameter specifies the four transmit OxUj can  */
/* be frame-aligned by using an internally generated common     */ 
/* frame reference                                              */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_gbl4x_synccfg";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  if (enable > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() enable %d out of range.  s/b 0.1.", func, enable);
    return (CS_ERROR);
  }

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, SYNCPER), period);
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, SYNCCFG), enable);
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  return (CS_OK);
}
/* Bugzilla 43359 End */
