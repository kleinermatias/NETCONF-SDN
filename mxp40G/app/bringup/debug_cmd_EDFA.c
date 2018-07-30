#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>

/* baudrate settings are defined in <asm/termbits.h>, which is included by <termios.h> */
#define BAUDRATE B9600
/* change this definition for the correct port */
#define MODEMDEVICE "/dev/ttyAL2"
#define _POSIX_SOURCE 1 /* POSIX compliant source */

#define FALSE 0
#define TRUE 1

#define N_CMD 3
        
int init_com(int *p_fd){
  int fd;
  struct termios oldtio,newtio;
  /*
  Open modem device for reading and writing and not as controlling tty
  because we don't want to get killed if linenoise sends CTRL-C.
  */
                
  fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
  if (fd <0) {perror(MODEMDEVICE); exit(-1); }

  tcgetattr(fd,&oldtio); /* save current serial port settings */
  bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */

/*
  BAUDRATE: Set bps rate. You could also use cfsetispeed and cfsetospeed.
  CRTSCTS : output hardware flow control (only used if the cable has all
	    necessary lines. See sect. 7 of Serial-HOWTO)
  CS8     : 8n1 (8bit,no parity,1 stopbit)
  CLOCAL  : local connection, no modem contol
  CREAD   : enable receiving characters
*/
  newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;

/*
  IGNPAR  : ignore bytes with parity errors
  ICRNL   : map CR to NL (otherwise a CR input on the other computer will
	    not terminate input)
	    otherwise make device raw (no other input processing)
*/
  newtio.c_iflag = IGNPAR;

/*
         Raw output.
*/
  newtio.c_oflag = 0;

/*
  ICANON  : enable canonical input disable all echo functionality, and don't
	    send signals to calling program
*/
  newtio.c_lflag = 0;//ICANON;

/*
  initialize all control characters default values can be found in 
  /usr/include/termios.h, and are given in the comments, but we don't need them here
*/
  newtio.c_cc[VINTR]    = 0;     /* Ctrl-c */
  newtio.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
  newtio.c_cc[VERASE]   = 0;     /* del */
  newtio.c_cc[VKILL]    = 0;     /* @ */
  newtio.c_cc[VEOF]     = 4;     /* Ctrl-d */
  newtio.c_cc[VTIME]    = 5;     /* inter-character timer unused */
  newtio.c_cc[VMIN]     = 50;     /* blocking read until 1 character arrives */
  newtio.c_cc[VSWTC]    = 0;     /* '\0' */
  newtio.c_cc[VSTART]   = 0;     /* Ctrl-q */
  newtio.c_cc[VSTOP]    = 0;     /* Ctrl-s */
  newtio.c_cc[VSUSP]    = 0;     /* Ctrl-z */
  newtio.c_cc[VEOL]     = 0;     /* '\0' */
  newtio.c_cc[VREPRINT] = 0;     /* Ctrl-r */
  newtio.c_cc[VDISCARD] = 0;     /* Ctrl-u */
  newtio.c_cc[VWERASE]  = 0;     /* Ctrl-w */
  newtio.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
  newtio.c_cc[VEOL2]    = 0;     /* '\0' */

/*
  now clean the modem line and activate the settings for the port
*/
  tcflush(fd, TCIFLUSH);
  tcsetattr(fd,TCSANOW,&newtio);

  *p_fd = fd;
  return 0;
}


int com_cmd(int fd, char *data_to_be_sent, int size, char *data_to_be_received){
    int res_r,res_w;

    res_w = write(fd, data_to_be_sent,size );
    usleep(160000);
    res_r = read(fd,data_to_be_received,50);
    data_to_be_received[res_r]=0;
    //printf(":%s:#rx=%d #tx=%d\n", buf, res_r,res_w);
    return 0;
}

int main(void)
{
  int fd,i;
          
  char buf[255];
  const char *cmd_edfa[N_CMD]= {"pout\n","pin\n","mt\n",};
  

  init_com(&fd);


while (1)
{
  
  i=(i+1)%N_CMD;
  //printf(" len(%d) - %s\n\r",strlen(cmd_edfa[i]),cmd_edfa[i]);
  com_cmd(fd,cmd_edfa[i],strlen(cmd_edfa[i]),buf);
  printf("|%s|\r\n------------------------------------------------------------\n\r",buf);
}
         
         
  return 0;
}

