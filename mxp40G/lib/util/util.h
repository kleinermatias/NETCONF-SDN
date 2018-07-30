/*
    util - helper functions
    Copyright (C) 2006 Jean Delvare <khali@linux-fr.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
 */

#ifndef __UTIL_H__
#define __UTIL_H__

#include <sys/syslog.h>

#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include "../../include/logtags.h"
#include "../logging/logging.h"

int CHECK_PARAM(const uint8_t , const int ,const char * , const char * , const int );

/*
#define CHECK_PARAM(expr, svrt, tag, msg) do {\
            if ( expr ) {\
                openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
                syslog(svrt, msg);\
                closelog();\
                return -1;\
            }\
} while (0)
*/

void CHECK_PARAM_N(const uint8_t , const int ,const char * , const char * , const int, const int );

/*
#define CHECK_PARAM_N(expr, svrt, tag, msg, id) do {\
		if ( expr ) {\
			openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
			syslog(svrt, "(ID=%d) %s", id, msg);\
			closelog();\
			return -1;\
		}\
} while (0)
*/

void LOG_AND_EXIT(const int ,const char * tag,const char *,const int);

/*
#define LOG_AND_EXIT(svrt, tag, msg) do {\
		openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
		syslog(svrt, msg);\
		closelog();\
		return -1;\
} while (0)
*/

void JUST_LOG(const int ,const char * tag,const char *,const int);

/*
#define JUST_LOG(svrt, tag, msg) do {\
		openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
		syslog(svrt, msg);\
		closelog();\
} while (0)
*/

void LOG_I2C(const int exp, const int svrt ,const char * tag, const char * msg, const int var1, const int var2, const int facility);

void LOG_VAR_1(const int ,const char *,const char *,const char *,const int);

/*
#define JUST_LOG_1(svrt, tag, msg, var1) do {\
		openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
		syslog(svrt, msg, var1);\
		closelog();\
} while (0)
*/

void LOG_VAR_2(const int ,const char *,const char *,const char *, const char *, const int);

/*
#define JUST_LOG_2(svrt, tag, msg, var1, var2) do {\
		openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
		syslog(svrt, msg, var1, var2);\
		closelog();\
} while (0)
*/

void LOG_VAR_3(const int ,const char *,const char *,const char *, const char *, const char *, const int);

/*
#define JUST_LOG_3(svrt, tag, msg, var1, var2, var3) do {\
		openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
		syslog(svrt, msg, var1, var2, var3);\
		closelog();\
} while (0)
*/

void LOG_VAR_4(const int ,const char *,const char *,const char *, const char *, const char *, const char *, const int);

/*
#define JUST_LOG_4(svrt, tag, msg, var1, var2, var3, var4) do {\
		openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
		syslog(svrt, msg, var1, var2, var3, var4);\
		closelog();\
} while (0)
*/

void LOG_VAR_5(const int ,const char *,const char *,const char *, const char *, const char *, const char *, const char *, const int);

/*
#define JUST_LOG_5(svrt, tag, msg, var1, var2, var3, var4, var5) do {\
		openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
		syslog(svrt, msg, var1, var2, var3, var4, var5);\
		closelog();\
} while (0)
*/

extern int user_ack(int def);

#endif /* __UTIL_H__ */
