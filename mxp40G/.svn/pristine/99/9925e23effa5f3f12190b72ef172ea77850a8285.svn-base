/*
    util - helper functions
    Copyright (C) 2006 Jean Delvare <khali@linux-fr.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
 */

#ifndef __LOGGING_H__
#define __LOGGING_H__

#ifndef __SYSLOG_H__
#define __SYSLOG_H__
#include <sys/syslog.h>
#endif /* __SYSLOG_H__ */

#include <string.h>

#include "../../include/logtags.h"

void send_syslog(const int, const char *, const char *, const int );
char * add_facility2msg(const int);


#endif /* __LOGGING_H__ */
