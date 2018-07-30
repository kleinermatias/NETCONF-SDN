#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "test_rw.h"

int main(int argc, char **argv)
{
	time_t start, end;
	struct tm *ts_start;
	char buffer_start[80];
	struct tm *ts_end;
	char buffer_end[80];

	unsigned int i;

	char buffer_write_address[15] = "";
	char buffer_write_data[15] = "";
	char buffer[32] = "";

	unsigned long int address = 0x00000;
	unsigned long int data_w = 0xBBBB;

/*inicio test para escribir*/
/*
	int fd_write_address = open("/dev/up_interface_0", O_WRONLY);

	//sprintf(buffer, "1-%lu-%lu", address, data_w);

	start = time(0);

	for(i = 0; i < 40000; i++)
	{
		write(fd_write_address, buffer, strlen(buffer));
	}

	end = time(0);

	close(fd_write_address);

	ts_start = localtime(&start);
	strftime(buffer_start, sizeof(buffer_start), "\n start 1 address writes:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_start);
	printf("%s\n", buffer_start);

	ts_end = localtime(&end);
	strftime(buffer_end, sizeof(buffer_end), " end 1 address writes:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_end);
	printf("%s\n", buffer_end);
*/
/*fin test para escribir*/

/*inicio test para leer*/


	int fd_read_data = open("/dev/up_interface_0", O_RDWR);

	unsigned long int read_data;



	start = time(0);

//	for(i = 0; i < 40000; i++)
	{
		sprintf(buffer, "0-%lu", address);

		address++;

//		write(fd_read_data, buffer, strlen(buffer));

		read(fd_read_data, &read_data, 4);
	}

	end = time(0);

	ts_start = localtime(&start);
	strftime(buffer_start, sizeof(buffer_start), "\n start 1 data reads:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_start);
	printf("%s\n", buffer_start);

	ts_end = localtime(&end);
	strftime(buffer_end, sizeof(buffer_end), " end 1 data reads:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_end);
	printf("%s\n", buffer_end);

	printf("read_data: %#08x\n", read_data);

	printf("data: %#08x\n", read_data & 0xffff);

	printf("status: %#08x\n", (read_data & 0x70000)>>16);

	close(fd_read_data);

/*fin test para leer*/

	return 0;

}
