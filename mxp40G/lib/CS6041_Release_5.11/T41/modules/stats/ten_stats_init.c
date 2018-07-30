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
 * ten_init_stats.c
 *
 * $Id: ten_stats_init.c,v 1.9 2013/02/22 20:48:50 jccarlis Exp $
 *
 */

#include "tenabo40.h"

/****************************************************************/
/* NAME       : GET BLOCK NAME                                  */
/* INPUTS     : Block Id                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : String                                          */
/* DESCRIPTION:                                                 */
/* Returns text string corresponding to block id.               */
/****************************************************************/
cs_char8 *ten_get_block_name(cs_uint16 block_id)
{
  cs_char8 *block_name;
  switch (block_id) {
  
  case TEN_ID_MPIF:
    block_name = "MPIF";
    break;

  case TEN_ID_GLB:
    block_name = "GLB";
    break;

  case TEN_ID_XCON:
    block_name = "XCON";
    break;

  case TEN_ID_SYNCDSYNC:
    block_name = "SYNCDSYNC";
    break;
    
  case TEN_ID_GPLLX1:
    block_name = "GPLLX1";
    break;

  case TEN_ID_SPOH:
    block_name = "SPOH";
    break;

  case TEN_ID_HSIF:
    block_name = "HSIF";
    break;

  case TEN_ID_XFI32X1:
    block_name = "XFI32X1";
    break;

  case TEN_ID_CFP32X1:
    block_name = "CPF32X1";
    break;

  case TEN_ID_GFEC_40G:
    block_name = "GFEC_40G";
    break;

  case TEN_ID_GFEC_10G:
    block_name = "GFEC_10G";
    break;

  case TEN_ID_UFEC:
    block_name = "UFEC";
    break;

  case TEN_ID_N40G:
    block_name = "N40G";
    break;

  case TEN_ID_OHPP:
    block_name = "OHPP";
    break;

  case TEN_ID_N10G:
    block_name = "N10G";
    break;

  case TEN_ID_PP10G:
    block_name = "PP10G";
    break;
  
  case TEN_ID_PP40G:
    block_name = "PP40G";
    break;
  
  case TEN_ID_PDCAL:
    block_name = "PDCAL";
    break;
    
  case TEN_ID_DM:
    block_name = "DM";
    break;
  
  default:
    block_name = "?UNKNOWN?";
    break;
  }
  return (block_name);
}

/****************************************************************/
/* NAME       : INIT XCON STATS                                 */
/* INPUTS     : Dev Id                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Internal function to init the Stats. This will register      */
/* the XCON block and its stats control tables with the         */
/* stats engine.                                                */
/****************************************************************/
cs_status ten_dev_init_xcon_stats(cs_uint16 dev_id)
{
  ten_dev_stats_t *p_dev_stats;

  if (!ten_stats_register_blk_cb(dev_id, TEN_DEVICE, TEN_ID_XCON, 
       TRUE, NULL, NULL, NULL)) {
    return (CS_ERROR);
  }

  p_dev_stats = TEN_DEV_GET_STATS_PTR(dev_id);
  if (p_dev_stats == NULL) {
    CS_PRINT_OUTPUT("dev-%d p_dev_stats is NULL\n", dev_id);
    return (CS_ERROR);
  }

  /* Each instance (0-7) of XCON stats gets its own section */
  if (ten_stats_add_sect_tbl_entry(dev_id, TEN_DEVICE, TEN_ID_XCON,
                                   "XCON Stats 0",
                                   0, 0, 0, TRUE,
                                   TEN_XCON_MAX_STAT,
                                   &(p_dev_stats->xcon.stats[0][0]),
                                   stats_table_xcon_0) != CS_OK) {
      return (CS_ERROR);
  }

  if (ten_stats_add_sect_tbl_entry(dev_id, TEN_DEVICE, TEN_ID_XCON,
                                   "XCON Stats 1",
                                   1, 0, 0, TRUE,
                                   TEN_XCON_MAX_STAT,
                                   &(p_dev_stats->xcon.stats[1][0]),
                                   stats_table_xcon_1) != CS_OK) {
      return (CS_ERROR);
  }
  
  if (ten_stats_add_sect_tbl_entry(dev_id, TEN_DEVICE, TEN_ID_XCON,
                                   "XCON Stats 2",
                                   2, 0, 0, TRUE,
                                   TEN_XCON_MAX_STAT,
                                   &(p_dev_stats->xcon.stats[2][0]),
                                   stats_table_xcon_2) != CS_OK) {
      return (CS_ERROR);
  }

  if (ten_stats_add_sect_tbl_entry(dev_id, TEN_DEVICE, TEN_ID_XCON,
                                   "XCON Stats 3",
                                   3, 0, 0, TRUE,
                                   TEN_XCON_MAX_STAT,
                                   &(p_dev_stats->xcon.stats[3][0]),
                                   stats_table_xcon_3) != CS_OK) {
      return (CS_ERROR);
  }

  if (ten_stats_add_sect_tbl_entry(dev_id, TEN_DEVICE, TEN_ID_XCON,
                                   "XCON Stats 4",
                                   4, 0, 0, TRUE,
                                   TEN_XCON_MAX_STAT,
                                   &(p_dev_stats->xcon.stats[4][0]),
                                   stats_table_xcon_4) != CS_OK) {
      return (CS_ERROR);
  }

  if (ten_stats_add_sect_tbl_entry(dev_id, TEN_DEVICE, TEN_ID_XCON,
                                   "XCON Stats 5",
                                   5, 0, 0, TRUE,
                                   TEN_XCON_MAX_STAT,
                                   &(p_dev_stats->xcon.stats[5][0]),
                                   stats_table_xcon_5) != CS_OK) {
      return (CS_ERROR);
  }

  if (ten_stats_add_sect_tbl_entry(dev_id, TEN_DEVICE, TEN_ID_XCON,
                                   "XCON Stats 6",
                                   6, 0, 0, TRUE,
                                   TEN_XCON_MAX_STAT,
                                   &(p_dev_stats->xcon.stats[6][0]),
                                   stats_table_xcon_6) != CS_OK) {
      return (CS_ERROR);
  }

  if (ten_stats_add_sect_tbl_entry(dev_id, TEN_DEVICE, TEN_ID_XCON,
                                   "XCON Stats 7",
                                   7, 0, 0, TRUE,
                                   TEN_XCON_MAX_STAT,
                                   &(p_dev_stats->xcon.stats[7][0]),
                                   stats_table_xcon_7) != CS_OK) {
      return (CS_ERROR);
  }
  
  return (CS_OK);
}

/************************************************************************/
/* NAME       : INIT SYNCDSYNC STATS                                    */
/* INPUTS     : Module Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Internal function to initialize the Stats.  This will                */
/* register the SYNCDSYNC block and its stats control tables with       */
/* the stats engine.                                                    */
/************************************************************************/
cs_status ten_mod_init_syncdsync_stats(cs_uint16 mod_id)
{
  ten_mod_stats_t *p_mod_stats;
  ten_mod_cb_t *pcb;
  cs_uint8 mod_num;

  /* Register Mapper Stats */
  if (!ten_stats_register_blk_cb(mod_id, TEN_MOD,
                TEN_ID_SYNCDSYNC, TRUE, NULL, NULL, NULL)) {
    return (CS_ERROR);
  }

  pcb = TEN_MOD_ID_TO_PCB_PTR(mod_id);
  if (!pcb) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  
  mod_num = TEN_MOD_ID_TO_MOD_NUM(mod_id);
 
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_SYNCDSYNC,
                                   "SYNCDSYNC Slice 0 Stats",
                                   0, mod_num, TEN_SYNCDSYNCRX_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_SYNCDSYNC_MAX_STAT,
                                   &(p_mod_stats->syncdsync.stats[0][0]),
                                   stats_table_syncdsync_0) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_SYNCDSYNC,
                                   "SYNCDSYNC Slice 1 Stats",
                                   1, mod_num, TEN_SYNCDSYNCRX_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_SYNCDSYNC_MAX_STAT,
                                   &(p_mod_stats->syncdsync.stats[1][0]),
                                   stats_table_syncdsync_1) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_SYNCDSYNC,
                                   "SYNCDSYNC Slice 2 Stats",
                                   2, mod_num, TEN_SYNCDSYNCRX_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_SYNCDSYNC_MAX_STAT,
                                   &(p_mod_stats->syncdsync.stats[2][0]),
                                   stats_table_syncdsync_2) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_SYNCDSYNC,
                                   "SYNCDSYNC Slice 3 Stats",
                                   3, mod_num, TEN_SYNCDSYNCRX_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_SYNCDSYNC_MAX_STAT,
                                   &(p_mod_stats->syncdsync.stats[3][0]),
                                   stats_table_syncdsync_3) != CS_OK) {
    return (CS_ERROR);
  }                                
                                   
  return (CS_OK);
}

/************************************************************************/
/* NAME       : INIT HSIF STATS                                         */
/* INPUTS     : Module Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Internal function to initialize the Stats.  This will                */
/* register the HSIF block and its stats control tables with            */
/* the stats engine.                                                    */
/************************************************************************/
cs_status ten_mod_init_hsif_stats(cs_uint16 mod_id)
{
  ten_mod_stats_t *p_mod_stats;
  ten_mod_cb_t *pcb;
  cs_uint8 mod_num;

  /* Register Mapper Stats */
  if (!ten_stats_register_blk_cb(mod_id, TEN_MOD,
                TEN_ID_HSIF, TRUE, NULL, NULL, NULL)) {
    return (CS_ERROR);
  }

  pcb = TEN_MOD_ID_TO_PCB_PTR(mod_id);
  if (!pcb) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  
  mod_num = TEN_MOD_ID_TO_MOD_NUM(mod_id);
 
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_HSIF,                  /* dpid, dp, blk_id */
                                   "HSIF MR SLC0 Stats",                          /* sect_name */
                                   0, mod_num, TEN_HSIF_STRIDE * sizeof(cs_reg),  /* sect_id, stride_id, stride_size */
                                   TRUE, TEN_HSIF_MR_SLC0_MAX_STAT,               /* ctl_enabled, num_child */
                                   &(p_mod_stats->hsif.stats_slc0[0]),            /* p_data */
                                   stats_table_hsif_slc0) != CS_OK) {             /* p_info_tbl */
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_HSIF,
                                   "HSIF MR SLC1 Stats",
                                   1, mod_num, TEN_HSIF_STRIDE * sizeof(cs_reg), 
                                   TRUE, TEN_HSIF_MR_SLC1_MAX_STAT,
                                   &(p_mod_stats->hsif.stats_slc1[0]),
                                   stats_table_hsif_slc1) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_HSIF,
                                   "HSIF MR SLC2 Stats",
                                   2, mod_num, TEN_HSIF_STRIDE * sizeof(cs_reg), 
                                   TRUE, TEN_HSIF_MR_SLC2_MAX_STAT,
                                   &(p_mod_stats->hsif.stats_slc2[0]),
                                   stats_table_hsif_slc2) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_HSIF,
                                   "HSIF MR SLC3 Stats",
                                   3, mod_num, TEN_HSIF_STRIDE * sizeof(cs_reg), 
                                   TRUE, TEN_HSIF_MR_SLC3_MAX_STAT,
                                   &(p_mod_stats->hsif.stats_slc3[0]),
                                   stats_table_hsif_slc3) != CS_OK) {
    return (CS_ERROR);
  }
  
  /* Bugzilla #30649, fix bus errors during stats access */
  if (mod_num == TEN_MODULE_B) {
    if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_HSIF,
                                     "HSIF XFI Stats",
                                     4, 0, 0, 
                                     TRUE, TEN_HSIF_XFI_MAX_STAT,
                                     &(p_mod_stats->hsif.stats_xfi[0]),
                                     stats_table_hsif_xfi) != CS_OK) {

      return (CS_ERROR);
    }
  }

  /* If T41 register cfp32x1 block, bugzilla 26512, include CFP stats with module B stats not dev stats */
  if ( (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(mod_id)) && (mod_num == 1) ) ) {
    if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_HSIF,                      /* dpid, dp, block id */
                                     "HSIF CFP32X1 Stats", 5, mod_num,                  /* section name, section ID, stride ID */
                                     0,                                                 /* stride size, */
                                     TRUE, TEN_HSIF_CFP_MAX_STAT,                       /* ctl_enabled, num child */
                                     &(p_mod_stats->hsif.stats_cfp[0]),                 /* p stats data */
                                     stats_table_hsif_cfp) != CS_OK) {                  /* p stats info */
      return (CS_ERROR);
    }   
  }
                                   
  return (CS_OK);
}

/************************************************************************/
/* NAME       : INIT GFEC40G STATS                                      */
/* INPUTS     : Module Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Internal function to initialize the Stats.  This will                */
/* register the GFEC40G block and its stats control tables with         */
/* the stats engine.                                                    */
/************************************************************************/
cs_status ten_mod_init_gfec_40g_stats(cs_uint16 mod_id)
{
  ten_mod_stats_t *p_mod_stats;
  ten_mod_cb_t *pcb;
  cs_uint8 mod_num;

  /* Register Mapper Stats */
  if (!ten_stats_register_blk_cb(mod_id, TEN_MOD,
                TEN_ID_GFEC_40G, TRUE, NULL, NULL, NULL)) {
    return (CS_ERROR);
  }

  pcb = TEN_MOD_ID_TO_PCB_PTR(mod_id);
  if (!pcb) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  
  mod_num = TEN_MOD_ID_TO_MOD_NUM(mod_id);
 
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_GFEC_40G,
                                   "GFEC 40G Stats",
                                   0, mod_num, TEN_GFEC40G_STRIDE * sizeof(cs_reg), TRUE,
                                   TEN_GFEC40G_MAX_STAT,
                                   &(p_mod_stats->gfec_40g.stats[0]),
                                   stats_table_gfec40g) != CS_OK) {
    return (CS_ERROR);
  }
  return (CS_OK);
}

/************************************************************************/
/* NAME       : INIT GFEC10G STATS                                      */
/* INPUTS     : Module Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Internal function to initialize the Stats.  This will                */
/* register the GFEC10G block and its stats control tables with         */
/* the stats engine.                                                    */
/************************************************************************/
cs_status ten_mod_init_gfec_10g_stats(cs_uint16 mod_id)
{
  ten_mod_stats_t *p_mod_stats;
  ten_mod_cb_t *pcb;
  cs_uint8 mod_num;

  /* Register Mapper Stats */
  if (!ten_stats_register_blk_cb(mod_id, TEN_MOD,
                TEN_ID_GFEC_10G, TRUE, NULL, NULL, NULL)) {
    return (CS_ERROR);
  }

  pcb = TEN_MOD_ID_TO_PCB_PTR(mod_id);
  if (!pcb) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  mod_num = TEN_MOD_ID_TO_MOD_NUM(mod_id);
 
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_GFEC_10G,
                                   "GFEC 10G Instance 0 Stats",
                                   0, 0, 0, TRUE,
                                   TEN_GFEC10G_MAX_STAT,
                                   &(p_mod_stats->gfec_10g.stats[0][0]),
                                   stats_table_gfec10g_0) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_GFEC_10G,
                                   "GFEC 10G Instance 1 Stats",
                                   1, 0, 0, TRUE,
                                   TEN_GFEC10G_MAX_STAT,
                                   &(p_mod_stats->gfec_10g.stats[1][0]),
                                   stats_table_gfec10g_1) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_GFEC_10G,
                                   "GFEC 10G Instance 2 Stats",
                                   2, 0, 0, TRUE,
                                   TEN_GFEC10G_MAX_STAT,
                                   &(p_mod_stats->gfec_10g.stats[2][0]),
                                   stats_table_gfec10g_2) != CS_OK) {
    return (CS_ERROR);
  }                                
                                   
                                   
  return (CS_OK);
}

/************************************************************************/
/* NAME       : INIT UFEC STATS                                         */
/* INPUTS     : Module Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Internal function to initialize the Stats.  This will                */
/* register the UFEC block and its stats control tables with            */
/* the stats engine.                                                    */
/************************************************************************/
cs_status ten_mod_init_ufec_stats(cs_uint16 mod_id)
{
  ten_mod_stats_t *p_mod_stats;
  ten_mod_cb_t *pcb;
  cs_uint8 mod_num;

  /* Register Mapper Stats */
  if (!ten_stats_register_blk_cb(mod_id, TEN_MOD,
                TEN_ID_UFEC, TRUE, NULL, NULL, NULL)) {
    return (CS_ERROR);
  }

  pcb = TEN_MOD_ID_TO_PCB_PTR(mod_id);
  if (!pcb) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  
  mod_num = TEN_MOD_ID_TO_MOD_NUM(mod_id);
 
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_UFEC,
                                   "UFEC Instance 0 Stats",
                                   0, 0, 0, TRUE,
                                   TEN_UFEC_MAX_STAT,
                                   &(p_mod_stats->ufec.stats[0][0]),
                                   stats_table_ufec_0) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_UFEC,
                                   "UFEC Instance 1 Stats",
                                   1, 0, 0, TRUE,
                                   TEN_UFEC_MAX_STAT,
                                   &(p_mod_stats->ufec.stats[1][0]),
                                   stats_table_ufec_1) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_UFEC,
                                   "UFEC Instance 2 Stats",
                                   2, 0, 0, TRUE,
                                   TEN_UFEC_MAX_STAT,
                                   &(p_mod_stats->ufec.stats[2][0]),
                                   stats_table_ufec_2) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_UFEC,
                                   "UFEC Instance 3 Stats",
                                   3, 0, 0, TRUE,
                                   TEN_UFEC_MAX_STAT,
                                   &(p_mod_stats->ufec.stats[3][0]),
                                   stats_table_ufec_3) != CS_OK) {
    return (CS_ERROR);
  }                                
                                   
                                   
  return (CS_OK);
}

/************************************************************************/
/* NAME       : INIT N40G STATS                                         */
/* INPUTS     : Module Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Internal function to initialize the Stats.  This will                */
/* register the N40G block and its stats control tables with            */
/* the stats engine.                                                    */
/************************************************************************/
cs_status ten_mod_init_n40g_stats(cs_uint16 mod_id)
{
  ten_mod_stats_t *p_mod_stats;
  ten_mod_cb_t *pcb;
  cs_uint8 mod_num;

  /* Register Mapper Stats */
  if (!ten_stats_register_blk_cb(mod_id, TEN_MOD,
                TEN_ID_N40G, TRUE, NULL, NULL, NULL)) {
    return (CS_ERROR);
  }

  pcb = TEN_MOD_ID_TO_PCB_PTR(mod_id);
  if (!pcb) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  
  mod_num = TEN_MOD_ID_TO_MOD_NUM(mod_id);
 
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_N40G,
                                   "N40G Stats",
                                   0, mod_num, TEN_N40G_STRIDE * sizeof(cs_reg), TRUE,
                                   TEN_N40G_MAX_STAT,
                                   &(p_mod_stats->n40g.stats[0]),
                                   stats_table_n40g) != CS_OK) {
    return (CS_ERROR);
  }   
  return (CS_OK);
}

/************************************************************************/
/* NAME       : INIT N10G STATS                                         */
/* INPUTS     : Module Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Internal function to initialize the Stats.  This will                */
/* register the N10G block and its stats control tables with            */
/* the stats engine.                                                    */
/************************************************************************/
cs_status ten_mod_init_n10g_stats(cs_uint16 mod_id)
{
  ten_mod_stats_t *p_mod_stats;
  ten_mod_cb_t *pcb;
  cs_uint8 mod_num;

  /* Register Mapper Stats */
  if (!ten_stats_register_blk_cb(mod_id, TEN_MOD,
                TEN_ID_N10G, TRUE, NULL, NULL, NULL)) {
    return (CS_ERROR);
  }

  pcb = TEN_MOD_ID_TO_PCB_PTR(mod_id);
  if (!pcb) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  mod_num = TEN_MOD_ID_TO_MOD_NUM(mod_id);
 
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_N10G,
                                   "N10G Slice 0 Stats", 0, mod_num, 
                                   TEN_N10G_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_N10G_MAX_STAT,
                                   &(p_mod_stats->n10g.stats[0][0]),
                                   stats_table_n10g_0) != CS_OK) {
    return (CS_ERROR);
  }   

  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_N10G,
                                   "N10G Slice 1 Stats", 1, mod_num, 
                                   TEN_N10G_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_N10G_MAX_STAT,
                                   &(p_mod_stats->n10g.stats[1][0]),
                                   stats_table_n10g_1) != CS_OK) {
    return (CS_ERROR);
  }   
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_N10G,
                                   "N10G Slice 2 Stats", 2, mod_num, 
                                   TEN_N10G_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_N10G_MAX_STAT,
                                   &(p_mod_stats->n10g.stats[2][0]),
                                   stats_table_n10g_2) != CS_OK) {
    return (CS_ERROR);
  }                                    
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_N10G,
                                   "N10G Slice 3 Stats", 3, mod_num, 
                                   TEN_N10G_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_N10G_MAX_STAT,
                                   &(p_mod_stats->n10g.stats[3][0]),
                                   stats_table_n10g_3) != CS_OK) {
    return (CS_ERROR);
  }                                   

  return (CS_OK);  
}

/************************************************************************/
/* NAME       : INIT PP40G STATS                                         */
/* INPUTS     : Module Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Internal function to initialize the Stats.  This will                */
/* register the PP40G block and its stats control tables with            */
/* the stats engine.                                                    */
/************************************************************************/
cs_status ten_mod_init_pp40g_stats(cs_uint16 mod_id)
{
  ten_mod_stats_t *p_mod_stats;
  ten_mod_cb_t *pcb;
  cs_uint8 mod_num;

  /* Device must be T41. T40 does not have PP40G stats */
  if (!ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(mod_id)))
  {
    CS_HNDL_ERROR(mod_id, ETEN_DEV_CHIP_JTAG_ID_MISMATCH, "Device not CS604x, no PP40G.");
    return (CS_ERROR);			/* <<<<<<<<<<<<<<<<<< EARLY EXIT <<<<<<<<<<<<<<< */
  }

  /* Register Mapper Stats */
  if (!ten_stats_register_blk_cb(mod_id, TEN_MOD,
                TEN_ID_PP40G, TRUE, NULL, NULL, NULL)) {
    return (CS_ERROR);			/* <<<<<<<<<<<<<<<<<< EARLY EXIT <<<<<<<<<<<<<<< */
  }

  pcb = TEN_MOD_ID_TO_PCB_PTR(mod_id);
  if (!pcb) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);			/* <<<<<<<<<<<<<<<<<< EARLY EXIT <<<<<<<<<<<<<<< */
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);			/* <<<<<<<<<<<<<<<<<< EARLY EXIT <<<<<<<<<<<<<<< */
  }

  mod_num = TEN_MOD_ID_TO_MOD_NUM(mod_id);

  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_PP40G,
                                   "PP40G Stats",
                                   0, mod_num, TEN_PP40G_STRIDE * sizeof(cs_reg), TRUE,
                                   TEN_PP40G_MAX_STAT,
                                   &(p_mod_stats->pp40g.stats[0]),
                                   stats_table_pp40g) != CS_OK) {
    return (CS_ERROR);
  }
  return (CS_OK);
}

/* Bugzilla 26512, cfp stats moved to module stats in the hsif block */

/************************************************************************/
/* NAME       : INIT PP10G STATS                                        */
/* INPUTS     : Module Id                                               */
/* OUTPUTS    : ----                                                    */
/* RETURNS    : CS_OK or CS_ERROR                                       */
/* DESCRIPTION:                                                         */
/* Internal function to initialize the Stats.  This will                */
/* register the PP10G block and its stats control tables with           */
/* the stats engine.                                                    */
/************************************************************************/
cs_status ten_mod_init_pp10g_stats(cs_uint16 mod_id)
{
  ten_mod_stats_t *p_mod_stats;
  ten_mod_cb_t *pcb;
  cs_uint8 mod_num;

  /* Register Mapper Stats */
  if (!ten_stats_register_blk_cb(mod_id, TEN_MOD, TEN_ID_PP10G, TRUE, NULL, NULL, NULL)) {
    return (CS_ERROR);
  }

  pcb = TEN_MOD_ID_TO_PCB_PTR(mod_id);  /* @TODO: Does this return a port CB ptr? Looks like it wants a regular CB ptr. */
  if (!pcb) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  p_mod_stats = &pcb->stats;
  if (!p_mod_stats) {
    CS_HNDL_ERROR(mod_id, ETEN_MOD_NULL_PTR, "Null Pointer.");
    return (CS_ERROR);
  }
  
  mod_num = TEN_MOD_ID_TO_MOD_NUM(mod_id);
 
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_PP10G,
                                   "PP10G Slice 0 Stats",
                                   0, mod_num, TEN_PP10G_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_PP10G_MAX_STAT,
                                   &(p_mod_stats->pp10g.stats[0][0]),
                                   stats_table_pp10g_0) != CS_OK) {
    return (CS_ERROR);
  }
                                   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_PP10G,
                                   "PP10G Slice 1 Stats",
                                   1, mod_num, TEN_PP10G_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_PP10G_MAX_STAT,
                                   &(p_mod_stats->pp10g.stats[1][0]),
                                   stats_table_pp10g_1) != CS_OK) {
    return (CS_ERROR);
  }                               
   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_PP10G,
                                   "PP10G Slice 2 Stats",
                                   2, mod_num, TEN_PP10G_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_PP10G_MAX_STAT,
                                   &(p_mod_stats->pp10g.stats[2][0]),
                                   stats_table_pp10g_2) != CS_OK) {
    return (CS_ERROR);
  }                                      
   
  if (ten_stats_add_sect_tbl_entry(mod_id, TEN_MOD, TEN_ID_PP10G,
                                   "PP10G Slice 3 Stats",
                                   3, mod_num, TEN_PP10G_STRIDE * sizeof(cs_reg) * 4, TRUE,
                                   TEN_PP10G_MAX_STAT,
                                   &(p_mod_stats->pp10g.stats[3][0]),
                                   stats_table_pp10g_3) != CS_OK) {
    return (CS_ERROR);
  }                                      
                                   
  return (CS_OK);
}

