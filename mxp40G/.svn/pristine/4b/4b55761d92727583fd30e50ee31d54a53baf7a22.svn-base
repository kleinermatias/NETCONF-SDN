#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "setrtc.h"
#include "../../lib/rtc/rtc.h"

int main (int argc, char **argv)
{

    int next_opt;
    int ret_code;
    
    const char* const short_opt = "y:m:d:h:t:s:" ;
    
    const struct option long_opt[] =
    {
        { "year",1, NULL,'y'},
        { "month",1, NULL,'m'},
        { "day",1, NULL,'d'},
        { "hours",1, NULL,'h'},
        { "minutes",1, NULL,'t'},
        { "seconds",1, NULL,'s'},
        {  NULL,  0, NULL, 0 }

    };
   
    int year,month,day,hours,minutes,seconds;
   
    int flag_y, flag_m, flag_d, flag_h, flag_t, flag_s;
    
    flag_y=flag_m=flag_d=flag_h=flag_t=flag_s=0;
    
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
            case 'y': //year

		if(flag_y==1)
			doc();
		else{
			flag_y=1;
		    	year = atoi(optarg);
		    		if(year<0)
		    			doc();
		    }
            break;

            case 'm': //month
            
            	if(flag_m==1)
            		doc();
            	else{
                        flag_m=1;
                        month = atoi(optarg);
                        	if(month>12 || month<1)
                            		doc();
                    }
            break;
            
            case 'd': //day
            	
            	if(flag_d==1)
			doc();
		else{
			flag_d=1;
			day = atoi(optarg);
			if(day>31 || day<1)
				doc();
                }                    
            break;
            
            case 'h': //hours
            
            	if(flag_h==1)
			doc();
		else{
			flag_h=1;
			hours = atoi(optarg);
			if(hours>23 || hours<0)
				doc();
		}
                    
            break;
            
            case 't': //minutes
            
            	if(flag_t==1)
			doc();
		else{
			flag_t=1;
			minutes = atoi(optarg);
			if(minutes>59 || minutes<0)
				doc();
		}
                       
            break;
            
            case 's': //seconds
            
            	if(flag_s==1)
			doc();
		else{
			flag_s=1;
			seconds = atoi(optarg);
			if(seconds>59 || seconds<0)
				doc();
		}
                       
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
    
	if(flag_y==1)
		rtc_set_years(year);
	if(flag_m==1)
		rtc_set_months(month);
	if(flag_d==1)
		rtc_set_date(day);
	if(flag_h==1)
		rtc_set_hour(hours);
	if(flag_t==1)
		rtc_set_minutes(minutes);
	if(flag_s==1)
		rtc_set_seconds(seconds);
return 0;
}

void doc() {
    printf("USAGE: setrtc [[-y] | [-m] | [-d] | [-h] | [-t] | [-s]] \n -y: year \n -m: month \n -d: day \n -h: hours \n -t: minutes \n -s: seconds \n");    
}
