#include "gpio.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../util/util.h"
#include <string.h>
#include <errno.h>
#include <sys/mman.h>

int fd_address[GPIO_ADDRESS];
int fd_output_data[GPIO_OUT_DATA];
int fd_input_data[GPIO_INPUT_DATA];
int fd_status[GPIO_STATUS];
int fd_read_write;
int fd_nios_start;

#ifdef MMAP_GPIO
	//BIT_GPIO_BASE
	#define AVALON_GPIO_OC_BASE 0x19000000
	struct pio_parameters pio_mmap;
#endif

void open_gpio_files(void)
{
	int port;

	for(port = O_IE_NIOS_ADDR_0; port <= O_IE_NIOS_ADDR_16; port++)
	{
		char path[255];

		sprintf(path, "/sys/class/gpio/gpio%d/value", port);

		fd_address[port - O_IE_NIOS_ADDR_0] = open(path, O_RDWR);
	}

	for(port = O_IE_NIOS_DATA_0; port <= O_IE_NIOS_DATA_15; port++)
	{
		char path[255];

		sprintf(path, "/sys/class/gpio/gpio%d/value", port);

		fd_output_data[port - O_IE_NIOS_DATA_0] = open(path, O_RDWR);
	}

	for(port = I_IE_NIOS_DATA_0; port <= I_IE_NIOS_DATA_15; port++)
	{
		char path[255];

		sprintf(path, "/sys/class/gpio/gpio%d/value", port);

		fd_input_data[port - I_IE_NIOS_DATA_0] = open(path, O_RDWR);
	}

	for(port = I_IE_NIOS_STATUS_0; port <= I_IE_NIOS_STATUS_2; port++)
	{
		char path[255];

		sprintf(path, "/sys/class/gpio/gpio%d/value", port);

		fd_status[port - I_IE_NIOS_STATUS_0] = open(path, O_RDWR);
	}

	char path[255];

	sprintf(path, "/sys/class/gpio/gpio%d/value", O_IE_NIOS_READ_WRITE);

	fd_read_write = open(path, O_RDWR);

	char path1[255];

	sprintf(path1, "/sys/class/gpio/gpio%d/value", O_IE_NIOS_START);

	fd_nios_start = open(path1, O_RDWR);
}

void close_gpio_files(void)
{
	int i;

	for(i = 0; i < GPIO_ADDRESS; i++)
	{
		close(fd_address[i]);
	}

	for(i = 0; i < GPIO_OUT_DATA; i++)
	{
		close(fd_output_data[i]);
	}

	for(i = 0; i < GPIO_INPUT_DATA; i++)
	{
		close(fd_input_data[i]);
	}

	for(i = 0; i < GPIO_STATUS; i++)
	{
		close(fd_status[i]);
	}

	close(fd_read_write);
	close(fd_nios_start);
}

int get_file_descriptor(int port)
{
	int fd;
	char path[255];

	CHECK_PARAM(port < GPIO_BASE || port > GPIO_MAX,
		LOG_ERR, TAG_GPIO, "Error in gpio_write_bit(): port out of range", LOG_LOCAL0);

	if(port >= O_IE_NIOS_ADDR_0 & port <= O_IE_NIOS_ADDR_16)
	{
		fd = fd_address[port - O_IE_NIOS_ADDR_0];
	}
	else if(port >= O_IE_NIOS_DATA_0 & port <= O_IE_NIOS_DATA_15)
	{
		fd = fd_output_data[port - O_IE_NIOS_DATA_0];
	}
	else if(port >= I_IE_NIOS_DATA_0 & port <= I_IE_NIOS_DATA_15)
	{
		fd = fd_input_data[port - I_IE_NIOS_DATA_0];
	}
	else if(port >= I_IE_NIOS_STATUS_0 & port <= I_IE_NIOS_STATUS_2)
	{
		fd = fd_status[port - I_IE_NIOS_STATUS_0];
	}
	else if(port == O_IE_NIOS_READ_WRITE)
	{
		fd = fd_read_write;
	}
	else if(port == O_IE_NIOS_START)
	{
		fd = fd_nios_start;
	}
	else
	{
		sprintf(path, "/sys/class/gpio/gpio%d/value", port);
		fd = open(path, O_RDWR);
	}

	return fd;
}

int close_file_descriptor(int port, int fd)
{
	CHECK_PARAM(port < GPIO_BASE || port > GPIO_MAX, LOG_ERR, TAG_GPIO, "Error in gpio_write_bit(): port out of range", LOG_LOCAL0);

	if(port >= O_IE_NIOS_ADDR_0 & port <= O_IE_NIOS_ADDR_16)
	{
		// no debe hacer nada
	}
	else if(port >= O_IE_NIOS_DATA_0 & port <= O_IE_NIOS_DATA_15)
	{
		// no debe hacer nada
	}
	else if(port >= I_IE_NIOS_DATA_0 & port <= I_IE_NIOS_DATA_15)
	{
		// no debe hacer nada
	}
	else if(port >= I_IE_NIOS_STATUS_0 & port <= I_IE_NIOS_STATUS_2)
	{
		// no debe hacer nada
	}
	else if(port == O_IE_NIOS_READ_WRITE)
	{
		// no debe hacer nada
	}
	else if(port == O_IE_NIOS_START)
	{
		// no debe hacer nada
	}
	else
	{
		close(fd);
	}

	return 0;
}

int gpio_write_bit(int port, unsigned int value)
{
	int fd;

	#ifdef MMAP_GPIO
		unsigned int				ret;

		pio_write(&pio_mmap,port,value);

		return 0;
	#else

		fd = get_file_descriptor(port);

		CHECK_PARAM(fd < 0, LOG_ERR, TAG_GPIO,
			"Error in gpio_write_bit(): in open operation");

		if (value == 1)
		{
		   CHECK_PARAM( write(fd, "1", 1)<0, LOG_ERR, TAG_GPIO,
			"Error in gpio_write_bit(): in write operation");
		}
		else
		{
		   CHECK_PARAM( write(fd, "0", 1)<0, LOG_ERR, TAG_GPIO,
			"Error in gpio_write_bit(): in write operation");
		}

		close_file_descriptor(port, fd);
	#endif


    return 0;
}

int gpio_read_bit(unsigned int port, unsigned int *value)
{
    char valor;
    int fd;

#ifdef MMAP_GPIO
	unsigned int				ret;

	int fd_lock;
	fd_lock = filelock_open("gpio_lock");
	filelock_lock(fd_lock);

	pio_read(&pio_mmap,port,value);

	filelock_close(fd_lock);

	return 0;

#else

	fd = get_file_descriptor(port);

    CHECK_PARAM(fd < 0, LOG_ERR, TAG_GPIO, "Error in gpio_read_bit(): in open operation");
    
    CHECK_PARAM(read(fd, &valor, 1)<0, LOG_ERR, TAG_GPIO, "Error in gpio_read_bit(): in read operation");

    if (valor == '0') 
    {    
        *value = 0;
    }
    else 
    {
        *value = 1;
    }

    lseek(fd, 0, SEEK_SET);

    close_file_descriptor(port, fd);


    return 0;

#endif
}

int gpio_init_ports(unsigned int low_limit, unsigned int high_limit, const char* direction) 
{
    int fd;
    unsigned int port;
    char buf[255];     

    CHECK_PARAM(low_limit < GPIO_BASE, LOG_ERR, TAG_GPIO, 
        "Error in gpio_init_ports(): low_limit out of range", LOG_LOCAL0);

    CHECK_PARAM(high_limit > GPIO_LIMIT, LOG_ERR, TAG_GPIO, 
        "Error in gpio_init_ports(): high_limit out of range", LOG_LOCAL0);

    for (port = low_limit; port <= high_limit; port++) 
    {        
        fd = open("/sys/class/gpio/export", O_WRONLY);

        CHECK_PARAM(fd < 0, LOG_ERR, TAG_GPIO, 
            "Error in gpio_init_ports(): in open operation", LOG_LOCAL0);

        sprintf(buf, "%d", port); 
        
        write(fd, buf, strlen(buf));    // port number

        CHECK_PARAM(close(fd) < 0, LOG_ERR, TAG_GPIO, 
            "Error in gpio_init_ports(): in close operation", LOG_LOCAL0);
        
        sprintf(buf, "/sys/class/gpio/gpio%d/direction", port);
        
        fd = open(buf, O_WRONLY);

        CHECK_PARAM(fd < 0, LOG_ERR, TAG_GPIO, 
            "Error in gpio_init_ports(): in open operation", LOG_LOCAL0);
        
        write(fd, direction, strlen(direction)); // in, out
        
        CHECK_PARAM(close(fd) < 0, LOG_ERR, TAG_GPIO, 
            "Error in gpio_init_ports(): in close operation", LOG_LOCAL0);
    }

    return 0;
}

int gpio_write_bus(unsigned int base, unsigned int limit, unsigned long long value) 
{
    CHECK_PARAM(base < GPIO_BASE || limit > GPIO_LIMIT, LOG_ERR, TAG_GPIO, 
        "Error in gpio_write_bus(): base or limit out of range", LOG_LOCAL0);
    
    CHECK_PARAM(value > 0xFFFFFFFF, LOG_ERR, TAG_GPIO, 
        "Error in gpio_write_bus(): value out of range", LOG_LOCAL0);

    unsigned int i, desp;
    int mask = 0x0001;
    desp = 0;

    for (i = base; i <= limit; i++)
    {
        CHECK_PARAM(gpio_write_bit(i, (value & mask) >> desp) < 0, LOG_ERR, TAG_GPIO, 
            "Error in gpio_write_bus(): gpio_write_bit()", LOG_LOCAL0);

        mask <<= 1;
        desp++;
    }
    return 0;
}

int gpio_read_bus(unsigned int base, unsigned int limit, unsigned long long *value) 
{    
    CHECK_PARAM(base < GPIO_BASE || limit > GPIO_LIMIT, LOG_ERR, TAG_GPIO, 
        "Error in gpio_read_bus(): base or limit out of range", LOG_LOCAL0);

    unsigned int i, desp;
    unsigned int lectura;
    desp = 0;
    *value = 0;
    
    for(i = base; i <= limit; i++)
    {    
        CHECK_PARAM(gpio_read_bit(i, &lectura) < 0, LOG_ERR, TAG_GPIO, 
            "Error in gpio_read_bus(): gpio_read_bit()", LOG_LOCAL0);

        *value |= lectura << desp; 
        desp++;
    }
    
    return 0;
}

void open_upie(void)
{
	fd_upie = open("/dev/up_interface_0", O_RDWR);
}

void close_upie()
{
	close(fd_upie);
}

unsigned long write_count = 0;

int parallel_write(unsigned long int address, unsigned long int data)
{
	char buffer[32] = "";

	int status = 0;
	unsigned int timeout = IE_T41_TIME_OUT;
	unsigned long int read_data;

//	_______________________
//	|     NIOS_STATUS     |
//	| Value | Condition   |
//	|   0   | In progress |
//	|   1   | ACK OK      |
//	|   2   | ACK FAIL    |
//	|   3   | FAIL BUSERRN|
//	|   4   | END TRANSAC.|
//	|_______|_____________|

	sprintf(buffer, "1-%lu-%lu", address, data);

//	printf("Write: buffer= %s\n", buffer);

	 int fd_lock;
	 fd_lock = filelock_open("upie_lock");
	 filelock_lock(fd_lock);

	write(fd_upie, buffer, strlen(buffer));

	// write (wr_rd, start)
	// wr_rd=1, start toggles from 0 to 1 and 0 again
	write(fd_upie, "2", 1);

	/*Expect an ack or error.*/
	do{
		read(fd_upie, &read_data, 4);
		status = (read_data & 0x70000)>>16;
//		printf("Write: read_data= %#08x, status= %#04x\n", read_data, status);
		timeout--;
	} while (status == 0 && timeout != 0);

	if(status != 1)
	{
//		printf("Error: conc_write. Address: %#04x. ", address);
		print_status_error(status);
	}
	else
	{
//		write_count++;
		//printf("WR: %#04x = %#04x\n", address, data);
	}
    filelock_close(fd_lock);

	return status;
}

unsigned long read_count = 0;

/*
 * safe function, use filelock
 */
unsigned long int parallel_read(unsigned long int address)
{
	unsigned int status = 0;
	unsigned long int value;
	char buffer[32] = "";
	unsigned long int read_data;
	unsigned long int data;
	unsigned int timeout = IE_T41_TIME_OUT;

	/*Send the address.*/
	sprintf(buffer, "0-%lu", address);

//	printf("Read: buffer= %s\n", buffer);

	 int fd_lock;
	 fd_lock = filelock_open("upie_lock");
	 filelock_lock(fd_lock);

	write(fd_upie, buffer, strlen(buffer));

	// write (wr_rd, start)
	// wr_rd=1, start toggles from 0 to 1 and 0 again
	write(fd_upie, "3", 1);

	/*Expect an ack or error.*/
	do{
		read(fd_upie, &read_data, 4);
		status = ((read_data & 0x70000)>>16);
//		printf("Read: read_data= %#08x, status= %#04x\n", read_data, status);
		timeout--;
	} while (status == 0 && timeout != 0);

	/*Read the data.*/
	if(status!=1)
	{
//		printf("Error: register_read. Address: %#04x. ", address);
		print_status_error(status);
	} else {
		value = (read_data & 0xffff);
		data = value;
//		read_count++;
//		printf("Read: data= %#08x\n", *data);
	}

	filelock_close(fd_lock);

	return data;
}

void number_of_transactions()
{
	printf("Read Transactions = %d\n", read_count);
	printf("Write Transactions = %d\n", write_count);
}


int register_write(unsigned int address, unsigned short data)
{
	unsigned int iterations = 10;
	unsigned int status = 0;
	
	do
	{
		status = gpio_t41_parallel_write(address, data);
		--iterations;
	}
	while(iterations != 0 && status != 1);
	
	if(status != 1)
	{
		printf("Error: register_write. Address: %#04x. ", address);
		print_status_error(status);
		return -1;
	}
	else
	{
		//printf("WR: %#04x = %#04x\n", address, data);
	}
	
	return 0;
}


int gpio_t41_parallel_write(unsigned int address, unsigned short data)
{
	unsigned int status = 0;
//	_______________________
//	|     NIOS_STATUS     |
//	| Value | Condition   |
//	|   0   | In progress |
//	|   1   | ACK OK      |
//	|   2   | ACK FAIL    |
//	|   3   | FAIL BUSERRN|
//	|   4   | END TRANSAC.|
//	|_______|_____________|

	/*Send the address.*/
	//Send the 16 bit of address.
	gpio_write_bit(O_IE_NIOS_ADDR_16,(address >> 16) & 0x0001);
	//Send the 0-15 bits of address.
	gpio_write_bus(O_IE_NIOS_ADDR_0, O_IE_NIOS_ADDR_15, address);

	/*Send the data.*/
	gpio_write_bus(O_IE_NIOS_DATA_0,O_IE_NIOS_DATA_15, data);
//	_______________________
//	|     READ / WRITE    |
//	| Value | Condition   |
//	|   0   | Read        |
//	|   1   | Write       |
//	|_______|_____________|

	/*Send the write signal.*/
	gpio_write_bit(O_IE_NIOS_READ_WRITE,1);

	/* Send the start signal.*/
	start_transaction();
//	_______________________
//	_______________________
//	|     NIOS_STATUS     |
//	| Value | Condition   |
//	|   0   | In progress |
//	|   1   | ACK OK      |
//	|   2   | ACK FAIL    |
//	|   3   | FAIL BUSERRN|
//	|_______|_____________|
    
	/*Expect an ack or error.*/
	status = wait_for_ack();	

	return status;
}

unsigned short register_read(unsigned int address)
{
	unsigned short data = 0;
	unsigned int iterations = 1;
	unsigned int status = 0;
	
	do
	{
		status = gpio_t41_parallel_read(address, &data);
		--iterations;
	}
	while(iterations != 0 && status != 1);
	
	if(status != 1)
	{
		printf("Error: register_read. Address: %#04x. ", address);
		print_status_error(status);
		
	}
	else
	{
		//printf("RD: %#04x = %#04x\n", address, data);
	}

	return data;
}

unsigned short gpio_t41_parallel_read(unsigned int address, unsigned short *data)
{
	unsigned int status = 0;
	unsigned long long value;

	/*Send the address.*/
	//Send the 16 bit of address.
	gpio_write_bit(O_IE_NIOS_ADDR_16, (address >> 16) & 0x0001);
	//Send the 0-15 bits of address.
	gpio_write_bus(O_IE_NIOS_ADDR_0, O_IE_NIOS_ADDR_15, address);
//	_______________________
//	|     READ / WRITE    |
//	| Value | Condition   |
//	|   0   | Read        |
//	|   1   | Write       |
//	|_______|_____________|

	/*Send the read signal.*/
	gpio_write_bit(O_IE_NIOS_READ_WRITE,0);

	/* Send the start signal.*/
	start_transaction();
	
	status = wait_for_ack();
	
	/*Read the data.*/
	if(status==1)
	{
		gpio_read_bus(I_IE_NIOS_DATA_0,I_IE_NIOS_DATA_15, &value);
		*data = value;
	}

	return status;
}

//	_______________________
//	_______________________
//	|     NIOS_STATUS     |
//	| Value | Condition   |
//	|   0   | In progress |
//	|   1   | ACK OK      |
//	|   2   | ACK FAIL    |
//	|   3   | FAIL BUSERRN|
//	|_______|_____________|

void start_transaction()
{
	gpio_write_bit(O_IE_NIOS_START,1);
	gpio_write_bit(O_IE_NIOS_START,0);
	gpio_write_bit(O_IE_NIOS_START,1);
}

unsigned int wait_for_ack(void)
{
	unsigned int status = 0;
	unsigned int status_0 = 0;
	unsigned int status_1 = 0;
	unsigned int status_2 = 0;
	unsigned int timeout = IE_T41_TIME_OUT;
	
	do 
	{
		gpio_read_bit(I_IE_NIOS_STATUS_2,&status_2);
		gpio_read_bit(I_IE_NIOS_STATUS_1,&status_1);
		gpio_read_bit(I_IE_NIOS_STATUS_0,&status_0);
		status_2 = status_2 << 2;
		status_1 = status_1 << 1;
		status = status_2 | status_1 | status_0;
		timeout = timeout - 1;
	} 
	while(status == 0 && timeout != 0);

	return status;
} 

void print_status_error(unsigned int status)
{
	switch(status)
	{
		case 0:
			printf("Status Error: In progress\n");
			break;
		case 1:
			printf("Status OK: Transaction done.\n");
			break;
		case 2:
			printf("Status Error: Ack fail\n");
			break;
		case 3:
			printf("Status Error: Bus error fail\n");
			break;
		default:
			printf("Status Error: ---\n");
			break;
	}
}

void reset()
{
	//Initialize with RSTN Low. After power is stable and the SYS_REFCLK_IN input pin is stable, 
	gpio_write_bit(47,0); 
			
	//continue to assert RSTN Low for an additional 1 ms minimum.
	usleep(1000);
			
	//Assert RSTN High
	gpio_write_bit(47,1); 
			
	// then wait 250 ms before general register access. 
	usleep(250000);
}

int pio_init(void){
	int ret;
	ret = pio_open(&pio_mmap,AVALON_GPIO_OC_BASE);
	return 0;
}

int pio_open(struct pio_parameters *pio_data,unsigned int avalon_address)
{
	unsigned int status = 0;
	void *map_base;

	char filename[]="/dev/mem";


	strcpy(pio_data->filename,filename);

	pio_data->avalon_address = avalon_address;

	if ((pio_data->file_descriptor = open(pio_data->filename, ( O_RDWR | O_SYNC ))) < 0)
	{
		printf("ERROR: could not open \"/dev/mem\": %s\n\r",strerror(errno));
		status = pio_data->error_code;
	}
	else
	{
		//printf("Page size %d\n\r",getpagesize());
		map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, pio_data->file_descriptor,  pio_data->avalon_address & ~MAP_MASK);
		if( map_base == MAP_FAILED )
		{
			close (pio_data->file_descriptor);
			printf("Memory mapping failed: %s\n\r",strerror(errno));
			status = pio_data->error_code;
		}
		else
		{
			//pio_data->address = map_base + ( ( unsigned long  )( pio_data->avalon_address ) & ( unsigned long)( MAP_MASK ) );
			pio_data->address = map_base + ( pio_data->avalon_address &  MAP_MASK );
		}
	}

	if (status != 0)
	{
		printf("Init mmap error: %d\r\n",status);
	}

	#ifdef MMAP_DEBUG
		printf("Memory mapped at address %p.\n", pio_data->address);
	#endif

	return status;
}

int pio_write(struct pio_parameters *pio_data, unsigned int pin, unsigned int value)
{
	unsigned int status = 0;
	unsigned int output;

	//	  7 6 5 4 3 2  1 0
	//	[|-|-|-|-|-|-|OE|D]
	//		OE: 	Output Enable
	//		D:	Data

		if (value == 0)
		{
			output = 2;
		}
		else
		{
			output = 3;
		}

		*((unsigned char *)(pio_data->address + pin)) = output;

	#ifdef MMAP_DEBUG
		//printf("Read value @ %p: %X\n\r",(pio_data->address + pin),read_result);
	#endif


	return status;
}

int pio_read(struct pio_parameters *pio_data, unsigned int pin, unsigned int *value)
{
	unsigned int status = 0;
	unsigned long read_result;

	//	  7 6 5 4 3 2 1 0
	//	[|-|-|-|-|-|-|-|D]
	//		D:	Data

	read_result = *((unsigned char *)(pio_data->address + pin));

#ifdef MMAP_DEBUG
	printf("Read value @ %p: %X\n\r",(pio_data->address + pin),read_result);
#endif

	*value = read_result & 0x1;

	return status;
}

int pio_close(struct pio_parameters *pio_data){
	unsigned int status = 0;

	if(munmap(pio_data->address, MAP_SIZE) == -1) FATAL;
    close(pio_data->filename);

	return status;
}
