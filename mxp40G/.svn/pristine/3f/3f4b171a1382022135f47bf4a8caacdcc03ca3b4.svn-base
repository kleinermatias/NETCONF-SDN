#include <stdio.h>
#include "testi2c.h"


int main(int argc, char **argv)
{
    int i;
    int n;
    int j;
    
    if(argc>1) {
        n=atoi(argv[1]);
    }
    else
    {
        n=1;
    }
    
    for ( j=0; j<n; j++) {
        
           
        for (i = 0; i < 4; i++)
        {
            printf("Test XFP %d: \n",i);
            showStatus(i);
            showInfo(i);
        }
    
        showConditions();
    }
    
	return 0;
}


void showConditions() {

   int status;
   
   //---------------------FAN
   fan_get_alert(FAN1_ALERT,&status);
   fan_clear(FAN1_CLEAR);
   
   if(status)
    printf("FAN 1 Status: OK\n");
   else
    printf("FAN 1 Status: NO OK\n");

   fan_get_alert(FAN2_ALERT,&status);
   fan_clear(FAN2_CLEAR);
   
   if(status)
    printf("FAN 2 Status: OK\n");
   else
    printf("FAN 2 Status: NO OK\n");
    
   fan_get_alert(FAN3_ALERT,&status);
   fan_clear(FAN3_CLEAR);
   
   if(status)
    printf("FAN 3 Status: OK\n");
   else
    printf("FAN 3 Status: NO OK\n");
    
   fan_get_alert(FAN4_ALERT,&status);
   fan_clear(FAN4_CLEAR);
   
   if(status)
    printf("FAN 4 Status: OK\n");
   else
    printf("FAN 4 Status: NO OK\n");
    
    //-------------------TMP
    float tmp;
    
    tmp = -1;    
    tmp_get_ext_temp(TMP_REMOTE_1_REG,&tmp);
    printf("FPGA Temp: %.2f C\n",tmp);
    
    tmp = -1;
    tmp_get_ext_temp(TMP_REMOTE_2_REG,&tmp);
    printf("JDSU Temp: %.2f C\n",tmp);
    
    tmp = -1;
    tmp_get_ext_temp(TMP_REMOTE_3_REG,&tmp);
    printf("EDFA Temp: %.2f C\n",tmp);
    
    tmp = -1;
    tmp_get_ext_temp(TMP_REMOTE_4_REG,&tmp);
    printf("T41 Temp: %.2f C\n",tmp);
    
    tmp = -1;
    tmp_get_ext_temp(TMP_REMOTE_5_REG,&tmp);
    printf("T41 internal Temp 1: %.2f C\n",tmp);
    
    tmp = -1;
    tmp_get_ext_temp(TMP_REMOTE_6_REG,&tmp);
    printf("T41 internal Temp 2: %.2f C\n",tmp);
    
    tmp = -1;
    tmp_get_ext_temp(TMP_REMOTE_7_REG,&tmp);
    printf("T41 internal Temp 3: %.2f C\n",tmp);
    
    tmp = -1;
    tmp_get_ext_temp(TMP_LOCAL_REG,&tmp);
    printf("Local Temp 3: %.2f C\n",tmp);
    
    //-------------------HMD
    
    status = 0;
    hmd_get_temp_comp_humidity(&status);
    printf("humidity: %d\n", &status);
    
    status = 0;
    hmd_get_humidity(&status);
    printf("humidity: %d\n", &status);
    
}

void showStatus(int port) {
    
    float temp;
    int status;
    double value_real;
    
        
    switch(port) {
        case 0:
            port = XFP_MOD_0;
            break;
            
        case 1:
            port = XFP_MOD_1;
            break;
            
        case 2:
            port = XFP_MOD_2;
            break;
        
        case 3:
            port = XFP_MOD_3;
            break;
        
        default:
            break;
        
        }
        
    xfp_get_laser_status(port, &status);
    
    if (status == 0)
        printf("    Laser Status: UP\n");
    else
        printf("    Laser Status: DOWN\n");
           
    xfp_get_temperature(port, &temp);
    printf("    Temperature: %.2f C\n", temp);

        
    printf("    Optical laser power: \n");
            
    xfp_get_tx_power(port, &status);
    value_real = ((double) status) * .0001;
    value_real = 10.0 * log10(value_real);
    printf("        TX: %.2f dBm\n", value_real);
            
    xfp_get_rx_power(port, &status);
    value_real = ((double) status) * .0001;
    value_real = 10.0 * log10(value_real);
    printf("        RX: %.2f dBm ", value_real);
	
    if (value_real <= -40.0) 
        printf("(no signal)");
    
    printf("\n");
                

}


void showInfo(int port) {
    
    int id;
    char info;
    
    
   
    int i,wl;
   
    id=-1;
    wl=-1;
       
    //	This check changes the output in case an XFP interface is unavailable.  
    
    if ( xfp_get_identifier(i,&id)>=0) {                
        
        printf("\tXFP Identifier: %d",id);
        printf("\n");
            
        xfp_get_wavelength(i,&wl);
        printf("\tWavelength: %d nm",wl);
        printf("\n");
            
            
        printf("\tVendor Name: ");
        xfp_get_vendor_name(i);
        printf("\n");
            
        printf("\tVendor OUI: ");
        xfp_get_vendor_oui(i);
        printf("\n");
            
        printf("\tVendor Part Number: ");
        xfp_get_part_number(i);
        printf("\n");
            
        printf("\tVendor Revision level: ");
        xfp_get_revision_level(i);
        printf("\n");
            
        printf("\tVendor's manufacturing date code: ");
        xfp_get_date_code(i);
        printf("\n");
        
        printf("\tVendor Serial Number: ");
        xfp_get_serial_number(i);
        printf("\n");
        
        } else {
            
            printf("\tDEVICE UNAVAILABLE\n");
        }
   
    
}
