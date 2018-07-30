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
 * ten_n40g_oohr.c
 *
 * N40G related code is implemented here.
 *
 * $Id: ten_n40g_oohr.c,v 1.19 2013/03/07 21:42:47 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNLFSF                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwnlfsf(cs_uint16 module_id, 
                               cs_uint16 sqgcc, 
                               cs_uint16 gensf_xlos, 
                               cs_uint16 gensf_los, 
                               cs_uint16 gensf_otuais, 
                               cs_uint16 gensf_lof, 
                               cs_uint16 gensf_feceed, 
                               cs_uint16 gensf_lom)
/* INPUTS     : o Module Id                                         */
/*              o SQGCC                                             */
/*              o GENSF XLOS                                        */
/*              o GENSF LOS                                         */
/*              o GENSF OTUAIS                                      */
/*              o GENSF LOF                                         */
/*              o GENSF FECEED                                      */
/*              o GENSF LOM                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Downstream Signal Fail Generation for Link/Frame         */
/* Layer Register.                                                  */
/*                                                                  */
/* The [sqgcc] parameter is specified as:                           */
/*   Forces squelching of GCC bytes to OHPP and serial port on      */
/*   a link/frame Signal Fail condition. The value of these         */
/*   bytes will be forced to FF in this case.                       */
/*                                                                  */
/* The [gensf_xlos] parameter is specified as:                      */
/*   Enables downstream link/frame Signal Fail due to external      */
/*   dLOS from optics.                                              */
/*                                                                  */
/* The [gensf_los] parameter is specified as:                       */
/*   Enables downstream link/frame Signal Fail due to dLOS.         */
/*                                                                  */
/* The [gensf_otuais] parameter is specified as:                    */
/*   Enables downstream link/frame Signal Fail due to dOTUkAIS.     */
/*                                                                  */
/* The [gensf_lof] parameter is specified as:                       */
/*   Enables downstream link/frame Signal Fail due to dLOF.         */
/*                                                                  */
/* The [gensf_feceed] parameter is specified as:                    */
/*   Enables downstream link/frame Signal Fail due to FECEED.       */
/*                                                                  */
/* The [gensf_lom] parameter is specified as:                       */
/*   Enables downstream link/frame Signal Fail due to dLOM.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNLFSF_t tmp_oohr_gendwnlfsf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwnlfsf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF));
  tmp_oohr_gendwnlfsf.bf.SQGCC = sqgcc;
  tmp_oohr_gendwnlfsf.bf.GENSF_XLOS = gensf_xlos;
  tmp_oohr_gendwnlfsf.bf.GENSF_LOS = gensf_los;
  tmp_oohr_gendwnlfsf.bf.GENSF_OTUAIS = gensf_otuais;
  tmp_oohr_gendwnlfsf.bf.GENSF_LOF = gensf_lof;
  tmp_oohr_gendwnlfsf.bf.GENSF_FECEED = gensf_feceed;
  tmp_oohr_gendwnlfsf.bf.GENSF_LOM = gensf_lom;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF), tmp_oohr_gendwnlfsf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNLFSF GENSF LOL                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwnlfsf_gensf_lol(cs_uint16 module_id, 
                                             cs_uint16 gensf_lol)
/* INPUTS     : o Module Id                                         */
/*              o GENSF LOL                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls Downstream Signal Fail Generation for Link/Frame Layer  */
/*                                                                  */
/*   [gensf_lol]                                                    */
/*     Enables downstream link/frame Signal Fail due to external    */
/*     dLOL from MLDRX. This bit applies only to N40G and has no    */
/*     effect in N10G.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNLFSF_t tmp_oohr_gendwnlfsf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwnlfsf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF));
  tmp_oohr_gendwnlfsf.bf.GENSF_LOL = gensf_lol;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF), tmp_oohr_gendwnlfsf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNLFSF SQBIPONLF                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwnlfsf_sqbiponlf(cs_uint16 module_id, 
                                             cs_uint16 sqbiponlf) 
/* INPUTS     : o Module Id                                         */
/*              o SQBIPONLF                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls Downstream Signal Fail Generation for Link/Frame Layer  */
/*                                                                  */
/*   [sqbiponlf]                                                    */
/*     Forces squelching of BIP sent to BEI Forwarding Unit on a    */
/*     link/frame Signal Fail condition.  The value of BIP will     */
/*     be forced to 0x00.                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N10G_OOHR_GENDWNLFSF_t tmp_oohr_gendwnlfsf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwnlfsf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF));
  tmp_oohr_gendwnlfsf.bf.SQBIPONLF = sqbiponlf;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF), tmp_oohr_gendwnlfsf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNLFSF SQIAEONMTTI                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwnlfsf_sqiaeonsmtti(cs_uint16 module_id, 
                                                cs_uint16 sqiaeonsmtti)
/* INPUTS     : o Module Id                                         */
/*              o SQIAEONSMTTI                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls Downstream Signal Fail Generation for Link/Frame Layer  */
/*                                                                  */
/*   [sqiaeonsmtti]                                                 */
/*     Forces squelching of dIAE sent to BEI Forwarding Unit on a   */
/*     dTIM condition in the SM sublayer.  The value of dIAE will   */
/*     be forced to 0.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N10G_OOHR_GENDWNLFSF_t tmp_oohr_gendwnlfsf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwnlfsf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF));
  tmp_oohr_gendwnlfsf.bf.SQIAEONSMTTI = sqiaeonsmtti;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF), tmp_oohr_gendwnlfsf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNLFSF SQIAEONLF                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwnlfsf_sqiaeonlf(cs_uint16 module_id, 
                                             cs_uint16 sqiaeonlf)
/* INPUTS     : o Module Id                                         */
/*              o SQIAEONLF                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls Downstream Signal Fail Generation for Link/Frame Layer  */
/*                                                                  */
/*   [sqiaeonlf]                                                    */
/*     Forces squelching of dIAE sent to BEI Forwarding Unit on a   */
/*     link/frame Signal Fail condition.  The value of dIAE will    */
/*     be forced to 0.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N10G_OOHR_GENDWNLFSF_t tmp_oohr_gendwnlfsf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwnlfsf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF));
  tmp_oohr_gendwnlfsf.bf.SQIAEONLF = sqiaeonlf;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNLFSF), tmp_oohr_gendwnlfsf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNPMSF                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwnpmsf(cs_uint16 module_id, 
                               cs_uint16 gensf_doduaisp, 
                               cs_uint16 gensf_dlckp, 
                               cs_uint16 gensf_docip, 
                               cs_uint16 gensf_dtimp, 
                               cs_uint16 gensf_dmsim, 
                               cs_uint16 gensf_dplm)
/* INPUTS     : o Module Id                                         */
/*              o GENSF DODUAISP                                    */
/*              o GENSF DLCKP                                       */
/*              o GENSF DOCIP                                       */
/*              o GENSF DTIMP                                       */
/*              o GENSF DMSIM                                       */
/*              o GENSF DPLM                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Downstream Signal Fail Generation for Path Layer         */
/* Register.                                                        */
/*                                                                  */
/* The [gensf_doduaisp] parameter is specified as:                  */
/*   Enables downstream Path Signal Fail due to dODUkAIS-P.         */
/*                                                                  */
/* The [gensf_dlckp] parameter is specified as:                     */
/*   Enables downstream Path Signal Fail due to dLCK-P.             */
/*                                                                  */
/* The [gensf_docip] parameter is specified as:                     */
/*   Enables downstream Path Signal Fail due to dOCI-P.             */
/*                                                                  */
/* The [gensf_dtimp] parameter is specified as:                     */
/*   Enables downstream Path Signal Fail due to dTIM-P from         */
/*   String Extractor #2.                                           */
/*                                                                  */
/* The [gensf_dmsim] parameter is specified as:                     */
/*   Enables downstream Path Signal Fail due to dMSIM.              */
/*                                                                  */
/* The [gensf_dplm] parameter is specified as:                      */
/*   Enables downstream Path Signal Fail due to dPLM                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNPMSF_t tmp_oohr_gendwnpmsf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwnpmsf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNPMSF));
  tmp_oohr_gendwnpmsf.bf.GENSF_DODUAISP = gensf_doduaisp;
  tmp_oohr_gendwnpmsf.bf.GENSF_DLCKP = gensf_dlckp;
  tmp_oohr_gendwnpmsf.bf.GENSF_DOCIP = gensf_docip;
  tmp_oohr_gendwnpmsf.bf.GENSF_DTIMP = gensf_dtimp;
  tmp_oohr_gendwnpmsf.bf.GENSF_DMSIM = gensf_dmsim;
  tmp_oohr_gendwnpmsf.bf.GENSF_DPLM = gensf_dplm;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNPMSF), tmp_oohr_gendwnpmsf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNTCM1SF                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwntcm1sf(cs_uint16 module_id, 
                                 cs_uint16 gensf_doduaistcm, 
                                 cs_uint16 gensf_dlcktcm, 
                                 cs_uint16 gensf_docitcm, 
                                 cs_uint16 gensf_dltc, 
                                 cs_uint16 gensf_dtimtcm)
/* INPUTS     : o Module Id                                         */
/*              o GENSF DODUAISTCM                                  */
/*              o GENSF DLCKTCM                                     */
/*              o GENSF DOCITCM                                     */
/*              o GENSF DLTC                                        */
/*              o GENSF DTIMTCM                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Downstream Signal Fail Generation for TCM Layer 1        */
/* Register.                                                        */
/*                                                                  */
/* The [gensf_doduaistcm] parameter is specified as:                */
/*   Enables downstream TCM Signal Fail due to dODUkAIS-TCM1.       */
/*                                                                  */
/* The [gensf_dlcktcm] parameter is specified as:                   */
/*   Enables downstreamTCM Signal Fail due to dLCK-TCM1.            */
/*                                                                  */
/* The [gensf_docitcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dOCI-TCM1.           */
/*                                                                  */
/* The [gensf_dltc] parameter is specified as:                      */
/*   Enables downstream TCM Signal Fail due to dLTC.                */
/*                                                                  */
/* The [gensf_dtimtcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dTIM-TCM1.           */
/*   String Extractors #3-8 are used for dTIM-TCM, with SE#3        */
/*   generating dTIM-TCM1 and SE#8 generating dTIM-TCM6.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNTCM1SF_t tmp_oohr_gendwntcm1sf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwntcm1sf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM1SF));
  tmp_oohr_gendwntcm1sf.bf.GENSF_DODUAISTCM = gensf_doduaistcm;
  tmp_oohr_gendwntcm1sf.bf.GENSF_DLCKTCM = gensf_dlcktcm;
  tmp_oohr_gendwntcm1sf.bf.GENSF_DOCITCM = gensf_docitcm;
  tmp_oohr_gendwntcm1sf.bf.GENSF_DLTC = gensf_dltc;
  tmp_oohr_gendwntcm1sf.bf.GENSF_DTIMTCM = gensf_dtimtcm;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM1SF), tmp_oohr_gendwntcm1sf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNTCM2SF                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwntcm2sf(cs_uint16 module_id, 
                                 cs_uint16 gensf_doduaistcm, 
                                 cs_uint16 gensf_dlcktcm, 
                                 cs_uint16 gensf_docitcm, 
                                 cs_uint16 gensf_dltc, 
                                 cs_uint16 gensf_dtimtcm)
/* INPUTS     : o Module Id                                         */
/*              o GENSF DODUAISTCM                                  */
/*              o GENSF DLCKTCM                                     */
/*              o GENSF DOCITCM                                     */
/*              o GENSF DLTC                                        */
/*              o GENSF DTIMTCM                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Downstream Signal Fail Generation for TCM Layer 2        */
/* Register.                                                        */
/*                                                                  */
/* The [gensf_doduaistcm] parameter is specified as:                */
/*   Enables downstream TCM Signal Fail due to dODUkAIS-TCM2.       */
/*                                                                  */
/* The [gensf_dlcktcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dLCK-TCM2.           */
/*                                                                  */
/* The [gensf_docitcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dOCI-TCM2.           */
/*                                                                  */
/* The [gensf_dltc] parameter is specified as:                      */
/*   Enables downstream TCM Signal Fail due to dLTC.                */
/*                                                                  */
/* The [gensf_dtimtcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dTIM-TCM2.           */
/*   String Extractors #3-8 are used for dTIM-TCM, with SE#3        */
/*   generating dTIM-TCM1 and SE#8 generating dTIM-TCM6.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNTCM2SF_t tmp_oohr_gendwntcm2sf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwntcm2sf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM2SF));
  tmp_oohr_gendwntcm2sf.bf.GENSF_DODUAISTCM = gensf_doduaistcm;
  tmp_oohr_gendwntcm2sf.bf.GENSF_DLCKTCM = gensf_dlcktcm;
  tmp_oohr_gendwntcm2sf.bf.GENSF_DOCITCM = gensf_docitcm;
  tmp_oohr_gendwntcm2sf.bf.GENSF_DLTC = gensf_dltc;
  tmp_oohr_gendwntcm2sf.bf.GENSF_DTIMTCM = gensf_dtimtcm;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM2SF), tmp_oohr_gendwntcm2sf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNTCM3SF                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwntcm3sf(cs_uint16 module_id, 
                                 cs_uint16 gensf_doduaistcm, 
                                 cs_uint16 gensf_dlcktcm, 
                                 cs_uint16 gensf_docitcm, 
                                 cs_uint16 gensf_dltc, 
                                 cs_uint16 gensf_dtimtcm)
/* INPUTS     : o Module Id                                         */
/*              o GENSF DODUAISTCM                                  */
/*              o GENSF DLCKTCM                                     */
/*              o GENSF DOCITCM                                     */
/*              o GENSF DLTC                                        */
/*              o GENSF DTIMTCM                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Downstream Signal Fail Generation for TCM Layer 3        */
/* Register.                                                        */
/*                                                                  */
/* The [gensf_doduaistcm] parameter is specified as:                */
/*   Enables downstream TCM Signal Fail due to dODUkAIS-TCM3.       */
/*                                                                  */
/* The [gensf_dlcktcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dLCK-TCM3.           */
/*                                                                  */
/* The [gensf_docitcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dOCI-TCM3.           */
/*                                                                  */
/* The [gensf_dltc] parameter is specified as:                      */
/*   Enables downstream TCM Signal Fail due to dLTC.                */
/*                                                                  */
/* The [gensf_dtimtcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dTIM-TCM3.           */
/*   String Extractors #3-8 are used for dTIM-TCM, with SE#3        */
/*   generating dTIM-TCM1 and SE#8 generating dTIM-TCM6.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNTCM3SF_t tmp_oohr_gendwntcm3sf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwntcm3sf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM3SF));
  tmp_oohr_gendwntcm3sf.bf.GENSF_DODUAISTCM = gensf_doduaistcm;
  tmp_oohr_gendwntcm3sf.bf.GENSF_DLCKTCM = gensf_dlcktcm;
  tmp_oohr_gendwntcm3sf.bf.GENSF_DOCITCM = gensf_docitcm;
  tmp_oohr_gendwntcm3sf.bf.GENSF_DLTC = gensf_dltc;
  tmp_oohr_gendwntcm3sf.bf.GENSF_DTIMTCM = gensf_dtimtcm;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM3SF), tmp_oohr_gendwntcm3sf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNTCM4SF                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwntcm4sf(cs_uint16 module_id, 
                                 cs_uint16 gensf_doduaistcm, 
                                 cs_uint16 gensf_dlcktcm, 
                                 cs_uint16 gensf_docitcm, 
                                 cs_uint16 gensf_dltc, 
                                 cs_uint16 gensf_dtimtcm)
/* INPUTS     : o Module Id                                         */
/*              o GENSF DODUAISTCM                                  */
/*              o GENSF DLCKTCM                                     */
/*              o GENSF DOCITCM                                     */
/*              o GENSF DLTC                                        */
/*              o GENSF DTIMTCM                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Downstream Signal Fail Generation for TCM Layer 4        */
/* Register.                                                        */
/*                                                                  */
/*                                                                  */
/* The [gensf_doduaistcm] parameter is specified as:                */
/*   Enables downstream TCM Signal Fail due to dODUkAIS-TCM4.       */
/*                                                                  */
/* The [gensf_dlcktcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dLCK-TCM4.           */
/*                                                                  */
/* The [gensf_docitcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dOCI-TCM4.           */
/*                                                                  */
/* The [gensf_dltc] parameter is specified as:                      */
/*   Enables downstream TCM Signal Fail due to dLTC.                */
/*                                                                  */
/* The [gensf_dtimtcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dTIM-TCM4.           */
/*   String Extractors #3-8 are used for dTIM-TCM, with SE#3        */
/*   generating dTIM-TCM1 and SE#8 generating dTIM-TCM6.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNTCM4SF_t tmp_oohr_gendwntcm4sf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwntcm4sf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM4SF));
  tmp_oohr_gendwntcm4sf.bf.GENSF_DODUAISTCM = gensf_doduaistcm;
  tmp_oohr_gendwntcm4sf.bf.GENSF_DLCKTCM = gensf_dlcktcm;
  tmp_oohr_gendwntcm4sf.bf.GENSF_DOCITCM = gensf_docitcm;
  tmp_oohr_gendwntcm4sf.bf.GENSF_DLTC = gensf_dltc;
  tmp_oohr_gendwntcm4sf.bf.GENSF_DTIMTCM = gensf_dtimtcm;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM4SF), tmp_oohr_gendwntcm4sf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNTCM5SF                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwntcm5sf(cs_uint16 module_id, 
                                 cs_uint16 gensf_doduaistcm, 
                                 cs_uint16 gensf_dlcktcm, 
                                 cs_uint16 gensf_docitcm, 
                                 cs_uint16 gensf_dltc, 
                                 cs_uint16 gensf_dtimtcm)
/* INPUTS     : o Module Id                                         */
/*              o GENSF DODUAISTCM                                  */
/*              o GENSF DLCKTCM                                     */
/*              o GENSF DOCITCM                                     */
/*              o GENSF DLTC                                        */
/*              o GENSF DTIMTCM                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Downstream Signal Fail Generation for TCM Layer 5        */
/* Register.                                                        */
/*                                                                  */
/*                                                                  */
/* The [gensf_doduaistcm] parameter is specified as:                */
/*   Enables downstream TCM Signal Fail due to dODUkAIS-TCM5.       */
/*                                                                  */
/* The [gensf_dlcktcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dLCK-TCM5.           */
/*                                                                  */
/* The [gensf_docitcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dOCI-TCM5.           */
/*                                                                  */
/* The [gensf_dltc] parameter is specified as:                      */
/*   Enables downstream TCM Signal Fail due to dLTC.                */
/*                                                                  */
/* The [gensf_dtimtcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dTIM-TCM5.           */
/*   String Extractors #3-8 are used for dTIM-TCM, with SE#3        */
/*   generating dTIM-TCM1 and SE#8 generating dTIM-TCM6.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNTCM5SF_t tmp_oohr_gendwntcm5sf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwntcm5sf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM5SF));
  tmp_oohr_gendwntcm5sf.bf.GENSF_DODUAISTCM = gensf_doduaistcm;
  tmp_oohr_gendwntcm5sf.bf.GENSF_DLCKTCM = gensf_dlcktcm;
  tmp_oohr_gendwntcm5sf.bf.GENSF_DOCITCM = gensf_docitcm;
  tmp_oohr_gendwntcm5sf.bf.GENSF_DLTC = gensf_dltc;
  tmp_oohr_gendwntcm5sf.bf.GENSF_DTIMTCM = gensf_dtimtcm;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM5SF), tmp_oohr_gendwntcm5sf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNTCM6SF                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwntcm6sf(cs_uint16 module_id, 
                                 cs_uint16 gensf_doduaistcm, 
                                 cs_uint16 gensf_dlcktcm, 
                                 cs_uint16 gensf_docitcm, 
                                 cs_uint16 gensf_dltc, 
                                 cs_uint16 gensf_dtimtcm)
/* INPUTS     : o Module Id                                         */
/*              o GENSF DODUAISTCM                                  */
/*              o GENSF DLCKTCM                                     */
/*              o GENSF DOCITCM                                     */
/*              o GENSF DLTC                                        */
/*              o GENSF DTIMTCM                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Downstream Signal Fail Generation for TCM Layer 6        */
/* Register.                                                        */
/*                                                                  */
/* The [gensf_doduaistcm] parameter is specified as:                */
/*   Enables downstream TCM Signal Fail due to dODUkAIS-TCM6.       */
/*                                                                  */
/* The [gensf_dlcktcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dLCK-TCM6.           */
/*                                                                  */
/* The [gensf_docitcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dOCI-TCM6.           */
/*                                                                  */
/* The [gensf_dltc] parameter is specified as:                      */
/*   Enables downstream TCM Signal Fail due to dLTC.                */
/*                                                                  */
/* The [gensf_dtimtcm] parameter is specified as:                   */
/*   Enables downstream TCM Signal Fail due to dTIM-TCM6.           */
/*   String Extractors #3-8 are used for dTIM-TCM, with SE#3        */
/*   generating dTIM-TCM1 and SE#8 generating dTIM-TCM6.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNTCM6SF_t tmp_oohr_gendwntcm6sf;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwntcm6sf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM6SF));
  tmp_oohr_gendwntcm6sf.bf.GENSF_DODUAISTCM = gensf_doduaistcm;
  tmp_oohr_gendwntcm6sf.bf.GENSF_DLCKTCM = gensf_dlcktcm;
  tmp_oohr_gendwntcm6sf.bf.GENSF_DOCITCM = gensf_docitcm;
  tmp_oohr_gendwntcm6sf.bf.GENSF_DLTC = gensf_dltc;
  tmp_oohr_gendwntcm6sf.bf.GENSF_DTIMTCM = gensf_dtimtcm;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNTCM6SF), tmp_oohr_gendwntcm6sf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNAIS                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwnais(cs_uint16 module_id, 
                              cs_uint16 genais_lf, 
                              cs_uint16 genais_sm, 
                              cs_uint16 genais_tcm6, 
                              cs_uint16 genais_tcm5, 
                              cs_uint16 genais_tcm4, 
                              cs_uint16 genais_tcm3, 
                              cs_uint16 genais_tcm2, 
                              cs_uint16 genais_tcm1, 
                              cs_uint16 genais_pm, 
                              cs_uint16 genais_py)
/* INPUTS     : o Module Id                                         */
/*              o GENAIS LF                                         */
/*              o GENAIS SM                                         */
/*              o GENAIS TCM6                                       */
/*              o GENAIS TCM5                                       */
/*              o GENAIS TCM4                                       */
/*              o GENAIS TCM3                                       */
/*              o GENAIS TCM2                                       */
/*              o GENAIS TCM1                                       */
/*              o GENAIS PM                                         */
/*              o GENAIS PY                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Downstream aAIS generation enable register.              */
/*                                                                  */
/* The [genais_lf] parameter is specified as:                       */
/*   Enables downstream aAIS due to Link/Frame layer Signal         */
/*   Fail (see GENDWNLFSF register).                                */
/*                                                                  */
/* The [genais_sm] parameter is specified as:                       */
/*   Enables downstream aAIS due to dTIM-S (dTIM detected by        */
/*   SE#1).                                                         */
/*                                                                  */
/* The [genais_tcm6] parameter is specified as:                     */
/*   Enables downstream aAIS due to TCM layer 6 Signal Fail         */
/*   (see GENDWNTCM6SF register).                                   */
/*                                                                  */
/* The [genais_tcm5] parameter is specified as:                     */
/*   Enables downstream aAIS due to TCM layer 5 Signal Fail         */
/*   (see GENDWNTCM5SF register).                                   */
/*                                                                  */
/* The [genais_tcm4] parameter is specified as:                     */
/*   Enables downstream aAIS due to TCM layer 4 Signal Fail         */
/*   (see GENDWNTCM4SF register).                                   */
/*                                                                  */
/* The [genais_tcm3] parameter is specified as:                     */
/*   Enables downstream aAIS due to TCM layer 3 Signal Fail         */
/*   (see GENDWNTCM3SF register).                                   */
/*                                                                  */
/* The [genais_tcm2] parameter is specified as:                     */
/*   Enables downstream aAIS due to TCM layer 2 Signal Fail         */
/*   (see GENDWNTCM2SF register).                                   */
/*                                                                  */
/* The [genais_tcm1] parameter is specified as:                     */
/*   Enables downstream aAIS due to TCM layer 1 Signal Fail         */
/*   (see GENDWNTCM1SF register).                                   */
/*                                                                  */
/* The [genais_pm] parameter is specified as:                       */
/*   Enables downstream aAIS due to Path layer Signal Fail          */
/*   (see GENDWNPMSF register).                                     */
/*                                                                  */
/* The [genais_py] parameter is specified as:                       */
/*   Enables downstream aAIS due to dCBRGENAIS detected in          */
/*   payload.                                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNAIS_t tmp_oohr_gendwnais;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwnais.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNAIS));
  tmp_oohr_gendwnais.bf.GENAIS_LF = genais_lf;
  tmp_oohr_gendwnais.bf.GENAIS_SM = genais_sm;
  tmp_oohr_gendwnais.bf.GENAIS_TCM6 = genais_tcm6;
  tmp_oohr_gendwnais.bf.GENAIS_TCM5 = genais_tcm5;
  tmp_oohr_gendwnais.bf.GENAIS_TCM4 = genais_tcm4;
  tmp_oohr_gendwnais.bf.GENAIS_TCM3 = genais_tcm3;
  tmp_oohr_gendwnais.bf.GENAIS_TCM2 = genais_tcm2;
  tmp_oohr_gendwnais.bf.GENAIS_TCM1 = genais_tcm1;
  tmp_oohr_gendwnais.bf.GENAIS_PM = genais_pm;
  tmp_oohr_gendwnais.bf.GENAIS_PY = genais_py;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNAIS), tmp_oohr_gendwnais.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GENDWNOK                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gendwnok(cs_uint16 module_id, 
                             cs_uint16 genok_lf, 
                             cs_uint16 genok_sm, 
                             cs_uint16 genok_tcm6, 
                             cs_uint16 genok_tcm5, 
                             cs_uint16 genok_tcm4, 
                             cs_uint16 genok_tcm3, 
                             cs_uint16 genok_tcm2, 
                             cs_uint16 genok_tcm1, 
                             cs_uint16 genok_pm, 
                             cs_uint16 genok_py)
/* INPUTS     : o Module Id                                         */
/*              o GENOK LF                                          */
/*              o GENOK SM                                          */
/*              o GENOK TCM6                                        */
/*              o GENOK TCM5                                        */
/*              o GENOK TCM4                                        */
/*              o GENOK TCM3                                        */
/*              o GENOK TCM2                                        */
/*              o GENOK TCM1                                        */
/*              o GENOK PM                                          */
/*              o GENOK PY                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the Down Stream OK generation enable Register.               */
/*                                                                  */
/*                                                                  */
/* The [genok_lf] parameter is specified as:                        */
/*   Enables downstream OK negation to Packet Processor due to      */
/*   Link/Frame layer Signal Fail (see GENDWNLFSF register).        */
/*                                                                  */
/* The [genok_sm] parameter is specified as:                        */
/*   Enables downstream OK negation to Packet Processor due to      */
/*   dTIM-S (dTIM detected by SE#1).                                */
/*                                                                  */
/* The [genok_tcm6] parameter is specified as:                      */
/*   Enables downstream OK negation to Packet Processor due to      */
/*   TCM layer 6 Signal Fail (see GENDWNTCM6SF register).           */
/*                                                                  */
/* The [genok_tcm5] parameter is specified as:                      */
/*   Enables downstream OK negation to Packet Processor due to      */
/*   TCM layer 5 Signal Fail (see GENDWNTCM5SF register).           */
/*                                                                  */
/* The [genok_tcm4] parameter is specified as:                      */
/*   Enables downstream OK negation to Packet Processor due to      */
/*   TCM layer 4 Signal Fail (see GENDWNTCM4SF register).           */
/*                                                                  */
/* The [genok_tcm3] parameter is specified as:                      */
/*   Enables downstream OK negation to Packet Processor due to      */
/*   TCM layer 3 Signal Fail (see GENDWNTCM3SF register).           */
/*                                                                  */
/* The [genok_tcm2] parameter is specified as:                      */
/*   Enables downstream OK negation to Packet Processor due to      */
/*   TCM layer 2 Signal Fail (see GENDWNTCM2SF register).           */
/*                                                                  */
/* The [genok_tcm1] parameter is specified as:                      */
/*   Enables downstream OK negation to Packet Processor due to      */
/*   TCM layer 1 Signal Fail (see GENDWNTCM1SF register).           */
/*                                                                  */
/* The [genok_pm] parameter is specified as:                        */
/*   Enables downstream OK negation to Packet Processor due to      */
/*   Path layer Signal Fail (see GENDWNPMSF register).              */
/*                                                                  */
/* The [genok_py] parameter is specified as:                        */
/*   Enables downstream OK negation to Packet Processor due to      */
/*   dCBRGENAIS detected in payload.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GENDWNOK_t tmp_oohr_gendwnok;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_gendwnok.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNOK));
  tmp_oohr_gendwnok.bf.GENOK_LF = genok_lf;
  tmp_oohr_gendwnok.bf.GENOK_SM = genok_sm;
  tmp_oohr_gendwnok.bf.GENOK_TCM6 = genok_tcm6;
  tmp_oohr_gendwnok.bf.GENOK_TCM5 = genok_tcm5;
  tmp_oohr_gendwnok.bf.GENOK_TCM4 = genok_tcm4;
  tmp_oohr_gendwnok.bf.GENOK_TCM3 = genok_tcm3;
  tmp_oohr_gendwnok.bf.GENOK_TCM2 = genok_tcm2;
  tmp_oohr_gendwnok.bf.GENOK_TCM1 = genok_tcm1;
  tmp_oohr_gendwnok.bf.GENOK_PM = genok_pm;
  tmp_oohr_gendwnok.bf.GENOK_PY = genok_py;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GENDWNOK), tmp_oohr_gendwnok.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CONFIG ITEMS 0 REG        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg0(cs_uint16 module_id, 
                         cs_uint16 mfdsyh, 
                         cs_uint16 mfsyhy)
/* INPUTS     : o Module Id                                         */
/*              o MFDSYH                                            */
/*              o MFSYHY                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the contents of the Miscellaneous Configuration Items       */
/* Register.                                                        */
/*                                                                  */
/*   [mfdsyh]                                                       */
/*                                                                  */
/* The [mfdsyh] parameter is specified as:                          */
/*   MFDSYH[7:0] = MFAS de-synchronization hysteresis. When LOM     */
/*   is reset and the received MFAS does not match the locally      */
/*   generated MFAS across more than MFDSYH consecutive frames,     */
/*   LOM is set.                                                    */
/*                                                                  */
/* The [mfsyhy] parameter is specified as:                          */
/*   MFSYHY[7:0] = MFAS synchronization hysteresis. When LOM is     */
/*   set and more than MFSYHY consecutive frames with valid         */
/*   MFAS values are received, the internal MFAS counter is         */
/*   updated and LOM is reset.                                      */
/*   NOTE:One more frame is needed to compare the previous MFAS     */
/*   value with the newly received value.                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG0_t tmp_oohr_cfg0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG0));
  tmp_oohr_cfg0.bf.MFDSYH = mfdsyh;
  tmp_oohr_cfg0.bf.MFSYHY = mfsyhy;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG0), tmp_oohr_cfg0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CONFIG ITEMS 1 REG    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_cfg1(cs_uint16 module_id, 
                                 cs_uint16 beidiv, 
                                 cs_uint16 beiniv)
/* INPUTS     : o Module Id                                     */
/*              o BEIDIV                                        */
/*              o BEINIV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Miscellaneous Configuration Items 1 */
/* Register.                                                    */
/*                                                              */
/* The [beidiv] parameter is specified as:                      */
/*   0x0000-0x00FF                                              */
/*   BEI Extract Signal Degrade Intermitted threshold Value.    */
/*   See BEIDTV for details.                                    */
/*                                                              */
/* The [beiniv] parameter is specified as:                      */
/*   0x0000-0x00FF                                              */
/*   BEI Extract No-signal-degrade Intermitted threshold Value. */
/*   See BEINTV for details.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_CFG1_t tmp_oohr_cfg1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG1));
  tmp_oohr_cfg1.bf.BEIDIV = beidiv;
  tmp_oohr_cfg1.bf.BEINIV = beiniv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG1), tmp_oohr_cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CONFIG ITEMS 2 REG    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_cfg2(cs_uint16 module_id, 
                                 cs_uint16 beintv, 
                                 cs_uint16 beidtv)
/* INPUTS     : o Module Id                                     */
/*              o BEINTV                                        */
/*              o BEIDTV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Miscellaneous Configuration Items 2 */
/* Register.                                                    */
/*                                                              */
/* The [beintv] parameter is specified as:                      */
/*   0x0000-0x00FF                                              */
/*   BEI Extract No-signal-degrade Threshold Value. Absence of  */
/*   excessive errors for BEINTV statistics intervals (as       */
/*   specified in BEISSEL) results in non-Signal Degrade state  */
/*   unless intermitted for more than BEINIV statistics         */
/*   intervals. When set to zero, every interval without        */
/*   excessive errors causes the BEI monitor to exit Signal     */
/*   Degrade state immediately.                                 */
/*                                                              */
/* The [beidtv] parameter is specified as:                      */
/*   0x0000-0x00FF                                              */
/*   BEI Extract Signal Degrade Threshold Value. Excessive      */
/*   errors result in Signal Degrade state when present for     */
/*   more than BEIDTV statistics intervals (as selected in      */
/*   BEISSEL without being intermitted for more than BEIDIV     */
/*   statistics intervals. When set to zero, every occurrence   */
/*   is accepted and BEIDIV is ignored.                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_CFG2_t tmp_oohr_cfg2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg2.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG2));
  tmp_oohr_cfg2.bf.BEINTV = beintv;
  tmp_oohr_cfg2.bf.BEIDTV = beidtv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG2), tmp_oohr_cfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CONFIG ITEMS 3 REG    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_cfg3(cs_uint16 module_id, 
                                 cs_uint16 bipdiv, 
                                 cs_uint16 bipniv)
/* INPUTS     : o Module Id                                     */
/*              o BIPDIV                                        */
/*              o BIPNIV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Miscellaneous Configuration Items 3 */
/* Register.                                                    */
/*                                                              */
/* The [bipdiv] parameter is specified as:                      */
/*   0x0000-0x00FF                                              */
/*   BIP8 Extract Signal Degrade Intermitted threshold Value    */
/*   See BIPDTV for details.                                    */
/*                                                              */
/* The [bipniv] parameter is specified as:                      */
/*   0x0000-0x00FF                                              */
/*   BIP8 Extract No-signal-degrade Intermitted threshold Value */
/*   See BIPNTV for details.                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_CFG3_t tmp_oohr_cfg3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg3.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG3));
  tmp_oohr_cfg3.bf.BIPDIV = bipdiv;
  tmp_oohr_cfg3.bf.BIPNIV = bipniv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG3), tmp_oohr_cfg3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CONFIG ITEMS 4 REG    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_cfg4(cs_uint16 module_id, 
                                 cs_uint16 bipntv, 
                                 cs_uint16 bipdtv)
/* INPUTS     : o Module Id                                     */
/*              o BIPNTV                                        */
/*              o BIPDTV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Miscellaneous Configuration Items 4 */
/* Register.                                                    */
/*                                                              */
/* The [bipntv] parameter is specified as:                      */
/*   0x0000-0x00FF                                              */
/*   BIP8 Extract No-signal-degrade Threshold Value. Absence of */
/*   excessive errors for BIPNTV statistics intervals (as       */
/*   selected in BIPSSEL) causes the BIP-8 monitor to exit      */
/*   Signal Degrade state unless intermitted for more than      */
/*   BIPNIV statistics intervals. When set to zero, any single  */
/*   interval without excessive errors causes the BIP-8 monitor */
/*   to exit Signal Degrade state immediately.                  */
/*                                                              */
/* The [bipdtv] parameter is specified as:                      */
/*   0x0000-0x00FF                                              */
/*   BIP8 Extract Signal Degrade Threshold Value. Excessive     */
/*   errors result in Signal Degrade state when present for     */
/*   more than BIPDTV statistics intervals (as selected in      */
/*   BIPSSEL) without being intermitted for more than BIPDIV    */
/*   statistics intervals. When set to zero, every occurrence   */
/*   is accepted and BIPDIV is ignored.                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_CFG4_t tmp_oohr_cfg4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg4.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG4));
  tmp_oohr_cfg4.bf.BIPNTV = bipntv;
  tmp_oohr_cfg4.bf.BIPDTV = bipdtv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG4), tmp_oohr_cfg4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CFG5 BIPMSK               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg5_bipmsk(cs_uint16 module_id, 
                         cs_uint16 bipmsk)
/* INPUTS     : o Module Id                                         */
/*              o BIPMSK                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the contents of the Miscellaneous Configuration Items 5     */
/* Register.                                                        */
/*                                                                  */
/* The [bipmsk] parameter is specified as:                          */
/*   BIPMSK[7:0] = Allows for excluding selected bits within a      */
/*   BIP-8 value from BIP-8 error monitoring. To exclude a bit,     */
/*   set the respective bit in BIPMSK to zero. This feature         */
/*   affects all BIP-8 monitors in the same way.                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG5_t tmp_oohr_cfg5;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5));
  tmp_oohr_cfg5.bf.BIPMSK = bipmsk;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5), tmp_oohr_cfg5.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CFG5 BIPSSEL              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg5_bipssel(cs_uint16 module_id, 
                         cs_uint16 bipssel)
/* INPUTS     : o Module Id                                         */
/*              o BIPSSEL                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the contents of the Miscellaneous Configuration Items 5     */
/* Register.                                                        */
/*                                                                  */
/* The [bipssel] parameter is specified as:                         */
/*   BIPSSEL[2:0] = BIP-8 Extraction Statistics Select Config-      */
/*   uration. Selects one out of eight global statistics            */
/*   interval timing generators.                                    */
/*   0 = 1st internal timing generator                              */
/*   1 = 2nd internal timing generator                              */
/*   2 = 3rd internal timing generator                              */
/*   3 = 4th internal timing generator                              */
/*   4 = 5th internal timing generator                              */
/*   5 = 6th internal timing generator                              */
/*   6 = Software controlled timing generator                       */
/*   7 = Timing generator controlled by external hardware           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG5_t tmp_oohr_cfg5;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5));
  tmp_oohr_cfg5.bf.BIPSSEL = bipssel;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5), tmp_oohr_cfg5.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CFG5 BEISSEL              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg5_beissel(cs_uint16 module_id, 
                         cs_uint16 beissel)
/* INPUTS     : o Module Id                                         */
/*              o BEISSEL                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the contents of the Miscellaneous Configuration Items 5     */
/* Register.                                                        */
/*                                                                  */
/* The [beissel] parameter is specified as:                         */
/*   BEISSEL[2:0] = BEI Extraction Statistics Select Config-        */
/*   uration. Selects one of out eight global statistics timing     */
/*   interval generators.                                           */
/*   0 = 1st internal timing generator                              */
/*   1 = 2nd internal timing generator                              */
/*   2 = 3rd internal timing generator                              */
/*   3 = 4th internal timing generator                              */
/*   4 = 5th internal timing generator                              */
/*   5  6th internal timing generator                               */
/*   6 = Software controlled timing generator                       */
/*   7 = Timing generator controlled by external hardware           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG5_t tmp_oohr_cfg5;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5));
  tmp_oohr_cfg5.bf.BEISSEL = beissel;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5), tmp_oohr_cfg5.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CFG5 MFALGNE              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg5_mfalgne(cs_uint16 module_id, 
                         cs_uint16 mfalgne)
/* INPUTS     : o Module Id                                         */
/*              o MFALGNE                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the contents of the Miscellaneous Configuration Items 5     */
/* Register.                                                        */
/*                                                                  */
/* The [mfalgne] parameter is specified as:                         */
/*   MFAS Alignment Enable. When set to '0', the internal MFAS      */
/*   counter is disabled and the incoming MFAS is used by all       */
/*   subsequent processors.                                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG5_t tmp_oohr_cfg5;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5));
  tmp_oohr_cfg5.bf.MFALGNE = mfalgne;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG5), tmp_oohr_cfg5.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CONFIG ITEMS 6 REG    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_cfg6(cs_uint16 module_id, 
                                 cs_uint16 sesiv, 
                                 cs_uint16 sestv)
/* INPUTS     : o Module Id                                     */
/*              o SESIV                                         */
/*              o SESTV                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Miscellaneous Configuration Items 6 */
/* Register.                                                    */
/*                                                              */
/* The [sesiv] parameter is specified as:                       */
/*   0x0000-0x00FF                                              */
/*   String Extraction Stable Intermitted threshold Value.      */
/*   See SESTV for details.                                     */
/*                                                              */
/* The [sestv] parameter is specified as:                       */
/*   0x0000-0x00FF                                              */
/*   String Extraction Stable Threshold Value. When more than   */
/*   SESTV consecutive matching strings are received without    */
/*   being intermitted by more than SESIV different strings,    */
/*   the string is regarded as stable. When set to zero, every  */
/*   occurrence is accepted and SESIV is ignored.               */
/*   NOTE:One more string is needed to compare the previous     */
/*   string with a new one.                                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_CFG6_t tmp_oohr_cfg6;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg6.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG6));
  tmp_oohr_cfg6.bf.SESIV = sesiv;
  tmp_oohr_cfg6.bf.SESTV = sestv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG6), tmp_oohr_cfg6.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET MISCELLANEOUS CONFIG ITEMS 7 REG    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_cfg7(cs_uint16 module_id, 
                                 cs_uint16 seuiv, 
                                 cs_uint16 seutv)
/* INPUTS     : o Module Id                                     */
/*              o SEUIV                                         */
/*              o SEUTV                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the contents of the Miscellaneous Configuration Items 7 */
/* Register.                                                    */
/*                                                              */
/* The [seuiv] parameter is specified as:                       */
/*   0x0000-0x00FF                                              */
/*   String Extraction Unstable Intermitted threshold Value.    */
/*   See SEUTV for details.                                     */
/*                                                              */
/* The [seutv] parameter is specified as:                       */
/*   0x0000-0x00FF                                              */
/*   String Extraction Unstable Threshold Value. When SEUTV     */
/*   consecutive strings differ from the accepted string        */
/*   without being intermitted by more than SEUIV matching      */
/*  strings, the string is regarded as unstable. When set to    */
/*   zero, every occurrence is accepted and SEUIV is ignored.   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_CFG7_t tmp_oohr_cfg7;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg7.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG7));
  tmp_oohr_cfg7.bf.SEUIV = seuiv;
  tmp_oohr_cfg7.bf.SEUTV = seutv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG7), tmp_oohr_cfg7.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG11 MSIEXT/CFG8 MSICNT               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg11_msiext_cfg8_msicnt(cs_uint16 module_id, 
                                                 cs_uint16 msi_ext__msi_cnt)
/* INPUTS     : o Module Id                                         */
/*              o MSIEXT_MSICNT                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets combined bits cfg11_msiext and cfg8_msicnt.                 */
/*                                                                  */
/* The [msi_ext__msi_cnt] parameter is specified as:                */
/*   Enable processing of extended MSI. Along with CFG8.MSICNT,     */
/*   determines the number of bytes in the MSI string.              */
/*   0 = 16-byte MSI (frames 2-17 of 256-frame PSI multi-frame)     */
/*   1 = 4-byte MSI (frames 2-5 of 256-frame PSI multi-frame)       */
/*   2 = 32-byte MSI (frames 2-33 of 256-frame PSI multi-frame)     */
/*   3 = 8-byte MSI (frames 2-9 of 256-frame PSI multi-frame).      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  if (msi_ext__msi_cnt > 3) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": msi_ext__msi_cnt out of range.  s/b 0..3.");
    return(CS_ERROR);
  }

  ten_n40g_oohr_cfg8_msicnt(module_id, msi_ext__msi_cnt&0x01);
  ten_n40g_oohr_cfg11_msi_ext(module_id, (msi_ext__msi_cnt&0x02)>>1);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG8 MSICNT                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg8_msicnt(cs_uint16 module_id, 
                                    cs_uint16 msicnt)
/* INPUTS     : o Module Id                                         */
/*              o MSICNT                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the contents of the Miscellaneous Configuration Items 8     */
/* msicnt.                                                          */
/*                                                                  */
/* The [msicnt] parameter is specified as:                          */
/*   Determines the number of bytes in the MSI string.              */
/*   0 = 16-byte MSI (frames 2-17 of 256-frame PSI multi-frame)     */
/*   1 =  4-byte MSI (frames 2-5  of 256-frame PSI multi-frame)     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG8_t tmp_oohr_cfg8;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg8.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG8));
  tmp_oohr_cfg8.bf.MSICNT = msicnt;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG8), tmp_oohr_cfg8.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG8                                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg8(cs_uint16 module_id, 
                         cs_uint16 msicnt, 
                         cs_uint16 stbldmsim, 
                         cs_uint16 stbldplm, 
                         cs_uint16 stbldtm, 
                         cs_uint16 iaeflen, 
                         cs_uint16 bdiflen, 
                         cs_uint16 biaeflen)
/* INPUTS     : o Module Id                                         */
/*              o MSICNT                                            */
/*              o STBLDMSIM                                         */
/*              o STBLDPLM                                          */
/*              o STBLDTM                                           */
/*              o IAEFLEN                                           */
/*              o BDIFLEN                                           */
/*              o BIAEFLEN                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the contents of the Miscellaneous Configuration Items 8     */
/* Register.                                                        */
/*                                                                  */
/* The [msicnt] parameter is specified as:                          */
/*   Determines the number of bytes in the MSI string.              */
/*   0 = 16-byte MSI (frames 2-17 of 256-frame PSI multi-frame)     */
/*   1 =  4-byte MSI (frames 2-5  of 256-frame PSI multi-frame)     */
/*                                                                  */
/* The [stbldmsim] parameter is specified as:                       */
/*   Determines how dMSIM status information is generated when      */
/*   MSI is unstable.                                               */
/*   0 = Sets the dMSIM defect either if a mismatch is detected     */
/*       between the accepted MSI string and the expected MSI       */
/*       or if the state of the received MSI is unstable.           */
/*   1 = Sets the dMSIM defect only if a mismatch is detected       */
/*       between the accepted MSI and the expected MSI. An          */
/*       unstable MSI has no effect.                                */
/*                                                                  */
/* The [stbldplm] parameter is specified as:                        */
/*   Determines how dPLM status information is generated when       */
/*   PTI is unstable.                                               */
/*   0 = Sets the dPLM defect either if a mismatch is detected      */
/*       between the accepted PTI and the expected PTI or if        */
/*       the state of the received PTI is unstable.                 */
/*   1 = Sets the dPLM defect only if a mismatch is detected        */
/*       between the accepted PTI and the expected PTI. An          */
/*       unstable PTI has no effect.                                */
/*                                                                  */
/* The [stbldtm] parameter is specified as:                         */
/*   Effective for all dTIM engines at the same time, STBLDTM       */
/*   determines how dTIM status information is generated:           */
/*   0 = Sets the dTIM output visible in SEnDTM either if the       */
/*       dTIM engine detects a mismatch between the received        */
/*       string and the reference string or if the state of the     */
/*       received string is unstable.                               */
/*   1 = Sets the dTIM output visible in SEnDTM only if the         */
/*       dTIM engine                                                */
/*                                                                  */
/* The [iaeflen] parameter is specified as:                         */
/*   IAEFLEN[3:0] = Length of OTUk dIAE filter. If value of "1"     */
/*   is detected in the IAE overhead bit for IAEFLEN consecu-       */
/*   tive frames, the dIAE defect is set. If the value "0" is       */
/*   detected for IAEFLEN consecutive frames, the dIAE defect       */
/*   is reset. For G.798 compliance, this value should be set       */
/*   to 5.                                                          */
/*                                                                  */
/* The [bdiflen] parameter is specified as:                         */
/*   BDIFLEN[3:0] = Length of dBDI filters. If value of "1" is      */
/*   detected in the BDI overhead bit for BDIFLEN consecutive       */
/*   frames, the dBDI defect is set. If the value "0" is            */
/*   detected for BDIFLEN consecutive frames, the dBDI defect       */
/*   is reset. For G.798 compliance, this value should be set       */
/*   to 5. This applies to the BIAE field in the SM, PM, and        */
/*   all TCM overheads.                                             */
/*                                                                  */
/* The [biaeflen] parameter is specified as:                        */
/*   BIAEFLEN[3:0] = Length of dBAIE filters. If value of           */
/*   "1011" is detected in the BIAE overhead bits for BIAEFLEN      */
/*   consecutive frames, the dBIAE defect is set. If the value      */
/*   "1011" is not detected for BIAEFLEN consecutive frames,        */
/*   the dBIAE defect is reset. For G.798 compliance, this          */
/*   value should be set to 3. This applies to the BIAE field       */
/*   in the SM and all TCM overheads.                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG8_t tmp_oohr_cfg8;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg8.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG8));
  tmp_oohr_cfg8.bf.MSICNT = msicnt;
  tmp_oohr_cfg8.bf.STBLDMSIM = stbldmsim;
  tmp_oohr_cfg8.bf.STBLDPLM = stbldplm;
  tmp_oohr_cfg8.bf.STBLDTM = stbldtm;
  tmp_oohr_cfg8.bf.IAEFLEN = iaeflen;
  tmp_oohr_cfg8.bf.BDIFLEN = bdiflen;
  tmp_oohr_cfg8.bf.BIAEFLEN = biaeflen;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG8), tmp_oohr_cfg8.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG9                                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg9(cs_uint16 module_id, 
                         cs_uint16 apsulen, 
                         cs_uint16 apsflen, 
                         cs_uint16 statulen, 
                         cs_uint16 statflen)
/* INPUTS     : o Module Id                                         */
/*              o APSULEN                                           */
/*              o APSFLEN                                           */
/*              o STATULEN                                          */
/*              o STATFLEN                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the contents of the Miscellaneous Configuration Items 9     */
/* Register.                                                        */
/*                                                                  */
/* The [apsulen] parameter is specified as:                         */
/*   APSULEN[3:0] = Length of APS/PCC unstable filter. If           */
/*   APSULEN multi-frames pass without APSFLEN consecutive          */
/*   identical values being detected for a specific channel,        */
/*   that APS/PCC channel is declared unstable. This applies to     */
/*   the OTU Section, Path, and all TCM APS/PCC channels.           */
/*                                                                  */
/* The [apsflen] parameter is specified as:                         */
/*   APSFLEN[3:0] = Length of APS/PCC byte filter. If an            */
/*   identical value is detected in the first three bytes of        */
/*   the APS/PCC overhead field during the same multi-frame         */
/*   slot for APSFLEN consecutive 8-frame multi-frames, the         */
/*   value is accepted. This applies to the OTU Section, Path,      */
/*   and all TCM APS/PCC channels.                                  */
/*                                                                  */
/* The [statulen] parameter is specified as:                        */
/*   STATULEN[3:0] = Length of STAT unstable filter. If             */
/*   STATULEN frames pass without STATFLEN consecutive              */
/*   identical values being detected, the STAT field is             */
/*   declared unstable. This applies to the STAT field in the       */
/*   PM and all TCM overheads.                                      */
/*                                                                  */
/* The [statflen] parameter is specified as:                        */
/*   STATFLEN[3:0] = Length of STAT filter. If an identical         */
/*   value is detected in the STAT overhead field for STATFLEN      */
/*   consecutive frames, the value is accepted. For G.798           */
/*   compliance, this value should be set to 3. This applies to     */
/*   the STAT field in the PM and all TCM overheads.                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG9_t tmp_oohr_cfg9;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg9.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG9));
  tmp_oohr_cfg9.bf.APSULEN = apsulen;
  tmp_oohr_cfg9.bf.APSFLEN = apsflen;
  tmp_oohr_cfg9.bf.STATULEN = statulen;
  tmp_oohr_cfg9.bf.STATFLEN = statflen;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG9), tmp_oohr_cfg9.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG10                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg10(cs_uint16 module_id, 
                          cs_uint16 msiulen, 
                          cs_uint16 msiflen, 
                          cs_uint16 ptiulen, 
                          cs_uint16 ptiflen)
/* INPUTS     : o Module Id                                         */
/*              o MSIULEN                                           */
/*              o MSIFLEN                                           */
/*              o PTIULEN                                           */
/*              o PTIFLEN                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the contents of the Miscellaneous Configuration Items 10    */
/* Register.                                                        */
/*                                                                  */
/* The [msiulen] parameter is specified as:                         */
/*   MSIULEN[3:0] = Length of MSI unstable filter. If MSIULEN       */
/*   multi-frames pass without MSIFLEN consecutive identical        */
/*   values being detected, the MI string is declared unstable.     */
/*                                                                  */
/* The [msiflen] parameter is specified as:                         */
/*   MSIFLEN[3:0] = Length of MSI string filter. If an              */
/*   identical value is detected in the 4 or 16-byte MSI string     */
/*   for MSIFLEN consecutive multi-frames, the value is             */
/*   accepted. For G.798 compliance, this value should be set       */
/*   to 3.                                                          */
/*                                                                  */
/* The [ptiulen] parameter is specified as:                         */
/*   PTIULEN[3:0] = Length of PTI unstable filter. If PTIULEN       */
/*   multi-frames pass without PTIFLEN consecutive identical        */
/*   values being detected, the PTI field is declared unstable.     */
/*                                                                  */
/* The [ptiflen] parameter is specified as:                         */
/*   PTIFLEN[3:0] = Length of PTI filter. If an identical value     */
/*   is detected in the PTI byte for PTIFLEN consecutive multi-     */
/*   frames, the value is accepted. For G.798 compliance,           */
/*   this value should be set to 3.                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG10_t tmp_oohr_cfg10;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg10.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG10));
  tmp_oohr_cfg10.bf.MSIULEN = msiulen;
  tmp_oohr_cfg10.bf.MSIFLEN = msiflen;
  tmp_oohr_cfg10.bf.PTIULEN = ptiulen;
  tmp_oohr_cfg10.bf.PTIFLEN = ptiflen;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG10), tmp_oohr_cfg10.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET EXPECTED PTI BYTE                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_expected_pti_byte(cs_uint16 module_id, 
                                         cs_uint16 expti)
/* INPUTS     : o Module Id                                     */
/*              o Expected PTI Byte                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Expected Payload Type Identifier (PTI).              */
/* Used for comparing against the accepted PTI value to         */
/* determine dPLM defect.                                       */
/*                                                              */
/* The [pti] parameter is specified as following:               */
/*   Expected PTI Byte                                          */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_oohr_expti;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_set_expected_pti_byte";  

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  CS_PRINT("%s() %s, expti=0x%X\n", func, ten_module_strings[module_id & 1], expti);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));
  tmp_oohr_expti.bf.EXPTI = expti;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI), tmp_oohr_expti.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G GET EXPECTED PTI BYTE                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n40g_get_expected_pti_byte(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Expected PTI Byte                               */
/* DESCRIPTION:                                                 */
/* Get the Expected Payload Type Identifier (PTI).              */
/* Used for comparing against the accepted PTI value to         */
/* determine dPLM defect.                                       */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  TEN_N40G_OOHR_EXPTI_t tmp_oohr_expti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_expti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXPTI));

  return ((cs_int16)tmp_oohr_expti.bf.EXPTI);
}

/****************************************************************/
/* $rtn_hdr_start  N40G COMPARE RECEIVED PTI BYTE               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_boolean ten_n40g_compare_pti_byte(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : TRUE or FALSE                                   */
/* DESCRIPTION:                                                 */
/* Compare the Accepted PTI Byte to the Expected PTI Byte.      */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  cs_boolean rtn_value;
  
  rtn_value = (ten_n40g_get_expected_pti_byte(module_id) ==
               ten_n40g_get_accepted_pti_byte(module_id));

  return (rtn_value);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET EXPECTED MSI STRING                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_expected_msi_string(cs_uint16 module_id, 
                                           cs_uint16 msi7,
                                           cs_uint16 msi6,
                                           cs_uint16 msi5,
                                           cs_uint16 msi4,
                                           cs_uint16 msi3,
                                           cs_uint16 msi2,
                                           cs_uint16 msi1,
                                           cs_uint16 msi0)
/* INPUTS     : o Module Id                                     */
/*              o Expected MSI String 7                         */
/*              o Expected MSI String 6                         */
/*              o Expected MSI String 5                         */
/*              o Expected MSI String 4                         */
/*              o Expected MSI String 3                         */
/*              o Expected MSI String 2                         */
/*              o Expected MSI String 1                         */
/*              o Expected MSI String 0                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Expected MSI.  Used for comparing against the        */
/* accepted MSI value to determine dMSIM defect. If MSICNT is   */
/* set to 1, only the lower 4 bytes are used for comparing      */
/* with the accepted MSI.                                       */
/*                                                              */
/* The [msi7-msi0] parameter is specified as following:         */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  TEN_N40G_OOHR_EXMSI0_t tmp_oohr_exmsi0;
  TEN_N40G_OOHR_EXMSI1_t tmp_oohr_exmsi1;
  TEN_N40G_OOHR_EXMSI2_t tmp_oohr_exmsi2;
  TEN_N40G_OOHR_EXMSI3_t tmp_oohr_exmsi3;
  TEN_N40G_OOHR_EXMSI4_t tmp_oohr_exmsi4;
  TEN_N40G_OOHR_EXMSI5_t tmp_oohr_exmsi5;
  TEN_N40G_OOHR_EXMSI6_t tmp_oohr_exmsi6;
  TEN_N40G_OOHR_EXMSI7_t tmp_oohr_exmsi7;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G); 
  tmp_oohr_exmsi0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI0));
  tmp_oohr_exmsi0.bf.EXMSI0 = msi0;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI0), tmp_oohr_exmsi0.wrd);
  tmp_oohr_exmsi1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI1));
  tmp_oohr_exmsi1.bf.EXMSI1 = msi1;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI1), tmp_oohr_exmsi1.wrd);
  tmp_oohr_exmsi2.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI2));
  tmp_oohr_exmsi2.bf.EXMSI2 = msi2;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI2), tmp_oohr_exmsi2.wrd);
  tmp_oohr_exmsi3.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI3));
  tmp_oohr_exmsi3.bf.EXMSI3 = msi3;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI3), tmp_oohr_exmsi3.wrd);
  tmp_oohr_exmsi4.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI4));
  tmp_oohr_exmsi4.bf.EXMSI4 = msi4;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI4), tmp_oohr_exmsi4.wrd);
  tmp_oohr_exmsi5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI5));
  tmp_oohr_exmsi5.bf.EXMSI5 = msi5;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI5), tmp_oohr_exmsi5.wrd);
  tmp_oohr_exmsi6.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI6));
  tmp_oohr_exmsi6.bf.EXMSI6 = msi6;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI6), tmp_oohr_exmsi6.wrd);
  tmp_oohr_exmsi7.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI7));
  tmp_oohr_exmsi7.bf.EXMSI7 = msi7;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI7), tmp_oohr_exmsi7.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET EXPECTED MSI EXT STRING             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N10G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_expected_msi_ext_string(cs_uint16 module_id, 
                                               cs_uint16 msi_ext7,
                                               cs_uint16 msi_ext6,
                                               cs_uint16 msi_ext5,
                                               cs_uint16 msi_ext4,
                                               cs_uint16 msi_ext3,
                                               cs_uint16 msi_ext2,
                                               cs_uint16 msi_ext1,
                                               cs_uint16 msi_ext0)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Expected MSI Ext String 7                     */
/*              o Expected MSI Ext String 6                     */
/*              o Expected MSI Ext String 5                     */
/*              o Expected MSI Ext String 4                     */
/*              o Expected MSI Ext String 3                     */
/*              o Expected MSI Ext String 2                     */
/*              o Expected MSI Ext String 1                     */
/*              o Expected MSI Ext String 0                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Expected MSI (Extension).   Used for comparing       */
/* against the accepted MSI value to determine dMSIM defect.    */
/* Expected MSI value - upper 16 bytes. Used when MSICNT=0      */
/* and MSI32 = 1.                                               */
/*                                                              */
/* The [msi_ext7-msi_ext0] parameter is specified as following: */
/*   0x0000 - 0xFFFF                                            */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  TEN_N40G_OOHR_EXMSI_EXT0_t tmp_oohr_exmsi_ext0;
  TEN_N40G_OOHR_EXMSI_EXT1_t tmp_oohr_exmsi_ext1;
  TEN_N40G_OOHR_EXMSI_EXT2_t tmp_oohr_exmsi_ext2;
  TEN_N40G_OOHR_EXMSI_EXT3_t tmp_oohr_exmsi_ext3;
  TEN_N40G_OOHR_EXMSI_EXT4_t tmp_oohr_exmsi_ext4;
  TEN_N40G_OOHR_EXMSI_EXT5_t tmp_oohr_exmsi_ext5;
  TEN_N40G_OOHR_EXMSI_EXT6_t tmp_oohr_exmsi_ext6;
  TEN_N40G_OOHR_EXMSI_EXT7_t tmp_oohr_exmsi_ext7;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G); 
  
  tmp_oohr_exmsi_ext0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT0));
  tmp_oohr_exmsi_ext0.bf.EXMSI0 = msi_ext0;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT0), tmp_oohr_exmsi_ext0.wrd);
  
  tmp_oohr_exmsi_ext1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT1));
  tmp_oohr_exmsi_ext1.bf.EXMSI1 = msi_ext1;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT1), tmp_oohr_exmsi_ext1.wrd);
  
  tmp_oohr_exmsi_ext2.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT2));
  tmp_oohr_exmsi_ext2.bf.EXMSI2 = msi_ext2;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT2), tmp_oohr_exmsi_ext2.wrd);
  
  tmp_oohr_exmsi_ext3.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT3));
  tmp_oohr_exmsi_ext3.bf.EXMSI3 = msi_ext3;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT3), tmp_oohr_exmsi_ext3.wrd);
  
  tmp_oohr_exmsi_ext4.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT4));
  tmp_oohr_exmsi_ext4.bf.EXMSI4 = msi_ext4;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT4), tmp_oohr_exmsi_ext4.wrd);
  
  tmp_oohr_exmsi_ext5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT5));
  tmp_oohr_exmsi_ext5.bf.EXMSI5 = msi_ext5;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT5), tmp_oohr_exmsi_ext5.wrd);
  
  tmp_oohr_exmsi_ext6.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT6));
  tmp_oohr_exmsi_ext6.bf.EXMSI6 = msi_ext6;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT6), tmp_oohr_exmsi_ext6.wrd);
     
  tmp_oohr_exmsi_ext7.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT7));
  tmp_oohr_exmsi_ext7.bf.EXMSI7 = msi_ext7;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, EXMSI_EXT7), tmp_oohr_exmsi_ext7.wrd);
  
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G GET ACCEPTED PTI BYTE                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n40g_get_accepted_pti_byte(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Accepted PTI Byte                               */
/* DESCRIPTION:                                                 */
/* Get the Accepted Payload Type Identifier (PTI).              */
/* Updated when an identical value is received in the PTI byte  */
/* for PTIFLEN consecutive multi-frames. Used for comparing     */
/* against the expected PTI value to determine dPLM defect.     */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  TEN_N40G_OOHR_ACPTI_t tmp_oohr_acpti;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  tmp_oohr_acpti.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACPTI));

  return ((cs_int16)tmp_oohr_acpti.bf.ACPTI);
}

/****************************************************************/
/* $rtn_hdr_start  N40G GET ACCEPTED MSI STRING                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_int16 ten_n40g_get_accepted_msi_string(cs_uint16 module_id,
                                          cs_uint8 index)
/* INPUTS     : o Module Id                                     */
/*              o Index                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Accepted MSI String                             */
/* DESCRIPTION:                                                 */
/* Get the Accepted MSI String.                                 */
/* Updated when an identical value is received in the MSI       */
/* string for MSIFLEN consecutive multi-frames. Used for        */
/* comparing against the expected MSI value to determine dMSIM  */
/* defect.                                                      */
/*                                                              */
/* The [index] parameter is index of MSI String:                */
/*   15 =  TEN_N40G_OOHR_ACCEPTED_MSI_EXT7,                     */
/*   14 =  TEN_N40G_OOHR_ACCEPTED_MSI_EXT6,                     */
/*   13 =  TEN_N40G_OOHR_ACCEPTED_MSI_EXT5,                     */
/*   12 =  TEN_N40G_OOHR_ACCEPTED_MSI_EXT4,                     */
/*   11 =  TEN_N40G_OOHR_ACCEPTED_MSI_EXT3,                     */
/*   10 =  TEN_N40G_OOHR_ACCEPTED_MSI_EXT2,                     */
/*   9  =  TEN_N40G_OOHR_ACCEPTED_MSI_EXT1,                     */
/*   8  =  TEN_N40G_OOHR_ACCEPTED_MSI_EXT0,                     */
/*   7  =  TEN_N40G_OOHR_ACCEPTED_MSI7,                         */
/*   6  =  TEN_N40G_OOHR_ACCEPTED_MSI6,                         */
/*   5  =  TEN_N40G_OOHR_ACCEPTED_MSI5,                         */
/*   4  =  TEN_N40G_OOHR_ACCEPTED_MSI4,                         */
/*   3  =  TEN_N40G_OOHR_ACCEPTED_MSI3,                         */
/*   2  =  TEN_N40G_OOHR_ACCEPTED_MSI2,                         */
/*   1  =  TEN_N40G_OOHR_ACCEPTED_MSI1,                         */
/*   0  =  TEN_N40G_OOHR_ACCEPTED_MSI0.                         */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  switch (index) {
  
    /* Bugzilla #28016, SW APIs needed for 32-byte MSI string */
    case 15:
     {
      TEN_N40G_OOHR_ACMSI_EXT7_t tmp_oohr_acmsi_ext7;
      tmp_oohr_acmsi_ext7.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI_EXT7));
      rtn = tmp_oohr_acmsi_ext7.bf.ACMSI7;
      break;
    }
    case 14:
    {
      TEN_N40G_OOHR_ACMSI_EXT6_t tmp_oohr_acmsi_ext6;
      tmp_oohr_acmsi_ext6.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI_EXT6));
      rtn = tmp_oohr_acmsi_ext6.bf.ACMSI6;
      break;
    }
    case 13:
    {
      TEN_N40G_OOHR_ACMSI_EXT5_t tmp_oohr_acmsi_ext5;
      tmp_oohr_acmsi_ext5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI_EXT5));
      rtn = tmp_oohr_acmsi_ext5.bf.ACMSI5;
      break;
    }
    case 12:
    {
      TEN_N40G_OOHR_ACMSI_EXT4_t tmp_oohr_acmsi_ext4;
      tmp_oohr_acmsi_ext4.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI_EXT4));
      rtn = tmp_oohr_acmsi_ext4.bf.ACMSI4;
      break;
    }
    case 11:
    {
      TEN_N40G_OOHR_ACMSI_EXT3_t tmp_oohr_acmsi_ext3;
      tmp_oohr_acmsi_ext3.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI_EXT3));
      rtn = tmp_oohr_acmsi_ext3.bf.ACMSI3;
      break;
    }
    case 10:
    {
      TEN_N40G_OOHR_ACMSI_EXT2_t tmp_oohr_acmsi_ext2;
      tmp_oohr_acmsi_ext2.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI_EXT2));
      rtn = tmp_oohr_acmsi_ext2.bf.ACMSI2;
      break;
    }
    case 9:
    {
      TEN_N40G_OOHR_ACMSI_EXT1_t tmp_oohr_acmsi_ext1;
      tmp_oohr_acmsi_ext1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI_EXT1));
      rtn = tmp_oohr_acmsi_ext1.bf.ACMSI1;
      break;
    }
    case 8:
    {
      TEN_N40G_OOHR_ACMSI_EXT0_t tmp_oohr_acmsi_ext0;
      tmp_oohr_acmsi_ext0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI_EXT0));
      rtn = tmp_oohr_acmsi_ext0.bf.ACMSI0;
      break;
    }
  
    case (7):
    {
      TEN_N40G_OOHR_ACMSI7_t tmp_oohr_acmsi7;
      tmp_oohr_acmsi7.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI7));
      rtn = tmp_oohr_acmsi7.bf.ACMSI7;
      break;
    }
    
    case (6):
    {
      TEN_N40G_OOHR_ACMSI6_t tmp_oohr_acmsi6;
      tmp_oohr_acmsi6.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI6));
      rtn = tmp_oohr_acmsi6.bf.ACMSI6;
      break;
    }
  
    case (5):
    {
      TEN_N40G_OOHR_ACMSI5_t tmp_oohr_acmsi5;
      tmp_oohr_acmsi5.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI5));
      rtn = tmp_oohr_acmsi5.bf.ACMSI5;
      break;
    }
  
    case (4):
    {
      TEN_N40G_OOHR_ACMSI4_t tmp_oohr_acmsi4;
      tmp_oohr_acmsi4.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI4));
      rtn = tmp_oohr_acmsi4.bf.ACMSI4;
      break;
    }
  
    case (3):
    {
      TEN_N40G_OOHR_ACMSI3_t tmp_oohr_acmsi3;
      tmp_oohr_acmsi3.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI3));
      rtn = tmp_oohr_acmsi3.bf.ACMSI3;
      break;
    }
  
    case (2):
    {
      TEN_N40G_OOHR_ACMSI2_t tmp_oohr_acmsi2;
      tmp_oohr_acmsi2.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI2));
      rtn = tmp_oohr_acmsi2.bf.ACMSI2;
      break;
    }
  
    case (1):
    {
      TEN_N40G_OOHR_ACMSI1_t tmp_oohr_acmsi1;
      tmp_oohr_acmsi1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI1));
      rtn = tmp_oohr_acmsi1.bf.ACMSI1;
      break;
    }
  
    case (0):
    {
      TEN_N40G_OOHR_ACMSI0_t tmp_oohr_acmsi0;
      tmp_oohr_acmsi0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACMSI0));
      rtn = tmp_oohr_acmsi0.bf.ACMSI0;
      break;
    }
  
    default:
    {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..7.");
      rtn = CS_ERROR;
      break;
    }
  }
  return (rtn);
}


/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET APS/PCC                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int32 ten_n40g_oohr_get_aps_pcc(cs_uint16 module_id, cs_uint8 aps)
/* INPUTS     : o Module Id                                         */
/*              o APS Selection                                     */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* Returns the accepted APS/PCC value.                              */
/* Updated when an identical value is received in the first 3       */
/* bytes of the APS/PCC overhead field for the specific channel     */
/* for APSFLEN consecutive multi frames.                            */
/*                                                                  */
/* [aps]  0-7.  APS0 gives the accepted APS/PCC value for the       */
/* ODUk Path, APS1 through APS6 give the accepted APS/PCC values    */
/* for ODUk TCM1 through ODUk TCM6 respectively.  APS7 gives the    */
/* accepted APS/PCC value for the OTUk Section.                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int32 rtn = 0;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  switch (aps)
  {
    case (0):
    {
      TEN_N40G_OOHR_ACAPS01_t tmp_oohr_acaps1;
      TEN_N40G_OOHR_ACAPS00_t tmp_oohr_acaps0;
      tmp_oohr_acaps1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS01));
      tmp_oohr_acaps0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS00));
      rtn = (tmp_oohr_acaps1.wrd << 16) | tmp_oohr_acaps0.wrd;
      break;
    }
  
    case (1):
    {
      TEN_N40G_OOHR_ACAPS11_t tmp_oohr_acaps1;
      TEN_N40G_OOHR_ACAPS10_t tmp_oohr_acaps0;
      tmp_oohr_acaps1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS11));
      tmp_oohr_acaps0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS10));
      rtn = (tmp_oohr_acaps1.wrd << 16) | tmp_oohr_acaps0.wrd;
      break;
    }
  
    case (2):
    {
      TEN_N40G_OOHR_ACAPS21_t tmp_oohr_acaps1;
      TEN_N40G_OOHR_ACAPS20_t tmp_oohr_acaps0;
      tmp_oohr_acaps1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS21));
      tmp_oohr_acaps0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS20));
      rtn = (tmp_oohr_acaps1.wrd << 16) | tmp_oohr_acaps0.wrd;
      break;
    }
  
    case (3):
    {
      TEN_N40G_OOHR_ACAPS31_t tmp_oohr_acaps1;
      TEN_N40G_OOHR_ACAPS30_t tmp_oohr_acaps0;
      tmp_oohr_acaps1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS31));
      tmp_oohr_acaps0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS30));
      rtn = (tmp_oohr_acaps1.wrd << 16) | tmp_oohr_acaps0.wrd;
      break;
    }
  
    case (4):
    {
      TEN_N40G_OOHR_ACAPS41_t tmp_oohr_acaps1;
      TEN_N40G_OOHR_ACAPS40_t tmp_oohr_acaps0;
      tmp_oohr_acaps1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS41));
      tmp_oohr_acaps0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS40));
      rtn = (tmp_oohr_acaps1.wrd << 16) | tmp_oohr_acaps0.wrd;
      break;
    }
  
    case (5):
      {
      TEN_N40G_OOHR_ACAPS51_t tmp_oohr_acaps1;
      TEN_N40G_OOHR_ACAPS50_t tmp_oohr_acaps0;
      tmp_oohr_acaps1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS51));
      tmp_oohr_acaps0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS50));
      rtn = (tmp_oohr_acaps1.wrd << 16) | tmp_oohr_acaps0.wrd;
      break;
    }
  
    case (6):
    {
      TEN_N40G_OOHR_ACAPS61_t tmp_oohr_acaps1;
      TEN_N40G_OOHR_ACAPS60_t tmp_oohr_acaps0;
      tmp_oohr_acaps1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS61));
      tmp_oohr_acaps0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS60));
      rtn = (tmp_oohr_acaps1.wrd << 16) | tmp_oohr_acaps0.wrd;
      break;
    }
  
    case (7):
    {
      TEN_N40G_OOHR_ACAPS71_t tmp_oohr_acaps1;
      TEN_N40G_OOHR_ACAPS70_t tmp_oohr_acaps0;
      tmp_oohr_acaps1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS71));
      tmp_oohr_acaps0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, ACAPS70));
      rtn = (tmp_oohr_acaps1.wrd << 16) | tmp_oohr_acaps0.wrd;
      break;
    }
 
    default:
    {
      CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..7.");
      rtn = CS_ERROR;
      break;
    }
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET BIP SIG DEGRADE 1ST VALUE THRESHOLD */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_bipvala(cs_uint16 module_id, 
                                    cs_uint16 bipvala01,
                                    cs_uint16 bipvala00)
/* INPUTS     : o Module Id                                     */
/*              o BIPVALa01                                     */
/*              o BIPVALa00                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the first threshold value for detecting Signal Degrade   */
/* condition.                                                   */
/*                                                              */
/* The [bipvala01] parameter is specified as:                   */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* The [bipvala00] parameter is specified as:                   */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_BIPVALa1_t tmp_oohr_bipvala1;
  TEN_N40G_OOHR_BIPVALa0_t tmp_oohr_bipvala0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_bipvala1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVALa1));
  tmp_oohr_bipvala1.bf.BIPVALa01 = bipvala01;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVALa1), tmp_oohr_bipvala1.wrd);
 
 tmp_oohr_bipvala0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVALa0));
  tmp_oohr_bipvala0.bf.BIPVALa00 = bipvala00;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVALa0), tmp_oohr_bipvala0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET BIP SIG DEGRADE 2ND VALUE THRESHOLD */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_bipvalb(cs_uint16 module_id, 
                                    cs_uint16 bipvalb01,
                                    cs_uint16 bipvalb00)
/* INPUTS     : o Module Id                                     */
/*              o BIPVALb01                                     */
/*              o BIPVALb00                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the second threshold value for detecting Signal Degrade  */
/* condition.                                                   */
/*                                                              */
/* The [bipvalb01] parameter is specified as:                   */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* The [bipvalb00] parameter is specified as:                   */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_BIPVALb1_t tmp_oohr_bipvalb1;
  TEN_N40G_OOHR_BIPVALb0_t tmp_oohr_bipvalb0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_bipvalb1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVALb1));
  tmp_oohr_bipvalb1.bf.BIPVALb01 = bipvalb01;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVALb1), tmp_oohr_bipvalb1.wrd);

  tmp_oohr_bipvalb0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVALb0));
  tmp_oohr_bipvalb0.bf.BIPVALb00 = bipvalb00;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVALb0), tmp_oohr_bipvalb0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR BIPCFG                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_bipcfg(cs_uint16 module_id, 
                           cs_uint16 bip7exs, 
                           cs_uint16 bip7blk, 
                           cs_uint16 bip6exs, 
                           cs_uint16 bip6blk, 
                           cs_uint16 bip5exs, 
                           cs_uint16 bip5blk, 
                           cs_uint16 bip4exs, 
                           cs_uint16 bip4blk, 
                           cs_uint16 bip3exs, 
                           cs_uint16 bip3blk, 
                           cs_uint16 bip2exs, 
                           cs_uint16 bip2blk, 
                           cs_uint16 bip1exs, 
                           cs_uint16 bip1blk, 
                           cs_uint16 bip0exs, 
                           cs_uint16 bip0blk)
/* INPUTS     : o Module Id                                         */
/*              o BIP7EXS                                           */
/*              o BIP7BLK                                           */
/*              o BIP6EXS                                           */
/*              o BIP6BLK                                           */
/*              o BIP5EXS                                           */
/*              o BIP5BLK                                           */
/*              o BIP4EXS                                           */
/*              o BIP4BLK                                           */
/*              o BIP3EXS                                           */
/*              o BIP3BLK                                           */
/*              o BIP2EXS                                           */
/*              o BIP2BLK                                           */
/*              o BIP1EXS                                           */
/*              o BIP1BLK                                           */
/*              o BIP0EXS                                           */
/*              o BIP0BLK                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets up BIP Extraction Unit.                                     */
/*                                                                  */
/*   [bip7exs]  Same as BIP0EXS, but for Section Monitoring.        */
/*                                                                  */
/*   [bip7blk]  Same as BIP0BLK, but for Section Monitoring.        */
/*                                                                  */
/*   [bip6exs]  Same as BIP0EXS, but for TCM 6.                     */
/*                                                                  */
/*   [bip6blk]  Same as BIP0BLK, but for TCM 6.                     */
/*                                                                  */
/*   [bip5exs]  Same as BIP0EXS, but for TCM 5.                     */
/*                                                                  */
/*   [bip5blk]  Same as BIP0BLK, but for TCM 5.                     */
/*                                                                  */
/*   [bip4exs]  Same as BIP0EXS, but for TCM 4.                     */
/*                                                                  */
/*   [bip4blk]  Same as BIP0BLK, but for TCM 4.                     */
/*                                                                  */
/*   [bip3exs]  Same as BIP0EXS, but for TCM 3.                     */
/*                                                                  */
/*   [bip3blk]  Same as BIP0BLK, but for TCM 3.                     */
/*                                                                  */
/*   [bip2exs]  Same as BIP0EXS, but for TCM 2.                     */
/*                                                                  */
/*   [bip2blk]  Same as BIP0BLK, but for TCM 2.                     */
/*                                                                  */
/*   [bip1exs]  Same as BIP0EXS, but for TCM 1.                     */
/*                                                                  */
/*   [bip1blk]  Same as BIP0BLK, but for TCM 1.                     */
/*                                                                  */
/*   [bip0exs]  When set, BIPVALb is used as the threshold for      */
/*     detecting Signal Degrade condition in Path Monitoring BIP-8. */
/*     If not set, BIPVALa is used.                                 */
/*                                                                  */
/*   [bip0blk]  When set, PM BIP-8 statistics data is computed      */
/*     byte-wise that is, one or more erroneous bits result in a    */
/*     maximum of one error per frame.  If not set, statistics      */
/*     processing is done bit-wise, allowing up to eight errors     */
/*     per frame to occur.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_BIPCFG_t tmp_oohr_bipcfg;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_bipcfg.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPCFG));
  tmp_oohr_bipcfg.bf.BIP7EXS = bip7exs;
  tmp_oohr_bipcfg.bf.BIP7BLK = bip7blk;
  tmp_oohr_bipcfg.bf.BIP6EXS = bip6exs;
  tmp_oohr_bipcfg.bf.BIP6BLK = bip6blk;
  tmp_oohr_bipcfg.bf.BIP5EXS = bip5exs;
  tmp_oohr_bipcfg.bf.BIP5BLK = bip5blk;
  tmp_oohr_bipcfg.bf.BIP4EXS = bip4exs;
  tmp_oohr_bipcfg.bf.BIP4BLK = bip4blk;
  tmp_oohr_bipcfg.bf.BIP3EXS = bip3exs;
  tmp_oohr_bipcfg.bf.BIP3BLK = bip3blk;
  tmp_oohr_bipcfg.bf.BIP2EXS = bip2exs;
  tmp_oohr_bipcfg.bf.BIP2BLK = bip2blk;
  tmp_oohr_bipcfg.bf.BIP1EXS = bip1exs;
  tmp_oohr_bipcfg.bf.BIP1BLK = bip1blk;
  tmp_oohr_bipcfg.bf.BIP0EXS = bip0exs;
  tmp_oohr_bipcfg.bf.BIP0BLK = bip0blk;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPCFG), tmp_oohr_bipcfg.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET BEI SIG DEGRADE 1ST VALUE THRESHOLD */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_beivala(cs_uint16 module_id, 
                                    cs_uint16 beivala1,
                                    cs_uint16 beivala0)
/* INPUTS     : o Module Id                                     */
/*              o BEIVALa1                                      */
/*              o BEIVALa0                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the first threshold value for detecting Signal Degrade   */
/* condition.                                                   */
/*                                                              */
/* The [beivala1] parameter is specified as:                    */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* The [beivala0] parameter is specified as:                    */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_BEIVALa1_t tmp_oohr_beivala1;
  TEN_N40G_OOHR_BEIVALa0_t tmp_oohr_beivala0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_beivala1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEIVALa1));
  tmp_oohr_beivala1.bf.BEIVALa1 = beivala1;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEIVALa1), tmp_oohr_beivala1.wrd);
  tmp_oohr_beivala0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEIVALa0));
  tmp_oohr_beivala0.bf.BEIVALa0 = beivala0;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEIVALa0), tmp_oohr_beivala0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET BEI SIG DEGRADE 2ND VALUE THRESHOLD */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_beivalb(cs_uint16 module_id, 
                                    cs_uint16 beivalb1,
                                    cs_uint16 beivalb0)
/* INPUTS     : o Module Id                                     */
/*              o BEIVALb1                                      */
/*              o BEIVALb0                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the second threshold value for detecting Signal Degrade  */
/* condition.                                                   */
/*                                                              */
/* The [beivalb1] parameter is specified as:                    */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* The [beivalb0] parameter is specified as:                    */
/*   0x0000-0xFFFF                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_BEIVALb1_t tmp_oohr_beivalb1;
  TEN_N40G_OOHR_BEIVALb0_t tmp_oohr_beivalb0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_beivalb1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEIVALb1));
  tmp_oohr_beivalb1.bf.BEIVALb1 = beivalb1;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEIVALb1), tmp_oohr_beivalb1.wrd);
  tmp_oohr_beivalb0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEIVALb0));
  tmp_oohr_beivalb0.bf.BEIVALb0 = beivalb0;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEIVALb0), tmp_oohr_beivalb0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR BEICFG                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_beicfg(cs_uint16 module_id, 
                           cs_uint16 layer,  
                           cs_uint16 bei_blk)
/* INPUTS     : o Module Id                                         */
/*              o Layer                                             */
/*              o BEI BLK                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the BEI Extraction Unit BEI/BLK.                             */
/*                                                                  */
/*   [layer]  Layer Selection                                       */
/*      TEN_OOHR_SECTION_LAYER = 1                                  */
/*      TEN_OOHR_PATH_LAYER = 2                                     */
/*      TEN_OOHR_TCM1_LAYER = 3                                     */
/*      TEN_OOHR_TCM2_LAYER = 4                                     */
/*      TEN_OOHR_TCM3_LAYER = 5                                     */
/*      TEN_OOHR_TCM4_LAYER = 6                                     */
/*      TEN_OOHR_TCM5_LAYER = 7                                     */
/*      TEN_OOHR_TCM6_LAYER = 8                                     */
/*      TEN_OOHR_ALL_LAYERS = 0xFF                                  */
/*                                                                  */
/* The [beiblk] parameter is specified as:                          */
/*   When set (= 1), PM-BEI statistics is computed block-wise       */
/*   across the four BEI bits, causing a BEI value between 1 and 8  */
/*   to increment an internal counter by 1 (equivalent to an        */
/*   errored frame).                                                */
/*   If bei_blk is not set (= 0), statistics                        */
/*   processing is done bit-wise, that is, the internal             */
/*   counter is incremented by the current numeric BEI value        */
/*   of up to eight errors per frame.                               */
/*   NOTE: For ITU-T G.709 compliance, BEI values of zero and       */
/*         greater than eight do not increment the counter in       */
/*         either mode.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_BEICFG_t tmp_oohr_beicfg;
  T41_t *pDev = NULL;

  if (((layer > TEN_OOHR_TCM6_LAYER) && (layer != TEN_OOHR_ALL_LAYERS)) || (layer == 0)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": layer out of range.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_beicfg.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEICFG));
  
  if ((layer == TEN_OOHR_SECTION_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI7BLK = bei_blk;
  }  
  if ((layer == TEN_OOHR_TCM6_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI6BLK = bei_blk;
  }  
  if ((layer == TEN_OOHR_TCM5_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI5BLK = bei_blk;
  }  
  if ((layer == TEN_OOHR_TCM4_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI4BLK = bei_blk;
  }  
  if ((layer == TEN_OOHR_TCM3_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI3BLK = bei_blk;
  }  
  if ((layer == TEN_OOHR_TCM2_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI2BLK = bei_blk;
  }  
  if ((layer == TEN_OOHR_TCM1_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI1BLK = bei_blk;
  }  
  if ((layer == TEN_OOHR_PATH_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI0BLK = bei_blk;
  }
  
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEICFG), tmp_oohr_beicfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR BEIEXS                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_beiexs(cs_uint16 module_id, 
                               cs_uint16 layer,  
                               cs_uint16 bei_exs)
/* INPUTS     : o Module Id                                         */
/*              o Layer                                             */
/*              o BEI EXS                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the BEI Extraction Unit BEI/EXS.                             */
/*                                                                  */
/*   [layer]  Layer Selection                                       */
/*      TEN_OOHR_SECTION_LAYER = 1                                  */
/*      TEN_OOHR_PATH_LAYER = 2                                     */
/*      TEN_OOHR_TCM1_LAYER = 3                                     */
/*      TEN_OOHR_TCM2_LAYER = 4                                     */
/*      TEN_OOHR_TCM3_LAYER = 5                                     */
/*      TEN_OOHR_TCM4_LAYER = 6                                     */
/*      TEN_OOHR_TCM5_LAYER = 7                                     */
/*      TEN_OOHR_TCM6_LAYER = 8                                     */
/*      TEN_OOHR_ALL_LAYERS = 0xFF                                  */
/*                                                                  */
/*   [bei_exs] parameter is specified as:                           */
/*     When set, BEIVALb is used as the threshold for detecting     */
/*     Signal Degrade condition in the Path Monitoring BEI field.   */
/*     If not set, BEIVALa is used.                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_BEICFG_t tmp_oohr_beicfg;
  T41_t *pDev = NULL;

  if (((layer > TEN_OOHR_TCM6_LAYER) && (layer != TEN_OOHR_ALL_LAYERS)) || (layer == 0)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": layer out of range.");
    return(CS_ERROR);
  }
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_beicfg.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEICFG));
  
  if ((layer == TEN_OOHR_SECTION_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI7EXS = bei_exs;
  }  
  if ((layer == TEN_OOHR_TCM6_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI6EXS = bei_exs;
  }  
  if ((layer == TEN_OOHR_TCM5_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI5EXS = bei_exs;
  }  
  if ((layer == TEN_OOHR_TCM4_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI4EXS = bei_exs;
  }  
  if ((layer == TEN_OOHR_TCM3_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI3EXS = bei_exs;
  }  
  if ((layer == TEN_OOHR_TCM2_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI2EXS = bei_exs;
  }  
  if ((layer == TEN_OOHR_TCM1_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI1EXS = bei_exs;
  }  
  if ((layer == TEN_OOHR_PATH_LAYER) || (layer == TEN_OOHR_ALL_LAYERS)) {
    tmp_oohr_beicfg.bf.BEI0EXS = bei_exs;
  }
  
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BEICFG), tmp_oohr_beicfg.wrd);

  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET SM STATUS                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_sm_status(cs_uint16 module_id, cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns OTUk Section Monitoring Status for the specified         */
/* bitfield, or the entire bitmapped register at once.              */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_SM_STATUS_APSUNST             0                */
/*     TEN_NX0G_OOHR_SM_STATUS_DIAE                1                */
/*     TEN_NX0G_OOHR_SM_STATUS_DBDI                2                */
/*     TEN_NX0G_OOHR_SM_STATUS_DBIAE               3                */
/*     TEN_NX0G_OOHR_SM_STATUS_BEISDS              4                */
/*     TEN_NX0G_OOHR_SM_STATUS_BIPSDS              5                */
/*     TEN_NX0G_OOHR_SM_STATUS_LOM                 6                */
/*     TEN_NX0G_OOHR_SM_STATUS_ALL (whole reg)   0xFF.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N40G_OOHR_SMSTAT_t tmp_oohr_smstat;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_smstat.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SMSTAT));
  
  switch (select) {
  case (TEN_NX0G_OOHR_SM_STATUS_APSUNST):
    rtn = tmp_oohr_smstat.bf.APSUNST;
    break;

  case (TEN_NX0G_OOHR_SM_STATUS_DIAE):
    rtn = tmp_oohr_smstat.bf.DIAE;
    break;

  case (TEN_NX0G_OOHR_SM_STATUS_DBDI):
    rtn = tmp_oohr_smstat.bf.DBDI;
    break;

  case (TEN_NX0G_OOHR_SM_STATUS_DBIAE):
    rtn = tmp_oohr_smstat.bf.DBIAE;
   break;

  case (TEN_NX0G_OOHR_SM_STATUS_BEISDS):
    rtn = tmp_oohr_smstat.bf.BEISDS;
    break;

  case (TEN_NX0G_OOHR_SM_STATUS_BIPSDS):
    rtn = tmp_oohr_smstat.bf.BIPSDS;
    break;

  case (TEN_NX0G_OOHR_SM_STATUS_LOM):
    rtn = tmp_oohr_smstat.bf.LOM;
    break;

  case (TEN_NX0G_OOHR_SM_STATUS_ALL):
    rtn = tmp_oohr_smstat.wrd;
    break;

  default:
    rtn = CS_ERROR;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    break;
  }
  return (rtn);
}
  
/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET TCM1 STATUS                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_tcm1_status(cs_uint16 module_id, cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns ODUk Tandem Connection Monitoring 1 Status for the       */
/* selected bitfield, or the entire bitmapped register all at once. */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT             0               */
/*     TEN_NX0G_OOHR_TCM_STATUS_STATUNST            1               */
/*     TEN_NX0G_OOHR_TCM_STATUS_APSUNST             2               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLTC                3               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DAIS                4               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DOCI                5               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLCK                6               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DIAE                7               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBDI                8               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBIAE               9               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BEISDS             10               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BIPSDS             11               */
/*     TEN_NX0G_OOHR_TCM_STATUS_ALL (whole reg)  0xFF.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N40G_OOHR_TCM1STAT_t tmp_oohr_tcm1stat;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_tcm1stat.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, TCM1STAT));
  
  switch (select) {
  case (TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT):
    rtn = tmp_oohr_tcm1stat.bf.ACCSTAT;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_STATUNST):
    rtn = tmp_oohr_tcm1stat.bf.STATUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_APSUNST):
    rtn = tmp_oohr_tcm1stat.bf.APSUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLTC):
    rtn = tmp_oohr_tcm1stat.bf.DLTC;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DAIS):
    rtn = tmp_oohr_tcm1stat.bf.DAIS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DOCI):
    rtn = tmp_oohr_tcm1stat.bf.DOCI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLCK):
    rtn = tmp_oohr_tcm1stat.bf.DLCK;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DIAE):
    rtn = tmp_oohr_tcm1stat.bf.DIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBDI):
    rtn = tmp_oohr_tcm1stat.bf.DBDI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBIAE):
    rtn = tmp_oohr_tcm1stat.bf.DBIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BEISDS):
    rtn = tmp_oohr_tcm1stat.bf.BEISDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BIPSDS):
    rtn = tmp_oohr_tcm1stat.bf.BIPSDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_ALL):
    rtn = tmp_oohr_tcm1stat.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET TCM2 STATUS                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_tcm2_status(cs_uint16 module_id, cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns ODUk Tandem Connection Monitoring 2 Status for the       */
/* selected bitfield, or the entire bitmapped register all at once. */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT             0               */
/*     TEN_NX0G_OOHR_TCM_STATUS_STATUNST            1               */
/*     TEN_NX0G_OOHR_TCM_STATUS_APSUNST             2               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLTC                3               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DAIS                4               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DOCI                5               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLCK                6               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DIAE                7               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBDI                8               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBIAE               9               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BEISDS             10               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BIPSDS             11               */
/*     TEN_NX0G_OOHR_TCM_STATUS_ALL (whole reg)  0xFF.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N40G_OOHR_TCM2STAT_t tmp_oohr_tcm2stat;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_tcm2stat.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, TCM2STAT));
  
  switch (select) {
  case (TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT):
    rtn = tmp_oohr_tcm2stat.bf.ACCSTAT;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_STATUNST):
    rtn = tmp_oohr_tcm2stat.bf.STATUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_APSUNST):
    rtn = tmp_oohr_tcm2stat.bf.APSUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLTC):
    rtn = tmp_oohr_tcm2stat.bf.DLTC;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DAIS):
    rtn = tmp_oohr_tcm2stat.bf.DAIS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DOCI):
    rtn = tmp_oohr_tcm2stat.bf.DOCI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLCK):
    rtn = tmp_oohr_tcm2stat.bf.DLCK;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DIAE):
    rtn = tmp_oohr_tcm2stat.bf.DIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBDI):
    rtn = tmp_oohr_tcm2stat.bf.DBDI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBIAE):
    rtn = tmp_oohr_tcm2stat.bf.DBIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BEISDS):
    rtn = tmp_oohr_tcm2stat.bf.BEISDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BIPSDS):
    rtn = tmp_oohr_tcm2stat.bf.BIPSDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_ALL):
    rtn = tmp_oohr_tcm2stat.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET TCM3 STATUS                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_tcm3_status(cs_uint16 module_id, cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns ODUk Tandem Connection Monitoring 3 Status for the       */
/* selected bitfield, or the entire bitmapped register all at once. */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT             0               */
/*     TEN_NX0G_OOHR_TCM_STATUS_STATUNST            1               */
/*     TEN_NX0G_OOHR_TCM_STATUS_APSUNST             2               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLTC                3               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DAIS                4               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DOCI                5               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLCK                6               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DIAE                7               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBDI                8               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBIAE               9               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BEISDS             10               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BIPSDS             11               */
/*     TEN_NX0G_OOHR_TCM_STATUS_ALL (whole reg)  0xFF.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N40G_OOHR_TCM3STAT_t tmp_oohr_tcm3stat;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_tcm3stat.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, TCM3STAT));
  
  switch (select) {
  case (TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT):
    rtn = tmp_oohr_tcm3stat.bf.ACCSTAT;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_STATUNST):
    rtn = tmp_oohr_tcm3stat.bf.STATUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_APSUNST):
    rtn = tmp_oohr_tcm3stat.bf.APSUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLTC):
    rtn = tmp_oohr_tcm3stat.bf.DLTC;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DAIS):
    rtn = tmp_oohr_tcm3stat.bf.DAIS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DOCI):
    rtn = tmp_oohr_tcm3stat.bf.DOCI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLCK):
    rtn = tmp_oohr_tcm3stat.bf.DLCK;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DIAE):
    rtn = tmp_oohr_tcm3stat.bf.DIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBDI):
    rtn = tmp_oohr_tcm3stat.bf.DBDI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBIAE):
    rtn = tmp_oohr_tcm3stat.bf.DBIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BEISDS):
    rtn = tmp_oohr_tcm3stat.bf.BEISDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BIPSDS):
    rtn = tmp_oohr_tcm3stat.bf.BIPSDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_ALL):
    rtn = tmp_oohr_tcm3stat.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET TCM4 STATUS                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_tcm4_status(cs_uint16 module_id, cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns ODUk Tandem Connection Monitoring 4 Status for the       */
/* selected bitfield, or the entire bitmapped register all at once. */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT             0               */
/*     TEN_NX0G_OOHR_TCM_STATUS_STATUNST            1               */
/*     TEN_NX0G_OOHR_TCM_STATUS_APSUNST             2               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLTC                3               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DAIS                4               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DOCI                5               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLCK                6               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DIAE                7               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBDI                8               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBIAE               9               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BEISDS             10               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BIPSDS             11               */
/*     TEN_NX0G_OOHR_TCM_STATUS_ALL (whole reg)  0xFF.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N40G_OOHR_TCM4STAT_t tmp_oohr_tcm4stat;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_tcm4stat.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, TCM4STAT));
  
  switch (select) {
  case (TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT):
    rtn = tmp_oohr_tcm4stat.bf.ACCSTAT;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_STATUNST):
    rtn = tmp_oohr_tcm4stat.bf.STATUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_APSUNST):
    rtn = tmp_oohr_tcm4stat.bf.APSUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLTC):
    rtn = tmp_oohr_tcm4stat.bf.DLTC;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DAIS):
    rtn = tmp_oohr_tcm4stat.bf.DAIS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DOCI):
    rtn = tmp_oohr_tcm4stat.bf.DOCI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLCK):
    rtn = tmp_oohr_tcm4stat.bf.DLCK;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DIAE):
    rtn = tmp_oohr_tcm4stat.bf.DIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBDI):
    rtn = tmp_oohr_tcm4stat.bf.DBDI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBIAE):
    rtn = tmp_oohr_tcm4stat.bf.DBIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BEISDS):
    rtn = tmp_oohr_tcm4stat.bf.BEISDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BIPSDS):
    rtn = tmp_oohr_tcm4stat.bf.BIPSDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_ALL):
    rtn = tmp_oohr_tcm4stat.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET TCM5 STATUS                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_tcm5_status(cs_uint16 module_id, cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns ODUk Tandem Connection Monitoring 5 Status for the       */
/* selected bitfield, or the entire bitmapped register all at once. */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT             0               */
/*     TEN_NX0G_OOHR_TCM_STATUS_STATUNST            1               */
/*     TEN_NX0G_OOHR_TCM_STATUS_APSUNST             2               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLTC                3               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DAIS                4               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DOCI                5               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLCK                6               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DIAE                7               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBDI                8               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBIAE               9               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BEISDS             10               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BIPSDS             11               */
/*     TEN_NX0G_OOHR_TCM_STATUS_ALL (whole reg)  0xFF.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N40G_OOHR_TCM5STAT_t tmp_oohr_tcm5stat;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_tcm5stat.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, TCM5STAT));
  
  switch (select) {
  case (TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT):
    rtn = tmp_oohr_tcm5stat.bf.ACCSTAT;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_STATUNST):
    rtn = tmp_oohr_tcm5stat.bf.STATUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_APSUNST):
    rtn = tmp_oohr_tcm5stat.bf.APSUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLTC):
    rtn = tmp_oohr_tcm5stat.bf.DLTC;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DAIS):
    rtn = tmp_oohr_tcm5stat.bf.DAIS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DOCI):
    rtn = tmp_oohr_tcm5stat.bf.DOCI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLCK):
    rtn = tmp_oohr_tcm5stat.bf.DLCK;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DIAE):
    rtn = tmp_oohr_tcm5stat.bf.DIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBDI):
    rtn = tmp_oohr_tcm5stat.bf.DBDI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBIAE):
    rtn = tmp_oohr_tcm5stat.bf.DBIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BEISDS):
    rtn = tmp_oohr_tcm5stat.bf.BEISDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BIPSDS):
    rtn = tmp_oohr_tcm5stat.bf.BIPSDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_ALL):
    rtn = tmp_oohr_tcm5stat.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET TCM6 STATUS                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_tcm6_status(cs_uint16 module_id, cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns ODUk Tandem Connection Monitoring 6 Status for the       */
/* selected bitfield, or the entire bitmapped register all at once. */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT             0               */
/*     TEN_NX0G_OOHR_TCM_STATUS_STATUNST            1               */
/*     TEN_NX0G_OOHR_TCM_STATUS_APSUNST             2               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLTC                3               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DAIS                4               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DOCI                5               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DLCK                6               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DIAE                7               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBDI                8               */
/*     TEN_NX0G_OOHR_TCM_STATUS_DBIAE               9               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BEISDS             10               */
/*     TEN_NX0G_OOHR_TCM_STATUS_BIPSDS             11               */
/*     TEN_NX0G_OOHR_TCM_STATUS_ALL              0xFF.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N40G_OOHR_TCM6STAT_t tmp_oohr_tcm6stat;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_tcm6stat.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, TCM6STAT));
  
  switch (select) {
  case (TEN_NX0G_OOHR_TCM_STATUS_ACCSTAT):
    rtn = tmp_oohr_tcm6stat.bf.ACCSTAT;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_STATUNST):
    rtn = tmp_oohr_tcm6stat.bf.STATUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_APSUNST):
    rtn = tmp_oohr_tcm6stat.bf.APSUNST;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLTC):
    rtn = tmp_oohr_tcm6stat.bf.DLTC;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DAIS):
    rtn = tmp_oohr_tcm6stat.bf.DAIS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DOCI):
    rtn = tmp_oohr_tcm6stat.bf.DOCI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DLCK):
    rtn = tmp_oohr_tcm6stat.bf.DLCK;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DIAE):
    rtn = tmp_oohr_tcm6stat.bf.DIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBDI):
    rtn = tmp_oohr_tcm6stat.bf.DBDI;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_DBIAE):
    rtn = tmp_oohr_tcm6stat.bf.DBIAE;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BEISDS):
    rtn = tmp_oohr_tcm6stat.bf.BEISDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_BIPSDS):
    rtn = tmp_oohr_tcm6stat.bf.BIPSDS;
    break;

  case (TEN_NX0G_OOHR_TCM_STATUS_ALL):
    rtn = tmp_oohr_tcm6stat.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET PM STATUS                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_pm_status(cs_uint16 module_id, cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns ODUk Path Monitoring Status for the selected bitfield,   */
/* the entire bitmapped register at once.                           */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_PM_STATUS_ACCSTAT             0                */
/*     TEN_NX0G_OOHR_PM_STATUS_MSIUNST             1                */
/*     TEN_NX0G_OOHR_PM_STATUS_PTIUNST             2                */
/*     TEN_NX0G_OOHR_PM_STATUS_STATUNST            3                */
/*     TEN_NX0G_OOHR_PM_STATUS_APSUNST             4                */
/*     TEN_NX0G_OOHR_PM_STATUS_DCBRAIS             5                */
/*     TEN_NX0G_OOHR_PM_STATUS_DMSIM               6                */
/*     TEN_NX0G_OOHR_PM_STATUS_DPLM                7                */
/*     TEN_NX0G_OOHR_PM_STATUS_DAIS                8                */
/*     TEN_NX0G_OOHR_PM_STATUS_DOCI                9                */
/*     TEN_NX0G_OOHR_PM_STATUS_DLCK               10                */
/*     TEN_NX0G_OOHR_PM_STATUS_DBDI               11                */
/*     TEN_NX0G_OOHR_PM_STATUS_BEISDS             12                */
/*     TEN_NX0G_OOHR_PM_STATUS_BIPSDS             13                */
/*     TEN_NX0G_OOHR_PM_STATUS_ALL (whole reg)  0xFF.               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;
  TEN_N40G_OOHR_PMSTAT_t tmp_oohr_pmstat;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_pmstat.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, PMSTAT));
  
  switch (select) {
  case (TEN_NX0G_OOHR_PM_STATUS_ACCSTAT):
    rtn = tmp_oohr_pmstat.bf.ACCSTAT;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_MSIUNST):
    rtn = tmp_oohr_pmstat.bf.MSIUNST;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_PTIUNST):
    rtn = tmp_oohr_pmstat.bf.PTIUNST;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_STATUNST):
    rtn = tmp_oohr_pmstat.bf.STATUNST;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_APSUNST):
    rtn = tmp_oohr_pmstat.bf.APSUNST;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_DCBRAIS):
    rtn = tmp_oohr_pmstat.bf.DCBRAIS;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_DMSIM):
    rtn = tmp_oohr_pmstat.bf.DMSIM;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_DPLM):
    rtn = tmp_oohr_pmstat.bf.DPLM;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_DAIS):
    rtn = tmp_oohr_pmstat.bf.DAIS;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_DOCI):
    rtn = tmp_oohr_pmstat.bf.DOCI;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_DLCK):
    rtn = tmp_oohr_pmstat.bf.DLCK;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_DBDI):
    rtn = tmp_oohr_pmstat.bf.DBDI;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_BEISDS):
    rtn = tmp_oohr_pmstat.bf.BEISDS;
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_BIPSDS):
    rtn = tmp_oohr_pmstat.bf.BIPSDS;    
    break;

  case (TEN_NX0G_OOHR_PM_STATUS_ALL):
    rtn = tmp_oohr_pmstat.wrd;    
    break;

    default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR MFMCFG                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_mfmcfg(cs_uint16 module_id, 
                               cs_uint8 match_unit, 
                               cs_uint8 mfmcmp, 
                               cs_uint8 mfmmsk)
/* INPUTS     : o Module Id                                         */
/*              o Match Unit                                        */
/*              o MFMCMP                                            */
/*              o MFMMSK                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure Comparison reference for specified MFAS Match unit.    */
/*                                                                  */
/*   [match_unit]  MFAS Match unit = 1-16                           */
/*                                                                  */
/*   [mfmcmp]  Comparison reference for MFAS Match unit             */
/*                                                                  */
/*   [mfmmsk]  Mask for MFAS Match unit.                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_MFMCFG1_t tmp_oohr_mfmcfg1;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((match_unit > 16) || (!match_unit)) { 
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": match unit out of range.  s/b 1..16.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  /* bugzilla #24439, klocwork */
  tmp_addr = TEN_N40G_OOHR_REG_ADDR(pDev, module_id, MFMCFG1);
  tmp_addr += match_unit - 1;
  tmp_oohr_mfmcfg1.wrd = TEN_REG_READ(tmp_addr);
  tmp_oohr_mfmcfg1.bf.MFM1CMP = mfmcmp;
  tmp_oohr_mfmcfg1.bf.MFM1MSK = mfmmsk;
  TEN_REG_WRITE(tmp_addr, tmp_oohr_mfmcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET ACCEPT FILTER STABLE THRESH VAL 1   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_afths1(cs_uint16 module_id, 
                                   cs_uint16 af1stv)
/* INPUTS     : o Module Id                                     */
/*              o AF1STV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Universal Stable Threshold Values for General Acceptance */
/* Filters 1.                                                   */
/*                                                              */
/* The [af1stv] parameter is specified as:                      */
/*   0x00 - 0x1F                                                */
/*   Acceptance Filter Stable Threshold Value for threshold     */
/*   value set 1. (The threshold value set is selected          */
/*   individually for each Acceptance Filter using AFnTS)       */
/*   When the portion of the byte selected for monitoring in    */
/*   AFnMSK remains unchanged for at least AF1STV consecutive   */
/*   samples (as triggered by the MFAS match event selected in  */
/*   AFnMF) the byte value is then accepted and made readable   */
/*   in AFnVAL.                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_AFTHS1_t tmp_oohr_afths1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_afths1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHS1));
  tmp_oohr_afths1.bf.AF1STV = af1stv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHS1), tmp_oohr_afths1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET ACCEPT FILTER UNSTABLE THRESH VAL 1 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_afthu1(cs_uint16 module_id, 
                                   cs_uint16 af1utv)
/* INPUTS     : o Module Id                                     */
/*              o AF1UTV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Universal Unstable Threshold Values for General          */
/* Acceptance Filters 1.                                        */
/*                                                              */
/* The [af1utv] parameter is specified as:                      */
/*   Acceptance Filter Unstable Threshold Value for threshold   */
/*   value set 1. When more than AF1UTV samples are received    */
/*   without at least AF1STV consecutive matching samples,      */
/*   unstable state is asserted and the unstable status bit     */
/*   AFnU is set. The unstable status will remain set until at  */
/*   least AF1STV consecutive matching samples are received.    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_AFTHU1_t tmp_oohr_afthu1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_afthu1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHU1));
  tmp_oohr_afthu1.bf.AF1UTV = af1utv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHU1), tmp_oohr_afthu1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET ACCEPT FILTER STABLE THRESH VAL 2   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_afths2(cs_uint16 module_id, 
                                   cs_uint16 af2stv)
/* INPUTS     : o Module Id                                     */
/*              o AF2STV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Universal Stable Threshold Values for General Acceptance */
/* Filters 2.                                                   */
/*                                                              */
/* The [af2stv] parameter is specified as:                      */
/*   0x00 - 0x1F                                                */
/*   Acceptance Filter Stable Threshold Value for threshold     */
/*   value set 2. (The threshold value set is selected          */
/*   individually for each Acceptance Filter using AFnTS)       */
/*   When the portion of the byte selected for monitoring in    */
/*   AFnMSK remains unchanged for at least AF2STV consecutive   */
/*   samples (as triggered by the MFAS match event selected in  */
/*   AFnMF) the byte value is then accepted and made readable   */
/*   in AFnVAL.                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_AFTHS2_t tmp_oohr_afths2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_afths2.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHS2));
  tmp_oohr_afths2.bf.AF2STV = af2stv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHS2), tmp_oohr_afths2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET ACCEPT FILTER UNSTABLE THRESH VAL 2 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_afthu2(cs_uint16 module_id, 
                                   cs_uint16 af2utv)
/* INPUTS     : o Module Id                                     */
/*              o AF2UTV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Universal Unstable Threshold Values for General          */
/* Acceptance Filters 2.                                        */
/*                                                              */
/* The [af2utv] parameter is specified as:                      */
/*   Acceptance Filter Unstable Threshold Value for threshold   */
/*   value set 2. When more than AF2UTV samples are received    */
/*   without at least AF2STV consecutive matching samples,      */
/*   unstable state is asserted and the unstable status bit     */
/*   AFnU is set. The unstable status will remain set until at  */
/*   least AF2STV consecutive matching samples are received.    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_AFTHU2_t tmp_oohr_afthu2;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_afthu2.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHU2));
  tmp_oohr_afthu2.bf.AF2UTV = af2utv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHU2), tmp_oohr_afthu2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET ACCEPT FILTER STABLE THRESH VAL 3   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_afths3(cs_uint16 module_id, 
                                   cs_uint16 af3stv)
/* INPUTS     : o Module Id                                     */
/*              o AF3STV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Universal Stable Threshold Values for General Acceptance */
/* Filters 3.                                                   */
/*                                                              */
/* The [af3stv] parameter is specified as:                      */
/*   0x00 - 0x1F                                                */
/*   Acceptance Filter Stable Threshold Value for threshold     */
/*   value set 3. (The threshold value set is selected          */
/*   individually for each Acceptance Filter using AFnTS)       */
/*   When the portion of the byte selected for monitoring in    */
/*   AFnMSK remains unchanged for at least AF3STV consecutive   */
/*   samples (as triggered by the MFAS match event selected in  */
/*   AFnMF) the byte value is then accepted and made readable   */
/*   in AFnVAL.                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_AFTHS3_t tmp_oohr_afths3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_afths3.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHS3));
  tmp_oohr_afths3.bf.AF3STV = af3stv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHS3), tmp_oohr_afths3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET ACCEPT FILTER UNSTABLE THRESH VAL 3 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_afthu3(cs_uint16 module_id, 
                                   cs_uint16 af3utv)
/* INPUTS     : o Module Id                                     */
/*              o AF3UTV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Universal Unstable Threshold Values for General          */
/* Acceptance Filters 3.                                        */
/*                                                              */
/* The [af3utv] parameter is specified as:                      */
/*   Acceptance Filter Unstable Threshold Value for threshold   */
/*   value set 3. When more than AF3UTV samples are received    */
/*   without at least AF3STV consecutive matching samples,      */
/*   unstable state is asserted and the unstable status bit     */
/*   AFnU is set. The unstable status will remain set until at  */
/*   least AF3STV consecutive matching samples are received.    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_AFTHU3_t tmp_oohr_afthu3;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_afthu3.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHU3));
  tmp_oohr_afthu3.bf.AF3UTV = af3utv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHU3), tmp_oohr_afthu3.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET ACCEPT FILTER STABLE THRESH VAL 4   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_afths4(cs_uint16 module_id, 
                                   cs_uint16 af4stv)
/* INPUTS     : o Module Id                                     */
/*              o AF4STV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Universal Stable Threshold Values for General Acceptance */
/* Filters 4.                                                   */
/*                                                              */
/* The [af4stv] parameter is specified as:                      */
/*   0x00 - 0x1F                                                */
/*   Acceptance Filter Stable Threshold Value for threshold     */
/*   value set 4. (The threshold value set is selected          */
/*   individually for each Acceptance Filter using AFnTS)       */
/*   When the portion of the byte selected for monitoring in    */
/*   AFnMSK remains unchanged for at least AF4STV consecutive   */
/*   samples (as triggered by the MFAS match event selected in  */
/*   AFnMF) the byte value is then accepted and made readable   */
/*   in AFnVAL.                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_AFTHS4_t tmp_oohr_afths4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_afths4.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHS4));
  tmp_oohr_afths4.bf.AF4STV = af4stv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHS4), tmp_oohr_afths4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G SET ACCEPT FILTER UNSTABLE THRESH VAL 4 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_oohr_afthu4(cs_uint16 module_id, 
                                   cs_uint16 af4utv)
/* INPUTS     : o Module Id                                     */
/*              o AF4UTV                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set Universal Unstable Threshold Values for General          */
/* Acceptance Filters 4.                                        */
/*                                                              */
/* The [af4utv] parameter is specified as:                      */
/*   Acceptance Filter Unstable Threshold Value for threshold   */
/*   value set 4. When more than AF4UTV samples are received    */
/*   without at least AF4STV consecutive matching samples,      */
/*   unstable state is asserted and the unstable status bit     */
/*   AFnU is set. The unstable status will remain set until at  */
/*   least AF4STV consecutive matching samples are received.    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OOHR_AFTHU4_t tmp_oohr_afthu4;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_afthu4.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHU4));
  tmp_oohr_afthu4.bf.AF4UTV = af4utv;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, AFTHU4), tmp_oohr_afthu4.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR COMPARISON UNIT                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cmp_unit(cs_uint16 module_id, 
                             cs_uint8 unit,
                             cs_uint16 cmp)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o CMP                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/* Set Comparison Reference Bytes for the General Acceptance        */
/* Filters for the specified unit.                                  */
/*                                                                  */
/*   [unit]  1..24                                                  */
/*                                                                  */
/*   [cmp]   Byte dedicated for comparison with extracted byte      */
/*           value from GAF.  If the extracted byte matches this    */
/*           value, the corresponding AFnEQL interrupt is set.      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CMPUNIT1_t tmp_oohr_cmpunit1;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
 
  if ((unit > TEN_NX0G_OTNSM_RAM_UNIT_NUM) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24.");
    return(CS_ERROR);
  }
 
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  /* bugzilla #24439, klocwork */
  tmp_addr = TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CMPUNIT1);
  tmp_addr += unit - 1;
  tmp_oohr_cmpunit1.wrd = TEN_REG_READ(tmp_addr);
  tmp_oohr_cmpunit1.bf.CMP1 = cmp;
  TEN_REG_WRITE(tmp_addr, tmp_oohr_cmpunit1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CONFIG GAF                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gaf_cfg(cs_uint16 module_id, 
                             cs_uint8 unit, 
                             cs_uint16 afmsk, 
                             cs_uint16 afts, 
                             cs_uint16 afcol, 
                             cs_uint16 afrow,
                             cs_uint16 afi, 
                             cs_uint16 afmf)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o AFMSK                                             */
/*              o AFTS                                              */
/*              o AFCOL                                             */
/*              o AFROW                                             */
/*              o AFI                                               */
/*              o AFMF                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configures various aspects of General Acceptance Filter Unit.    */
/*                                                                  */
/*   [unit]                                                         */
/*     Specified as 1..24                                           */
/*                                                                  */
/*   [afmsk]  Mask for General Acceptance Filter unit {instance);   */
/*     Only the bits set in this register are observed.             */
/*                                                                  */
/*   [afts]  Selects the set of threshold values for filtering the  */
/*     byte specified in AF23ROW, AF23COL, AF23MSK.                 */
/*                                                                  */
/*   [afcol]  Column Address of General Acceptance Filter           */
/*     Unit {instance}.                                             */
/*                                                                  */
/*   [afrow]  Row Address of General Acceptance Filter              */
/*     Unit {instance}.                                             */
/*                                                                  */
/*   [afi]  When set, the result of GAF (General Acceptance Filter) */
/*     unit {instance} is inverted prior to sending it to the       */
/*     Centralized Overhead Processing Unit.  Only applies to       */
/*     instance=1..8.                                               */
/*                                                                  */
/*   [afmf]  Determines the MFAS Event to be used as the time base  */
/*      for Acceptance Filter unit {instance}.                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GAF1CFG0_t tmp_oohr_gaf1cfg0;
  TEN_N40G_OOHR_GAF1CFG1_t tmp_oohr_gaf1cfg1;
  volatile cs_reg *tmp_addr0;
  volatile cs_reg *tmp_addr1;
  T41_t *pDev = NULL;

  if ((unit > TEN_NX0G_OTNSM_RAM_UNIT_NUM) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  /* bugzilla #24439, klocwork */
  tmp_addr0 = TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GAF1CFG0);
  tmp_addr0 += unit - 1;
  tmp_oohr_gaf1cfg0.wrd = TEN_REG_READ(tmp_addr0);
  tmp_addr1 = TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GAF1CFG1);
  tmp_addr1 += + unit - 1;
  tmp_oohr_gaf1cfg1.wrd = TEN_REG_READ(tmp_addr1);

  tmp_oohr_gaf1cfg0.bf.AF1MSK = afmsk;
  tmp_oohr_gaf1cfg0.bf.AF1TS = afts;
  tmp_oohr_gaf1cfg0.bf.AF1COL = afcol;
  tmp_oohr_gaf1cfg0.bf.AF1ROW = afrow;
  
  if (unit < 9) {  
    tmp_oohr_gaf1cfg1.bf.AF1I = afi;
  }
  tmp_oohr_gaf1cfg1.bf.AF1MF = afmf;

  TEN_REG_WRITE(tmp_addr0, tmp_oohr_gaf1cfg0.wrd);
  TEN_REG_WRITE(tmp_addr1, tmp_oohr_gaf1cfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GAF CMP                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_gaf_cmp(cs_uint16 module_id, 
                                cs_uint8 unit,
                                cs_uint16 gc_msk)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o GCMSK                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/*                                                                  */
/*                                                                  */
/*   [gcmsk]                                                        */
/*                                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_GAFCMP1_t tmp_oohr_gafcmp1;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  
  if ((unit > 8) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..8.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);

  /* bugzilla #24439, klocwork */
  tmp_addr = TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GAFCMP1);
  tmp_addr += + unit - 1;
  tmp_oohr_gafcmp1.wrd = TEN_REG_READ(tmp_addr);
  tmp_oohr_gafcmp1.bf.GC1MSK = gc_msk;
  TEN_REG_WRITE(tmp_addr, tmp_oohr_gafcmp1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET GAF STATUS                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_gaf_status(cs_uint16 module_id, cs_uint8 unit, 
                                      cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Get General Acceptance Filter Unit Status for the specified      */
/* unit and the specified bitfield.                                 */
/*                                                                  */
/*   [unit]  1..24                                                  */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_GAF_STATUS_AFE                 0               */
/*     TEN_NX0G_OOHR_GAF_STATUS_AFU                 1               */
/*     TEN_NX0G_OOHR_GAF_STATUS_AFVAL               2               */
/*     TEN_NX0G_OOHR_GAF_STATUS_ALL (whole reg)  0xFF.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;
  TEN_N40G_OOHR_GAF1STAT_t tmp_oohr_gaf1stat;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if ((unit > TEN_NX0G_OTNSM_RAM_UNIT_NUM) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  /* bugzilla #24439, klocwork */
  tmp_addr  = TEN_N40G_OOHR_REG_ADDR(pDev, module_id, GAF1STAT);
  tmp_addr += unit - 1;
  tmp_oohr_gaf1stat.wrd = TEN_REG_READ(tmp_addr);
  
  switch (select) {
  case (TEN_NX0G_OOHR_GAF_STATUS_AFE):
    rtn = tmp_oohr_gaf1stat.bf.AF1E;
    break;

  case (TEN_NX0G_OOHR_GAF_STATUS_AFU):
    rtn = tmp_oohr_gaf1stat.bf.AF1U;
    break;

  case (TEN_NX0G_OOHR_GAF_STATUS_AFVAL):
    rtn = tmp_oohr_gaf1stat.bf.AF1VAL;
    break;

  case (TEN_NX0G_OOHR_GAF_STATUS_ALL):
    rtn = tmp_oohr_gaf1stat.wrd;
    break;

  default:
    rtn = CS_ERROR;
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CONFIG STRING EXTRACTOR                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_config_string_extractor(cs_uint16 module_id, 
                             cs_uint8 unit, 
                             cs_uint16 se_mfe, 
                             cs_uint16 se_cnt, 
                             cs_uint16 se_col, 
                             cs_uint16 se_row, 
                             cs_uint16 se_cmp)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o SEMFE                                             */
/*              o SECNT                                             */
/*              o SECOL                                             */
/*              o SEROW                                             */
/*              o SECMP                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure the specified String Extractor Unit.                   */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 1-24.                                           */
/*                                                                  */
/*   [se_mfe]                                                       */
/*     Selects the triggering MFAS Event for String Extractor unit. */
/*                                                                  */
/*   [se_cnt]                                                       */
/*     Specifies the number of bytes from the string to be compared */
/*     by extractor unit.  A value of 0 compares one byte and a     */
/*     value of 3F hex compares 64 bytes.                           */
/*                                                                  */
/*   [se_col]                                                       */
/*     Selects the target column for String Extractor unit.         */
/*                                                                  */
/*   [se_row]                                                       */
/*     Selects the target row for String Extractor unit.            */
/*                                                                  */
/*   [se_cmp]                                                       */
/*    Compare selects for String Extractor Unit.  Selects which     */
/*    bytes of the accepted string are compared with the expected   */
/*    string for dTIM comparison.                                   */
/*    SECMP[0] = 1 : Bytes 1 16 used for comparison                 */
/*    SECMP[0] = 0 : Bytes 1 16 ignored for dTIM                    */
/*    SECMP[1] = 1 : Bytes 17 32 used for comparison                */
/*    SECMP[1] = 0 : Bytes 17 32 ignored for dTIM                   */
/*    SECMP[2] = 1 : Bytes 33 48 used for comparison                */
/*    SECMP[2] = 0 : Bytes 33 48 ignored for dTIM                   */
/*    SECMP[3] = 1 : Bytes 49 64 used for comparison                */
/*    SECMP[3] = 0 : Bytes 49 64 ignored for dTIM                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_SECFG1_0_t tmp_oohr_secfg1_0;
  TEN_N40G_OOHR_SECFG1_1_t tmp_oohr_secfg1_1;
  T41_t *pDev = NULL;

  if ((unit > TEN_NX0G_OTNSM_RAM_UNIT_NUM) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_secfg1_0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_0) + (unit-1)*2);
  tmp_oohr_secfg1_1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_1) + (unit-1)*2);
  tmp_oohr_secfg1_0.bf.SE1MFE = se_mfe;
  tmp_oohr_secfg1_0.bf.SE1CNT = se_cnt;
  tmp_oohr_secfg1_0.bf.SE1COL = se_col;
  tmp_oohr_secfg1_0.bf.SE1ROW = se_row;
  tmp_oohr_secfg1_1.bf.SE1CMP = se_cmp;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_0) + (unit-1)*2, tmp_oohr_secfg1_0.wrd);
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_1) + (unit-1)*2, tmp_oohr_secfg1_1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CONFIG STRING EXTRACTOR CMP            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_config_string_extractor_cmp(cs_uint16 module_id, 
                             cs_uint8 unit, 
                             cs_uint16 se_cmp)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o SECMP                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure the specified String Extractor Unit CMP.               */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 1-24.                                           */
/*                                                                  */
/*   [se_cmp]                                                       */
/*    Compare selects for String Extractor Unit.  Selects which     */
/*    bytes of the accepted string are compared with the expected   */
/*    string for dTIM comparison.                                   */
/*    SECMP[0] = 1 : Bytes 1 16 used for comparison                 */
/*    SECMP[0] = 0 : Bytes 1 16 ignored for dTIM                    */
/*    SECMP[1] = 1 : Bytes 17 32 used for comparison                */
/*    SECMP[1] = 0 : Bytes 17 32 ignored for dTIM                   */
/*    SECMP[2] = 1 : Bytes 33 48 used for comparison                */
/*    SECMP[2] = 0 : Bytes 33 48 ignored for dTIM                   */
/*    SECMP[3] = 1 : Bytes 49 64 used for comparison                */
/*    SECMP[3] = 0 : Bytes 49 64 ignored for dTIM                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_SECFG1_1_t tmp_oohr_secfg1_1;
  T41_t *pDev = NULL;

  if ((unit > TEN_NX0G_OTNSM_RAM_UNIT_NUM) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_secfg1_1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_1) + (unit-1)*2);
  tmp_oohr_secfg1_1.bf.SE1CMP = se_cmp;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_1) + (unit-1)*2, tmp_oohr_secfg1_1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR SET STRING EXTRACTOR DT DIS            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_set_string_extractor_dt_dis(cs_uint16 module_id, 
                                                    cs_uint8 unit,  
                                                    cs_uint16 se_dt_dis)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o SEDTDIS                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set String Extractor Unit DT DIS, specified by {instance}.       */
/*                                                                  */
/*   [unit]                                                         */
/*     Specified as 1-24.                                           */
/*                                                                  */
/*   [se_dt_dis]                                                    */
/*     When set, String Extractor unit will disable dTIM comparison */
/*     and set dTIM defect status to 0.                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_SECFG1_1_t tmp_oohr_secfg1_1;
  T41_t *pDev = NULL;

  if ((unit > 24) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24.");
    return(CS_ERROR);
  }

  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(module_id))) {
    CS_PRINT("T41 only feature, exit\n");
    return (CS_OK);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_secfg1_1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_1) + (unit-1)*2);
  tmp_oohr_secfg1_1.bf.SE1_DT_DIS = se_dt_dis;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_1) + (unit-1)*2, tmp_oohr_secfg1_1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR SET STRING EXTRACTOR DMM               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_set_string_extractor_dmm(cs_uint16 module_id, 
                             cs_uint8 unit, 
                             cs_uint16 se_dmm)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o SEDMM                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set String Extractor Unit DMM, specified by {instance}.          */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 1-24.                                           */
/*                                                                  */
/*   [se_dmm]                                                       */
/*    When set, String Extractor unit will work in dTIM Mode.       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_SECFG1_1_t tmp_oohr_secfg1_1;
  T41_t *pDev = NULL;

  if ((unit > TEN_NX0G_OTNSM_RAM_UNIT_NUM) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_secfg1_1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_1) + (unit-1)*2);
  tmp_oohr_secfg1_1.bf.SE1DMM = se_dmm;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_1) + (unit-1)*2, tmp_oohr_secfg1_1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR SET STRING EXTRACTOR OFF               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_set_string_extractor_off(cs_uint16 module_id, 
                             cs_uint8 unit, 
                             cs_uint16 se_off)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o SEOFF                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set String Extractor Unit Off, specified by {instance}.          */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 1-24.                                           */
/*                                                                  */
/*   [se_off]                                                       */
/*     When set, resets and disables String Extractor unit.         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_SECFG1_0_t tmp_oohr_secfg1_0;
  T41_t *pDev = NULL;

  if ((unit > TEN_NX0G_OTNSM_RAM_UNIT_NUM) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24.");
    return(CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_secfg1_0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_0) + (unit-1)*2);
  tmp_oohr_secfg1_0.bf.SE1OFF = se_off;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SECFG1_0) + (unit-1)*2, tmp_oohr_secfg1_0.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET STRING EXTRACTOR UNIT STATUS0      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_string_extractor_unit_status0(cs_uint16 module_id, 
                                                         cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Gets the String Extractor Unit Status for units 1-16.            */
/* When set, the string extracted by unit selection is regarded as  */
/* stable.                                                          */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_STATUS_SE16ST             16                   */
/*     TEN_NX0G_OOHR_STATUS_SE15ST             15                   */
/*     TEN_NX0G_OOHR_STATUS_SE14ST             14                   */
/*     TEN_NX0G_OOHR_STATUS_SE13ST             13                   */
/*     TEN_NX0G_OOHR_STATUS_SE12ST             12                   */
/*     TEN_NX0G_OOHR_STATUS_SE11ST             11                   */
/*     TEN_NX0G_OOHR_STATUS_SE10ST             10                   */
/*     TEN_NX0G_OOHR_STATUS_SE9ST               9                   */
/*     TEN_NX0G_OOHR_STATUS_SE8ST               8                   */
/*     TEN_NX0G_OOHR_STATUS_SE7ST               7                   */
/*     TEN_NX0G_OOHR_STATUS_SE6ST               6                   */
/*     TEN_NX0G_OOHR_STATUS_SE5ST               5                   */
/*     TEN_NX0G_OOHR_STATUS_SE4ST               4                   */
/*     TEN_NX0G_OOHR_STATUS_SE3ST               3                   */
/*     TEN_NX0G_OOHR_STATUS_SE2ST               2                   */
/*     TEN_NX0G_OOHR_STATUS_SE1ST               1                   */
/*     TEN_NX0G_OOHR_STATUS_ALL                0xFF                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 rtn = CS_ERROR;
  TEN_N40G_OOHR_SEST0_t tmp_oohr_sest0;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_sest0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SEST0));
  
  switch (select) {
  case (TEN_NX0G_OOHR_STATUS_SE16ST):
  rtn = tmp_oohr_sest0.bf.SE16ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE15ST):
  rtn = tmp_oohr_sest0.bf.SE15ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE14ST):
  rtn = tmp_oohr_sest0.bf.SE14ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE13ST):
  rtn = tmp_oohr_sest0.bf.SE13ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE12ST):
  rtn = tmp_oohr_sest0.bf.SE12ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE11ST):
  rtn = tmp_oohr_sest0.bf.SE11ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE10ST):
  rtn = tmp_oohr_sest0.bf.SE10ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE9ST):
  rtn = tmp_oohr_sest0.bf.SE9ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE8ST):
  rtn = tmp_oohr_sest0.bf.SE8ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE7ST):
  rtn = tmp_oohr_sest0.bf.SE7ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE6ST):
  rtn = tmp_oohr_sest0.bf.SE6ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE5ST):
  rtn = tmp_oohr_sest0.bf.SE5ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE4ST):
  rtn = tmp_oohr_sest0.bf.SE4ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE3ST):
  rtn = tmp_oohr_sest0.bf.SE3ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE2ST):
  rtn = tmp_oohr_sest0.bf.SE2ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE1ST):
  rtn = tmp_oohr_sest0.bf.SE1ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_ALL):
  rtn = tmp_oohr_sest0.wrd;
  break;

  default:
  CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
  rtn = CS_ERROR;
  break;
  }
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET STRING EXTRACTOR UINT STATUS1      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_string_extractor_unit_status1(cs_uint16 module_id, 
                                                         cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Gets the String Extractor Unit Status for units 17-24.           */
/* When set, the string extracted by unit selection is regarded as  */
/* stable.                                                          */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_STATUS_SE24ST              24                  */
/*     TEN_NX0G_OOHR_STATUS_SE23ST              23                  */
/*     TEN_NX0G_OOHR_STATUS_SE22ST              22                  */
/*     TEN_NX0G_OOHR_STATUS_SE21ST              21                  */
/*     TEN_NX0G_OOHR_STATUS_SE20ST              20                  */
/*     TEN_NX0G_OOHR_STATUS_SE19ST              19                  */
/*     TEN_NX0G_OOHR_STATUS_SE18ST              18                  */
/*     TEN_NX0G_OOHR_STATUS_SE17ST              17                  */
/*     TEN_NX0G_OOHR_STATUS_ALL                0xFF                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;
  TEN_N40G_OOHR_SEST1_t tmp_oohr_sest1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_sest1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SEST1));
  
  switch (select) {
  case (TEN_NX0G_OOHR_STATUS_SE24ST):
  rtn = tmp_oohr_sest1.bf.SE24ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE23ST):
  rtn = tmp_oohr_sest1.bf.SE23ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE22ST):
  rtn = tmp_oohr_sest1.bf.SE22ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE21ST):
  rtn = tmp_oohr_sest1.bf.SE21ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE20ST):
  rtn = tmp_oohr_sest1.bf.SE20ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE19ST):
  rtn = tmp_oohr_sest1.bf.SE19ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE18ST):
  rtn = tmp_oohr_sest1.bf.SE18ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_SE17ST):
  rtn = tmp_oohr_sest1.bf.SE17ST;
  break;

  case (TEN_NX0G_OOHR_STATUS_ALL):
  rtn = tmp_oohr_sest1.wrd;
  break;

  default:
  CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
  rtn = CS_ERROR;
  break;
  }
  
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET DEFECT TRACE IDENTIFIER STATUS0    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_defect_trace_identifier_status0(cs_uint16 module_id, 
                                                           cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Get the Defect Trace Identifier Mismatch Status.                 */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_STATUS_SE16DTM            16                   */
/*     TEN_NX0G_OOHR_STATUS_SE15DTM            15                   */
/*     TEN_NX0G_OOHR_STATUS_SE14DTM            14                   */
/*     TEN_NX0G_OOHR_STATUS_SE13DTM            13                   */
/*     TEN_NX0G_OOHR_STATUS_SE12DTM            12                   */
/*     TEN_NX0G_OOHR_STATUS_SE11DTM            11                   */
/*     TEN_NX0G_OOHR_STATUS_SE10DTM            10                   */
/*     TEN_NX0G_OOHR_STATUS_SE9DTM              9                   */
/*     TEN_NX0G_OOHR_STATUS_SE8DTM              8                   */
/*     TEN_NX0G_OOHR_STATUS_SE7DTM              7                   */
/*     TEN_NX0G_OOHR_STATUS_SE6DTM              6                   */
/*     TEN_NX0G_OOHR_STATUS_SE5DTM              5                   */
/*     TEN_NX0G_OOHR_STATUS_SE4DTM              4                   */
/*     TEN_NX0G_OOHR_STATUS_SE3DTM              3                   */
/*     TEN_NX0G_OOHR_STATUS_SE2DTM              2                   */
/*     TEN_NX0G_OOHR_STATUS_SE1DTM              1                   */
/*     TEN_NX0G_OOHR_STATUS_ALL              0xFF                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;
  TEN_N40G_OOHR_DTIM0_t tmp_oohr_dtim0;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_dtim0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, DTIM0));

  switch (select) {
  case (TEN_NX0G_OOHR_STATUS_SE16DTM):
    rtn = tmp_oohr_dtim0.bf.SE16DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE15DTM):
    rtn = tmp_oohr_dtim0.bf.SE15DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE14DTM):
    rtn = tmp_oohr_dtim0.bf.SE14DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE13DTM):
    rtn = tmp_oohr_dtim0.bf.SE13DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE12DTM):
    rtn = tmp_oohr_dtim0.bf.SE12DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE11DTM):
    rtn = tmp_oohr_dtim0.bf.SE11DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE10DTM):
    rtn = tmp_oohr_dtim0.bf.SE10DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE9DTM):
    rtn = tmp_oohr_dtim0.bf.SE9DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE8DTM):
    rtn = tmp_oohr_dtim0.bf.SE8DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE7DTM):
    rtn = tmp_oohr_dtim0.bf.SE7DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE6DTM):
    rtn = tmp_oohr_dtim0.bf.SE6DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE5DTM):
    rtn = tmp_oohr_dtim0.bf.SE5DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE4DTM):
    rtn = tmp_oohr_dtim0.bf.SE4DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE3DTM):
    rtn = tmp_oohr_dtim0.bf.SE3DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE2DTM):
    rtn = tmp_oohr_dtim0.bf.SE2DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE1DTM):
    rtn = tmp_oohr_dtim0.bf.SE1DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SEDTM_ALL):
    rtn = tmp_oohr_dtim0.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR GET DEFECT TRACE IDENTIFIER STATUS1    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_n40g_oohr_get_defect_trace_identifier_status1(cs_uint16 module_id, 
                                                           cs_uint8 select)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Get the Defect Trace Identifier Mismatch Status.                 */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_NX0G_OOHR_STATUS_SE24DTM            24                   */
/*     TEN_NX0G_OOHR_STATUS_SE23DTM            23                   */
/*     TEN_NX0G_OOHR_STATUS_SE22DTM            22                   */
/*     TEN_NX0G_OOHR_STATUS_SE21DTM            21                   */
/*     TEN_NX0G_OOHR_STATUS_SE20DTM            20                   */
/*     TEN_NX0G_OOHR_STATUS_SE19DTM            19                   */
/*     TEN_NX0G_OOHR_STATUS_SE18DTM            18                   */
/*     TEN_NX0G_OOHR_STATUS_SE17DTM            17                   */
/*     TEN_NX0G_OOHR_STATUS_ALL              0xFF                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_int16 rtn;
  TEN_N40G_OOHR_DTIM1_t tmp_oohr_dtim1;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  tmp_oohr_dtim1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, DTIM1));

  switch (select) {
  case (TEN_NX0G_OOHR_STATUS_SE24DTM):
    rtn = tmp_oohr_dtim1.bf.SE24DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE23DTM):
    rtn = tmp_oohr_dtim1.bf.SE23DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE22DTM):
    rtn = tmp_oohr_dtim1.bf.SE22DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE21DTM):
    rtn = tmp_oohr_dtim1.bf.SE21DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE20DTM):
    rtn = tmp_oohr_dtim1.bf.SE20DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE19DTM):
    rtn = tmp_oohr_dtim1.bf.SE19DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE18DTM):
    rtn = tmp_oohr_dtim1.bf.SE18DTM;
    break;

  case (TEN_NX0G_OOHR_STATUS_SE17DTM):
    rtn = tmp_oohr_dtim1.bf.SE17DTM;
    break;
  
  case (TEN_NX0G_OOHR_STATUS_SEDTM_ALL):
    rtn = tmp_oohr_dtim1.wrd;
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
    rtn = CS_ERROR;
    break;
  }
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CONFIG STRING INSERTER                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_config_string_inserter(cs_uint16 module_id, 
                           cs_uint8 unit, 
                           cs_uint16 sicnt, 
                           cs_uint16 simfe, 
                           cs_uint16 sicol, 
                           cs_uint16 sirow)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o SICNT                                             */
/*              o SIMFE                                             */
/*              o SICOL                                             */
/*              o SIROW                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Configure String Inserter Unit.                                  */
/*                                                                  */
/*   [unit]  Specified as 1..24                                     */
/*                                                                  */
/*   [sicnt]  Specifies the number of bytes for the string to be    */
/*     inserted by unit {instance}.                                 */
/*                                                                  */
/*   [simfe]  Specifies the MFAS Event upon which String Inserter   */
/*     unit {instance} will start string insertion.                 */
/*                                                                  */
/*   [sicol]  Specifies the target column for String Inserter       */
/*     unit {instance}.                                             */
/*                                                                  */
/*   [sirow]  Specifies the target row for String Inserter          */
/*     unit {instance}.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_SICFG1_t tmp_oohr_sicfg1;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  
  if ((unit > TEN_NX0G_OTNSM_RAM_UNIT_NUM) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  /* bugzilla #24439, klocwork */
  tmp_addr = TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SICFG1);
  tmp_addr += unit - 1;
  tmp_oohr_sicfg1.wrd = TEN_REG_READ(tmp_addr);
  tmp_oohr_sicfg1.bf.SI1CNT = sicnt;
  tmp_oohr_sicfg1.bf.SI1MFE = simfe;
  tmp_oohr_sicfg1.bf.SI1COL = sicol;
  tmp_oohr_sicfg1.bf.SI1ROW = sirow;
  TEN_REG_WRITE(tmp_addr, tmp_oohr_sicfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR SET STRING INSERTER IE                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_set_string_inserter_ie(cs_uint16 module_id, 
                           cs_uint8 unit, 
                           cs_uint16 siie)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/*              o SIIE                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set String Inserter IE.                                          */
/*                                                                  */
/*   [unit]  Specified as 1..24                                     */
/*                                                                  */
/*   [siie]  When set to zero, String Inserter unit {instance} is   */
/*     disabled.                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_SICFG1_t tmp_oohr_sicfg1;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  
  if ((unit > TEN_NX0G_OTNSM_RAM_UNIT_NUM) || (!unit)) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24.");
    return(CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  /* bugzilla #24439, klocwork */
  tmp_addr = TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SICFG1);
  tmp_addr += + unit - 1;
  tmp_oohr_sicfg1.wrd = TEN_REG_READ(tmp_addr);
  tmp_oohr_sicfg1.bf.SI1IE = siie;
  TEN_REG_WRITE(tmp_addr, tmp_oohr_sicfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR STRING INSERTION UPDATE                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_string_insertion_update(cs_uint16 module_id, 
                              cs_uint8 unit)
/* INPUTS     : o Module Id                                         */
/*              o Unit                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Toggles the internal double string buffer upon reception of the  */
/* selected MFAS event, making string data previously delivered via */
/* the processor interface available for insertion through String   */
/* Inserter Unit selected.                                          */
/*                                                                  */
/*   [unit]  Unit 1..24, 0xFF = ALL                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_N40G_OOHR_SIUPDATE0_t tmp_oohr_siupdate0;
  TEN_N40G_OOHR_SIUPDATE1_t tmp_oohr_siupdate1;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  
  tmp_oohr_siupdate0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0));
  tmp_oohr_siupdate1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1));

  /* This is an edge-triggered function, so once it is set once it must be   */
  /* written to 0 before triggering it again.                                */
  switch (unit) {
  case (1):
    tmp_oohr_siupdate0.bf.SI1UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI1UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (2):
    tmp_oohr_siupdate0.bf.SI2UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI2UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (3):
    tmp_oohr_siupdate0.bf.SI3UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI3UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;
  
  case (4):
    tmp_oohr_siupdate0.bf.SI4UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI4UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;
  
  case (5):
    tmp_oohr_siupdate0.bf.SI5UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI5UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (6):
    tmp_oohr_siupdate0.bf.SI6UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI6UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (7):
    tmp_oohr_siupdate0.bf.SI7UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI7UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (8):
    tmp_oohr_siupdate0.bf.SI8UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI8UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (9):
    tmp_oohr_siupdate0.bf.SI9UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI9UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (10):
    tmp_oohr_siupdate0.bf.SI10UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI10UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (11):
    tmp_oohr_siupdate0.bf.SI11UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI11UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (12):
    tmp_oohr_siupdate0.bf.SI12UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI12UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (13):
    tmp_oohr_siupdate0.bf.SI13UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI13UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (14):
    tmp_oohr_siupdate0.bf.SI14UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI14UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (15):
    tmp_oohr_siupdate0.bf.SI15UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI15UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (16):
    tmp_oohr_siupdate0.bf.SI16UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.bf.SI16UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    break;

  case (17):
    tmp_oohr_siupdate1.bf.SI17UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate1.bf.SI17UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    break;

  case (18):
    tmp_oohr_siupdate1.bf.SI18UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate1.bf.SI18UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    break;

  case (19):
    tmp_oohr_siupdate1.bf.SI19UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate1.bf.SI19UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    break;

  case (20):
    tmp_oohr_siupdate1.bf.SI20UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate1.bf.SI20UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    break;

  case (21):
    tmp_oohr_siupdate1.bf.SI21UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate1.bf.SI21UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    break;

  case (22):
    tmp_oohr_siupdate1.bf.SI22UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate1.bf.SI22UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    break;

  case (23):
    tmp_oohr_siupdate1.bf.SI23UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate1.bf.SI23UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    break;

  case (24):
    tmp_oohr_siupdate1.bf.SI24UP = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate1.bf.SI24UP = 1;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    break;

  case (TEN_INSTANCE_ALL):
    tmp_oohr_siupdate0.wrd = 0;
    tmp_oohr_siupdate1.wrd = 0;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    tmp_oohr_siupdate0.wrd = 0xFFFF;
    tmp_oohr_siupdate1.wrd = 0x00FF;
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE0), tmp_oohr_siupdate0.wrd);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, SIUPDATE1), tmp_oohr_siupdate1.wrd);
    /* Bugzilla #25991, break was missing here */ 
    break;

  default:
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": unit out of range.  s/b 1..24 or 0xFF.");
    rtn = CS_ERROR;
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG11 SPS MFDSCR                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg11_sps_mfdscr(cs_uint16 module_id, 
                                         cs_uint16 sps_mfdscr)
/* INPUTS     : o Module Id                                         */
/*              o SPS MFDSCR                                        */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets miscellaneous configuration item sps_mfdscr.                */
/*                                                                  */
/*   [sps_mfdscr]                                                   */
/*     ODU2SPS MFAS Descramble Enable: This bit should be set when  */
/*     ODU2SPS=1 and the incoming stream was scrambled as a single  */
/*     40G signal before splitting into 4x10G. In this case, the    */
/*     data cannot be descrambled, but the MFAS needs to be         */
/*     descrambled when it is interpreted to aid in alignment of    */
/*     the lanes. This bit applies to N10G only.                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG11_t tmp_oohr_cfg11;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg11.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11));
  tmp_oohr_cfg11.bf.SPS_MFDSCR = sps_mfdscr;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11), tmp_oohr_cfg11.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG11 OH63SEL                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg11_oh63sel(cs_uint16 module_id, 
                                      cs_uint16 oh63sel)
/* INPUTS     : o Module Id                                         */
/*              o OH63SEL                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets miscellaneous configuration item oh63sel.                   */
/*                                                                  */
/*   [oh63sel]                                                      */
/*     When set to 0, byte 63 of the overhead stream to the OHPP    */
/*     will be the status of GAF #17-24.                            */
/*     When set to 1, byte 63 of the overhead stream to the OHPP    */
/*     will be dLOF[3:0] and dLOR[3:0], the Loss-of-Frame and       */
/*     Loss-of-Recovery defect status from the four MLD lanes.      */
/*     Note: For N10G, this bit should always be set to 0.          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG11_t tmp_oohr_cfg11;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg11.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11));
  tmp_oohr_cfg11.bf.OH63SEL = oh63sel;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11), tmp_oohr_cfg11.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG11 OH62SEL                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg11_oh62sel(cs_uint16 module_id, 
                                      cs_uint16 oh62sel)
/* INPUTS     : o Module Id                                         */
/*              o OH62SEL                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets miscellaneous configuration item oh62sel.                   */
/*                                                                  */
/*   [oh62sel]                                                      */
/*     When set to 0, byte 62 of the overhead stream to the OHPP    */
/*     will be the status of GAF #9-16. When set to 1, byte 62 of   */
/*     the overhead stream to the OHPP will be AcLM[3:0][1:0],      */
/*     the 2-bit accepted lane markers from each of the four MLD    */
/*     lanes. Note: For N10G, this bit should always be set to 0.   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG11_t tmp_oohr_cfg11;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg11.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11));
  tmp_oohr_cfg11.bf.OH62SEL = oh62sel;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11), tmp_oohr_cfg11.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG11 OHPP BIPSEL                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg11_ohpp_bipsel(cs_uint16 module_id, 
                                          cs_uint16 ohpp_bipsel)
/* INPUTS     : o Module Id                                         */
/*              o OHPP BIPSEL                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets miscellaneous configuration item ohpp_bipsel.               */
/*                                                                  */
/*   [ohpp_bipsel]                                                  */
/*    0 = received BIP is inserted in overhead byte slots and       */
/*        calculated BIP is inserted in OHPP byte 3.                */
/*    1 = BIP error mask is inserted in overhead byte slots and     */
/*        DEG or EED is inserted in OHPP byte 3 selectable          */
/*        via OHPP_EEDSEL.                                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG11_t tmp_oohr_cfg11;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg11.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11));
  tmp_oohr_cfg11.bf.OHPP_BIPSEL = ohpp_bipsel;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11), tmp_oohr_cfg11.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG11 OHPP EEDSEL                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg11_ohpp_eedsel(cs_uint16 module_id, 
                                          cs_uint16 ohpp_eedsel)
/* INPUTS     : o Module Id                                         */
/*              o OHPP EEDSEL                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets miscellaneous configuration item ohpp_eedsel.               */
/*                                                                  */
/*   [ohpp_eedsel]                                                  */
/*     OHPP EED versus DEG alarm select.                            */
/*     0 = DEG is inserted in OHHP byte 1 and EED is inserted in    */
/*         byte 3 if enabled via OHPP_BIPSEL.                       */
/*     1 = EED is inserted in OHHP byte 1 and DEG is inserted in    */
/*         byte 3 if enabled via OHPP_BIPSEL.                       */
/*     The upper bit is dedicated to SM, OHPP_EEDSEL[6:1] are for   */
/*     TCM6-TCM1 and the least significant bit is dedicated to PM.  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG11_t tmp_oohr_cfg11;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg11.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11));
  tmp_oohr_cfg11.bf.OHPP_EEDSEL = ohpp_eedsel;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11), tmp_oohr_cfg11.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG11 OHPP MSI TRBSEL                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg11_ohpp_msi_trbsel(cs_uint16 module_id, 
                                              cs_uint16 ohpp_msi_trbsel)
/* INPUTS     : o Module Id                                         */
/*              o OHPP MSI TRBSEL                                   */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets miscellaneous configuration item ohpp_msi_trbsel.           */
/*                                                                  */
/*   [ohpp_msi_trbsel]                                              */
/*     When set to 1, the per-tributary dMSIM for tributary 0 will  */
/*     be sent to OHPP in place of the dMSIM over the entire MSI.   */
/*     This is used for N10G for HO mapping when not all trib slots */
/*     are allocated.                                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG11_t tmp_oohr_cfg11;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg11.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11));
  tmp_oohr_cfg11.bf.OHPP_MSI_TRBSEL = ohpp_msi_trbsel;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11), tmp_oohr_cfg11.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG11 ACC MSI TRBSEL                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg11_acc_msi_trbsel(cs_uint16 module_id, 
                                             cs_uint16 acc_msi_trbsel)
/* INPUTS     : o Module Id                                         */
/*              o ACC MSI TRBSEL                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets miscellaneous configuration item acc_msi_trbsel.            */
/*                                                                  */
/*   [acc_msi_trbsel]                                               */
/*     When set to 1, the accepted MSI registers (ACMSI, ACMSI_EXT) */
/*     hold the per-tributary accepted MSI. The accepted MSI for    */
/*     tributary 0 is located in ACMSI[63:0], tributary 1 is        */
/*     located in ACMSI[127:64], tributary 2 is located in          */
/*     ACMSI_EXT[63:0], and tributary 3 is located in               */
/*     ACMSI_EXT[127:64].  When set = 0, the accepted MSI registers */
/*     hold the accepted value filtered over the entire string.     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG11_t tmp_oohr_cfg11;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg11.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11));
  tmp_oohr_cfg11.bf.ACC_MSI_TRBSEL = acc_msi_trbsel;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11), tmp_oohr_cfg11.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG11 FLOMEN                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg11_flomen(cs_uint16 module_id, 
                                     cs_uint16 flomen)
/* INPUTS     : o Module Id                                         */
/*              o FLOMEN                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets miscellaneous configuration item flomen                     */
/*                                                                  */
/*   [flomen]                                                       */
/*     1 = FLOM is forwarded to OHPP.                               */
/*     0 = LOM is forwarded to OHPP.                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG11_t tmp_oohr_cfg11;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg11.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11));
  tmp_oohr_cfg11.bf.FLOMEN = flomen;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11), tmp_oohr_cfg11.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR CFG11 MSI EXT                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_cfg11_msi_ext(cs_uint16 module_id, 
                                      cs_uint16 msi_ext)
/* INPUTS     : o Module Id                                         */
/*              o MSI EXT                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets miscellaneous configuration item msi_ext.                   */
/*                                                                  */
/*   [msi_ext]                                                      */
/*     Enable processing of extended MSI. Along with CFG8.MSICNT,   */
/*     determines the number of bytes in the MSI string.            */
/*     00 = 16-byte MSI (frames 2-17 of 256-frame PSI multi-frame)  */
/*     01 = 4-byte MSI (frames 2-5 of 256-frame PSI multi-frame)    */
/*     10 = 32-byte MSI (frames 2-33 of 256-frame PSI multi-frame)  */
/*     11 = 8-byte MSI (frames 2-9 of 256-frame PSI multi-frame).   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_CFG11_t tmp_oohr_cfg11;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_cfg11.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11));
  tmp_oohr_cfg11.bf.MSI_EXT = msi_ext;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, CFG11), tmp_oohr_cfg11.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/* Bugzilla 31127 Start */
/********************************************************************/
/* $rtn_hdr_start  N40G OOHR LOMCFG TDELON TDELOFF                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_lomcfg_tdelon_tdeloff(cs_uint16 module_id,
                              cs_uint16 tdelon, cs_uint16 tdeloff)
/* INPUTS     : o Module Id                                         */
/*              o TDELON                                            */
/*              o TDELOFF                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets value for LOM Acceptance Filter Configuration #1 and #2.    */
/*                                                                  */
/*   [tdelon]  TDELON Value                                         */
/*                                                                  */
/*   [tdelon]  TDELOFF Value.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_OOHR_LOMCFG0_t tmp_oohr_lomcfg0;
  TEN_N40G_OOHR_LOMCFG1_t tmp_oohr_lomcfg1;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_oohr_lomcfg_tdelon_tdeloff";  

  CS_PRINT("%s() %s, tdelon=%d, tdeloff=%d\n",
           func,
           ten_module_strings[module_id & 1],
           tdelon,
           tdeloff);

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_lomcfg0.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, LOMCFG0));
  tmp_oohr_lomcfg0.bf.TDELON = tdelon;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, LOMCFG0), tmp_oohr_lomcfg0.wrd);

  tmp_oohr_lomcfg1.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, LOMCFG1));
  tmp_oohr_lomcfg1.bf.TDELOFF = tdeloff;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, LOMCFG1), tmp_oohr_lomcfg1.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}
/* Bugzilla 31127 End */

/********************************************************************/
/* $rtn_hdr_start  N40G_OOHR DMCSF CFGDM                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_dmcsf_cfgdm(cs_uint16 module_id, 
                                    cs_uint16 cfgdm)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/*              o CFGDM                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Select a single filtered DM and send to Delay Counter.           */
/*                                                                  */
/*   [cfgdm]                                                        */
/*     TEN_DM_NONE = 0, (Clear All)                                 */
/*     TEN_DM_PM   = 1, (DMp)                                       */
/*     TEN_DM_TCM6 = 2, (DMt6)                                      */
/*     TEN_DM_TCM5 = 3, (DMt5)                                      */
/*     TEN_DM_TCM4 = 4, (DMt4)                                      */
/*     TEN_DM_TCM3 = 5, (DMt3)                                      */
/*     TEN_DM_TCM2 = 6, (DMt2)                                      */
/*     TEN_DM_TCM1 = 7, (DMt1)                                      */
/*     TEN_DM_RES  = 8, (Res, Unused PM&TCM LSB, Not Applicable here*/
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_N40G_OOHR_DMCSF_t tmp_oohr_dmcsf;

  if (cfgdm > TEN_DM_TCM1) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": cfgdm out of range.  s/b 0..7.");
    return (CS_ERROR);
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_dmcsf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, DMCSF));
  tmp_oohr_dmcsf.bf.CFGDM = cfgdm;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, DMCSF), tmp_oohr_dmcsf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G_OOHR DMCSF DM FILT                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_dmcsf_dm_filt(cs_uint16 module_id, 
                                      cs_uint16 dm_filt)
/* INPUTS     : o Module Id                                         */
/*              o DM FILT                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets DM filter window (number of frames).                        */
/*                                                                  */
/*   [dm_filt]                                                      */
/*     TEN_DM_FILT_0_FRMS = 0,  (Accept received)                   */
/*     TEN_DM_FILT_2_FRMS = 1,  (Accept 2 matches)                  */
/*     TEN_DM_FILT_3_FRMS = 2,  (Accept 3 matches)                  */
/*     TEN_DM_FILT_5_FRMS = 3   (Accept 5 matches)                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_N40G_OOHR_DMCSF_t tmp_oohr_dmcsf;

  if (dm_filt > TEN_DM_FILT_5_FRMS) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_filt out of range.  s/b 0..3.");
    return (CS_ERROR);
  }
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_dmcsf.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, DMCSF));
  tmp_oohr_dmcsf.bf.DM_FILT = dm_filt;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, DMCSF), tmp_oohr_dmcsf.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G_OOHR DMCSF STAT DMACPT                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_n40g_oohr_get_dmcsf_stat_dmacpt(cs_uint16 module_id, cs_uint16 tcmpm)
/* INPUTS     : o Module Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : DMACPT                                              */
/* DESCRIPTION:                                                     */
/* Returns '1' if selected tcmpm if active, or '0' otherwise.       */
/*                                                                  */
/*   [tcmpm]                                                        */
/*     TEN_DM_NONE = 0, (None)                                      */
/*     TEN_DM_PM   = 1, (DMp)                                       */
/*     TEN_DM_TCM6 = 2, (DMt6)                                      */
/*     TEN_DM_TCM5 = 3, (DMt5)                                      */
/*     TEN_DM_TCM4 = 4, (DMt4)                                      */
/*     TEN_DM_TCM3 = 5, (DMt3)                                      */
/*     TEN_DM_TCM2 = 6, (DMt2)                                      */
/*     TEN_DM_TCM1 = 7, (DMt1)                                      */
/*     TEN_DM_RES  = 8, (Reserved, Unused PM&TCM LSB)               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_N40G_OOHR_DMCSF_STAT_t tmp_oohr_dmcsf_stat;
  cs_uint16 dmacpt = TEN_DM_NONE;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, TEN_DM_NONE);
  tmp_oohr_dmcsf_stat.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, DMCSF_STAT));
  
  switch (tcmpm) {
  case (TEN_DM_PM):
    dmacpt = !((tmp_oohr_dmcsf_stat.bf.DMACPT & 0x0001) == 0);
    break;
    
  case (TEN_DM_TCM1):
    dmacpt = !((tmp_oohr_dmcsf_stat.bf.DMACPT & 0x0040)== 0);
    break;
    
  case (TEN_DM_TCM2):
    dmacpt = !((tmp_oohr_dmcsf_stat.bf.DMACPT & 0x0020) == 0);
    break;
    
  case (TEN_DM_TCM3):
    dmacpt = !((tmp_oohr_dmcsf_stat.bf.DMACPT & 0x0010) == 0);
    break;
    
  case (TEN_DM_TCM4):
    dmacpt = !((tmp_oohr_dmcsf_stat.bf.DMACPT & 0x0008) == 0);
    break;
    
  case (TEN_DM_TCM5):
    dmacpt = !((tmp_oohr_dmcsf_stat.bf.DMACPT & 0x0004) == 0);
    break;
    
  case (TEN_DM_TCM6):
    dmacpt = !((tmp_oohr_dmcsf_stat.bf.DMACPT & 0x0002) == 0);
    break;
    
  case (TEN_DM_NONE):
  case (TEN_DM_RES):
    dmacpt = 0;
    break;
  
  default:  
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": dm_select out of range.  s/b 0..8.");
    dmacpt = 0;
    break;
  }
               
  return (dmacpt);
}


/********************************************************************/
/* $rtn_hdr_start  N40G OOHR BIPCFG2 SFBLK                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_bipcfg2_sfblk(cs_uint16 module_id, 
                                      cs_uint16 sfblk)
/* INPUTS     : o Module Id                                         */
/*              o SFBLK                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls BIP Extraction Unit Threshold Select SFBLK.             */
/*                                                                  */
/*   [sfblk]                                                        */
/*     1 = SF processing is based on block error per OTN frame      */
/*     0 = SF processing is based on acuumulated BIP-8 per OTN      */
/*         frame (maximum is 8-bit error).                          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_N40G_OOHR_BIPCFG2_t tmp_oohr_bipcfg2;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_bipcfg2.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPCFG2));
  tmp_oohr_bipcfg2.bf.SFBLK = sfblk;
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPCFG2), tmp_oohr_bipcfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR BIPCFG2 BIP THSEL                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_bipcfg2_bip_thsel(cs_uint16 module_id, 
                                cs_uint16 bip, 
                                cs_uint16 bip_thsel)
/* INPUTS     : o Module Id                                         */
/*              o BIP                                               */
/*              o BIP_THSEL                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Controls BIP Threshold Select.                                   */
/*                                                                  */
/*   [bip]                                                          */
/*    7 = bip7thsel SM BIP-8                                        */
/*    6 = bip6thsel TCM-6 BIP-8                                     */
/*    5 = bip5thsel TCM-5 BIP-8                                     */
/*    4 = bip4thsel TCM-4 BIP-8                                     */
/*    3 = bip3thsel TCM-3 BIP-8                                     */
/*    2 = bip2hsel  TCM-2 BIP-8                                     */
/*    1 = bip1thsel TCM-1 BIP-8                                     */
/*    0 = bip0thsel PM BIP-8                                        */
/*    0xFF = set all at once (0-7).                                 */
/*                                                                  */
/*   [bip_thsel]                                                    */
/*    0 = use threshold selected by corresponding BIPCFG.BIPEXS     */
/*    1 = use threshold in corresponding BIPVAL registers.          */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_N40G_OOHR_BIPCFG2_t tmp_oohr_bipcfg2;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_oohr_bipcfg2.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPCFG2));
  
  if ((bip == 7) || (bip == 0xFF)) {
    tmp_oohr_bipcfg2.bf.BIP7THSEL = bip_thsel;
  }
  if ((bip == 6) || (bip == 0xFF)) {
    tmp_oohr_bipcfg2.bf.BIP6THSEL = bip_thsel;
  }
  if ((bip == 5) || (bip == 0xFF)) {
    tmp_oohr_bipcfg2.bf.BIP5THSEL = bip_thsel;
  }
  if ((bip == 4) || (bip == 0xFF)) {
    tmp_oohr_bipcfg2.bf.BIP4THSEL = bip_thsel;
  }
  if ((bip == 3) || (bip == 0xFF)) {
    tmp_oohr_bipcfg2.bf.BIP3THSEL = bip_thsel;
  }
  if ((bip == 2) || (bip == 0xFF)) {
    tmp_oohr_bipcfg2.bf.BIP2THSEL = bip_thsel;
  }
  if ((bip == 1) || (bip == 0xFF)) {
    tmp_oohr_bipcfg2.bf.BIP1THSEL = bip_thsel;
  }
  if ((bip == 0) || (bip == 0xFF)) {
    tmp_oohr_bipcfg2.bf.BIP0THSEL = bip_thsel;
  }
  TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPCFG2), tmp_oohr_bipcfg2.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  N40G OOHR BIPVAL                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N10G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_oohr_bipval(cs_uint16 module_id, cs_uint8 slice, 
                               cs_uint16 bip,
                               cs_uint32 bipval)
/* INPUTS     : o Module Id                                         */
/*              o BIP                                               */
/*              o BIPVAL                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets BIP Threshold value.                                        */
/*                                                                  */
/*   [bip]                                                          */
/*    7 = SM BIP-8                                                  */
/*    6 = TCM-6 BIP-8                                               */
/*    5 = TCM-5 BIP-8                                               */
/*    4 = TCM-4 BIP-8                                               */
/*    3 = TCM-3 BIP-8                                               */
/*    2 = TCM-2 BIP-8                                               */
/*    1 = TCM-1 BIP-8                                               */
/*    0 = PM BIP-8                                                  */
/*    0xFF = set all at once (0-7).                                 */
/*                                                                  */
/*   [bipval]                                                       */
/*    Threshold value for detecting Signal Degrade condition for    */
/*    selected BIP unit when corresponding BIPTHSEL=1.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_status rtn;
  TEN_N40G_OOHR_BIPVAL71_t tmp_oohr_bipval71;
  TEN_N40G_OOHR_BIPVAL70_t tmp_oohr_bipval70;
  TEN_N40G_OOHR_BIPVAL61_t tmp_oohr_bipval61;
  TEN_N40G_OOHR_BIPVAL60_t tmp_oohr_bipval60;
  TEN_N40G_OOHR_BIPVAL51_t tmp_oohr_bipval51;
  TEN_N40G_OOHR_BIPVAL50_t tmp_oohr_bipval50;
  TEN_N40G_OOHR_BIPVAL41_t tmp_oohr_bipval41;
  TEN_N40G_OOHR_BIPVAL40_t tmp_oohr_bipval40;
  TEN_N40G_OOHR_BIPVAL31_t tmp_oohr_bipval31;
  TEN_N40G_OOHR_BIPVAL30_t tmp_oohr_bipval30;
  TEN_N40G_OOHR_BIPVAL21_t tmp_oohr_bipval21;
  TEN_N40G_OOHR_BIPVAL20_t tmp_oohr_bipval20;
 
  rtn = CS_OK;
  
  if ((bip == 1) || (bip == 0xFF)) {
    rtn |= ten_n40g_set_oohr_bipvalb(module_id,
                                     (cs_uint16)((bipval & 0xFFFF0000) >> 16),
                                     (cs_uint16)(bipval & 0x0000FFFF));
  }
  if ((bip == 0) || (bip == 0xFF)) {
     rtn |= ten_n40g_set_oohr_bipvala(module_id, 
                                      (cs_uint16)((bipval & 0xFFFF0000) >> 16),
                                      (cs_uint16)(bipval & 0x0000FFFF));
  }

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  if ((bip == 7) || (bip == 0xFF)) {
    tmp_oohr_bipval70.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL70));
    tmp_oohr_bipval70.bf.BIPVAL70 = (cs_uint16)(bipval & 0x0000FFFF);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL70), tmp_oohr_bipval70.wrd);
  
    tmp_oohr_bipval71.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL71));
    tmp_oohr_bipval71.bf.BIPVAL71 = (cs_uint16)((bipval & 0xFFFF0000) >> 16);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL71), tmp_oohr_bipval71.wrd);
  }
  if ((bip == 6) || (bip == 0xFF)) {
    tmp_oohr_bipval60.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL60));
    tmp_oohr_bipval60.bf.BIPVAL60 = (cs_uint16)(bipval & 0x0000FFFF);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL60), tmp_oohr_bipval60.wrd);
    
    /* Bug #38685 - fix compiler warnings. */
    tmp_oohr_bipval61.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL61));
    tmp_oohr_bipval61.bf.BIPVAL61 = (cs_uint16)((bipval & 0xFFFF0000) >> 16);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL61), tmp_oohr_bipval61.wrd);
  }
  if ((bip == 5) || (bip == 0xFF)) {
    tmp_oohr_bipval50.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL50));
    tmp_oohr_bipval50.bf.BIPVAL50 = (cs_uint16)(bipval & 0x0000FFFF);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL50), tmp_oohr_bipval50.wrd);
  
    tmp_oohr_bipval51.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL51));
    tmp_oohr_bipval51.bf.BIPVAL51 = (cs_uint16)((bipval & 0xFFFF0000) >> 16);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL51), tmp_oohr_bipval51.wrd);
  }
  if ((bip == 4) || (bip == 0xFF)) {
    tmp_oohr_bipval40.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL40));
    tmp_oohr_bipval40.bf.BIPVAL40 = (cs_uint16)(bipval & 0x0000FFFF);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL40), tmp_oohr_bipval40.wrd);
  
    tmp_oohr_bipval41.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL41));
    tmp_oohr_bipval41.bf.BIPVAL41 = (cs_uint16)((bipval & 0xFFFF0000) >> 16);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL41), tmp_oohr_bipval41.wrd);
  }
  if ((bip == 3) || (bip == 0xFF)) {
    tmp_oohr_bipval30.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL30));
    tmp_oohr_bipval30.bf.BIPVAL30 = (cs_uint16)(bipval & 0x0000FFFF);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL30), tmp_oohr_bipval30.wrd);
  
    tmp_oohr_bipval31.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL31));
    tmp_oohr_bipval31.bf.BIPVAL31 = (cs_uint16)((bipval & 0xFFFF0000) >> 16);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL31), tmp_oohr_bipval31.wrd);
  }
  if ((bip == 2) || (bip == 0xFF)) {
    tmp_oohr_bipval20.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL20));
    tmp_oohr_bipval20.bf.BIPVAL20 = (cs_uint16)(bipval & 0x0000FFFF);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL20), tmp_oohr_bipval20.wrd);
  
    tmp_oohr_bipval21.wrd = TEN_REG_READ(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL21));
    tmp_oohr_bipval21.bf.BIPVAL21 = (cs_uint16)((bipval & 0xFFFF0000) >> 16);
    TEN_REG_WRITE(TEN_N40G_OOHR_REG_ADDR(pDev, module_id, BIPVAL21), tmp_oohr_bipval21.wrd);
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);
  return (CS_OK);
}




