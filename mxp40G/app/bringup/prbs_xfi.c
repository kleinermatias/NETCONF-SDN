#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include "prbs_xfi.h"
#include "../../lib/xfp/xfp.h"
#include "../../lib/gpio/gpio.h"

int electric;
int port;
int patron;
int prot;
FILE *fp;

cs_uint8 dynrep;

const char *nombre_programa;

#define SILABS_SLAVE_ADDRESS 0x50
#define SILABS_BUS 0x50

/* USE:
prbs_xfi cortina slice[0...3] traffic[0...2] dyn_repro[0, 1] -> Configure KPGA on selected slice for selected traffic (0:OTU2, 1: XGE, 2:OC192). dyn_repro=0 for initial config, dyn_repro=1 for incremental config.

prbs_xfi xfp port[0...3] loopback[0, 1] -> enable selected xfp port, either with electric loopback (loopback=1) or laser activated (loopback=0)
*/

int main (int argc, char **argv)
{
    electric=1;
    port=1;
    prot=0;
    patron = TEN_HSIF_PRBS_PN31;
    const char* const short_opt = "ep:t:" ;
    int next_opt;
	int i;
	int loopback;

    const struct option long_opt[] =
    {
        { "electric", 0, NULL,'e'},
        { "port", 1, NULL,'p'},
        { "test", 1, NULL,'t'},
        {  NULL,  0, NULL, 0 }
    };
    
    open_gpio_files();

    if (argc == 1) 
    {
        
    }
    
	/*
    while (1) 
    {
        
        next_opt = getopt_long (argc, argv, short_opt, long_opt, NULL);
        if (next_opt == -1) break;

        switch (next_opt) {
            
            case 'e': 
                    electric=1;
            break;
            
            case 't': 
                    patron=atoi(optarg);
                    
                    switch(patron) {
                    
                        case 0:
                            patron = TEN_HSIF_PRBS_PN31;
                        break;
                        
                        case 1:
                            patron = TEN_HSIF_PRBS_PN23;
                        break;
                        
                        case 2:
                            patron = TEN_HSIF_PRBS_PN15;
                        break;
                        
                        case 3:
                            patron = TEN_HSIF_PRBS_PN7;
                        break;
                        
                        case 4:
                            patron = TEN_HSIF_PRBS_PN9;
                        break;
                        
                        default:
                            patron = TEN_HSIF_PRBS_PN31;
                        break;
                    
                    }
            break;
        
            case 'p': 
                    
                    port=atoi(optarg);
                    
                    switch(port) {
                    
                        case 0:
                            port =0;
                        break;
                        case 1:
                            port =1;
                        break;
                        case 2:
                            port =2;
                        break;
                        case 3:
                            port =3;
                        break;
                        default:
                            port =0xFF;
                        break;
                    
                    }
            break;
            
            case '?':
                
                    exit(1);
            break;
                    
            case -1:
                   
                    exit(1);
            break;
                    
            default:    
                    abort();
            break;
        }
    }
    */

	if(argc == 2)
	{
		if(strcmp(argv[1],"ber") == 0)
		{
			get_ber(1, port);
		}
		else
		{
			printf("Wrong command. Enter ./prbs_xfi ber\n");
		}
	}

	else if(argc == 3)
	{

		{
			printf("Argument number not valid. Enter either 2 or 4 arguments\n");
		}
	}
/*
		if(strcmp(argv[1],"cortina") == 0)
		{
			dyn_repro = (int) strtol(argv[3], NULL, 10);

			port = (int) strtol(argv[2], NULL, 10);
			
			initialize(port, dyn_repro);
		}
		else
		{
			printf("Wrong command. Enter ./prbs_xfi cortina port\n");
		}
	}
*/

	else if(argc == 4)
	{
		if(strcmp(argv[1],"xfp") == 0)
		{
			port = (int) strtol(argv[2], NULL, 10);
			loopback = (int) strtol(argv[3], NULL, 10);
			
			if(port == 0xFF) 
			{
				for(i = 0; i < 4; i++)
				{
					hl_setup_xfp_module(i, loopback);
					xfp_enable_laser(i);
				}
			}
			else
			{
				hl_setup_xfp_module(port, loopback);
				xfp_enable_laser(port);
			}
		}
		else
		{
			printf("Wrong command. Enter either ./prbs_xfi cortina slice dynrep, or ./prbs_xfi xfp port loopback\n");
		}
	}

	else if(argc == 5)
	{

		if(strcmp(argv[1],"cortina") == 0)
		{
			port = (int) strtol(argv[2], NULL, 10);
			prot = (int) strtol(argv[3], NULL, 10);
			dynrep = (int) strtol(argv[4], NULL, 10);

			initialize(port, prot, dynrep);
		}
	}

	else
	{
		printf("Wrong command\n");
	}

	
	close_gpio_files();

    return 0;
}

int initialize(int port, int prot, int dyn_repro)
{   
	T41_t Chips;

	cs_uint16 dev_id;
	cs_uint16 module_line;
	cs_uint16 module_client;

	cs_uint16 status;
	cs_uint8 instance;
	cs_uint8 slice;

	cs_uint8 prov_line;
	cs_uint8 prov_client;

	double rate_xge = 1031250000.000000; // 10 GbE 7.3
	double rate_otu2 = 10709225320.000000; // OTU2
	double rate_oc192 = 9953280000.000000; // OC192

	double rate_xge_frac = 32226562; // 10 GbE 7.3 (CHECK)
	double rate_otu2_frac = 334663291; // OTU2
	double rate_oc192_frac = 311040000; // OC192 (CHECK)

	int  sysclk_freq;
	int  sysrefclk = 400;	//antes 425

	int traffic = 0;

    slice = (cs_uint8) port;
	
	printf("Slice: %d\n", slice);

	dev_id = 0;
	module_line = dev_id << 8;
	module_client = module_client | 1;

	sysclk_freq =  sysrefclk * 1000000;
	sysclk_freq =  sysclk_freq > 200000000 ?  sysclk_freq :  sysclk_freq * 4;

    prov_line   = dyn_repro != 1;
    prov_client = 1;

	gpio_write_bit(26,1);	//Enable 400 MHz clock

	/** 9.4 Initialize the Device Driver */

	//Driver instantiation
	//cs_status ten_drvr_load (void), PAGE 270
	print_status("Driver loaded", ten_drvr_load());	//The driver is loaded

	ten_drvr_ctl_stats_hex_format(1);

	// Value initialization.
	Chips.mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft;
	Chips.mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;

	//Device registration

	//cs_status ten_dev_register (cs_uint16 dev_id, cs_uint32 base_addr), PAGE 255

	print_status("Device registered", ten_dev_register(dev_id, (cs_uint32)&Chips));

	// Initialize the device driver

	//cs_status ten_dev_main_init (cs_uint16 dev_id), PAGE 247

	print_status("Device init", ten_dev_main_init(dev_id));

	printf("Device Chip Id = %08X\n", ten_mpif_get_chip_jtag_id(dev_id));

	//cs_uint16 ten_mod_main_init (cs_uint16 dev_id, cs_uint8 mod_num), PAGE 281

	module_client = ten_mod_main_init( dev_id, TEN_MODULE_B );
	printf("Module client: %d\n",module_client);

	module_line = ten_mod_main_init( dev_id, TEN_MODULE_A );
	printf("Module line: %d\n",module_line);

	if((dyn_repro==0) || (dyn_repro == 3))
	{
	
	    /** 9.5 Global Configuration */

		//cs_status ten_hl_config_global (cs_uint16 dev_id, cs_uint16 a_mode, cs_uint16 b_mode, cs_uint16 mbclksel, cs_uint16 mr_mode_a_not_sfi41, cs_uint16 mr_mode_b_not_sfi41), PAGE 375
		print_status("ten_hl_config_global", ten_hl_config_global(dev_id, TEN_GLOBAL_MODE_S_40G, TEN_GLOBAL_MODE_QUAD_10G, 1, 1, 1));

		//cs_status ten_hl_ohpp_and_shadow_ram_init (cs_uint16 dev_id), PAGE 552
		print_status("ten_hl_ohpp_and_shadow_ram_init", ten_hl_ohpp_and_shadow_ram_init(dev_id));
	}
	
	printf("Module client: %d\n",module_client);
	printf("Module line: %d\n",module_line);

	//cs_status ten_cb_rates (cs_uint16 dev_id, double line_rate, double client_rate), PAGE 734
	switch(prot)
	{
	case 0: // OTU2
		print_status("ten_cb_rates", ten_cb_rates(dev_id, rate_otu2, 0.000000 ));
		break;
	case 1: // XGE
		print_status("ten_cb_rates", ten_cb_rates(dev_id, rate_xge, 0.000000 ));
		break;
	case 2: // OC192
		print_status("ten_cb_rates", ten_cb_rates(dev_id, rate_oc192, 0.000000 ));
		break;
	default:
		break;
	}
	//cs_status ten_hl_fracdiv_config (cs_uint16 dev_id, cs_uint16 instance, cs_uint32 sysclk_freq, cs_uint32 desired_freq), PAGE 418

	instance = slice + 4;	//INSTANCE 0-15 Instance =4 para XFP0.
	printf("Instance: %d\n", instance);
	switch(prot)
	{
	case 0: // OTU2
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config( dev_id, instance, sysclk_freq, rate_otu2_frac ));
		break;
	case 1: // XGE
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config( dev_id, instance, sysclk_freq, rate_xge_frac ));
		break;
	case 2: // OC192
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config( dev_id, instance, sysclk_freq, rate_oc192_frac ));
		break;
	default:
		break;
	}


	//cs_boolean ten_dev_is_ws_in_progress (cs_uint16 dev_id), PAGE 246
	
	ten_dev_is_ws_in_progress(dev_id);
	
	//cs_status ten_mpif_pilot_div (cs_uint16 dev_id, cs_uint8 instance, cs_uint16 div), PAGE 1430
	
	instance = slice + 4;	//INSTANCE 0-7 Instance =4 para XFP0.
	print_status("ten_mpif_pilot_div", ten_mpif_pilot_div(dev_id, instance, 0x4 )); 	
	printf("Instance: %d\n", instance);
	
	//cs_status ten_mpif_rxdiv_cfg0_pilot_t41 (cs_uint16 dev_id, cs_uint8 instance, cs_uint16 pilot), PAGE 1440
	
	instance = slice + 4;	//INSTANCE 0-7 Instance =4 para XFP0.
	print_status("ten_mpif_rxdiv_cfg0_pilot_t41", ten_mpif_rxdiv_cfg0_pilot_t41(dev_id, instance, 0x4 ));
	printf("Instance: %d\n", instance);
	
	//cs_status ten_mpif_rxdiv_cfg0_mode_t41 (cs_uint16 dev_id,cs_uint8 instance,cs_uint16 mode) PAGE 1439
	
	instance = slice + 4;	//INSTANCE 0-7 Instance =4 para XFP0.
	print_status("ten_mpif_rxdiv_cfg0_mode_t41", ten_mpif_rxdiv_cfg0_mode_t41(dev_id, instance, 0x2 ));
	printf("Instance: %d\n", instance);
	
	//cs_status ten_set_cb_cupll_calc_t41 (cs_uint16 dev_id, double rate, cs_uint8 source, cs_uint16 k_value, cs_uint32 freq, cs_uint32 pdoffset) PAGE 3447
	switch(prot)
	{
	case 0:
		print_status("ten_set_cb_cupll_calc_t41", ten_set_cb_cupll_calc_t41(dev_id, rate_otu2, 0x1, 0x40, sysclk_freq, 0x320 ));
		break;
	case 1:
		print_status("ten_set_cb_cupll_calc_t41", ten_set_cb_cupll_calc_t41(dev_id, rate_xge, 0x1, 0x40, sysclk_freq, 0x320 ));
		break;
	case 2:
		print_status("ten_set_cb_cupll_calc_t41", ten_set_cb_cupll_calc_t41(dev_id, rate_oc192, 0x1, 0x40, sysclk_freq, 0x320 ));
		break;
	default:
		break;
	}
	//cs_status ten_hl_cupll_config_t41 (cs_uint16 module_id, cs_uint8 slice), PAGE 3443
	
	print_status("ten_hl_cupll_config_t41", ten_hl_cupll_config_t41( 0x1, slice));
		
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) )
    {
    	//cs_status ten_hl_cupll_calibrate_config_t41 (cs_uint16 dev_id, cs_uint8 slice), PAGE 3441
		print_status("ten_hl_cupll_calibrate_config_t41", ten_hl_cupll_calibrate_config_t41(dev_id, slice));
    }

	//cs_status ten_xfi_cupll_pdcal_t41 (cs_uint16 module_id, cs_uint8 slice, cs_uint16 pdcalsel, cs_uint16 pdcaloverride), PAGE 1490
	print_status("ten_xfi_cupll_pdcal_t41", ten_xfi_cupll_pdcal_t41( 0x1, slice, 0x0, 0x80 ));

    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) )
    {
		//cs_status ten_hsif_provision_datapath (cs_uint16 module_id, cs_uint8 instance, cs_uint16 tx_xfiselect, cs_uint16 rx_xfiselect, cs_uint16 tx_pswtchen, cs_uint16 tx_mrprotocol, cs_uint16 rx_pswtchen, cs_uint16 rx_mrprotocol), PAGE 1009
		print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath( 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 ));
    }

	print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath( 0x1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 ));
	
    if ( dyn_repro == 0 )
    {
		//cs_boolean ten_dev_is_t41 (cs_uint16 dev_id), PAGE 245
		printf("ten_dev_is_t41: %d\n", ten_dev_is_t41(dev_id));
    }

	//cs_status ten_hsif_set_ok_ctrl (cs_uint16 module_id, cs_uint8 slice, cs_uint16 select, cs_uint16 value), PAGE 1029
    
    print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl( 0x1, 0xff, 0x0, 0x0 ));

	//cs_status ten_hl_config_xfi_t41 (cs_uint16 module_id, cs_uint8 slice, cs_uint16 client, cs_uint16 invert_dir, cs_uint16 invert, cs_uint32 sysclk_freq, cs_uint16 prot, cs_uint16 sync, cs_uint16 aux_clk, cs_uint16 waitfor_vcotune, cs_uint16 div, cs_uint16 clock_distribution, cs_uint16 ext1, cs_uint16 ext2), PAGE 406
	
    switch(prot)
    {
    	case 0: traffic = 5; break; // OTU2
    	case 1: traffic = 12; break; // XGE
    	case 2: traffic = 8; break; // OC192
    	default: break;
    }
	if((slice == 0) || (slice == 2))
	{
		print_status("ten_hl_config_xfi_t41", ten_hl_config_xfi_t41( 0x1, slice, traffic, 0x2, 0x1, sysclk_freq, 0x1, 0x0, 0x0, 0x1, 0x2, 0x1, 0x0, 0x0 ));
	}
	else
	{
		print_status("ten_hl_config_xfi_t41", ten_hl_config_xfi_t41( 0x1, slice, traffic, 0x2, 0x0, sysclk_freq, 0x1, 0x0, 0x0, 0x1, 0x2, 0x1, 0x0, 0x0 ));
	}
	//cs_status ten_xfi32x1_invert (cs_uint16 module_id, cs_uint8 slice, cs_dir_t dir, cs_uint8 invert) PAGE 3474
	
	//if((slice == 0) || (slice == 2))
	//{
	//print_status("ten_xfi32x1_invert", ten_xfi32x1_invert(0x1, slice, 0x2, 0x1));
	//}

	//else
	//{
		//print_status("ten_hl_config_xfi_t41", ten_hl_config_xfi_t41( 0x1, slice, 0x5, 0x2, 0x0, sysclk_freq, 0x1, 0x0, 0x0, 0x1, 0x2, 0x1, 0x0, 0x0 ));
	//}
	
    //cs_boolean ten_dev_is_t41 (cs_uint16 dev_id), PAGE 245
	
    printf("ten_dev_is_t41: %d\n", ten_dev_is_t41(dev_id));
    
	//cs_status ten_hl_syncdsync_datapath_config_t41 (cs_uint16 module_id_line, cs_uint8 slice_line, cs_uint16 module_id_client, cs_uint8 slice_client, cs_uint8 fec_line, cs_uint8 fec_client, cs_uint8 mode, cs_uint16 method, cs_uint8 k_divider, cs_uint8 map_odtu, cs_uint8 map_oxuv, cs_uint8 gmp_timeslots), PAGE 963
	
	//WTF -> slice_line and slice_client
    print_status("ten_hl_syncdsync_datapath_config_t41", ten_hl_syncdsync_datapath_config_t41( 0x1, slice, 0x0, 0x0, 0xd, 0x10, 0x1, 0x3, 0x40, 0xff, 0x0, 0x4 ));
   
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) )
    {
		//cs_status ten_mpif_global_clock_disable_common (cs_uint16 dev_id, cs_ctl_t ctl, cs_uint16 bitfield), PAGE 1354
		print_status("ten_mpif_global_clock_disable_common", ten_mpif_global_clock_disable_common(dev_id, 0x1, 0x1 ));

		//cs_status ten_mpif_global_reset_common (cs_uint16 dev_id, cs_reset_action_t act, cs_uint16 bitfield), PAGE 1382
		print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, 0x0, 0x2 ));
		print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, 0x0, 0x20 ));
    }

	//cs_status ten_hl_config_otu2_kpga (cs_uint16 module_id, cs_uint8 slice, cs_uint16 traffic_type, cs_uint8 dyn_repro, cs_uint16 pattern, cs_uint16 data_in_stuff_bytes), PAGE 881
	
    switch(prot)
    {
    case 0: // OTU2
    	print_status("ten_hl_config_otu2_kpga", ten_hl_config_otu2_kpga( 0x1, slice, 0x5, dyn_repro, 0x3, 0x1 ));
    	break;
    case 1: // XGE
    	print_status("ten_hl_config_10g_cbr_kpga_t41", ten_hl_config_10g_cbr_kpga_t41( 0x1, slice, 0x3, dyn_repro )); // CHECK!
    	break;
    case 2: // OC192
    	print_status("ten_hl_config_oc192_kpga", ten_hl_config_oc192_kpga( 0x1, slice, dyn_repro, 0x3 ));
    	break;
    default:
    	break;
    }

	//cs_status ten_hl_config_fec_t41 (cs_uint16 module_id, cs_uint8 slice, cs_uint16 size, cs_uint16 overhead), PAGE 188
	
    print_status("ten_hl_config_fec_t41", ten_hl_config_fec_t41( 0x1, slice, 0x0, 0xd ));
    
    //cs_status ten_hl_n10g_config_lof_from_traffic (cs_uint16 module_id, cs_uint8 slice, cs_uint16 traffic_type, cs_uint16 fec), PAGE 945
	
    print_status("ten_hl_n10g_config_lof_from_traffic", ten_hl_n10g_config_lof_from_traffic( 0x1, slice, 0x5, 0xd ));
	
	//cs_status ten_hl_n10g_config_lom_from_traffic (cs_uint16 module_id, cs_uint8 slice, cs_uint16 traffic_type, cs_uint16 fec), PAGE 948
	
	print_status("ten_hl_n10g_config_lom_from_traffic", ten_hl_n10g_config_lom_from_traffic( 0x1, slice, 0x5, 0xd ));
    
	//cs_status ten_hsif_set_ok_ctrl (cs_uint16 module_id, cs_uint8 slice, cs_uint16 select, cs_uint16 value) PAGE 1029
	
    print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl( 0x1, slice, 0x0, 0x0 ));
	
    //cs_status ten_hl_xfi_config_clockmux_t41 (cs_uint16 module_id, cs_uint8 slice, cs_uint16 aux_clk, cs_uint16 k_value, cs_uint16 stxp_pilot_sel, cs_uint16 cupll_in_use), PAGE 685

	print_status("ten_hl_xfi_config_clockmux_t41", ten_hl_xfi_config_clockmux_t41( 0x1, slice, 0x0, 0x40, 0x1, 0x1 ));
    
	//cs_status ten_mpif_clock_select_gpll_in (cs_uint16 dev_id, cs_module_t module_num, cs_uint8 slice, cs_dir_t dir, cs_ctl_t select), PAGE 1297
	
	print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, 0x1, slice, 0x0, 0x0 ));
	
	//cs_status ten_hl_gpllx1_waitfor_gpll_lock (cs_uint16 dev_id, cs_uint8 instance), PAGE 438
    
	instance = slice + 9;	//9 + slice' for Module B.
	
    print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock(dev_id, instance));
    printf("Instance: %d\n", instance);
	
    print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock(dev_id, instance));
    printf("Instance: %d\n", instance);
	
//    print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback( module_client, TEN_SLICE0, TEN_HSIF_LOOPBACK_FACILITY_XFI, CS_ENABLE ));

    //cs_status ten_hl_config_remove_module_soft_resets (cs_uint16 module_id, cs_uint8 slice, cs_uint16 line), PAGE 385
	
	print_status("ten_hl_config_remove_module_soft_resets", ten_hl_config_remove_module_soft_resets( 0x1, slice, traffic ));
    
	//cs_status ten_mpif_set_clock_switch_force (cs_uint16 dev_id, cs_module_t module_num, cs_uint8 slice, cs_dir_t dir, cs_ctl_t ctl), PAGE 1447
	
    print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force( dev_id, 0x1, slice, 0x2, 0x0 ));
    
	//cs_status ten_mpif_global_reset_hsif (cs_uint16 dev_id, cs_module_t module_num, cs_dir_t dir, cs_reset_action_t act), PAGE 1392
	
    print_status("ten_mpif_global_reset_hsif", ten_mpif_global_reset_hsif(dev_id, 0x1, 0x2, 0x0 ));
    
	//cs_uint16 ten_reg_read (cs_uint16 dev_id, cs_uint32 reg_offset)
    
    //printf("ten_reg_read(0x0, 0x15098)", ten_reg_read(dev_id, 0x15098 )); // CAMBIAR PRINT, DEVUELVE EL REG DIRECTO
    
    
    
//	get_ber(module_client, port);
    
	return 0;

}

void get_ber(cs_uint16 module_client, int port)
{
	int check; 
	int i;
	int j;
	int log = 0;
	
	if(log)
	{
		fp = fopen ( "/var/log/rsyslog/ber_xfi.txt", "a" ); 
	   
		if (fp==NULL) 
		{
			fputs ("File error",stderr); 
			exit (1);
		}
	}
   
   for(j = 0; j < 5; j ++)
	{
		if (port == 0xFF) 
		{
			for(i = 0; i <= 3; i ++)
			{
				fprintf(fp, "PRBS CHK %d: %d\n" , i, ten_xfi32x1_prbschk_get_status(module_client,i));
				printf("PRBS CHK %d: %d\n", i, ten_xfi32x1_prbschk_get_status(module_client,i));
			}
		}
		else 
		{
			check = ten_xfi32x1_prbschk_get_status(module_client,port);
            //fprintf(fp, "PRBS CHK %d: %d\n" ,port,check);
            printf("PRBS CHK %d: %d\n" ,port,check);
		}
		sleep(1);
		//ten_xfi32x1_prbsgen_control(module_client,0xFF,1,0,0,0);
	}
   
	if(log)
	{
		fclose ( fp );
	}
}
