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
 * ten_pp10g_isr.c
 *
 * PP10G related isr code is implemented here.
 *
 * $Id: ten_pp10g_isr.c,v 1.7 2013/02/22 20:48:04 jccarlis Exp $
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
void ten_pp10g_pcs_rx_rxint_handler (ten_irq_handler_data_t handler_data)
/* INPUTS     : o Interrupt Hander Data                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : VOID                                            */
/* DESCRIPTION:                                                 */
/* Handle the PP10g PCS RX Interrupt for 10GE                   */
/*                                                              */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 es_num;
  cs_uint16 module_id;
  cs_uint16 drvr_flag_saved;
  TEN_PP10G_PCS_RX_RXINT_t tmp_pp10g_pcs_rx_rxint;
  TEN_XCON_ES_RESET_t tmp_es_reset;
  TEN_XCON_GLB_ES_SOURCE_SELECT_0_t tmp_glb_es_source_select;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_pp10g_pcs_rx_rxint_handler";  

  drvr_flag_saved = g_pTEN->drvr_flag;        /* Context save flags */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND; /* Enable driver log */

  dev_id = handler_data.dev_id;
  TEN_DEV_COMMON_VALIDATE_INTERNAL(dev_id, &pDev);

  CS_PRINT("%s() %s\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

  module_id =  (handler_data.slice < 4) ? TEN_MODULE_A : TEN_MODULE_B;

  /* Find transmitter that is using this source */
  for (es_num=0; es_num<TEN_XCON_ES_COUNT; es_num++) {
    tmp_glb_es_source_select.wrd = TEN_REG_READ(TEN_XCON_ES_SOURCE_SEL_REG_ADDR(pDev, es_num));
    if (tmp_glb_es_source_select.bf.SOURCE == handler_data.slice) {
      /* Transmitter es_num which is using this source */
      tmp_es_reset.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, RESET, es_num));
      if (!tmp_es_reset.bf.RESET) {
        /* Transmitter es_num is out of reset, so mathing source has been found */
        break;
      }
    }
  }

  if (es_num == TEN_XCON_ES_COUNT) {
    /* Transmitter using this source was not found */
    CS_PRINT("%s()  Transmitter using %s as a source was not found!\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);
    return;
  }

  /* Get interrupts that are active */
  tmp_pp10g_pcs_rx_rxint.wrd = handler_data.ireg_data;
  /* Mask out interrupts that are not enabled */
  tmp_pp10g_pcs_rx_rxint.wrd &= TEN_REG_READ(TEN_PP10G_PCS_REG_ADDR(pDev, module_id, handler_data.slice%4, RXINTENABLE));
  CS_PRINT("%s() tmp_pp10g_pcs_rx_rxint=0x%X\n", func, tmp_pp10g_pcs_rx_rxint.wrd);

  /* Service interrupts */
  if (tmp_pp10g_pcs_rx_rxint.bf.syncdetI) {
    /* Receive synchronization status has changed*/
    if (ten_pp10g_pcs_rx_status(module_id, handler_data.slice%4, TEN_PP10G_PCS_RX_SYNCDETS)) {
      /* PP10G has gone from out of sync to in sync state */
      CS_PRINT("%s() %s PP10G is in sync,  So reset and recenter elastic store\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

      /* Reset and recenter elastic store on oposit side */
      ten_xcon_select_es_packet_centering (dev_id, es_num, XCON_FORCE_CENTER, CS_ENABLE);
      ten_xcon_select_es_packet_centering (dev_id, es_num, XCON_FORCE_CENTER, CS_DISABLE);
    } else {
      CS_PRINT("%s() %s PP10G is NOT in sync\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);
    }
  }

  CS_PRINT("%s() %s   EXIT\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

  g_pTEN->drvr_flag = drvr_flag_saved; /* Context restore flags */
}

/****************************************************************/
/* $rtn_hdr_start  PP10G PCS RX INTERRUPT HANDLER ENABLE        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_pp10g_pcs_rx_rxint_handler_enable (cs_uint16 module_id,
                                                 cs_uint16 slice,
                                                 cs_uint16 bitfield)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Bit Field                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable PP10G PCS rx interrupt handler for 10GE and 10GFC     */
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/* The [slice] parameters specify the slice:                    */
/*   TEN_SLICE0 = 0                                             */
/*   TEN_SLICE1 = 1                                             */
/*   TEN_SLICE2 = 2                                             */
/*   TEN_SLICE3 = 3                                             */
/*                                                              */
/* The [bitfield] parameter is specified as:                    */
/*   TEN_PP10G_PCS_RX_RXINT_ERRORPKTI = 0x0001                  */
/*   TEN_PP10G_PCS_RX_RXINT_ERRORDECI = 0x0008                  */
/*   TEN_PP10G_PCS_RX_RXINT_ERRORPATI = 0x0020                  */
/*   TEN_PP10G_PCS_RX_RXINT_SYNCDETI  = 0x0100                  */
/*   TEN_PP10G_PCS_RX_RXINT_BERHIGHI  = 0x0200                  */
/*   TEN_PP10G_PCS_RX_RXINT_PATSYNCI  = 0x0400                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_PP10G_PCS_RX_RXINT_t tmp_pp10g_pcs_rx_rxint;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_pp10g_pcs_rx_rxint_handler_enable";  

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s %s bitfield=0x%X\n", func, ten_module_strings[module_id & 1], ten_slice_strings[slice], bitfield);

  /* Register the interrupt handler for the N10G_OTNR_INTR register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_PP10G_PCS_RX_RXINT, ten_pp10g_pcs_rx_rxint_handler);

  /* Enable the propagation of this interrupt all the way up the interrupt tree */
  tmp_pp10g_pcs_rx_rxint.wrd = bitfield;
  ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_PP10G_PCS_RX_RXINT, tmp_pp10g_pcs_rx_rxint.wrd, TEN_IRQ_DIR_UP);

  return (CS_OK);
}
