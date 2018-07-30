/*
    util.c - helper functions
    Copyright (C) 2006 Jean Delvare <khali@linux-fr.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
 */

#include <stdio.h>
#include "util.h"


int CHECK_PARAM(const uint8_t expr, const int svrt,const char * tag, const char * msg, const int facility){
	if (expr) {
		send_syslog(svrt, tag, msg, facility);
		return -1;
	}
	else
		return 0;
}

void CHECK_PARAM_N(const uint8_t expr, const int svrt,const char * tag, const char * msg, const int id, const int facility){
	char id_msg[500] = "";
	int result = sprintf(id_msg,"(ID=%d) %s", id, msg);
	if(result < 0)
		perror("sprintf CHECK_PARAM_N");
	else
		CHECK_PARAM(expr,svrt,tag,id_msg,facility);
}

void LOG_AND_EXIT(const int svrt ,const char * tag,const char * msg, const int facility){
	CHECK_PARAM(1,svrt,tag,msg,facility);
}

void JUST_LOG(const int svrt ,const char * tag,const char * msg, const int facility){
	CHECK_PARAM(1,svrt,tag,msg,facility);
}

void LOG_VAR_1(const int svrt ,const char * tag, const char * msg, const char * var1, const int facility){
	char log_msg[500] = "";
	int result = sprintf(log_msg, msg,var1);
	if(result < 0)
		perror("sprintf LOG_VAR_1");
	else
		CHECK_PARAM(1,svrt,tag,log_msg,facility);
}

void LOG_VAR_2(const int svrt ,const char * tag, const char * msg, const char * var1,const char * var2, const int facility){
	char log_msg[500] = "";
	int result = sprintf(log_msg, msg,var1,var2);
	if(result < 0)
		perror("sprintf LOG_VAR_2");
	else
		CHECK_PARAM(1,svrt,tag,log_msg,facility);
}


void LOG_I2C(const int exp, const int svrt ,const char * tag, const char * msg, const int var1, const int var2, const int facility){
	char log_msg[500] = "";

	sprintf(log_msg,"i2c bus name: %d; slave address: 0x%02x; %s",var1,var2,msg);

	CHECK_PARAM(exp,svrt,tag,log_msg,facility);
}

void LOG_VAR_3(const int svrt ,const char * tag, const char * msg, const char * var1, const char * var2, const char * var3, const int facility){
	char log_msg[500] = "";
	int result = sprintf(log_msg, msg,var1,var2,var3);
	if(result < 0)
		perror("sprintf LOG_VAR_3");
	else
		CHECK_PARAM(1,svrt,tag,log_msg,facility);
}

void LOG_VAR_4(const int svrt ,const char * tag, const char * msg, const char * var1, const char * var2, const char * var3, const char * var4, const int facility){
	char log_msg[500] = "";
	int result = sprintf(log_msg, msg,var1,var2,var3,var4);
	if(result < 0)
		perror("sprintf LOG_VAR_4");
	else
		CHECK_PARAM(1,svrt,tag,log_msg,facility);
}

void LOG_VAR_5(const int svrt ,const char * tag, const char * msg, const char * var1, const char * var2, const char * var3, const char * var4, const char * var5, const int facility){
	char log_msg[500] = "";
	int result = sprintf(log_msg, msg,var1,var2,var3,var4,var5);
	if(result < 0)
		perror("sprintf LOG_VAR_5");
	else
		CHECK_PARAM(1,svrt,tag,log_msg,facility);
}

/* Return 1 if we should continue, 0 if we should abort */

int user_ack(int def)
{
	char s[2];
	int ret;

	if (!fgets(s, 2, stdin))
		return 0; /* Nack by default */

	switch (s[0]) {
	case 'y':
	case 'Y':
		ret = 1;
		break;
	case 'n':
	case 'N':
		ret = 0;
		break;
	default:
		ret = def;
	}

	/* Flush extra characters */
	while (s[0] != '\n') {
		int c = fgetc(stdin);
		if (c == EOF) {
			ret = 0;
			break;
		}
		s[0] = c;
	}

	return ret;
}

