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
 * ten_xcon.c
 *
 * API's for XCON block.
 *
 * $Id: ten_xcon.c,v 1.41 2013/02/22 20:48:11 jccarlis Exp $
 *
 */
 
#include "tenabo40.h"




/****************************************************************/
/* $rtn_hdr_start   XCON CONTROL DATAPATH SOFT (LOGIC) RESET    */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_datapath_reset(cs_uint16 dev_id, 
                                  cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Reset Control                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control reset on the cross connect's (XCON) datapath.        */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XCON_GLB_RESET_t tmp_glb_reset;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(act > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_datapath_reset Param2"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  tmp_glb_reset.wrd = 0;
  tmp_glb_reset.bf.ACTIVE_RESET = 1;
  ten_reset_action(TEN_XCON_REG_ADDR(pDev, RESET), tmp_glb_reset.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON ELASTIC STORE SOURCE SELECT             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_es_select_source(cs_uint16 dev_id,
                                    ten_xcon_es_num_t es_num,
                                    ten_xcon_channel_num_t chnl_num,
                                    ten_xcon_interface_t chnl_if)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Elastic Store Input Channel                   */
/*              o N10G or PP10G input                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Controls what input to the XCON block gets sent to the ES0-7 */
/* It chooses for the specified ES (es_num) what input stream   */
/* of data will be used as the source for the write side of the */
/* elastic store.                                               */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*                                                              */
/* The [chnl_num] parameter is specified as:                    */
/*   0 = XCON_MODULE_A_CHANNEL_1                                */
/*   1 = XCON_MODULE_A_CHANNEL_2                                */
/*   2 = XCON_MODULE_A_CHANNEL_3                                */
/*   3 = XCON_MODULE_A_CHANNEL_4                                */
/*   4 = XCON_MODULE_B_CHANNEL_1                                */
/*   5 = XCON_MODULE_B_CHANNEL_2                                */
/*   6 = XCON_MODULE_B_CHANNEL_3                                */
/*   7 = XCON_MODULE_B_CHANNEL_4                                */
/*                                                              */
/* The [chnl_if] parameter is specified as:                     */
/*   0 = XCON_N10G                                              */
/*   1 = XCON_PP10G                                             */
/*                                                              */
/* NOTE: RX Threshold select is programmed by this API and is   */
/*       the exact opposite of ES source select.                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  volatile cs_reg *regaddr ;
  TEN_XCON_GLB_INTERFACE_SELECT_t tmp_glb_interface_select;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xcon_es_select_source";  

  /* Parameter Checking */
  if (es_num > XCON_ELASTIC_STORE_7) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_num %d out of range.  s/b 0..7.", func, es_num); 
    return CS_ERROR; 
  }

  if (chnl_num > XCON_MODULE_B_CHANNEL_4) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() chnl_num %d out of range.  s/b 0..7.", func, chnl_num); 
    return CS_ERROR; 
  }

  if (chnl_if > XCON_PP10G) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() chnl_if %d out of range.  s/b 0..1.", func, chnl_if);
    return CS_ERROR; 
  }

  CS_PRINT("%s()  %s i.e. %s, %s i.e. %s, %s\n", 
           func, ten_xcon_es_num_strings[es_num], ten_xcon_es_mod_slice_strings[es_num], 
           ten_xcon_input_strings[chnl_num], ten_xcon_es_mod_slice_strings[chnl_num], 
           ten_xcon_interface_strings[chnl_if]);

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  /* Select input channel for elastic store #n */
  regaddr = TEN_XCON_ES_SOURCE_SEL_REG_ADDR(pDev, es_num);
  TEN_REG_WRITE(regaddr, chnl_num);

  /* RX threshold select */
  /* This has to be the reverse of ES source select */
  regaddr = TEN_XCON_RX_THRSHLD_SEL_REG_ADDR(pDev, chnl_num);
  TEN_REG_WRITE(regaddr, es_num);

  /* if channel source input*/
  tmp_glb_interface_select.wrd = TEN_REG_READ(TEN_XCON_REG_ADDR(pDev, INTERFACE_SELECT));
  if(chnl_if == XCON_N10G)
    tmp_glb_interface_select.wrd &= ~(1 << es_num);
  else
    tmp_glb_interface_select.wrd |= 1 << es_num;
  TEN_REG_WRITE(TEN_XCON_REG_ADDR(pDev, INTERFACE_SELECT), tmp_glb_interface_select.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON ELASTIC STORE SOURCE SELECT NO RX THRESH */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_es_select_source_no_rx_thresh(cs_uint16 dev_id,
                                    ten_xcon_es_num_t es_num,
                                    ten_xcon_channel_num_t chnl_num,
                                    ten_xcon_interface_t chnl_if)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Elastic Store Input Channel                   */
/*              o N10G or PP10G input                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Controls what input to the XCON block gets sent to the ES0-7 */
/* It chooses for the specified ES (es_num) what input stream   */
/* of data will be used as the source for the write side of the */
/* elastic store.  The RX Thresholds are not programmed.        */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*                                                              */
/* The [chnl_num] parameter is specified as:                    */
/*   0 = XCON_MODULE_A_CHANNEL_1                                */
/*   1 = XCON_MODULE_A_CHANNEL_2                                */
/*   2 = XCON_MODULE_A_CHANNEL_3                                */
/*   3 = XCON_MODULE_A_CHANNEL_4                                */
/*   4 = XCON_MODULE_B_CHANNEL_1                                */
/*   5 = XCON_MODULE_B_CHANNEL_2                                */
/*   6 = XCON_MODULE_B_CHANNEL_3                                */
/*   7 = XCON_MODULE_B_CHANNEL_4                                */
/*                                                              */
/* The [chnl_if] parameter is specified as:                     */
/*   0 = XCON_N10G                                              */
/*   1 = XCON_PP10G.                                            */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  volatile cs_reg *regaddr ;
  TEN_XCON_GLB_INTERFACE_SELECT_t tmp_glb_interface_select;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if (es_num > XCON_ELASTIC_STORE_7) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_select_source Param2"); 
    return CS_ERROR; 
  }

  if (chnl_num > XCON_MODULE_B_CHANNEL_4) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_select_source Param3"); 
    return CS_ERROR; 
  }

  if (chnl_if > XCON_PP10G) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_select_source Param4"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  /* Select input channel for elastic store #n */
  regaddr = TEN_XCON_ES_SOURCE_SEL_REG_ADDR(pDev, es_num);
  TEN_REG_WRITE(regaddr, chnl_num);

  /* if channel source input */
  tmp_glb_interface_select.wrd = TEN_REG_READ(TEN_XCON_REG_ADDR(pDev, INTERFACE_SELECT));
  if(chnl_if == XCON_N10G)
    tmp_glb_interface_select.wrd &= ~(1 << es_num);
  else
    tmp_glb_interface_select.wrd |= 1 << es_num;
  TEN_REG_WRITE(TEN_XCON_REG_ADDR(pDev, INTERFACE_SELECT), tmp_glb_interface_select.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ELASTIC STORE RX THRESHOLD SELECT           */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_rx_threshold_select(cs_uint16 dev_id, 
                                          cs_uint16 input,
                                          cs_uint16 source)
/* INPUTS     : o Device Id                                         */
/*              o Input Select                                      */
/*              o ES Source                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Selects the ES receive thresholds for the specified XCON input.  */
/*                                                                  */
/* [input] parameter is specified as:  (0..7)                       */
/*                                                                  */
/* [source] parameter is specified as:                              */
/*   Selects the elastic store (0..7) to provide receive            */
/*   threshold status for XCON input selected.                      */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_XCON_GLB_ES_RX_THRESHOLD_SELECT_0_t tmp_glb_es_rx_threshold_select_0;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xcon_es_rx_threshold_select";  

  /* Parameter Checking */
  if (input >= TEN_XCON_ES_COUNT) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() input %d out of range.  s/b 0..7.", func, input); 
    return (CS_ERROR); 
  }
  if (source >= TEN_XCON_ES_COUNT) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() source %d out of range.  s/b 0..7.", func, source); 
    return (CS_ERROR); 
  }

  CS_PRINT("%s()  %s i.e. %s, %s i.e. %s\n", 
           func, ten_xcon_input_strings[input], ten_xcon_es_mod_slice_strings[input],
           ten_xcon_es_num_strings[source], ten_xcon_es_mod_slice_strings[source]);
  
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  /* bugzilla #24439, klocwork */
  tmp_addr = TEN_XCON_RX_THRSHLD_SEL_REG_ADDR(pDev, input);
  tmp_glb_es_rx_threshold_select_0.wrd = TEN_REG_READ(tmp_addr);
  tmp_glb_es_rx_threshold_select_0.bf.SOURCE = source;
  TEN_REG_WRITE(tmp_addr, tmp_glb_es_rx_threshold_select_0.wrd);
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON ELASTIC STORE SELECT READ SOURCE        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_es_select_read_source(cs_uint16 dev_id,
                                            ten_xcon_channel_num_t chnl_num,
                                            ten_xcon_source_t source)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Input Channel                   */
/*              o Read Source Select                            */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the Read Source Select.                                 */
/*                                                              */
/* The [chnl_num] parameter is specified as:                    */
/*   0 = XCON_MODULE_A_CHANNEL_1                                */
/*   1 = XCON_MODULE_A_CHANNEL_2                                */
/*   2 = XCON_MODULE_A_CHANNEL_3                                */
/*   3 = XCON_MODULE_A_CHANNEL_4                                */
/*   4 = XCON_MODULE_B_CHANNEL_1                                */
/*   5 = XCON_MODULE_B_CHANNEL_2                                */
/*   6 = XCON_MODULE_B_CHANNEL_3                                */
/*   7 = XCON_MODULE_B_CHANNEL_4                                */
/*                                                              */
/* The [source] parameter selects the ES read side driver for   */
/* side A/B                                                     */
/*   0 = XCON_BERT_OFF (Normal data flow from ES)               */
/*   1 = XCON_CBERT                                             */
/*   2 = XCON_PBERT                                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XCON_GLB_ES_RD_SELECT_t tmp_glb_es_rd_select;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(chnl_num > XCON_MODULE_B_CHANNEL_4) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_cs_xcon_es_select_source Param2"); 
    return CS_ERROR; 
  }
  if(source > XCON_PBERT) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_cs_xcon_es_select_source Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  /* Select channel source for normal data flow */
  tmp_glb_es_rd_select.wrd = TEN_REG_READ(TEN_XCON_REG_ADDR(pDev, ES_RD_SELECT));
  tmp_glb_es_rd_select.wrd &= ~(3 << (chnl_num*2));
  tmp_glb_es_rd_select.wrd |= source << (chnl_num*2);
  TEN_REG_WRITE(TEN_XCON_REG_ADDR(pDev, ES_RD_SELECT), tmp_glb_es_rd_select.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start XCON SELECT ELASTIC STORE PAUSE QUANTA SOURCE */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_select_es_pause_quanta_source(cs_uint16 dev_id,
                                                 ten_xcon_tx_channel_t chnl_num,
                                                 ten_xcon_channel_num_t pause_quanta_chnl)
/* INPUTS     : o Device Id                                     */
/*              o Tx Channel                                    */
/*              o Pause Quanta Channel Selection                */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Controls which pause quanta input is directed to the         */
/* specifed transmit channel.                                   */
/*                                                              */
/* The [chnl_num] parameter is specified as:                    */
/*   0    = XCON_TX_CHANNEL_0                                   */
/*   1    = XCON_TX_CHANNEL_1                                   */
/*   2    = XCON_TX_CHANNEL_2                                   */
/*   3    = XCON_TX_CHANNEL_3                                   */
/*   4    = XCON_TX_CHANNEL_4                                   */
/*   5    = XCON_TX_CHANNEL_5                                   */
/*   6    = XCON_TX_CHANNEL_6                                   */
/*   7    = XCON_TX_CHANNEL_7                                   */
/*   0xFF = XCON_TX_CHANNEL_ALL                                 */
/*                                                              */
/* The [pause_quanta_chnl] parameter is specified as:           */
/*   0 = XCON_MODULE_A_CHANNEL_1                                */
/*   1 = XCON_MODULE_A_CHANNEL_2                                */
/*   2 = XCON_MODULE_A_CHANNEL_3                                */
/*   3 = XCON_MODULE_A_CHANNEL_4                                */
/*   4 = XCON_MODULE_B_CHANNEL_1                                */
/*   5 = XCON_MODULE_B_CHANNEL_2                                */
/*   6 = XCON_MODULE_B_CHANNEL_3                                */
/*   7 = XCON_MODULE_B_CHANNEL_4                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_GLB_ES_QUANTA_SELECT_0_t tmp_glb_es_quanta_select_0;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((chnl_num > XCON_TX_CHANNEL_7) && (chnl_num != XCON_TX_CHANNEL_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_select_es_pause_quanta_source Param2"); 
    return CS_ERROR; 
  }
  if(pause_quanta_chnl > XCON_MODULE_B_CHANNEL_4) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_select_es_pause_quanta_source Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_GLB_ES_QUANTA_SELECT_0_COUNT; ii++) {
    if ((chnl_num == ii) || (chnl_num == XCON_TX_CHANNEL_ALL)) {

      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_XCON_REG_ADDR(pDev, ES_QUANTA_SELECT_0);
      tmp_addr += ii * TEN_XCON_GLB_ES_QUANTA_SELECT_0_STRIDE;
      tmp_glb_es_quanta_select_0.wrd = TEN_REG_READ(tmp_addr);
      tmp_glb_es_quanta_select_0.bf.SOURCE = pause_quanta_chnl;
      TEN_REG_WRITE(tmp_addr, tmp_glb_es_quanta_select_0.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  XCON SET ES PAUSE FRAME WATERMARK LEVEL      */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_set_es_pause_frame_watermark_level(cs_uint16 dev_id,
                                                      ten_xcon_es_num_t es_num,
                                                      ten_xcon_pause_wmark_level_t level,
                                                      cs_uint16 value)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Watermark Level                               */
/*              o Watermark Value                               */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the Elastic Stores's pause frame watermark level.       */
/* Levels 0-1 correspond to the levels at which the pause       */
/* signal tells the Tx Packet processor that the ES is filling  */
/* up. These levels are used to know when to send Pause packets */
/* back to the device the stream was received from. Use         */
/* PAUSE_THRESHOLD_SELECT to tell each Tx packet processor      */
/* which of the elastic stores to monitor the pause levels      */
/* from.   The unit is words of 4 bytes. The depth of the       */
/* FIFO is 8192 entries.                                        */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [level] parameter is specified as:                       */
/*   0 = XCON_PAUSE_LEVEL_0                                     */
/*   1 = XCON_PAUSE_LEVEL_1                                     */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   Number of words full in the ES at which to signal pause    */
/*   frame threshold crossing                                   */
/*  0 - 0x1FFF                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_es_pause_frame_watermark_level Param2"); 
    return CS_ERROR; 
  }
  if(level > XCON_PAUSE_LEVEL_1) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_es_pause_frame_watermark_level Param3"); 
    return CS_ERROR; 
  }

  if(value > 8191) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_es_pause_frame_watermark_level Param4"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_GLB_ES_0_PAUSE_LEVEL_0_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      TEN_REG_WRITE(TEN_XCON_ES_PS_LVL_REG_ADDR(pDev, ii, level), value);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  XCON SET ES PAUSE FRAME THRESHOLD SELECT     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_set_es_pause_threshold_select(cs_uint16 dev_id,
                                                 ten_xcon_es_num_t es_num,
                                                 ten_xcon_channel_num_t chnl_num)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Channel Number                                */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Controls which ES feeds the pause frame thresholds to each   */
/* packet processor - used to generate Pause Packets based on   */
/* ES levels.                                                   */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [chnl_num] parameter is specified as:                    */
/*   0 = XCON_MODULE_A_CHANNEL_1                                */
/*   1 = XCON_MODULE_A_CHANNEL_2                                */
/*   2 = XCON_MODULE_A_CHANNEL_3                                */
/*   3 = XCON_MODULE_A_CHANNEL_4                                */
/*   4 = XCON_MODULE_B_CHANNEL_1                                */
/*   5 = XCON_MODULE_B_CHANNEL_2                                */
/*   6 = XCON_MODULE_B_CHANNEL_3                                */
/*   7 = XCON_MODULE_B_CHANNEL_4                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;

  /* Parameter Checking */
    if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_es_pause_threshold_select Param2"); 
    return CS_ERROR; 
  }
  if(chnl_num > XCON_MODULE_B_CHANNEL_4) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_es_pause_threshold_select Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
        TEN_REG_WRITE(TEN_XCON_ES_PS_TH_SEL_REG_ADDR(pDev, ii), chnl_num);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  XCON SET ES WATERMARK LEVEL                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_set_es_watermark_level(cs_uint16 dev_id,
                                          ten_xcon_es_num_t es_num,
                                          ten_xcon_threshold_level_t level,
                                          cs_uint16 value)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Threshold Level                               */
/*              o Threshold Value                               */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Sets the Elastic Stores's watermark level.  Levels 0-4       */
/* correspond to the level at which the rx_above signal says    */
/* that the ES is filling up. Level 5 controls the tx_below     */
/* threshold.  The unit is words of 4 bytes. The depth of the   */
/* FIFO is 8192 entries. (rate adaptation)                      */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [level] parameter is specified as:                       */
/*   0 = XCON_THRESHOLD_LEVEL_0                                 */
/*   1 = XCON_THRESHOLD_LEVEL_1                                 */
/*   2 = XCON_THRESHOLD_LEVEL_2                                 */
/*   3 = XCON_THRESHOLD_LEVEL_3                                 */
/*   4 = XCON_THRESHOLD_LEVEL_4                                 */
/*   5 = XCON_THRESHOLD_LEVEL_5                                 */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   Number of words full in the ES at which to signal          */
/*   threshold crossing                                         */
/*   0 - 0x1FFF                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xcon_set_es_watermark_level";  

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_num %d is out of range.  s/b 0..7 or 255.", func, es_num); 
    return CS_ERROR; 
  }
  if(level > XCON_THRESHOLD_LEVEL_5) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() level %d is out of range.  s/b 0..5.", func, level); 
    return CS_ERROR; 
  }
  if(value > 8191) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() value %d is out of range.  s/b 0..8191.", func, value); 
    return CS_ERROR; 
  }

  CS_PRINT("%s()  %s i.e. %s, level = %d, value = %d\n", 
           func, ten_xcon_es_num_strings[es_num], ten_xcon_es_mod_slice_strings[es_num], 
           level, value); 

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_5_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      TEN_REG_WRITE(TEN_XCON_ES_TH_LVL_REG_ADDR(pDev, ii, level), value);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  XCON SELECT BERT                             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_select_bert(cs_uint16 dev_id,
                               ten_xcon_channel_num_t chnl_num,
                               ten_xcon_source_t source)
/* INPUTS     : o Device Id                                     */
/*              o Channel Num                                   */
/*              o Source                                        */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures datapath muxes such that data from the BERT is    */
/* sent instead of ES data.  (Note:  Configure the PACKET BERT  */
/* separately to generate data).                                */
/*                                                              */
/* The [chnl_num] parameter is specified as:                    */
/*   0 = XCON_MODULE_A_CHANNEL_1                                */
/*   1 = XCON_MODULE_A_CHANNEL_2                                */
/*   2 = XCON_MODULE_A_CHANNEL_3                                */
/*   3 = XCON_MODULE_A_CHANNEL_4                                */
/*   4 = XCON_MODULE_B_CHANNEL_1                                */
/*   5 = XCON_MODULE_B_CHANNEL_2                                */
/*   6 = XCON_MODULE_B_CHANNEL_3                                */
/*   7 = XCON_MODULE_B_CHANNEL_4                                */
/*                                                              */
/* The [source] parameter is specified as:                      */
/*   0 = XCON_BERT_OFF,                                         */
/*   1 = XCON_CBERT,                                            */
/*   2 = XCON_PBERT                                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XCON_GLB_BERT_CONFIG_t tmp_glb_bert_config;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(chnl_num > XCON_MODULE_B_CHANNEL_4) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_select_bert Param2"); 
    return CS_ERROR; 
  }
  if(source > XCON_PBERT) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_select_bert Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  tmp_glb_bert_config.wrd = TEN_REG_READ(TEN_XCON_REG_ADDR(pDev, BERT_CONFIG));
  tmp_glb_bert_config.wrd &= ~(3 << (chnl_num*2));
  tmp_glb_bert_config.wrd |= source << (chnl_num*2);
  TEN_REG_WRITE(TEN_XCON_REG_ADDR(pDev, BERT_CONFIG), tmp_glb_bert_config.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON ES GET CAPTURE RESULT                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_get_capture_depth_result(cs_uint16 dev_id,
                                            ten_xcon_capture_result_t capture_num)
/* INPUTS     : o Device Id                                     */
/*              o Capture Result Index Number                   */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Issues a command to capture each of the ES depths at a       */
/* single point in time so that uP read delays do not           */
/* complicate depth comparisons and records the value of the    */
/* depth for a given fifo at the moment the capture command is  */
/* issued.                                                      */
/*                                                              */
/* The [capture_num] parameter is specified as:                 */
/*   0 = XCON_CAPTURE_RESULT_0                                  */
/*   1 = XCON_CAPTURE_RESULT_1                                  */
/*   2 = XCON_CAPTURE_RESULT_2                                  */
/*   3 = XCON_CAPTURE_RESULT_3                                  */
/*   4 = XCON_CAPTURE_RESULT_4                                  */
/*   5 = XCON_CAPTURE_RESULT_5                                  */
/*   6 = XCON_CAPTURE_RESULT_6                                  */
/*   7 = XCON_CAPTURE_RESULT_7                                  */
/*   0xFF = XCON_CAPTURE_RESULT_ALL                             */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  cs_reg *regaddr ;
  cs_uint16 result;
  TEN_XCON_GLB_ES_CAPTURE_COMMAND_t tmp_glb_es_capture_command;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((capture_num > XCON_CAPTURE_RESULT_7) && (capture_num != XCON_CAPTURE_RESULT_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_get_capture_depth_result Param2"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  tmp_glb_es_capture_command.wrd = TEN_REG_READ(TEN_XCON_REG_ADDR(pDev, ES_CAPTURE_COMMAND));
  tmp_glb_es_capture_command.bf.CAPTURE = 1;
  TEN_REG_WRITE(TEN_XCON_REG_ADDR(pDev, ES_CAPTURE_COMMAND), tmp_glb_es_capture_command.wrd);

  regaddr = (cs_reg *)TEN_XCON_REG_ADDR(pDev, ES_CAPTURE_RESULT_0);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((capture_num == ii) || (capture_num == XCON_CAPTURE_RESULT_ALL)) {
    
      /* bugzilla #24439, klocwork */
      tmp_addr = regaddr;
      tmp_addr += ii;
      result = TEN_REG_READ(tmp_addr);
      CS_PRINT("ES%d Captured FIFO Depth = 0x%x\n", ii, result); 
    }
  }

  tmp_glb_es_capture_command.wrd = TEN_REG_READ(TEN_XCON_REG_ADDR(pDev, ES_CAPTURE_COMMAND));
  tmp_glb_es_capture_command.bf.CAPTURE = 0;
  TEN_REG_WRITE(TEN_XCON_REG_ADDR(pDev, ES_CAPTURE_COMMAND), tmp_glb_es_capture_command.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON ELASTIC STORE SOFT (LOGIC) RESET        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_es_reset(cs_uint16 dev_id, 
                            ten_xcon_es_num_t es_num,
                            cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Reset Control                                 */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control XCON sub-block logic reset for the specified         */
/* datapath direction.                                          */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_ES_RESET_t tmp_es_reset;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_reset Param2"); 
    return CS_ERROR; 
  }
  if(act > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_reset Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_es_reset.wrd = 0;
      tmp_es_reset.bf.RESET = 1;
      
      /* bugzilla #28734, klocwork */
      ten_reset_action(TEN_XCON_ES_INST_REG_ADDR(pDev, RESET, ii), tmp_es_reset.wrd, act);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON CONFIGURE ELASTIC STORE MODE            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_config_es_mode(cs_uint16 dev_id,
                                  ten_xcon_es_num_t es_num,
                                  ten_xcon_mfp_mode_t mfp_mode,
                                  ten_xcon_gfp_mode_t gfp_mode,
                                  ten_xcon_sf_mode_t sf_mode,
                                  ten_xcon_pkt_mode_t pkt_mode)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o MFP Mode                                      */
/*              o GFP Mode                                      */
/*              o Store & Forward/Cut Through Mode              */
/*              o Circuit / Packet Mode                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Setup the corrsponding elastic store configuration           */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [mfp_mode] parameter is specified as follows:            */
/*   0 = XCON_FP  (Frame pulse)                                 */
/*   1 = XCON_MFP (Multi Frame pulse)                           */
/*                                                              */
/* The [gfp_mode] parameter allows GFP traffic to pass through  */
/* and is specified as:                                         */
/*   0 = XCON_NO_GFP                                            */
/*   1 = XCON_GFP                                               */
/*                                                              */
/* The [sf_mode] parameter is specified as:                     */
/*   0 = XCON_MODE_CUT_THRU                                     */
/*       Cut-Through based on the IML OR a complete packet.     */
/*   1 = XCON_MODE_STORE_FWD                                    */
/*       Strict Store-and-Forward based on SOP / EOP.           */
/*                                                              */
/* The [pkt_mode] parameter is specified as:                    */
/*   0 = XCON_MODE_CCT                                          */
/*       FIFO Mode of operation is Circuit (raw data)           */
/*   1 = XCON_MODE_PKT                                          */
/*       FIFO Mode of operation is Packet (sop / eop)           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_ES_CONFIG_t tmp_es_config;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_config_es_mode Param2"); 
    return CS_ERROR; 
  }
  if (mfp_mode > XCON_MFP) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_config_es_mode Param3"); 
    return CS_ERROR; 
  }
  if (gfp_mode > CS_ENABLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_config_es_mode Param4"); 
    return CS_ERROR; 
  }
  if (sf_mode > XCON_MODE_STORE_FWD) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_config_es_mode Param5"); 
    return CS_ERROR; 
  }
  if (pkt_mode > XCON_MODE_PKT) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_config_es_mode Param6"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
    
      /* bugzilla #28734, klocwork (one line) */
      tmp_addr = TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii);
      tmp_es_config.wrd = TEN_REG_READ(tmp_addr);
      tmp_es_config.bf.MFP_MODE = mfp_mode;
      tmp_es_config.bf.GFP_MODE = gfp_mode;
      tmp_es_config.bf.SF_MODE = sf_mode;
      tmp_es_config.bf.PKT_MODE = pkt_mode;
      TEN_REG_WRITE(tmp_addr, tmp_es_config.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  XCON SELECT CIRCUIT MODE CENTERING           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_select_es_packet_centering(cs_uint16 dev_id, 
                                              ten_xcon_es_num_t es_num,
                                              ten_xcon_center_type_t type,
                                              cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Centering Option                              */
/*              o Control                                       */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the specified circuit mode centering option              */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [type] parameter is specified as:                        */
/*   0 = XCON_AUTO_CENTER                                       */
/*       If the FIFO spills (overflow/underflow), recenter the  */
/*       FIFO to a depth of IML words.                          */
/*   1 = XCON_FORCE_CENTER                                      */
/*       Immediately force the FIFO to recenter around the IML  */
/*       threshold.                                             */
/*   2 = XCON_RECENTER_LOWER                                    */
/*       If the FIFO crosses under the CIRCUIT_THRESHOLD_LOWER  */
/*       value, recenter the FIFO to a depth of IML words.      */
/*   3 = XCON_RECENTER_UPPER                                    */
/*       If the FIFO crosses over the CIRCUIT_THRESHOLD_LOWER   */
/*       value, recenter the FIFO to a depth of IML words.      */
/*   4 = XCON_PKT_CENTERING_ALL (AUTO)                          */
/*       Set all parameters to same value.                      */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_ES_CONFIG_t tmp_es_config;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xcon_select_es_packet_centering";  

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_num %d out of range", func, es_num); 
    return CS_ERROR; 
  }
  if(type > XCON_PKT_CENTERING_ALL) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() type %d out of range", func, type); 
    return CS_ERROR; 
  }
  if(ctl > CS_ENABLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG,"%s() ctl %d out of range", func, ctl); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  CS_PRINT("%s() %s, %s , %s\n", func, ten_xcon_es_mod_slice_strings[es_num], ten_xcon_center_type_strings[type], ten_ctrl_strings[ctl]);

  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_es_config.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii) );

      switch(type) {
        case XCON_AUTO_CENTER:
          tmp_es_config.bf.AUTO_CENTER = ctl;
          break;

        case XCON_FORCE_CENTER:
          tmp_es_config.bf.FORCE_CENTER = ctl;
          break;

        case XCON_RECENTER_LOWER:
          tmp_es_config.bf.AUTO_RECENTER_LOWER = ctl; 
          break;

        case XCON_RECENTER_UPPER:
          tmp_es_config.bf.AUTO_RECENTER_UPPER = ctl;
          break;

        case (XCON_PKT_CENTERING_ALL):
          tmp_es_config.bf.AUTO_CENTER = ctl;
          tmp_es_config.bf.AUTO_RECENTER_LOWER = ctl; 
          tmp_es_config.bf.AUTO_RECENTER_UPPER = ctl;  
          break;
      }

      TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii), tmp_es_config.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  XCON SET CIRCUIT MODE FIFO THRESHOLDS        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_set_circuit_thresholds(cs_uint16 dev_id, 
                                          ten_xcon_es_num_t es_num,
                                          ten_xcon_circuit_threshold_t type, 
                                          cs_uint16 value)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Circuit Threshold                             */
/*              o Value                                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the specified circuit mode FIFO threshold.               */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [type] parameter is specified as:                        */
/*   0 = XCON_ES_IML_THRESH                                     */
/*   1 = XCON_ES_CIRCUIT_THRESHOLD_UPPER                        */
/*   2 = XCON_ES_CIRCUIT_THRESHOLD_LOWER                        */
/*                                                              */
/* The [value] parameter is specified as:                       */
/*   Value of FIFO threshold.                                   */
/*   0 - 0x1FFF                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_circuit_thresholds Param2"); 
    return CS_ERROR; 
  }
  if(type > XCON_ES_CIRCUIT_THRESHOLD_LOWER) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_circuit_thresholds Param3"); 
    return CS_ERROR; 
  }
  if(value > 8191) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_circuit_thresholds Param4"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      if(type == XCON_ES_IML_THRESH) {
        TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, IML_THRESH, ii), value);
      }
      else if (type == XCON_ES_CIRCUIT_THRESHOLD_UPPER) {
        TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, CIRCUIT_THRESHOLD_UPPER, ii), value);
      }
      else {
        TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, CIRCUIT_THRESHOLD_LOWER, ii), value);
      }
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CONFIGURES THE PACKET BERT MODE              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_set_pbert_mode(cs_uint16 dev_id, 
                                  ten_xcon_es_num_t es_num,
                                  ten_xcon_traffic_type_t traffic,
                                  ten_xcon_pbert_profile_t profile)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Traffic Type                                  */
/*              o Profile Selection                             */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the TX/RX PACKET BERT mode                        */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [traffic] parametr is specified as:                      */
/*   0 = XCON_TRAFFIC_FRAME                                     */
/*   1 = XCON_TRAFFIC_ORDERED_SETS                              */
/*                                                              */
/* The [profile] parameter is specified as:                     */
/*   0 = XCON_PBERT_PROFILE_ETH_0                               */
/*       Ethernet : Transport of MAC frames (DA/SA/../FCS)      */
/*   1 = XCON_PBERT_PROFILE_ETH_1                               */
/*       Ethernet : Transport of MAC frames (DA/SA/../FCS) and  */
/*                  Ordered Sets                                */
/*   2 = XCON_PBERT_PROFILE_ETH_2                               */
/*       Ethernet : Transport of entire MAC frames              */
/*                  (Preamble/SFD/DA/SA/../FCS) and Ordered Sets*/
/*   3 = XCON_PBERT_PROFILE_ETH_3                               */
/*       Ethernet : Transparent transport via the IEEE          */
/*                  Std 802.3-2005 Clause 49 PCS transmitter    */
/*   4 = XCON_PBERT_PROFILE_ETH_4                               */
/*       Ethernet : Transparent transport via the IEEE          */
/*                  Std 802.3-2005 Clause 47/48 XAUI transmitter*/
/*   5 = XCON_PBERT_PROFILE_GFP_S                               */
/*       GFP-F    : transport of MAC frames (DA/SA/../FCS)      */
/*   6 = XCON_PBERT_PROFILE_GFP_T                               */
/*       GFP-T    : transparent transport of entire MAC frames  */
/*                  (Preamble/SFD/DA/SA/../FCS) and Ordered Sets*/
/*   7 = XCON_PBERT_PROFILE_FC                                  */
/*       Fibre Channel : Transport of FC frames (SOF/../EOF),   */
/*                       Primitive Signals & Primitive Sequences*/
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_RX_MODE_t tmp_pbert_rx_mode;
  TEN_XCON_PBERT_TX_MODE_t tmp_pbert_tx_mode;
  TEN_XCON_PBERT_RX_PCTRL_FR_t tmp_pbert_rx_pctrl_fr;
  TEN_XCON_PBERT_TX_PCTRL_FR_t tmp_pbert_tx_pctrl_fr;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_pbert_mode Param2"); 
    return CS_ERROR; 
  }
  if(traffic > XCON_TRAFFIC_ORDERED_SETS) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_pbert_mode Param3"); 
    return CS_ERROR;
  }
  if(profile > XCON_PBERT_PROFILE_FC) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_pbert_mode Param4"); 
    return CS_ERROR;
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      /* Select profile */
      tmp_pbert_rx_mode.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_MODE, ii));

      tmp_pbert_rx_mode.bf.traffic = traffic;
      tmp_pbert_rx_mode.bf.profile = profile;

      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_MODE, ii), tmp_pbert_rx_mode.wrd);

      tmp_pbert_tx_mode.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_MODE, ii));

      tmp_pbert_tx_mode.bf.traffic = traffic;
      tmp_pbert_tx_mode.bf.profile = profile;

      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_MODE, ii), tmp_pbert_tx_mode.wrd);
                     
      /*  When asserted, invert the PRBS23 sequence before insertion into the frame. */
      /*  When MODE[profile]=FC, the prbs_inv configuration of the                   */
      /*  PBert Rx and Tx must be opposite, ie rx=0/tx=1 or rx=1/tx=0.               */
      if (profile == XCON_PBERT_PROFILE_FC) {                               
        tmp_pbert_rx_pctrl_fr.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_PCTRL_FR, ii));
        tmp_pbert_rx_pctrl_fr.bf.prbs_inv = 1;
        TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_PCTRL_FR, ii), tmp_pbert_rx_pctrl_fr.wrd);
                                      
        tmp_pbert_tx_pctrl_fr.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_PCTRL_FR, ii));
        tmp_pbert_tx_pctrl_fr.bf.prbs_inv = 0;
        TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_PCTRL_FR, ii), tmp_pbert_tx_pctrl_fr.wrd);
      }                             
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  CONFIGURES THE PACKET BERT PROTOCOL          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_set_pbert_protocol(cs_uint16 dev_id,
                                      ten_xcon_es_num_t es_num,
                                      ten_xcon_fc_sof_t sof_delimiter,
                                      ten_xcon_fc_eof_t eof_delimiter, 
                                      ten_xcon_da_type_t da_type)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Start of Frame Delimiter                      */
/*              o End of Frame Delimiter                        */
/*              o Detination Address Type                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the TX/RX PACKET BERT protocol settings           */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [sof_delimiter] parameter is specified as:               */
/*   Fiber Channel (Framing and Signalling)                     */
/*   0  = XCON_SOF_CONNECT_CLASS1                               */
/*   1  = XCON_SOF_INITIATE_CLASS1                              */
/*   2  = XCON_SOF_NORMAL_CLASS1                                */
/*   3  = XCON_SOF_INITIATE_CLASS2                              */
/*   4  = XCON_SOF_NORMAL_CLASS2                                */
/*   5  = XCON_SOF_INITIATE_CLASS3                              */
/*   6  = XCON_SOF_NORMAL_CLASS3                                */
/*   7  = XCON_SOF_ACTIVATE_CLASS4                              */
/*   8  = XCON_SOF_INITIATE_CLASS4                              */
/*   9  = XCON_SOF_NORMAL_CLASS4                                */
/*   10 = XCON_SOF_FABRIC                                       */
/*                                                              */
/* The [eof_delimiter] parameter is specified as:               */
/*   0 = XCON_EOF_TERMINATE                                     */
/*   1 = XCON_EOF_DISCON_TERMINATE                              */
/*   2 = XCON_EOF_NORM_TERMINATE                                */
/*   3 = XCON_EOF_REMOVE_TERMINATE                              */
/*   4 = XCON_EOF_ABORT                                         */
/*   5 = XCON_EOF_DISCON_TERMINATE_INVLD_CLASS                  */
/*   6 = XCON_EOF_NORMAL_TERMINATE_INVLD_CLASS                  */
/*   7 = XCON_EOF_REMOVE_TERMINATE_INVLD_CLASS                  */
/*                                                              */
/* The [da_type)] parameter is specified as:                    */
/*   0 = XCON_DA_UCAST                                          */
/*   1 = XCON_DA_MCAST                                          */
/*   2 = XCON_DA_BCAST                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_RX_PROTOCOL_t tmp_pbert_rx_protocol;
  TEN_XCON_PBERT_TX_PROTOCOL_t tmp_pbert_tx_protocol;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_pbert_protocol Param2"); 
    return CS_ERROR; 
  }
  if(sof_delimiter > XCON_SOF_FABRIC) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_pbert_protocol Param3"); 
    return CS_ERROR; 
  }
  if(eof_delimiter > XCON_EOF_REMOVE_TERMINATE_INVLD_CLASS) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_pbert_protocol Param4"); 
    return CS_ERROR; 
  }
  if(da_type > XCON_DA_BCAST) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_set_pbert_protocol Param5"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) { 
      /* Select protocol controls */
      tmp_pbert_rx_protocol.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_PROTOCOL, ii));

      tmp_pbert_rx_protocol.bf.fc_eof = eof_delimiter;
      tmp_pbert_rx_protocol.bf.fc_sof = sof_delimiter;
      tmp_pbert_rx_protocol.bf.eth_da = da_type;

      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_PROTOCOL, ii), tmp_pbert_rx_protocol.wrd);

      tmp_pbert_tx_protocol.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_PROTOCOL, ii));

      tmp_pbert_tx_protocol.bf.fc_eof = eof_delimiter;
      tmp_pbert_tx_protocol.bf.fc_sof = sof_delimiter;
      tmp_pbert_tx_protocol.bf.eth_da = da_type;

      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_PROTOCOL, ii), tmp_pbert_tx_protocol.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON PBERT PRBS RESET                        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pbert_prbs_reset(cs_uint16 dev_id, 
                                    ten_xcon_es_num_t es_num,
                                    cs_dir_t dir,
                                    cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Direction                                     */
/*              o Reset Control                                 */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control XCON PBERT PRBS reset                                */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_RX_PCTRL_FR_t tmp_pbert_rx_pctrl_fr;
  TEN_XCON_PBERT_TX_PCTRL_FR_t tmp_pbert_tx_pctrl_fr;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_prbs_reset Param2"); 
    return CS_ERROR; 
  }
  if(dir > CS_TX_AND_RX) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_prbs_reset Param3"); 
    return CS_ERROR; 
  }
  if(act > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_prbs_reset Param4"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      if((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
        tmp_pbert_rx_pctrl_fr.wrd = 0;
        tmp_pbert_rx_pctrl_fr.bf.prbs_reset = 1;
        ten_reset_action((TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_PCTRL_FR, ii)), tmp_pbert_rx_pctrl_fr.wrd, act);
      }
      if((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
        tmp_pbert_tx_pctrl_fr.wrd = 0;
        tmp_pbert_tx_pctrl_fr.bf.prbs_reset = 1;
        ten_reset_action((TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_PCTRL_FR, ii)), tmp_pbert_tx_pctrl_fr.wrd, act);
      }
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  CONTROL PACKET BERT FRAME PAYLOAD            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_control_pbert_frame_payload(cs_uint16 dev_id,
                                               ten_xcon_es_num_t es_num,
                                               ten_xcon_payload_type_t payload,
                                               cs_ctl_t seqnum_enbl)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Payload Type                                  */
/*              o Enable Sequence Number in First Two Payload   */
/*                Octets                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the BERT TX/RX fixed patterns                     */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [payload] parameter is specified as:                     */
/*   0 = XCON_PAYLOAD_FIXED                                     */ 
/*   1 = XCON_PAYLOAD_PRBS                                      */
/*                                                              */
/* The [seqnum_enbl] parameter is specified as:                 */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_RX_PCTRL_FR_t tmp_pbert_rx_pctrl_fr;
  TEN_XCON_PBERT_TX_PCTRL_FR_t tmp_pbert_tx_pctrl_fr;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_control_pbert_frame_payload Param2"); 
    return CS_ERROR; 
  }
  if(payload > XCON_PAYLOAD_PRBS) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_control_pbert_frame_payload Param3"); 
    return CS_ERROR; 
  }
  if(seqnum_enbl > CS_ENABLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_control_pbert_frame_payload Param4"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) { 
      tmp_pbert_rx_pctrl_fr.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_PCTRL_FR, ii));
      tmp_pbert_rx_pctrl_fr.bf.type = payload;
      tmp_pbert_rx_pctrl_fr.bf.seqnum = seqnum_enbl;

      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_PCTRL_FR, ii), tmp_pbert_rx_pctrl_fr.wrd);

      tmp_pbert_tx_pctrl_fr.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_PCTRL_FR, ii));
      
      tmp_pbert_tx_pctrl_fr.bf.type = payload;
      tmp_pbert_tx_pctrl_fr.bf.seqnum = seqnum_enbl;

      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_PCTRL_FR, ii), tmp_pbert_tx_pctrl_fr.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  CONFIGURES THE PACKET BERT FIXED PATTERN     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pbert_select_fixed_pattern(cs_uint16 dev_id,
                                              ten_xcon_es_num_t es_num,
                                              ten_xcon_fixed_pattern_t type,
                                              cs_uint8 value_n,
                                              cs_uint8 value_n_plus_1)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Pattern Type                                  */
/*              o Pattern Value fpatN                           */
/*              o Pattern Value fpatN+1                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the BERT TX/RX fixed patterns                     */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [type] parameter specifies the pattern type as:          */
/*   0 = XCON_FIXED_PATTERN_01                                  */
/*   1 = XCON_FIXED_PATTERN_23                                  */
/*   2 = XCON_FIXED_PATTERN_45                                  */
/*   3 = XCON_FIXED_PATTERN_67                                  */
/*                                                              */
/* The [value_n] parameter specifies the fixed pattrern N value */
/* where N = 0,2,4,6                                            */
/*   0 - 0xFF                                                   */
/*                                                              */
/* The [value_n_plus_1] parameter specifies the fixed pattrern  */
/* N+1 value where N=1,3,5,7                                    */
/*   0 - 0xFF                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_RX_FPAT01_t tmp_pbert_rx_fpat01;
  TEN_XCON_PBERT_TX_FPAT01_t tmp_pbert_tx_fpat01;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_select_fixed_pattern Param2"); 
    return CS_ERROR; 
  }
  if(type > XCON_FIXED_PATTERN_67) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_select_fixed_pattern Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {

      /* bugzilla #24439, klocwork */
      tmp_addr = TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_FPAT01, ii);
      tmp_pbert_rx_fpat01.wrd = TEN_REG_READ(tmp_addr);
      tmp_pbert_rx_fpat01.bf.fpat1 = value_n_plus_1;
      tmp_pbert_rx_fpat01.bf.fpat0 = value_n;
      TEN_REG_WRITE(tmp_addr, tmp_pbert_rx_fpat01.wrd);
      
      tmp_addr = TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_FPAT01, ii);
      tmp_pbert_tx_fpat01.wrd = TEN_REG_READ(tmp_addr);
      tmp_pbert_tx_fpat01.bf.fpat1 = value_n_plus_1;
      tmp_pbert_tx_fpat01.bf.fpat0 = value_n;
      TEN_REG_WRITE(tmp_addr, tmp_pbert_tx_fpat01.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  CONTROL PACKET BERT UNIT LENGTH              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_control_pbert_unit_len(cs_uint16 dev_id, 
                                          ten_xcon_es_num_t es_num,
                                          ten_xcon_len_mode_t mode, 
                                          cs_uint16 rndmask,
                                          cs_uint16 min_len,
                                          cs_uint16 max_len)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Length Mode                                   */
/*              o Unit Length Mask value                        */
/*              o Minimum Octets Per Unit                       */
/*              o Maximum Octets Per Unit                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the BERT TX unit length control where the word    */
/* *unit* is either a frame or an ordered set set by th API     */
/* ten_xcon_set_pbert_mode() traffic param                      */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [mode] parameter specifies the unit length mode as:      */
/*   0 = XCON_UNIT_LEN_RANDOM                                   */
/*       Random unit length bound by MINLEN/MAXLEN/RNDMASK.     */
/*       The random unit length is generated by using 15 bits   */
/*       of a PRBS23. The 15 bits are masked by RNDMASK and then*/
/*       subjected to a MINLEN/MAXLEN filter.                   */
/*   1 = XCON_UNIT_LEN_LINEAR                                   */
/*       Incrementing unit length MINLEN -> MAXLEN              */
/*       (wrap-around to MINLEN)                                */
/*                                                              */
/* The [mask] parameter selects the random mask value and       */
/* applies only to RANDOM unit length mode                      */
/*   0 - 0x7FFF                                                 */
/*                                                              */
/* The [min_len] parameter selects the unit minimum length value*/
/* (number of octets per unit). For MODE[traffic]=OS unit       */
/* minimum length must satisfy 'minlen % 4 = 0'                 */
/* When ULEN[mode]=LIN, set MINLEN=MAXLEN for fixed length units*/
/*   0 - 0x7FFF                                                 */
/*                                                              */
/* The [max_len] paramter selects the unit maximum length value */
/* (number of octets per unit). For MODE[traffic]=OS, unit      */
/* maximum length must satisfy 'maxlen % 4 = 0'                 */ 
/* When ULEN[mode]=LIN, set MAXLEN=MINLEN for fixed length units*/
/*   0 - 0x7FFF                                                 */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_TX_ULEN_t tmp_pbert_tx_ulen;
  TEN_XCON_PBERT_TX_ULENMIN_t tmp_pbert_tx_ulenmin;
  TEN_XCON_PBERT_TX_ULENMAX_t tmp_pbert_tx_ulenmax;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_control_pbert_unit_len Param2"); 
    return CS_ERROR; 
  }
  if(mode > XCON_UNIT_LEN_LINEAR) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_control_pbert_unit_len Param3"); 
    return CS_ERROR; 
  }
  if(rndmask > 32767) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_control_pbert_unit_len Param4"); 
    return CS_ERROR; 
  }
  if(min_len > 32767) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_control_pbert_unit_len Param5"); 
    return CS_ERROR; 
  }
  if(max_len > 32767) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_control_pbert_unit_len Param6"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_pbert_tx_ulen.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, ULEN, ii));

      tmp_pbert_tx_ulen.bf.mode = mode;
      tmp_pbert_tx_ulen.bf.rndmask = rndmask;
      
      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, ULEN, ii), tmp_pbert_tx_ulen.wrd);

      tmp_pbert_tx_ulenmin.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, ULENMIN, ii));

      tmp_pbert_tx_ulenmin.bf.minlen = min_len;
      
      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, ULENMIN, ii), tmp_pbert_tx_ulenmin.wrd);

      tmp_pbert_tx_ulenmax.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, ULENMAX, ii));

      tmp_pbert_tx_ulenmax.bf.maxlen = max_len;
      
      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, ULENMAX, ii), tmp_pbert_tx_ulenmax.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  CONFIGURE PACKET BERT INTER FRAME GAP        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pbert_control_ifg(cs_uint16 dev_id, 
                                     ten_xcon_es_num_t es_num,
                                     ten_xcon_ifg_symbol_t symbol,
                                     cs_uint16 ifg)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Inter Frame Gap Symbol                        */
/*              o Inter Frame Gap                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the inter-packet gap (the number of coreclk       */
/* cycles to wait between generated packets)                    */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [symbol] paramater selects the ifg symbol specified as:  */
/*   0 = XCON_IFG_SYMBOL_IDLE                                   */
/*       Uses XGMII idle as the ifg symbol                      */
/*   1 = XCON_IFG_SYMBOL_ARBFF                                  */
/*       Uses XGMII ARBff as th ifg symbol                      */
/*                                                              */
/* The [ifg] parameter is the inter frame gap specified as:     */
/*   0 = Line rate                                              */
/*   1 - 0x3FFF columns of inter frame gap                      */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_TX_IFG_t tmp_pbert_tx_ifg;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_control_ifg Param2"); 
    return CS_ERROR; 
  }
    if((symbol > XCON_IFG_SYMBOL_ARBFF) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_control_ifg Param3"); 
    return CS_ERROR; 
  }
    if((ifg > 0x3FFF) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_control_ifg Param4"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      
      tmp_pbert_tx_ifg.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, IFG, ii));

      tmp_pbert_tx_ifg.bf.type = symbol;
      tmp_pbert_tx_ifg.bf.cnt = ifg;
      
      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, IFG, ii), tmp_pbert_tx_ifg.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  PACKET BERT TRAFFIC CONTROL                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pbert_control_traffic(cs_uint16 dev_id, 
                                         ten_xcon_es_num_t es_num,
                                         cs_uint16 units)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Number of Frames or Packets                   */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the number of units where the unit is either      */
/* a frame or an ordered set.                                   */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [units] parameter selects number of units specified as:  */ 
/*   0 = Continuous traffic                                     */
/*   1 - 0xFFFF units                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_TX_UCTRL_t tmp_pbert_tx_uctrl;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_control_traffic Param2"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_pbert_tx_uctrl.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, UCTRL, ii));

      tmp_pbert_tx_uctrl.bf.units = units;
      
      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, UCTRL, ii), tmp_pbert_tx_uctrl.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  INJECT ERROR IN PACKET BERT TRANSMIT STREAM  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pbert_inject_err(cs_uint16 dev_id, 
                                    ten_xcon_es_num_t es_num,
                                    ten_xcon_error_type_t err_type, 
                                    cs_uint16 duration)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Single or Continuous                          */
/*              o Duration                                      */ 
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the PACKET BERT generator to inject errors. If    */
/* Single Error needs to be generated Set the single_err to     */
/* TRUE else errors will be injected continuously for the       */
/* duration specified in microseconds.                          */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [err_type] parameter is specified as:                    */
/*   0 = XCON_CONTINUOUS_PRBS_ERROR                             */
/*   1 = XCON_SINGLE_PRBS_ERROR                                 */
/*   2 = XCON_CONTINUOUS_FCS_ERROR                              */
/*   3 = XCON_SINGLE_FCS_ERROR                                  */
/*                                                              */
/* The [duration] parameter is specified as:                    */
/*   duration (ms) for which errors will be generated           */
/*                                                              */
/* NOTE:  This function might block for the duration if         */
/* continuous errors need to be generated and duration is       */
/* non-zero.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_TX_ERRINS_t tmp_pbert_tx_errins;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_inject_err Param2"); 
    return CS_ERROR; 
  }
  if(err_type > XCON_SINGLE_FCS_ERROR) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_inject_err Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  
  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_pbert_tx_errins.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, ERRINS, ii));

      switch(err_type) {
        case XCON_CONTINUOUS_PRBS_ERROR:
          tmp_pbert_tx_errins.bf.PRBS_ErrC = 1;
          break;

        case XCON_SINGLE_PRBS_ERROR:
          tmp_pbert_tx_errins.bf.PRBS_ErrS = 1;
          break;

        case XCON_CONTINUOUS_FCS_ERROR:
          tmp_pbert_tx_errins.bf.FCS_ErrC = 1;
          break;

        case XCON_SINGLE_FCS_ERROR:
          tmp_pbert_tx_errins.bf.FCS_ErrS = 1;
          break;
      }

      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, ERRINS, ii), tmp_pbert_tx_errins.wrd);
    }
  }

  if((err_type == XCON_CONTINUOUS_PRBS_ERROR) || (err_type == XCON_CONTINUOUS_FCS_ERROR)) {
    TEN_MDELAY(duration);
  }  

  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      switch(err_type) {
        case XCON_CONTINUOUS_PRBS_ERROR:
          tmp_pbert_tx_errins.bf.PRBS_ErrC = 0;
          break;

        case XCON_SINGLE_PRBS_ERROR:
          tmp_pbert_tx_errins.bf.PRBS_ErrS = 0;
          break;

        case XCON_CONTINUOUS_FCS_ERROR:
          tmp_pbert_tx_errins.bf.FCS_ErrC = 0;
          break;

        case XCON_SINGLE_FCS_ERROR:
          tmp_pbert_tx_errins.bf.FCS_ErrS = 0;
          break;
      }

      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, ERRINS, ii), tmp_pbert_tx_errins.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE PACKET BERT GENERATOR         */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pbert_control_generator(cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num,
                                           cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable/Disable the PACKET BERT generator.                    */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* NOTE:  call ten_xcon_pbert_control_traffic() API to          */
/* configure traffic parameters before enabling the generator.  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_TX_GO_t tmp_pbert_tx_go;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_control_generator Param2"); 
    return CS_ERROR; 
  }
  if((ctl > CS_ENABLE) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_control_generator Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_pbert_tx_go.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, GO, ii));

      tmp_pbert_tx_go.bf.go = ctl;
      
      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, GO, ii), tmp_pbert_tx_go.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  PACKET BERT SEQUENCE NUMBER CONTROL          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pbert_control_seq_num(cs_uint16 dev_id,
                                         ten_xcon_es_num_t es_num,
                                         ten_xcon_seqnum_ctrl_t type)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Sequence Number Control                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Action taken by PACKET BERT based on sequence number         */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [type] parameter is specified as:                        */ 
/*   0 = XCON_SEQNUM_RESET                                      */
/*       Sequence number is reset to 0                          */
/*   1 = XCON_SEQNUM_RESYNC_DSBL                                */
/*       The mismatching sequence number value +1 will be the   */
/*       next expected sequence number(exSeqnum(new)=rxSeqnum+1)*/
/*       irregardless of the received                           */
/*       frame's error status.                                  */
/*   2 = XCON_SEQNUM_RESYNC_ENBL                                */
/*       The current expected sequence number value +1 will be  */
/*       the next expected sequence number                      */
/*       (exSeqnum(new)=exSeqnum+1).                            */
/*       NOTE (1 and 2):                                        */
/*       If a received sequence number (rxSeqnum) does not match*/
/*       the expected sequence number (exSeqnum), this config   */
/*       bit determines what sequence number to expect next.    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_RX_PCTRL_FR_t tmp_pbert_rx_pctrl_fr;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_control_seq_num Param2"); 
    return CS_ERROR; 
  }
  if(type > XCON_SEQNUM_RESYNC_ENBL) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_control_seq_num Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) { 
      tmp_pbert_rx_pctrl_fr.wrd = TEN_REG_READ(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_PCTRL_FR, ii));
      if(type == XCON_SEQNUM_RESET)
        tmp_pbert_rx_pctrl_fr.bf.seqnum_reset = 0;

      if(type == XCON_SEQNUM_RESYNC_DSBL)
        tmp_pbert_rx_pctrl_fr.bf.seqnum_resync = 0;
      else if(type == XCON_SEQNUM_RESYNC_ENBL)
        tmp_pbert_rx_pctrl_fr.bf.seqnum_resync = 1;


      TEN_REG_WRITE(TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_PCTRL_FR, ii), tmp_pbert_rx_pctrl_fr.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start   CONFIGURE XCON SADECO SKEW AND DELAY COMP   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status  ten_xcon_sadeco_config(cs_uint16 dev_id,
                                  cs_uint8 block_id,
                                  cs_uint16 es_depth,
                                  cs_uint16 es_skew_length,
                                  ten_xcon_sadeco_fp_type_t fp_type)
/* INPUTS     : o Device Id                                     */
/*              o Block_id                                      */
/*              o Elastic Store Depth                           */
/*              o Skew and Delay Compensation Length            */
/*              o Internal Frame Pulse Distribution Style       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configure the SADECO delay and compensation                  */
/*                                                              */
/* The [block_id] parameter select the SADECO instance specified*/
/* as:                                                          */
/*   0 = Sadeco 0 (ES 0 - 3 TX)                                 */
/*   1 = Sadeco 1 (ES 4 - 7 TX)                                 */
/*                                                              */
/* The [es_depth] parameter adjusts the ES latency upon auto or */
/* manual synchronization. Incrementing ESDEPTH by 1 will delay */
/* the (40 Gbit/s) stream by 128 bits.                          */
/*   0 - 0x1FFF                                                 */
/*                                                              */
/* The [skew_length] parameter specifies the frame length,      */
/* divided by 32 bits, of the frames transferred through the    */
/* elastic store.                                               */
/*   0 - 0x1FFF                                                 */ 
/*                                                              */
/* The frame pulse style parameter is specified as:             */
/*   0 = XCON_SONET_SDH_INACTIVE                                */ 
/*   1 = XCON_SONET_SDH_16                                      */ 
/*   2 = XCON_SONET_SDH_64                                      */ 
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_SADECO_SADCFG0_t tmp_sadeco_sadcfg0;
  TEN_XCON_SADECO_SADCFG1_t tmp_sadeco_sadcfg1;
  TEN_XCON_SADECO_SADCFG3_t tmp_sadeco_sadcfg3;
  T41_t *pDev = NULL;
  cs_char8 *func = "ten_xcon_sadeco_config";  

  /* Parameter Checking */
  if(block_id > 1) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() block_id %d is invalid", func, block_id); 
    return CS_ERROR; 
  }
  if(es_depth > 0x1FFF) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_depth 0x%X is invalid", func, es_depth); 
    return CS_ERROR; 
  }
  if(es_skew_length > 0x1FFF) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_skew_length 0x%X is invalid", func, es_skew_length); 
    return CS_ERROR; 
  }
  if(fp_type > XCON_SONET_SDH_64) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() fp_type 0x%X is invalid", func, fp_type);
    return CS_ERROR; 
  }

  CS_PRINT("%s() %s, es_depth = 0x%X, es_skew_length = 0x%X, %s\n", 
           func, ten_module_strings[block_id], es_depth, es_skew_length, ten_sadeco_fp_type_strings[fp_type]);

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  
  for (ii=0; ii<TEN_XCON_SADECO_COUNT; ii++) {
    if ((block_id == ii) || (block_id == XCON_SADECO_ALL)) {
      tmp_sadeco_sadcfg0.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG0, ii));
      
      tmp_sadeco_sadcfg0.bf.ESDEPTH = es_depth;
      
      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG0, ii), tmp_sadeco_sadcfg0.wrd);

      tmp_sadeco_sadcfg1.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG1, ii));

      tmp_sadeco_sadcfg1.bf.HIGHLIM = es_skew_length;

      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG1, ii), tmp_sadeco_sadcfg1.wrd);
                                    

      tmp_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii));

      if (fp_type == XCON_SONET_SDH_INACTIVE) {
        tmp_sadeco_sadcfg3.bf.SDH16MD = 0;
        tmp_sadeco_sadcfg3.bf.SDH64MD = 0;
      }
      else if (fp_type == XCON_SONET_SDH_16) {
        tmp_sadeco_sadcfg3.bf.SDH16MD = 1;
        tmp_sadeco_sadcfg3.bf.SDH64MD = 0;
      }
      else {
        tmp_sadeco_sadcfg3.bf.SDH16MD = 0;
        tmp_sadeco_sadcfg3.bf.SDH64MD = 1;
      }
      
      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii), tmp_sadeco_sadcfg3.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON SADECO CONTROL                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_sadeco_control(cs_uint16 dev_id, 
                                  cs_uint8 block_id,
                                  cs_ctl_t ctl)
/* INPUTS     : o Device Id                                         */
/*              o Block_id                                          */
/*              o Control                                           */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Switches off the frame pulses used on the read side of the       */
/* elastic store.                                                   */
/*                                                                  */
/* [block_id] parameter selects the SADECO instance:                */
/*   0 = Sadeco 0 (ES 0 - 3 TX)                                     */
/*   1 = Sadeco 1 (ES 4 - 7 TX)                                     */
/*                                                                  */
/* [ctl]  CS_DISABLE = 0, Switches off the frame pulses used        */
/*        on the read side of the elastic store; sets sdcoff = 1.   */
/*        CS_ENABLE = 1, Switches on the frame pulses used on       */
/*        the read side of the ES, sets sdcoff=0.  Additionally,    */
/*        AUTO_CENTER, AUTO_RECENTER_UPPER, and                      */
/*        AUTO_RECENTER_LOWER are set to 0.                         */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_SADECO_SADCFG3_t tmp_sadeco_sadcfg3;
  TEN_XCON_ES_CONFIG_t tmp_es_config;
  T41_t *pDev = NULL;

  if ((block_id >= TEN_XCON_SADECO_COUNT) && (block_id != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..1.");
    return(CS_ERROR);
  }
  
  if(ctl > CS_ENABLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": control out of range."); 
    return CS_ERROR; 
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_SADECO_COUNT; ii++) {
    if ((block_id == ii) || (block_id == TEN_INSTANCE_ALL)) {
      tmp_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii));
      tmp_sadeco_sadcfg3.bf.SDCOFF = (ctl == CS_DISABLE);
      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii), tmp_sadeco_sadcfg3.wrd);
    }
  }
  
  if (ctl == CS_ENABLE) {
    if ((block_id == XCON_SADECO_0) || (block_id == TEN_INSTANCE_ALL)) {
      for (ii=0; ii<4; ii++) {
        tmp_es_config.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii));
        tmp_es_config.bf.AUTO_CENTER = 0;
        tmp_es_config.bf.AUTO_RECENTER_LOWER = 0; 
        tmp_es_config.bf.AUTO_RECENTER_UPPER = 0;  
        TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii), tmp_es_config.wrd);
      }
    }
    
    if ((block_id == XCON_SADECO_1) || (block_id == TEN_INSTANCE_ALL)) {
      for (ii=4; ii<8; ii++) {
        tmp_es_config.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii));
        tmp_es_config.bf.AUTO_CENTER = 0;
        tmp_es_config.bf.AUTO_RECENTER_LOWER = 0; 
        tmp_es_config.bf.AUTO_RECENTER_UPPER = 0;  
        TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii), tmp_es_config.wrd);
        }
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);
  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON SADECO ENABLE  FRAME PULSES                 */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_sadeco_enable_fp(cs_uint16 dev_id, 
                                    cs_uint8 block_id,
                                    cs_ctl_t enable)
/* INPUTS     : o Device Id                                         */
/*              o Block_id                                          */
/*              o Enable                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Switches off the frame pulses used on the read side of the       */
/* elastic store.                                                   */
/*                                                                  */
/* [block_id] parameter selects the SADECO instance:                */
/*   0 = Sadeco 0 (ES 0 - 3 TX)                                     */
/*   1 = Sadeco 1 (ES 4 - 7 TX)                                     */
/*                                                                  */
/* [enable] CS_DISABLE = 0, Switches off the frame pulses used      */
/*          on the read side of the elastic store; sets sdcoff = 1. */
/*          CS_ENABLE = 1, Switches on the frame pulses used on     */
/*          the read side of the ES, sets sdcoff=0.                 */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_SADECO_SADCFG3_t tmp_sadeco_sadcfg3;
  T41_t *pDev = NULL;

  if ((block_id >= TEN_XCON_SADECO_COUNT) && (block_id != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..1.");
    return(CS_ERROR);
  }
  
  if(enable > CS_ENABLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": control out of range."); 
    return CS_ERROR; 
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_SADECO_COUNT; ii++) {
    if ((block_id == ii) || (block_id == TEN_INSTANCE_ALL)) {
      tmp_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii));
      tmp_sadeco_sadcfg3.bf.SDCOFF = (enable == CS_DISABLE);
      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii), tmp_sadeco_sadcfg3.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);
  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON ELASTIC STORE SOFT (LOGIC) RESET        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_sadeco_reset(cs_uint16 dev_id, 
                                cs_uint8 block_id,
                                ten_xcon_sadeco_blk_reset_t rst_block,
                                cs_reset_action_t act)
/* INPUTS     : o Module Id                                     */
/*              o Block_id                                      */
/*              o Sub Block to be reset                         */
/*              o Reset Control                                 */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Control XCON sub-block logic reset for the specified         */
/* datapath direction.                                          */
/*                                                              */
/* The [block_id] parameter select the SADECO instance specified*/
/* as:                                                          */
/*   0 = Sadeco 0 (ES 0 - 3 TX)                                 */
/*   1 = Sadeco 1 (ES 4 - 7 TX)                                 */
/*   0xFF = Both                                                */
/*                                                              */
/* The [rst_block] parameter selects the block to be reset and  */
/* is specified as:                                             */
/*   0 = XCON_BLOCK_RESET                                       */
/*   1 = XCON_FIFO_RESET                                        */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_SADECO_SADCFG3_t tmp_sadeco_sadcfg3;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(block_id > 1) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_sadeco_reset Param2"); 
    return CS_ERROR; 
  }
  if(rst_block > XCON_FIFO_RESET) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_sadeco_reset Param3"); 
    return CS_ERROR; 
  }
  if(act > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_sadeco_reset Param4"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_SADECO_COUNT; ii++) {
    if ((block_id == ii) || (block_id == XCON_SADECO_ALL)) {
      tmp_sadeco_sadcfg3.wrd = 0;

      if(rst_block == XCON_BLOCK_RESET) {
        tmp_sadeco_sadcfg3.bf.SWRST = 1;
        tmp_sadeco_sadcfg3.bf.FIFORST = 0;
      }
      else {
        tmp_sadeco_sadcfg3.bf.SWRST = 0;
        tmp_sadeco_sadcfg3.bf.FIFORST = 1;
      }
      ten_reset_action(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii), tmp_sadeco_sadcfg3.wrd, act);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  SADECO DATA STREAM SELECTION                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_sadeco_sel_data_stream(cs_uint16 dev_id, 
                                          cs_uint8 block_id,
                                          cs_uint8 ref_stream,
                                          cs_uint8 trib_stream)
/* INPUTS     : o Device Id                                     */
/*              o Block Id                                      */
/*              o Reference Stream                              */
/*              o Tributary Stream                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* In Skew and Delay Compensation mode, used to select incoming */
/* reference and tributary streams                              */
/*                                                              */
/* The [block_id] parameter select the SADECO instance specified*/
/* as:                                                          */
/*   0 = Sadeco 0 (ES 0 - 3 TX)                                 */
/*   1 = Sadeco 1 (ES 4 - 7 TX)                                 */
/*   0xFF = Both                                                */
/*                                                              */
/* The [ref_stream] parameter selects the set of incoming data  */
/* streams that serve as references for aligning the newly      */
/* combined 4X stream                                           */
/*   0 through 0xF                                              */
/*                                                              */
/* The [trib_stream] parameter in Skew and Delay Compensation   */
/* mode, RSYMSK defines a set of incoming tributary data streams*/
/* that trigger automatic resynchronization of alignment for    */
/* the newly combined 4X stream                                 */
/*   0 - 0x1F                                                   */
/* NOTE: The bits RSYMSK 0..3 enable resynchronization based on */
/*       data streams 0..3 respectively                         */
/*       Bit 4 enables resynchronization when there is an       */
/* underflow or overflow error condition detected by any of the */
/* elastic stores                                               */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_SADECO_SADCFG3_t tmp_sadeco_sadcfg3;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(block_id > 1) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_sadeco_resync Param2"); 
    return CS_ERROR; 
  }
  if(ref_stream > 0xF) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_sadeco_resync Param2"); 
    return CS_ERROR; 
  }
  if(trib_stream > 0x1F) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_sadeco_resync Param2"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_SADECO_COUNT; ii++) {
    if ((block_id == ii) || (block_id == XCON_SADECO_ALL)) {
      tmp_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii));
      tmp_sadeco_sadcfg3.bf.MSTSEL = ref_stream;
      tmp_sadeco_sadcfg3.bf.RSYMSK = trib_stream;

      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii), tmp_sadeco_sadcfg3.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON SADECO SADCFG3 RSYMSK                       */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_sadeco_sadcfg3_rsymsk(cs_uint16 dev_id, 
                                         cs_uint8 instance, 
                                         cs_uint16 rsymsk)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o RSYMSK                                            */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Sets RSYMSK.                                                     */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..1 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [rsymsk]  RSYMSK defines a set of incoming tributary data      */
/*     streams that trigger automatic resynchronization of          */
/*     alignment for the newly combined 4X stream.                  */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_SADECO_SADCFG3_t tmp_sadeco_sadcfg3;
  T41_t *pDev = NULL;

  if ((instance >= TEN_XCON_SADECO_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..2.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_SADECO_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii));
      tmp_sadeco_sadcfg3.bf.RSYMSK = rsymsk;
      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii), tmp_sadeco_sadcfg3.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  SADECO DATA SKEW DELAY COMP FRAME LENGTH     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_sadeco_skew_delay_comp_len(cs_uint16 dev_id, 
                                              cs_uint8 block_id,
                                              cs_uint16 length)
/* INPUTS     : o Device Id                                     */
/*              o Block Id                                      */
/*              o Delay Compensation Length                     */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Select the delay compensation frame length                   */
/*                                                              */
/* The [block_id] parameter select the SADECO instance specified*/
/* as:                                                          */
/*   0 = Sadeco 0 (ES 0 - 3 TX)                                 */
/*   1 = Sadeco 1 (ES 4 - 7 TX)                                 */
/*   0xFF = Both                                                */
/*                                                              */
/* The [length] parameter specifies the frame length, divided   */
/* by 32 bits, of the frames transferred through the elastic    */
/* store                                                        */
/*   0 - 0xFFFF                                                 */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(block_id > 1) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_sadeco_resync Param2"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_SADECO_COUNT; ii++) {
    if ((block_id == ii) || (block_id == XCON_SADECO_ALL)) {
      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SDCLEN, ii), length);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  RESYNC SADECO FRAME ALIGNMENT                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_sadeco_resync(cs_uint16 dev_id, 
                                 cs_uint8 block_id)
/* INPUTS     : o Device Id                                     */
/*              o Block Id                                      */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Force a mnual resync of the generated frame alignment        */
/*                                                              */
/* The [block_id] parameter select the SADECO instance specified*/
/* as:                                                          */
/*   0 = Sadeco 0 (ES 0 - 3 TX)                                 */
/*   1 = Sadeco 1 (ES 4 - 7 TX)                                 */
/*   0xFF = Both                                                */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_SADECO_SADCFG3_t tmp_sadeco_sadcfg3;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(block_id > 1) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_sadeco_resync Param2"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  
  for (ii=0; ii<TEN_XCON_SADECO_COUNT; ii++) {
    if ((block_id == ii) || (block_id == XCON_SADECO_ALL)) {
      tmp_sadeco_sadcfg3.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii));
      tmp_sadeco_sadcfg3.bf.MANRSY = 1;

      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii), tmp_sadeco_sadcfg3.wrd);
      tmp_sadeco_sadcfg3.bf.MANRSY = 0;

      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADCFG3, ii), tmp_sadeco_sadcfg3.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE CIRCUIT BERT GENERATOR        */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_cbert_control_generator(cs_uint16 dev_id,
                                           ten_xcon_es_num_t es_num,
                                           cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable/Disable the CIRCUIT BERT generator.                   */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_CBERT_ENABLE_t tmp_cbert_enable;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_control_generator Param2"); 
    return CS_ERROR; 
  }
  if(ctl > CS_ENABLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pbert_control_generator Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_CBERT_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_cbert_enable.wrd = TEN_REG_READ(TEN_XCON_CBERT_INST_REG_ADDR(pDev, ENABLE, ii));

      tmp_cbert_enable.bf.GEN_EN = ctl;
      
      TEN_REG_WRITE(TEN_XCON_CBERT_INST_REG_ADDR(pDev, ENABLE, ii), tmp_cbert_enable.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE CIRCUIT BERT CHECKER          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_cbert_control_checker(cs_uint16 dev_id, 
                                         ten_xcon_es_num_t es_num, 
                                         cs_ctl_t ctl)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable/Disable the PACKET BERT checker.                      */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_CBERT_ENABLE_t tmp_cbert_enable;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_ctl_checker Param2"); 
    return CS_ERROR; 
  }
  if(ctl > CS_ENABLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_ctl_checker Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_CBERT_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_cbert_enable.wrd = TEN_REG_READ(TEN_XCON_CBERT_INST_REG_ADDR(pDev, ENABLE, ii));

      tmp_cbert_enable.bf.CHK_EN = ctl;
      
      TEN_REG_WRITE(TEN_XCON_CBERT_INST_REG_ADDR(pDev, ENABLE, ii), tmp_cbert_enable.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  INJECT ERROR IN CIRCUIT BERT TRANSMIT STREAM */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_cbert_inject_err(cs_uint16 dev_id, 
                                    ten_xcon_es_num_t es_num,
                                    ten_xcon_error_type_t err_type,
                                    cs_uint8 num_err_bits,
                                    cs_uint16 duration)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Single or Continuous                          */
/*              o Number of Error Bits for Continuous Error     */
/*              o Duration                                      */ 
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Configures the CIRCUIT BERT generator to inject errors. If   */
/* Single Error needs to be generated Set the single_err to     */
/* TRUE else errors will be injected continuously for the       */
/* duration specified in microseconds.                          */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [err_type] parameter is specified as:                    */
/*   0 = XCON_CONTINUOUS_PRBS_ERROR                             */
/*   1 = XCON_SINGLE_PRBS_ERROR                                 */
/*                                                              */
/* The [num_err_bits] parameter is the number of bits errored   */
/* in every word that is generated and is specified as:         */
/*   0 - 0x1F                                                   */
/*                                                              */
/* The [duration] parameter is specified as:                    */
/*   duration (ms) for which errors will be generated           */
/*                                                              */
/* NOTE:  This function might block for the duration if         */
/* continuous errors need to be generated and duration is       */
/* non-zero.                                                    */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_CBERT_PRBS_CONFIG_t tmp_cbert_prbs_config;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_inject_err Param2"); 
    return CS_ERROR; 
  }
  if(err_type > XCON_SINGLE_PRBS_ERROR) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_inject_err Param3"); 
    return CS_ERROR; 
  }
  if(num_err_bits > 31) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_inject_err Param4"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  
  for (ii=0; ii<TEN_XCON_CBERT_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_cbert_prbs_config.wrd = TEN_REG_READ(TEN_XCON_CBERT_INST_REG_ADDR(pDev, PRBS_CONFIG, ii));

      switch(err_type) {
        case XCON_CONTINUOUS_PRBS_ERROR:
          tmp_cbert_prbs_config.bf.FORCE_CONT_ERROR = num_err_bits;
          break;

        case XCON_SINGLE_PRBS_ERROR:
          tmp_cbert_prbs_config.bf.FORCE_SINGLE_ERROR = 1;
          break;

        case XCON_CONTINUOUS_FCS_ERROR:
        case XCON_SINGLE_FCS_ERROR:
          break;
      }

      TEN_REG_WRITE(TEN_XCON_CBERT_INST_REG_ADDR(pDev, PRBS_CONFIG, ii), tmp_cbert_prbs_config.wrd);
    }
  }

  if(err_type == XCON_CONTINUOUS_PRBS_ERROR) {
    TEN_MDELAY(duration);
  }  

  for (ii=0; ii<TEN_XCON_CBERT_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
    switch(err_type) {
      case XCON_CONTINUOUS_PRBS_ERROR:
        tmp_cbert_prbs_config.bf.FORCE_CONT_ERROR = 0;
        break;

      case XCON_SINGLE_PRBS_ERROR:
        tmp_cbert_prbs_config.bf.FORCE_SINGLE_ERROR = 0;
        break;

      case XCON_CONTINUOUS_FCS_ERROR:
      case XCON_SINGLE_FCS_ERROR:
        break;
    }

    TEN_REG_WRITE(TEN_XCON_CBERT_INST_REG_ADDR(pDev, PRBS_CONFIG, ii), tmp_cbert_prbs_config.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  SET THE CHECKER INTO HUNT STATE              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_cbert_resync(cs_uint16 dev_id, 
                                ten_xcon_es_num_t es_num)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Forces the Checker to re-synchronize                         */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_CBERT_PRBS_CONFIG_t tmp_cbert_prbs_config;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_resync Param2"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  
  for (ii=0; ii<TEN_XCON_CBERT_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_cbert_prbs_config.wrd = TEN_REG_READ(TEN_XCON_CBERT_INST_REG_ADDR(pDev, PRBS_CONFIG, ii));

      tmp_cbert_prbs_config.bf.FORCE_RESYNC = 1;

      TEN_REG_WRITE(TEN_XCON_CBERT_INST_REG_ADDR(pDev, PRBS_CONFIG, ii), tmp_cbert_prbs_config.wrd);

      tmp_cbert_prbs_config.bf.FORCE_RESYNC = 0;

      TEN_REG_WRITE(TEN_XCON_CBERT_INST_REG_ADDR(pDev, PRBS_CONFIG, ii), tmp_cbert_prbs_config.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  CBERT PRBS CONFIGURATION                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_cbert_config(cs_uint16 dev_id,
                                ten_xcon_es_num_t es_num,
                                ten_xcon_prbs_poly_t poly)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o PRBS Polynomial                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Set the Checker into the HUNT state.                         */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [poly] parameter selects between four available PRBS     */
/* generator polynomials                                        */
/*   0 = XCON_PRBS_POLY_DEGREE_07   (2b0-x^07+x^06+1)           */
/*   1 = XCON_PRBS_POLY_DEGREE_15   (2b1-x^15+x^15+1)           */
/*   2 = XCON_PRBS_POLY_DEGREE_23   (2b2-x^23+x^18+1)           */
/*   3 = XCON_PRBS_POLY_DEGREE_31   (2b3-x^31+x^28+1)           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_CBERT_PRBS_CONFIG_t tmp_cbert_prbs_config;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_config Param2"); 
    return CS_ERROR; 
  }
  if((poly > XCON_PRBS_POLY_DEGREE_31) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_config Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  
  for (ii=0; ii<TEN_XCON_CBERT_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_cbert_prbs_config.wrd = TEN_REG_READ(TEN_XCON_CBERT_INST_REG_ADDR(pDev, PRBS_CONFIG, ii));

      tmp_cbert_prbs_config.bf.POLY_SELECT = poly;

      TEN_REG_WRITE(TEN_XCON_CBERT_INST_REG_ADDR(pDev, PRBS_CONFIG, ii), tmp_cbert_prbs_config.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  CBERT PRBS CONFIG ERROR THRESHOLD            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_cbert_config_err_threshold(cs_uint16 dev_id,
                                ten_xcon_es_num_t es_num,
                                cs_uint8 err_thresh)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Error Threshold                               */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Config Error threshold.                                      */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [err_thresh] parameter is the number of bit errors in a  */
/* given word to force out of sync state                        */
/*   0 - 0x1F                                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_CBERT_PRBS_CONFIG_t tmp_cbert_prbs_config;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_config Param2"); 
    return CS_ERROR; 
  }

  if((err_thresh > 31) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_config Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  
  for (ii=0; ii<TEN_XCON_CBERT_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_cbert_prbs_config.wrd = TEN_REG_READ(TEN_XCON_CBERT_INST_REG_ADDR(pDev, PRBS_CONFIG, ii));
      tmp_cbert_prbs_config.bf.ERR_THRESH = err_thresh;
      TEN_REG_WRITE(TEN_XCON_CBERT_INST_REG_ADDR(pDev, PRBS_CONFIG, ii), tmp_cbert_prbs_config.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON CBERT INT STATUS                            */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_boolean ten_xcon_cbert_get_sync_status(cs_uint16 dev_id, 
                                          ten_xcon_es_num_t es_num)
/* INPUTS     : o Device Id                                         */
/*              o ES Number                                         */
/* OUTPUTS    : ----                                                */
/* RETURNS    : TRUE or FALSE                                       */
/* DESCRIPTION:                                                     */
/* Gets the current state of the synchronization FSM in the PRBS    */
/* checker (SYNC or HUNT).  Returns 0 (out of sync) or 1 (in sync). */
/*                                                                  */
/* The [es_num] parameter is specified as:                          */
/*   0 = XCON_ELASTIC_STORE_0                                       */
/*   1 = XCON_ELASTIC_STORE_1                                       */
/*   2 = XCON_ELASTIC_STORE_2                                       */
/*   3 = XCON_ELASTIC_STORE_3                                       */
/*   4 = XCON_ELASTIC_STORE_4                                       */
/*   5 = XCON_ELASTIC_STORE_5                                       */
/*   6 = XCON_ELASTIC_STORE_6                                       */
/*   7 = XCON_ELASTIC_STORE_7                                       */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_XCON_CBERT_INT_STATUS_t tmp_cbert_int_status;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  if (es_num > XCON_ELASTIC_STORE_7) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_cbert_config Param2"); 
    return (FALSE); 
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, FALSE);
  
  /* bugzilla #24439, klocwork */
  tmp_addr = TEN_XCON_CBERT_INST_REG_ADDR(pDev, INT_STATUS, es_num);
  tmp_cbert_int_status.wrd = TEN_REG_READ(tmp_addr);
  return (tmp_cbert_int_status.bf.SYNCSTATEs == 1);
}


/****************************************************************/
/* $rtn_hdr_start  XCON PBERT RX RESET                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pbert_rx_reset(cs_uint16 dev_id, cs_uint8 instance, 
                                  cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*            : o Instance                                      */
/*              o Action                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Resets the RX PBERT.                                         */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   Specified as 0..7 or TEN_INSTANCE_ALL (0xFF)               */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   CS_RESET_DEASSERT                                          */
/*   CS_RESET_ASSERT                                            */
/*   CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_RX_MODE_t tmp_pbert_rx_mode;
  T41_t *pDev = NULL;

  if ((instance >= TEN_XCON_PBERT_RX_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..8.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_PBERT_RX_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_pbert_rx_mode.wrd = 0;
      tmp_pbert_rx_mode.bf.rxrst = 1;
      ten_reset_action((TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_rx_MODE, ii)), tmp_pbert_rx_mode.wrd, act);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON PBERT TX RESET                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pbert_tx_reset(cs_uint16 dev_id, cs_uint8 instance, 
                                  cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*            : o Instance                                      */
/*              o Action                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Resets the TX PBERT.                                         */
/*                                                              */
/* The [instance] parameter is specified as:                    */
/*   Specified as 0..7 or TEN_INSTANCE_ALL (0xFF)               */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   CS_RESET_DEASSERT                                          */
/*   CS_RESET_ASSERT                                            */
/*   CS_RESET_TOGGLE                                            */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_PBERT_TX_MODE_t tmp_pbert_tx_mode;
  T41_t *pDev = NULL;

  if ((instance >= TEN_XCON_PBERT_TX_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..8.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_PBERT_TX_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_pbert_tx_mode.wrd = 0;
      tmp_pbert_tx_mode.bf.txrst = 1;
      ten_reset_action((TEN_XCON_PBERT_INST_REG_ADDR(pDev, pbert_tx_MODE, ii)), tmp_pbert_tx_mode.wrd, act);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}


/****************************************************************/
/* $rtn_hdr_start  CONFIGURE XCON                               */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_config(cs_uint16 dev_id,
                          ten_xcon_es_num_t es_num,
                          ten_xcon_gfp_mode_t gfp_mode,
                          ten_xcon_sf_mode_t sf_mode,
                          ten_xcon_pkt_mode_t pkt_mode)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o GFP Mode                                      */
/*              o Store & Forward/Cut Through Mode              */
/*              o Circuit / Packet Mode                         */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Setup the corrsponding elastic store configuration           */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [gfp_mode] parameter allows GFP traffic to pass through  */
/* and is specified as:                                         */
/*   0 = XCON_NO_GFP                                            */
/*   1 = XCON_GFP                                               */
/*                                                              */
/* The [sf_mode] parameter is specified as:                     */
/*   0 = XCON_MODE_CUT_THRU                                     */
/*       Cut-Through based on the IML OR a complete packet.     */
/*   1 = XCON_MODE_STORE_FWD                                    */
/*       Strict Store-and-Forward based on SOP / EOP.           */
/*                                                              */
/* The [pkt_mode] parameter is specified as:                    */
/*   0 = XCON_MODE_CCT                                          */
/*       FIFO Mode of operation is Circuit (raw data)           */
/*   1 = XCON_MODE_PKT                                          */
/*       FIFO Mode of operation is Packet (sop / eop)           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_ES_CONFIG_t tmp_es_config;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if ((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_config_es_mode Param2"); 
    return CS_ERROR; 
  }
  if (gfp_mode > CS_ENABLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_config_es_mode Param3"); 
    return CS_ERROR; 
  }
  if (sf_mode > XCON_MODE_STORE_FWD) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_config_es_mode Param4"); 
    return CS_ERROR; 
  }
  if (pkt_mode > XCON_MODE_PKT) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_config_es_mode Param5"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_es_config.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii));
      tmp_es_config.bf.GFP_MODE = gfp_mode;
      tmp_es_config.bf.SF_MODE = sf_mode;
      tmp_es_config.bf.PKT_MODE = pkt_mode;

      TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii), tmp_es_config.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  XCON SADECO SET SDCLEN REGISTER              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_sadeco_sdclen(cs_uint16 dev_id,
                                 cs_uint8  block_id, 
                                 cs_uint16 sdclen)
/* INPUTS     : o Device Id                                     */
/*            : o Block ID                                      */
/*              o SDCLEN                                        */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Skew and Delay Compensation Frame Length.                    */
/*                                                              */
/* The [block_id] parameter select the SADECO instance specified*/
/* as:                                                          */
/*   0 = Sadeco 0 (ES 0 - 3 TX)                                 */
/*   1 = Sadeco 1 (ES 4 - 7 TX)                                 */
/*   0xFF = Both                                                */
/*                                                              */
/* The [sdclen] parameter is specified as:                      */
/*   SDCLEN[15:0] Skew and Delay Compensation Length specifies  */
/*   the frame length, divided by 32 bits, of the frames        */
/*   transferred through the elastic store.                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_SADECO_SDCLEN_t tmp_sadeco_sdclen;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((block_id > 1) && (block_id != TEN_INSTANCE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_sadeco_reset Param2"); 
    return CS_ERROR; 
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);

  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_SADECO_COUNT; ii++) {
    if ((block_id == ii) || (block_id == TEN_INSTANCE_ALL)) {
      tmp_sadeco_sdclen.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SDCLEN, ii));
      tmp_sadeco_sdclen.bf.SDCLEN = sdclen;
      TEN_REG_WRITE(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SDCLEN, ii), tmp_sadeco_sdclen.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON SADECO SADSTAT                              */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_int16 ten_xcon_sadeco_sadstat(cs_uint16 dev_id, cs_uint8 block_id)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Returns the  state of SADECO synchronization:                    */
/* 0 = the SADECO is not in sync,                                   */
/* 1 = the SADECO has achieved alignment between the channels.      */
/*                                                                  */
/* [block_id] parameter selects the SADECO instance:                */
/*   0 = Sadeco 0 (ES 0 - 3 TX)                                     */
/*   1 = Sadeco 1 (ES 4 - 7 TX)                                     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  TEN_XCON_SADECO_SADSTAT_t tmp_sadeco_sadstat;
  T41_t *pDev = NULL;

  if (block_id >= TEN_XCON_SADECO_COUNT) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": block_id out of range.  s/b 0..1.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  tmp_sadeco_sadstat.wrd = TEN_REG_READ(TEN_XCON_SADECO_INST_REG_ADDR(pDev, SADSTAT, block_id));
  return (tmp_sadeco_sadstat.bf.SYNC);
}

/****************************************************************/
/* $rtn_hdr_start  XCON SET CIRCUIT THRESHOLD LEVEL             */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_set_circuit_threshold_level_t41(cs_uint16 dev_id,
                                                   cs_uint8 es_index,
                                                   ten_xcon_es_recenter_circuit_types_t threshold_type,
                                                   ten_xcon_circuit_threshold_t         threshold_select,
                                                   cs_uint8                             threshold_index,
                                                   cs_uint16                            threshold_lvalue)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Index                           */
/*              o Threshold Type                                */
/*              o Threshold Select                              */
/*              o Threshold Index                               */
/*              o Threshold Level Value                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* For threshold_type==XCON_ES_RECENTER_IML the                 */
/* the following registers should be set:                       */
/*   XCON_ES_IML_THRESH,                                        */
/*   XCON_ES_CIRCUIT_THRESHOLD_UPPER,                           */
/*   XCON_ES_CIRCUIT_THRESHOLD_LOWER,                           */
/*   XCON_ES_THRESHOLD_LEVEL[0..5]                              */
/* For threshold_type==XCON_ES_RECENTER_AMPLITUDE the           */
/* the following registers should be set:                       */
/*   XCON_ES_IML_THRESH,                                        */
/*   XCON_ES_CIRCUIT_THRESHOLD_UPPER,                           */
/*   XCON_ES_CIRCUIT_THRESHOLD_LOWER,                           */
/*   XCON_ES_MARGIN_UPPER,                                      */
/*   XCON_ES_MARGIN_LOWER,                                      */
/*   XCON_ES_THRESHOLD_LEVEL[0..5]                              */
/*                                                              */
/* The [es_index] parameter is specified as:                    */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [threshold_type] parameter is specified as:              */
/*   0 = XCON_ES_RECENTER_IML                                   */
/*   1 = XCON_ES_RECENTER_AMPLITUDE                             */
/*                                                              */
/* The [threshold_select] parameter is specified as:            */
/*   0 = XCON_ES_IML_THRESH                                     */
/*   1 = XCON_ES_CIRCUIT_THRESHOLD_UPPER                        */
/*   2 = XCON_ES_CIRCUIT_THRESHOLD_LOWER                        */
/*   3 = XCON_ES_MARGIN_UPPER                                   */
/*   4 = XCON_ES_MARGIN_LOWER                                   */
/*   5 = XCON_ES_THRESHOLD_LEVEL                                */
/*                                                              */
/* The [threshold_index] parameter is specified as:             */
/*   For threshold_select==XCON_ES_THRESHOLD_LEVEL,             */
/*     0 = XCON_THRESHOLD_LEVEL_0                               */
/*     1 = XCON_THRESHOLD_LEVEL_1                               */
/*     2 = XCON_THRESHOLD_LEVEL_2                               */
/*     3 = XCON_THRESHOLD_LEVEL_3                               */
/*     4 = XCON_THRESHOLD_LEVEL_4                               */
/*     5 = XCON_THRESHOLD_LEVEL_5                               */
/*   For all other threshold_select, this argument is ignored.  */
/*                                                              */
/* The [threshold_lvalue] parameter is specified as:            */
/*  0 - 0xFFFF                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_status ret_val = CS_OK;
  cs_uint16 ii;

  if (threshold_type == XCON_ES_RECENTER_IML) {
    for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
      if ((es_index == ii) || (es_index == XCON_ELASTIC_STORE_ALL)) {
        switch (threshold_select) {
          case XCON_ES_IML_THRESH: 
            ret_val |= ten_xcon_set_circuit_thresholds(dev_id, es_index,
                                                       XCON_ES_IML_THRESH, 
                                                       threshold_lvalue);
            break;
          case XCON_ES_CIRCUIT_THRESHOLD_UPPER: 
            ret_val |= ten_xcon_set_circuit_thresholds(dev_id, es_index,
                                                       XCON_ES_CIRCUIT_THRESHOLD_UPPER, 
                                                       threshold_lvalue);
            break;
          case XCON_ES_CIRCUIT_THRESHOLD_LOWER: 
            ret_val |= ten_xcon_set_circuit_thresholds(dev_id, es_index,
                                                       XCON_ES_CIRCUIT_THRESHOLD_LOWER, 
                                                       threshold_lvalue);
            break;
          case XCON_ES_THRESHOLD_LEVEL:
            ret_val |= ten_xcon_set_es_watermark_level(dev_id, es_index,
                                                       threshold_index,
                                                       threshold_lvalue);
            break;
          default: 
            CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                               ": ten_xcon_set_circuit_threshold_level_t41 threshold_select"); 
            ret_val = CS_ERROR;
            break;
        }
      }
    }
  }
  else if (threshold_type == XCON_ES_RECENTER_AMPLITUDE) {
    for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
      if ((es_index == ii) || (es_index == XCON_ELASTIC_STORE_ALL)) {
        switch (threshold_select) {
          case XCON_ES_IML_THRESH: 
            ret_val |= ten_xcon_set_circuit_thresholds(dev_id, es_index,
                                                       XCON_ES_IML_THRESH, 
                                                       threshold_lvalue);
            break;
          case XCON_ES_CIRCUIT_THRESHOLD_UPPER: 
            ret_val |= ten_xcon_set_circuit_thresholds(dev_id, es_index,
                                                       XCON_ES_CIRCUIT_THRESHOLD_UPPER, 
                                                       threshold_lvalue);
            break;
          case XCON_ES_CIRCUIT_THRESHOLD_LOWER: 
            ret_val |= ten_xcon_set_circuit_thresholds(dev_id, es_index,
                                                       XCON_ES_CIRCUIT_THRESHOLD_LOWER, 
                                                       threshold_lvalue);
            break;
          case XCON_ES_MARGIN_UPPER: 
            TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
            TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
            TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, MARGIN_UPPER, ii), threshold_lvalue );
            TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);
            break;
          case XCON_ES_MARGIN_LOWER: 
            TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
            TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
            TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, MARGIN_LOWER, ii), threshold_lvalue);
            TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);
            break;
          case XCON_ES_THRESHOLD_LEVEL:
            ret_val |= ten_xcon_set_es_watermark_level(dev_id, es_index,
                                                       threshold_index,
                                                       threshold_lvalue);
            break;
          case XCON_ES_PAUSE_LEVEL:
            ret_val |= ten_xcon_set_es_pause_frame_watermark_level(dev_id, es_index,
                                                                   threshold_index,
                                                                   threshold_lvalue);
            break;
          default: 
            CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                               ": ten_xcon_set_circuit_threshold_level_t41 threshold_select"); 
            ret_val = CS_ERROR;
            break;
        }
      }
    }
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                  ": ten_xcon_set_circuit_threshold_level_t41 threshold_type"); 
    ret_val = CS_ERROR;
  }

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XCON SET PACKET THRESHOLD LEVEL              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_set_packet_threshold_level_t41(cs_uint16 dev_id,
                                                  cs_uint8  es_index,
                                                  ten_xcon_es_recenter_packet_types_t threshold_type,
                                                  ten_xcon_circuit_threshold_t        threshold_select,
                                                  cs_uint8                            threshold_index,
                                                  cs_uint16                           threshold_lvalue)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Index                           */
/*              o Threshold Type                                */
/*              o Threshold Select                              */
/*              o Threshold Index                               */
/*              o Threshold Level Value                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* For threshold_type==XCON_ES_RECENTER_RATE_ADAPT the          */
/* the following registers should be set:                       */
/*   XCON_ES_IML_THRESH,                                        */
/*   XCON_ES_PAUSE_LEVEL[0..1]                                  */
/* For threshold_type==XCON_ES_RECENTER_RATE_ADJUST the         */
/* the following registers should be set:                       */
/*   XCON_ES_IML_THRESH,                                        */
/*   XCON_ES_THRESHOLD_LEVEL[0..5]                              */
/*                                                              */
/* The [es_index] parameter is specified as:                    */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [threshold_type] parameter is specified as:              */
/*   0 = XCON_ES_RECENTER_RATE_ADAPT                            */
/*   1 = XCON_ES_RECENTER_RATE_ADJUST                           */
/*                                                              */
/* The [threshold_select] parameter is specified as:            */
/*   0 = XCON_ES_IML_THRESH                                     */
/*   5 = XCON_ES_THRESHOLD_LEVEL                                */
/*   6 = XCON_ES_PAUSE_LEVEL                                    */
/*                                                              */
/* The [threshold_index] parameter is specified as:             */
/*   For threshold_select==XCON_ES_THRESHOLD_LEVEL,             */
/*     0 = XCON_THRESHOLD_LEVEL_0                               */
/*     1 = XCON_THRESHOLD_LEVEL_1                               */
/*     2 = XCON_THRESHOLD_LEVEL_2                               */
/*     3 = XCON_THRESHOLD_LEVEL_3                               */
/*     4 = XCON_THRESHOLD_LEVEL_4                               */
/*     5 = XCON_THRESHOLD_LEVEL_5                               */
/*   For threshold_select==XCON_ES_PAUSE_LEVEL,                 */
/*     0 = XCON_PAUSE_LEVEL_0                                   */
/*     1 = XCON_PAUSE_LEVEL_1                                   */
/*   For all other threshold_select, this argument is ignored.  */
/*                                                              */
/* The [threshold_lvalue] parameter is specified as:       */
/*  0 - 0xFFFF                                                  */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  cs_uint16 ii;

  if (threshold_type == XCON_ES_RECENTER_RATE_ADAPT) {
    for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
      if ((es_index == ii) || (es_index == XCON_ELASTIC_STORE_ALL)) {
        switch (threshold_select) {
          case XCON_ES_IML_THRESH: 
            ret_val |= ten_xcon_set_circuit_thresholds(dev_id, es_index,
                                                       XCON_ES_IML_THRESH, 
                                                       threshold_lvalue);
            break;
          case XCON_ES_PAUSE_LEVEL:
            ret_val |= ten_xcon_set_es_pause_frame_watermark_level(dev_id, es_index,
                                                                   threshold_index,
                                                                   threshold_lvalue);
            break;
          default: 
            CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                               ": ten_xcon_set_packet_threshold_level_t41 threshold_select"); 
            ret_val = CS_ERROR;
            break;
        }
      }
    }
  }
  else if (threshold_type == XCON_ES_RECENTER_RATE_ADJUST) {
    for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
      if ((es_index == ii) || (es_index == XCON_ELASTIC_STORE_ALL)) {
        switch (threshold_select) {
          case XCON_ES_IML_THRESH: 
            ret_val |= ten_xcon_set_circuit_thresholds(dev_id, es_index,
                                                       XCON_ES_IML_THRESH, 
                                                       threshold_lvalue);
            break;
          case XCON_ES_THRESHOLD_LEVEL:
            ret_val |= ten_xcon_set_es_watermark_level(dev_id, es_index,
                                                       threshold_index,
                                                       threshold_lvalue);
            break;
          default: 
            CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                               ": ten_xcon_set_packet_threshold_level_t41 threshold_select"); 
            ret_val = CS_ERROR;
            break;
        }
      }
    }
  }
  else {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                  ": ten_xcon_set_packet_threshold_level_t41 threshold_type"); 
    ret_val = CS_ERROR;
  }

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XCON ELASTIC STORE THRESHOLD SELECT          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_threshold_select(cs_uint16 dev_id,
                                    cs_uint8  es_index,
                                    cs_uint8  threshold_source,
                                    cs_uint8  threshold_type)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Index                           */
/*              o Threshold Source                              */
/*              o Threshold Type                                */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Selector for threshold selects.                              */
/*                                                              */
/* The [es_index] parameter is specified as:                    */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [threshold_source] parameter is specified as:            */
/*   0 = XCON_MODULE_A_CHANNEL_1                                */
/*   1 = XCON_MODULE_A_CHANNEL_2                                */
/*   2 = XCON_MODULE_A_CHANNEL_3                                */
/*   3 = XCON_MODULE_A_CHANNEL_4                                */
/*   4 = XCON_MODULE_B_CHANNEL_1                                */
/*   5 = XCON_MODULE_B_CHANNEL_2                                */
/*   6 = XCON_MODULE_B_CHANNEL_3                                */
/*   7 = XCON_MODULE_B_CHANNEL_4                                */
/*                                                              */
/* The [threshold_type] parameter is specified as:              */
/*   0 = XCON_ES_RX_THRESHOLD                                   */
/*   1 = XCON_PP_ES_PAUSE_THRESHOLD                             */
/*   2 = XCON_SELECT_ES_PAUSE_QUANTA_SOURCE                     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;
  cs_uint16 ii;

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_index == ii) || (es_index == XCON_ELASTIC_STORE_ALL)) {
      switch(threshold_type) {
        case XCON_ES_RX_THRESHOLD: 
          ret_val |= ten_xcon_es_rx_threshold_select(dev_id, es_index, threshold_source);
          break;
        case XCON_PP_ES_PAUSE_THRESHOLD: 
          ret_val |= ten_xcon_pp_es_pause_threshold_select(dev_id, es_index, threshold_source);
          break;
        case XCON_SELECT_ES_PAUSE_QUANTA_SOURCE: 
          ret_val |= ten_xcon_select_es_pause_quanta_source(dev_id, es_index, threshold_source);
          break;
        default: 
          CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_threshold_select es_index"); 
          ret_val = CS_ERROR;
          break;
      }
    }
  }

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XCON ELASTIC STORE RECENTER                  */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_es_recenter_t41(cs_uint16 dev_id,
                                   cs_uint8  es_index)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Index                           */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Activate 10G recentering.                                    */
/*                                                              */
/* The [es_index] parameter is specified as:                    */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XCON_ES_INTSTATUS_t tmp_amp_recenter_status;
  T41_t *pDev = NULL;
  cs_status ret_val      = CS_OK;
  cs_uint32 msec_elapsed = 0;
  cs_uint32    delay_1st = TEN_XCON_AMP_RECENTER_MSEC_DELAY;
  ten_dev_cb_t *pdevcb   = NULL;

  /* Parameter Checking */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  if (es_index > XCON_ELASTIC_STORE_7) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_recenter_t41 es_index=%d\n", es_index); 
    return CS_ERROR; 
  }

  /* Perform the recenter */
  if ( ten_xcon_select_es_packet_centering(dev_id,
       es_index, XCON_FORCE_CENTER, CS_ENABLE    ) != CS_OK) return CS_ERROR;
  if ( ten_xcon_select_es_packet_centering(dev_id,
       es_index, XCON_FORCE_CENTER, CS_DISABLE   ) != CS_OK) return CS_ERROR;

  /* Wait for amplitude recentering to complete */
  /* Bugzilla 30990 This block rearranged to reduce recenter time */
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb->es_cb[es_index].recenter.type == TEN_XCON_ES_RECENTER_AMP_10G) {
    delay_1st = pdevcb->es_cb[es_index].recenter.parms.amp.duration;
  }
  if (delay_1st > (TEN_DRVR_MDELAY_MIN+2)) {  /* Use TEN_MDELAY only for long delays. */
    delay_1st -= 1;                           /* try to come in a little early.       */
    TEN_MDELAY(delay_1st);
  }
  else {
    /* use a finer resolution timer */
    ten_udelay_hi_res(delay_1st*1000);
  }
  msec_elapsed += ( delay_1st > TEN_DRVR_MDELAY_MIN )   /* Increment elapsed by the greater of   */
                  ? delay_1st : TEN_DRVR_MDELAY_MIN ;   /* delay and sys def TEN_DRVR_MDELAY_MIN */

  do {
    tmp_amp_recenter_status.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, INTSTATUS, es_index) );
    if (tmp_amp_recenter_status.bf.AMPLITUDE_RECENTERs) {
      if (msec_elapsed >= TEN_XCON_AMP_RECENTER_MSEC_TIMEOUT) {
        CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT,
                      ": Elastic Store-%d TIMED OUT WAITING FOR AMPLITUDE RECENTER.\n", es_index);
        ret_val = CS_ERROR;
        break;    /* <<<<<<<<<<<<<<<<<< EARLY LOOP EXIT <<<<<<<<<<<<<<<<<<< */
      }
      ten_udelay_hi_res(TEN_XCON_AMP_RECENTER_MSEC_DELAY*1000);  
      msec_elapsed += ( TEN_XCON_AMP_RECENTER_MSEC_DELAY > TEN_DRVR_MDELAY_MIN ) 
                      ? TEN_XCON_AMP_RECENTER_MSEC_DELAY : TEN_DRVR_MDELAY_MIN ;
    }
  } while (tmp_amp_recenter_status.bf.AMPLITUDE_RECENTERs);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XCON 40G RECENTER                            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_40g_recenter_t41(cs_uint16 dev_id,
                                    cs_uint8  module_num)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Activate monolithic recentering.                             */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XCON_ES_INTSTATUS_t tmp_amp_recenter_status;
  cs_uint16    ii;
  T41_t        *pDev     = NULL;
  cs_status    ret_val   = CS_OK;
  cs_uint32 msec_elapsed = 0;
  cs_uint32    delay_1st = TEN_XCON_AMP_RECENTER_MSEC_DELAY;
  cs_uint16    not_done  = 0;
  ten_dev_cb_t *pdevcb   = NULL;
  cs_char8     esList[48]= "";

  /* Validate args */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  if ((module_num != TEN_MODULE_A) && (module_num != TEN_MODULE_B)) {
    CS_HNDL_ERROR(dev_id, ETEN_MOD_ID_OUT_OF_RANGE,
                  "ten_xcon_40g_recenter_t41(module_num=%d)\n", module_num);
    return (CS_ERROR);
  }

  /* Perform the recenter */
  if ( ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
       XCON_GLB_PP40G_CFG_RECENTER, CS_ENABLE          ) != CS_OK) return CS_ERROR;
  if ( ten_xcon_glb_pp40g_config_t41(dev_id, module_num,
       XCON_GLB_PP40G_CFG_RECENTER, CS_DISABLE         ) != CS_OK) return CS_ERROR;

  /* Wait for amplitude recentering to complete */
  /* Bugzilla 30990 This block rearranged to reduce recenter time */
  pdevcb = TEN_DEV_ID_TO_DEVCB_PTR(dev_id);
  if (pdevcb->es_cb[module_num * 4].recenter.type == TEN_XCON_ES_RECENTER_AMP_40G) {
    delay_1st = pdevcb->es_cb[module_num * 4].recenter.parms.amp.duration;
  }
  if (delay_1st > (TEN_DRVR_MDELAY_MIN+2)) {  /* Use TEN_MDELAY only for long delays. */
    delay_1st -= 1;                           /* try to come in a little early.       */
    TEN_MDELAY(delay_1st);
  }
  else {
    /* use a finer resolution timer */
    ten_udelay_hi_res(delay_1st*1000);
  }
  msec_elapsed += ( delay_1st > TEN_DRVR_MDELAY_MIN )   /* Increment elapsed by the greater of   */
                  ? delay_1st : TEN_DRVR_MDELAY_MIN ;   /* delay and sys def TEN_DRVR_MDELAY_MIN */

  do {
    not_done = 0;
    for (ii=module_num*4; ii<(module_num*4+TEN_XCON_ES_COUNT/2); ii++) {
      tmp_amp_recenter_status.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, INTSTATUS, ii) );
      /* For Monolithic configs we must check recenter status for four ES's */
      not_done |= (tmp_amp_recenter_status.bf.AMPLITUDE_RECENTERs << ii);
    }
    if (not_done) {
      if (msec_elapsed >= TEN_XCON_AMP_RECENTER_MSEC_TIMEOUT) {
        /* Bug 27270, release 5.5, improve error report by logging which ES's didn't recenter.   */
        for (ii=module_num*4; ii<(module_num*4+4); ii++) {  /* OK to re-use ii, exiting do-loop. */
          if ( (1<<ii) & not_done) sprintf(esList, "%s %d", esList, ii);
        }
        CS_HNDL_ERROR(dev_id, ETEN_DRVR_UNEXPECTED_RESULT,
                      ": Module-%d TIMED OUT WAITING FOR AMPLITUDE RECENTER for ES(s)%s.\n", module_num, esList);
        ret_val = CS_ERROR;
        break;    /* <<<<<<<<<<<<<<<<<< EARLY LOOP EXIT <<<<<<<<<<<<<<<<<<< */
      }
      ten_udelay_hi_res(TEN_XCON_AMP_RECENTER_MSEC_DELAY*1000);
      msec_elapsed += ( TEN_XCON_AMP_RECENTER_MSEC_DELAY > TEN_DRVR_MDELAY_MIN ) 
                      ? TEN_XCON_AMP_RECENTER_MSEC_DELAY : TEN_DRVR_MDELAY_MIN ;
    }
  } while (not_done);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XCON PP40G RECENTER                          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pp40g_recenter_t41(cs_uint16 dev_id,
                                      cs_uint8  module_num)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Deprecated.  Same as ten_xcon_40g_recenter_t41().            */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A                                           */
/*   1 = TEN_MODULE_B                                           */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return ten_xcon_40g_recenter_t41(dev_id, module_num);
}

/****************************************************************/
/* $rtn_hdr_start  XCON ELASTIC STORE RECENTER TRIGGER          */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_config_es_recenter_trigger_t41(cs_uint16 dev_id,
                                                  cs_uint8  es_index,
                                                  cs_uint8  type)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Index                           */
/*              o Type                                          */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable recenter triggers.                                    */
/*                                                              */
/* The [es_index] parameter is specified as:                    */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*                                                              */
/* The [type] parameter is specified as:                        */
/*   0 = XCON_MODE_CCT                                          */
/*   1 = XCON_MODE_PKT                                          */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;

  /* Parameter Checking */
  if(type > XCON_MODE_PKT) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_config_es_recenter_trigger_t41 dev_id"); 
    return CS_ERROR; 
  }

  if (type == XCON_MODE_CCT) {
    ret_val |= ten_xcon_es_config_t41(dev_id, es_index,
                                      XCON_ES_CONFIG_AUTO_CENTER,
                                      CS_ENABLE);
    ret_val |= ten_xcon_es_config_t41(dev_id, es_index,
                                      XCON_ES_CONFIG_AUTO_RECENTER_UPPER,
                                      CS_ENABLE);
    ret_val |= ten_xcon_es_config_t41(dev_id, es_index,
                                      XCON_ES_CONFIG_AUTO_RECENTER_LOWER,
                                      CS_ENABLE);
  }

  ret_val |= ten_xcon_es_config_t41(dev_id, es_index,
                                    XCON_ES_CONFIG_PP10G_RF_RECENTER_EN,
                                    CS_ENABLE);
  ret_val |= ten_xcon_es_config_t41(dev_id, es_index,
                                    XCON_ES_CONFIG_PP10G_LF_RECENTER_EN,
                                    CS_ENABLE);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XCON ELASTIC STORE DELAYED RECENTER PERIOD   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_config_es_delayed_recenter_period(cs_uint16 dev_id,
                                                     cs_uint8  es_index,
                                                     cs_uint8  delay)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Index                           */
/*              o Delay                                         */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/*                                                              */
/* The [es_index] parameter is specified as:                    */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*                                                              */
/* The [delay] parameter is specified as:                       */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_status ret_val = CS_OK;

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE XCON ES CLOCKS                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_disable_es_clock_t41(cs_uint16         dev_id,
                                        ten_xcon_es_num_t es_num,
                                        cs_ctl_t          ctl)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable/Disable the XCON ES clocks.                           */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp;
  TEN_XCON_GLB_CONFIG_t tmp_xcon_glb_config;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_disable_es_clock_t41 Param2"); 
    return CS_ERROR; 
  }
  if((ctl > CS_ENABLE) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_disable_es_clock_t41 Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  if (es_num == XCON_ELASTIC_STORE_ALL) {
    temp = 0xFF;
  }
  else {
    temp = 1<<es_num;
  }

  tmp_xcon_glb_config.wrd = TEN_REG_READ(TEN_XCON_REG_ADDR(pDev, CONFIG));

  if (ctl == CS_DISABLE) {
    tmp_xcon_glb_config.bf.DISABLE_ES =  temp | tmp_xcon_glb_config.wrd;
  }
  else {
    tmp_xcon_glb_config.bf.DISABLE_ES = ~temp & tmp_xcon_glb_config.wrd;
  }

  TEN_REG_WRITE(TEN_XCON_REG_ADDR(pDev, CONFIG), tmp_xcon_glb_config.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE XCON TX ALIGN                 */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_enable_tx_algn_t41(cs_uint16         dev_id,
                                      ten_xcon_es_num_t es_num,
                                      cs_ctl_t          ctl)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable/Disable the XCON TX ALIGNMENT.                        */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp;
  TEN_XCON_GLB_CONFIG_t tmp_xcon_glb_config;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_enable_tx_algn_t41 es_num"); 
    return CS_ERROR; 
  }
  if(ctl > CS_ENABLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_enable_tx_algn_t41 ctl"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  if (es_num == XCON_ELASTIC_STORE_ALL) {
    temp = 0xFF;
  }
  else {
    temp = 1 << es_num;
  }

  tmp_xcon_glb_config.wrd = TEN_REG_READ(TEN_XCON_REG_ADDR(pDev, CONFIG));

  if (ctl == CS_ENABLE) {
    tmp_xcon_glb_config.bf.TX_ALGN_EN |=  temp;
  }
  else {
    tmp_xcon_glb_config.bf.TX_ALGN_EN &= ~temp;
  }

  TEN_REG_WRITE(TEN_XCON_REG_ADDR(pDev, CONFIG), tmp_xcon_glb_config.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE ES RECENTER ENABLES           */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_es_recenter_enables_t41(cs_uint16         dev_id, 
                                           ten_xcon_es_num_t es_num,
                                           cs_uint8          enable_num,
                                           cs_ctl_t          ctl)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Enable Number                                 */
/*              o Control                                       */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables or disables ES Recenter functions.                   */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [enable_num] parameter is specified as:                  */
/*   0 =   XCON_ES_RECENTER_ACCUMULATE_EN                       */
/*   1 =   XCON_ES_RECENTER_AMPLITUDE_RECENTER_EN               */
/*   2 =   XCON_ES_RECENTER_FP_ALIGN_EN                         */
/*   3 =   XCON_ES_RECENTER_LOWER_VIOLATION_EN                  */
/*   4 =   XCON_ES_RECENTER_UPPER_VIOLATION_EN                  */
/*   5 =   XCON_ES_RECENTER_TX_DRAIN_EN                         */
/*   6 =   XCON_ES_RECENTER_STATIC_DEPTH_EN                     */
/*   8 =   XCON_ES_RECENTER_MEASURE_EN                          */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XCON_ES_RECENTER_CONFIG_t tmp_xcon_es_recenter_config;
  T41_t *pDev = NULL;
  cs_int16 ret_val = CS_OK;
  cs_uint16 ii;
  volatile cs_reg *tmp_addr;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_recenter_enables_t41 es_num"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_addr =  TEN_XCON_ES_INST_REG_ADDR(pDev, RECENTER_CONFIG, ii);
      tmp_xcon_es_recenter_config.wrd = TEN_REG_READ(tmp_addr);
      switch(enable_num) {
        case XCON_ES_RECENTER_ACCUMULATE_EN: 
          tmp_xcon_es_recenter_config.bf.ACCUMULATE_EN = ctl;
          break;
        case XCON_ES_RECENTER_AMPLITUDE_RECENTER_EN: 
          tmp_xcon_es_recenter_config.bf.AMPLITUDE_RECENTER_EN = ctl;
          break;
        case XCON_ES_RECENTER_FP_ALIGN_EN: 
          tmp_xcon_es_recenter_config.bf.FP_ALIGN_EN = ctl;
          break;
        case XCON_ES_RECENTER_LOWER_VIOLATION_EN: 
          tmp_xcon_es_recenter_config.bf.LOWER_VIOLATION_EN = ctl;
          break;
        case XCON_ES_RECENTER_UPPER_VIOLATION_EN: 
          tmp_xcon_es_recenter_config.bf.UPPER_VIOLATION_EN = ctl;
          break;
        case XCON_ES_RECENTER_TX_DRAIN_EN: 
          tmp_xcon_es_recenter_config.bf.TX_DRAIN_EN = ctl;
          break;
        case XCON_ES_RECENTER_STATIC_DEPTH_EN: 
          tmp_xcon_es_recenter_config.bf.STATIC_DEPTH_EN = ctl;
          break;
        case XCON_ES_RECENTER_MEASURE_EN:       /* Bugzilla 29270 API for ES level capture */
          tmp_xcon_es_recenter_config.bf.MEASURE_EN = ctl;
          break;
        default: 
          CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_recenter_enables_t41 enable_num"); 
          ret_val = CS_ERROR;
          break;
      }
      TEN_REG_WRITE(tmp_addr, tmp_xcon_es_recenter_config.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE ES CONFIG                     */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_es_config_t41(cs_uint16         dev_id, 
                                 ten_xcon_es_num_t es_num,
                                 cs_uint8          enable_num,
                                 cs_ctl_t          ctl)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Enable Number                                 */
/*              o Control                                       */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables or disables ES configuration options.                */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [enable_num] parameter is specified as:                  */
/*   0 = XCON_ES_CONFIG_PKT_MODE                                */
/*   1 = XCON_ES_CONFIG_SF_MODE                                 */
/*   2 = XCON_ES_CONFIG_GFP_MODE                                */
/*   3 = XCON_ES_CONFIG_AUTO_RECENTER_LOWER                     */
/*   4 = XCON_ES_CONFIG_AUTO_RECENTER_UPPER                     */
/*   5 = XCON_ES_CONFIG_AUTO_CENTER                             */
/*   6 = XCON_ES_CONFIG_FORCE_CENTER                            */
/*   7 = XCON_ES_CONFIG_MFP_MODE                                */
/*   8 = XCON_ES_CONFIG_FLAG_ECCERR                             */
/*  10 = XCON_ES_CONFIG_PP10G_LF_RECENTER_EN                    */
/*  11 = XCON_ES_CONFIG_PP10G_RF_RECENTER_EN                    */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XCON_ES_CONFIG_t tmp_xcon_es_config;
  T41_t *pDev = NULL;
  cs_int16 ret_val = CS_OK;
  cs_uint16 ii;
  volatile cs_reg *tmp_addr;
  cs_char8 *func = "ten_xcon_es_config_t41";  

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, "%s() es_num %d invalid", func, es_num); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_addr =  TEN_XCON_ES_INST_REG_ADDR(pDev, CONFIG, ii);
      tmp_xcon_es_config.wrd = TEN_REG_READ(tmp_addr);
      switch(enable_num) {
        case XCON_ES_CONFIG_PKT_MODE: 
          tmp_xcon_es_config.bf.PKT_MODE = ctl;
          break;
        case XCON_ES_CONFIG_SF_MODE: 
          tmp_xcon_es_config.bf.SF_MODE = ctl;
          break;
        case XCON_ES_CONFIG_GFP_MODE: 
          tmp_xcon_es_config.bf.GFP_MODE = ctl;
          break;
        case XCON_ES_CONFIG_AUTO_RECENTER_LOWER: 
          tmp_xcon_es_config.bf.AUTO_RECENTER_LOWER = ctl;
          break;
        case XCON_ES_CONFIG_AUTO_RECENTER_UPPER: 
          tmp_xcon_es_config.bf.AUTO_RECENTER_UPPER = ctl;
          break;
        case XCON_ES_CONFIG_AUTO_CENTER: 
          tmp_xcon_es_config.bf.AUTO_CENTER = ctl;
          break;
        case XCON_ES_CONFIG_FORCE_CENTER: 
          tmp_xcon_es_config.bf.FORCE_CENTER = ctl;
          break;
        case XCON_ES_CONFIG_MFP_MODE: 
          tmp_xcon_es_config.bf.MFP_MODE = ctl;
          break;
        case XCON_ES_CONFIG_FLAG_ECCERR: 
          tmp_xcon_es_config.bf.FLAG_ECCERR = ctl;
          break;
        case XCON_ES_CONFIG_PP10G_LF_RECENTER_EN: 
          tmp_xcon_es_config.bf.PP10G_LF_RECENTER_EN = ctl;
          break;
        case XCON_ES_CONFIG_PP10G_RF_RECENTER_EN: 
          tmp_xcon_es_config.bf.PP10G_RF_RECENTER_EN = ctl;
          break;
        default: 
          CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_es_config_t41 enable_num"); 
          ret_val = CS_ERROR;
          break;
      }
      TEN_REG_WRITE(tmp_addr, tmp_xcon_es_config.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE GLB PP40G CONFIG              */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_glb_pp40g_config_t41(cs_uint16 dev_id, 
                                        cs_uint8  module_num,
                                        cs_uint8  enable_num,
                                        cs_ctl_t  ctl)
/* INPUTS     : o Device Id                                     */
/*              o Module Number                                 */
/*              o Enable Number                                 */
/*              o Control                                       */
/*                                                              */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enables or disables XCON PP40G configuration options.        */
/*                                                              */
/* The [module_num] parameter is specified as:                  */
/*   0 = TEN_MODULE_A (ES # 0-3)                                */
/*   1 = TEN_MODULE_B (ES # 4-7)                                */
/*   2 = TEN_MODULE_A_AND_B (ES # 0-7)                          */
/*                                                              */
/* The [enable_num] parameter is specified as:                  */
/*   0 = XCON_GLB_PP40G_CFG_FLTSRC                              */
/*   1 = XCON_GLB_PP40G_CFG_RESET                               */
/*   2 = XCON_GLB_PP40G_CFG_RECENTER                            */
/*   3 = XCON_GLB_PP40G_CFG_TX_ALGN_EN                          */
/*   4 = XCON_GLB_PP40G_CFG_LF_DIS                              */
/*   5 = XCON_GLB_PP40G_CFG_RF_DIS                              */
/*   6 = XCON_GLB_PP40G_CFG_IDLE_DIS                            */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  T41_t *pDev = NULL;
  cs_int16 ret_val = CS_OK;
  volatile cs_reg *tmp_addr;
  TEN_XCON_GLB_PP40G_CFG_0_t tmp_xcon_glb_pp40g_cfg;

  /* Parameter Checking */
  if(module_num > TEN_MODULE_A_AND_B) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_glb_pp40g_config_t41 module_num"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  if ((module_num == TEN_MODULE_A) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_addr =  TEN_XCON_REG_ADDR(pDev, PP40G_CFG_0);
    tmp_xcon_glb_pp40g_cfg.wrd = TEN_REG_READ(tmp_addr);
    switch(enable_num) {
      case XCON_GLB_PP40G_CFG_FLTSRC: 
        tmp_xcon_glb_pp40g_cfg.bf.FLTSRC = ctl;
        break;
      case XCON_GLB_PP40G_CFG_RESET: 
        tmp_xcon_glb_pp40g_cfg.bf.RESET = ctl;
        break;
      case XCON_GLB_PP40G_CFG_RECENTER: 
        tmp_xcon_glb_pp40g_cfg.bf.RECENTER = ctl;
        break;
      case XCON_GLB_PP40G_CFG_TX_ALGN_EN: 
        tmp_xcon_glb_pp40g_cfg.bf.TX_ALGN_EN = ctl;
        break;
      case XCON_GLB_PP40G_CFG_LF_DIS: 
        tmp_xcon_glb_pp40g_cfg.bf.LF_DIS = ctl;
        break;
      case XCON_GLB_PP40G_CFG_RF_DIS: 
        tmp_xcon_glb_pp40g_cfg.bf.RF_DIS = ctl;
        break;
      case XCON_GLB_PP40G_CFG_IDLE_DIS: 
        tmp_xcon_glb_pp40g_cfg.bf.IDLE_DIS = ctl;
        break;
      default: 
        CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                           ": ten_xcon_glb_pp40g_config_t41 enable_num"); 
        ret_val = CS_ERROR;
        break;
      }
    if (ret_val == CS_OK) {
      TEN_REG_WRITE(tmp_addr, tmp_xcon_glb_pp40g_cfg.wrd);
    }
  }

  if ((module_num == TEN_MODULE_B) || (module_num == TEN_MODULE_A_AND_B)) {
    tmp_addr =  TEN_XCON_REG_ADDR(pDev, PP40G_CFG_1);
    tmp_xcon_glb_pp40g_cfg.wrd = TEN_REG_READ(tmp_addr);
    switch(enable_num) {
      case XCON_GLB_PP40G_CFG_FLTSRC: 
        tmp_xcon_glb_pp40g_cfg.bf.FLTSRC = ctl;
        break;
      case XCON_GLB_PP40G_CFG_RESET: 
        tmp_xcon_glb_pp40g_cfg.bf.RESET = ctl;
        break;
      case XCON_GLB_PP40G_CFG_RECENTER: 
        tmp_xcon_glb_pp40g_cfg.bf.RECENTER = ctl;
        break;
      case XCON_GLB_PP40G_CFG_TX_ALGN_EN: 
        tmp_xcon_glb_pp40g_cfg.bf.TX_ALGN_EN = ctl;
        break;
      case XCON_GLB_PP40G_CFG_LF_DIS: 
        tmp_xcon_glb_pp40g_cfg.bf.LF_DIS = ctl;
        break;
      case XCON_GLB_PP40G_CFG_RF_DIS: 
        tmp_xcon_glb_pp40g_cfg.bf.RF_DIS = ctl;
        break;
      case XCON_GLB_PP40G_CFG_IDLE_DIS: 
        tmp_xcon_glb_pp40g_cfg.bf.IDLE_DIS = ctl;
        break;
      default: 
        CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                           ": ten_xcon_glb_pp40g_config_t41 enable_num"); 
        ret_val = CS_ERROR;
        break;
      }
    if (ret_val == CS_OK) {
      TEN_REG_WRITE(tmp_addr, tmp_xcon_glb_pp40g_cfg.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (ret_val);
}

/****************************************************************/
/* $rtn_hdr_start  XCON PP ES PAUSE THRESHOLD SELECT            */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pp_es_pause_threshold_select(cs_uint16         dev_id,
                                                ten_xcon_es_num_t es_num,
                                                ten_xcon_es_num_t select)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Each register corresponds to a single XCON output port. The  */
/* value programmed into the register selects the ES which      */
/* provides the pause threshold information determined by the   */
/* corresponding ES_x_PAUSE_LEVEL_0/1 registers.                */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [select] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_GLB_PP_ES_PAUSE_THRESHOLD_SELECT_0_t tmp_pp_es_pause_thresh_select;
  volatile cs_reg *tmp_addr;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pp_es_pause_threshold_select es_num"); 
    return CS_ERROR; 
  }
  if(select > XCON_ELASTIC_STORE_7) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pp_es_pause_threshold_select select"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((es_num == ii) || (es_num == XCON_ELASTIC_STORE_ALL)) {
      tmp_addr  = TEN_XCON_ES_PS_TH_SEL_REG_ADDR(pDev, ii);
      tmp_pp_es_pause_thresh_select.wrd = TEN_REG_READ(tmp_addr);
      tmp_pp_es_pause_thresh_select.bf.SELECT = select;
      TEN_REG_WRITE(tmp_addr, tmp_pp_es_pause_thresh_select.wrd);
    }
  }

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start  ENABLE/DISABLE XCON PBERT CLOCKS                */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_disable_pbert_clock_t41(cs_uint16         dev_id,
                                           ten_xcon_es_num_t es_num,
                                           cs_dir_t          dir, 
                                           cs_ctl_t          ctl)
/* INPUTS     : o Device Id                                     */
/*              o Elastic Store Id                              */
/*              o Direction                                     */
/*              o Control                                       */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* Enable/Disable the XCON PBERT clocks.                        */
/*                                                              */
/* The [es_num] parameter is specified as:                      */
/*   0 = XCON_ELASTIC_STORE_0                                   */
/*   1 = XCON_ELASTIC_STORE_1                                   */
/*   2 = XCON_ELASTIC_STORE_2                                   */
/*   3 = XCON_ELASTIC_STORE_3                                   */
/*   4 = XCON_ELASTIC_STORE_4                                   */
/*   5 = XCON_ELASTIC_STORE_5                                   */
/*   6 = XCON_ELASTIC_STORE_6                                   */
/*   7 = XCON_ELASTIC_STORE_7                                   */
/*   0xFF = XCON_ELASTIC_STORE_ALL                              */
/*                                                              */
/* The [dir] parameter is specified as:                         */
/*   0 = CS_TX                                                  */
/*   1 = CS_RX                                                  */
/*   2 = CS_TX_AND_RX                                           */
/*                                                              */
/* The [ctl] parameter is specified as:                         */
/*   0 = CS_DISABLE                                             */
/*   1 = CS_ENABLE                                              */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  cs_uint16 temp;
  TEN_XCON_GLB_CLOCK_DISABLE_PBERT_t tmp_xcon_glb_clock_disable_pbert;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if((es_num > XCON_ELASTIC_STORE_7) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_disable_es_clock_t41 Param2"); 
    return CS_ERROR; 
  }
  if(dir > CS_TX_AND_RX) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": dir out of range"); 
    return(CS_ERROR); 
  }
  if((ctl > CS_ENABLE) && (es_num != XCON_ELASTIC_STORE_ALL)) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_disable_es_clock_t41 Param3"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  if (es_num == XCON_ELASTIC_STORE_ALL) {
    temp = 0xFF;
  }
  else {
    temp = 1<<es_num;
  }

  tmp_xcon_glb_clock_disable_pbert.wrd = TEN_REG_READ(TEN_XCON_REG_ADDR(pDev, CONFIG));

  if ((dir == CS_RX) || (dir == CS_TX_AND_RX)) {
    if (ctl == CS_DISABLE) {
      tmp_xcon_glb_clock_disable_pbert.bf.DISABLE_RX =  temp | tmp_xcon_glb_clock_disable_pbert.wrd;
    }
    else {
      tmp_xcon_glb_clock_disable_pbert.bf.DISABLE_RX = ~temp & tmp_xcon_glb_clock_disable_pbert.wrd;
    }
  }
  else if ((dir == CS_TX) || (dir == CS_TX_AND_RX)) {
    if (ctl == CS_DISABLE) {
      tmp_xcon_glb_clock_disable_pbert.bf.DISABLE_TX =  temp | tmp_xcon_glb_clock_disable_pbert.wrd;
    }
    else {
      tmp_xcon_glb_clock_disable_pbert.bf.DISABLE_TX = ~temp & tmp_xcon_glb_clock_disable_pbert.wrd;
    }
  }

  TEN_REG_WRITE(TEN_XCON_REG_ADDR(pDev, CONFIG), tmp_xcon_glb_clock_disable_pbert.wrd);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start   XCON PP40G RESET MODULE A                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pp40g_reset_a_t41(cs_uint16         dev_id, 
                                     cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Reset Control                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* While set, ES #0-3 are reset simultaneously. The RESET bit   */
/* must be cleared to disable reset.                            */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XCON_GLB_PP40G_CFG_0_t tmp_xcon_glb_pp40g_cfg_0;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(act > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pp40g_reset_a_t41 act"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  tmp_xcon_glb_pp40g_cfg_0.wrd = 0;
  tmp_xcon_glb_pp40g_cfg_0.bf.RESET = 1;
  ten_reset_action(TEN_XCON_REG_ADDR(pDev, PP40G_CFG_0), tmp_xcon_glb_pp40g_cfg_0.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/****************************************************************/
/* $rtn_hdr_start   XCON PP40G RESET MODULE B                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pp40g_reset_b_t41(cs_uint16         dev_id, 
                                     cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Reset Control                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* While set, ES #4-7 are reset simultaneously. The RESET bit   */
/* must be cleared to disable reset.                            */
/* Invokes the original API ten_xcon_pp40g_reset_t41, which     */
/* only resets Module B.                                        */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  return (ten_xcon_pp40g_reset_t41(dev_id, act));
}

/****************************************************************/
/* $rtn_hdr_start   XCON PP40G RESET MODULE B                   */
/* CATEGORY   : API                                             */
/* ACCESS     : Public                                          */
/* BLOCK      : XCON                                            */
/* CHIP       : Tenabo                                          */
cs_status ten_xcon_pp40g_reset_t41(cs_uint16         dev_id, 
                                   cs_reset_action_t act)
/* INPUTS     : o Device Id                                     */
/*              o Reset Control                                 */
/* OUTPUTS    : ----                                            */
/* RETURNS    : CS_OK or CS_ERROR                               */
/* DESCRIPTION:                                                 */
/* While set, ES #4-7 are reset simultaneously. The RESET bit   */
/* must be cleared to disable reset.                            */
/* The API ten_xcon_pp40g_reset_b_t41 invokes this API, which   */
/* only sets Module B reset.                                    */
/*                                                              */
/* The [act] parameter specifies the reset option and is one    */
/* of the following:                                            */
/*   0 = CS_RESET_DEASSERT                                      */
/*   1 = CS_RESET_ASSERT                                        */
/*   2 = CS_RESET_TOGGLE                                        */
/*   The CS_RESET_TOGGLE option will assert reset, hold the     */
/*   reset for a while and then de-assert the reset bit(s).     */
/*                                                              */
/* $rtn_hdr_end                                                 */
/****************************************************************/
{
  TEN_XCON_GLB_PP40G_CFG_1_t tmp_xcon_glb_pp40g_cfg_1;
  T41_t *pDev = NULL;

  /* Parameter Checking */
  if(act > CS_RESET_TOGGLE) { 
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, 
                             ": ten_xcon_pp40g_reset_t41 act"); 
    return CS_ERROR; 
  }

  /* Register setting */
  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);

  tmp_xcon_glb_pp40g_cfg_1.wrd = 0;
  tmp_xcon_glb_pp40g_cfg_1.bf.RESET = 1;
  ten_reset_action(TEN_XCON_REG_ADDR(pDev, PP40G_CFG_1), tmp_xcon_glb_pp40g_cfg_1.wrd, act);

  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES CORRECTION LOWER                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_correction_lower(cs_uint16 dev_id, cs_uint8 instance, 
                                       cs_uint16 level)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o LEVEL                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set correction for lower threshold adjustment for an             */
/* amplitude recenter.                                              */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..7 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [level]                                                        */
/*     XCON_ES_CIRCUIT_THRESHOLD_LOWER is increased by LEVEL        */
/*     after computing the new threshold following an amplitude     */
/*     recenter.                                                    */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_ES_CORRECTION_LOWER_t tmp_es_correction_lower;
  T41_t *pDev = NULL;

  if ((instance >= TEN_XCON_ES_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..8.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_es_correction_lower.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, CORRECTION_LOWER, ii) );
      tmp_es_correction_lower.bf.LEVEL = level;
      TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, CORRECTION_LOWER, ii), tmp_es_correction_lower.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES CORRECTION UPPER                         */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_correction_upper(cs_uint16 dev_id, cs_uint8 instance, 
                                       cs_uint16 level)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o LEVEL                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set correction for upper threshold adjustment for an             */
/* amplitude recenter.                                              */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..7 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [level]                                                        */
/*     XCON_ES_CIRCUIT_THRESHOLD_UPPER is decreased by LEVEL after  */
/*     computing the new threshold following an amplitude recenter. */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_ES_CORRECTION_UPPER_t tmp_es_correction_upper;
  T41_t *pDev = NULL;

  if ((instance >= TEN_XCON_ES_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..8.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_es_correction_upper.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, CORRECTION_UPPER, ii));
      tmp_es_correction_upper.bf.LEVEL = level;
      TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, CORRECTION_UPPER, ii), tmp_es_correction_upper.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}

/********************************************************************/
/* $rtn_hdr_start  XCON ES STATIC DEPTH                             */
/* CATEGORY   : API                                                 */
/* ACCESS     : Public                                              */
/* BLOCK      : XCON                                                */
/* CHIP       : Tenabo                                              */
cs_status ten_xcon_es_static_depth(cs_uint16 dev_id, cs_uint8 instance, 
                                  cs_uint16 depth)
/* INPUTS     : o Device Id                                         */
/*            : o Instance                                          */
/*              o DEPTH                                             */
/* OUTPUTS    : ----                                                */
/* RETURNS    : CS_OK or CS_ERROR                                   */
/* DESCRIPTION:                                                     */
/* Set static recenter depth for amplitude recenter static          */
/* depth mode.                                                      */
/*                                                                  */
/*   [instance]                                                     */
/*     Specified as 0..7 or TEN_INSTANCE_ALL (0xFF)                 */
/*                                                                  */
/*   [depth]                                                        */
/*     Whenever FP_ALIGN_EN, TX_DRAIN_EN, and STATIC_DEPTH_EN are   */
/*     set in the XCON_ES_RECENTER_CONFIG register, DEPTH is used   */
/*     for an amplitude recenter instead of a calculated depth.     */
/*                                                                  */
/* $rtn_hdr_end                                                     */
/********************************************************************/
{
  cs_uint16 ii;
  TEN_XCON_ES_STATIC_DEPTH_t tmp_es_static_depth;
  T41_t *pDev = NULL;

  if ((instance >= TEN_XCON_ES_COUNT) && (instance != TEN_INSTANCE_ALL)) {
    CS_HNDL_ERROR(dev_id, ETEN_DEV_INVALID_USER_ARG, ": instance out of range.  s/b 0..8.");
    return(CS_ERROR);
  }

  TEN_DEV_COMMON_VALIDATE(dev_id, pDev, CS_ERROR);
  TEN_DEV_LOCK(dev_id, TEN_ID_XCON);
  for (ii=0; ii<TEN_XCON_ES_COUNT; ii++) {
    if ((instance == ii) || (instance == TEN_INSTANCE_ALL)) {
      tmp_es_static_depth.wrd = TEN_REG_READ(TEN_XCON_ES_INST_REG_ADDR(pDev, STATIC_DEPTH, ii));
      tmp_es_static_depth.bf.DEPTH = depth;
      TEN_REG_WRITE(TEN_XCON_ES_INST_REG_ADDR(pDev, STATIC_DEPTH, ii), tmp_es_static_depth.wrd);
    }
  }
  TEN_DEV_UNLOCK(dev_id, TEN_ID_XCON);

  return (CS_OK);
}





/* Bugzilla 28734 Start, Klocwork */
/********************************************************************/
/* Function: ten_get_xfi_cupll_inst_reg_addr                        */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a XCON_es register.                          */
/*                                                                  */
/* Used by macro TEN_XCON_ES_INST_REG_ADDR. Given the base address  */
/* of a non-common XCON_es register as defined in t41_registers.h,  */
/* and its instance number (0..TEN_XCON_ES_COUNT-1), calcuates      */
/* the offset and adds it to the base register's address.           */
/********************************************************************/
volatile cs_reg *ten_get_xcon_es_inst_reg_addr( cs_reg   *pReg,
                                                cs_uint16 instance )
{
  if (instance >= TEN_XCON_ES_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "XCON_es instance %d out of range. S/b < TEN_XCON_ES_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_XCON_ES_STRIDE);
}

/********************************************************************/
/* Function: ten_get_xcon_cbert_inst_reg_addr                       */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a XCON_cbert register.                       */
/*                                                                  */
/* Used by macro TEN_XCON_CBERT_INST_REG_ADDR. Given the base       */
/* address of a non-common XCON_cbert register as defined in        */
/* t41_registers.h, and its instance number (0..TEN_XCON_CBERT_     */
/* COUNT-1), calculates the offset and adds it to the base          */
/* register's address.                                              */
/********************************************************************/
volatile cs_reg *ten_get_xcon_cbert_inst_reg_addr( cs_reg   *pReg,
                                                   cs_uint16 instance )
{
  if (instance >= TEN_XCON_CBERT_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "XCON_cbert instance %d out of range. S/b < TEN_XCON_CBERT_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_XCON_CBERT_STRIDE);
}

/********************************************************************/
/* Function: ten_get_xcon_pbert_inst_reg_addr                       */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a XCON pbert register.                       */
/*                                                                  */
/* Used by macro TEN_XCON_PBERT_INST_REG_ADDR. Given the base       */
/* address of a non-common XCON pbert register as defined in        */
/* t41_registers.h, and its instance number (0..TEN_XCON_PBERT_RX/  */
/* TX_COUNT-1), calculates the offset and adds it to the base       */
/* register's address.                                              */
/********************************************************************/
volatile cs_reg *ten_get_xcon_pbert_inst_reg_addr( cs_reg   *pReg,
                                                   cs_uint16 instance )
{
  if (instance >= TEN_XCON_PBERT_RX_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "XCON pbert instance %d out of range. S/b < TEN_XCON_PBERT_RX/TX_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_XCON_PBERT_RX_STRIDE);
}

/********************************************************************/
/* Function: ten_get_xcon_sadeco_inst_reg_addr                      */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of a XCON sadeco register.                      */
/*                                                                  */
/* Used by macro TEN_XCON_SADECO_INST_REG_ADDR. Given the base      */
/* address of a non-common XCON sadeco register as defined in       */
/* t41_registers.h, and its instance number (0..TEN_XCON_SADECO_    */
/* COUNT-1), calculates the offset and adds it to the base          */
/* register's address.                                              */
/********************************************************************/
volatile cs_reg *ten_get_xcon_sadeco_inst_reg_addr( cs_reg   *pReg,
                                                    cs_uint16 instance )
{
  if (instance >= TEN_XCON_SADECO_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "XCON sadeco instance %d out of range. S/b < TEN_XCON_SADECO_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_XCON_SADECO_STRIDE);
}


/********************************************************************/
/* Function: ten_get_xcon_es_th_lvl_reg_addr()                      */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of any of the XCON ES Thrshld Lvl registers:    */
/*   XCON.ES_<instance>_THRESHOLD_LEVEL_<level> where               */
/*     - instance is the ES instance (0-7) and                      */
/*     - level is the threshold level to set (0-5)                  */
/*                                                                  */
/* Used by macro TEN_XCON_ES_TH_LVL_REG_ADDR. Given the base        */
/* address of an XCON ES Thrshld Lvl register as defined in         */
/* t41_registers.h, and its instance number (0..TEN_XCON_GLB_ES_    */
/* 0_THRESHOLD_LEVEL_0_COUNT-1), calculates the offset and adds it  */
/* to the base register's address.                                  */
/********************************************************************/
volatile cs_reg *ten_get_xcon_es_th_lvl_reg_addr( cs_reg   *pReg,
                                                  cs_uint16 instance,
                                                  cs_uint8  level)
{
  if (instance >= TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_0_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "XCON ES Thrshld Lvl instance %d out of range. S/b < TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_0_COUNT.",
                  instance);
    instance = 0;
  }
  if (level >= 6) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "XCON ES Thrshld Lvl level %d out of range. S/b < 6.",
                  level);
    level = 0;
  }
  return (pReg + level + instance * TEN_XCON_GLB_ES_0_THRESHOLD_LEVEL_0_STRIDE);
}


/********************************************************************/
/* Function:  ten_get_xcon_es_ps_lvl_reg_addr()                     */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of any of the XCON ES Pause Lvl registers:      */
/*  XCON.ES_<instance>_PAUSE_LEVEL_<level> where                    */
/*  - instance is the ES instance (0-7) and                         */
/*  - level is the pause level to set (0 or 1)                      */
/*                                                                  */
/* Used by macro TEN_XCON_ES_PS_LVL_REG_ADDR. Given the base        */
/* address of an XCON ES Pause Lvl register as defined in           */
/* t41_registers.h, and its instance number (0..TEN_XCON_GLB_ES_    */
/* 0_PAUSE_LEVEL_0_COUNT-1), calculates the offset and adds it      */
/* to the base register's address.                                  */
/********************************************************************/
volatile cs_reg *ten_get_xcon_es_ps_lvl_reg_addr( cs_reg   *pReg,
                                                  cs_uint16 instance,
                                                  cs_uint8  level)
{
  if (instance >= TEN_XCON_GLB_ES_0_PAUSE_LEVEL_0_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "XCON ES Pause Lvl instance %d out of range. S/b < .",
                  instance);
    instance = 0;
  }
  if (level >= 2) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "XCON ES Pause Lvl level %d out of range. S/b < 2.",
                  level);
    level = 0;
  }
  return (pReg + level + instance * TEN_XCON_GLB_ES_0_PAUSE_LEVEL_0_STRIDE);
}

/********************************************************************/
/* Function: ten_get_xcon_es_ps_th_sel_reg_addr()                   */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of any of the XCON ES Pause Threshold Select    */
/* registers XCON.PP_ES_PAUSE_THRESHOLD_SELECT_<instance> where     */
/*  - instance is the ES instance (0-7)                             */
/*                                                                  */
/* Used by macro TEN_XCON_ES_PS_TH_SEL_REG_ADDR. Given the base     */
/* address of an XCON ES Pause Threshold Select register as defined */
/* in t41_registers.h, and its instance number (0..TEN_XCON_GLB_PP_ */
/* ES_PAUSE_THRESHOLD_SELECT_0_COUNT-1), calculates the offset and  */
/* adds it to the base register's address.                          */
/********************************************************************/
volatile cs_reg *ten_get_xcon_es_ps_th_sel_reg_addr( cs_reg   *pReg,
                                                     cs_uint16 instance )
{
  if (instance >= TEN_XCON_GLB_PP_ES_PAUSE_THRESHOLD_SELECT_0_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "XCON ES Pause Threshold Select instance %d out of range. S/b < TEN_XCON_GLB_PP_ES_PAUSE_THRESHOLD_SELECT_0_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance * TEN_XCON_GLB_PP_ES_PAUSE_THRESHOLD_SELECT_0_STRIDE);
}


/********************************************************************/
/* Function: ten_get_xcon_es_source_sel_reg_addr()                  */
/********************************************************************/
/* For Bugzilla 28734:                                              */
/* Gets the address of any of the XCON ES Source Select             */
/* registers XCON.ES_SOURCE_SELECT_<instance> where                 */
/*  - instance is the ES instance (0-7)                             */
/*                                                                  */
/* Used by macro TEN_XCON_ES_SOURCE_SEL_REG_ADDR. Given the base    */
/* address of an XCON ES Pause Threshold Select register as defined */
/* in t41_registers.h, and its instance number (0..TEN_XCON_ES_     */
/* COUNT-1), calculates the offset and adds it to the base          */
/* register's address.                                              */
/********************************************************************/
volatile cs_reg *ten_get_xcon_es_source_sel_reg_addr( cs_reg   *pReg,
                                                     cs_uint16 instance )
{
  if (instance >= TEN_XCON_ES_COUNT) {
    CS_HNDL_ERROR(0, ETEN_DEV_INVALID_USER_ARG,
                  "XCON ES Source Select instance %d out of range. S/b < TEN_XCON_ES_COUNT.",
                  instance);
    instance = 0;
  }
  return (pReg + instance);
}
/* Bugzilla 28734 End, Klocwork  */



