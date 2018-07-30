#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../../lib/gpio/gpio.h"
#include "../../lib/txp/txp.h"
#include "cortinaLoopbackOclaroPrbs.h"
#include "../../lib/clk/clk.h"
#include "../../lib/silabs/silabs.h"

int main (int argc, char **argv)
{
//	clock_t start, end;
//	double cpu_time_used;
//	start = clock();

	time_t start, end;
	struct tm *ts_start;
	char buffer_start[80];
    struct tm *ts_end;
    char buffer_end[80];

    start = time(0);

	open_gpio_files();

	clk_set_osc_684_28_mhz(1);
	usleep(250000);
	clk_set_osc_400_mhz(1);
	usleep(250000);
	clk_set_mux_a(1);
	usleep(250000);
	gpio_write_bit(MOD_40G_LATCH_ENABLE,1);
	usleep(250000);
	gpio_write_bit(MOD_40G_LS_ENABLE_LATCH,1);
	usleep(250000);
	clk_set_mux_b(1);
	usleep(250000);

	/* NORMAL OPERATION */

	gpio_write_bit(MOD_40G_MOD_RESET_LATCH, 0);
	usleep(250000);
	gpio_write_bit(MOD_40G_REG_RESET_LATCH, 0);



	if(argc == 2)
	{
		if(strcmp(argv[1],"alarm") == 0)
		{
			/*Leer registro en módulo 40g de Oclaro*/

			union rx_alarm_status rx_alarm;
			read_rx_alarm_status_register(&rx_alarm);

			union tx_alarm_status tx_alarm;
			read_tx_alarm_status_register(&tx_alarm);

			unsigned short error_count;
			read_error_checker_error_count(&error_count);

			union error_prbs_counters_union prbs_counters;

			read_prbs_error_counters(4, &prbs_counters);
			read_prbs_error_counters(5, &prbs_counters);
			read_prbs_error_counters(6, &prbs_counters);
		}

		else if(strcmp(argv[1],"cortina_lock") == 0)
		{
			T41_t Chips;
			cs_uint16 dev_id;
			cs_uint16 i;
			cs_uint16 module_a_id;
			cs_uint16 module_b_id;

			/** 9.4 Initialize the Device Driver */

			//cs_status ten_drvr_load (void), PAGE 270
			print_status("Driver loaded", ten_drvr_load());

		    ten_drvr_ctl_stats_hex_format(1);

		    // Value initialization.
			Chips.mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft;
			Chips.mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;
			dev_id = 0;

			int  sysclk_freq;
			int  sysrefclk = 400;

			sysclk_freq =  sysrefclk * 1000000;
			sysclk_freq =  sysclk_freq > 200000000 ?  sysclk_freq :  sysclk_freq * 4;

			//Device registration

			//cs_status ten_dev_register (cs_uint16 dev_id, cs_uint32 base_addr), PAGE 255
			print_status("Device registered", ten_dev_register(dev_id, (cs_uint32)&Chips));

			//cs_boolean ten_dev_is_ws_in_progress (cs_uint16 dev_id) PAGE 246
			for(i = 0; i < 6; i++)
			{
				print_status("Warm Start is active currently", ten_dev_is_ws_in_progress( dev_id ));
			}

			//cs_status ten_dev_main_init (cs_uint16 dev_id), PAGE 247
			print_status("Device init", ten_dev_main_init(dev_id));

			//cs_uint16 ten_mod_main_init (cs_uint16 dev_id, cs_uint8 mod_num), PAGE 281
			module_a_id = ten_mod_main_init( dev_id, TEN_MODULE_A);
			printf("ten_mod_main_init (Module A): %d\n", module_a_id);

			module_b_id = ten_mod_main_init( dev_id, TEN_MODULE_B);
			printf("ten_mod_main_init (Module B): %d\n", module_b_id);

			print_status("ten_hl_gpllx1_waitfor_gpll_lock_40g", ten_hl_gpllx1_waitfor_gpll_lock_40g( dev_id, 0x1 ));
			print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock( dev_id, 0x1 ));
		}

		else
		{
			union tx_command_reg_union tx_command_register_write;
			read_tx_command_register(&tx_command_register_write);

			/*TX REGISTER DEFAULT VALUES */
			tx_command_register_write.fields.prbsen 		=1;
			tx_command_register_write.fields.prbspat0		=1;
			tx_command_register_write.fields.prbspat1		=1;
			tx_command_register_write.fields.txdeskewen 	=1;
//			tx_command_register_write.fields.txdcksel 		=0;
			tx_command_register_write.fields.txlinetimsel	=1;
			tx_command_register_write.fields.txlloopenb 	=1;
			tx_command_register_write.fields.txreset		=1;
			tx_command_register_write.fields.txfifores		=1;
			tx_command_register_write.fields.autotxfifores	=1;
			tx_command_register_write.fields.sctxreset 		=1;
			tx_command_register_write.fields.txmutemonclk 	=1;
			tx_command_register_write.fields.lsenable 		=0;
			tx_command_register_write.fields.txratesel0 	=0;
			tx_command_register_write.fields.txratesel1 	=1;
			tx_command_register_write.fields.txrefsel 		=0;
//			tx_command_register_write.fields.TxSRCCKSEL 	=1;

			set_tx_command_register(&tx_command_register_write);

			/*Generator PRBS enable en módulo 40g de Oclaro*/
			tx_command_register_write.fields.txlinetimsel	=1;
//			tx_command_register_write.fields.txlloopenb 	=0;
			tx_command_register_write.fields.prbsen 		=0;
			tx_command_register_write.fields.prbspat0		=1;
			tx_command_register_write.fields.prbspat1		=1;

			set_tx_command_register(&tx_command_register_write);
			read_tx_command_register(&tx_command_register_write);

			union rx_command_reg_union data_rx;
			read_rx_command_register(&data_rx);

			/*RX REGISTER - VALORES POR DEFAULT*/
			data_rx.fields.rxmute		=1;
			data_rx.fields.rxdloopenb  	=1;
			data_rx.fields.scrxreset	=1;
			data_rx.fields.prbsen		=1;
			data_rx.fields.prbspat0		=1;
			data_rx.fields.prbspat1		=1;
			data_rx.fields.rxratesel0	=0;
			data_rx.fields.rxratesel1	=1;
			data_rx.fields.rxrefsel		=0;
			data_rx.fields.rxlckref		=1;
			data_rx.fields.rxmonclksel	=0;
			data_rx.fields.rxreset		=1;
			data_rx.fields.rxmuterxdck	=1;
			data_rx.fields.rxmutemonclk	=1;

			set_rx_command_register(&data_rx);
			read_rx_command_register(&data_rx);

			/*Checker PRBS enable en módulo 40g de Oclaro*/
			data_rx.fields.rxdloopenb  	=0;
			data_rx.fields.prbsen		=0;
			data_rx.fields.prbspat0		=1;
			data_rx.fields.prbspat1		=1;

			set_rx_command_register(&data_rx);
			read_rx_command_register(&data_rx);

			/*Configuración silabs*/

			silabs_config(1, argv[1]);
			printf("The silabs #1 was configured\n");

			/*Configuración loopback en Cortina*/

			reset();

			sfi51_40g_kpga();

			close_gpio_files();
		}
	}

//	end = clock();

//	printf("\n start: %ld\n", start);
//	printf(" end: %ld\n", end);

//	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
//	printf("\n cpu_time_used: %f seconds to execute. \n", cpu_time_used);

	ts_start = localtime(&start);
    strftime(buffer_start, sizeof(buffer_start), "\n start:\t %a %Y-%m-%d %H:%M:%S %Z \t", ts_start);
    printf("%s\n", buffer_start);

    end = time(0);

    ts_end = localtime(&end);
    strftime(buffer_end, sizeof(buffer_end), " end:\t %a %Y-%m-%d %H:%M:%S %Z \n", ts_end);
    printf("%s\n", buffer_end);

	if(argc == 3 && strcmp(argv[2],"clk_config") == 0)
	{
		silabs_config(1, argv[1]);
		printf("\n The silabs #1 was re-configured. \n");
	}

	return 0;
}

void sfi51_40g_kpga()
{
	T41_t Chips;
	cs_uint16 dev_id;
	cs_uint16 i;
	cs_uint16 module_a_id;
	cs_uint16 module_b_id;

    /** 9.4 Initialize the Device Driver */

	//cs_status ten_drvr_load (void), PAGE 270

	print_status("Driver loaded", ten_drvr_load());	//The driver is loaded

    ten_drvr_ctl_stats_hex_format(1);

//	ten_drvr_ctl_logging(CS_LOG_DELAYS_ONLY);

    // Value initialization.
    Chips.mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft;
    Chips.mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;
    dev_id = 0;

    int  sysclk_freq;
    int  sysrefclk = 400;	//antes 425

    sysclk_freq =  sysrefclk * 1000000;
    sysclk_freq =  sysclk_freq > 200000000 ?  sysclk_freq :  sysclk_freq * 4;

    //Device registration

	//cs_status ten_dev_register (cs_uint16 dev_id, cs_uint32 base_addr), PAGE 255

	print_status("Device registered", ten_dev_register(dev_id, (cs_uint32)&Chips));

	//cs_boolean ten_dev_is_ws_in_progress (cs_uint16 dev_id) PAGE 246

	for(i = 0; i < 6; i++)
	{
		print_status("Warm Start is active currently", ten_dev_is_ws_in_progress( dev_id ));
	}

	//cs_status ten_dev_main_init (cs_uint16 dev_id), PAGE 247

	print_status("Device init", ten_dev_main_init(dev_id));

	//cs_uint16 ten_mod_main_init (cs_uint16 dev_id, cs_uint8 mod_num), PAGE 281

	module_a_id = ten_mod_main_init( dev_id, TEN_MODULE_A);
	printf("ten_mod_main_init (Module A): %d\n", module_a_id);

	module_b_id = ten_mod_main_init( dev_id, TEN_MODULE_B);
	printf("ten_mod_main_init (Module B): %d\n", module_b_id);

	//cs_status ten_hl_config_global (cs_uint16 dev_id, cs_uint16 a_mode, cs_uint16 b_mode, cs_uint16 mbclksel, cs_uint16 mr_mode_a_not_sfi41, cs_uint16 mr_mode_b_not_sfi41), PAGE 375

	print_status("ten_hl_config_global", ten_hl_config_global(dev_id, TEN_GLOBAL_MODE_S_40G, TEN_GLOBAL_MODE_QUAD_10G, 0x1, 0x1, 0x1));

	//cs_status ten_hl_ohpp_and_shadow_ram_init (cs_uint16 dev_id), PAGE 552

	print_status("ten_hl_ohpp_and_shadow_ram_init", ten_hl_ohpp_and_shadow_ram_init(dev_id));

	//cs_status ten_cb_rates (cs_uint16 dev_id, double line_rate, double client_rate), PAGE 734
	//print_status("ten_cb_rates", ten_cb_rates(dev_id, 43793920000.000000, 0.000000 ));
	print_status("ten_cb_rates", ten_cb_rates(dev_id, 43018413560.000000, 0.000000 ));

	//cs_status ten_hl_fracdiv_config (cs_uint16 dev_id, cs_uint16 instance, cs_uint32 sysclk_freq, cs_uint32 desired_freq), PAGE 418
	for(i = 0; i < 4; i++)
	{
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config( dev_id, i, sysclk_freq, (2*168040678) ));
		//print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config( dev_id, i, sysclk_freq, (2*171070000) ));
	}

	print_status("Warm Start is active currently", ten_dev_is_ws_in_progress( dev_id ));

	//Sets the source selection for RXi_DIV output
	//cs_status ten_mpif_rxdiv_cfg0_mode_t41 (cs_uint16 dev_id,cs_uint8 instance,cs_uint16 mode) PAGE 1439
	print_status("ten_mpif_rxdiv_cfg0_mode_t41", ten_mpif_rxdiv_cfg0_mode_t41(dev_id, TEN_SLICE0, 0x0 ));

	//Configure the line protocol for each slice.
	//cs_status ten_hsif_provision_datapath (cs_uint16 module_id, cs_uint8 instance, cs_uint16 tx_xfiselect, cs_uint16 rx_xfiselect, cs_uint16 tx_pswtchen, cs_uint16 tx_mrprotocol, cs_uint16 rx_pswtchen, cs_uint16 rx_mrprotocol), PAGE 1009
	print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath( module_a_id, TEN_INSTANCE_ALL, 0x0, 0x0, 0x0, 0x1, 0x0, 0x1 )); //Cambio que hace lock
	print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath( module_b_id, TEN_INSTANCE_ALL, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 ));

	//Configure the serdes clock to be used for 40G.
	//cs_status ten_hsif_set_clk_40g (cs_uint16 module_id,cs_uint16 select,cs_uint16 value) PAGE 1025
	print_status("ten_hsif_set_clk_40g", ten_hsif_set_clk_40g( module_a_id, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1 ));
	print_status("ten_hsif_set_clk_40g", ten_hsif_set_clk_40g( module_a_id, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1 ));

	//cs_boolean ten_dev_is_t41 (cs_uint16 dev_id), PAGE 245
	printf("ten_dev_is_t41: %d\n", ten_dev_is_t41(dev_id));

	//Sets external LOS Filter input polarity configuration MR XLOS
	//cs_status ten_glb_misc_xlos_inv_mr (cs_uint16 module_id,cs_uint8 slice,cs_uint16 active_low) PAGE 319
	print_status("ten_glb_misc_xlos_inv_mr", ten_glb_misc_xlos_inv_mr( module_a_id, TEN_SLICE0, 0x0 ));

	//cs_status ten_hl_config_sfi51 (cs_uint16 module_id) PAGE 399
	print_status("ten_hl_config_sfi51", ten_hl_config_sfi51( module_a_id ));

	//cs_boolean ten_dev_is_t41 (cs_uint16 dev_id), PAGE 245
	printf("ten_dev_is_t41: %d\n", ten_dev_is_t41(dev_id));

	//Configures line and client syncdsync blocks based on mode and method
	//cs_status ten_hl_syncdsync_datapath_config_t41 (cs_uint16 module_id_line, cs_uint8 slice_line, cs_uint16 module_id_client, cs_uint8 slice_client, cs_uint8 fec_line, cs_uint8 fec_client, cs_uint8 mode, cs_uint16 method, cs_uint8 k_divider, cs_uint8 map_odtu, cs_uint8 map_oxuv, cs_uint8 gmp_timeslots), PAGE 963
	print_status("ten_hl_syncdsync_datapath_config_t41", ten_hl_syncdsync_datapath_config_t41( module_a_id, TEN_SLICE0, module_b_id, 0x0, 0xd, 0x10, TEN_40G_MUXPONDER, 0x3, 0x40, 0xff, 0x0, 0x4 ));

	//Control disabling of the clock to the specified (masked on) blocks in the CS600X device. The blocks that have clock
	//disable set to CS_DISABLE are inaccessible from the microprocessor port. After the clock disable to a block is written from
	//CS_DISABLE to CS_ENABLE, the software reset APIs should be used to reset that affected block.
	//cs_status ten_mpif_global_clock_disable_common (cs_uint16 dev_id, cs_ctl_t ctl, cs_uint16 bitfield), PAGE 1354
	print_status("ten_mpif_global_clock_disable_common", ten_mpif_global_clock_disable_common(dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON));

	//Performs a hard reset on the specified selections. The selections that are masked off will not be affected.
	//cs_status ten_mpif_global_reset_common (cs_uint16 dev_id, cs_reset_action_t act, cs_uint16 bitfield), PAGE 1382
	print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON ));

	print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS ));

	//Provision an OC768 KPGA tester. The tester will see B3 errors because of a problem with the T40 chip.
	//cs_status ten_hl_config_otu3v_kpga_t41 (cs_uint16 module_id,cs_uint16 traffic_type,cs_uint16 fec,cs_uint16 pattern,cs_uint16 mld,cs_uint16 data_in_stuff_bytes) PAGE 911
//	print_status("ten_hl_config_otu3v_kpga_t41", ten_hl_config_otu3v_kpga_t41( module_a_id, TEN_TRAFFIC_TYPE_OTU3, 0xd, TEN_KPG_PN31, 0x0, 0x1 ));

//	printf("ten_hl_config_40g_hsif_kpga", ten_hl_config_40g_hsif_kpga(module_a_id, TEN_HSIF_PROTOCOL_SFI51, 0, TEN_HSIF_PRBS_PN31));

	print_status("ten_hl_config_otu3_kpga", ten_hl_config_otu3_kpga(module_a_id, TEN_TRAFFIC_TYPE_OTU3, TEN_KPG_PN31, 0));

	//Controls the OK signals sent to PP10G/N40G
	//cs_status ten_hsif_set_ok_ctrl (cs_uint16 module_id, cs_uint8 slice, cs_uint16 select, cs_uint16 value) PAGE 1029
	print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl( module_a_id, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0x0 ));

	//Configure the CLOCKMUX for a 40G multi-rate interface, i.e., SFI-5.1 or 16-lane SFI-4.2
	//cs_status ten_hl_mr_40g_config_clockmux (cs_uint16 module_id) PAGE 500
	print_status("ten_hl_mr_40g_config_clockmux", ten_hl_mr_40g_config_clockmux( module_a_id ));

	//Select between the HSIF output clocks. This is the 1st stage of top level clock muxing.
	//cs_status ten_mpif_clock_select_gpll_in (cs_uint16 dev_id, cs_module_t module_num, cs_uint8 slice, cs_dir_t dir, cs_ctl_t select), PAGE 1297
	print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, TEN_MODULE_A, TEN_SLICE_ALL, CS_TX, 0x0 ));

	//cs_status ten_hl_gpllx1_waitfor_gpll_lock_40g (cs_uint16 dev_id,cs_uint8 instance) PAGE 439

	print_status("ten_hl_gpllx1_waitfor_gpll_lock_40g", ten_hl_gpllx1_waitfor_gpll_lock_40g( dev_id, 0x1 ));

	//cs_status ten_hl_gpllx1_waitfor_gpll_lock (cs_uint16 dev_id,cs_uint8 instance) PAGE 438

	print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock( dev_id, 0x1 ));

	//cs_status ten_hl_hsif_control_loopback(cs_uint16 module_id, cs_uint8 slice, cs_uint8 loopback, cs_ctl_t ctl);

	print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback( module_a_id, TEN_SLICE_ALL, TEN_HSIF_LOOPBACK_MR_RX2TX, CS_ENABLE ));

	//cs_status ten_n40g_set_global_resets (cs_uint16 module_id,cs_reset_action_t act,cs_uint16 bitfield) PAGE 2480

	print_status("ten_n40g_set_global_resets", ten_n40g_set_global_resets( module_a_id, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL ));

	//cs_status ten_n10g_set_global_resets (cs_uint16 module_id,cs_uint8 slice,cs_reset_action_t act,cs_uint16 bitfield) PAGE 1858

	print_status("ten_n10g_set_global_resets", ten_n10g_set_global_resets( module_a_id, TEN_SLICE0, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL ));
	print_status("ten_n10g_set_global_resets", ten_n10g_set_global_resets( module_a_id, TEN_SLICE1, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL ));
	print_status("ten_n10g_set_global_resets", ten_n10g_set_global_resets( module_a_id, TEN_SLICE2, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL ));
	print_status("ten_n10g_set_global_resets", ten_n10g_set_global_resets( module_a_id, TEN_SLICE3, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL ));

	//cs_status ten_xcon_datapath_reset (cs_uint16 dev_id,cs_reset_action_t act) PAGE 3309

	print_status("ten_xcon_datapath_reset", ten_xcon_datapath_reset( dev_id, CS_RESET_DEASSERT ));

	//cs_status ten_xcon_es_reset (cs_uint16 dev_id,ten_xcon_es_num_t es_num,cs_reset_action_t act) PAGE 3330

	print_status("ten_xcon_es_reset", ten_xcon_es_reset( dev_id, 0x0, 0x0 ));
	print_status("ten_xcon_es_reset", ten_xcon_es_reset( dev_id, 0x1, 0x0 ));
	print_status("ten_xcon_es_reset", ten_xcon_es_reset( dev_id, 0x2, 0x0 ));
	print_status("ten_xcon_es_reset", ten_xcon_es_reset( dev_id, 0x3, 0x0 ));
	print_status("ten_xcon_es_reset", ten_xcon_es_reset( dev_id, 0x4, 0x0 ));
	print_status("ten_xcon_es_reset", ten_xcon_es_reset( dev_id, 0x5, 0x0 ));
	print_status("ten_xcon_es_reset", ten_xcon_es_reset( dev_id, 0x6, 0x0 ));
	print_status("ten_xcon_es_reset", ten_xcon_es_reset( dev_id, 0x7, 0x0 ));

	//cs_status ten_mpif_global_reset_syncdsync (cs_uint16 dev_id,cs_module_t module_num,cs_uint8 slice,cs_dir_t dir,cs_reset_action_t act) PAGE 1416

	print_status("ten_mpif_global_reset_syncdsync", ten_mpif_global_reset_syncdsync( dev_id, TEN_MODULE_A, TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_DEASSERT ));

	//cs_status ten_hl_resets_block (cs_uint16 module_id,cs_uint8 slice,cs_reset_action_t act,cs_uint16 block) PAGE 625

	print_status("ten_hl_resets_block", ten_hl_resets_block( module_a_id, TEN_SLICE0, CS_RESET_DEASSERT, TEN_HL_RESETS_BLOCK_SYNCDSYNC ));

	//cs_status ten_mpif_set_clock_switch_force (cs_uint16 dev_id,cs_module_t module_num,cs_uint8 slice,cs_dir_t dir,cs_ctl_t ctl) PAGE 1447

	print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force( dev_id, TEN_MODULE_A, TEN_SLICE_ALL, CS_TX_AND_RX, 0x0 ));

	//cs_status ten_mpif_global_reset_hsif (cs_uint16 dev_id, cs_module_t module_num, cs_dir_t dir, cs_reset_action_t act), PAGE 1392

	print_status("ten_mpif_global_reset_hsif", ten_mpif_global_reset_hsif(dev_id, TEN_MODULE_A, CS_TX_AND_RX, 0x0 ));

	//cs_status ten_hl_gpllx1_waitfor_gpll_lock_40g (cs_uint16 dev_id,cs_uint8 instance) PAGE 439

	print_status("ten_hl_gpllx1_waitfor_gpll_lock_40g", ten_hl_gpllx1_waitfor_gpll_lock_40g( dev_id, 0x1 ));

	//cs_status ten_n40g_sdfr_select_global_timing_source (cs_uint16 module_id,cs_uint16 select) PAGE 2469

	print_status("ten_n40g_sdfr_select_global_timing_source", ten_n40g_sdfr_select_global_timing_source( module_a_id, 0x6 ));

	//cs_status ten_glb_misc_set_gsti (cs_uint16 dev_id,cs_uint8 instance,cs_uint16 base1,cs_uint16 base0) PAGE 313

	print_status("ten_glb_misc_set_gsti", ten_glb_misc_set_gsti( dev_id, 0x0, 0x17d7, 0x8400 ));

	//cs_status ten_mpif_global_reset_common (cs_uint16 dev_id, cs_reset_action_t act, cs_uint16 bitfield), PAGE 1382

	print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, 0x20 ));
}
