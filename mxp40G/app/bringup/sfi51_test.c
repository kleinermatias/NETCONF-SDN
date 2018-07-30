/*
 * sfi51_test.c
 *
 *  Created on: 31/03/2015
 *      Author: Giraudo Nicolás
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sfi51_test.h"
#include "../../lib/txp/txp.h"
#include "../../lib/cs6041/cs6041.h"

int main (int argc, char **argv)
{
	int status_read_1 = -1;
	int status_read_2 = -1;
	int status_write_1 = -1;
	rx_commandregister data;

	/*
	 * We get the RX command register.
	 */

	status_read_1 = oclaro_read_rx_cmd_reg(&data);
	printf("\n status read default values: %d\n", status_read_1);

	oclaro_print_struct_rx_cmd_t(&data);

	/*
	 * We change one value.
	 */

	data.rxdloopenb = 0;
	status_write_1 = oclaro_set_rx_cmd_reg(data);
	printf("\n status write change: %d\n", status_write_1);

	/*
	 * We get the new RX command register.
	 */

	status_read_2 = oclaro_read_rx_cmd_reg(&data);
	printf("\n status read new values: %d\n", status_read_2);

	oclaro_print_struct_rx_cmd_t(&data);

	return 0;
}
