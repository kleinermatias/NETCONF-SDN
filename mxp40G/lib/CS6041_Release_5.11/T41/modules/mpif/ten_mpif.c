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
 * ten_mpif.c
 *
 * Code related to MPIF block
 *
 * $Id: ten_mpif.c,v 1.62 2013/04/11 17:01:44 jccarlis Exp $
 *
 */

#include "tenabo40.h"
/* Local function prototype */
static cs_uint32 ten_mpif_get_misc_counter_low32(ten_dev_cb_t *pdevcb, 
                                                 cs_uint16     read_type);

/* Functions                */

/****************************************************************/
/* $rtn_hdr_start  GET CHIP'S JTAG ID                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint32 ten_mpif_get_chip_jtag_id(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 32-bit JTAG Id (or 0 on error)                  */
/* DESCRIPTION:                                                 */
/* Returns the 32-bit JTAG Id of the chip.                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 chip_id;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  chip_id = (TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_LSB)) |
             TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_MSB)) << 16);

  return (chip_id);
}

/****************************************************************/
/* $rtn_hdr_start  GET CHIP'S REVISION ID                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint32 ten_mpif_get_chip_rev_id(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Revision Id (or 0 on error)                     */
/* DESCRIPTION:                                                 */
/* Returns the Revision Id of the chip.                         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_CHIP_ID_MSB_t tmp_chip_id_msb;
  cs_uint32 rev_id;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  tmp_chip_id_msb.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_MSB));
  rev_id = tmp_chip_id_msb.bf.RevCode;
  
  return (rev_id);
}

/****************************************************************/
/* $rtn_hdr_start  GET CHIP'S DEV ID CODE SKU                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_chip_dev_id_code_sku(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : DevIdCode SKU                                   */
/* DESCRIPTION:                                                 */
/* Returns the Dev Id Code SKU of the chip.                     */
/*                                                              */
/* See ten_dev_id_code_sku_enums:                               */
/*   TEN_DEV_ID_CODE_SKU_CS6041 = 1,                            */
/*   TEN_DEV_ID_CODE_SKU_CS6042 = 2,                            */
/*   TEN_DEV_ID_CODE_SKU_CS6043 = 3,                            */
/*   TEN_DEV_ID_CODE_SKU_CS6045 = 5,                            */
/*   TEN_DEV_ID_CODE_SKU_CS6046 = 6,                            */
/*   TEN_DEV_ID_CODE_SKU_CS6048 = 8,                            */
/*   TEN_DEV_ID_CODE_SKU_CS6049 = 7                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_CHIP_ID_LSB_t tmp_chip_id_lsb;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  tmp_chip_id_lsb.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_LSB));
  return (tmp_chip_id_lsb.bf.DevIDCode_SKU);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF PRINT CHIP ID                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_print_chip_id(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Prints the various fields of the chip id.                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CHIP_ID_MSB_t tmp_chip_id_msb;
  TEN_MPIF_CHIP_ID_LSB_t tmp_chip_id_lsb;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_chip_id_msb.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_MSB));
  tmp_chip_id_lsb.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_LSB));

  CS_PRINT_OUTPUT("DevIDCode_SKU = %5d (0x%04X)\n", tmp_chip_id_lsb.bf.DevIDCode_SKU,
                                             tmp_chip_id_lsb.bf.DevIDCode_SKU);
  CS_PRINT_OUTPUT("ManID         = %5d (0x%04X)\n", tmp_chip_id_lsb.bf.ManID,
                                             tmp_chip_id_lsb.bf.ManID);
  CS_PRINT_OUTPUT("lsb           = %5d (0x%04X)\n", tmp_chip_id_lsb.bf.lsb,
                                             tmp_chip_id_lsb.bf.lsb);
  CS_PRINT_OUTPUT("RevCode       = %5d (0x%04X)\n", tmp_chip_id_msb.bf.RevCode,
                                             tmp_chip_id_msb.bf.RevCode);
  CS_PRINT_OUTPUT("DevIDCode     = %5d (0x%04X)\n", tmp_chip_id_msb.bf.DevIDCode,
                                             tmp_chip_id_msb.bf.DevIDCode);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CFG                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_cfg(cs_uint16 dev_id,
                          cs_uint16 tx_quad_mode_b,
                          cs_uint16 tx_quad_mode_a,
                          cs_uint16 rx_quad_mode_b,
                          cs_uint16 rx_quad_mode_a)
/* INPUTS     : o Device Id                                         */
/*              o Tx Quad Mode B                                    */
/*              o Tx Quad Mode A                                    */
/*              o Rx Quad Mode B                                    */
/*              o Rx Quad Mode A                                    */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Quad Mode settings: when clear (0), the 40G module is enabled.   */
/* When set (1), the 40G module is bypassed and should only be set  */
/* for quad 10G applications.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GLOBAL_CFG_t tmp_global_cfg;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_global_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CFG));
  tmp_global_cfg.bf.tx_quad_mode_b = tx_quad_mode_b;
  tmp_global_cfg.bf.tx_quad_mode_a = tx_quad_mode_a;
  tmp_global_cfg.bf.rx_quad_mode_b = rx_quad_mode_b;
  tmp_global_cfg.bf.rx_quad_mode_a = rx_quad_mode_a;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CFG), tmp_global_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/* Bugzilla 26130 Start */
/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT 40G PER MODULE                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_cfg_per_module (cs_uint16 dev_id,
                                          cs_module_t module_num,
                                          cs_uint16 tx_quad_mode,
                                          cs_uint16 rx_quad_mode)
/* INPUTS     : o Device Id                                         */
/*              o Tx Quad Mode                                      */
/*              o Rx Quad Mode                                      */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Quad Mode settings: when clear (0), the 40G module is enabled.   */
/* When set (1), the 40G module is bypassed and should only be set  */
/* for quad 10G applications.                                       */
/*                                                                  */
/* The [tx_quad_mode] parameter is specified as:                    */
/*   0 = 40G TX module is enabled.                                  */
/*   1 = 40G TX module B is bypassed; should only be set for quad   */
/*           10G applications.                                      */
/*                                                                  */
/* The [rx_quad_mode] parameter is specified as:                    */
/*   0 = 40G RX module is enabled.                                  */
/*   1 = 40G RX module B is bypassed; should only be set for quad   */
/*           10G applications.                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GLOBAL_CFG_t tmp_global_cfg;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_mpif_global_cfg_per_module";  

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s, tx_quad_mode=%d, rx_quad_mode=%d\n",
           func,
           ten_module_strings[module_num],
           tx_quad_mode,
           rx_quad_mode);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_global_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CFG));

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_cfg.bf.tx_quad_mode_a = tx_quad_mode;
    tmp_global_cfg.bf.rx_quad_mode_a = rx_quad_mode;
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_cfg.bf.tx_quad_mode_b = tx_quad_mode;
    tmp_global_cfg.bf.rx_quad_mode_b = rx_quad_mode;
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CFG), tmp_global_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}
/* Bugzilla 26130 End */

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET COMMON                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_common(cs_uint16 dev_id,
                                       cs_reset_action_t act,
                                       cs_uint16 bitfield)
/* INPUTS     : o Device Id                                     */
/*              o Reset Action                                  */
/*              o Bitfield                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections.           */
/* The selections that are masked off will not be affected.     */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* The [bitfield] parameter is specified as:                    */
/*   TEN_MPIF_GLOBAL_RESET_COMMON_CHIP    = 0x0001,             */
/*   TEN_MPIF_GLOBAL_RESET_COMMON_XCON    = 0x0002,             */
/*   TEN_MPIF_GLOBAL_RESET_COMMON_SPOH    = 0x0004,             */
/*   TEN_MPIF_GLOBAL_RESET_COMMON_OHPP_A  = 0x0008,             */
/*   TEN_MPIF_GLOBAL_RESET_COMMON_OHPP_B  = 0x0010,             */
/*   TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS  = 0x0020,             */
/*   TEN_MPIF_GLOBAL_RESET_COMMON_CLKLOSS = 0x0080,             */
/*   TEN_MPIF_GLOBAL_RESET_COMMON_MPIF    = 0x0100,             */
/*   TEN_MPIF_GLOBAL_RESET_COMMON_ALL     = 0x01FF              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_COMMON_t tmp_global_reset_common;
  T41_t *pDev = NULL;

  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": act = 0x%04X\n", act);
      return (CS_ERROR);
  }
  if (bitfield > TEN_MPIF_GLOBAL_RESET_COMMON_ALL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": bitfield = 0x%04X\n", bitfield);
      return (CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_common.wrd = bitfield;

  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_COMMON),
                     tmp_global_reset_common.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET HSIF                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_hsif(cs_uint16 dev_id,
                                     cs_module_t module_num,
                                     cs_dir_t dir,
                                     cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_HSIF_t tmp_global_reset_hsif;
  T41_t *pDev = NULL;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  /* set mask bits for affected selections */
  tmp_global_reset_hsif.wrd = 0;
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_hsif.bf.rx_a = 1;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_hsif.bf.tx_a = 1;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_hsif.bf.rx_b = 1;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_hsif.bf.tx_b = 1;
    }
  }
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_HSIF),
                   tmp_global_reset_hsif.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET HSIF MPIF                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_hsif_mpif(cs_uint16 dev_id,
                                          cs_module_t module_num,
                                          cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_HSIF_t tmp_global_reset_hsif;
  T41_t *pDev = NULL;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  /* set mask bits for affected selections */
  tmp_global_reset_hsif.wrd = 0;
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_reset_hsif.bf.mpif_a = 1;
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_reset_hsif.bf.mpif_b = 1;
  }
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_HSIF),
                   tmp_global_reset_hsif.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SFI41                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_sfi41(cs_uint16 dev_id,
                                      cs_module_t module_num,
                                      cs_dir_t dir,
                                      cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_SFI41_t tmp_global_reset_sfi41;
  T41_t *pDev = NULL;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  /* set mask bits for affected selections */
  tmp_global_reset_sfi41.wrd = 0;
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_sfi41.bf.rx_a = 1;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_sfi41.bf.tx_a = 1;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_sfi41.bf.rx_b = 1;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_sfi41.bf.tx_b = 1;
    }
  }
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SFI41),
                   tmp_global_reset_sfi41.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SFI41 MPIF                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_sfi41_mpif(cs_uint16 dev_id,
                                           cs_module_t module_num,
                                           cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_SFI41_t tmp_global_reset_sfi41;
  T41_t *pDev = NULL;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  /* set mask bits for affected selections */
  tmp_global_reset_sfi41.wrd = 0;
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_reset_sfi41.bf.mpif_a = 1;
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_reset_sfi41.bf.mpif_b = 1;
  }
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SFI41),
                   tmp_global_reset_sfi41.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET GFEC 10G                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_gfec_10g(cs_uint16 dev_id,
                                         cs_uint16 select,
                                         cs_dir_t dir,
                                         cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Select                                        */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified  selections.          */
/* The selections that are masked off will not be affected.     */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_MPIF_GLOBAL_GFEC_10G_0   = 0x0001                      */
/*   TEN_MPIF_GLOBAL_GFEC_10G_1   = 0x0002                      */
/*   TEN_MPIF_GLOBAL_GFEC_10G_2   = 0x0004                      */
/*   TEN_MPIF_GLOBAL_GFEC_10G_ALL = 0x0007                      */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_GFEC_t tmp_global_reset_gfec;
  T41_t *pDev = NULL;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  /* set mask bits for affected selections */
  tmp_global_reset_gfec.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_reset_gfec.bf.One0g_rx = select;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_reset_gfec.bf.One0g_tx = select;
  }

   /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GFEC),
                                       tmp_global_reset_gfec.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GET GLOBAL RESET GFEC 10G               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_global_reset_gfec_10g(cs_uint16 dev_id,
                                             cs_uint16 select,
                                             cs_dir_t dir)
/* INPUTS     : o Device Id                                     */
/*              o Select                                        */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 1=hard reset, 0=not in hard reset               */
/* DESCRIPTION:                                                 */
/* Returns the current state of the hard reset for the          */
/* specified selection.                                         */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_MPIF_GLOBAL_GFEC_10G_0   = 0                           */
/*   TEN_MPIF_GLOBAL_GFEC_10G_1   = 1                           */
/*   TEN_MPIF_GLOBAL_GFEC_10G_2   = 2                           */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_GFEC_t tmp_global_reset_gfec;
  T41_t *pDev = NULL;
  cs_uint16 tmp;

  if (dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (0);
  }
  if (select > 2) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": select out of range");
    return (0);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);
  tmp_global_reset_gfec.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GFEC));
  tmp = (1<<select);
  if (dir == CS_RX) {
    if (tmp_global_reset_gfec.bf.One0g_rx & tmp) {
      CS_PRINT("MPIF_GLOBAL_RESET_GFEC.One0g_rx instance=%d still in hard reset\n", select);
      return 1;
    }
  }
  if (dir == CS_TX) {
    if (tmp_global_reset_gfec.bf.One0g_tx & tmp) {
      CS_PRINT("MPIF_GLOBAL_RESET_GFEC.One0g_tx instance=%d still in hard reset\n", select);
      return 1;
    }
  }
  return (0);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET GFEC 40G                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_gfec_40g(cs_uint16 dev_id,
                                         cs_uint16 select,
                                         cs_dir_t dir,
                                         cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Select                                        */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified  selections.          */
/* The selections that are masked off will not be affected.     */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_MPIF_GLOBAL_GFEC_40G_0   = 0x0001                      */
/*   TEN_MPIF_GLOBAL_GFEC_40G_1   = 0x0002                      */
/*   TEN_MPIF_GLOBAL_GFEC_40G_ALL = 0x0003                      */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_GFEC_t tmp_global_reset_gfec;
  T41_t *pDev = NULL;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  /* set mask bits for affected selections */
  tmp_global_reset_gfec.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_reset_gfec.bf.Four0g_rx = select;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_reset_gfec.bf.Four0g_tx = select;
  }

   /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GFEC),
                                       tmp_global_reset_gfec.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GET GLOBAL RESET GFEC 40G               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_global_reset_gfec_40g(cs_uint16 dev_id,
                                             cs_uint16 select,
                                             cs_dir_t dir)
/* INPUTS     : o Device Id                                     */
/*              o Select                                        */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 1=hard reset, 0=not in hard reset               */
/* DESCRIPTION:                                                 */
/* Returns the current state of the hard reset for the          */
/* specified selection.                                         */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_MPIF_GLOBAL_GFEC_40G_0   = 0                           */
/*   TEN_MPIF_GLOBAL_GFEC_40G_1   = 1                           */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_GFEC_t tmp_global_reset_gfec;
  T41_t *pDev = NULL;
  cs_uint16 tmp;

  if (dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (0);
  }
  if (select > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": select out of range");
    return (0);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);
  tmp_global_reset_gfec.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GFEC));
  tmp = (1<<select);
  if (dir == CS_RX) {
    if (tmp_global_reset_gfec.bf.Four0g_rx & tmp) {
      CS_PRINT("MPIF_GLOBAL_RESET_GFEC.Four0g_rx instance=%d still in hard reset\n", select);
      return 1;
    }
  }
  if (dir == CS_TX) {
    if (tmp_global_reset_gfec.bf.Four0g_tx & tmp) {
      CS_PRINT("MPIF_GLOBAL_RESET_GFEC.Four0g_tx instance=%d still in hard reset\n", select);
      return 1;
    }
  }
  return (0);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET UFEC                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_ufec(cs_uint16 dev_id,
                                     cs_uint16 select,
                                     cs_dir_t dir,
                                     cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Select                                        */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified  selections.          */
/* The selections that are masked off will not be affected.     */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_MPIF_GLOBAL_UFEC_0   = 0x0001                          */
/*   TEN_MPIF_GLOBAL_UFEC_1   = 0x0002                          */
/*   TEN_MPIF_GLOBAL_UFEC_2   = 0x0004                          */
/*   TEN_MPIF_GLOBAL_UFEC_3   = 0x0008                          */
/*   TEN_MPIF_GLOBAL_UFEC_ALL = 0x000F                          */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_UFEC_t tmp_global_reset_ufec;
  T41_t *pDev = NULL;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_ufec.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_reset_ufec.bf.rx = select;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_reset_ufec.bf.tx = select;
  }

  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_UFEC),
                     tmp_global_reset_ufec.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GET GLOBAL RESET UFEC                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_global_reset_ufec(cs_uint16 dev_id,
                                         cs_uint16 select,
                                         cs_dir_t dir)
/* INPUTS     : o Device Id                                     */
/*              o Select                                        */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 1=hard reset, 0=not in hard reset               */
/* DESCRIPTION:                                                 */
/* Returns the current state of the hard reset for the          */
/* specified selection.                                         */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_MPIF_GLOBAL_UFEC_0   = 1                               */
/*   TEN_MPIF_GLOBAL_UFEC_1   = 2                               */
/*   TEN_MPIF_GLOBAL_UFEC_2   = 3                               */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_UFEC_t tmp_global_reset_ufec;
  T41_t *pDev = NULL;
  cs_uint16 tmp;

  if (dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (0);
  }
  
  if (select > 3) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": select out of range");
    return (0);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_global_reset_ufec.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_UFEC));
  tmp = (1<<select);
  if (dir == CS_RX) {
    if (tmp_global_reset_ufec.bf.rx & tmp) {
      CS_PRINT("TEN_MPIF_GLOBAL_RESET_UFEC.rx instance=%d still in hard reset\n", select);
      return 1;
    }
  }
  if (dir == CS_TX) {
    if (tmp_global_reset_ufec.bf.tx & tmp) {
      CS_PRINT("TEN_MPIF_GLOBAL_RESET_UFEC.tx instance=%d still in hard reset\n", select);
      return 1;
    }
  }
  return (0);  
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET N40G                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_n40g(cs_uint16 dev_id,
                                     cs_module_t module_num,
                                     cs_dir_t dir,
                                     cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_N40G_t tmp_global_reset_n40g;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_mpif_global_reset_n40g";  

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   module_num out of range", func);
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED! dir out of range", func);
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!  act out of range", func);
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s, %s, %s\n",
           func,
           ten_module_strings[module_num & 1],
           ten_dir_strings[dir],
           ten_reset_act_strings[act]);


  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_n40g.wrd = 0;
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_n40g.bf.rx_a = 1;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_n40g.bf.tx_a = 1;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_n40g.bf.rx_b = 1;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_n40g.bf.tx_b = 1;
    }
  }
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N40G),
                   tmp_global_reset_n40g.wrd, act);
  /* API decides how sys reset bits should be set, if both   */
  /* RX and TX are asserted, SYS should assert               */
  tmp_global_reset_n40g.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N40G));
  tmp_global_reset_n40g.bf.sys_a = tmp_global_reset_n40g.bf.tx_a & tmp_global_reset_n40g.bf.rx_a;
  tmp_global_reset_n40g.bf.sys_b = tmp_global_reset_n40g.bf.tx_b & tmp_global_reset_n40g.bf.rx_b;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N40G), tmp_global_reset_n40g.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GET GLOBAL RESET N40G                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_global_reset_n40g(cs_uint16 dev_id,
                                     cs_module_t module_num,
                                     cs_dir_t dir)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 1=hard reset, 0=not in hard reset               */
/* DESCRIPTION:                                                 */
/* Returns the current state of the hard reset for the          */
/* specified selection.                                         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_N40G_t tmp_global_reset_n40g;
  T41_t *pDev = NULL;

  if (module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "module_num out of range");
    return (0);
  }
  if (dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "dir out of range");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);
  tmp_global_reset_n40g.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N40G));

  if ((dir == CS_RX) && (module_num == TEN_MODULE_A)) {
    if (tmp_global_reset_n40g.bf.rx_a) {
      CS_PRINT("TEN_MPIF_GLOBAL_RESET_N40G.rx_a still in hard reset\n");
      return 1;
    }
  }
  else if ((dir == CS_RX) && (module_num == TEN_MODULE_B)) {
    if (tmp_global_reset_n40g.bf.rx_b) {
      CS_PRINT("TEN_MPIF_GLOBAL_RESET_N40G.rx_b still in hard reset\n");
      return 1;
    }
  }
  else if ((dir == CS_TX) && (module_num == TEN_MODULE_A)) {
    if (tmp_global_reset_n40g.bf.tx_a) {
      CS_PRINT("TEN_MPIF_GLOBAL_RESET_N40G.tx_a still in hard reset\n");
      return 1;
    }
  }
  else if ((dir == CS_TX) && (module_num == TEN_MODULE_B)) {
    if (tmp_global_reset_n40g.bf.tx_b) {
      CS_PRINT("TEN_MPIF_GLOBAL_RESET_N40G.tx_b still in hard reset\n");
      return 1;
    }
  }
  return (0);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET N10G                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_n10g(cs_uint16 dev_id,
                                     cs_module_t module_num,
                                     cs_uint8 slice,
                                     cs_dir_t dir,
                                     cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_RESET_N10G_A_t tmp_global_reset_n10g_a;
    /* set mask bits for affected selections */
    tmp_global_reset_n10g_a.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_n10g_a.bf.rx = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_n10g_a.bf.tx = tmp;
    }
    /* perform the specified reset action */
    ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_A),
                     tmp_global_reset_n10g_a.wrd, act);
    /* API decides how sys reset bits should be set, if both   */
    /* RX and TX are asserted, SYS should assert               */
    tmp_global_reset_n10g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_A));
    tmp_global_reset_n10g_a.bf.sys = (tmp_global_reset_n10g_a.bf.rx &
                                      tmp_global_reset_n10g_a.bf.tx);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_A), tmp_global_reset_n10g_a.wrd);
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_RESET_N10G_B_t tmp_global_reset_n10g_b;
    /* set mask bits for affected selections */
    tmp_global_reset_n10g_b.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_n10g_b.bf.rx = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_n10g_b.bf.tx = tmp;
    }
    /* perform the specified reset action */
    ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_B),
                     tmp_global_reset_n10g_b.wrd, act);
    /* API decides how sys reset bits should be set, if both   */
    /* RX and TX are asserted, SYS should assert               */
    tmp_global_reset_n10g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_B));
    tmp_global_reset_n10g_b.bf.sys = (tmp_global_reset_n10g_b.bf.rx &
                                      tmp_global_reset_n10g_b.bf.tx);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_B), tmp_global_reset_n10g_b.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GET GLOBAL RESET N10G                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_global_reset_n10g(cs_uint16 dev_id,
                                         cs_module_t module_num,
                                         cs_uint8 slice,
                                         cs_dir_t dir)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 1=hard reset, 0=not in hard reset               */
/* DESCRIPTION:                                                 */
/* Returns the current state of the hard reset for the          */
/* specified selection.                                         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_N10G_A_t tmp_global_reset_n10g_a;
  TEN_MPIF_GLOBAL_RESET_N10G_B_t tmp_global_reset_n10g_b;

  if (module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num out of range");
    return (0);
  }
  
  if(dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (0);
  }
  if (slice > TEN_SLICE3) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": slice out of range");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  tmp = (1<<slice);
  if ((dir == CS_RX) && (module_num == TEN_MODULE_A)) {
    tmp_global_reset_n10g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_A));
    if (tmp_global_reset_n10g_a.bf.rx & tmp) {
      CS_PRINT("TEN_MPIF_GLOBAL_RESET_N10G_A.rx slice=%d still in hard reset\n", slice);
      return 1;
    }
  }
  if ((dir == CS_RX) && (module_num == TEN_MODULE_B)) {
    tmp_global_reset_n10g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_B));
    if (tmp_global_reset_n10g_b.bf.rx & tmp) {
      CS_PRINT("TEN_MPIF_GLOBAL_RESET_N10G_B.rx slice=%d still in hard reset\n", slice);
      return 1;
    }
  }
  if ((dir == CS_TX) && (module_num == TEN_MODULE_A)) {
    tmp_global_reset_n10g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_A));
    if (tmp_global_reset_n10g_a.bf.tx & tmp) {
      CS_PRINT("TEN_MPIF_GLOBAL_RESET_N10G_A.tx slice=%d still in hard reset\n", slice);
      return 1;
    }
  }
  if ((dir == CS_TX) && (module_num == TEN_MODULE_B)) {
    tmp_global_reset_n10g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_B));
    if (tmp_global_reset_n10g_b.bf.tx & tmp) {
      CS_PRINT("TEN_MPIF_GLOBAL_RESET_N10G_B.tx slice=%d still in hard reset\n", slice);
      return 1;
    }
  }
  
  return (0);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET PP10G                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_pp10g(cs_uint16 dev_id,
                                      cs_module_t module_num,
                                      cs_uint8 slice,
                                      cs_dir_t dir,
                                      cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_RESET_PP10G_A_t tmp_global_reset_pp10g_a;
    /* set mask bits for affected selections */
    tmp_global_reset_pp10g_a.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_pp10g_a.bf.rx = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_pp10g_a.bf.tx = tmp;
    }
    /* perform the specified reset action */
    ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_A),
                     tmp_global_reset_pp10g_a.wrd, act);
    /* API decides how sys reset bits should be set, if both   */
    /* RX and TX are asserted, SYS should assert               */
    tmp_global_reset_pp10g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_A));
    tmp_global_reset_pp10g_a.bf.sys = (tmp_global_reset_pp10g_a.bf.rx &
                                       tmp_global_reset_pp10g_a.bf.tx);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_A), tmp_global_reset_pp10g_a.wrd);
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_RESET_PP10G_B_t tmp_global_reset_pp10g_b;
    /* set mask bits for affected selections */
    tmp_global_reset_pp10g_b.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_pp10g_b.bf.rx = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_pp10g_b.bf.tx = tmp;
    }
    /* perform the specified reset action */
    ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_B),
                     tmp_global_reset_pp10g_b.wrd, act);
    /* API decides how sys reset bits should be set, if both   */
    /* RX and TX are asserted, SYS should assert               */
    tmp_global_reset_pp10g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_B));
    tmp_global_reset_pp10g_b.bf.sys = (tmp_global_reset_pp10g_b.bf.rx &
                                       tmp_global_reset_pp10g_b.bf.tx);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_B), tmp_global_reset_pp10g_b.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET PP10G SYS                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_pp10g_sys(cs_uint16 dev_id,
                                      cs_module_t module_num,
                                      cs_uint8 slice,
                                      cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }

  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_RESET_PP10G_A_t tmp_global_reset_pp10g_a;
    /* set mask bits for affected selections */
    tmp_global_reset_pp10g_a.wrd = 0;
    tmp_global_reset_pp10g_a.bf.sys = tmp;
    /* perform the specified reset action */
    ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_A),
                     tmp_global_reset_pp10g_a.wrd, act);
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_RESET_PP10G_B_t tmp_global_reset_pp10g_b;
    /* set mask bits for affected selections */
    tmp_global_reset_pp10g_b.wrd = 0;
    tmp_global_reset_pp10g_b.bf.sys = tmp;
    /* perform the specified reset action */
    ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_B),
                     tmp_global_reset_pp10g_b.wrd, act);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SYNCDSYNC                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_syncdsync(cs_uint16 dev_id,
                                          cs_module_t module_num,
                                          cs_uint8 slice,
                                          cs_dir_t dir,
                                          cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp    = 0;
  cs_uint16 tmp_ra = 0;
  cs_uint16 tmp_ta = 0;
  cs_uint16 tmp_rb = 0;
  cs_uint16 tmp_tb = 0;
  TEN_MPIF_GLOBAL_RESET_SYNCDSYNC_t tmp_global_reset_syncdsync;
  cs_char8 *func = "ten_mpif_global_reset_syncdsync";  

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() module_num out of range", func);
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() dir out of range", func);
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() act out of range", func);
    return(CS_ERROR);
  }
/*  CS_PRINT("%s() %s, %s, %s, %s\n",
            func,
            ten_module_strings[module_num],
            ten_slice_strings[slice],
            ten_dir_strings[dir],
            ten_reset_act_strings[act]);
*/

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_syncdsync.wrd = 0;
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_ra = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_ta = tmp << 8;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_rb = tmp << 4;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_tb = tmp << 12;
    }
  }
  /* perform the specified reset action */
  tmp_global_reset_syncdsync.wrd = tmp_ra | tmp_ta | tmp_rb | tmp_tb;
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SYNCDSYNC),
                     tmp_global_reset_syncdsync.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GET GLOBAL RESET SYNCDSYNC              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_global_reset_syncdsync(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_uint8 slice,
                                              cs_dir_t dir)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0 = not in hard reset, 1 = hard reset           */
/* DESCRIPTION:                                                 */
/* Returns the current state of the hard reset for the          */
/* specified selection.                                         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 tmp;
  TEN_MPIF_GLOBAL_RESET_SYNCDSYNC_t tmp_global_reset_syncdsync;
  T41_t *pDev;

  if (module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "module_num out of range");
    return (0);
  }
  if (dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "dir out of range");
    return (0);
  }
  if (slice > TEN_SLICE3) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "slice out of range");
    return (0);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  tmp_global_reset_syncdsync.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SYNCDSYNC));
  
  if (dir == CS_RX) {
  tmp = (1 << (slice + (module_num)*4));
  CS_PRINT("slice=%d, tmp=%04X\n", slice, tmp);
    if (tmp_global_reset_syncdsync.bf.rx & tmp) {
      CS_PRINT("MPIF_GLOBAL_RESET_SYNCDSYNC RX in hard reset\n");
      return (1);
    }
  }
  
  if (dir == CS_TX) {
  tmp = (1 << (slice + (module_num)*4));
  CS_PRINT("slice=%d, tmp=%04X\n", slice, tmp);
    if (tmp_global_reset_syncdsync.bf.tx & tmp) {
      CS_PRINT("MPIF_GLOBAL_RESET_SYNCDSYNC TX in hard reset\n");
      return (1);
    }
  }
  return (0);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET GPLL                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_gpll(cs_uint16 dev_id,
                                     cs_module_t module_num,
                                     cs_uint8 slice,
                                     cs_dir_t dir,
                                     cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp    = 0;
  cs_uint16 tmp_ra = 0;
  cs_uint16 tmp_ta = 0;
  cs_uint16 tmp_rb = 0;
  cs_uint16 tmp_tb = 0;
  TEN_MPIF_GLOBAL_RESET_GPLL_t tmp_global_reset_gpll;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  /* set mask bits for affected selections */
  tmp_global_reset_gpll.wrd = 0;
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_ra = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_ta = tmp << 4;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_rb = tmp << 8;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_tb = tmp << 12;
    }
  }
  /* perform the specified reset action */
  tmp_global_reset_gpll.wrd = tmp_ra | tmp_ta | tmp_rb | tmp_tb;
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_GPLL),
                   tmp_global_reset_gpll.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SYSPLL                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_reset_syspll(cs_uint16 dev_id,
                                       cs_reset_action_t act)
/* INPUTS     : o Device Id                                         */
/*              o Reset Action                                      */
/*              o Sds                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a hard reset on the specified (masked on) selections.   */
/* The selections that are masked off will not be affected.         */
/*                                                                  */
/* The [act] parameter specifies the reset option and is one of the */
/* following:                                                       */
/*   CS_RESET_DEASSERT, CS_RESET_ASSERT or CS_RESET_TOGGLE.         */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset for 20 milliseconds and then de-assert the reset bit(s). */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_SYSPLL_t tmp_global_reset_syspll;
  T41_t *pDev = NULL;

  if ((act != CS_RESET_DEASSERT) && (act != CS_RESET_ASSERT) && (act != CS_RESET_TOGGLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": act = 0x%04X\n", act);
      return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_syspll.wrd = 0;
  tmp_global_reset_syspll.bf.sds = 1;

  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SYSPLL),
                     tmp_global_reset_syspll.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET XFI DSP                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_xfi_dsp(cs_uint16 dev_id,
                                           cs_uint8 slice,
                                           cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t    *pDev = NULL;
  cs_uint16 tmp  = 0;
  TEN_MPIF_GLOBAL_RESET_XFI_DSP_t tmp_global_reset_xfi_dsp;

  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_global_reset_xfi_dsp.wrd = 0;

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  /* perform the specified reset action */
  tmp_global_reset_xfi_dsp.bf.msmif = tmp;
  tmp_global_reset_xfi_dsp.bf.agc = tmp;
  tmp_global_reset_xfi_dsp.bf.dsp = tmp;
  tmp_global_reset_xfi_dsp.bf.mseq = tmp;
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_XFI_DSP),
                   tmp_global_reset_xfi_dsp.wrd, act);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET CLOCK LOSS                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_clock_loss(cs_uint16 dev_id,
                                           cs_module_t module_num,
                                           cs_uint8 slice,
                                           cs_dir_t dir,
                                           cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp    = 0;
  cs_uint16 tmp_ra = 0;
  cs_uint16 tmp_ta = 0;
  cs_uint16 tmp_rb = 0;
  cs_uint16 tmp_tb = 0;
  TEN_MPIF_GLOBAL_RESET_CLOCK_LOSS_t tmp_global_reset_clock_loss;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  /* set mask bits for affected selections */
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_ra = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_ta = tmp << 4;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_rb = tmp << 8;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_tb = tmp << 12;
    }
  }
  /* perform the specified reset action */
  tmp_global_reset_clock_loss.wrd = tmp_ra | tmp_ta | tmp_rb | tmp_tb;
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_CLOCK_LOSS),
                     tmp_global_reset_clock_loss.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE COMMON                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_clock_disable_common(cs_uint16 dev_id,
                                               cs_ctl_t  ctl,
                                               cs_uint16 bitfield)
/* INPUTS     : o Device Id                                         */
/*              o Control                                           */
/*              o Bitfield                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control disabling of the clock to the specified (masked on)      */
/* blocks in the CS600X device.  The blocks that have clock         */
/* disable set to CS_DISABLE are inaccessible from the              */
/* microprocessor port.  After the clock disable to a block is      */
/* written from CS_DISABLE to CS_ENABLE, the software reset APIs    */
/* should be used to reset that affected block.                     */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* the following:                                                   */
/*   CS_DISABLE (0) to disable the specified clock(s) or            */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API will  */
/*   generate the correct sense of the bit expected by the device.  */
/*                                                                  */
/* The [bitfield] parameter is specified as:                        */
/*   TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON   = 0x0001,          */
/*   TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_SPOH   = 0x0002,          */
/*   TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_OHPP_A = 0x0004,          */
/*   TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_OHBB_B = 0x0008,          */
/*   TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_ALL    = 0x000F           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_t tmp_global_clock_disable_common;
  T41_t *pDev = NULL;

  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (bitfield > TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_ALL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": bitfield = 0x%04X\n", bitfield);
      return (CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_global_clock_disable_common.wrd = bitfield;
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_COMMON),
                                  tmp_global_clock_disable_common.wrd, ctl);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE MR A               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_clock_disable_mr_a(cs_uint16 dev_id,
                                             cs_uint8 slice,
                                             cs_dir_t dir,
                                             cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control disabling of the clock to the specified              */
/* blocks in the CS600X device.  The blocks that have clock     */
/* disable set to CS_DISABLE are inaccessible from the          */
/* microprocessor port.  After the clock disable to a block is  */
/* written from CS_DISABLE to CS_ENABLE, the software reset     */
/* APIs should be used to reset that affected block.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   CS_DISABLE (0) to disable the specified clock(s) or        */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API   */
/*   will generate the correct sense of the bit expected by the */
/*   device.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_A_t tmp_global_clock_disable_hsif_a;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_clock_disable_hsif_a.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_hsif_a.bf.mr_rx = tmp;
    tmp_global_clock_disable_hsif_a.bf.xfi_rx = tmp;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_hsif_a.bf.mr_tx = tmp;
    tmp_global_clock_disable_hsif_a.bf.xfi_tx = tmp;
  }
  /* perform the specified reset action */
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_HSIF_A),
                    tmp_global_clock_disable_hsif_a.wrd, ctl);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE MR B               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_clock_disable_mr_b(cs_uint16 dev_id,
                                             cs_uint8 slice,
                                             cs_dir_t dir,
                                             cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control disabling of the clock to the specified              */
/* blocks in the CS600X device.  The blocks that have clock     */
/* disable set to CS_DISABLE are inaccessible from the          */
/* microprocessor port.  After the clock disable to a block is  */
/* written from CS_DISABLE to CS_ENABLE, the software reset     */
/* APIs should be used to reset that affected block.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   CS_DISABLE (0) to disable the specified clock(s) or        */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API   */
/*   will generate the correct sense of the bit expected by the */
/*   device.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B_t tmp_global_clock_disable_hsif_b;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_clock_disable_hsif_b.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_hsif_b.bf.mr_rx = tmp;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_hsif_b.bf.mr_tx = tmp;
  }
  /* perform the specified reset action */
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_HSIF_B),
                    tmp_global_clock_disable_hsif_b.wrd, ctl);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE XFI B              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_clock_disable_xfi_b(cs_uint16 dev_id,
                                              cs_uint8 slice,
                                              cs_dir_t dir,
                                              cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control disabling of the clock to the specified              */
/* blocks in the CS600X device.  The blocks that have clock     */
/* disable set to CS_DISABLE are inaccessible from the          */
/* microprocessor port.  After the clock disable to a block is  */
/* written from CS_DISABLE to CS_ENABLE, the software reset     */
/* APIs should be used to reset that affected block.            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   CS_DISABLE (0) to disable the specified clock(s) or        */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API   */
/*   will generate the correct sense of the bit expected by the */
/*   device.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_HSIF_B_t tmp_global_clock_disable_hsif_b;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_clock_disable_hsif_b.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_hsif_b.bf.xfi_rx = tmp;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_hsif_b.bf.xfi_tx = tmp;
  }
  /* perform the specified reset action */
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_HSIF_B),
                    tmp_global_clock_disable_hsif_b.wrd, ctl);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE GFEC 10G           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_clock_disable_gfec_10g(cs_uint16 dev_id,
                                                 cs_uint16 select,
                                                 cs_dir_t dir,
                                                 cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Select                                        */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control disabling of the clock to the specified              */
/* blocks in the CS600X device.  The blocks that have clock     */
/* disable set to CS_DISABLE are inaccessible from the          */
/* microprocessor port.  After the clock disable to a block is  */
/* written from CS_DISABLE to CS_ENABLE, the software reset     */
/* APIs should be used to reset that affected block.            */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_MPIF_GLOBAL_GFEC_10G_0   = 0x0001                      */
/*   TEN_MPIF_GLOBAL_GFEC_10G_1   = 0x0002                      */
/*   TEN_MPIF_GLOBAL_GFEC_10G_2   = 0x0004                      */
/*   TEN_MPIF_GLOBAL_GFEC_10G_ALL = 0x0007                      */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   CS_DISABLE (0) to disable the specified clock(s) or        */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API   */
/*   will generate the correct sense of the bit expected by the */
/*   device.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC_t tmp_global_clock_disable_gfec;
  T41_t *pDev = NULL;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_global_clock_disable_gfec.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_gfec.bf.One0g_rx = select;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_gfec.bf.One0g_tx = select;
  }
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_GFEC),
                    tmp_global_clock_disable_gfec.wrd, ctl);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}
/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE GFEC 40G           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_clock_disable_gfec_40g(cs_uint16 dev_id,
                                                 cs_uint16 select,
                                                 cs_dir_t dir,
                                                 cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Select                                        */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control disabling of the clock to the specified              */
/* blocks in the CS600X device.  The blocks that have clock     */
/* disable set to CS_DISABLE are inaccessible from the          */
/* microprocessor port.  After the clock disable to a block is  */
/* written from CS_DISABLE to CS_ENABLE, the software reset     */
/* APIs should be used to reset that affected block.            */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_MPIF_GLOBAL_GFEC_40G_0   = 0x0001                      */
/*   TEN_MPIF_GLOBAL_GFEC_40G_1   = 0x0002                      */
/*   TEN_MPIF_GLOBAL_GFEC_40G_ALL = 0x0003                      */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   CS_DISABLE (0) to disable the specified clock(s) or        */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API   */
/*   will generate the correct sense of the bit expected by the */
/*   device.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_GFEC_t tmp_global_clock_disable_gfec;
  T41_t *pDev = NULL;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_global_clock_disable_gfec.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_gfec.bf.Four0g_rx = select;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_gfec.bf.Four0g_tx = select;
  }
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_GFEC),
                    tmp_global_clock_disable_gfec.wrd, ctl);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE UFEC               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_clock_disable_ufec(cs_uint16 dev_id,
                                             cs_uint16 select,
                                             cs_dir_t dir,
                                             cs_ctl_t  ctl)
/* INPUTS     : o Device Id                                     */
/*              o Select                                        */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control disabling of the clock to the specified              */
/* blocks in the CS600X device.  The blocks that have clock     */
/* disable set to CS_DISABLE are inaccessible from the          */
/* microprocessor port.  After the clock disable to a block is  */
/* written from CS_DISABLE to CS_ENABLE, the software reset     */
/* APIs should be used to reset that affected block.            */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   TEN_MPIF_GLOBAL_UFEC_0   = 0x0001                          */
/*   TEN_MPIF_GLOBAL_UFEC_1   = 0x0002                          */
/*   TEN_MPIF_GLOBAL_UFEC_2   = 0x0004                          */
/*   TEN_MPIF_GLOBAL_UFEC_3   = 0x0008                          */
/*   TEN_MPIF_GLOBAL_UFEC_ALL = 0x000F                          */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   CS_DISABLE (0) to disable the specified clock(s) or        */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API   */
/*   will generate the correct sense of the bit expected by the */
/*   device.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_UFEC_t tmp_global_clock_disable_ufec;
  T41_t *pDev = NULL;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_global_clock_disable_ufec.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_ufec.bf.rx = select;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_ufec.bf.tx = select;
  }
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_UFEC),
                         tmp_global_clock_disable_ufec.wrd, ctl);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE N40G               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_clock_disable_n40g(cs_uint16 dev_id,
                                             cs_module_t module_num,
                                             cs_dir_t dir,
                                             cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control disabling of the clock to the specified              */
/* blocks in the CS600X device.  The blocks that have clock     */
/* disable set to CS_DISABLE are inaccessible from the          */
/* microprocessor port.  After the clock disable to a block is  */
/* written from CS_DISABLE to CS_ENABLE, the software reset     */
/* APIs should be used to reset that affected block.            */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   CS_DISABLE (0) to disable the specified clock(s) or        */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API   */
/*   will generate the correct sense of the bit expected by the */
/*   device.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_mpif_global_clock_disable_n40g";  

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   module_num out of range", func);
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!  dir out of range", func);
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() FAILED!   ctl = 0x%04X\n", func, ctl);
    return (CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_A_t tmp_global_clock_disable_n40g_a;
    /* set mask bits for affected selections */
    tmp_global_clock_disable_n40g_a.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_n40g_a.bf.rx40g = 1;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_n40g_a.bf.tx40g = 1;
    }
    /* perform the specified reset action */
    ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_A),
                      tmp_global_clock_disable_n40g_a.wrd, ctl);
    /* API decides how sys clock bit should be set, if both    */
    /* RX and TX are asserted, SYS should assert               */
    tmp_global_clock_disable_n40g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_A));
    tmp_global_clock_disable_n40g_a.bf.sys = (tmp_global_clock_disable_n40g_a.bf.rx40g &
                                      tmp_global_clock_disable_n40g_a.bf.tx40g);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_A), tmp_global_clock_disable_n40g_a.wrd);
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_B_t tmp_global_clock_disable_n40g_b;
    /* set mask bits for affected selections */
    tmp_global_clock_disable_n40g_b.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_n40g_b.bf.rx40g = 1;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_n40g_b.bf.tx40g = 1;
    }
    /* perform the specified reset action */
    ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_B),
                      tmp_global_clock_disable_n40g_b.wrd, ctl);
    /* API decides how sys clock bit should be set, if both    */
    /* RX and TX are asserted, SYS should assert               */
    tmp_global_clock_disable_n40g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_B));
    tmp_global_clock_disable_n40g_b.bf.sys = (tmp_global_clock_disable_n40g_b.bf.rx40g &
                                      tmp_global_clock_disable_n40g_b.bf.tx40g);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_B), tmp_global_clock_disable_n40g_b.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE N10G               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_clock_disable_n10g(cs_uint16 dev_id,
                                             cs_module_t module_num,
                                             cs_uint8 slice,
                                             cs_dir_t dir,
                                             cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control disabling of the clock to the specified              */
/* blocks in the CS600X device.  The blocks that have clock     */
/* disable set to CS_DISABLE are inaccessible from the          */
/* microprocessor port.  After the clock disable to a block is  */
/* written from CS_DISABLE to CS_ENABLE, the software reset     */
/* APIs should be used to reset that affected block.            */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   CS_DISABLE (0) to disable the specified clock(s) or        */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API   */
/*   will generate the correct sense of the bit expected by the */
/*   device.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  cs_char8 *func = "ten_mpif_global_clock_disable_n10g";  

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() module_num %d out of range", func, module_num);
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() dir %d out of range", func, dir);
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() ctl = 0x%04X out of range\n", func, ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
    CS_PRINT("%s() %s, SLICE_ALL, %s, %s\n", func, ten_module_strings[module_num], ten_dir_strings[dir], ten_ctrl_strings[ctl]);
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
    CS_PRINT("%s() %s, %s, %s, %s\n", func, ten_module_strings[module_num], ten_slice_strings[slice], ten_dir_strings[dir], ten_ctrl_strings[ctl]);
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, TEN_SLICE_ALL.", func, slice);
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_A_t tmp_global_clock_disable_n10g_a;
    TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_A_t tmp_global_clock_disable_n40g_a;
    /* set mask bits for affected selections */
    tmp_global_clock_disable_n10g_a.wrd = 0;
    tmp_global_clock_disable_n40g_a.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_n10g_a.bf.rx = tmp;
      tmp_global_clock_disable_n40g_a.bf.rx = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_n10g_a.bf.tx = tmp;
      tmp_global_clock_disable_n40g_a.bf.tx = tmp;
    }
    /* perform the specified reset action */
    ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_A),
                      tmp_global_clock_disable_n10g_a.wrd, ctl);
    ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_A),
                      tmp_global_clock_disable_n40g_a.wrd, ctl);
    /* API decides how sys reset bits should be set, if both   */
    /* RX and TX are asserted, SYS should assert               */
    tmp_global_clock_disable_n10g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_A));
    tmp_global_clock_disable_n10g_a.bf.sys = (tmp_global_clock_disable_n10g_a.bf.rx &
                                      tmp_global_clock_disable_n10g_a.bf.tx);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_A), tmp_global_clock_disable_n10g_a.wrd);
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_B_t tmp_global_clock_disable_n10g_b;
    TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_B_t tmp_global_clock_disable_n40g_b;
    /* set mask bits for affected selections */
    tmp_global_clock_disable_n10g_b.wrd = 0;
    tmp_global_clock_disable_n40g_b.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_n10g_b.bf.rx = tmp;
      tmp_global_clock_disable_n40g_b.bf.rx = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_n10g_b.bf.tx = tmp;
      tmp_global_clock_disable_n40g_b.bf.tx = tmp;
    }
    /* perform the specified reset action */
    ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_B),
                      tmp_global_clock_disable_n10g_b.wrd, ctl);
    ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_B),
                      tmp_global_clock_disable_n40g_b.wrd, ctl);
    /* API decides how sys reset bits should be set, if both   */
    /* RX and TX are asserted, SYS should assert               */
    tmp_global_clock_disable_n10g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_B));
    tmp_global_clock_disable_n10g_b.bf.sys = (tmp_global_clock_disable_n10g_b.bf.rx &
                                      tmp_global_clock_disable_n10g_b.bf.tx);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_B), tmp_global_clock_disable_n10g_b.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE N40G AND N10G      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_clock_disable_n40g_n10g(cs_uint16 dev_id,
                                             cs_module_t module_num,
                                             cs_uint8 slice,
                                             cs_uint8 datapath,
                                             cs_dir_t dir,
                                             cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Datapath Mode                                 */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Controls clock enable/disable for N40G/N10G blocks.          */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [datapath] parameter is specified as:                    */
/*   0 = TEN_MPIF_N40G_DATAPATH,                                */
/*   1 = TEN_MPIF_N10G_DATAPATH,                                */
/*   2 = TEN_MPIF_XAUI_DATAPATH                                 */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   CS_DISABLE (0) to *DISABLE* the specified clock(s) or      */
/*   CS_ENABLE (1) to *ENABLE* the specified clock(s).  The API */
/*   will generate the correct sense of the bit expected by the */
/*   device.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_A_t tmp_global_clock_disable_n40g_a;
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_N40G_B_t tmp_global_clock_disable_n40g_b;
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_B_t tmp_global_clock_disable_n10g_b;
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_N10G_A_t tmp_global_clock_disable_n10g_a;
  T41_t *pDev = NULL;
  cs_uint16 which_slices = 0;
  cs_char8 *func = "ten_mpif_global_clock_disable_n40g_n10g";  

  if (module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() module_num %d out of range", func, module_num);
    return(CS_ERROR);
  }

  if (dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() dir %d out of range", func, dir);
    return(CS_ERROR);
  }

  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() ctl = 0x%04X out of range", func, ctl);
      return (CS_ERROR);
  }

  if (datapath > TEN_MPIF_XAUI_DATAPATH) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() datapath %d out of range", func, datapath);
    return(CS_ERROR);
  }

  if (slice == TEN_SLICE_ALL) {
    which_slices = 0x000F;
      CS_PRINT("%s()  %s, SLICE_ALL, %s, %s, %s\n", func, ten_module_strings[module_num], 
                ten_mpif_n40g_n10g_strings[datapath], ten_dir_strings[dir], ten_ctrl_strings[ctl]);
  }
  else if (slice <= TEN_SLICE3) {
    which_slices = 1 << slice;
      CS_PRINT("%s()  %s, %s, %s, %s, %s\n", func, ten_module_strings[module_num], ten_slice_strings[slice], 
                ten_mpif_n40g_n10g_strings[datapath], ten_dir_strings[dir], ten_ctrl_strings[ctl]);
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, TEN_SLICE_ALL.", func, slice);
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_global_clock_disable_n40g_a.wrd=0; /* Bugzilla 30509, benign splint complaint, 4 lines */
  tmp_global_clock_disable_n40g_b.wrd=0;
  tmp_global_clock_disable_n10g_b.wrd=0;
  tmp_global_clock_disable_n10g_a.wrd=0;

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_clock_disable_n10g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_A));
    tmp_global_clock_disable_n40g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_A));
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_clock_disable_n10g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_B));
    tmp_global_clock_disable_n40g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_B));
  }

  if (datapath == TEN_MPIF_N40G_DATAPATH) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_a.bf.rx40g = 0;
          tmp_global_clock_disable_n40g_a.bf.sys   = 0;
          tmp_global_clock_disable_n40g_a.bf.rx    = 0;
          tmp_global_clock_disable_n10g_a.bf.rx    = 0;
          tmp_global_clock_disable_n10g_a.bf.sys   = 0;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_a.bf.rx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.rx    = 1;
          tmp_global_clock_disable_n10g_a.bf.rx    = 1;
        }
      }
      if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_b.bf.rx40g = 0;
          tmp_global_clock_disable_n40g_b.bf.sys   = 0;
          tmp_global_clock_disable_n40g_b.bf.rx    = 0;
          tmp_global_clock_disable_n10g_b.bf.rx    = 0;
          tmp_global_clock_disable_n10g_b.bf.sys   = 0;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_b.bf.rx40g = 1;
          tmp_global_clock_disable_n40g_b.bf.rx    = 1;
          tmp_global_clock_disable_n10g_b.bf.rx    = 1;
        }
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
     if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_a.bf.tx40g = 0;
          tmp_global_clock_disable_n40g_a.bf.sys   = 0;
          tmp_global_clock_disable_n40g_a.bf.tx    = 0;
          tmp_global_clock_disable_n10g_a.bf.tx    = 0;
          tmp_global_clock_disable_n10g_a.bf.sys   = 0;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_a.bf.tx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.tx    = 1;
          tmp_global_clock_disable_n10g_a.bf.tx    = 1;
        }
      }
      if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_b.bf.tx40g = 0;
          tmp_global_clock_disable_n40g_b.bf.sys   = 0;
          tmp_global_clock_disable_n40g_b.bf.tx    = 0;
          tmp_global_clock_disable_n10g_b.bf.tx    = 0;
          tmp_global_clock_disable_n10g_b.bf.sys   = 0;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_a.bf.tx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.tx    = 1;
          tmp_global_clock_disable_n10g_b.bf.tx    = 1;
        }
      }
    }
  }

  else if (datapath == TEN_MPIF_N10G_DATAPATH) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_a.bf.rx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.sys   = 1;
          tmp_global_clock_disable_n40g_a.bf.rx   &= ~which_slices;
          tmp_global_clock_disable_n10g_a.bf.rx   &= ~which_slices;
          tmp_global_clock_disable_n10g_a.bf.sys  &= ~which_slices;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_a.bf.rx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.rx   |= which_slices;
          tmp_global_clock_disable_n10g_a.bf.rx   |= which_slices;
        }
      }
      if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_b.bf.rx40g  = 1;
          tmp_global_clock_disable_n40g_b.bf.sys    = 1;
          tmp_global_clock_disable_n40g_b.bf.rx    &= ~which_slices;
          tmp_global_clock_disable_n10g_b.bf.rx    &= ~which_slices;
          tmp_global_clock_disable_n10g_b.bf.sys   &= ~which_slices;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_b.bf.rx40g = 1;
          tmp_global_clock_disable_n40g_b.bf.rx   |= which_slices;
          tmp_global_clock_disable_n10g_b.bf.rx   |= which_slices;
        }
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
     if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_a.bf.tx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.sys   = 1;
          tmp_global_clock_disable_n40g_a.bf.tx   &= ~which_slices;
          tmp_global_clock_disable_n10g_a.bf.tx   &= ~which_slices;
          tmp_global_clock_disable_n10g_a.bf.sys  &= ~which_slices;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_a.bf.tx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.tx   |= which_slices;
          tmp_global_clock_disable_n10g_a.bf.tx   |= which_slices;
        }
      }
      if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_b.bf.tx40g = 1;
          tmp_global_clock_disable_n40g_b.bf.sys   = 1;
          tmp_global_clock_disable_n40g_b.bf.tx   &= ~which_slices;
          tmp_global_clock_disable_n10g_b.bf.tx   &= ~which_slices;
          tmp_global_clock_disable_n10g_b.bf.sys  &= ~which_slices;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_a.bf.tx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.tx   |= which_slices;
          tmp_global_clock_disable_n10g_b.bf.tx   |= which_slices;
        }
      }
    }
  }

  else { /* TEN_MPIF_XAUI_DATAPATH */
     if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_a.bf.rx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.sys   = 1;
          tmp_global_clock_disable_n40g_a.bf.rx   |= which_slices;
          tmp_global_clock_disable_n10g_a.bf.rx   |= which_slices;
          tmp_global_clock_disable_n10g_a.bf.sys  |= which_slices;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_a.bf.rx    &= ~which_slices;
          tmp_global_clock_disable_n10g_a.bf.rx    &= ~which_slices;
        }
      }
      if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_b.bf.rx40g  = 1;
          tmp_global_clock_disable_n40g_b.bf.sys    = 1;
          tmp_global_clock_disable_n40g_b.bf.rx    |= which_slices;
          tmp_global_clock_disable_n10g_b.bf.rx    |= which_slices;
          tmp_global_clock_disable_n10g_b.bf.sys   |= which_slices;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_b.bf.rx    &= ~which_slices;
          tmp_global_clock_disable_n10g_b.bf.rx    &= ~which_slices;
        }
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
     if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_a.bf.tx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.sys   = 1;
          tmp_global_clock_disable_n40g_a.bf.tx   |= which_slices;
          tmp_global_clock_disable_n10g_a.bf.tx   |= which_slices;
          tmp_global_clock_disable_n10g_a.bf.sys  |= which_slices;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_a.bf.tx40g = 1;
          tmp_global_clock_disable_n40g_a.bf.tx    &= ~which_slices;
          tmp_global_clock_disable_n10g_a.bf.tx    &= ~which_slices;
        }
      }
      if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
        if (ctl == CS_ENABLE) {
          tmp_global_clock_disable_n40g_b.bf.tx40g = 1;
          tmp_global_clock_disable_n40g_b.bf.sys   = 1;
          tmp_global_clock_disable_n40g_b.bf.tx   |= which_slices;
          tmp_global_clock_disable_n10g_b.bf.tx   |= which_slices;
          tmp_global_clock_disable_n10g_b.bf.sys  |= which_slices;
        }
        else { /* CS_DISABLE */
          tmp_global_clock_disable_n40g_a.bf.tx  &= ~which_slices;
          tmp_global_clock_disable_n10g_b.bf.tx  &= ~which_slices;
        }
      }
    }
  }

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_A), tmp_global_clock_disable_n40g_a.wrd);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_A), tmp_global_clock_disable_n10g_a.wrd);
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N40G_B), tmp_global_clock_disable_n40g_b.wrd);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_N10G_B), tmp_global_clock_disable_n10g_b.wrd);
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE PP10G              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_clock_disable_pp10g(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_uint8 slice,
                                              cs_dir_t dir,
                                              cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control disabling of the clock to the specified              */
/* blocks in the CS600X device.  The blocks that have clock     */
/* disable set to CS_DISABLE are inaccessible from the          */
/* microprocessor port.  After the clock disable to a block is  */
/* written from CS_DISABLE to CS_ENABLE, the software reset     */
/* APIs should be used to reset that affected block.            */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter specifies the control option and is one  */
/* of the following:                                            */
/*   CS_DISABLE (0) to disable the specified clock(s) or        */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API   */
/*   will generate the correct sense of the bit expected by the */
/*   device.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A_t tmp_global_clock_disable_pp10g_a;
    /* set mask bits for affected selections */
    tmp_global_clock_disable_pp10g_a.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_pp10g_a.bf.rx = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_pp10g_a.bf.tx = tmp;
    }
    /* perform the specified reset action */
    ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP10G_A),
                      tmp_global_clock_disable_pp10g_a.wrd, ctl);
    /* API decides how sys reset bits should be set, if both   */
    /* RX and TX are asserted, SYS should assert               */
    tmp_global_clock_disable_pp10g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP10G_A));
    tmp_global_clock_disable_pp10g_a.bf.sys = (tmp_global_clock_disable_pp10g_a.bf.rx &
                                      tmp_global_clock_disable_pp10g_a.bf.tx);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP10G_A), tmp_global_clock_disable_pp10g_a.wrd);
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B_t tmp_global_clock_disable_pp10g_b;
    /* set mask bits for affected selections */
    tmp_global_clock_disable_pp10g_b.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_pp10g_b.bf.rx = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_clock_disable_pp10g_b.bf.tx = tmp;
    }
    /* perform the specified reset action */
    ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP10G_B),
                      tmp_global_clock_disable_pp10g_b.wrd, ctl);
    /* API decides how sys reset bits should be set, if both   */
    /* RX and TX are asserted, SYS should assert               */
    tmp_global_clock_disable_pp10g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP10G_B));
    tmp_global_clock_disable_pp10g_b.bf.sys = (tmp_global_clock_disable_pp10g_b.bf.rx &
                                      tmp_global_clock_disable_pp10g_b.bf.tx);
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP10G_B), tmp_global_clock_disable_pp10g_b.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL GET CLOCK DISABLE PP10G              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_mpif_global_get_clock_disable_pp10g(cs_uint16 dev_id,
                                     cs_module_t module_num,
                                     cs_dir_t dir)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value of PP10G clock disable                        */
/* DESCRIPTION:                                                     */
/* Returns value of PP10g clock disable.                            */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 rtn = CS_OK;
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_A_t tmp_global_clock_disable_pp10g_a;
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP10G_B_t tmp_global_clock_disable_pp10g_b;

  if (module_num >= TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }

  if (dir >= CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (module_num == TEN_MODULE_A) {
    tmp_global_clock_disable_pp10g_a.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP10G_A));
    if (dir == CS_RX) {
      rtn = tmp_global_clock_disable_pp10g_a.bf.rx;
    }
    else {
      rtn = tmp_global_clock_disable_pp10g_a.bf.tx;
    }
  }
  else {
    tmp_global_clock_disable_pp10g_b.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP10G_B));
    if (dir == CS_RX) {
      rtn = tmp_global_clock_disable_pp10g_b.bf.rx;
    }
    else {
      rtn = tmp_global_clock_disable_pp10g_b.bf.tx;
    }
  }
  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT HSIF OUT                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_clock_select_hsif_out(cs_uint16 dev_id,
                                         cs_module_t module_num,
                                         cs_uint8 slice,
                                         cs_dir_t dir,
                                         cs_ctl_t select)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Selects between the HSIF output clocks.  This is the 1st     */
/* stage of top level clock muxing.                             */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   selects the MR SERDES clock out of HSIF                    */
/*   0 = For RXA, selects Module A MR SERDES RX clock.          */
/*       For TXA, selects Module A MR SERDES TX clock.          */
/*       For RXB, selects Module B MR SERDES RX clock.          */
/*       For TXB, selects Module B MR SERDES TX clock.          */
/*   1 = For RXA, selects Module B MR SERDES RX clock. This     */
/*       option may be used in MR SERDES protection switching   */
/*       mode.                                                  */
/*       For TXA, selects Module B MR SERDES TX clock. This     */
/*       option may be used in MR SERDES protection switching   */
/*       mode.                                                  */
/*       For RXB, selects Module B XFI SERDES RX clock.         */
/*       For TXB, selects Module B XFI SERDES TX clock.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_CLOCK_SELECT_HSIF_OUT_t tmp_clock_select_hsif_out;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if (select > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": select = 0x%04X\n", select);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_select_hsif_out.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_HSIF_OUT));

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    /* set mask bits for affected selections */
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_hsif_out.bf.rxa |= tmp;
      }
      else {
        tmp_clock_select_hsif_out.bf.rxa &= ~tmp;
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_hsif_out.bf.txa |= tmp;
      }
      else {
        tmp_clock_select_hsif_out.bf.txa &= ~tmp;
      }
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    /* set mask bits for affected selections */
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_hsif_out.bf.rxb |= tmp;
      }
      else {
        tmp_clock_select_hsif_out.bf.rxb &= ~tmp;
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_hsif_out.bf.txb |= tmp;
      }
      else {
        tmp_clock_select_hsif_out.bf.txb &= ~tmp;
      }
    }
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_HSIF_OUT), tmp_clock_select_hsif_out.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT GPLL IN                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_clock_select_gpll_in(cs_uint16 dev_id,
                                         cs_module_t module_num,
                                         cs_uint8 slice,
                                         cs_dir_t dir,
                                         cs_ctl_t select)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Selects between the HSIF output clocks.  This is the 1st     */
/* stage of top level clock muxing.                             */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   0 = For tx fields, selects the GPLL internal reference     */
/*       clock source as the clock selected by                  */
/*       MPIF_CLOCK_SELECT_HSIF_OUT.tx. For rx fields, selects  */
/*       the GPLL internal reference clock source as the clock  */
/*       selected by MPIF_CLOCK_SELECT_HSIF_OUT.rx.             */
/*   1 = For tx fields, selects the GPLL internal reference     */
/*       clock source as the clock selected by                  */
/*       MPIF_CLOCK_SELECT_HSIF_OUT.rx. For rx fields, selects  */
/*       the GPLL internal reference clock source as the clock  */
/*       selected by MPIF_CLOCK_SELECT_HSIF_OUT.tx.             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_CLOCK_SELECT_GPLL_IN_t tmp_clock_select_gpll_in;
  cs_char8 *func = "ten_mpif_clock_select_gpll_in";  

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() module_num out of range", func);
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() dir out of range", func);
    return(CS_ERROR);
  }
  if (select > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() select = 0x%04X\n", func, select);
      return (CS_ERROR);
  }

  CS_PRINT("%s() %s, ", func, ten_module_strings[module_num&1]);
  if (slice == TEN_SLICE_ALL) {
    CS_PRINT("SLICE_ALL");
  } else {
    CS_PRINT("%s", ten_slice_strings[slice]);
  }
  CS_PRINT(", %s, select=%d\n", ten_dir_strings[dir], select);

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_select_gpll_in.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_GPLL_IN));

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    /* set mask bits for affected selections */
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_gpll_in.bf.rxa |= tmp;
      }
      else {
        tmp_clock_select_gpll_in.bf.rxa &= ~tmp;
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_gpll_in.bf.txa |= tmp;
      }
      else {
        tmp_clock_select_gpll_in.bf.txa &= ~tmp;
      }
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    /* set mask bits for affected selections */
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_gpll_in.bf.rxb |= tmp;
      }
      else {
        tmp_clock_select_gpll_in.bf.rxb &= ~tmp;
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_gpll_in.bf.txb |= tmp;
      }
      else {
        tmp_clock_select_gpll_in.bf.txb &= ~tmp;
      }
    }
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_GPLL_IN), tmp_clock_select_gpll_in.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT GPLL OUT                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_clock_select_gpll_out(cs_uint16 dev_id,
                                         cs_module_t module_num,
                                         cs_uint8 slice,
                                         cs_dir_t dir,
                                         cs_ctl_t select)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Selects between the HSIF output clocks.  This is the 1st     */
/* stage of top level clock muxing.                             */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   0 = For tx fields, selects the TX  datapath source as the  */
/*       GPLL internal reference clock selected by              */
/*       CLOCK_SELECT_GPLL_IN.tx. For rx fields, selects the RX */
/*       datapath source as the GPLL internal reference clock   */
/*       selected by CLOCK_SELECT_GPLL_IN.rx.                   */
/*   1 = For tx fields, selects the TX datapath source as the   */
/*       TX GPLL output clock. For rx fields, selects the RX    */
/*       datapath source as the RX GPLL output clock.           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_CLOCK_SELECT_GPLL_OUT_t tmp_clock_select_gpll_out;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if (select > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": select = 0x%04X\n", select);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_select_gpll_out.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_GPLL_OUT));

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    /* set mask bits for affected selections */
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_gpll_out.bf.rxa |= tmp;
      }
      else {
        tmp_clock_select_gpll_out.bf.rxa &= ~tmp;
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_gpll_out.bf.txa |= tmp;
      }
      else {
        tmp_clock_select_gpll_out.bf.txa &= ~tmp;
      }
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    /* set mask bits for affected selections */
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_gpll_out.bf.rxb |= tmp;
      }
      else {
        tmp_clock_select_gpll_out.bf.rxb &= ~tmp;
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_gpll_out.bf.txb |= tmp;
      }
      else {
        tmp_clock_select_gpll_out.bf.txb &= ~tmp;
      }
    }
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_GPLL_OUT), tmp_clock_select_gpll_out.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT 40G                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_clock_select_40g(cs_uint16 dev_id,
                                    cs_uint16 txb,
                                    cs_uint16 rxb,
                                    cs_uint16 txa,
                                    cs_uint16 rxa)
/* INPUTS     : o Device Id                                         */
/*              o Txb                                               */
/*              o Rxb                                               */
/*              o Txa                                               */
/*              o Rxa                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects 40G clocking mode.  After the clock selects are          */
/* modified, the software reset APIs should be applied to the       */
/* affected blocks.                                                 */
/*                                                                  */
/* The [txb] parameter is specified as:                             */
/*   0 = selects the TX Module B datapath source to be 4            */
/*       independent 10G clocks.                                    */
/*   1 = selects the TX Module B datapath source to be the single   */
/*       40G RX clock.                                              */
/*                                                                  */
/* The [rxb] parameter is specified as:                             */
/*   0 = selects the RX Module B datapath source to be 4            */
/*       independent 10G clocks.                                    */
/*   1 = selects the RX Module B datapath source to be the single   */
/*       40G RX clock.                                              */
/*                                                                  */
/* The [txa] parameter is specified as:                             */
/*   0 = selects the TX Module A datapath source to be 4            */
/*       independent 10G clocks.                                    */
/*   1 = selects the TX Module A datapath source to be the single   */
/*       40G RX clock.                                              */
/*                                                                  */
/* The [rxa] parameter is specified as:                             */
/*   0 = selects the RX Module A datapath source to be 4            */
/*       independent 10G clocks.                                    */
/*   1 = selects the RX Module A datapath source to be the single   */
/*       40G RX clock.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SELECT_40G_t tmp_clock_select_40g;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_clock_select_40g.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_40G));
  tmp_clock_select_40g.bf.txb = txb;
  tmp_clock_select_40g.bf.rxb = rxb;
  tmp_clock_select_40g.bf.txa = txa;
  tmp_clock_select_40g.bf.rxa = rxa;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_40G), tmp_clock_select_40g.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT 40G PER MODULE                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_clock_select_40g_per_module(cs_uint16 dev_id,
                                               cs_module_t module_num,
                                               cs_uint16 tx,
                                               cs_uint16 rx)
/* INPUTS     : o Device Id                                         */
/*              o Tx                                               */
/*              o Rx                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects 40G clocking mode.  After the clock selects are          */
/* modified, the software reset APIs should be applied to the       */
/* affected blocks.                                                 */
/*                                                                  */
/* The [txb] parameter is specified as:                             */
/*   0 = selects the TX Module datapath source to be 4              */
/*       independent 10G clocks.                                    */
/*   1 = selects the TX Module datapath source to be the single     */
/*       40G RX clock.                                              */
/*                                                                  */
/* The [rxb] parameter is specified as:                             */
/*   0 = selects the RX Module datapath source to be 4              */
/*       independent 10G clocks.                                    */
/*   1 = selects the RX Module datapath source to be the single     */
/*       40G RX clock.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SELECT_40G_t tmp_clock_select_40g;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_clock_select_40g.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_40G));


  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_clock_select_40g.bf.txa = tx;
    tmp_clock_select_40g.bf.rxa = rx;
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_clock_select_40g.bf.txb = tx;
    tmp_clock_select_40g.bf.rxb = rx;
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_40G), tmp_clock_select_40g.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT PROT                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_clock_select_prot(cs_uint16 dev_id,
                                     cs_uint16 tx_40g_prot,
                                     cs_uint16 rx_40g_prot,
                                     cs_uint16 tx_a2b,
                                     cs_uint16 rx_a2b)
/* INPUTS     : o Device Id                                         */
/*              o Tx 40G Protection                                 */
/*              o Rx 40G Protection                                 */
/*              o Tx A2b                                            */
/*              o Rx A2b                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Overrides the clock source selection to TX Module B HSIF block   */
/* when in protection mode.                                         */
/* After the clock selects are modified, the software reset APIs    */
/* should be applied to the affected blocks.                        */
/*                                                                  */
/* The [tx_40g_prot] parameter is specified as:                     */
/*   0 = TX Module B clocking is not affected.                      */
/*   1 = sets the TX Module B HSIF clocking to 40G mode.            */
/*                                                                  */
/* The [rx_40g_prot] parameter is specified as:                     */
/*   0 = RX Module B clocking is not affected.                      */
/*   1 = sets the RX Module B HSIF clocking to 40G mode.            */
/*                                                                  */
/* The [tx_a2b] parameter is specified as:                          */
/*   tx_a2b[3:0]                                                    */
/*   0 = TX Module B clocking is not affected.                      */
/*   1 = selects the A side TX GPLL output as the clock to the      */
/*       multi-rate section of the HSIF TX on the B side.           */
/*                                                                  */
/* The [rx_a2b] parameter is specified as:                          */
/*   rx_a2b[3:0]                                                    */
/*   0 = RX Module B clocking is not affected.                      */
/*   1 = selects the A side RX GPLL output as the clock to the      */
/*       multi-rate section of the HSIF RX on the B side.           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SELECT_PROT_t tmp_clock_select_prot;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_clock_select_prot.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PROT));
  tmp_clock_select_prot.bf.tx_40g_prot = tx_40g_prot;
  tmp_clock_select_prot.bf.rx_40g_prot = rx_40g_prot;
  tmp_clock_select_prot.bf.tx_a2b = tx_a2b;
  tmp_clock_select_prot.bf.rx_a2b = rx_a2b;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PROT), tmp_clock_select_prot.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT PROT 40G                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_clock_select_prot_40g(cs_uint16 dev_id,
                                         cs_uint16 tx_40g_prot,
                                         cs_uint16 rx_40g_prot)
/* INPUTS     : o Device Id                                         */
/*              o Tx 40G Protection                                 */
/*              o Rx 40G Protection                                 */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Overrides the clock source selection to TX Module B HSIF block   */
/* when in protection mode.                                         */
/* After the clock selects are modified, the software reset APIs    */
/* should be applied to the affected blocks.                        */
/*                                                                  */
/* The [tx_40g_prot] parameter is specified as:                     */
/*   0 = TX Module B clocking is not affected.                      */
/*   1 = sets the TX Module B HSIF clocking to 40G mode.            */
/*                                                                  */
/* The [rx_40g_prot] parameter is specified as:                     */
/*   0 = RX Module B clocking is not affected.                      */
/*   1 = sets the RX Module B HSIF clocking to 40G mode.            */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SELECT_PROT_t tmp_clock_select_prot;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_clock_select_prot.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PROT));
  tmp_clock_select_prot.bf.tx_40g_prot = tx_40g_prot;
  tmp_clock_select_prot.bf.rx_40g_prot = rx_40g_prot;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PROT), tmp_clock_select_prot.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT PROT PER SLICE             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_clock_select_prot_per_slice(cs_uint16 dev_id,
                                               cs_module_t module_num,
                                               cs_uint8 slice,
                                               cs_dir_t dir,
                                               cs_ctl_t select)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Selects between the HSIF output clocks.  This is the 1st     */
/* stage of top level clock muxing.                             */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   tx_a2b[3:0]                                                */
/*   0 = TX Module B clocking is not affected.                  */
/*   1 = selects the A side TX GPLL output as the clock to the  */
/*       multi-rate section of the HSIF TX on the B side.       */
/*                                                              */
/*   rx_a2b[3:0]                                                */
/*   0 = RX Module B clocking is not affected.                  */
/*   1 = selects the A side RX GPLL output as the clock to the  */
/*       multi-rate section of the HSIF RX on the B side.       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_CLOCK_SELECT_PROT_t tmp_clock_select_prot;

  if (module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num out of range");
    return (CS_ERROR);
  }

  if (dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (CS_ERROR);
  }

  if (select > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": select = 0x%04X\n", select);
      return (CS_ERROR);
  }

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x00FF;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_select_prot.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PROT));

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    /* set mask bits for affected selections */
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (select) {
        tmp_clock_select_prot.bf.rx_a2b |= tmp;
      }
      else {
        tmp_clock_select_prot.bf.rx_a2b &= ~tmp;
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (select) {
        tmp_clock_select_prot.bf.tx_a2b |= tmp;
      }
      else {
        tmp_clock_select_prot.bf.tx_a2b &= ~tmp;
      }
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    /* set mask bits for affected selections */
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (select) {
        tmp_clock_select_prot.bf.rx_a2b |= tmp;
      }
      else {
        tmp_clock_select_prot.bf.rx_a2b &= ~tmp;
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (select) {
        tmp_clock_select_prot.bf.tx_a2b |= tmp;
      }
      else {
        tmp_clock_select_prot.bf.tx_a2b &= ~tmp;
      }
    }
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PROT), tmp_clock_select_prot.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SELECT PROT                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_select_prot(cs_uint16 dev_id,
                                         cs_dir_t dir)
/* INPUTS     : o Dev Id                                            */
/*              o Select                                            */
/*              o Dir                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* Returns the provisioned clock select prot.                       */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..3                                            */
/*                                                                  */
/*   [dir] parameter is specified as:                               */
/*     0 = CS_TX                                                    */
/*     1 = CS_RX                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SELECT_PROT_t tmp_clock_select_prot;
  T41_t *pDev = NULL;

  if ((dir != CS_RX) && (dir != CS_TX)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range.  s/b 0..1.");
    return (0);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_clock_select_prot.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PROT));
  if (dir == CS_TX) {
    return (tmp_clock_select_prot.bf.tx_a2b);
  }
  else {
    return (tmp_clock_select_prot.bf.rx_a2b);
  }
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT SYS                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_clock_select_sys(cs_uint16 dev_id,
                                    cs_uint16 bypass)
/* INPUTS     : o Device Id                                         */
/*              o Bypass                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Bypasses the System Clock GPLL.                                  */
/* After the clock selects are modified, the software reset APIs    */
/* should be applied to the affected blocks.                        */
/*                                                                  */
/* The [bypass] parameter is specified as:                          */
/*   0 = the internal system clock GPLL output is the source for    */
/*       the internal system clock domain; SYS_REFCK_P/N is the     */
/*       reference clock for the system clock GPLL.                 */
/*   1 = the SYS_REFCK_P/N input clock is the source for the        */
/*       internal system clock domain.                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SELECT_SYS_t tmp_clock_select_sys;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_clock_select_sys.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_SYS));
  tmp_clock_select_sys.bf.bypass = bypass;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_SYS), tmp_clock_select_sys.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GFEC CFG PORT 2 THROUGH 4                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_gfec_cfg_port2_4(cs_uint16 dev_id,
                                    cs_uint16 module_num,
                                    cs_uint16 slice)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the datapath association and clocks source to the GFEC   */
/* blocks for ports 2 through 4.                                    */
/* After the clock selects are modified, the software reset APIs    */
/* should be applied to the affected blocks.                        */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   TEN_MODULE_A (0) or TEN_MODULE_B. (1)                          */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0 = TEN_SLICE0 (10G)                                           */
/*   1 = TEN_SLICE1 (10G)                                           */
/*   2 = TEN_SLICE2 (10G)                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GFEC_CFG_t tmp_gfec_cfg;
  T41_t *pDev = NULL;

  if (module_num > TEN_MAX_NUM_MODULES) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num > TEN_MODULE_B");
    return CS_ERROR;
  }
  if (slice > TEN_SLICE2) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": slice > TEN_SLICE2");
    return CS_ERROR;
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_gfec_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GFEC_CFG));

  if(slice == TEN_SLICE0) {
    if(module_num == TEN_MODULE_A) {
      tmp_gfec_cfg.bf.tx_b &= ~0x01;
      tmp_gfec_cfg.bf.rx_b &= ~0x01;
    }
    else {
      tmp_gfec_cfg.bf.tx_b |= 0x01;
      tmp_gfec_cfg.bf.rx_b |= 0x01;
    }
  }

  if(slice == TEN_SLICE1) {
    if(module_num == TEN_MODULE_A) {
      tmp_gfec_cfg.bf.tx_b &= ~(0x01 << 1);
      tmp_gfec_cfg.bf.rx_b &= ~(0x01 << 1);
    }
    else {
      tmp_gfec_cfg.bf.tx_b |= (0x01 << 1);
      tmp_gfec_cfg.bf.rx_b |= (0x01 << 1);
    }
  }

  if(slice == TEN_SLICE2) {
    if(module_num == TEN_MODULE_A) {
      tmp_gfec_cfg.bf.tx_b &= ~(0x01 << 2);
      tmp_gfec_cfg.bf.rx_b &= ~(0x01 << 2);
    }
    else {
      tmp_gfec_cfg.bf.tx_b |= (0x01 << 2);
      tmp_gfec_cfg.bf.rx_b |= (0x01 << 2);
    }
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GFEC_CFG), tmp_gfec_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GFEC CFG PORT 1                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_gfec_cfg_port1(cs_uint16 dev_id,
                                  cs_uint16 module_num,
                                  cs_uint16 mode)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Mode                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the datapath association and clocks source to the GFEC   */
/* blocks for port 1.                                               */
/* After the clock selects are modified, the software reset APIs    */
/* should be applied to the affected blocks.                        */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   TEN_MODULE_A (0) or TEN_MODULE_B. (1)                          */
/*                                                                  */
/* The [mode] parameter is specified as:                            */
/*   0 = TEN_SLICE_10G                                              */
/*   1 = TEN_SLICE_40G                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GFEC_CFG_t tmp_gfec_cfg;
  T41_t *pDev = NULL;

  if (module_num > TEN_MAX_NUM_MODULES) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num > TEN_MODULE_B");
    return CS_ERROR;
  }
  if (mode > TEN_SLICE_40G) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": mode > TEN_SLICE_40G");
    return CS_ERROR;
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_gfec_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GFEC_CFG));

  if(module_num == TEN_MODULE_A) {
    if(mode == TEN_SLICE_10G) {
      tmp_gfec_cfg.bf.rxa_10g = 1;
      tmp_gfec_cfg.bf.txa_10g = 1;
    }
    else {
      tmp_gfec_cfg.bf.rxa_10g = 0;
      tmp_gfec_cfg.bf.txa_10g = 0;
    }
  }
  else { /* TEN_MODULE_B */
    if(mode == TEN_SLICE_10G) {
      tmp_gfec_cfg.bf.rxb_10g = 1;
      tmp_gfec_cfg.bf.txb_10g = 1;
    }
    else {
      tmp_gfec_cfg.bf.rxb_10g = 0;
      tmp_gfec_cfg.bf.txb_10g = 0;
    }
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GFEC_CFG), tmp_gfec_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF UFEC CFG                                    */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_ufec_cfg(cs_uint16 dev_id,
                            cs_uint16 module_num,
                            cs_uint16 slice,
                            cs_uint16 mode)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Mode                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the datapath association and clocks source to the UFEC   */
/* blocks.                                                          */
/* After the clock selects are modified, the software reset APIs    */
/* should be applied to the affected blocks.                        */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   TEN_MODULE_A (0) or TEN_MODULE_B. (1)                          */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0 = TEN_SLICE0 (10G/40G)                                       */
/*   1 = TEN_SLICE1 (10G)                                           */
/*   2 = TEN_SLICE2 (10G)                                           */
/*   3 = TEN_SLICE3 (10G)                                           */
/*                                                                  */
/* The [mode] parameter is specified as:                            */
/*   0 = TEN_SLICE_10G                                              */
/*   1 = TEN_SLICE_40G                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_UFEC_CFG_t tmp_ufec_cfg;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_ufec_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, UFEC_CFG));

  if(module_num == TEN_MODULE_A) {
    /* Set UFEC on side A */
    if(slice == TEN_SLICE0) {
      tmp_ufec_cfg.bf.tx_b &= ~0x01;
      tmp_ufec_cfg.bf.rx_b &= ~0x01;
    }
    else if(slice == TEN_SLICE1) {
      tmp_ufec_cfg.bf.tx_b &= ~(0x01 << 1);
      tmp_ufec_cfg.bf.rx_b &= ~(0x01 << 1);
    }
    else if(slice == TEN_SLICE2) {
      tmp_ufec_cfg.bf.tx_b &= ~(0x01 << 2);
      tmp_ufec_cfg.bf.rx_b &= ~(0x01 << 2);
    }
    else if(slice == TEN_SLICE3) {
      tmp_ufec_cfg.bf.tx_b &= ~(0x01 << 3);
      tmp_ufec_cfg.bf.rx_b &= ~(0x01 << 3);
    }

    /* Set UFEC type */
    if(mode == TEN_SLICE_10G) {
      tmp_ufec_cfg.bf.rx1_10g = 1;
      tmp_ufec_cfg.bf.tx1_10g = 1;
    }
    else {
      tmp_ufec_cfg.bf.rx1_10g = 0;
      tmp_ufec_cfg.bf.tx1_10g = 0;
    }
  }
  else { /* TEN_MODULE_B */
    /* Set UFEC on side A */
    if(slice == TEN_SLICE0) {
      tmp_ufec_cfg.bf.tx_b |= 0x01;
      tmp_ufec_cfg.bf.rx_b |= 0x01;
    }
    else if(slice == TEN_SLICE1) {
      tmp_ufec_cfg.bf.tx_b |= (0x01 << 1);
      tmp_ufec_cfg.bf.rx_b |= (0x01 << 1);
    }
    else if(slice == TEN_SLICE2) {
      tmp_ufec_cfg.bf.tx_b |= (0x01 << 2);
      tmp_ufec_cfg.bf.rx_b |= (0x01 << 2);
    }
    else if(slice == TEN_SLICE3) {
      tmp_ufec_cfg.bf.tx_b |= (0x01 << 3);
      tmp_ufec_cfg.bf.rx_b |= (0x01 << 3);
    }

    /* Set UFEC type */
    if(mode == TEN_SLICE_10G) {
      tmp_ufec_cfg.bf.rx2_10g = 1;
      tmp_ufec_cfg.bf.tx2_10g = 1;
    }
    else {
      tmp_ufec_cfg.bf.rx2_10g = 0;
      tmp_ufec_cfg.bf.tx2_10g = 0;
    }
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, UFEC_CFG), tmp_ufec_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF RXCLK REFOUT                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_rxclk_refout(cs_uint16 dev_id,
                                cs_uint16 div,
                                cs_uint16 select)
/* INPUTS     : o Device Id                                         */
/*              o Div                                               */
/*              o Select                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set the RX Clock Reference Output Configuration.                 */
/*                                                                  */
/* The [div] parameter is specified as:                             */
/*   div[2:0]                                                       */
/*   Divide Ratio for the selected RXCLK_REFOUT output.             */
/*   0 = Divide by 2                                                */
/*   1 = Divide by 4                                                */
/*   2 = Divide by 8                                                */
/*   3 = Divide by 16                                               */
/*   4 = Divide by 32                                               */
/*   5 = Divide by 64                                               */
/*   6 = Divide by 128                                              */
/*   7 = Divide by 1                                                */
/*                                                                  */
/* The [select] parameter is specified as:                          */
/*   select[2:0]                                                    */
/*   Source Selection for RXCLK_REFOUT output.                      */
/*   0 = RX Module A GPLL #1 output clock                           */
/*   1 = RX Module A GPLL #2 output clock                           */
/*   2 = RX Module A GPLL #3 output clock                           */
/*   3 = RX Module A GPLL #4 output clock                           */
/*   4 = RX Module B GPLL #1 output clock                           */
/*   5 = RX Module B GPLL #2 output clock                           */
/*   6 = RX Module B GPLL #3 output clock                           */
/*   7 = RX Module B GPLL #4 output clock                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_RXCLK_REFOUT_t tmp_rxclk_refout;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_rxclk_refout.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXCLK_REFOUT));
  tmp_rxclk_refout.bf.div = div;
  tmp_rxclk_refout.bf.select = select;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXCLK_REFOUT), tmp_rxclk_refout.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF PRBS SYNC                                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_prbs_sync(cs_uint16 dev_id,
                             cs_uint16 txb,
                             cs_uint16 rxb,
                             cs_uint16 txa,
                             cs_uint16 rxa)
/* INPUTS     : o Device Id                                         */
/*              o Txb                                               */
/*              o Rxb                                               */
/*              o Txa                                               */
/*              o Rxa                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the source for the PRBS synchronization event output     */
/* signals.  These output signals toggle when the selected PRBS     */
/* feedback registers are set to all "1".                           */
/*                                                                  */
/* The [txb] parameter is specified as:                             */
/*   txb[2:0]                                                       */
/*   Source Selection for PRBSTXB output pin.                       */
/*   0   = PRBS Sync Event TX N40G Module B                         */
/*   1   = PRBS Sync Event TX N10G #1 Module B                      */
/*   2   = PRBS Sync Event TX N10G #2 Module B                      */
/*   3   = PRBS Sync Event TX N10G #2 Module B                      */
/*   4   = PRBS Sync Event TX N10G #4 Module B                      */
/*   5-7 = invalid                                                  */
/*                                                                  */
/* The [rxb] parameter is specified as:                             */
/*   rxb[2:0]                                                       */
/*   Source Selection for PRBSRXB output pin.                       */
/*   0   = PRBS Sync Event RX N40G Module B                         */
/*   1   = PRBS Sync Event RX N10G #1 Module B                      */
/*   2   = PRBS Sync Event RX N10G #2 Module B                      */
/*   3   = PRBS Sync Event RX N10G #2 Module B                      */
/*   4   = PRBS Sync Event RX N10G #4 Module B                      */
/*   5-7 = invalid                                                  */
/*                                                                  */
/* The [txa] parameter is specified as:                             */
/*   txa[2:0]                                                       */
/*   Source Selection for PRBSTXA output pin.                       */
/*   0   = PRBS Sync Event TX N40G Module A                         */
/*   1   = PRBS Sync Event TX N10G #1 Module A                      */
/*   2   = PRBS Sync Event TX N10G #2 Module A                      */
/*   3   = PRBS Sync Event TX N10G #2 Module A                      */
/*   4   = PRBS Sync Event TX N10G #4 Module A                      */
/*   5-7 = invalid                                                  */
/*                                                                  */
/* The [rxa] parameter is specified as:                             */
/*   rxa[2:0]                                                       */
/*   Source Selection for PRBSRXA output pin.                       */
/*   0   = PRBS Sync Event RX N40G Module A                         */
/*   1   = PRBS Sync Event RX N10G #1 Module A                      */
/*   2   = PRBS Sync Event RX N10G #2 Module A                      */
/*   3   = PRBS Sync Event RX N10G #2 Module A                      */
/*   4   = PRBS Sync Event RX N10G #4 Module A                      */
/*   5-7 = invalid                                                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_PRBS_SYNC_t tmp_prbs_sync;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_prbs_sync.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PRBS_SYNC));
  tmp_prbs_sync.bf.txb = txb;
  tmp_prbs_sync.bf.rxb = rxb;
  tmp_prbs_sync.bf.txa = txa;
  tmp_prbs_sync.bf.rxa = rxa;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, PRBS_SYNC), tmp_prbs_sync.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF SCRATCH PAD1                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_scratch_pad1(cs_uint16 dev_id,
                            cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes to Scratch Pad Register #1.                               */
/*                                                                  */
/* The [value] parameter is specified as 0 - FFFF hex.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_SCRATCH_PAD1_t tmp_scratch_pad1;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_scratch_pad1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SCRATCH_PAD1));
  tmp_scratch_pad1.bf.value = value;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, SCRATCH_PAD1), tmp_scratch_pad1.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF READ SCRATCH PAD1                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_read_scratch_pad1(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value (16 bit)                                      */
/* DESCRIPTION:                                                     */
/* Reads Scratch Pad Register #1.                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_SCRATCH_PAD1_t tmp_scratch_pad1;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_scratch_pad1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SCRATCH_PAD1));

  return (tmp_scratch_pad1.wrd);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF SCRATCH PAD2                                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_scratch_pad2(cs_uint16 dev_id,
                            cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes to Scratch Pad Register #2.                               */
/*                                                                  */
/* The [value] parameter is specified as 0 - FFFF hex.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_SCRATCH_PAD2_t tmp_scratch_pad2;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_scratch_pad2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SCRATCH_PAD2));
  tmp_scratch_pad2.bf.value = value;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, SCRATCH_PAD2), tmp_scratch_pad2.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF READ SCRATCH PAD2                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_read_scratch_pad2(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value (16 bit)                                      */
/* DESCRIPTION:                                                     */
/* Reads Scratch Pad Register #2.                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_SCRATCH_PAD2_t tmp_scratch_pad2;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_scratch_pad2.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, SCRATCH_PAD2));

  return (tmp_scratch_pad2.wrd);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GPIO DIRECTION                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_gpio_direction(cs_uint16 dev_id,
                                  cs_uint16 map,
                                  cs_uint16 mask)
/* INPUTS     : o Device Id                                         */
/*              o Map                                               */
/*              o Mask                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This configures the GPIO pins on the chip. There are 16 pins     */
/* which can be configured to be either input or output.            */
/*                                                                  */
/* The [map] parameter specifies:                                   */
/*   16-bit I/O map (0=input, 1=output)                             */
/*                                                                  */
/* The [mask] parameter specifies:                                  */
/*   16-bit Mask (0=don't change, 1=change config).                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GPIO_DIRECTION_t tmp_gpio_direction;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_gpio_direction.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_DIRECTION));
  tmp_gpio_direction.wrd = (tmp_gpio_direction.wrd & ~mask) | (map & mask);
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GPIO_DIRECTION), tmp_gpio_direction.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GPIO CCFP                                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_gpio_ccfp(cs_uint16 dev_id,
                             cs_uint16 en)
/* INPUTS     : o Device Id                                         */
/*              o En                                                */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Enables the Communications Channel Frame Pulses to be output     */
/* on the GPIO pins.                                                */
/* GPIO_DIRECTION is automaticaly configured to set enabled pins    */
/* to output.                                                       */
/*                                                                  */
/* The [en] parameter is specified as 0 - FFFF hex.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GPIO_CCFP_t tmp_gpio_ccfp;
  TEN_MPIF_GPIO_DIRECTION_t tmp_gpio_direction;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_gpio_direction.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_DIRECTION));
  tmp_gpio_direction.wrd |= en;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GPIO_DIRECTION), tmp_gpio_direction.wrd);

  tmp_gpio_ccfp.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_CCFP));
  tmp_gpio_ccfp.bf.en = en;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GPIO_CCFP), tmp_gpio_ccfp.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GPIO OUTPUT                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_gpio_output(cs_uint16 dev_id, cs_uint16 data,
                               cs_uint16 mask)
/* INPUTS     : o Device Id                                         */
/*              o Data                                              */
/*              o Bit Mask                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Writes a 1 or 0 to the GPIO output pin. The data is bit-map      */
/* corresponding to the 16 GPIO pins.                               */
/*                                                                  */
/* The [data] parameter specifies:                                  */
/*   Value of Data to be output on the pins                         */
/*                                                                  */
/* The [mask] parameter specifies:                                  */
/*   Bit-mask (0=don't change, 1=change output).                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GPIO_OUTPUT_t tmp_gpio_output;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_gpio_output.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_OUTPUT));
  tmp_gpio_output.bf.o = (tmp_gpio_output.wrd & ~mask) | (data & mask);
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, GPIO_OUTPUT), tmp_gpio_output.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GPIO SAMPLE                                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_gpio_sample(cs_uint16 dev_id, cs_uint16 mask)
/* INPUTS     : o Device Id                                         */
/*              o Bit Mask                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Sample Value (16 bits)                              */
/* DESCRIPTION:                                                     */
/* This reads (samples) the GPIO input pins. The [mask]             */
/* parameter specifies which input pins to be read from (the        */
/* others are masked out and the value returned has 0's for         */
/* those bits.                                                      */
/*                                                                  */
/* The [mask] parameter specifies:                                  */
/*   Bit-mask (0 - mask off, 1 - input pin).                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GPIO_SAMPLE_t tmp_gpio_sample;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);
  tmp_gpio_sample.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GPIO_SAMPLE));
  return (tmp_gpio_sample.wrd & mask);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SDS MR                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_sds_mr(cs_uint16 dev_id,
                                       cs_module_t module_num,
                                       cs_uint8 slice,
                                       cs_dir_t dir,
                                       cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
  TEN_MPIF_GLOBAL_RESET_SDS_MRA_t tmp_global_reset_sds_mra;
    /* set mask bits for affected selections */
    tmp_global_reset_sds_mra.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_sds_mra.bf.rx = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_sds_mra.bf.tx = tmp;
    }
    /* perform the specified reset action */
    ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_MRA),
                     tmp_global_reset_sds_mra.wrd, act);
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
  TEN_MPIF_GLOBAL_RESET_SDS_MRB_t tmp_global_reset_sds_mrb;
    /* set mask bits for affected selections */
    tmp_global_reset_sds_mrb.wrd = 0;
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_sds_mrb.bf.rx = tmp;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_sds_mrb.bf.tx = tmp;
    }
    /* perform the specified reset action */
    ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_MRB),
                     tmp_global_reset_sds_mrb.wrd, act);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GET GLOBAL RESET SDS MR                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_global_reset_sds_mr(cs_uint16 dev_id,
                                           cs_module_t module_num,
                                           cs_uint8 slice,
                                           cs_dir_t dir)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 1=hard reset, 0 not in hard reset               */
/* DESCRIPTION:                                                 */
/* Returns the current state of hard reset for the specified    */
/* selection.                                                   */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_SDS_MRA_t tmp_global_reset_sds_mra;
  TEN_MPIF_GLOBAL_RESET_SDS_MRB_t tmp_global_reset_sds_mrb;

  if (module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "module_num out of range");
    return (0);
  }
  if (dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "dir out of range");
    return (0);
  }
  if (slice > TEN_SLICE3) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "slice out of range");
    return (0);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (module_num == TEN_MODULE_A) {
    tmp_global_reset_sds_mra.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_MRA));
    if (dir == CS_TX) {
      tmp = 1 << slice;
      CS_PRINT("slice=%d, tmp=%04X\n", slice, tmp);
      if (tmp_global_reset_sds_mra.bf.tx & tmp) {
        CS_PRINT("MPIF_GLOBAL_RESET_SDS_MRA.bf.tx in hard reset\n");
        return (1);
      }
    }
    else {
      tmp = 1 << slice;
      CS_PRINT("slice=%d, tmp=%04X\n", slice, tmp);
      if (tmp_global_reset_sds_mra.bf.rx & tmp) {
        CS_PRINT("MPIF_GLOBAL_RESET_SDS_MRA.bf.rx in hard reset\n");
        return (1);
      }
    
    }
  }
 
  if (module_num == TEN_MODULE_B) {
    tmp_global_reset_sds_mrb.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_MRB));
    if (dir == CS_TX) {
      tmp = 1 << slice;
      CS_PRINT("slice=%d, tmp=%04X\n", slice, tmp);
      if (tmp_global_reset_sds_mrb.bf.tx & tmp) {
        CS_PRINT("MPIF_GLOBAL_RESET_SDS_MRB.bf.tx in hard reset\n");
        return (1);
      }
    }
    else {
      tmp = 1 << slice;
      CS_PRINT("slice=%d, tmp=%04X\n", slice, tmp);
      if (tmp_global_reset_sds_mrb.bf.rx & tmp) {
        CS_PRINT("MPIF_GLOBAL_RESET_SDS_MRB.bf.rx in hard reset\n");
        return (1);
      }
    }
  }
  return (0);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SDS MR MPIF                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_sds_mr_mpif(cs_uint16 dev_id,
                                            cs_module_t module_num,
                                            cs_uint8 slice,
                                            cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_RESET_SDS_MRA_t tmp_global_reset_sds_mra;
    /* set mask bits for affected selections */
    tmp_global_reset_sds_mra.wrd     = 0;
    tmp_global_reset_sds_mra.bf.mpif = tmp;
    /* perform the specified reset action */
    ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_MRA),
                     tmp_global_reset_sds_mra.wrd, act);
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    TEN_MPIF_GLOBAL_RESET_SDS_MRB_t tmp_global_reset_sds_mrb;
    /* set mask bits for affected selections */
    tmp_global_reset_sds_mrb.wrd     = 0;
    tmp_global_reset_sds_mrb.bf.mpif = tmp;
    /* perform the specified reset action */
    ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_MRB),
                     tmp_global_reset_sds_mrb.wrd, act);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SDS XFI                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_sds_xfi(cs_uint16 dev_id,
                                        cs_uint8 slice,
                                        cs_dir_t dir,
                                        cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_SDS_XFI_t tmp_global_reset_sds_xfi;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_sds_xfi.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_reset_sds_xfi.bf.rx = tmp;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_reset_sds_xfi.bf.tx = tmp;
  }
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_XFI),
                   tmp_global_reset_sds_xfi.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GET GLOBAL RESET SDS XFI                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_global_reset_sds_xfi(cs_uint16 dev_id,
                                            cs_uint8 slice,
                                            cs_dir_t dir)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 1=hard reset, 0 not in hard reset               */
/* DESCRIPTION:                                                 */
/* Returns the current state of hard reset for the specified    */
/* selection.                                                   */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_SDS_XFI_t tmp_global_reset_sds_xfi;

  if (dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "dir out of range");
    return (0);
  }
  if (slice > TEN_SLICE3) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "slice out of range");
    return (0);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  tmp_global_reset_sds_xfi.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_XFI));
  if (dir == CS_TX) {
    tmp = 1 << slice;
    CS_PRINT("slice=%d, tmp=%04X\n", slice, tmp);
    if (tmp_global_reset_sds_xfi.bf.tx & tmp) {
      CS_PRINT("MPIF_GLOBAL_RESET_SDS_XFI.bf.tx in hard reset\n");
      return (1);
    }
  }
  else {
    tmp = 1 << slice;
    CS_PRINT("slice=%d, tmp=%04X\n", slice, tmp);
    if (tmp_global_reset_sds_xfi.bf.rx & tmp) {
      CS_PRINT("MPIF_GLOBAL_RESET_SDS_XFI.bf.rx in hard reset\n");
      return (1);
    }
  
  }
  return (0);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SDS XFI MPIF               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_sds_xfi_mpif(cs_uint16 dev_id,
                                             cs_uint8 slice,
                                             cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_SDS_XFI_t tmp_global_reset_sds_xfi;

  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_sds_xfi.wrd = 0;
  tmp_global_reset_sds_xfi.bf.mpif = tmp;
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_XFI),
                   tmp_global_reset_sds_xfi.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SDS XFI DSP T41            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_sds_xfi_dsp_t41(cs_uint16 dev_id,
                                                cs_uint8 slice,
                                                cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_SDS_XFI_t tmp_global_reset_sds_xfi;
  
  if (act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_PRINT("Not appliable for T40\n");
    return (CS_OK);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_sds_xfi.wrd = 0;
  tmp_global_reset_sds_xfi.bf.dsp = tmp;
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_XFI), tmp_global_reset_sds_xfi.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}


/********************************************************************/
/* $rtn_hdr_start  MPIF SET LVDS OUTPUT POWER DOWN                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_lvds_pd(cs_uint16 dev_id,
                               cs_uint16 select,
                               cs_uint16 value)
/* INPUTS     : o Device Id                                         */
/*              o Select                                            */
/*              o Value                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Allows the selected LVDS output buffers to be powered-down.      */
/*                                                                  */
/*   [select]                                                       */
/*     TEN_MPIF_LVDS_PD_SELECT_RXREF                      1         */
/*     TEN_MPIF_LVDS_PD_SELECT_SYSREF                     2         */
/*     TEN_MPIF_LVDS_PD_SELECT_OHPPO_B                    3         */
/*     TEN_MPIF_LVDS_PD_SELECT_OHPPI_B                    4         */
/*     TEN_MPIF_LVDS_PD_SELECT_OHPPO_A                    5         */
/*     TEN_MPIF_LVDS_PD_SELECT_OHPPI_A                    6         */
/*     TEN_MPIF_LVDS_PD_SELECT_OHPPO_B_OHPPI_B_SYSREF     7         */
/*     TEN_MPIF_LVDS_PD_SELECT_OHPPO_A_OHPPI_A_SYSREF     8         */
/*     TEN_MPIF_LVDS_PD_SELECT_ALL_EXCEPT_RXREF           9         */
/*     TEN_MPIF_LVDS_PD_SELECT_ALL                        0xFF.     */
/*                                                                  */
/*   [value]                                                        */
/*     0 = LVDS output buffers to be powered-on                     */
/*     1 = LVDS output buffers to be powered-down.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_LVDS_PD_t tmp_lvds_pd;
  T41_t *pDev = NULL;

  if ((!select) || (select > TEN_MPIF_LVDS_PD_SELECT_ALL_EXCEPT_RXREF)) {
    if (select != TEN_MPIF_LVDS_PD_SELECT_ALL) {
      CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                    ": select out of range.");
      return(CS_ERROR);
    }
  }

  if (value > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                  ": value out of range, s/b 0 or 1.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_lvds_pd.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, LVDS_PD));

  switch (select) {
  case (TEN_MPIF_LVDS_PD_SELECT_RXREF):
    tmp_lvds_pd.bf.rxref = value;
    break;

  case (TEN_MPIF_LVDS_PD_SELECT_SYSREF):
    tmp_lvds_pd.bf.sysref = value;
    break;

  case (TEN_MPIF_LVDS_PD_SELECT_OHPPO_B):
    tmp_lvds_pd.bf.ohppo_b = value;
    break;

  case (TEN_MPIF_LVDS_PD_SELECT_OHPPI_B):
    tmp_lvds_pd.bf.ohppi_b = value;
    break;

  case (TEN_MPIF_LVDS_PD_SELECT_OHPPO_A):
    tmp_lvds_pd.bf.ohppo_a = value;
    break;

  case (TEN_MPIF_LVDS_PD_SELECT_OHPPI_A):
    tmp_lvds_pd.bf.ohppi_a = value;
    break;

  case (TEN_MPIF_LVDS_PD_SELECT_OHPPO_B_OHPPI_B_SYSREF):
    tmp_lvds_pd.bf.ohppo_b = value;
    tmp_lvds_pd.bf.ohppi_b = value;
    tmp_lvds_pd.bf.sysref = value;
    break;

  case (TEN_MPIF_LVDS_PD_SELECT_OHPPO_A_OHPPI_A_SYSREF):
    tmp_lvds_pd.bf.ohppo_a = value;
    tmp_lvds_pd.bf.ohppi_a = value;
    tmp_lvds_pd.bf.sysref = value;
    break;

  case (TEN_MPIF_LVDS_PD_SELECT_ALL_EXCEPT_RXREF):
    tmp_lvds_pd.bf.sysref = value;
    tmp_lvds_pd.bf.ohppo_b = value;
    tmp_lvds_pd.bf.ohppi_b = value;
    tmp_lvds_pd.bf.ohppo_a = value;
    tmp_lvds_pd.bf.ohppi_a = value;
    break;

  case (TEN_MPIF_LVDS_PD_SELECT_ALL):
    tmp_lvds_pd.bf.rxref = value;
    tmp_lvds_pd.bf.sysref = value;
    tmp_lvds_pd.bf.ohppo_b = value;
    tmp_lvds_pd.bf.ohppi_b = value;
    tmp_lvds_pd.bf.ohppo_a = value;
    tmp_lvds_pd.bf.ohppi_a = value;
    break;

  default:
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                  ": default, select out of range.");
    break;
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, LVDS_PD), tmp_lvds_pd.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF SET LVDS DIV POWER DOWN REGISTER        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_set_lvds_div_pd(cs_uint16 dev_id,
                                   cs_module_t module_num,
                                   cs_uint8 slice,
                                   cs_dir_t dir,
                                   cs_uint16 value)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Value                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register allows LVDS output buffers to be powered-down. */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*     0                                                        */
/*     1 = power-down _DIV_P/N LVDS outputs                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_LVDS_DIV_PD_t tmp_lvds_div_pd;
  T41_t *pDev = NULL;
  cs_uint16 which_slices = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(value > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": value out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slices = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slices = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_lvds_div_pd.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, LVDS_DIV_PD));
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (value == 1) {
        tmp_lvds_div_pd.bf.syncdsync_rxa |= which_slices;
      }
      else {
        tmp_lvds_div_pd.bf.syncdsync_rxa &= ~which_slices;
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (value == 1) {
        tmp_lvds_div_pd.bf.syncdsync_txa |= which_slices;
      }
      else {
        tmp_lvds_div_pd.bf.syncdsync_txa &= ~which_slices;
      }
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (value == 1) {
        tmp_lvds_div_pd.bf.syncdsync_rxb |= which_slices;
      }
      else {
        tmp_lvds_div_pd.bf.syncdsync_rxb &= ~which_slices;
      }
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (value == 1) {
        tmp_lvds_div_pd.bf.syncdsync_txb |= which_slices;
      }
      else {
        tmp_lvds_div_pd.bf.syncdsync_txb &= ~which_slices;
      }
    }
  }
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, LVDS_DIV_PD), tmp_lvds_div_pd.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF SET CLOCK SWITCH FORCE REGISTER             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_force(cs_uint16 dev_id,
                                          cs_module_t module_num,
                                          cs_uint8 slice,
                                          cs_dir_t dir,
                                          cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows software to switch the internal clock       */
/* source to a GPLL (RX) or Sync-Desync module (TX).                */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = RX: Do not force protection clock for the     */
/*                        RX GPLL input reference.                  */
/*                    TX: Do not force fractional divider output to */
/*                        be used as the RX_DIV output and input to */
/*                        the TX controllable divider.              */
/*   CS_ENABLE  (1) = RX: Force use of protection clock for the     */
/*                        RX GPLL input reference.                  */
/*                    TX: force use of fractional divider ouptut as */
/*                        RX_DIV output and input to the TX         */
/*                        controllable divider.                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_char8 *func = "ten_mpif_set_clock_switch_force";

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s()  module_num %d out of range", func, module_num);
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s()  dir %d out of range", func, dir);
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() ctl %d out of range", func, ctl);
    return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
    CS_PRINT("%s()  %s, SLICE_ALL, %s, %s\n", func, ten_module_strings[module_num], ten_dir_strings[dir], ten_ctrl_strings[ctl]);
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
    CS_PRINT("%s()  %s, %s, %s, %s\n", func, ten_module_strings[module_num], ten_slice_strings[slice], ten_dir_strings[dir], ten_ctrl_strings[ctl]);
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, "%s() slice %d out of range.  s/b 0..3, TEN_SLICE_ALL.", func, slice);
    return(CS_ERROR);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_RX_FORCE_t tmp_clock_switch_rx_force;
    tmp_clock_switch_rx_force.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_FORCE));
    if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_rx_force.bf.rxa |= which_slice;
      }
      else {
        tmp_clock_switch_rx_force.bf.rxa &= ~which_slice;
      }
    }
    if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_rx_force.bf.rxb |= which_slice;
      }
      else {
        tmp_clock_switch_rx_force.bf.rxb &= ~which_slice;
      }
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_FORCE), tmp_clock_switch_rx_force.wrd);
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_TX_FORCE_t tmp_clock_switch_tx_force;
    tmp_clock_switch_tx_force.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_FORCE));
    if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_tx_force.bf.txa |= which_slice;
      }
      else {
        tmp_clock_switch_tx_force.bf.txa &= ~which_slice;
      }
    }
    if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_tx_force.bf.txb |= which_slice;
      }
      else {
        tmp_clock_switch_tx_force.bf.txb &= ~which_slice;
      }
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_FORCE), tmp_clock_switch_tx_force.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF SET CLOCK SWITCH XLOS MR REGISTER           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_xlos_mr(cs_uint16 dev_id,
                                            cs_module_t module_num,
                                            cs_uint8 slice,
                                            cs_dir_t dir,
                                            cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL when External LOS failures occur (RX) or Sync-  */
/* Desync module (TX). For TX, this clock switch control is         */
/* multiplexed from RX to TX using the same mux selection used for  */
/* the RX divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.      */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Filtered XLOS alarm associated with the XFI   */
/*                    SerDes will NOT cause a HW switch of the GPLL */
/*                    input reference (RX) or Sync-Desync input     */
/*                    reference (TX).                               */
/*   CS_ENABLE  (1) = Filtered XLOS alarm associated with the XFI   */
/*                    SerDes will cause a HW switch of the GPLL     */
/*                    input reference (RX) or Sync-Desync input     */
/*                    reference (TX).                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_RX_XLOS_t tmp_clock_switch_rx_xlos;
    tmp_clock_switch_rx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_XLOS));
    if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_rx_xlos.bf.mra |= which_slice;
      }
      else {
        tmp_clock_switch_rx_xlos.bf.mra &= ~which_slice;
      }
    }
    if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_rx_xlos.bf.mrb |= which_slice;
      }
      else {
        tmp_clock_switch_rx_xlos.bf.mrb &= ~which_slice;
      }
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_XLOS), tmp_clock_switch_rx_xlos.wrd);
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_TX_XLOS_t tmp_clock_switch_tx_xlos;
    tmp_clock_switch_tx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_XLOS));
    if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_tx_xlos.bf.mra |= which_slice;
      }
      else {
        tmp_clock_switch_tx_xlos.bf.mra &= ~which_slice;
      }
    }
    if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_tx_xlos.bf.mrb |= which_slice;
      }
      else {
        tmp_clock_switch_tx_xlos.bf.mrb &= ~which_slice;
      }
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_XLOS), tmp_clock_switch_tx_xlos.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH XLOS MR REGISTER           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_xlos_mr(cs_uint16 dev_id,
                                            cs_module_t module_num,
                                            cs_uint8 slice,
                                            cs_dir_t dir)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL when External LOS failures occur (RX) or Sync-  */
/* Desync module (TX). For TX, this clock switch control is         */
/* multiplexed from RX to TX using the same mux selection used for  */
/* the RX divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.      */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_uint16 value = 0;

  if(module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return (0);
  }
  if(dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return (0);
  }
  
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  if (dir == CS_RX) {
    TEN_MPIF_CLOCK_SWITCH_RX_XLOS_t tmp_clock_switch_rx_xlos;
    tmp_clock_switch_rx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_XLOS));
    if (module_num == TEN_MODULE_A) {
      value = (tmp_clock_switch_rx_xlos.bf.mra & which_slice) == which_slice;
    }
    else { 
      value = (tmp_clock_switch_rx_xlos.bf.mrb & which_slice) == which_slice;
    }
  }
  else if (dir == CS_TX) {
    TEN_MPIF_CLOCK_SWITCH_TX_XLOS_t tmp_clock_switch_tx_xlos;
    tmp_clock_switch_tx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_XLOS));
    if (module_num == TEN_MODULE_A) {
      value = (tmp_clock_switch_tx_xlos.bf.mra & which_slice) == which_slice;
    }
    else {
      value = (tmp_clock_switch_tx_xlos.bf.mrb & which_slice) == which_slice;
    }
  }
  return (value);
}
/********************************************************************/
/* $rtn_hdr_start  MPIF SET CLOCK SWITCH XLOS XFI REGISTER          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_xlos_xfi(cs_uint16 dev_id,
                                             cs_uint8 slice,
                                             cs_dir_t dir,
                                             cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL when External LOS failures occur (RX) or Sync-  */
/* Desync module (TX). For TX, this clock switch control is         */
/* multiplexed from RX to TX using the same mux selection used for  */
/* the RX divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.      */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Filtered XLOS alarm associated with the XFI   */
/*                    SerDes will NOT cause a HW switch of the GPLL */
/*                    input reference (RX) or Sync-Desync input     */
/*                    reference (TX).                               */
/*   CS_ENABLE  (1) = Filtered XLOS alarm associated with the XFI   */
/*                    SerDes will cause a HW switch of the GPLL     */
/*                    input reference (RX) or Sync-Desync input     */
/*                    reference (TX).                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_RX_XLOS_t tmp_clock_switch_rx_xlos;
    tmp_clock_switch_rx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_XLOS));
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_rx_xlos.bf.xfi |= which_slice;
    }
    else {
      tmp_clock_switch_rx_xlos.bf.xfi &= ~which_slice;
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_XLOS), tmp_clock_switch_rx_xlos.wrd);
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_TX_XLOS_t tmp_clock_switch_tx_xlos;
    tmp_clock_switch_tx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_XLOS));
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_xlos.bf.xfi |= which_slice;
    }
    else {
      tmp_clock_switch_tx_xlos.bf.xfi &= ~which_slice;
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_XLOS), tmp_clock_switch_tx_xlos.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH XLOS XFI REGISTER          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_xlos_xfi(cs_uint16 dev_id,
                                             cs_uint8 slice,
                                             cs_dir_t dir)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL when External LOS failures occur (RX) or Sync-  */
/* Desync module (TX). For TX, this clock switch control is         */
/* multiplexed from RX to TX using the same mux selection used for  */
/* the RX divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.      */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_uint16 value = 0;

  if(dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return (0);
  }
  if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  if (dir == CS_RX) {
    TEN_MPIF_CLOCK_SWITCH_RX_XLOS_t tmp_clock_switch_rx_xlos;
    tmp_clock_switch_rx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_XLOS));
    value = (tmp_clock_switch_rx_xlos.bf.xfi & which_slice) == which_slice;
  }
  else if (dir == CS_TX) {
    TEN_MPIF_CLOCK_SWITCH_TX_XLOS_t tmp_clock_switch_tx_xlos;
    tmp_clock_switch_tx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_XLOS));
    value = (tmp_clock_switch_tx_xlos.bf.xfi & which_slice) == which_slice;
  }
  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF SET CLOCK SWITCH XLOS MRB2A                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_xlos_mrb2a(cs_uint16 dev_id,
                                               cs_uint8 slice,
                                               cs_dir_t dir,
                                               cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL when External LOS failures occur (RX) or Sync-  */
/* Desync module (TX). For TX, this clock switch control is         */
/* multiplexed from RX to TX using the same mux selection used for  */
/* the RX divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.      */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/* CS_DISABLE (0) or CS_ENABLE  (1)                                 */
/* When '1', Filtered XLOS alarm associated with MR SerDes B will   */
/* cause a HW protection switch of the TX/RX-A GPLL input reference.*/
/* This is to be used when the MR-B SerDes is used with the         */
/* internal A-side datapath.                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (CS_ERROR);
  }
  
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_RX_XLOS_t tmp_clock_switch_rx_xlos;
    tmp_clock_switch_rx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_XLOS));
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_rx_xlos.bf.mrb2a |= which_slice;
    }
    else {
      tmp_clock_switch_rx_xlos.bf.mrb2a &= ~which_slice;
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_XLOS), tmp_clock_switch_rx_xlos.wrd);
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_TX_XLOS_t tmp_clock_switch_tx_xlos;
    tmp_clock_switch_tx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_XLOS));
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_xlos.bf.mrb2a |= which_slice;
    }
    else {
      tmp_clock_switch_tx_xlos.bf.mrb2a &= ~which_slice;
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_XLOS), tmp_clock_switch_tx_xlos.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH XLOS MRB2A                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_xlos_mrb2a(cs_uint16 dev_id,
                                               cs_uint8 slice,
                                               cs_dir_t dir)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL when External LOS failures occur (RX) or Sync-  */
/* Desync module (TX). For TX, this clock switch control is         */
/* multiplexed from RX to TX using the same mux selection used for  */
/* the RX divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.      */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_uint16 value = 0;

  if (dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (0);
  }
  if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  if (dir == CS_RX) {
    TEN_MPIF_CLOCK_SWITCH_RX_XLOS_t tmp_clock_switch_rx_xlos;
    tmp_clock_switch_rx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_XLOS));
    value = (tmp_clock_switch_rx_xlos.bf.mrb2a & which_slice) == which_slice;
  }
  else if (dir == CS_TX) {
    TEN_MPIF_CLOCK_SWITCH_TX_XLOS_t tmp_clock_switch_tx_xlos;
    tmp_clock_switch_tx_xlos.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_XLOS));
    value = (tmp_clock_switch_tx_xlos.bf.mrb2a & which_slice) == which_slice;
  }
  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF SET CLOCK SWITCH LOCKDET MR REGISTER        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_lockdet_mr(cs_uint16 dev_id,
                                               cs_module_t module_num,
                                               cs_uint8 slice,
                                               cs_dir_t dir,
                                               cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL (RX) or Sync-Desync module (TX) when LOCKDET    */
/* failures occur. For TX, this clock switch control is multiplexed */
/* from RX to TX using the same mux selection used for the RX       */
/* divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.             */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Filtered LOCKDET alarm associated with the XFI*/
/*                    SerDes will NOT cause a HW switch of the GPLL */
/*                    input reference (RX) or Sync-Desync input     */
/*                    reference (TX).                               */
/*   CS_ENABLE  (1) = Filtered LOCKDET alarm associated with the XFI*/
/*                    SerDes will cause a HW switch of the GPLL     */
/*                    input reference (RX) or Sync-Desync input     */
/*                    reference (TX).                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_RX_LOCKDET_t tmp_clock_switch_rx_lockdet;
    tmp_clock_switch_rx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_LOCKDET));
    if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_rx_lockdet.bf.mra |= which_slice;
      }
      else {
        tmp_clock_switch_rx_lockdet.bf.mra &= ~which_slice;
      }
    }
    if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_rx_lockdet.bf.mrb |= which_slice;
      }
      else {
        tmp_clock_switch_rx_lockdet.bf.mrb &= ~which_slice;
      }
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_LOCKDET), tmp_clock_switch_rx_lockdet.wrd);
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_TX_LOCKDET_t tmp_clock_switch_tx_lockdet;
    tmp_clock_switch_tx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_LOCKDET));
    if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_tx_lockdet.bf.mra |= which_slice;
      }
      else {
        tmp_clock_switch_tx_lockdet.bf.mra &= ~which_slice;
      }
    }
    if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
      if (ctl == CS_ENABLE) {
        tmp_clock_switch_tx_lockdet.bf.mrb |= which_slice;
      }
      else {
        tmp_clock_switch_tx_lockdet.bf.mrb &= ~which_slice;
      }
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_LOCKDET), tmp_clock_switch_tx_lockdet.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH LOCKDET MR REGISTER        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_lockdet_mr(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_uint8 slice,
                                              cs_dir_t dir)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL (RX) or Sync-Desync module (TX) when LOCKDET    */
/* failures occur. For TX, this clock switch control is multiplexed */
/* from RX to TX using the same mux selection used for the RX       */
/* divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.             */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_uint16 value = 0;
  
  if (module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num out of range");
    return (0);
  }
  
  if (dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (0);
  }
  
  if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  if (dir == CS_RX) {
    TEN_MPIF_CLOCK_SWITCH_RX_LOCKDET_t tmp_clock_switch_rx_lockdet;
    tmp_clock_switch_rx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_LOCKDET));
    if (module_num == TEN_MODULE_A) {
      value = (tmp_clock_switch_rx_lockdet.bf.mra & which_slice) == which_slice;
    }
    else {
      value = (tmp_clock_switch_rx_lockdet.bf.mrb & which_slice) == which_slice;
    }
  }
  
  if (dir == CS_TX) {
    TEN_MPIF_CLOCK_SWITCH_TX_LOCKDET_t tmp_clock_switch_tx_lockdet;
    tmp_clock_switch_tx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_LOCKDET));
    if (module_num == TEN_MODULE_A) {
      value = (tmp_clock_switch_tx_lockdet.bf.mra & which_slice) == which_slice;
    }
    else {
      value = (tmp_clock_switch_tx_lockdet.bf.mrb & which_slice) == which_slice;
    }
  }

  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH LOCKDET MRB2A REGISTER     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_lockdet_mrb2a(cs_uint16 dev_id,
                                                  cs_uint8 slice,
                                                  cs_dir_t dir)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* Returns MPIF_CLOCK_SWITCH_TX_LOCKDET mrb2a or                    */
/* MPIF_CLOCK_SWITCH_RX_LOCKDET mrb2a bitfield setting.             */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_uint16 value = 0;
  
  if (dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (0);
  }
  
  if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  if (dir == CS_RX) {
    TEN_MPIF_CLOCK_SWITCH_RX_LOCKDET_t tmp_clock_switch_rx_lockdet;
    tmp_clock_switch_rx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_LOCKDET));
      value = ((tmp_clock_switch_rx_lockdet.bf.mrb2a & which_slice) == which_slice);
  }
  
  if (dir == CS_TX) {
    TEN_MPIF_CLOCK_SWITCH_TX_LOCKDET_t tmp_clock_switch_tx_lockdet;
    tmp_clock_switch_tx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_LOCKDET));
    value = ((tmp_clock_switch_tx_lockdet.bf.mrb2a & which_slice) == which_slice);
  }

  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF SET CLOCK SWITCH LOCKDET XFI REGISTER       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_lockdet_xfi(cs_uint16 dev_id,
                                                cs_uint8 slice,
                                                cs_dir_t dir,
                                                cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL (RX) or Sync-Desync module (TX) when LOCKDET    */
/* failures occur. For TX, this clock switch control is multiplexed */
/* from RX to TX using the same mux selection used for the RX       */
/* divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.             */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Filtered LOCKDET alarm associated with the XFI*/
/*                    SerDes will NOT cause a HW switch of the GPLL */
/*                    input reference (RX) or Sync-Desync input     */
/*                    reference (TX).                               */
/*   CS_ENABLE  (1) = Filtered LOCKDET alarm associated with the XFI*/
/*                    SerDes will cause a HW switch of the GPLL     */
/*                    input reference (RX) or Sync-Desync input     */
/*                    reference (TX).                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_RX_LOCKDET_t tmp_clock_switch_rx_lockdet;
    tmp_clock_switch_rx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_LOCKDET));
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_rx_lockdet.bf.xfi |= which_slice;
    }
    else {
      tmp_clock_switch_rx_lockdet.bf.xfi &= ~which_slice;
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_LOCKDET), tmp_clock_switch_rx_lockdet.wrd);
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_TX_LOCKDET_t tmp_clock_switch_tx_lockdet;
    tmp_clock_switch_tx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_LOCKDET));
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_lockdet.bf.xfi |= which_slice;
    }
    else {
      tmp_clock_switch_tx_lockdet.bf.xfi &= ~which_slice;
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_LOCKDET), tmp_clock_switch_tx_lockdet.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH LOCKDET XFI REGISTER       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_lockdet_xfi(cs_uint16 dev_id,
                                                cs_uint8 slice,
                                                cs_dir_t dir)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL (RX) or Sync-Desync module (TX) when LOCKDET    */
/* failures occur. For TX, this clock switch control is multiplexed */
/* from RX to TX using the same mux selection used for the RX       */
/* divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.             */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX.                                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_uint16 value = 0;

  if(dir > CS_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (0);
  }
  if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  if (dir == CS_RX) {
    TEN_MPIF_CLOCK_SWITCH_RX_LOCKDET_t tmp_clock_switch_rx_lockdet;
    tmp_clock_switch_rx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_LOCKDET));
    value = (tmp_clock_switch_rx_lockdet.bf.xfi & which_slice) == which_slice;
  }
  else if (dir == CS_TX) {
    TEN_MPIF_CLOCK_SWITCH_TX_LOCKDET_t tmp_clock_switch_tx_lockdet;
    tmp_clock_switch_tx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_LOCKDET));
    value = (tmp_clock_switch_tx_lockdet.bf.xfi & which_slice) == which_slice;
  }

  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF SET CLOCK SWITCH LOCKDET MRB2A              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_lockdet_mrb2a(cs_uint16 dev_id,
                                                  cs_uint8 slice,
                                                  cs_dir_t dir,
                                                  cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Direction                                         */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL (RX) or Sync-Desync module (TX) when LOCKDET    */
/* failures occur. For TX, this clock switch control is multiplexed */
/* from RX to TX using the same mux selection used for the RX       */
/* divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.             */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Filtered LOCKDET alarm associated with the    */
/*                    MRB2A                                         */
/*                    SerDes will NOT cause a HW switch of the GPLL */
/*                    input reference (RX) or Sync-Desync input     */
/*                    reference (TX).                               */
/*   CS_ENABLE  (1) = Filtered LOCKDET alarm associated with the    */
/*                    MRB2A                                         */
/*                    SerDes will cause a HW switch of the GPLL     */
/*                    input reference (RX) or Sync-Desync input     */
/*                    reference (TX).                               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return(CS_ERROR);
  }
  
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
    return (CS_ERROR);
  }
  
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_RX_LOCKDET_t tmp_clock_switch_rx_lockdet;
    tmp_clock_switch_rx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_LOCKDET));
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_rx_lockdet.bf.mrb2a |= which_slice;
    }
    else {
      tmp_clock_switch_rx_lockdet.bf.mrb2a &= ~which_slice;
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_LOCKDET), tmp_clock_switch_rx_lockdet.wrd);
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_TX_LOCKDET_t tmp_clock_switch_tx_lockdet;
    tmp_clock_switch_tx_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_LOCKDET));
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_lockdet.bf.mrb2a |= which_slice;
    }
    else {
      tmp_clock_switch_tx_lockdet.bf.mrb2a &= ~which_slice;
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_LOCKDET), tmp_clock_switch_tx_lockdet.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF SET CLOCK SWITCH CLKLOSS REGISTER           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_clkloss(cs_uint16 dev_id,
                                               cs_module_t module_num,
                                               cs_dir_t dir,
                                               cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Direction                                         */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to a GPLL (RX) or Sync-Desync (TX) when SFI41 clock loss  */
/* failures occur. For TX, this clock switch control is multiplexed */
/* from RX to TX using the same mux selection used for the RX       */
/* divided clock, see SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.             */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Clock loss alarm from SFI41 will NOT cause a  */
/*                    HW switch of the GPLL (RX) or Sync-Desync     */
/*                    (TX) input reference.                         */
/*   CS_ENABLE  (1) = Clock loss alarm from SFI41 will cause a      */
/*                    HW switch of the GPLL (RX) or Sync-Desync     */
/*                    (TX) input reference. When configured for     */
/*                    SFI41, the clock loss alarm is avalibe as     */
/*                    MPIF_CLOCK_LOSS_STATUS.*X*i[0].               */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_RX_CLKLOSS_t tmp_clock_switch_rx_clkloss;
    tmp_clock_switch_rx_clkloss.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_CLKLOSS));
    if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
      tmp_clock_switch_rx_clkloss.bf.mra = ctl;
    }
    if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
      tmp_clock_switch_rx_clkloss.bf.mrb = ctl;
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_CLKLOSS), tmp_clock_switch_rx_clkloss.wrd);
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    TEN_MPIF_CLOCK_SWITCH_TX_CLKLOSS_t tmp_clock_switch_tx_clkloss;
    tmp_clock_switch_tx_clkloss.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_CLKLOSS));
    if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
      tmp_clock_switch_tx_clkloss.bf.mra = ctl;
    }
    if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
      tmp_clock_switch_tx_clkloss.bf.mrb = ctl;
    }
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_CLKLOSS), tmp_clock_switch_tx_clkloss.wrd);
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF SET CLOCK SWITCH SOURCE REGISTER            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_rx_source(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_uint8 slice,
                                              cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows selection of the source used when the       */
/* internal clock source to an RX GPLL is automatically switched    */
/* due to specific failures.                                        */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Selected TX Module SerDes ouptut clock,       */
/*                    selected via MPIF_CLOCK_SELECT_HSIF_OUT,      */
/*                    used as RX Module GPLL reference when HW      */
/*                    switch is enabled.                            */
/*   CS_ENABLE  (1) = Internaly generated system clock based        */
/*                    reference, configured via FRAC_DIV*           */
/*                    registers, used as RX Module GPLL reference   */
/*                    when HW switch is enabled.                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_RX_SOURCE_t tmp_clock_switch_rx_source;
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_switch_rx_source.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_SOURCE));
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_rx_source.bf.rxa |= which_slice;
    }
    else {
      tmp_clock_switch_rx_source.bf.rxa &= ~which_slice;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_rx_source.bf.rxb |= which_slice;
    }
    else {
      tmp_clock_switch_rx_source.bf.rxb &= ~which_slice;
    }
  }
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_RX_SOURCE), tmp_clock_switch_rx_source.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SWITCH TX CBRGENAIS 10G REGISTER      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_tx_cbrgenais_10g(cs_uint16 dev_id,
                                                     cs_module_t module_num,
                                                     cs_uint8 slice,
                                                     cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when CBRGENAIS failures occur.      */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Consequent action CBRGENAIS alarm will NOT    */
/*                    cause a HW switch of the associated Sync-     */
/*                    Desync input reference.                       */
/*   CS_ENABLE  (1) = Consequent action CBRGENAIS alarm will        */
/*                    cause a HW switch of the associated input     */
/*                    reference to the internal pilot.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_CBRGENAIS_t tmp_clock_switch_tx_cbrgenais;
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_switch_tx_cbrgenais.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_CBRGENAIS));
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_cbrgenais.bf.One0g_a |= which_slice;
    }
    else {
      tmp_clock_switch_tx_cbrgenais.bf.One0g_a &= ~which_slice;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_cbrgenais.bf.One0g_b |= which_slice;
    }
    else {
      tmp_clock_switch_tx_cbrgenais.bf.One0g_b &= ~which_slice;
    }
  }
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_CBRGENAIS), tmp_clock_switch_tx_cbrgenais.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH TX CBRGENAIS 10G REGISTER  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_tx_cbrgenais_10g(cs_uint16 dev_id,
                                                     cs_module_t module_num,
                                                     cs_uint8 slice)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when CBRGENAIS failures occur.      */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_CBRGENAIS_t tmp_clock_switch_tx_cbrgenais;
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_uint16 value = 0;

  if(module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num out of range");
    return (0);
  }
  
  if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  tmp_clock_switch_tx_cbrgenais.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_CBRGENAIS));
  if (module_num == TEN_MODULE_A) {
    value = (tmp_clock_switch_tx_cbrgenais.bf.One0g_a & which_slice) == which_slice;
  }
  
  if (module_num == TEN_MODULE_B) {
    value = (tmp_clock_switch_tx_cbrgenais.bf.One0g_b & which_slice) == which_slice;
  }
  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SWITCH TX CBRGENAIS 40G REGISTER      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_tx_cbrgenais_40g(cs_uint16 dev_id,
                                                     cs_module_t module_num,
                                                     cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when CBRGENAIS failures occur.      */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Consequent action CBRGENAIS alarm will NOT    */
/*                    cause a HW switch of the #0 (Module A) or     */
/*                    #4 (Module B) Sync-Desync input reference.    */
/*   CS_ENABLE  (1) = Consequent action CBRGENAIS alarm will        */
/*                    cause a HW switch of the #0 (Module A) or     */
/*                    #4 (Module B) Sync-Desync input reference.    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_CBRGENAIS_t tmp_clock_switch_tx_cbrgenais;
  T41_t *pDev = NULL;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_switch_tx_cbrgenais.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_CBRGENAIS));
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_clock_switch_tx_cbrgenais.bf.Four0g_a = ctl;
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_clock_switch_tx_cbrgenais.bf.Four0g_b = ctl;
  }
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_CBRGENAIS), tmp_clock_switch_tx_cbrgenais.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH TX CBRGENAIS 40G REGISTER  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_tx_cbrgenais_40g(cs_uint16 dev_id,
                                                     cs_module_t module_num)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when CBRGENAIS failures occur.      */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_CBRGENAIS_t tmp_clock_switch_tx_cbrgenais;
  T41_t *pDev = NULL;
  cs_uint16 value = 0;

  if(module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num out of range");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  tmp_clock_switch_tx_cbrgenais.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_CBRGENAIS));
  if (module_num == TEN_MODULE_A) {
    value = tmp_clock_switch_tx_cbrgenais.bf.Four0g_a;
  }
  else {
    value = tmp_clock_switch_tx_cbrgenais.bf.Four0g_b;
  }
  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SWITCH TX PN11 10G REGISTER           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_tx_pn11_10g(cs_uint16 dev_id,
                                                cs_module_t module_num,
                                                cs_uint8 slice,
                                                cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when PN11 failures occur.           */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Consequent action PN11 alarm will NOT         */
/*                    cause a HW switch of the associated Sync-     */
/*                    Desync input reference.                       */
/*   CS_ENABLE  (1) = Consequent action PN11 alarm will             */
/*                    cause a HW switch of the associated input     */
/*                    reference to the internal pilot.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_PN11_t tmp_clock_switch_tx_pn11;
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_switch_tx_pn11.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_PN11));
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_pn11.bf.One0g_a |= which_slice;
    }
    else {
      tmp_clock_switch_tx_pn11.bf.One0g_a &= ~which_slice;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_pn11.bf.One0g_b |= which_slice;
    }
    else {
      tmp_clock_switch_tx_pn11.bf.One0g_b &= ~which_slice;
    }
  }
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_PN11), tmp_clock_switch_tx_pn11.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH TX PN11 10G REGISTER       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_tx_pn11_10g(cs_uint16 dev_id,
                                                cs_module_t module_num,
                                                cs_uint8 slice)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when PN11 failures occur.           */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_PN11_t tmp_clock_switch_tx_pn11;
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_uint16 value = 0;

  if (module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num out of range");
    return (0);
  }
  
  if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  tmp_clock_switch_tx_pn11.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_PN11));
  if (module_num == TEN_MODULE_A) {
    value = (tmp_clock_switch_tx_pn11.bf.One0g_a & which_slice) == which_slice;
  }
  else {
    value = (tmp_clock_switch_tx_pn11.bf.One0g_b & which_slice) == which_slice;
  }
  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SWITCH TX PN11 40G REGISTER           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_tx_pn11_40g(cs_uint16 dev_id,
                                                cs_module_t module_num,
                                                cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when PN11 failures occur.           */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Consequent action PN11 alarm will NOT         */
/*                    cause a HW switch of the #0 (Module A) or     */
/*                    #4 (Module B) Sync-Desync input reference.    */
/*   CS_ENABLE  (1) = Consequent action PN11 alarm will             */
/*                    cause a HW switch of the #0 (Module A) or     */
/*                    #4 (Module B) Sync-Desync input reference.    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_PN11_t tmp_clock_switch_tx_pn11;
  T41_t *pDev = NULL;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_switch_tx_pn11.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_PN11));
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_clock_switch_tx_pn11.bf.Four0g_a = ctl;
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_clock_switch_tx_pn11.bf.Four0g_b = ctl;
  }
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_PN11), tmp_clock_switch_tx_pn11.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH TX PN11 40G REGISTER       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_tx_pn11_40g(cs_uint16 dev_id,
                                                cs_module_t module_num)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when PN11 failures occur.           */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_PN11_t tmp_clock_switch_tx_pn11;
  T41_t *pDev = NULL;
  cs_uint16 value = 0;

  if (module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num out of range");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  tmp_clock_switch_tx_pn11.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_PN11));
  if (module_num == TEN_MODULE_A) {
    value = tmp_clock_switch_tx_pn11.bf.Four0g_a;
  }
  else {
    value = tmp_clock_switch_tx_pn11.bf.Four0g_b;
  }
  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SWITCH TX MS 10G REGISTER             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_tx_ms_10g(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_uint8 slice,
                                              cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when MS failures occur.             */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Consequent action MS alarm will NOT           */
/*                    cause a HW switch of the associated Sync-     */
/*                    Desync input reference.                       */
/*   CS_ENABLE  (1) = Consequent action MS alarm will               */
/*                    cause a HW switch of the associated input     */
/*                    reference to the internal pilot.              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_MS_t tmp_clock_switch_tx_ms;
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_switch_tx_ms.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MS));
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_ms.bf.One0g_a |= which_slice;
    }
    else {
      tmp_clock_switch_tx_ms.bf.One0g_a &= ~which_slice;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_ms.bf.One0g_b |= which_slice;
    }
    else {
      tmp_clock_switch_tx_ms.bf.One0g_b &= ~which_slice;
    }
  }
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MS), tmp_clock_switch_tx_ms.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH TX MS 10G REGISTER         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_tx_ms_10g(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_uint8 slice)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when MS failures occur.             */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B.                                              */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_MS_t tmp_clock_switch_tx_ms;
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_uint16 value = 0;

  if(module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num out of range");
    return (0);
  }
  
  if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  tmp_clock_switch_tx_ms.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MS));
  if (module_num == TEN_MODULE_A) {
    value = (tmp_clock_switch_tx_ms.bf.One0g_a & which_slice) == which_slice;
  }
  else {
    value = (tmp_clock_switch_tx_ms.bf.One0g_b & which_slice) == which_slice;
  }
  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SWITCH TX MS 40G REGISTER             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_tx_ms_40g(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when MS failures occur.             */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Consequent action MS alarm  will NOT          */
/*                    cause a HW switch of the #0 (Module A) or     */
/*                    #4 (Module B) Sync-Desync input reference.    */
/*   CS_ENABLE  (1) = Consequent action MS alarm will               */
/*                    cause a HW switch of the #0 (Module A) or     */
/*                    #4 (Module B) Sync-Desync input reference.    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_MS_t tmp_clock_switch_tx_ms;
  T41_t *pDev = NULL;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_switch_tx_ms.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MS));
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_clock_switch_tx_ms.bf.Four0g_a = ctl;
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_clock_switch_tx_ms.bf.Four0g_b = ctl;
  }
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MS), tmp_clock_switch_tx_ms.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH TX MS 40G REGISTER         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_tx_ms_40g(cs_uint16 dev_id,
                                              cs_module_t module_num)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when MS failures occur.             */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B.                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_MS_t tmp_clock_switch_tx_ms;
  T41_t *pDev = NULL;
  cs_uint16 value = 0;

  if(module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num out of range");
    return (0);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  tmp_clock_switch_tx_ms.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MS));
  if (module_num == TEN_MODULE_A) {
    value = tmp_clock_switch_tx_ms.bf.Four0g_a;
  }
  else {
    value = tmp_clock_switch_tx_ms.bf.Four0g_b;
  }
  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SWITCH TX MSAIS REGISTER              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_set_clock_switch_tx_msais(cs_uint16 dev_id,
                                             cs_module_t module_num,
                                             cs_uint8 slice,
                                             cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when MSAIS failures occur.          */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one of   */
/* of the following:                                                */
/*   CS_DISABLE (0) = Consequent action MSAIS alarm will NOT        */
/*                    cause a HW switch of the associated Sync-     */
/*                    Desync input reference.                       */
/*   CS_ENABLE  (1) = Consequent action MSAIS alarm will            */
/*                    cause a HW switch of the associated Sync-     */
/*                    Desync input reference to the internal pilot. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_MSAIS_t tmp_clock_switch_tx_msais;
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    which_slice = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_clock_switch_tx_msais.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MSAIS));
  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_msais.bf.One0g_a |= which_slice;
    }
    else {
      tmp_clock_switch_tx_msais.bf.One0g_a &= ~which_slice;
    }
  }
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if (ctl == CS_ENABLE) {
      tmp_clock_switch_tx_msais.bf.One0g_b |= which_slice;
    }
    else {
      tmp_clock_switch_tx_msais.bf.One0g_b &= ~which_slice;
    }
  }
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MSAIS), tmp_clock_switch_tx_msais.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GET CLOCK SWITCH TX MSAIS REGISTER          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_mpif_get_clock_switch_tx_msais(cs_uint16 dev_id,
                                             cs_module_t module_num,
                                             cs_uint8 slice)
/* INPUTS     : o Device Id                                         */
/*              o Module Number                                     */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Value                                               */
/* DESCRIPTION:                                                     */
/* This register allows hardware to switch the internal clock       */
/* source to the TX Sync-Desync when MSAIS failures occur.          */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3.                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SWITCH_TX_MSAIS_t tmp_clock_switch_tx_msais;
  T41_t *pDev = NULL;
  cs_uint16 which_slice = 0;
  cs_uint16 value = 0;

  if(module_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": module_num out of range");
    return (0);
  }
  
  if (slice <= TEN_SLICE3) {
    which_slice = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  tmp_clock_switch_tx_msais.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SWITCH_TX_MSAIS));
  if (module_num == TEN_MODULE_A) {
    value = (tmp_clock_switch_tx_msais.bf.One0g_a & which_slice) == which_slice;
  }
  else {
    value = (tmp_clock_switch_tx_msais.bf.One0g_b & which_slice) == which_slice;
  }
  return (value);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET PP40G SYS T41                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_reset_pp40g_sys_t41(cs_uint16 dev_id,
                                              cs_module_t module_num,
                                              cs_reset_action_t act)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a hard reset on the specified selections. The           */
/* selections that are masked off will not be affected.             */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [act] parameter specifies the reset option and is one        */
/* of the following:                                                */
/*   0 = CS_RESET_DEASSERT                                          */
/*   1 = CS_RESET_ASSERT                                            */
/*   2 = CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset for a while and then de-assert the reset bit(s).         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_PP40G_t tmp_global_reset_pp40g;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_mpif_global_reset_pp40g_sys_t41";  

  if (module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!  module_num out of range", func);
    return (CS_ERROR);
  }

  if (act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   act out of range", func);
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   T41 only feature.", func);
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_pp40g.wrd = 0;

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_reset_pp40g.bf.sys_a = 1;
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_reset_pp40g.bf.sys_b = 1;
  }

  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP40G), tmp_global_reset_pp40g.wrd, act);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET PP40G T41                      */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_reset_pp40g_t41(cs_uint16 dev_id,
                                          cs_module_t module_num,
                                          cs_dir_t dir,
                                          cs_reset_action_t act)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Performs a hard reset on the specified selections. The           */
/* selections that are masked off will not be affected.             */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [act] parameter specifies the reset option and is one        */
/* of the following:                                                */
/*   0 = CS_RESET_DEASSERT                                          */
/*   1 = CS_RESET_ASSERT                                            */
/*   2 = CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the         */
/*   reset for a while and then de-assert the reset bit(s).         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GLOBAL_RESET_PP40G_t tmp_global_reset_pp40g;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_mpif_global_reset_pp40g_t41";  

  if (dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   dir out of range", func);
    return (CS_ERROR);
  }

  if (module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   module_num out of range", func);
    return (CS_ERROR);
  }

  if (act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   act out of range", func);
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   T41 only feature.", func);
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

   /* set mask bits for affected selections */
  tmp_global_reset_pp40g.wrd = 0;

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_pp40g.bf.rx_a = 1;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_pp40g.bf.tx_a = 1;
    }
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_pp40g.bf.rx_b = 1;
    }
    if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      tmp_global_reset_pp40g.bf.tx_b = 1;
    }
  }

  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP40G), tmp_global_reset_pp40g.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SDS CFP T41                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_sds_cfp_t41(cs_uint16 dev_id,
                                            cs_uint8 slice,
                                            cs_dir_t dir,
                                            cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_SDS_CFP_t tmp_global_reset_sds_cfp;

  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": T41 only feature.");
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_sds_cfp.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_reset_sds_cfp.bf.rx = tmp;
  }
  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_reset_sds_cfp.bf.tx = tmp;
  }
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_CFP),
                   tmp_global_reset_sds_cfp.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GET GLOBAL RESET SDS CFP T41            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_global_reset_sds_cfp_t41(cs_uint16 dev_id,
                                                cs_uint8 slice,
                                                cs_dir_t dir)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Returns the hard reset on the specified selections.          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_SDS_CFP_t tmp_global_reset_sds_cfp;

  if (dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (0);
  }
  
  if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": T41 only feature.");
    return(0);
  }
  
  tmp_global_reset_sds_cfp.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_CFP));
 
  if (dir == CS_TX) {
    return ((tmp_global_reset_sds_cfp.bf.tx & tmp) == tmp);
  }
  else if (dir == CS_RX) {
    return ((tmp_global_reset_sds_cfp.bf.rx & tmp) == tmp);
  }
  else {
    return ( ((tmp_global_reset_sds_cfp.bf.tx & tmp) == tmp) &
             ((tmp_global_reset_sds_cfp.bf.rx & tmp) == tmp) ); 
  }
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET SDS CFP MPIF T41           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_sds_cfp_mpif_t41(cs_uint16 dev_id,
                                                 cs_uint8 slice,
                                                 cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_SDS_CFP_t tmp_global_reset_sds_cfp;

  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_sds_cfp.wrd = 0;
  tmp_global_reset_sds_cfp.bf.mpif = tmp;
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_SDS_CFP),
                   tmp_global_reset_sds_cfp.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE PP40G BYP T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_clock_disable_pp40g_byp_t41(cs_uint16 dev_id,
                                                      cs_module_t module_num,
                                                      cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control disabling of the clock to the specified blocks.          */
/* The blocks that have clock disable set to CS_DISABLE are         */
/* inaccessible from the microprocessor port.  After the clock      */
/* disable to a block is written from CS_DISABLE to CS_ENABLE,      */
/* the software reset APIs should be used to reset the              */
/* affected block.                                                  */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one      */
/* of the following:                                                */
/*   CS_DISABLE (0) to disable the specified clock(s) or            */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API       */
/*   will generate the correct sense of the bit expected by the     */
/*   device.                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP40G_t tmp_global_clock_disable_pp40g;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_mpif_global_clock_disable_pp40g_byp_t41";  

  if (module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   module_num out of range", func);
    return (CS_ERROR);
  }

  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() FAILED!   ctl = 0x%04X\n", func, ctl);
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED! T41 only feature.", func);
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_clock_disable_pp40g.wrd = 0;
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_clock_disable_pp40g.bf.byp_a = 1;
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_clock_disable_pp40g.bf.byp_b = 1;
  }

  /* perform the specified reset action */
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP40G),
                    tmp_global_clock_disable_pp40g.wrd, ctl);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE PP40G SYS T41          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_clock_disable_pp40g_sys_t41(cs_uint16 dev_id,
                                                      cs_module_t module_num,
                                                      cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control disabling of the clock to the specified blocks.          */
/* The blocks that have clock disable set to CS_DISABLE are         */
/* inaccessible from the microprocessor port.  After the clock      */
/* disable to a block is written from CS_DISABLE to CS_ENABLE,      */
/* the software reset APIs should be used to reset the              */
/* affected block.                                                  */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one      */
/* of the following:                                                */
/*   CS_DISABLE (0) to disable the specified clock(s) or            */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API       */
/*   will generate the correct sense of the bit expected by the     */
/*   device.                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP40G_t tmp_global_clock_disable_pp40g;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_mpif_global_clock_disable_pp40g_sys_t41";  

  if (module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   module_num out of range", func);
    return (CS_ERROR);
  }

  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() FAILED!   ctl = 0x%04X\n", func, ctl);
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   T41 only feature.", func);
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_clock_disable_pp40g.wrd = 0;
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_clock_disable_pp40g.bf.sys_a = 1;
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_clock_disable_pp40g.bf.sys_b = 1;
  }

  /* perform the specified reset action */
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP40G),
                    tmp_global_clock_disable_pp40g.wrd, ctl);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE PP40G RX T41           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_clock_disable_pp40g_rx_t41(cs_uint16 dev_id,
                                                     cs_module_t module_num,
                                                     cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control disabling of the clock to the specified blocks.          */
/* The blocks that have clock disable set to CS_DISABLE are         */
/* inaccessible from the microprocessor port.  After the clock      */
/* disable to a block is written from CS_DISABLE to CS_ENABLE,      */
/* the software reset APIs should be used to reset the              */
/* affected block.                                                  */
/*                                                                  */
/* The [module_num] parameter is specified as:                      */
/*   0 = TEN_MODULE_A                                               */
/*   1 = TEN_MODULE_B                                               */
/*   2 = TEN_MODULE_A_AND_B                                         */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one      */
/* of the following:                                                */
/*   CS_DISABLE (0) to disable the specified clock(s) or            */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API       */
/*   will generate the correct sense of the bit expected by the     */
/*   device.                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_PP40G_t tmp_global_clock_disable_pp40g;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_mpif_global_clock_disable_pp40g_rx_t41";  

  if (module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   module_num out of range", func);
    return (CS_ERROR);
  }

  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, "%s() FAILED!   ctl = 0x%04X\n", func, ctl);
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() FAILED!   T41 only feature.", func);
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_clock_disable_pp40g.wrd = 0;
  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_clock_disable_pp40g.bf.rx_a = 1;
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_global_clock_disable_pp40g.bf.rx_b = 1;
  }

  /* perform the specified reset action */
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_PP40G),
                    tmp_global_clock_disable_pp40g.wrd, ctl);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE CFP T41                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_clock_disable_cfp_t41(cs_uint16 dev_id,
                                                cs_dir_t dir,
                                                cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control disabling of the clock to the specified blocks.          */
/* The blocks that have clock disable set to CS_DISABLE are         */
/* inaccessible from the microprocessor port.  After the clock      */
/* disable to a block is written from CS_DISABLE to CS_ENABLE,      */
/* the software reset APIs should be used to reset the              */
/* affected block.                                                  */
/*                                                                  */
/* The [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                      */
/*   1 = CS_RX                                                      */
/*   2 = CS_TX_AND_RX                                               */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one      */
/* of the following:                                                */
/*   CS_DISABLE (0) to disable the specified clock(s) or            */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API       */
/*   will generate the correct sense of the bit expected by the     */
/*   device.                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_CFP_t tmp_global_clock_disable_cfp;
  T41_t *pDev = NULL;

  if (dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": dir out of range");
    return (CS_ERROR);
  }

  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": T41 only feature.");
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_global_clock_disable_cfp.wrd = 0;
  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_cfp.bf.rx = 1;
  }

  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_global_clock_disable_cfp.bf.tx = 1;
  }

  /* perform the specified reset action */
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_CFP),
                    tmp_global_clock_disable_cfp.wrd, ctl);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF N10G RX IS ACTIVE                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_mpif_n10g_rx_is_active(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE or FALSE                                       */
/* DESCRIPTION:                                                     */
/* Returns TRUE if the specified N10G RX block is out of reset and  */
/* OTN is turned on, FALSE otherwise.                               */
/*                                                                  */
/* [module_id] specifies line's module ID                           */
/*   0xXX00 = Module A                                              */
/*   0xXX01 = Module B                                              */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8  n10g_reset;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  TEN_MPIF_GLOBAL_RESET_N10G_A_t tmp_global_reset_n10g;
  TEN_N10G_GBLR_DPCFG_t tmp_gblr_dpcfg;
  cs_boolean ret_val;

  CS_PRINT("ten_mpif_n10g_rx_is_active: mod_id=0x%04X, sl=%d\n",
           module_id, slice);

  /* Bugzilla #25991, fix static analyzer tool issues */
  if (slice > TEN_SLICE3) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return (FALSE);
  }

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, FALSE);

  /* Determine if n10g is in reset */
  if (module_id == TEN_MODULE_A) {
    tmp_addr  = TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_A);
  }
  else {
    tmp_addr  = TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_N10G_B);
  }
  tmp_global_reset_n10g.wrd = TEN_REG_READ(tmp_addr);
  n10g_reset = (1<<slice) & tmp_global_reset_n10g.wrd;

  if (n10g_reset == 0) {ret_val = TRUE;}
  else                 {ret_val = FALSE;}

  if (ret_val) {
    /* Determine if otnoff is on or off */
    tmp_addr  = TEN_N10G_REG_ADDR(pDev, module_id, slice, DPCFG);
    tmp_gblr_dpcfg.wrd = TEN_REG_READ(tmp_addr);

    if (tmp_gblr_dpcfg.bf.OTNOFF == 0) {ret_val = TRUE;}
    else                               {ret_val = FALSE;}
  }

  return(ret_val);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF PP10G RX IS ACTIVE                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_mpif_pp10g_rx_is_active(cs_uint16 module_id,
                                       cs_uint8  slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE or FALSE                                       */
/* DESCRIPTION:                                                     */
/* Returns TRUE if the specified PP10G RX block is out of reset     */
/* and xgpcs is turned, on FALSE otherwise.                         */
/*                                                                  */
/* [module_id] specifies line's module ID                           */
/*   0xXX00 = Module A                                              */
/*   0xXX01 = Module B                                              */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8  pp10g_reset;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  TEN_MPIF_GLOBAL_RESET_PP10G_A_t tmp_global_reset_pp10g;
  TEN_PP10G_MISC_CLKEN_LINE_RX_t  tmp_pp10g_misc_clken_line_rx;
  cs_boolean ret_val;

  CS_PRINT("ten_mpif_pp10g_rx_is_active: mod_id=0x%04X, sl=%d\n",
           module_id, slice);

  /* Bugzilla #25991, fix static analyzer tool issues */
  if (slice > TEN_SLICE3) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, FALSE);

  /* Determine if pp10g is in reset */
  if (module_id == TEN_MODULE_A) {
    tmp_addr  = TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_A);
  }
  else {
    tmp_addr  = TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_PP10G_B);
  }
  tmp_global_reset_pp10g.wrd = TEN_REG_READ(tmp_addr);
  pp10g_reset = (1<<slice) & tmp_global_reset_pp10g.wrd;

  if (pp10g_reset == 0) {ret_val = TRUE;}
  else                  {ret_val = FALSE;}

  if (ret_val) {
    /* Determine if xgpcs is on */
    tmp_addr  = TEN_PP10G_MISC_REG_ADDR(pDev, module_id, slice, CLKEN_LINE_RX);
    tmp_pp10g_misc_clken_line_rx.wrd = TEN_REG_READ(tmp_addr);

    if (tmp_pp10g_misc_clken_line_rx.bf.rx_en_xgpcs == 1) {ret_val = TRUE;}
    else                                                  {ret_val = FALSE;}
  }

  return(ret_val);
}

/* Bug 28921 start */
/********************************************************************/
/* $rtn_hdr_start  MPIF CUPLL IS IN HOLDOVER                        */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_mpif_cupll_in_holdover(cs_uint16 module_id,
                                      cs_uint8  slice)
/* INPUTS     : o Module Id                                         */
/*              o Slice                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE or FALSE                                       */
/* DESCRIPTION:                                                     */
/* Returns TRUE if the specified CUPLL is in Holdover, FALSE        */
/* otherwise.                                                       */
/*                                                                  */
/* [module_id] specifies line's module ID                           */
/*   0xXX00 = Module A                                              */
/*   0xXX01 = Module B                                              */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8  cupll_in_holdover;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  TEN_MPIF_CUPLL_HOLDOVER_STATUS_t tmp_mpif_cupll_holdover_status;
  cs_boolean ret_val = FALSE;

  CS_PRINT("ten_mpif_cupll_in_holdover: mod_id=0x%04X, sl=%d\n",
           module_id, slice);

  if (slice > TEN_SLICE3) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3.");
    return(FALSE);
  }

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, FALSE);

  /* Determine if CUPLL is in reset */
  tmp_addr  = TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_STATUS);
  tmp_mpif_cupll_holdover_status.wrd = TEN_REG_READ(tmp_addr);
  cupll_in_holdover = (1<<slice) & tmp_mpif_cupll_holdover_status.bf.REViO;

  if (cupll_in_holdover == 1) {ret_val = TRUE;}

  return(ret_val);
}
/* Bug 28921 end */

/********************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL CLOCK DISABLE CUPLL T41              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_global_clock_disable_cupll_t41(cs_uint16 dev_id,
                                                  cs_uint8  slice,
                                                  cs_ctl_t  ctl)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Control disabling of the clock to the specified blocks.          */
/* The blocks that have clock disable set to CS_DISABLE are         */
/* inaccessible from the microprocessor port.  After the clock      */
/* disable to a block is written from CS_DISABLE to CS_ENABLE,      */
/* the software reset APIs should be used to reset the              */
/* affected block.                                                  */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [ctl] parameter specifies the control option and is one      */
/* of the following:                                                */
/*   CS_DISABLE (0) to disable the specified clock(s) or            */
/*   CS_ENABLE (1) to enable the specified clock(s).  The API       */
/*   will generate the correct sense of the bit expected by the     */
/*   device.                                                        */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_CLOCK_DISABLE_CUPLL_t tmp_global_clock_disable_cupll;

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }

  if ((ctl != CS_DISABLE) && (ctl != CS_ENABLE)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": T41 only feature.");
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_clock_disable_cupll.wrd = 0;
  tmp_global_clock_disable_cupll.bf.tx = tmp;
  /* perform the specified reset action */
  ten_clock_disable(TEN_MPIF_REG_ADDR(pDev, GLOBAL_CLOCK_DISABLE_CUPLL),
                    tmp_global_clock_disable_cupll.wrd, ctl);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET CUPLL MPIF T41             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_cupll_mpif_t41(cs_uint16         dev_id,
                                               cs_uint8          slice,
                                               cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_CUPLL_t tmp_global_reset_cupll;

  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_cupll.wrd = 0;
  tmp_global_reset_cupll.bf.mpif = tmp;
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_CUPLL),
                   tmp_global_reset_cupll.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GET GLOBAL RESET CUPLL MPIF T41         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mpif_get_global_reset_cupll_mpif_t41(cs_uint16         dev_id,
                                                   cs_uint8          slice)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 0 or 1                                          */
/* DESCRIPTION:                                                 */
/* Returns the current state of hard reset.                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_CUPLL_t tmp_global_reset_cupll;

  if (slice <= TEN_SLICE3) {
    tmp = 1<<slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (0);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (0);
  }
  
  tmp_global_reset_cupll.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_CUPLL));
  return ((tmp_global_reset_cupll.bf.mpif & tmp) == tmp);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET CUPLL TX T41               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_cupll_tx_t41(cs_uint16         dev_id,
                                             cs_uint8          slice,
                                             cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_CUPLL_t tmp_global_reset_cupll;

  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_cupll.wrd = 0;
  tmp_global_reset_cupll.bf.tx = tmp;
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_CUPLL),
                   tmp_global_reset_cupll.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET CUPLL HOLDOVER T41         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_cupll_holdover_t41(cs_uint16         dev_id,
                                                   cs_uint8          holdover,
                                                   cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [holdover] parameter is specified as:                    */
/*   TEN_HOLDOVER0    = 0                                       */
/*   TEN_HOLDOVER1    = 1                                       */
/*   TEN_HOLDOVER2    = 2                                       */
/*   TEN_HOLDOVER3    = 3                                       */
/*   TEN_HOLDOVER4    = 4                                       */
/*   TEN_HOLDOVER5    = 5                                       */
/*   TEN_HOLDOVER6    = 6                                       */
/*   TEN_HOLDOVER7    = 7                                       */
/*   TEN_HOLDOVER_ALL = 0xFF                                    */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_GLOBAL_RESET_CUPLL_t tmp_global_reset_cupll;

  if(act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": act out of range");
    return(CS_ERROR);
  }

  if (holdover == TEN_HOLDOVER_ALL) {
    tmp = 0x00FF;
  }
  else if (holdover < TEN_MAX_HOLDOVER) {
    tmp = 1 << holdover;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": holdover out of range.  s/b 0..7, 0xFF.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return(CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_cupll.wrd = 0;
  tmp_global_reset_cupll.bf.holdover = tmp;
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_CUPLL),
                   tmp_global_reset_cupll.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF CUPLL LOCAL FORCE                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_cupll_local_force_t41(cs_uint16 dev_id,
                                         cs_uint8  slice,
                                         cs_uint8  select,
                                         cs_ctl_t  ctl)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Select                                        */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register allows software to configure how the CUPLL     */
/* will enter local clock generation mode.                      */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   0 = on                                                     */
/*   1 = off                                                    */
/*   2 = follow                                                 */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   on:                                                        */
/*   0 =                                                        */
/*   1 = Force CUPLL local mode =1                              */
/*                                                              */
/*   off:                                                       */
/*   0 =                                                        */
/*   1 = Force CUPLL local mode =0 as long as on is not set     */
/*                                                              */
/*   follow:                                                    */
/*   0 =                                                        */
/*   1 = CUPLL local mode will follow the                       */
/*       CLOCK_SWITCH_STATUS.TXBiO                              */
/*                                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  cs_status rtn = CS_OK;
  TEN_MPIF_CUPLL_LOCAL_FORCE_t tmp_cupll_local_force;

  if (ctl > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_cupll_local_force.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_LOCAL_FORCE));

  switch (select) {
    case 0:
      if (ctl == 1) {
        tmp_cupll_local_force.bf.on |= tmp;
      }
      else {
        tmp_cupll_local_force.bf.on &= ~tmp;
      }
      break;

    case 1:
      if (ctl == 1) {
        tmp_cupll_local_force.bf.off |= tmp;
      }
      else {
        tmp_cupll_local_force.bf.off &= ~tmp;
      }
      break;

    case 2:
      if (ctl == 1) {
        tmp_cupll_local_force.bf.follow |= tmp;
      }
      else {
        tmp_cupll_local_force.bf.follow &= ~tmp;
      }
      break;

    default:
      CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                    ": default, select out of range.");
      rtn = CS_ERROR;
      break;
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CUPLL_LOCAL_FORCE), tmp_cupll_local_force.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF CUPLL SETTLE FORCE                      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_cupll_settle_force_t41(cs_uint16 dev_id,
                                         cs_uint8   slice,
                                         cs_uint8   select,
                                         cs_ctl_t   ctl)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Select                                        */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register allows software to configure CUPLL settling    */
/* mode.                                                        */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   0 = fast                                                   */
/*   1 = slow                                                   */
/*   2 = settle                                                 */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   fast:                                                      */
/*   0 =                                                        */
/*   1 = Force CUPLL settling to fast mode                      */
/*                                                              */
/*   slow:                                                      */
/*   0 =                                                        */
/*   1 = Force CUPLL settling to slow mode                      */
/*                                                              */
/*   settle:                                                    */
/*   0 =                                                        */
/*   1 = Force CUPLL to re-settling using the programmed timer  */
/*       value                                                  */
/*                                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  cs_status rtn = CS_OK;
  TEN_MPIF_CUPLL_SETTLE_FORCE_t tmp_cupll_settle_force;

  if (ctl > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_cupll_settle_force.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_FORCE));

  switch (select) {
    case 0:
      if (ctl == 1) {
        tmp_cupll_settle_force.bf.fast |= tmp;
      }
      else {
        tmp_cupll_settle_force.bf.fast &= ~tmp;
      }
      break;

    case 1:
      if (ctl == 1) {
        tmp_cupll_settle_force.bf.slow |= tmp;
      }
      else {
        tmp_cupll_settle_force.bf.slow &= ~tmp;
      }
      break;

    case 2:
      if (ctl == 1) {
        tmp_cupll_settle_force.bf.settle |= tmp;
      }
      else {
        tmp_cupll_settle_force.bf.settle &= ~tmp;
      }
      break;

    default:
      CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                    ": default, select out of range.");
      rtn = CS_ERROR;
      break;
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_FORCE), tmp_cupll_settle_force.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CUPLL SETTLE TIMER                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_cupll_settle_timer_t41(cs_uint16 dev_id,
                                          cs_uint8  slice, 
                                          cs_uint16 timer)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Timer                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* This register allows software to configure CUPLL settling mode   */
/* timer.                                                           */
/*   CUPLL fast settle duration = (mpif_clk period * 256 * timer)   */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* The [timer] parameter is specified as:                           */
/*   0x0000..0xFFFF                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint8 sl;
  TEN_MPIF_CUPLL_SETTLE_TIMER0_t tmp_mpif_cupll_settle_timer0_cfg;
  T41_t *pDev = NULL;

  if ((slice >= TEN_MAX_SLICES) && (slice != TEN_SLICE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  for (sl=0; sl<TEN_MAX_SLICES; sl++) {
    if ((slice == sl) || (slice == TEN_SLICE_ALL)) {
    
      if (sl == 0) {
        tmp_mpif_cupll_settle_timer0_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER0));
      }
      else if (sl == 1) {
        tmp_mpif_cupll_settle_timer0_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER1));
      }
      else if (sl == 2) {
        tmp_mpif_cupll_settle_timer0_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER2));
      }
      else {
        tmp_mpif_cupll_settle_timer0_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER3));
      }
      
      tmp_mpif_cupll_settle_timer0_cfg.bf.timer = timer;
      
      if (sl == 0) {
        TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER0), tmp_mpif_cupll_settle_timer0_cfg.wrd);
      }
      else if (sl == 1) {
        TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER1), tmp_mpif_cupll_settle_timer0_cfg.wrd);
      }
      else if (sl == 2) {
        TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER2), tmp_mpif_cupll_settle_timer0_cfg.wrd);
      }
      else {
        TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CUPLL_SETTLE_TIMER3), tmp_mpif_cupll_settle_timer0_cfg.wrd);
      }
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT PILOT                          */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_clock_select_pilot(cs_uint16 dev_id, 
                                  cs_uint16 pilot_rxa2b)
/* INPUTS     : o Device Id                                         */
/*              o Pilot Rxa2b                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Allows software to override the clock source selection to        */
/* TX Module B HSIF block when in protection mode.                  */
/* After the clock selects are modfified, software should           */
/* also reset the affected blocks.                                  */
/*                                                                  */
/* [pilot_rxa2b]                                                    */
/*   When '0', the fractional divider output pilot tone used for    */
/*   the B-side XFI SerDes input is also used for the B-side        */
/*   Multi-rate SerDes input.                                       */
/*   When '1', the fractional divider output pilot tone used for    */
/*   the A-side Multi-rate SerDes input is also used for the B-side */
/*   Multi-rate SerDes input.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_MPIF_CLOCK_SELECT_PILOT_t tmp_clock_select_pilot;
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_clock_select_pilot.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PILOT));
  tmp_clock_select_pilot.bf.pilot_rxa2b = pilot_rxa2b;
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PILOT), tmp_clock_select_pilot.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT PILOT PER SLICE                */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_clock_select_pilot_per_slice(cs_uint16 dev_id, 
                                                cs_uint8  slice,
                                                cs_uint16 pilot_rxa2b)
/* INPUTS     : o Device Id                                         */
/*              o Slice                                             */
/*              o Pilot Rxa2b                                       */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Allows software to override the clock source selection to        */
/* TX Module B HSIF block when in protection mode.                  */
/* After the clock selects are modified, software should            */
/* also reset the affected blocks.                                  */
/*                                                                  */
/* The [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                              */
/*   0x01 = TEN_SLICE1                                              */
/*   0x02 = TEN_SLICE2                                              */
/*   0x03 = TEN_SLICE3                                              */
/*   0xFF = TEN_SLICE_ALL                                           */
/*                                                                  */
/* [pilot_rxa2b]                                                    */
/*   When '0', the fractional divider output pilot tone used for    */
/*   the B-side XFI SerDes input is also used for the B-side        */
/*   Multi-rate SerDes input.                                       */
/*   When '1', the fractional divider output pilot tone used for    */
/*   the A-side Multi-rate SerDes input is also used for the B-side */
/*   Multi-rate SerDes input.                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_CLOCK_SELECT_PILOT_t tmp_clock_select_pilot;

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_clock_select_pilot.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PILOT));
  if (pilot_rxa2b) {
    tmp_clock_select_pilot.bf.pilot_rxa2b |= tmp;
  }
  else {
    tmp_clock_select_pilot.bf.pilot_rxa2b &= ~tmp;
  }
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_PILOT), tmp_clock_select_pilot.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF MR PROT CFG CLK XLOS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_mr_prot_cfg_clk_xlos(cs_uint16 dev_id, 
                                    cs_uint8  slice,
                                    cs_dir_t  dir,
                                    cs_uint16 clk_xlos)
/*              o Slice                                         */
/*              o Direction                                     */
/*              o CLK XLOS                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables control of clock switching for Multi-Rate SerDes     */
/* protection.                                                  */
/*                                                              */
/* [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* [clk_xlos]                                                   */
/*   Enable MR SERDES protection TX and/or RX clock switching   */
/*   to be controlled by the filtered MRA_EXT_LOS input.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_MR_PROT_CFG_t tmp_mr_prot_cfg;
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }
  
  if (dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,  ": dir out of range");
    return (CS_ERROR);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_mr_prot_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MR_PROT_CFG));

  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_mr_prot_cfg.bf.txclk_xlos = tmp;
  }

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_mr_prot_cfg.bf.rxclk_xlos = tmp;
  }
  
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, MR_PROT_CFG), tmp_mr_prot_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF MR PROT CFG CLK PSWTCHEN                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_mr_prot_cfg_clk_pswtchen(cs_uint16 dev_id, 
                                    cs_uint8  slice,
                                    cs_dir_t  dir,
                                    cs_uint16 clk_pswtchen)
/*              o Slice                                         */
/*              o Direction                                     */
/*              o CLK PSWTCHEN                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables control of clock switching for Multi-Rate SerDes     */
/* protection.                                                  */
/*                                                              */
/* [slice] parameter is specified as:                           */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* [dir] parameter is specified as:                             */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/*  [clk_pswtchen]                                              */
/*   Enable MR SERDES protection TX and/or RX clock switching   */
/*   to be controlled through the parallel OH interface.        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_MR_PROT_CFG_t tmp_mr_prot_cfg;
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }
  
  if (dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,  ": dir out of range");
    return (CS_ERROR);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  tmp_mr_prot_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MR_PROT_CFG));

  if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    tmp_mr_prot_cfg.bf.txclk_pswtchen = tmp;
  }

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    tmp_mr_prot_cfg.bf.rxclk_pswtchen = tmp;
  }
  
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, MR_PROT_CFG), tmp_mr_prot_cfg.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF RXDIV CFG0 MODE                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_rxdiv_cfg0_mode_t41(cs_uint16 dev_id,
                                       cs_uint8  instance, 
                                       cs_uint16 mode)
/* INPUTS     : o Device Id                                         */
/*              o Instance                                          */
/*              o Mode                                              */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Source Selection for RXi_DIV output.                    */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..7                                                           */
/*                                                                  */
/* The [mode] parameter is specified as:                            */
/*   0 = RXDIV from RX controllable divider & protection mux,       */
/*       t40 mode                                                   */
/*   1 = RXDIV from internal pilot, no divider, same as protection  */
/*       mux pilot input                                            */
/*   2 = RXDIV from internal pilot, after divider & mux,            */
/*       see RXDIV_CFGi.pilot and PILOT_DIVi                        */
/*   3 = RXDIV from RX Line, after divider & mux,                   */
/*       see RXDIV_CFGi.rx_sel and RXLINE_DIVi                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_MPIF_RXDIV_CFG0_t tmp_mpif_rxdiv_cfg;
  cs_char8 *func = "ten_mpif_rxdiv_cfg0_mode_t41";


  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  /* Bugzilla #30812, Bus errors in T40 */
  if (!ten_dev_is_t41(dev_id)) {
    CS_PRINT("%s() T41 only feature.\n", func);
    return (CS_OK);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* Broken out with a case statement to satisfy Klocwork */
  switch (instance) {
    case 0:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG0));
      tmp_mpif_rxdiv_cfg.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG0), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 1:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG1));
      tmp_mpif_rxdiv_cfg.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG1), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 2:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG2));
      tmp_mpif_rxdiv_cfg.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG2), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 3:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG3));
      tmp_mpif_rxdiv_cfg.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG3), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 4:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG4));
      tmp_mpif_rxdiv_cfg.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG4), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 5:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG5));
      tmp_mpif_rxdiv_cfg.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG5), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 6:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG6));
      tmp_mpif_rxdiv_cfg.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG6), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 7:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG7));
      tmp_mpif_rxdiv_cfg.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG7), tmp_mpif_rxdiv_cfg.wrd);
      break;
    default:
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, "%s()  instance %d out of range.  s/b 0..%d", func, instance, TEN_MPIF_RXDIV_CFG0_COUNT-1);
      rtn = CS_ERROR;
      break;
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF RXDIV CFG0 PILOT                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_rxdiv_cfg0_pilot_t41(cs_uint16 dev_id,
                                        cs_uint8  instance, 
                                        cs_uint16 pilot)
/* INPUTS     : o Device Id                                         */
/*              o Instance                                          */
/*              o Pilot                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets the Source Selection for RXi_DIV output, divided pilot      */
/* clock option.                                                    */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..7                                                           */
/*                                                                  */
/* The [pilot] parameter is specified as:                           */
/*   0 = RX Module A internal pilot #1 clock after divder,          */
/*       see PILOT_DIV0                                             */
/*   1 = RX Module A internal pilot #2 clock after divder,          */
/*       see PILOT_DIV1                                             */
/*   2 = RX Module A internal pilot #2 clock after divder,          */
/*       see PILOT_DIV2                                             */
/*   3 = RX Module A internal pilot #4 clock after divder,          */
/*       see PILOT_DIV3                                             */
/*   4 = RX Module B internal pilot #1 clock after divder,          */
/*       see PILOT_DIV4                                             */
/*   5 = RX Module B internal pilot #2 clock after divder,          */
/*       see PILOT_DIV5                                             */
/*   6 = RX Module B internal pilot #3 clock after divder,          */
/*       see PILOT_DIV6                                             */
/*   7 = RX Module B internal pilot #4 clock after divder,          */
/*       see PILOT_DIV7                                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_MPIF_RXDIV_CFG0_t tmp_mpif_rxdiv_cfg;


  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* Broken out with a case statement to satisfy Klocwork */
  switch (instance) {
    case 0:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG0));
      tmp_mpif_rxdiv_cfg.bf.pilot = pilot;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG0), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 1:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG1));
      tmp_mpif_rxdiv_cfg.bf.pilot = pilot;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG1), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 2:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG2));
      tmp_mpif_rxdiv_cfg.bf.pilot = pilot;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG2), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 3:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG3));
      tmp_mpif_rxdiv_cfg.bf.pilot = pilot;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG3), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 4:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG4));
      tmp_mpif_rxdiv_cfg.bf.pilot = pilot;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG4), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 5:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG5));
      tmp_mpif_rxdiv_cfg.bf.pilot = pilot;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG5), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 6:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG6));
      tmp_mpif_rxdiv_cfg.bf.pilot = pilot;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG6), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 7:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG7));
      tmp_mpif_rxdiv_cfg.bf.pilot = pilot;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG7), tmp_mpif_rxdiv_cfg.wrd);
      break;
    default:
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..%d",TEN_MPIF_RXDIV_CFG0_COUNT-1);
      rtn = CS_ERROR;
      break;
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF RXDIV CFG0 RX SEL                           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_rxdiv_cfg0_rx_sel_t41(cs_uint16 dev_id,
                                         cs_uint8  instance, 
                                         cs_uint16 rx_sel)
/* INPUTS     : o Device Id                                         */
/*              o Instance                                          */
/*              o Rx Sel                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Source Selection for RXi_DIV output,                        */
/* divided RX Line clock option.                                    */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..7                                                           */
/*                                                                  */
/* The [rx_sel] parameter is specified as:                          */
/* 0=RX Module A GPLL #1 output clk, after divder, see RXLINE_DIV0  */
/* 1=RX Module A GPLL #2 output clk, after divder, see RXLINE_DIV1  */
/* 2=RX Module A GPLL #3 output clk, after divder, see RXLINE_DIV2  */
/* 3=RX Module A GPLL #4 output clk, after divder, see RXLINE_DIV3  */
/* 4=RX Module B GPLL #1 output clk, after divder, see RXLINE_DIV4  */
/* 5=RX Module B GPLL #2 output clk, after divder, see RXLINE_DIV5  */
/* 6=RX Module B GPLL #3 output clk, after divder, see RXLINE_DIV6  */
/* 7=RX Module B GPLL #4 output clk, after divder, see RXLINE_DIV7  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_MPIF_RXDIV_CFG0_t tmp_mpif_rxdiv_cfg;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  if (!ten_dev_is_t41(dev_id)) {
    CS_PRINT("T41 only feature.");
    return (CS_OK);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* Broken out with a case statement to satisfy Klocwork */
  switch (instance) {
    case 0:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG0));
      tmp_mpif_rxdiv_cfg.bf.rx_sel = rx_sel;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG0), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 1:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG1));
      tmp_mpif_rxdiv_cfg.bf.rx_sel = rx_sel;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG1), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 2:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG2));
      tmp_mpif_rxdiv_cfg.bf.rx_sel = rx_sel;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG2), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 3:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG3));
      tmp_mpif_rxdiv_cfg.bf.rx_sel = rx_sel;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG3), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 4:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG4));
      tmp_mpif_rxdiv_cfg.bf.rx_sel = rx_sel;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG4), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 5:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG5));
      tmp_mpif_rxdiv_cfg.bf.rx_sel = rx_sel;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG5), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 6:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG6));
      tmp_mpif_rxdiv_cfg.bf.rx_sel = rx_sel;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG6), tmp_mpif_rxdiv_cfg.wrd);
      break;
    case 7:
      tmp_mpif_rxdiv_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG7));
      tmp_mpif_rxdiv_cfg.bf.rx_sel = rx_sel;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXDIV_CFG7), tmp_mpif_rxdiv_cfg.wrd);
      break;
    default:
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..%d",TEN_MPIF_RXDIV_CFG0_COUNT-1);
      rtn = CS_ERROR;
      break;
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF PILOT DIV                                   */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_pilot_div(cs_uint16 dev_id,
                             cs_uint8  instance, 
                             cs_uint16 div)
/* INPUTS     : o Device Id                                         */
/*              o Instance                                          */
/*              o Pilot                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Divide Ratio for the internal pilot clock.                       */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..7                                                           */
/*                                                                  */
/* The [div] parameter is specified as:                             */
/*   0 = Divide by 2                                                */
/*   1 = Divide by 4                                                */
/*   2 = Divide by 8                                                */
/*   3 = Divide by 16                                               */
/*   4 = Divide by 32                                               */
/*   5 = Divide by 1                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_MPIF_PILOT_DIV0_t tmp_mpif_pilot_div_cfg;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* Broken out with a case statement to satisfy Klocwork */
  switch (instance) {
    case 0:
      tmp_mpif_pilot_div_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV0));
      tmp_mpif_pilot_div_cfg.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV0), tmp_mpif_pilot_div_cfg.wrd);
      break;
    case 1:
      tmp_mpif_pilot_div_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV1));
      tmp_mpif_pilot_div_cfg.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV1), tmp_mpif_pilot_div_cfg.wrd);
      break;
    case 2:
      tmp_mpif_pilot_div_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV2));
      tmp_mpif_pilot_div_cfg.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV2), tmp_mpif_pilot_div_cfg.wrd);
      break;
    case 3:
      tmp_mpif_pilot_div_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV3));
      tmp_mpif_pilot_div_cfg.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV3), tmp_mpif_pilot_div_cfg.wrd);
      break;
    case 4:
      tmp_mpif_pilot_div_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV4));
      tmp_mpif_pilot_div_cfg.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV4), tmp_mpif_pilot_div_cfg.wrd);
      break;
    case 5:
      tmp_mpif_pilot_div_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV5));
      tmp_mpif_pilot_div_cfg.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV5), tmp_mpif_pilot_div_cfg.wrd);
      break;
    case 6:
      tmp_mpif_pilot_div_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV6));
      tmp_mpif_pilot_div_cfg.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV6), tmp_mpif_pilot_div_cfg.wrd);
      break;
    case 7:
      tmp_mpif_pilot_div_cfg.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV7));
      tmp_mpif_pilot_div_cfg.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, PILOT_DIV7), tmp_mpif_pilot_div_cfg.wrd);
      break;
    default:
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..%d",TEN_MPIF_PILOT_DIV0_COUNT-1);
      rtn = CS_ERROR;
      break;
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF RXLINE DIV                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_rxline_div0_div_t41(cs_uint16 dev_id, 
                                       cs_uint8 instance, 
                                       cs_uint16 div)
/* INPUTS     : o Device Id                                         */
/*              o Instance                                          */
/*              o Div                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets RX Line divider configuration.                              */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..7                                                           */
/*                                                                  */
/* The [div] parameter is specified as:                             */
/*   Divide Ratio for RX Line GPLL output clock.                    */
/*   Register 0-3 for RX-A 0-3; register 4-7 for RX-B 0-3.          */
/*   0 = Divide by 2                                                */
/*   1 = Divide by 4                                                */
/*   2 = Divide by 8                                                */
/*   3 = Divide by 16                                               */
/*   4 = Divide by 32                                               */
/*   5 = Divide by 1                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_MPIF_RXLINE_DIV0_t tmp_mpif_rxline_div;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  if (!ten_dev_is_t41(dev_id)) {
    CS_PRINT("T41 only feature.");
    return (CS_OK);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* Broken out with a case statement to satisfy Klocwork */
  switch (instance) {
    case 0:
      tmp_mpif_rxline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV0));
      tmp_mpif_rxline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV0), tmp_mpif_rxline_div.wrd);
      break;
    case 1:
      tmp_mpif_rxline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV1));
      tmp_mpif_rxline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV1), tmp_mpif_rxline_div.wrd);
      break;
    case 2:
      tmp_mpif_rxline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV2));
      tmp_mpif_rxline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV2), tmp_mpif_rxline_div.wrd);
      break;
    case 3:
      tmp_mpif_rxline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV3));
      tmp_mpif_rxline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV3), tmp_mpif_rxline_div.wrd);
      break;
    case 4:
      tmp_mpif_rxline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV4));
      tmp_mpif_rxline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV4), tmp_mpif_rxline_div.wrd);
      break;
    case 5:
      tmp_mpif_rxline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV5));
      tmp_mpif_rxline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV5), tmp_mpif_rxline_div.wrd);
      break;
    case 6:
      tmp_mpif_rxline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV6));
      tmp_mpif_rxline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV6), tmp_mpif_rxline_div.wrd);
      break;
    case 7:
      tmp_mpif_rxline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV7));
      tmp_mpif_rxline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, RXLINE_DIV7), tmp_mpif_rxline_div.wrd);
      break;
    default:
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..%d",TEN_MPIF_RXLINE_DIV0_COUNT-1);
      rtn = CS_ERROR;
      break;
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF TXLINE DIV                                  */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_txline_div0_div_t41(cs_uint16 dev_id, 
                                       cs_uint8 instance, 
                                       cs_uint16 div)
/* INPUTS     : o Device Id                                         */
/*              o Instance                                          */
/*              o Div                                               */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets TX Line divider configuration.                              */
/*                                                                  */
/* The [instance] parameter is specified as:                        */
/*   0..7                                                           */
/*                                                                  */
/* The [div] parameter is specified as:                             */
/*   Divide Ratio for TX Line GPLL output clock.                    */
/*   Register 0-3 for TX-A 0-3; register 4-7 for TX-B 0-3.          */
/*   0 = Divide by 2                                                */
/*   1 = Divide by 4                                                */
/*   2 = Divide by 8                                                */
/*   3 = Divide by 16                                               */
/*   4 = Divide by 32                                               */
/*   5 = Divide by 1                                                */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_MPIF_TXLINE_DIV0_t tmp_mpif_txline_div;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  if (!ten_dev_is_t41(dev_id)) {
    CS_PRINT("T41 only feature.");
    return (CS_OK);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* Broken out with a case statement to satisfy Klocwork */
  switch (instance) {
    case 0:
      tmp_mpif_txline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV0));
      tmp_mpif_txline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV0), tmp_mpif_txline_div.wrd);
      break;
    case 1:
      tmp_mpif_txline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV1));
      tmp_mpif_txline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV1), tmp_mpif_txline_div.wrd);
      break;
    case 2:
      tmp_mpif_txline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV2));
      tmp_mpif_txline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV2), tmp_mpif_txline_div.wrd);
      break;
    case 3:
      tmp_mpif_txline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV3));
      tmp_mpif_txline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV3), tmp_mpif_txline_div.wrd);
      break;
    case 4:
      tmp_mpif_txline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV4));
      tmp_mpif_txline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV4), tmp_mpif_txline_div.wrd);
      break;
    case 5:
      tmp_mpif_txline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV5));
      tmp_mpif_txline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV5), tmp_mpif_txline_div.wrd);
      break;
    case 6:
      tmp_mpif_txline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV6));
      tmp_mpif_txline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV6), tmp_mpif_txline_div.wrd);
      break;
    case 7:
      tmp_mpif_txline_div.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV7));
      tmp_mpif_txline_div.bf.div = div;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXLINE_DIV7), tmp_mpif_txline_div.wrd);
      break;
    default:
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..%d",TEN_MPIF_TXLINE_DIV0_COUNT-1);
      rtn = CS_ERROR;
      break;
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (rtn);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF TXDIV CFG MODE 1                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_txdiv_cfg0_mode1_t41(cs_uint16 dev_id, 
                                        cs_uint8 instance, 
                                        cs_uint16 mode1)
/* INPUTS     : o Device Id                                         */
/*              o Instance                                          */
/*              o Mode1                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Source Selection for TXi_DIV output.                        */
/*                                                                  */
/* [mode1]                                                          */
/*  0 = TXDIV the same as TXsyncdsync pdo input                     */
/*      (output of mux controlled by mode)                          */
/*  1 = TXDIV from internal pilot                                   */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_MPIF_TXDIV_CFG0_t tmp_txdiv_cfg0;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  if (!ten_dev_is_t41(dev_id)) {
    CS_PRINT("T41 only feature.");
    return (CS_OK);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  
  /* Broken out with a case statement to satisfy Klocwork */
  switch (instance) {
    case 0:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG0));
      tmp_txdiv_cfg0.bf.mode1 = mode1;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG0), tmp_txdiv_cfg0.wrd);
      break;
    case 1:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG1));
      tmp_txdiv_cfg0.bf.mode1 = mode1;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG1), tmp_txdiv_cfg0.wrd);
      break;
    case 2:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG2));
      tmp_txdiv_cfg0.bf.mode1 = mode1;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG2), tmp_txdiv_cfg0.wrd);
      break;
    case 3:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG3));
      tmp_txdiv_cfg0.bf.mode1 = mode1;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG3), tmp_txdiv_cfg0.wrd);
      break;
    case 4:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG4));
      tmp_txdiv_cfg0.bf.mode1 = mode1;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG4), tmp_txdiv_cfg0.wrd);
      break;
    case 5:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG5));
      tmp_txdiv_cfg0.bf.mode1 = mode1;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG5), tmp_txdiv_cfg0.wrd);
      break;
    case 6:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG6));
      tmp_txdiv_cfg0.bf.mode1 = mode1;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG6), tmp_txdiv_cfg0.wrd);
      break;
    case 7:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG7));
      tmp_txdiv_cfg0.bf.mode1 = mode1;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG7), tmp_txdiv_cfg0.wrd);
      break;
    default:
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..%d", TEN_MPIF_TXDIV_CFG0_COUNT-1);
      rtn = CS_ERROR;
      break;
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  MPIF TXDIV CFG MODE                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : MPIF                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_mpif_txdiv_cfg0_mode_t41(cs_uint16 dev_id, 
                                       cs_uint8 instance, 
                                       cs_uint16 mode)
/* INPUTS     : o Device Id                                         */
/*              o Instance                                          */
/*              o Mode1                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets Source Selection for TXi_DIV output.                        */
/*                                                                  */
/* [mode]                                                           */
/*   0 = TXDIV & TXsyncdsync pdo input from                         */ 
/*       TX controllable divider, t40 mode                          */
/*   1 = TXDIV & TXsyncdsync pdo input from TX Line,                */
/*       after divider, see TXLINE_DIVi                             */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_MPIF_TXDIV_CFG0_t tmp_txdiv_cfg0;

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  if (!ten_dev_is_t41(dev_id)) {
    CS_PRINT("T41 only feature.");
    return (CS_OK);
  }
  
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  
  /* Broken out with a case statement to satisfy Klocwork */
  switch (instance) {
    case 0:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG0));
      tmp_txdiv_cfg0.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG0), tmp_txdiv_cfg0.wrd);
      break;
    case 1:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG1));
      tmp_txdiv_cfg0.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG1), tmp_txdiv_cfg0.wrd);
      break;
    case 2:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG2));
      tmp_txdiv_cfg0.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG2), tmp_txdiv_cfg0.wrd);
      break;
    case 3:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG3));
      tmp_txdiv_cfg0.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG3), tmp_txdiv_cfg0.wrd);
      break;
    case 4:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG4));
      tmp_txdiv_cfg0.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG4), tmp_txdiv_cfg0.wrd);
      break;
    case 5:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG5));
      tmp_txdiv_cfg0.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG5), tmp_txdiv_cfg0.wrd);
      break;
    case 6:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG6));
      tmp_txdiv_cfg0.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG6), tmp_txdiv_cfg0.wrd);
      break;
    case 7:
      tmp_txdiv_cfg0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG7));
      tmp_txdiv_cfg0.bf.mode = mode;
      TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, TXDIV_CFG7), tmp_txdiv_cfg0.wrd);
      break;
    default:
      CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": instance out of range.  s/b 0..%d", TEN_MPIF_TXDIV_CFG0_COUNT-1);
      rtn = CS_ERROR;
      break;
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF CUPLL HOLDOVER LOCKDET                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_cupll_holdover_lockdet(cs_uint16 dev_id,
                                          cs_uint8  slice,
                                          cs_uint8  select,
                                          cs_ctl_t  ctl)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Select                                        */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register allows software to enable CUPLL holdover mode, */
/* when LOCKDET failures occur. This holdover control is        */
/* multiplexed from RX to TX using the same mux selection       */
/* used for the RX divided clock, see                           */
/* SYNCDSYNCTX_CFGTX_CFG.RX_DIV_MUX.                            */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   0 = mra                                                    */
/*   1 = mrb                                                    */
/*   2 = xfi                                                    */
/*   3 = mrb2a                                                  */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 =                                                        */
/*   1 = The Filtered LOCKDET alarm associated with the         */
/*       selected interface will cause the CUPLL                */
/*       to enter holdover mode                                 */
/*                                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  cs_status rtn = CS_OK;
  TEN_MPIF_CUPLL_HOLDOVER_LOCKDET_t tmp_cupll_holdover_lockdet;

  if (ctl > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }

  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_cupll_holdover_lockdet.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_LOCKDET));

  switch (select) {
    case 0:
      if (ctl == 1) {
        tmp_cupll_holdover_lockdet.bf.mra |= tmp;
      }
      else {
        tmp_cupll_holdover_lockdet.bf.mra &= ~tmp;
      }
      break;

    case 1:
      if (ctl == 1) {
        tmp_cupll_holdover_lockdet.bf.mrb |= tmp;
      }
      else {
        tmp_cupll_holdover_lockdet.bf.mrb &= ~tmp;
      }
      break;

    case 2:
      if (ctl == 1) {
        tmp_cupll_holdover_lockdet.bf.xfi |= tmp;
      }
      else {
        tmp_cupll_holdover_lockdet.bf.xfi &= ~tmp;
      }
      break;

    case 3:
      if (ctl == 1) {
        tmp_cupll_holdover_lockdet.bf.mrb2a |= tmp;
      }
      else {
        tmp_cupll_holdover_lockdet.bf.mrb2a &= ~tmp;
      }
      break;

    default:
      CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                    ": default, select out of range.");
      rtn = CS_ERROR;
      break;
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_LOCKDET), tmp_cupll_holdover_lockdet.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (rtn);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF CUPLL HOLDOVER SELECT                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_cupll_holdover_select(cs_uint16 dev_id,
                                         cs_uint8  slice,
                                         cs_ctl_t  ctl)
/* INPUTS     : o Device Id                                     */
/*              o Slice                                         */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This register allows software to choose which TX datapath    */
/* to associate with each CUPLL holdover signal. When the       */
/* holdover signal is active, each TX datapath can be enabled   */
/* to assert TX alarm data.                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0, source of holdover input for CUPLL 0    */
/*   0x01 = TEN_SLICE1, source of holdover input for CUPLL 1    */
/*   0x02 = TEN_SLICE2, source of holdover input for CUPLL 2    */
/*   0x03 = TEN_SLICE3, source of holdover input for CUPLL 3    */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = holdover associated with TX datapath A1                */
/*   1 = holdover associated with TX datapath A2                */
/*   2 = holdover associated with TX datapath A3                */
/*   3 = holdover associated with TX datapath A4                */
/*   4 = holdover associated with TX datapath B1                */
/*   5 = holdover associated with TX datapath B2                */
/*   6 = holdover associated with TX datapath B3                */
/*   7 = holdover associated with TX datapath B4                */
/*                                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status rtn = CS_OK;
  TEN_MPIF_CUPLL_HOLDOVER_SELECT_t tmp_cupll_holdover_select;

  if (ctl > 7) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": ctl = 0x%04X\n", ctl);
      return (CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_cupll_holdover_select.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_SELECT));

  switch (slice) {
    case 0:
      tmp_cupll_holdover_select.bf.sel0 = ctl;
      break;

    case 1:
      tmp_cupll_holdover_select.bf.sel1 = ctl;
      break;

    case 2:
      tmp_cupll_holdover_select.bf.sel2 = ctl;
      break;

    case 3:
      tmp_cupll_holdover_select.bf.sel3 = ctl;
      break;

    default:
      CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                    ": default, slice out of range.");
      rtn = CS_ERROR;
      break;
  }

  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_SELECT), tmp_cupll_holdover_select.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (rtn);
}

/****************************************************************/
/* Bugzilla 30990, hi res timer required.                       */
/*                                                              */
/* This high-res timer uses the lower 32 bits of the MPIF       */
/* miscellaneous counter register. The counter is read in a     */
/* busy wait loop until the requested time has elaspsed.        */
/*                                                              */
/* The timer's resolution adapts to the system to make the      */
/* timer as accurate as possible. Its resolution is a function  */
/* of register read time and system clock. Although an          */
/* environment may support a very high resolution, the CS6040   */
/* driver is tested at the default access time of TEN_MPIF_     */
/* UDELAY_DEFAULT_ACC_TIME_USEC. Thus, a warning message is     */
/* printed when a shorter duration than the default read access */
/* time is requested.                                           */
/*                                                              */
/* A distinction is made between register access via network    */
/* (slow access) via on-board (fast). This is because the       */
/* finest possible resolution of this busy-wait timer is the    */
/* time for one register access. The slow access rate (over the */
/* network) is on the same order as the increment rate of MISC_ */
/* COUNTER1, rendering MISC_COUNTER0 useless and its reads      */
/* costly. So when MPIF access is characterized as "slow", via  */
/* a network,                                                   */
/* o For delay requests longer than 12 or so access times, the  */
/*   MPIF UDELAY timer reads only MISC_COUNTER1 to time the     */
/*   busy wait. These require a minimum of 4 register reads.    */
/* o For shorter delay requests, blind reads are done in a loop */
/*   until their cumulative access times add up to the          */
/*   requested duration.                                        */
/*                                                              */
/* When MPIF access is characterized as normal, not via a       */
/* network,                                                     */
/* o For delay requests longer than 18 or so access times,      */
/*   MISC_COUNTER1 and MISC_COUNTER0 are used together to time  */
/*   busy waits. These require a minimum of 6 register reads.   */
/* o For shorter delay requests, blind reads are done in a loop */
/*   until their cumulative access times add up to the          */
/*   requested duration.                                        */
/*                                                              */
/****************************************************************/
/* defines for local use */
#define TEN_MPIF_UDELAY_DEFAULT_ACC_TIME_USEC (5)
#define TEN_MPIF_MHZ                        (1000000)
#define TEN_MPIF_UDELAY_DEFAULT_MPIF_CLK    (100000000)
#define TEN_MPIF_UDELAY_MAX                 (8*TEN_MPIF_UDELAY_DEFAULT_MPIF_CLK/100) /* 8 secs   */
#define TEN_MPIF_UDELAY_HI_RES_RPT          (10) /* high res reads per tic (boundary)            */
#define TEN_MPIF_UDELAY_HI_RES_TST          (50) /* sample count for testing for high res timing */
#define TEN_MPIF_UDELAY_MODE_LO_RES         (0)  /* uses MPIF_MISC_COUNTER 1 */
#define TEN_MPIF_UDELAY_MODE_HI_RES         (1)  /* uses MPIF_MISC_COUNTER 0 */
#define TEN_MPIF_UDELAY_MODE_HI_LONG        (2)  /* uses both regs, requires correction */
#define TEN_MPIF_UDELAY_MODE_BLIND          (3)  /* one blind access with no readback   */

/****************************************************************/
/* $rtn_hdr_start  MPIF USEC DELAY HI RES                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_uint32 ten_mpif_udelay_hi_res(cs_uint16 dev_id,
                                 cs_uint32 usecs )
/* INPUTS     : o Device Id                                     */
/*              o Microseconds                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Closest nominal delay,                          */
/*              0 if function didn't delay.                     */
/* DESCRIPTION:                                                 */
/*                                                              */
/* NOTICE!     This is a busy-wait timer.       NOTICE!         */
/*                                                              */
/* Loops reading lower two regisers in MPIF_MISC_COUNTER until  */
/* usecs microseconds have passed.                              */
/*                                                              */
/* This high-res timer uses the lower 32 bits of the MPIF       */
/* miscellaneous counter register. The counter is read in a     */
/* busy wait loop until the requested time has elaspsed.        */
/*                                                              */
/* The timer's resolution adapts to the system to make the      */
/* timer as accurate as possible. Its resolution is a function  */
/* of register read time and system clock. See function ten_    */
/* mpif_init_sys_access_times().                                */
/*                                                              */
/* Although an environment may support a very high resolution,  */
/* the CS6040 driver is tested at the default access time of    */
/* TEN_MPIF_UDELAY_DEFAULT_ACC_TIME_USEC. Thus, a warning       */
/* message is printed when a shorter duration than the default  */
/* read access time is requested.                               */
/*                                                              */
/* To contain wrap scenarios, usecs must be less than half of   */
/* MISC_COUNTER1 wrap period.                                   */
/*                                                              */
/* The [usecs] parameter is specified as:                       */
/*   Time in microseconds, with restrictions as described above */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32     start_tics;
  cs_uint32     end_tics;
  cs_uint32     curr_tics;
  cs_uint16     read_mode;
  cs_uint32     loop_guard;
  cs_uint32     loop_index;
  cs_uint16     ii;
  cs_uint16     log_suspend_flag;
  cs_uint32     tics   = 0;
  cs_uint16     wrap   = (1==0);
  ten_dev_cb_t *pdevcb = NULL;
  cs_uint32     err    = 0;

  CS_PRINT("ten_mpif_udelay_hi_res(dev_id=%d, usecs=%d)\n", dev_id, usecs);
  if (usecs <= 1) return tics;    /* Probably spun that off just getting here and back */
  else if (usecs > TEN_MPIF_UDELAY_MAX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": usecs=%d, exceeds maximum %d\n",
                  usecs, TEN_MPIF_UDELAY_MAX);
    return tics;           /* <<<<<<<<<<<<<<<< Early exit on error <<<<<<<<<<<<<<<< */
  }

  /* Validate args */
  if (!(TEN_IS_DEVICE_VALID(dev_id, &err))) {
    CS_HNDL_ERROR(dev_id, err, NULL);
    return tics;           /* <<<<<<<<<<<<<<<< Early exit on error <<<<<<<<<<<<<<<< */
  }
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_NOT_REGD, NULL);
    return tics;           /* <<<<<<<<<<<<<<<< Early exit on error <<<<<<<<<<<<<<<< */
  }
  if (!ten_dev_is_t41_ptr(pdevcb)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": T41 only feature.");
    return tics;           /* <<<<<<<<<<<<<<<< Early exit on error <<<<<<<<<<<<<<<< */
  }
  if (pdevcb->mpif.acctime == 0) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_OP, ": ERROR: MPIF access times not initialized. Use ten_mpif_init_sys_access_times().\n");
    return tics;           /* <<<<<<<<<<<<<<<< Early exit on error <<<<<<<<<<<<<<<< */
  }

  /* Delay, either by count of blind reads or by polling as appropriate             */
  tics = pdevcb->mpif.freq * usecs;

  if (tics < pdevcb->mpif.acctime/2) {
    /* Too short to support. Return 0 */
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": ERROR: usecs less than supported minimum\n");
    return 0;              /* <<<<<<<<<<<<<<<< Early exit on error <<<<<<<<<<<<<<<< */
  }

  /* Print warning if requested usecs is <75% of tested default minimum.          */
  if (usecs < (TEN_MPIF_UDELAY_DEFAULT_ACC_TIME_USEC - TEN_MPIF_UDELAY_DEFAULT_ACC_TIME_USEC/4) ) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": WARNING: usecs less than default minimum\n");
  }

  if (tics <= 8 * pdevcb->mpif.acctime) {
    /* Delay is short compared to read access time. Busy-wait n reads and return.   */
    /* Add 1/4 acctime to tics before integer divide to improve average accuracy.   */
    loop_guard = (tics + (pdevcb->mpif.acctime/4))/pdevcb->mpif.acctime; 
    loop_guard = (loop_guard==0) ? 1 : loop_guard;
    /* Suspend reg r/w logs for clean output */
    log_suspend_flag = g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND;
    g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
    for (ii=0; ii < loop_guard; ii++) {
      ten_mpif_get_misc_counter_low32(pdevcb, TEN_MPIF_UDELAY_MODE_BLIND);
    }
    tics = ii * pdevcb->mpif.acctime;
    g_pTEN->drvr_flag &= (~TEN_DRVR_LOG_SUSPEND | log_suspend_flag);   /* restore log suspend flag */
  }
  else {
    /* Delay is long compared to read access time. Busy-wait while polling counter.  */
    if (pdevcb->mpif.net_acc) read_mode = TEN_MPIF_UDELAY_MODE_LO_RES;
    else if (tics < 0xF800)   read_mode = TEN_MPIF_UDELAY_MODE_HI_RES;
    else                      read_mode = TEN_MPIF_UDELAY_MODE_HI_LONG;

    /* Suspend reg r/w logs for clean output */
    log_suspend_flag = g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND;
    g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

    start_tics  = ten_mpif_get_misc_counter_low32(pdevcb, read_mode);

    /* Set up some worst-case loop control.                                          */
    loop_guard  = tics/pdevcb->mpif.acctime;
    loop_guard += loop_guard/4 + 10;   /* add a 25% margin to the while-loop guard   */
    loop_index  = loop_guard;

    /* Calculate end_tics short by 1/3 to 1/2 read time to improve average accuracy  */
    /* without causing excessive underruns.                                          */
    tics -= (cs_uint32)(pdevcb->mpif.acctime);
    end_tics = start_tics + tics;
    wrap        = (start_tics > end_tics);
    if (wrap) {
      do {
        curr_tics = ten_mpif_get_misc_counter_low32(pdevcb, read_mode);
        loop_index -= 1;
      } while ( ( (curr_tics >= start_tics) || (curr_tics < end_tics)) && (loop_index) );
      /* Calculate actual */
      tics += (curr_tics > end_tics) ? curr_tics - end_tics : end_tics - curr_tics;
    }
    else {
      do {
        curr_tics = ten_mpif_get_misc_counter_low32(pdevcb, read_mode);
        loop_index -= 1;
      } while (  (curr_tics <  end_tics  ) 
              && (curr_tics >= start_tics)  /* catch last-read wrap */
              && (loop_index) );
      /* Calculate actual */
      if (curr_tics > start_tics)
        tics += (curr_tics > end_tics) ? curr_tics - end_tics : end_tics - curr_tics;
      else
        tics += (curr_tics > end_tics) ? curr_tics - end_tics : end_tics + curr_tics; /* 1's comp */
    } /* end else no wrap */
    g_pTEN->drvr_flag &= (~TEN_DRVR_LOG_SUSPEND | log_suspend_flag);   /* restore log suspend flag */

    if (loop_index == 0) {
      CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, ": end time not found after %d reads\n", loop_guard);
      tics = loop_guard * pdevcb->mpif.acctime;
    }
  } /* end if delay is long compared to read time */

  return (tics);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF INIT SYSTEM ACCESS TIMES                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_init_access_times(cs_uint16 dev_id,
                                     cs_uint32 sysclk_freq)
/* INPUTS     : o Device Id                                     */
/*              o System clock frequence in Hz                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* This function characterizes MPIF register read times in      */
/* terms of MPF_MISC_COUNTER, and writes the characterizations  */
/* to the 'timing' entry of the device control block. The       */
/* characterizations include access time and a 'network' flag   */
/* that helps the MPIF UDELAY function ten_mpif_udelay_hi_res() */
/* to adapt to very long access times as when via RPC.          */
/*                                                              */
/* It uses register reads of TEN_MPIF_MISC_COUNTER1  to         */
/* determine if the driver is working over a network, and if    */
/* not, a series of reads of counter 0 and counter 1 to         */
/* determine what the average access time is.                   */
/*                                                              */
/* When system clock is 400MHz, MISC_COUNTER1 tics are 164      */
/* microsecs.                                                   */
/*                                                              */
/* The [sysclk_freq] parameter is specified as:                 */
/*   In Hz, the CS6040 system clock frequency                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32     tics;
  cs_uint32     start_tics;
  cs_uint32     end_tics;
  cs_uint16     log_suspend_flag;
  ten_dev_cb_t *pdevcb = NULL;
  T41_t        *pDev   = NULL;
  cs_uint16     rd_cnt = 0;
  cs_uint32     err    = 0;

  CS_PRINT("ten_mpif_init_access_times(dev_id=%d, sysclk_freq=%d\n", dev_id, sysclk_freq);

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err))) {
    CS_HNDL_ERROR(dev_id, err, NULL);
    return CS_ERROR;     /* <<<<<<<<<<<<<<<< Early exit on error <<<<<<<<<<<<<<<< */
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_NOT_REGD, NULL);
    return CS_ERROR;     /* <<<<<<<<<<<<<<<< Early exit on error <<<<<<<<<<<<<<<< */
  }
  if (!ten_dev_is_t41_ptr(pdevcb)) {
    CS_PRINT("ten_mpif_init_access_times-T41 only feature.\n");
    return (CS_OK);
  }
  pDev = (T41_t *) pdevcb->base_addr;

  /* process and store sysclk_freq as MPIF bus frequency in MHz */
  if ( sysclk_freq!=0 ) {
    /* MPIF freq (MHz) = sysclk_freq/1MHz/4, rounded up if needed */
    sysclk_freq  = ((sysclk_freq % TEN_MPIF_MHZ) < TEN_MPIF_MHZ/2) ? 
                                                       sysclk_freq : sysclk_freq + TEN_MPIF_MHZ;
    sysclk_freq /= TEN_MPIF_MHZ;
    sysclk_freq  = ((sysclk_freq % 4) < 2) ? 
                               sysclk_freq : sysclk_freq + 2;
    pdevcb->mpif.freq = sysclk_freq/4;
  }

  /* Measure register access time, which is the finest resolution this timer     */
  /* can support in this environment. Assume slow access first.                  */
  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* Suspend reg r/w logs for clean output */
  log_suspend_flag = g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND;
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  /* Read the mpif misc counter a bunch of times, save first and last            */
  TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER3));
  TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER2));
  start_tics        = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER1)) << 16;
  start_tics       |= TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER0));
  for (rd_cnt=0; rd_cnt<(TEN_MPIF_UDELAY_HI_RES_TST); rd_cnt++) {
    TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER3));
    TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER2));
    end_tics        = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER1)) << 16;
    end_tics       |= TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER0));
  }
  g_pTEN->drvr_flag &= (~TEN_DRVR_LOG_SUSPEND | log_suspend_flag);   /* restore log suspend flag */
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  /* Calculate elapsed time in tics                                              */
  if (end_tics >= start_tics) {
    tics = end_tics - start_tics;
  }
  else {         /* handle wrap explicitly by dropping the LSBit of the counter. */
    tics = ( ( (end_tics >> 1) | 0x80000000)  - (start_tics >> 1) ) << 1;
  }
  /* If MISC_COUNTER1 increments more than once per dozen reads or so, register  */
  /* access is slow, as when reading over network. See section header for more   */
  /* information such as why this distinction is important for the MPIF timer.   */
  if ( (tics >> 16) > ( (4 * TEN_MPIF_UDELAY_HI_RES_TST) / TEN_MPIF_UDELAY_HI_RES_RPT) ) {
    pdevcb->mpif.net_acc = TRUE;
  }
  else {
    pdevcb->mpif.net_acc = FALSE;
  }
  /* Calculate the average access time in sysclock cycles.                       */
  pdevcb->mpif.acctime = tics / (TEN_MPIF_UDELAY_HI_RES_TST*4);

  CS_PRINT("MPIF clock freq=%d, reg access via network=%s, reg access tics=%d\n",
            pdevcb->mpif.freq, ( (pdevcb->mpif.net_acc==1) ? "True" : "False"), pdevcb->mpif.acctime);
  if (pdevcb->mpif.acctime==0) {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT, "Register access time is 0\n");
  }
  return CS_OK;
}

/*****************************************************************************
 *  ten_mpif_get_misc_counter_low32 (private):
 *  Input args:
 *    POINTER TO DEVICE CB
 *    READ MODE
 *      TEN_MPIF_UDELAY_MODE_LO_RES         (0) uses MPIF_MISC_COUNTER 1
 *      TEN_MPIF_UDELAY_MODE_HI_RES         (1) uses MPIF_MISC_COUNTER 0
 *      TEN_MPIF_UDELAY_MODE_HI_LONG        (2) uses both regs, requires correction
 *      TEN_MPIF_UDELAY_MODE_BLIND          (3) one blind access with no readback
 *      
 *  Returns  : low 32 bits of MPIF misc counter, shifted or corrected as needed
 *****************************************************************************/
static cs_uint32 ten_mpif_get_misc_counter_low32(ten_dev_cb_t *pdevcb, cs_uint16 read_type)
{
  cs_uint32 time   = 0;
  T41_t    *pDev   = (T41_t *) pdevcb->base_addr;

  TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER3));  /* sample new time */

  switch (read_type) {
    case TEN_MPIF_UDELAY_MODE_BLIND :
      break;

    case TEN_MPIF_UDELAY_MODE_LO_RES :
      time  = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER1));
      time  = (time << 16) & 0xFFFF0000;
      break;

    case TEN_MPIF_UDELAY_MODE_HI_RES :
      time  = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER0));
      time &= 0x0000FFFF;
      break;

    case TEN_MPIF_UDELAY_MODE_HI_LONG :
      TEN_DEV_LOCK(pdevcb->dev_id, TEN_ID_MPIF);
      time  = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER1));
      time  = (time << 16) & 0xFFFF0000;
      time |= TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MISC_COUNTER0));
      TEN_DEV_UNLOCK(pdevcb->dev_id, TEN_ID_MPIF);
      break;

    default :
      break;
  }

  return (time);
}

/*****************************************************************************
 *  ten_mpif_dump_cb (not for API):
 *  Input args:
 *    POINTER TO DEVICE's MPIF CB
 *  Returns   : n/a
 *****************************************************************************/
void      ten_mpif_dump_cb(ten_mpif_cb_t *mpif_cb)
{
  CS_PRINT_OUTPUT("mpif frequency    = %d\n", mpif_cb->freq);
  CS_PRINT_OUTPUT("mpif access time  = %d\n", mpif_cb->acctime);
  CS_PRINT_OUTPUT("mpif slow access  = %s\n", ( (mpif_cb->net_acc) ? "TRUE" : "FALSE") );
}
/* End Bugzilla 30990, hires timer required.            */

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET DM MPIF T41                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_dm_mpif_t41(cs_uint16 dev_id,
                                            cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MPIF_GLOBAL_RESET_DM_t tmp_global_reset_dm;

  if (act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": act out of range");
    return (CS_ERROR);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_dm.wrd = 0;
  tmp_global_reset_dm.bf.mpif = 1;
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_DM), tmp_global_reset_dm.wrd, act);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF GLOBAL RESET DM LOGIC T41               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_global_reset_dm_logic_t41(cs_uint16 dev_id,
                                            cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Reset Action                                  */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Performs a hard reset on the specified selections. The       */
/* selections that are masked off will not be affected.         */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  TEN_MPIF_GLOBAL_RESET_DM_t tmp_global_reset_dm;

  if (act > CS_RESET_TOGGLE) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": act out of range");
    return (CS_ERROR);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (!ten_dev_is_t41(dev_id)) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": T41 only feature.");
    return (CS_ERROR);
  }

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  /* set mask bits for affected selections */
  tmp_global_reset_dm.wrd = 0;
  tmp_global_reset_dm.bf.logic = 1;
  /* perform the specified reset action */
  ten_reset_action(TEN_MPIF_REG_ADDR(pDev, GLOBAL_RESET_DM), tmp_global_reset_dm.wrd, act);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  MPIF CLOCK SELECT INTERNAL RXDIV             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : MPIF                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_mpif_clock_select_int_rxdiv(cs_uint16 dev_id,
                                          cs_module_t module_num,
                                          cs_uint8 slice,
                                          cs_dir_t dir,
                                          cs_ctl_t select)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Slice                                         */
/*              o Direction                                     */
/*              o Select                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Selects between the HSIF output clocks and RXDIV clocks.     */
/* This is the 2nd stage of top level clock muxing.             */
/* Each RXDIV output is hardwired to the GPLL path              */  
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*   2 = TEN_MODULE_A_AND_B                                     */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*   0xFF = TEN_SLICE_ALL                                       */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   0 = selects the clock selected by                          */
/*       MPIF_CLOCK_SELECT_HSIF_OUT.txb                         */
/*   1 = selects internal connection from RXB[n]_DIV            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 tmp = 0;
  TEN_MPIF_CLOCK_SELECT_INTERNAL_RXDIV_t tmp_clock_select_internal_rxdiv;

  if(module_num > TEN_MODULE_A_AND_B) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": module_num out of range");
    return(CS_ERROR);
  }
  if(dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,
                             ": dir out of range");
    return(CS_ERROR);
  }
  if (select > 1) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, ": select = 0x%04X\n", select);
      return (CS_ERROR);
  }
  if (slice == TEN_SLICE_ALL) {
    tmp = 0x000F;
  }
  else if (slice <= TEN_SLICE3) {
    tmp = 1 << slice;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_INVALID_USER_ARG, ": slice out of range.  s/b 0..3, TEN_SLICE_ALL.");
    return(CS_ERROR);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);
  
  tmp_clock_select_internal_rxdiv.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_INTERNAL_RXDIV));

  if(module_num == TEN_MODULE_A) {
    if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_internal_rxdiv.bf.rxa |= tmp ;
      }
      else {
        tmp_clock_select_internal_rxdiv.bf.rxa &= ~tmp;
      }
    }
    if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_internal_rxdiv.bf.txa |= tmp;
      }
      else {
        tmp_clock_select_internal_rxdiv.bf.txa &= ~tmp;
      }
    }
  }
  else {
    if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_internal_rxdiv.bf.rxb |= tmp;
      }
      else {
        tmp_clock_select_internal_rxdiv.bf.rxb &= ~tmp;
      }
    }
    if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
      if (select == 1) {
        tmp_clock_select_internal_rxdiv.bf.txb |= tmp;
      }
      else {
        tmp_clock_select_internal_rxdiv.bf.txb &= ~tmp;
      }
    }
  }
  
  TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, CLOCK_SELECT_INTERNAL_RXDIV), tmp_clock_select_internal_rxdiv.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  return (CS_OK);
}


