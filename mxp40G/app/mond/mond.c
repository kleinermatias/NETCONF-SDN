#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/syslog.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <string.h>
#include "mond.h"
#include "logger.h"
#include "parser.h"
#define SLEEP_TIME 900

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
    
    // Change the current working directory to root.
    chdir("/");
    
    // Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    //int count = 0;

    // Open a log file in write mode.
    //fp = fopen ("Log.txt", "w+");
    config_t config;

    get_config("/etc/mxp/mond.conf", &config);    // from parser

    init_tmp(&config.tmp);

    init_hmd();

    init_T41();

    init_xfp(&config.xfp);

    init_qsfp(&config.qsfp);

    init_txp(&config.txp);

    while (1)
    {
        //Dont block context switches, let the process sleep for some time
        //sleep(1);
        //openlog("MxPmond", LOG_PID|LOG_CONS, LOG_USER);
        //syslog(LOG_INFO, "Counter value: %d", ++count);
        //closelog();

        
        // HMD API
        //log_hmd(&config.hmd);
//        sleep(SLEEP_TIME);
        //TMP API
        //log_tmp(&config.tmp);
//        sleep(SLEEP_TIME);
        // XFP API
        log_xfp();
//        sleep(SLEEP_TIME);
        // T41
        //log_otn();
//        sleep(SLEEP_TIME);
        //log_eth();
//        sleep(SLEEP_TIME);
        //log_qsfp(&config.qsfp);
//        sleep(SLEEP_TIME);
        log_txp();
        
        sleep(SLEEP_TIME);

        //fprintf(fp, "Logging info...\n");
        //fflush(fp);
        // Implement and call some function that does core work for this daemon.
    }
    
    //fclose(fp);
    return (0);
}
