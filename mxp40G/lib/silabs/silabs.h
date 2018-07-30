#ifndef __SILABS_H__
#define __SILABS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../gpio/gpio.h"
#include "../../lib/i2c/i2crw.h"
#include "../../lib/clk/clk.h"
#include "../../lib/util/util.h"

#define	SILABS_TOTAL	2
#define	SILABS1			0x68
#define	SILABS2			0x69

int silabs_config(int silabs_number, char *file_name);
int silabs_reset(unsigned int silabs_number);

#endif /* __SILABS_H__ */
