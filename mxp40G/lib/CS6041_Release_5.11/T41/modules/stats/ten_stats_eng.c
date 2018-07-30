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
 * ten_stats.c
 *
 * $Id: ten_stats_eng.c,v 1.14 2013/02/22 20:48:50 jccarlis Exp $
 *
 */

#include "tenabo40.h"

static cs_uint32 _ten_sect_print_flag = 0;

/*********************************************************************
 * Internal function declaration
 *********************************************************************/
static cs_boolean ten_stats_is_spl_hndlr_valid(const ten_stats_info_t *p_unit_info,
                                               ten_stats_op_type_t op);

static cs_status ten_stats_spl_handler(cs_uint16 dpid,
                                       ten_dev_or_mod_t dp,
                                       cs_uint16 blk_id,
                                       cs_uint16 sect_id,
                                       cs_uint16 unit_id,
                                       ten_stats_op_type_t op,
                                       cs_dir_t dir, cs_boolean sect_context);

static cs_status ten_stats_update_unit_data(cs_uint16 dpid,
                                            ten_dev_or_mod_t dp,
                                            cs_uint16 blk_id,
                                            cs_uint16 stride_id,
                                            cs_uint32 stride_size,
                                            const ten_stats_info_t *p_unit_info,
                                            ten_stats_data_t *p_unit_data,
                                         /*   ten_stats_work_area_t *p_work_area, */
                                            cs_dir_t dir);

static cs_status ten_stats_clear_unit_data(cs_uint16 dpid,
                                           ten_dev_or_mod_t dp,
                                           cs_uint16 blk_id,
                                           cs_uint16 stride_id,
                                           cs_uint32 stride_size,
                                           const ten_stats_info_t *p_unit_info,
                                           ten_stats_data_t *p_unit_data,
                                        /*   ten_stats_work_area_t *p_work_area, */
                                           cs_dir_t dir);

static void ten_stats_print_unit_cntr_in_hex(const cs_char8 *name, cs_uint32 flags,
                                             cs_uint32 rx_ms, cs_uint32 rx_ls,
                                             cs_uint32 tx_ms, cs_uint32 tx_ls);

static void ten_stats_print_unit_cntr_in_dec(const cs_char8 *name, cs_uint32 flags,
                                             cs_uint32 rx_ms, cs_uint32 rx_ls,
                                             cs_uint32 tx_ms, cs_uint32 tx_ls);

static cs_status ten_stats_set_blk_cb(cs_uint16 dpid,
                                      ten_dev_or_mod_t dp,
                                      cs_uint16 blk_id,
                                      ten_stats_blk_cb_t *blk_cb);
                                      
cs_status ten_ppxx_pm_read_counter(cs_uint16 module_id, cs_uint16 blk_id, 
                                   cs_uint8 slice, cs_uint32 cntr_id, 
                                   cs_uint32 *counter_ms, cs_uint32 *counter_ls)
{
    if (blk_id==TEN_ID_PP10G) {
    	return ten_pp10g_pm_read_counter(module_id, slice, cntr_id,
    																 	counter_ms, counter_ls);
    }
    else {
    	return ten_pp40g_pm_read_counter(module_id, cntr_id, 
                                       counter_ms, counter_ls);
    }
}
                                      
/*********************************************************************
 * Public APIs definitions
 *********************************************************************/
 
/*********************************************************************/
/*                    REGISTER STATS BLOCK CB                        */
/* CATEGORY   : API                                                  */
/* ACCESS     : Public                                               */
/* BLOCK      : STATS                                                */
/* CHIP       : Tenabo                                               */
ten_stats_blk_cb_t *ten_stats_register_blk_cb(cs_uint16 dpid,
                                              ten_dev_or_mod_t dp,
                                              cs_uint16 blk_id,
                                              cs_boolean ctl_enabled,
                                              ten_stats_get_func pGet_func,
                                              ten_stats_print_func pPrint_func,
                                              ten_stats_clear_func pClear_func)
/* INPUTS     : o Device or Module Id                                */
/*              o TEN_DEVICE or TEN_MOD                              */
/*              o Block Id                                           */
/*              o TRUE ( Stats Enabled ) or FALSE                    */
/*              o Pointer to special handler for GET                 */
/*              o Pointer to special handler for PRINT               */
/*              o Pointer to special handler for CLEAR               */
/* OUTPUTS    : ----                                                 */
/* RETURNS    : CS_OK or CS_ERROR                                    */
/* DESCRIPTION:                                                      */
/* Register the Block CB. This is an internal API to be invoked by   */
/* individual modules to register their block CB.                    */
/* This API will do the allocation of memory for the block CB and    */
/* if sanity checks pass, returns the pointer to ten_stats_blk_cb_t  */
/* back to the called. The individual blocks can the go on adding    */
/* their sections to the block_cb.                                   */
/*                                                                   */
/*********************************************************************/
{
  cs_uint16 ii;
  ten_stats_blk_cb_t *stats_blk_cb;

  stats_blk_cb = ten_stats_get_blk_cb(dpid, dp, blk_id);

  /* If block CB is NULL, Allocate it */
  if (stats_blk_cb == NULL) {
    /* Allocate memory for STATS block CB */
    stats_blk_cb = (ten_stats_blk_cb_t *) CS_MALLOC(sizeof(ten_stats_blk_cb_t));
    if (stats_blk_cb == NULL) {
      cs_uint32 err_code = ((dp == TEN_DEVICE) ?
                            ETEN_DEV_MALLOC_FAILED : ETEN_MOD_MALLOC_FAILED);
      CS_HNDL_ERROR(dpid, err_code, NULL);
      return (NULL);
    }

    /* Clear out the pointer table to STATS section CB */
    for (ii = 0; ii < TEN_STATS_MAX_SECT; ii++) {
      stats_blk_cb->p_sect_cb[ii] = NULL;
    }
  }

  stats_blk_cb->blk_name = ten_get_block_name(blk_id);
  stats_blk_cb->enabled = ctl_enabled;
  stats_blk_cb->num_sect = 0;
  stats_blk_cb->get_func = pGet_func;
  stats_blk_cb->print_func = pPrint_func;
  stats_blk_cb->clear_func = pClear_func;
  ten_stats_set_blk_cb(dpid, dp, blk_id, stats_blk_cb);
  return (stats_blk_cb);
}

/*********************************************************************/
/*                 UNREGISTER STATS BLOCK CB                         */
/* CATEGORY   : API                                                  */
/* ACCESS     : Public                                               */
/* BLOCK      : STATS                                                */
/* CHIP       : Tenabo                                               */
cs_status ten_stats_deregister_blk_cb(cs_uint16 dpid,
                                      ten_dev_or_mod_t dp, cs_uint16 blk_id)
/* INPUTS     : o Device or Module Id                                */
/*              o TEN_DEVICE or TEN_MOD                              */
/*              o Module ID                                          */
/* OUTPUTS    : ----                                                 */
/* RETURNS    : CS_OK or CS_ERROR                                    */
/* DESCRIPTION:                                                      */
/* Unregister the Block CB. This is an internal API to be invoked    */
/* to deregister the block CB. This API shall free any memory        */
/* allocated for the block CB and section CBs. This should be called */
/* ideally everytime before the Port init to clean up any resources  */
/* allocated from last time.                                         */
/*                                                                   */
/*********************************************************************/
{
  cs_uint16 ii;
  ten_stats_blk_cb_t *stats_blk_cb;

  stats_blk_cb = ten_stats_get_blk_cb(dpid, dp, blk_id);
  if (stats_blk_cb == NULL) {
    return (CS_OK);             /* this stats blk not registered */
  }

  for (ii = 0; ii < TEN_STATS_MAX_SECT; ii++) {
    ten_stats_remove_sect_tbl_entry(dpid, dp, blk_id, ii);
  }

  CS_FREE(stats_blk_cb);
  ten_stats_set_blk_cb(dpid, dp, blk_id, NULL);

  return (CS_OK);
}

/*********************************************************************/
/*                 CLEAN STATS BLOCK CB                              */
/* CATEGORY   : API                                                  */
/* ACCESS     : Public                                               */
/* BLOCK      : STATS                                                */
/* CHIP       : Tenabo                                               */
cs_status ten_stats_clean_all(cs_uint16 dpid, ten_dev_or_mod_t dp)
/* INPUTS     : o Device or Module Id                                */
/*              o TEN_DEVICE or TEN_MOD                             */
/* OUTPUTS    : ----                                                 */
/* RETURNS    : CS_OK or CS_ERROR                                    */
/* DESCRIPTION:                                                      */
/* Unregister the All Block CB. This is an internal API to be invoked*/
/* to deregister the block CB. This API shall free any memory        */
/* allocated for the block CB and section CBs. This should be called */
/* ideally everytime before the Port init to clean up any resources  */
/* allocated from last time.                                         */
/*                                                                   */
/*********************************************************************/
{
  if (dp == TEN_DEVICE) {
    ten_stats_deregister_blk_cb(dpid, dp, TEN_ID_XCON);
   /* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
  }
  else {                        /* TEN_MOD */
    ten_stats_deregister_blk_cb(dpid, dp, TEN_ID_SYNCDSYNC);
    ten_stats_deregister_blk_cb(dpid, dp, TEN_ID_HSIF);
    ten_stats_deregister_blk_cb(dpid, dp, TEN_ID_GFEC_40G);
    ten_stats_deregister_blk_cb(dpid, dp, TEN_ID_GFEC_10G);
    ten_stats_deregister_blk_cb(dpid, dp, TEN_ID_UFEC);
    ten_stats_deregister_blk_cb(dpid, dp, TEN_ID_N40G);
    ten_stats_deregister_blk_cb(dpid, dp, TEN_ID_N10G);
    ten_stats_deregister_blk_cb(dpid, dp, TEN_ID_PP10G);

    /* T40 doesn't have PP40G or CFP32x1 SDS block */
    if (ten_dev_is_t41(TEN_MOD_ID_TO_DEV_ID(dpid))) {
      ten_stats_deregister_blk_cb(dpid, dp, TEN_ID_PP40G);
    }
  }
  return (CS_OK);
}

/**********************************************************************/
/*                 ADD SECTION CB TO BLOCK CB                        */
/* CATEGORY   : API                                                  */
/* ACCESS     : Public                                               */
/* BLOCK      : STATS                                                */
/* CHIP       : Tenabo                                               */
cs_status ten_stats_add_sect_tbl_entry(cs_uint16 dpid,
                                       ten_dev_or_mod_t dp,
                                       cs_uint16 blk_id,
                                       cs_char8 *sect_name,
                                       cs_uint16 sect_id,
                                       cs_uint8 stride_id,
                                       cs_uint32 stride_size,
                                       cs_boolean ctl_enabled,
                                       cs_uint16 num_child,
                                       ten_stats_data_t *p_data,
                                       const ten_stats_info_t *p_info_tbl)
/* INPUTS     : o Device or Module Id                                */
/*              o TEN_DEVICE or TEN_MOD                              */
/*              o Section Name                                       */
/*              o Section ID                                         */
/*              o Section Size                                       */
/*              o Number of counter blocks in this section           */
/*              o Pointer to Section stats data structure            */
/*              o Pointer to the Section Info Table                  */
/* OUTPUTS    : ----                                                 */
/* RETURNS    : CS_OK or CS_ERROR                                    */
/* DESCRIPTION:                                                      */
/* Add Section CB to block CB. Individual modules must call this API */
/* to register their Section tables. Section ID identifies the       */
/* section stats.                                                    */
/* The [sect_id] is the section ID of the section stats. Each Module */
/* should register their section stats by calling this API for each  */
/* section they wish to register.                                    */
/* The [stride_id] identifies the stride.                            */
/* The [stride_size] is the stride size that used to determine where */
/* the next stride is                                                */
/* The [ctl_enabled] is to enbl/disable statistics gathering/printing*/
/* for this section table. If [ctl_enabled] is FALSE, stats are not  */
/* accumulated for this section.                                     */
/* The [num_child] is the number of STAT unit data entries in this   */
/* section.                                                          */
/* The [p_data] is pointer to user allocated data structure where the*/
/* statistics will be accumulated.                                   */
/* The [p_info_tbl] is pointer to section info table. This table     */
/* should be an array of stats unit info entries and contain info    */
/* about the register offset , flags which dictate how the registers */
/* will be read/cleared and other info like if special handling is   */
/* required to get the stats for this unit.                          */
/*                                                                   */
/*********************************************************************/
{
  cs_uint16 ii;
  cs_uint32 err_code = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;
 /* cs_boolean need_work_area = FALSE; */

  stats_blk_cb = ten_stats_get_blk_cb(dpid, dp, blk_id);

  if ((stats_blk_cb == NULL) || (sect_id >= TEN_STATS_MAX_SECT)) {
    err_code = ((dp == TEN_DEVICE) ? ETEN_DEV_TBL_NULL : ETEN_MOD_TBL_NULL);
    CS_HNDL_ERROR(dpid, err_code, NULL);
    return (CS_ERROR);
  }

  /*
   * Get the Pointer to Section CB entry.
   * If it is NULL, allocate a new entry.
   */
  stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id];
  if (stats_sect_cb == NULL) {
    if ((stats_sect_cb = (ten_stats_sect_cb_t *)
         CS_MALLOC(sizeof(ten_stats_sect_cb_t))) == NULL) {
      err_code = ((dp == TEN_DEVICE) ? ETEN_DEV_MALLOC_FAILED : ETEN_MOD_MALLOC_FAILED);
      CS_HNDL_ERROR(dpid, err_code, NULL);
      goto RTN_CLEANUP;
    }

    if ((stats_sect_cb->enbl_tbl = (cs_boolean *)
         CS_MALLOC(num_child * sizeof(cs_boolean))) == NULL) {
      err_code = ((dp == TEN_DEVICE) ? ETEN_DEV_MALLOC_FAILED : ETEN_MOD_MALLOC_FAILED);
      CS_HNDL_ERROR(dpid, err_code, NULL);
      goto RTN_CLEANUP;
    }

    #if 0 /* not needed for T40 */
    /* determine we need scratch or not */
    for (ii = 0; ii < num_child; ii++) {
      /* add checking conditions here   */
      if (p_info_tbl[ii].flags & TEN_STATS_FLAG_NO_CLR_TX_RX) {
        need_work_area = TRUE;
        break;
      }
    }

    if (need_work_area) {
      if ((stats_sect_cb->work_area_tbl = (ten_stats_work_area_t *)
           CS_MALLOC(num_child * sizeof(ten_stats_work_area_t))) == NULL) {
        err_code = ((dp == TEN_DEVICE) ? ETEN_DEV_MALLOC_FAILED :
                    ETEN_MOD_MALLOC_FAILED);
        CS_HNDL_ERROR(dpid, err_code, NULL);
        goto RTN_CLEANUP;
      }
    }
    else {
      stats_sect_cb->work_area_tbl = NULL;
    }
    #endif

    stats_blk_cb->p_sect_cb[sect_id] = stats_sect_cb;
    for (ii = 0; ii < num_child; ii++) {
      /* enable all by default */
      *(stats_sect_cb->enbl_tbl + ii) = TRUE;

      #if 0 /* not needed for T40 */
      if (need_work_area) {
        stats_sect_cb->work_area_tbl[ii].prev_data.rx_ms = 0;
        stats_sect_cb->work_area_tbl[ii].prev_data.rx_ls = 0;
        stats_sect_cb->work_area_tbl[ii].prev_data.tx_ms = 0;
        stats_sect_cb->work_area_tbl[ii].prev_data.tx_ls = 0;
      }
      #endif
    }
  }

  stats_sect_cb->sect_name = sect_name;
  stats_sect_cb->enabled = ctl_enabled;
  stats_sect_cb->stride_id = stride_id;
  stats_sect_cb->stride_size = stride_size;
  stats_sect_cb->num_entries = num_child;
  stats_sect_cb->pStats = p_data;
  stats_sect_cb->info_tbl = p_info_tbl;
  stats_blk_cb->num_sect++;
  return (CS_OK);

RTN_CLEANUP:
  if (stats_sect_cb) {
    if (stats_sect_cb->enbl_tbl) {
      CS_FREE(stats_sect_cb->enbl_tbl);
    }
    #if 0 /* not needed for T40 */
    if (stats_sect_cb->work_area_tbl) {
      CS_FREE(stats_sect_cb->work_area_tbl);
    }
    #endif
    CS_FREE(stats_sect_cb);
  }
  return (CS_ERROR);
}

/*********************************************************************/
/*                 REMOVE SECTION CB FROM BLOCK CB                   */
/* CATEGORY   : API                                                  */
/* ACCESS     : Public                                               */
/* BLOCK      : STATS                                                */
/* CHIP       : Tenabo                                               */
cs_status ten_stats_remove_sect_tbl_entry(cs_uint16 dpid, ten_dev_or_mod_t dp,
                                          cs_uint16 blk_id, cs_uint16 sect_id)
/* INPUTS     : o Device or Module Id                                */
/*              o TEN_DEVICE or TEN_MOD                             */
/*              o Module ID                                          */
/*              o Section ID                                         */
/* OUTPUTS    : ----                                                 */
/* RETURNS    : CS_OK or CS_ERROR                                    */
/* DESCRIPTION:                                                      */
/* Removes the section table from the stats block CB and frees up    */
/* any memory allocated for the section CB.                          */
/*                                                                   */
/*********************************************************************/
{
  cs_uint32 err_code = 0;
  ten_stats_sect_cb_t *stats_sect_cb = NULL;
  ten_stats_blk_cb_t *stats_blk_cb;

  stats_blk_cb = ten_stats_get_blk_cb(dpid, dp, blk_id);

  if ((stats_blk_cb == NULL) || (sect_id >= TEN_STATS_MAX_SECT)) {
    err_code = ((dp == TEN_DEVICE) ? ETEN_DEV_TBL_NULL : ETEN_MOD_TBL_NULL);
    CS_HNDL_ERROR(dpid, err_code, NULL);
    return (CS_ERROR);
  }

  stats_sect_cb = stats_blk_cb->p_sect_cb[sect_id];
  if (stats_sect_cb) {
    CS_FREE(stats_sect_cb->enbl_tbl);
    #if 0 /* not needed for T40 */
    if (stats_sect_cb->work_area_tbl != NULL) {
      CS_FREE(stats_sect_cb->work_area_tbl);
    }
    #endif
    CS_FREE(stats_sect_cb);
    stats_blk_cb->p_sect_cb[sect_id] = NULL;
    stats_blk_cb->num_sect--;
  }
  return (CS_OK);
}

/*********************************************************************
 * Internal function to read the hardware counter
 *********************************************************************/
void ten_stats_get_hw_cntr(volatile cs_reg *reg_tbl, cs_uint16 num_regs, 
                           cs_uint16 lsb_first, cs_uint32 *cnt_val_ms,
                           cs_uint32 *cnt_val_ls)
{
  cs_uint16 ii;
  cs_uint16 counter[4];
  cs_uint16 reg_val = 0;
  cs_int16 kk;
  
  /* support max of 64 bit counters */      
  if ((!reg_tbl) || (!num_regs) || (num_regs > 4))
  {
    *cnt_val_ms = 0;
    *cnt_val_ls = 0;
    return;
  }
  for (ii=0; ii<4; ii++) {
    counter[ii] = 0;
  }

  /* The order of read is from MSB to LSB */
  for (ii=0; ii<num_regs; ii++) {
    kk = num_regs - ii - 1;   
    /* if LSB is first in the register map, then still read MSB first */
    if (lsb_first) {
      if ((kk >= 0) && (kk < 4)) {
        reg_val = TEN_REG_READ(&reg_tbl[kk]);
      }
    }
    else {
      reg_val = TEN_REG_READ(&reg_tbl[ii]);
    } 
    if ((kk >= 0) && (kk < 4)) {
      counter[kk] = reg_val;
    }
  }
  *cnt_val_ms = (((cs_uint32)counter[3]) << 16) | counter[2];
  *cnt_val_ls = (((cs_uint32)counter[1]) << 16) | counter[0]; 
}

/********************************************************************
 * Internal function to clear the hardware counter
 ********************************************************************/
void ten_stats_clear_hw_cntr(volatile cs_reg *reg_tbl,
                             cs_uint16 num_regs, cs_boolean read_clear,
                             cs_uint16 lsb_first)
{
  cs_uint16 cntr = 0, ii, kk;

  if (!reg_tbl) {
    return;
  }
  /* The order of read is from MSB to LSB */
  if (read_clear) {
    for (ii = 0; ii < num_regs; ii++) {
      kk = num_regs - ii - 1;   
    
      if (lsb_first) {
        /* if LSB is first in the register map, then still read MSB first */
        cntr = TEN_REG_READ(&reg_tbl[kk]);
      }
      else {
        cntr = TEN_REG_READ(&reg_tbl[ii]);
      }  
    }
  }
  else {                        /* write to clear */
    /* The order of write is from LSB to MSB (reverse of read order) */
    for (ii = 0; ii < num_regs; ii++) {
      kk = num_regs - ii - 1;   
      if (lsb_first) {
        /* if LSB is first in the register map, write in this order */
        TEN_REG_WRITE(&reg_tbl[ii], 0);
      }
      else {
        TEN_REG_WRITE(&reg_tbl[kk], 0);
      }
    }
  }
}

/********************************************************************
 * This function is STATS internal function. This function gets the
 * hardware counters for the STATS unit data ( RX and TX ) counters.
 ********************************************************************/
static
cs_status ten_stats_update_unit_data(cs_uint16 dpid,
                                     ten_dev_or_mod_t dp,
                                     cs_uint16 blk_id,
                                     cs_uint16 stride_id,
                                     cs_uint32 stride_size,
                                     const ten_stats_info_t * p_unit_info,
                                     ten_stats_data_t * p_unit_data,
                                    /* ten_stats_work_area_t *p_work_area,*/ cs_dir_t dir)
{
  T41_t *pDev = 0;
  cs_uint32 counter_val_ms = 0;
  cs_uint32 counter_val_ls = 0;
  cs_uint32 tmp_ls;
  volatile cs_reg *regaddr = NULL;

  if (dp == TEN_DEVICE) {
    TEN_DEV_COMMON_VALIDATE(dpid, pDev, CS_ERROR);
  }
  else {                        /* TEN_MOD */
    TEN_MOD_COMMON_VALIDATE(dpid, pDev, CS_ERROR);
  }

  /* If Rx is valid, read the Rx hw counter and increment */
  if ((TEN_STATS_UNIT_IS_RX_VALID(p_unit_info->flags)) &&
      ((dir == CS_RX) || (dir == CS_RX_AND_TX))) {
      regaddr = (volatile cs_reg *)
      TEN_STATS_GET_RX_REG_ADDR(pDev, stride_id, stride_size, p_unit_info);
      
    if (p_unit_info->flags & TEN_STATS_FLAG_PROTECT_RX) {
      if (dp == TEN_DEVICE) {
        TEN_DEV_LOCK(dpid, blk_id);
      }
      else {
        TEN_MOD_LOCK(dpid, blk_id);
      }
    }

    if (p_unit_info->flags & TEN_STATS_FLAG_INDIRECT) {
       /* These pms are read through an access register. Currently applies to PP10G and PP40G */
       ten_ppxx_pm_read_counter(dpid, blk_id, p_unit_info->slice, p_unit_info->rx_reg_ofst, 
                                 &counter_val_ms, &counter_val_ls);
    }
    else {
      ten_stats_get_hw_cntr(regaddr, p_unit_info->num_regs, 
                  p_unit_info->flags & TEN_STATS_FLAG_LSB_FIRST, 
                  &counter_val_ms, &counter_val_ls);
    }          

    if (p_unit_info->flags & TEN_STATS_FLAG_PROTECT_RX) {
      if (dp == TEN_DEVICE) {
        TEN_DEV_UNLOCK(dpid, blk_id);
      }
      else {
        TEN_MOD_UNLOCK(dpid, blk_id);
      }
    }

    /* Bugzilla #21565, flag needs to be RX here */
    if ( (p_unit_info->flags & TEN_STATS_FLAG_RX_READ_CLR) ||
              ((p_unit_info->flags & TEN_STATS_FLAG_TIMING_INTERVAL) && 
              (g_pTEN->drvr_flag & TEN_DRVR_STATS_TIMING_INTERVAL)) ) {
      tmp_ls = p_unit_data->rx_ls + counter_val_ls;
      if ((tmp_ls < p_unit_data->rx_ls) || (tmp_ls < counter_val_ls)) {
        /* carry 1 */
        p_unit_data->rx_ms += 1;
      } 
      p_unit_data->rx_ms += counter_val_ms;
      p_unit_data->rx_ls = tmp_ls;
    } 
    else if (p_unit_info->flags & TEN_STATS_FLAG_NO_ACCUM) {
      p_unit_data->rx_ms = counter_val_ms;
      p_unit_data->rx_ls = counter_val_ls;
    }
    else {  /* non clear-on-read => ie, framer cntrs, etc. */
      p_unit_data->rx_ms = counter_val_ms;
      p_unit_data->rx_ls = counter_val_ls;
    }
    #if 0 /* not used in T40 */
    else if (p_unit_info->flags & TEN_STATS_FLAG_NO_CLR_RX) {
      cs_uint16 shift = 64 - (p_unit_info->num_regs * 16);
      if (p_work_area) {
        tmp = counter_val - p_work_area->prev_data.rx;
        p_unit_data->rx += (tmp << shift) >> shift;
        p_work_area->prev_data.rx = counter_val;
      }
      else {
        return (CS_ERROR);
      }
    }
    #endif
  }

  if ((TEN_STATS_UNIT_IS_TX_VALID(p_unit_info->flags)) &&
      ((dir == CS_TX) || (dir == CS_RX_AND_TX))) {
    regaddr = (volatile cs_reg *)
      TEN_STATS_GET_TX_REG_ADDR(pDev, stride_id, stride_size, p_unit_info);

    if (p_unit_info->flags & TEN_STATS_FLAG_PROTECT_TX) {
      if (dp == TEN_DEVICE) {
        TEN_DEV_LOCK(dpid, blk_id);
      }
      else {
        TEN_MOD_LOCK(dpid, blk_id);
      }
    }
    
    if (p_unit_info->flags & TEN_STATS_FLAG_INDIRECT) {
      ten_ppxx_pm_read_counter(dpid, blk_id, p_unit_info->slice, p_unit_info->tx_reg_ofst,
                                               &counter_val_ms, &counter_val_ls);
    }
    else {
      ten_stats_get_hw_cntr(regaddr, p_unit_info->num_regs,
                  p_unit_info->flags & TEN_STATS_FLAG_LSB_FIRST, 
                  &counter_val_ms, &counter_val_ls);
    }

    if (p_unit_info->flags & TEN_STATS_FLAG_PROTECT_TX) {
      if (dp == TEN_DEVICE) {
        TEN_DEV_UNLOCK(dpid, blk_id);
      }
      else {
        TEN_MOD_UNLOCK(dpid, blk_id);
      }
    }

    if ( (p_unit_info->flags & TEN_STATS_FLAG_TX_READ_CLR) ||
              ((p_unit_info->flags & TEN_STATS_FLAG_TIMING_INTERVAL) && 
              (g_pTEN->drvr_flag & TEN_DRVR_STATS_TIMING_INTERVAL)) ) {
      /* Bugzilla #21565, variable needs to be TX here */
      tmp_ls = p_unit_data->tx_ls + counter_val_ls;
      if ((tmp_ls < p_unit_data->tx_ls) || (tmp_ls < counter_val_ls)) {
        /* carry 1 */
        p_unit_data->tx_ms += 1;
      } 
      p_unit_data->tx_ms += counter_val_ms;
      p_unit_data->tx_ls = tmp_ls;
    }
    else if (p_unit_info->flags & TEN_STATS_FLAG_NO_ACCUM) {
      /* mirror what's in the counter register. */
      p_unit_data->tx_ms = counter_val_ms;
      p_unit_data->tx_ls = counter_val_ls;
    }
    else {  /* non clear-on-read => ie, framer cntrs, etc. */
      p_unit_data->tx_ms = counter_val_ms;
      p_unit_data->tx_ls = counter_val_ls;
    }
    #if 0 /* not used in T40 */
    else if (p_unit_info->flags & TEN_STATS_FLAG_NO_CLR_TX) {
      cs_uint16 shift = 64 - (p_unit_info->num_regs * 16);
      if (p_work_area) {
        tmp = counter_val - p_work_area->prev_data.tx;
        p_unit_data->tx += (tmp << shift) >> shift;
        p_work_area->prev_data.tx = counter_val;
      }
      else {
        return (CS_ERROR);
      }
    }
    #endif
  }
  return (CS_OK);
}

/*********************************************************************
 * This function is STATS internal function. This function clears the
 * hardware counters for the STATS unit data ( RX and TX ) counters.
 *********************************************************************/
static cs_status ten_stats_clear_unit_data(cs_uint16 dpid,
                                           ten_dev_or_mod_t dp,
                                           cs_uint16 blk_id,
                                           cs_uint16 stride_id,
                                           cs_uint32 stride_size,
                                           const ten_stats_info_t * p_unit_info,
                                           ten_stats_data_t * p_unit_data,
                                      /*     ten_stats_work_area_t * p_work_area, */
                                           cs_dir_t dir)
{
  T41_t *pDev = 0;
  volatile cs_reg *regaddr;
  cs_boolean read_clr = FALSE;

  /* Suspend logging information during stats clear */
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND; /* don't show reg reads */

  if (dp == TEN_DEVICE) {
    if (TEN_DEV_COMMON_VALIDATE_INTERNAL(dpid, &pDev) == CS_ERROR) {
      g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
      return (CS_ERROR);
    }
  }
  else {                        /* TEN_MOD */
    if (TEN_MOD_COMMON_VALIDATE_INTERNAL(dpid, &pDev) == CS_ERROR) {
      g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
      return (CS_ERROR);
    }      
  }
  
  /* If Rx is valid, read the RX hw counter and increment */
  if ((TEN_STATS_UNIT_IS_RX_VALID(p_unit_info->flags)) &&
      ((dir == CS_RX) || (dir == CS_RX_AND_TX))) {
    regaddr = (volatile cs_reg *)
      TEN_STATS_GET_RX_REG_ADDR(pDev, stride_id, stride_size, p_unit_info);

    if (p_unit_info->flags & TEN_STATS_FLAG_NO_CLR_RX) {
      /* just to make sure prev_data is up to date at time of clear */
      /* since this is an offset to actual count                    */
      ten_stats_update_unit_data(dpid, dp, blk_id, stride_id, stride_size,
                                 p_unit_info, p_unit_data, /* p_work_area,*/ CS_RX);
    }
    else {
      if (p_unit_info->flags & TEN_STATS_FLAG_INDIRECT) {
        /* cannot clear an individual PP10G counter, */
        /* only a block level clear is possible.     */
        g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
        /* Bugzilla #30772, allow pp10g software shadow to clear */
    }
    else {
      read_clr = ((p_unit_info->flags & TEN_STATS_FLAG_RX_READ_CLR) ? TRUE : FALSE);
      ten_stats_clear_hw_cntr(regaddr, p_unit_info->num_regs, read_clr, 
                              p_unit_info->flags & TEN_STATS_FLAG_LSB_FIRST);
      }                        
    }
    p_unit_data->rx_ms = 0;
    p_unit_data->rx_ls = 0;
  }

  if (TEN_STATS_UNIT_IS_TX_VALID(p_unit_info->flags) &&
      ((dir == CS_TX) || (dir == CS_RX_AND_TX))) {
    regaddr = (volatile cs_reg *)
      TEN_STATS_GET_TX_REG_ADDR(pDev, stride_id, stride_size, p_unit_info);

    if (p_unit_info->flags & TEN_STATS_FLAG_NO_CLR_TX) {
      ten_stats_update_unit_data(dpid, dp, blk_id, stride_id, stride_size,
                                 p_unit_info, p_unit_data, /* p_work_area,*/ CS_TX);
    }
    else {
      if (p_unit_info->flags & TEN_STATS_FLAG_INDIRECT) {
        /* cannot clear an individual PP10G counter, */
        /* only a block level clear is possible.     */
        g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
        /* Bugzilla #30772, allow pp10g software shadow to clear */
    }
    else {
      read_clr = ((p_unit_info->flags & TEN_STATS_FLAG_TX_READ_CLR) ? TRUE : FALSE);
      ten_stats_clear_hw_cntr(regaddr, p_unit_info->num_regs, read_clr,
                              p_unit_info->flags & TEN_STATS_FLAG_LSB_FIRST);
      }
    }
    p_unit_data->tx_ms = 0;
    p_unit_data->tx_ls = 0;
  }
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

  return (CS_OK);
}

/*********************************************************************
 * This function performs get/print and clear operation on the stats
 * data unit.
 *********************************************************************/
cs_status ten_stats_unit_cmn_op(cs_uint16 dpid,
                                ten_dev_or_mod_t dp,
                                cs_uint16 blk_id,
                                cs_uint16 sect_id,
                                cs_uint16 unit_id,
                                ten_stats_sect_cb_t * sect_cb,
                                ten_stats_op_type_t op,
                                cs_dir_t dir, cs_boolean sect_context)
{
  const ten_stats_info_t *p_unit_info;
  ten_stats_data_t *p_unit_data;
 /* ten_stats_work_area_t *p_work_area = NULL; */
  #if 0
  CS_PRINT("ten_stats_unit_cmn_op:  blk_id=%d, sect_id=%d, unit_id=%d\n", 
            blk_id, sect_id, unit_id); 
  #endif
 
  if (unit_id >= sect_cb->num_entries) {
    CS_PRINT_OUTPUT("ERROR: unit_id(%d) > num_entries(%d)\n",
             unit_id, sect_cb->num_entries);
    return (CS_ERROR);
  }

  /* If Stats is disabled for this unit, return, don't do anything */
  if ((*(sect_cb->enbl_tbl + unit_id)) == FALSE)
    return (CS_ERROR);

  p_unit_info = sect_cb->info_tbl + unit_id;

  /* Handle special case if special handling flags are set */
  if (ten_stats_is_spl_hndlr_valid(p_unit_info, op)) {
    return ten_stats_spl_handler(dpid, dp, blk_id, sect_id,   /* <<<<<<<<<<<<< Early Exit <<<<<<<<<<<<< */
                                 unit_id, op, dir, sect_context);
  }
  
  /* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
  /* Skip if this stat does not apply to this module */
  if (dp == TEN_MOD) {
    if (  ( (p_unit_info->flags & TEN_STATS_MODULE_A_ONLY) && (dpid !=0) )
        ||( (p_unit_info->flags & TEN_STATS_MODULE_B_ONLY) && (dpid !=1) ) ) {
      return (CS_OK);                                         /* <<<<<<<<<<<<< Early Exit <<<<<<<<<<<<< */
    }
  }

  p_unit_data = sect_cb->pStats + unit_id;
  #if 0 /* not needed in T40 */
  if (sect_cb->work_area_tbl != NULL) {
    p_work_area = &sect_cb->work_area_tbl[unit_id];
  }
  #endif

  switch (op) {
  case TEN_STATS_PRINT:

    #if 0 /* not used in T40 */
    if (TEN_STATS_UNIT_IS_TIE_VALID(p_unit_info->flags)) {
      if (ten_get_sect_print_flag() == 1) {
      
        if (TEN_STATS_UNIT_IS_NEXT_TIE(p_unit_info->flags)) {
          /* update RX pkts & bytes first */
          if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area,*/ CS_RX);
            p_unit_info = sect_cb->info_tbl + unit_id + 1;
            p_unit_data = sect_cb->pStats + unit_id + 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
          }
          /* update TX pkts & bytes secondly */
          if ((dir == CS_TX) || (dir == CS_RX_AND_TX)) {
          
            p_unit_info = sect_cb->info_tbl + unit_id;
            p_unit_data = sect_cb->pStats + unit_id;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
            p_unit_info = sect_cb->info_tbl + unit_id + 1;
            p_unit_data = sect_cb->pStats + unit_id + 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
          }
        }
      }
      else {
        if (TEN_STATS_UNIT_IS_NEXT_TIE(p_unit_info->flags)) {
          /* update RX pkts & bytes first */
          if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area,*/ CS_RX);
            p_unit_info = sect_cb->info_tbl + unit_id + 1;
            p_unit_data = sect_cb->pStats + unit_id + 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area,*/ CS_RX);
          }
          /* update TX pkts & bytes secondly */
          if ((dir == CS_TX) || (dir == CS_RX_AND_TX)) {
            p_unit_info = sect_cb->info_tbl + unit_id;
            p_unit_data = sect_cb->pStats + unit_id;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data,/* p_work_area, */ CS_TX);
            p_unit_info = sect_cb->info_tbl + unit_id + 1;
            p_unit_data = sect_cb->pStats + unit_id + 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
          }
        }
        else {
          /* update RX pkts & bytes first */
          if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
            p_unit_info = sect_cb->info_tbl + unit_id - 1;
            p_unit_data = sect_cb->pStats + unit_id - 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
            p_unit_info = sect_cb->info_tbl + unit_id;
            p_unit_data = sect_cb->pStats + unit_id;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
          }
          /* update TX pkts & bytes secondly */
          if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
            p_unit_info = sect_cb->info_tbl + unit_id - 1;
            p_unit_data = sect_cb->pStats + unit_id - 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
            p_unit_info = sect_cb->info_tbl + unit_id;
            p_unit_data = sect_cb->pStats + unit_id;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
          }
        }
      }
    }
    else 
    #endif /* not used in T40 */
    {
     g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND; /* don't show reg reads */
     /* Bugzilla #31083, check if counter is active before printing, clearing, or updating */
     if (ten_stats_blk_is_active(dpid, dp, sect_id, unit_id, p_unit_info->blk_active_check)) { 
        ten_stats_update_unit_data(dpid, dp, blk_id,
                                   sect_cb->stride_id,
                                   sect_cb->stride_size,
                                   p_unit_info, p_unit_data,/* p_work_area, */ dir);
        g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

        p_unit_info = sect_cb->info_tbl + unit_id;
        p_unit_data = sect_cb->pStats + unit_id;

        ten_stats_print_unit_cntr(p_unit_info->name, p_unit_info->flags, p_unit_data);
      }
      g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
    }
    break;

  case TEN_STATS_GET:
    #if 0 /* not used in T40 */
    if (TEN_STATS_UNIT_IS_TIE_VALID(p_unit_info->flags)) {
      if (ten_get_sect_print_flag() == 1) {
        if (TEN_STATS_UNIT_IS_NEXT_TIE(p_unit_info->flags)) {
          /* update RX pkts & bytes first */
          if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
            p_unit_info = sect_cb->info_tbl + unit_id + 1;
            p_unit_data = sect_cb->pStats + unit_id + 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
          }
          /* update TX pkts & bytes secondly */
          if ((dir == CS_TX) || (dir == CS_RX_AND_TX)) {
            p_unit_info = sect_cb->info_tbl + unit_id;
            p_unit_data = sect_cb->pStats + unit_id;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
            p_unit_info = sect_cb->info_tbl + unit_id + 1;
            p_unit_data = sect_cb->pStats + unit_id + 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
          }
        }
      }
      else {
        if (TEN_STATS_UNIT_IS_NEXT_TIE(p_unit_info->flags)) {
          /* update RX pkts & bytes first */
          if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data,/* p_work_area, */ CS_RX);
            p_unit_info = sect_cb->info_tbl + unit_id + 1;
            p_unit_data = sect_cb->pStats + unit_id + 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
          }
          /* update TX pkts & bytes secondly */
          if ((dir == CS_TX) || (dir == CS_RX_AND_TX)) {
            p_unit_info = sect_cb->info_tbl + unit_id;
            p_unit_data = sect_cb->pStats + unit_id;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
            p_unit_info = sect_cb->info_tbl + unit_id + 1;
            p_unit_data = sect_cb->pStats + unit_id + 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
          }
        }
        else {
          /* update RX pkts & bytes first */
          if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
            p_unit_info = sect_cb->info_tbl + unit_id - 1;
            p_unit_data = sect_cb->pStats + unit_id - 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
            p_unit_info = sect_cb->info_tbl + unit_id;
            p_unit_data = sect_cb->pStats + unit_id;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
          }
          /* update TX pkts & bytes secondly */
          if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
            p_unit_info = sect_cb->info_tbl + unit_id - 1;
            p_unit_data = sect_cb->pStats + unit_id - 1;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
            p_unit_info = sect_cb->info_tbl + unit_id;
            p_unit_data = sect_cb->pStats + unit_id;
            ten_stats_update_unit_data(dpid, dp, blk_id,
                                       sect_cb->stride_id,
                                       sect_cb->stride_size,
                                       p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
          }
        }
      }
    }
    else
    #endif /* not used in T40 */
    {
      if (ten_stats_blk_is_active(dpid, dp, sect_id, unit_id, p_unit_info->blk_active_check)) { 
        ten_stats_update_unit_data(dpid, dp, blk_id,
                                   sect_cb->stride_id,
                                   sect_cb->stride_size,
                                   p_unit_info, p_unit_data,/* p_work_area, */ dir);
      }
    }
    break;

  case TEN_STATS_CLEAR:
    if ((ten_get_sect_print_flag() == 1)
        || (!TEN_STATS_UNIT_IS_TIE_VALID(p_unit_info->flags))) {
           
      /* Bugzilla #30649, check if counter is active clearing */
      if (ten_stats_blk_is_active(dpid, dp, sect_id, unit_id, p_unit_info->blk_active_check)) { 
        ten_stats_clear_unit_data(dpid, dp, blk_id,
                                  sect_cb->stride_id,
                                  sect_cb->stride_size,
                                  p_unit_info, p_unit_data, /* p_work_area, */ dir);
      }
    }
    #if 0 /* not used in T40 */
    else {
      if (TEN_STATS_UNIT_IS_NEXT_TIE(p_unit_info->flags)) {
        /* clear RX pkts & bytes first */
        if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
          ten_stats_clear_unit_data(dpid, dp, blk_id,
                                    sect_cb->stride_id,
                                    sect_cb->stride_size,
                                    p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
          p_unit_info = sect_cb->info_tbl + unit_id + 1;
          p_unit_data = sect_cb->pStats + unit_id + 1;
          ten_stats_clear_unit_data(dpid, dp, blk_id,
                                    sect_cb->stride_id,
                                    sect_cb->stride_size,
                                    p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
        }
        /* clear TX pkts & bytes secondly */
        if ((dir == CS_TX) || (dir == CS_RX_AND_TX)) {
          p_unit_info = sect_cb->info_tbl + unit_id;
          p_unit_data = sect_cb->pStats + unit_id;
          ten_stats_clear_unit_data(dpid, dp, blk_id,
                                    sect_cb->stride_id,
                                    sect_cb->stride_size,
                                    p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
          p_unit_info = sect_cb->info_tbl + unit_id + 1;
          p_unit_data = sect_cb->pStats + unit_id + 1;
          ten_stats_clear_unit_data(dpid, dp, blk_id,
                                    sect_cb->stride_id,
                                    sect_cb->stride_size,
                                    p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
        }
      }
      else {
        /* clear RX pkts & bytes first */
        if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
          p_unit_info = sect_cb->info_tbl + unit_id - 1;
          p_unit_data = sect_cb->pStats + unit_id - 1;
          ten_stats_clear_unit_data(dpid, dp, blk_id,
                                    sect_cb->stride_id,
                                    sect_cb->stride_size,
                                    p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
          p_unit_info = sect_cb->info_tbl + unit_id;
          p_unit_data = sect_cb->pStats + unit_id;
          ten_stats_clear_unit_data(dpid, dp, blk_id,
                                    sect_cb->stride_id,
                                    sect_cb->stride_size,
                                    p_unit_info, p_unit_data, /* p_work_area, */ CS_RX);
        }
        /* clear TX pkts & bytes secondly */
        if ((dir == CS_RX) || (dir == CS_RX_AND_TX)) {
          p_unit_info = sect_cb->info_tbl + unit_id - 1;
          p_unit_data = sect_cb->pStats + unit_id - 1;
          ten_stats_clear_unit_data(dpid, dp, blk_id,
                                    sect_cb->stride_id,
                                    sect_cb->stride_size,
                                    p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
          p_unit_info = sect_cb->info_tbl + unit_id;
          p_unit_data = sect_cb->pStats + unit_id;
          ten_stats_clear_unit_data(dpid, dp, blk_id,
                                    sect_cb->stride_id,
                                    sect_cb->stride_size,
                                    p_unit_info, p_unit_data, /* p_work_area, */ CS_TX);
        }
      }
    }
    #endif /* not used in T40 */
    break;
  }
  return (CS_OK);
}

/**********************************************************************
 * This is Internal function for STATS only use. This function handles
 * GET/PRINT and CLEAR requests at the Section level.
 **********************************************************************/
cs_status ten_stats_sect_cmn_op(cs_uint16 dpid,
                                ten_dev_or_mod_t dp,
                                cs_uint16 blk_id,
                                cs_uint16 sect_id,
                                ten_stats_sect_cb_t *stats_sect_cb,
                                ten_stats_op_type_t op, cs_dir_t dir)
{
  cs_uint32 ii;

  ten_set_sect_print_flag(1);

  for (ii = 0; ii < stats_sect_cb->num_entries; ii++) {
    ten_stats_unit_cmn_op(dpid, dp, blk_id, sect_id, ii, stats_sect_cb, op, dir, TRUE);
  }
  return (CS_OK);
}

/*********************************************************************
 * Check if any special handling is required based on the flags set for
 * the unit data.
 *********************************************************************/
static
cs_boolean ten_stats_is_spl_hndlr_valid(const ten_stats_info_t * pinfo,
                                        ten_stats_op_type_t op)
{
  cs_uint32 val = 0;

  switch (op) {
  case TEN_STATS_GET:
    val = (pinfo->flags & TEN_STATS_FLAG_SPL_GET);
    break;
  case TEN_STATS_PRINT:
    val = (pinfo->flags & TEN_STATS_FLAG_SPL_PRINT);
    break;
  case TEN_STATS_CLEAR:
    val = (pinfo->flags & TEN_STATS_FLAG_SPL_CLEAR);
    break;
  }

  return ((val) ? TRUE : FALSE);
}

/*********************************************************************
 * Call the Special handler.
 *********************************************************************/
static
cs_status ten_stats_spl_handler(cs_uint16 dpid,
                                ten_dev_or_mod_t dp,
                                cs_uint16 blk_id,
                                cs_uint16 sect_id,
                                cs_uint16 unit_id,
                                ten_stats_op_type_t op,
                                cs_dir_t dir, cs_boolean sect_context)
{
  ten_stats_blk_cb_t *blk_cb = ten_stats_get_blk_cb(dpid, dp, blk_id);

  if (!blk_cb) {
    return (CS_ERROR);
  }

  switch (op) {
  case TEN_STATS_GET:
    if (blk_cb->get_func) {
      blk_cb->get_func(dpid, sect_id, unit_id, dir, sect_context);
    }
    break;
  case TEN_STATS_PRINT:
    if (blk_cb->print_func) {
      blk_cb->print_func(dpid, sect_id, unit_id, dir, sect_context);
    }
    break;
  case TEN_STATS_CLEAR:
    if (blk_cb->clear_func) {
      blk_cb->clear_func(dpid, sect_id, unit_id, dir, sect_context);
    }
    break;
  }
  return (CS_OK);
}

/*********************************************************************
 * GET POINTER TO STATS BLOCK CB
 *********************************************************************/
ten_stats_blk_cb_t *ten_stats_get_blk_cb(cs_uint16 dpid,
                                         ten_dev_or_mod_t dp, cs_uint16 blk_id)
{ 
  if (dp == TEN_DEVICE) {
    ten_dev_stats_cb_t *p = NULL;

    p = TEN_DEV_GET_STATS_CB((cs_uint8) dpid);
    if (p) {
      switch (blk_id) {

      case TEN_ID_XCON:
        return (p->xcon);

      /* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
      default:
        return (NULL);          /* error */
      }
    }
  }
  else {                        /* MODULE */
    ten_mod_stats_cb_t *p = NULL;
    ten_mod_cb_t *pcb;

    pcb = TEN_MOD_ID_TO_PCB_PTR(dpid);
    if (!pcb) {
      return (NULL);
    }  
    p = &pcb->stats_cb;
    
    if (p) {
      switch (blk_id) {
     
      case TEN_ID_SYNCDSYNC:
        return (p->syncdsync);

      case TEN_ID_HSIF:
        return (p->hsif);

      case TEN_ID_GFEC_40G:
        return (p->gfec_40g);

      case TEN_ID_GFEC_10G:
        return (p->gfec_10g);

      case TEN_ID_UFEC:
        return (p->ufec);
        
      case TEN_ID_N40G:
        return (p->n40g);

      case TEN_ID_N10G:
        return (p->n10g);
        
      case TEN_ID_PP10G:
        return (p->pp10g);

      case TEN_ID_PP40G:
        return (p->pp40g);

      default:
        return (NULL);          /* error */
      }
    }
  }
  return (NULL);
}

/********************************************************************
 * SET THE BLOCK CB POINTER IN PORT STATS CB
 ********************************************************************/
static cs_status ten_stats_set_blk_cb(cs_uint16 dpid,
                                      ten_dev_or_mod_t dp,
                                      cs_uint16 blk_id, ten_stats_blk_cb_t *blk_cb)
{
  if (dp == TEN_DEVICE) {
    ten_dev_stats_cb_t *p = NULL;

    p = TEN_DEV_GET_STATS_CB((cs_uint8) dpid);
    if (p) {
      switch (blk_id) {
      case TEN_ID_XCON:
        (p->xcon = blk_cb);
        break;

      /* Bugzilla 26512, cfp stats moved to module stats in the hsif block */
      default:
        return (CS_ERROR);
      }
    }
  }
  else {                        /* MODULE */
    ten_mod_stats_cb_t *p = NULL;
    ten_mod_cb_t *pcb;

    pcb = TEN_MOD_ID_TO_PCB_PTR(dpid);
    if (!pcb) {
      return (CS_ERROR);
    }  
    p = &pcb->stats_cb;
    
    if (p) {
      switch (blk_id) {
      
      case TEN_ID_SYNCDSYNC:
        p->syncdsync = blk_cb;
        break;
        
      case TEN_ID_HSIF:
        p->hsif = blk_cb;
        break;
        
      case TEN_ID_GFEC_40G:
        p->gfec_40g = blk_cb;
        break;

      case TEN_ID_GFEC_10G:
        p->gfec_10g = blk_cb;
        break;

      case TEN_ID_UFEC:
        p->ufec = blk_cb;
        break;
        
      case TEN_ID_N40G:
        p->n40g = blk_cb;
        break;
        
      case TEN_ID_N10G:
        p->n10g = blk_cb;
        break;        
        
      case TEN_ID_PP10G:
        p->pp10g = blk_cb;
        break;
        
      case TEN_ID_PP40G:
        p->pp40g = blk_cb;
        break;

      default:
        return (CS_ERROR);
      }
    }
  }
  return (CS_OK);
}

/*********************************************************************
 * PRINT BLOCK HEADER
 *********************************************************************/
void ten_stats_print_blk_hdr(cs_uint16 dpid, ten_dev_or_mod_t dp, cs_char8 *blk_name)
{
  if (dp == TEN_DEVICE) {
    if (ten_drvr_is_esc_code_enbld()) {
      CS_PRINT_OUTPUT("\033[4m\033[1m");       /* underline + bold */
      CS_PRINT_OUTPUT("\n\t\t\tDev-%02d \t %s STATISTICS\n", dpid, blk_name);
      CS_PRINT_OUTPUT("\033[m");       /* put back to normal printing */
    }

    else {
      CS_PRINT_OUTPUT("= = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
      CS_PRINT_OUTPUT("Dev-%02d \t %s STATISTICS\n", dpid, blk_name);
      CS_PRINT_OUTPUT("= = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
    }
  }

  else {                        /* TEN_MOD */
    if (ten_drvr_is_esc_code_enbld()) {
      CS_PRINT_OUTPUT("\033[4m\033[1m");       /* underline + bold */
      CS_PRINT_OUTPUT("\n\t\t\tModule-0x%04X \t %s STATISTICS\n", dpid, blk_name);
      CS_PRINT_OUTPUT("\033[m");       /* put back to normal printing */
    }

    else {
      CS_PRINT_OUTPUT("= = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
      CS_PRINT_OUTPUT("Module-0x%04X \t %s STATISTICS\n", dpid, blk_name);
      CS_PRINT_OUTPUT("= = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
    }
  }
  return;
}

/************************************************************************
 * PRINT SECTION HEADER
 ***********************************************************************/
void ten_stats_print_sect_hdr(cs_uint16 dpid, ten_dev_or_mod_t dp, cs_char8 *name)
{
  cs_uint8 i;
  cs_char8 myName[] = "-------------------------------------------";

  for (i = 0; i < sizeof(myName); i++) {
    if (name[i] != 0) {
      myName[i] = name[i];
    }
    else {
      myName[i] = ' ';
      break;
    }
  }

  if (dp == TEN_DEVICE) {
    CS_PRINT_OUTPUT("--- Device %02d %-43s-------------- RX ------------------- TX ------\n",
             dpid, myName, "", "");
  }

  else {                        /* TEN_MOD */
    CS_PRINT_OUTPUT("--- Module 0x%04X %-43s---------- RX ------------------- TX ------\n",
             dpid, myName, "", "");
  }

  return;
}

void ten_stats_print_unit_cntr(const cs_char8 *name, cs_uint32 flags,
                               ten_stats_data_t *p_data)
{
  if (ten_drvr_is_stats_in_hex_fmt()) {
    ten_stats_print_unit_cntr_in_hex(name, flags, p_data->rx_ms, p_data->rx_ls,
                                     p_data->tx_ms, p_data->tx_ls);
  }
  else {
    ten_stats_print_unit_cntr_in_dec(name, flags, p_data->rx_ms, p_data->rx_ls,
                                     p_data->tx_ms, p_data->tx_ls);
  }
}

static
void ten_stats_print_unit_cntr_in_hex(const cs_char8 *name, cs_uint32 flags,
                                      cs_uint32 urx, cs_uint32 lrx,
                                      cs_uint32 utx, cs_uint32 ltx)
{
  if (TEN_STATS_UNIT_IS_RX_VALID(flags) && TEN_STATS_UNIT_IS_TX_VALID(flags)) { /* Rx & Tx */
    if (ten_drvr_is_mask_zero_cntr() == TRUE) {
      if (utx | urx | lrx | ltx) {
        if ((urx > 0) && (utx > 0)) {
          CS_PRINT_OUTPUT("\t%-40s :       %8x%08xH      %8x%08xH\n", name, urx, lrx, utx, ltx);
        }
        else if (urx > 0) {
          CS_PRINT_OUTPUT("\t%-40s :       %8x%08xH      %16xH\n", name, urx, lrx, ltx);
        }
        else if (utx > 0) {
          CS_PRINT_OUTPUT("\t%-40s :       %16xH      %8x%08xH\n", name, lrx, utx, ltx);
        }
        else {
          CS_PRINT_OUTPUT("\t%-40s :       %16xH      %16xH\n", name, lrx, ltx);
        }
      }
    }
    else {
      if ((urx > 0) && (utx > 0)) {
        CS_PRINT_OUTPUT("\t%-40s :       %8x%08xH      %8x%08xH\n", name, urx, lrx, utx, ltx);
      }
      else if (urx > 0) {
        CS_PRINT_OUTPUT("\t%-40s :       %8x%08xH      %16xH\n", name, urx, lrx, ltx);
      }
      else if (utx > 0) {
        CS_PRINT_OUTPUT("\t%-40s :       %16xH      %8x%08xH\n", name, lrx, utx, ltx);
      }
      else {
        CS_PRINT_OUTPUT("\t%-40s :       %16xH      %16xH\n", name, lrx, ltx);
      }
    }
  }

  else if (TEN_STATS_UNIT_IS_RX_VALID(flags)) { /* Rx only */
    if (ten_drvr_is_mask_zero_cntr() == TRUE) {
      if (urx | lrx) {
        if (urx > 0) {
          CS_PRINT_OUTPUT("\t%-40s :       %8x%08xH     %18s\n", name, urx, lrx, "N/A");
        }
        else {
          CS_PRINT_OUTPUT("\t%-40s :       %16xH     %18s\n", name, lrx, "N/A");
        }
      }
    }
    else {
      if (urx > 0) {
        CS_PRINT_OUTPUT("\t%-40s :       %8x%08xH     %18s\n", name, urx, lrx, "N/A");
      }
      else {
        CS_PRINT_OUTPUT("\t%-40s :       %16xH     %18s\n", name, lrx, "N/A");
      }
    }
  }

  else if (TEN_STATS_UNIT_IS_TX_VALID(flags)) { /* Tx only */
    if (ten_drvr_is_mask_zero_cntr() == TRUE) {
      if (utx | ltx) {
        if (utx > 0) {
          CS_PRINT_OUTPUT("\t%-40s :      %18s      %8x%08xH\n", name, "N/A", utx, ltx);
        }
        else {
          CS_PRINT_OUTPUT("\t%-40s :      %18s      %16xH\n", name, "N/A", ltx);
        }
      }
    }
    else {
      if (utx > 0) {
        CS_PRINT_OUTPUT("\t%-40s :      %18s      %8x%08xH\n", name, "N/A", utx, ltx);
      }
      else {
        CS_PRINT_OUTPUT("\t%-40s :      %18s      %16xH\n", name, "N/A", ltx);
      }
    }
  }
}

#define TEN_BCD_PLACES 20
const cs_uint8 ten_dec_vals[64][TEN_BCD_PLACES] = { 
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },  /* 2 ^  0 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },  /* 2 ^  1 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 },  /* 2 ^  2 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8 },  /* 2 ^  3 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,6 },  /* 2 ^  4 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2 },  /* 2 ^  5 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,4 },  /* 2 ^  6 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,8 },  /* 2 ^  7 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,5,6 },  /* 2 ^  8 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,2 },  /* 2 ^  9 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,2,4 },  /* 2 ^ 10 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,4,8 },  /* 2 ^ 11 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,9,6 },  /* 2 ^ 12 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,1,9,2 },  /* 2 ^ 13 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,6,3,8,4 },  /* 2 ^ 14 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2,7,6,8 },  /* 2 ^ 15 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,5,5,3,6 },  /* 2 ^ 16 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,1,0,7,2 },  /* 2 ^ 17 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,6,2,1,4,4 },  /* 2 ^ 18 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,2,4,2,8,8 },  /* 2 ^ 19 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,4,8,5,7,6 },  /* 2 ^ 20 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,9,7,1,5,2 },  /* 2 ^ 21 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,9,4,3,0,4 },  /* 2 ^ 22 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,0,8,3,8,8,6,0,8 },  /* 2 ^ 23 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,1,6,7,7,7,2,1,6 },  /* 2 ^ 24 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,3,3,5,5,4,4,3,2 },  /* 2 ^ 25 */
  { 0,0,0,0,0,0,0,0,0,0,0,0,6,7,1,0,8,8,6,4 },  /* 2 ^ 26 */
  { 0,0,0,0,0,0,0,0,0,0,0,1,3,4,2,1,7,7,2,8 },  /* 2 ^ 27 */
  { 0,0,0,0,0,0,0,0,0,0,0,2,6,8,4,3,5,4,5,6 },  /* 2 ^ 28 */
  { 0,0,0,0,0,0,0,0,0,0,0,5,3,6,8,7,0,9,1,2 },  /* 2 ^ 29 */
  { 0,0,0,0,0,0,0,0,0,0,1,0,7,3,7,4,1,8,2,4 },  /* 2 ^ 30 */
  { 0,0,0,0,0,0,0,0,0,0,2,1,4,7,4,8,3,6,4,8 },  /* 2 ^ 31 */
  { 0,0,0,0,0,0,0,0,0,0,4,2,9,4,9,6,7,2,9,6 },  /* 2 ^ 32 */
  { 0,0,0,0,0,0,0,0,0,0,8,5,8,9,9,3,4,5,9,2 },  /* 2 ^ 33 */
  { 0,0,0,0,0,0,0,0,0,1,7,1,7,9,8,6,9,1,8,4 },  /* 2 ^ 34 */
  { 0,0,0,0,0,0,0,0,0,3,4,3,5,9,7,3,8,3,6,8 },  /* 2 ^ 35 */
  { 0,0,0,0,0,0,0,0,0,6,8,7,1,9,4,7,6,7,3,6 },  /* 2 ^ 36 */
  { 0,0,0,0,0,0,0,0,1,3,7,4,3,8,9,5,3,4,7,2 },  /* 2 ^ 37 */
  { 0,0,0,0,0,0,0,0,2,7,4,8,7,7,9,0,6,9,4,4 },  /* 2 ^ 38 */
  { 0,0,0,0,0,0,0,0,5,4,9,7,5,5,8,1,3,8,8,8 },  /* 2 ^ 39 */
  { 0,0,0,0,0,0,0,1,0,9,9,5,1,1,6,2,7,7,7,6 },  /* 2 ^ 40 */
  { 0,0,0,0,0,0,0,2,1,9,9,0,2,3,2,5,5,5,5,2 },  /* 2 ^ 41 */
  { 0,0,0,0,0,0,0,4,3,9,8,0,4,6,5,1,1,1,0,4 },  /* 2 ^ 42 */
  { 0,0,0,0,0,0,0,8,7,9,6,0,9,3,0,2,2,2,0,8 },  /* 2 ^ 43 */
  { 0,0,0,0,0,0,1,7,5,9,2,1,8,6,0,4,4,4,1,6 },  /* 2 ^ 44 */
  { 0,0,0,0,0,0,3,5,1,8,4,3,7,2,0,8,8,8,3,2 },  /* 2 ^ 45 */
  { 0,0,0,0,0,0,7,0,3,6,8,7,4,4,1,7,7,6,6,4 },  /* 2 ^ 46 */
  { 0,0,0,0,0,1,4,0,7,3,7,4,8,8,3,5,5,3,2,8 },  /* 2 ^ 47 */
  { 0,0,0,0,0,2,8,1,4,7,4,9,7,6,7,1,0,6,5,6 },  /* 2 ^ 48 */
  { 0,0,0,0,0,5,6,2,9,4,9,9,5,3,4,2,1,3,1,2 },  /* 2 ^ 49 */
  { 0,0,0,0,1,1,2,5,8,9,9,9,0,6,8,4,2,6,2,4 },  /* 2 ^ 50 */
  { 0,0,0,0,2,2,5,1,7,9,9,8,1,3,6,8,5,2,4,8 },  /* 2 ^ 51 */
  { 0,0,0,0,4,5,0,3,5,9,9,6,2,7,3,7,0,4,9,6 },  /* 2 ^ 52 */
  { 0,0,0,0,9,0,0,7,1,9,9,2,5,4,7,4,0,9,9,2 },  /* 2 ^ 53 */
  { 0,0,0,1,8,0,1,4,3,9,8,5,0,9,4,8,1,9,8,4 },  /* 2 ^ 54 */
  { 0,0,0,3,6,0,2,8,7,9,7,0,1,8,9,6,3,9,6,8 },  /* 2 ^ 55 */
  { 0,0,0,7,2,0,5,7,5,9,4,0,3,7,9,2,7,9,3,6 },  /* 2 ^ 56 */
  { 0,0,1,4,4,1,1,5,1,8,8,0,7,5,8,5,5,8,7,2 },  /* 2 ^ 57 */
  { 0,0,2,8,8,2,3,0,3,7,6,1,5,1,7,1,1,7,4,4 },  /* 2 ^ 58 */
  { 0,0,5,7,6,4,6,0,7,5,2,3,0,3,4,2,3,4,8,8 },  /* 2 ^ 59 */
  { 0,1,1,5,2,9,2,1,5,0,4,6,0,6,8,4,6,9,7,6 },  /* 2 ^ 60 */
  { 0,2,3,0,5,8,4,3,0,0,9,2,1,3,6,9,3,9,5,2 },  /* 2 ^ 61 */
  { 0,4,6,1,1,6,8,6,0,1,8,4,2,7,3,8,7,9,0,4 },  /* 2 ^ 62 */
  { 0,9,2,2,3,3,7,2,0,3,6,8,5,4,7,7,5,8,0,8 }   /* 2 ^ 63 */
};

static
void ten_stats_print_unit_cntr_in_dec(const cs_char8 *name, cs_uint32 flags,
                                      cs_uint32 urx, cs_uint32 lrx,
                                      cs_uint32 utx, cs_uint32 ltx)
{
  /* to work with compilers that do not support 64 bits,        */
  /* use a BCD method of displaying 64 bit counters in decimal  */
  /* instead of CS_PRINT_OUTPUT("%lld", cnt).                          */
  
  cs_uint8 dec_num[TEN_BCD_PLACES+1];
  cs_uint8 rx_dec_num[TEN_BCD_PLACES+1];
  cs_uint16 ii, jj, kk, ll, found_nonzero;
  cs_uint32 bit_pos = 0;
  cs_uint32 in_ms, in_ls;
  
  for (ll=0; ll<2; ll++) {
    if (ll == 0) {
      in_ms = urx;
      in_ls = lrx;
    } 
    else {
      for (ii=0; ii<TEN_BCD_PLACES; ii++) {
        rx_dec_num[ii] = dec_num[ii];
      }
      rx_dec_num[TEN_BCD_PLACES] = 0;
      in_ms = utx;
      in_ls = ltx;
    }
    
    for (ii=0; ii<TEN_BCD_PLACES; ii++) {
      dec_num[ii] = 0;
    }
    /* CS_PRINT_OUTPUT("%08X-%08X\n", in_ms, in_ls); */
    
    for (ii=0; ii<64; ii++) {
      if (ii < 32) {
        bit_pos = in_ls & 1;
        in_ls >>= 1;
      }
      else {
         bit_pos = in_ms & 1;
         in_ms >>= 1;
      }
      
      for (jj=(TEN_BCD_PLACES-1); jj>0; jj--) {
        dec_num[jj] += (bit_pos*ten_dec_vals[ii][jj]);
        
        if (dec_num[jj] >= 10) {
          dec_num[jj] -= 10;
          if (jj) {
            dec_num[jj-1] += 1;
          }
        }
      }
    }
    for (kk=0; kk<TEN_BCD_PLACES; kk++) {
      dec_num[kk] += '0';
    }  
    found_nonzero = 0;
    for (kk=1; kk<TEN_BCD_PLACES; kk++) {
      if ((dec_num[kk-1] == '0') & (!found_nonzero)) {
        dec_num[kk-1] = 0x20; /* strip leading zeroes */ 
      }
      if (dec_num[kk] != '0') {
        found_nonzero = 1;
      }
    }
    dec_num[TEN_BCD_PLACES] = 0;
  }
  
  /* Rx & Tx */
  if (TEN_STATS_UNIT_IS_RX_VALID(flags) && TEN_STATS_UNIT_IS_TX_VALID(flags)) {
    if (ten_drvr_is_mask_zero_cntr() == TRUE) {
      if (utx | urx | ltx | lrx) {
          CS_PRINT_OUTPUT("\t%-40s :  %22s %22s\n", name, rx_dec_num, dec_num);
      }
    }
    else {
      CS_PRINT_OUTPUT("\t%-40s :  %22s %22s\n", name, rx_dec_num, dec_num);
    }
  }

  /* Rx only */
  else if (TEN_STATS_UNIT_IS_RX_VALID(flags)) { 
    if (ten_drvr_is_mask_zero_cntr() == TRUE) {
      if (urx | lrx) {
         CS_PRINT_OUTPUT("\t%-40s :  %22s %22s\n", name, rx_dec_num, "N/A");
      }
    }
    else {
      CS_PRINT_OUTPUT("\t%-40s :  %22s %22s\n", name, rx_dec_num, "N/A");
    }
  }
  
  /* Tx only */
  else if (TEN_STATS_UNIT_IS_TX_VALID(flags)) { 
    if (ten_drvr_is_mask_zero_cntr() == TRUE) {
      if (utx | ltx) {
        CS_PRINT_OUTPUT("\t%-40s :  %22s %22s\n", name, "N/A", dec_num );
      }
    }
    else {
      CS_PRINT_OUTPUT("\t%-40s :  %22s %22s\n", name, "N/A", dec_num );
    }
  }
}

/****************************************
 * Set Section print flag               *
 ****************************************/
void ten_set_sect_print_flag(cs_uint32 val)
{
  _ten_sect_print_flag = val;
}

/****************************************
 * Get Section print flag               *
 ****************************************/
cs_uint32 ten_get_sect_print_flag(void)
{
  return (_ten_sect_print_flag);
}

/********************************************************************
 * This function is STATS internal function. This function checks    
 * if the current counter is active before displaying, reading or 
 * clearing it.                                                 
 * This check avoids bus errors for those counters which are not 
 * functionally-enabled or still in reset.
 ********************************************************************/
cs_uint16 ten_stats_blk_is_active(cs_uint16 dpid,
                                  ten_dev_or_mod_t dp,
                                  cs_uint16 sect_id,
                                  cs_uint16 unit_id,
                                  cs_uint16 blk_check_id)
{
  cs_uint16 active = 1;
  cs_uint16 module_id = 0;
  cs_uint16 mod_num = 0; 
  cs_uint16 dev_id = 0;
  cs_uint16 pp_misc_reset = 0;
  cs_uint8 slice = (cs_uint8)(sect_id & 0x00FF);
  
  if (dp == TEN_DEVICE) {
    dev_id = dpid;
  }
  else {                
    module_id = dpid;
    dev_id = TEN_MOD_ID_TO_DEV_ID(dpid);
    mod_num = TEN_MOD_ID_TO_MOD_NUM(dpid);
  }
  
  CS_PRINT("ten_stats_blk_is_active, d/m_id=%d, dp=%d, slice=%d, blk_chk_id=%d\n",
            dpid, dp, slice, blk_check_id);
  
  /* if pp10g misc_reset is enabled, no need to check func_ens (will cause bus errors) */
  if ((blk_check_id >= TEN_STATS_CHECK_PP10G_MISC_RESET) && (blk_check_id <= TEN_STATS_CHECK_PP10G_TX_BYPASS)) {
    pp_misc_reset = ten_pp10g_get_misc_reset(module_id, slice);
    if (pp_misc_reset) {
      /* this pp10g is in reset, not active */
      return 0;
    }
  }
  
  /* if pp40g misc_reset is enabled, no need to check func_ens (will cause bus errors) */
  if ( (blk_check_id == TEN_STATS_CHECK_PP40G_MISC_RESET) || 
       (blk_check_id == TEN_STATS_CHECK_PP40G_PBERT) ) {
    pp_misc_reset = ten_pp40g_get_misc_sreset_t41(module_id);
    if (pp_misc_reset) {
      /* this pp40g is in reset, not active */
      return 0;
    }
  }
  
  switch (blk_check_id) {
  
  case (TEN_STATS_CHECK_NONE):
    active = 1;
    break;
  
  case (TEN_STATS_CHECK_PP10G_RX_XGPCS):
    active = ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_XGPCS);
    break;

  case (TEN_STATS_CHECK_PP10G_RX_GFP):
    active = ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_GFP);
    break;

  case (TEN_STATS_CHECK_PP10G_RX_BASEX):
    active = ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_BASEX);
    break;

  case (TEN_STATS_CHECK_PP10G_RX_EGPCS):
    active = ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_EGPCS);
    break;

  case (TEN_STATS_CHECK_PP10G_RX_XCODE):
    active = ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_XCODE);
    break;

  case (TEN_STATS_CHECK_PP10G_RX_MAC):
    active = ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_MAC);
    break;

  case (TEN_STATS_CHECK_PP10G_RX_BYPASS):
    active = ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_BYPASS);
    break;

  case (TEN_STATS_CHECK_PP10G_RX_FC):
    active = ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_FC);  
    break;

  case (TEN_STATS_CHECK_PP10G_RX_MON10):
    active = ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_MON10B);  
    break;

  case (TEN_STATS_CHECK_PP10G_RX_BER10B):
     active = ten_pp10g_get_funcen_rx(module_id, slice, TEN_PP10G_FUNCEN_BER10B);  
     break;
     
  case (TEN_STATS_CHECK_PP10G_TX_XGPCS):
    active = ten_pp10g_get_funcen_tx(module_id, slice, TEN_PP10G_FUNCEN_XGPCS);
    break;

  case (TEN_STATS_CHECK_PP10G_TX_GFP):
    active = ten_pp10g_get_funcen_tx(module_id, slice, TEN_PP10G_FUNCEN_GFP); 
    break;

  case (TEN_STATS_CHECK_PP10G_TX_BASEX):
    active = ten_pp10g_get_funcen_tx(module_id, slice, TEN_PP10G_FUNCEN_BASEX);
    break;

  case (TEN_STATS_CHECK_PP10G_TX_EGPCS):
    active = ten_pp10g_get_funcen_tx(module_id, slice, TEN_PP10G_FUNCEN_EGPCS);
    break;

  case (TEN_STATS_CHECK_PP10G_TX_XCODE):
    active = ten_pp10g_get_funcen_tx(module_id, slice, TEN_PP10G_FUNCEN_XCODE); 
    break;

  case (TEN_STATS_CHECK_PP10G_TX_MAC):
    active = ten_pp10g_get_funcen_tx(module_id, slice, TEN_PP10G_FUNCEN_MAC);
    break;

  case (TEN_STATS_CHECK_PP10G_TX_BYPASS):
    active = ten_pp10g_get_funcen_tx(module_id, slice, TEN_PP10G_FUNCEN_BYPASS);
    break;

  case (TEN_STATS_CHECK_SYNCDSYNC):
    if ( ((ten_mpif_get_global_reset_syncdsync(dev_id, mod_num, slice, CS_RX)) == 0) &&
         ((ten_mpif_get_global_reset_syncdsync(dev_id, mod_num, slice, CS_TX)) == 0) ) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  case (TEN_STATS_CHECK_SDS_MR):
    if ( ((ten_mpif_get_global_reset_sds_mr(dev_id, mod_num, slice, CS_RX)) == 0) &&
         ((ten_mpif_get_global_reset_sds_mr(dev_id, mod_num, slice, CS_TX)) == 0) ) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  case (TEN_STATS_CHECK_SDS_XFI):
    if ( ((ten_mpif_get_global_reset_sds_xfi(dev_id, unit_id, CS_RX)) == 0) &&
         ((ten_mpif_get_global_reset_sds_xfi(dev_id, unit_id, CS_TX)) == 0) ) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  case (TEN_STATS_CHECK_GFEC40G):
    if ( ((ten_mpif_get_global_reset_gfec_40g(dev_id, mod_num, CS_RX)) == 0) &&                                      
         ((ten_mpif_get_global_reset_gfec_40g(dev_id, mod_num, CS_TX)) == 0) ) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  case (TEN_STATS_CHECK_GFEC10G):
    if ( ((ten_mpif_get_global_reset_gfec_10g(dev_id, slice, CS_RX)) == 0) &&                                      
         ((ten_mpif_get_global_reset_gfec_10g(dev_id, slice, CS_TX)) == 0) ) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  case (TEN_STATS_CHECK_UFEC):
    if ( ((ten_mpif_get_global_reset_ufec(dev_id, slice, CS_RX)) == 0) &&                                      
         ((ten_mpif_get_global_reset_ufec(dev_id, slice, CS_TX)) == 0) ) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  case (TEN_STATS_CHECK_N40G):
    if ( ((ten_mpif_get_global_reset_n40g(dev_id, mod_num, CS_RX)) == 0) &&                                      
         ((ten_mpif_get_global_reset_n40g(dev_id, mod_num, CS_TX)) == 0) ) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  case (TEN_STATS_CHECK_N10G):
    if ( ((ten_mpif_get_global_reset_n10g(dev_id, mod_num, slice, CS_RX)) == 0) &&                                      
         ((ten_mpif_get_global_reset_n10g(dev_id, mod_num, slice, CS_TX)) == 0) ) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  case (TEN_STATS_CHECK_N10G_SOH):
    if ( ((ten_mpif_get_global_reset_n10g(dev_id, mod_num, slice, CS_RX)) == 0) &&                                      
         ((ten_mpif_get_global_reset_n10g(dev_id, mod_num, slice, CS_TX)) == 0) &&
         ((ten_n10g_get_gblr_dpcfg_sdhoff(module_id, slice)) == 0) ) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  case (TEN_STATS_CHECK_CFP_MR):
    if ((ten_mpif_get_global_reset_sds_cfp_t41(dev_id, unit_id, CS_TX_AND_RX)) == 0) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  case (TEN_STATS_CHECK_PP40G_PBERT):
    if ( ((ten_pp40g_get_misc_tx_funcen_pbt(module_id)) == 1) &&                                      
         ((ten_pp40g_misc_tx_clken_pbt(module_id)) == 1) ) {
      active = 1; /* RX/TX blocks are out of hard reset */
    }
    else {
      active = 0;
    }
    break;
    
  default:
    active = 1;
    break;
  }
  return (active);
}






