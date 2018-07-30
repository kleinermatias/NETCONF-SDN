#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include "logrotate.h"

#define CANTIDAD_LOGS   17
#define COMANDO         "df /var/log/ | tail -1 | awk '{print $5}' | cut -f 1 -d '%'"
#define BACKUPS_PATH    "/var/log/rsyslog/backups/"
#define LOGS_PATH       "/var/log/rsyslog/"

char *paths [CANTIDAD_LOGS] = {"xfp.log","txp.log","i2c.log",
                                "gpio.log","kern.log","fan.log",
                                "clk.log","ltc.log","tmp.log",
                                "led.log","qsfp.log","rtc.log",
                                "bman.log","edfa.log","hmd.log",
                                "user.log","messages"};
                                        
int main(void)
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
    //close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
      check_modify_date();  
      sleep(60);
      check_space(); 
    }
     
    return EXIT_SUCCESS;
}

int df ()
{
    FILE *fp;
    char path[256];

    /* Open the command for reading. */
    fp = popen(COMANDO, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        return -1;
    }

    /* Read the output a line at a time - output it. */
    while (fgets(path, sizeof(path)-1, fp) != NULL) {}
      
    pclose(fp);

    return atoi(path);
}

int check_space(void)
{     
    int used_space;
    char cmd[512];
    
    used_space = df();
    
    printf("Espacio disponible: %d %\n",(100-used_space));
    printf("Espacio utilizado: %d %\n",(used_space));
   
    //primer paso, borrar todo los archivos de la carpeta /var/log/rsyslog/backups/
    if ( used_space >= 12 ) {
        
        sprintf(cmd, "rm -r  %s* ", BACKUPS_PATH);
        system(cmd);
        printf("%s*\n",BACKUPS_PATH);
    } 
    
    used_space = df();
     
    //segundo paso, limpiar los logs.
    if ( used_space >= 12 ) {
        
        int i;
        for (i = 0; i < CANTIDAD_LOGS; i++) {
        
            sprintf(cmd, "echo >  %s%s ", LOGS_PATH, paths[i]);
            system(cmd);
            printf("%s\n",cmd);
        }
    }
      
    return 0;
}

int check_modify_date(void) {

   time_t current_time;
    char date[10];
    char archivo_actual[512];
    int today;
    struct stat attrib;
    //char filePath[256] = "/home/rantonana/testRW.c";
    
    struct tm* tm;
    int modify,i,month,year;
    
    current_time = time(NULL);
    
        if ( current_time == ((time_t)-1) ) {
            
            (void) fprintf(stderr, "Failure to compute the current time.");
            return -1;
        }
    
        tm = localtime(&current_time);
        
        //today = tm->tm_mday;
        today = tm->tm_min;
        //printf("Current number day is %d\n",today);
        
        for (i = 0; i < CANTIDAD_LOGS; i++) {
                                 
            strcpy(archivo_actual,paths[i]);
            stat(archivo_actual, &attrib);
        
            //                  %d.%m.%Y %H:%M:%S
            //strftime(date, 10, "%d", gmtime(&(attrib.st_mtime)));
            strftime(date, 10, "%M", gmtime(&(attrib.st_mtime)));
            modify = atoi(date);
            
            if ( (today == 45 || today == 0 || today == 15 || today == 30) && (modify != 45 || modify != 0 || modify != 15 || modify != 30) ) {
                
                char cmd[512];
                
                strftime(date, 10, "%H%M%S", gmtime(&(attrib.st_mtime)));
                //strftime(date, 10, "%d%m%Y", gmtime(&(attrib.st_mtime)));
                sprintf(cmd, "tar cvf %s%s%s.tar %s%s", BACKUPS_PATH, archivo_actual, date, LOGS_PATH, archivo_actual);
                system(cmd);
                
                sprintf(cmd, "echo >  %s%s ", LOGS_PATH, archivo_actual);
                printf("%s\n",cmd);
                system(cmd);
            }
            
             date[0] = 0;
       }

    return 0;
}
