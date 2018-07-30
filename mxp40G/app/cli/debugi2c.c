#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include "debugi2c.h"

void doc();

    itu_channel_t itu;  
    int mode = 0;
    int side;
    int port;
    

int main (int argc, char **argv)
{

    int next_opt;
    int ret_code;
       
    const char* const short_opt = "m:a:v:o:s:h" ;
    
    const struct option long_opt[] =
    {
        { "module", 1, NULL,'m'},
        { "address", 1, NULL,'a'},
        { "value", 1, NULL,'v'},
        { "size", 1, NULL,'s'},
        { "operation", 1, NULL,'o'},
        { "help", 0, NULL,'h'},
        {  NULL,  0, NULL, 0 }
    };
       
    int modulo,tamano,direccion,operacion,valor,slave;
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
        
            case 'm': //modulo
                    if(strncmp(optarg,"xfp0",4)==0){
                        slave = XFP_SLAVE_ADDRESS;
                        modulo = XFP_MOD_0;
                        printf("Modulo: %s\n",optarg);
                    }
                    else if(strncmp(optarg,"xfp1",4)==0){
                        slave = XFP_SLAVE_ADDRESS;
                        modulo = XFP_MOD_1;
                        printf("Modulo: %s\n",optarg);
                    }
                    else if(strncmp(optarg,"xfp2",4)==0){
                        slave = XFP_SLAVE_ADDRESS;
                        modulo = XFP_MOD_2;
                        printf("Modulo: %s\n",optarg);
                    }
                    else if(strncmp(optarg,"xfp3",4)==0){
                        slave = XFP_SLAVE_ADDRESS;
                        modulo = XFP_MOD_3;
                        printf("Modulo: %s\n",optarg);
                    }
                    else if(strncmp(optarg,"clk",3)==0){
                        slave = CLK_SLAVE_ADDRESS;
                        modulo = CLK_BUS;
                        printf("Modulo: %s\n",optarg);
                    }
                    else if(strncmp(optarg,"rtc",3)==0){
                        slave = RTC_SLAVE_ADDRESS;
                        modulo = RTC_BUS;
                        printf("Modulo: %s\n",optarg);
                    }
                    else if(strncmp(optarg,"hmd",3)==0){
                        slave = HMD_SLAVE_ADDRESS;
                        modulo = HMD_BUS;
                        printf("Modulo: %s\n",optarg);
                    }
                    else
                    {
                        doc();
                    }
                    
            break;
                
            case 'a': //address
                   
                   direccion = atoi(optarg);
                   if(direccion<0)
                    doc();
                   printf("Direccion: %d\n",direccion);
            break;
                
            case 'v': //valor
                   valor = atoi(optarg);
                   printf("valor: %d\n",valor);
            break;
                
            case 'o': //operacion
                    
                if(strncmp(optarg,"read",4)==0)
                     operacion=0;
                if(strncmp(optarg,"write",5)==0)
                     operacion=1;
            break;
             
            case 's': //tamañp
                  
                  
                  if(strncmp("byte",optarg,4)==0 && strlen(optarg)==1)
                    tamano = 2;
                  else if(strncmp("word",optarg,4)==0 && strlen(optarg)==1)
                    tamano = 3;
                   else
                        doc();
            break;
            case 'h':
                 doc();
                
            break;
            
            case '?':
                
            break;
                
            case -1:
               
            break;
                
            default:    // Invalid outcome
                abort();
            break;
        }
    }
    int reg;
    
    if(operacion==0){
        i2c_read(modulo, slave, direccion,tamano, &reg, 0);
        printf("Valor: %d\n",reg);
    }
    if(operacion==1){
        i2c_write(modulo, slave, direccion,tamano, &valor, 0);
    }
    
    return 0;
}

void doc()
{
    printf("Debug: --module [XFP1-XFP2,XFP3-XFP4-JDSU-CLK-] --address [0-256] --operation [read-write] --size[byte-word] \n");
    exit(EXIT_FAILURE);
}
