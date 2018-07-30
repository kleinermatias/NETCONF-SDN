#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <termios.h>
#include <fcntl.h>
#include "rtc.h"
#include "edfa.h"
#include "gpio.h"
#include "txp.h"
#include "xfp.h"
#include "utils.h"
#include "version.h"
#include "hl_configs.h"

typedef struct{
	int year;
	int month;
	int day;
}date_now;

typedef struct{
	int hours;
	int minutes;
	int seconds;
}time_now;

void doc(void)
{
    printf("USAGE: ./setting --date -y [] -m [] -d [] -h [] -t [] -s [] \n -y: year \n -m: month \n -d: day \n -h: hours \n -t: minutes \n -s: seconds \n");
}

#endif /* SETTINGS_H_ */
