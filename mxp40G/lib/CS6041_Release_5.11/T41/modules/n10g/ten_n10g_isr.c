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
 * ten_n10g_isr.c
 *
 * N10G related isr code is implemented here.
 *
 * $Id: ten_n10g_isr.c,v 1.8 2013/02/22 20:47:56 jccarlis Exp $
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
void ten_n10g_otnr_intr_handler (ten_irq_handler_data_t handler_data)
/* INPUTS     : o Interrupt Hander Data                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : VOID                                            */
/* DESCRIPTION:                                                 */
/* Handle the N10g OTNR Interrupt for OTN                       */
/*                                                              */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module_id;
  cs_uint16 drvr_flag_saved;
  TEN_N10G_OTNR_INTR_t tmp_n10g_otnr_intr;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_n10g_otnr_intr_handler";  

  drvr_flag_saved = g_pTEN->drvr_flag;        /* Context save flags */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND; /* Enable driver log */

  dev_id = handler_data.dev_id;
  TEN_DEV_COMMON_VALIDATE_INTERNAL(dev_id, &pDev);

  CS_PRINT("%s() %s\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

  module_id =  (handler_data.slice < 4) ? TEN_MODULE_A : TEN_MODULE_B;

  /* tmp_global_reset_common.bf.xcon = 0 */
  /* tmp_global_clock_disable_common.bf.xcon = 0 */
  /* tmp_xcon_glb_config.bf.DISABLE_ES */


  /* Get interrupts that are active */
  tmp_n10g_otnr_intr.wrd = handler_data.ireg_data;
  /* Mask out interrupts that are not enabled */
  tmp_n10g_otnr_intr.wrd &= TEN_REG_READ(TEN_N10G_REG_ADDR(pDev, module_id, handler_data.slice%4, otnr_INTRE));
  CS_PRINT("%s() tmp_n10g_otnr_intr=0x%X\n", func, tmp_n10g_otnr_intr.wrd);

  /* Service interrupts */
  if (tmp_n10g_otnr_intr.bf.IIF) {
    /* IF status (SIF) state has changed */
    if (ten_n10g_get_otu_framer_status (module_id, handler_data.slice%4, TEN_NX0G_OTNR_OFSTAT_SIF)) {
      /* OTN Framer has gone from out of frame to IF (In Frame synced) state */
      CS_PRINT("%s() %s OTN is in frame,  So reset and recenter elastic store\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

      /* Reset and recenter elastic store on opposite side */
      ten_xcon_es_handle_traffic_stable_event_10g_t41(dev_id, handler_data.slice);
    } else {
      CS_PRINT("%s() %s OTN is NOT in frame\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);
    }
  }
  if (tmp_n10g_otnr_intr.bf.ILOF) {
    /* Loss Of Fram status (SLOF) state has changed */
    if (!ten_n10g_get_otu_framer_status (module_id, handler_data.slice%4, TEN_NX0G_OTNR_OFSTAT_SLOF)) {
      /* OTN Framer has gone from Loss Of Frame to Not Loss Of Frane state */
      CS_PRINT("%s() %s OTN is Not in Loss Of Frame,  So reset and recenter elastic store\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

      /* Reset and recenter elastic store on opposite side */
      ten_xcon_es_handle_traffic_stable_event_10g_t41(dev_id, handler_data.slice);
    } else {
      CS_PRINT("%s() %s OTN is in Loss Of Frame\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);
    }
  }
  if (tmp_n10g_otnr_intr.bf.IOOF) {
    /* Out Of Fram status (SOOF) state has changed */
    if (!ten_n10g_get_otu_framer_status (module_id, handler_data.slice%4, TEN_NX0G_OTNR_OFSTAT_SOOF)) {
      /* OTN Framer has gone from Out Of Frame to Not Out Of Frame state */
      CS_PRINT("%s() %s OTN is Not in Out Of Frame,  So reset and recenter elastic store\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

      /* Reset and recenter elastic store on opposite side */
      ten_xcon_es_handle_traffic_stable_event_10g_t41(dev_id, handler_data.slice);
    } else {
      CS_PRINT("%s() %s OTN is in Out Of Frame\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);
    }
  }

  CS_PRINT("%s() %s   EXIT\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

  g_pTEN->drvr_flag = drvr_flag_saved; /* Context restore flags */
}

/****************************************************************/
/* $rtn_hdr_start  N10G OTNR INTERRUPT HANDLER ENABLE           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_otnr_intr_handler_enable (cs_uint16 module_id,
                                             cs_uint16 slice,
                                             cs_uint16 bitfield)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Bit Field                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable N10G OTNR interrut handler for OTN                    */
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
/*   TEN_N10G_OTNR_INTR_IPN11   = 0x0001                        */
/*   TEN_N10G_OTNR_INTR_IOOF    = 0x0004                        */
/*   TEN_N10G_OTNR_INTR_ILOF    = 0x0008                        */
/*   TEN_N10G_OTNR_INTR_IIF     = 0x0010                        */
/*   TEN_N10G_OTNR_INTR_FSCH    = 0x0020                        */
/*   TEN_N10G_OTNR_INTR_FSUSTSI = 0x0040                        */
/*   TEN_N10G_OTNR_INTR_GMPI    = 0x0080                        */
/*   TEN_N10G_OTNR_INTR_FS_MMI  = 0x0100                        */
/*   TEN_N10G_OTNR_INTR_FAWMI   = 0x0200                        */
/*   TEN_N10G_OTNR_INTR_ALL     = 0x3FFF                        */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N10G_OTNR_INTR_t tmp_n10g_otnr_intr;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_n10g_otnr_intr_handler_enable";  

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s %s bitfield=0x%X\n", func, ten_module_strings[module_id & 1], ten_slice_strings[slice], bitfield);

  /* Register the interrupt handler for the N10G_OTNR_INTR register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OTNR_INTR, ten_n10g_otnr_intr_handler);

  /* Enable the propagation of this interrupt all the way up the interrupt tree */
  tmp_n10g_otnr_intr.wrd = bitfield;
  ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OTNR_INTR, tmp_n10g_otnr_intr.wrd, TEN_IRQ_DIR_UP);

  return (CS_OK);
}

/****************************************************************/
/* CATEGORY   : Interupt Handler                                */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
void ten_10g_sdfr_sdfist_handler (ten_irq_handler_data_t handler_data)
/* INPUTS     : o Interrupt Hander Data                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : VOID                                            */
/* DESCRIPTION:                                                 */
/* Handle the N10g SDFR Interrupt for Sonet                     */
/*                                                              */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module_id;
  cs_uint16 drvr_flag_saved;
  TEN_N10G_SDFR_SDFIST_t tmp_n10g_sdfr_sdfist;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_10g_sdfr_sdfist_handler";  

  drvr_flag_saved = g_pTEN->drvr_flag;        /* Context save flags */
  g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND; /* Enable driver log */

  dev_id = handler_data.dev_id;
  TEN_DEV_COMMON_VALIDATE_INTERNAL(dev_id, &pDev);

  CS_PRINT("%s() %s\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

  module_id =  (handler_data.slice < 4) ? TEN_MODULE_A : TEN_MODULE_B;

  /* tmp_global_reset_common.bf.xcon = 0 */
  /* tmp_global_clock_disable_common.bf.xcon = 0 */
  /* tmp_xcon_glb_config.bf.DISABLE_ES */

  /* Get interrupts that are active */
  tmp_n10g_sdfr_sdfist.wrd = handler_data.ireg_data;
  /* Mask out interrupts that are not enabled */
  tmp_n10g_sdfr_sdfist.wrd &= TEN_REG_READ(TEN_XML_N10G_SDFR_REG_ADDR(pDev, module_id, handler_data.slice%4, sdfr_SDFISTE));
  CS_PRINT("%s() tmp_n10g_sdfr_sdfist=0x%X\n", func, tmp_n10g_sdfr_sdfist.wrd);


  /* Service interrupts */
  if (tmp_n10g_sdfr_sdfist.bf.OOF) {
    /* Out Of Frame status (OOF) state has changed */
    if (!ten_n10g_get_sdfr_rx_status (module_id, handler_data.slice%4, TEN_SDFR_SDFSTAT_OOFS)) {
      /* Sonet Framer has gone from Out Of Frame to Not Out of Frame state */
      CS_PRINT("%s() %s Sonet is in frame,  So reset and recenter elastic store\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

      /* Reset and recenter elastic store on opposite side */
      ten_xcon_es_handle_traffic_stable_event_10g_t41(dev_id, handler_data.slice);
    } else {
      CS_PRINT("%s() %s Sonet is NOT in frame\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);
    }
  }
  if (tmp_n10g_sdfr_sdfist.bf.LOF) {
    /* Loss Of Frame status (LOF) state has changed */
    if (!ten_n10g_get_sdfr_rx_status (module_id, handler_data.slice%4, TEN_SDFR_SDFSTAT_LOFS)) {
      /* Sonet Framer has gone from Loss Of Frame to Not Loss of Frame state */
      CS_PRINT("%s() %s Sonet is in frame,  So reset and recenter elastic store\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

      /* Reset and recenter elastic store on opposite side */
      ten_xcon_es_handle_traffic_stable_event_10g_t41(dev_id, handler_data.slice);
    } else {
      CS_PRINT("%s() %s Sonet is NOT in frame\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);
    }
  }

  CS_PRINT("%s() %s   EXIT\n", func, ten_xcon_es_mod_slice_strings[handler_data.slice]);

  g_pTEN->drvr_flag = drvr_flag_saved; /* Context restore flags */
}

/****************************************************************/
/* $rtn_hdr_start  N10G SDFR SDFIST INTERRUPT HANDLER ENABLE    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_sdfr_sdfist_handler_enable (cs_uint16 module_id,
                                               cs_uint16 slice,
                                               cs_uint16 bitfield)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Bit Field                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable N10G SDFR SDFIST interrut handler for Sonet           */
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
/*    TEN_N10G_SDFR_SDFIST_OOF        = 0x0001                  */
/*    TEN_N10G_SDFR_SDFIST_LOF        = 0x0002                  */
/*    TEN_N10G_SDFR_SDFIST_LOS        = 0x0004                  */
/*    TEN_N10G_SDFR_SDFIST_FER        = 0x0008                  */
/*    TEN_N10G_SDFR_SDFIST_FOK        = 0x0010                  */
/*    TEN_N10G_SDFR_SDFIST_B1INVI     = 0x0040                  */
/*    TEN_N10G_SDFR_SDFIST_B1BTEX     = 0x0080                  */
/*    TEN_N10G_SDFR_SDFIST_B1BLEX     = 0x0100                  */
/*    TEN_N10G_SDFR_SDFIST_B2BTEX     = 0x0200                  */
/*    TEN_N10G_SDFR_SDFIST_B2BLEX     = 0x0400                  */
/*    TEN_N10G_SDFR_SDFIST_SFI        = 0x0800                  */
/*    TEN_N10G_SDFR_SDFIST_SDI        = 0x1000                  */
/*    TEN_N10G_SDFR_SDFIST_IPN11      = 0x8000                  */
/*    TEN_N10G_SDFR_SDFIST_ALL        = 0x9FDF                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N10G_SDFR_SDFIST_t tmp_n10g_sdfr_sdfist;
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_n10g_sdfr_sdfist_handler_enable";  

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s %s bitfield=0x%X\n", func, ten_module_strings[module_id & 1], ten_slice_strings[slice], bitfield);

  /* Register the interrupt handler for the N10G_SDFR_SDFIST register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_SDFR_SDFIST, ten_10g_sdfr_sdfist_handler);

  /* Enable the propagation of this interrupt all the way up the interrupt tree */
  tmp_n10g_sdfr_sdfist.wrd = bitfield;
  ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_SDFR_SDFIST, tmp_n10g_sdfr_sdfist.wrd, TEN_IRQ_DIR_UP);

  return (CS_OK);
}


/* Bugzilla 29997 Start */
/****************************************************************/
/* CATEGORY   : Interupt Handler for APS/PCC                    */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
void ten_10g_oohr_otu2_aps_pcc_handler (ten_irq_handler_data_t handler_data)
/* INPUTS     : o Interrupt Handler Data                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : VOID                                            */
/* DESCRIPTION:                                                 */
/* Handle the N10G OOHR APs/PCC Interrupt                       */
/*                                                              */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module_id;
  cs_uint16 state_and_protection_type;
  cs_uint16 requested_signal;
  cs_uint16 bridged_signal;
  cs_uint16 reg_data;
  cs_uint32 reg_offset;
  T41_t     *pDev = NULL;
  cs_char8 *func = "ten_10g_oohr_otu2_aps_pcc_handler";

  TEN_N10G_OOHR_SMSTAT_t   tmp_n10g_oohr_smstat;
  TEN_N10G_OOHR_TCM1STAT_t tmp_n10g_oohr_tcm1stat;
  TEN_N10G_OOHR_TCM2STAT_t tmp_n10g_oohr_tcm2stat;
  TEN_N10G_OOHR_TCM3STAT_t tmp_n10g_oohr_tcm3stat;
  TEN_N10G_OOHR_TCM4STAT_t tmp_n10g_oohr_tcm4stat;
  TEN_N10G_OOHR_TCM5STAT_t tmp_n10g_oohr_tcm5stat;
  TEN_N10G_OOHR_TCM6STAT_t tmp_n10g_oohr_tcm6stat;
  TEN_N10G_OOHR_PMSTAT_t   tmp_n10g_oohr_pmstat;
  
  /* Bugzilla #32223: fix problem compiling ten_n10g_isr.c */
  TEN_N10G_OOHR_SMINT_t tmp_n10g_oohr_smint;
  TEN_N10G_OOHR_PMINT0_t tmp_n10g_oohr_pmint0;
  TEN_N10G_OOHR_PMINT1_t tmp_n10g_oohr_pmint1;
  TEN_N10G_OOHR_TCM1INT_t tmp_n10g_oohr_tcm1int;
  TEN_N10G_OOHR_TCM2INT_t tmp_n10g_oohr_tcm2int;
  TEN_N10G_OOHR_TCM3INT_t tmp_n10g_oohr_tcm3int;
  TEN_N10G_OOHR_TCM4INT_t tmp_n10g_oohr_tcm4int;
  TEN_N10G_OOHR_TCM5INT_t tmp_n10g_oohr_tcm5int;
  TEN_N10G_OOHR_TCM6INT_t tmp_n10g_oohr_tcm6int;

  module_id =  (handler_data.slice < 4) ? TEN_MODULE_A : TEN_MODULE_B;
  dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  TEN_DEV_COMMON_VALIDATE_INTERNAL(dev_id, &pDev);

  CS_PRINT("%s() %s %s\n", func, ten_module_strings[module_id & 1], ten_slice_strings[handler_data.slice%4]);

  /* Get the interrupt register offset */
  reg_offset = handler_data.node->ireg;
  reg_data = handler_data.ereg_data;

  switch(reg_offset) {
    case TEN_N10G_OOHR_SMINT:
      /* Bugzilla #32223: fix problem compiling ten_n10g_isr.c */
      tmp_n10g_oohr_smint.wrd = reg_data;
      if (tmp_n10g_oohr_smint.bf.APSCHI == 1) {
        state_and_protection_type = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS71));
        requested_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS70)) >> 8;
        bridged_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS70)) & 0xFF;
      }
      else if (tmp_n10g_oohr_smint.bf.APSUNSTI == 1) {
        tmp_n10g_oohr_smstat.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, SMSTAT));
        if(tmp_n10g_oohr_smstat.bf.APSUNST) {}
          /* Write a value greater than 255 - customer dependent */
      }
      break;

    case TEN_N10G_OOHR_PMINT0:
     /* Bugzilla #32223: fix problem compiling ten_n10g_isr.c */
      tmp_n10g_oohr_pmint0.wrd = reg_data;
      if (tmp_n10g_oohr_pmint0.bf.APSUNSTI == 1) {
        tmp_n10g_oohr_pmstat.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, PMSTAT));
        if(tmp_n10g_oohr_pmstat.bf.APSUNST) {}
          /* Write a value greater than 255 - customer dependent */
      }
      break;

    case TEN_N10G_OOHR_PMINT1:
     /* Bugzilla #32223: fix problem compiling ten_n10g_isr.c */
      tmp_n10g_oohr_pmint1.wrd = reg_data;
      if (tmp_n10g_oohr_pmint1.bf.APSCHI == 1) {
        state_and_protection_type = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS01));
        requested_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS00)) >> 8;
        bridged_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS00)) & 0xFF;
      }
      break;

    case TEN_N10G_OOHR_TCM1INT:
     /* Bugzilla #32223: fix problem compiling ten_n10g_isr.c */
      tmp_n10g_oohr_tcm1int.wrd = reg_data;
      if (tmp_n10g_oohr_tcm1int.bf.APSCHI == 1) {
        state_and_protection_type = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS11));
        requested_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS10)) >> 8;
        bridged_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS10)) & 0xFF;
      }
      else if (tmp_n10g_oohr_tcm1int.bf.APSUNSTI == 1) {
        tmp_n10g_oohr_tcm1stat.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, TCM1STAT));
        if(tmp_n10g_oohr_tcm1stat.bf.APSUNST) {}
          /* Write a value greater than 255 - customer dependent */
      }
      break;

    case TEN_N10G_OOHR_TCM2INT:
     /* Bugzilla #32223: fix problem compiling ten_n10g_isr.c */
      tmp_n10g_oohr_tcm2int.wrd = reg_data;
      if (tmp_n10g_oohr_tcm2int.bf.APSCHI == 1) {
        state_and_protection_type = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS21));
        requested_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS20)) >> 8;
        bridged_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS20)) & 0xFF;
      }
      else if (tmp_n10g_oohr_tcm2int.bf.APSUNSTI == 1) {
        tmp_n10g_oohr_tcm2stat.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, TCM2STAT));
        if(tmp_n10g_oohr_tcm2stat.bf.APSUNST) {}
          /* Write a value greater than 255 - customer dependent */
      }
      break;

    case TEN_N10G_OOHR_TCM3INT:
     /* Bugzilla #32223: fix problem compiling ten_n10g_isr.c */
      tmp_n10g_oohr_tcm3int.wrd = reg_data;
      if (tmp_n10g_oohr_tcm3int.bf.APSCHI == 1) {
        state_and_protection_type = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS31));
        requested_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS30)) >> 8;
        bridged_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS30)) & 0xFF;
      }
      else if (tmp_n10g_oohr_tcm3int.bf.APSUNSTI == 1) {
        tmp_n10g_oohr_tcm3stat.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, TCM3STAT));
        if(tmp_n10g_oohr_tcm3stat.bf.APSUNST) {}
          /* Write a value greater than 255 - customer dependent */
      }
      break;

    case TEN_N10G_OOHR_TCM4INT:
     /* Bugzilla #32223: fix problem compiling ten_n10g_isr.c */
      tmp_n10g_oohr_tcm4int.wrd = reg_data;
      if (tmp_n10g_oohr_tcm4int.bf.APSCHI == 1) {
        state_and_protection_type = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS41));
        requested_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS40)) >> 8;
        bridged_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS40)) & 0xFF;
      }
      else if (tmp_n10g_oohr_tcm4int.bf.APSUNSTI == 1) {
        tmp_n10g_oohr_tcm4stat.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, TCM4STAT));
        if(tmp_n10g_oohr_tcm4stat.bf.APSUNST) {}
          /* Write a value greater than 255 - customer dependent */
      }
      break;

   case TEN_N10G_OOHR_TCM5INT:
    /* Bugzilla #32223: fix problem compiling ten_n10g_isr.c */
      tmp_n10g_oohr_tcm5int.wrd = reg_data;
      if (tmp_n10g_oohr_tcm5int.bf.APSCHI == 1) {
        state_and_protection_type = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS51));
        requested_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS50)) >> 8;
        bridged_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS50)) & 0xFF;
      }
      else if (tmp_n10g_oohr_tcm5int.bf.APSUNSTI == 1) {
        tmp_n10g_oohr_tcm5stat.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, TCM5STAT));
        if(tmp_n10g_oohr_tcm5stat.bf.APSUNST) {}
          /* Write a value greater than 255. Lets assume 266 */
      }
      break;

    case TEN_N10G_OOHR_TCM6INT:
     /* Bugzilla #32223: fix problem compiling ten_n10g_isr.c */
      tmp_n10g_oohr_tcm6int.wrd = reg_data;
      if (tmp_n10g_oohr_tcm6int.bf.APSCHI == 1) {
        state_and_protection_type = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS61));
        requested_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS60)) >> 8;
        bridged_signal = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, ACAPS60)) & 0xFF;
      }
      else if (tmp_n10g_oohr_tcm6int.bf.APSUNSTI == 1) {
        tmp_n10g_oohr_tcm6stat.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, handler_data.slice%4, TCM6STAT));
        if(tmp_n10g_oohr_tcm6stat.bf.APSUNST) {}
          /* Write a value greater than 255 - customer dependent */
      }                                                
      break;
  }
}

/****************************************************************/
/* $rtn_hdr_start  N10G OOHR APS INTERRUPT HANDLER ENABLE       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_n10g_oohr_otu2_aps_pcc_handler_enable(cs_uint16 module_id,
                                                    cs_uint16 slice,
                                                    cs_uint16 event_type,
                                                    cs_uint16 monitor_layer)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/*              o Event                                         */
/*              o Layer To Monitor                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Setup interrut handler for OTU2 APS/PCC Detection            */
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
/* The [event_type] parameter is specified as:                  */
/*   TEN_APS_DETECT_VALUE_CHANGED              = 1              */
/*   TEN_APS_DETECT_VALUE_UNSTABLE             = 2              */
/*   TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE = 3              */
/*                                                              */
/* The [monitor_layer] parameter is specified as:               */
/*   TEN_OOHR_SECTION_LAYER = 1                                 */
/*   TEN_OOHR_PATH_LAYER    = 2                                 */
/*   TEN_OOHR_TCM1_LAYER    = 3                                 */
/*   TEN_OOHR_TCM2_LAYER    = 4                                 */
/*   TEN_OOHR_TCM3_LAYER    = 5                                 */
/*   TEN_OOHR_TCM4_LAYER    = 6                                 */
/*   TEN_OOHR_TCM5_LAYER    = 7                                 */
/*   TEN_OOHR_TCM6_LAYER    = 8                                 */
/*   TEN_OOHR_ALL_LAYERS    = 0xFF                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_N10G_OOHR_SMINT_t   tmp_n10g_oohr_smint;
  TEN_N10G_OOHR_PMINT0_t  tmp_n10g_oohr_pmint0;
  TEN_N10G_OOHR_PMINT1_t  tmp_n10g_oohr_pmint1;
  TEN_N10G_OOHR_TCM1INT_t tmp_n10g_oohr_tcm1int;
  TEN_N10G_OOHR_TCM2INT_t tmp_n10g_oohr_tcm2int;
  TEN_N10G_OOHR_TCM3INT_t tmp_n10g_oohr_tcm3int;
  TEN_N10G_OOHR_TCM4INT_t tmp_n10g_oohr_tcm4int;
  TEN_N10G_OOHR_TCM5INT_t tmp_n10g_oohr_tcm5int;
  TEN_N10G_OOHR_TCM6INT_t tmp_n10g_oohr_tcm6int;
  TEN_N40G_OOHR_CFG9_t    tmp_n10g_oohr_cfg9;
   T41_t     *pDev = NULL;

  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  cs_char8 *func = "ten_10g_oohr_otu2_aps_pcc_handler";

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  CS_PRINT("%s() %s %s\n", func, ten_module_strings[module_id & 1], ten_slice_strings[slice]);

  /* APSULEN has to be programmed to a value greater than APSFLEN to detect unstable values. 
     Setting both bit fields to zero is an invalid configuration */
  if((event_type == TEN_APS_DETECT_VALUE_UNSTABLE) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE)) {
    tmp_n10g_oohr_cfg9.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, CFG9));
    tmp_n10g_oohr_cfg9.bf.APSULEN = 15;
    TEN_REG_WRITE(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, CFG9), tmp_n10g_oohr_cfg9.wrd);
  }

  /* Set the INTE bits for the monitor layer specified */
  if((monitor_layer == TEN_OOHR_SECTION_LAYER) || (monitor_layer == TEN_OOHR_ALL_LAYERS)) {
    ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OOHR_SMINT, ten_10g_oohr_otu2_aps_pcc_handler);
    tmp_n10g_oohr_smint.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, SMINT));

    if((event_type == TEN_APS_DETECT_VALUE_CHANGED) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_smint.bf.APSCHI   = 1;
    else if((event_type == TEN_APS_DETECT_VALUE_UNSTABLE) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_smint.bf.APSUNSTI = 1;

    ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OOHR_SMINT, tmp_n10g_oohr_smint.wrd, TEN_IRQ_DIR_UP);
  }
    
  if((monitor_layer == TEN_OOHR_PATH_LAYER) || (monitor_layer == TEN_OOHR_ALL_LAYERS)) {
    ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OOHR_PMINT0, ten_10g_oohr_otu2_aps_pcc_handler);
    tmp_n10g_oohr_pmint0.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, PMINT0));

    ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OOHR_PMINT1, ten_10g_oohr_otu2_aps_pcc_handler);
    tmp_n10g_oohr_pmint1.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, PMINT1));

    if((event_type == TEN_APS_DETECT_VALUE_CHANGED) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_pmint1.bf.APSCHI   = 1;
    else if((event_type == TEN_APS_DETECT_VALUE_UNSTABLE) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_pmint0.bf.APSUNSTI = 1;

    ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OOHR_PMINT0, tmp_n10g_oohr_pmint0.wrd, TEN_IRQ_DIR_UP);
    ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OOHR_PMINT1, tmp_n10g_oohr_pmint1.wrd, TEN_IRQ_DIR_UP);
  }

  if((monitor_layer == TEN_OOHR_TCM1_LAYER) || (monitor_layer == TEN_OOHR_ALL_LAYERS)) {
    ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OOHR_TCM1INT, ten_10g_oohr_otu2_aps_pcc_handler);
    tmp_n10g_oohr_tcm1int.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, TCM1INT));

    if((event_type == TEN_APS_DETECT_VALUE_CHANGED) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm1int.bf.APSCHI   = 1;
    else if((event_type == TEN_APS_DETECT_VALUE_UNSTABLE) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm1int.bf.APSUNSTI = 1;

    ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OOHR_TCM1INT, tmp_n10g_oohr_tcm1int.wrd, TEN_IRQ_DIR_UP);
  }

  if((monitor_layer == TEN_OOHR_TCM2_LAYER) || (monitor_layer == TEN_OOHR_ALL_LAYERS)) {
    ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OOHR_TCM2INT, ten_10g_oohr_otu2_aps_pcc_handler);
    tmp_n10g_oohr_tcm2int.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, TCM2INT));

    if((event_type == TEN_APS_DETECT_VALUE_CHANGED) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm2int.bf.APSCHI   = 1;
    else if((event_type == TEN_APS_DETECT_VALUE_UNSTABLE) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm2int.bf.APSUNSTI = 1;

    ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OOHR_TCM2INT, tmp_n10g_oohr_tcm2int.wrd, TEN_IRQ_DIR_UP);
  }

  if((monitor_layer == TEN_OOHR_TCM3_LAYER) || (monitor_layer == TEN_OOHR_ALL_LAYERS)) {
    ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OOHR_TCM3INT, ten_10g_oohr_otu2_aps_pcc_handler);
    tmp_n10g_oohr_tcm3int.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, TCM3INT));

    if((event_type == TEN_APS_DETECT_VALUE_CHANGED) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm3int.bf.APSCHI   = 1;
    else if((event_type == TEN_APS_DETECT_VALUE_UNSTABLE) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm3int.bf.APSUNSTI = 1;

    ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OOHR_TCM3INT, tmp_n10g_oohr_tcm3int.wrd, TEN_IRQ_DIR_UP);
  }

  if((monitor_layer == TEN_OOHR_TCM4_LAYER) || (monitor_layer == TEN_OOHR_ALL_LAYERS)) {
    ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OOHR_TCM4INT, ten_10g_oohr_otu2_aps_pcc_handler);
    tmp_n10g_oohr_tcm4int.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, TCM4INT));

    if((event_type == TEN_APS_DETECT_VALUE_CHANGED) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm4int.bf.APSCHI   = 1;
    else if((event_type == TEN_APS_DETECT_VALUE_UNSTABLE) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm4int.bf.APSUNSTI = 1;

    ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OOHR_TCM4INT, tmp_n10g_oohr_tcm4int.wrd, TEN_IRQ_DIR_UP);
  }

  if((monitor_layer == TEN_OOHR_TCM5_LAYER) || (monitor_layer == TEN_OOHR_ALL_LAYERS)) {
    ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OOHR_TCM5INT, ten_10g_oohr_otu2_aps_pcc_handler);
    tmp_n10g_oohr_tcm5int.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, TCM5INT));

    if((event_type == TEN_APS_DETECT_VALUE_CHANGED) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm5int.bf.APSCHI   = 1;
    else if((event_type == TEN_APS_DETECT_VALUE_UNSTABLE) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm5int.bf.APSUNSTI = 1;

    ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OOHR_TCM5INT, tmp_n10g_oohr_tcm5int.wrd, TEN_IRQ_DIR_UP);
  }

  if((monitor_layer == TEN_OOHR_TCM6_LAYER) || (monitor_layer == TEN_OOHR_ALL_LAYERS)) {
    ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OOHR_TCM6INT, ten_10g_oohr_otu2_aps_pcc_handler);
    tmp_n10g_oohr_tcm6int.wrd = TEN_REG_READ(TEN_N10G_OOHR_REG_ADDR (pDev, module_id, slice, TCM6INT));

    if((event_type == TEN_APS_DETECT_VALUE_CHANGED) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm6int.bf.APSCHI   = 1;
    else if((event_type == TEN_APS_DETECT_VALUE_UNSTABLE) ||(event_type == TEN_APS_DETECT_VALUE_CHANGED_AND_UNSTABLE))
      tmp_n10g_oohr_tcm6int.bf.APSUNSTI = 1;

    ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OOHR_TCM6INT, tmp_n10g_oohr_tcm6int.wrd, TEN_IRQ_DIR_UP);
  }
  return (CS_OK);
}
/* Bugzilla 29997 End */
