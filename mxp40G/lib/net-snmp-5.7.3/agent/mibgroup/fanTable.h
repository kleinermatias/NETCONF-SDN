/*
 * Note: this file originally auto-generated by mib2c using
 *       version $ of $
 *
 * $Id:$
 */
#ifndef FANTABLE_H
#define FANTABLE_H

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
config_require(FTNC-MIB/fanTable/fanTable_interface)
config_require(FTNC-MIB/fanTable/fanTable_data_access)
config_require(FTNC-MIB/fanTable/fanTable_data_get)
config_require(FTNC-MIB/fanTable/fanTable_data_set)
    /* *INDENT-ON*  */

/* OID and column number definitions for fanTable */
#include "FTNC-MIB/fanTable/fanTable_oids.h"

/* enum definions */
#include "FTNC-MIB/fanTable/fanTable_enums.h"

/* *********************************************************************
 * function declarations
 */
void init_fanTable(void);
void shutdown_fanTable(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table fanTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * FTNC-MIB::fanTable is subid 2 of mxpMIBObjects.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.43484.2.2, length: 9
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review fanTable registration context.
     */
typedef netsnmp_data_list fanTable_registration;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review fanTable data context structure.
 * This structure is used to represent the data for fanTable.
 */
/*
 * This structure contains storage for all the columns defined in the
 * fanTable.
 */
typedef struct fanTable_data_s {
    
        /*
         * fan1(2)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   fan1[65535];
size_t      fan1_len; /* # of char elements, not bytes */
    
        /*
         * fan2(3)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   fan2[65535];
size_t      fan2_len; /* # of char elements, not bytes */
    
        /*
         * fan3(4)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   fan3[65535];
size_t      fan3_len; /* # of char elements, not bytes */
    
        /*
         * fan4(5)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   fan4[65535];
size_t      fan4_len; /* # of char elements, not bytes */
    
        /*
         * fan5(6)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */
   char   fan5[65535];
size_t      fan5_len; /* # of char elements, not bytes */
    
} fanTable_data;


/*
 * TODO:120:r: |-> Review fanTable mib index.
 * This structure is used to represent the index for fanTable.
 */
typedef struct fanTable_mib_index_s {

        /*
         * fanIndex(1)/OCTETSTR/ASN_OCTET_STR/char(char)//L/a/w/e/R/d/h
         */
   char   fanIndex[32];
   size_t      fanIndex_len;


} fanTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review fanTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
     *
     * BE VERY CAREFUL TO TAKE INTO ACCOUNT THE MAXIMUM
     * POSSIBLE LENGHT FOR EVERY VARIABLE LENGTH INDEX!
     * Guessing 128 - col/entry(2)  - oid len(9)
*/
#define MAX_fanTable_IDX_LEN     33


/* *********************************************************************
 * TODO:130:o: |-> Review fanTable Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * fanTable_rowreq_ctx pointer.
 */
typedef struct fanTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_fanTable_IDX_LEN];
    
    fanTable_mib_index        tbl_idx;
    
    fanTable_data              data;

    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * TODO:131:o: |   |-> Add useful data to fanTable rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *fanTable_data_list;

} fanTable_rowreq_ctx;

typedef struct fanTable_ref_rowreq_ctx_s {
    fanTable_rowreq_ctx *rowreq_ctx;
} fanTable_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int fanTable_pre_request(fanTable_registration * user_context);
    int fanTable_post_request(fanTable_registration * user_context,
        int rc);

    int fanTable_rowreq_ctx_init(fanTable_rowreq_ctx *rowreq_ctx,
                                   void *user_init_ctx);
    void fanTable_rowreq_ctx_cleanup(fanTable_rowreq_ctx *rowreq_ctx);


    fanTable_rowreq_ctx *
                  fanTable_row_find_by_mib_index(fanTable_mib_index *mib_idx);

extern const oid fanTable_oid[];
extern const int fanTable_oid_size;


#include "FTNC-MIB/fanTable/fanTable_interface.h"
#include "FTNC-MIB/fanTable/fanTable_data_access.h"
#include "FTNC-MIB/fanTable/fanTable_data_get.h"
#include "FTNC-MIB/fanTable/fanTable_data_set.h"

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

#endif /* FANTABLE_H */
/** @} */
