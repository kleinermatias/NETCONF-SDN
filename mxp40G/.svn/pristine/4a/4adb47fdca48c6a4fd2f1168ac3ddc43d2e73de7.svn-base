#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

#include "debug.h"

void doc();

    itu_channel_t itu;  
    int mode = 0;
    int side;
    int port;
    

int main (int argc, char **argv)
{

    int next_opt;
    int ret_code;
    char eth[4]="eth\0";
    char otu[4]="otn\0";
    
    const char* const short_opt = "m:a:v:o:s:" ;
    
    const struct option long_opt[] =
    {
        { "module", 1, NULL,'m'},
        { "address", 1, NULL,'d'},
        { "value", 1, NULL,'v'},
        { "size", 1, NULL,'s'},
        { "operation", 1, NULL,'o'},
        {  NULL,  0, NULL, 0 }

    };
       
    int modulo,tamano,direccion,operacion,valor;
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
                   
                    if(strncmp(optarg,"xfp1",4)==0)
                        printf("Modulo: %s\n",optarg);
                    if(strncmp(optarg,"xfp2",4)==0)
                        printf("Modulo: %s\n",optarg);
                    if(strncmp(optarg,"xfp3",4)==0)
                        printf("Modulo: %s\n",optarg);
                    if(strncmp(optarg,"xfp4",4)==0)
                        printf("Modulo: %s\n",optarg);
                    if(strncmp(optarg,"jdsu",4)==0)
                        printf("Modulo: %s\n",optarg);
                    
                    
            break;
                
            case 'a': //address
                   
                   direccion = atoi(optarg);
                   
                   printf("address: %d\n",direccion);
                                   
            break;
                
            case 'v': //valor
                   
                    valor = atoi(optarg);
                   
                   printf("valor: %d\n",valor);
                    
            break;
                
            case 'o': //operacion
                    
                if(strncmp(optarg,"r",1)==0)
                     printf("read\n");
                if(strncmp(optarg,"w",1)==0)
                     printf("write\n");
            break;
             
            case 's': //tamañp
            
            
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

    
    return 0;
}

void doc()
{
    printf("Debug: --module [XFP1-XFP2,XFP3-XFP4-JDSU-CLK-] --address [0-256] --operation [R-W] --size[b-w] \n");
    exit(EXIT_FAILURE);
}
