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
 * ten_n40g_isr.c
 *
 * N40G related isr code is implemented here.
 *
 * $Id: ten_n40g_isr.c,v 1.7 2013/02/22 20:44:38 jccarlis Exp $
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
void ten_n40g_otnr4x_intr_handler (ten_irq_handler_data_t handler_data)
/* INPUTS     : o Interrupt Hander Data                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : VOID                                            */
/* DESCRIPTION:                                                 */
/* Handle the N40g OTNR4X Interrupt for OTN                     */
/*                                                              */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module_id;
  cs_uint16 module_id_other_side;
  cs_uint16 drvr_flag_saved;
  cs_uint16 instance;
  TEN_N40G_OTNR4X_INTR_t tmp_n40g_otnr4x_intr;
  TEN_XCON_GLB_ES_SOURCE_SELECT_0_t tmp_glb_es_source_select;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_otnr4x_intr_handler";  

  drvr_flag_saved = g_pTEN->drvr_flag;        /* Context save flags */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND; /* Enable driver log */

  dev_id = handler_data.dev_id;
  /*module_id =  (handler_data.slice < 1) ? TEN_MODULE_A : TEN_MODULE_B;*/
  /*module_id_other_side = (module_id == TEN_MODULE_A) ? TEN_MODULE_B : TEN_MODULE_A;*/
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
  
  CS_PRINT("%s() %s\n", func, ten_module_strings[module_id & 1]);

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
  tmp_n40g_otnr4x_intr.wrd = handler_data.ireg_data;
  tmp_n40g_otnr4x_intr.wrd &= TEN_REG_READ(TEN_N40G_REG_ADDR(pDev, module_id, INTRE));
  CS_PRINT("%s() tmp_n40g_otnr4x_intr=0x%X\n", func, tmp_n40g_otnr4x_intr.wrd);

  /* Service interrupts */
  if (tmp_n40g_otnr4x_intr.bf.IIF)  {
    /* IF status (SIF) state has changed */
    if (ten_n40g_otnr4x_get_ofstat (module_id, TEN_N40G_OTNR4X_STATUS_SIF)) {
      /* OTN Framer has gone from out of frame to IF (In Frame synced) state */
      CS_PRINT("%s(%s) OTN is in frame,  So reset and recenter elastic store\n", func, ten_module_strings[module_id & 1]);

      /* Reset and recenter elastic store on oposit side */
      ten_xcon_es_handle_traffic_stable_event_40g_t41(dev_id, module_id);
    } else {
      CS_PRINT("%s(%s) OTN is NOT in frame\n", func, ten_module_strings[module_id & 1]);
    }
  }

  CS_PRINT("%s() %s   EXIT\n", func, ten_module_strings[module_id & 1]);

  g_pTEN->drvr_flag = drvr_flag_saved; /* Context restore flags */
}

/****************************************************************/
/* $rtn_hdr_start  N40G OTNR4X INTERRUPT HANDLER ENABLE         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_otnr4x_intr_handler_enable (cs_uint16 module_id,
                                               cs_uint16 bitfield)
/* INPUTS     : o Module Id                                     */
/*              o Bit Field                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable N40G OTNR4X interrut handler for OTN                  */
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/* The [bitfield] parameter is specified as:                    */
/*  TEN_N40G_OTNR4X_INTR_IPSFND	  = 0x0001                      */
/*  TEN_N40G_OTNR4X_INTR_IPLOST	  = 0x0002                      */
/*  TEN_N40G_OTNR4X_INTR_IOOF	  = 0x0004                      */
/*  TEN_N40G_OTNR4X_INTR_ILOF	  = 0x0008                      */
/*  TEN_N40G_OTNR4X_INTR_IIF	  = 0x0010                      */
/*  TEN_N40G_OTNR4X_INTR_FSCH	  = 0x0020                      */
/*  TEN_N40G_OTNR4X_INTR_FSUSTSI  = 0x0040                      */
/*  TEN_N40G_OTNR4X_INTR_GMP0I	  = 0x0080                      */
/*  TEN_N40G_OTNR4X_INTR_GMP1I	  = 0x0100                      */
/*  TEN_N40G_OTNR4X_INTR_GMP2I	  = 0x0200                      */
/*  TEN_N40G_OTNR4X_INTR_GMP3I	  = 0x0400                      */
/*  TEN_N40G_OTNR4X_INTR_FSMMI	  = 0x0800                      */
/*  TEN_N40G_OTNR4X_INTR_OBFA2I	  = 0x1000                      */
/*  TEN_N40G_OTNR4X_INTR_FAWMI	  = 0x2000                      */
/*  TEN_N40G_OTNR4X_INTR_FSMMTRBI = 0x4000                      */
/*  TEN_N40G_OTNR4X_INTR_ALL	  = 0x3FFF                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_OTNR4X_INTR_t tmp_n40g_otnr4x_intr;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_n40g_otnr4x_intr_handler_enable";  

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s bitfield=0x%X\n", func, ten_module_strings[module_id & 1], bitfield);

  /* Register the interrupt handler for the N40G_OTNR4X_INTR register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N40G_OTNR4X_INTR, ten_n40g_otnr4x_intr_handler);

  /* Enable the propagation of this interrupt all the way up the interrupt tree */
  tmp_n40g_otnr4x_intr.wrd = bitfield;
  ten_mod_irq_enable (module_id, 0, &TEN_IRQ_NODE_N40G_OTNR4X_INTR, tmp_n40g_otnr4x_intr.wrd, TEN_IRQ_DIR_UP);

  return (CS_OK);
}

/****************************************************************/
/* CATEGORY   : Interupt Handler                                */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
void ten_n40g_sdfr_sdfist_handler (ten_irq_handler_data_t handler_data)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Handle the N40g SDFR Interrupt for Sonet                     */
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module_id;
  cs_uint16 module_id_other_side;
  cs_uint16 drvr_flag_saved;
  TEN_N40G_SDFR_SDFIST_t tmp_sdfr_sdfist;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n40g_sdfr_sdfist_handler";  

  drvr_flag_saved = g_pTEN->drvr_flag;        /* Context save flags */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND; /* Enable driver log */
  
  dev_id = handler_data.dev_id;
  module_id =  (handler_data.slice < 1) ? TEN_MODULE_A : TEN_MODULE_B;
  module_id_other_side = (module_id == TEN_MODULE_A) ? TEN_MODULE_B : TEN_MODULE_A;

  TEN_DEV_COMMON_VALIDATE_INTERNAL (dev_id, &pDev);

  CS_PRINT("%s() %s\n", func, ten_module_strings[module_id & 1]);

  tmp_sdfr_sdfist.wrd = handler_data.ireg_data;
  /*CS_PRINT("%s() sdfr_sdfist=0x%X\n", func, tmp_sdfr_sdfist.wrd);*/

  /* Service interrupts */
  if (tmp_sdfr_sdfist.bf.OOF) { 
    if (!ten_n40g_get_sdfr_rx_status (module_id, TEN_SDFR_SDFSTAT_OOFS)) {
      /* Sonet Framer has gone from out of frame to  In Frame state */
      CS_PRINT("%s(%s) Sonet is in frame,  So reset and recenter elastic store\n", func, ten_module_strings[module_id & 1]);

      ten_xcon_es_handle_traffic_stable_event_40g_t41(dev_id, module_id);
    } else {
      CS_PRINT("%s(%s) Sonet is Out Of frame\n", func, ten_module_strings[module_id & 1]);
    }
  }
  
  CS_PRINT("%s() %s   EXIT\n", func, ten_module_strings[module_id & 1]);

  g_pTEN->drvr_flag = drvr_flag_saved; /* Context restore flags */
}
  
/****************************************************************/
/* $rtn_hdr_start  N40G SDFR SDF INTERRUPT HANDLER ENABLE       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_n40g_sdfr_sdfist_handler_enable (cs_uint16 module_id,
                                               cs_uint16 bitfield)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable N40G SDFR SDF interrut handler                        */
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/* The [bitfield] parameter is specified as:                    */
/*   TEN_N40G_SDFR_SDFIST_OOF	 = 0x0001                       */
/*   TEN_N40G_SDFR_SDFIST_LOF	 = 0x0002                       */
/*   TEN_N40G_SDFR_SDFIST_LOS	 = 0x0004                       */
/*   TEN_N40G_SDFR_SDFIST_FER	 = 0x0008                       */
/*   TEN_N40G_SDFR_SDFIST_FOK	 = 0x0010                       */
/*   TEN_N40G_SDFR_SDFIST_B1INVI = 0x0040                       */
/*   TEN_N40G_SDFR_SDFIST_B1BTEX = 0x0080                       */
/*   TEN_N40G_SDFR_SDFIST_B1BLEX = 0x0100                       */
/*   TEN_N40G_SDFR_SDFIST_B2BTEX = 0x0200                       */
/*   TEN_N40G_SDFR_SDFIST_B2BLEX = 0x0400                       */
/*   TEN_N40G_SDFR_SDFIST_SFI	 = 0x0800                       */
/*   TEN_N40G_SDFR_SDFIST_SDI	 = 0x1000                       */
/*   TEN_N40G_SDFR_SDFIST_IPN11  = 0x8000                       */
/*   TEN_N40G_SDFR_SDFIST_ALL	 = 0x9FDF                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N40G_SDFR_SDFIST_t tmp_sdfr_sdfist;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_n40g_sdfr_sdfist_handler_enable";  

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s bitfield=%d\n", func, ten_module_strings[module_id & 1], bitfield);

  /* Register the interrupt handler for the N40G_OTNR4X_INTR register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N40G_SDFR_SDFIST, ten_n40g_sdfr_sdfist_handler);
  
  /* Enable the propagation of this interrupt all the way up the interrupt tree */
  tmp_sdfr_sdfist.wrd = bitfield;
  ten_mod_irq_enable (module_id, 0, &TEN_IRQ_NODE_N40G_SDFR_SDFIST, tmp_sdfr_sdfist.wrd, TEN_IRQ_DIR_UP);

  return (CS_OK);
}



