/**
 * \file
 * \brief LTC API header.
 */
#ifndef _LTC_H
#define _LTC_H

/**
 * Latch Enable.
 */
#define LTC_ENABLED 1
/**
 * Latch Disable.
 */
#define LTC_DISABLED 0

/**
 * \brief This function enables the latch.    
 *
 * When the latch is enabled all the input signals are copied to the output of 
 * the latch.  
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int ltc_enable_latch(void);

/**
 * \brief This function disable the latch.
 *
 * When the latch is disabled, all output signals are frozen to the value of 
 * the inputs at the time of disabling the latch. 
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0. 
 */
int ltc_disable_latch(void);

/**
 * \brief This function returns the status of the latch.
 *
 * \param[out] latch_value Latch Status is written in this variable.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int ltc_get_latch_status(int *latch_value);


int latch_optical_modules_enable(void);

int latch_optical_modules_disable(void);

int latch_optical_modules_status(int *latch_value);

int latch_txp_enable(void);

int latch_txp_disable(void);

int latch_txp_status(int *latch_value);

#endif /* _LTC_H */
