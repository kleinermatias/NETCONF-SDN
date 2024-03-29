/*
 * Note: this file originally auto-generated by mib2c using
 *       version $ of $ 
 *
 * $Id:$
 */
/** \page MFD helper for xfp3SeverityTable
 *
 * \section intro Introduction
 * Introductory text.
 *
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "xfp3SeverityTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "FTNC-MIB/xfp3SeverityTable/xfp3SeverityTable_interface.h"

const oid xfp3SeverityTable_oid[] = { XFP3SEVERITYTABLE_OID };
const int xfp3SeverityTable_oid_size = OID_LENGTH(xfp3SeverityTable_oid);

    xfp3SeverityTable_registration  xfp3SeverityTable_user_context;

void initialize_table_xfp3SeverityTable(void);
void shutdown_table_xfp3SeverityTable(void);


/**
 * Initializes the xfp3SeverityTable module
 */
void
init_xfp3SeverityTable(void)
{
    DEBUGMSGTL(("verbose:xfp3SeverityTable:init_xfp3SeverityTable","called\n"));

    /*
     * TODO:300:o: Perform xfp3SeverityTable one-time module initialization.
     */
     
    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("xfp3SeverityTable"))
        initialize_table_xfp3SeverityTable();

} /* init_xfp3SeverityTable */

/**
 * Shut-down the xfp3SeverityTable module (agent is exiting)
 */
void
shutdown_xfp3SeverityTable(void)
{
    if (should_init("xfp3SeverityTable"))
        shutdown_table_xfp3SeverityTable();

}

/**
 * Initialize the table xfp3SeverityTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_xfp3SeverityTable(void)
{
    xfp3SeverityTable_registration * user_context;
    u_long flags;

    DEBUGMSGTL(("verbose:xfp3SeverityTable:initialize_table_xfp3SeverityTable","called\n"));

    /*
     * TODO:301:o: Perform xfp3SeverityTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize xfp3SeverityTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("xfp3SeverityTable", NULL, NULL);
    
    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;
    
    /*
     * call interface initialization code
     */
    _xfp3SeverityTable_initialize_interface(user_context, flags);
} /* initialize_table_xfp3SeverityTable */

/**
 * Shutdown the table xfp3SeverityTable 
 */
void
shutdown_table_xfp3SeverityTable(void)
{
    /*
     * call interface shutdown code
     */
    _xfp3SeverityTable_shutdown_interface(&xfp3SeverityTable_user_context);
}

/**
 * extra context initialization (eg default values)
 *
 * @param rowreq_ctx    : row request context
 * @param user_init_ctx : void pointer for user (parameter to rowreq_ctx_allocate)
 *
 * @retval MFD_SUCCESS  : no errors
 * @retval MFD_ERROR    : error (context allocate will fail)
 */
int
xfp3SeverityTable_rowreq_ctx_init(xfp3SeverityTable_rowreq_ctx *rowreq_ctx,
                           void *user_init_ctx)
{
    DEBUGMSGTL(("verbose:xfp3SeverityTable:xfp3SeverityTable_rowreq_ctx_init","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:210:o: |-> Perform extra xfp3SeverityTable rowreq initialization. (eg DEFVALS)
     */

    return MFD_SUCCESS;
} /* xfp3SeverityTable_rowreq_ctx_init */

/**
 * extra context cleanup
 *
 */
void xfp3SeverityTable_rowreq_ctx_cleanup(xfp3SeverityTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:xfp3SeverityTable:xfp3SeverityTable_rowreq_ctx_cleanup","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:211:o: |-> Perform extra xfp3SeverityTable rowreq cleanup.
     */
} /* xfp3SeverityTable_rowreq_ctx_cleanup */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
xfp3SeverityTable_pre_request(xfp3SeverityTable_registration * user_context)
{
    DEBUGMSGTL(("verbose:xfp3SeverityTable:xfp3SeverityTable_pre_request","called\n"));

    /*
     * TODO:510:o: Perform xfp3SeverityTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* xfp3SeverityTable_pre_request */

/**
 * post-request callback
 *
 * Note:
 *   New rows have been inserted into the container, and
 *   deleted rows have been removed from the container and
 *   released.
 *
 * @param user_context
 * @param rc : MFD_SUCCESS if all requests succeeded
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int
xfp3SeverityTable_post_request(xfp3SeverityTable_registration * user_context, int rc)
{
    DEBUGMSGTL(("verbose:xfp3SeverityTable:xfp3SeverityTable_post_request","called\n"));

    /*
     * TODO:511:o: Perform xfp3SeverityTable post-request actions.
     */

    /*
     * check to set if any rows were changed.
     */
    if (xfp3SeverityTable_dirty_get()) {
        /*
         * check if request was successful. If so, this would be
         * a good place to save data to its persistent store.
         */
        if (MFD_SUCCESS == rc) {
            /*
             * save changed rows, if you haven't already
             */
        }
        
        xfp3SeverityTable_dirty_set(0); /* clear table dirty flag */
    }

    return MFD_SUCCESS;
} /* xfp3SeverityTable_post_request */


/** @{ */
