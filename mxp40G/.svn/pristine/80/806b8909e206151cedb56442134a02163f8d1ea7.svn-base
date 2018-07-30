#include "update.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

#define PATH "/opt/update/"
#define PATH_DESTINO "/opt/bin/"

int test_app(char nombre[]);

int main(int argc, char **argv)
{
     
    if (argc == 1) 
    {
        return 0;
    }
    
    int next_opt;
    const char* const short_opt = "u:p:i:c:" ;
    const struct option long_opt[] =
    {
        { "user", 1, NULL,'u'},
        { "path", 1, NULL,'p'},
        { "ip", 1, NULL,'i'},
        { "command", 1, NULL,'c'},
        {  NULL,  0, NULL, 0 }

    };
    
    char scp[512];
    char user[256];
    char path[512];
    char ip[256];
    char comando[256];
    int flag_p, flag_u, flag_i, flag_c;
    
    flag_p=flag_u=flag_i=flag_c=0;
    
     while (1) 
    {
        
        next_opt = getopt_long (argc, argv, short_opt, long_opt, NULL);
        if (next_opt == -1) break;

        switch (next_opt)
        {   
            case 'u':
            
                    if(flag_u==1)
                        return 0;
                    
                    flag_u=1;
                    
                    strcpy(user,optarg);
            
            break;
            
            case 'p':
                    if(flag_p==1)
                        return 0;
                    
                    flag_p=1;
                    
                    strcpy(path,optarg);
            break;
            
            case 'i':
                    if(flag_i==1)
                        return 0;
                    
                    flag_i=1;
                    
                    strcpy(ip,optarg);
            break;
            
            case 'c':
                    if(flag_c==1)
                        return 0;
                    
                    flag_c=1;
                    
                    strcpy(comando,optarg);
            break;
            case '?':
                 exit(1);
            break;
                
            case -1:
                
                exit(1);
            break;
                
            default:    // Invalid outcome
                abort();
            break;
        }
    }
    
       
    sprintf(scp, "scp  %s@%s:/%s/%s %s", user, ip, path, comando,PATH);
    printf("%s\n",scp);
	if(system(scp)==0) {
       
        sprintf(scp, "chmod 777 %s%s",PATH,comando);
        printf("%s\n",scp);
        system(scp);
        
            
         if(test_app(comando)<0) {
                printf("no son lo mismo\n");
        }
        else {
              
            sprintf(scp, "mv %s%s %s",PATH,comando,PATH_DESTINO);
            printf("%s\n",scp);
            system(scp);
        }
    }

    return 0;
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
             
        if(strncmp(name,nombre,strlen(nombre))!=0)
            return -1;
          
        wait();
    }
    
    return 0;
}

