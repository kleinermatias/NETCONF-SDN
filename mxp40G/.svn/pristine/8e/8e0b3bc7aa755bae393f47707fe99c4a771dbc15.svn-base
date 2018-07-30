#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h> // needed for memset

int main(int argc,char** argv)
{
        struct termios tio;
        struct termios stdio;
        int tty_fd;
        fd_set rdset;

        unsigned char c='D';

        printf("Please start with %s /dev/ttyS1 (for example)\n",argv[0]);
        memset(&stdio,0,sizeof(stdio));
        stdio.c_iflag=0;
        stdio.c_oflag=0;
        stdio.c_cflag=0;
        stdio.c_lflag=0;
        stdio.c_cc[VMIN]=1;
        stdio.c_cc[VTIME]=0;
        tcsetattr(STDOUT_FILENO,TCSANOW,&stdio);
        tcsetattr(STDOUT_FILENO,TCSAFLUSH,&stdio);
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);       // make the reads non-blocking

        memset(&tio,0,sizeof(tio));
        tio.c_iflag=0;
        tio.c_oflag=0;
        tio.c_cflag=CS8|CREAD|CLOCAL;           // 8n1, see termios.h for more information
        tio.c_lflag=0;
        tio.c_cc[VMIN]=1;
        tio.c_cc[VTIME]=5;

//        tty_fd=open(argv[1], O_RDWR | O_NONBLOCK);
        tty_fd=open(argv[1], O_RDWR | O_NOCTTY | O_NONBLOCK);
//        cfsetospeed(&tio,B9600);            // 115200 baud
//        cfsetispeed(&tio,B9600);            // 115200 baud
        cfsetospeed(&tio,B9600);            // 115200 baud
        cfsetispeed(&tio,B9600);            // 115200 baud

        tcsetattr(tty_fd,TCSANOW,&tio);

        int start_read = 0;


//        write(tty_fd,"ver\n",5);

        printf("Collecting FIFO garbage...\n");

        while(read(tty_fd,&c,1)>0)
        {
        	write(STDOUT_FILENO,&c,1);
        }

        write(tty_fd,"\n",2);

        while(read(tty_fd,&c,1)>0)
        {
        	write(STDOUT_FILENO,&c,1);
        }

        printf("\nReady.\n");

        while (c!='q')
        {

			if (read(STDIN_FILENO,&c,1)>0)
			{
				if(c!='q')
				{
					write(tty_fd,&c,1);                     // if new data is available on the console, send it to the serial port
					start_read = 0;
				}
			}

			if (read(tty_fd,&c,1)>0)
			{
				start_read = 1;
				write(STDOUT_FILENO,&c,1);              // if new data is available on the serial port, print it out
			}
			/*
			else
			{
				if(start_read == 1)
				{
					start_read = 0;
					write(tty_fd,"\n",1);
					// PROBAR DE NO ESCRIBIR EL \N, A VER SI CON EL SLEEP SOLO YA SE ARREGLA
					usleep(100000);
					read(tty_fd,&c,1);
					// PONER LOS WRITES SIGUIENTES EN UN WHILE AUTOMATICO QUE LEA HASTA QUE DEVUELVA CERO
					write(STDOUT_FILENO,&c,1);
					read(tty_fd,&c,1);
					write(STDOUT_FILENO,&c,1);
					read(tty_fd,&c,1);
					write(STDOUT_FILENO,&c,1);
					read(tty_fd,&c,1);
					write(STDOUT_FILENO,&c,1);
					read(tty_fd,&c,1);
					write(STDOUT_FILENO,&c,1);
					//printf("start read\n");
				}

			}
			*/

        }

        close(tty_fd);
        return 1;
//        select();

}
