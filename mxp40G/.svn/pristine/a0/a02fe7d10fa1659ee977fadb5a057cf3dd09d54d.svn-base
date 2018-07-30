/******************************************************************************/
/* This file contains information proprietary to Cortina Systems, Inc.        */
/* (Cortina). Any use or disclosure, in whole or in part, of this information */
/* to any unauthorized party, for any purposes other than that for which it   */
/* is provided is expressly prohibited except as authorized by Cortina in     */
/* writing. Cortina reserves its rights to pursue both civil and criminal     */
/* penalties for copying or disclosure of this material without               */
/* authorization. Cortina Systems (R), Cortina (TM) and the Cortina Systems   */
/* Earth Logo are the trademarks or registered trademarks of Cortina Systems, */
/* Inc. and its subsidiaries in the U.S. and other countries. Any other       */
/* product and company names are the trademarks of their respective owners.   */
/* Copyright (C) 2006-2013 Cortina Systems, Inc. All rights reserved.         */
/******************************************************************************/


/*
 * This file is auto-generated from n40g_config.xml; DO NOT MODIFY
 */

#include "tenabo40.h"

/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_MLDR_SCR_OFF                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_mldr_scr_off_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   turns off MLD scrambler                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_MLDR_MLDCFG_t tmp_n40g_mldrx_mldr_mldcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_mldr_mldcfg.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, MLDCFG));
  tmp_n40g_mldrx_mldr_mldcfg.bf.DSCRL_EN = 0;
  TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, MLDCFG), tmp_n40g_mldrx_mldr_mldcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}



/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_MLDR_SET_LMFIRLEN                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_mldr_set_lmfirlen_t41(cs_uint16 module_id,
                                               cs_uint16 val)
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

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_mldr_lmcfg.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, LMCFG));
  tmp_n40g_mldrx_mldr_lmcfg.bf.LMFIRLEN = val;
  TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, LMCFG), tmp_n40g_mldrx_mldr_lmcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_MLDR_SET_LMFORLEN                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_mldr_set_lmforlen_t41(cs_uint16 module_id,
                                               cs_uint16 val)
/* INPUTS     : o Module_id                                                   */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets LMFORLEN to a value other than the correct '5' for debug purposes   */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_MLDR_LMCFG_t tmp_n40g_mldrx_mldr_lmcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_mldr_lmcfg.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, LMCFG));
  tmp_n40g_mldrx_mldr_lmcfg.bf.LMFORLEN = val;
  TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, LMCFG), tmp_n40g_mldrx_mldr_lmcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_MLDR_SET_TDELOFF                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_mldr_set_tdeloff_t41(cs_uint16 module_id,
                                              cs_uint16 val)
/* INPUTS     : o Module_id                                                   */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets TDELOFF to a value other than the default '0x1ef' for debug         */
/*     purposes                                                               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_MLDR_LOLCFG1_t tmp_n40g_mldrx_mldr_lolcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_mldr_lolcfg1.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, LOLCFG1));
  tmp_n40g_mldrx_mldr_lolcfg1.bf.TDELOFF = val;
  TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, LOLCFG1), tmp_n40g_mldrx_mldr_lolcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_MLD_ES_RELEASE_SRESET                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_mld_es_release_sreset_t41(cs_uint16 module_id,
                                                   cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   releases soft resets                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_MLD_ES_RESET_t tmp_n40g_mldrx_mld_es_reset;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_mld_es_reset.wrd = 0;
  TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, RESET), tmp_n40g_mldrx_mld_es_reset.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_MLD_ES_ES_IML_THRESH                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_mld_es_es_iml_thresh_t41(cs_uint16 module_id,
                                                  cs_uint8  slice,
                                                  cs_uint16 val)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets IML threshold to value                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_MLD_ES_IML_THRESH_t tmp_n40g_mldrx_mld_es_iml_thresh;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_mld_es_iml_thresh.wrd = val;
  TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, IML_THRESH), tmp_n40g_mldrx_mld_es_iml_thresh.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_MLD_ES_ES_UPPER_THRESH                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_mld_es_es_upper_thresh_t41(cs_uint16 module_id,
                                                    cs_uint8  slice,
                                                    cs_uint16 val)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets IML threshold to value                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_MLD_ES_CIRCUIT_THRESHOLD_UPPER_t tmp_n40g_mldrx_mld_es_circuit_threshold_upper;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_mld_es_circuit_threshold_upper.wrd = val;
  TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, CIRCUIT_THRESHOLD_UPPER), tmp_n40g_mldrx_mld_es_circuit_threshold_upper.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_SADECO_RELEASE_SRESET                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_sadeco_release_sreset_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   releases soft resets                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SADCFG3_t tmp_n40g_mldrx_sadeco_sadcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3));
  tmp_n40g_mldrx_sadeco_sadcfg3.bf.SWRST = 0;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3), tmp_n40g_mldrx_sadeco_sadcfg3.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_SADECO_SDC_ON                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_sadeco_sdc_on_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   turns off MLD SDCOFF bit to enable SDC                                   */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SADCFG3_t tmp_n40g_mldrx_sadeco_sadcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3));
  tmp_n40g_mldrx_sadeco_sadcfg3.bf.SDCOFF = 0;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3), tmp_n40g_mldrx_sadeco_sadcfg3.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_SADECO_RSYMSK                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_sadeco_rsymsk_t41(cs_uint16 module_id,
                                           cs_uint16 val)
/* INPUTS     : o Module_id                                                   */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets RSYMSK to value                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SADCFG3_t tmp_n40g_mldrx_sadeco_sadcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3));
  tmp_n40g_mldrx_sadeco_sadcfg3.bf.RSYMSK = val;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3), tmp_n40g_mldrx_sadeco_sadcfg3.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_SADECO_FRAME_WORD_LENGTH                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_sadeco_frame_word_length_t41(cs_uint16 module_id,
                                                      cs_uint16 val)
/* INPUTS     : o Module_id                                                   */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets SDCLEN to value                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SDCLEN_t tmp_n40g_mldrx_sadeco_sdclen;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_sadeco_sdclen.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SDCLEN));
  tmp_n40g_mldrx_sadeco_sdclen.bf.SDCLEN = val;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SDCLEN), tmp_n40g_mldrx_sadeco_sdclen.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_SADECO_ES_DEPTH                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_sadeco_es_depth_t41(cs_uint16 module_id,
                                             cs_uint16 val)
/* INPUTS     : o Module_id                                                   */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets ESDEPTH to value                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SADCFG0_t tmp_n40g_mldrx_sadeco_sadcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_sadeco_sadcfg0.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG0));
  tmp_n40g_mldrx_sadeco_sadcfg0.bf.ESDEPTH = val;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG0), tmp_n40g_mldrx_sadeco_sadcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_SADECO_ES_HIGH_LIMIT                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_sadeco_es_high_limit_t41(cs_uint16 module_id,
                                                  cs_uint16 val)
/* INPUTS     : o Module_id                                                   */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets HIGHLIM to value                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SADCFG1_t tmp_n40g_mldrx_sadeco_sadcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_sadeco_sadcfg1.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG1));
  tmp_n40g_mldrx_sadeco_sadcfg1.bf.HIGHLIM = val;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG1), tmp_n40g_mldrx_sadeco_sadcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_MLDRX_SADECO_SDH16_MODE                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_mldrx_sadeco_sdh16_mode_t41(cs_uint16 module_id,
                                               cs_uint16 val)
/* INPUTS     : o Module_id                                                   */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets SDH16MD                                                             */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_SADECO_SADCFG3_t tmp_n40g_mldrx_sadeco_sadcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_mldrx_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3));
  tmp_n40g_mldrx_sadeco_sadcfg3.bf.SDH16MD = val;
  TEN_REG_WRITE(TEN_N40G_MLDRX_SADECO_REG_ADDR(pDev, module_id, SADCFG3), tmp_n40g_mldrx_sadeco_sadcfg3.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_GFEC                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_gfec_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   UFEC, PreScramble off and PostScramble on                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_OCFG_t tmp_n40g_otnt4x_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_ocfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OCFG));
  tmp_n40g_otnt4x_ocfg.bf.FECMD = 0;
  tmp_n40g_otnt4x_ocfg.bf.PRESCR = 0;
  tmp_n40g_otnt4x_ocfg.bf.POSTSCR = 1;
  tmp_n40g_otnt4x_ocfg.bf.FECEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OCFG), tmp_n40g_otnt4x_ocfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_UFEC                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_ufec_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_OCFG_t tmp_n40g_otnt4x_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_ocfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OCFG));
  tmp_n40g_otnt4x_ocfg.bf.FECMD = 1;
  tmp_n40g_otnt4x_ocfg.bf.PRESCR = 1;
  tmp_n40g_otnt4x_ocfg.bf.POSTSCR = 0;
  tmp_n40g_otnt4x_ocfg.bf.FECEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OCFG), tmp_n40g_otnt4x_ocfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_SM_BIP_INSERTION                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_sm_bip_insertion_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable OTU Section BIP insertion                                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CFG4_t tmp_n40g_otnt4x_cfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_cfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG4));
  tmp_n40g_otnt4x_cfg4.bf.BIPMSK = ((tmp_n40g_otnt4x_cfg4.bf.BIPMSK & ~0x80) | (0x80 & 0x80)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG4), tmp_n40g_otnt4x_cfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_NROWS                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_nrows_t41(cs_uint16 module_id,
                                cs_uint16 rows)
/* INPUTS     : o Module_id                                                   */
/*              o Rows                                                        */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG0_t tmp_n40g_otnt4x_wrpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG0));
  tmp_n40g_otnt4x_wrpcfg0.bf.NROWS = rows;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG0), tmp_n40g_otnt4x_wrpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_NCOLS                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_ncols_t41(cs_uint16 module_id,
                                cs_uint16 columns)
/* INPUTS     : o Module_id                                                   */
/*              o Columns                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG0_t tmp_n40g_otnt4x_wrpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG0));
  tmp_n40g_otnt4x_wrpcfg0.bf.NCOLS = columns;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG0), tmp_n40g_otnt4x_wrpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_NPAR                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_npar_t41(cs_uint16 module_id,
                               cs_uint16 parity)
/* INPUTS     : o Module_id                                                   */
/*              o Parity                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG2_t tmp_n40g_otnt4x_wrpcfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG2));
  tmp_n40g_otnt4x_wrpcfg2.bf.NPAR = parity;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG2), tmp_n40g_otnt4x_wrpcfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_NPARB                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_nparb_t41(cs_uint16 module_id,
                                cs_uint16 parity)
/* INPUTS     : o Module_id                                                   */
/*              o Parity                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG2_t tmp_n40g_otnt4x_wrpcfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG2));
  tmp_n40g_otnt4x_wrpcfg2.bf.NPARB = parity;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG2), tmp_n40g_otnt4x_wrpcfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}

/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OTU3                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_otu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Transmit OTU3 traffic                                                    */
/*   Calculate and Insert SM BIP                                              */
/*   WRMD = 3 to configure ODU3 to OTU3                                       */
/*   STM256MD and STM64MD = 0                                                 */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_n40g_otnt4x_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.OBY = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_ncols_t41(module_id, 254);
  ten_n40g_tx_npar_t41(module_id, 16);
  ten_n40g_tx_sm_bip_insertion_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.KPGBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
  tmp_n40g_otnt4x_wrpcfg3.bf.WRMD = 3;
  tmp_n40g_otnt4x_wrpcfg3.bf.STM256MD = 0;
  tmp_n40g_otnt4x_wrpcfg3.bf.STM64MD = 0;
  tmp_n40g_otnt4x_wrpcfg3.bf.AGGRMOD = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_n40g_otnt4x_wrpcfg3.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_gfec_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_ODU3                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_odu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Transmit ODU3 traffic                                                    */
/*   Calculate and Insert SM BIP                                              */
/*   WRMD = 0 to turn off dewrapper                                           */
/*   STM256MD and STM64MD = 0                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_n40g_otnt4x_wrpcfg3;
  TEN_N40G_OTNT4X_OCFG_t tmp_n40g_otnt4x_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.OBY = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_ncols_t41(module_id, 238);
  ten_n40g_tx_npar_t41(module_id, 0);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_ocfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OCFG));
  tmp_n40g_otnt4x_ocfg.bf.FECMD = 0;
  tmp_n40g_otnt4x_ocfg.bf.POSTSCR = 1;
  tmp_n40g_otnt4x_ocfg.bf.PRESCR = 0;
  tmp_n40g_otnt4x_ocfg.bf.FECEN = 0;
  
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OCFG), tmp_n40g_otnt4x_ocfg.wrd);

  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.KPGBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
  tmp_n40g_otnt4x_wrpcfg3.bf.WRMD = 0;
  tmp_n40g_otnt4x_wrpcfg3.bf.STM256MD = 0;
  tmp_n40g_otnt4x_wrpcfg3.bf.STM64MD = 0;
  tmp_n40g_otnt4x_wrpcfg3.bf.AGGRMOD = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_n40g_otnt4x_wrpcfg3.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_AGGR                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_aggr_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable aggregation.  Bypass OC768                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_n40g_otnt4x_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
  tmp_n40g_otnt4x_wrpcfg3.bf.AGGRMOD = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_n40g_otnt4x_wrpcfg3.wrd);

  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  tmp_n40g_gblt4x_cfg.bf.DSBLDSKW = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_TCMBIPINSERTION                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_tcmbipinsertion_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CFG4_t tmp_n40g_otnt4x_cfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_cfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG4));
  tmp_n40g_otnt4x_cfg4.bf.BIPMSK = ((tmp_n40g_otnt4x_cfg4.bf.BIPMSK & ~0x7E) | (0x7E & 0x7E)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG4), tmp_n40g_otnt4x_cfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PMBIPINSERTION                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_pmbipinsertion_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CFG4_t tmp_n40g_otnt4x_cfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_cfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG4));
  tmp_n40g_otnt4x_cfg4.bf.BIPMSK = ((tmp_n40g_otnt4x_cfg4.bf.BIPMSK & ~0x01) | (0x01 & 0x01)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG4), tmp_n40g_otnt4x_cfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OPU3                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_opu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_n40g_otnt4x_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
  tmp_n40g_otnt4x_wrpcfg3.bf.WRMD = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_n40g_otnt4x_wrpcfg3.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pmbipinsertion_t41(module_id);
  ten_n40g_tx_tcmbipinsertion_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_CBR40                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_cbr40_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Transparent Mode, Sonet is bypassed                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OC768_MSREGEN                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_oc768_msregen_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC768 layer, enables scramble and OC768 frame alignment                  */
/*   DPCFG should be set to 64-byte interleaving (MDPCFG=3) to match Rx MLDCFG*/
/*   so that overhead bytes can be properly monitored in N10G 16-byte         */
/*   interleaving (MDPCFG=2) is only for reverse multiplexing mode            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_ST4X_OHIE_t tmp_n40g_st4x_ohie;
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_n40g_otnt4x_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
  tmp_n40g_otnt4x_wrpcfg3.bf.STM256MD = 1;
  tmp_n40g_otnt4x_wrpcfg3.bf.STM64MD = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_n40g_otnt4x_wrpcfg3.wrd);

  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.KPGBY = 1;
  tmp_n40g_gblt4x_cfg.bf.MDPCFG = 3;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  tmp_n40g_st4x_ohie.bf.A1A2RSH = 1;
  tmp_n40g_st4x_ohie.bf.SCREN = 1;
  tmp_n40g_st4x_ohie.bf.B1IE = 1;
  tmp_n40g_st4x_ohie.bf.PRBSIE = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_n40g_st4x_ohie.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OC768_TRANSPARENT                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_oc768_transparent_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC768 transparent mode, layer, enables scramble and OC768 frame alignment*/
/*   MDPCFG should be set to generic splitting (MDPCFG=0) because data are    */
/*   traded as CBR40 in transparent mode                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_ST4X_OHIE_t tmp_n40g_st4x_ohie;
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_WRPCFG3_t tmp_n40g_otnt4x_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_wrpcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3));
  tmp_n40g_otnt4x_wrpcfg3.bf.STM256MD = 1;
  tmp_n40g_otnt4x_wrpcfg3.bf.STM64MD = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG3), tmp_n40g_otnt4x_wrpcfg3.wrd);

  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.KPGBY = 1;
  tmp_n40g_gblt4x_cfg.bf.MDPCFG = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  tmp_n40g_st4x_ohie.bf.PRBSIE = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_n40g_st4x_ohie.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OC768_OUT                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_oc768_out_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC768 outgoing traffic, OTN layer is disabled                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.OBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OTL34                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_otl34_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable OTN MLD, OTL3.4                                                   */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_GBLT4X_MLDTXCFG_t tmp_n40g_gblt4x_mldtxcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.MLDEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_gblt4x_mldtxcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, MLDTXCFG));
  tmp_n40g_gblt4x_mldtxcfg.bf.TX_MODE = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, MLDTXCFG), tmp_n40g_gblt4x_mldtxcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_STL256                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_stl256_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable SONET MLD, STL256                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_GBLT4X_MLDTXCFG_t tmp_n40g_gblt4x_mldtxcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.MLDEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_gblt4x_mldtxcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, MLDTXCFG));
  tmp_n40g_gblt4x_mldtxcfg.bf.TX_MODE = 1;
  tmp_n40g_gblt4x_mldtxcfg.bf.SKEW_EN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, MLDTXCFG), tmp_n40g_gblt4x_mldtxcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_125G_TS                                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_125g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.TSMODE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_25G_TS                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_25g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.TSMODE = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PT_ENABLE                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_pt_enable_t41(cs_uint16 module_id,
                                    cs_uint16 pt)
/* INPUTS     : o Module_id                                                   */
/*              o Pt                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CFG2_t tmp_n40g_otnt4x_cfg2;
  TEN_N40G_OTNT4X_CFG0_t tmp_n40g_otnt4x_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_cfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG2));
  tmp_n40g_otnt4x_cfg2.bf.PTI = pt;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG2), tmp_n40g_otnt4x_cfg2.wrd);

  tmp_n40g_otnt4x_cfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG0));
  tmp_n40g_otnt4x_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG0), tmp_n40g_otnt4x_cfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PT_DISABLE                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_pt_disable_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CFG0_t tmp_n40g_otnt4x_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_cfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG0));
  tmp_n40g_otnt4x_cfg0.bf.PTIE = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG0), tmp_n40g_otnt4x_cfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_AMP_LO                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_amp_lo_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   monolithic only                                                          */
/*   WRMD AGGRMD AMP_MODE  JCEN GMPMDi NTEN FSi NTMDi NTMD_MONO Wrapping Mode */
/*   01     0       x        1    0     0    0    x     x         AMP         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x01) | (0x01 & 0x01)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x2);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_AMP_TRIB                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_amp_trib_t41(cs_uint16 module_id,
                                   cs_uint16 trib)
/* INPUTS     : o Module_id                                                   */
/*              o Trib                                                        */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x1 << trib) | (0 & 0x1 << trib)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x20);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_AMP_TRIB_0                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_amp_trib_0_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Aggregation only, Tributary 0 AMP mapping                                */
/*   Payload type is programed to 2 for monolithic and will be overwritten if */
/*   it is aggregation when AMP_TRIB_1 ... are called.                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x01) | (0x00 & 0x01)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x20);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_AMP_TRIB_1                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_amp_trib_1_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Aggregation only, Tributary 1 AMP mapping                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x02) | (0x00 & 0x02)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x20);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_AMP_TRIB_2                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_amp_trib_2_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Aggregation only, Tributary 2 AMP mapping                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x04) | (0x00 & 0x04)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x20);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_AMP_TRIB_3                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_amp_trib_3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Aggregation only, Tributary 3 AMP mapping                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x08) | (0x00 & 0x08)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x20);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_GMP_HO_TRIB_0                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_gmp_ho_trib_0_t41(cs_uint16 module_id,
                                        cs_uint32 cn)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   HO GMP Tributary 0                                                       */
/*   Cn00= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn01= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_WRPCFG1_t tmp_n40g_otnt4x_wrpcfg1;
  TEN_N40G_OTNT4X_CMCFG0_t tmp_n40g_otnt4x_cmcfg0;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_125g_ts_t41(module_id);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD0 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  tmp_n40g_otnt4x_cmcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG0));
  tmp_n40g_otnt4x_cmcfg0.bf.CmInit = cn/8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG0), tmp_n40g_otnt4x_cmcfg0.wrd);

  tmp_n40g_otnt4x_wrpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1));
  tmp_n40g_otnt4x_wrpcfg1.bf.JCHYST = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1), tmp_n40g_otnt4x_wrpcfg1.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x21);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_GMP_HO_TRIB_1                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_gmp_ho_trib_1_t41(cs_uint16 module_id,
                                        cs_uint32 cn)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   HO GMP Tributary 1                                                       */
/*   Cn10= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn11= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CMCFG1_t tmp_n40g_otnt4x_cmcfg1;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_CNCFG11_t tmp_n40g_otnt4x_cncfg11;
  TEN_N40G_OTNT4X_CNCFG10_t tmp_n40g_otnt4x_cncfg10;
  TEN_N40G_OTNT4X_WRPCFG1_1_t tmp_n40g_otnt4x_wrpcfg1_1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_125g_ts_t41(module_id);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD1 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

  tmp_n40g_otnt4x_cncfg11.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG11));
  tmp_n40g_otnt4x_cncfg11.bf.Cn11 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG11), tmp_n40g_otnt4x_cncfg11.wrd);

  tmp_n40g_otnt4x_cncfg10.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG10));
  tmp_n40g_otnt4x_cncfg10.bf.Cn10 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG10), tmp_n40g_otnt4x_cncfg10.wrd);

  tmp_n40g_otnt4x_cmcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG1));
  tmp_n40g_otnt4x_cmcfg1.bf.CmInit = cn/8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG1), tmp_n40g_otnt4x_cmcfg1.wrd);

  tmp_n40g_otnt4x_wrpcfg1_1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_1));
  tmp_n40g_otnt4x_wrpcfg1_1.bf.JCHYST = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_1), tmp_n40g_otnt4x_wrpcfg1_1.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x21);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_GMP_HO_TRIB_2                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_gmp_ho_trib_2_t41(cs_uint16 module_id,
                                        cs_uint32 cn)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   HO GMP Tributary 2                                                       */
/*   Cn20= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn21= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CMCFG2_t tmp_n40g_otnt4x_cmcfg2;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_CNCFG21_t tmp_n40g_otnt4x_cncfg21;
  TEN_N40G_OTNT4X_WRPCFG1_2_t tmp_n40g_otnt4x_wrpcfg1_2;
  TEN_N40G_OTNT4X_CNCFG20_t tmp_n40g_otnt4x_cncfg20;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_125g_ts_t41(module_id);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD2 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

  tmp_n40g_otnt4x_cncfg21.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG21));
  tmp_n40g_otnt4x_cncfg21.bf.Cn21 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG21), tmp_n40g_otnt4x_cncfg21.wrd);

  tmp_n40g_otnt4x_cncfg20.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG20));
  tmp_n40g_otnt4x_cncfg20.bf.Cn20 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG20), tmp_n40g_otnt4x_cncfg20.wrd);

  tmp_n40g_otnt4x_cmcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG2));
  tmp_n40g_otnt4x_cmcfg2.bf.CmInit = cn/8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG2), tmp_n40g_otnt4x_cmcfg2.wrd);

  tmp_n40g_otnt4x_wrpcfg1_2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_2));
  tmp_n40g_otnt4x_wrpcfg1_2.bf.JCHYST = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_2), tmp_n40g_otnt4x_wrpcfg1_2.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x21);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_GMP_HO_TRIB_3                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_gmp_ho_trib_3_t41(cs_uint16 module_id,
                                        cs_uint32 cn)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   HO GMP Tributary 3                                                       */
/*   Cn30= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn31= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG1_3_t tmp_n40g_otnt4x_wrpcfg1_3;
  TEN_N40G_OTNT4X_CMCFG3_t tmp_n40g_otnt4x_cmcfg3;
  TEN_N40G_OTNT4X_CNCFG31_t tmp_n40g_otnt4x_cncfg31;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_CNCFG30_t tmp_n40g_otnt4x_cncfg30;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_125g_ts_t41(module_id);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD3 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

  tmp_n40g_otnt4x_cncfg31.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG31));
  tmp_n40g_otnt4x_cncfg31.bf.Cn31 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG31), tmp_n40g_otnt4x_cncfg31.wrd);

  tmp_n40g_otnt4x_cncfg30.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG30));
  tmp_n40g_otnt4x_cncfg30.bf.Cn30 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG30), tmp_n40g_otnt4x_cncfg30.wrd);

  tmp_n40g_otnt4x_cmcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG3));
  tmp_n40g_otnt4x_cmcfg3.bf.CmInit = cn/8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG3), tmp_n40g_otnt4x_cmcfg3.wrd);

  tmp_n40g_otnt4x_wrpcfg1_3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_3));
  tmp_n40g_otnt4x_wrpcfg1_3.bf.JCHYST = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1_3), tmp_n40g_otnt4x_wrpcfg1_3.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x21);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_GMP_HO_TSEN                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_gmp_ho_tsen_t41(cs_uint16 module_id,
                                      cs_uint16 tsen0,
                                      cs_uint16 tsen1)
/* INPUTS     : o Module_id                                                   */
/*              o Tsen0                                                       */
/*              o Tsen1                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPTSENABLE1_t tmp_n40g_otnt4x_wrptsenable1;
  TEN_N40G_OTNT4X_WRPTSENABLE0_t tmp_n40g_otnt4x_wrptsenable0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrptsenable0.wrd = tsen0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSENABLE0), tmp_n40g_otnt4x_wrptsenable0.wrd);

  tmp_n40g_otnt4x_wrptsenable1.wrd = tsen1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPTSENABLE1), tmp_n40g_otnt4x_wrptsenable1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}










/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_DETAMP_LO                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_detamp_lo_t41(cs_uint16 module_id,
                                    cs_uint16 dthyst)
/* INPUTS     : o Module_id                                                   */
/*              o Dthyst                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Deterministic AMP, aggregation tributary 0                               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRP0DH0_t tmp_n40g_otnt4x_wrp0dh0;
  TEN_N40G_OTNT4X_WRP0DH1_t tmp_n40g_otnt4x_wrp0dh1;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x01) | (0x01 & 0x01)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_wrp0dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH1));
  tmp_n40g_otnt4x_wrp0dh1.bf.DTHYST01 = dthyst >> 16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH1), tmp_n40g_otnt4x_wrp0dh1.wrd);

  tmp_n40g_otnt4x_wrp0dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH0));
  tmp_n40g_otnt4x_wrp0dh0.bf.DTHYST00 = dthyst % 65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH0), tmp_n40g_otnt4x_wrp0dh0.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x2);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_DETAMP_TRIB_0                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_detamp_trib_0_t41(cs_uint16 module_id,
                                        cs_uint16 dthyst)
/* INPUTS     : o Module_id                                                   */
/*              o Dthyst                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Deterministic AMP, aggregation tributary 0                               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRP0DH0_t tmp_n40g_otnt4x_wrp0dh0;
  TEN_N40G_OTNT4X_WRP0DH1_t tmp_n40g_otnt4x_wrp0dh1;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x01) | (0x01 & 0x01)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_wrp0dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH1));
  tmp_n40g_otnt4x_wrp0dh1.bf.DTHYST01 = dthyst >> 16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH1), tmp_n40g_otnt4x_wrp0dh1.wrd);

  tmp_n40g_otnt4x_wrp0dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH0));
  tmp_n40g_otnt4x_wrp0dh0.bf.DTHYST00 = dthyst % 65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH0), tmp_n40g_otnt4x_wrp0dh0.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x20);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_DETAMP_TRIB_1                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_detamp_trib_1_t41(cs_uint16 module_id,
                                        cs_uint16 dthyst)
/* INPUTS     : o Module_id                                                   */
/*              o Dthyst                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Deterministic AMP, aggregation tributary 1                               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRP1DH1_t tmp_n40g_otnt4x_wrp1dh1;
  TEN_N40G_OTNT4X_WRP1DH0_t tmp_n40g_otnt4x_wrp1dh0;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x02) | (0x02 & 0x02)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_wrp1dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH1));
  tmp_n40g_otnt4x_wrp1dh1.bf.DTHYST11 = dthyst >> 16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH1), tmp_n40g_otnt4x_wrp1dh1.wrd);

  tmp_n40g_otnt4x_wrp1dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH0));
  tmp_n40g_otnt4x_wrp1dh0.bf.DTHYST10 = dthyst % 65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH0), tmp_n40g_otnt4x_wrp1dh0.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x20);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_DETAMP_TRIB_2                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_detamp_trib_2_t41(cs_uint16 module_id,
                                        cs_uint16 dthyst)
/* INPUTS     : o Module_id                                                   */
/*              o Dthyst                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Deterministic AMP, aggregation tributary 2                               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRP2DH0_t tmp_n40g_otnt4x_wrp2dh0;
  TEN_N40G_OTNT4X_WRP2DH1_t tmp_n40g_otnt4x_wrp2dh1;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x04) | (0x04 & 0x04)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_wrp2dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH1));
  tmp_n40g_otnt4x_wrp2dh1.bf.DTHYST21 = dthyst >> 16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH1), tmp_n40g_otnt4x_wrp2dh1.wrd);

  tmp_n40g_otnt4x_wrp2dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH0));
  tmp_n40g_otnt4x_wrp2dh0.bf.DTHYST20 = dthyst % 65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH0), tmp_n40g_otnt4x_wrp2dh0.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x20);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_DETAMP_TRIB_3                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_detamp_trib_3_t41(cs_uint16 module_id,
                                        cs_uint16 dthyst)
/* INPUTS     : o Module_id                                                   */
/*              o Dthyst                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Deterministic AMP, aggregation tributary 3                               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRP3DH1_t tmp_n40g_otnt4x_wrp3dh1;
  TEN_N40G_OTNT4X_WRP3DH0_t tmp_n40g_otnt4x_wrp3dh0;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x08) | (0x08 & 0x08)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_wrp3dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH1));
  tmp_n40g_otnt4x_wrp3dh1.bf.DTHYST31 = dthyst >> 16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH1), tmp_n40g_otnt4x_wrp3dh1.wrd);

  tmp_n40g_otnt4x_wrp3dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH0));
  tmp_n40g_otnt4x_wrp3dh0.bf.DTHYST30 = dthyst % 65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH0), tmp_n40g_otnt4x_wrp3dh0.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x20);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_DETGMP_HO_TRIB_0                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_detgmp_ho_trib_0_t41(cs_uint16 module_id,
                                           cs_uint32 cn,
                                           cs_uint16 dthyst)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/*              o Dthyst                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Determinstic HO GMP Tributary 0                                          */
/*   Cn00= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn01= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRP0DH0_t tmp_n40g_otnt4x_wrp0dh0;
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_WRP0DH1_t tmp_n40g_otnt4x_wrp0dh1;
  TEN_N40G_OTNT4X_CMCFG0_t tmp_n40g_otnt4x_cmcfg0;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_125g_ts_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD0 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  tmp_n40g_otnt4x_cmcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG0));
  tmp_n40g_otnt4x_cmcfg0.bf.CmInit = cn/8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG0), tmp_n40g_otnt4x_cmcfg0.wrd);

  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x01) | (0x01 & 0x01)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_wrp0dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH1));
  tmp_n40g_otnt4x_wrp0dh1.bf.DTHYST01 = dthyst >> 16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH1), tmp_n40g_otnt4x_wrp0dh1.wrd);

  tmp_n40g_otnt4x_wrp0dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH0));
  tmp_n40g_otnt4x_wrp0dh0.bf.DTHYST00 = dthyst % 65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH0), tmp_n40g_otnt4x_wrp0dh0.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x21);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_DETGMP_HO_TRIB_1                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_detgmp_ho_trib_1_t41(cs_uint16 module_id,
                                           cs_uint32 cn,
                                           cs_uint16 dthyst)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/*              o Dthyst                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Determinstic HO GMP Tributary 1                                          */
/*   Cn10= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn11= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CMCFG1_t tmp_n40g_otnt4x_cmcfg1;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_WRP1DH1_t tmp_n40g_otnt4x_wrp1dh1;
  TEN_N40G_OTNT4X_CNCFG11_t tmp_n40g_otnt4x_cncfg11;
  TEN_N40G_OTNT4X_WRP1DH0_t tmp_n40g_otnt4x_wrp1dh0;
  TEN_N40G_OTNT4X_CNCFG10_t tmp_n40g_otnt4x_cncfg10;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_125g_ts_t41(module_id);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD1 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

  tmp_n40g_otnt4x_cncfg11.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG11));
  tmp_n40g_otnt4x_cncfg11.bf.Cn11 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG11), tmp_n40g_otnt4x_cncfg11.wrd);

  tmp_n40g_otnt4x_cncfg10.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG10));
  tmp_n40g_otnt4x_cncfg10.bf.Cn10 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG10), tmp_n40g_otnt4x_cncfg10.wrd);

  tmp_n40g_otnt4x_cmcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG1));
  tmp_n40g_otnt4x_cmcfg1.bf.CmInit = cn/8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG1), tmp_n40g_otnt4x_cmcfg1.wrd);

  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x02) | (0x02 & 0x02)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_wrp1dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH1));
  tmp_n40g_otnt4x_wrp1dh1.bf.DTHYST11 = dthyst>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH1), tmp_n40g_otnt4x_wrp1dh1.wrd);

  tmp_n40g_otnt4x_wrp1dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH0));
  tmp_n40g_otnt4x_wrp1dh0.bf.DTHYST10 = dthyst % 65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH0), tmp_n40g_otnt4x_wrp1dh0.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x21);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_DETGMP_HO_TRIB_2                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_detgmp_ho_trib_2_t41(cs_uint16 module_id,
                                           cs_uint32 cn,
                                           cs_uint16 dthyst)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/*              o Dthyst                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Determinstic HO GMP Tributary 2                                          */
/*   Cn20= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn21= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRP2DH0_t tmp_n40g_otnt4x_wrp2dh0;
  TEN_N40G_OTNT4X_CMCFG2_t tmp_n40g_otnt4x_cmcfg2;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_CNCFG21_t tmp_n40g_otnt4x_cncfg21;
  TEN_N40G_OTNT4X_CNCFG20_t tmp_n40g_otnt4x_cncfg20;
  TEN_N40G_OTNT4X_WRP2DH1_t tmp_n40g_otnt4x_wrp2dh1;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_125g_ts_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD2 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

  tmp_n40g_otnt4x_cncfg21.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG21));
  tmp_n40g_otnt4x_cncfg21.bf.Cn21 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG21), tmp_n40g_otnt4x_cncfg21.wrd);

  tmp_n40g_otnt4x_cncfg20.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG20));
  tmp_n40g_otnt4x_cncfg20.bf.Cn20 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG20), tmp_n40g_otnt4x_cncfg20.wrd);

  tmp_n40g_otnt4x_cmcfg2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG2));
  tmp_n40g_otnt4x_cmcfg2.bf.CmInit = cn/8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG2), tmp_n40g_otnt4x_cmcfg2.wrd);

  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x04) | (0x04 & 0x04)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_wrp2dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH1));
  tmp_n40g_otnt4x_wrp2dh1.bf.DTHYST21 = dthyst>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH1), tmp_n40g_otnt4x_wrp2dh1.wrd);

  tmp_n40g_otnt4x_wrp2dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH0));
  tmp_n40g_otnt4x_wrp2dh0.bf.DTHYST20 = dthyst % 65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH0), tmp_n40g_otnt4x_wrp2dh0.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x21);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_DETGMP_HO_TRIB_3                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_detgmp_ho_trib_3_t41(cs_uint16 module_id,
                                           cs_uint32 cn,
                                           cs_uint16 dthyst)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/*              o Dthyst                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Determinstic HO GMP Tributary 3                                          */
/*   Cn30= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn31= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CMCFG3_t tmp_n40g_otnt4x_cmcfg3;
  TEN_N40G_OTNT4X_CNCFG31_t tmp_n40g_otnt4x_cncfg31;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_WRP3DH1_t tmp_n40g_otnt4x_wrp3dh1;
  TEN_N40G_OTNT4X_WRP3DH0_t tmp_n40g_otnt4x_wrp3dh0;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  TEN_N40G_OTNT4X_CNCFG30_t tmp_n40g_otnt4x_cncfg30;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_125g_ts_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD3 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

  tmp_n40g_otnt4x_cncfg31.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG31));
  tmp_n40g_otnt4x_cncfg31.bf.Cn31 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG31), tmp_n40g_otnt4x_cncfg31.wrd);

  tmp_n40g_otnt4x_cncfg30.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG30));
  tmp_n40g_otnt4x_cncfg30.bf.Cn30 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG30), tmp_n40g_otnt4x_cncfg30.wrd);

  tmp_n40g_otnt4x_cmcfg3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG3));
  tmp_n40g_otnt4x_cmcfg3.bf.CmInit = cn/8;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CMCFG3), tmp_n40g_otnt4x_cmcfg3.wrd);

  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = ((tmp_n40g_otnt4x_wrpcfg4.bf.JCEN & ~0x08) | (0x08 & 0x08)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_wrp3dh1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH1));
  tmp_n40g_otnt4x_wrp3dh1.bf.DTHYST31 = dthyst>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH1), tmp_n40g_otnt4x_wrp3dh1.wrd);

  tmp_n40g_otnt4x_wrp3dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH0));
  tmp_n40g_otnt4x_wrp3dh0.bf.DTHYST30 = dthyst % 65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH0), tmp_n40g_otnt4x_wrp3dh0.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x21);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_GMP_LO                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_gmp_lo_t41(cs_uint16 module_id,
                                 cs_uint32 cn)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_GMPCFG1_t tmp_n40g_otnt4x_gmpcfg1;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_125g_ts_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = 0x01;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_gmpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1));
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD0 = 1;
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD1 = 0;
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD2 = 0;
  tmp_n40g_otnt4x_gmpcfg1.bf.GMPMD3 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPCFG1), tmp_n40g_otnt4x_gmpcfg1.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = cn % 65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x2);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PROPMAP_LO                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_propmap_lo_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Cortina Propertory Mapping at OxU3 level, asynchronous mapping           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG1_t tmp_n40g_otnt4x_wrpcfg1;
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JC_PLUS = 0x01;
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = 0x01;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  tmp_n40g_otnt4x_wrpcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1));
  tmp_n40g_otnt4x_wrpcfg1.bf.JCHYST = 0x00;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG1), tmp_n40g_otnt4x_wrpcfg1.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_25g_ts_t41(module_id);
  ten_n40g_tx_pt_enable_t41(module_id, 0x2);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PROPMAP_HO                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_propmap_ho_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Cortina Propertory Mapping at OxU3 level, asynchronous mapping           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_WRPCFG4_t tmp_n40g_otnt4x_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpcfg4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4));
  tmp_n40g_otnt4x_wrpcfg4.bf.JC_PLUS = 0x0;
  tmp_n40g_otnt4x_wrpcfg4.bf.JCEN = 0x0f;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPCFG4), tmp_n40g_otnt4x_wrpcfg4.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_25g_ts_t41(module_id);
  ten_n40g_tx_pt_enable_t41(module_id, 0x20);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PKT_BYPASS                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_pkt_bypass_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40G traffic bypass the whole N40G; this is not same as quad 10g bypass   */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.OBY = 1;
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  tmp_n40g_gblt4x_cfg.bf.KPGBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_UFEC7                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_ufec7_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_ufec_t41(module_id);
  ten_n40g_tx_nrows_t41(module_id, 3);
  ten_n40g_tx_ncols_t41(module_id, 254);
  ten_n40g_tx_npar_t41(module_id, 16);
  ten_n40g_tx_nparb_t41(module_id, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_UFEC10                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_ufec10_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_ufec_t41(module_id);
  ten_n40g_tx_nrows_t41(module_id, 3);
  ten_n40g_tx_ncols_t41(module_id, 261);
  ten_n40g_tx_npar_t41(module_id, 23);
  ten_n40g_tx_nparb_t41(module_id, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_UFEC12                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_ufec12_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_ufec_t41(module_id);
  ten_n40g_tx_nrows_t41(module_id, 3);
  ten_n40g_tx_ncols_t41(module_id, 266);
  ten_n40g_tx_npar_t41(module_id, 28);
  ten_n40g_tx_nparb_t41(module_id, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_UFEC26                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_ufec26_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_ufec_t41(module_id);
  ten_n40g_tx_nrows_t41(module_id, 3);
  ten_n40g_tx_ncols_t41(module_id, 300);
  ten_n40g_tx_npar_t41(module_id, 62);
  ten_n40g_tx_nparb_t41(module_id, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_UFEC25                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_ufec25_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_ufec_t41(module_id);
  ten_n40g_tx_nrows_t41(module_id, 3);
  ten_n40g_tx_ncols_t41(module_id, 296);
  ten_n40g_tx_npar_t41(module_id, 58);
  ten_n40g_tx_nparb_t41(module_id, 0);
  return (CS_OK);
}



/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OTN_SCR_OFF                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_otn_scr_off_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_OCFG_t tmp_n40g_otnt4x_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_ocfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OCFG));
  tmp_n40g_otnt4x_ocfg.bf.PRESCR = 0;
  tmp_n40g_otnt4x_ocfg.bf.POSTSCR = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OCFG), tmp_n40g_otnt4x_ocfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OC768_SCR_OFF                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_oc768_scr_off_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_ST4X_OHIE_t tmp_n40g_st4x_ohie;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  tmp_n40g_st4x_ohie.bf.SCREN = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_n40g_st4x_ohie.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_FEC_DATAPATH_BYPASS                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_fec_datapath_bypass_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bypasses the FEC datapath for sims that have FEC blocks instantiated but */
/*     not running                                                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNT4X_OCFG_t tmp_n40g_otnt4x_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_ocfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OCFG));
  tmp_n40g_otnt4x_ocfg.bf.FECEN = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OCFG), tmp_n40g_otnt4x_ocfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PRBS_OC768                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_prbs_oc768_t41(cs_uint16 module_id,
                                     cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS in OC768.  PRBS pattern in KPG (defaults to PRBS31)                 */
/*   OC768 outgoing traffic, OTN layer is disabled                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_ST4X_OHIE_t tmp_n40g_st4x_ohie;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_n40g_gblt4x_kpgcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_oc768_out_t41(module_id);
  ten_n40g_tx_oc768_msregen_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  tmp_n40g_st4x_ohie.bf.A1A2RSH = 0;
  tmp_n40g_st4x_ohie.bf.A1A2IE = 1;
  tmp_n40g_st4x_ohie.bf.PRBSIE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_n40g_st4x_ohie.wrd);

  tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
  tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PRBS_OTU3                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_prbs_otu3_t41(cs_uint16 module_id,
                                    cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS=>OPU3=>ODU3=>OTU3.  PRBS pattern in KPG (defaults to PRBS31)        */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_n40g_gblt4x_kpgcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  ten_n40g_tx_pt_enable_t41(module_id, 0xfe);
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.KPGBY = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
  tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PRBS_OC768_OTU3                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_prbs_oc768_otu3_t41(cs_uint16 module_id,
                                          cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS in OC768 in OTU3.  PRBS pattern in KPG (defaults to PRBS31)         */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_ST4X_OHIE_t tmp_n40g_st4x_ohie;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_n40g_gblt4x_kpgcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_oc768_msregen_t41(module_id);
  ten_n40g_tx_pt_enable_t41(module_id, 0x3);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  tmp_n40g_st4x_ohie.bf.A1A2RSH = 0;
  tmp_n40g_st4x_ohie.bf.A1A2IE = 1;
  tmp_n40g_st4x_ohie.bf.PRBSIE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_n40g_st4x_ohie.wrd);

  tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
  tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_CBR_OTU3_OTL34                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_cbr_otu3_otl34_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   CBR in OTU3 in OTL3.4 (OTN MLD), BMP                                     */
/*   Enable OTN MLD, OTL3.4                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otl34_t41(module_id);
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_ODU3_OTU3                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_odu3_otu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU3 layer termination only, FEC overhead bytes are removed and ODU3     */
/*     layer is untouched                                                     */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_ODU3E1_OTU3E1                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_odu3e1_otu3e1_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU3E1 to OTU3E1                                                         */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_ODU3E2_OTU3E2                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_odu3e2_otu3e2_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU3E2 to OTU3E2                                                         */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_ODU3_GMP_LO_OTU3E2                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_odu3_gmp_lo_otu3e2_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU3 to OTU3E2, Low Order GMP                                            */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 14759;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_40GE_GMP_LO_OTU3                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_40ge_gmp_lo_otu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3, LO GMP                                                     */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 15219;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_40GE_GMP_LO_ODU3                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_40ge_gmp_lo_odu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in ODU3, LO GMP                                                     */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_odu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 15219;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_40GE_GMP_LO_OTU3_25U                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_40ge_gmp_lo_otu3_25u_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3, 25% UFEC, LO GMP                                           */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_gmp_lo_t41(module_id, 15232);
  ten_n40g_tx_ufec25_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 15219;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_40GE_GMP_LO_OTU3_OTL34                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_40ge_gmp_lo_otu3_otl34_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3 in OTL3.4 (OTN MLD), LO GMP                                 */
/*   Enable OTN MLD, OTL3.4                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otl34_t41(module_id);
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 15219;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_40GE_GMP_LO_OTU3E2                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_40ge_gmp_lo_otu3e2_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3E2, LO GMP                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 15100;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_40GE_GMP_LO_OTU3E2_PPM                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_40ge_gmp_lo_otu3e2_ppm_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3E2, LO GMP                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 15101;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_40GE_GMP_LO_OTU3E1                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_40ge_gmp_lo_otu3e1_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3E1, LO GMP                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_CNCFG00_t tmp_n40g_otnt4x_cncfg00;
  TEN_N40G_OTNT4X_CNCFG01_t tmp_n40g_otnt4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01));
  tmp_n40g_otnt4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG01), tmp_n40g_otnt4x_cncfg01.wrd);

  tmp_n40g_otnt4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00));
  tmp_n40g_otnt4x_cncfg00.bf.Cn00 = 14817;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, otnt4x_CNCFG00), tmp_n40g_otnt4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_40GE_PROPMAP_LO_OTU3E1                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_40ge_propmap_lo_otu3e1_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE_PROPMAP_LO_OTU3E1                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/*   Cortina Propertory Mapping at OxU3 level, asynchronous mapping           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_WRPFS0_t tmp_n40g_otnt4x_wrpfs0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_propmap_lo_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_wrpfs0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS0));
  tmp_n40g_otnt4x_wrpfs0.bf.FS0 = 127;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS0), tmp_n40g_otnt4x_wrpfs0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_40GE_FS96_OTU3                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_40ge_fs96_otu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   for erratum12 - no justification - FS = 96 bytes                         */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_WRPFS0_t tmp_n40g_otnt4x_wrpfs0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_wrpfs0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS0));
  tmp_n40g_otnt4x_wrpfs0.bf.FS0 = 96;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS0), tmp_n40g_otnt4x_wrpfs0.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x3);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_40GE_FS32_OTU3                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_40ge_fs32_otu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   for erratum12 - no justification - FS = 32 bytes                         */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_OTNT4X_WRPFS0_t tmp_n40g_otnt4x_wrpfs0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_otnt4x_wrpfs0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS0));
  tmp_n40g_otnt4x_wrpfs0.bf.FS0 = 32;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPFS0), tmp_n40g_otnt4x_wrpfs0.wrd);
 
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x3);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_125G_TS_ODTU_OTU3                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_125g_ts_odtu_otu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   125G_TS_ODTU_OTU3                                                        */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   Enable aggregation.  Bypass OC768                                        */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_aggr_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_125g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_125G_TS_ODTU_OTU3E2                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_125g_ts_odtu_otu3e2_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   125G_TS_ODTU_OTU3E2                                                      */
/*   125G_TS_ODTU_OTU3                                                        */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   Enable aggregation.  Bypass OC768                                        */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_125g_ts_odtu_otu3_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_25G_TS_ODTU_OTU3                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_25g_ts_odtu_otu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   25G_TS_ODTU_OTU3                                                         */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   Enable aggregation.  Bypass OC768                                        */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_aggr_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_25g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_25G_TS_ODTU_OTU3E1                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_25g_ts_odtu_otu3e1_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   25G_TS_ODTU_OTU3E1 for 40GEP lanes                                       */
/*   Async justification with 2 C15 per TRIB is used                          */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   Enable aggregation.  Bypass OC768                                        */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/*   Cortina Propertory Mapping at OxU3 level, asynchronous mapping           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBL4X_SYNCCFG_t tmp_n40g_gbl4x_synccfg;
  TEN_N40G_OTNT4X_WRPC15EN1_t tmp_n40g_otnt4x_wrpc15en1;
  TEN_N40G_GBL4X_SYNCPER_t tmp_n40g_gbl4x_syncper;
  TEN_N40G_OTNT4X_WRPC15EN0_t tmp_n40g_otnt4x_wrpc15en0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_aggr_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_propmap_ho_t41(module_id);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0));
  tmp_n40g_otnt4x_wrpc15en0.bf.C15RES_EN0 = 1;
  tmp_n40g_otnt4x_wrpc15en0.bf.C15RES_EN1 = 1;
  tmp_n40g_otnt4x_wrpc15en0.bf.C15RES_EN2 = 1;
  tmp_n40g_otnt4x_wrpc15en0.bf.C15RES_EN3 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0), tmp_n40g_otnt4x_wrpc15en0.wrd);

  tmp_n40g_otnt4x_wrpc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1));
  tmp_n40g_otnt4x_wrpc15en1.bf.C15RES_EN4 = 1;
  tmp_n40g_otnt4x_wrpc15en1.bf.C15RES_EN5 = 1;
  tmp_n40g_otnt4x_wrpc15en1.bf.C15RES_EN6 = 1;
  tmp_n40g_otnt4x_wrpc15en1.bf.C15RES_EN7 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1), tmp_n40g_otnt4x_wrpc15en1.wrd);

  tmp_n40g_gbl4x_synccfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, SYNCCFG));
  tmp_n40g_gbl4x_synccfg.bf.N10G_SYNC_EN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, SYNCCFG), tmp_n40g_gbl4x_synccfg.wrd);

  tmp_n40g_gbl4x_syncper.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, SYNCPER));
  tmp_n40g_gbl4x_syncper.bf.FRMPERIOD = 3824;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, SYNCPER), tmp_n40g_gbl4x_syncper.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_25g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_25G_TS_ODTU_OTU3E1_DT                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_25g_ts_odtu_otu3e1_dt_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   25G_TS_ODTU_OTU3E1 for 40GEP lanes                                       */
/*   DT justification for HC not syncdsync                                    */
/*   2 C15 per TRIB, DHYST = is used                                          */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   Enable aggregation.  Bypass OC768                                        */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/*   Cortina Propertory Mapping at OxU3 level, asynchronous mapping           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBL4X_SYNCCFG_t tmp_n40g_gbl4x_synccfg;
  TEN_N40G_OTNT4X_WRP0DH0_t tmp_n40g_otnt4x_wrp0dh0;
  TEN_N40G_OTNT4X_WRP2DH0_t tmp_n40g_otnt4x_wrp2dh0;
  TEN_N40G_OTNT4X_WRPC15EN1_t tmp_n40g_otnt4x_wrpc15en1;
  TEN_N40G_OTNT4X_WRP3DH0_t tmp_n40g_otnt4x_wrp3dh0;
  TEN_N40G_OTNT4X_WRP1DH0_t tmp_n40g_otnt4x_wrp1dh0;
  TEN_N40G_GBL4X_SYNCPER_t tmp_n40g_gbl4x_syncper;
  TEN_N40G_OTNT4X_WRPC15EN0_t tmp_n40g_otnt4x_wrpc15en0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_aggr_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_propmap_ho_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnt4x_wrpc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0));
  tmp_n40g_otnt4x_wrpc15en0.bf.C15RES_EN0 = 1;
  tmp_n40g_otnt4x_wrpc15en0.bf.C15RES_EN1 = 1;
  tmp_n40g_otnt4x_wrpc15en0.bf.C15RES_EN2 = 1;
  tmp_n40g_otnt4x_wrpc15en0.bf.C15RES_EN3 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN0), tmp_n40g_otnt4x_wrpc15en0.wrd);

  tmp_n40g_otnt4x_wrpc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1));
  tmp_n40g_otnt4x_wrpc15en1.bf.C15RES_EN4 = 1;
  tmp_n40g_otnt4x_wrpc15en1.bf.C15RES_EN5 = 1;
  tmp_n40g_otnt4x_wrpc15en1.bf.C15RES_EN6 = 1;
  tmp_n40g_otnt4x_wrpc15en1.bf.C15RES_EN7 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRPC15EN1), tmp_n40g_otnt4x_wrpc15en1.wrd);

  tmp_n40g_otnt4x_wrp0dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH0));
  tmp_n40g_otnt4x_wrp0dh0.bf.DTHYST00 = 3923;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP0DH0), tmp_n40g_otnt4x_wrp0dh0.wrd);

  tmp_n40g_otnt4x_wrp1dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH0));
  tmp_n40g_otnt4x_wrp1dh0.bf.DTHYST10 = 3923;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP1DH0), tmp_n40g_otnt4x_wrp1dh0.wrd);

  tmp_n40g_otnt4x_wrp2dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH0));
  tmp_n40g_otnt4x_wrp2dh0.bf.DTHYST20 = 3923;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP2DH0), tmp_n40g_otnt4x_wrp2dh0.wrd);

  tmp_n40g_otnt4x_wrp3dh0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH0));
  tmp_n40g_otnt4x_wrp3dh0.bf.DTHYST30 = 3923;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, WRP3DH0), tmp_n40g_otnt4x_wrp3dh0.wrd);

  tmp_n40g_gbl4x_synccfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, SYNCCFG));
  tmp_n40g_gbl4x_synccfg.bf.N10G_SYNC_EN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, SYNCCFG), tmp_n40g_gbl4x_synccfg.wrd);

  tmp_n40g_gbl4x_syncper.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, SYNCPER));
  tmp_n40g_gbl4x_syncper.bf.FRMPERIOD = 3824;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, SYNCPER), tmp_n40g_gbl4x_syncper.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_25g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_25G_TS_ODTU_OTU310U_OTL34                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_25g_ts_odtu_otu310u_otl34_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   25G_TS_ODTU_OTU310U_OTL34                                                */
/*   Enable OTN MLD, OTL3.4                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   Enable aggregation.  Bypass OC768                                        */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_otl34_t41(module_id);
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_aggr_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_25g_ts_t41(module_id);
  ten_n40g_tx_ufec10_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_125G_TS_ODTU_OTU310U_OTL34                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_125g_ts_odtu_otu310u_otl34_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   125G_TS_ODTU_OTU310U_OTL34                                               */
/*   Enable OTN MLD, OTL3.4                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   Enable aggregation.  Bypass OC768                                        */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_otl34_t41(module_id);
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_aggr_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_125g_ts_t41(module_id);
  ten_n40g_tx_ufec10_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_25G_TS_ODTU23P_OTU3P                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_25g_ts_odtu23p_otu3p_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   25G_TS_ODTU23P_OTU3P                                                     */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   Enable aggregation.  Bypass OC768                                        */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_aggr_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_25g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OC768_STL256                                      */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_oc768_stl256_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC768_STL256                                                             */
/*   Enable SONET MLD, STL256                                                 */
/*   OC768 outgoing traffic, OTN layer is disabled                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_stl256_t41(module_id);
  ten_n40g_tx_oc768_out_t41(module_id);
  ten_n40g_tx_oc768_msregen_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PRBS_OC768_STL256                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_prbs_oc768_stl256_t41(cs_uint16 module_id,
                                            cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS_OC768_STL256                                                        */
/*   OC768_STL256                                                             */
/*   Enable SONET MLD, STL256                                                 */
/*   OC768 outgoing traffic, OTN layer is disabled                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_ST4X_OHIE_t tmp_n40g_st4x_ohie;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_n40g_gblt4x_kpgcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_oc768_stl256_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  tmp_n40g_st4x_ohie.bf.A1A2RSH = 0;
  tmp_n40g_st4x_ohie.bf.A1A2IE = 1;
  tmp_n40g_st4x_ohie.bf.PRBSIE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_n40g_st4x_ohie.wrd);

  tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
  tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OC768_OTU3_OTL34                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_oc768_otu3_otl34_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC768_OTU3_OTL34                                                         */
/*   Enable OTN MLD, OTL3.4                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_otl34_t41(module_id);
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_oc768_msregen_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PRBS_OC768_OTU3_OTL34                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_prbs_oc768_otu3_otl34_t41(cs_uint16 module_id,
                                                cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS_OC768_OTU3_OTL34.  PRBS pattern in KPG (defaults to PRBS31)         */
/*   Enable OTN MLD, OTL3.4                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_ST4X_OHIE_t tmp_n40g_st4x_ohie;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_n40g_gblt4x_kpgcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_otl34_t41(module_id);
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_oc768_msregen_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  tmp_n40g_st4x_ohie.bf.A1A2RSH = 0;
  tmp_n40g_st4x_ohie.bf.A1A2IE = 1;
  tmp_n40g_st4x_ohie.bf.PRBSIE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_n40g_st4x_ohie.wrd);

  tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
  tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_tx_pt_enable_t41(module_id, 0x3);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_ODU3_OTU3_OTL34                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_odu3_otu3_otl34_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU3_OTU3_OTL34                                                          */
/*   Enable OTN MLD, OTL3.4                                                   */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otl34_t41(module_id);
  ten_n40g_tx_otu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}




/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OC768_TRANSPARENT_ODU3                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_oc768_transparent_odu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bypass Tx STM256 then mapping to ODU3                                    */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_odu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_oc768_transparent_t41(module_id);
  ten_n40g_tx_pt_enable_t41(module_id, 0x3);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PRBS_OUT                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_prbs_out_t41(cs_uint16 module_id,
                                   cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS=>Out                                                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_n40g_gblt4x_kpgcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.OBY = 1;
  tmp_n40g_gblt4x_cfg.bf.KPGBY = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
  tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PRBS_ODU3                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_prbs_odu3_t41(cs_uint16 module_id,
                                    cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS=>OPU3=>ODU3.  PRBS pattern in KPG (defaults to PRBS31)              */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_n40g_gblt4x_kpgcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_odu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  ten_n40g_tx_pt_enable_t41(module_id, 0xfe);
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.KPGBY = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
  tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_PRBS_OC768_ODU3                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_prbs_oc768_odu3_t41(cs_uint16 module_id,
                                          cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS in OC768 in OTU3.  PRBS pattern in KPG (defaults to PRBS31)         */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_ST4X_OHIE_t tmp_n40g_st4x_ohie;
  TEN_N40G_GBLT4X_KPGCFG_t tmp_n40g_gblt4x_kpgcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_odu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_oc768_msregen_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  tmp_n40g_st4x_ohie.bf.A1A2RSH = 0;
  tmp_n40g_st4x_ohie.bf.A1A2IE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_n40g_st4x_ohie.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_tx_pt_enable_t41(module_id, 0x3);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_n40g_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  tmp_n40g_st4x_ohie.bf.PRBSIE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_n40g_st4x_ohie.wrd);

  tmp_n40g_gblt4x_kpgcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG));
  tmp_n40g_gblt4x_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, KPGCFG), tmp_n40g_gblt4x_kpgcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_OC768_ODU3                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_oc768_odu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC768 in ODU3                                                            */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_odu3_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_oc768_msregen_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_N10G_ODU3AGGR_OTU3                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_n10g_odu3aggr_otu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Wraps N10G ODTU23 traffic into OTU3                                      */
/*   Enable OTU Section BIP insertion                                         */
/*   UFEC, PreScramble off and PostScramble on                                */
/*   Enable aggregation.  Bypass OC768                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLT4X_CFG_t tmp_n40g_gblt4x_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_tx_otu3_t41(module_id);
  ten_n40g_tx_aggr_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblt4x_cfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, CFG));
  tmp_n40g_gblt4x_cfg.bf.KPGBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, CFG), tmp_n40g_gblt4x_cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_TX_125G_TS_ODTU_ODU3                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_tx_125g_ts_odtu_odu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   125G_TS_ODTU_ODU3                                                        */
/*   Enable aggregation.  Bypass OC768                                        */
/*   OPU3 layer, dewrapper is enabled                                         */
/*   Enable PM BIP insertion                                                  */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_tx_odu3_t41(module_id);
  ten_n40g_tx_aggr_t41(module_id);
  ten_n40g_tx_opu3_t41(module_id);
  ten_n40g_tx_125g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_GFEC                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_gfec_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_OACFG0_t tmp_n40g_otnr4x_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_n40g_otnr4x_oacfg0.bf.FECMD = 0;
  tmp_n40g_otnr4x_oacfg0.bf.PREDSCR = 1;
  tmp_n40g_otnr4x_oacfg0.bf.POSTDSCR = 0;
  tmp_n40g_otnr4x_oacfg0.bf.FECEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_n40g_otnr4x_oacfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_UFEC                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_ufec_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDeScramble on and PostDeScramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_OACFG0_t tmp_n40g_otnr4x_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_n40g_otnr4x_oacfg0.bf.FECMD = 1;
  tmp_n40g_otnr4x_oacfg0.bf.PREDSCR = 0;
  tmp_n40g_otnr4x_oacfg0.bf.POSTDSCR = 1;
  tmp_n40g_otnr4x_oacfg0.bf.FECEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_n40g_otnr4x_oacfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_NROWS                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_nrows_t41(cs_uint16 module_id,
                                cs_uint16 rows)
/* INPUTS     : o Module_id                                                   */
/*              o Rows                                                        */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_OFCFG0_t tmp_n40g_otnr4x_ofcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_ofcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG0));
  tmp_n40g_otnr4x_ofcfg0.bf.NROWS = rows;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG0), tmp_n40g_otnr4x_ofcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_NCOLS                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_ncols_t41(cs_uint16 module_id,
                                cs_uint16 columns)
/* INPUTS     : o Module_id                                                   */
/*              o Columns                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_OFCFG0_t tmp_n40g_otnr4x_ofcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_ofcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG0));
  tmp_n40g_otnr4x_ofcfg0.bf.NCOLS = columns;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG0), tmp_n40g_otnr4x_ofcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_NPAR                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_npar_t41(cs_uint16 module_id,
                               cs_uint16 parity)
/* INPUTS     : o Module_id                                                   */
/*              o Parity                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_OFCFG1_t tmp_n40g_otnr4x_ofcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_ofcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG1));
  tmp_n40g_otnr4x_ofcfg1.bf.NPAR = parity;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG1), tmp_n40g_otnr4x_ofcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_NPARB                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_nparb_t41(cs_uint16 module_id,
                                cs_uint16 parity)
/* INPUTS     : o Module_id                                                   */
/*              o Parity                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_OFCFG1_t tmp_n40g_otnr4x_ofcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_ofcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG1));
  tmp_n40g_otnr4x_ofcfg1.bf.NPARB = parity;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OFCFG1), tmp_n40g_otnr4x_ofcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receiving OTU3 traffic                                                   */
/*   BYSEL = 0, BYSEL1 = 0, BYPCFG = 1                                        */
/*   BIPMSK = 0xFF, all SM, PM, 6 TCMs BIP-8 bits can be monitored, this affect*/
/*   all SM,PM,TCMn BIPs.                                                     */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG_t tmp_n40g_otnr4x_odwcfg;
  TEN_N40G_OTNR4X_OACFG0_t tmp_n40g_otnr4x_oacfg0;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OOHR_CFG5_t tmp_n40g_oohr_cfg5;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.OBY = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_rx_ncols_t41(module_id, 254);
  ten_n40g_rx_npar_t41(module_id, 16);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_n40g_otnr4x_oacfg0.bf.ALEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_n40g_otnr4x_oacfg0.wrd);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL = 0;
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL1 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_n40g_otnr4x_odwcfg.bf.FSOMD = 1;
  tmp_n40g_otnr4x_odwcfg.bf.AGGRMOD = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_n40g_otnr4x_odwcfg.wrd);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.BYPCFG = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_oohr_cfg5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5));
  tmp_n40g_oohr_cfg5.bf.BIPMSK = 0xff;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5), tmp_n40g_oohr_cfg5.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_rx_gfec_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_ODU3                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_odu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receiving ODU3 traffic                                                   */
/*   BYSEL = 0, BYSEL1 = 0, BYPCFG = 1                                        */
/*   BIPMSK = 0x7F, all PM and 6 TCMs BIP can be monitored, this affect all   */
/*     PM,TCMn BIPs in the same way. ODU2 layer, traffic goes through OxU2 term*/
/*     which removes FEC overhead BYPCFG =1 to configure generic splitting by */
/*     Bypass Split block rather than OTU reverse multiplexing all PM and TCMs*/
/*     BIP-8 bits can be minotored, affects all BIP-8 monitors in the same way */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG_t tmp_n40g_otnr4x_odwcfg;
  TEN_N40G_OTNR4X_OACFG0_t tmp_n40g_otnr4x_oacfg0;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OOHR_CFG5_t tmp_n40g_oohr_cfg5;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.OBY = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_rx_ncols_t41(module_id, 238);
  ten_n40g_rx_npar_t41(module_id, 0);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_n40g_otnr4x_oacfg0.bf.ALEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_n40g_otnr4x_oacfg0.wrd);

  tmp_n40g_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_n40g_otnr4x_odwcfg.bf.FSOMD = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_n40g_otnr4x_odwcfg.wrd);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL = 0;
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL1 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_n40g_otnr4x_odwcfg.bf.AGGRMOD = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_n40g_otnr4x_odwcfg.wrd);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.BYPCFG = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_oohr_cfg5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5));
  tmp_n40g_oohr_cfg5.bf.BIPMSK = ((tmp_n40g_oohr_cfg5.bf.BIPMSK & ~0x7f) | (0x7f & 0x7f)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5), tmp_n40g_oohr_cfg5.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_SECOND_ODU3                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_second_odu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Second ODU3 Aligner                                                      */
/*   BYSEL1 = 1, BYSEL = 0                                                    */
/*   OTNR4X_OBFA2_OACFG0:ALEN = 1, OTNR4X_OBFA2_OFCFG0:NCOLS = 238            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_OBFA2_OFCFG0_t tmp_n40g_otnr4x_obfa2_ofcfg0;
  TEN_N40G_OTNR4X_OBFA2_OACFG0_t tmp_n40g_otnr4x_obfa2_oacfg0;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL1 = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_otnr4x_obfa2_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_OACFG0));
  tmp_n40g_otnr4x_obfa2_oacfg0.bf.ALEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_OACFG0), tmp_n40g_otnr4x_obfa2_oacfg0.wrd);

  tmp_n40g_otnr4x_obfa2_ofcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_OFCFG0));
  tmp_n40g_otnr4x_obfa2_ofcfg0.bf.NCOLS = 238;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OBFA2_OFCFG0), tmp_n40g_otnr4x_obfa2_ofcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_AGGR                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_aggr_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable Aggregation, Bypass OC768                                         */
/*   EXPTI is programmed to 0x20 for AMP, however should be 0x21 for GMP      */
/*   ODU3 Aggregation layer, aggregation is on and OTN is enabled             */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG_t tmp_n40g_otnr4x_odwcfg;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_n40g_otnr4x_odwcfg.bf.AGGRMOD = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_n40g_otnr4x_odwcfg.wrd);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OPU3                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_opu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable Dewrapper                                                         */
/*   BYSEL = 1, BYSEL1 = 0                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG_t tmp_n40g_otnr4x_odwcfg;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_n40g_otnr4x_odwcfg.bf.DW_ENABLE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_n40g_otnr4x_odwcfg.wrd);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL1 = 0;
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OC768_IN                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_oc768_in_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC768 outgoing traffic, OTN layer is disabled                            */
/*   BYPCFG =1 to configure generic splitting by Bypass Split block           */
/*   rather than OTU reverse multiplexing                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.BYPCFG = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.OBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OC768_MSREGEN                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_oc768_msregen_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC768 layer inside OTN, enables scramble and OC768 frame alignment       */
/*   MDPCFG should be set to 64-byte interleaving (MDPCFG=3) so that overhead */
/*   bytes can be properly monitored in N10G                                  */
/*     16-byte interleaving (MDPCFG=2) is only for reverse multiplexing mode  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG_t tmp_n40g_otnr4x_odwcfg;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 0;
  tmp_n40g_gblr4x_dpcfg0.bf.SDHE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_n40g_otnr4x_odwcfg.bf.STM256MD = 1;
  tmp_n40g_otnr4x_odwcfg.bf.STM64MD = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_n40g_otnr4x_odwcfg.wrd);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.MDPCFG = 3;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OC768_TRANSPARENT                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_oc768_transparent_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC768 layer inside OTN, bypass Sonet/SDH processing, could also be called*/
/*   CBR40 mode SDHE = 0 to save power                                        */
/*     MDPCFG is set to 64-byte interleaving (MDPCFG=3) so that overhead      */
/*     bytes can be properly monitored in N10G                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG_t tmp_n40g_otnr4x_odwcfg;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.SDHE = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_n40g_otnr4x_odwcfg.bf.STM256MD = 1;
  tmp_n40g_otnr4x_odwcfg.bf.STM64MD = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_n40g_otnr4x_odwcfg.wrd);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.MDPCFG = 3;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTL34                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otl34_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable OTN MLD: OTL3.4                                                   */
/*   Enable MLD Descramble                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_MLDR_MLDCFG_t tmp_n40g_mldrx_mldr_mldcfg;
  TEN_N40G_OOHR_JCSQUELCH_t tmp_n40g_oohr_jcsquelch;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.MLDEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_mldrx_mldr_mldcfg.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, MLDCFG));
  tmp_n40g_mldrx_mldr_mldcfg.bf.RX_MODE = 0;
  tmp_n40g_mldrx_mldr_mldcfg.bf.DSCRL_EN = 1;
  TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, MLDCFG), tmp_n40g_mldrx_mldr_mldcfg.wrd);

  tmp_n40g_oohr_jcsquelch.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, JCSQUELCH));
  tmp_n40g_oohr_jcsquelch.bf.JCSQLCH_LOL = 1;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, JCSQUELCH), tmp_n40g_oohr_jcsquelch.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_STL256                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_stl256_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable Sonet MLD: STL256                                                 */
/*   Enable MLD Descramble                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_MLDRX_MLDR_MLDCFG_t tmp_n40g_mldrx_mldr_mldcfg;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.MLDEN = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_mldrx_mldr_mldcfg.wrd = TEN_REG_READ(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, MLDCFG));
  tmp_n40g_mldrx_mldr_mldcfg.bf.RX_MODE = 1;
  tmp_n40g_mldrx_mldr_mldcfg.bf.DSCRL_EN = 1;
  TEN_REG_WRITE(TEN_N40G_MLDRX_REG_ADDR(pDev, module_id, MLDCFG), tmp_n40g_mldrx_mldr_mldcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_125G_TS                                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_125g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.TSMODE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_25G_TS                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_25g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.TSMODE = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_AMP_LO                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_amp_lo_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   AMP mode for monolithic or aggregation tributary 0                       */
/*   Payload type is programed to 2 for monolithic and will be overwritten if */
/*     it is aggregation when AMP_TRIB_1 ... are called. DW_ENABLE  AGGRMD    */
/*     AMP_MODE	 JCEN	   GMPMDi	NTEN	  FSi	NTMDi	 NTMD_MONO	Wrapping 1         */
/*     0        X        1       0       0       0     x      x       AMP     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = ((tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE & ~0x1) | (0x1 & 0x1)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x2;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_AMP_TRIB                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_amp_trib_t41(cs_uint16 module_id,
                                   cs_uint16 trib)
/* INPUTS     : o Module_id                                                   */
/*              o Trib                                                        */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   AMP mode for an aggregation tributary                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = ((tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE & ~0x1 << trib) | (0x1 << trib & 0x1 << trib)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x20;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_AMP_TRIB_0                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_amp_trib_0_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   AMP mode for aggregation tributary 0                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = ((tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE & ~0x1) | (0x1 & 0x1)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x20;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_AMP_TRIB_1                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_amp_trib_1_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   AMP mode for aggregation tributary 1                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = ((tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE & ~0x2) | (0x2 & 0x2)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x20;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_AMP_TRIB_2                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_amp_trib_2_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   AMP mode for aggregation tributary 2                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = ((tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE & ~0x4) | (0x4 & 0x4)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x20;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_AMP_TRIB_3                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_amp_trib_3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   AMP mode for aggregation tributary 3                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = ((tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE & ~0x8) | (0x8 & 0x8)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x20;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_GMP_HO_TRIB_0                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_gmp_ho_trib_0_t41(cs_uint16 module_id,
                                        cs_uint32 cn)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   HO GMP Tributary 0                                                       */
/*   Cn00= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn01= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OGMPR4X_GMPODW0CFG1_t tmp_n40g_ogmpr4x_gmpodw0cfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_OGMPR4X_GMPODWCFG0_t tmp_n40g_ogmpr4x_gmpodwcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_125g_ts_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
  tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD0 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = ((tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE & ~0x1) | (0x1 & 0x1)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x21;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  tmp_n40g_ogmpr4x_gmpodw0cfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW0CFG1));
  tmp_n40g_ogmpr4x_gmpodw0cfg1.bf.ADJMAX = 0x40;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW0CFG1), tmp_n40g_ogmpr4x_gmpodw0cfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_GMP_HO_TRIB_1                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_gmp_ho_trib_1_t41(cs_uint16 module_id,
                                        cs_uint32 cn)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   HO GMP Tributary 1                                                       */
/*   Cn10= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn11= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG11_t tmp_n40g_ogmpr4x_cncfg11;
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_OGMPR4X_GMPODWCFG0_t tmp_n40g_ogmpr4x_gmpodwcfg0;
  TEN_N40G_OGMPR4X_GMPODW1CFG1_t tmp_n40g_ogmpr4x_gmpodw1cfg1;
  TEN_N40G_OGMPR4X_CNCFG10_t tmp_n40g_ogmpr4x_cncfg10;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_125g_ts_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
  tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD1 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = ((tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE & ~0x2) | (0x2 & 0x2)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_ogmpr4x_cncfg11.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG11));
  tmp_n40g_ogmpr4x_cncfg11.bf.Cn11 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG11), tmp_n40g_ogmpr4x_cncfg11.wrd);

  tmp_n40g_ogmpr4x_cncfg10.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG10));
  tmp_n40g_ogmpr4x_cncfg10.bf.Cn10 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG10), tmp_n40g_ogmpr4x_cncfg10.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x21;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  tmp_n40g_ogmpr4x_gmpodw1cfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW1CFG1));
  tmp_n40g_ogmpr4x_gmpodw1cfg1.bf.ADJMAX = 0x40;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW1CFG1), tmp_n40g_ogmpr4x_gmpodw1cfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_GMP_HO_TRIB_2                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_gmp_ho_trib_2_t41(cs_uint16 module_id,
                                        cs_uint32 cn)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   HO GMP Tributary 2                                                       */
/*   Cn20= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn21= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG20_t tmp_n40g_ogmpr4x_cncfg20;
  TEN_N40G_OGMPR4X_CNCFG21_t tmp_n40g_ogmpr4x_cncfg21;
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_OGMPR4X_GMPODWCFG0_t tmp_n40g_ogmpr4x_gmpodwcfg0;
  TEN_N40G_OGMPR4X_GMPODW2CFG1_t tmp_n40g_ogmpr4x_gmpodw2cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_125g_ts_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
  tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD2 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = ((tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE & ~0x4) | (0x4 & 0x4)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_ogmpr4x_cncfg21.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG21));
  tmp_n40g_ogmpr4x_cncfg21.bf.Cn21 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG21), tmp_n40g_ogmpr4x_cncfg21.wrd);

  tmp_n40g_ogmpr4x_cncfg20.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG20));
  tmp_n40g_ogmpr4x_cncfg20.bf.Cn20 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG20), tmp_n40g_ogmpr4x_cncfg20.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x21;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  tmp_n40g_ogmpr4x_gmpodw2cfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW2CFG1));
  tmp_n40g_ogmpr4x_gmpodw2cfg1.bf.ADJMAX = 0x40;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW2CFG1), tmp_n40g_ogmpr4x_gmpodw2cfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_GMP_HO_TRIB_3                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_gmp_ho_trib_3_t41(cs_uint16 module_id,
                                        cs_uint32 cn)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   HO GMP Tributary 3                                                       */
/*   Cn30= Cn % 0x10000 = cn%65536 (this gets us lower 16 bits of Cn)         */
/*   Cn31= Cn >> 16                (this gets us upper 16 bits)               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_GMPODW3CFG1_t tmp_n40g_ogmpr4x_gmpodw3cfg1;
  TEN_N40G_OGMPR4X_CNCFG30_t tmp_n40g_ogmpr4x_cncfg30;
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_OGMPR4X_GMPODWCFG0_t tmp_n40g_ogmpr4x_gmpodwcfg0;
  TEN_N40G_OGMPR4X_CNCFG31_t tmp_n40g_ogmpr4x_cncfg31;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_125g_ts_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
  tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD3 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = ((tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE & ~0x8) | (0x8 & 0x8)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_ogmpr4x_cncfg31.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG31));
  tmp_n40g_ogmpr4x_cncfg31.bf.Cn31 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG31), tmp_n40g_ogmpr4x_cncfg31.wrd);

  tmp_n40g_ogmpr4x_cncfg30.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG30));
  tmp_n40g_ogmpr4x_cncfg30.bf.Cn30 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG30), tmp_n40g_ogmpr4x_cncfg30.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x21;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  tmp_n40g_ogmpr4x_gmpodw3cfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW3CFG1));
  tmp_n40g_ogmpr4x_gmpodw3cfg1.bf.ADJMAX = 0x40;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODW3CFG1), tmp_n40g_ogmpr4x_gmpodw3cfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_GMP_HO_TSEN                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_gmp_ho_tsen_t41(cs_uint16 module_id,
                                      cs_uint16 tsen0,
                                      cs_uint16 tsen1)
/* INPUTS     : o Module_id                                                   */
/*              o Tsen0                                                       */
/*              o Tsen1                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_ODWTSENABLE0_t tmp_n40g_ogmpr4x_odwtsenable0;
  TEN_N40G_OGMPR4X_ODWTSENABLE1_t tmp_n40g_ogmpr4x_odwtsenable1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_ogmpr4x_odwtsenable0.wrd = tsen0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSENABLE0), tmp_n40g_ogmpr4x_odwtsenable0.wrd);

  tmp_n40g_ogmpr4x_odwtsenable1.wrd = tsen1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWTSENABLE1), tmp_n40g_ogmpr4x_odwtsenable1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}










/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_DETAMP                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_detamp_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   DETGMP place holder, details not implemented yet                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_GMP_LO                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_gmp_lo_t41(cs_uint16 module_id,
                                 cs_uint32 cn)
/* INPUTS     : o Module_id                                                   */
/*              o Cn                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   LO GMP Tributary 0                                                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_OGMPR4X_GMPODWCFG0_t tmp_n40g_ogmpr4x_gmpodwcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_125g_ts_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = 0x1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  tmp_n40g_ogmpr4x_gmpodwcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0));
  tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD0 = 1;
  tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD1 = 0;
  tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD2 = 0;
  tmp_n40g_ogmpr4x_gmpodwcfg0.bf.GMPMD3 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, GMPODWCFG0), tmp_n40g_ogmpr4x_gmpodwcfg0.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = cn>>16;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = cn%65536;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x2;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_PROPMAP_LO                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_propmap_lo_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Cortina Propertory Mapping at OxU3 level, enable up to 6 PJO             */
/*   when LOF happens, configuring the bits below will make sure shutdown JC  */
/*     going to syncdsync see bug 17051 for details                           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_OOHR_GENDWNLFSF_t tmp_n40g_oohr_gendwnlfsf;
  TEN_N40G_OTNR4X_ODWCFG_t tmp_n40g_otnr4x_odwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_PLUS = 0x1;
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = 0x1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_rx_25g_ts_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_n40g_otnr4x_odwcfg.bf.LINKALM_JCNOM = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_n40g_otnr4x_odwcfg.wrd);

  tmp_n40g_oohr_gendwnlfsf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF));
  tmp_n40g_oohr_gendwnlfsf.bf.GENSF_LOF = 1;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF), tmp_n40g_oohr_gendwnlfsf.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x2;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_PROPMAP_HO                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_propmap_ho_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Cortina Proprietary Mapping at OxU3 level, asynchronous mapping, each    */
/*     tributory supports up to 6 PJO, however, 2 and 3 are typical case      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWCFG1_t tmp_n40g_otnr4x_odwcfg1;
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwcfg1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1));
  tmp_n40g_otnr4x_odwcfg1.bf.JC_PLUS = 0xF;
  tmp_n40g_otnr4x_odwcfg1.bf.JC_ENABLE = 0xF;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG1), tmp_n40g_otnr4x_odwcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_rx_25g_ts_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x20;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_N40G_BYPASS                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_n40g_bypass_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40G traffic bypass the whole N40G to 10G Circuit Processor Bypass;       */
/*   this is not same as quad 10g bypass                                      */
/*   BYPCFG =1 to configure generic splitting by Bypass Split block           */
/*   rather than OTU reverse multiplexing                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.BYPCFG = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL1 = 0;
  tmp_n40g_gblr4x_dpcfg0.bf.OBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_PKT_BYPASS                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_pkt_bypass_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40G traffic bypass the whole N40G to 10G Circuit Processor; this is not  */
/*     same as quad 10g bypass                                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.OBY = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_UFEC7                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_ufec7_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDeScramble on and PostDeScramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_ufec_t41(module_id);
  ten_n40g_rx_nrows_t41(module_id, 3);
  ten_n40g_rx_ncols_t41(module_id, 254);
  ten_n40g_rx_npar_t41(module_id, 16);
  ten_n40g_rx_nparb_t41(module_id, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_UFEC10                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_ufec10_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDeScramble on and PostDeScramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_ufec_t41(module_id);
  ten_n40g_rx_nrows_t41(module_id, 3);
  ten_n40g_rx_ncols_t41(module_id, 261);
  ten_n40g_rx_npar_t41(module_id, 23);
  ten_n40g_rx_nparb_t41(module_id, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_UFEC12                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_ufec12_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDeScramble on and PostDeScramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_ufec_t41(module_id);
  ten_n40g_rx_nrows_t41(module_id, 3);
  ten_n40g_rx_ncols_t41(module_id, 266);
  ten_n40g_rx_npar_t41(module_id, 28);
  ten_n40g_rx_nparb_t41(module_id, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_UFEC26                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_ufec26_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDeScramble on and PostDeScramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_ufec_t41(module_id);
  ten_n40g_rx_nrows_t41(module_id, 3);
  ten_n40g_rx_ncols_t41(module_id, 300);
  ten_n40g_rx_npar_t41(module_id, 62);
  ten_n40g_rx_nparb_t41(module_id, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_UFEC25                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_ufec25_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDeScramble on and PostDeScramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_ufec_t41(module_id);
  ten_n40g_rx_nrows_t41(module_id, 3);
  ten_n40g_rx_ncols_t41(module_id, 296);
  ten_n40g_rx_npar_t41(module_id, 58);
  ten_n40g_rx_nparb_t41(module_id, 0);
  return (CS_OK);
}



/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTN_SCR_OFF                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otn_scr_off_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_OACFG0_t tmp_n40g_otnr4x_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_n40g_otnr4x_oacfg0.bf.PREDSCR = 0;
  tmp_n40g_otnr4x_oacfg0.bf.POSTDSCR = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_n40g_otnr4x_oacfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OC768_SCR_OFF                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_oc768_scr_off_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_SDFR_SDFCFG_t tmp_n40g_sdfr_sdfcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_sdfr_sdfcfg.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG));
  tmp_n40g_sdfr_sdfcfg.bf.SCREN = 0;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG), tmp_n40g_sdfr_sdfcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OC768_OOF_HYST                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_oc768_oof_hyst_t41(cs_uint16 module_id,
                                         cs_uint16 val)
/* INPUTS     : o Module_id                                                   */
/*              o Val                                                         */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   sets Sonet inFrame to OOF Hyteresis to value                             */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_SDFR_SDFCFG_t tmp_n40g_sdfr_sdfcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_sdfr_sdfcfg.wrd = TEN_REG_READ(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG));
  tmp_n40g_sdfr_sdfcfg.bf.OOFHY = val;
  TEN_REG_WRITE(TEN_N40G_SDFR_REG_ADDR(pDev, module_id, SDFCFG), tmp_n40g_sdfr_sdfcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_FEC_DATAPATH_BYPASS                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_fec_datapath_bypass_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bypasses the FEC datapath for sims that have FEC blocks instantiated but */
/*     not running                                                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_OACFG0_t tmp_n40g_otnr4x_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_oacfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0));
  tmp_n40g_otnr4x_oacfg0.bf.FECEN = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OACFG0), tmp_n40g_otnr4x_oacfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_GENERATE_FRAME_PULSES                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_generate_frame_pulses_t41(cs_uint16 module_id,
                                                cs_uint16 frame_pulse_len)
/* INPUTS     : o Module_id                                                   */
/*              o Frame_pulse_len                                             */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   generate Frame Pulses from Generic Splitter                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_GBLR4X_FPCFG_t tmp_n40g_gblr4x_fpcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_fpcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, FPCFG));
  tmp_n40g_gblr4x_fpcfg.bf.FPLEN = frame_pulse_len;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, FPCFG), tmp_n40g_gblr4x_fpcfg.wrd);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.GRFP = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OC768_PRBS                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_oc768_prbs_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS in OC768                                                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_oc768_in_t41(module_id);
  ten_n40g_rx_oc768_msregen_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3_PRBS                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3_prbs_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS in OTU3                                                             */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0xFE;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3_OC768_PRBS                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3_oc768_prbs_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS in OC768 in OTU3                                                    */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_oc768_msregen_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x3;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3_ODU3                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3_odu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU3 layer termination only, FEC overhead bytes are removed and ODU3     */
/*     layer is untouched                                                     */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3E1_ODU3E1                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3e1_odu3e1_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU3E1 to OTU3E1                                                         */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3E2_ODU3E2                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3e2_odu3e2_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU3E2 to OTU3E2                                                         */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3E2_GMP_LO_ODU3                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3e2_gmp_lo_odu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU3 in OPU3E2 in OTU3E2, Lower Order GMP mode                           */
/*   Cn default value is 14759                                                */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   LO GMP Tributary 0                                                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_second_odu3_t41(module_id);
  ten_n40g_rx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 14759;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3E2_ODU3E2_AND_GMP_LO_40GE_MON                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3e2_odu3e2_and_gmp_lo_40ge_mon_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Passing ODU3E2 to XCON and extract 40GE from ODU3E2 for                  */
/*   non-intrusive monitoring                                                 */
/*   This one used in Table21 - do not modify for other tests                 */
/*   without warning Table 21 owner                                           */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   LO GMP Tributary 0                                                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_OTNR4X_ODWCFG_t tmp_n40g_otnr4x_odwcfg;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 15100;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  tmp_n40g_otnr4x_odwcfg.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG));
  tmp_n40g_otnr4x_odwcfg.bf.DW_ENABLE = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWCFG), tmp_n40g_otnr4x_odwcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3_GMP_LO_40GE                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3_gmp_lo_40ge_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3, Lower Order GMP mode                                       */
/*   Cn default value is 15219                                                */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   LO GMP Tributary 0                                                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 15219;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_ODU3_GMP_LO_40GE                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_odu3_gmp_lo_40ge_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in ODU3 Lower Order GMP mode                                        */
/*   Cn default value is 15219                                                */
/*   LO GMP Tributary 0                                                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_odu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 15219;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3_25U_GMP_LO_40GE                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3_25u_gmp_lo_40ge_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3, 25% UFEC, Lower Order GMP mode                             */
/*   Cn default value is 15219                                                */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   LO GMP Tributary 0                                                       */
/*   Enable UFEC, PreDeScramble on and PostDeScramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_gmp_lo_t41(module_id, 15232);
  ten_n40g_rx_ufec25_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 15219;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTL34_OTU3_GMP_LO_40GE                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otl34_otu3_gmp_lo_40ge_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3 in OTN MLD OTL3.4, Lower Order GMP mode                     */
/*   Cn default value is 15219                                                */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   LO GMP Tributary 0                                                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otl34_t41(module_id);
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 15219;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3E1_GMP_LO_40GE                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3e1_gmp_lo_40ge_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3E1, Lower Order GMP mode                                     */
/*   Cn default value is 14817                                                */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   LO GMP Tributary 0                                                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 14817;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3E2_GMP_LO_40GE                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3e2_gmp_lo_40ge_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3E2, Lower Order GMP mode                                     */
/*   Cn default value is 15100                                                */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   LO GMP Tributary 0                                                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 15100;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3E2_GMP_LO_40GE_PPM                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3e2_gmp_lo_40ge_ppm_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE in OTU3E2, Lower Order GMP mode                                     */
/*   Cn default value is 15100                                                */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   LO GMP Tributary 0                                                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OGMPR4X_CNCFG00_t tmp_n40g_ogmpr4x_cncfg00;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OGMPR4X_CNCFG01_t tmp_n40g_ogmpr4x_cncfg01;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_gmp_lo_t41(module_id, 15232);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_ogmpr4x_cncfg01.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01));
  tmp_n40g_ogmpr4x_cncfg01.bf.Cn01 = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG01), tmp_n40g_ogmpr4x_cncfg01.wrd);

  tmp_n40g_ogmpr4x_cncfg00.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00));
  tmp_n40g_ogmpr4x_cncfg00.bf.Cn00 = 15101;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ogmpr4x_CNCFG00), tmp_n40g_ogmpr4x_cncfg00.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3E1_PROPMAP_LO_40GE                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3e1_propmap_lo_40ge_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU3E1_PROPMAP_LO_40GE, OTU3E1=44.57097G 20ppm; 40GE=41.25G (40G*66/64)  */
/*     100ppm => PJO=3, FS=127                                                */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OTNR4X_ODWFS0_t tmp_n40g_otnr4x_odwfs0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_propmap_lo_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_otnr4x_odwfs0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS0));
  tmp_n40g_otnr4x_odwfs0.bf.FS0 = 127;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS0), tmp_n40g_otnr4x_odwfs0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3_FS96_40GE                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3_fs96_40ge_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   for erratum12 - no justification - FS = 96 bytes                         */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OTNR4X_ODWFS0_t tmp_n40g_otnr4x_odwfs0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_otnr4x_odwfs0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS0));
  tmp_n40g_otnr4x_odwfs0.bf.FS0 = 96;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS0), tmp_n40g_otnr4x_odwfs0.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x3;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3_FS32_40GE                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3_fs32_40ge_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   for erratum12 - no justification - FS = 32 bytes                         */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  TEN_N40G_OTNR4X_ODWFS0_t tmp_n40g_otnr4x_odwfs0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_otnr4x_odwfs0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS0));
  tmp_n40g_otnr4x_odwfs0.bf.FS0 = 32;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWFS0), tmp_n40g_otnr4x_odwfs0.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x3;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3_ODTU_125G_TS                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3_odtu_125g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU3_ODTU_125G_TS                                                        */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_aggr_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_125g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3E2_ODTU_125G_TS                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3e2_odtu_125g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU3E2_ODTU_125G_TS                                                      */
/*   OTU3_ODTU_125G_TS                                                        */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  ten_n40g_rx_otu3_odtu_125g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3E1_ODTU_25G_TS                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3e1_odtu_25g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU3E1_ODTU_125G_TS with Corr. TX config  25G_TS_ODTU_OTU3E1             */
/*   HO async mapping                                                         */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   Cortina Propertory Mapping at OxU3 level, asynchronous mapping, each     */
/*     tributory supports up to 6 PJO, however, 2 and 3 are typical case      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OTNR4X_ODWC15EN0_t tmp_n40g_otnr4x_odwc15en0;
  TEN_N40G_OTNR4X_ODWC15EN1_t tmp_n40g_otnr4x_odwc15en1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_aggr_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_propmap_ho_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_otnr4x_odwc15en0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0));
  tmp_n40g_otnr4x_odwc15en0.bf.C15RES_EN0 = 1;
  tmp_n40g_otnr4x_odwc15en0.bf.C15RES_EN1 = 1;
  tmp_n40g_otnr4x_odwc15en0.bf.C15RES_EN2 = 1;
  tmp_n40g_otnr4x_odwc15en0.bf.C15RES_EN3 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN0), tmp_n40g_otnr4x_odwc15en0.wrd);

  tmp_n40g_otnr4x_odwc15en1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1));
  tmp_n40g_otnr4x_odwc15en1.bf.C15RES_EN4 = 1;
  tmp_n40g_otnr4x_odwc15en1.bf.C15RES_EN5 = 1;
  tmp_n40g_otnr4x_odwc15en1.bf.C15RES_EN6 = 1;
  tmp_n40g_otnr4x_odwc15en1.bf.C15RES_EN7 = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, ODWC15EN1), tmp_n40g_otnr4x_odwc15en1.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  
  ten_n40g_rx_25g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3_ODTU_25G_TS                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3_odtu_25g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU3_ODTU_25G_TS                                                         */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_aggr_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_25g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTL34_OTU310U_ODTU_25G_TS                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otl34_otu310u_odtu_25g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTL34_OTU310U_ODTU_25G_TS                                                */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   Enable UFEC, PreDeScramble on and PostDeScramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_otl34_t41(module_id);
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_aggr_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_25g_ts_t41(module_id);
  ten_n40g_rx_ufec10_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTL34_OTU310U_ODTU_125G_TS                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otl34_otu310u_odtu_125g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTL34_OTU310U_ODTU_125G_TS                                               */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/*   Enable UFEC, PreDeScramble on and PostDeScramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_otl34_t41(module_id);
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_aggr_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_125g_ts_t41(module_id);
  ten_n40g_rx_ufec10_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTU3P_ODTU23P_25G_TS                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otu3p_odtu23p_25g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU3P_ODTU23P_25G_TS                                                     */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_aggr_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_25g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_STL256_OC768                                      */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_stl256_oc768_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   STL256_OC768                                                             */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_stl256_t41(module_id);
  ten_n40g_rx_oc768_in_t41(module_id);
  ten_n40g_rx_oc768_msregen_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_STL256_OC768_PRBS                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_stl256_oc768_prbs_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   STL256_OC768_PRBS                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_stl256_t41(module_id);
  ten_n40g_rx_oc768_in_t41(module_id);
  ten_n40g_rx_oc768_msregen_t41(module_id);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTL34_OTU3_OC768                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otl34_otu3_oc768_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTL34_OTU3_OC768                                                         */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_otl34_t41(module_id);
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_oc768_msregen_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTL34_OTU3_OC768_PRBS                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otl34_otu3_oc768_prbs_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTL34_OTU3_OC768_PRBS                                                    */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otl34_t41(module_id);
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_oc768_msregen_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x3;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTL34_OTU3_ODU3                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otl34_otu3_odu3_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU3_OTU3_OTL34                                                          */
/*   OTU3 layer termination only, FEC overhead bytes are removed and ODU3     */
/*     layer is untouched                                                     */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n40g_rx_otl34_t41(module_id);
  ten_n40g_rx_otu3_odu3_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_OTL34_OTU3_PRBS                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_otl34_otu3_prbs_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTL34_OTU3_PRBS                                                          */
/*   Enable UFEC, PreDeScramble off and PostDeScramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_otl34_t41(module_id);
  ten_n40g_rx_otu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x3;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}




/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_ODU3_OC768_TRANSPARENT_PRBS                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_odu3_oc768_transparent_prbs_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU3_OC768_TRANSPARENT_PRBS, OC768 mapping into ODU3.                    */
/*   Transparent mode is enabled so that unaligned OC768 is sent to           */
/*   bypass split                                                             */
/*   OC768 is also monitored and PRBS data are extracted from OC768           */
/*   SPE and sent to KPA                                                      */
/*   SDHE = 1 to enable Sonet/SDH processing which is turned off to           */
/*   save power in OC768_TRANSPARENT configuration                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_odu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_oc768_transparent_t41(module_id);
   /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SDHE = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x3;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_CBR40IN                                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_cbr40in_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive CBR40 traffic unwrapped, bypass Sonet and OTN                    */
/*   40G traffic bypass the whole N40G to 10G Circuit Processor               */
/*   Bypass; this is not same as quad 10g bypass                              */
/*   BYPCFG =1 to configure generic splitting by Bypass Split                 */
/*   block rather than OTU reverse multiplexing                               */
/*   monitor known pattern unmapped                                           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.BYPCFG = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.BYSEL1 = 0;
  tmp_n40g_gblr4x_dpcfg0.bf.OBY = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_ODU3_PRBS                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_odu3_prbs_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS=>OPU3=>ODU3                                                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_odu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.SBY = 1;
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 1;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0xFE;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_ODU3_OC768_PRBS                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_odu3_oc768_prbs_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS in OC768 in ODU3                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_n40g_oohr_expti;
  TEN_N40G_GBLR4X_DPCFG0_t tmp_n40g_gblr4x_dpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n40g_rx_odu3_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_oc768_msregen_t41(module_id);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  tmp_n40g_gblr4x_dpcfg0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0));
  tmp_n40g_gblr4x_dpcfg0.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, DPCFG0), tmp_n40g_gblr4x_dpcfg0.wrd);

  tmp_n40g_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_n40g_oohr_expti.bf.EXPTI = 0x3;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_n40g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_RX_ODU3_ODTU_125G_TS                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_rx_odu3_odtu_125g_ts_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU3_ODTU_125G_TS                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n40g_rx_odu3_t41(module_id);
  ten_n40g_rx_aggr_t41(module_id);
  ten_n40g_rx_opu3_t41(module_id);
  ten_n40g_rx_125g_ts_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_GLOBAL_RELEASE_SRESET                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_global_release_sreset_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   releases soft resets                                                     */
/*   releases soft resets                                                     */
/*   releases soft resets                                                     */
/*   releases soft resets                                                     */
/*   releases soft resets                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBL4X_SWRST_t tmp_n40g_gbl4x_swrst;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gbl4x_swrst.wrd = 0;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, SWRST), tmp_n40g_gbl4x_swrst.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_mldrx_mld_es_release_sreset_t41(module_id, ((module_id&1)*4)+0);
  ten_n40g_mldrx_mld_es_release_sreset_t41(module_id, ((module_id&1)*4)+1);
  ten_n40g_mldrx_mld_es_release_sreset_t41(module_id, ((module_id&1)*4)+2);
  ten_n40g_mldrx_mld_es_release_sreset_t41(module_id, ((module_id&1)*4)+3);
  ten_n40g_mldrx_sadeco_release_sreset_t41(module_id);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N40G_GLOBAL_SRESET                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N40G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n40g_global_sreset_t41(cs_uint16 module_id)
/* INPUTS     : o Module_id                                                   */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   releases soft resets                                                     */
/*   releases soft resets                                                     */
/*   releases soft resets                                                     */
/*   releases soft resets                                                     */
/*   releases soft resets                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N40G_GBL4X_SWRST_t tmp_n40g_gbl4x_swrst;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_n40g_gbl4x_swrst.wrd = 0x0177;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, SWRST), tmp_n40g_gbl4x_swrst.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  ten_n40g_global_release_sreset_t41(module_id);
  return (CS_OK);
}


