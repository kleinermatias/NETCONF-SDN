
#include "prbs_sfi51.h"


int electric;
int port;
int patron;
FILE *fp;

T41_t Chips;

cs_uint16 dev_id;
cs_uint16 module_line;
cs_uint16 module_client;
cs_uint8 dyn_repro;

const char *nombre_programa;

#define SILABS_SLAVE_ADDRESS 0x50
#define SILABS_BUS 0x50

int main (int argc, char **argv)
{
    electric=1;
    port=1;
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
		if(strcmp(argv[1],"cortina") == 0)
		{
			port = (int) strtol(argv[2], NULL, 10);
			
			initialize(port);
		}
		else
		{
			printf("Wrong command. Enter ./prbs_xfi cortina port\n");
		}
	}
	else if(argc == 4)
	{
		if(strcmp(argv[1],"xfp") == 0)
		{
			port = (int) strtol(argv[2], NULL, 10);
			
			loopback = (int) strtol(argv[3], NULL, 10);
			
			if(port == 0xFF) 
			{
				for(i = 0; i <= 3; i++)
				{
					//setup_xfp_module(i, loopback);
				}
			}
			else
			{
				//setup_xfp_module(port, loopback);
			}
		}
		else
		{
			printf("Wrong command. Enter ./prbs_xfi xfp port loopback\n");
		}
	}
	else
	{
		printf("Wrong command\n");
	}
	
    return 0;
}

int setup_xfp_module(int module_id, int loopback)
{
	unsigned int status;
	
	xfp_enable_communication(module_id);
	xfp_power_up(module_id);
	printf("XFI %d Normal Operation: %d\n", module_id, xfp_set_normal_operation(module_id));
        
	xfp_set_data_rate(module_id,0x06);
		
	xfp_get_presence_status(module_id, &status);
			
	if(status == 0)
	{
		printf("XFI %d is present.\n", module_id);
	}
	else
	{
		printf("XFI %d is not present.\n", module_id);
	}
		
    if (loopback) 
	{
		printf("XFI %d Loopback: %d\n", module_id,xfp_set_xfi_loopback(module_id));
    }
	
	return 0;
}

int initialize(int port)
{   
	cs_uint16 status;
	cs_uint8 instance;
	cs_uint8 slice;
	double rate = 10709225320.000000;

    slice = (cs_uint8) port;
	
	printf("Slice: %d\n", slice);
	
	gpio_write_bit(26,1);	//Enable 400 MHz clock
	
    /** 9.4 Initialize the Device Driver */
    
	//Driver instantation
	
	//cs_status ten_drvr_load (void), PAGE 270
	
	print_status("Driver loaded", ten_drvr_load());	//The driver is loaded
	
    ten_drvr_ctl_stats_hex_format(1);

    // Value initialization.
    Chips.mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft;
    Chips.mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;
    dev_id = 0;
    module_line = dev_id << 8;
    module_client = module_client | 1;
    
    int  sysclk_freq;
    int  sysrefclk = 400;	//antes 425
    
    sysclk_freq =  sysrefclk * 1000000;
    sysclk_freq =  sysclk_freq > 200000000 ?  sysclk_freq :  sysclk_freq * 4;

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
	
    /** 9.5 Global Configuration */
	
	//cs_status ten_hl_config_global (cs_uint16 dev_id, cs_uint16 a_mode, cs_uint16 b_mode, cs_uint16 mbclksel, cs_uint16 mr_mode_a_not_sfi41, cs_uint16 mr_mode_b_not_sfi41), PAGE 375

    print_status("ten_hl_config_global", ten_hl_config_global(dev_id, TEN_GLOBAL_MODE_S_40G, TEN_GLOBAL_MODE_QUAD_10G, 1, 1, 1));
	
    //cs_status ten_hl_ohpp_and_shadow_ram_init (cs_uint16 dev_id), PAGE 552
	
	print_status("ten_hl_ohpp_and_shadow_ram_init", ten_hl_ohpp_and_shadow_ram_init(dev_id));

	//cs_status ten_cb_rates (cs_uint16 dev_id, double line_rate, double client_rate), PAGE 734
	
	print_status("ten_cb_rates", ten_cb_rates(dev_id, rate, 0.000000 ));

	//cs_status ten_hl_fracdiv_config (cs_uint16 dev_id, cs_uint16 instance, cs_uint32 sysclk_freq, cs_uint32 desired_freq), PAGE 418

	instance = slice + 4;	//INSTANCE 0-15 Instance =4 para XFP0.
	
    print_status("ten_hl_fracdiv_config 0x04", ten_hl_fracdiv_config( dev_id, 0x04, sysclk_freq, 334663291 ));
    print_status("ten_hl_fracdiv_config 0x05", ten_hl_fracdiv_config( dev_id, 0x05, sysclk_freq, 334663291 ));
    print_status("ten_hl_fracdiv_config 0x06", ten_hl_fracdiv_config( dev_id, 0x06, sysclk_freq, 334663291 ));
    print_status("ten_hl_fracdiv_config 0x07", ten_hl_fracdiv_config( dev_id, 0x07, sysclk_freq, 334663291 ));
	
	
	/** cs_boolean ten_dev_is_ws_in_progress    ( 
                                                cs_uint16 dev_id 
                                             
                                             )   
    
    PAGE 246 */
	
	ten_dev_is_ws_in_progress(dev_id);
    
    
	/** cs_status ten_mpif_rxdiv_cfg0_mode_t41 (
                                                cs_uint16 dev_id
                                                cs_uint8 instance
                                                cs_uint16 mode
                                                ), 
    PAGE 1439 */

    print_status("ten_mpif_rxdiv_cfg0_mode_t41",ten_mpif_rxdiv_cfg0_mode_t41( 0x0, 0x4, 0x0 ));
    
    
    /** cs_status ten_hsif_provision_datapath (
                                                cs_uint16 module_id
                                                cs_uint8 instance
                                                cs_uint16 tx_xfiselect
                                                cs_uint16 rx_xfiselect
                                                cs_uint16 tx_pswtchen
                                                cs_uint16 tx_mrprotocol
                                                cs_uint16 rx_pswtchen
                                                cs_uint16 rx_mrprotocol
                                                )
    * PAGE 1009
    */
    print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath( 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 ));
	
	print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath( 0x1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 ));
	
    
    /** cs_status ten_hsif_set_clk_40g (
                                        cs_uint16 module_id
                                        cs_uint16 select
                                        cs_uint16 value
                                        )
    * PAGE 1025
    */
    print_status("ten_hsif_set_clk_40g", ten_hsif_set_clk_40g( 0x1, 0x1, 0x1 ));
    
    print_status("ten_hsif_set_clk_40g", ten_hsif_set_clk_40g( 0x1, 0x3, 0x1 ));
	
    printf("ten_dev_is_t41: %d\n", ten_dev_is_t41(dev_id));
    
    
    /** cs_status ten_glb_misc_xlos_inv_mr (
                                            cs_uint16 module_id
                                            cs_uint8 slice
                                            cs_uint16 active_low
                                            )
    * PAGE 319 
    */
    print_status("ten_glb_misc_xlos_inv_mr", ten_glb_misc_xlos_inv_mr( 0x1, 0x0, 0x1 ));
    
    /** cs_status ten_hl_config_sfi51 (
                                        cs_uint16 module_id
                                       )

    * PAGE 399
    */
    print_status("ten_hl_config_sfi51", ten_hl_config_sfi51( 0x1 ));
    
    
    printf("ten_dev_is_t41: %d\n", ten_dev_is_t41(dev_id));
    
    
    /** cs_status ten_hl_syncdsync_datapath_config_t41 (
                                                        cs_uint16 module_id_line
                                                        cs_uint8 slice_line
                                                        cs_uint16 module_id_client
                                                        cs_uint8 slice_client
                                                        cs_uint8 fec_line
                                                        cs_uint8 fec_client
                                                        cs_uint8 mode
                                                        cs_uint16 method
                                                        cs_uint8 k_divider
                                                        cs_uint8 map_odtu
                                                        cs_uint8 map_oxuv
                                                        cs_uint8 gmp_timeslots
                                                        )

    PAGE 963
    */
    print_status("ten_hl_syncdsync_datapath_config_t41", ten_hl_syncdsync_datapath_config_t41( 0x1, 0x0, 0x0, 0x0, 0xd, 0x10, 0x1, 0x3, 0x40, 0xff, 0x0, 0x4 ));
    
    
    /** cs_status ten_mpif_global_clock_disable_common (
                                                        cs_uint16 dev_id
                                                        cs_ctl_t ctl
                                                        cs_uint16 bitfield
                                                        )
    PAGE 1354
    */
    print_status("ten_mpif_global_clock_disable_common", ten_mpif_global_clock_disable_common(dev_id, 0x1, 0x1 ));
    
    
    /** cs_status ten_mpif_global_reset_common (
                                                cs_uint16 dev_id
                                                cs_reset_action_t act
                                                cs_uint16
                                                bitfield
                                                )
     
    PAGE 1382
    */
    print_status("ten_mpif_global_reset_common",ten_mpif_global_reset_common( 0x0, 0x0, 0x2 ));

    print_status("ten_mpif_global_reset_common",ten_mpif_global_reset_common( 0x0, 0x0, 0x20 ));

    /** cs_status ten_hl_config_otu3v_kpga_t41 (
                                                cs_uint16 module_id
                                                cs_uint16 traffic_type
                                                cs_uint16 fec
                                                cs_uint16 pattern
                                                cs_uint16 mld
                                                cs_uint16 data_in_stuff_bytes
                                                )
    PAGE 911
    */
    print_status("ten_hl_config_otu3v_kpga_t41",ten_hl_config_otu3v_kpga_t41( 0x1, 0x1, 0xd, 0x3, 0x0, 0x1 ));
    
    
    /** cs_status ten_hsif_set_ok_ctrl (
                                        cs_uint16 module_id
                                        cs_uint8 slice
                                        cs_uint16 select
                                        cs_uint16 value
                                        )
    PAGE 1029
    */
    print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl( 0x1, 0xff, 0x0, 0x0 ));
    
    
    /** cs_status ten_hl_mr_40g_config_clockmux (
                                                cs_uint16 module_id
                                                )
    PAGE 500
    */
    print_status("ten_hl_mr_40g_config_clockmux",ten_hl_mr_40g_config_clockmux( 0x1 ));
    
    /** cs_status ten_mpif_clock_select_gpll_in (
                                                cs_uint16 dev_id
                                                cs_module_t module_num
                                                cs_uint8 slice
                                                cs_dir_t dir
                                                cs_ctl_t select
                                                )
    PAGE 1297
    */
    print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, 0x1, 0xff, 0x0, 0x0 ));
    
    /** cs_status ten_hl_gpllx1_waitfor_gpll_lock_40g (
                                                    cs_uint16 dev_id
                                                    cs_uint8 instance
                                                    )
    PAGE 439
    */
    print_status("ten_hl_gpllx1_waitfor_gpll_lock_40g",ten_hl_gpllx1_waitfor_gpll_lock_40g( 0x0, 0x9 ));
    
    /** cs_status ten_hl_gpllx1_waitfor_gpll_lock_40g_t41 (
                                                            cs_uint16 dev_id
                                                            cs_uint8 module_num
                                                            )

    PAGE 440
    */
    print_status("ten_hl_gpllx1_waitfor_gpll_lock",ten_hl_gpllx1_waitfor_gpll_lock( 0x0, 0x9 ));
    
    
    /** cs_status ten_n40g_set_global_resets (
                                            cs_uint16 module_id
                                            cs_reset_action_t act
                                            cs_uint16 bitfield
                                            )
    PAGE 2480
    */
    print_status("ten_n40g_set_global_resets ",ten_n40g_set_global_resets( 0x1, 0x0, 0x177 ));
    
    
    /** cs_status ten_n10g_set_global_resets (
                                                cs_uint16 module_id
                                                cs_uint8 slice
                                                cs_reset_action_t act
                                                cs_uint16 bitfield
                                                )

    PAGE 1858
    */
    print_status("ten_n40g_set_global_resets 0x00",ten_n10g_set_global_resets( 0x1, 0x0, 0x0, 0x17f ));

    print_status("ten_n40g_set_global_resets 0x01",ten_n10g_set_global_resets( 0x1, 0x1, 0x0, 0x17f ));
    
    print_status("ten_n40g_set_global_resets 0x02",ten_n10g_set_global_resets( 0x1, 0x2, 0x0, 0x17f ));

    print_status("ten_n40g_set_global_resets 0x04",ten_n10g_set_global_resets( 0x1, 0x3, 0x0, 0x17f ));
    
    
    /** cs_status ten_xcon_datapath_reset (
                                        cs_uint16 dev_id
                                        cs_reset_action_t act
                                        )
    
    PAGE 3309
     */
    print_status("ten_xcon_datapath_reset",ten_xcon_datapath_reset( 0x0, 0x0 ));

    
    /**  cs_status ten_xcon_es_reset (
                                        cs_uint16 dev_id
                                        ten_xcon_es_num_t es_num
                                        cs_reset_action_t act
                                        )
    PAGE 3330 
    */
    print_status("ten_xcon_es_reset 0x00",ten_xcon_es_reset( 0x0, 0x0, 0x0 ));
    
    print_status("ten_xcon_es_reset 0x01",ten_xcon_es_reset( 0x0, 0x1, 0x0 ));

    print_status("ten_xcon_es_reset 0x02",ten_xcon_es_reset( 0x0, 0x2, 0x0 ));
    
    print_status("ten_xcon_es_reset 0x03",ten_xcon_es_reset( 0x0, 0x3, 0x0 ));
    
    print_status("ten_xcon_es_reset 0x04",ten_xcon_es_reset( 0x0, 0x4, 0x0 ));

    print_status("ten_xcon_es_reset 0x05",ten_xcon_es_reset( 0x0, 0x5, 0x0 ));
    
    print_status("ten_xcon_es_reset 0x06",ten_xcon_es_reset( 0x0, 0x6, 0x0 ));

    print_status("ten_xcon_es_reset 0x07",ten_xcon_es_reset( 0x0, 0x7, 0x0 ));
    
    
    /** cs_status ten_mpif_global_reset_syncdsync (
                                                    cs_uint16 dev_id
                                                    cs_module_t module_num
                                                    cs_uint8 slice
                                                    cs_dir_t dir
                                                    cs_reset_action_t act
                                                    )

    PAGE 1416
    */
    print_status("ten_mpif_global_reset_syncdsync",ten_mpif_global_reset_syncdsync( 0x0, 0x1, 0xff, 0x2, 0x0 ));
    
    /** cs_status ten_hl_resets_block (
                                        cs_uint16 module_id
                                        cs_uint8 slice
                                        cs_reset_action_t act
                                        cs_uint16 block
                                        )
     PAGE 626 
     */
    print_status("ten_hl_resets_block",ten_hl_resets_block( 0x1, 0x0, 0x0, 0x1 ));

    /** cs_status ten_mpif_set_clock_switch_force (
                                                    cs_uint16 dev_id
                                                    cs_module_t module_num
                                                    cs_uint8 slice
                                                    cs_dir_t dir
                                                    cs_ctl_t ctl
                                                    )
    PAGE 1447
    */
    print_status("ten_mpif_set_clock_switch_force",ten_mpif_set_clock_switch_force( 0x0, 0x1, 0xff, 0x2, 0x0 ));

    /** cs_status ten_mpif_global_reset_hsif (
                                            cs_uint16 dev_id
                                            cs_module_t module_num
                                            cs_dir_t dir
                                            cs_reset_action_t act
                                            )

    PAGE 1392
    */
    print_status("ten_mpif_global_reset_hsif",ten_mpif_global_reset_hsif( 0x0, 0x1, 0x2, 0x0 ));

    /** cs_status ten_hl_gpllx1_waitfor_gpll_lock_40g (
                                                        cs_uint16 dev_id
                                                        cs_uint8 instance
                                                        )

    PAGE 439
    */
    print_status("ten_hl_gpllx1_waitfor_gpll_lock_40g",ten_hl_gpllx1_waitfor_gpll_lock_40g( 0x0, 0x9 ));
    
    
    /** cs_status ten_n40g_sdfr_select_global_timing_source (
                                                            cs_uint16 module_id
                                                            cs_uint16 select
                                                            )
    PAGE 2469
    */
    print_status("ten_n40g_sdfr_select_global_timing_source",ten_n40g_sdfr_select_global_timing_source( 0x1, 0x6 ));

    /** cs_status ten_glb_misc_set_gsti (
                                        cs_uint16 dev_id
                                        cs_uint8 instance
                                        cs_uint16 base1
                                        cs_uint16 base0
                                        )
    PAGE 313
    */
    print_status("ten_glb_misc_set_gsti",ten_glb_misc_set_gsti( 0x0, 0x0, 0x17d7, 0x8400 ));

    //PAGE 1382 Performs a hard reset on the specified selections. The selections that are masked off will not be affected.
    print_status("ten_mpif_global_reset_common",ten_mpif_global_reset_common( 0x0, 0x0, 0x20 ));
    
    
	//get_ber(module_client, port);
    
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
