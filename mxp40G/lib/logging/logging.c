/*
 * logging.c
 *
 *  Created on: 16 nov. 2016
 *      Author: maguerreberry
 */

#include "logging.h"

void send_syslog(const int svrt, const char * tag, const char * msg, const int facility){
	char fac_msg[3000] = "";
	strcpy(fac_msg, add_facility2msg(facility));
	strcat(fac_msg, msg);
	openlog(tag, LOG_PID|LOG_CONS, facility);
	syslog(svrt, fac_msg);
	closelog();
}

char * add_facility2msg (const int facility){
	if(facility == LOG_USER)
		return "[U]";

	else if (facility == LOG_LOCAL0)
		return "[H]";

	else
		return "[D]";
}
