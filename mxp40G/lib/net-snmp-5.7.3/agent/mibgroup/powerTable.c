/*
 * Note: this file originally auto-generated by mib2c using
 *       version $ of $ 
 *
 * $Id:$
 */
/** \page MFD helper for powerTable
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
#include "powerTable.h"

#include <net-snmp/agent/mib_modules.h>

#include "FTNC-MIB/powerTable/powerTable_interface.h"

const oid powerTable_oid[] = { POWERTABLE_OID };
const int powerTable_oid_size = OID_LENGTH(powerTable_oid);

    powerTable_registration  powerTable_user_context;

void initialize_table_powerTable(void);
void shutdown_table_powerTable(void);


/**
 * Initializes the powerTable module
 */
void
init_powerTable(void)
{
    DEBUGMSGTL(("verbose:powerTable:init_powerTable","called\n"));

    /*
     * TODO:300:o: Perform powerTable one-time module initialization.
     */
     
    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("powerTable"))
        initialize_table_powerTable();

} /* init_powerTable */

/**
 * Shut-down the powerTable module (agent is exiting)
 */
void
shutdown_powerTable(void)
{
    if (should_init("powerTable"))
        shutdown_table_powerTable();

}

/**
 * Initialize the table powerTable 
 *    (Define its contents and how it's structured)
 */
void
initialize_table_powerTable(void)
{
    powerTable_registration * user_context;
    u_long flags;

    DEBUGMSGTL(("verbose:powerTable:initialize_table_powerTable","called\n"));

    /*
     * TODO:301:o: Perform powerTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize powerTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    user_context = netsnmp_create_data_list("powerTable", NULL, NULL);
    
    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;
    
    /*
     * call interface initialization code
     */
    _powerTable_initialize_interface(user_context, flags);
} /* initialize_table_powerTable */

/**
 * Shutdown the table powerTable 
 */
void
shutdown_table_powerTable(void)
{
    /*
     * call interface shutdown code
     */
    _powerTable_shutdown_interface(&powerTable_user_context);
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
powerTable_rowreq_ctx_init(powerTable_rowreq_ctx *rowreq_ctx,
                           void *user_init_ctx)
{
    DEBUGMSGTL(("verbose:powerTable:powerTable_rowreq_ctx_init","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:210:o: |-> Perform extra powerTable rowreq initialization. (eg DEFVALS)
     */

    return MFD_SUCCESS;
} /* powerTable_rowreq_ctx_init */

/**
 * extra context cleanup
 *
 */
void powerTable_rowreq_ctx_cleanup(powerTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:powerTable:powerTable_rowreq_ctx_cleanup","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);
    
    /*
     * TODO:211:o: |-> Perform extra powerTable rowreq cleanup.
     */
} /* powerTable_rowreq_ctx_cleanup */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int
powerTable_pre_request(powerTable_registration * user_context)
{
    DEBUGMSGTL(("verbose:powerTable:powerTable_pre_request","called\n"));

    /*
     * TODO:510:o: Perform powerTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* powerTable_pre_request */

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
powerTable_post_request(powerTable_registration * user_context, int rc)
{
    DEBUGMSGTL(("verbose:powerTable:powerTable_post_request","called\n"));

    /*
     * TODO:511:o: Perform powerTable post-request actions.
     */

    /*
     * check to set if any rows were changed.
     */
    if (powerTable_dirty_get()) {
        /*
         * check if request was successful. If so, this would be
         * a good place to save data to its persistent store.
         */
        if (MFD_SUCCESS == rc) {
            /*
             * save changed rows, if you haven't already
             */
        }
        
        powerTable_dirty_set(0); /* clear table dirty flag */
    }

    return MFD_SUCCESS;
} /* powerTable_post_request */


/** @{ */
