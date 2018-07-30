#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugtmp.h"
#include "../../lib/tmp/tmp.h"


int main(int argc, char **argv)
{ 
    /**
     * 
     * Canal 3 =  
     * 
     * Canal 4 =
     * 
     * Canal 5 = Abajo del chip de Cortina
     * 
     */
     
     
    float temp;
    
    while(1) {
        
         //-------------------TMP
    float tmp;
    
    tmp = -1;    
    int t=-1;
    
   
    
    tmp_get_ext_temp(TMP_REMOTE_1_REG,&tmp);
    printf("FPGA Temp: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_2_REG,&tmp);
    printf("JDSU Temp: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_3_REG,&tmp);
    printf("EDFA Temp: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_4_REG,&tmp);
    printf("T41 Temp: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_5_REG,&tmp);
    printf("T41 internal Temp 1: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_6_REG,&tmp);
    printf("T41 internal Temp 2: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_7_REG,&tmp);
    printf("T41 internal Temp 3: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_LOCAL_REG,&tmp);
    
    getchar();
        
        
    }
    
    return 0;
}

void clear_screen()
{
system("clear");
} 
