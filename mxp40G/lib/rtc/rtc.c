#include "rtc.h"
#include "../i2c/i2crw.h"
#include "../gpio/gpio.h"
#include <math.h> 
#include "../../include/util.h"
#include <unistd.h>
#include <ctype.h>

int rtc_set_seconds(int seconds)
{

	CHECK_PARAM(seconds < RTC_SECONDS_MIN || seconds > RTC_SECONDS_MAX, LOG_ERR, TAG_RTC, 
        "Error in rtc_set_seconds(): seconds out of range");

	int s;   
	rtc_int_to_hex(seconds,&s);
   
	CHECK_PARAM(i2c_write(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_SECONDS, 
	I2C_SMBUS_BYTE_DATA, &s, 0) < 0, LOG_ERR, TAG_RTC, 
	"Error in rtc_set_seconds(): i2c_write()");    

    return 0;
}

int rtc_stop()
{
	int current_value;

	CHECK_PARAM(i2c_read(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_SECONDS, 
	I2C_SMBUS_BYTE_DATA, &current_value, 0) < 0, LOG_ERR, TAG_RTC, 
	"Error in rtc_stop(): i2c_read()");

	int new_value = (current_value | RTC_STOP_BYTE);
        
	CHECK_PARAM(i2c_write(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_SECONDS, 
	I2C_SMBUS_BYTE_DATA, &new_value, 0) < 0, LOG_ERR, TAG_RTC, 
	"Error in rtc_stop(): i2c_write()");    

return 0;
}

int rtc_get_seconds(int *seconds)
{
	
	CHECK_PARAM(i2c_read(RTC_BUS, RTC_SLAVE_ADDRESS, 0x00, I2C_SMBUS_BYTE_DATA, 
	seconds, 0) < 0, LOG_ERR, TAG_RTC, 
	"Error in rtc_get_seconds(): i2c_read()");

	*seconds = *seconds & 0x7F;

	rtc_hex_to_int(*seconds, seconds);
    
return 0;
}

int rtc_set_minutes(int minutes)
{
	
	CHECK_PARAM(minutes < RTC_MINUTES_MIN || minutes > RTC_MINUTES_MAX, LOG_ERR, TAG_RTC, 
	"Error in rtc_set_minutes(): minutes out of range");

	int m;
	rtc_int_to_hex(minutes, &m);

	CHECK_PARAM(i2c_write(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_MINUTES, 
	I2C_SMBUS_BYTE_DATA, &m, 0) < 0, LOG_ERR, TAG_RTC, 
	"Error in rtc_set_minutes(): i2c_write()");    

return 0;
}

int rtc_get_minutes(int *minutes)
{
	CHECK_PARAM(i2c_read(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_MINUTES, I2C_SMBUS_BYTE_DATA, 
	minutes, 0) < 0, LOG_ERR, TAG_RTC, 
	"Error in rtc_get_minutes(): i2c_read()");

	*minutes = *minutes & 0x7F;
	rtc_hex_to_int(*minutes, minutes);

return 0;
}

int rtc_set_hour(int hour)
{
	CHECK_PARAM(hour < RTC_HOUR_MIN || hour > RTC_HOUR_MAX, LOG_ERR, TAG_RTC, 
	"Error in rtc_set_hour(): hour out of range");

	int h;
	rtc_int_to_hex(hour, &h);

	CHECK_PARAM(i2c_write(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_HOURS, 
	I2C_SMBUS_BYTE_DATA, &h, 0) < 0, LOG_ERR, TAG_RTC, 
	"Error in rtc_set_hour(): i2c_write()");

return 0;
}

int rtc_get_hour(int *hour)
{
	
	CHECK_PARAM(i2c_read(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_HOURS, I2C_SMBUS_BYTE_DATA, 
	hour, 0) < 0, LOG_ERR, TAG_RTC, "Error in rtc_get_hour(): i2c_read()");

	*hour = (*hour&0x3F);
	rtc_hex_to_int(*hour, hour);

return 0;
}

int rtc_set_day(int day)
{
	CHECK_PARAM(day < RTC_DAY_MIN || day > RTC_DAY_MAX, LOG_ERR, TAG_RTC, 
	"Error in rtc_set_day(): day out of range");

	CHECK_PARAM(i2c_write(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_DAY, 
	I2C_SMBUS_BYTE_DATA, &day, 0) < 0, LOG_ERR, TAG_RTC, 
	"Error in rtc_set_day(): i2c_write()");

return 0;
}

int rtc_get_day(int *day)
{
	CHECK_PARAM(i2c_read(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_DAY, I2C_SMBUS_BYTE_DATA, 
	day, 0) < 0, LOG_ERR, TAG_RTC, "Error in rtc_get_day(): i2c_read()");

	*day = (*day&0x07);

return 0;
}

int rtc_set_date(int date)
{
	CHECK_PARAM(date < RTC_DATE_MIN || date > RTC_DATE_MAX, LOG_ERR, TAG_RTC, 
	"Error in rtc_set_date(): date out of range");

	int d;
	rtc_int_to_hex(date, &d);

	CHECK_PARAM(i2c_write(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_DATE, 
	I2C_SMBUS_BYTE_DATA, &d, 0) < 0, LOG_ERR, TAG_RTC, "Error in rtc_set_date(): i2c_write()");

return 0;
}

int rtc_get_date(int *date)
{
	CHECK_PARAM(i2c_read(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_DATE, I2C_SMBUS_BYTE_DATA, 
	date, 0) < 0, LOG_ERR, TAG_RTC, "Error in rtc_get_date(): i2c_read()");

	*date = (*date&0x3F);
	rtc_hex_to_int(*date, date);

return 0;
}

int rtc_set_months(int months)
{
	
	CHECK_PARAM(months < RTC_MONTH_MIN || months > RTC_MONTH_MAX, LOG_ERR, TAG_RTC, 
	"Error in rtc_set_months(): months out of range");

	int m;
	rtc_int_to_hex(months, &m);

	CHECK_PARAM(i2c_write(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_MONTH, 
	I2C_SMBUS_BYTE_DATA, &m, 0) < 0, LOG_ERR, TAG_RTC, "Error in rtc_set_months(): i2c_write()");

return 0;
}

int rtc_get_months( int *months)
{
	CHECK_PARAM(i2c_read(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_MONTH, I2C_SMBUS_BYTE_DATA, 
	months, 0) < 0, LOG_ERR, TAG_RTC, "Error in rtc_get_months(): i2c_read()");

	*months = (*months&0x1F);
	rtc_hex_to_int(*months, months);

return 0;
}

int rtc_set_years(int years)
{
	CHECK_PARAM(years < RTC_YEARS_MIN || years > RTC_YEARS_MAX, LOG_ERR, TAG_RTC, 
	"Error in rtc_set_years(): years out of range");

	int y;
	rtc_int_to_hex(years, &y);

	CHECK_PARAM(i2c_write(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_YEARS, 
	I2C_SMBUS_BYTE_DATA, &y, 0) < 0, LOG_ERR, TAG_RTC, "Error in rtc_set_years(): i2c_write()");

return 0;
}

int rtc_get_years( int *years)
{
	CHECK_PARAM(i2c_read(RTC_BUS, RTC_SLAVE_ADDRESS, RTC_YEARS, I2C_SMBUS_BYTE_DATA,
	years, 0) < 0, LOG_ERR, TAG_RTC, "Error in rtc_get_years(): i2c_read()");

	rtc_hex_to_int(*years, years);

return 0;
}

int set_date_from_rtc()
{
	int sec,min,hs,day,date,months,years;

        rtc_get_seconds(&sec);
        rtc_get_minutes(&min);
        rtc_get_hour(&hs);
	rtc_get_day(&day);
	rtc_get_date(&date);
	rtc_get_months(&months);
	rtc_get_years(&years);

	char cmd[32];
	sprintf(cmd, "date --set '20%d-%d-%d %d:%d'\n",years,months,date,hs,min);
	system(cmd);

return 0;
}

int rtc_int_to_hex(int in, int *out)
{
//    printf("in: %d\n",in);

    if((0 <= in ) && (in < 10))
        *out = in;
    if((10 <= in ) && (in <= 19))
        *out = in+6;
    if((20 <= in ) && (in <= 29))
        *out = in+12;
    if((30 <= in ) && (in <= 39))
        *out = in+18;
    if((40 <= in ) && (in <= 49))
        *out = in+24;
    if((50 <= in ) && (in <= 59))
        *out = in+30;
    if((60 <= in ) && (in <= 69))
        *out = in+36;
    if((70 <= in ) && (in <= 79))
        *out = in+42;
    if((80 <= in ) && (in <= 89))
        *out = in+48;
    if((90 <= in ) && (in <= 99))
        *out = in+54;

//    printf("out: %d\n",*out);
    return 0;
}

int rtc_hex_to_int(int in, int *out)
{
//    printf("in: %d\n",in);

    if((0 <= in ) && (in < 10)) 
        *out = in;
    if((16 <= in ) && (in <= 25)) 
        *out = in-6;
    if((32 <= in ) && (in <= 41)) 
        *out = in-12;
    if((48 <= in ) && (in <= 57)) 
        *out = in-18;
    if((64 <= in ) && (in <= 73)) 
        *out = in-24;
    if((80 <= in ) && (in <= 89)) 
        *out = in-30;
    if((96 <= in ) && (in <= 105))
        *out = in-36;
    if((112 <= in ) && (in <= 121))
        *out = in-42;
    if((128 <= in ) && (in <= 137))
        *out = in-48;
    if((144 <= in ) && (in <= 153))
        *out = in-54;

//    printf("out: %d\n",*out);
    return 0;
}


