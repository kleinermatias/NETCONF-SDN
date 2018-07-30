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

#ifndef __SYSLOG_H__
#define __SYSLOG_H__
#include <sys/syslog.h>
#endif /* __SYSLOG_H__ */

#include <string.h>
#include <stdarg.h>
#include "logtags.h"



#define CHECK_PARAM(expr, svrt, tag, msg) do {\
            if ( expr ) {\
                openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
                syslog(svrt, msg);\
                closelog();\
                return -1;\
            }\
} while (0)

#define CHECK_PARAM_N(expr, svrt, tag, msg, id) do {\
            if ( expr ) {\
                openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
                syslog(svrt, "(ID=%d) %s", id, msg);\
                closelog();\
                return -1;\
            }\
} while (0)

#define LOG_AND_EXIT(svrt, tag, msg) do {\
            openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
            syslog(svrt, msg);\
            closelog();\
            return -1;\
} while (0)

#define JUST_LOG(svrt, tag, msg) do {\
            openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
            syslog(svrt, msg);\
            closelog();\
} while (0)

#define JUST_LOG_1(svrt, tag, msg, var1) do {\
            openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
            syslog(svrt, msg, var1);\
            closelog();\
} while (0)

#define JUST_LOG_2(svrt, tag, msg, var1, var2) do {\
            openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
            syslog(svrt, msg, var1, var2);\
            closelog();\
} while (0)

#define JUST_LOG_3(svrt, tag, msg, var1, var2, var3) do {\
            openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
            syslog(svrt, msg, var1, var2, var3);\
            closelog();\
} while (0)

#define JUST_LOG_4(svrt, tag, msg, var1, var2, var3, var4) do {\
            openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
            syslog(svrt, msg, var1, var2, var3, var4);\
            closelog();\
} while (0)

#define JUST_LOG_5(svrt, tag, msg, var1, var2, var3, var4, var5) do {\
            openlog(tag, LOG_PID|LOG_CONS, LOG_USER);\
            syslog(svrt, msg, var1, var2, var3, var4, var5);\
            closelog();\
} while (0)

extern int user_ack(int def);


#endif /* __UTIL_H__ */
