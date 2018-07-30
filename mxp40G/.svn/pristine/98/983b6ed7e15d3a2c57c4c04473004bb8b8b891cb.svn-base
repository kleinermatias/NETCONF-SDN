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
 * ten_debug.c
 *
 * Contains many of the debug utilities and functions that are useful for
 * testing purposes.
 *
 * $Id: ten_debug.c,v 1.53 2013/03/12 14:43:40 khill Exp $
 *
 */

#include "tenabo40.h"
#include <util.h>
/****************************************************************/
/* Register write trace facility for debug.                     */
/****************************************************************/
/* Initially support device ids 0-2)                            */
static cs_uint32 ten_debug_reg_write_trcpnt[3][8];
/* Trace state can be TEN_DEBUG_REG_WR_TR_STATE_NULL, TEN_DEBUG_*/
/* REG_WR_TR_STATE_DISABLE, or TEN_DEBUG_REG_WR_TR_STATE_ENABLE.*/
static cs_uint16 ten_debug_reg_write_trc_st[3] = {0,0,0};  


/****************************************************************/
/*                                                              */  
/*  TEN_REG_READ                                                */
/*                                                              */  
/****************************************************************/
cs_uint16 TEN_REG_READ(volatile cs_uint16 *pReg)
{
  cs_uint16 data;
  #ifdef TEN_CHECK_FOR_BUS_ERRORS
  TEN_MPIF_MPIF_INTERRUPT_t tmp_mpif_interrupt;
  #endif

  data = CS_REG_READ(pReg);
  if (!(g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND)) {
   CS_PRINT("RD: 0x%05X = 0x%04X\n", ((cs_uint32)(pReg) - 
            g_pTEN->debug_base_address)>>1 , data );
  }
  ten_reg_read_cb(pReg, data);

  /* Bugzilla #26434, more control for bus errors */
  #ifdef TEN_CHECK_FOR_BUS_ERRORS
  if (g_pTEN->ten_bus_error_ctl == CS_ENABLE) {
  
    /* Check for Bus Errors, Bugzilla #19363 */
    tmp_mpif_interrupt.wrd = CS_REG_READ((cs_uint16 *)(g_pTEN->debug_base_address) + TEN_MPIF_MPIF_INTERRUPT);
    if (tmp_mpif_interrupt.bf.buserri) { 
      g_pTEN->ten_bus_error_count++; /* Bugzilla #26434 */
      /* if (!(g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND)) { */
        CS_PRINT("BUS ERROR ON RD: 0x%05X = 0x%04X\n", ((cs_uint32)(pReg) - g_pTEN->debug_base_address)>>1 , data );
        CS_HNDL_ERROR(0, ETEN_DEV_REG_ACCESS_TIMEOUT, ": Bus Error.");
      /* } */
      /* Bugzilla #29271, fix bus error warning */
      CS_REG_WRITE((cs_uint16 *)(g_pTEN->debug_base_address) + TEN_MPIF_MPIF_INTERRUPT, tmp_mpif_interrupt.bf.buserri);
    }
  }
  #endif
  
  return (data);
}

/****************************************************************/
/*                                                              */  
/*  TEN_REG_WRITE                                               */
/*                                                              */  
/****************************************************************/
void TEN_REG_WRITE(volatile cs_uint16 *addr, cs_uint16 data)
{
  cs_uint32 offset;

  #ifdef TEN_CHECK_FOR_BUS_ERRORS
  TEN_MPIF_MPIF_INTERRUPT_t tmp_mpif_interrupt;
  #endif

  /* this is ugly. Search for dev_id based on addr. */
  cs_uint16 ii;
  cs_uint16 *pDev=0;
  cs_uint16 dev_id = TEN_MAX_NUM_DEVICES; /* Init to out of range */
  for (ii=0; ii<3; ii++) {  /* If more than 3 devices necessary, change upper limit from 3 to TEN_MAX_NUM_DEVICES */
    if (g_pTEN->p_dev_cb_tbl[ii]) {
      if ( ((cs_uint16 *)(g_pTEN->p_dev_cb_tbl[ii]->base_addr) > pDev) && ((cs_uint16 *)(g_pTEN->p_dev_cb_tbl[ii]->base_addr) <= addr) ) {
        dev_id = ii;
        pDev = (cs_uint16 *) g_pTEN->p_dev_cb_tbl[ii]->base_addr;
      }
    }
  }
  if (dev_id == TEN_MAX_NUM_DEVICES) { /* dev_id lookup failed. Skip trace and get offset the old way. */
    offset = ((cs_uint32)(addr) - g_pTEN->debug_base_address)>>1;
  }
  else {
    offset = ((cs_uint32)(addr) - (cs_uint32)pDev)>>1;
    if (ten_debug_reg_write_trc_st[dev_id] == TEN_DEBUG_REG_WR_TR_STATE_ENABLE) {
      for (ii=0; ii<8; ii++) {
        if (offset==ten_debug_reg_write_trcpnt[dev_id][ii]) {
          CS_PRINT_OUTPUT("WR: 0x%05X = 0x%04X  <<< TRACE <<< dev_id=%d trc_id=%d\n", offset, (data), dev_id, ii);
          break;
        }
      }
    }
  }

  if (g_pTEN->ws_ctl.enbl == FALSE) {
    if (!(g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND)) {
      CS_PRINT("WR: 0x%05X = 0x%04X\n", offset, (data));
    }
    CS_REG_WRITE(addr, data);
  }
  ten_reg_write_cb(addr, data);

  #ifdef TEN_CHECK_FOR_BUS_ERRORS
  /* Bugzilla #26434, more control for bus errors */
  if (g_pTEN->ten_bus_error_ctl == CS_ENABLE) {
    /* Check for Bus Errors, Bugzilla #19363 */
    tmp_mpif_interrupt.wrd = CS_REG_READ((cs_uint16 *)(g_pTEN->debug_base_address) + TEN_MPIF_MPIF_INTERRUPT);
    if (tmp_mpif_interrupt.bf.buserri) { 
      g_pTEN->ten_bus_error_count++; /* Bugzilla #26434 */
      /* if (!(g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND)) { */
        CS_PRINT("BUS ERROR ON WR: 0x%05X = 0x%04X\n", ((cs_uint32)(addr) - g_pTEN->debug_base_address)>>1 , (data));
        CS_HNDL_ERROR(0, ETEN_DEV_REG_ACCESS_TIMEOUT, ": Bus Error.");
      /* } */
      /* Bugzilla #29271, fix bus error warning */
      CS_REG_WRITE((cs_uint16 *)(g_pTEN->debug_base_address) + TEN_MPIF_MPIF_INTERRUPT, tmp_mpif_interrupt.bf.buserri);
    }
  }
  #endif
}

#if (0)
/* Bugzilla #21920, use fpga based timer for testing */
#define T40EVB_DEBUG_TIMER_clkpd_us (100)
#define T40EVB_DEBUG_TIMER  (0x00007)
#define FPGA_SYS_ID (432)
cs_uint16 t40fpga_read_reg( int dev_id, int addr );

cs_uint16 TEN_FPGA_BASED_UDELAY(cs_uint16 us) 
{
  cs_uint32 clkpd_us, startcntr, fpgacntr, addr_FCNTR, elapsed_us;
  #if 0
  cs_uint16 chip_id;
  cs_uint32 ii, jj;
  #endif
  T41_t *pDev = NULL;

  TEN_DEV_COMMON_VALIDATE(0, pDev, 0);
  clkpd_us = T40EVB_DEBUG_TIMER_clkpd_us;
  /*  use FPGA counter which counts by 100us        */
  /*  back-to-back reads of FCNTR with APISH takes about 424 us */
  elapsed_us = 0;
  addr_FCNTR = T40EVB_DEBUG_TIMER;
  
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
  
  startcntr = t40fpga_read_reg(FPGA_SYS_ID, addr_FCNTR); /* eg 54 */
  /* JUST_LOG_1(LOG_INFO, "T41", "start = %d\n", startcntr);  */

  while (elapsed_us < us) {
    fpgacntr = t40fpga_read_reg(FPGA_SYS_ID, addr_FCNTR); /* eg 58 */
    /*  JUST_LOG_2(LOG_INFO, "T41", "el = %d, cnt=%d\n", elapsed_us, fpgacntr); */

    if (fpgacntr < startcntr) {
      /* cntr has rolled over, so add max cnt (65536) */
      fpgacntr += 1 << 16;
    }
    elapsed_us = ((fpgacntr - startcntr) * clkpd_us);  /* eg 4-1 * 100us */
  }
  /* JUST_LOG_2(LOG_INFO, "T41", "el = %d, cnt=%d\n", elapsed_us, fpgacntr); */
  
  /* TBD use chip id for times less than 100us */
  /* takes 247600 reads for 1 second */
  #if 0
  for (ii=0; ii<(us>>1);ii++) {
    chip_id = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, CHIP_ID_LSB)); 
  }
  fpgacntr = t40fpga_read_reg(FPGA_SYS_ID, addr_FCNTR); /* eg 58 */
  #endif
  /* JUST_LOG_2(LOG_INFO, "T41", "end=%d, diff=%d\n", fpgacntr, fpgacntr-startcntr); */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
  return (0);
}
#endif

/****************************************************************/
/*                                                              */  
/*  Delay utilities                                             */
/*                                                              */  
/****************************************************************/
 /* Bugzilla #24139, allow more time in TEN_MDELAY/TEN_UDELAY */
void TEN_UDELAY(cs_uint32 usecs) 
{
  /* No bugzilla. Release 5.5. No functional change.          */
  /* Output suppression follows TEN_DRVR_LOG_SUSPEND flag.    */
  TEN_UDELAY_PRINT_OPT(usecs, !(g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND) );
}

/* No bugzilla. Release 5.5. Copied rom old TEN_UDELAY.       */
/* Print is supressed when print_it is FALSE.                 */
void TEN_UDELAY_PRINT_OPT(cs_uint32 usecs, cs_uint8 print_it)
{
  cs_uint32 tmp_usecs = 0;
  
  /* Bugzilla #28471, 6ms minimum delay */
  /* Bugzilla #30990, minimum delay configurable by #define */
  if (usecs < TEN_DRVR_UDELAY_MIN) {
    tmp_usecs = TEN_DRVR_UDELAY_MIN;
  }
  else {
    tmp_usecs = usecs;
  }
    
  /* check for delay logging or not */
  if (print_it) {
    CS_PRINT_DELAYS("TEN_UDELAY:  %d ms (%d us)\n", tmp_usecs/1000, tmp_usecs);
  }
  
  /* Bugzilla #24530, do not delay if warm start is active */
  if (g_pTEN->ws_ctl.enbl) {
    CS_PRINT_DELAYS("TEN_UDELAY:  Warm Start active, no delay taken.\n");
    return;
  }
  
  if (CS_IN_SIM_ENV()) {
    ten_sim_delay(FALSE, tmp_usecs);
  }  
  else {
    #if (1) 
    CS_UDELAY(tmp_usecs);
    #else 
    TEN_FPGA_BASED_UDELAY(tmp_usecs);
    #endif
  }
}

/* Bugzilla #24139, allow more time in TEN_MDELAY/TEN_UDELAY */
void TEN_MDELAY(cs_uint32 msecs) 
{
  /* No bugzilla. Release 5.5. No functional change.          */
  /* Output suppression follows TEN_DRVR_LOG_SUSPEND flag.    */
  TEN_MDELAY_PRINT_OPT(msecs, !(g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND) );
}

/* No bugzilla. Release 5.5. Copied rom old TEN_MDELAY.       */
/* Print is supressed when print_it is FALSE.                 */
void TEN_MDELAY_PRINT_OPT(cs_uint32 msecs, cs_uint8 print_it)
{
  /* CS_PRINT_DELAYS("TEN_MDELAY:  Wait for %d milliseconds\n", msecs); */
  if (CS_IN_SIM_ENV()) {
    ten_sim_delay(TRUE, msecs);
  }  
  else {
    /* Bugzilla #21920, use fpga based timer for testing.     */
    /* Subsequent to #21920, No bugzilla. Release 5.5. No     */
    /* functional change.                                     */
    TEN_UDELAY_PRINT_OPT(msecs*1000, print_it);
  }
}


/****************************************************************/
/* $rtn_hdr_start  HIGH RES USEC DELAY VIA CALL-BACK            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_udelay_hi_res(cs_uint32 usecs)
/* INPUTS     : o Micro-seconds                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Register value                                  */
/* DESCRIPTION:                                                 */
/* Accesses a usec delay timer via callback.                    */
/*                                                              */
/* The default timer function registered for callback is a      */
/* busy-wait timer implemented using the MPIF registers on the  */
/* first T41 to be registered during driver initialization.     */
/*                                                              */
/* This can be replaced by calling ten_unregister_udelay_hi_    */
/* res() and then calling ten_register_udelay_hi_res() with the */
/* delay or sleep function of choice.                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_udelay_hi_res_cb(usecs);
}

/****************************************************************/




cs_boolean TEN_DRVR_IS_LOADED(void) 
{
   if (!g_pTEN) {
     return (FALSE);
   }
   else {
     return (g_pTEN->drvr_loaded);
   }  
}
ten_dev_cb_t *TEN_DEV_ID_TO_DEVCB_PTR(cs_uint16 dev_id)
{
  return (g_pTEN->p_dev_cb_tbl[dev_id]);
}

cs_status TEN_DEV_COMMON_VALIDATE_INTERNAL(cs_uint16 DEV_ID, T41_t **BASE_ADDR)
{
  if (!g_pTEN)
  {
    CS_HNDL_ERROR(DEV_ID, ETEN_DEV_PTEN_NULL,
                  ": pTEN is a null ptr.");
    return (CS_ERROR);
  }

  if (!(g_pTEN->drvr_loaded)) {
    CS_HNDL_ERROR(DEV_ID, ETEN_DRVR_NOT_LOADED,
                  ": drvr is not loaded.");
    return (CS_ERROR);
  }

  if (DEV_ID >= TEN_MAX_NUM_DEVICES) {
    CS_HNDL_ERROR(DEV_ID, ETEN_DEV_ID_OUT_OF_RANGE,
                  ": max devices exceeded, s/b 0..15.");
    return (CS_ERROR);
  }

  if (!g_pTEN->p_dev_cb_tbl[DEV_ID]) {
    CS_HNDL_ERROR(DEV_ID, ETEN_DEV_TBL_NULL,
                  ": dev cb tbl is a null ptr.");
      return (CS_ERROR);
  }

  if ((g_pTEN->p_dev_cb_tbl[DEV_ID])->state == TEN_DEV_STATE_INVALID) {
    CS_HNDL_ERROR(DEV_ID, ETEN_DEV_NOT_INITED,
                  ": dev state is invalid.");
    return (CS_ERROR);
  }

  *BASE_ADDR = (T41_t *)((g_pTEN->p_dev_cb_tbl[DEV_ID])->base_addr);
  return (CS_OK);
}

cs_status TEN_MOD_COMMON_VALIDATE_INTERNAL(cs_uint16 MODULE_ID,  T41_t **BASE_ADDR)
{
  cs_uint16 temp_dev_id = TEN_MOD_ID_TO_DEV_ID(MODULE_ID);
  cs_uint16 temp_mod_num = TEN_MOD_ID_TO_MOD_NUM(MODULE_ID);

  if (!g_pTEN)
  {
    CS_HNDL_ERROR(temp_dev_id, ETEN_MOD_NULL_PTR,
                  ": pTEN is a null ptr.");
    return (CS_ERROR);
  }

  if (!(g_pTEN->drvr_loaded)) {
    CS_HNDL_ERROR(temp_dev_id, ETEN_DRVR_NOT_LOADED,
                  ": drvr not loaded.");
    return (CS_ERROR);
  }

  if (temp_dev_id >= TEN_MAX_NUM_DEVICES) {
    CS_HNDL_ERROR(temp_dev_id, ETEN_DEV_ID_OUT_OF_RANGE,
                  ": max devices exceeded, s/b 0..15.");
    return (CS_ERROR);
  }

  if (temp_mod_num > TEN_MODULE_B) {
    CS_HNDL_ERROR(temp_dev_id, ETEN_MOD_ID_OUT_OF_RANGE,
                  ": max module num exceeded, s/b 0..1.");
    return (CS_ERROR);
  }

  if (!g_pTEN->p_dev_cb_tbl[temp_dev_id]) {
    CS_HNDL_ERROR(temp_dev_id, ETEN_DEV_TBL_NULL,
                  ": dev cb tbl is a null ptr.");
    return (CS_ERROR);
  }

  if ((g_pTEN->p_dev_cb_tbl[temp_dev_id])->state != TEN_DEV_STATE_INITIALIZED) {
    CS_HNDL_ERROR(temp_dev_id, ETEN_DEV_NOT_INITED,
                  ": dev state is not initialized.");
    return (CS_ERROR);
  }

  if (!(g_pTEN->p_dev_cb_tbl[temp_dev_id])->ppcb[temp_mod_num]) {
    CS_HNDL_ERROR(temp_dev_id, ETEN_MOD_TBL_NULL,
                  ": mod cb tbl is a null ptr.");
    return (CS_ERROR);
  }

  if ((g_pTEN->p_dev_cb_tbl[temp_dev_id])->ppcb[temp_mod_num]->state
                            != TEN_MOD_STATE_HW_INIT_DONE) {
   CS_HNDL_ERROR(temp_dev_id, ETEN_MOD_NOT_INITED,
                 ": dev cb tbl state not initialized.");
   return (CS_ERROR);
  }

  *BASE_ADDR = ((T41_t *)(g_pTEN->p_dev_cb_tbl[temp_dev_id]->base_addr));
  return (CS_OK);
}

void cs_bar(void)
{
  CS_PRINT_OUTPUT("----------------------------------------------------\n");
}

/****************************************************************/
/* $rtn_hdr_start  READ REGISTER                                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_reg_read(cs_uint16 dev_id, cs_uint32 reg_offset)
/* INPUTS     : o Device Id                                     */
/*              o Register Offset                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Register value                                  */
/* DESCRIPTION:                                                 */
/* Reads the value from the specified register.                 */
/* Note that the register offset is the actual offset as given  */
/* in the register specification (without any shifting).        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  volatile cs_reg *drvr_reg_addr;
  cs_uint32 dev_base;
  cs_uint32 err_code = 0; /* SPLINT, benign issue fix */

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_PRINT("ERROR: Invalid dev-id(%d) - error code(0x%x)\n", dev_id, err_code);
    return (0xDEAD);
  }

  dev_base = (cs_uint32)((g_pTEN->p_dev_cb_tbl[dev_id])->base_addr);

  drvr_reg_addr = (volatile cs_reg *)(dev_base + reg_offset * sizeof(cs_reg));
  return (TEN_REG_READ(drvr_reg_addr));
}


#define T40EVB_DEBUG_TIMER_CLKPD_US (100)
#define T40EVB_DEBUG_TIMER  (0x00007)
#define FPGA_SYS_ID (432)
/****************************************************************/
/* $rtn_hdr_start  READ REGISTER MULTIPLE TIMES                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_dev_multi_reg_read(cs_uint16 dev_id, 
                                 cs_uint32 reg_write_offset,
                                 cs_uint16 reg_write_val,
                                 cs_uint32 reg_offset1, 
                                 cs_uint32 reg_offset2, 
                                 cs_uint32 reg_offset3,
                                 cs_uint16 repetitions, 
                                 cs_uint16 cr_lf)
/* INPUTS     : o Device Id                                     */
/*              o Register Write Offset                         */
/*              o Register Write Value                          */
/*              o Register Offset 1                             */
/*              o Register Offset 2                             */
/*              o Register Offset 3                             */
/*              o Repetitions                                   */
/*              o Cr_lf                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Register value                                  */
/* DESCRIPTION:                                                 */
/* First, this API writes the value 'write_reg_val' at address  */
/* 'write_reg_offset.'  Then reads the specified registers      */
/* in a loop.                                                   */
/* The count of the loop is controlled by the 'repetitions'     */
/* parameter.                                                   */
/* Up to 3 registers can be specified by 'reg_offset1',         */
/* 'reg_offset2' and 'reg_offset3'.  If only 1 or 2 registers   */
/* are needed, then use 0xFFFFFFFF to indicate an unused        */
/* parameter.  After the read loop is complete, the register    */
/* reads are displayed.                                         */
/*                                                              */
/* [reg_write_offset]  register offset for initial reg write    */
/*                                                              */
/* [reg_write_val]  register value for initial reg write        */
/*                                                              */
/* [reg_offset1]  register offset for first register to read    */
/*                                                              */
/* [reg_offset2]  register offset for second register to read   */
/*                                                              */
/* [reg_offset3]  register offset for third register to read    */
/*                                                              */
/* [repetitions]  number of times to read the registers.        */
/*                                                              */
/* [cr_lf]  whether to print reads with crlf (1) or not (0)     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii, tmp_read;
  cs_uint16 *read_list, *tmp_read_list ;
  cs_uint16 num_addr = 0;
  cs_uint32 startcntr = 0, fpgacntr = 0, elapsed_us;
  cs_uint32 err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_PRINT("ERROR: Invalid dev-id(%d) - error code(0x%x)\n", dev_id, err_code);
    return (0);
  }
  
  if (reg_offset1 != TEN_REG_ADDR_UNUSED) {
    num_addr++;
  }
  
  if (reg_offset2 != TEN_REG_ADDR_UNUSED) {
    num_addr++;
  }
  
  if (reg_offset3 != TEN_REG_ADDR_UNUSED) {
    num_addr++;
  }
  
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;  
  
  read_list = (cs_uint16 *)CS_MALLOC(sizeof(cs_uint16) * repetitions * num_addr);
  if (read_list) {
    tmp_read_list = read_list;
    
    /*  FPGA counter counts by 100us        */
    elapsed_us = 0;
    

    if (reg_write_offset != TEN_REG_ADDR_UNUSED) {
       ten_reg_write(dev_id, reg_write_offset, reg_write_val);
    }

    for (ii=0; ii<repetitions; ii++) {
      if (reg_offset1 != TEN_REG_ADDR_UNUSED) {
        *tmp_read_list++ = ten_reg_read(dev_id, reg_offset1);
      }
     
      if (reg_offset2 != TEN_REG_ADDR_UNUSED) {
        *tmp_read_list++ = ten_reg_read(dev_id, reg_offset2);
      }
      
      if (reg_offset3 != TEN_REG_ADDR_UNUSED) {
        *tmp_read_list++ = ten_reg_read(dev_id, reg_offset3);
      }
    }
    

    if (fpgacntr < startcntr) {
      /* cntr has rolled over, so add max cnt (65536) */
      fpgacntr += 1 << 16;
    }
    elapsed_us = ((fpgacntr - startcntr) * T40EVB_DEBUG_TIMER_CLKPD_US);  
    
    g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;

    tmp_read_list = read_list;
    for (ii=0; ii<repetitions; ii++) {
      if (reg_offset1 != TEN_REG_ADDR_UNUSED) {
        tmp_read = *tmp_read_list++;
        CS_PRINT_OUTPUT("%5d:  0x%05X = 0x%04X%c%c", ii, reg_offset1, tmp_read, 
                         cr_lf ? 0x0D : 0x20, cr_lf ? 0x0A : 0x20);
      }
     
      if (reg_offset2 != TEN_REG_ADDR_UNUSED) {
        tmp_read = *tmp_read_list++;
        CS_PRINT_OUTPUT("%5d:  0x%05X = 0x%04X%c%c", ii, reg_offset2, tmp_read,
                         cr_lf ? 0x0D : 0x20, cr_lf ? 0x0A : 0x20);

      }
      
      if (reg_offset3 != TEN_REG_ADDR_UNUSED) {
        tmp_read = *tmp_read_list++;
        CS_PRINT_OUTPUT("%5d:  0x%05X = 0x%04X%c%c", ii, reg_offset3, tmp_read,
                         cr_lf ? 0x0D : 0x20, cr_lf ? 0x0A : 0x20);

      }
    }
    CS_FREE(read_list);
    
    CS_PRINT_OUTPUT("Starting count of fpga_counter = %d\n", startcntr);  
    CS_PRINT_OUTPUT("Ending count of fpga_counter   = %d\n", fpgacntr); 
    CS_PRINT_OUTPUT("Elapsed time (microseconds)    = %d\n", elapsed_us); 
  }
  else 
  {
    CS_PRINT_OUTPUT("Out of memory.\n");  
  }
  return (CS_OK);
}



/****************************************************************/
/* $rtn_hdr_start  WRITE REGISTER                               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_reg_write(cs_uint16 dev_id, cs_uint32 reg_offset, cs_uint16 data)
/* INPUTS     : o Device Id                                     */
/*              o Register Offset                               */
/*              o Write Value                                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Writes the specified value into the register.                */
/* Note that the register offset is the actual offset as given  */
/* in the register specification (without any shifting).        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  volatile cs_reg *drvr_reg_addr;
  cs_uint32 dev_base;
  cs_uint32 err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_PRINT("ERROR: Invalid dev-id(%d) - error code(0x%x)\n", dev_id, err_code);
    return (CS_ERROR);
  }

  dev_base = (cs_uint32)((g_pTEN->p_dev_cb_tbl[dev_id])->base_addr);

  drvr_reg_addr = (volatile cs_reg *)(dev_base + reg_offset * sizeof(cs_reg));
  TEN_REG_WRITE(drvr_reg_addr, data);
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  DEVICE INITIALIZATION                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_main_init(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* This API is the main entry point to configure the device     */
/* software.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status status = CS_OK;

  CS_PRINT("ten_dev_main_init\n");

  if (!(TEN_DRVR_IS_LOADED())) {
    CS_HNDL_ERROR(dev_id, ETEN_DRVR_NOT_LOADED, NULL);
    return (CS_ERROR);
  }

  if (dev_id >= TEN_MAX_NUM_DEVICES) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_ID_OUT_OF_RANGE, NULL);
    return (CS_ERROR);
  }

  /* Initialize hardware */
  if (ten_dev_init(dev_id) != CS_OK) {
    status = CS_ERROR;
  }
  return (status);
}

/****************************************************************/
/* $rtn_hdr_start  MODULE INITIALIZATION                        */
/* CATEGORY   : Module                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_mod_main_init(cs_uint16 dev_id, cs_uint8 mod_num)
/* INPUTS     : o Device Id                                     */
/*              o Num                                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Module-Id (module handle)                       */
/* DESCRIPTION:                                                 */
/* This API is the main entry point to configure the module     */
/* software.                                                    */
/*                                                              */
/* Note:  This API takes dev_id as parameter and on successful  */
/* completion creates a module-handle (or module_id).  All      */
/* subsequent API calls for module software will use this       */
/* returned handle and a slice number to reference the 10G/40G  */
/* instances.                                                   */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   TEN_MODULE_A (0) or TEN_MODULE_B. (1)                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 mod_id = TEN_INVALID_MODULE_ID;
  cs_uint32 err_code = 0;
  cs_status status   = CS_OK;

  CS_PRINT("ten_mod_main_init\n");
  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_HNDL_ERROR(dev_id, err_code, NULL);
    return (mod_id);
  }

  if (mod_num >= TEN_MAX_NUM_MODULES) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": mod_num(%d) > 0!\n");
    return (mod_id);
  }

  mod_id = ten_mod_open(dev_id, mod_num);
  if (mod_id == TEN_INVALID_MODULE_ID) {
    status = CS_ERROR;
    goto RTN_EXIT;
  }

  CS_PRINT("Module-0x%04X: Init Module\n", mod_id);

  if (ten_mod_init(mod_id) != CS_OK) {
    CS_PRINT("ERROR during port initialization\n");
    ten_mod_close(mod_id);
    status = CS_ERROR;
    goto RTN_EXIT;
  }

RTN_EXIT:
  if (status == CS_OK) {
    CS_PRINT("Tenabo initialization done (Module-Id is 0x%04X)\n", mod_id);
  }
  return (mod_id);
}


/****************************************************************/
/* $rtn_hdr_start  DUMP DRIVER CONTROL BLOCK                    */
/* CATEGORY   : Driver                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_drvr_dump_cb( void )
/* INPUTS     : ----                                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Dumps the Driver Control Block (provided for debugging       */
/* purposes).                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint32 ii;
  cs_uint16 print_cntr = 0;

  CS_PRINT("ten_mod_main_init\n");

  if (TEN_DRVR_IS_LOADED()) {
    CS_PRINT_OUTPUT("\n");
    cs_bar();
    CS_PRINT_OUTPUT("Tenabo Driver Control Block\n");
    cs_bar();

    CS_PRINT_OUTPUT("drvr_loaded   = %s\n", (g_pTEN->drvr_loaded) ? "Y" : "N");
    CS_PRINT_OUTPUT("drvr @        = %p\n", g_pTEN);
    CS_PRINT_OUTPUT("drvr_flag     = 0x%04X\n", g_pTEN->drvr_flag);
    for (ii = 0; ii < TEN_MAX_NUM_DEVICES; ii++) {
      if (g_pTEN->p_dev_cb_tbl[ii]) {
        print_cntr++;
        CS_PRINT_OUTPUT("dev_cb[%02d] @  = 0x%08X\n", ii, (cs_uint32) g_pTEN->p_dev_cb_tbl[ii]);
      }
    }

    if (print_cntr == 0)
      CS_PRINT_OUTPUT("No valid devices!\n");

    cs_bar();
  }
}

/****************************************************************/
/* $rtn_hdr_start  DUMP DEVICE CONTROL BLOCK                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_dev_dump_cb(cs_uint16 dev_id)
/* INPUTS     : o Device Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Dumps the Device Control Block (provided for debugging       */
/* purposes).                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_dev_cb_t *pdevcb;
  cs_uint32     err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_PRINT("ERROR: Dev-Id (%d) is invalid!\n", dev_id);
    return;
  }

  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);

  cs_bar();
  CS_PRINT_OUTPUT("Tenabo     Device Control Block\n");
  cs_bar();
  if (pdevcb)
  {
    CS_PRINT_OUTPUT("dev id      = %d\n", pdevcb->dev_id);
    CS_PRINT_OUTPUT("dev cb @    = %p\n", pdevcb);
    CS_PRINT_OUTPUT("base addr   = 0x%X\n", pdevcb->base_addr);
    CS_PRINT_OUTPUT("dev cb size = 0x%X bytes\n", sizeof(ten_dev_cb_t));
    CS_PRINT_OUTPUT("chip_type   = 0x%X\n", pdevcb->chip_type);
    CS_PRINT_OUTPUT("state       = ");
    if (pdevcb->state == 0)
      CS_PRINT_OUTPUT("invalid\n");
    else if (pdevcb->state == 1)
      CS_PRINT_OUTPUT("registered\n");
    else if (pdevcb->state == 2)
      CS_PRINT_OUTPUT("initialized\n");
    CS_PRINT_OUTPUT("sysclk freq = %d\n", pdevcb->sysclock);
    CS_PRINT_OUTPUT("debug flag  = 0x%X\n", pdevcb->debug_flag);

    CS_PRINT_OUTPUT("pcb ptr array @   = %p\n", pdevcb->ppcb);
    CS_PRINT_OUTPUT("statistics cb @   = %p\n", pdevcb->stats_cb);
    CS_PRINT_OUTPUT("semaphore mpif    = %p\n", pdevcb->sem_mpif);
    CS_PRINT_OUTPUT("semaphore glb     = %p\n", pdevcb->sem_glb);
    CS_PRINT_OUTPUT("semaphore xcon    = %p\n", pdevcb->sem_xcon);
    CS_PRINT_OUTPUT("semaphore fracdiv = %p\n", pdevcb->sem_fracdiv);
    CS_PRINT_OUTPUT("semaphore gpllx1  = %p\n", pdevcb->sem_gpllx1);
    CS_PRINT_OUTPUT("semaphore irq     = %p\n", pdevcb->sem_irq);
    CS_PRINT_OUTPUT("semaphore pdcal   = %p\n", pdevcb->sem_pdcal);
    CS_PRINT_OUTPUT("semaphore dm       = %p\n", pdevcb->sem_dm);

    ten_xcon_es_dump_cb(pdevcb->es_cb);
    ten_mpif_dump_cb(&(pdevcb->mpif));
  }
  cs_bar();
}

/****************************************************************/
/* $rtn_hdr_start  DUMP MODULE CONTROL BLOCK                    */
/* CATEGORY   : Module                                          */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_mod_dump_cb(cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Dumps the Module Control Block (MCB) and is provided for     */
/* debugging purposes.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  ten_mod_cb_t *ppcb;
  cs_uint32     err_code = 0;

  if (!(TEN_IS_MOD_VALID(module_id, &err_code))) {
    CS_PRINT("ERROR: API   -Id (0x%x) is invalid!\n", module_id);
    return;
  }

  ppcb = TEN_MOD_ID_TO_PCB_PTR(module_id);

  cs_bar();
  CS_PRINT_OUTPUT("Tenabo     Module Control Block\n");
  cs_bar();

  if (ppcb)
  {
    CS_PRINT_OUTPUT("module id      = 0x%X\n", ppcb->mod_id, ppcb, sizeof(ten_mod_cb_t));
    CS_PRINT_OUTPUT("module cb @    = %p\n", ppcb);
    CS_PRINT_OUTPUT("module cb size = 0x%X bytes\n", sizeof(ten_mod_cb_t));

    CS_PRINT_OUTPUT("state        = ");
    if (ppcb->state == 0)
      CS_PRINT_OUTPUT("invalid\n");
    else if (ppcb->state == 1)
      CS_PRINT_OUTPUT("opened\n");
    else if (ppcb->state == 2)
      CS_PRINT_OUTPUT("data initialized\n");
    else if (ppcb->state == 3)
      CS_PRINT_OUTPUT("hw initialized\n");

    CS_PRINT_OUTPUT("stat cb     @    = %p\n", ppcb->stats_cb);
    CS_PRINT_OUTPUT("semaphore syncdsync   = %p\n", ppcb->sem_syncdsync);
    CS_PRINT_OUTPUT("semaphore spoh        = %p\n", ppcb->sem_spoh);
    CS_PRINT_OUTPUT("semaphore hsif        = %p\n", ppcb->sem_hsif);
    CS_PRINT_OUTPUT("semaphore xfi32x1     = %p\n", ppcb->sem_xfi32x1);
    CS_PRINT_OUTPUT("semaphore n40g        = %p\n", ppcb->sem_n40g);
    CS_PRINT_OUTPUT("semaphore ohpp        = %p\n", ppcb->sem_ohpp);
    CS_PRINT_OUTPUT("semaphore n10g        = %p\n", ppcb->sem_n10g);
    CS_PRINT_OUTPUT("semaphore pp10g       = %p\n", ppcb->sem_pp10g);
    CS_PRINT_OUTPUT("semaphore gfec10g     = %p\n", ppcb->sem_gfec10g);
    CS_PRINT_OUTPUT("semaphore gfec40g     = %p\n", ppcb->sem_gfec40g);
    CS_PRINT_OUTPUT("semaphore ufec        = %p\n", ppcb->sem_ufec);
  }
  cs_bar();
}

struct {
  cs_uint32 start_addr;
  cs_uint32 end_addr;
} ten_reg_dump_table[] = {
  {0x0000, 0x0032},
  {0x1000, 0x122B},
  {0x0000, 0x0000} }; /* use 0x0000 and 0x0000 to end table */

#if 0
/****************************************************************/
/* DUMP CS600X REGISTERS                                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_reg_dump(cs_uint16 dev_id, cs_uint8 dump)
/* INPUTS     : o Dev Id                                        */
/*              o Dump Type                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Dumps all of the CS600X registers and is provided mainly     */
/* for debugging purposes.                                      */
/*                                                              */
/* The [dump] parameter is specified as:                        */
/*   (0) = Full Register Dump,                                  */
/*   (1) = Configuration Registers.                             */
/*                                                              */
/****************************************************************/
{
  volatile cs_reg *drvr_reg_addr;
  cs_uint32 dev_base;
  cs_uint32 reg_offset;
  cs_uint32 reg_val;
  cs_uint32 ii;
  cs_uint32 err_code = 0;

  CS_PRINT_OUTPUT("ten_reg_dump =%d\n", dump);;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_PRINT_OUTPUT("ERROR: Invalid dev-id(%d) - error code(0x%x)\n",
                     dev_id, err_code);
    return;
  }
  dev_base = (cs_uint32)((g_pTEN->p_dev_cb_tbl[dev_id])->base_addr);

  ii = 0;
  for (;;) {
    if ((ten_reg_dump_table[ii].start_addr == 0)
        && (ten_reg_dump_table[ii].end_addr == 0)) {
      break;
    }
    else {
      reg_offset = ten_reg_dump_table[ii].start_addr;
      do {
        drvr_reg_addr = (volatile cs_reg *)(dev_base + reg_offset * sizeof(cs_reg));
        reg_val = TEN_REG_READ(drvr_reg_addr);
        g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
        CS_PRINT_OUTPUT("%05X = %04X\n", reg_offset, reg_val);
        g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
      } while (reg_offset++ != ten_reg_dump_table[ii].end_addr);
    }
    ii++;
  }
}
#endif

/****************************************************************/
/* $rtn_hdr_start  DUMP A RANGE OF REGISTERS                    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_reg_dump_range(cs_uint16 dev_id, cs_uint32 start_addr,
                        cs_uint32 end_addr)
/* INPUTS     : o Dev Id                                        */
/*              o Start Addr                                    */
/*              o End Addr                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/* Dumps a range of registers and is provided mainly            */
/* for debugging purposes.                                      */
/*                                                              */
/* [start_addr]  32 bit address for the start of the range.     */
/*                                                              */
/* [end_addr]  32 bit address for the end of the range.         */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  volatile cs_reg *drvr_reg_addr;
  cs_uint32 dev_base;
  cs_uint32 reg_val;
  cs_uint32 ii;
  cs_uint32 err_code = 0;

  if (!(TEN_IS_DEVICE_VALID(dev_id, &err_code))) {
    CS_PRINT_OUTPUT("ERROR: Invalid dev-id(%d) - error code(0x%X)\n",
                     dev_id, err_code);
    return;
  }
  
  dev_base = (cs_uint32)((g_pTEN->p_dev_cb_tbl[dev_id])->base_addr);

  for (ii=start_addr; ii<=end_addr; ii++) {
    drvr_reg_addr = (volatile cs_reg *)(dev_base + ii * sizeof(cs_reg));
    g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;
    reg_val = TEN_REG_READ(drvr_reg_addr);
    g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
    CS_PRINT_OUTPUT("RD: 0x%05X = 0x%04X\n", ii, reg_val);
  }
}

/*********************************************************************
 * DELAY UTILITY FOR SIMULATION                                      *
 * When running in RTL simulation, the delay needed should be        *
 * corresponding to the sim cycles and not to the cpu cycles in sim. *
 * For example, when doing sw initiated hard reset, we want to       *
 * make sure that the reset pulse is asserted long enough in terms   *
 * of simulation time.                                               *
 * Currently, this delay needed for simulation is implemented by     *
 * doing repeated reads of the jtag-id from the chip. The            *
 * numbers used are just arbitrary estimates.                        *
 *********************************************************************/
void ten_sim_delay(cs_boolean is_in_msec, cs_uint32 delay)
{
  volatile cs_uint32 jtag_id;
  cs_uint16 ii, loop_cnt;
  cs_uint16 dev_id = 0;

  CS_PRINT_DELAYS("ten_sim_delay = %d ms (is_in_msec=%d)\n", delay, is_in_msec);
  g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;

  if (is_in_msec) {
    loop_cnt = 3 + (delay / 10);
  }
  else {
    loop_cnt = 1;
  }

  for (ii = 0; ii < loop_cnt; ii++) {
     jtag_id = ten_mpif_get_chip_jtag_id(dev_id); 
  }
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND;
}

/****************************************************************
 * Perform a reset action on the specified register.            *
 ****************************************************************/
void ten_reset_action(volatile cs_reg *rst_reg, cs_uint16 bits,
                      cs_reset_action_t act)
{
  cs_uint16 rst;
  rst = TEN_REG_READ(rst_reg);

  switch (act) {
  case CS_RESET_DEASSERT:
    rst &= ~bits;
    break;

  case CS_RESET_ASSERT:
    rst |= bits;
    break;

  case CS_RESET_TOGGLE:
    rst |= bits;
    TEN_REG_WRITE(rst_reg, rst);
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
    rst &= ~bits;
    break;
  }
  TEN_REG_WRITE(rst_reg, rst);

  if (act != CS_RESET_ASSERT) {
    TEN_MDELAY(TEN_HRESET_MSEC_DELAY);
  }
}

/****************************************************************
 * Clock disable for the specified register.                    *
 ****************************************************************/
void ten_clock_disable(volatile cs_reg *rst_reg, cs_uint16 bits, cs_ctl_t ctl)
{
  cs_uint16 clk;
  clk = TEN_REG_READ(rst_reg);

  switch (ctl) {
  case CS_ENABLE:
    clk &= ~bits;
    break;

  case CS_DISABLE:
    clk |= bits;
    break;
  }
  TEN_REG_WRITE(rst_reg, clk);
}

/****************************************************************/
/* $rtn_hdr_start  PRINT TO SCREEN                              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_print(const cs_char8 *s)
/* INPUTS     : o The string to print                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Register value                                  */
/* DESCRIPTION:                                                 */
/* Prints a string to the console.                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_char8 buffer[CS_PRINT_BUFFER_SIZE - 1];

  if (s) {
    strncpy(buffer, s, CS_PRINT_BUFFER_SIZE - 1);
    buffer[CS_PRINT_BUFFER_SIZE - 2] = 0;
    CS_PRINT("%s\n", buffer);
  }
  else {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG, ": null ptr.");
  }
}

/****************************************************************/
/* $rtn_hdr_start  GET LAST STRING LENGTH                       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_drvr_get_last_str_len( void )
/* INPUTS     : ----                                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Length                                          */
/* DESCRIPTION:                                                 */
/* Gets the length of the last string dumped using              */
/* ten_string_dump and resets the pointer to the beginning,     */
/* in preparation for calling ten_get_last_str_len and          */
/* ten_get_last_str_char to retrieve the string in APISH.       */
/* This is mainly for debugging purposes to provide a simple    */
/* method of copying strings from the driver to APISH.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  if (TEN_DRVR_IS_LOADED()) {
    g_pTEN->drvr_last_str_idx = 0;
    return (g_pTEN->drvr_last_str_len);
  }
  else {
    g_pTEN->drvr_last_str_idx = 0;
    g_pTEN->drvr_last_str_len = 0;
    return (0);
  }
}

/****************************************************************/
/* $rtn_hdr_start  GET LAST STRING CHAR                         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_int16 ten_drvr_get_last_str_char( void )
/* INPUTS     : ----                                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    :  Character of Last String                       */
/* DESCRIPTION:                                                 */
/* Returns a character from the last string and increments      */
/* current index for next character.                            */
/* This is mainly for debugging purposes to provide a simple    */
/* method of copying strings from the driver to APISH.          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_char8 tmp_char = 0;
  
  if (TEN_DRVR_IS_LOADED()) {
    if (g_pTEN->drvr_last_str_idx >= g_pTEN->drvr_last_str_len) {
      tmp_char = 0;
    }
    else {
      tmp_char = g_pTEN->drvr_last_str[g_pTEN->drvr_last_str_idx];
      g_pTEN->drvr_last_str_idx++;
    }
  }  
  return (((cs_int16)tmp_char)&0xFF); /* don't sign extend */
}

/****************************************************************/
/* $rtn_hdr_start  STRING DUMP                                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void ten_drvr_str_dump(cs_char8 *dbg_str, cs_uint16 str_size)
/* INPUTS     : o Debug String                                  */
/*              o Debug String Size                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Register value                                  */
/* DESCRIPTION:                                                 */
/* Dumps a debug string to the console, and saves the results   */
/* in the driver's control block, for later extraction with     */
/* APIs ten_drvr_get_last_str_len and                           */
/* ten_drvr_get_last_str_char.                                  */
/* This is mainly for debugging purposes.                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  /* Bugzilla #23881, seg faults fixed, if over size is passed in */
  cs_uint16 ii = 0;
  cs_uint16 cnt = 0;

  if (!TEN_DRVR_IS_LOADED()) {
     return;
  }   
  
  if (str_size <= TEN_DEBUG_BUFFER_SIZE) {
    g_pTEN->drvr_last_str_len = str_size;
  }
  else {
    g_pTEN->drvr_last_str_len = TEN_DEBUG_BUFFER_SIZE;
  }
  g_pTEN->drvr_last_str_idx = 0;
  
  if (dbg_str) {
    for (ii=0; ii<str_size; ii++) {
      if (ii < TEN_DEBUG_BUFFER_SIZE) {
        g_pTEN->drvr_last_str[ii] = dbg_str[ii];
      if ((dbg_str[ii]>= 0x20) && (dbg_str[ii] <= 0x7E)) {
        CS_PRINT_OUTPUT("%c", dbg_str[ii]);
      }
      else {
        CS_PRINT_OUTPUT(".");
      }
    }
    }
    CS_PRINT_OUTPUT("\nHEX:\n");
    
    for (ii=0; ii<str_size; ii++) {
      if (ii < TEN_DEBUG_BUFFER_SIZE) {
      CS_PRINT_OUTPUT("%02X ", (dbg_str[ii] & 0xFF));
      if (++cnt == 16) {
        CS_PRINT_OUTPUT("\n");
        cnt = 0;
      }
    }
    }
    CS_PRINT_OUTPUT("\n");
  }  
}

/****************************************************************/
/* $rtn_hdr_start  PRINT BUS ERROR INFORMATION                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_print_bus_error_info(cs_uint16 dev_id)
/* INPUTS     : o Dev Id                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Prints bus error information. This is provided mainly for    */
/* debugging purposes.                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_MPIF_MPIF_INTERRUPT_t tmp_mpif_interrupt;
  TEN_MPIF_TIMEOUT_ADDRESS0_t tmp_timeout_address0;
  TEN_MPIF_TIMEOUT_ADDRESS1_t tmp_timeout_address1;
  TEN_MPIF_TIMEOUT_TRANSACTION_t tmp_timeout_transaction;
  cs_uint16 buserr;
  cs_status rtn  = CS_OK;
  T41_t    *pDev = NULL;

  if (!TEN_DRVR_IS_LOADED()) {
     return (CS_ERROR);
  }  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_timeout_transaction.wrd = 0;  /* SPINT, benign issue fix (3 lines) */
  tmp_timeout_address0.wrd    = 0;
  tmp_timeout_address1.wrd    = 0;

  TEN_DEV_LOCK(dev_id, TEN_ID_MPIF);

  tmp_mpif_interrupt.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, MPIF_INTERRUPT));
  buserr = tmp_mpif_interrupt.bf.buserri;
  
  if (buserr) {
    tmp_timeout_address0.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TIMEOUT_ADDRESS0));
    tmp_timeout_address1.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TIMEOUT_ADDRESS1));
    tmp_timeout_transaction.wrd = TEN_REG_READ(TEN_MPIF_REG_ADDR(pDev, TIMEOUT_TRANSACTION));
    tmp_mpif_interrupt.bf.buserri = 1; /* RW1C */
    TEN_REG_WRITE(TEN_MPIF_REG_ADDR(pDev, MPIF_INTERRUPT), tmp_mpif_interrupt.wrd);
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_MPIF);

  CS_PRINT_OUTPUT("Bus Error = %d\n", buserr);
  if (buserr) {
    rtn = CS_ERROR;
    CS_PRINT_OUTPUT("rwn       = %d\n", tmp_timeout_transaction.bf.rwn);
    CS_PRINT_OUTPUT("address   = 0x%04X%04X\n", tmp_timeout_address0.bf.address, 
                    tmp_timeout_address1.bf.address);
  }
  return (rtn);
}

/* Bugilla #26434 */
/****************************************************************/
/* $rtn_hdr_start  CLEAR BUS ERROR COUNT                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_clear_bus_error_count(cs_uint16 dev_id)
/* INPUTS     : o Dev Id                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Clears total bus errors. Also cleared in last ten_dev_init   */
/* call.  This is provided mainly for debugging purposes.       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;

  if (!TEN_DRVR_IS_LOADED()) {
     return (CS_ERROR);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  
  g_pTEN->ten_bus_error_count = 0;
  return (CS_OK);
}

/* Bugilla #26434 */
/****************************************************************/
/* $rtn_hdr_start  GET BUS ERROR COUNT                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_uint16 ten_dev_get_bus_error_count(cs_uint16 dev_id)
/* INPUTS     : o Dev Id                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : Count                                           */
/* DESCRIPTION:                                                 */
/* Returns total bus errors since last ten_dev_init call.       */
/* This is provided mainly for debugging purposes.              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;

  if (!TEN_DRVR_IS_LOADED()) {
     return (0);
  }
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);

  return (g_pTEN->ten_bus_error_count);
}

/* Bugilla #26434 */
/****************************************************************/
/* $rtn_hdr_start  SET BUS ERROR CHECK                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
cs_status ten_dev_set_bus_error_check(cs_uint16 dev_id, cs_ctl_t ctl)
/* INPUTS     : o Dev Id                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Returns total bus errors since last ten_dev_init call.       */
/* This is provided mainly for debugging purposes.              */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   CS_DISABLE (0) or CS_ENABLE (1)                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;

  if (!TEN_DRVR_IS_LOADED()) {
     return (CS_ERROR);
  }
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  if (ctl == CS_DISABLE) {
    g_pTEN->ten_bus_error_ctl = CS_DISABLE;
  }
  else {
    g_pTEN->ten_bus_error_ctl = CS_ENABLE;
  }
  return (CS_OK);
}

/****************************************************************
 * Print/Debug utility                                          *
 * This can be customized as needed by the user.                *
 ****************************************************************/
/* Bugzilla #18781                            */
/* Allow more control over debugging messages */

/* private, common print routine called by       */
/* CS_PRINT, CS_PRINT_ERRRORS, CS_PRINT_DELAYS   */
/* CS_PRINT_OUTPUT                               */
static void CS_COMMON_PRINT(cs_char8 *log_str) 
{
  #ifndef __CS_DONT_PRINT__

  #ifndef RELEASE_PLATFORM
  /* print to client window */
  cs_trans_cb_client_dump(log_str);
  #endif
   
  /* Bugzilla #28788, support compiler option CS_DONT_USE_STDLIB */
  #ifndef CS_DONT_USE_STDLIB
  /* print to stdout */
  /* Bug #38685 - fix compiler warnings. */
  JUST_LOG_1(LOG_INFO, "T41", "%s", log_str);
  printf("\tT41: %s", log_str);
  
  /* print to log file */
  if (g_pTEN) {
    if ((g_pTEN->drvr_loaded) && (g_pTEN->drvr_out_fp)) {
      /* Bug #38685 - fix compiler warnings. */
      fprintf(g_pTEN->drvr_out_fp, "%s", log_str);
      fflush(g_pTEN->drvr_out_fp);
    }
  }
  #endif
  #endif
}

/* print the output of commands, like stats */
/* with no filtering (ie, not a debug msg)  */
void CS_PRINT_OUTPUT(cs_char8 *fmt, ...) 
{
  #ifndef __CS_DONT_PRINT__
  
  va_list VarArg;
  cs_char8 log_str[CS_PRINT_BUFFER_SIZE];
 
  va_start(VarArg, fmt);
  #ifdef CS_DONT_HAVE_VSNPRINTF
  vsprintf(log_str, fmt, VarArg);
  #else
  vsnprintf(log_str, sizeof(log_str), fmt, VarArg);
  #endif
  va_end(VarArg);

  log_str[CS_PRINT_BUFFER_SIZE - 1] = 0;
  CS_COMMON_PRINT(log_str);
  #endif
}


/* Bugzilla #18781, allow more control over debugging messages */
void CS_PRINT_DELAYS(cs_char8 *fmt, ...) 
{
  #ifndef __CS_DONT_PRINT__
  va_list VarArg;
  cs_char8 log_str[CS_PRINT_BUFFER_SIZE];
 
  if (g_pTEN) {
    if (g_pTEN->drvr_flag & (TEN_DRVR_LOG_ALL | 
        TEN_DRVR_LOG_DELAYS_AND_ERRORS | TEN_DRVR_LOG_DELAYS_ONLY)) {
      va_start(VarArg, fmt);
      #ifdef CS_DONT_HAVE_VSNPRINTF
      vsprintf(log_str, fmt, VarArg);
      #else
      vsnprintf(log_str, sizeof(log_str), fmt, VarArg);
      #endif
      va_end(VarArg);

      log_str[CS_PRINT_BUFFER_SIZE - 1] = 0;
      
      if (g_pTEN) {
        if (g_pTEN->drvr_flag & (TEN_DRVR_LOG_ALL | 
              TEN_DRVR_LOG_DELAYS_AND_ERRORS | TEN_DRVR_LOG_DELAYS_ONLY)) {
          CS_COMMON_PRINT(log_str);
        }
      }
    }
  }
  #endif
}

/* Bugzilla #18781, allow more control over debugging messages */
void CS_PRINT_ERRORS(cs_char8 *fmt, ...) 
{
  #ifndef __CS_DONT_PRINT__

  va_list VarArg;
  cs_char8 log_str[CS_PRINT_BUFFER_SIZE];
  
  if (g_pTEN) {
    if (g_pTEN->drvr_flag & (TEN_DRVR_LOG_ALL | 
        TEN_DRVR_LOG_DELAYS_AND_ERRORS | TEN_DRVR_LOG_ERRORS_ONLY)) {
          
    va_start(VarArg, fmt);
    #ifdef CS_DONT_HAVE_VSNPRINTF
    vsprintf(log_str, fmt, VarArg);
    #else
    vsnprintf(log_str, sizeof(log_str), fmt, VarArg);
    #endif
    va_end(VarArg);

    log_str[CS_PRINT_BUFFER_SIZE - 1] = 0;
    
      if (g_pTEN) {
        if (g_pTEN->drvr_flag & (TEN_DRVR_LOG_ALL | 
              TEN_DRVR_LOG_DELAYS_AND_ERRORS | TEN_DRVR_LOG_ERRORS_ONLY)) {
          CS_COMMON_PRINT(log_str);
        }
      }
    }
  }
  #endif
}

void CS_PRINT(cs_char8 *fmt, ...) 
{
  #ifndef __CS_DONT_PRINT__

  va_list VarArg;
  cs_char8 log_str[CS_PRINT_BUFFER_SIZE];
  
  if (g_pTEN) {
    if ((g_pTEN->drvr_flag & TEN_DRVR_LOG_ALL)) {
    
    if ((g_pTEN->drvr_flag & TEN_DRVR_LOG_SUSPEND)) {
      return;
    }
 
    va_start(VarArg, fmt);
    #ifdef CS_DONT_HAVE_VSNPRINTF
    vsprintf(log_str, fmt, VarArg);
    #else
    vsnprintf(log_str, sizeof(log_str), fmt, VarArg);
    #endif
    va_end(VarArg);

    log_str[CS_PRINT_BUFFER_SIZE - 1] = 0;
      
      if (g_pTEN) {
        if ((g_pTEN->drvr_flag & TEN_DRVR_LOG_ALL)) {
          /* logging disabled */      
          CS_COMMON_PRINT(log_str);
        }
      }
    }
  }
  #endif
}



/****************************************************************/
/* $rtn_hdr_start  DEBUG REGISTER WRITE TRACE                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : GENERAL                                         */
/* CHIP       : Tenabo                                          */
void   ten_debug_reg_write_trace(cs_uint16 dev_id,
                                 cs_uint8  trc_id,
                                 cs_uint32 offset)
/* INPUTS     : o DEV ID                                        */
/*              O TRACE ID                                      */
/*              O REGISTER OFFSET                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : ----                                            */
/* DESCRIPTION:                                                 */
/*  Debug facility to capture writes to up to 8 specified       */
/*  register offsets per device. Use this to provide a flagged  */
/*  output of writes to specific register offsets, or to set    */
/*  gdb breakpoints on those writes.                            */  
/*                                                              */
/* The [dev_id] parameter is specified as:                      */
/*   0..2 (only 3 devices supported for now).                   */
/* The [trc_id] parameter is specified as:                      */
/*   0..7 = a trace ID                                          */
/*   0xCC = TEN_DEBUG_REG_WR_TR_ACTN_CLR_ALL, clear all         */
/*   0xDD = TEN_DEBUG_REG_WR_TR_ACTN_DISABLE, disable all       */
/*   0xEE = TEN_DEBUG_REG_WR_TR_ACTN_ENABLE,  enable all        */
/*   0xFF = TEN_DEBUG_REG_WR_TR_ACTN_DISPLAY, display all       */
/* The [offset] parameter is specified as:                      */
/*   A register offset, as from t41_registers.h or equiv't.     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_char8 *func = "ten_debug_reg_write_trace";
  
  if (dev_id > 2) {
    CS_PRINT_OUTPUT("%s(dev_id=%d), invalid device id\n", func, dev_id);
    return;
  }
  switch (trc_id) {
    case TEN_DEBUG_REG_WR_TR_ACTN_DISPLAY :
      break;
    case TEN_DEBUG_REG_WR_TR_ACTN_CLR_ALL :                                /* clear all and mark uninitialized */
      ten_debug_reg_write_trc_st[dev_id] = 0;  /* Device's trace state is uninitialized. */
      for (ii=0; ii<8; ii++) {
        ten_debug_reg_write_trcpnt[dev_id][ii] = 0xDEADBEEF;
      }
      break;
    case TEN_DEBUG_REG_WR_TR_ACTN_DISABLE :                                /* Disable trace points */
      switch (ten_debug_reg_write_trc_st[dev_id]) {
        case TEN_DEBUG_REG_WR_TR_STATE_DISABLE :
          break;
        case TEN_DEBUG_REG_WR_TR_STATE_ENABLE :
          ten_debug_reg_write_trc_st[dev_id] = TEN_DEBUG_REG_WR_TR_STATE_DISABLE;  /* disable */
          break;
        default :
          CS_PRINT_OUTPUT("%s(dev_id=%d), Invalid request, no register offsets are defined.\n", func, dev_id);
          break;
      }
      break;
    case TEN_DEBUG_REG_WR_TR_ACTN_ENABLE :
      switch (ten_debug_reg_write_trc_st[dev_id]) {
        case TEN_DEBUG_REG_WR_TR_STATE_DISABLE :
          ten_debug_reg_write_trc_st[dev_id] = TEN_DEBUG_REG_WR_TR_STATE_ENABLE;  /* enable */
          break;
        case TEN_DEBUG_REG_WR_TR_STATE_ENABLE :
          break;
        default :
          CS_PRINT_OUTPUT("%s(dev_id=%d), Invalid request, no register offsets are defined.\n", func, dev_id);
          break;
      }
      break;
    default :
      if (trc_id >= 8) {
        CS_PRINT_OUTPUT("%s(dev_id=%d), invalid offset id %d. Valid: 0-7, 0xCC (clear all), 0xDD (disable all)" \
                        ", 0xEE (Enable all), 0xFF (Display all)\n", func, dev_id, trc_id);
      }
      else {
        /* initialze the tracepoint structure if not initialized */
        if ( (ten_debug_reg_write_trc_st[dev_id] != TEN_DEBUG_REG_WR_TR_STATE_DISABLE) && 
             (ten_debug_reg_write_trc_st[dev_id] != TEN_DEBUG_REG_WR_TR_STATE_ENABLE)) {
          for (ii=0; ii<8; ii++) {
            ten_debug_reg_write_trcpnt[dev_id][ii] = 0xDEADBEEF;
          }
          ten_debug_reg_write_trc_st[dev_id] = TEN_DEBUG_REG_WR_TR_STATE_ENABLE;
        }
        ten_debug_reg_write_trcpnt[dev_id][trc_id] = offset;
      }
      break;
  }
  
  /* display register write tracepoints */
  CS_PRINT_OUTPUT("Register write tracepoints for dev_id=%d:\n", dev_id);
  switch (ten_debug_reg_write_trc_st[dev_id]) {
    case TEN_DEBUG_REG_WR_TR_STATE_DISABLE :
    case TEN_DEBUG_REG_WR_TR_STATE_ENABLE :
      CS_PRINT_OUTPUT("  trc_id    offset  (%s)\n", 
                      (ten_debug_reg_write_trc_st[dev_id]==TEN_DEBUG_REG_WR_TR_STATE_ENABLE) ? "Enabled" : "Disabled" );
      for (ii=0; ii<8; ii++) {
        if (ten_debug_reg_write_trcpnt[dev_id][ii] != 0xDEADBEEF) {
          CS_PRINT_OUTPUT("  %4d-%d  0x%06X\n", dev_id, ii, ten_debug_reg_write_trcpnt[dev_id][ii]);
        }
      } 
      break;
    default :
      CS_PRINT_OUTPUT("  No register offsets have been set.\n", dev_id);
      break;
  }
  CS_PRINT_OUTPUT("  -\n", dev_id);
}

