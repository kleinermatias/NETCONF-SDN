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
 * ten_irq_thread.c
 *
 * Interrupt related code is implemented here.
 *
 * $Id: ten_irq_thread.c,v 1.32 2013/02/22 20:44:29 jccarlis Exp $
 *
 */

#include "ten_irq_tree.h"
#include "ten_irq.h"
#include <util.h>

/* bugzilla #24439, klocwork, no ret value  */
/* bugzilla #26154, manage thread activity with compile switch  */
#if TEN_IRQ_THREAD_ENABLE
/****************************************************************/
/* CATEGORY   : Interupt Request Polling Thread                 */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
void *irq_polling_thread(void *arg)
/* INPUTS     : o None                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : None                                            */
/* DESCRIPTION:                                                 */
/* Thread that will poll the interrupt requests                 */
/*                                                              */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 dev_id = 0;
  cs_uint16 count = 0;
  cs_char8 *func = "irq_polling_thread";

  TEN_DEV_COMMON_VALIDATE_INTERNAL (dev_id, &pDev);

  JUST_LOG_1(LOG_INFO, "T41", "%s()  IRQ polling thread active\n", func);
  while (1) {
    g_pTEN->drvr_flag |= TEN_DRVR_LOG_SUSPEND;  /* Suspend driver logging */
    /* CS_PRINT("%s(%d) Poll IRQ ISR\n", func, count); */
    ten_irq_isr (dev_id);

    count ++;
    g_pTEN->drvr_flag &= ~TEN_DRVR_LOG_SUSPEND; /* Resume driver logging */
    /* Bugzilla #28471, minimum delay */
    TEN_MDELAY_PRINT_OPT(1000, FALSE);  /* Bugzilla 29751, and rel 5.5 print suppressed */
  }
  pthread_exit(NULL);
}
#endif

/****************************************************************/
/* CATEGORY   : Interupt Handler                                */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
void ten_sadeco_n40g_deskew_error_handler (ten_irq_handler_data_t handler_data)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Handle the Sadeco Sync intrerrupt in order to resolve the    */
/* N40G TX Deskew error when it occures.                        */
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/****************************************************************/
{
  cs_uint16 dev_id;
  cs_uint16 module_id;
  TEN_XCON_SADECO_SADSTAT_t tmp_sadeco_sadstat;
  TEN_N40G_GBL4X_GBLINT_t tmp_n40g_gbl4x_gblint;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_sadeco_n40g_deskew_error_handler";  
  volatile cs_reg *tmp_addr;

  dev_id = handler_data.dev_id;
  module_id =  (handler_data.slice < 1) ? TEN_MODULE_A : TEN_MODULE_B;

  TEN_DEV_COMMON_VALIDATE_INTERNAL (dev_id, &pDev);

  CS_PRINT("%s() %s\n", func, ten_module_strings[module_id & 1]);

  /* Poll sync status */

  /* bugzilla #24439, klocwork */
  tmp_addr = TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADSTAT, (module_id & 1));
  tmp_sadeco_sadstat.wrd = TEN_REG_READ(tmp_addr);
  if (tmp_sadeco_sadstat.bf.SYNC) {
    /* Sync status has gone from inactive to active */
    /*CS_PRINT("%s() Sadeco Sync statis is active for %s\n", func, ten_module_strings[module_id & 1]);*/

    /* Poll N40G TX Desckew Error */

    /* bugzilla #24439, klocwork */
    tmp_addr = TEN_N40G_REG_ADDR (pDev, 0, GBLINT);
    tmp_addr += (module_id & 0x0001) * TEN_N40G_STRIDE;
    tmp_n40g_gbl4x_gblint.wrd = TEN_REG_READ(tmp_addr);
    if (tmp_n40g_gbl4x_gblint.bf.TXDSKERR) {
      /* N40G TX Desckew Error is active */
      /*CS_PRINT("%s() TXDSKERR is active for %s, so clear it\n", func, ten_module_strings[module_id & 1]);*/
      /* Clear bit from initial setup */
      tmp_n40g_gbl4x_gblint.wrd = 0;
      tmp_n40g_gbl4x_gblint.bf.TXDSKERR = 1;
      TEN_REG_WRITE(tmp_addr, tmp_n40g_gbl4x_gblint.wrd);

      /* Bugzilla #28471, minimum delay */
      TEN_MDELAY(6); /* 0.000125 seconds wait for a Sonet frame */

      /* Read it again to see if it is still set */
      tmp_n40g_gbl4x_gblint.wrd = TEN_REG_READ(tmp_addr);
      if (tmp_n40g_gbl4x_gblint.bf.TXDSKERR) {
        /* N40G has detected deskew error is persistent, so force recync frame alignment in sadeco */
        CS_PRINT("%s() TXDSKERR is persistent for %s, so resync Sadeo frame alignment!\n", func, ten_module_strings[module_id & 1]);
        ten_xcon_sadeco_resync (dev_id, (module_id & 1));
      }
      else {
        /*CS_PRINT("%s() TXDSKERR was NOT persistent for %s, so disregard it\n", func, ten_module_strings[module_id & 1]);*/
      }
    }
  }
}

/****************************************************************/
/* $rtn_hdr_start  SADECO N40G DESKEW ERROR HANDLER ENABLE      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_sadeco_n40g_deskew_error_handler_enable (cs_uint16 module_id)
/* INPUTS     : o Module Id                                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable Sadeco Sync interrup handler for N40G TX Deskew error */
/* resolution                                                   */
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  TEN_XCON_SADECO_SADINTE_t tmp_sadeco_sadinte;

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  /* Register the interrupt handler for the XCON_SADECO_SADINT register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_XCON_SADECO_SADINT, ten_sadeco_n40g_deskew_error_handler);

  /* Enable the SYNCI interrupt in the  XCON_SADECO_SADINT register and enable the
     propagation of this interrupt all the way up the interrupt tree */
  tmp_sadeco_sadinte.wrd = 0;
  tmp_sadeco_sadinte.bf.SYNCIE = 1;
  ten_mod_irq_enable (module_id, 0, &TEN_IRQ_NODE_XCON_SADECO_SADINT, tmp_sadeco_sadinte.wrd, TEN_IRQ_DIR_UP);
  return (CS_OK);
}

/* Bugzilla 24419 Start */
/****************************************************************/
/* $rtn_hdr_start  LOF RECOVERY ERROR HANDLER ENABLE            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_lof_recovery_error_handler_enable (cs_uint16 module_id,
                                                 cs_uint8  slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable interrupt handler for OTNR LOF error resolution.      */
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t                 *pDev = NULL;
  cs_uint16             dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  TEN_N10G_OTNR_INTRE_t tmp_n10g_otnr_intre;
  volatile cs_reg       *tmp_addr;
  cs_boolean            n10g_active;

  CS_PRINT("ten_lof_recovery_error_handler_enable: mod_id=0x%04X, sl=%d\n",
           module_id, slice);

  /* Determine if n10g is active */
  n10g_active = ten_mpif_n10g_rx_is_active(module_id, slice);

  /* Do not enable if n10g is in reset */
  if (!n10g_active) {
      CS_PRINT("Framer is in reset - do not enable recovery sequence.\n");
      return (CS_OK);
  }

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  /* Clear N10G_OTNR_INTR interrupts */
  tmp_addr  = TEN_N10G_REG_ADDR(pDev, module_id, slice, otnr_INTR);
  /* tmp_addr += slice * TEN_N10G_STRIDE; */
  TEN_REG_WRITE(tmp_addr, 0xFFFF);

  /* Register the interrupt handler for the N10G_OTNR_INTR register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_OTNR_INTR, ten_hl_config_perform_recovery_sequence);

  /* Enable the ILOF interrupt in the  N10G_OTNR_INTR register and enable the
     propagation of this interrupt all the way up the interrupt tree */
  tmp_n10g_otnr_intre.wrd = 0;
  tmp_n10g_otnr_intre.bf.ILOFE = 1;
  ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_OTNR_INTR, tmp_n10g_otnr_intre.wrd, TEN_IRQ_DIR_UP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  DLOS RECOVERY ERROR HANDLER ENABLE           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_dlos_recovery_error_handler_enable (cs_uint16 module_id,
                                                  cs_uint8  slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable interrupt handler for dLOS error resolution.          */
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  TEN_N10G_GBLR_INTRE_t tmp_n10g_gblr_intre;
  volatile cs_reg *tmp_addr;
  cs_boolean            n10g_active;

  CS_PRINT("ten_dlos_recovery_error_handler_enable: mod_id=0x%04X, sl=%d\n",
           module_id, slice);

  /* Determine if n10g is active */
  n10g_active = ten_mpif_n10g_rx_is_active(module_id, slice);

  /* Do not enable if n10g is in reset */
  if (!n10g_active) {
      CS_PRINT("Framer is in reset - do not enable recovery sequence.\n");
      return (CS_OK);
  }

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  /* Configure LOSCFG to interrupt on all-zeros or all-ones (0x0002) */
  ten_n10g_gblr_loscfg0(module_id, slice, 2);

  /* Clear TEN_N10G_GLBR_INTR interrupts */
  tmp_addr  = TEN_N10G_REG_ADDR(pDev, module_id, slice, gblr_INTR);
  /* tmp_addr += slice * TEN_N10G_STRIDE; */
  TEN_REG_WRITE(tmp_addr, 0xFFFF);

  /* Register the interrupt handler for the N10G_GBLR_INTR register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_N10G_GBLR_INTR, ten_hl_config_perform_recovery_sequence);

  /* Enable the LOSFC interrupt in the  N10G_GBLR_INTR register and enable the
     propagation of this interrupt all the way up the interrupt tree */
  tmp_n10g_gblr_intre.wrd = 0;
  tmp_n10g_gblr_intre.bf.LOSFCE = 1;
  ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_N10G_GBLR_INTR, tmp_n10g_gblr_intre.wrd, TEN_IRQ_DIR_UP);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  PCS RECOVERY ERROR HANDLER ENABLE            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_pcs_recovery_error_handler_enable (cs_uint16 module_id,
                                                 cs_uint8  slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable interrupt handler for PCS loss error resolution.      */
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  TEN_PP10G_PCS_RX_RXINTENABLE_t tmp_pp10g_pcs_rx_rxintenable;
  volatile cs_reg *tmp_addr;
  cs_boolean                     pp10g_active;

  CS_PRINT("ten_pcs_recovery_error_handler_enable: mod_id=0x%04X, sl=%d\n",
           module_id, slice);

  /* Determine if pp10g is active */
  pp10g_active = ten_mpif_pp10g_rx_is_active(module_id, slice);

  /* Do not enable if the pp10g is in reset */
  if (!pp10g_active) {
      CS_PRINT("PCS is in reset - do not enable recovery sequence.\n");
      return (CS_OK);
  }

  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  /* Clear TEN_PP10G_PCS_RX_RXINTENABLE interrupts */
  tmp_addr  = TEN_PP10G_PCS_REG_ADDR(pDev, module_id, slice, RXINT);
  /* tmp_addr += slice * TEN_PP10G_STRIDE; */
  TEN_REG_WRITE(tmp_addr, 0xFFFF);

  /* Register the interrupt handler for the TEN_PP10G_PCS_RX_RXINT register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_PP10G_PCS_RX_RXINT, ten_hl_config_perform_recovery_sequence);

  /* Enable the syncdet interrupt in the  TEN_PP10G_PCS_RX_RXINT register and enable the
     propagation of this interrupt all the way up the interrupt tree */
  tmp_pp10g_pcs_rx_rxintenable.wrd = 0;
  tmp_pp10g_pcs_rx_rxintenable.bf.syncdetE = 1;
  ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_PP10G_PCS_RX_RXINT, tmp_pp10g_pcs_rx_rxintenable.wrd, TEN_IRQ_DIR_UP);

  return (CS_OK);
}
/* Bugzilla 24419 End */

/* Bug 28921 start */
/****************************************************************/
/* $rtn_hdr_start  HOLDOVER RECOVERY ERROR HANDLER ENABLE       */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : HIGH LEVEL                                      */
/* CHIP       : Tenabo                                          */
cs_status ten_holdover_recovery_error_handler_enable (cs_uint16 module_id,
                                                      cs_uint8  slice)
/* INPUTS     : o Module Id                                     */
/*              o Slice                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable interrupt handler for CUPLL holdover error resolution.*/
/*                                                              */
/* [module_id] specifies line's module ID                       */
/*   0xXX00 = Module A                                          */
/*   0xXX01 = Module B                                          */
/*                                                              */
/* The [slice] parameter is specified as:                       */
/*   0x00 = TEN_SLICE0                                          */
/*   0x01 = TEN_SLICE1                                          */
/*   0x02 = TEN_SLICE2                                          */
/*   0x03 = TEN_SLICE3                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_uint16 dev_id = TEN_MOD_ID_TO_DEV_ID(module_id);
  TEN_MPIF_CUPLL_HOLDOVER_INTENABLE_t tmp_mpif_cupll_holdover_intenable;
  volatile cs_reg *tmp_addr;
  cs_uint16 tmp_data;

  CS_PRINT("ten_holdover_recovery_error_handler_enable: mod_id=0x%04X, sl=%d\n",
           module_id, slice);


  TEN_DEV_COMMON_VALIDATE (dev_id, pDev, CS_ERROR);

  /* Clear TEN_MPIF_CUPLL_HOLDOVER_INTENABLE interrupts */
  tmp_addr  = TEN_MPIF_REG_ADDR(pDev, CUPLL_HOLDOVER_INTERRUPT);
  TEN_REG_WRITE(tmp_addr, 0xFFFF);

  /* Enable the REVi interrupt in the  TEN_MPIF_CUPLL_HOLDOVER_INTERRUPT register and enable the
     propagation of this interrupt all the way up the interrupt tree */
  tmp_data = 1<<slice;
  tmp_mpif_cupll_holdover_intenable.wrd = 0;
  tmp_mpif_cupll_holdover_intenable.bf.REVe = tmp_data;
  ten_mod_irq_enable (module_id, slice, &TEN_IRQ_NODE_MPIF_CUPLL_HOLDOVER_INTERRUPT, tmp_mpif_cupll_holdover_intenable.wrd, TEN_IRQ_DIR_UP);

  /* Set the "follow" bit (select=2) */
  ten_mpif_cupll_local_force_t41(dev_id, slice, 2, 1);
  /* Set the holdover select register - the CUPLL uses its own holdover alarm */
  ten_mpif_cupll_holdover_select(dev_id, slice, (module_id*4+slice));

  /* Register the interrupt handler for the TEN_MPIF_CUPLL_HOLDOVER_INTERRUPT register */
  ten_irq_register_handler (dev_id, &TEN_IRQ_NODE_MPIF_CUPLL_HOLDOVER_INTERRUPT, ten_hl_config_perform_cupll_recovery_sequence);

  return (CS_OK);
}
/* Bug 28921 end */

