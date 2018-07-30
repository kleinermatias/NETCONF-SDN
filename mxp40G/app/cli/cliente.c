#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <dirent.h>
#include "cliente.h"

volatile sig_atomic_t flag = 0;
int sockfd,n;
struct sockaddr_in servaddr;
char sendline[1000];
char recvline[1000];

void my_function(int sig){ // can be called asynchronously
  flag = 1; // set flag
}

int main(int argc, char**argv)
{
   
   if(argc<2)
        return 0;
        
    
   signal(SIGINT, my_function); 
   
   sockfd=socket(AF_INET,SOCK_STREAM,0);

   bzero(&servaddr,sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
   servaddr.sin_port=htons(5000);
  
  if(strncmp(argv[1],"restore",7)==0){
     
     if(argc<3)
        return 0;
                    
    printf("%s %s\n",argv[1], argv[2]);
        
   connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
   
   char restore[128];
   
   strcpy(restore,argv[1]);
   strcat(restore,"/\\");
   strcat(restore,argv[2]);
   
   if(send(sockfd, restore, 128, 0) < 0)
    {
     printf("ERROR: \n");
     close(sockfd);
     return -1;
    }
        return 0;
    }
        
   

   
}
