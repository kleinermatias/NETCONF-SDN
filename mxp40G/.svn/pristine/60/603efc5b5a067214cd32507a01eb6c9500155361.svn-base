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
 * ten_pp40g_isr.c
 *
 * PP40G related isr code is implemented here.
 *
 * $Id: ten_pp40g_isr.c,v 1.5 2013/02/22 20:56:33 jccarlis Exp $
 *
 */

#include "tenabo40.h"
#include "ten_irq_tree.h"
#include "ten_irq.h"

/****************************************************************/
/* CATEGORY   : Interupt Handler                                */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
void ten_pp40g_pcs_rx_interupt_handler (ten_irq_handler_data_t handler_data)
/* INPUTS     : o Interrupt Hander Data                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : VOID                                            */
/* DESCRIPTION:                                                 */
/* Handle the PP40g PCS RX Interrupt for 40GE                   */
/*                                                              */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module_id;
  cs_uint16 module_id_other_side;
  cs_uint16 drvr_flag_saved;
  cs_uint16 instance;
  TEN_PP40G_PCS_RX_INTERRUPT_t tmp_pp40g_pcs_rx_interrupt;
  TEN_XCON_GLB_ES_SOURCE_SELECT_0_t tmp_glb_es_source_select;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_pp40g_pcs_rx_interupt_handler";  

  drvr_flag_saved = g_pTEN->drvr_flag;        /* Context save flags */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND; /* Enable driver log */

  dev_id = handler_data.dev_id;
  if (handler_data.slice == 0) {
    /* Side A */
    module_id = TEN_MODULE_A;
    instance = 0;
  } else {
    /* Side B */
    module_id = TEN_MODULE_B;
    instance = 4;
  }

  TEN_DEV_COMMON_VALIDATE_INTERNAL (dev_id, &pDev);
  
  CS_PRINT("%s() %s\n", func, ten_module_strings[module_id&1]);

  /* Read this sides source to determine if we are in loopback */
  tmp_glb_es_source_select.wrd = TEN_REG_READ(TEN_XCON_ES_SOURCE_SEL_REG_ADDR(pDev, instance));
  if (tmp_glb_es_source_select.bf.SOURCE == instance) {
    /* This side is in loopback */
    module_id_other_side = module_id;
  } else {
    module_id_other_side = (module_id == TEN_MODULE_A) ? TEN_MODULE_B : TEN_MODULE_A; 
  }                
  /*CS_PRINT("%s() module_id=%s, module_id_other_side=%s\n", func, ten_module_strings[module_id & 1], ten_module_strings[module_id_other_side & 1]);*/

  /* Get interrupts that are active */
  tmp_pp40g_pcs_rx_interrupt.wrd = handler_data.ireg_data;
  tmp_pp40g_pcs_rx_interrupt.wrd &= TEN_REG_READ(TEN_PP40G_REG_ADDR(pDev, module_id, pcs_rx_INTENABLE));
  CS_PRINT("%s() tmp_pp40g_pcs_rx_interrupt=0x%X\n", func, tmp_pp40g_pcs_rx_interrupt.wrd);

  /* Service interrupts */
  if (tmp_pp40g_pcs_rx_interrupt.bf.xdcblocklockI) {
    /* xdcblocklockS has changed */
    if (ten_pp40g_pcs_rx_intstatus_t41(module_id, TEN_PP40G_PCS_RX_INTSTATUS_SELECT_XDCBLOCKLOCKS)) {
      /* Receive 1024b/1027b block lock status for the trans-decoder is active */
      CS_PRINT("%s(%s) 1024b/1027b block lock is active,  So reset and recenter elastic store\n", func, ten_module_strings[module_id & 1]);

      /* Reset and recenter elastic store on oposit side */
      ten_xcon_es_pp40g_reset_t41 (module_id_other_side);
    } else {
      CS_PRINT("%s(%s) 024b/1027b block lock is NOT active\n", func, ten_module_strings[module_id & 1]);
    }
  }

  CS_PRINT("%s() %s   EXIT\n", func, ten_module_strings[module_id & 1]);

  g_pTEN->drvr_flag = drvr_flag_saved; /* Context restore flags */
}

/****************************************************************/
/* $rtn_hdr_start  PP40G PCS RX INTERRUPT HANDLER ENABLE        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_pp40g_pcs_rx_interupt_handler_enable (cs_uint16 module_id,
                                                    cs_uint16 bitfield)
/* INPUTS     : o Module Id                                     */
/*              o Bit Field                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable PP40G PCS RX interrut handler for 40GE                */
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/* The [bitfield] parameter is specified as:                    */
/*   TEN_PP40G_PCS_RX_INTERRUPT_LANEBLOCKLOCK0I  = 0x0001       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_LANEBLOCKLOCK1I  = 0x0002       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_LANEBLOCKLOCK2I  = 0x0004       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_LANEBLOCKLOCK3I  = 0x0008       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_LANEAMSTATUSI    = 0x0010       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_LANEALIGNSTATUSI = 0x0020       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_MONOBLOCKLOCKI   = 0x0040       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_MONOAMSTATUSI    = 0x0080       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_XDCBLOCKLOCKI    = 0x0100       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_XDCAMSTATUSI     = 0x0200       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_BERHIGHI         = 0x0400       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_ERRORDECI        = 0x0800       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_PATDETECTI       = 0x1000       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_SKEWHIGHI        = 0x2000       */
/*   TEN_PP40G_PCS_RX_INTERRUPT_ALL              = 0x3FFF       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_pp40g_pcs_rx_interupt_handler_enable";  

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s bitfield=0x%X\n", func, ten_module_strings[module_id & 1], bitfield);

  /* Register the interrupt handler for the N10G_SDFR_SDFIST register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_PP40G_PCS_RX_INTERRUPT, ten_pp40g_pcs_rx_interupt_handler);

  /* Enable the propagation of this interrupt all the way up the interrupt tree */
  ten_mod_irq_enable (module_id, 0, &TEN_IRQ_NODE_PP40G_PCS_RX_INTERRUPT, bitfield, TEN_IRQ_DIR_UP);

  return (CS_OK);
}
