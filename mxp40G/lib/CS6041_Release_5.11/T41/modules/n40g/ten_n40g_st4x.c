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
 * ten_n40g_st4x.c
 *
 * N40G related code is implemented here.
 *
 * $Id: ten_n40g_st4x.c,v 1.6 2013/02/22 20:44:38 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* $rtn_hdr_start  N40G SET THE POH BYTE                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_set_poh_byte(cs_uint16 module_id,
                                cs_uint16 ovrhd,
                                cs_uint8 val)
/* INPUTS     : o Module Id                                     */
/*              o Overhead Byte Type                            */
/*              o Overhead Byte Value                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the SONET Overhead byte to be inserted in the transmit   */
/* stream.                                                      */
/*                                                              */
/* The [ovrhd] parameter is specified as following:             */
/*   TEN_POH_J1        = 0                                      */
/*   TEN_POH_SSBITS    = 1                                      */
/*   TEN_POH_G1        = 2                                      */
/*   TEN_POH_C2        = 3                                      */
/*   TEN_POH_H4        = 4                                      */
/*   TEN_POH_F2        = 5                                      */
/*   TEN_POH_K3        = 6                                      */
/*   TEN_POH_F3        = 7                                      */
/*   TEN_POH_PFIXSTF   = 8                                      */
/*   TEN_POH_N1        = 9                                      */
/*                                                              */
/* The [val] parameter is specified as following:               */
/*   Overhead Byte Value                                        */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;
  
  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  switch (ovrhd) {
    case TEN_POH_J1 :
      {
        TEN_N40G_ST4X_POHBTS0_t tmp_n40g_st4x_pohbts0;
        tmp_n40g_st4x_pohbts0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS0));
        tmp_n40g_st4x_pohbts0.bf.J1BYTE = val;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS0), tmp_n40g_st4x_pohbts0.wrd);
        ret_val = CS_OK;
        break;
      }
    case TEN_POH_SSBITS :
      {
        TEN_N40G_ST4X_POHBTS0_t tmp_n40g_st4x_pohbts0;
        tmp_n40g_st4x_pohbts0.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS0));
        tmp_n40g_st4x_pohbts0.bf.SSBITS = val;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS0), tmp_n40g_st4x_pohbts0.wrd);
        ret_val = CS_OK;
        break;
      }
    case TEN_POH_G1 :
      {
        TEN_N40G_ST4X_POHBTS1_t tmp_n40g_st4x_pohbts1;
        tmp_n40g_st4x_pohbts1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS1));
        tmp_n40g_st4x_pohbts1.bf.G1BYTE = val;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS1), tmp_n40g_st4x_pohbts1.wrd);
        ret_val = CS_OK;
        break;
      }
    case TEN_POH_C2 :
      {
        TEN_N40G_ST4X_POHBTS1_t tmp_n40g_st4x_pohbts1;
        tmp_n40g_st4x_pohbts1.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS1));
        tmp_n40g_st4x_pohbts1.bf.C2BYTE = val;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS1), tmp_n40g_st4x_pohbts1.wrd);
        ret_val = CS_OK;
        break;
      }
    case TEN_POH_H4 :
      {
        TEN_N40G_ST4X_POHBTS2_t tmp_n40g_st4x_pohbts2;
        tmp_n40g_st4x_pohbts2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS2));
        tmp_n40g_st4x_pohbts2.bf.H4BYTE = val;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS2), tmp_n40g_st4x_pohbts2.wrd);
        ret_val = CS_OK;
        break;
      }
    case TEN_POH_F2 :
      {
        TEN_N40G_ST4X_POHBTS2_t tmp_n40g_st4x_pohbts2;
        tmp_n40g_st4x_pohbts2.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS2));
        tmp_n40g_st4x_pohbts2.bf.F2BYTE = val;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS2), tmp_n40g_st4x_pohbts2.wrd);
        ret_val = CS_OK;
        break;
      }
    case TEN_POH_K3 :
      {
        TEN_N40G_ST4X_POHBTS3_t tmp_n40g_st4x_pohbts3;
        tmp_n40g_st4x_pohbts3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS3));
        tmp_n40g_st4x_pohbts3.bf.K3BYTE = val;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS3), tmp_n40g_st4x_pohbts3.wrd);
        ret_val = CS_OK;
        break;
      }
    case TEN_POH_F3 :
      {
        TEN_N40G_ST4X_POHBTS3_t tmp_n40g_st4x_pohbts3;
        tmp_n40g_st4x_pohbts3.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS3));
        tmp_n40g_st4x_pohbts3.bf.F3BYTE = val;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS3), tmp_n40g_st4x_pohbts3.wrd);
        ret_val = CS_OK;
        break;
      }
    
    case TEN_POH_N1 :
      {
        TEN_N40G_ST4X_POHBTS4_t tmp_n40g_st4x_pohbts4;
        tmp_n40g_st4x_pohbts4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS4));
        tmp_n40g_st4x_pohbts4.bf.N1BYTE = val;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS4), tmp_n40g_st4x_pohbts4.wrd);
        ret_val = CS_OK;
        break;
     }   
   case TEN_POH_PFIXSTF :
      {
        TEN_N40G_ST4X_POHBTS4_t tmp_n40g_st4x_pohbts4;
        tmp_n40g_st4x_pohbts4.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS4));
        tmp_n40g_st4x_pohbts4.bf.PFIXSTF = val;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, POHBTS4), tmp_n40g_st4x_pohbts4.wrd);
        ret_val = CS_OK;
        break;
      }
    default :
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.  s/b 0..9.");
        ret_val = CS_ERROR;
        break;
      } 
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  /* Bugzilla #36019 - return value for API ten_n40g_set_poh_byte */
  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  N40G ST4X SET OHIE REGISTER                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_st4x_set_ohie(cs_uint16 module_id, 
                         cs_uint16 b1inv, 
                         cs_uint16 b1trans, 
                         cs_uint16 b1ie, 
                         cs_uint16 scren,  
                         cs_uint16 a1a2rsh)
/* INPUTS     : o Module Id                                     */
/*              o B1INV                                         */
/*              o B1TRANS                                       */
/*              o B1IE                                          */
/*              o SCREN                                         */
/*              o A1A2RSH                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets Insert enable bits.                                     */
/*                                                              */
/*   [b1inv]  Configures the B1 byte inversion control,         */
/*     should be used only for test purposes.                   */
/*     0 = no effect                                            */
/*     1 = invert calculated BIP-8 bitwise before insertion     */
/*         to B1 byte position                                  */
/*                                                              */
/*   [b1trans]  Used to enable simple B1 error transparency.    */
/*     0 = no effect                                            */
/*     1 = insert calculated B1 byte                            */
/*                                                              */
/*   [b1ie]  Configures the insertion of the calculated BIP-8   */
/*     to the B1 byte position.                                 */
/*     0 = no effect                                            */
/*     1 = insert calculated B1 byte                            */
/*                                                              */
/*   [scren]  Configures the SONET/SDH scrambler operation.     */
/*     0 = no scrambling                                        */
/*     1 = scrambling enabled                                   */
/*                                                              */
/*   [a1a2rsh]  Insert A1A2 in place of values received from    */
/*     Cross Connect to refresh FAS bytes.                      */ 
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_ST4X_OHIE_t tmp_st4x_ohie;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  tmp_st4x_ohie.bf.B1INV = b1inv;
  tmp_st4x_ohie.bf.B1TRANS = b1trans;
  tmp_st4x_ohie.bf.B1IE = b1ie;
  tmp_st4x_ohie.bf.SCREN = scren;
  tmp_st4x_ohie.bf.A1A2RSH = a1a2rsh;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  N40G ST4X SET B1ERRINS REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : N40G                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_st4x_set_b1errins(cs_uint16 module_id, 
                                     cs_uint16 b1errmsk)
/* INPUTS     : o Module Id                                     */
/*              o B1ErrMsk                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets B1 error insertion.                                     */
/*                                                              */
/*   [b1errmsk]  B1 error mask.                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_ST4X_B1ERRINS_t tmp_st4x_b1errins;
  T41_t *pDev = NULL;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);
  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_st4x_b1errins.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, B1ERRINS));
  tmp_st4x_b1errins.bf.B1ErrMsk = b1errmsk;
  TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, B1ERRINS), tmp_st4x_b1errins.wrd);
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  N40G SET OVERHEAD INSERTION ENABLES              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : N40G                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_n40g_set_oh_insertion_enables(cs_uint16 module_id, 
                                            cs_uint16 select, 
                                            cs_uint16 value)
/* INPUTS     : o Module Id                                         */
/*              o Select                                            */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Insert enable bits.                                              */
/*                                                                  */
/* The [select] parameter is specified as:                          */
/*   TEN_N40G_ST4X_OHIE_A1A2IE     =  0                             */
/*   TEN_N40G_ST4X_OHIE_A1A2RSH    =  1                             */
/*   TEN_N40G_ST4X_OHIE_A1A2INV    =  2                             */
/*   TEN_N40G_ST4X_OHIE_ErrFawEna  =  3                             */
/*   TEN_N40G_ST4X_OHIE_PRBSIE     =  4                             */
/*   TEN_N40G_ST4X_OHIE_POHIE      =  5                             */
/*   TEN_N40G_ST4X_OHIE_SCREN      =  6                             */
/*   TEN_N40G_ST4X_OHIE_B1IE       =  7                             */
/*   TEN_N40G_ST4X_OHIE_B1TRANS    =  8                             */
/*   TEN_N40G_ST4X_OHIE_B1INV      =  9                             */
/*                                                                  */
/* The [value] parameter is specified as:                           */
/*   For select = TEN_N40G_ST4X_OHIE_A1A2IE                         */
/*     This bit configures the timing generation of the SONET/SDH   */
/*     frame.                                                       */
/*     0 = Frame timing taken from input signal from Cross Connect. */
/*     1 = Frame timing generated locally.and A1/A2 bytes inserted. */
/*                                                                  */
/*   For select = TEN_N40G_ST4X_OHIE_A1A2RSH                        */
/*     Insert A1A2 in place of values received from Cross Connect   */
/*     to refresh FAS bytes.                                        */
/*                                                                  */
/*   For select = TEN_N40G_ST4X_OHIE_A1A2INV                        */
/*     FAS inversion control; use for test purposes only. This      */
/*     control becomes effective only if A1A2IE or A1A2RSH is set.  */
/*     0 = No effect                                                */
/*     1 = Invert FAS bitwise prior to insertion.                   */
/*                                                                  */
/*   For select = TEN_N40G_ST4X_OHIE_ErrFawEna                      */
/*     ErrFawEna[3:0] - These bits configure the minimum number of  */
/*     subsequent frames that will carry frame word error (see      */
/*     A1A2INV in SOHT_OHBEN0).                                     */
/*     Note: Setting value to 0 will set error continuously.        */
/*                                                                  */
/*   For select = TEN_N40G_ST4X_OHIE_PRBSIE                         */
/*     The payload of SONET/SDH frames will be replaced with PRBS   */
/*     as configured by the KPA. Additionally, if the POHIE is set, */
/*     the POH registers contents will be inserted to the POH byte  */
/*     positions of the first virtual container of the concatenated */
/*     payload. All other POH bytes of the concatenated payload     */
/*     will be set to the value configured in PFIXSTF (Fixed Stuff).*/
/*     The administrative unit (AU) pointer of the first AU of the  */
/*     concatenation will be set to 522(dec) with SS-bits as        */
/*     configured in SSBITS. All other AU pointers will be set to   */
/*     conctenation indication.                                     */
/*     0 = no effect                                                */
/*     1 = insert PRBS pattern to concatenated payload              */
/*                                                                  */
/*   For select = TEN_N40G_ST4X_OHIE_POHIE                          */
/*     If PRBSIE is set, this bit configures the insertion of POH   */
/*     bytes.                                                       */
/*     0 no effect                                                  */
/*     1 insert POH bytes as configured in respective registers     */
/*                                                                  */
/*   For select = TEN_N40G_ST4X_OHIE_SCREN                          */
/*     This bit configures the SONET/SDH scrambler operation.       */
/*     0 = no scrambling                                            */
/*     1 = scrambling enabled                                       */
/*                                                                  */
/*   For select = TEN_N40G_ST4X_OHIE_B1IE                           */
/*     This bit configures the insertion of the calculated BIP-8 to */
/*     the B1 byte position.                                        */
/*     0 = no effect                                                */
/*     1 = insert calculated B1 byte                                */
/*                                                                  */
/*   For select = TEN_N40G_ST4X_OHIE_B1TRANS                        */
/*     This bit is used to enable simple B1 error transparency. B1  */
/*     error byte detected by the receiver (recalculated BIP-8      */
/*     XORed with received B1 byte) is XORed with calculated BIP-8  */
/*     before insertion to B1 byte position. Note, that             */
/*     configuration bit B1IE must be set in this case.             */
/*     0 = no effect                                                */
/*     1 = insert calculated B1 byte                                */
/*                                                                  */
/*   For select = TEN_N40G_ST4X_OHIE_B1INV                          */
/*     This bit configures the B1 byte inversion control, should be */
/*     used only for test purposes.                                 */
/*     0 = no effect                                                */
/*     1 = invert calculated BIP-8 bitwise before insertion to B1   */
/*         byte position                                            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_N40G_ST4X_OHIE_t tmp_st4x_ohie;
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;

  TEN_MOD_COMMON_VALIDATE(module_id, pDev, CS_ERROR);

  TEN_MOD_LOCK(module_id, TEN_ID_N40G);
  tmp_st4x_ohie.wrd = TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, OHIE));
  switch (select) {
    case TEN_N40G_ST4X_OHIE_A1A2IE :
      {
        tmp_st4x_ohie.bf.A1A2IE = value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
        break;
      }
    case TEN_N40G_ST4X_OHIE_A1A2RSH :
      {
        tmp_st4x_ohie.bf.A1A2RSH = value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
        break;
      }
    case TEN_N40G_ST4X_OHIE_A1A2INV :
      {
        tmp_st4x_ohie.bf.A1A2INV = value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
        break;
      }
    case TEN_N40G_ST4X_OHIE_ErrFawEna :
      {
        tmp_st4x_ohie.bf.ErrFawEna = value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
        break;
      }
    case TEN_N40G_ST4X_OHIE_PRBSIE :
      {
        tmp_st4x_ohie.bf.PRBSIE = value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
        break;
      }
    case TEN_N40G_ST4X_OHIE_POHIE :
      {
        tmp_st4x_ohie.bf.POHIE = value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
        break;
      }
    case TEN_N40G_ST4X_OHIE_SCREN :
      {
        tmp_st4x_ohie.bf.SCREN = value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
        break;
      }
    case TEN_N40G_ST4X_OHIE_B1IE :
      {
        tmp_st4x_ohie.bf.B1IE = value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
        break;
      }
    case TEN_N40G_ST4X_OHIE_B1TRANS :
      {
        tmp_st4x_ohie.bf.B1TRANS = value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
        break;
      }
    case TEN_N40G_ST4X_OHIE_B1INV :
      {
        tmp_st4x_ohie.bf.B1INV = value;
        TEN_REG_WRITE(TEN_N40G_REG_ADDR(pDev, module_id, OHIE), tmp_st4x_ohie.wrd);
        break;
      }
    default :
      {
        CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_USER_ARG, ": select out of range.");
        ret_val = CS_ERROR;
      }
  }
  TEN_MOD_UNLOCK(module_id, TEN_ID_N40G);

  return (ret_val);
}
