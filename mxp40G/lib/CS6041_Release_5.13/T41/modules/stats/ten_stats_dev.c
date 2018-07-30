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
 * ten_dev_stats.c
 *
 * $Id: ten_stats_dev.c,v 1.6 2013/02/22 20:48:50 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/************************************************************************/
/* $rtn_hdr_start  PRINT DEVICE STATISTICS                              */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_print_stats(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                             */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Prints statistics for the device of all the blocks that are          */
/* registered and are active in the current mode.                       */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, NULL);
    return (CS_ERROR);
  }

  CS_PRINT_OUTPUT("\n");
  if (ten_drvr_is_esc_code_enbld()) {
    CS_PRINT_OUTPUT("\033[7m Dev-%d  STATS :\033[m\n", dev_id);
  }
  else {
    CS_PRINT_OUTPUT(" Dev-%d  STATS :\n", dev_id);
  }

  if (TEN_STATS_IS_BLK_REGISTERED((cs_uint16) dev_id, TEN_DEVICE, TEN_ID_XCON)) {
    ten_dev_print_blk_stats(dev_id, TEN_ID_XCON);
  }

  /* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  PRINT DEVICE BLOCK STATS                             */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_print_blk_stats(cs_uint16 dev_id, cs_uint16 block_id)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Prints the block's statistics for the device.                        */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2.          */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0, ii;
  ten_stats_blk_cb_t *blk_cb;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, NULL);
    return (CS_ERROR);
  }

  blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if (blk_cb->enabled == FALSE) {
    CS_PRINT_OUTPUT("STATISTICS DISABLED FOR %s\n", blk_cb->blk_name);
    return (CS_ERROR);
  }

  ten_stats_print_blk_hdr((cs_uint16) dev_id, TEN_DEVICE, blk_cb->blk_name);

  for (ii = 0; ii < TEN_STATS_MAX_SECT; ii++) {
    /* Print Section stats if valid and are enabled */
    if ((blk_cb->p_sect_cb[ii]) && (blk_cb->p_sect_cb[ii]->enabled)) {
      ten_dev_print_sect_stats(dev_id, block_id, ii);
    }
  }

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  PRINT DEVICE SECTION STATS                           */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_print_sect_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                   cs_uint16 sect_id)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Prints the Stats for the user specified section of the device.       */
/* Stats within a block are organized as a collection of section stats. */
/* Each section is identified by block_id and section_id combination.   */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2.          */
/*                                                                      */
/* The [sect_id] parameter is specified as:  XCON instance 0-7.         */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *sect_cb = NULL;
  ten_stats_blk_cb_t *blk_cb;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((sect_cb = blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "Section not registered for Stats (%d)\n", sect_id);
    return (CS_ERROR);
  }

  if (sect_cb->enabled == FALSE) {
    CS_PRINT_OUTPUT("STATISTICS DISABLED FOR %s section %s\n",
             blk_cb->blk_name, sect_cb->sect_name);
    return (CS_ERROR);
  }

  ten_stats_print_sect_hdr((cs_uint16) dev_id, TEN_DEVICE, sect_cb->sect_name);

  ten_stats_sect_cmn_op((cs_uint16) dev_id, TEN_DEVICE, block_id, sect_id,
                        sect_cb, TEN_STATS_PRINT, CS_RX_AND_TX);

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  PRINT DEVICE UNIT STATS                              */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_print_unit_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                   cs_uint16 sect_id, cs_uint16 unit_id)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Unit Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Prints the Stats for the user specified unit for the device.         */
/* Stats for the device are organized as a collection of block          */
/* stats. Each block has number of section stats identified by section  */
/* id. Each section then has unit stats. Unit stat is the atomic entity */
/* of the stats and carry RX and TX stats. Each unit is uniquely        */
/* identified by block_id, section_id and unit_id combination.          */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2.          */
/*                                                                      */
/* The [sect_id] parameter is specified as:  XCON instance 0-7          */
/*                                                                      */
/* [unit_id]  Unit id refers to an individual counter:                  */
/*   TEN_XCON_ES_FIFO_OVERFLOW_STAT      = 0, (CS_RX)                   */
/*   TEN_XCON_CBERT_PRBS_ERR_COUNT_STAT  = 1, (CS_RX)                   */
/*   TEN_XCON_PBERT_GOOD_UCNT_STAT       = 2, (CS_TX/CS_RX)             */
/*   TEN_XCON_PBERT_GOOD_UOCNT_STAT      = 3, (CS_TX/CS_RX)             */
/*   TEN_XCON_PBERT_RX_UERRCNT_STAT      = 4, (CS_RX)                   */
/*   TEN_XCON_PBERT_RX_UOERRCNT_STAT     = 5, (CS_RX)                   */
/*   TEN_XCON_PBERT_RX_PRBSERRCNT_STAT   = 6  (CS_RX).                  */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;
  ten_stats_data_t *p_unit_data;
  cs_status rtn;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, "\n");
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "Section not registered for Stats (%d)\n", sect_id);
    return (CS_ERROR);
  }

  if (stats_sect_cb->enabled == FALSE) {
    CS_PRINT_OUTPUT("STATISTICS DISABLED FOR %s section %s\n",
             stats_blk_cb->blk_name, stats_sect_cb->sect_name);
    return (CS_ERROR);
  }

  p_unit_data = stats_sect_cb->pStats + unit_id;
  if (*(stats_sect_cb->enbl_tbl + unit_id) == FALSE) {
    CS_PRINT_OUTPUT("STATS DISABLED FOR %s : SECT_ID : %d UNIT_ID : %d\n",
             stats_blk_cb->blk_name, sect_id, unit_id);
    return (CS_ERROR);
  }

  ten_set_sect_print_flag(0);
  
  rtn = ten_stats_unit_cmn_op((cs_uint16) dev_id, TEN_DEVICE,
                               block_id, sect_id, unit_id,
                               stats_sect_cb, TEN_STATS_PRINT, CS_RX_AND_TX, FALSE);
                               
  return (rtn);                            
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR DEVICE STATS                                   */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_clear_stats(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                             */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clear the Device stats. This clears the hardware registers and also  */
/* the internal stats structure which accumulates the stats for both    */
/* RX and TX direction.                                                 */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  return ten_dev_clear_dir_stats(dev_id, CS_RX_AND_TX);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR DEVICE STATS FOR THE DIRECTION (RX/TX/BOTH)    */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_clear_dir_stats(cs_uint16 dev_id, cs_dir_t dir)
/* INPUTS     : o Device Id                                             */
/*              o Direction                                             */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clear the RX/TX or Both stats. This clears the hardware registers    */
/* and also the internal stats structure which accumulates the stats.   */
/* This clears the stats and hw register for the direction specified.   */
/*                                                                      */
/* The [dir] parameter is specified as:                                 */
/*   CS_TX = 0                                                          */
/*   CS_RX = 1                                                          */
/*   CS_TX_AND_RX = 2.                                                  */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, "invalid device, ten_dev_clear_dir_stats.");
    return (CS_ERROR);
  }

  if (TEN_STATS_IS_BLK_REGISTERED((cs_uint16) dev_id, TEN_DEVICE, TEN_ID_XCON)) {
    ten_dev_clear_blk_dir_stats(dev_id, TEN_ID_XCON, dir);
  }

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR DEVICE BLOCK STATS                             */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_clear_blk_stats(cs_uint16 dev_id, cs_uint16 block_id)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clears the stats for the block.                                      */
/* This API clears both the hardware counters and internal stats block  */
/* stats structure.                                                     */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2.          */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  return ten_dev_clear_blk_dir_stats(dev_id, block_id, CS_RX_AND_TX);
}

/**************************************************************************/
/* $rtn_hdr_start CLEAR DEVICE BLOCK STATS FOR THE DIRECTION (RX/TX/BOTH) */
/* CATEGORY   : API                                                         */
/* ACCESS     : Public                                                    */
/* BLOCK      : STATS                                                     */
/* CHIP       : Tenabo                                                    */
cs_status ten_dev_clear_blk_dir_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                      cs_dir_t dir)
/* INPUTS     : o Device Id                                               */
/*              o Block Id                                                */
/*              o Direction                                               */
/* OUTPUTS    : ----                                                      */
/* RETURNS    : CS_OK or CS_ERROR                                         */
/* DESCRIPTION:                                                           */
/* Clears the stats for the block and hw register for the direction       */
/* specified.                                                             */
/*                                                                        */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2.            */
/*                                                                        */
/* The [dir] parameter is specified as:                                   */
/*   CS_TX = 0                                                            */
/*   CS_RX = 1                                                            */
/*   CS_TX_AND_RX = 2.                                                    */
/*                                                                        */
/* $rtn_hdr_end                                                           */
/**************************************************************************/
{
  cs_uint32 error = 0, ii;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, "\n");
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  for (ii = 0; ii < TEN_STATS_MAX_SECT; ii++) {
    if ((stats_blk_cb->p_sect_cb[ii]) && (stats_blk_cb->p_sect_cb[ii]->enabled)) {
      ten_dev_clear_sect_dir_stats(dev_id, block_id, ii, dir);
    }
  }

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR DEVICE SECTION STATS                           */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                 */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_clear_sect_stats(cs_uint16 dev_id,
                                   cs_uint16 block_id, cs_uint16 sect_id)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clears the Stats for the section in user specified block's section.  */
/* Refer to the individual header files for the section ID defines.     */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2.          */
/*                                                                      */
/* The [sect_id] parameter is specified as:  XCON instance 0-7.         */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  return ten_dev_clear_sect_dir_stats(dev_id, block_id, sect_id, CS_RX_AND_TX);
}

/*****************************************************************************/
/* $rtn_hdr_start  CLEAR DEVICE SECTION STATS FOR THE DIRECTION (RX/TX/BOTH) */
/* CATEGORY   : API                                                          */
/* ACCESS     : Public                                                       */
/* BLOCK      : STATS                                                        */
/* CHIP       : Tenabo                                                       */
cs_status ten_dev_clear_sect_dir_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                       cs_uint16 sect_id, cs_dir_t dir)
/* INPUTS     : o Device Id                                                  */
/*              o Block Id                                                   */
/*              o Section Id                                                 */
/*              o Direction                                                  */
/* OUTPUTS    : ----                                                         */
/* RETURNS    : CS_OK or CS_ERROR                                            */
/* DESCRIPTION:                                                              */
/* Clears the Stats for the section in user specified block's section.       */
/* This clears the stats and hw register for the direction specified.        */
/*                                                                           */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2.               */
/*                                                                           */
/* The [sect_id] parameter is specified as:  XCON instance 0-7.              */
/*                                                                           */
/* The [dir] parameter is specified as:                                      */
/*   CS_TX = 0                                                               */
/*   CS_RX = 1                                                               */
/*   CS_TX_AND_RX = 2.                                                       */
/*                                                                           */
/* $rtn_hdr_end                                                              */
/*****************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, "\n");
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL, "Section not registered for Stats\n");
    return (CS_ERROR);
  }

  if (stats_sect_cb->enabled == FALSE) {
    CS_PRINT_OUTPUT("STATISTICS DISABLED FOR %s section %s\n",
             stats_blk_cb->blk_name, stats_sect_cb->sect_name);
    return (CS_ERROR);
  }

  ten_stats_sect_cmn_op((cs_uint16) dev_id, TEN_DEVICE, block_id,
                        sect_id, stats_sect_cb, TEN_STATS_CLEAR, dir);
  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR DEVICE STATS UNIT                              */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_clear_unit_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                   cs_uint16 sect_id, cs_uint16 unit_id)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Unit Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clears the Stats for the unit in user specified block's section.     */
/* This clears the stats structure and also the hardware counters.      */
/* Refer to the individual header files for the section ID and unit Id  */
/* defines.                                                             */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2           */
/*                                                                      */
/* The [sect_id] parameter is specified as:  XCON instance 0-7          */
/*                                                                      */
/* [unit_id]  Unit id refers to an individual counter:                  */
/*   TEN_XCON_ES_FIFO_OVERFLOW_STAT      = 0, (CS_RX)                   */
/*   TEN_XCON_CBERT_PRBS_ERR_COUNT_STAT  = 1, (CS_RX)                   */
/*   TEN_XCON_PBERT_GOOD_UCNT_STAT       = 2, (CS_TX/CS_RX)             */
/*   TEN_XCON_PBERT_GOOD_UOCNT_STAT      = 3, (CS_TX/CS_RX)             */
/*   TEN_XCON_PBERT_RX_UERRCNT_STAT      = 4, (CS_RX)                   */
/*   TEN_XCON_PBERT_RX_UOERRCNT_STAT     = 5, (CS_RX)                   */
/*   TEN_XCON_PBERT_RX_PRBSERRCNT_STAT   = 6  (CS_RX).                  */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  return ten_dev_clear_unit_dir_stats(dev_id, block_id, sect_id, unit_id, CS_RX_AND_TX);
}

/**************************************************************************/
/* $rtn_hdr_start  CLEAR DEVICE STATS UNIT FOR THE DIRECTION (RX/TX/BOTH) */
/* CATEGORY   : API                                                       */
/* ACCESS     : Public                                                    */
/* BLOCK      : STATS                                                     */
/* CHIP       : Tenabo                                                    */
cs_status ten_dev_clear_unit_dir_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                       cs_uint16 sect_id, cs_uint16 unit_id, cs_dir_t dir)
/* INPUTS     : o Device Id                                               */
/*              o Block Id                                                */
/*              o Section Id                                              */
/*              o Unit Id                                                 */
/*              o Direction                                               */
/* OUTPUTS    : ----                                                      */
/* RETURNS    : CS_OK or CS_ERROR                                         */
/* DESCRIPTION:                                                           */
/* Clears the Stats for the unit in user specified block's section.       */
/* This clears the stats and hw register for the direction specified.     */
/* Refer to the individual header files for the section ID and unit Id    */
/* defines.                                                               */
/*                                                                        */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2             */
/*                                                                        */
/* The [sect_id] parameter is specified as:  XCON instance 0-7            */
/*                                                                        */
/* [unit_id]  Unit id refers to an individual counter:                    */
/*   TEN_XCON_ES_FIFO_OVERFLOW_STAT      = 0, (CS_RX)                     */
/*   TEN_XCON_CBERT_PRBS_ERR_COUNT_STAT  = 1, (CS_RX)                     */
/*   TEN_XCON_PBERT_GOOD_UCNT_STAT       = 2, (CS_TX/CS_RX)               */
/*   TEN_XCON_PBERT_GOOD_UOCNT_STAT      = 3, (CS_TX/CS_RX)               */
/*   TEN_XCON_PBERT_RX_UERRCNT_STAT      = 4, (CS_RX)                     */
/*   TEN_XCON_PBERT_RX_UOERRCNT_STAT     = 5, (CS_RX)                     */
/*   TEN_XCON_PBERT_RX_PRBSERRCNT_STAT   = 6  (CS_RX)                     */
/*                                                                        */
/* The [dir] parameter is specified as:                                   */
/*   CS_TX = 0                                                            */
/*   CS_RX = 1                                                            */
/*   CS_TX_AND_RX = 2.                                                    */
/*                                                                        */
/* $rtn_hdr_end                                                           */
/**************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL, "Section not registered for Stats\n");
    return (CS_ERROR);
  }

  if (*(stats_sect_cb->enbl_tbl + unit_id) == FALSE) {
    CS_PRINT_OUTPUT("STATS DISABLED FOR %s : SECT_ID : %d UNIT_ID : %d\n",
             stats_blk_cb->blk_name, sect_id, unit_id);
    return (CS_ERROR);
  }

  ten_set_sect_print_flag(0);

  return ten_stats_unit_cmn_op((cs_uint16) dev_id, TEN_DEVICE,
                               block_id, sect_id, unit_id,
                               stats_sect_cb, TEN_STATS_CLEAR, dir, FALSE);
}

/************************************************************************/
/* $rtn_hdr_start  GET DEVICE STATS                                     */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_get_stats(cs_uint16 dev_id, ten_dev_stats_t *pStats)
/* INPUTS     : o Device Id                                             */
/*              o Pointer to user allocated ten_dev_stats_t struct      */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Get the Stats for user specified Device.                             */
/* User should allocate at least as many bytes as size of               */
/* ten_dev_stats_t structure and pass the pointer to that as pStats     */
/* argument to the function.                                            */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;

  /* CS_PRINT_OUTPUT("ten_dev_get_stats\n"); */

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, NULL);
    return (CS_ERROR);
  }

  if (pStats == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  if (TEN_STATS_IS_BLK_REGISTERED((cs_uint16) dev_id, TEN_DEVICE, TEN_ID_XCON)) {
    ten_dev_get_blk_stats(dev_id, TEN_ID_XCON, &pStats->xcon, sizeof(ten_xcon_stats_t));
  }

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  GET DEVICE BLOCK STATS                               */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_get_blk_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                void *pStats, cs_uint16 len)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/*              o Pointer to user allocated structure                   */
/*              o Size of the user allocated structure                  */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Gets the Stats for the section in user specified block.              */
/* User is responsible for allocating the memory where the block        */
/* stats will be copied back and pass the pointer to that as pStats     */
/* argument to the API. The size of the memory to be allocated is the   */
/* size of the blocks stats structure. Block's stats structure can be   */
/* found in individual blocks's header file. The len field specifies    */
/* the length of the user allocated bytes.                              */
/* Refer to the individual header files for definition of the block     */
/* stats structures definitions.                                        */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2           */
/*                                                                      */
/* The [len] parameter is the length of the user allocated memory where */
/* block stats will be copied.                                          */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0, ii;
  ten_stats_blk_cb_t *stats_blk_cb;
  cs_uint16 blk_stats_len = 0;
  void *p_blk_stats = 0;
  ten_dev_stats_t *p_dev_stats = 0;

  /* CS_PRINT_OUTPUT("ten_dev_get_blk_stats\n"); */

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, NULL);
    return (CS_ERROR);
  }

  if (pStats == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }
  p_dev_stats = TEN_DEV_GET_STATS_PTR(dev_id);

  switch (block_id) {
  case TEN_ID_XCON:
    p_blk_stats = (void *)&p_dev_stats->xcon;
    blk_stats_len = sizeof(ten_xcon_stats_t);
    break;

  default:
    return (CS_ERROR);
  }

  if (len < blk_stats_len) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_SIZE, "len s/b %d\n", blk_stats_len);
    return (CS_ERROR);
  }
  
  /* bugzilla #24439, klocwork */
  if (!p_blk_stats) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_SIZE, "p_blk_stats is NULL.\n");
    return (CS_ERROR);
  }
  
  for (ii = 0; ii < TEN_STATS_MAX_SECT; ii++) {
    /* Print Section stats if valid and are enabled */
    if ((stats_blk_cb->p_sect_cb[ii]) && (stats_blk_cb->p_sect_cb[ii]->enabled)) {
      ten_stats_sect_cmn_op((cs_uint16) dev_id, TEN_DEVICE, block_id, ii,
                            stats_blk_cb->p_sect_cb[ii], TEN_STATS_GET, CS_RX_AND_TX);
    }
  }
  CS_MEMCPY(pStats, p_blk_stats, len);
  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  GET DEVICE SECTION STATS                             */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_get_sect_stats(cs_uint16 dev_id, cs_uint16 block_id, cs_uint16 sect_id,
                                 void *pStats, cs_uint16 len)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Pointer to user allocated structure                   */
/*              o Length of the user allocated structure                */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Gets the Stats for the section in user specified block.              */
/* User should allocate memory of at least as many bytes as the size of */
/* section stats structure and pass its pointer as pStats argument to   */
/* the API. If the size of the memory is less than the size of the      */
/* section stats structure, API will return CS_ERROR.                   */
/* Refer to the individual header files for the section stats struct    */
/* definitions and for section ID defines.                              */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2           */
/*                                                                      */
/* The [sect_id] parameter is specified as:  XCON instance 0-7          */
/*                                                                      */
/* The [len] parameter is the length of the user allocated memory where */
/* section stats will be copied.                                        */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;
  ten_stats_data_t *p_unit_data;
  cs_uint16 sect_stats_len;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, ":dev_id : %d\n", dev_id);
    return (CS_ERROR);
  }

  if (pStats == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "Section not registered for Stats (%d)\n", sect_id);
    return (CS_ERROR);
  }

  sect_stats_len = (sizeof(ten_stats_data_t) * stats_sect_cb->num_entries);

  if (len < sect_stats_len) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_SIZE, "len s/b %d\n", sect_stats_len);
    return (CS_ERROR);
  }

  p_unit_data = stats_sect_cb->pStats;
  ten_stats_sect_cmn_op((cs_uint16) dev_id, TEN_DEVICE,
                        block_id, sect_id, stats_sect_cb, TEN_STATS_GET, CS_RX_AND_TX);

  CS_MEMCPY(pStats, p_unit_data, len);

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  GET DEVICE UNIT STATS                                */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_get_unit_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, cs_uint16 unit_id,
                                 cs_dir_t dir, 
                                 ten_stats_data_t *pUnit_Stats)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Unit Id                                               */
/*              o Direction                                             */
/*              o Pointer to user allocated ten_stats_data_t structure  */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Get unit stats for the user specified unit with specified block's    */
/* section. Unit stats carry TX and RX stats, but for the given stats   */
/* RX and TX or only RX or only TX might be valid. In case only         */
/* one direction is valid, the other counter will be Zero.              */
/* Refer to the individual header files for the section ID and unit id  */
/* defines.                                                             */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2           */
/*                                                                      */
/* The [sect_id] parameter is specified as:  XCON instance 0-7          */
/*                                                                      */
/* [unit_id]  Unit id refers to an individual counter:                  */
/*   TEN_XCON_ES_FIFO_OVERFLOW_STAT      = 0, (CS_RX)                   */
/*   TEN_XCON_CBERT_PRBS_ERR_COUNT_STAT  = 1, (CS_RX)                   */
/*   TEN_XCON_PBERT_GOOD_UCNT_STAT       = 2, (CS_TX/CS_RX)             */
/*   TEN_XCON_PBERT_GOOD_UOCNT_STAT      = 3, (CS_TX/CS_RX)             */
/*   TEN_XCON_PBERT_RX_UERRCNT_STAT      = 4, (CS_RX)                   */
/*   TEN_XCON_PBERT_RX_UOERRCNT_STAT     = 5, (CS_RX)                   */
/*   TEN_XCON_PBERT_RX_PRBSERRCNT_STAT   = 6  (CS_RX)                   */
/*                                                                      */
/* The [dir] parameter is specified as:                                 */
/*   CS_TX = 0                                                          */
/*   CS_RX = 1                                                          */
/*   CS_TX_AND_RX = 2.                                                  */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;
  ten_stats_data_t *p_unit_data;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, NULL);
    return (CS_ERROR);
  }

  if (pUnit_Stats == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, NULL);
    return (CS_ERROR);
  }
  
  if (dir > CS_TX_AND_RX) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, NULL);
    return (CS_ERROR);
  }
  
  stats_blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "Section not registered for Stats (%d)\n", sect_id);
    return (CS_ERROR);
  }

  if (unit_id >= stats_sect_cb->num_entries) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  ten_set_sect_print_flag(0);

  ten_stats_unit_cmn_op((cs_uint16) dev_id, TEN_DEVICE,
                        block_id, sect_id, unit_id,
                        stats_sect_cb, TEN_STATS_GET, dir, FALSE);

  p_unit_data = stats_sect_cb->pStats + unit_id;
  CS_MEMCPY(pUnit_Stats, p_unit_data, sizeof(ten_stats_data_t));

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE DEVICE BLOCK STATS                    */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_ctl_blk_stats(cs_uint16 dev_id, cs_uint16 block_id, cs_ctl_t ctl)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/*              o Control                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Enable/Disable the stats for the Device block.                       */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON.              */
/*                                                                      */
/* The [ctl] parameter is specified as:                                 */
/*   CS_DISABLE (0) or CS_ENABLE (1).                                   */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  stats_blk_cb->enabled = (ctl == CS_ENABLE) ? TRUE : FALSE;
  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE DEVICE SECTION STATS                  */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_ctl_sect_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, cs_ctl_t ctl)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Control                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Enable/Disable the Stats for the section in user specified block.    */
/* Refer to the individual header files for the section ID defines.     */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2           */
/*                                                                      */
/* The [sect_id] parameter is specified as:  XCON instance 0-7.         */
/*                                                                      */
/* The [ctl] parameter is specified as:                                 */
/*   CS_DISABLE (0) or CS_ENABLE (1).                                   */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "Section not registered for Stats (%d)\n", sect_id);
    return (CS_ERROR);
  }

  stats_sect_cb->enabled = (ctl == CS_ENABLE) ? TRUE : FALSE;
  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE DEVICE STATS UNIT                     */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_ctl_unit_stats(cs_uint16 dev_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, cs_uint16 unit_id, cs_ctl_t ctl)
/* INPUTS     : o Device Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Unit Id                                               */
/*              o Control                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Enable/Disable the Stats for the section in user specified block.    */
/* Refer to the individual header files for the section ID and unit ID  */
/* defines. Unit ID is the atomic unit of stats, which consists of the  */
/* RX and TX side stats.                                                */
/*                                                                      */
/* The [block_id] parameter is specified as:  TEN_ID_XCON = 2           */
/*                                                                      */
/* The [sect_id] parameter is specified as:  XCON instance 0-7          */
/*                                                                      */
/* [unit_id]  Unit id refers to an individual counter:                  */
/*   TEN_XCON_ES_FIFO_OVERFLOW_STAT      = 0, (CS_RX)                   */
/*   TEN_XCON_CBERT_PRBS_ERR_COUNT_STAT  = 1, (CS_RX)                   */
/*   TEN_XCON_PBERT_GOOD_UCNT_STAT       = 2, (CS_TX/CS_RX)             */
/*   TEN_XCON_PBERT_GOOD_UOCNT_STAT      = 3, (CS_TX/CS_RX)             */
/*   TEN_XCON_PBERT_RX_UERRCNT_STAT      = 4, (CS_RX)                   */
/*   TEN_XCON_PBERT_RX_UOERRCNT_STAT     = 5, (CS_RX)                   */
/*   TEN_XCON_PBERT_RX_PRBSERRCNT_STAT   = 6  (CS_RX)                   */
/*                                                                      */
/* The [ctl] parameter is specified as:                                 */
/*   CS_DISABLE (0) or CS_ENABLE (1).                                   */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, "\n", dev_id);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb((cs_uint16) dev_id, TEN_DEVICE, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_TBL_NULL, "Section not registered for Stats\n");
    return (CS_ERROR);
  }

  if (unit_id >= stats_sect_cb->num_entries) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_ID_OUT_OF_RANGE,
                  "Unit Stat specified out of Range (%d)\n", unit_id);
    return (CS_ERROR);
  }

  *(stats_sect_cb->enbl_tbl + unit_id) = ((ctl == CS_ENABLE) ? TRUE : FALSE);
  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  LOAD DEVICE STATS                                    */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_dev_load_stats(cs_uint16 dev_id, ten_dev_stats_t *pStats)
/* INPUTS     : o Device Id                                             */
/*              o Pointer to user allocated ten_dev_stats_t struct      */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Load the user-provided statistic counters into the driver.           */
/* Normally, after cold initialization the driver statistic             */
/* counters are cleared. This API is provided so that the               */
/* software has the flexibility of having the driver maintain           */
/* counters from a non-zero starting point - for eg., for warm          */
/* start the application could save the driver statistics, do           */
/* warm reboot and call this API to re-load it.                         */
/* User should allocate at least as many bytes as size of               */
/* ten_dev_stats_t structure and pass the pointer to that as pStats     */
/* argument to the function.                                            */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_dev_stats_t *p_dev_stats = NULL;

  if (TEN_IS_DEVICE_VALID(dev_id, &error) != TRUE) {
    CS_HNDL_ERROR(dev_id, error, NULL);
    return (CS_ERROR);
  }

  if (pStats == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  p_dev_stats = TEN_DEV_GET_STATS_PTR(dev_id);
  if (p_dev_stats == NULL) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  CS_MEMCPY(p_dev_stats, pStats, sizeof(ten_dev_stats_t));
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start   TEN READ DEV STAT                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : STATS                                           */
/* CHIP       : Tenabo                                          */
cs_uint64 ten_dev_read_stat(cs_uint16 dev_id, cs_uint16 block_id,
                            cs_uint16 sect_id, cs_uint16 unit_id, 
                            cs_dir_t dir)
/* INPUTS     : o Device Id                                     */
/*              o Block Id                                      */
/*              o Section Id                                    */
/*              o Unit Id                                       */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 64 bit counter                                  */
/* DESCRIPTION:                                                 */
/* Reads an individual counter for the specified direction.     */
/* This wraps the API ten_dev_get_unit_stats, mainly for use    */
/* in APISH scripts.                                            */
/*                                                              */
/* [block_id]  TEN_ID_XCON = 2                                  */
/*                                                              */
/* [sect_id]  Instance of XCON = 0..7                           */
/*                                                              */
/* [unit_id]  Unit id refers to an individual counter:          */
/*   TEN_XCON_ES_FIFO_OVERFLOW_STAT      = 0, (CS_RX)           */
/*   TEN_XCON_CBERT_PRBS_ERR_COUNT_STAT  = 1, (CS_RX)           */
/*   TEN_XCON_PBERT_GOOD_UCNT_STAT       = 2, (CS_TX/CS_RX)     */
/*   TEN_XCON_PBERT_GOOD_UOCNT_STAT      = 3, (CS_TX/CS_RX)     */
/*   TEN_XCON_PBERT_RX_UERRCNT_STAT      = 4, (CS_RX)           */
/*   TEN_XCON_PBERT_RX_UOERRCNT_STAT     = 5, (CS_RX)           */
/*   TEN_XCON_PBERT_RX_PRBSERRCNT_STAT   = 6  (CS_RX)           */
/*                                                              */
/* [dir]  direction of the counter:                             */
/*   CS_TX = 0                                                  */
/*   CS_RX = 1.                                                 */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  ten_stats_data_t temp_stats_data;
  cs_uint64 ret_val = 0x0BADDEAD;
  
  temp_stats_data.rx_ms = 0x0BADDEAD;
  temp_stats_data.rx_ls = 0x0BADDEAD;
  temp_stats_data.tx_ms = 0x0BADDEAD;
  temp_stats_data.tx_ls = 0x0BADDEAD;
  
  if (ten_dev_get_unit_stats(dev_id, block_id, sect_id, unit_id,
                             dir, &temp_stats_data) != CS_OK) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_OP, "Invalid user parms.\n");
  }
                                     
  if (dir == CS_RX) {
    ret_val = ((cs_uint64)(temp_stats_data.rx_ms) << 32) | temp_stats_data.rx_ls;
  }
  else if (dir == CS_TX) {
    ret_val = ((cs_uint64)(temp_stats_data.tx_ms) << 32) | temp_stats_data.tx_ls;
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_OP, "Dir out of range.\n");
  }
  return (ret_val);
}

ten_dev_stats_cb_t *TEN_DEV_GET_STATS_CB(cs_uint8 dev_id)
{
  ten_dev_cb_t *p = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  if (!p)
    return (NULL);
  return (&p->stats_cb);
}

ten_dev_stats_t *TEN_DEV_GET_STATS_PTR(cs_uint16 dev_id)
{
  ten_dev_cb_t *p = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  if (!p) {
    return (NULL);
  }
  return (&p->stats);
}

