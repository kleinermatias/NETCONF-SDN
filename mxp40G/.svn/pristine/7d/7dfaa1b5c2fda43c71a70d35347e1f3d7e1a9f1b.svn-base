/*
 * testoclaro.c
 *
 *  Created on: 19/03/2015
 *      Author: Giraudo Nicolás
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "testoclaro.h"
#include "../../txp/txp.h"

int main (int argc, char **argv)
{
	unsigned char part_number [16];
	int status = 0;
	int i=0;

	status = oclaro_read_unit_part_number(&part_number[0]);

	printf("\n Unit Part Number: ");

	for(i=0;i<16;i++)
	{
		printf("%c", part_number[i]);
	}

	printf("\n\n");

	return 0;
}
