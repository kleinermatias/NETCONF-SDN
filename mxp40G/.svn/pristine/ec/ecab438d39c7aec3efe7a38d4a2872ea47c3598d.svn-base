#include <stdio.h>
#include "testRW.h"

int main(int argc, char **argv)
{
    T41_t Chip;
	int dev_id = 0;
    int mod_a;
    int mod_b;
    int hsif_kpga = TEN_HSIF_PRBS_PN31;
    int kpga = TEN_KPG_PN31;
    
    // Driver loading.
    if (ten_drvr_load() != CS_OK) {
        printf("Error: could not load Cortina driver!\n");
        return -1;
    }
    
    ten_drvr_ctl_stats_hex_format(1);
    
    //Registramos el Dispositivo
    print_status("Device registered: ", ten_dev_register(dev_id, 0));
       
	//Inicializamos el dispositivo
    print_status("FF - CS604x device initialization: ",ten_dev_main_init(dev_id));
        
    printf("FF  - Device Chip Id = %08X\n", ten_mpif_get_chip_jtag_id(dev_id));

    mod_a =  dev_id << 8;
    mod_b = (  dev_id << 8 ) | 1;
    
    mod_a = ten_mod_main_init(dev_id, TEN_MODULE_A );
    mod_b = ten_mod_main_init(dev_id, TEN_MODULE_B );
    
    if (mod_a == TEN_INVALID_MODULE_ID)
	{ 
        printf("Error opening module.\n");
		return (-1);
	}
    else
        printf("Module A initialization: CS_OK.\n");
    
    if (mod_b == TEN_INVALID_MODULE_ID)
	{
		 printf("Error opening module.\n");
		 return (-1);
	}
     else
        printf("Module B initialization: CS_OK.\n");
        
    printf("Read Scratch Pad 1 = %08X\n",ten_mpif_read_scratch_pad1(dev_id));
    printf("Read Scratch Pad 2 = %08X\n",ten_mpif_read_scratch_pad2(dev_id));
    
    printf("Write Scratch Pad 1 0x00DE0\n",ten_mpif_scratch_pad1(dev_id,0x00DE0));
    printf("Write Scratch Pad 1 0x00D1C\n",ten_mpif_scratch_pad2(dev_id,0x00D1C));
    
    printf("Read Scratch Pad 1 = %08X\n",ten_mpif_read_scratch_pad1(dev_id));
    printf("Read Scratch Pad 2 = %08X\n",ten_mpif_read_scratch_pad2(dev_id));
    
    
    
     if(ten_hl_config_global(
            dev_id,                     //Device ID
            TEN_GLOBAL_MODE_S_40G,      //Line Mode
            TEN_GLOBAL_MODE_QUAD_10G,   //Client Mode
            0,                          //mbclksel
            1,                          //Multi-Rate Mode not SFI41 Line
            1                           //Multi-Rate Mode not SFI41 Client
            )!=CS_OK) {
                return -1;
            }
    
    //ten_debug_mpif_dump_settings(dev_id);
    //ten_debug_frac_div_dump_settings(dev_id);
    //ten_debug_dev_dump_settings(dev_id);

    return 0;
}
