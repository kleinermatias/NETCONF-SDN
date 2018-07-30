#include "edfa.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <errno.h>
#include "../gpio/gpio.h"
#include "../ltc/ltc.h"
#include "../utils/filelock.h"

#include "../../lib/util/util.h"

int edfa_set_blocking (int fd)
{
	struct termios tty;

	CHECK_PARAM(fd < 0, LOG_ERR, TAG_EDFA,"Error in edfa_set_blocking: fd out of range", LOG_LOCAL0);

	memset (&tty, 0, sizeof tty);

#ifndef TESTING
	CHECK_PARAM(tcgetattr (fd, &tty) != 0, LOG_ERR, TAG_EDFA,"Error in edfa_set_blocking: tcgetattr()",LOG_LOCAL0);
#endif

	tty.c_cc[VMIN]  =  0;
	tty.c_cc[VTIME] = (unsigned char)256;

#ifndef TESTING
	CHECK_PARAM(tcsetattr (fd, TCSANOW, &tty) != 0, LOG_ERR, TAG_EDFA,"Error in edfa_set_blocking: tcsetattr()",LOG_LOCAL0);
#endif

	return 0;
}

int edfa_set_interface_attribs (int fd, int speed, int parity)
{
	struct termios tty;
	memset (&tty, 0, sizeof tty);

	CHECK_PARAM(fd < 0, LOG_ERR, TAG_EDFA,"Error in edfa_set_interface_attribs: fd out of range", LOG_LOCAL0);

	CHECK_PARAM((speed != B9600), LOG_ERR, TAG_EDFA,"Error in edfa_set_interface_attribs: speed out of range", LOG_LOCAL0);

	CHECK_PARAM((parity != 1 && parity!=0), LOG_ERR, TAG_EDFA,"Error in edfa_set_interface_attribs: parity out of range", LOG_LOCAL0);

	CHECK_PARAM(tcgetattr (fd, &tty) != 0, LOG_ERR, TAG_EDFA,"Error in edfa_set_interface_attribs: tcgetattr()", LOG_LOCAL0);
	cfsetospeed (&tty, speed);
	cfsetispeed (&tty, speed);


	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
	// disable IGNBRK for mismatched speed tests; otherwise receive break
	// as \000 chars
	tty.c_iflag &= ~IGNBRK;                         // disable break processing
	tty.c_lflag = 0;                                // no signaling chars, no echo,
	// no canonical processing
	tty.c_oflag = 0;                                // no remapping, no delays
	tty.c_cc[VMIN]  = 1;                            // read doesn't block
	tty.c_cc[VTIME] = 5;                            // 0.5 seconds read timeout

	tty.c_iflag &= ~(IXON | IXOFF | IXANY);         // shut off xon/xoff ctrl

	tty.c_cflag |= (CLOCAL | CREAD);                // ignore modem controls,
	// enable reading
	tty.c_cflag &= ~(PARENB | PARODD);              // shut off parity
	tty.c_cflag |= parity;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~020000000000;

	CHECK_PARAM(tcsetattr (fd, TCSAFLUSH, &tty) != 0, LOG_ERR, TAG_EDFA,"Error in set_interface_attribs: tcsetattr()", LOG_LOCAL0);

	return 0;
}

int edfa_set_term(int fd)
{
	struct termios tio;

	memset(&tio,0,sizeof(tio));
	tio.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR | PARMRK | INPCK | ISTRIP | IXON);
	tio.c_oflag=0;
	tio.c_cflag=CS8|CREAD|CLOCAL;           // 8n1, see termios.h for more information
	tio.c_lflag=0;
	tio.c_cc[VMIN]=1;
	tio.c_cc[VTIME]=10;

	cfsetospeed(&tio,B9600);            // 9600 baud
	cfsetispeed(&tio,B9600);            // 9600 baud

	tcsetattr(fd, TCSANOW, &tio);

	fcntl(fd, F_SETFL, FNDELAY);       // make the reads non-blocking

	return 0;
}

int edfa_set_term_test1(int fd)
{
	struct termios options;
	tcgetattr( fd, &options );

	/* SEt Baud Rate */

	cfsetispeed( &options, B9600 );
	cfsetospeed( &options, B9600 );

	//I don't know what this is exactly

	options.c_cflag |= ( CLOCAL | CREAD );

	// Set the Charactor size

	options.c_cflag &= ~CSIZE; /* Mask the character size bits */
	options.c_cflag |= CS8;    /* Select 8 data bits */

	// Set parity - No Parity (8N1)

	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSTOPB;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;

	// Disable Hardware flowcontrol

	//  options.c_cflag &= ~CNEW_RTSCTS;  -- not supported

	// Enable Raw Input

	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

	// Disable Software Flow control

	options.c_iflag &= ~(IXON | IXOFF | IXANY);

	// Chose raw (not processed) output

	options.c_oflag &= ~OPOST;

	if ( tcsetattr( fd, TCSANOW, &options ) == -1 )
		printf ("Error with tcsetattr = %s\n", strerror ( errno ) );
	else
		printf ( "%s\n", "tcsetattr succeed" );

	fcntl(fd, F_SETFL, FNDELAY);

	return 0;
}

int edfa_set_terminal(int fd)
{
	int fd_lock;
	fd_lock = filelock_open("edfa_lock");
	filelock_lock(fd_lock);

	struct termios tio;

	memset(&tio,0,sizeof(tio));
	tio.c_iflag=IGNPAR;
	tio.c_oflag=0;
	tio.c_cflag=CS8|CREAD|CLOCAL;           // 8n1, see termios.h for more information
	tio.c_lflag=0;
	tio.c_cc[VMIN]=1;
	tio.c_cc[VTIME]=5;

	cfsetospeed(&tio,B9600);            // 9600 baud
	cfsetispeed(&tio,B9600);            // 9600 baud


	tcflush(fd, TCIFLUSH);
	tcsetattr(fd,TCSANOW,&tio);

	filelock_close(fd_lock);

	return 0;
}

/*
int edfa_set_terminal(int fd)
{
	//Configure terminal
	CHECK_PARAM( edfa_set_interface_attribs (fd, B9600, 0) < 0, LOG_ERR, TAG_EDFA,"Error in edfa_send_command: edfa_set_interface_attribs()");

	//Set Blocking
	CHECK_PARAM(edfa_set_blocking(fd) < 0, LOG_ERR, TAG_EDFA,"Error in edfa_send_command: edfa_set_blocking()");

	return 0;
}
 */

int edfa_clean_fifo (int fd)
{
	unsigned char c='D';
	int fd_lock;
	fd_lock = filelock_open("edfa_lock");

	filelock_lock(fd_lock);

	while(read(fd,&c,1)>0){
	}

	filelock_close(fd_lock);

	return 0;
}

int edfa_trx(int fd, char *data_to_be_sent, int size, char *data_to_be_received)
{
	//	sem_wait(&shm_semaphores->edfa.sem_id);
	//	printf("Take edfa_trx semaphore \n");
	int fd_lock;
	fd_lock = filelock_open("edfa_lock");

	filelock_lock(fd_lock);
	//	printf("edfa_trx, critical region\n");

	int i=0, j=0, status=1;
	unsigned char c='D';

	while(i<size)
	{
		c = data_to_be_sent[i];
		CHECK_PARAM(write(fd, &c, 1) < 0, LOG_ERR, TAG_EDFA,"Error in edfa_send_command: Write Failed", LOG_LOCAL0);
		i++;
	}

	usleep(160000);

	while(status>0)
	{
		status = read(fd, &c, 1);
		if(c!='\0')
		{
			data_to_be_received[j] = c;
			j++;
		}
	}

	//close() automatically releases the file lock.
	
	filelock_close(fd_lock);

	//	sem_post(&shm_semaphores->edfa.sem_id);
	//	printf("Release edfa_trx semaphore \n");
	
	return 0;
}

int edfa_trx_unsafe(int fd, char *data_to_be_sent, int size, char *data_to_be_received)
{
	//	sem_wait(&shm_semaphores->edfa.sem_id);
	//	printf("Take edfa_trx semaphore \n");
	//	printf("edfa_trx, critical region\n");
	//int fd_lock;
	//fd_lock = filelock_open("edfa_lock");
	//if(filelock_lock_timeout(fd_lock, 0) != -1){
	if(1){
		int i=0, j=0, status=1;
		unsigned char c='D';	

		while(i<size)
		{
			c = data_to_be_sent[i];
			CHECK_PARAM(write(fd, &c, 1) < 0, LOG_ERR, TAG_EDFA,"Error in edfa_send_command: Write Failed", LOG_LOCAL0);
			i++;
		}	

		usleep(160000);	

		while(status>0)
		{
			status = read(fd, &c, 1);
			if(c!='\0')
			{
				data_to_be_received[j] = c;
				j++;
			}
		//close() automatically releases the file lock.
		//	sem_post(&shm_semaphores->edfa.sem_id);
		//	printf("Release edfa_trx semaphore \n");
		}
	}

	//filelock_close(fd_lock);
	
	return 0;
}

int edfa_send_command(int fd, char *data_to_be_sent, int size, char *data_to_be_received)
{
	int SIZE = 512;
	int status;
	char tty[]="/dev/ttyAL2";
	char *bufptr;
	int nbytes; // Number of bytes read

	//	sem_wait(&shm_semaphores->edfa.sem_id);
	//	printf("Take edfa_trx semaphore \n");
	int fd_lock;
	fd_lock = filelock_open("edfa_lock");

	filelock_lock(fd_lock);
	//	printf("edfa_send_command, critical region\n");



	CHECK_PARAM(size < 0, LOG_ERR, TAG_EDFA,"Error in edfa_send_command: size less than zero", LOG_LOCAL0);

	//	fflush(fd);

#ifndef TESTING
	//Open File Descriptor
	//		CHECK_PARAM((fd = open(tty, O_RDWR | O_NDELAY | O_NONBLOCK)) < 0, LOG_ERR, TAG_EDFA,"Error in edfa_send_command: Open Failed");

	//Configure terminal
	//		CHECK_PARAM( edfa_set_interface_attribs (fd, B9600, 0) < 0, LOG_ERR, TAG_EDFA,"Error in edfa_send_command: edfa_set_interface_attribs()");

	//Set Blocking
	//		CHECK_PARAM(edfa_set_blocking(fd) < 0, LOG_ERR, TAG_EDFA,"Error in edfa_send_command: edfa_set_blocking()");

	//Send Data
	CHECK_PARAM(write(fd, data_to_be_sent, size) < 0, LOG_ERR, TAG_EDFA,"Error in edfa_send_command: Write Failed", LOG_LOCAL0);

	//		fflush(fd);

	//		usleep(500000);

	usleep(2000*1000);

	/*
		bufptr = data_to_be_received;
		while((nbytes = read(fd, bufptr, data_to_be_received + sizeof(data_to_be_received)-1)) > 0)
		{
			bufptr += nbytes;
			if (bufptr[-1] == '\n' || bufptr[-1] == '\r')
				break;
		}
	 */
	//Read Data
	status = read(fd, data_to_be_received, SIZE);

	usleep(2000*1000);

	//		usleep(500000);

	CHECK_PARAM(status < 0, LOG_ERR, TAG_EDFA, "Error in edfa_send_command: Read Failed", LOG_LOCAL0);

	CHECK_PARAM(status == 0, LOG_ERR, TAG_EDFA, "Error in edfa_send_command: Read timeout", LOG_LOCAL0);

	//		fflush(fd);


	//		printf("edfa_send_command: read buffer= %s\n",data_to_be_received);

	//data_to_be_received = buffer;

	//Close File
	//		CHECK_PARAM(close(fd)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_send_command: Close Failed");
#endif

	//		sem_post(&shm_semaphores->edfa.sem_id);
	//		printf("Release edfa_trx semaphore \n");

	//close() automatically releases the file lock.
	filelock_close(fd_lock);

	return 0;
}

int edfa_get_information(int fd, char *data_to_be_received)
{
	char cmd[5]= "ver\n";

#ifdef TESTING

	if(edfa_send_command_mock(cmd,sizeof(cmd)) < 0)
		return -1;

#else

	//		CHECK_PARAM(edfa_send_command(fd,cmd,sizeof(cmd), data_to_be_received) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_information: edfa_send_command()");
	CHECK_PARAM(edfa_trx(fd,cmd,sizeof(cmd), data_to_be_received) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_information: edfa_send_command()", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_get_echo(int fd, char *data_to_be_received)
{
	char cmd[7]= "echo\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd,sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_echo: edfa_send_command()");

#else

	//		printf("Entro al else de get_echo\n");

	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_echo: edfa_send_command()", LOG_LOCAL0);
#endif

	return 0;
}


int edfa_set_echo(int fd, int echo, char *data_to_be_received)
{
	//	char data_to_be_received;

	CHECK_PARAM(((echo != EDFA_ECHO_ON) && (echo != EDFA_ECHO_OFF)), LOG_ERR, TAG_EDFA, "Error in edfa_set_echo: echo out of range", LOG_LOCAL0);

#ifdef TESTING
	if(echo==1)
	{
		if(edfa_send_command_mock(EDFA_COMMAND_ECHO_ON,9) < 0)
			return -1;
	}

	else
	{

		if(edfa_send_command_mock(EDFA_COMMAND_ECHO_OFF,10) < 0)
			return -1;
	}

#else
	if(echo==1)
	{
		char cmd [9] = "echo on\n";

		CHECK_PARAM(edfa_send_command(fd,cmd,sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_echo: edfa_send_command(): echo on", LOG_LOCAL0);
	}

	else
	{
		char cmd [] = "echo off\n";

		CHECK_PARAM(edfa_send_command(fd, cmd,sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_echo: edfa_send_command(): echo off", LOG_LOCAL0);
	}
#endif

	return 0;
}


int edfa_set_baud_rate(int fd, int baud, char *data_to_be_received)
{
	char cmd[13];
	int i;

	for (i = 0; i < 13; ++i)
		cmd[i] = '\0';

	CHECK_PARAM(((baud != EDFA_BAUD_9600) && (baud != EDFA_BAUD_19200) && (baud != EDFA_BAUD_38400) && (baud != EDFA_BAUD_57600) &&
			(baud != EDFA_BAUD_115200)), LOG_ERR, TAG_EDFA, "Error in edfa_set_baud_rate: Baud Rate out of range", LOG_LOCAL0);

	sprintf(cmd, "baud %d\n", baud);

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_baud_rate: edfa_send_command(fd, )");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_baud_rate: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_get_baud_rate(int fd, char *data_to_be_received)
{
	char cmd[6]= "baud\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_baud_rate: edfa_send_command_mock()");

#else
	//		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_baud_rate: edfa_send_command(fd, )");
	CHECK_PARAM(edfa_trx(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_baud_rate: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_set_mode_and_val(int fd, int mode, float val, char *data_to_be_received)
{
	char cmd[32];
	int i;

	for (i = 0; i < 32; ++i)
		cmd[i] = '\0';

	switch(mode)
	{
	case EDFA_MODE_G:

		CHECK_PARAM(((val<EDFA_RANGE_GAIN_MIN)||(val>EDFA_RANGE_GAIN_MAX)), LOG_ERR, TAG_EDFA, "Error in edfa_set_mode_and_gain: Gain out of range", LOG_LOCAL0);

		sprintf(cmd, "mode g  %f\n", val);

#ifdef TESTING
		CHECK_PARAM(edfa_send_command_mock(cmd, strlen(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_mode_and_gain: edfa_send_command_mock()");

#else
		CHECK_PARAM(edfa_trx(fd,cmd,sizeof(cmd), data_to_be_received) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_information: edfa_send_command()", LOG_LOCAL0);
		//				CHECK_PARAM(edfa_send_command(fd, cmd, strlen(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_mode_and_gain: edfa_send_command(fd, )");

#endif
		break;

	case EDFA_MODE_P:
		CHECK_PARAM(((val<EDFA_RANGE_POUT_MIN)||(val>EDFA_RANGE_POUT_MAX)), LOG_ERR, TAG_EDFA, "Error in edfa_set_mode_and_gain: Power Output out of range", LOG_LOCAL0);

		sprintf(cmd, "mode p  %f\n", val);

#ifdef TESTING
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_mode_and_gain: edfa_send_command_mock()");
#else
		CHECK_PARAM(edfa_trx(fd,cmd,sizeof(cmd), data_to_be_received) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_information: edfa_send_command()", LOG_LOCAL0);
		//        		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_mode_and_gain: edfa_send_command(fd, )");
#endif
		break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_set_mode_and_gain: mode out of range", LOG_LOCAL0);
		return -1;
		break;
	}

	return 0;
}


int edfa_set_mode(int fd, int mode, char *data_to_be_received)
{
	switch(mode)
	{
	case EDFA_MODE_M:
	{
		char cmd[8]= "mode m\n";

#ifdef TESTING
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd)) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_mode: edfa_send_command_mock()");

#else
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_mode: edfa_send_command(fd, )", LOG_LOCAL0);

#endif
	}
	break;

	case EDFA_MODE_D:
	{
		char cmd[8]= "mode d\n";

#ifdef TESTING
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_mode: edfa_send_command_mock()");

#else
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_mode: edfa_send_command(fd, )", LOG_LOCAL0);

#endif
	}
	break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_set_mode: mode out of range", LOG_LOCAL0);
		return -1;
		break;
	}

	return 0;
}

int edfa_get_mode(int fd, char *data_to_be_received)
{
	char cmd[6]= "mode\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_mode : edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_trx(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_baud_rate: edfa_send_command(fd, )", LOG_LOCAL0);
	//		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_mode : edfa_send_command(fd, )");
#endif

	return 0;
}

int edfa_set_splim(int fd, int stage, float value, char *data_to_be_received)
{
	char cmd[13];

	int i;
	for (i = 0; i < 13; ++i)
		cmd[i] = '\0';

	CHECK_PARAM(stage < 1, LOG_ERR, TAG_EDFA, "Error in edfa_set_splim: Stage out of range", LOG_LOCAL0);

	CHECK_PARAM(((value<EDFA_RANGE_POUT_MIN)||(value>EDFA_RANGE_POUT_MAX)), LOG_ERR, TAG_EDFA, "Error in edfa_set_splim: Value out of range", LOG_LOCAL0); //ver valores posible de value

	sprintf(cmd, "splim %d %f\n", stage, value);

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_splim: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_splim: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_get_splim(int fd, int stage, char *data_to_be_received)
{
	int i;
	char cmd[13];

	for (i = 0; i < 13; ++i)
		cmd[i] = '\0';

	CHECK_PARAM(stage < 1, LOG_ERR, TAG_EDFA, "Error in edfa_get_splim: Stage out of range", LOG_LOCAL0);

	sprintf(cmd, "splim %d\n", stage);

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_splim: edfa_send_command_mock()");
#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_splim: edfa_send_command(fd, )", LOG_LOCAL0);
#endif

	return 0;
}

int edfa_set_sglim(int fd, int stage, float value, char *data_to_be_received)
{
	char cmd[13];
	int i;

	for (i = 0; i < 13; ++i)
		cmd[i] = '\0';

	CHECK_PARAM(stage < 1, LOG_ERR, TAG_EDFA, "Error in edfa_set_sglim: Stage out of range", LOG_LOCAL0);

	CHECK_PARAM(((value<EDFA_RANGE_GAIN_MIN)||(value>EDFA_RANGE_GAIN_MAX)), LOG_ERR, TAG_EDFA, "Error in edfa_set_sglim: Value out of range", LOG_LOCAL0);

	sprintf(cmd, "sglim %d %f\n", stage, value);

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_sglim: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_sglim: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_get_sglim(int fd, int stage, char *data_to_be_received)
{
	int i;
	char cmd[13];

	for (i = 0; i < 13; ++i)
		cmd[i] = '\0';

	CHECK_PARAM(stage < 1, LOG_ERR, TAG_EDFA, "Error in edfa_get_sglim: Stage out of range", LOG_LOCAL0);

	sprintf(cmd, "sglim %d\n", stage);

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_sglim: edfa_send_command(fd, )");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_sglim: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_get_input_power(int fd, char *data_to_be_received)
{
	char cmd[5]= "pin\n";

	CHECK_PARAM(edfa_trx_unsafe(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_input_power: edfa_trx()", LOG_LOCAL0);

	return 0;
}

int edfa_get_output_power(int fd, char *data_to_be_received)
{
	char cmd[6]= "pout\n";

	CHECK_PARAM(edfa_trx_unsafe(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_output_power: edfa_trx()", LOG_LOCAL0);

	return 0;
}

int edfa_get_signal_power(int fd, char *data_to_be_received)
{
	char cmd[6]= "psig\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_signal_power: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_signal_power: edfa_send_command(fd, )", LOG_LOCAL0);
#endif

	return 0;
}

int edfa_get_signal_gain(int fd, char *data_to_be_received)
{
	char cmd[6]= "gain\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_signal_gain: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_signal_gain: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_get_amplifier_status(int fd, char *data_to_be_received)
{
	char cmd[5]= "mst\n";

	CHECK_PARAM(edfa_trx_unsafe(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_amplifier_status: edfa_trx()", LOG_LOCAL0);

	return 0;
}

int edfa_set_los_mode(int fd, int mode, char *data_to_be_received)
{
#ifdef TESTING
	switch(mode)
	{
	case EDFA_LOS_MODE_A:
	{
		char cmd[7]= "los a\n";
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mode: edfa_send_command_mock()");
	}
	break;

	case EDFA_LOS_MODE_I:
	{
		char cmd[7]= "los i\n";
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mode: edfa_send_command_mock()");
	}
	break;

	case EDFA_LOS_MODE_P:
	{
		char cmd[7]= "los p\n";
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mode: edfa_send_command_mock()");
	}
	break;

	case EDFA_LOS_MODE_N:
	{
		char cmd[7]= "los n\n";
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mode: edfa_send_command_mock()");
	}
	break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_set_los_mode: mode out of range");
		return -1;
		break;
	}

#else
	switch(mode)
	{
	case EDFA_LOS_MODE_A:
	{
		char cmd[7]= "los a\n";
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mode: edfa_send_command(fd, )", LOG_LOCAL0);
	}
	break;

	case EDFA_LOS_MODE_I:
	{
		char cmd[7]= "los i\n";
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mode: edfa_send_command(fd, )", LOG_LOCAL0);
	}
	break;

	case EDFA_LOS_MODE_P:
	{
		char cmd[7]= "los p\n";
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mode: edfa_send_command(fd, )", LOG_LOCAL0);
	}
	break;

	case EDFA_LOS_MODE_N:
	{
		char cmd[7]= "los n\n";
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mode: edfa_send_command(fd, )", LOG_LOCAL0);
	}
	break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_set_los_mode: mode out of range", LOG_LOCAL0);
		return -1;
		break;
	}
#endif

	return 0;
}

int edfa_get_los_mode(int fd, char *data_to_be_received)
{
	char cmd[5]= "los\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_los_mode: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_los_mode: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_set_los_mA(int fd, int mA, char *data_to_be_received)
{
	char cmd[13];
	int i;

	for (i = 0; i < 13; ++i)
		cmd[i] = '\0';

	CHECK_PARAM(mA < 1, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mA: mA out of range", LOG_LOCAL0);

	sprintf(cmd, "los i %d\n", mA);

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mA: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_los_mA: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_reset_factory_default_values(int fd, char *data_to_be_received)
{
	char cmd[5]= "rst\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_factory_default_values: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_trx(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_factory_default_values: edfa_send_command()", LOG_LOCAL0);
	//		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), &data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_factory_default_values: edfa_send_command(fd, )");

#endif

	sleep(1);

	return 0;
}

int edfa_reset_firmware(int fd, char *data_to_be_received)
{
	char cmd[6]= "boot\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_firmware: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_trx(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_firmware: edfa_send_command()", LOG_LOCAL0);
	//		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_firmware: edfa_send_command()");

#endif

	sleep(1);

	return 0;
}

int edfa_get_case_temperature(int fd, char *data_to_be_received)
{
	char cmd[4]= "mt\n";

	CHECK_PARAM(edfa_trx_unsafe(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_case_temperature: edfa_trx()", LOG_LOCAL0);

	return 0;
}

int edfa_clean_data(char data[])
{
	int i = 0;
	int j = 0;
	char aux_data[100] = {0};

	while (data[i] != ':' && i<100)
	{
		i++;
	}
	i=i+2;
	while ((data[i] != '\r' && data[i] != ' ') && i<100)
	{
		aux_data[j] = data[i];
		j++;
		i++;
	}

	for(i=0; i<100; i++)
		data[i]='\0';

	for(i=0; i<100;i++)
	{
		data[i] = aux_data[i];
	}

	return 0;
}

int edfa_get_pump_status(int fd, int param, char *data_to_be_received)
{
#ifdef TESTING
	switch(param)
	{
	case EDFA_PUMP_ILD:
	{
		char cmd[10]= "pump ild\n";
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_pump_status: edfa_send_command_mock()");
	}
	break;

	case EDFA_PUMP_EOL:
	{
		char cmd[10]= "pump eol\n";
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA,	"Error in edfa_get_pump_status: edfa_send_command_mock()");
	}
	break;

	case EDFA_PUMP_TMP:
	{
		char cmd[10]= "pump tmp\n";
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_pump_status: edfa_send_command_mock()");
	}
	break;

	case EDFA_PUMP_ALL:
	{
		char cmd[6]= "pump\n";
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_pump_status: edfa_send_command_mock()");
	}
	break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_get_pump_status: edfa_send_command_mock()");
		return -1;
		break;
	}

#else
	switch(param)
	{
	case EDFA_PUMP_ILD:
	{
		char cmd[10]= "pump ild\n";
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_pump_status: edfa_send_command(fd, )", LOG_LOCAL0);
	}
	break;

	case EDFA_PUMP_EOL:
	{
		char cmd[10]= "pump eol\n";
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA,	"Error in edfa_get_pump_status: edfa_send_command(fd, )", LOG_LOCAL0);
	}
	break;

	case EDFA_PUMP_TMP:
	{
		char cmd[10]= "pump tmp\n";
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_pump_status: edfa_send_command(fd, )", LOG_LOCAL0);
	}
	break;

	case EDFA_PUMP_ALL:
	{
		char cmd[6]= "pump\n";
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_pump_status: edfa_send_command(fd, )", LOG_LOCAL0);
	}
	break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_get_pump_status: edfa_send_command(fd, )", LOG_LOCAL0);
		return -1;
		break;
	}
#endif

	return 0;
}

int edfa_set_pump_mA(int fd, float mA, char *data_to_be_received)
{
	char cmd[13];
	int i;

	for (i = 0; i < 13; ++i) cmd[i] = '\0';

	CHECK_PARAM(mA < 1, LOG_ERR, TAG_EDFA, "Error in edfa_set_pump_mA: mA out of range", LOG_LOCAL0);

	sprintf(cmd, "pump isp %f\n", mA);

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_pump_mA: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_pump_mA: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_get_pump_mA(int fd, char *data_to_be_received)
{
	char cmd[10]= "pump isp\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_pump_mA: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_pump_mA: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_set_alarm_mode(int fd, int mode, char *data_to_be_received)
{
#ifdef TESTING
	switch(mode)
	{
	case EDFA_ALARM_MODE_NORMAL:
	{
		char cmd[8]= "astm n\n";
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_alarm_mode: edfa_send_command_mock()");
	}
	break;

	case EDFA_ALARM_MODE_STICKY:
	{
		char cmd[8]= "astm s\n";
		CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_alarm_mode: edfa_send_command_mock()");
	}
	break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_set_alarm_mode: mode out of range");
		return -1;
		break;
	}


#else
	switch(mode)
	{
	case EDFA_ALARM_MODE_NORMAL:
	{
		char cmd[8]= "astm n\n";
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_alarm_mode: edfa_send_command(fd, )", LOG_LOCAL0);
	}
	break;

	case EDFA_ALARM_MODE_STICKY:
	{
		char cmd[8]= "astm s\n";
		CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_alarm_mode: edfa_send_command(fd, )", LOG_LOCAL0);
	}
	break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_set_alarm_mode: mode out of range", LOG_LOCAL0);
		return -1;
		break;
	}

#endif

	return 0;
}

int edfa_get_alarm_mode(int fd, char *data_to_be_received)
{
	char cmd[6]= "astm\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_alarm_mode: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_alarm_mode: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_list_all_alarm(int fd, char *data_to_be_received)
{
	char cmd[5]= "ast\n";

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_list_all_alarm: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_list_all_alarm: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_get_alarm_information(int fd, int alrm, int parameter, char *data_to_be_received)
{
	char cmd[13];
	int i;

	for (i = 0; i < 13; ++i)
		cmd[i] = '\0';

	switch(alrm)
	{
	case EDFA_ALARM_ILD:
		strcpy(cmd,"alrm ild ");
		break;

	case EDFA_ALARM_TMP:
		strcpy(cmd,"alrm tmp ");
		break;

	case EDFA_ALARM_MTH:
		strcpy(cmd,"alrm mth ");
		break;

	case EDFA_ALARM_MTL:
		strcpy(cmd,"alrm mtl ");
		break;

	case EDFA_ALARM_LOS:
		strcpy(cmd,"alrm los ");
		break;

	case EDFA_ALARM_LOP:
		strcpy(cmd,"alrm lop ");
		break;

	case EDFA_ALARM_ALL:
		strcpy(cmd,"alrm ");
		break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_get_alarm_information: alarm out of range", LOG_LOCAL0);
		return -1;
		break;
	}

	switch(parameter)
	{
	case EDFA_ALARM_PARAM_STA:
		strcat(cmd,"sta\n");
		break;

	case EDFA_ALARM_PARAM_SST:
		strcat(cmd,"sst\n");
		break;

	case EDFA_ALARM_PARAM_THR:
		strcat(cmd,"thr\n");
		break;

	case EDFA_ALARM_PARAM_HYS:
		strcat(cmd,"hys\n");
		break;

	case EDFA_ALARM_PARAM_ALL:
		strcat(cmd,"\n");
		break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_get_alarm_information: parameter out of range", LOG_LOCAL0);
		return -1;
		break;
	}

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_alarm_information: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_trx_unsafe(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_alarm_information: edfa_trx()", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_set_threshold_level(int fd, int alrm, float level, char *data_to_be_received)
{
	char cmd[20];
	int i;

	for (i = 0; i < 20; ++i)
		cmd[i] = '\0';

	switch(alrm)
	{
	case EDFA_ALARM_ILD:
		CHECK_PARAM((level<0)||(level>100), LOG_ERR, TAG_EDFA, "Error in edfa_set_threshold_level: Pump overcurrent  level out of range", LOG_LOCAL0);
		sprintf(cmd,"alrm ild thr %f\n",level);
		break;

	case EDFA_ALARM_TMP:
		CHECK_PARAM((level<EDFA_RANGE_TMP_THR_MIN)||(level>EDFA_RANGE_TMP_THR_MAX), LOG_ERR, TAG_EDFA, "Error in edfa_set_threshold_level: Temperature level out of range", LOG_LOCAL0);
		sprintf(cmd,"alrm tmp thr %f\n",level);
		break;

	case EDFA_ALARM_MTH:
		CHECK_PARAM((level<EDFA_RANGE_TMP_THR_MIN)||(level>EDFA_RANGE_TMP_THR_MAX), LOG_ERR, TAG_EDFA,
				"Error in edfa_set_threshold_level: High Temperature threshold level out of range", LOG_LOCAL0);
		sprintf(cmd,"alrm mth thr %f\n",level);
		break;

	case EDFA_ALARM_MTL:
		CHECK_PARAM((level<EDFA_RANGE_TMP_THR_MIN)||(level>EDFA_RANGE_TMP_THR_MAX), LOG_ERR, TAG_EDFA,
				"Error in edfa_set_threshold_level: Low temperature threshold level out of range", LOG_LOCAL0);
		sprintf(cmd,"alrm mtl thr %f\n",level);
		break;

	case EDFA_ALARM_LOS:
		CHECK_PARAM((level<EDFA_RANGE_LOS_THR_MIN)||(level>EDFA_RANGE_LOS_THR_MAX), LOG_ERR, TAG_EDFA,
				"Error in edfa_set_threshold_level: LOS threshold level out of range", LOG_LOCAL0);
		sprintf(cmd,"alrm los thr %f\n",level);
		break;

	case EDFA_ALARM_LOP:
		CHECK_PARAM((level<-10)||(level>10), LOG_ERR, TAG_EDFA,
				"Error in edfa_set_threshold_level: LOP threshold level out of range", LOG_LOCAL0);
		sprintf(cmd,"alrm lop thr %f\n",level);
		break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_set_threshold_level: alarm out of range", LOG_LOCAL0);
		return -1;
		break;
	}

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_threshold_level: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_threshold_level: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_set_hysteresis_level(int fd, int alrm, float level, char *data_to_be_received)
{
	char cmd[20];
	int i;

	for (i = 0; i < 20; ++i)
		cmd[i] = '\0';

	switch(alrm)
	{
	case EDFA_ALARM_ILD:
		CHECK_PARAM((level<0)||(level>100), LOG_ERR, TAG_EDFA,
				"Error in edfa_set_hysteresis_level: Pump overcurrent  level out of range", LOG_LOCAL0);

		sprintf(cmd,"alrm ild hys %f\n",level);
		break;

	case EDFA_ALARM_TMP:
		CHECK_PARAM((level<EDFA_RANGE_TMP_THR_MIN)||(level>EDFA_RANGE_TMP_THR_MAX), LOG_ERR, TAG_EDFA,
				"Error in edfa_set_hysteresis_level: Temperature  hysteresislevel out of range", LOG_LOCAL0);

		sprintf(cmd,"alrm tmp hys %f\n",level);
		break;

	case EDFA_ALARM_MTH:
		CHECK_PARAM((level<EDFA_RANGE_TMP_THR_MIN)||(level>EDFA_RANGE_TMP_THR_MAX), LOG_ERR, TAG_EDFA,
				"Error in edfa_set_hysteresis_level: High Temperature hysteresis level out of range", LOG_LOCAL0);

		sprintf(cmd,"alrm mth hys %f\n",level);
		break;

	case EDFA_ALARM_MTL:
		CHECK_PARAM((level<EDFA_RANGE_TMP_THR_MIN)||(level>EDFA_RANGE_TMP_THR_MAX), LOG_ERR, TAG_EDFA,
				"Error in edfa_set_hysteresis_level: Low Temperature hysteresis level out of range", LOG_LOCAL0);

		sprintf(cmd,"alrm mtl hys %f\n",level);
		break;

	case EDFA_ALARM_LOS:
		CHECK_PARAM((level<EDFA_RANGE_LOS_THR_MIN)||(level>EDFA_RANGE_LOS_THR_MAX), LOG_ERR, TAG_EDFA,
				"Error in edfa_set_hysteresis_level: LOS hysteresis level out of range", LOG_LOCAL0);

		sprintf(cmd,"alrm los hys %f\n",level);
		break;

	case EDFA_ALARM_LOP:
		CHECK_PARAM((level<-10)||(level>10), LOG_ERR, TAG_EDFA,
				"Error in edfa_set_hysteresis_level: LOP hysteresis level out of range", LOG_LOCAL0);

		sprintf(cmd,"alrm lop hys %f\n",level);
		break;

	default:
		CHECK_PARAM(1,LOG_ERR, TAG_EDFA,"Error in edfa_set_hysteresis_level: alarm out of range", LOG_LOCAL0);
		return -1;
		break;
	}

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA,
			"Error in edfa_set_hysteresis_level: edfa_send_command(fd, )");

#else
	CHECK_PARAM(edfa_send_command(fd, cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA,
			"Error in edfa_set_hysteresis_level: edfa_send_command(fd, )", LOG_LOCAL0);
#endif

	return 0;
}

int edfa_reset_alarm_status(int fd, int alrm, char *data_to_be_received)
{
	int i;
	char cmd[13];

	for (i = 0; i < 13; ++i)
		cmd[i] = '\0';

	switch(alrm)
	{
	case EDFA_ALARM_ILD:
		strcpy(cmd,"alrm ild clr\n");
		break;

	case EDFA_ALARM_TMP:
		strcpy(cmd,"alrm tmp clr\n");
		break;

	case EDFA_ALARM_MTH:
		strcpy(cmd,"alrm mth clr\n");
		break;

	case EDFA_ALARM_MTL:
		strcpy(cmd,"alrm mtl clr\n");
		break;

	case EDFA_ALARM_LOS:
		strcpy(cmd,"alrm los clr\n");
		break;

	case EDFA_ALARM_LOP:
		strcpy(cmd,"alrm lop clr\n");
		break;

	case EDFA_ALARM_ALL:
		strcpy(cmd,"alrm clr\n");
		break;

	default:
		JUST_LOG(LOG_ERR, TAG_EDFA,"Error in edfa_reset_alarm_status: alarm out of range", LOG_LOCAL0);
		return -1;
		break;
	}

#ifdef TESTING
	CHECK_PARAM(edfa_send_command_mock(cmd, sizeof(cmd))< 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_alarm_status: edfa_send_command_mock()");

#else
	CHECK_PARAM(edfa_send_command(fd,  cmd, sizeof(cmd), data_to_be_received)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_alarm_status: edfa_send_command(fd, )", LOG_LOCAL0);

#endif

	return 0;
}

int edfa_get_loss_input_alarm(unsigned int *status)
{
	CHECK_PARAM(gpio_read_bit(EDFA_PIN_LOSS_INPUT, status) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_loss_input_alarm: gpio_read_bit()", LOG_LOCAL0);

	return 0;
}

int edfa_reset_hw()
{
	int latch;

	int fd_lock;
	fd_lock=filelock_open("edfa_lock");
	
	filelock_lock(fd_lock);
	
	CHECK_PARAM(latch_optical_modules_status(&latch) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_hw(): xfp_get_latch_status()", LOG_LOCAL0);
	CHECK_PARAM(latch == LTC_DISABLED, LOG_ERR, TAG_EDFA, "Error in edfa_reset_hw(): Latch is disabled", LOG_LOCAL0);
	//	CHECK_PARAM( gpio_write_bit(LTC_BIT_STATUS, LTC_ENABLE) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_hw: gpio_write_bit()");
	sleep(5);

	CHECK_PARAM(gpio_write_bit(EDFA_PIN_SHUTDOWN,0) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_shutdown: gpio_write_bit()", LOG_LOCAL0);
	CHECK_PARAM(gpio_write_bit(EDFA_PIN_RESET,0) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_hw: gpio_write_bit()", LOG_LOCAL0);
	sleep(5);

	CHECK_PARAM( gpio_write_bit(EDFA_PIN_SHUTDOWN,1) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_shutdown: gpio_write_bit()", LOG_LOCAL0);
	sleep(10);

	CHECK_PARAM(gpio_write_bit(EDFA_PIN_RESET,1) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_reset_hw: gpio_write_bit()", LOG_LOCAL0);
	sleep(10);

	filelock_close(fd_lock);

	return 0;
}

int edfa_shutdown(int fd, char *data_to_be_received)
{
	int latch;

	CHECK_PARAM(latch_optical_modules_status(&latch) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_shutdown(): xfp_get_latch_status()", LOG_LOCAL0);

	CHECK_PARAM(latch == LTC_DISABLED, LOG_ERR, TAG_EDFA, "Error in edfa_shutdown(): Latch is disabled", LOG_LOCAL0);

	CHECK_PARAM(gpio_write_bit(EDFA_PIN_SHUTDOWN,0) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_shutdown: gpio_write_bit()", LOG_LOCAL0);

	sleep(15);

	CHECK_PARAM( gpio_write_bit(EDFA_PIN_SHUTDOWN,1) < 0, LOG_ERR, TAG_EDFA, "Error in edfa_shutdown: gpio_write_bit()", LOG_LOCAL0);

	return 0;
}

int hl_edfa_set_pout (float power)
{
	char rdata[512];
	unsigned int i;
	int fd=0;
	char tty[]="/dev/ttyAL2";

	if(CHECK_EDFA_POUT(power))
	{
		fd = open(tty, O_RDWR | O_NOCTTY | O_NONBLOCK);

		printf("Reconfigurando potencia de salida EDFA...\n", LOG_LOCAL0);

		int fd_lock;
		fd_lock = filelock_open("edfa_lock");
		filelock_lock(fd_lock);

		latch_optical_modules_enable();

		filelock_close(fd_lock);

		edfa_set_terminal(fd);

		edfa_clean_fifo(fd);

		for(i=0; i<512; i++)
		{
			rdata[i]='\0';
		}

		CHECK_PARAM(edfa_get_mode(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_mode: edfa_get_mode()", LOG_LOCAL0);
		usleep(100000);
		printf("Modo y valor actuales EDFA: %s\n", rdata);
		usleep(100000);

		for(i=0; i<512; i++)
		{
			rdata[i]='\0';
		}

		edfa_set_mode_and_val(fd, EDFA_MODE_P, power, rdata);
		usleep(100000);
		printf("Configuracion modo y valor EDFA: %s\n", rdata);
		usleep(100000);

		for(i=0; i<512; i++)
		{
			rdata[i]='\0';
		}

		CHECK_PARAM(edfa_get_mode(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_mode: edfa_get_mode()", LOG_LOCAL0);
		usleep(100000);

		//Close File
		CHECK_PARAM(close(fd)< 0, LOG_ERR, TAG_EDFA, "Error in hl_edfa_init(): Close Failed", LOG_LOCAL0);
	}
	else
	{
		printf(EDFA_POUT_RANGE_ERROR);
	}

	return(0);
}


int hl_edfa_init (float pout)
{
	char rdata[512];
	int value=0;
	unsigned int i;
	int fd = 0;
	char tty[]="/dev/ttyAL2";

	fd = open(tty, O_RDWR | O_NOCTTY | O_NONBLOCK);

	printf("Configurando EDFA...\n");

	edfa_set_terminal(fd);

	edfa_clean_fifo(fd);

	printf("Reset por hardware...\n");

	edfa_reset_hw();

	printf("Reset por software a valores de fabrica...\n");

	edfa_reset_factory_default_values(fd, rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	printf("Reboot de firmware...\n");

	edfa_reset_firmware(fd, rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_set_mode_and_val(fd, EDFA_MODE_P, pout, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_set_mode_and_val()", LOG_LOCAL0);
	usleep(100000);
	printf("Configuracion modo y valor EDFA: %s\n", rdata);
	usleep(100000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_mode(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_mode: edfa_get_mode()", LOG_LOCAL0);
	usleep(100000);
	printf("Modo y valor EDFA: %s\n", rdata);
	usleep(100000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	int fd_lock;
	fd_lock = filelock_open("edfa_lock");
	filelock_lock(fd_lock);

	CHECK_PARAM(edfa_get_input_power(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_input_power()", LOG_LOCAL0);
	usleep(1000000);
	printf("Potencia de entrada EDFA: %s\n", rdata);
	usleep(500000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_output_power(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_output_power()", LOG_LOCAL0);
	usleep(100000);
	printf("Potencia de salida EDFA: %s\n", rdata);
	usleep(100000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_loss_input_alarm(&value)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_loss_input_alarm()", LOG_LOCAL0);
	usleep(100000);
	printf("LOS EDFA (hardware pin, 0=LOS): %u\n", value);
	usleep(100000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_alarm_information(fd, EDFA_ALARM_LOS, EDFA_ALARM_PARAM_STA, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_alarm_information()", LOG_LOCAL0);
	usleep(100000);
	printf("LOS EDFA (registro): %s\n", rdata);
	usleep(100000);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	CHECK_PARAM(edfa_get_amplifier_status(fd, rdata)< 0, LOG_ERR, TAG_EDFA, "Error in edfa_get_amplifier_status()", LOG_LOCAL0);
	usleep(100000);
	printf("Estado EDFA: %s\n", rdata);

	for(i=0; i<512; i++)
	{
		rdata[i]='\0';
	}

	usleep(100000);

	filelock_close(fd_lock);
	//Close File
	CHECK_PARAM(close(fd)< 0, LOG_ERR, TAG_EDFA, "Error in hl_edfa_init(): Close Failed", LOG_LOCAL0);

	printf("Fin configuracion EDFA.\n");

	return(0);	
}
