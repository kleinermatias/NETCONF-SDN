#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "logs.h"

int main (int argc, char **argv)
{

    int next_opt;
    int ret_code;
    char parameters[256];
    char filtro[256];
    char module[8];
    char date[32];
    const char* const short_opt = "wecm:d:" ;
    
    const struct option long_opt[] =
    {
        { "warnings", 0, NULL,'w'},
        { "errors", 0, NULL,'e'},
        { "critical", 0, NULL,'c'},
        { "module",1, NULL,'m'},
        { "date",1, NULL,'d'},
        {  NULL,  0, NULL, 0 }

    };
    strcpy(parameters,"grep \"");
    strcpy(date,"| grep \"^");
    strcpy(filtro,"");
    int flag_w, flag_e, flag_c, flag_m, flag_d, flag_inicio;
    
    flag_w=flag_e=flag_c=flag_m=flag_inicio=flag_d=0;
    /* Si se ejecuta sin parámetros ni opciones */
    if (argc == 1) 
    {
        doc();
    }

    while (1) 
    {
        
        next_opt = getopt_long (argc, argv, short_opt, long_opt, NULL);
        if (next_opt == -1) break;

        switch (next_opt)
        {
        
            case 'w': //warnings
                    flag_w=1;
            break;
            
            case 'e': //errors
                    flag_e=1;
            break;
            
            case 'c': //critical
                    flag_c=1;
            break;
            
            case 'm': //module
                    flag_m=1;
                    strcpy(module,optarg);
            break;
            
            case 'd': //date
                   flag_d=1;
                   strcat(date,optarg);
                   strcat(date,"\"");
                   
            break;
            
            case '?':
                doc ();
                 exit(1);
            break;
                
            case -1:
                doc ();
                exit(1);
            break;
                
            default:    // Invalid outcome
                abort();
            break;
        }
    }

    if(flag_m)
    {
       
    if(strncmp(module,"xfp",3)==0){
        
        if(strcmp(module,"xfp1")==0)
            strcat(filtro,"ID=1\" /var/log/rsyslog/xfp.log ");
        else if(strcmp(module,"xfp2")==0)
             strcat(filtro,"ID=2\" /var/log/rsyslog/xfp.log ");
        else if(strcmp(module,"xfp3")==0)
            strcat(filtro,"ID=3\" /var/log/rsyslog/xfp.log ");
        else if(strcmp(module,"xfp4")==0)
            strcat(filtro,"ID=4\" /var/log/rsyslog/xfp.log ");
          else if((strcmp(module,"xfp")==0) && strlen(module)==3)
           strcat(filtro,"XFP\" /var/log/rsyslog/xfp.log ");
        else
            doc();
        
        
    }
    else if(strcmp(module,"txp")==0)
                strcat(filtro,"TXP\" /var/log/rsyslog/txp.log ");
    else if(strcmp(module,"edfa")==0)
                strcat(filtro,"EDFA\" /var/log/rsyslog/edfa.log ");
    else if(strcmp(module,"gpio")==0)
                strcat(filtro,"GPIO\" /var/log/rsyslog/gpio.log ");
    else if(strcmp(module,"i2c")==0)
                strcat(filtro,"I2C\" /var/log/rsyslog/i2c.log ");
    else if(strcmp(module,"bman")==0)
                strcat(filtro,"BMAN\" /var/log/rsyslog/bman.log ");
    else if(strcmp(module,"clk")==0)
                strcat(filtro,"CLK\" /var/log/rsyslog/clk.log ");
    else if(strcmp(module,"fan")==0)
                strcat(filtro,"FAN\" /var/log/rsyslog/fan.log ");
    else if(strcmp(module,"led")==0)
                strcat(filtro,"LED\" /var/log/rsyslog/led.log ");
    else if(strcmp(module,"qsfp")==0)
                strcat(filtro,"QDFP\" /var/log/rsyslog/qsfp.log ");
    else if(strcmp(module,"ltc")==0)
                strcat(filtro,"LTC\" /var/log/rsyslog/ltc.log ");
    else if(strcmp(module,"tmp")==0)
                strcat(filtro,"TMP\" /var/log/rsyslog/tmp.log ");
     else if(strcmp(module,"rtc")==0)
                strcat(filtro,"RTC\" /var/log/rsyslog/rtc.log ");
     else if(strcmp(module,"kernel")==0)
                strcat(filtro,"kernel\" /var/log/rsyslog/kern.log ");
    else
        doc();
    }
    
    if(flag_w || flag_e || flag_c)
    {
        if(flag_w)
        {
            flag_inicio=1;
            strcat(filtro," | grep \"Warn");
        }
        if(flag_e)
        {
            if(flag_inicio)
                strcat(filtro,"\\|Error");
            else {
                strcat(filtro," | grep \"Error");
                flag_inicio=1;
            }
        }
        if(flag_c)
        {
            if(flag_inicio)
                strcat(filtro,"\\|Crit");
            else {
                strcat(filtro,"| grep \"Crit");
                flag_inicio=1;
            }
        }
        
        strcat(filtro,"\" ");
    }
    
   
    
    if(flag_d)
    {
    strcat(filtro,date);
    }
    
    strcat(filtro," | more");
    
    
    strcat(parameters,filtro);
    printf("filtro: %s\n\n",filtro);
    printf("comando: %s\n\n",parameters);
    system(parameters);
    
    return 0;
}

void doc() {
    printf("USAGE: logs [ [-wec] | [-m] [xfp|txp|tmp|edfa|i2c|gpio|ltc|led|qsfp|bmanclk|fan|rtc] ]  [-d] [\"Month  Day\"] \n -w: Include warning messages \n -e: Include error messages \n -c: Include critical messages\n -d: Date\n");
    printf(" -m Include specified module messages\n");
    
   exit(EXIT_FAILURE);
    
}
