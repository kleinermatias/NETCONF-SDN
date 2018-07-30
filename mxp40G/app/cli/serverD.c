#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "serverD.h"

int test_app(char nombre[]);
int restore_command(char nombre[]) ;

int main(int argc, char* argv[])
{
    //FILE *fp= NULL;
    pid_t process_id = 0;
    pid_t sid = 0;

    // Create child process
    process_id = fork();
    
    // Indication of fork() failure
    if (process_id < 0)
    {
        printf("fork failed!\n");
        // Return failure in exit status
        exit(1);
    }

    // PARENT PROCESS. Need to kill it.
    if (process_id > 0)
    {
        printf("process_id of child process %d \n", process_id);
        // return success in exit status
        exit(0);
    }

    //unmask the file mode
    umask(0);
    
    //set new session
    sid = setsid();
    if(sid < 0)
    {
        // Return failure
        exit(1);
    }
    
    //Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

   
    while (1)
    {
   
   int listenfd,connfd;
   struct sockaddr_in servaddr,cliaddr;
   socklen_t clilen;
   pid_t     childpid;
   char nombre[1218];

   listenfd=socket(AF_INET,SOCK_STREAM,0);

   bzero(&servaddr,sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
   servaddr.sin_port=htons(5000);
   
   if(bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr))==-1)
   {
       printf("No se pudo bindear\n");
   }

   listen(listenfd,1024);

   for(;;)
   {
      clilen=sizeof(cliaddr);
      
      if((connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&clilen))==-1)
      {
          printf("ERROR: Obtaining new Socket Despcritor. (errno = )\n");
      }
      else
      {
         printf("[Server] Server has got connected from %s\n", inet_ntoa(cliaddr.sin_addr));
      }

      if ((childpid = fork()) == 0)
      {
         close (listenfd);

               
        char fr_name[256] = "/opt/update/";
        int size;
            
           if((size = recv(connfd, nombre, 128, 0)) > 0)
            {
                printf("tamaño del archivo: %d\n",size);
                
               
                
                if(strncmp(nombre,"restore",7)==0){
                    printf("Restore file: %s\n",nombre);
                    restore_command(nombre);
                    return 0;
                }
                else 
                {  
                    strcat(fr_name,nombre);
                    printf("Nombre del archivo: %s\n",fr_name);
                }
            }
             
        int LENGTH = 256;
        char revbuf[LENGTH]; 
        /*Receive File from Client */
       
        FILE *fr = fopen(fr_name, "a");
        if(fr == NULL)
            printf("File Cannot be opened file on server.\n");
        else
        {
            bzero(revbuf, LENGTH); 
            int fr_block_sz = 0;
             
            while((fr_block_sz = recv(connfd, revbuf, LENGTH, 0)) > 0) 
            { 
                int write_sz = fwrite(revbuf, sizeof(char), fr_block_sz, fr);
                if(write_sz < fr_block_sz)
                {
                    //error("File write failed on server.\n");
                }
                
                bzero(revbuf, LENGTH);
                if (fr_block_sz == 0 || fr_block_sz != 256) 
                {
                  break;
                }
               
            }
            if(fr_block_sz < 0)
            {
                if (errno == EAGAIN)
                {
                    printf("recv() timed out.\n");
                }
                else
                {
                    fprintf(stderr, "recv() failed due to errno = %d\n", errno);
                    exit(1);
                }
            }
            printf("Ok received from cliente!\n");
            fclose(fr);
            //--------
           
             char chmod[256];
             sprintf(chmod, "chmod -R 777 /opt/update/%s", nombre);
             system(chmod);
            
            if(test_app(nombre)<0) {
                printf("no son lo mismo\n");
            }
            else
            {
                char cmd[256];
                sprintf(cmd, "pkill  %s", nombre);
                
                if(system(cmd)==0)
                    printf("%s\n",cmd);
                
                sprintf(cmd, "mv  /opt/update/%s /opt/bin/ ", nombre);
                if(system(cmd)==0)
                    printf("Archivo Copiado\n");
                
                //printf("son lo mismo\n");
            }
                    
            
            //------------------
           kill(getpid(), SIGKILL); 
        }
         
      }
      close(connfd);
   }    

        
        
    }
    
    
    return (0);
}

int test_app(char nombre[])
{
    char* arguments[] = {nombre,"-^", NULL};

        
    int my_pipe[2];
    if(pipe(my_pipe) == -1)
    {
        fprintf(stderr, "Error creating pipe\n");
    }

    pid_t child_id;
    child_id = fork();
    if(child_id == -1)
    {
        fprintf(stderr, "Fork error\n");
    }
    
    if(child_id == 0) // child process
    {
        close(my_pipe[0]); // child doesn't read
        dup2(my_pipe[1], 1); // redirect stdout
        
        char comando[256]="./";
        strcat(comando,nombre);
        execvp(comando, arguments);

        fprintf(stderr, "Exec failed\n");
        
        
    }
    else
    {
        close(my_pipe[1]); // parent doesn't write

       char reading_buf[1];
       char name[256]="";
       int i=0;
       while(read(my_pipe[0], reading_buf, 1) > 0)
       {
           write(1, reading_buf, 0); // 1 -> stdout
           name[i]=reading_buf[0];
           i++;
       }
    
      close(my_pipe[0]);
                 
      //printf("name = %s\n",name);
      //printf("name = %s\n",nombre);
       
       if(strncmp(name,nombre,strlen(nombre))!=0)
            return -1;
          
       wait();
    }
    
    return 0;
}

int restore_command(char nombre[]) 
{
    char s2[4] = "/\\";
    char *ptr;
    char restore[128];
   
    printf( "comando = %s\n", nombre );
    strcpy(restore,"/opt/factory/");
    ptr = strtok( nombre, s2 );    // Primera llamada => Primer token
    printf( "%s\n", ptr );
    
    while( (ptr = strtok( NULL, s2 )) != NULL ) 
        strcat(restore,ptr);
  
   printf( "file = %s\n", restore );
    
   if((system(restore))==0) 
   {
      
       char cp[256];
       strcpy(cp,"cp ");
       strcat(cp,restore);
       strcat(cp, " /opt/bin/");
       if((system(cp))==0) 
       {
            printf("Archivo copiado.\n");
       }
   }
   else
   {
       printf("file not found\n");
   }
   
   return 0;
}
