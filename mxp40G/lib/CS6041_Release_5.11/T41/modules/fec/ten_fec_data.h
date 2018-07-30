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
 * ten_fec_data.h
 *
 * Data Header file for FEC block.
 *
 * $Id: ten_fec_data.h,v 1.8 2013/02/22 20:48:57 jccarlis Exp $
 *
 */

#ifndef __TEN_FEC_DATA_H__
#define __TEN_FEC_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  TEN_CONT_ERR,
  TEN_SINGLE_ERR
} ten_err_freq_t;

typedef enum {
  TEN_BYTE_ERROR,
  TEN_ZERO_ERROR,
  TEN_ONE_ERROR
} ten_err_source_t;

typedef enum {
  TEN_SEED_ERSEL,
  TEN_CEED_ERSEL,
  TEN_SDEG_ERSEL,
  TEN_CDEG_ERSEL
} ten_fec_err_sel_t;

typedef enum {
  TEN_N0B_N1B_NUCODEWD_NCBYTE,
  TEN_N0B_N1B_NUCODEWD_YCBYTE,
  TEN_N0B_N1B_YUCODEWD_NCBYTE,
  TEN_N0B_N1B_YUCODEWD_YCBYTE,
  TEN_N0B_Y1B_NUCODEWD_NCBYTE,
  TEN_N0B_Y1B_NUCODEWD_YCBYTE,
  TEN_N0B_Y1B_YUCODEWD_NCBYTE,
  TEN_N0B_Y1B_YUCODEWD_YCBYTE,
  TEN_Y0B_N1B_NUCODEWD_NCBYTE,
  TEN_Y0B_N1B_NUCODEWD_YCBYTE,
  TEN_Y0B_N1B_YUCODEWD_NCBYTE,
  TEN_Y0B_N1B_YUCODEWD_YCBYTE,
  TEN_Y0B_Y1B_NUCODEWD_NCBYTE,
  TEN_Y0B_Y1B_NUCODEWD_YCBYTE,
  TEN_Y0B_Y1B_YUCODEWD_NCBYTE,
  TEN_Y0B_Y1B_YUCODEWD_YCBYTE
} ten_gfec_err_type_t;

typedef enum {
  TEN_N0B_N1B_NUCODEWD,
  TEN_N0B_N1B_YUCODEWD,
  TEN_N0B_Y1B_NUCODEWD,
  TEN_N0B_Y1B_YUCODEWD,
  TEN_Y0B_N1B_NUCODEWD,
  TEN_Y0B_N1B_YUCODEWD,
  TEN_Y0B_Y1B_NUCODEWD,
  TEN_Y0B_Y1B_YUCODEWD
} ten_ufec_err_type_t;

typedef enum {
  TEN_NLDS_N4DS_N3DS_N2DS_N1DS,
  TEN_NLDS_N4DS_N3DS_N2DS_Y1DS,
  TEN_NLDS_N4DS_N3DS_Y2DS_N1DS,
  TEN_NLDS_N4DS_N3DS_Y2DS_Y1DS,
  TEN_NLDS_N4DS_Y3DS_N2DS_N1DS,
  TEN_NLDS_N4DS_Y3DS_N2DS_Y1DS,
  TEN_NLDS_N4DS_Y3DS_Y2DS_N1DS,
  TEN_NLDS_N4DS_Y3DS_Y2DS_Y1DS,
  TEN_NLDS_Y4DS_N3DS_N2DS_N1DS,
  TEN_NLDS_Y4DS_N3DS_N2DS_Y1DS,
  TEN_NLDS_Y4DS_N3DS_Y2DS_N1DS,
  TEN_NLDS_Y4DS_N3DS_Y2DS_Y1DS,
  TEN_NLDS_Y4DS_Y3DS_N2DS_N1DS,
  TEN_NLDS_Y4DS_Y3DS_N2DS_Y1DS,
  TEN_NLDS_Y4DS_Y3DS_Y2DS_N1DS,
  TEN_NLDS_Y4DS_Y3DS_Y2DS_Y1DS,
  TEN_YLDS_N4DS_N3DS_N2DS_N1DS,
  TEN_YLDS_N4DS_N3DS_N2DS_Y1DS,
  TEN_YLDS_N4DS_N3DS_Y2DS_N1DS,
  TEN_YLDS_N4DS_N3DS_Y2DS_Y1DS,
  TEN_YLDS_N4DS_Y3DS_N2DS_N1DS,
  TEN_YLDS_N4DS_Y3DS_N2DS_Y1DS,
  TEN_YLDS_N4DS_Y3DS_Y2DS_N1DS,
  TEN_YLDS_N4DS_Y3DS_Y2DS_Y1DS,
  TEN_YLDS_Y4DS_N3DS_N2DS_N1DS,
  TEN_YLDS_Y4DS_N3DS_N2DS_Y1DS,
  TEN_YLDS_Y4DS_N3DS_Y2DS_N1DS,
  TEN_YLDS_Y4DS_N3DS_Y2DS_Y1DS,
  TEN_YLDS_Y4DS_Y3DS_N2DS_N1DS,
  TEN_YLDS_Y4DS_Y3DS_N2DS_Y1DS,
  TEN_YLDS_Y4DS_Y3DS_Y2DS_N1DS,
  TEN_YLDS_Y4DS_Y3DS_Y2DS_Y1DS
} ten_fec_err_src_t;

typedef enum {
  TEN_INT_TIME_SOURCE_1,
  TEN_INT_TIME_SOURCE_2,
  TEN_INT_TIME_SOURCE_3,
  TEN_INT_TIME_SOURCE_4,
  TEN_INT_TIME_SOURCE_5,
  TEN_INT_TIME_SOURCE_6,
  TEN_SW_TIME_SOURCE,
  TEN_EXT_TIME_SOURCE
} ten_fec_time_unit_sel_t;

/* Bugzilla #20657, regression fixes */
typedef enum {
  TEN_FEC_MODE_OTUkV             = 0,   /*   7% */
  TEN_FEC_MODE_OTUkV_262         = 1,   /*  10% */
  TEN_FEC_MODE_OTUkV_273         = 2,   /*  15% */
  TEN_FEC_MODE_OTUkV_285         = 3,   /*  20% */
  TEN_FEC_MODE_OTUkV_297         = 4,   /*  25% */
  TEN_FEC_MODE_OTUkV_5_4         = 5,   /*  25% */
  TEN_FEC_MODE_OTUkV_301         = 6,   /*  26% */
  TEN_FEC_MODE_OTUkV_SDH_A       = 7,   /*   7% */
  TEN_FEC_MODE_OTUkV_SDH_B       = 8,   /*   7% */
  TEN_FEC_MODE_OTUkV_4080_3929   = 9,   /* 3.4% */
  TEN_FEC_MODE_OTUkV_68_65       = 10,  /* 4.2% */
  TEN_FEC_MODE_OTUkV_267         = 11,  /*  12% */
  TEN_FEC_MODE_OTUkV_270         = 12,  /*  13% */
  TEN_FEC_MODE_GFEC              = 13,  /*   7% */
  TEN_FEC_MODE_ZEROFEC           = 14,  /*   7%, FEC is all zeroes */
  TEN_FEC_MODE_NOFEC             = 15,  /*   0%, FEC not present   */
  TEN_FEC_MODE_DEALLOCATE        = 16,  /*   0%, Power down FEC */
  
  /* Bugzilla#32517, add new UFEC configurations */
  TEN_FEC_MODE_OTUkV_263         = 17,  /*   7% */
  TEN_FEC_MODE_OTUkV_280         = 18,  /*  18% */
  TEN_FEC_MODE_OTUkV_295         = 19,  /*  25% */
  
  TEN_FEC_MODE_MAX_NUM 
} ten_fec_ovhd_t;
      
typedef enum {
  TEN_ED_BUF_5KB,
  TEN_ED_BUF_10KB,
  TEN_ED_BUF_15KB
} ten_ed_buffer_type_t;

typedef enum {
  TEN_FEC_GFEC_10G,
  TEN_FEC_GFEC_40G,
  TEN_FEC_UFEC_10G,
  TEN_FEC_UFEC_40G
} ten_fec_type_t;

typedef enum {
  TEN_FEC_BYPASS,
  TEN_FEC_ACTIVE
} ten_fec_action_t;

typedef enum {
  TEN_ROW_AND_COL_ENC_MODULE_DISABLED,
  TEN_ROW_ENCODER_MODULE_ENABLED,
  TEN_COLUMN_ENCODER_MODULE_ENABLED,
  TEN_ROW_AND_COL_ENC_MODULE_ENABLED
} ten_enc_rc_enbl_t;

typedef enum {
  TEN_ALL_ROW_DEC0DER_DISABLED = 0x00,
  TEN_THIRD_ROW_DECODER        = 0x01,
  TEN_SECOND_COLUMN_DECODER    = 0x02,
  TEN_SECOND_ROW_DECODER       = 0x04,
  TEN_FIRST_COLUMN_DECODER     = 0x08,
  TEN_FIRST_ROW_DECODER        = 0x10
} ten_dec_corr_ctrl_t;

#ifdef __cplusplus
}
#endif
#endif /* __TEN_FEC_DATA_H__ */
