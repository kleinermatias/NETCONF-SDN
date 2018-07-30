/***********************************************************************/
/* This file contains unpublished documentation and software           */
/* proprietary to Cortina Systems Incorporated. Any use or disclosure, */
/* in whole or in part, of the information in this file without a      */
/* written consent of an officer of Cortina Systems Incorporated is    */
/* strictly prohibited.                                                */
/* Copyright (c) 2002-2014 by Cortina Systems Incorporated.            */
/***********************************************************************/
/*
 * cs_rtos.h
 *
 * Header file with RTOS specific defines and macros that can be
 * customized as required by the target environment.
 *
 * $Id: cs_rtos.h,v 1.23 2014/03/20 15:28:15 ktleinfe Exp $
 */
#ifndef __CS_RTOS_H__
#define __CS_RTOS_H__


/******** NOTE ********** NOTE ********** NOTE ********* NOTE *********
 * NOTE: This header file MUST BE CUSTOMIZED before using the driver!!*
 *                                                                    *
 * This contains all the RTOS(like system calls) and environment      *
 * related macro's and stub utilities which should be modified or     *
 * filled in as suited to the customer environment. It is important   *
 * that this customization or porting of the driver is done BEFORE    *
 * making any attempt to compile or use the driver.                   *
 ******** NOTE ********** NOTE ********** NOTE ********* NOTE *********/

#ifndef CS_DONT_USE_STDLIB
# include <stdlib.h>  /* for malloc() and free() */
# include <unistd.h>     /* for usleep              */
# include <errno.h>
# include <string.h>     /* for memcpy()            */

#endif /* CS_DONT_USE_STDLIB */

#include "cs_types.h"
#include "../../../lib/util/util.h"
#include "../../gpio/gpio.h"
#include <sys/syslog.h>

#define MSG_WRITE "write: %p - %#010x"
#define MSG_READ  "read:  %p"
#ifdef T41_EVB_SDK
#define T41_SYS_ID 448
#endif

#ifndef RELEASE_PLATFORM  /* for Cortina Internal use only! */
#ifndef POSIX_PTHREAD
# define POSIX_PTHREAD
#endif

#include "cs_lab_rtos.h"

#endif        /* for Cortina Internal use only! */

#ifdef GTEST
#include "cs_ut_rtos.h"
#endif

/*
 * The following macro determines if we are running in interrupt
 * context. Customer can change this macro to determine if we are
 * in interrupt context by reading the CPU register or through the
 * OS provided APIs.
 */
#ifndef CS_IS_INTR_CONTEXT
# define CS_IS_INTR_CONTEXT()            0
#endif /* CS_IS_INTR_CONTEXT */


/*
 * CS_IRQ_USER_HANDLER macro maps the user provided handler to be called.
 * Customer can redefine this macro to call their ISR handler.
 */
#ifndef CS_IRQ_USER_HANDLER
# define CS_IRQ_USER_HANDLER(DPID, IRQ_INFO)    \
  { /* add code to call user handler */ }
#endif /* CS_IRQ_USER_HANDLER */


/**********************************************************
 *         Register Access Methods                        *
 **********************************************************/
#ifndef __CS_REG_ACCESS_DEFINED__
#define __CS_REG_ACCESS_DEFINED__
/********   Read  Register  *********/
CS_INLINE  cs_uint32 CS_REG_READ(volatile cs_uint32 * pReg)
{
    /*openlog("T41", LOG_PID|LOG_CONS, LOG_USER);
    syslog(LOG_CRIT, MSG_READ, pReg);
    closelog();*/

	return parallel_read(*pReg);

#ifdef CS_DONT_USE_INLINE
  if ( 0 ) { /* don't modify this - this keeps compiler happy */
    CS_REG_READ(pReg) ;
  }
#endif /* CS_DONT_USE_INLINE */
}

/********   Write  Register  *********/
CS_INLINE CS_REG_WRITE(volatile cs_uint32 * pReg, cs_uint32 data)
{
    /*openlog("T41", LOG_PID|LOG_CONS, LOG_USER);
    syslog(LOG_CRIT, MSG_WRITE, pReg, data);
    closelog();*/

	return parallel_write(*pReg, data);

#ifdef CS_DONT_USE_INLINE
  if ( 0 ) { /* don't modify this - this keeps compiler happy */
    CS_REG_WRITE(pReg, data) ;
  }
#endif /* CS_DONT_USE_INLINE */
}

#endif /* __CS_REG_ACCESS_DEFINED__ */


/**********************************************************
 *         Timer delay utilities                          *
 **********************************************************/
#ifndef __CS_DELAY_UTILS_DEFINED__
#define __CS_DELAY_UTILS_DEFINED__
#       define CS_UDELAY(usecs) ( usleep(usecs) )
#       define CS_MDELAY(msecs) ( usleep(msecs * 1000) )
#endif /* __CS_DELAY_UTILS_DEFINED__ */


/**********************************************************
 *         Memory Handling                                *
 **********************************************************/
#ifndef __CS_MEM_UTILS_DEFINED__
#define __CS_MEM_UTILS_DEFINED__
#ifndef CS_DONT_USE_STDLIB
# define  CS_MALLOC(x)        malloc(x)

/* bugzilla #21563 */
# define  CS_FREE(x)          { free(x); x = NULL; }
# define  CS_MEMCPY(DST, SRC, LEN)    memcpy((DST), (SRC), (LEN))
# define  CS_MEMSET(DST, VALUE, LEN)  memset((DST), (VALUE), (LEN))
# define  CS_MEMCMP(DST, SRC, LEN)    memcmp((DST), (SRC), (LEN))
#else
/* user defined memory handling utilities should be defined here  */
/* #  define  CS_MALLOC(x)       <....>  */
/* #  define  CS_FREE(x)       <....>  */
/* #  define  CS_MEMCPY(DST, SRC, LEN)   <....>  */
/* #    define  CS_MEMSET(DST, VALUE, LEN) <....>  */
/* #    define  CS_MEMCMP(DST, SRC, LEN)   <....>  */
#endif /* CS_DONT_USE_STDLIB */
#endif /* __CS_MEM_UTILS_DEFINED__ */


/**********************************************************
 *         Error Reporting                                *
 **********************************************************/
#ifndef CS_SET_ERRNO
#ifndef CS_DONT_USE_STDLIB
# define  CS_SET_ERRNO(x) errno = x
#endif /* CS_DONT_USE_STDLIB */
#endif /* CS_SET_ERRNO */


/**********************************************************
 *                  Semaphores                            *
 *                                                        *
 * Change CS_SEM typedef appropriately and add code to    *
 * CS_SEM_* inline functions to implement RTOS-dependent  *
 * semaphore handling mechanism.                          *
 *                                                        *
 * NOTE: Use mutually exclusive semaphores(and not plain  *
 * binary ones) which allow the same task/process which is*
 * currently the owner of a semaphore take it again(ie.   *
 * recursively)! This is required as some driver API's    *
 * may be a nested call to other API's and could take the *
 * same semaphore more than once.                         *
 **********************************************************/
#ifndef __CS_SEM_UTILS_DEFINED__
#define __CS_SEM_UTILS_DEFINED__

typedef void *  CS_SEM ;

CS_INLINE  cs_status  CS_SEM_INIT(CS_SEM * sem_id)
{
  /* Add code to create semaphore */
  return(CS_OK) ;

#ifdef CS_DONT_USE_INLINE
  if ( 0 ) { /* don't modify this - this keeps compiler happy */
    CS_SEM_INIT(sem_id) ;
  }
#endif
}


CS_INLINE  cs_status  CS_SEM_TAKE(CS_SEM * sem_id)
{
  if (CS_IS_INTR_CONTEXT()) {
    return (CS_ERROR) ;
  }
  /* Add code to take semaphore */
  return(CS_OK) ;

#ifdef CS_DONT_USE_INLINE
  if ( 0 ) { /* don't modify this - this keeps compiler happy */
    CS_SEM_TAKE(sem_id) ;
  }
#endif
}


CS_INLINE  void  CS_SEM_GIVE(CS_SEM * sem_id)
{
  if (CS_IS_INTR_CONTEXT()) {
    return ;
  }
  /* Add code to post/give semaphore */
  return ;

#ifdef CS_DONT_USE_INLINE
  if ( 0 ) { /* don't modify this - this keeps compiler happy */
    CS_SEM_GIVE(sem_id) ;
  }
#endif
}


CS_INLINE  cs_status  CS_SEM_DESTROY(CS_SEM * sem_id)
{
  /* Delete semaphore */
  return(CS_OK) ;

#ifdef CS_DONT_USE_INLINE
  if ( 0 ) { /* don't modify this - this keeps compiler happy */
    CS_SEM_DESTROY(sem_id) ;
  }
#endif
}

#endif /* __CS_SEM_UTILS_DEFINED__ */



/**********************************************************
 *         Interrupt locking                              *
 **********************************************************/
#ifndef __CS_IRQ_LOCKING_DEFINED__
#define __CS_IRQ_LOCKING_DEFINED__

CS_INLINE  cs_uint32  CS_INTERRUPT_LOCK()
{
  /* Add code to lock out maskable interrupts */
  return (0) ; /* return key */

#ifdef CS_DONT_USE_INLINE
  if ( 0 ) { /* don't modify this - this keeps compiler happy */
    CS_INTERRUPT_LOCK() ;
  }
#endif
}


CS_INLINE  void CS_INTERRUPT_UNLOCK(cs_uint32 key)
{
  /* Add code to unlock maskable interrupts */

#ifdef CS_DONT_USE_INLINE
  if ( 0 ) { /* don't modify this - this keeps compiler happy */
    CS_INTERRUPT_UNLOCK(key) ;
  }
#endif
}

#endif /* __CS_IRQ_LOCKING_DEFINED__ */



#endif /* __CS_RTOS_H__ */










