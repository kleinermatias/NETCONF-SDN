/*
 * Note: this file originally auto-generated by mib2c using
 *       version $ of $
 *
 * $Id:$
 */
#ifndef XFP1TABLE_H
#define XFP1TABLE_H

#ifdef __cplusplus
extern "C" {
#endif


/** @addtogroup misc misc: Miscellaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>

/* other required module components */
    /* *INDENT-OFF*  */
config_add_mib(FTNC-MIB)
config_require(FTNC-MIB/xfp1Table/xfp1Table_interface)
config_require(FTNC-MIB/xfp1Table/xfp1Table_data_access)
config_require(FTNC-MIB/xfp1Table/xfp1Table_data_get)
config_require(FTNC-MIB/xfp1Table/xfp1Table_data_set)
    /* *INDENT-ON*  */

/* OID and column number definitions for xfp1Table */
#include "FTNC-MIB/xfp1Table/xfp1Table_oids.h"

/* enum definions */
#include "FTNC-MIB/xfp1Table/xfp1Table_enums.h"

/* *********************************************************************
 * function declarations
 */
void init_xfp1Table(void);
void shutdown_xfp1Table(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table xfp1Table
 ***
 **********************************************************************
 **********************************************************************/
/*
 * FTNC-MIB::xfp1Table is subid 3 of mxpMIBObjects.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.43484.2.3, length: 9
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review xfp1Table registration context.
     */
typedef netsnmp_data_list xfp1Table_registration;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review xfp1Table data context structure.
 * This structure is used to represent the data for xfp1Table.
 */
/*
 * This structure contains storage for all the columns defined in the
 * xfp1Table.
 */
typedef struct xfp1Table_data_s {
    
        /*
         * xfp1Pres(2)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1Pres[65535];
size_t      xfp1Pres_len; /* # of char elements, not bytes */
    
        /*
         * xfp1Loss(3)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1Loss[65535];
size_t      xfp1Loss_len; /* # of char elements, not bytes */
    
        /*
         * xfp1Rdy(4)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1Rdy[65535];
size_t      xfp1Rdy_len; /* # of char elements, not bytes */
    
        /*
         * xfp1Int(5)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1Int[65535];
size_t      xfp1Int_len; /* # of char elements, not bytes */
    
        /*
         * xfp1TxPow(6)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1TxPow[65535];
size_t      xfp1TxPow_len; /* # of char elements, not bytes */
    
        /*
         * xfp1RxPow(7)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1RxPow[65535];
size_t      xfp1RxPow_len; /* # of char elements, not bytes */
    
        /*
         * xfp1Temp(8)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1Temp[65535];
size_t      xfp1Temp_len; /* # of char elements, not bytes */
    
        /*
         * xfp1LowTxPow(9)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1LowTxPow[65535];
size_t      xfp1LowTxPow_len; /* # of char elements, not bytes */
    
        /*
         * xfp1HighTxPow(10)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1HighTxPow[65535];
size_t      xfp1HighTxPow_len; /* # of char elements, not bytes */
    
        /*
         * xfp1LowRxPow(11)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1LowRxPow[65535];
size_t      xfp1LowRxPow_len; /* # of char elements, not bytes */
    
        /*
         * xfp1HighRxPow(12)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1HighRxPow[65535];
size_t      xfp1HighRxPow_len; /* # of char elements, not bytes */
    
        /*
         * xfp1RxCdrLol(13)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1RxCdrLol[65535];
size_t      xfp1RxCdrLol_len; /* # of char elements, not bytes */
    
        /*
         * xfp1TxCdrLol(14)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1TxCdrLol[65535];
size_t      xfp1TxCdrLol_len; /* # of char elements, not bytes */
    
        /*
         * xfp1LasFault(15)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   xfp1LasFault[65535];
size_t      xfp1LasFault_len; /* # of char elements, not bytes */
    
} xfp1Table_data;


/*
 * TODO:120:r: |-> Review xfp1Table mib index.
 * This structure is used to represent the index for xfp1Table.
 */
typedef struct xfp1Table_mib_index_s {

        /*
         * xfp1Index(1)/OCTETSTR/ASN_OCTET_STR/char(char)//L/a/w/e/R/d/h
         */
   char   xfp1Index[32];
   size_t      xfp1Index_len;


} xfp1Table_mib_index;

    /*
     * TODO:121:r: |   |-> Review xfp1Table max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
     *
     * BE VERY CAREFUL TO TAKE INTO ACCOUNT THE MAXIMUM
     * POSSIBLE LENGHT FOR EVERY VARIABLE LENGTH INDEX!
     * Guessing 128 - col/entry(2)  - oid len(9)
*/
#define MAX_xfp1Table_IDX_LEN     33


/* *********************************************************************
 * TODO:130:o: |-> Review xfp1Table Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * xfp1Table_rowreq_ctx pointer.
 */
typedef struct xfp1Table_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_xfp1Table_IDX_LEN];
    
    xfp1Table_mib_index        tbl_idx;
    
    xfp1Table_data              data;

    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * TODO:131:o: |   |-> Add useful data to xfp1Table rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *xfp1Table_data_list;

} xfp1Table_rowreq_ctx;

typedef struct xfp1Table_ref_rowreq_ctx_s {
    xfp1Table_rowreq_ctx *rowreq_ctx;
} xfp1Table_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int xfp1Table_pre_request(xfp1Table_registration * user_context);
    int xfp1Table_post_request(xfp1Table_registration * user_context,
        int rc);

    int xfp1Table_rowreq_ctx_init(xfp1Table_rowreq_ctx *rowreq_ctx,
                                   void *user_init_ctx);
    void xfp1Table_rowreq_ctx_cleanup(xfp1Table_rowreq_ctx *rowreq_ctx);


    xfp1Table_rowreq_ctx *
                  xfp1Table_row_find_by_mib_index(xfp1Table_mib_index *mib_idx);

extern const oid xfp1Table_oid[];
extern const int xfp1Table_oid_size;


#include "FTNC-MIB/xfp1Table/xfp1Table_interface.h"
#include "FTNC-MIB/xfp1Table/xfp1Table_data_access.h"
#include "FTNC-MIB/xfp1Table/xfp1Table_data_get.h"
#include "FTNC-MIB/xfp1Table/xfp1Table_data_set.h"

/*
 * DUMMY markers, ignore
 *
 * TODO:099:x: *************************************************************
 * TODO:199:x: *************************************************************
 * TODO:299:x: *************************************************************
 * TODO:399:x: *************************************************************
 * TODO:499:x: *************************************************************
 */

#ifdef __cplusplus
}
#endif

#endif /* XFP1TABLE_H */
/** @} */
