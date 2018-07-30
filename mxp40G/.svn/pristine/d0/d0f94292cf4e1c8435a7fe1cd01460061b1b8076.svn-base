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
 * ten_mod_stats.c
 *
 * $Id: ten_stats_mod.c,v 1.8 2013/03/15 21:01:20 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/************************************************************************/
/* $rtn_hdr_start  PRINT MODULE STATISTICS                              */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_print_stats(cs_uint16 module_id)
/* INPUTS     : o Module Id                                             */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Prints statistics for all the blocks of the module that are          */
/* registered and are active in the current mode.                       */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  CS_PRINT_OUTPUT("\n");
  if (ten_drvr_is_esc_code_enbld()) {
    CS_PRINT_OUTPUT("\033[7m Module-x0%04X  STATS :\033[m\n", module_id);
  }
  else {
    CS_PRINT_OUTPUT("Module-0x%04X  STATS :\n", module_id);
  }

  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_SYNCDSYNC)) {
   ten_mod_print_blk_stats(module_id, TEN_ID_SYNCDSYNC);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_HSIF)) {
    ten_mod_print_blk_stats(module_id, TEN_ID_HSIF);
  }

  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_GFEC_40G)) {
    ten_mod_print_blk_stats(module_id, TEN_ID_GFEC_40G);
  }

  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_GFEC_10G)) {
    ten_mod_print_blk_stats(module_id, TEN_ID_GFEC_10G);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_UFEC)) {
    ten_mod_print_blk_stats(module_id, TEN_ID_UFEC);
  }

  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_N40G)) {
    ten_mod_print_blk_stats(module_id, TEN_ID_N40G);
  }

  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_N10G)) {
    ten_mod_print_blk_stats(module_id, TEN_ID_N10G);
  }

  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_PP10G)) {
    ten_mod_print_blk_stats(module_id, TEN_ID_PP10G);
  }

  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_PP40G)) {
    ten_mod_print_blk_stats(module_id, TEN_ID_PP40G);
  }

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  PRINT MODULE BLOCK STATS                             */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_print_blk_stats(cs_uint16 module_id, cs_uint16 block_id)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Prints the block's statistics.                                       */
/*                                                                      */
/* The [block_id] parameter is specified as one of the following:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0, ii;
  ten_stats_blk_cb_t *blk_cb;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if (blk_cb->enabled == FALSE) {
    CS_PRINT_OUTPUT("STATISTICS DISABLED FOR %s\n", blk_cb->blk_name);
    return (CS_ERROR);
  }

  if(block_id==TEN_ID_GFEC_40G)
  {
	  ten_stats_print_blk_hdr(module_id, TEN_MOD, blk_cb->blk_name);
  }

  for (ii = 0; ii < TEN_STATS_MAX_SECT; ii++) {
    /* Print Section stats if valid and are enabled */
    if ((blk_cb->p_sect_cb[ii]) && (blk_cb->p_sect_cb[ii]->enabled)) {
      ten_mod_print_sect_stats(module_id, block_id, ii);
    }
  }

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  PRINT SECTION STATS                                  */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_print_sect_stats(cs_uint16 module_id, cs_uint16 block_id,
                                   cs_uint16 sect_id)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Prints the stats for the user-specified section of the module.       */
/* Stats within a block are organized as a collection of section stats. */
/* Each section is identified by block_id and section_id combo.         */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* [sect_id]  Specifies the slice (0-3) for 10G counters or (0) for     */
/*   the 40G counters.                                                  */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *sect_cb = NULL;
  ten_stats_blk_cb_t *blk_cb;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((sect_cb = blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "Section not registered for Stats (%d)\n", sect_id);
    return (CS_ERROR);
  }

  if (sect_cb->enabled == FALSE) {
    CS_PRINT_OUTPUT("STATISTICS DISABLED FOR %s section %s\n",
             blk_cb->blk_name, sect_cb->sect_name);
    return (CS_ERROR);
  }

  ten_stats_print_sect_hdr(module_id, TEN_MOD, sect_cb->sect_name);

  ten_stats_sect_cmn_op(module_id, TEN_MOD, block_id, sect_id,
                        sect_cb, TEN_STATS_PRINT, CS_RX_AND_TX);

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  PRINT UNIT STATS                                     */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_print_unit_stats(cs_uint16 module_id, cs_uint16 block_id,
                                    cs_uint16 sect_id, cs_uint16 unit_id)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Unit Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Prints the Stats for the user specified unit for the module.         */
/* Stats for the module are organized as a collection of block          */
/* stats. Each block has number of section stats identified by section  */
/* id. Each section then has unit stats. Unit stat is the atomic entity */
/* of the stats and carry RX and TX stats. Each unit is uniquely        */
/* identified by block_id, section_id and unit_id combo.                */
/* Refer to the individual header files for the section Id and unit_id  */
/* defines.                                                             */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* The [sect_id] parameter is specified as:                             */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.          */
/*                                                                      */
/* The [unit_id] parameter is specified as:  refer to header file       */
/*   for a complete list of all counter enumeration values:             */
/*   (design/sw/drivers/T41/modules/stats/ten_stats.h)                  */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;
  ten_stats_data_t *p_unit_data;
  cs_status rtn;

  /* CS_PRINT_OUTPUT("ten_mod_print_unit_stats\n"); */

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
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
  rtn = ten_stats_unit_cmn_op(module_id, TEN_MOD,
                               block_id, sect_id, unit_id,
                               stats_sect_cb, TEN_STATS_PRINT, CS_RX_AND_TX, FALSE);
  return (rtn);                             
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR MODULE STATS                                   */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_clear_stats(cs_uint16 module_id)
/* INPUTS     : o Module Id                                             */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clear the Module stats. This clears the hardware registers and also  */
/* the internal stats structure which accumulates the stats for both    */
/* RX and TX direction for the whole module.                            */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  return ten_mod_clear_dir_stats(module_id, CS_RX_AND_TX);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR MODULE DIRECTION STATS                         */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_clear_dir_stats(cs_uint16 module_id, cs_dir_t dir)
/* INPUTS     : o Module Id                                             */
/*              o Direction                                             */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clear the Module RX/TX or Both stats. This clears the hardware       */
/* registers and also the internal stats structure which accumulates    */
/* the stats.  This clears the stats and hw register for the direction  */
/* specified.                                                           */
/*                                                                      */
/* The [dir] parameter is specified as:                                 */
/*   CS_TX = 0                                                          */
/*   CS_RX = 1                                                          */
/*   CS_TX_AND_RX = CS_RX_AND_TX = 2.                                   */ 
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_SYNCDSYNC)) {
    ten_mod_clear_blk_dir_stats(module_id, TEN_ID_SYNCDSYNC, dir);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_HSIF)) {
    ten_mod_clear_blk_dir_stats(module_id, TEN_ID_HSIF, dir);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_GFEC_40G)) {
    ten_mod_clear_blk_dir_stats(module_id, TEN_ID_GFEC_40G, dir);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_GFEC_10G)) {
    ten_mod_clear_blk_dir_stats(module_id, TEN_ID_GFEC_10G, dir);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_UFEC)) {
    ten_mod_clear_blk_dir_stats(module_id, TEN_ID_UFEC, dir);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_N40G)) {
    ten_mod_clear_blk_dir_stats(module_id, TEN_ID_N40G, dir);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_N10G)) {
    ten_mod_clear_blk_dir_stats(module_id, TEN_ID_N10G, dir);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_PP10G)) {
    ten_mod_clear_blk_dir_stats(module_id, TEN_ID_PP10G, dir);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_PP40G)) {
    ten_mod_clear_blk_dir_stats(module_id, TEN_ID_PP40G, dir);
  }
  
  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR MODULE BLOCK STATS                             */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_clear_blk_stats(cs_uint16 module_id, cs_uint16 block_id)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clears the stats for the block.                                      */
/* This API clears both the hardware counters and internal stats block  */
/* stats structure.                                                     */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  return ten_mod_clear_blk_dir_stats(module_id, block_id, CS_RX_AND_TX);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR BLOCK DIRECTION STATS                          */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_clear_blk_dir_stats(cs_uint16 module_id, cs_uint16 block_id,
                                      cs_dir_t dir)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Direction                                             */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clears the stats for the block.  This clears the stats and hw        */
/* register for the direction specified.                                */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14,                                                 */
/*   TEN_ID_PP40G = 17.                                                 */
/*                                                                      */
/* The [dir] parameter is specified as:                                 */
/*   CS_TX = 0                                                          */
/*   CS_RX = 1                                                          */
/*   CS_TX_AND_RX = CS_RX_AND_TX = 2.                                   */ 
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0, ii;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  for (ii = 0; ii < TEN_STATS_MAX_SECT; ii++) {
    if ((stats_blk_cb->p_sect_cb[ii]) && (stats_blk_cb->p_sect_cb[ii]->enabled)) {
      ten_mod_clear_sect_dir_stats(module_id, block_id, ii, dir);
    }
  }

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR SECTION STATS                                  */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_clear_sect_stats(cs_uint16 module_id, cs_uint16 block_id,
                                   cs_uint16 sect_id)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clears the Stats for the section in user specified block's section.  */
/* Refer to the individual header files for the section Id defines.     */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* The [sect_id] parameter is specified as:                             */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.          */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  return ten_mod_clear_sect_dir_stats(module_id, block_id, sect_id, CS_RX_AND_TX);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR SECTION DIRECTION STATS                        */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_clear_sect_dir_stats(cs_uint16 module_id, cs_uint16 block_id,
                                       cs_uint16 sect_id, cs_dir_t dir)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Direction                                             */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clears the Stats for the section in user specified block's section.  */
/* This clears the stats and hw register for the direction specified.   */
/* Refer to the individual header files for the section Id defines.     */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* The [sect_id] parameter is specified as:                             */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.          */
/*                                                                      */
/* The [dir] parameter is specified as:                                 */
/*   CS_TX = 0                                                          */
/*   CS_RX = 1                                                          */
/*   CS_TX_AND_RX = CS_RX_AND_TX = 2.                                   */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL, "Section not registered for Stats\n");
    return (CS_ERROR);
  }

  if (stats_sect_cb->enabled == FALSE) {
    CS_PRINT_OUTPUT("STATISTICS DISABLED FOR %s section %s\n",
             stats_blk_cb->blk_name, stats_sect_cb->sect_name);
    return (CS_ERROR);
  }

  if (block_id == TEN_ID_PP10G) {
    /* Bugzilla #31083, fix bus errors with stats */
    if (ten_pp10g_get_misc_reset(module_id, sect_id) == 0) {
      ten_pp10g_pm_clear(module_id, sect_id, 1);
    }
  }
  
  /* Bugzilla #26186, fix pp40g stats */
  if (block_id == TEN_ID_PP40G) {
    /* Bugzilla #31083, fix bus errors with stats */
    if (ten_pp40g_get_misc_sreset_t41(module_id) == 0) {
      ten_pp40g_pm_clear_t41(module_id);
    }
  }
 
  ten_stats_sect_cmn_op(module_id, TEN_MOD, block_id,
                        sect_id, stats_sect_cb, TEN_STATS_CLEAR, dir);

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR MODULE STATS UNIT                              */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_clear_unit_stats(cs_uint16 module_id, cs_uint16 block_id,
                                    cs_uint16 sect_id, cs_uint16 unit_id)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Unit Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clears the Stats for the unit in user specified block's section.     */
/* This clears the stats structure and also the hardware counters.      */
/* Refer to the individual header files for the section Id and unit Id  */
/* defines.                                                             */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14 (Not Applicable)                                 */
/*   TEN_ID_PP40G = 17 (Not Applicable)                                 */
/*                                                                      */
/* NOTE:  TEN_ID_PP10G/TEN_ID_PP40G are not supported at the unit level,*/
/*   since individual PP10G/PP40G counters cannot be cleared.           */
/*   The clearing is possible only at the sect, blk and mod level.      */
/*   No error message is given,  but the clearing is ignored at the     */
/*   unit level for PP10G/PP40G.                                        */
/*                                                                      */
/* The [sect_id] parameter is specified as:                             */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.          */
/*                                                                      */
/* The [unit_id] parameter is specified as:  refer to header file       */
/*   for a complete list of all counter enumeration values:             */
/*   (design/sw/drivers/T41/modules/stats/ten_stats.h)                  */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  return ten_mod_clear_unit_dir_stats(module_id, block_id, sect_id, unit_id, CS_RX_AND_TX);
}

/************************************************************************/
/* $rtn_hdr_start  CLEAR UNIT DIRECTION STATS                           */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_clear_unit_dir_stats(cs_uint16 module_id, cs_uint16 block_id,
                                       cs_uint16 sect_id, cs_uint16 unit_id, 
                                       cs_dir_t dir)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Unit Id                                               */
/*              o Direction                                             */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Clears the Stats for the unit in user specified block's section.     */
/* This clears the stats and hw register for the direction specified.   */
/* Refer to the individual header files for the section Id and unit Id  */
/* defines.                                                             */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14 (Not Applicable)                                 */
/*   TEN_ID_PP40G = 17 (Not Applicable).                                */
/*                                                                      */
/* NOTE:  TEN_ID_PP10G/TEN_ID_PP40G are not supported at the unit level,*/
/*   since individual PP10G/PP40G counters cannot be cleared.           */
/*   The clearing is possible only at the sect, blk and mod level.      */
/*   No error message is given,  but the clearing is ignored at the     */
/*   unit level for PP10G/PP40G.                                        */
/*                                                                      */
/* The [sect_id] parameter is specified as:                             */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.          */
/*                                                                      */
/* The [unit_id] parameter is specified as:  refer to header file       */
/*   for a complete list of all counter enumeration values:             */
/*   (design/sw/drivers/T41/modules/stats/ten_stats.h)                  */
/*                                                                      */
/* The [dir] parameter is specified as:                                 */
/*   CS_TX = 0                                                          */
/*   CS_RX = 1                                                          */
/*   CS_TX_AND_RX = CS_RX_AND_TX = 2.                                   */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL, "Section not registered for Stats\n");
    return (CS_ERROR);
  }

  if (*(stats_sect_cb->enbl_tbl + unit_id) == FALSE) {
    CS_PRINT_OUTPUT("STATS DISABLED FOR %s : SECT_ID : %d UNIT_ID : %d\n",
             stats_blk_cb->blk_name, sect_id, unit_id);
    return (CS_ERROR);
  }

  ten_set_sect_print_flag(0);

  return ten_stats_unit_cmn_op(module_id, TEN_MOD,
                               block_id, sect_id, unit_id,
                               stats_sect_cb, TEN_STATS_CLEAR, dir, FALSE);
}

/************************************************************************/
/* $rtn_hdr_start  GET MODULE STATS                                     */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_get_stats(cs_uint16 module_id, ten_mod_stats_t *pStats)
/* INPUTS     : o Module Id                                             */
/*              o Pointer to user allocated ten_mod_stats_t struct      */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Get the Stats for user specified Port.                               */
/* User should allocate at least as many bytes as size of               */
/* ten_mod_stats_t structure and pass the pointer to that as pStats     */
/* argument to the function.                                            */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (pStats == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, NULL);
    return (CS_ERROR);
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_SYNCDSYNC)) {
    ten_mod_get_blk_stats(module_id, TEN_ID_SYNCDSYNC, &pStats->syncdsync,
                           sizeof(ten_syncdsync_stats_t));
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_HSIF)) {
    ten_mod_get_blk_stats(module_id, TEN_ID_HSIF, &pStats->hsif,
                           sizeof(ten_hsif_stats_t));
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_GFEC_40G)) {
    ten_mod_get_blk_stats(module_id, TEN_ID_GFEC_40G, &pStats->gfec_40g,
                           sizeof(ten_gfec_40g_stats_t));
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_GFEC_10G)) {
    ten_mod_get_blk_stats(module_id, TEN_ID_GFEC_10G, &pStats->gfec_10g,
                           sizeof(ten_gfec_10g_stats_t));
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_UFEC)) {
    ten_mod_get_blk_stats(module_id, TEN_ID_UFEC, &pStats->ufec,
                           sizeof(ten_ufec_stats_t));
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_N40G)) {
    ten_mod_get_blk_stats(module_id, TEN_ID_N40G, &pStats->n40g,
                           sizeof(ten_n40g_stats_t));
  }
   
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_N10G)) {
    ten_mod_get_blk_stats(module_id, TEN_ID_N10G, &pStats->n10g,
                           sizeof(ten_n10g_stats_t));
  }
  
  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_PP10G)) {
    ten_mod_get_blk_stats(module_id, TEN_ID_PP10G, &pStats->pp10g,
                           sizeof(ten_pp10g_stats_t));
  }

  if (TEN_STATS_IS_BLK_REGISTERED(module_id, TEN_MOD, TEN_ID_PP40G)) {
    ten_mod_get_blk_stats(module_id, TEN_ID_PP40G, &pStats->pp40g,
                         sizeof(ten_pp40g_stats_t));
  }

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  GET MODULE BLOCK STATS                               */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_get_blk_stats(cs_uint16 module_id, cs_uint16 block_id,
                                void *pStats, cs_uint16 len)
/* INPUTS     : o Module Id                                             */
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
/* found in individual blocks's header file.                            */
/* The structure returned will contain all of the block's counters.     */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* The [*pStats] parameter is specified as a pointer to one of these    */
/*   structures:                                                        */
/*   ten_syncdsync_stats_t                                              */ 
/*   ten_hsif_stats_t                                                   */
/*   ten_gfec_40g_stats_t                                               */
/*   ten_gfec_10g_stats_t                                               */
/*   ten_ufec_stats_t                                                   */
/*   ten_n40g_stats_t                                                   */
/*   ten_n10g_stats_t                                                   */
/*   ten_pp10g_stats_t                                                  */
/*   ten_pp40g_stats_t                                                  */
/*                                                                      */
/* The [len] parameter is the length of the user allocated memory where */
/* block stats will be copied.  It will be "sizeof" the structure       */
/* pointed to by pStats.                                                */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0, ii;
  ten_stats_blk_cb_t *stats_blk_cb;
  cs_uint16 blk_stats_len = 0;
  void *p_blk_stats = 0;
  ten_mod_stats_t *p_mod_stats;
  ten_mod_cb_t *pcb;


  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (pStats == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }
  
  pcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  if (!pcb) {
    return (CS_ERROR);
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    return (CS_ERROR);
  }
  
  switch (block_id) {
     
  case TEN_ID_SYNCDSYNC:
    p_blk_stats = (void *)&p_mod_stats->syncdsync;
    blk_stats_len = sizeof(ten_syncdsync_stats_t);
    break;
  
  case TEN_ID_HSIF:
    p_blk_stats = (void *)&p_mod_stats->hsif;
    blk_stats_len = sizeof(ten_hsif_stats_t);
    break;
  
  case TEN_ID_GFEC_40G:
    p_blk_stats = (void *)&p_mod_stats->gfec_40g;
    blk_stats_len = sizeof(ten_gfec_40g_stats_t);
    break;

  case TEN_ID_GFEC_10G:
    p_blk_stats = (void *)&p_mod_stats->gfec_10g;
    blk_stats_len = sizeof(ten_gfec_10g_stats_t);
    break;
    
  case TEN_ID_UFEC:
    p_blk_stats = (void *)&p_mod_stats->ufec;
    blk_stats_len = sizeof(ten_ufec_stats_t);
    break;
    
  case TEN_ID_N40G:
    p_blk_stats = (void *)&p_mod_stats->n40g;
    blk_stats_len = sizeof(ten_n40g_stats_t);
    break;
    
  case TEN_ID_N10G:
    p_blk_stats = (void *)&p_mod_stats->n10g;
    blk_stats_len = sizeof(ten_n10g_stats_t);
    break;
    
  case TEN_ID_PP10G:
    p_blk_stats = (void *)&p_mod_stats->pp10g;
    blk_stats_len = sizeof(ten_pp10g_stats_t);
    break;
    
  case TEN_ID_PP40G:
    p_blk_stats = (void *)&p_mod_stats->pp40g;
    blk_stats_len = sizeof(ten_pp40g_stats_t);
    break;
     
  default:
    return (CS_ERROR);
  }

  if (len < blk_stats_len) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_SIZE, "len s/b %d\n", blk_stats_len);
    return (CS_ERROR);
  }

  for (ii = 0; ii < TEN_STATS_MAX_SECT; ii++) {
    /* Print Section stats if valid and are enabled */
    if ((stats_blk_cb->p_sect_cb[ii]) && (stats_blk_cb->p_sect_cb[ii]->enabled)) {
      ten_stats_sect_cmn_op(module_id, TEN_MOD,
                            block_id, ii,
                            stats_blk_cb->p_sect_cb[ii], TEN_STATS_GET, CS_RX_AND_TX);
    }
  }

  CS_MEMCPY(pStats, p_blk_stats, len);

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  GET SECTION STATS                                    */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_get_sect_stats(cs_uint16 module_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, void *pStats, cs_uint16 len)
/* INPUTS     : o Module Id                                             */
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
/* definitions and for section Id defines.                              */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* The [sect_id] parameter is specified as:                             */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.          */
/*                                                                      */
/* The [*pStats] parameter is specified as a pointer to one of these    */
/*   structures:                                                        */
/*   ten_syncdsync_stats_t                                              */ 
/*   ten_hsif_stats_t                                                   */
/*   ten_gfec_40g_stats_t                                               */
/*   ten_gfec_10g_stats_t                                               */
/*   ten_ufec_stats_t                                                   */
/*   ten_n40g_stats_t                                                   */
/*   ten_n10g_stats_t                                                   */
/*   ten_pp10g_stats_t                                                  */
/*   ten_pp40g_stats_t                                                  */
/*                                                                      */
/* The [len] parameter is the length of the user allocated memory where */
/* block stats will be copied.  It will be "sizeof" the structure       */
/* pointed to by pStats.                                                */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;
  ten_stats_data_t *p_unit_data;
  cs_uint16 sect_stats_len;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (pStats == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "Section not registered for Stats (%d)\n", sect_id);
    return (CS_ERROR);
  }

  sect_stats_len = (sizeof(ten_stats_data_t) * stats_sect_cb->num_entries);

  if (len < sect_stats_len) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_SIZE, "len s/b %d\n", sect_stats_len);
    return (CS_ERROR);
  }

  p_unit_data = stats_sect_cb->pStats;
  ten_stats_sect_cmn_op(module_id, TEN_MOD,
                        block_id, sect_id, stats_sect_cb, TEN_STATS_GET, CS_RX_AND_TX);

  CS_MEMCPY(pStats, p_unit_data, len);

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  GET SECTION DIRECTION STATS                          */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_get_sect_dir_stats(cs_uint16 module_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, cs_dir_t dir, 
                                 void *pStats, cs_uint16 len)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Direction                                             */
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
/* definitions and for section Id defines.                              */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* The [sect_id] parameter is specified as:                             */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.          */
/*                                                                      */
/* The [dir] parameter is specified as:                                 */
/*   CS_TX = 0                                                          */
/*   CS_RX = 1                                                          */
/*   CS_TX_AND_RX = CS_RX_AND_TX = 2.                                   */
/*                                                                      */
/* The [*pStats] parameter is specified as a pointer to one of these    */
/*   structures:                                                        */
/*   ten_syncdsync_stats_t                                              */ 
/*   ten_hsif_stats_t                                                   */
/*   ten_gfec_40g_stats_t                                               */
/*   ten_gfec_10g_stats_t                                               */
/*   ten_ufec_stats_t                                                   */
/*   ten_n40g_stats_t                                                   */
/*   ten_n10g_stats_t                                                   */
/*   ten_pp10g_stats_t                                                  */
/*   ten_pp40g_stats_t                                                  */
/*                                                                      */
/* The [len] parameter is the length of the user allocated memory where */
/* block stats will be copied.  It will be "sizeof" the structure       */
/* pointed to by pStats.                                                */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;
  ten_stats_data_t *p_unit_data;
  cs_uint16 sect_stats_len;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (pStats == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "Section not registered for Stats (%d)\n", sect_id);
    return (CS_ERROR);
  }

  sect_stats_len = (sizeof(ten_stats_data_t) * stats_sect_cb->num_entries);

  if (len < sect_stats_len) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_INVALID_SIZE, "len s/b %d\n", sect_stats_len);
    return (CS_ERROR);
  }

  p_unit_data = stats_sect_cb->pStats;
  ten_stats_sect_cmn_op(module_id, TEN_MOD,
                        block_id, sect_id, stats_sect_cb, TEN_STATS_GET, dir);

  CS_MEMCPY(pStats, p_unit_data, len);

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  GET MODULE UNIT DIRECTION STATS                      */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_get_unit_stats(cs_uint16 module_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, cs_uint16 unit_id,
                                 cs_dir_t dir, 
                                 ten_stats_data_t *pUnit_Stats)
/* INPUTS     : o Module Id                                             */
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
/* both RX and TX or only RX or only TX might be valid. In case only    */
/* one direction is valid, the other counter will be Zero.              */
/* Refer to the individual header files for the section Id and unit id  */
/* defines.                                                             */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* The [sect_id] parameter is specified as:                             */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.          */
/*                                                                      */
/* The [unit_id] parameter is specified as:  refer to header file       */
/*   for a complete list of all counter enumeration values:             */
/*   (design/sw/drivers/T41/modules/stats/ten_stats.h)                  */
/*                                                                      */
/* The [dir] parameter is specified as:                                 */
/*   CS_TX = 0                                                          */
/*   CS_RX = 1                                                          */
/*   CS_TX_AND_RX = CS_RX_AND_TX = 2.                                   */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;
  ten_stats_data_t *p_unit_data;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (pUnit_Stats == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }
  
  if (dir > CS_RX_AND_TX) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }
  
  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "Section not registered for Stats (%d)\n", sect_id);
    return (CS_ERROR);
  }

  if (unit_id >= stats_sect_cb->num_entries) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  ten_set_sect_print_flag(0);

  ten_stats_unit_cmn_op(module_id, TEN_MOD,
                        block_id, sect_id, unit_id,
                        stats_sect_cb, TEN_STATS_GET, dir, FALSE);

  p_unit_data = stats_sect_cb->pStats + unit_id;
  CS_MEMCPY(pUnit_Stats, p_unit_data, sizeof(ten_stats_data_t));

  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE MODULE BLOCK STATS                    */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_ctl_blk_stats(cs_uint16 module_id, cs_uint16 block_id, 
                                cs_ctl_t ctl)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Control                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Enable/Disable the stats for the block.                              */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14                                                  */
/*   TEN_ID_PP40G = 17                                                  */
/*                                                                      */
/* The [ctl] parameter is specified as CS_DISABLE (0) or CS_ENABLE (1). */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  stats_blk_cb->enabled = (ctl == CS_ENABLE) ? TRUE : FALSE;
  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE MODULE SECTION STATS                  */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_ctl_sect_stats(cs_uint16 module_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, cs_ctl_t ctl)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Control                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Enable/Disable the Stats for the section in user specified block.    */
/* Refer to the individual header files for the section Id defines.     */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14,                                                 */
/*   TEN_ID_PP40G = 17.                                                 */
/*                                                                      */
/* The [sect_id] parameter is specified as:                             */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.          */
/*                                                                      */
/* The [ctl] parameter is specified as CS_DISABLE (0) or CS_ENABLE (1). */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "Section not registered for Stats (%d)\n", sect_id);
    return (CS_ERROR);
  }

  stats_sect_cb->enabled = (ctl == CS_ENABLE) ? TRUE : FALSE;
  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE STATS UNIT                            */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_ctl_unit_stats(cs_uint16 module_id, cs_uint16 block_id,
                                 cs_uint16 sect_id, cs_uint16 unit_id, cs_ctl_t ctl)
/* INPUTS     : o Module Id                                             */
/*              o Block Id                                              */
/*              o Section Id                                            */
/*              o Unit Id                                               */
/*              o Control                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Enable/Disable the Stats for the section in user specified block.    */
/* Refer to the individual header files for the section Id and unit Id  */
/* defines. Unit Id is the atomic unit of stats, which consists of the  */
/* RX and TX side stats.                                                */
/*                                                                      */
/* [block_id]  Specifies in which block the counter is contained:       */
/*   TEN_ID_SYNCDSYNC = 3,                                              */
/*   TEN_ID_HSIF = 6,                                                   */
/*   TEN_ID_GFEC_40G = 8,                                               */
/*   TEN_ID_GFEC_10G = 9,                                               */
/*   TEN_ID_UFEC = 10,                                                  */
/*   TEN_ID_N40G = 11,                                                  */
/*   TEN_ID_N10G = 13,                                                  */
/*   TEN_ID_PP10G = 14,                                                 */
/*   TEN_ID_PP40G = 17.                                                 */
/*                                                                      */
/* The [sect_id] parameter is specified as:                             */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.          */
/*                                                                      */
/* The [unit_id] parameter is specified as:  refer to header file       */
/*   for a complete list of all counter enumeration values:             */
/*   (design/sw/drivers/T41/modules/stats/ten_stats.h)                  */
/*                                                                      */
/* The [ctl] parameter is specified as CS_DISABLE (0) or CS_ENABLE (1). */
/*                                                                      */
/* $rtn_hdr_end                                                         */
/************************************************************************/
{
  cs_uint32 error = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (sect_id >= TEN_STATS_MAX_SECT) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_RANGE_ERR, NULL);
    return (CS_ERROR);
  }

  stats_blk_cb = ten_stats_get_blk_cb(module_id, TEN_MOD, block_id);
  if (stats_blk_cb == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL,
                  "%s not registered for Stats\n", ten_get_block_name(block_id));
    return (CS_ERROR);
  }

  if ((stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id]) == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_TBL_NULL, "Section not registered for Stats\n");
    return (CS_ERROR);
  }

  if (unit_id >= stats_sect_cb->num_entries) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_ID_OUT_OF_RANGE,
                  "Unit Stat specified out of Range (%d)\n", unit_id);
    return (CS_ERROR);
  }

  *(stats_sect_cb->enbl_tbl + unit_id) = ((ctl == CS_ENABLE) ? TRUE : FALSE);
  return (CS_OK);
}

/************************************************************************/
/* $rtn_hdr_start  LOAD MODULE STATS                                    */
/* CATEGORY   : API                                                     */
/* ACCESS     : Public                                                  */
/* BLOCK      : STATS                                                   */
/* CHIP       : Tenabo                                                  */
cs_status ten_mod_load_stats(cs_uint16 module_id, ten_mod_stats_t *pStats)
/* INPUTS     : o Module Id                                             */
/*              o Pointer to user allocated ten_mod_stats_t struct      */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Load the user-provided statistic counters into the driver.           */
/* Normally, after cold initialization the driver statistic             */
/* counters are cleared.  This API is provided so that the              */
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
  ten_mod_stats_t *p_mod_stats = NULL;
  ten_mod_cb_t *pcb;

  if (TEN_IS_MOD_VALID(module_id, &error) != TRUE) {
    CS_HNDL_ERROR(module_id, error, NULL);
    return (CS_ERROR);
  }

  if (pStats == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }

  pcb = TEN_MOD_ID_TO_PCB_PTR(module_id);
  if (!pcb) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  
  if (p_mod_stats == NULL) {
    CS_HNDL_ERROR(module_id, ETEN_MOD_NULL_PTR, NULL);
    return (CS_ERROR);
  }

  CS_MEMCPY(p_mod_stats, pStats, sizeof(ten_mod_stats_t));
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start   TEN MOD READ STAT                           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : STATS                                           */
/* CHIP       : Tenabo                                          */
cs_uint64 ten_mod_read_stat(cs_uint16 mod_id, cs_uint16 block_id,
                            cs_uint16 sect_id, cs_uint16 unit_id, 
                            cs_dir_t dir)
/* INPUTS     : o Module Id                                     */
/*              o Block Id                                      */
/*              o Section Id                                    */
/*              o Unit Id                                       */
/*              o Direction                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : 64 bit counter                                  */
/* DESCRIPTION:                                                 */
/* Reads an individual counter for the specified direction.     */
/* This wraps the API ten_mod_get_unit_stats, mainly for use    */
/* in APISH scripts.                                            */
/*                                                              */
/* [block_id]                                                   */
/*   TEN_ID_SYNCDSYNC  = 3,                                     */
/*   TEN_ID_HSIF       = 6,                                     */
/*   TEN_ID_GFEC_40G   = 8,                                     */
/*   TEN_ID_GFEC_10G   = 9,                                     */
/*   TEN_ID_UFEC       = 10,                                    */
/*   TEN_ID_N40G       = 11,                                    */
/*   TEN_ID_N10G       = 13,                                    */
/*   TEN_ID_PP10G      = 14,                                    */
/*   TEN_ID_PP40G      = 17                                     */
/*                                                              */
/* [sect_id] parameter is specified as:                         */
/*   slice (0-3) for 10G counters or (0) for the 40G counters.  */
/*                                                              */
/* [unit_id]                                                    */
/*   unit_id refers to the unit enumerations available for      */
/*   each individual unit counter of CS600X.                    */
/*   See design/sw/drivers/T41/modules/stats/ten_stats.h        */
/*   header file for the complete list of stats enumerations    */
/*   available in each block/section.                           */
/*                                                              */
/*   When using block_id = TEN_ID_SYNCDSYNC:                    */
/*   Use dir = CS_TX or CS_RX,                                  */
/*   Use sect_id (0-3) for the four 10G slices and unit_id:     */
/*   TEN_SYNCDSYNC_CFGMON_ODTU23_PJO1_STAT = 0,                 */
/*   TEN_SYNCDSYNC_CFGMON_ODTU23_NJO1_STAT = 1,                 */
/*   TEN_SYNCDSYNC_CFGMON_OXUN_PJO1_STAT   = 2,                 */
/*   TEN_SYNCDSYNC_CFGMON_OXUN_NJO1_STAT   = 3,                 */
/*                                                              */
/*   When using block_id = TEN_ID_HSIF for Multirate Serdes,    */
/*   Use sect_id = 0-3 for the four 10G slices,                 */
/*   dir = CS_RX for all and unit_id:                           */
/*   TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK0_STAT = 0,      */
/*   TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK1_STAT = 1,      */
/*   TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK2_STAT = 2,      */
/*   TEN_HSIF_MR_SLC0_MR10X4_SDS_COMMON_PRBSCHK3_STAT = 3,      */
/*                                                              */
/*   TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK0_STAT = 0,      */
/*   TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK1_STAT = 1,      */
/*   TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK2_STAT = 2,      */
/*   TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK3_STAT = 3,      */
/*   TEN_HSIF_MR_SLC1_MR10X5_SDS_COMMON_PRBSCHK4_STAT = 4,      */
/*                                                              */
/*   TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK0_STAT = 0,      */
/*   TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK1_STAT = 1,      */
/*   TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK2_STAT = 2,      */
/*   TEN_HSIF_MR_SLC2_MR10X4_SDS_COMMON_PRBSCHK3_STAT = 3,      */
/*                                                              */
/*   TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK0_STAT = 0,      */
/*   TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK1_STAT = 1,      */
/*   TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK2_STAT = 2,      */
/*   TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK3_STAT = 3,      */
/*   TEN_HSIF_MR_SLC3_MR10X5_SDS_COMMON_PRBSCHK4_STAT = 4,      */
/*                                                              */
/*   When using block_id = TEN_ID_HSIF for XFI,                 */
/*   Use sect_id = 4 for XFI, dir = CS_RX for all and unit_id:  */ 
/*   TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK0_STAT = 0,      */
/*   TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK1_STAT = 1,      */
/*   TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK2_STAT = 2,      */
/*   TEN_XFI32X1_SDS_XFI32X1_SDS_COMMON_PRBSCHK3_STAT = 3,      */
/*                                                              */
/*   When using block_id = TEN_ID_HSIF for CFP,                 */
/*   Use sect_id = 5 for XFI, dir = CS_RX for all and unit_id:  */ 
/*   TEN_CFP32X1_SDS_COMMON_PRBSCHK_STAT_SLICE_0 = 0,           */
/*   TEN_CFP32X1_SDS_COMMON_PRBSCHK_STAT_SLICE_1 = 1,           */
/*   TEN_CFP32X1_SDS_COMMON_PRBSCHK_STAT_SLICE_2 = 2,           */
/*   TEN_CFP32X1_SDS_COMMON_PRBSCHK_STAT_SLICE_3 = 3,           */
/*                                                              */
/*   When using block_id = TEN_ID_GFEC_40G:                     */
/*   Use dir = CS_RX for all,                                   */
/*   Use sect_id = 0 for the single 40G slice and unit_id:      */
/*   TEN_GFEC40G_FRX40_RZBTER0_STAT = 0,                        */
/*   TEN_GFEC40G_FRX40_ROBTER0_STAT = 1,                        */
/*   TEN_GFEC40G_FRX40_RBYTER0_STAT = 2,                        */
/*   TEN_GFEC40G_FRX40_RERROV0_STAT = 3,                        */
/*                                                              */
/*   When using block_id = TEN_ID_GFEC_10G:                     */
/*   Use dir = CS_RX for all,                                   */
/*   Use sect_id (0-3) for the four 10G slices and unit_id:     */
/*   TEN_GFEC10G_FRX40_RZBTER0_STAT = 0,                        */
/*   TEN_GFEC10G_FRX40_ROBTER0_STAT = 1,                        */
/*   TEN_GFEC10G_FRX40_RBYTER0_STAT = 2,                        */
/*   TEN_GFEC14G_FRX40_RERROV0_STAT = 3,                        */
/*                                                              */
/*   When using block_id = TEN_ID_UFEC:                         */
/*   Use dir = CS_RX for all,                                   */
/*   Use sect_id (0-3) for the four instances and unit_id:      */
/*   TEN_UFEC_URX_R1C00_STAT = 0,                               */
/*   TEN_UFEC_URX_R1C10_STAT = 1,                               */
/*   TEN_UFEC_URX_R1EO0_STAT = 2,                               */
/*   TEN_UFEC_URX_C1C00_STAT = 3,                               */
/*   TEN_UFEC_URX_C1C10_STAT = 4,                               */
/*   TEN_UFEC_URX_C1EO0_STAT = 5,                               */
/*   TEN_UFEC_URX_R2C00_STAT = 6,                               */
/*   TEN_UFEC_URX_R2C10_STAT = 7,                               */
/*   TEN_UFEC_URX_R2EO0_STAT = 8,                               */
/*   TEN_UFEC_URX_C2C00_STAT = 9,                               */
/*   TEN_UFEC_URX_C2C10_STAT = 10,                              */
/*   TEN_UFEC_URX_C2EO0_STAT = 11,                              */
/*   TEN_UFEC_URX_R3C00_STAT = 12,                              */
/*   TEN_UFEC_URX_R3C10_STAT = 13,                              */
/*   TEN_UFEC_URX_R3EO0_STAT = 14,                              */
/*   TEN_UFEC_URX_TC00_STAT = 15,                               */
/*   TEN_UFEC_URX_TC10_STAT = 16,                               */
/*   TEN_UFEC_URX_TEO0_STAT = 17,                               */
/*   TEN_UFEC_URX_MSYNCERRCNT_STAT = 18                         */
/*                                                              */
/*   When using block_id = TEN_ID_N40G:                         */
/*   Use dir = CS_RX,                                           */
/*   Use sect_id = 0 for the single 40G slice and unit_id:      */
/*   {Refer to ten_stats.h for the complete list}               */
/*                                                              */
/*   When using block_id = TEN_ID_N10G:                         */
/*   Use dir = CS_RX,                                           */
/*   Use sect_id (0-3) for the four 10G slices and unit_id:     */
/*   {Refer to ten_stats.h for the complete list}               */
/*                                                              */
/*   When using block_id = TEN_ID_PP10G:                        */
/*   Use dir = CS_TX or CS_RX,                                  */
/*   Refer to the unit enumeration -- has "TX" or "RX"          */
/*   contained in it -- choose dir = CS_TX or CS_RX to match.   */
/*   Use sect_id (0-3) for the four 10G slices and unit_id:     */
/*   {Refer to ten_stats.h for the complete list}               */
/*                                                              */
/*   When using block_id = TEN_ID_PP40G:                        */
/*   Use dir = CS_TX or CS_RX,                                  */
/*   Refer to the unit enumeration -- has "TX" or "RX"          */
/*   contained in it -- choose dir = CS_TX or CS_RX to match.   */
/*   Use sect_id (0), (ie N/A for 40G)                          */
/*   {Refer to ten_stats.h for the complete list}               */
/*                                                              */
/* [dir]  direction of the counter:                             */
/*   CS_TX = 0                                                  */
/*   CS_RX = 1.                                                 */
/*                                                              */
/* $rtn_hdr_end.                                                */
/****************************************************************/
{
  ten_stats_data_t temp_stats_data;
  cs_uint64 ret_val = 0xBADDEAD;
  
  temp_stats_data.rx_ms = 0xBADDEAD;
  temp_stats_data.rx_ls = 0xBADDEAD;
  temp_stats_data.tx_ms = 0xBADDEAD;
  temp_stats_data.tx_ls = 0xBADDEAD;

  if (ten_mod_get_unit_stats(mod_id, block_id, sect_id, unit_id, dir,
                             &temp_stats_data) != CS_OK) {
    CS_HNDL_ERROR(mod_id, ETEN_DEV_INVALID_OP, "Parameter out of range.\n");
  }
                                     
  if (dir == CS_RX) {
    ret_val = ((cs_uint64)(temp_stats_data.rx_ms) << 32) | temp_stats_data.rx_ls;
    CS_PRINT("stats_data.rx_ms = 0x%04X\n", temp_stats_data.rx_ms);
    CS_PRINT("stats_data.rx_ls = 0x%04X\n", temp_stats_data.rx_ls);
  }
  else if (dir == CS_TX) {
    ret_val = ((cs_uint64)(temp_stats_data.tx_ms) << 32) | temp_stats_data.tx_ls;
    CS_PRINT("stats_data.tx_ms = 0x%04X\n", temp_stats_data.tx_ms);
    CS_PRINT("stats_data.tx_ls = 0x%04X\n", temp_stats_data.tx_ls);
  }
  return (ret_val);
}

