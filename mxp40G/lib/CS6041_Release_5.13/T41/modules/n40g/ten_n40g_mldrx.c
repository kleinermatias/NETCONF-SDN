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
 * ten_n40g_mldrx.c
 *
 * N40G related code is implemented here.
 *
 * $Id: ten_n40g_mldrx.c,v 1.6 2013/02/22 20:44:38 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/* Bugzilla 26908 Start */
/****************************************************************/
/* $rtn_hdr_start   CONFIGURE N40G SADECO SKEW AND DELAY COMP   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status  ten_n40g_sadeco_config(cs_uint16 module_id,
                                  cs_uint16 es_depth,
                                  cs_uint16 es_skew_length,
                                  cs_uint16 fp_type,
                                  cs_uint16 trib_stream)
/* INPUTS     : o Module Id                                     */
/*              o Elastic Store Depth                           */
/*              o Skew and Delay Compensation Length            */
/*              o Internal Frame Pulse Distribution Style       */
/*              o Tributary Stream                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the SADECO delay and compensation                  */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [es_depth] parameter adjusts the ES latency upon auto or */
/* manual synchronization. Incrementing ESDEPTH by 1 will delay */
/* the (40 Gbit/s) stream by 128 bits.                          */
/*   0 - 0x1FFF                                                 */
/*                                                              */
/* The [skew_length] parameter specifies the frame length,      */
/* divided by 32 bits, of the frames transferred through the    */
/* elastic store.                                               */
/*   0 - 0x1FFF                                                 */ 
/*                                                              */
/* The frame pulse style parameter is specified as:             */
/*   0 = XCON_SONET_SDH_INACTIVE                                */ 
/*   1 = XCON_SONET_SDH_16                                      */ 
/*                                                              */
/* The [trib_stream] parameter in Skew and Delay Compensation   */
/* mode, RSYMSK defines a set of incoming tributary data streams*/
/* that trigger automatic resynchronization of alignment for    */
/* the newly combined 4X stream                                 */
/*   0 - 0x1F                                                   */
/* NOTE: The bits RSYMSK 0..3 enable resynchronization based on */
/*       data streams 0..3 respectively                         */
/*       Bit 4 enables resynchronization when there is an       */
/* underflow or overflow error condition detected by any of the */
/* elastic stores                                               */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SADCFG0_t tmp_n40g_mldrx_sadeco_sadcfg0;
  TEN_N40G_MLDRX_SADECO_SADCFG1_t tmp_n40g_mldrx_sadeco_sadcfg1;
  TEN_N40G_MLDRX_SADECO_SADCFG3_t tmp_n40g_mldrx_sadeco_sadcfg3;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_sadeco_config";  


  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  if(es_depth > 0x1FFF) { 
    CS_HNDL_ERROR (module_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_depth=0x%X is too large", func, es_depth);
    return CS_ERROR; 
  }
  if(es_skew_length > 0x1FFF) { 
    CS_HNDL_ERROR (module_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_skew_length=0x%X is too large", func, es_skew_length);
    return CS_ERROR; 
  }
  if(fp_type > XCON_SONET_SDH_64) { 
    CS_HNDL_ERROR (module_id, ETEN_DEV_INVALID_USER_ARG, "%s() fp_type=%d is too large", func, fp_type);
    return CS_ERROR; 
  }
  if(trib_stream > 0x01F) { 
    CS_HNDL_ERROR (module_id, ETEN_DEV_INVALID_USER_ARG, "%s() trib_stream=0x%X is too large", func, trib_stream);
    return CS_ERROR; 
  }


  CS_PRINT("%s() %s, es_depth=0x%X, es_skew_length=0x%X, %s, trib_stream=0x%X\n",
           func,
           ten_module_strings[module_id&1],
           es_depth,
           es_skew_length,
           ten_sadeco_fp_type_strings[fp_type],
		   trib_stream);
           

  TEN_MOD_LOCK (module_id, TEN_ID_N40G); 
  /* Configuration for Skew and Delay Compensator */
  tmp_n40g_mldrx_sadeco_sadcfg0.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG0));
  tmp_n40g_mldrx_sadeco_sadcfg0.bf.ESDEPTH = es_depth;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG0), tmp_n40g_mldrx_sadeco_sadcfg0.wrd);
 
  tmp_n40g_mldrx_sadeco_sadcfg1.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG1));
  tmp_n40g_mldrx_sadeco_sadcfg1.bf.HIGHLIM = es_skew_length;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG1), tmp_n40g_mldrx_sadeco_sadcfg1.wrd);
                                
  tmp_n40g_mldrx_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3));
  if (fp_type == XCON_SONET_SDH_INACTIVE) {
    tmp_n40g_mldrx_sadeco_sadcfg3.bf.SDH16MD = 0;
  }
  else { /*else if (fp_type == XCON_SONET_SDH_16) {*/
    tmp_n40g_mldrx_sadeco_sadcfg3.bf.SDH16MD = 1;
  }
  tmp_n40g_mldrx_sadeco_sadcfg3.bf.RSYMSK = trib_stream;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3), tmp_n40g_mldrx_sadeco_sadcfg3.wrd);
  TEN_MOD_UNLOCK (module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G SADECO ENABLE  FRAME PULSES                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_sadeco_enable_fp(cs_uint16 module_id, 
                                    cs_ctl_t enable)
/* INPUTS     : o Module Id                                         */
/*              o Enable                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Switches off the frame pulses used on the read side of the       */
/* elastic store.                                                   */
/*                                                                  */
/* [module_id] parameter specifies line's module ID                 */
/* 16 devices can be registered and module bit indicates line       */
/* or client side of the registered device. The registered device    */
/* is identified by the dev_id bits specified below                 */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module      */
/*                                                                  */
/* [enable] CS_DISABLE = 0, Switches off the frame pulses used      */
/*          on the read side of the elastic store; sets sdcoff = 1. */
/*          CS_ENABLE = 1, Switches on the frame pulses used on     */
/*          the read side of the ES, sets sdcoff=0.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SADCFG3_t tmp_n40g_mldrx_sadeco_sadcfg3;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_sadeco_enable_fp";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  
  if (enable > CS_ENABLE) { 
    CS_HNDL_ERROR (module_id, ETEN_DEV_INVALID_USER_ARG, "%s() enable=%d is too large", func, enable);
    return CS_ERROR; 
  }

  CS_PRINT("%s() %s, enable=%d\n", func, ten_module_strings[module_id&1], enable);

  TEN_MOD_LOCK (module_id, TEN_ID_N40G); 
  tmp_n40g_mldrx_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3));
  tmp_n40g_mldrx_sadeco_sadcfg3.bf.SDCOFF = (enable == CS_DISABLE);
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3), tmp_n40g_mldrx_sadeco_sadcfg3.wrd);

  TEN_MOD_UNLOCK (module_id, TEN_ID_N40G);
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SADECO SET SDCLEN REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_sadeco_sdclen(cs_uint16 module_id,
                                 cs_uint16 sdclen)
/* INPUTS     : o Module Id                                     */
/*              o SDCLEN                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Skew and Delay Compensation Frame Length.                    */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [sdclen] parameter is specified as:                      */
/*   SDCLEN[15:0] Skew and Delay Compensation Length specifies  */
/*   the frame length, divided by 32 bits, of the frames        */
/*   transferred through the elastic store.                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SDCLEN_t tmp_n40g_mldrx_sadeco_sdclen;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_sadeco_sdclen";  


  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);
  /*if (sdclen > 0xFFFF) {                                                                             */
  /*  CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,  "%s() sdclen=0x%X is too large", func, sdclen);*/
  /*  return CS_ERROR;                                                                                 */
  /*}                                                                                                  */

  CS_PRINT("%s() %s, sdclen=0x%X\n", func, ten_module_strings[module_id&1], sdclen);

  TEN_MOD_LOCK (module_id, TEN_ID_N40G); 
  tmp_n40g_mldrx_sadeco_sdclen.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SDCLEN));
  tmp_n40g_mldrx_sadeco_sdclen.bf.SDCLEN = sdclen;
  TEN_REG_WRITE (TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SDCLEN), tmp_n40g_mldrx_sadeco_sdclen.wrd);
  TEN_MOD_UNLOCK (module_id, TEN_ID_N40G);

  return (CS_OK);
}



/****************************************************************/
/* $rtn_hdr_start  N40G SET CIRCUIT MODE FIFO THRESHOLDS        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_circuit_thresholds(cs_uint16 module_id, 
                                          cs_uint8 slice,
                                          cs_uint16 type, 
                                          cs_uint16 value)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Circuit Threshold                             */
/*              o Value                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the specified circuit mode FIFO threshold.               */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [type] parameter is specified as:                        */
/*   0 = XCON_ES_IML_THRESH                                     */
/*   1 = XCON_ES_CIRCUIT_THRESHOLD_UPPER                        */
/*   2 = XCON_ES_CIRCUIT_THRESHOLD_LOWER                        */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   Value of FIFO threshold.                                   */
/*   0 - 0x1FF                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N40G_MLDRX_MLD_ES_IML_THRESH_t tmp_n40g_mldrx_mld_es_iml_thresh;
  TEN_N40G_MLDRX_MLD_ES_CIRCUIT_THRESHOLD_UPPER_t tmp_n40g_mldrx_mld_es_circuit_threshold_upper;
  TEN_N40G_MLDRX_MLD_ES_CIRCUIT_THRESHOLD_LOWER_t tmp_n40g_mldrx_mld_es_circuit_threshold_lower;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_set_circuit_thresholds";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, CS_ERROR);


  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR (module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, 255", func, slice);
    return (CS_ERROR);
  }
  if (type > XCON_ES_CIRCUIT_THRESHOLD_LOWER) { 
    CS_HNDL_ERROR (module_id, ETEN_DEV_INVALID_USER_ARG, "%s() type %d out of range.  s/b 0, 1 or 2", func, type);
    return CS_ERROR; 
  }
  if (value > 0x1FF) { 
    CS_HNDL_ERROR (module_id, ETEN_DEV_INVALID_USER_ARG, "%s() value 0x%x out of range.  s/b 0..0x1FF", func, value);
    return CS_ERROR; 
  }

  CS_PRINT("%s() %s, %s, value=0x%X\n", func, ten_module_strings[module_id&1], ten_ex_circuit_threshold_strings[type], value);


  TEN_MOD_LOCK (module_id, TEN_ID_N40G); 
  for (sl=0; sl<TEN_N40G_MLDRX_MLD_ES_COUNT; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      if (type == XCON_ES_IML_THRESH) {
        tmp_n40g_mldrx_mld_es_iml_thresh.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, IML_THRESH) + sl * TEN_N40G_MLDRX_MLD_ES_STRIDE);
        tmp_n40g_mldrx_mld_es_iml_thresh.bf.IML_THRESH = value;
        TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, IML_THRESH) + sl * TEN_N40G_MLDRX_MLD_ES_STRIDE, tmp_n40g_mldrx_mld_es_iml_thresh.wrd);
      }
      else if (type == XCON_ES_CIRCUIT_THRESHOLD_UPPER) {
        tmp_n40g_mldrx_mld_es_circuit_threshold_upper.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, CIRCUIT_THRESHOLD_UPPER) + sl * TEN_N40G_MLDRX_MLD_ES_STRIDE);
        tmp_n40g_mldrx_mld_es_circuit_threshold_upper.bf.LEVEL = value;
        TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, CIRCUIT_THRESHOLD_UPPER) + sl * TEN_N40G_MLDRX_MLD_ES_STRIDE, tmp_n40g_mldrx_mld_es_circuit_threshold_upper.wrd);
      }
      else {
        tmp_n40g_mldrx_mld_es_circuit_threshold_lower.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, CIRCUIT_THRESHOLD_LOWER) + sl * TEN_N40G_MLDRX_MLD_ES_STRIDE);
        tmp_n40g_mldrx_mld_es_circuit_threshold_lower.bf.LEVEL = value;
        TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, CIRCUIT_THRESHOLD_LOWER) + sl * TEN_N40G_MLDRX_MLD_ES_STRIDE, tmp_n40g_mldrx_mld_es_circuit_threshold_lower.wrd);
      }
    }
  }

  TEN_MOD_UNLOCK (module_id, TEN_ID_N40G);

  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDR_SET_LMFIRLEN                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldr_set_lmfirlen(cs_uint16 module_id,
                                     cs_uint16 lmfirlen)
/* INPUTS     : o Module_id                                                   */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets LMFIRLEN to a value other than the correct '5' for debug purposes   */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_MLDR_LMCFG_t tmp_n40g_mldrx_mldr_lmcfg;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_mldr_set_lmfirlen";  

  TEN_MOD_COMMON_VALIDATE (module_id, pDev, FALSE);

  if (lmfirlen > 0xF) { 
    CS_HNDL_ERROR (module_id, ETEN_DEV_INVALID_USER_ARG, "%s() lmfirlen %d out of range.  s/b 0..15", func, lmfirlen);
    return CS_ERROR; 
  }
  CS_PRINT("%s() %s, lmfirlen=0x%X\n", func, ten_module_strings[module_id&1], lmfirlen);

  TEN_MOD_LOCK (module_id, TEN_ID_N40G); 
  tmp_n40g_mldrx_mldr_lmcfg.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, LMCFG));
  tmp_n40g_mldrx_mldr_lmcfg.bf.LMFIRLEN = lmfirlen;
  TEN_REG_WRITE (TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, LMCFG), tmp_n40g_mldrx_mldr_lmcfg.wrd);
  TEN_MOD_UNLOCK (module_id, TEN_ID_N40G);

  return (CS_OK);
}

/* Bugzilla 27628 Start */
/****************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_MLD_ES_SET_SRESET                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_mldrx_mld_es_set_sreset_t41 (cs_uint16 module_id,
                                                cs_uint8  slice,
                                                cs_uint16 reset)
/* INPUTS     : o Module_id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*   set or releases soft resets                                */
/*                                                              */
/* [module_id] parameter specifies line's module ID             */
/* 16 devices can be registered and module bit indicates line   */
/* or client side of the registered device. The registered device*/
/* is identified by the dev_id bits specified below             */
/*   Bits 11:8 – dev_id, Bits 7:1 – don’t care, Bit 0 – module  */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [reset] parameter is specified as:                       */
/*   0 = Take elastic store out of reset                        */
/*   1 = Place elastic store in reset                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 sl;
  TEN_N40G_MLDRX_MLD_ES_RESET_t tmp_n40g_mldrx_mld_es_reset;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_mldrx_mld_es_set_sreset_t41";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);

  if ((slice>=TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3.", func, slice);
    return(CS_ERROR);
  }

  if (reset > 1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() reset %d out of range.  s/b 0..1.", func, reset);
    return(CS_ERROR);
  }

  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("%s() %s, TEN_SLICE_ALL, reset= %d\n", func, ten_module_strings[module_id&1], reset);
  } else {
    CS_PRINT("%s() %s, %s, reset= %d\n", func, ten_module_strings[module_id&1], ten_slice_strings[slice], reset);
  }

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  for (sl=0; sl<TEN_N40G_MLDRX_MLD_ES_COUNT; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_n40g_mldrx_mld_es_reset.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, RESET) + sl * TEN_N40G_MLDRX_MLD_ES_STRIDE);
      tmp_n40g_mldrx_mld_es_reset.bf.RESET = reset;
      TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, RESET) + sl * TEN_N40G_MLDRX_MLD_ES_STRIDE, tmp_n40g_mldrx_mld_es_reset.wrd);
    }
  }    

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}



/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_SADECO_SET_SRESET                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_sadeco_set_sreset_t41(cs_uint16 module_id, cs_uint16 swrst)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   provision soft resets                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SADCFG3_t tmp_n40g_mldrx_sadeco_sadcfg3;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_mldrx_sadeco_set_sreset_t41";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);

  if (swrst >1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() swrst %d out of range.  s/b 0..1.", func, swrst);
    return(CS_ERROR);
  }
  
  CS_PRINT("%s() %s, swrst= %d\n",
           func,
           ten_module_strings[module_id&1],
           swrst);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_n40g_mldrx_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3));
  tmp_n40g_mldrx_sadeco_sadcfg3.bf.SWRST = swrst;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3), tmp_n40g_mldrx_sadeco_sadcfg3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/* Bugzilla 27628 End */
