/**
 * \file
 * \brief RTC API header.
 * 
 */
#ifndef _RTC_H
#define _RTC_H


/**
 * I2C BUS
 */
#define RTC_BUS	0x09

/**
 * I2C Module Address
 */
#define RTC_SLAVE_ADDRESS	0x68
/**
 * Seconds Register Address
 */
#define RTC_SECONDS			0x00
/**
 * Minutes Register Address
 */
#define RTC_MINUTES			0x01
/**
 * Hours Register Address
 */
#define RTC_HOURS			0x02
/**
 * Day Register Address
 */
#define RTC_DAY				0x03
/**
 * Date egister Address
 */
#define RTC_DATE			0x04	
/**
 * Month egister Address
 */
#define RTC_MONTH			0x05
/**
 * Year Register Address
 */
#define RTC_YEARS			0x06
/**
 * Calibration and configuration Register Address
 */
#define RTC_CAL_CFG1		0x07
/**
 * Trickle charge enable Register Address
 */
#define RTC_TCH2			0x08
/**
 * Configuration 2 Register Address
 */
#define RTC_CFG2			0x09
/**
 * Special function key 1 Register Address
 */
#define RTC_SF_KEY_1		0x20
/**
 * Special function key 2 Register Address
 */
#define RTC_SF_KEY_2		0x21
/**
 * Special function registe Register Address
 */
#define RTC_SFR				0x22
/**
 * Bus number of RTC chip
 */
#define RTC_I2C_BUS_NUMBER	0x04
/**
 * Minimum Second Value.
 */
#define RTC_SECONDS_MIN		0
/**
 * Maximum Second Value.
 */
#define RTC_SECONDS_MAX		59
/**
 * Stop Address Register.
 */
#define RTC_STOP_BYTE		0x80
/**
 * Minimum Minute Value.
 */
#define RTC_MINUTES_MIN		0
/**
 * Maximum Minute Value.
 */
#define RTC_MINUTES_MAX		59
/**
 * Minimum Hour Value.
 */
#define RTC_HOUR_MIN		0
/**
 * Maximum Hour Value.
 */
#define RTC_HOUR_MAX		23
/**
 * Minimum Day Value.
 */
#define RTC_DAY_MIN		1
/**
 * Maximum Day Value.
 */
#define RTC_DAY_MAX		7
/**
 * Minimum Date Value.
 */
#define RTC_DATE_MIN		1
/**
 * Maximum Date Value.
 */
#define RTC_DATE_MAX		31
/**
 * Minimum Month Value.
 */
#define RTC_MONTH_MIN		1
/**
 * Maximum Month Value.
 */
#define RTC_MONTH_MAX		12
/**
 * Minimum Year Value.
 */
#define RTC_YEARS_MIN		0
/**
 * Maximun Year Value.
 */
#define RTC_YEARS_MAX		99

/**
 * \brief This function sets the RTC Seconds
 *
 * \param[in] i2c_bus_number  RTC number.
 * 
 * \param[in] seconds Seconds Value to set.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_set_seconds(int seconds);

/**
 * \brief This function stops the RTC chip.
 *
 * \param[in] i2c_bus_number  RTC number.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_stop();

/**
 * \brief This function gets the seconds of RTC chip.
 *	
 * \param[in] i2c_bus_number  RTC number.
 *
 * \param[out] seconds  Seconds Value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_get_seconds(int *seconds);

/**
 * \brief This function sets the minutes at RTC chip.
 *
 * \param[in] i2c_bus_number  RTC number.
 * 
 * \param[in] minutes Minutes Value to set.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_set_minutes(int minutes);

/**
 * \brief This function gets the minutes of RTC chip.
 *	
 * \param[in] i2c_bus_number  RTC number.
 *
 * \param[out] minutes  Minutes Value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 * 
 */
int rtc_get_minutes(int *minutes);

/**
 * \brief This function sets the hour at RTC chip.
 *
 * \param[in] i2c_bus_number  RTC number.
 * 
 * \param[in] hour Hour Value to set.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_set_hour(int hour);

/**
 * \brief This function gets the hour of RTC chip.
 *	
 * \param[in] i2c_bus_number  RTC number.
 *
 * \param[out] hour Hour value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_get_hour(int *hour);

/**
 * \brief This function sets the day at RTC chip.
 *
 * \param[in] i2c_bus_number  RTC number.
 * 
 * \param[in] day Day Value to set. Either 1 Sunday, 2 Monday, 3 Tuesday, 4 Wednesday, 5 Thursday, 6 Friday or 7 Saturday.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_set_day(int day);

/**
 * \brief This function gets the day of RTC chip.
 *	
 * \param[in] i2c_bus_number  RTC number.
 *
 * \param[out] day Day value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_get_day(int *day);

/**
 * \brief This function sets the date at RTC chip.
 *
 * \param[in] i2c_bus_number  RTC number.
 * 
 * \param[in] date Date value to set.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_set_date(int date);

/**
 * \brief This function gets the date of RTC chip.
 *	
 * \param[in] i2c_bus_number  RTC number.
 *
 * \param[out] date Function output is written to this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_get_date(int *date);

/**
 * \brief This function sets the months at RTC chip.
 *
 * \param[in] i2c_bus_number  RTC number.
 * 
 * \param[in] months Month Value to set.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_set_months(int months);

/**
 * \brief This function gets the months of RTC chip.
 *	
 * \param[in] i2c_bus_number  RTC number.
 *
 * \param[out] months Months Value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_get_months(int *months);

/**
 * \brief This function sets the years at RTC chip.
 *
 * \param[in] i2c_bus_number  RTC number.
 * 
 * \param[in] years Years Value to set.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_set_years(int years);

/**
 * \brief This function gets the years of RTC chip.
 *	
 * \param[in] i2c_bus_number  RTC number.
 *
 * \param[out] years Year Value is written to this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_get_years(int *years);

/**
 * \brief This function sets the date from the RTC chip.
 *	
 * \param[in] i2c_bus_number  RTC number.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0. */
int set_date_from_rtc(void);

/**
 * \brief This function converts int value to hex value.
 *	
 * \param[in] in int value.
 * 
 * \param[out] out Hex value is written in this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_int_to_hex(int in, int *out);

/**
 * \brief This function converts hex value to int value.
 *	
 * \param[in] in hex value.
 * 
 * \param[out] out int value is written in this variable.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int rtc_hex_to_int(int in, int *out);

#endif /* _RTC_H */
