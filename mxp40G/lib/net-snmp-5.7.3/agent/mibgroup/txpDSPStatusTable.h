/*
 * Note: this file originally auto-generated by mib2c using
 *       version $ of $
 *
 * $Id:$
 */
#ifndef TXPDSPSTATUSTABLE_H
#define TXPDSPSTATUSTABLE_H

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
config_require(FTNC-MIB/txpDSPStatusTable/txpDSPStatusTable_interface)
config_require(FTNC-MIB/txpDSPStatusTable/txpDSPStatusTable_data_access)
config_require(FTNC-MIB/txpDSPStatusTable/txpDSPStatusTable_data_get)
config_require(FTNC-MIB/txpDSPStatusTable/txpDSPStatusTable_data_set)
    /* *INDENT-ON*  */

/* OID and column number definitions for txpDSPStatusTable */
#include "FTNC-MIB/txpDSPStatusTable/txpDSPStatusTable_oids.h"

/* enum definions */
#include "FTNC-MIB/txpDSPStatusTable/txpDSPStatusTable_enums.h"

/* *********************************************************************
 * function declarations
 */
void init_txpDSPStatusTable(void);
void shutdown_txpDSPStatusTable(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table txpDSPStatusTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * FTNC-MIB::txpDSPStatusTable is subid 1 of txpDSP.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.43484.2.9.3.1, length: 11
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review txpDSPStatusTable registration context.
     */
typedef netsnmp_data_list txpDSPStatusTable_registration;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review txpDSPStatusTable data context structure.
 * This structure is used to represent the data for txpDSPStatusTable.
 */
/*
 * This structure contains storage for all the columns defined in the
 * txpDSPStatusTable.
 */
typedef struct txpDSPStatusTable_data_s {
    
        /*
         * dsprunning(2)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   dsprunning[65535];
size_t      dsprunning_len; /* # of char elements, not bytes */
    
        /*
         * converged(3)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   converged[65535];
size_t      converged_len; /* # of char elements, not bytes */
    
        /*
         * msebelowThreshold(4)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   msebelowThreshold[65535];
size_t      msebelowThreshold_len; /* # of char elements, not bytes */
    
        /*
         * bcdEnable(5)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   bcdEnable[65535];
size_t      bcdEnable_len; /* # of char elements, not bytes */
    
        /*
         * coarseCarrierLock(6)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   coarseCarrierLock[65535];
size_t      coarseCarrierLock_len; /* # of char elements, not bytes */
    
        /*
         * collision(7)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   collision[65535];
size_t      collision_len; /* # of char elements, not bytes */
    
        /*
         * dspInitialized(8)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   dspInitialized[65535];
size_t      dspInitialized_len; /* # of char elements, not bytes */
    
        /*
         * presenceOfLight(9)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   presenceOfLight[65535];
size_t      presenceOfLight_len; /* # of char elements, not bytes */
    
        /*
         * localOscillatorRunning(10)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   localOscillatorRunning[65535];
size_t      localOscillatorRunning_len; /* # of char elements, not bytes */
    
        /*
         * transmitLaserRunning(11)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   transmitLaserRunning[65535];
size_t      transmitLaserRunning_len; /* # of char elements, not bytes */
    
} txpDSPStatusTable_data;


/*
 * TODO:120:r: |-> Review txpDSPStatusTable mib index.
 * This structure is used to represent the index for txpDSPStatusTable.
 */
typedef struct txpDSPStatusTable_mib_index_s {

        /*
         * txpDSPStatusIndex(1)/OCTETSTR/ASN_OCTET_STR/char(char)//L/a/w/e/R/d/h
         */
   char   txpDSPStatusIndex[32];
   size_t      txpDSPStatusIndex_len;


} txpDSPStatusTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review txpDSPStatusTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
     *
     * BE VERY CAREFUL TO TAKE INTO ACCOUNT THE MAXIMUM
     * POSSIBLE LENGHT FOR EVERY VARIABLE LENGTH INDEX!
     * Guessing 128 - col/entry(2)  - oid len(11)
*/
#define MAX_txpDSPStatusTable_IDX_LEN     33


/* *********************************************************************
 * TODO:130:o: |-> Review txpDSPStatusTable Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * txpDSPStatusTable_rowreq_ctx pointer.
 */
typedef struct txpDSPStatusTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_txpDSPStatusTable_IDX_LEN];
    
    txpDSPStatusTable_mib_index        tbl_idx;
    
    txpDSPStatusTable_data              data;

    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * TODO:131:o: |   |-> Add useful data to txpDSPStatusTable rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *txpDSPStatusTable_data_list;

} txpDSPStatusTable_rowreq_ctx;

typedef struct txpDSPStatusTable_ref_rowreq_ctx_s {
    txpDSPStatusTable_rowreq_ctx *rowreq_ctx;
} txpDSPStatusTable_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int txpDSPStatusTable_pre_request(txpDSPStatusTable_registration * user_context);
    int txpDSPStatusTable_post_request(txpDSPStatusTable_registration * user_context,
        int rc);

    int txpDSPStatusTable_rowreq_ctx_init(txpDSPStatusTable_rowreq_ctx *rowreq_ctx,
                                   void *user_init_ctx);
    void txpDSPStatusTable_rowreq_ctx_cleanup(txpDSPStatusTable_rowreq_ctx *rowreq_ctx);


    txpDSPStatusTable_rowreq_ctx *
                  txpDSPStatusTable_row_find_by_mib_index(txpDSPStatusTable_mib_index *mib_idx);

extern const oid txpDSPStatusTable_oid[];
extern const int txpDSPStatusTable_oid_size;


#include "FTNC-MIB/txpDSPStatusTable/txpDSPStatusTable_interface.h"
#include "FTNC-MIB/txpDSPStatusTable/txpDSPStatusTable_data_access.h"
#include "FTNC-MIB/txpDSPStatusTable/txpDSPStatusTable_data_get.h"
#include "FTNC-MIB/txpDSPStatusTable/txpDSPStatusTable_data_set.h"

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

#endif /* TXPDSPSTATUSTABLE_H */
/** @} */
