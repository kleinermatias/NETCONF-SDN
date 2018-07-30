/*
 * test_syslog.c
 *
 *  Created on: 3 nov. 2016
 *      Author: maguerreberry
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/syslog.h>
#include "syslog_test.h"

#ifndef LOGGING_H
#define LOGGING_H
#include "../lib/util/util.h"
#endif

#define CANT_MESSAGE 1026

int main(int argc, char **argv){
	int tag = 0;
	char id_msg[150] = "";

	for(int ii=0; ii<1728000; ii++){

		sprintf(id_msg,"Nº=%d", ii) ;

		CHECK_PARAM(1, LOG_ERR, tag, id_msg, LOG_USER);

		printf( "Ready %d \n\r",ii);

		usleep(50 * 1000); //500 milisegundos
	}

	printf( "Test app finished");

	return 0;
}

/*
int main(int argc, char **argv) {
	while(1){
		char * tag = "monitor";

		for(int i = 0; i < 20; i++){
			CHECK_PARAM(1,LOG_ERR, tag, "message", LOG_USER);
		}
		for(int i = 0; i < 20; i++){
			CHECK_PARAM(1,LOG_ERR, tag, "message", LOG_LOCAL0);
			//JUST_LOG_1(LOG_ERR, tag, "local 0 facility %s","just_log_1", LOG_LOCAL0);
		}

		tag = 0;

		for(int i = 0; i < 20; i++){
			CHECK_PARAM(1,LOG_ERR, tag, "message", LOG_USER);
			//JUST_LOG_1(LOG_ERR, tag, "user facility %s","just_log_1", LOG_USER);
		}

		for(int i = 0; i < 20; i++){
			CHECK_PARAM(1,LOG_ERR, tag, "message", LOG_LOCAL0);
			//JUST_LOG_1(LOG_ERR, tag, "local 0 facility %s","just_log_1", LOG_LOCAL0);
		}

		printf( "Ready\n\r");
		sleep(1);
		printf( "_Ready_\n\r");
	}

	return 0;
}
 */
