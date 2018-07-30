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
 * ten_xcon_isr.c
 *
 * XCON related isr code is implemented here.
 *
 */

#include "tenabo40.h"
#include "ten_irq_tree.h"
#include "ten_irq.h"

extern void ten_xcon_es_refresh_thrshlds(cs_uint16 dev_id, ten_xcon_es_num_t es_num,
                                         cs_uint16 circuit_threshold_lower,
                                         cs_uint16 circuit_threshold_upper );


/********************************************************************/
/* CATEGORY   : Interupt Handler                                    */
/* ACCESS     : Public                                              */
/* BLOCK      : HIGH LEVEL                                          */
/* CHIP       : Tenabo                                              */
void ten_xcon_es_intr_handler (ten_irq_handler_data_t handler_data)
/* INPUTS     : o Interrupt Hander Data                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : VOID                                                */
/* DESCRIPTION:                                                     */
/* Handle XCON ES Interrupts                                        */
/*                                                                  */
/* ten_irq_handler_data_t handler_data:                             */
/*     cs_uint16                dev_id;                             */
/*     ten_irq_node_ptr         node;                               */
/*     cs_uint16                ireg_data;                          */
/*     cs_uint16                ereg_data;                          */
/*     cs_uint16                sreg_data; (0 when no status reg)   */
/*     cs_uint8                 slice;                              */
/*                                                                  */
/* Using interrupt handlers:                                        */
/*   First, bit-and the i and e reg_data to see which interrupts    */
/*   fired, and test to see if one of them is of interest to this   */
/*   handler. If so, use sreg_data to see if the state is of        */
/*   interest, and if so, handle the interrupt. Note: There are     */
/*   three reasons sreg_data can be 0: a) there is no status        */
/*   register for this interrupt, b) all events were trailing       */
/*   events, or c) the interrupt registers don't follow convention  */
/*   so the status needs should be read directly.                   */
/********************************************************************/
{
  cs_uint16      drvr_flag_saved;
  TEN_XCON_ES_INTERRUPT_t tmp_intr_i_e;
  cs_char8      *func          = "ten_xcon_es_intr_handler";  

  drvr_flag_saved = g_pTEN->drvr_flag;        /* Context save flags */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND; /* Enable driver log */


  /* Get interrupts that are active and enabled */
  tmp_intr_i_e.wrd  = handler_data.ireg_data & handler_data.ereg_data;

  CS_PRINT("%s() tmp_xcon_intr=0x%X\n", func, tmp_intr_i_e.wrd);

  /* Service interrupts */

  if (tmp_intr_i_e.bf.AMPLITUDE_RECENTERi) {
    ten_dev_irq_disable(handler_data.dev_id, &TEN_IRQ_NODE_XCON_ES_INTERRUPT, TEN_XCON_ES_INTR_AMPLITUDE_RECENTER, TEN_IRQ_DIR_UP);
    /* amplitude recenter status has changed. */
    ten_xcon_es_amp_recntr_intr_handler(handler_data.dev_id, handler_data.slice);
  } 

  g_pTEN->drvr_flag = drvr_flag_saved; /* Context restore flags */
}

/****************************************************************/
/* $rtn_hdr_start  N10G XCON ES INTERRUPT HANDLER ENABLE        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_es_intr_handler_enable (cs_uint16 dev_id,
                                           cs_uint16 bitfield)
/* INPUTS     : o Device Id                                     */
/*              o ES Number                                     */
/*              o Bit Field                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Register XCON Elastic Store interrupt handler and enable its */
/* interrupts (ES 0-7)                                          */
/*                                                              */
/* The [bitfield] parameter is specified as:                    */
/*   TEN_XCON_ES_INTR_FIFO_OVERFLOW_CNT_OV = 0x0001,            */
/*   TEN_XCON_ES_INTR_FFIFO_SINGLE_ERR     = 0x0010,            */
/*   TEN_XCON_ES_INTR_FFIFO_DOUBLE_ERR     = 0x0020,            */
/*   TEN_XCON_ES_INTR_DFIFO_SINGLE_ERR     = 0x0040,            */
/*   TEN_XCON_ES_INTR_DFIFO_DOUBLE_ERR     = 0x0080,            */
/*   TEN_XCON_ES_INTR_SYNC_CHANGE          = 0x0100,            */
/*   TEN_XCON_ES_INTR_SYNC_LOST            = 0x2000,            */
/*   TEN_XCON_ES_INTR_OVERFLOW             = 0x0800,            */
/*   TEN_XCON_ES_INTR_RECENTER             = 0x1000,            */
/*   TEN_XCON_ES_INTR_LOWER_VIOLATION      = 0x2000,            */
/*   TEN_XCON_ES_INTR_UPPER_VIOLATION      = 0x4000,            */
/*   TEN_XCON_ES_INTR_AMPLITUDE_RECENTER   = 0x8000,            */
/*   TEN_XCON_ES_INTR_ALL                  = 0xFFF1             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xcon_es_intr_handler_enable";  

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() bitfield=0x%X\n", func, bitfield);

  /* Register the interrupt handler for elastic store interrupt register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_XCON_ES_INTERRUPT, ten_xcon_es_intr_handler);

  /* Enable the propagation of this interrupt all the way up the interrupt tree */
  ten_dev_irq_enable(dev_id, &TEN_IRQ_NODE_XCON_ES_INTERRUPT, bitfield, TEN_IRQ_DIR_UP);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  N10G XCON ES INTERRUPT  ENABLE               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_es_intr_enable (cs_uint16 dev_id,
                                   cs_uint16 bitfield)
/* INPUTS     : o Device Id                                     */
/*              o ES Number                                     */
/*              o Bit Field                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable XCON Elastic Store interrupts (ES 0-7). Assumes       */
/* handler is already enabled.                                  */
/*                                                              */
/* The [bitfield] parameter is specified as:                    */
/*   TEN_XCON_ES_INTR_FIFO_OVERFLOW_CNT_OV = 0x0001,            */
/*   TEN_XCON_ES_INTR_FFIFO_SINGLE_ERR     = 0x0010,            */
/*   TEN_XCON_ES_INTR_FFIFO_DOUBLE_ERR     = 0x0020,            */
/*   TEN_XCON_ES_INTR_DFIFO_SINGLE_ERR     = 0x0040,            */
/*   TEN_XCON_ES_INTR_DFIFO_DOUBLE_ERR     = 0x0080,            */
/*   TEN_XCON_ES_INTR_SYNC_CHANGE          = 0x0100,            */
/*   TEN_XCON_ES_INTR_SYNC_LOST            = 0x2000,            */
/*   TEN_XCON_ES_INTR_OVERFLOW             = 0x0800,            */
/*   TEN_XCON_ES_INTR_RECENTER             = 0x1000,            */
/*   TEN_XCON_ES_INTR_LOWER_VIOLATION      = 0x2000,            */
/*   TEN_XCON_ES_INTR_UPPER_VIOLATION      = 0x4000,            */
/*   TEN_XCON_ES_INTR_AMPLITUDE_RECENTER   = 0x8000,            */
/*   TEN_XCON_ES_INTR_ALL                  = 0xFFF1             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xcon_es_intr_enable";  

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() bitfield=0x%X\n", func, bitfield);

  /* Enable the propagation of this interrupt all the way up the interrupt tree */
  ten_dev_irq_enable(dev_id, &TEN_IRQ_NODE_XCON_ES_INTERRUPT, bitfield, TEN_IRQ_DIR_UP);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON SADECO SADINT                               */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_sadeco_sadint(cs_uint16 dev_id, cs_uint8 instance, 
                                 cs_uint16 eserr, 
                                 cs_uint16 sdcerr, 
                                 cs_uint16 synci)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o ESERR                                             */
/*              o SDCERR                                            */
/*              o SYNCI                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Write 1 to clear various XCON interrupts.                        */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..1 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [eserr]                                                        */
/*     The Skew and Delay Compensator has detected an elastic       */
/*     store underflow or overflow. If enabled by RSYMSK[4],        */
/*     this will cause a loss of SYNC status and a realignment      */
/*     to occur.                                                    */
/*                                                                  */
/*   [sdcerr]                                                       */
/*     The Skew and Delay Compensator has detected a change in      */
/*     frame alignment on the given input channel.                  */
/*     If enabled by RSYMSK, this will cause a loss of SYNC         */
/*     status and a realignment to occur.                           */
/*                                                                  */
/*   [synci]                                                        */
/*     Interrupt is set when a change in state occurs on            */
/*     SYNC status.                                                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  cs_uint16 ii;
  TEN_XCON_SADECO_SADINT_t tmp_sadeco_sadint;

  if ((instance >= TEN_XCON_SADECO_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..2.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_SADECO_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_sadeco_sadint.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADINT, instance));
      tmp_sadeco_sadint.bf.ESERR = eserr;
      tmp_sadeco_sadint.bf.SDCERR = sdcerr;
      tmp_sadeco_sadint.bf.SYNCI = synci;
      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADINT, instance), tmp_sadeco_sadint.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON GET SADECO SADINT SYNCI                     */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_uint16 ten_xcon_get_sadeco_sadint_synci(cs_uint16 dev_id, cs_uint8 instance)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : Status                                              */
/* DESCRIPTION:                                                     */
/* Returns SYNCI, Interrupt is set when a change in state           */
/* occurs on SYNC status.                                           */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..1.                                           */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  T41_t *pDev;
  TEN_XCON_SADECO_SADINT_t tmp_sadeco_sadint;

  if (instance >= TEN_XCON_SADECO_COUNT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..1.");
    return (0);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, 0);
  tmp_sadeco_sadint.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADINT, instance));
  return (tmp_sadeco_sadint.bf.SYNCI);
}

