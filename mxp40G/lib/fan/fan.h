/**
 * \file
 * \brief FAN API header.
 */
#ifndef _FAN_H_
#define _FAN_H_

#define FAN_SPEED_WARNING 0
#define FAN_SPEED_OK 1

/**
 * \brief This function gets the Alert status of specified fan.
 * 
 * \param[in] fan_id Fan Id. Either FAN1_ALERT, FAN2_ALERT, FAN3_ALERT, FAN4_ALERT or FAN5_ALERT
 * 
 * \param[out] status Alert Status is written in this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int fan_get_alert(unsigned int fan_id, unsigned int *status);

/**
 * \brief This function Clears the Alert status of specified fan.
 * 
 * \param[in] fan_id Fan Id. Either FAN1_CLEAR, FAN2_CLEAR, FAN3_CLEAR, FAN4_CLEAR or FAN5_CLEAR
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int fan_clear(unsigned int fan_id);

#endif /* _FAN_H_ */
