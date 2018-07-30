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
 * This file is auto-generated from n10g_config.xml; DO NOT MODIFY
 */

#include "tenabo40.h"


/******************************************************************************/
/* N10g tx configuration is broken down to five layers: OTU2, ODU2, OPU2,     */
/* OC192, VC4_64C                                                             */
/*                                                                            */
/*                     OTU2   ODU2/ODU2AGGR  OPU2  OC192_MSREGEN  VC4_64C     */
/* GBLT_CFGTX0:OTNOFF    0     0       0                                      */
/* GBLT_CFGTX0:OBY       0     0       0                                      */
/* GBLT_CFGTX0:KPGBY     1     1       1               1                      */
/* GBLT_CFGTX0:SBY       1     1       1               0                      */
/* GBLT_CFGTX0:PKTIE                                                          */
/*                                                                            */
/* OTNT_OCFG:FECMD             0       0                                      */
/* OTNT_OCFG:POSTSCR           1       0                                      */
/* OTNT_OCFG:PRESCR            0       0                                      */
/* OTNT_OCFG:FECEN             0       0                                      */
/*                                                                            */
/* OTNT_WRPCFG3:WRMD     3     3       0      1                               */
/* OTNT_WRPCFG3:STM64MD                                1                      */
/*                                                                            */
/* SOHT_OHBEN0:SCREN                                   1                      */
/* SOHT_POHBEN0:POHIE                                  0             1        */
/*                                                                            */
/* Each layer configures its own protocol, as well as it output mux for the   */
/* next (higher) layer, OTU2 being the lowest layer and PKT being the highest */
/* layer                                                                      */
/*                                                                            */
/* The upper layer protocol will overwrite the configuration of lower layer   */
/* protocol if it is the same register field. For example ODU2_OTU2 programs  */
/* WRMOD = 0, while ODU2_OTU2_OPU2 will reprogram DWMOD from 0 to 1.          */
/*                                                                            */
/* OTU2:       enable OTN, turn off OTN bypass (OBY)                          */
/*                                                                            */
/* ODU2        bypass SONET (this is modified later when SONET protocol is    */
/*             enabled)                                                       */
/*             set "short frame mode" (WRMD=3) and it can be modified later   */
/*             if higher layer protocol is enabled                            */
/*                                                                            */
/* ODU2AGGR:   aggregation mode, ODU2 inside ODTU23/OxU3, AGGRMODE = 1        */
/*                                                                            */
/* OPU2:       enable OTN wrapper (WRMD=1), this will overwrite WRMD value    */
/*             programmed by ODU2 layer.                                      */
/*                                                                            */
/* OC192_MSREGEN: SONET termination, disable SONET bypass (SBY=0) and takes   */
/*             data directly from cross connect with circuit mode (PKTIE=0)   */
/*             again, PKTIE will be overwritten to 1 to take data from packet */
/*             process if packet layer (10GE/FC/GFP) is selected.             */
/*                                                                            */
/*             The difference between OC192 and OC192_OUT is that OC192 is    */
/*             always wrapped by this definition in OTN and OC192_OUT is not. */
/*                                                                            */
/*                                                                            */
/* OC192NIM:   SONET No Intrusive Monitoring, disable SONET bypass (SBY=0)    */
/*             and takes data directly from cross connect with circuit mode   */
/*             (PKTIE=0)                                                      */
/*             again, PKTIE will be overwritten to 1 to take data from packet */
/*             process if packet layer (10GE/FC/GFP) is selected.             */
/*                                                                            */
/* OC192OUT:   OC192 traffic going out of N10G tx, not OTN layer at all.      */
/*             OBY=1 to bypass OTN. Sonet Scramble is enabled                 */
/*             (SOHT_OHBEN0_SCREN=1)                                          */
/*             VC4 is disabled but will be enabled later if VC4 layer is      */
/*             enabled.                                                       */
/*                                                                            */
/* VC4_64C_GEN:POHIE = 1 to enabled VC4_64C layer.  This will overwrite value */
/*             programmed in OC192 and OC192OUT.                              */
/*                                                                            */
/* Payload Type:                                                              */
/* 'h02  Asynchronous CBR Mapping, AMP or GMP                                 */
/* 'h03  Synchronous  CBR Mapping, i.e OC192 into OTU2                        */
/* 'h05  GFP mapping                                                          */
/* 'h08  FC-1200 into ODU2e mapping                                           */
/* 'h09  GFP mapping into extended OPU2 payload - G43MD                       */
/* 'h0E  FC-400 mapping into ODUflex                                          */
/* 'h0F  FC-800 mapping into ODUflex                                          */
/* 'hFE  PRBS test signal                                                     */
/*                                                                            */
/*  JC EN configuration:        JCEN_OTU2   JCEN_ODTU23  JCEN_DT              */
/*                                                                            */
/*  1. first level async            1            0           0                */
/*     second level sync                                                      */
/*                                                                            */
/*  2. first level sync             0            0           1                */
/*     second level sync (=DETAMP)                                            */
/*                                                                            */
/*  3. first level sync             0            1           0                */
/*     second level async                                                     */
/*                                                                            */
/*  4. first level async            1            0           1                */
/*     second level sync (=DETAMP)                                            */
/*                                                                            */
/*  note: first level is for ODU2, second level is for ODTU                   */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*         Configuration bucket (basic buidling block)                        */
/******************************************************************************/

/* Bugzilla 29609 Start */
/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_BYPASS                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_bypass_t41(cs_uint16 module_id,
                                 cs_uint8  slice,
                                 cs_uint16 bypass)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Bypass                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Set parameter 'bypass' to 1 for bypass, 0 to select n10g output and enable*/
/*   internal tx clock.                                                       */
/*   In bypass, bypasses N10G Tx traffic from XCON or PP10G to N40G           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  cs_uint16 sl;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n10g_tx_bypass_t41";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice out of range.  s/b 0..3.", func);
    return(CS_ERROR);
  }

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
      tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, sl, BYPCFG));
      tmp_n10g_gbl_bypcfg.bf.TX_BYPASS = bypass;
      tmp_n10g_gbl_bypcfg.bf.CLKTX_DIS = bypass;
      TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, sl, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);
    }
  }

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}
/* Bugzilla 29609 End */

/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_GFEC                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_gfec_t41(cs_uint16 module_id,
                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_OCFG_t tmp_n10g_otnt_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_ocfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG));
  tmp_n10g_otnt_ocfg.bf.FECMD = 0;
  tmp_n10g_otnt_ocfg.bf.PRESCR = 0;
  tmp_n10g_otnt_ocfg.bf.POSTSCR = 1;
  tmp_n10g_otnt_ocfg.bf.FECEN = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG), tmp_n10g_otnt_ocfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_SM_BIP_INSERTION                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_sm_bip_insertion_t41(cs_uint16 module_id,
                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable OTU Section BIP insertion                                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG4_t tmp_n10g_otnt_cfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG4));
  tmp_n10g_otnt_cfg4.bf.BIPMSK = ((tmp_n10g_otnt_cfg4.bf.BIPMSK & ~0x80) | (0x80 & 0x80)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG4), tmp_n10g_otnt_cfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_NROWS                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_nrows_t41(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_uint16 rows)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Rows                                                        */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG0_t tmp_n10g_otnt_wrpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG0));
  tmp_n10g_otnt_wrpcfg0.bf.NROWS = rows;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG0), tmp_n10g_otnt_wrpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_NCOLS                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_ncols_t41(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_uint16 columns)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Columns                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG0_t tmp_n10g_otnt_wrpcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG0));
  tmp_n10g_otnt_wrpcfg0.bf.NCOLS = columns;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG0), tmp_n10g_otnt_wrpcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_NPAR                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_npar_t41(cs_uint16 module_id,
                               cs_uint8  slice,
                               cs_uint16 parity)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Parity                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG2_t tmp_n10g_otnt_wrpcfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG2));
  tmp_n10g_otnt_wrpcfg2.bf.NPAR = parity;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG2), tmp_n10g_otnt_wrpcfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_NPARB                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_nparb_t41(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_uint16 parity)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Parity                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG2_t tmp_n10g_otnt_wrpcfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG2));
  tmp_n10g_otnt_wrpcfg2.bf.NPARB = parity;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG2), tmp_n10g_otnt_wrpcfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OTU2                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_otu2_t41(cs_uint16 module_id,
                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Transmit OTU2 traffic, aggregation is off and OTN is enabled             */
/*   Standard 7%, OTN                                                         */
/*   Calculate and Insert SM BIP                                              */
/*   Bypass Sonet                                                             */
/*   DWMOD = 3 to configure 'ODU2 to OTU2' - FEC parity bytes are added,      */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_GMPCFG1_t tmp_n10g_otnt_gmpcfg1;
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.TX_BYPASS = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.OTNOFF = 0;
  tmp_n10g_gblt_cfgtx0.bf.OBY = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  ten_n10g_tx_ncols_t41(module_id, slice, 254);
  ten_n10g_tx_npar_t41(module_id, slice, 16);
  ten_n10g_tx_sm_bip_insertion_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.KPGBY = 1;
  tmp_n10g_gblt_cfgtx0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  tmp_n10g_otnt_gmpcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1));
  tmp_n10g_otnt_gmpcfg1.bf.WRMD2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1), tmp_n10g_otnt_gmpcfg1.wrd);

  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.WRMD = 3;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  ten_n10g_tx_gfec_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODU2                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_odu2_t41(cs_uint16 module_id,
                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Transmit ODU2 traffic, aggregation is off and OTN is enabled             */
/*   No FEC party bytes are added NCOLS=238                                   */
/*   Calculate and Insert SM BIP                                              */
/*   Bypass Sonet                                                             */
/*   DWMOD = 0 to disable wrapper                                             */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_GMPCFG1_t tmp_n10g_otnt_gmpcfg1;
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_OTNT_OCFG_t tmp_n10g_otnt_ocfg;
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.TX_BYPASS = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.OTNOFF = 0;
  tmp_n10g_gblt_cfgtx0.bf.OBY = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  ten_n10g_tx_ncols_t41(module_id, slice, 238);
  ten_n10g_tx_npar_t41(module_id, slice, 0);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_ocfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG));
  tmp_n10g_otnt_ocfg.bf.FECMD = 0;
  tmp_n10g_otnt_ocfg.bf.POSTSCR = 1;
  tmp_n10g_otnt_ocfg.bf.PRESCR = 0;
  tmp_n10g_otnt_ocfg.bf.FECEN = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG), tmp_n10g_otnt_ocfg.wrd);

  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.KPGBY = 1;
  tmp_n10g_gblt_cfgtx0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  tmp_n10g_otnt_gmpcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1));
  tmp_n10g_otnt_gmpcfg1.bf.WRMD2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1), tmp_n10g_otnt_gmpcfg1.wrd);

  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.WRMD = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODUFLEX                                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oduflex_t41(cs_uint16 module_id,
                                  cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODUFlex, aggregation is off and OTN is enabled, scramble is off          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  ten_n10g_tx_odu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODU2AGGR                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_odu2aggr_t41(cs_uint16 module_id,
                                   cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Transmit ODTUx aggregation traffic.                                      */
/*   No FEC party bytes are added NCOLS=238.                                  */
/*   Scramble is off.                                                         */
/*   Bypass Sonet.                                                            */
/*   DWMOD = 0 to disable wrapper.                                            */
/*                                                                            */
/*   Second level is asynchronous mode as default: JCEN_DT=0, JCEN_ODTU23=1   */
/*   and can be overwritten by ODTU_DETAMP for deterministic asynchronous     */
/*   first level dewrapper off.                                               */
/*                                                                            */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble is*/
/*   off JCEN_ODTU23 should be set to 1 for aggregation which enables JC from */
/*   syncdsync.                                                               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_OCFG_t tmp_n10g_otnt_ocfg;
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_ocfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG));
  tmp_n10g_otnt_ocfg.bf.FECMD = 0;
  tmp_n10g_otnt_ocfg.bf.POSTSCR = 0;
  tmp_n10g_otnt_ocfg.bf.PRESCR = 0;
  tmp_n10g_otnt_ocfg.bf.FECEN = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG), tmp_n10g_otnt_ocfg.wrd);

  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_DT = 0;
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_ODTU23 = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODUFLEX_AGGR                                      */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oduflex_aggr_t41(cs_uint16 module_id,
                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODUFlex, aggregation is on and OTN is enabled, scramble is off           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_TCMBIPINSERTION                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_tcmbipinsertion_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable TCM BIP insertion                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG4_t tmp_n10g_otnt_cfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG4));
  tmp_n10g_otnt_cfg4.bf.BIPMSK = ((tmp_n10g_otnt_cfg4.bf.BIPMSK & ~0x7E) | (0x7E & 0x7E)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG4), tmp_n10g_otnt_cfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PMBIPINSERTION                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_pmbipinsertion_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG4_t tmp_n10g_otnt_cfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG4));
  tmp_n10g_otnt_cfg4.bf.BIPMSK = ((tmp_n10g_otnt_cfg4.bf.BIPMSK & ~0x01) | (0x01 & 0x01)) & 0xFFFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG4), tmp_n10g_otnt_cfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OPU2                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_opu2_t41(cs_uint16 module_id,
                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable OTN Payload insertion                                             */
/*   Wrapper is on and JC commands are inserted                               */
/*   TCM and PM BIPs are inserted                                             */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_GMPCFG1_t tmp_n10g_otnt_gmpcfg1;
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_gmpcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1));
  tmp_n10g_otnt_gmpcfg1.bf.WRMD2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1), tmp_n10g_otnt_gmpcfg1.wrd);

  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.WRMD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  ten_n10g_tx_tcmbipinsertion_t41(module_id, slice);
  ten_n10g_tx_pmbipinsertion_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_CBR10                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_cbr10_t41(cs_uint16 module_id,
                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable CBR10 Payload insertion                                           */
/*   STM64MD=1                                                                */
/*   Sonet is bypassesd                                                       */
/*   Normally calls "OPU2" first                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.STM64MD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.SBY = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_FTREGEN                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_ftregen_t41(cs_uint16 module_id,
                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 Full Transparent Regen mode                                        */
/*   Sonet scramble on                                                        */
/*   STM64MD=1                                                                */
/*   B1, B2, etc TOH overhead are not overwritten.                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_SOHT_OHBEN2_t tmp_n10g_soht_ohben2;
  TEN_N10G_SOHT_OHBEN0_t tmp_n10g_soht_ohben0;
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  TEN_N10G_SOHT_POHBEN0_t tmp_n10g_soht_pohben0;
  TEN_N10G_SOHT_OHBEN1_t tmp_n10g_soht_ohben1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.SBY = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  tmp_n10g_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN0));
  tmp_n10g_soht_ohben0.bf.SCREN = 1;
  tmp_n10g_soht_ohben0.bf.B140G = 0;
  tmp_n10g_soht_ohben0.bf.B1IE = 0;
  tmp_n10g_soht_ohben0.bf.DCMIE = 0;
  tmp_n10g_soht_ohben0.bf.DCRIE = 0;
  tmp_n10g_soht_ohben0.bf.NU9IE = 0;
  tmp_n10g_soht_ohben0.bf.NU2IE = 0;
  tmp_n10g_soht_ohben0.bf.NU1IE = 0;
  tmp_n10g_soht_ohben0.bf.J0IE = 0;
  tmp_n10g_soht_ohben0.bf.A1A2RSH = 0;
  tmp_n10g_soht_ohben0.bf.DEFIE = 0;
  tmp_n10g_soht_ohben0.bf.A1A2IE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN0), tmp_n10g_soht_ohben0.wrd);

  tmp_n10g_soht_ohben1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN1));
  tmp_n10g_soht_ohben1.bf.K1IE = 0;
  tmp_n10g_soht_ohben1.bf.K2IE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN1), tmp_n10g_soht_ohben1.wrd);

  tmp_n10g_soht_ohben2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN2));
  tmp_n10g_soht_ohben2.bf.S1IE = 0;
  tmp_n10g_soht_ohben2.bf.E2IE = 0;
  tmp_n10g_soht_ohben2.bf.F1IE = 0;
  tmp_n10g_soht_ohben2.bf.E1IE = 0;
  tmp_n10g_soht_ohben2.bf.M1IE = 0;
  tmp_n10g_soht_ohben2.bf.M0IE = 0;
  tmp_n10g_soht_ohben2.bf.K2FIE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN2), tmp_n10g_soht_ohben2.wrd);

  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.STM64MD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  tmp_n10g_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0));
  tmp_n10g_soht_pohben0.bf.POHIE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0), tmp_n10g_soht_pohben0.wrd);

  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.KPGBY = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_RSREGEN                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_rsregen_t41(cs_uint16 module_id,
                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 RS Regen mode                                                      */
/*   Sonet scramble on                                                        */
/*   STM64MD=1                                                                */
/*   A1 refresh and B1 insertion are enabled                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_SOHT_OHBEN0_t tmp_n10g_soht_ohben0;
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  TEN_N10G_SOHT_POHBEN0_t tmp_n10g_soht_pohben0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.SBY = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  tmp_n10g_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN0));
  tmp_n10g_soht_ohben0.bf.SCREN = 1;
  tmp_n10g_soht_ohben0.bf.A1A2RSH = 1;
  tmp_n10g_soht_ohben0.bf.B1IE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN0), tmp_n10g_soht_ohben0.wrd);

  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.STM64MD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  tmp_n10g_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0));
  tmp_n10g_soht_pohben0.bf.POHIE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0), tmp_n10g_soht_pohben0.wrd);

  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.KPGBY = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_B2INSERTION                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_b2insertion_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable B2 insertion                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_SOHT_B2IE0_t tmp_n10g_soht_b2ie0;
  TEN_N10G_SOHT_B2IE4_t tmp_n10g_soht_b2ie4;
  TEN_N10G_SOHT_B2IE8_t tmp_n10g_soht_b2ie8;
  TEN_N10G_SOHT_B2IE10_t tmp_n10g_soht_b2ie10;
  TEN_N10G_SOHT_B2IE3_t tmp_n10g_soht_b2ie3;
  TEN_N10G_SOHT_B2IE5_t tmp_n10g_soht_b2ie5;
  TEN_N10G_SOHT_B2IE1_t tmp_n10g_soht_b2ie1;
  TEN_N10G_SOHT_B2IE6_t tmp_n10g_soht_b2ie6;
  TEN_N10G_SOHT_B2IE11_t tmp_n10g_soht_b2ie11;
  TEN_N10G_SOHT_B2IE7_t tmp_n10g_soht_b2ie7;
  TEN_N10G_SOHT_B2IE2_t tmp_n10g_soht_b2ie2;
  TEN_N10G_SOHT_B2IE9_t tmp_n10g_soht_b2ie9;
  TEN_N10G_SOHT_B2IE12_t tmp_n10g_soht_b2ie12;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_soht_b2ie0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE0));
  tmp_n10g_soht_b2ie0.bf.B2IE0 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE0), tmp_n10g_soht_b2ie0.wrd);

  tmp_n10g_soht_b2ie1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE1));
  tmp_n10g_soht_b2ie1.bf.B2IE1 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE1), tmp_n10g_soht_b2ie1.wrd);

  tmp_n10g_soht_b2ie2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE2));
  tmp_n10g_soht_b2ie2.bf.B2IE2 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE2), tmp_n10g_soht_b2ie2.wrd);

  tmp_n10g_soht_b2ie3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE3));
  tmp_n10g_soht_b2ie3.bf.B2IE3 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE3), tmp_n10g_soht_b2ie3.wrd);

  tmp_n10g_soht_b2ie4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE4));
  tmp_n10g_soht_b2ie4.bf.B2IE4 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE4), tmp_n10g_soht_b2ie4.wrd);

  tmp_n10g_soht_b2ie5.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE5));
  tmp_n10g_soht_b2ie5.bf.B2IE5 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE5), tmp_n10g_soht_b2ie5.wrd);

  tmp_n10g_soht_b2ie6.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE6));
  tmp_n10g_soht_b2ie6.bf.B2IE6 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE6), tmp_n10g_soht_b2ie6.wrd);

  tmp_n10g_soht_b2ie7.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE7));
  tmp_n10g_soht_b2ie7.bf.B2IE7 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE7), tmp_n10g_soht_b2ie7.wrd);

  tmp_n10g_soht_b2ie8.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE8));
  tmp_n10g_soht_b2ie8.bf.B2IE8 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE8), tmp_n10g_soht_b2ie8.wrd);

  tmp_n10g_soht_b2ie9.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE9));
  tmp_n10g_soht_b2ie9.bf.B2IE9 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE9), tmp_n10g_soht_b2ie9.wrd);

  tmp_n10g_soht_b2ie10.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE10));
  tmp_n10g_soht_b2ie10.bf.B2IE10 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE10), tmp_n10g_soht_b2ie10.wrd);

  tmp_n10g_soht_b2ie11.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE11));
  tmp_n10g_soht_b2ie11.bf.B2IE11 = 0x7FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE11), tmp_n10g_soht_b2ie11.wrd);

  tmp_n10g_soht_b2ie12.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE12));
  tmp_n10g_soht_b2ie12.bf.B2IE12 = 0x0FFF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, B2IE12), tmp_n10g_soht_b2ie12.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_MSREGEN                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_msregen_t41(cs_uint16 module_id,
                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 MS Regen mode                                                      */
/*   Sonet scramble on                                                        */
/*   STM64MD=1                                                                */
/*   A1 refresh, B1 and B2 insertion are enabled                              */
/*   Enable B2 insertion                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  TEN_N10G_SOHT_OHBEN0_t tmp_n10g_soht_ohben0;
  TEN_N10G_SOHT_POHBEN0_t tmp_n10g_soht_pohben0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.SBY = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  tmp_n10g_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN0));
  tmp_n10g_soht_ohben0.bf.SCREN = 1;
  tmp_n10g_soht_ohben0.bf.A1A2RSH = 1;
  tmp_n10g_soht_ohben0.bf.B1IE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN0), tmp_n10g_soht_ohben0.wrd);

  ten_n10g_tx_b2insertion_t41(module_id, slice);
  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.STM64MD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  tmp_n10g_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0));
  tmp_n10g_soht_pohben0.bf.POHIE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0), tmp_n10g_soht_pohben0.wrd);

  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.KPGBY = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_OUT                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_out_t41(cs_uint16 module_id,
                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 outgoing traffic, OTN layer is disabled                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.TX_BYPASS = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.OTNOFF = 1;
  tmp_n10g_gblt_cfgtx0.bf.OBY = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_VC4_64C_GEN                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_vc4_64c_gen_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   VC4_64c layer, unaligned VC4_64C data, known pattern over VC4_64c        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_SOHT_OHBEN0_t tmp_n10g_soht_ohben0;
  TEN_N10G_SOHT_POHBEN0_t tmp_n10g_soht_pohben0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN0));
  tmp_n10g_soht_ohben0.bf.A1A2RSH = 0;
  tmp_n10g_soht_ohben0.bf.A1A2IE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN0), tmp_n10g_soht_ohben0.wrd);

  tmp_n10g_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0));
  tmp_n10g_soht_pohben0.bf.POHIE = 1;
  tmp_n10g_soht_pohben0.bf.B3IE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0), tmp_n10g_soht_pohben0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PKT                                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_pkt_t41(cs_uint16 module_id,
                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Use this config to take data from the 10G packet processor.              */
/*   Use transmit config "CIRCUIT" to take data from 40G packet processor or  */
/*   XCONN.                                                                   */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.TX_PKTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.PKTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_CIRCUIT                                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_circuit_t41(cs_uint16 module_id,
                                  cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Use this config to take data from the XCON Circuit path OR the 40G packet*/
/*   processor. Use transmit config "PKT" to take data from 10G packet        */
/*   processor.                                                               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.TX_PKTIE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.PKTIE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_UFEC                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_ufec_t41(cs_uint16 module_id,
                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_OCFG_t tmp_n10g_otnt_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_ocfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG));
  tmp_n10g_otnt_ocfg.bf.FECMD = 1;
  tmp_n10g_otnt_ocfg.bf.PRESCR = 1;
  tmp_n10g_otnt_ocfg.bf.POSTSCR = 0;
  tmp_n10g_otnt_ocfg.bf.FECEN = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG), tmp_n10g_otnt_ocfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_B3INSERTION                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_b3insertion_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable B3 insertion                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_SOHT_POHBEN0_t tmp_n10g_soht_pohben0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0));
  tmp_n10g_soht_pohben0.bf.B3IE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0), tmp_n10g_soht_pohben0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_BMP                                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_bmp_t41(cs_uint16 module_id,
                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bit Synchronous Mapping Procedure.                                       */
/*   Clear JCEN_DT because it is for aggregation case                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  TEN_N10G_OTNT_GMPCFG1_t tmp_n10g_otnt_gmpcfg1;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_gmpcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1));
  tmp_n10g_otnt_gmpcfg1.bf.WRMD2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1), tmp_n10g_otnt_gmpcfg1.wrd);

  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_OTU2 = 0;
  tmp_n10g_otnt_wrpcfg4.bf.JC_PLUS_OTU2 = 0;
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_DT = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x3;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_AMP                                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_amp_t41(cs_uint16 module_id,
                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bit Asynchronous Mapping Procedure on odu2                               */
/*   Clear JCEN_DT because it is for aggregation case                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  TEN_N10G_OTNT_GMPCFG1_t tmp_n10g_otnt_gmpcfg1;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_gmpcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1));
  tmp_n10g_otnt_gmpcfg1.bf.WRMD2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1), tmp_n10g_otnt_gmpcfg1.wrd);

  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_OTU2 = 1;
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_DT = 0;
  tmp_n10g_otnt_wrpcfg4.bf.JC_PLUS_OTU2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x2;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_AMP_PROP                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_amp_prop_t41(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 fixedstuff)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Fixedstuff                                                  */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Cortina proprietary Bit Asynchronous Mapping Procedure for mapping on    */
/*   odu2. Enable JC-plus and set FS to user-supplied value.                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  TEN_N10G_OTNT_WRPFS_t tmp_n10g_otnt_wrpfs;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_amp_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JC_PLUS_OTU2 = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  tmp_n10g_otnt_wrpfs.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPFS));
  tmp_n10g_otnt_wrpfs.bf.FS = fixedstuff;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPFS), tmp_n10g_otnt_wrpfs.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_GMP_LO                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_gmp_lo_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bit Synchronous Mapping Procedure.                                       */
/*   Remove JCEN_DT because it is for aggregation case                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  TEN_N10G_OTNT_GMPCFG1_t tmp_n10g_otnt_gmpcfg1;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_gmpcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1));
  tmp_n10g_otnt_gmpcfg1.bf.WRMD2 = 2;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1), tmp_n10g_otnt_gmpcfg1.wrd);

  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_OTU2 = 1;
  tmp_n10g_otnt_wrpcfg4.bf.JC_PLUS_OTU2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x2;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_GMP_HO                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_gmp_ho_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   High Order GMP Mapping                                                   */
/*   Remove JCEN_DT because it is for aggregation case.                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  TEN_N10G_OTNT_GMPCFG1_t tmp_n10g_otnt_gmpcfg1;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_gmpcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1));
  tmp_n10g_otnt_gmpcfg1.bf.WRMD2 = 3;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1), tmp_n10g_otnt_gmpcfg1.wrd);

  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_OTU2 = 1;
  tmp_n10g_otnt_wrpcfg4.bf.JC_PLUS_OTU2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x21;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_GMP_CM_CN                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_gmp_cm_cn_t41(cs_uint16 module_id,
                                    cs_uint8  slice,
                                    cs_uint16 cm,
                                    cs_uint16 cn_lo16,
                                    cs_uint16 cn_hibit)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Cm                                                          */
/*              o Cn_lo16                                                     */
/*              o Cn_hibit                                                    */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Set initial Cm client data entities mapped into server frame or server   */
/*   multi-frame when out of reset. Set Cn: Number of client bytes per server */
/*   frame/multiframe                                                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CMCFG_t tmp_n10g_otnt_cmcfg;
  TEN_N10G_OTNT_CNCFG1_t tmp_n10g_otnt_cncfg1;
  TEN_N10G_OTNT_CNCFG0_t tmp_n10g_otnt_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cmcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CMCFG));
  tmp_n10g_otnt_cmcfg.bf.CmInit = cm;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CMCFG), tmp_n10g_otnt_cmcfg.wrd);

  tmp_n10g_otnt_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1));
  tmp_n10g_otnt_cncfg1.bf.Cn1 = cn_hibit;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1), tmp_n10g_otnt_cncfg1.wrd);

  tmp_n10g_otnt_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0));
  tmp_n10g_otnt_cncfg0.bf.Cn0 = cn_lo16;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0), tmp_n10g_otnt_cncfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_AMP_ODTU                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_amp_odtu_t41(cs_uint16 module_id,
                                   cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bit Asynchronous Mapping Procedure for mapping on odtu.                  */
/*   Enable JC-plus and set FS to user-supplied value.                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_OTU2 = 0;
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_ODTU23 = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_AMP_PROP_ODTU                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_amp_prop_odtu_t41(cs_uint16 module_id,
                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Cortina proprietary Bit Asynchronous Mapping Procedure for mapping on    */
/*   ODTU.                                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_amp_odtu_t41(module_id, slice);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JC_PLUS_ODTU23 = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_GMP_HO_ODTU                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_gmp_ho_odtu_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   High Order GMP Mapping on odtu                                           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  ten_n10g_tx_amp_odtu_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODTU_DETAMP                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_odtu_detamp_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Second level Deterministic Justification for Asynchronous Mapping        */
/*   Procedure. Don't configure first level jc, let BMP, AMP, GMP_LO and GMP_HO*/
/*   to configure first level jc mode.                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_DT = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_GFP_MAPPING                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_gfp_mapping_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   GFP Bit Synchronous Mapping Procedure                                    */
/*   Remove JCEN_DT because it is for aggregation case.                       */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  TEN_N10G_OTNT_GMPCFG1_t tmp_n10g_otnt_gmpcfg1;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_gmpcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1));
  tmp_n10g_otnt_gmpcfg1.bf.WRMD2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPCFG1), tmp_n10g_otnt_gmpcfg1.wrd);

  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_OTU2 = 0;
  tmp_n10g_otnt_wrpcfg4.bf.JC_PLUS_OTU2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x5;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_UFEC7                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_ufec7_t41(cs_uint16 module_id,
                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
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

  ten_n10g_tx_ufec_t41(module_id, slice);
  ten_n10g_tx_nrows_t41(module_id, slice, 3);
  ten_n10g_tx_ncols_t41(module_id, slice, 254);
  ten_n10g_tx_npar_t41(module_id, slice, 16);
  ten_n10g_tx_nparb_t41(module_id, slice, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_UFEC10                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_ufec10_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
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

  ten_n10g_tx_ufec_t41(module_id, slice);
  ten_n10g_tx_nrows_t41(module_id, slice, 3);
  ten_n10g_tx_ncols_t41(module_id, slice, 261);
  ten_n10g_tx_npar_t41(module_id, slice, 23);
  ten_n10g_tx_nparb_t41(module_id, slice, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_UFEC15                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_ufec15_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
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

  ten_n10g_tx_ufec_t41(module_id, slice);
  ten_n10g_tx_nrows_t41(module_id, slice, 3);
  ten_n10g_tx_ncols_t41(module_id, slice, 272);
  ten_n10g_tx_npar_t41(module_id, slice, 34);
  ten_n10g_tx_nparb_t41(module_id, slice, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_UFEC20                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_ufec20_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
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

  ten_n10g_tx_ufec_t41(module_id, slice);
  ten_n10g_tx_nrows_t41(module_id, slice, 3);
  ten_n10g_tx_ncols_t41(module_id, slice, 284);
  ten_n10g_tx_npar_t41(module_id, slice, 46);
  ten_n10g_tx_nparb_t41(module_id, slice, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_UFEC26                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_ufec26_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
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

  ten_n10g_tx_ufec_t41(module_id, slice);
  ten_n10g_tx_nrows_t41(module_id, slice, 3);
  ten_n10g_tx_ncols_t41(module_id, slice, 300);
  ten_n10g_tx_npar_t41(module_id, slice, 62);
  ten_n10g_tx_nparb_t41(module_id, slice, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OTN_SCR_OFF                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_otn_scr_off_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_OCFG_t tmp_n10g_otnt_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_ocfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG));
  tmp_n10g_otnt_ocfg.bf.PRESCR = 0;
  tmp_n10g_otnt_ocfg.bf.POSTSCR = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG), tmp_n10g_otnt_ocfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_SCR_OFF                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_scr_off_t41(cs_uint16 module_id,
                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_SOHT_OHBEN0_t tmp_n10g_soht_ohben0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_soht_ohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN0));
  tmp_n10g_soht_ohben0.bf.SCREN = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OHBEN0), tmp_n10g_soht_ohben0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_FEC_DATAPATH_BYPASS                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_fec_datapath_bypass_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bypasses the FEC datapath for sims that have FEC blocks instantiated but */
/*     not running                                                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_OCFG_t tmp_n10g_otnt_ocfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_ocfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG));
  tmp_n10g_otnt_ocfg.bf.FECEN = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OCFG), tmp_n10g_otnt_ocfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_G43MD                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_g43md_t41(cs_uint16 module_id,
                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable G43 Mode, JC EN = 0 becase JC bytes are used for payload.         */
/*   PTI = 9 according to G709                                                */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.G43MD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_OTU2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x9;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/*   Customer Application Configurations                                      */
/******************************************************************************/

/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PKT_BYPASS                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_pkt_bypass_t41(cs_uint16 module_id,
                                     cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bypass packet data from PP10G                                            */
/*   In bypass, bypasses N10G Tx traffic from XCON or PP10G to N40G           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.TX_PKTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  ten_n10g_tx_bypass_t41(module_id, slice, 1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PP40G_ENABLE                                      */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_pp40g_enable_t41(cs_uint16 module_id,
                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.PP40G_EN = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PP40G_DISABLE                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_pp40g_disable_t41(cs_uint16 module_id,
                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.PP40G_EN = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_CIRCUIT_BYPASS                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_circuit_bypass_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   CBR data from PP40G on the bypass path                                   */
/*   In bypass, bypasses N10G Tx traffic from XCON or PP10G to N40G           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.TX_PKTIE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  ten_n10g_tx_bypass_t41(module_id, slice, 1);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PP40G_CIRCUIT_BYPASS                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_pp40g_circuit_bypass_t41(cs_uint16 module_id,
                                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE data from the PP40G on the bypass path                              */
/*   CBR data from PP40G on the bypass path                                   */
/*   In bypass, bypasses N10G Tx traffic from XCON or PP10G to N40G           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  ten_n10g_tx_circuit_bypass_t41(module_id, slice);
  ten_n10g_tx_pp40g_enable_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PRBS_OC192                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_prbs_oc192_t41(cs_uint16 module_id,
                                     cs_uint8  slice,
                                     cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 with PRBS payload                                                  */
/*   OC192 MS Regen                                                           */
/*   PRBS pattern in KPG (defaults to PRBS31)                                 */
/*   OC192 outgoing traffic, OTN layer is disabled                            */
/*   Enable B2 insertion                                                      */
/*   VC4_64c layer, unaligned VC4_64C data, known pattern over VC4_64c        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLT_KPGCFG_t tmp_n10g_gblt_kpgcfg;
  TEN_N10G_SOHT_POHBEN0_t tmp_n10g_soht_pohben0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oc192_out_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_vc4_64c_gen_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0));
  tmp_n10g_soht_pohben0.bf.PRBSIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0), tmp_n10g_soht_pohben0.wrd);

  tmp_n10g_gblt_kpgcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG));
  tmp_n10g_gblt_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG), tmp_n10g_gblt_kpgcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PRBS_OTU2                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_prbs_otu2_t41(cs_uint16 module_id,
                                    cs_uint8  slice,
                                    cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU2 with PRBS payload                                                   */
/*   PRBS pattern in KPG (defaults to PRBS31).                                */
/*   PTI = 0xFE to indicate PRBS test signal mapping.                         */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  TEN_N10G_GBLT_KPGCFG_t tmp_n10g_gblt_kpgcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_otu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.KPGBY = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  tmp_n10g_gblt_kpgcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG));
  tmp_n10g_gblt_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG), tmp_n10g_gblt_kpgcfg.wrd);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0xFE;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PRBS_OC192_MSREGEN_OTU2                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_prbs_oc192_msregen_otu2_t41(cs_uint16 module_id,
                                                  cs_uint8  slice,
                                                  cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS in OC192 in OTU2                                                    */
/*   OC192 MS Regen                                                           */
/*   PRBS pattern in KPG (defaults to PRBS31)                                 */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   Enable B2 insertion                                                      */
/*   VC4_64c layer, unaligned VC4_64C data, known pattern over VC4_64c        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  TEN_N10G_GBLT_KPGCFG_t tmp_n10g_gblt_kpgcfg;
  TEN_N10G_SOHT_POHBEN0_t tmp_n10g_soht_pohben0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_otu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_vc4_64c_gen_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0));
  tmp_n10g_soht_pohben0.bf.PRBSIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0), tmp_n10g_soht_pohben0.wrd);

  tmp_n10g_gblt_kpgcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG));
  tmp_n10g_gblt_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG), tmp_n10g_gblt_kpgcfg.wrd);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x3;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GE_ODU2                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10ge_odu2_t41(cs_uint16 module_id,
                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GE in ODU2, BMP                                                        */
/*   STM64MD=0                                                                */
/*   Payload Data coming from PP10G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  ten_n10g_tx_odu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GE_ODU2_ODTU                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10ge_odu2_odtu_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GE in ODU2 in ODTUx                                                    */
/*   STM64MD=0                                                                */
/*   Payload Data coming from PP10G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x3;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GE_BMP_ODU2E                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10ge_bmp_odu2e_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GE in ODU2E, BMP                                                       */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP10G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n10g_tx_odu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GE_BMP_OTU1E                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10ge_bmp_otu1e_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GE BMP =>OTU1E (STM64 not set)                                         */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  ten_n10g_tx_otu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GE_BMP_OTU2E                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10ge_bmp_otu2e_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GE in ODU2E, BMP                                                       */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP10G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  ten_n10g_tx_otu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GE_BMP_ODU2E_ODTU                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10ge_bmp_odu2e_odtu_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GE in ODU2 (BM)) in ODTUx                                              */
/*   Payload Data coming from PP10G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GE_OC192_MSREGEN_BMP_ODU2                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10ge_oc192_msregen_bmp_odu2_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GE in OC192 in ODU2, BMP                                               */
/*   OC192 MS Regen                                                           */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP10G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   Enable B2 insertion                                                      */
/*   VC4_64c layer, unaligned VC4_64C data, known pattern over VC4_64c        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n10g_tx_odu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_vc4_64c_gen_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GE_OC192_MSREGEN_BMP_ODU2_ODTU                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10ge_oc192_msregen_bmp_odu2_odtu_t41(cs_uint16 module_id,
                                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GE in OC192 in ODU2, BMP, in ODTUx                                     */
/*   OC192 MS Regen                                                           */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP10G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   Enable B2 insertion                                                      */
/*   VC4_64c layer, unaligned VC4_64C data, known pattern over VC4_64c        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_vc4_64c_gen_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GFC_ODU2E_ODTU                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10gfc_odu2e_odtu_t41(cs_uint16 module_id,
                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GFC in ODU2E, BMP, in ODTUx                                            */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP10G                                           */
/*   PTI = 8 to indicate FC-1200 into ODU2E mapping.                          */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);

  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x8;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_CBR_BMP_ODU2E_ODTU                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_cbr_bmp_odu2e_odtu_t41(cs_uint16 module_id,
                                             cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   CBR in ODU2E, BMP, in ODTUx                                              */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP40G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GE_ODU2E_ODTU                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10ge_odu2e_odtu_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GE in ODU2E, BMP, in ODTUx                                             */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP10G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_10GFC_ODU2E                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_10gfc_odu2e_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   10GFC in ODU2E, BMP                                                      */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP10G                                           */
/*   PTI = 8 to indicate FC-1200 into ODU2E mapping.                          */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n10g_tx_odu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x8;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_40GEP_ODU2E                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_40gep_odu2e_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE parallel in ODU2E, BMP                                              */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP40G                                           */
/*   Select Master Frame Pulse                                                */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  ten_n10g_tx_pp40g_enable_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.MST_FPSYNCE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_40GEP_OTU2E                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_40gep_otu2e_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE parallel in OTU2E, BMP                                              */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP40G                                           */
/*   Select Master Frame Pulse                                                */
/*   PTI = 3 to indicate synchronous CBR mapping.                             */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_otu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  ten_n10g_tx_pp40g_enable_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.MST_FPSYNCE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_40GEP_OTU2E_26P                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_40gep_otu2e_26p_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE parallel in OTU2E, BMP, 26% UFEC                                    */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP40G                                           */
/*   Select Master Frame Pulse                                                */
/*   PTI = 3 to indicate synchronous CBR mapping                              */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   Enable UFEC, PreScramble on and PostScramble off                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_otu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  ten_n10g_tx_ufec26_t41(module_id, slice);
  ten_n10g_tx_pp40g_enable_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.MST_FPSYNCE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_40GE_ODU2E_ODTU                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_40ge_odu2e_odtu_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE parallel in ODU2 in ODTUx, BMP                                      */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP40G                                           */
/*   Select Master Frame Pulse                                                */
/*   PTI = 3 to indicate synchronous CBR mapping                              */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  ten_n10g_tx_pp40g_enable_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.MST_FPSYNCE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_40GE_ODU2E_ODTU_DT                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_40ge_odu2e_odtu_dt_t41(cs_uint16 module_id,
                                             cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   40GE parallel in ODU2E in ODTUx,                                         */
/*   Deterministic JC at ODTUx for HC not syncdsync                           */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP40G                                           */
/*   Select Master Frame Pulse                                                */
/*   PTI = 3 to indicate synchronous CBR mapping                              */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG3_t tmp_n10g_otnt_wrpcfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_cbr10_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  ten_n10g_tx_odtu_detamp_t41(module_id, slice);
  ten_n10g_tx_pp40g_enable_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg3.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3));
  tmp_n10g_otnt_wrpcfg3.bf.MST_FPSYNCE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG3), tmp_n10g_otnt_wrpcfg3.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_MSREGEN_BMP_ODU2                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_msregen_bmp_odu2_t41(cs_uint16 module_id,
                                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 MS Regein in ODU2, BMP                                             */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP40G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping                              */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   Enable B2 insertion                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n10g_tx_odu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OPU2_ODU2_ODTU                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_opu2_odu2_odtu_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 in ODU2 in ODTUx. Note: Specify regen and synchronicity separately */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP40G                                           */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  
  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_MSREGEN_BMP_ODU2_ODTU                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_msregen_bmp_odu2_odtu_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 MS Regen in ODU2 in ODTUx, BMP                                     */
/*   STM64MD=1                                                                */
/*   Payload Data coming from PP40G                                           */
/*   PTI = 3 to indicate synchronous CBR mapping                              */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   Enable B2 insertion                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n10g_tx_opu2_odu2_odtu_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_4GFC_MON_BMP_ODUFLEX                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_4gfc_mon_bmp_oduflex_t41(cs_uint16 module_id,
                                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   4GFC in ODUFLEX, BMP                                                     */
/*   Payload Data coming from PP40G                                           */
/*   PTI = 0xE to indicate 4GFC mapping into ODUFLEX                          */
/*   ODUFlex, aggregation is off and OTN is enabled, scramble is off          */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oduflex_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0xE;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_8GFC_MON_BMP_ODUFLEX                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_8gfc_mon_bmp_oduflex_t41(cs_uint16 module_id,
                                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   8GFC in ODUFLEX, BMP                                                     */
/*   Payload Data coming from PP40G                                           */
/*   PTI = 0xF to indicate 8GFC mapping into ODUFLEX                          */
/*   ODUFlex, aggregation is off and OTN is enabled, scramble is off          */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_4gfc_mon_bmp_oduflex_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0xF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_5GIBA_MON_BMP_ODUFLEX                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_5giba_mon_bmp_oduflex_t41(cs_uint16 module_id,
                                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   5GIBA in ODUFLEX, BMP                                                    */
/*   Payload Data coming from PP40G                                           */
/*   ODUFlex, aggregation is off and OTN is enabled, scramble is off          */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  ten_n10g_tx_4gfc_mon_bmp_oduflex_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_4GFC_MON_BMP_ODUFLEX_ODTU                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_4gfc_mon_bmp_oduflex_odtu_t41(cs_uint16 module_id,
                                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   4GFC in ODUFLEX in ODTUx, BMP                                            */
/*   Payload Data coming from PP40G                                           */
/*   PTI = 0xE to indicate 4GFC mapping into ODUFLEX                          */
/*   ODUFlex, aggregation is on and OTN is enabled, scramble is off           */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oduflex_aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0xE;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_8GFC_MON_BMP_ODUFLEX_ODTU                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_8gfc_mon_bmp_oduflex_odtu_t41(cs_uint16 module_id,
                                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   8GFC in ODUFLEX in ODTUx, BMP                                            */
/*   Payload Data coming from PP40G                                           */
/*   PTI = 0xF to indicate 8GFC mapping into ODUFLEX                          */
/*   ODUFlex, aggregation is on and OTN is enabled, scramble is off           */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_4gfc_mon_bmp_oduflex_odtu_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0xF;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_5GIBA_MON_BMP_ODUFLEX_ODTU                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_5giba_mon_bmp_oduflex_odtu_t41(cs_uint16 module_id,
                                                     cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   5GIBA in ODUFLEX in ODTUx, BMP                                           */
/*   Payload Data coming from PP40G                                           */
/*   ODUFlex, aggregation is on and OTN is enabled, scramble is off           */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  /* Bugzilla #34375, Remove unnecessary nested semaphores */

  ten_n10g_tx_4gfc_mon_bmp_oduflex_odtu_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODU2_OTU2                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_odu2_otu2_t41(cs_uint16 module_id,
                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU2 layer termination only, FEC overhead bytes are added and ODU2 layer */
/*     is untouched by default                                                */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_otu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODU2_ODTU                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_odu2_odtu_t41(cs_uint16 module_id,
                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU2 in ODTUx                                                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODU1E_OTU1E                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_odu1e_otu1e_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU1E in OTU1E                                                           */
/*   OTU2 layer termination only, FEC overhead bytes are added and ODU2 layer */
/*     is untouched by default                                                */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  ten_n10g_tx_odu2_otu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_8GFC_MON_GMP_LO_ODU2                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_8gfc_mon_gmp_lo_odu2_t41(cs_uint16 module_id,
                                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   8GFC_MON_GMP_LO_ODU2 8GFC=>GMP LO ODU2.                                  */
/*   Cn = 12952 for 8.5G 8GFC =>9.995 Gbps OPU2;  TS_EN = 0xFE, 7 time slot.  */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CNCFG1_t tmp_n10g_otnt_cncfg1;
  TEN_N10G_OTNT_CNCFG0_t tmp_n10g_otnt_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_gmp_lo_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1));
  tmp_n10g_otnt_cncfg1.bf.Cn1 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1), tmp_n10g_otnt_cncfg1.wrd);

  tmp_n10g_otnt_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0));
  tmp_n10g_otnt_cncfg0.bf.Cn0 = 12953;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0), tmp_n10g_otnt_cncfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_8GFC_MON_GMP_LO_ODU2_ODTU                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_8gfc_mon_gmp_lo_odu2_odtu_t41(cs_uint16 module_id,
                                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   8GFC_MON_GMP_LO_ODTU 8GFC=>GMP LO ODU2AGGR.                              */
/*   Cn = 12952 for 8.5G 8GFC =>9.995 Gbps OPU2;  TS_EN = 0xFE, 7 time slot.  */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CNCFG1_t tmp_n10g_otnt_cncfg1;
  TEN_N10G_OTNT_CNCFG0_t tmp_n10g_otnt_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2aggr_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_gmp_lo_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1));
  tmp_n10g_otnt_cncfg1.bf.Cn1 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1), tmp_n10g_otnt_cncfg1.wrd);

  tmp_n10g_otnt_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0));
  tmp_n10g_otnt_cncfg0.bf.Cn0 = 12953;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0), tmp_n10g_otnt_cncfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODUFLEX_GMP_HO_OTU2                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oduflex_gmp_ho_otu2_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODUFLEX_GMP_HO_OTU2 Circuit=>GMP LO OTU2                                 */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_otu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_gmp_ho_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODUFLEX_GMP_HO_OTU2E                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oduflex_gmp_ho_otu2e_t41(cs_uint16 module_id,
                                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODUFLEX_GMP_HO_OTU2E Circuit=>GMP LO OTU2E                               */
/*   ODUFLEX_GMP_HO_OTU2 Circuit=>GMP LO OTU2                                 */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oduflex_gmp_ho_otu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_8GFC_ODUFLEX_GMP_HO_OTU2                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_8gfc_oduflex_gmp_ho_otu2_t41(cs_uint16 module_id,
                                                   cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   8GFC_ODUFLEX_GMP_HO_OTU2 Circuit=>GMP HO OTU2, 8GFC 8.5Gbps => Cn =      */
/*     104062 (0x1967E) and 7 time slots                                      */
/*   ODUFLEX_GMP_HO_OTU2 Circuit=>GMP LO OTU2                                 */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPTSENABLE_t tmp_n10g_otnt_wrptsenable;
  TEN_N10G_OTNT_CMCFG_t tmp_n10g_otnt_cmcfg;
  TEN_N10G_OTNT_CNCFG1_t tmp_n10g_otnt_cncfg1;
  TEN_N10G_OTNT_CNCFG0_t tmp_n10g_otnt_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oduflex_gmp_ho_otu2_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cmcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CMCFG));
  tmp_n10g_otnt_cmcfg.bf.CmInit = 14866;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CMCFG), tmp_n10g_otnt_cmcfg.wrd);

  tmp_n10g_otnt_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1));
  tmp_n10g_otnt_cncfg1.bf.Cn1 = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1), tmp_n10g_otnt_cncfg1.wrd);

  tmp_n10g_otnt_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0));
  tmp_n10g_otnt_cncfg0.bf.Cn0 = 0x967E;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0), tmp_n10g_otnt_cncfg0.wrd);

  tmp_n10g_otnt_wrptsenable.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPTSENABLE));
  tmp_n10g_otnt_wrptsenable.bf.TSEN7 = 0;
  tmp_n10g_otnt_wrptsenable.bf.TSEN6 = 1;
  tmp_n10g_otnt_wrptsenable.bf.TSEN5 = 1;
  tmp_n10g_otnt_wrptsenable.bf.TSEN4 = 1;
  tmp_n10g_otnt_wrptsenable.bf.TSEN3 = 1;
  tmp_n10g_otnt_wrptsenable.bf.TSEN2 = 1;
  tmp_n10g_otnt_wrptsenable.bf.TSEN1 = 1;
  tmp_n10g_otnt_wrptsenable.bf.TSEN0 = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPTSENABLE), tmp_n10g_otnt_wrptsenable.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_4GFC_ODUFLEX_GMP_HO_OTU2E                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_4gfc_oduflex_gmp_ho_otu2e_t41(cs_uint16 module_id,
                                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   4GFC_ODUFLEX_GMP_HO_OTU2E Circuit=>GMP HO OTU2, 4GFC 4.25Gbps => Cn =    */
/*     50219 and 4 time slots                                                 */
/*   ODUFLEX_GMP_HO_OTU2E Circuit=>GMP LO OTU2E                               */
/*   ODUFLEX_GMP_HO_OTU2 Circuit=>GMP LO OTU2                                 */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPTSENABLE_t tmp_n10g_otnt_wrptsenable;
  TEN_N10G_OTNT_CMCFG_t tmp_n10g_otnt_cmcfg;
  TEN_N10G_OTNT_CNCFG1_t tmp_n10g_otnt_cncfg1;
  TEN_N10G_OTNT_CNCFG0_t tmp_n10g_otnt_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oduflex_gmp_ho_otu2e_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cmcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CMCFG));
  tmp_n10g_otnt_cmcfg.bf.CmInit = 12555;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CMCFG), tmp_n10g_otnt_cmcfg.wrd);

  tmp_n10g_otnt_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1));
  tmp_n10g_otnt_cncfg1.bf.Cn1 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1), tmp_n10g_otnt_cncfg1.wrd);

  tmp_n10g_otnt_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0));
  tmp_n10g_otnt_cncfg0.bf.Cn0 = 50219;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0), tmp_n10g_otnt_cncfg0.wrd);

  tmp_n10g_otnt_wrptsenable.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPTSENABLE));
  tmp_n10g_otnt_wrptsenable.bf.TSEN7 = 0;
  tmp_n10g_otnt_wrptsenable.bf.TSEN6 = 0;
  tmp_n10g_otnt_wrptsenable.bf.TSEN5 = 0;
  tmp_n10g_otnt_wrptsenable.bf.TSEN4 = 0;
  tmp_n10g_otnt_wrptsenable.bf.TSEN3 = 1;
  tmp_n10g_otnt_wrptsenable.bf.TSEN2 = 1;
  tmp_n10g_otnt_wrptsenable.bf.TSEN1 = 1;
  tmp_n10g_otnt_wrptsenable.bf.TSEN0 = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPTSENABLE), tmp_n10g_otnt_wrptsenable.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_8GFC_ODUFLEX_GMP_LO_OTU2                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_8gfc_oduflex_gmp_lo_otu2_t41(cs_uint16 module_id,
                                                   cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   8GFC_ODUFLEX_GMP_LO_OTU2 Circuit=>GMP LO OTU2, 8GFC 8.5Gbps => Cn =      */
/*     13008(0x32d0), Cm=1626                                                 */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CMCFG_t tmp_n10g_otnt_cmcfg;
  TEN_N10G_OTNT_CNCFG1_t tmp_n10g_otnt_cncfg1;
  TEN_N10G_OTNT_CNCFG0_t tmp_n10g_otnt_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_otu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_gmp_lo_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cmcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CMCFG));
  tmp_n10g_otnt_cmcfg.bf.CmInit = 1626;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CMCFG), tmp_n10g_otnt_cmcfg.wrd);

  tmp_n10g_otnt_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1));
  tmp_n10g_otnt_cncfg1.bf.Cn1 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG1), tmp_n10g_otnt_cncfg1.wrd);

  tmp_n10g_otnt_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0));
  tmp_n10g_otnt_cncfg0.bf.Cn0 = 13008;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, otnt_CNCFG0), tmp_n10g_otnt_cncfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_MSREGEN_OC192_OUT                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_msregen_oc192_out_t41(cs_uint16 module_id,
                                                  cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192_MSREGEN_OC192OUT: OC192 coming in from PP40G/XCON and going out to */
/*     N40G                                                                   */
/*   OC192 outgoing traffic, OTN layer is disabled                            */
/*   Enable B2 insertion                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oc192_out_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* N10G BLock Configurations                                                  */
/******************************************************************************/

/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PRBS_OUT                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_prbs_out_t41(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS=>OPU2=>ODU2                                                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_GBLT_KPGCFG_t tmp_n10g_gblt_kpgcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.OBY = 1;
  tmp_n10g_gblt_cfgtx0.bf.KPGBY = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  tmp_n10g_gblt_kpgcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG));
  tmp_n10g_gblt_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG), tmp_n10g_gblt_kpgcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PRBS_ODU2                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_prbs_odu2_t41(cs_uint16 module_id,
                                    cs_uint8  slice,
                                    cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS=>OPU2=>ODU2                                                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  TEN_N10G_GBLT_KPGCFG_t tmp_n10g_gblt_kpgcfg;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.KPGBY = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0xFE;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  tmp_n10g_gblt_kpgcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG));
  tmp_n10g_gblt_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG), tmp_n10g_gblt_kpgcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PRBS_OC192_ODU2                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_prbs_oc192_odu2_t41(cs_uint16 module_id,
                                          cs_uint8  slice,
                                          cs_uint16 pattern)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Pattern                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   PRBS31 in OC192 in ODU2                                                  */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   Enable B2 insertion                                                      */
/*   VC4_64c layer, unaligned VC4_64C data, known pattern over VC4_64c        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  TEN_N10G_GBLT_KPGCFG_t tmp_n10g_gblt_kpgcfg;
  TEN_N10G_SOHT_POHBEN0_t tmp_n10g_soht_pohben0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_vc4_64c_gen_t41(module_id, slice);
  
  /* Bugzilla #34375, Remove unnecessary nested semaphores */
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_soht_pohben0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0));
  tmp_n10g_soht_pohben0.bf.PRBSIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, POHBEN0), tmp_n10g_soht_pohben0.wrd);

  tmp_n10g_gblt_kpgcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG));
  tmp_n10g_gblt_kpgcfg.bf.PATSEL = pattern;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, KPGCFG), tmp_n10g_gblt_kpgcfg.wrd);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x3;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_MSREGEN_OTU2                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_msregen_otu2_t41(cs_uint16 module_id,
                                             cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   This can be the data path configuration for intrusive monitoring of      */
/*     OC192 Synchronous mapping                                              */
/*   OTU2 layer termination only, FEC overhead bytes are added and ODU2 layer */
/*     is untouched by default                                                */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   Enable B2 insertion                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_odu2_otu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x3;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PKT_OTU2                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_pkt_otu2_t41(cs_uint16 module_id,
                                   cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   this can be the data path configuration for 10GE over OTU2               */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_CFG2_t tmp_n10g_otnt_cfg2;
  TEN_N10G_OTNT_CFG0_t tmp_n10g_otnt_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_otu2_t41(module_id, slice);
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_otnt_cfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0));
  tmp_n10g_otnt_cfg0.bf.PTIE = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG0), tmp_n10g_otnt_cfg0.wrd);

  tmp_n10g_otnt_cfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2));
  tmp_n10g_otnt_cfg2.bf.PTI = 0x2;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG2), tmp_n10g_otnt_cfg2.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PKT_OC192                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_pkt_oc192_t41(cs_uint16 module_id,
                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   this can be the data path configuration for 10GE over OC192              */
/*   OC192 outgoing traffic, OTN layer is disabled                            */
/*   Enable B2 insertion                                                      */
/*   VC4_64c layer, unaligned VC4_64C data, known pattern over VC4_64c        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oc192_out_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_vc4_64c_gen_t41(module_id, slice);
  ten_n10g_tx_pkt_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_INTERNAL_BYPASS                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_internal_bypass_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bypass data through N10G via internal datapaths                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLT_CFGTX0_t tmp_n10g_gblt_cfgtx0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblt_cfgtx0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0));
  tmp_n10g_gblt_cfgtx0.bf.OBY = 1;
  tmp_n10g_gblt_cfgtx0.bf.SBY = 1;
  tmp_n10g_gblt_cfgtx0.bf.KPGBY = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFGTX0), tmp_n10g_gblt_cfgtx0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_CIRCUIT_INTERNAL_BYPASS                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_circuit_internal_bypass_t41(cs_uint16 module_id,
                                                  cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bypass circuit data through N10G via internal datapaths                  */
/*   Bypass data through N10G via internal datapaths                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_circuit_t41(module_id, slice);
  ten_n10g_tx_internal_bypass_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PKT_INTERNAL_BYPASS                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_pkt_internal_bypass_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bypass packet data from PP10G to N10G internally                         */
/*   Bypass data through N10G via internal datapaths                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_pkt_t41(module_id, slice);
  ten_n10g_tx_internal_bypass_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_MSREGEN_AMP_ODU2_DTAMP_ODTU                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_msregen_amp_odu2_dtamp_odtu_t41(cs_uint16 module_id,
                                                            cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 Multiplexor Section Regen into ODU2                                */
/*   OPU2 add AMP synchronicity on ODU2                                       */
/*   Payload Data coming from PP40G                                           */
/*   Deterministic AMP synchronicity on ODTU23                                */
/*   OC192 (AMP, MSREGEN) -> ODU2(DT AMP 1.25/2.5) -> ODTU23 -> ODU3          */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   Enable B2 insertion                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_opu2_odu2_odtu_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_amp_t41(module_id, slice);
  ten_n10g_tx_odtu_detamp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_RSREGEN_AMP_ODU2_DTAMP_ODTU                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_rsregen_amp_odu2_dtamp_odtu_t41(cs_uint16 module_id,
                                                            cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 Regenerator Section Regen into ODU2                                */
/*   OPU2 add AMP synchronicity on ODU2                                       */
/*   Payload Data coming from PP40G                                           */
/*   Deterministic AMP synchronicity on ODTU23                                */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_opu2_odu2_odtu_t41(module_id, slice);
  ten_n10g_tx_oc192_rsregen_t41(module_id, slice);
  ten_n10g_tx_amp_t41(module_id, slice);
  ten_n10g_tx_odtu_detamp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_FTREGEN_AMP_ODU2_DTAMP_ODTU                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_ftregen_amp_odu2_dtamp_odtu_t41(cs_uint16 module_id,
                                                            cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192, Fully Transparent Regen into ODU2                                 */
/*   OPU2 add AMP synchronicity on ODU2                                       */
/*   Payload Data coming from PP40G                                           */
/*   Deterministic AMP synchronicity on ODTU23                                */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_opu2_odu2_odtu_t41(module_id, slice);
  ten_n10g_tx_oc192_ftregen_t41(module_id, slice);
  ten_n10g_tx_amp_t41(module_id, slice);
  ten_n10g_tx_odtu_detamp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_ODTU_DETGMP                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_odtu_detgmp_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   second level Deterministic Justification for Generic Mapping Procedure.  */
/*   Use BMP, AMP, GMP_LO and GMP_HO to configure first level jc mode         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNT_WRPCFG4_t tmp_n10g_otnt_wrpcfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnt_wrpcfg4.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4));
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_DT = 1;
  tmp_n10g_otnt_wrpcfg4.bf.JCEN_ODTU23 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, WRPCFG4), tmp_n10g_otnt_wrpcfg4.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_MSREGEN_AMP_ODU2_DTGMP_ODTU                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_msregen_amp_odu2_dtgmp_odtu_t41(cs_uint16 module_id,
                                                            cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 Multiplexor Section Regen into ODU2                                */
/*   OPU2 add AMP synchronicity on ODU2                                       */
/*   Payload Data coming from PP40G                                           */
/*   Deterministic AMP synchronicity on ODTU23                                */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   Enable B2 insertion                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_opu2_odu2_odtu_t41(module_id, slice);
  ten_n10g_tx_oc192_msregen_t41(module_id, slice);
  ten_n10g_tx_amp_t41(module_id, slice);
  ten_n10g_tx_odtu_detgmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_RSREGEN_AMP_ODU2_DTGMP_ODTU                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_rsregen_amp_odu2_dtgmp_odtu_t41(cs_uint16 module_id,
                                                            cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 Regenerator Section Regen into ODU2                                */
/*   OPU2 add AMP synchronicity on ODU2                                       */
/*   Payload Data coming from PP40G                                           */
/*   Deterministic AMP synchronicity on ODTU23                                */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_opu2_odu2_odtu_t41(module_id, slice);
  ten_n10g_tx_oc192_rsregen_t41(module_id, slice);
  ten_n10g_tx_amp_t41(module_id, slice);
  ten_n10g_tx_odtu_detgmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_FTREGEN_AMP_ODU2_DTGMP_ODTU                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_ftregen_amp_odu2_dtgmp_odtu_t41(cs_uint16 module_id,
                                                            cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192, Fully Transparent Regen into ODU2                                 */
/*   OPU2 add AMP synchronicity on ODU2                                       */
/*   Payload Data coming from PP40G                                           */
/*   Deterministic AMP synchronicity on ODTU23                                */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_opu2_odu2_odtu_t41(module_id, slice);
  ten_n10g_tx_oc192_ftregen_t41(module_id, slice);
  ten_n10g_tx_amp_t41(module_id, slice);
  ten_n10g_tx_odtu_detgmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_RSREGEN_OC192_OUT                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_rsregen_oc192_out_t41(cs_uint16 module_id,
                                                  cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192, Regenerator Section regen, from PP40G/XCON and going out to N40G  */
/*   OC192 outgoing traffic, OTN layer is disabled                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oc192_out_t41(module_id, slice);
  ten_n10g_tx_oc192_rsregen_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_FTREGEN_OC192_OUT                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_ftregen_oc192_out_t41(cs_uint16 module_id,
                                                  cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192, Fully Transparent regen, from PP40G/XCON and going out to N40G    */
/*   OC192 outgoing traffic, OTN layer is disabled                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oc192_out_t41(module_id, slice);
  ten_n10g_tx_oc192_ftregen_t41(module_id, slice);
  ten_n10g_tx_circuit_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_RSREGEN_BMP_ODU2_ODTU                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_rsregen_bmp_odu2_odtu_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 Regenerator Section regen in ODU2 in ODTUx                         */
/*   Synchronicity is BMP                                                     */
/*   Payload Data coming from PP40G                                           */
/*   Regenerator Section regen                                                */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_opu2_odu2_odtu_t41(module_id, slice);
  ten_n10g_tx_oc192_rsregen_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OC192_BMP_ODU2_ODTU                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_oc192_bmp_odu2_odtu_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 Fully Transparent regen in ODU2 in ODTUx                           */
/*   Synchronicity is BMP                                                     */
/*   Payload Data coming from PP40G                                           */
/*   OC192 regen is Fully transparent                                         */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_opu2_odu2_odtu_t41(module_id, slice);
  ten_n10g_tx_oc192_ftregen_t41(module_id, slice);
  ten_n10g_tx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OPU2_AMP_ODU2_ODTU                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_opu2_amp_odu2_odtu_t41(cs_uint16 module_id,
                                             cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OPU2 in ODU2 in ODTUx, Synchronicity is AMP                              */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_oc192_bmp_odu2_odtu_t41(module_id, slice);
  ten_n10g_tx_amp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OPU2_ODU2_OTU2                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_opu2_odu2_otu2_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   OTU2 layer termination only, FEC overhead bytes are added and ODU2 layer */
/*     is untouched by default                                                */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_opu2_t41(module_id, slice);
  ten_n10g_tx_odu2_otu2_t41(module_id, slice);
  return (CS_OK);
}



/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OPU2_ODU2_GMP_ODTU                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_opu2_odu2_gmp_odtu_t41(cs_uint16 module_id,
                                             cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   OTU2 layer termination only, FEC overhead bytes are added and ODU2 layer */
/*     is untouched by default                                                */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_tx_opu2_odu2_otu2_t41(module_id, slice);
  ten_n10g_tx_gmp_ho_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OPU2_ODU2_OTU1E                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_opu2_odu2_otu1e_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   OTU2 layer termination only, FEC overhead bytes are added and ODU2 layer */
/*     is untouched by default                                                */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  ten_n10g_tx_opu2_odu2_otu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_OPU2_ODU2_OTU2v                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_opu2_odu2_otu2v_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable TCM BIP insertion                                                 */
/*   Enable PM BIP insertion                                                  */
/*   OTU2 layer termination only, FEC overhead bytes are added and ODU2 layer */
/*     is untouched by default                                                */
/*   Enable OTU Section BIP insertion                                         */
/*   Enable GFEC, PreScramble off and PostScramble on                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  ten_n10g_tx_opu2_odu2_otu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_TX_PASSTHRU_10GPKT_TO_40GCKT                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_tx_passthru_10gpkt_to_40gckt_t41(cs_uint16 module_id,
                                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   N10G in bypass, PP10G TO N40G                                            */
/*   In bypass, bypasses N10G Tx traffic from XCON or PP10G to N40G           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  ten_n10g_tx_bypass_t41(module_id, slice, 1);
  ten_n10g_tx_pkt_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* n10g rx configuration is broken down to five major layers: OTU2, ODU2,     */
/* OPU2, CBR10/OC192, VC4_64C_TERM                                            */
/*                                                                            */
/*                                    ODU2       OC192_MSREGEN/     VC4_      */
/*                        OTU2  ODU2  AGGR  OPU2  CBR10   NIM   64C_TERM      */
/* GBL_BYPCFG:RX_BYPASS40G 0      0     0     0     0      0           0      */
/* GBL_BYPCFG:RX_BYPASS10G                    0     0                  0      */
/*                                                                            */
/* GBLR_DPCFG:OTNOFF       0      0     0                                     */
/* GBLR_DPCFG:OBY          0      0     0                                     */
/* GBLR_DPCFG:XSEL         1      1     1    2      2      1           2      */
/* GBLR_DPCFG:SBYFRM       1      1     1                                     */
/* GBLR_DPCFG:SBYPLD                         1      1                  0      */
/* GBLR_DPCFG:KPASEL                         1                                */
/*                                                                            */
/* OTNR_ODWCFG:FSOMD       1      1     1                                     */
/* OTNR_ODWCFG:DWMOD       5      5     5    3                                */
/* OTNR_OACFG0:FECMD      0/1           0                                     */
/* OTNR_OACFG0:POSTDSCR                 0                                     */
/* OTNR_OACFG0:PREDSCR                  0                                     */
/* OTNR_OACFG0:FECEN                    0                                     */
/* OTNR_ODWCFG:STM64MD                       1             1                  */
/*                                                                            */
/* GBLR_DPCFG:SDHOFF                         1             0                  */
/* SDFR_SDFCFG:SCREN                                       1                  */
/* GBLR_DPCFG:SBYFRM                                       0                  */
/*                                                                            */
/* Each layer configures its own protocol, as well as it output mux for the   */
/* next (higher) layer, OTU2 beeing the lowest layer and VC4_64C_TERM being   */
/* the highest layer                                                          */
/*                                                                            */
/* The upper layer protocol will overwrite the configuration of lower layer   */
/*          protocol if it is the same register field. For example OTU2_ODU2  */
/*          programs DWMOD = 5 while OTU2_ODU2_OPU2 will reprogram DWMOD from */
/*          5 to 3. OTU2_ODU2_OPU2_OC192_VC4_64C_TERM will overwrite KPASEL   */
/*          from 1 to 0                                                       */
/*                                                                            */
/* OTU2:    enable OTN block                                                  */
/*                                                                            */
/* ODU2:    set dewrapper "short frame mode" (WRMD=5) which removes FEC and   */
/*          passes ODU2                                                       */
/*          It can be overwritten later if higher layer protocol is enabled.  */
/*          For example, if OC192 over OTU2, WRMD will be reconfigured to 3.  */
/*          ODU2 data are passing to cross connect by setting XSEL=1.         */
/*                                                                            */
/* OPU2:    enabled dewrapper with Justiciation (WRMD=3).  This is a default  */
/*          and can be changed to difference value if needed.                 */
/*          OPU2 data are passing to cross connect by setting XSEL=2 and      */
/*          SBYPLD=1                                                          */
/*                                                                            */
/* OC192_MSREGEN: SONET termination is enabled and aligned OC192 frame is     */
/*          passing to cross connect (XSEL=1)                                 */
/*          The difference between OC192 and OC192_IN is that OC192 is always */
/*          dewrapped from OTN by this definition and OC192_IN is not. In     */
/*          other words, OPU2 is always paired with OC192.                    */
/*                                                                            */
/* OC192_IN: the incoming traffic is OC192.  OTN is disabled.                 */
/*                                                                            */
/* VC4_64C_TERM: VC4_64C_TERM payload data are passing to cross connect or    */
/*          packet processor                                                  */
/*          KPA is programmed to take VC4_64C_TERM data and analyze it by     */
/*          default.                                                          */
/*                                                                            */
/* CBR10IN: the incoming traffic is CBR10 like data. There is not necessary   */
/*          to having framing info.                                           */
/*          Both OTN and Sonet are bypassed (OBY=1, XSEL=1, SBYPLD=1) KPA is  */
/*          programmed to take raw user data and analyze it by default.       */
/*                                                                            */
/* CBR10: OPU payload is CBR, STM64MD = 1                                     */
/*                                                                            */
/* Payload Type:                                                              */
/* 'h02  Asynchronous CBR Mapping, AMP or GMP                                 */
/* 'h03  Synchronous  CBR Mapping, i.e OC192 into OTU2                        */
/* 'h05  GFP mapping                                                          */
/* 'h08  FC-1200 into ODU2e mapping                                           */
/* 'h09  GFP mapping into extended OPU2 payload - G43MD                       */
/* 'h0E  FC-400 mapping into ODUflex                                          */
/* 'h0F  FC-800 mapping into ODUflex                                          */
/* 'hFE  PRBS test signal                                                     */
/******************************************************************************/

/******************************************************************************/
/*     RX Configuration bucket                                                */
/******************************************************************************/

/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_GFEC                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_gfec_t41(cs_uint16 module_id,
                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_OACFG0_t tmp_n10g_otnr_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0));
  tmp_n10g_otnr_oacfg0.bf.FECMD = 0;
  tmp_n10g_otnr_oacfg0.bf.POSTDSCR = 0;
  tmp_n10g_otnr_oacfg0.bf.PREDSCR = 1;
  tmp_n10g_otnr_oacfg0.bf.FECEN = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0), tmp_n10g_otnr_oacfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_UFEC                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_ufec_t41(cs_uint16 module_id,
                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDescramble off and PostDescramble on                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_OACFG0_t tmp_n10g_otnr_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0));
  tmp_n10g_otnr_oacfg0.bf.FECMD = 1;
  tmp_n10g_otnr_oacfg0.bf.POSTDSCR = 1;
  tmp_n10g_otnr_oacfg0.bf.PREDSCR = 0;
  tmp_n10g_otnr_oacfg0.bf.FECEN = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0), tmp_n10g_otnr_oacfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_NROWS                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_nrows_t41(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_uint16 rows)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Rows                                                        */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_OFCFG0_t tmp_n10g_otnr_ofcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_ofcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OFCFG0));
  tmp_n10g_otnr_ofcfg0.bf.NROWS = rows;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OFCFG0), tmp_n10g_otnr_ofcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_NCOLS                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_ncols_t41(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_uint16 columns)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Columns                                                     */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_OFCFG0_t tmp_n10g_otnr_ofcfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_ofcfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OFCFG0));
  tmp_n10g_otnr_ofcfg0.bf.NCOLS = columns;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OFCFG0), tmp_n10g_otnr_ofcfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_NPAR                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_npar_t41(cs_uint16 module_id,
                               cs_uint8  slice,
                               cs_uint16 parity)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Parity                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_OFCFG1_t tmp_n10g_otnr_ofcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_ofcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OFCFG1));
  tmp_n10g_otnr_ofcfg1.bf.NPAR = parity;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OFCFG1), tmp_n10g_otnr_ofcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_NPARB                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_nparb_t41(cs_uint16 module_id,
                                cs_uint8  slice,
                                cs_uint16 parity)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Parity                                                      */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_OFCFG1_t tmp_n10g_otnr_ofcfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_ofcfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OFCFG1));
  tmp_n10g_otnr_ofcfg1.bf.NPARB = parity;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OFCFG1), tmp_n10g_otnr_ofcfg1.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2_t41(cs_uint16 module_id,
                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receiving OTU2 traffic, aggregation is off and OTN is enabled            */
/*   Standard 7%, OTN aligner is enabled                                      */
/*   XSEL = 1 to send aligned OxU2 data to PP40G/XCON - This can be overwritten*/
/*   later DWMOD = 5 to configure 'OTU2 to ODU2' - FEC parity bytes are       */
/*   removed, Dewrapper is off                                                */
/*   BIPMSK = 0xFF, all SM, PM, 6 TCMs BIP-8 bits can be monitored, this affect*/
/*   all SM,PM,TCMn BIPs.                                                     */
/*                                                                            */
/*   ODU2 layer, traffic goes through OxU2 term which removes FEC overhead    */
/*   ODU2 layer, by pass Sonet framer, this can be reconfigured later if Sonet*/
/*   is on all SM, PM, 6 TCMs BIP-8 bits can be monitored, affects all BIP-8  */
/*   monitors in the same way                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_CFG5_t tmp_n10g_oohr_cfg5;
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_OTNR_OACFG0_t tmp_n10g_otnr_oacfg0;
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.OTNOFF = 0;
  tmp_n10g_gblr_dpcfg.bf.OBY = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);
 
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  ten_n10g_rx_ncols_t41(module_id, slice, 254);
  ten_n10g_rx_npar_t41(module_id, slice, 16);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0));
  tmp_n10g_otnr_oacfg0.bf.ALEN = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0), tmp_n10g_otnr_oacfg0.wrd);

  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.XSEL = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.FSOMD = 1;
  tmp_n10g_otnr_odwcfg.bf.DWMOD = 5;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.SBYFRM = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_oohr_cfg5.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_CFG5));
  tmp_n10g_oohr_cfg5.bf.BIPMSK = 0xff;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_CFG5), tmp_n10g_oohr_cfg5.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  ten_n10g_rx_gfec_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2_t41(cs_uint16 module_id,
                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receiving ODU2 traffic, aggregation is off and OTN is enabled            */
/*   No FEC party bytes are expected, NCOLS=238                               */
/*   XSEL = 1 to send aligned OxU2 data to PP40G/XCON - This can be overwritten*/
/*   later DWMOD = 5, this might not be necessary but should not matter.      */
/*   Dewrapper is off because DWMOD=5                                         */
/*   BIPMSK = 0x7F, all PM and 6 TCMs BIP can be monitored, this affect all   */
/*   PM,TCMn BIPs in the same way.                                            */
/*                                                                            */
/*   ODU2 layer, traffic goes through OxU2 term which removes FEC overhead    */
/*   ODU2 layer, by pass Sonet framer, this can be reconfigured later if Sonet*/
/*   is on all PM and TCMs BIP-8 bits can be minotored, affects all BIP-8     */
/*   monitors in the same way                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_CFG5_t tmp_n10g_oohr_cfg5;
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_OTNR_OACFG0_t tmp_n10g_otnr_oacfg0;
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.OTNOFF = 0;
  tmp_n10g_gblr_dpcfg.bf.OBY = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  ten_n10g_rx_ncols_t41(module_id, slice, 238);
  ten_n10g_rx_npar_t41(module_id, slice, 0);
  tmp_n10g_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0));
  tmp_n10g_otnr_oacfg0.bf.ALEN = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0), tmp_n10g_otnr_oacfg0.wrd);

  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.XSEL = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.FSOMD = 1;
  tmp_n10g_otnr_odwcfg.bf.DWMOD = 5;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.SBYFRM = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_oohr_cfg5.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_CFG5));
  tmp_n10g_oohr_cfg5.bf.BIPMSK = ((tmp_n10g_oohr_cfg5.bf.BIPMSK & ~0x7f) | (0x7f & 0x7f)) & 0xFFFF;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_CFG5), tmp_n10g_oohr_cfg5.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODUFLEX                                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oduflex_t41(cs_uint16 module_id,
                                  cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODUFLEX                                                                  */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2AGGR                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2aggr_t41(cs_uint16 module_id,
                                   cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Disable generation of dLOS at ODU2 layer, this is only configured to 3 for*/
/*   aggregation mode.                                                        */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_LOSCFG0_t tmp_n10g_gblr_loscfg0;
  TEN_N10G_OTNR_OACFG0_t tmp_n10g_otnr_oacfg0;
  TEN_N10G_OTNR_OACFG2_t tmp_n10g_otnr_oacfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_t41(module_id, slice);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0));
  tmp_n10g_otnr_oacfg0.bf.FECMD = 0;
  tmp_n10g_otnr_oacfg0.bf.POSTDSCR = 0;
  tmp_n10g_otnr_oacfg0.bf.PREDSCR = 0;
  tmp_n10g_otnr_oacfg0.bf.FECEN = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0), tmp_n10g_otnr_oacfg0.wrd);

  tmp_n10g_otnr_oacfg2.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG2));
  tmp_n10g_otnr_oacfg2.bf.MFCMPES = 1;
  tmp_n10g_otnr_oacfg2.bf.MFCMPED = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG2), tmp_n10g_otnr_oacfg2.wrd);

  tmp_n10g_gblr_loscfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, LOSCFG0));
  tmp_n10g_gblr_loscfg0.bf.LOSCFG = 3;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, LOSCFG0), tmp_n10g_gblr_loscfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_MONITOR_OPU2_PRBS                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_monitor_opu2_prbs_t41(cs_uint16 module_id,
                                            cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OPU2 layer, known pattern over OPU2                                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.DWMOD = 3;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.KPASEL = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OPU2                                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_opu2_t41(cs_uint16 module_id,
                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OPU2 layer, switches unaligned data to PP40G to XC                       */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_monitor_opu2_prbs_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS10G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.XSEL = 2;
  tmp_n10g_gblr_dpcfg.bf.SBYPLD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_CBR10                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_cbr10_t41(cs_uint16 module_id,
                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.SDHOFF = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS10G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.XSEL = 2;
  tmp_n10g_gblr_dpcfg.bf.SBYPLD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.STM64MD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OC192_FTREGEN                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oc192_ftregen_t41(cs_uint16 module_id,
                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 Full Transparent Regen Mode is enabled.                            */
/*   STM64MD = 1 in case OTN protocol is enabled.                             */
/*   OC192 framing alignment is enabled.                                      */
/*   OC192 descramble is enabled.                                             */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  TEN_N10G_SDFR_SDFCFG_t tmp_n10g_sdfr_sdfcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.SDHOFF = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.XSEL = 1;
  tmp_n10g_gblr_dpcfg.bf.SBYFRM = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.STM64MD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_sdfr_sdfcfg.wrd = TEN_REG_READ(TEN_XML_N10G_SDFR_REG_ADDR(pDev, module_id, slice, sdfr_SDFCFG));
  tmp_n10g_sdfr_sdfcfg.bf.SCREN = 1;
  TEN_REG_WRITE(TEN_XML_N10G_SDFR_REG_ADDR(pDev, module_id, slice, sdfr_SDFCFG), tmp_n10g_sdfr_sdfcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OC192_RSREGEN                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oc192_rsregen_t41(cs_uint16 module_id,
                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 RS Regen Mode is enabled.                                          */
/*   STM64MD = 1 in case OTN protocol is enabled.                             */
/*   OC192 framing alignment is enabled.                                      */
/*   OC192 descramble is enabled.                                             */
/*   OC192 B1 transparent mode is enabled.                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_SOHR_S1CFG_t tmp_n10g_sohr_s1cfg;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  TEN_N10G_SDFR_SDFCFG_t tmp_n10g_sdfr_sdfcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.SDHOFF = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.XSEL = 1;
  tmp_n10g_gblr_dpcfg.bf.SBYFRM = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.STM64MD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_sdfr_sdfcfg.wrd = TEN_REG_READ(TEN_XML_N10G_SDFR_REG_ADDR(pDev, module_id, slice, sdfr_SDFCFG));
  tmp_n10g_sdfr_sdfcfg.bf.SCREN = 1;
  TEN_REG_WRITE(TEN_XML_N10G_SDFR_REG_ADDR(pDev, module_id, slice, sdfr_SDFCFG), tmp_n10g_sdfr_sdfcfg.wrd);

  tmp_n10g_sohr_s1cfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, S1CFG));
  tmp_n10g_sohr_s1cfg.bf.B1TRANS = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, S1CFG), tmp_n10g_sohr_s1cfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OC192_MSREGEN                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oc192_msregen_t41(cs_uint16 module_id,
                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 MS Regen Mode is enabled.                                          */
/*   STM64MD = 1 in case OTN protocol is enabled.                             */
/*   OC192 framing alignment is enabled.                                      */
/*   OC192 descramble is enabled.                                             */
/*   OC192 B1 transparent mode is enabled.                                    */
/*   OC192 B2 transparent mode is enabled.                                    */
/*                                                                            */
/*   Make pattern checking possible by routing this extracted payload to the  */
/*   KPA                                                                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_SOHR_S1CFG_t tmp_n10g_sohr_s1cfg;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  TEN_N10G_SDFR_SDFCFG_t tmp_n10g_sdfr_sdfcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.SDHOFF = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.XSEL = 1;
  tmp_n10g_gblr_dpcfg.bf.SBYFRM = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.STM64MD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_sdfr_sdfcfg.wrd = TEN_REG_READ(TEN_XML_N10G_SDFR_REG_ADDR(pDev, module_id, slice, sdfr_SDFCFG));
  tmp_n10g_sdfr_sdfcfg.bf.SCREN = 1;
  TEN_REG_WRITE(TEN_XML_N10G_SDFR_REG_ADDR(pDev, module_id, slice, sdfr_SDFCFG), tmp_n10g_sdfr_sdfcfg.wrd);

  tmp_n10g_sohr_s1cfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, S1CFG));
  tmp_n10g_sohr_s1cfg.bf.B1TRANS = 1;
  tmp_n10g_sohr_s1cfg.bf.B2TRANS = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, S1CFG), tmp_n10g_sohr_s1cfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OC192_IN                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oc192_in_t41(cs_uint16 module_id,
                                   cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receiving OC192 traffic                                                  */
/*   OTN is bypassed                                                          */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.OBY = 1;
  tmp_n10g_gblr_dpcfg.bf.OTNOFF = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_VC4_64C_TERM                                      */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_vc4_64c_term_t41(cs_uint16 module_id,
                                       cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable OC192 SPE terminator                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS10G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.XSEL = 2;
  tmp_n10g_gblr_dpcfg.bf.KPASEL = 0;
  tmp_n10g_gblr_dpcfg.bf.SBYPLD = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_CBR10IN                                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_cbr10in_t41(cs_uint16 module_id,
                                  cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive CBR10 traffic, this CBR10 can be OC192 or other CBR traffic      */
/*   Bypass OTN and Sonet                                                     */
/*                                                                            */
/*   unaligned data going to XC                                               */
/*   known pattern unmapped                                                   */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.OBY = 1;
  tmp_n10g_gblr_dpcfg.bf.SBYPLD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS10G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.XSEL = 2;
  tmp_n10g_gblr_dpcfg.bf.KPASEL = 2;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_BMP                                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_bmp_t41(cs_uint16 module_id,
                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bit Synchronous Mapping Procedure                                        */
/*   DWMOD=1: ignore JC bytes                                                 */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  TEN_N10G_OGMPR_GMPODWCFG_t tmp_n10g_ogmpr_gmpodwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_gmpodwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG));
  tmp_n10g_ogmpr_gmpodwcfg.bf.DWMOD2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG), tmp_n10g_ogmpr_gmpodwcfg.wrd);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.DWMOD = 1;
  tmp_n10g_otnr_odwcfg.bf.JC_PLUS = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0x3;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_AMP                                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_amp_t41(cs_uint16 module_id,
                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bit Asynchronous Mapping Procedure                                       */
/*   DWMOD=3: process JC bytes                                                */
/*                                                                            */
/*   When LOF, configuring the bits below will make sure shutdown JC going to */
/*   syncdsync.                                                               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_OOHR_GENDWNLFSF_t tmp_n10g_oohr_gendwnlfsf;
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  TEN_N10G_OGMPR_GMPODWCFG_t tmp_n10g_ogmpr_gmpodwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_gmpodwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG));
  tmp_n10g_ogmpr_gmpodwcfg.bf.DWMOD2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG), tmp_n10g_ogmpr_gmpodwcfg.wrd);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.DWMOD = 3;
  tmp_n10g_otnr_odwcfg.bf.JC_PLUS = 0;
  tmp_n10g_otnr_odwcfg.bf.LINKALM_JCNOM = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_oohr_gendwnlfsf.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_GENDWNLFSF));
  tmp_n10g_oohr_gendwnlfsf.bf.GENSF_LOF = 1;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_GENDWNLFSF), tmp_n10g_oohr_gendwnlfsf.wrd);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0x2;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_AMP_PROP                                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_amp_prop_t41(cs_uint16 module_id,
                                   cs_uint8  slice,
                                   cs_uint16 fs)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Fs                                                          */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*      Bit Asynchronous Mapping Procedure for Cortina proprietary mapping.   */
/*      Enable JC-plus and set FS to user-supplied value.                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWFS_t tmp_n10g_otnr_odwfs;
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_amp_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.JC_PLUS = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_otnr_odwfs.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWFS));
  tmp_n10g_otnr_odwfs.bf.FS = fs;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWFS), tmp_n10g_otnr_odwfs.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_GMP_LO                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_gmp_lo_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable Low Order GMP                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  TEN_N10G_OGMPR_GMPODWCFG_t tmp_n10g_ogmpr_gmpodwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_gmpodwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG));
  tmp_n10g_ogmpr_gmpodwcfg.bf.DWMOD2 = 2;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG), tmp_n10g_ogmpr_gmpodwcfg.wrd);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0x2;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_GMP_HO                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_gmp_ho_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable High Order GMP                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  TEN_N10G_OGMPR_GMPODWCFG_t tmp_n10g_ogmpr_gmpodwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_gmpodwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG));
  tmp_n10g_ogmpr_gmpodwcfg.bf.DWMOD2 = 3;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG), tmp_n10g_ogmpr_gmpodwcfg.wrd);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0x21;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_GMP_CN                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_gmp_cn_t41(cs_uint16 module_id,
                                 cs_uint8  slice,
                                 cs_uint16 cn_lo16,
                                 cs_uint16 cn_hibit)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/*              o Cn_lo16                                                     */
/*              o Cn_hibit                                                    */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Set initial Cm client data entities mapped into server frame or server   */
/*   multi-frame when out of reset. Set Cn: Number of client bytes per server */
/*   frame/multiframe                                                         */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OGMPR_CNCFG1_t tmp_n10g_ogmpr_cncfg1;
  TEN_N10G_OGMPR_CNCFG0_t tmp_n10g_ogmpr_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1));
  tmp_n10g_ogmpr_cncfg1.bf.Cn1 = cn_hibit;  /* Bugzilla 36501 */
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1), tmp_n10g_ogmpr_cncfg1.wrd);

  tmp_n10g_ogmpr_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0));
  tmp_n10g_ogmpr_cncfg0.bf.Cn0 = cn_lo16; /* Bugzilla 36501 */
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0), tmp_n10g_ogmpr_cncfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_GFP_MAPPING                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_gfp_mapping_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   GFP Bit Synchronous Mapping Procedure                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  TEN_N10G_OGMPR_GMPODWCFG_t tmp_n10g_ogmpr_gmpodwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_gmpodwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG));
  tmp_n10g_ogmpr_gmpodwcfg.bf.DWMOD2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG), tmp_n10g_ogmpr_gmpodwcfg.wrd);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.DWMOD = 1;
  tmp_n10g_otnr_odwcfg.bf.JC_PLUS = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0x5;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_UFEC7                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_ufec7_t41(cs_uint16 module_id,
                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable standard 7% UFEC                                                  */
/*   Enable UFEC, PreDescramble off and PostDescramble on                     */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_ufec_t41(module_id, slice);
  ten_n10g_rx_nrows_t41(module_id, slice, 3);
  ten_n10g_rx_ncols_t41(module_id, slice, 254);
  ten_n10g_rx_npar_t41(module_id, slice, 16);
  ten_n10g_rx_nparb_t41(module_id, slice, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_UFEC10                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_ufec10_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable standard 10% UFEC                                                 */
/*   Enable UFEC, PreDescramble off and PostDescramble on                     */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_ufec_t41(module_id, slice);
  ten_n10g_rx_nrows_t41(module_id, slice, 3);
  ten_n10g_rx_ncols_t41(module_id, slice, 261);
  ten_n10g_rx_npar_t41(module_id, slice, 23);
  ten_n10g_rx_nparb_t41(module_id, slice, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_UFEC15                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_ufec15_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDescramble off and PostDescramble on                     */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_ufec_t41(module_id, slice);
  ten_n10g_rx_nrows_t41(module_id, slice, 3);
  ten_n10g_rx_ncols_t41(module_id, slice, 272);
  ten_n10g_rx_npar_t41(module_id, slice, 34);
  ten_n10g_rx_nparb_t41(module_id, slice, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_UFEC20                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_ufec20_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDescramble off and PostDescramble on                     */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_ufec_t41(module_id, slice);
  ten_n10g_rx_nrows_t41(module_id, slice, 3);
  ten_n10g_rx_ncols_t41(module_id, slice, 284);
  ten_n10g_rx_npar_t41(module_id, slice, 46);
  ten_n10g_rx_nparb_t41(module_id, slice, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_UFEC26                                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_ufec26_t41(cs_uint16 module_id,
                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable UFEC, PreDescramble off and PostDescramble on                     */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_ufec_t41(module_id, slice);
  ten_n10g_rx_nrows_t41(module_id, slice, 3);
  ten_n10g_rx_ncols_t41(module_id, slice, 300);
  ten_n10g_rx_npar_t41(module_id, slice, 62);
  ten_n10g_rx_nparb_t41(module_id, slice, 0);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTN_SCR_OFF                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otn_scr_off_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_OACFG0_t tmp_n10g_otnr_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0));
  tmp_n10g_otnr_oacfg0.bf.POSTDSCR = 0;
  tmp_n10g_otnr_oacfg0.bf.PREDSCR = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0), tmp_n10g_otnr_oacfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OC192_SCR_OFF                                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oc192_scr_off_t41(cs_uint16 module_id,
                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   None                                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_SDFR_SDFCFG_t tmp_n10g_sdfr_sdfcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_sdfr_sdfcfg.wrd = TEN_REG_READ(TEN_XML_N10G_SDFR_REG_ADDR(pDev, module_id, slice, sdfr_SDFCFG));
  tmp_n10g_sdfr_sdfcfg.bf.SCREN = 0;
  TEN_REG_WRITE(TEN_XML_N10G_SDFR_REG_ADDR(pDev, module_id, slice, sdfr_SDFCFG), tmp_n10g_sdfr_sdfcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_FEC_DATAPATH_BYPASS                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_fec_datapath_bypass_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Bypasses the FEC datapath for sims that have FEC blocks instantiated but */
/*     not running                                                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_OACFG0_t tmp_n10g_otnr_oacfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_oacfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0));
  tmp_n10g_otnr_oacfg0.bf.FECEN = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, OACFG0), tmp_n10g_otnr_oacfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_G43MD                                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_g43md_t41(cs_uint16 module_id,
                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Enable G43 Mode, DWMOD = 1 to enable dewrapper and ignore JC             */
/*   PTI = 9 according to G709 extended payload for GFP mapping               */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  TEN_N10G_OGMPR_GMPODWCFG_t tmp_n10g_ogmpr_gmpodwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.G43MD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_ogmpr_gmpodwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG));
  tmp_n10g_ogmpr_gmpodwcfg.bf.DWMOD2 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, GMPODWCFG), tmp_n10g_ogmpr_gmpodwcfg.wrd);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.DWMOD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0x9;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/*     Customer Application Configurations                                    */
/******************************************************************************/

/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OC192_PRBS                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oc192_prbs_t41(cs_uint16 module_id,
                                     cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive OC192 traffic and analyze PRBS payload                           */
/*   Enable OC192 SPE terminator                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_oc192_in_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  ten_n10g_rx_vc4_64c_term_t41(module_id, slice);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2_PRBS                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2_prbs_t41(cs_uint16 module_id,
                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive OTU2 traffic and analyze PRBS payload                            */
/*   PTI = 0xFE to indicate PRBS testing signal mapping                       */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.KPASEL = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0xFE;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2_OC192_MSREGEN_PRBS                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2_oc192_msregen_prbs_t41(cs_uint16 module_id,
                                                  cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive OTU2 traffic carrying OC192 data and analyze PRBS payload in OC192*/
/*   SPE STM64MD=1                                                            */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable OC192 SPE terminator                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  ten_n10g_rx_vc4_64c_term_t41(module_id, slice);

  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2_10GE                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2_10ge_t41(cs_uint16 module_id,
                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODU2 traffic carrying 10GE data, use BMP mapping                 */
/*   STM64MD=0                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_10GE                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_10ge_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic carrying ODU2 with 10GE payload, use BMP mapping   */
/*   STM64MD=0                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2E_BMP_10GE                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2e_bmp_10ge_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODU2E traffic carrying 10GE data, use BMP mapping                */
/*   STM64MD=1                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_10ge_t41(module_id, slice);
  ten_n10g_rx_cbr10_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2E_BMP_10GE                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2e_bmp_10ge_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive OTU2E traffic carrying 10GE data, use BMP mapping                */
/*   STM64MD=1                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_cbr10_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU1E_BMP_10GE                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu1e_bmp_10ge_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive OTU1E traffic carrying 10GE data, use BMP mapping                */
/*   STM64MD=0                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_cbr10_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.STM64MD = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2E_BMP_10GE                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2e_bmp_10ge_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic, 10GE over ODU2E over ODTUx                        */
/*   10GE over ODU2E uses BMP mapping                                         */
/*   STM64MD=1                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_odu2_t41(module_id, slice);
  ten_n10g_rx_cbr10_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU1E_BMP_10GE                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu1e_bmp_10ge_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic, 10GE over ODU1E over ODTUx                        */
/*   10GE over ODU1E uses BMP mapping                                         */
/*   STM64MD=0                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_odu2_t41(module_id, slice);
  ten_n10g_rx_cbr10_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.STM64MD = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2_BMP_OC192_MSREGEN_10GE                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2_bmp_oc192_msregen_10ge_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODU2 traffic, 10GE over OC192 over ODU2                          */
/*   OC192 over ODU2 uses BMP mapping                                         */
/*   STM64MD=1                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable OC192 SPE terminator                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  ten_n10g_rx_vc4_64c_term_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_BMP_OC192_MSREGEN_10GE                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_bmp_oc192_msregen_10ge_t41(cs_uint16 module_id,
                                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic, 10GE over OC192 over ODU2                         */
/*   OC192 over ODU2 uses BMP mapping                                         */
/*   STM64MD=1                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable OC192 SPE terminator                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  ten_n10g_rx_vc4_64c_term_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2E_10GFC                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2e_10gfc_t41(cs_uint16 module_id,
                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic, 10GFC over ODU2E over ODTUx                       */
/*   10GFC over ODU2E uses BMP mapping                                        */
/*   STM64MD=0 ?  Is this correct?                                            */
/*   PTI = 0x8 to indicate FC-1200 mapping into ODU2E                         */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 8;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2E_10GE                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2e_10ge_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic, 10GE over ODU2E over ODTUx                        */
/*   10GE over ODU2E uses BMP mapping                                         */
/*   STM64MD=0 ?  Is this correct?                                            */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2E_10GFC                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2e_10gfc_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODU2E traffic                                                    */
/*   10GFC over ODU2E uses BMP mapping                                        */
/*   STM64MD=0 ?  Is this correct?                                            */
/*   PTI = 0x8 to indicate FC-1200 mapping into ODU2E                         */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 8;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2E_40GEP                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2e_40gep_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODU2E traffic                                                    */
/*   40GE Parallel over ODU2E uses BMP mapping                                */
/*   STM64MD=1                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_cbr10_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2E_40GEP                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2e_40gep_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive OTU2E traffic                                                    */
/*   40GE Parallel over OTU2E uses BMP mapping                                */
/*   STM64MD=1                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_cbr10_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2E_40GEP_26P                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2e_40gep_26p_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive OTU2E traffic with 26% UFEC                                      */
/*   40GE Parallel over OTU2E uses BMP mapping                                */
/*   STM64MD=1                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/*   Enable UFEC, PreDescramble off and PostDescramble on                     */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_cbr10_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_ufec26_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2_BMP_OC192_MSREGEN                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2_bmp_oc192_msregen_t41(cs_uint16 module_id,
                                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODU2 traffic                                                     */
/*   OC192 over OTU2E uses BMP mapping                                        */
/*   STM64MD=1                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_BMP_OC192_MSREGEN                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_bmp_oc192_msregen_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic, OC192 over ODU2 over ODTUx,                       */
/*   OC192 over ODU2 uses BMP mapping                                         */
/*   STM64MD=1                                                                */
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODUFLEX_BMP_4GFC                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oduflex_bmp_4gfc_t41(cs_uint16 module_id,
                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODUFLEX traffic                                                  */
/*   4GFC over ODUFLEX uses BMP mapping                                       */
/*   STM64MD=0                                                                */
/*   PTI = 0xE to indicate 4GFC mapping into ODUFLEX                          */
/*   ODUFLEX                                                                  */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_oduflex_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0xE;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODUFLEX_BMP_8GFC                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oduflex_bmp_8gfc_t41(cs_uint16 module_id,
                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODUFLEX traffic                                                  */
/*                                                                            */
/*        8GFC over ODUFLEX uses BMP mapping                                  */
/*   STM64MD=0                                                                */
/*   PTI = 0xF to indicate 8GFC mapping into ODUFLEX                          */
/*   ODUFLEX                                                                  */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_oduflex_bmp_4gfc_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0xF;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODUFLEX_BMP_5GIBA                                 */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oduflex_bmp_5giba_t41(cs_uint16 module_id,
                                            cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODUFLEX traffic                                                  */
/*   5G Infinite Band over ODUFLEX uses BMP mapping                           */
/*   STM64MD=0                                                                */
/*   ODUFLEX                                                                  */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_oduflex_bmp_4gfc_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODUFLEX_BMP_4GFC                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_oduflex_bmp_4gfc_t41(cs_uint16 module_id,
                                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTux traffic, 4GFC over ODUFLEX over ODTUx                      */
/*   4GFC over ODUFLEX uses BMP mapping                                       */
/*   STM64MD=0                                                                */
/*   PTI = 0xE to indicate 4GFC mapping into ODUFLEX                          */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0xE;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODUFLEX_BMP_8GFC                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_oduflex_bmp_8gfc_t41(cs_uint16 module_id,
                                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTux traffic, 8GFC over ODUFLEX over ODTUx                      */
/*   8GFC over ODUFLEX uses BMP mapping                                       */
/*   STM64MD=0                                                                */
/*   PTI = 0xF to indicate 8GFC mapping into ODUFLEX                          */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odtu_oduflex_bmp_4gfc_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0xF;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODUFLEX_BMP_5GIBA                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_oduflex_bmp_5giba_t41(cs_uint16 module_id,
                                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTux traffic, 5GIBA over ODUFLEX over ODTUx                     */
/*   5GIBA over ODUFLEX uses BMP mapping                                      */
/*   STM64MD=0                                                                */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odtu_oduflex_bmp_4gfc_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2_ODU2                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2_odu2_t41(cs_uint16 module_id,
                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU2 layer termination only, FEC overhead bytes are added and ODU2 layer */
/*     is untouched by default                                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_t41(cs_uint16 module_id,
                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic, extract ODU2                                      */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU1E_ODU1E                                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu1e_odu1e_t41(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU1E_ODU1E ODU2=>OTU2                                                   */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2_GMP_LO_8GFC                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2_gmp_lo_8gfc_t41(cs_uint16 module_id,
                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODU2 traffic, extract 8GFC from ODU2 in Low Order GMP mapping    */
/*   Cn default value is 12953                                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable Low Order GMP                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OGMPR_CNCFG1_t tmp_n10g_ogmpr_cncfg1;
  TEN_N10G_OGMPR_CNCFG0_t tmp_n10g_ogmpr_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_gmp_lo_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1));
  tmp_n10g_ogmpr_cncfg1.bf.Cn1 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1), tmp_n10g_ogmpr_cncfg1.wrd);

  tmp_n10g_ogmpr_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0));
  tmp_n10g_ogmpr_cncfg0.bf.Cn0 = 12953;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0), tmp_n10g_ogmpr_cncfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_GMP_LO_8GFC                                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_gmp_lo_8gfc_t41(cs_uint16 module_id,
                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODTU_GMP_LO_8GFC 8GFC=>GMP LO ODU2AGGR                                   */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable Low Order GMP                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OGMPR_CNCFG1_t tmp_n10g_ogmpr_cncfg1;
  TEN_N10G_OGMPR_CNCFG0_t tmp_n10g_ogmpr_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_gmp_lo_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1));
  tmp_n10g_ogmpr_cncfg1.bf.Cn1 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1), tmp_n10g_ogmpr_cncfg1.wrd);

  tmp_n10g_ogmpr_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0));
  tmp_n10g_ogmpr_cncfg0.bf.Cn0 = 12953;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0), tmp_n10g_ogmpr_cncfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_GMP_LO_8GFC                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_gmp_lo_8gfc_t41(cs_uint16 module_id,
                                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODTU_ODU2_GMP_LO_8GFC 8GFC=>GMP LO ODU2AGGR                              */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable Low Order GMP                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OGMPR_CNCFG1_t tmp_n10g_ogmpr_cncfg1;
  TEN_N10G_OGMPR_CNCFG0_t tmp_n10g_ogmpr_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_gmp_lo_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1));
  tmp_n10g_ogmpr_cncfg1.bf.Cn1 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1), tmp_n10g_ogmpr_cncfg1.wrd);

  tmp_n10g_ogmpr_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0));
  tmp_n10g_ogmpr_cncfg0.bf.Cn0 = 12953;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0), tmp_n10g_ogmpr_cncfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2_GMP_HO_ODUFLEX                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2_gmp_ho_oduflex_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU2_GMP_HO_ODUFLEX Circuit=>GMP LO OTU2                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable High Order GMP                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_gmp_ho_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2E_GMP_HO_ODUFLEX                              */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2e_gmp_ho_oduflex_t41(cs_uint16 module_id,
                                               cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU2E_GMP_HO_ODUFLEX Circuit=>GMP LO OTU2E                               */
/*   OTU2_GMP_HO_ODUFLEX Circuit=>GMP LO OTU2                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable High Order GMP                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_gmp_ho_oduflex_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2_GMP_HO_ODUFLEX_8GFC                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2_gmp_ho_oduflex_8gfc_t41(cs_uint16 module_id,
                                                   cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU2_GMP_HO_ODUFLEX_8GFC Circuit=>GMP HO OTU2, 8GFC 8.5Gbps => Cn =      */
/*     104062 (0x1967E) and 7 time slots                                      */
/*   OTU2_GMP_HO_ODUFLEX Circuit=>GMP LO OTU2                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable High Order GMP                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OGMPR_CNCFG1_t tmp_n10g_ogmpr_cncfg1;
  TEN_N10G_OGMPR_ODWTSENABLE_t tmp_n10g_ogmpr_odwtsenable;
  TEN_N10G_OGMPR_CNCFG0_t tmp_n10g_ogmpr_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_gmp_ho_oduflex_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1));
  tmp_n10g_ogmpr_cncfg1.bf.Cn1 = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1), tmp_n10g_ogmpr_cncfg1.wrd);

  tmp_n10g_ogmpr_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0));
  tmp_n10g_ogmpr_cncfg0.bf.Cn0 = 0x967E;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0), tmp_n10g_ogmpr_cncfg0.wrd);

  tmp_n10g_ogmpr_odwtsenable.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWTSENABLE));
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN7 = 0;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN6 = 1;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN5 = 1;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN4 = 1;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN3 = 1;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN2 = 1;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN1 = 1;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN0 = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWTSENABLE), tmp_n10g_ogmpr_odwtsenable.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2E_GMP_HO_ODUFLEX_4GFC                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2e_gmp_ho_oduflex_4gfc_t41(cs_uint16 module_id,
                                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU2E_GMP_HO_ODUFLEX_4GFC Circuit=>GMP HO OTU2E, 4GFC 4.25Gbps => Cn =   */
/*     50219 and 4 time slots                                                 */
/*   OTU2E_GMP_HO_ODUFLEX Circuit=>GMP LO OTU2E                               */
/*   OTU2_GMP_HO_ODUFLEX Circuit=>GMP LO OTU2                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable High Order GMP                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OGMPR_CNCFG1_t tmp_n10g_ogmpr_cncfg1;
  TEN_N10G_OGMPR_ODWTSENABLE_t tmp_n10g_ogmpr_odwtsenable;
  TEN_N10G_OGMPR_CNCFG0_t tmp_n10g_ogmpr_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2e_gmp_ho_oduflex_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_ogmpr_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1));
  tmp_n10g_ogmpr_cncfg1.bf.Cn1 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1), tmp_n10g_ogmpr_cncfg1.wrd);

  tmp_n10g_ogmpr_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0));
  tmp_n10g_ogmpr_cncfg0.bf.Cn0 = 50219;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0), tmp_n10g_ogmpr_cncfg0.wrd);

  tmp_n10g_ogmpr_odwtsenable.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWTSENABLE));
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN7 = 0;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN6 = 0;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN5 = 0;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN4 = 0;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN3 = 1;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN2 = 1;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN1 = 1;
  tmp_n10g_ogmpr_odwtsenable.bf.TSEN0 = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWTSENABLE), tmp_n10g_ogmpr_odwtsenable.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2_GMP_LO_ODUFLEX_8GFC                          */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2_gmp_lo_oduflex_8gfc_t41(cs_uint16 module_id,
                                                   cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU2_GMP_LO_ODUFLEX_8GFC Circuit=>GMP LO OTU2, 8GFC 8.5Gbps => Cn =      */
/*     13008                                                                  */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable Low Order GMP                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OGMPR_CNCFG1_t tmp_n10g_ogmpr_cncfg1;
  TEN_N10G_OGMPR_CNCFG0_t tmp_n10g_ogmpr_cncfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_gmp_lo_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_ogmpr_cncfg1.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1));
  tmp_n10g_ogmpr_cncfg1.bf.Cn1 = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG1), tmp_n10g_ogmpr_cncfg1.wrd);

  tmp_n10g_ogmpr_cncfg0.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0));
  tmp_n10g_ogmpr_cncfg0.bf.Cn0 = 13008;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ogmpr_CNCFG0), tmp_n10g_ogmpr_cncfg0.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OC192_IN_OC192_MSREGEN                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oc192_in_oc192_msregen_t41(cs_uint16 module_id,
                                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 traffic coming in and OC192 going out to XC                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_oc192_in_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/*     N10G RX BLock Configurations                                           */
/******************************************************************************/

/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2_PRBS                                         */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2_prbs_t41(cs_uint16 module_id,
                                    cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODU2 traffic and analyze PRBS payload                            */
/*   PTI = 0xFE to indicate PRBS testing signal mapping                       */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.KPASEL = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0xFE;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2_OC192_MSREGEN_PRBS                           */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2_oc192_msregen_prbs_t41(cs_uint16 module_id,
                                                  cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODU2 traffic, extract OC192 and analyze PRBS payload within OC192*/
/*   SPE PTI = 0x3 to indicate synchronous mapping                            */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable OC192 SPE terminator                                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  ten_n10g_rx_vc4_64c_term_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.KPASEL = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0x3;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2_OC192_MSREGEN                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2_oc192_msregen_t41(cs_uint16 module_id,
                                             cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive OTU2 traffic, extract OC192                                      */
/*   this can be the data path configuration for intrusive monitoring of OC192*/
/*   PTI = 0x3 to indicate synchronous mapping                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OOHR_EXPTI_t tmp_n10g_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  tmp_n10g_oohr_expti.wrd = TEN_REG_READ(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI));
  tmp_n10g_oohr_expti.bf.EXPTI = 0x3;
  TEN_REG_WRITE(TEN_XML_N10G_OOHR_REG_ADDR(pDev, module_id, slice, oohr_EXPTI), tmp_n10g_oohr_expti.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_BYPASS_40G_TRAFFIC                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_bypass_40g_traffic_t41(cs_uint16 module_id,
                                             cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Traffic from 40G processor (bypass bus), bypassing N10G and going to 40G */
/*     Packet Processor bypass bus (PP40G)                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 1;
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS10G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_BYPASS_EXTERNAL                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_bypass_external_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Traffic from 40G processor (not bypass bus), bypassing N10G and going to */
/*     10G Packet Processor (PP10G)                                           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS10G = 1;
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_BYPASS_NON_INTRUSIVE_PP10GMON                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_bypass_non_intrusive_pp10gmon_t41(cs_uint16 module_id,
                                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Traffic from 40G processor (not bypass bus), bypassing N10G and going to */
/*   10G Packet Processor (PP10G) and XCON. This config also allows PP10G     */
/*   non-intrusive monitoring, thus same data goes on PP10G bus and XCON/PP40G*/
/*   bus from N10G                                                            */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS10G = 1;
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 2;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_BYPASS_10G_40G_TRAFFIC                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_bypass_10g_40g_traffic_t41(cs_uint16 module_id,
                                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Traffic from 40G processor ( both the bypass bus and TDMR)               */
/*   This config allows PP40G non-intrusive monitoring                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS10G = 1;
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_BYPASS_INTERNAL                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_bypass_internal_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Traffic from 40G processor (not bypass bus), bypassing OTN, Sonet and    */
/*     going to 10G Packet Processor (PP10G)                                  */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  TEN_N10G_GBL_BYPCFG_t tmp_n10g_gbl_bypcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.OBY = 1;
  tmp_n10g_gblr_dpcfg.bf.SBYPLD = 1;
  tmp_n10g_gblr_dpcfg.bf.XSEL = 2;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  tmp_n10g_gbl_bypcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG));
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS40G = 0;
  tmp_n10g_gbl_bypcfg.bf.RX_BYPASS10G = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, BYPCFG), tmp_n10g_gbl_bypcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODU2_NON_INTRUSIVE_MONITORING                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odu2_non_intrusive_monitoring_t41(cs_uint16 module_id,
                                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Can be use to overwrite what is going to the XCON for 10GE inside ODU    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.FSOMD = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.SBYFRM = 1;
  tmp_n10g_gblr_dpcfg.bf.XSEL = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODUFLEX_NON_INTRUSIVE_MONITORING                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oduflex_non_intrusive_monitoring_t41(cs_uint16 module_id,
                                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Can be use to overwrite what is going to the XCON for 10GE inside ODU    */
/*   No FEC to remove, so FSOMD = 0 instead of 1                              */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_OTNR_ODWCFG_t tmp_n10g_otnr_odwcfg;
  TEN_N10G_GBLR_DPCFG_t tmp_n10g_gblr_dpcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);
  
  tmp_n10g_otnr_odwcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG));
  tmp_n10g_otnr_odwcfg.bf.FSOMD = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, ODWCFG), tmp_n10g_otnr_odwcfg.wrd);

  tmp_n10g_gblr_dpcfg.wrd = TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG));
  tmp_n10g_gblr_dpcfg.bf.SBYFRM = 1;
  tmp_n10g_gblr_dpcfg.bf.XSEL = 1;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG), tmp_n10g_gblr_dpcfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU1E_ODU1E_BMP_WITH_NON_INTRUSIVE_MON            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu1e_odu1e_bmp_with_non_intrusive_mon_t41(cs_uint16 module_id,
                                                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU1E to XCON and Non-intrusive 10GE Monitoring                          */
/*   ODU1e goes to the XCON but 10GE to the PP10G                             */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/*   Can be use to overwrite what is going to the XCON for 10GE inside ODU    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu1e_bmp_10ge_t41(module_id, slice);
  ten_n10g_rx_odu2_non_intrusive_monitoring_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2E_ODU2E_BMP_WITH_NON_INTRUSIVE_MON            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2e_odu2e_bmp_with_non_intrusive_mon_t41(cs_uint16 module_id,
                                                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   ODU2E to XCON and Non-intrusive 10GE Monitoring                          */
/*   ODU2e goes to the XCON but 10GE to the PP10G                             */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/*   Can be use to overwrite what is going to the XCON for 10GE inside ODU    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2e_bmp_10ge_t41(module_id, slice);
  ten_n10g_rx_odu2_non_intrusive_monitoring_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU1E_BMP_NON_INTRUSIVE_MON                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu1e_bmp_non_intrusive_mon_t41(cs_uint16 module_id,
                                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Overwrite letting the ODU through the XCON                               */
/*   This is typically use if the receive client is OTU1e/ODU1e and only mon. */
/*   10GE                                                                     */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/*   Can be use to overwrite what is going to the XCON for 10GE inside ODU    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odtu_odu1e_bmp_10ge_t41(module_id, slice);
  ten_n10g_rx_odu2_non_intrusive_monitoring_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2E_BMP_NON_INTRUSIVE_MON                  */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2e_bmp_non_intrusive_mon_t41(cs_uint16 module_id,
                                                           cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Deaggregation of ODTU to ODU2e with 10GE monitoring                      */
/*   This is typically use if the receive client is OTU2/ODU2/OTU2e/ODU2e and */
/*   only mon. 10GE. Overwrite letting the ODU through the XCON               */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/*   Can be use to overwrite what is going to the XCON for 10GE inside ODU    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odtu_odu2e_bmp_10ge_t41(module_id, slice);
  ten_n10g_rx_odu2_non_intrusive_monitoring_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2E_10GE_BMP_NON_INTRUSIVE_MON             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2e_10ge_bmp_non_intrusive_mon_t41(cs_uint16 module_id,
                                                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Deaggregation of ODTU to 10GE with 10GE monitoring                       */
/*   i.e. The data is NOT going from the PP10G to XCON but N10G to XCON       */
/*   even if it is the same data                                              */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odtu_odu2e_bmp_10ge_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU1E_10GE_BMP_NON_INTRUSIVE_MON             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu1e_10ge_bmp_non_intrusive_mon_t41(cs_uint16 module_id,
                                                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Deaggregation of ODTU to 10GE with 10GE monitoring                       */
/*   i.e. The data is NOT going from the PP10G to XCON but N10G to XCON       */
/*   even if it is the same data                                              */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OC192 layer, termination, enables framing alignment and B1, B2           */
/*     monitoring, etc                                                        */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odtu_odu1e_bmp_10ge_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_AMP_OC192_MSREGEN                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_amp_oc192_msregen_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTU23 traffic, OC192 in OPU2 over ODU2 over ODTU23,             */
/*   AMP synchronicity                                                        */
/*   Multiplexor Section regen for OC192                                      */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_amp_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_AMP_OC192_RSREGEN                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_amp_oc192_rsregen_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTU23 traffic, OC192 in OPU2 over ODU2 over ODTU23,             */
/*   AMP synchronicity                                                        */
/*   Regenerator Section regen for OC192                           -->        */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_amp_t41(module_id, slice);
  ten_n10g_rx_oc192_rsregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_AMP_OC192                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_amp_oc192_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTU23 traffic, OC192 in OPU2 over ODU2 over ODTU23,             */
/*   AMP synchronicity                                                        */
/*   Fully Transparent regen for OC192                             -->        */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_amp_t41(module_id, slice);
  ten_n10g_rx_oc192_ftregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_BMP_OC192_RSREGEN                       */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_bmp_oc192_rsregen_t41(cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTU23 traffic, OC192 in OPU2 over ODU2 over ODTU23,             */
/*   AMP synchronicity                                                        */
/*   Regenerator Section regen for OC192                           -->        */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_oc192_rsregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_BMP_OC192                               */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_bmp_oc192_t41(cs_uint16 module_id,
                                              cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTU23 traffic, OC192 in OPU2 over ODU2 over ODTU23,             */
/*   AMP synchronicity                                                        */
/*   Fully Transparent regen for OC192                             -->        */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_oc192_ftregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OC192_IN_OC192_RSREGEN                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oc192_in_oc192_rsregen_t41(cs_uint16 module_id,
                                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 traffic coming in                                                  */
/*   OC192 going out to XC with Regenerator Section regen             -->     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_oc192_in_t41(module_id, slice);
  ten_n10g_rx_oc192_rsregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OC192_IN_OC192                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_oc192_in_oc192_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OC192 traffic coming in                                                  */
/*   OC192 going out to XC with Fully Transparent regen               -->     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_oc192_in_t41(module_id, slice);
  ten_n10g_rx_oc192_ftregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_GMPH0_OC192_MSREGEN                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_gmph0_oc192_msregen_t41(cs_uint16 module_id,
                                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic, OC192 over ODU2 over ODTUx,                       */
/*   OC192 over ODU2 uses BMP mapping                                         */
/*   0C192 using Regenerator Section regen                         -->        */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable High Order GMP                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_gmp_ho_t41(module_id, slice);
  ten_n10g_rx_oc192_msregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_GMPH0_OC192_RSREGEN                     */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_gmph0_oc192_rsregen_t41(cs_uint16 module_id,
                                                        cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic, OC192 over ODU2 over ODTUx,                       */
/*   OC192 over ODU2 uses BMP mapping                                         */
/*   0C192 using Regenerator Section regen                         -->        */
/*                                                                            */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable High Order GMP                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_gmp_ho_t41(module_id, slice);
  ten_n10g_rx_oc192_rsregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_GMPH0_OC192                             */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_gmph0_oc192_t41(cs_uint16 module_id,
                                                cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic, OC192 over ODU2 over ODTUx,                       */
/*   OC192 over ODU2 uses BMP mapping                                         */
/*   0C192 regen is Fully Transparent                                         */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/*   Enable High Order GMP                                                    */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  ten_n10g_rx_bmp_t41(module_id, slice);
  ten_n10g_rx_gmp_ho_t41(module_id, slice);
  ten_n10g_rx_oc192_ftregen_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU2v_ODU2_OPU2                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu2v_odu2_opu2_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive OTU2 traffic, send to xconn                                      */
/*   OTU2 layer termination only, FEC overhead bytes are added and ODU2 layer */
/*     is untouched by default                                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2_odu2_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  return (CS_OK);
}



/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_ODTU_ODU2_OPU2                                    */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_odtu_odu2_opu2_t41(cs_uint16 module_id,
                                         cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Receive ODTUx traffic carrying ODU2                                      */
/*   ODU2 Aggregation layer, aggregation is on and OTN is enabled, scramble   */
/*     is off                                                                 */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_odu2aggr_t41(module_id, slice);
  ten_n10g_rx_opu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_OTU1E_ODU2_OPU2                                   */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_otu1e_odu2_opu2_t41(cs_uint16 module_id,
                                          cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   OTU1E_ODU1E ODU2=>OTU2 OPU2                                              */
/*   Receive OTU2 traffic, send to xconn                                      */
/*   OTU2 layer termination only, FEC overhead bytes are added and ODU2 layer */
/*     is untouched by default                                                */
/*   Program NCOLS, for standard 7% FEC, NCOLS should be 254                  */
/*   Program NPAR for standard 7% FEC, NPAR should be 16                      */
/*   Enable GFEC, PreDescramble on and PostDescramble off                     */
/*   OPU2 layer, dewrapper is enabled and JC commands are evaluated           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  
  ten_n10g_rx_otu2v_odu2_opu2_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_RX_PASSTHRU_40GCKT_TO_PKT                            */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_rx_passthru_40gckt_to_pkt_t41(cs_uint16 module_id,
                                                 cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   N10G in bypass, N40G to PP10G/40G                                        */
/*   Traffic from 40G processor (not bypass bus), bypassing N10G and going to */
/*     10G Packet Processor (PP10G)                                           */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  ten_n10g_rx_bypass_external_t41(module_id, slice);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_GLOBAL_RELEASE_SRESET                                */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_global_release_sreset_t41(cs_uint16 module_id,
                                             cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Releases soft resets                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_CFG_t tmp_n10g_gbl_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  /* Bug #38685 - fix compiler warnings. */
  tmp_n10g_gbl_cfg.wrd = 0;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG), tmp_n10g_gbl_cfg.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);
  return (CS_OK);
}


/******************************************************************************/
/* $rtn_hdr_start   N10G_GLOBAL_SRESET                                        */
/* CATEGORY   : API                                                           */
/* ACCESS     : Public                                                        */
/* BLOCK      : N10G                                                          */
/* CHIP       : Tenabo                                                        */
cs_status ten_n10g_global_sreset_t41(cs_uint16 module_id,
                                     cs_uint8  slice)
/* INPUTS     : o Module_id                                                   */
/*              o Slice                                                       */
/* OUTPUTS    : ----                                                          */
/* RETURNS    : CS_OK or CS_ERROR                                             */
/* DESCRIPTION:                                                               */
/*   Sets and releases soft resets                                            */
/*   Releases soft resets                                                     */
/* $rtn_hdr_end                                                               */
/******************************************************************************/
{
  TEN_N10G_GBL_CFG_t tmp_n10g_gbl_cfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, FALSE);
  TEN_MOD_LOCK(module_id, TEN_ID_N10G);

  /* Bug #38685 - fix compiler warnings. */
  tmp_n10g_gbl_cfg.wrd = 0x017F;
  TEN_REG_WRITE(TEN_N10G_REG_ADDR(pDev, module_id, slice, CFG), tmp_n10g_gbl_cfg.wrd);

  /* TEN_MDELAY(6); Was used in simulation but probably not needed in a system */
  TEN_MOD_UNLOCK(module_id, TEN_ID_N10G);

  ten_n10g_global_release_sreset_t41(module_id, slice);
  return (CS_OK);
}


