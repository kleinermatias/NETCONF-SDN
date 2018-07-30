#include "transponder.h"

#define SILABS_SLAVE_ADDRESS 0x50
#define SILABS_BUS 0x50

int main(int argc, char **argv)
{

	clk_set_osc_400_mhz(1);
	clk_set_osc_684_28_mhz(1);
	clk_set_mux_a(0);
	clk_set_mux_b(1);

	// Silabs #2 configuration 162Mhz
    char *silabs_congif_file = "out1_162_Mhz_out2_162_Mhz.txt";
    silabs_config(2, silabs_congif_file);

    // Open GPIO Files to boost read/write transactions against Cortina's Chip
	open_upie();

	int next_opt;
	int i;
	int loopback;
	int traffic[4];
	int console_output = 0;

	if (argc == 1)
	{
		printf("Wrong argument count.\n");
	}
	else if (argc == 2)
	{
		if (strcmp(argv[1], "config") == 0)
		{
			T41_t Chips;
			cs_uint16 dev_id = 0;
			cs_uint16 mod_a;
			cs_uint16 mod_b;

			int sysclk_freq;
			int sysrefclk = 400;

			sysclk_freq = sysrefclk * 1000000;

			clk_set_osc_400_mhz(1);
			clk_set_osc_684_28_mhz(1);
			clk_set_mux_a(0);
			clk_set_mux_b(1);

			open_gpio_files();

			cs6041_init(0, &Chips, &mod_a, &mod_b);

			initialize(0, mod_a, mod_b, sysclk_freq);
		}
		else
		{
			printf("Wrong command.\n");
		}
	}
	else if (argc == 3)
	{

	}
	else if (argc == 4)
	{

	}

	// Close GPIO Files
	close_upie();

	return 0;
}

void initialize(cs_uint16 dev_id, cs_uint16 mod_a, cs_uint16 mod_b, cs_uint32 sysclk_freq)
{
	cs_uint16 fracdiv_module;
	cs_uint8 fracdiv_slice;

	cs_uint8 slice_line = 0;
	cs_uint8 slice_client = 0;

	cs_uint8 inst;
	cs_uint8 gpllx1_inst_line;
	cs_uint8 gpllx1_inst_client;

	cs_uint16 mod_line = (mod_a) | 0;
	cs_uint16 mod_client = (mod_b) | 1;

	print_status("ten_hl_config_global", ten_hl_config_global(dev_id, TEN_GLOBAL_MODE_S_40G, TEN_GLOBAL_MODE_S_40G, 1, 1, 1));

	print_status("ten_hl_ohpp_and_shadow_ram_init", ten_hl_ohpp_and_shadow_ram_init(dev_id));

	print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX, 0));

	print_status("ten_hl_hsif_power_down_serdes", ten_hl_hsif_power_down_serdes(mod_a));

	print_status("ten_hl_hsif_power_down_serdes", ten_hl_hsif_power_down_serdes(mod_b));

	/* This will enable logging
	 ten_drvr_ctl_logging (CS_ENABLE);
	 */

	print_status("ten_cb_rates", ten_cb_rates(dev_id, 43793920000.0, 43793920000.0)); //684.28 Mhz * 16 * 4

	fracdiv_module = mod_line;
	fracdiv_slice = slice_line;
	inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice : fracdiv_slice + 4;

	//LINE
	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 0, sysclk_freq, 342140000));
	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 1, sysclk_freq, 342140000));
	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 2, sysclk_freq, 342140000));
	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 3, sysclk_freq, 342140000));

	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 4, sysclk_freq, 342140000));
	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 5, sysclk_freq, 342140000));
	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 6, sysclk_freq, 342140000));
	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 7, sysclk_freq, 342140000));

	//CLIENT ------------------------------------------
	fracdiv_module = mod_line;
	fracdiv_slice = slice_client;
	inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice + 8 : fracdiv_slice + 12;

	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, inst, sysclk_freq, 9802025));

	print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX, CS_ENABLE));

//	fracdiv_module = mod_client;
//	fracdiv_slice = slice_client;
//	inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice : fracdiv_slice + 4;
//
//	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, inst, sysclk_freq, 334663291));

	fracdiv_module = mod_client;
	fracdiv_slice = slice_client;

	inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice + 8 : fracdiv_slice + 12;

	print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, inst, sysclk_freq, 10458227));

	print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX, CS_ENABLE));

	//-------------------------------------------------

	print_status("ten_mpif_global_reset_sds_xfi_mpif", ten_mpif_global_reset_sds_xfi_mpif(dev_id, slice_client, CS_RESET_TOGGLE));

	print_status("ten_mpif_rxdiv_cfg0_mode_t41", ten_mpif_rxdiv_cfg0_mode_t41(dev_id, mod_line * 4 + slice_line, 0x0));
	TEN_MDELAY(5000);

	print_status("ten_mpif_rxdiv_cfg0_mode_t41", ten_mpif_rxdiv_cfg0_mode_t41(dev_id, mod_client * 4 + slice_client, 0));
	TEN_MDELAY(5000);

	print_status("ten_set_cb_cupll_calc_t41", ten_set_cb_cupll_calc_t41(dev_id, 43793920000.0, 0x1, 0x40, sysclk_freq, 0x320));

	print_status("ten_hl_cupll_config_t41", ten_hl_cupll_config_t41(mod_client, slice_client));

	print_status("ten_hl_cupll_calibrate_config_t41", ten_hl_cupll_calibrate_config_t41(dev_id, slice_client));

	print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath(mod_a, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0));

	// 7 for 40G (XLAUI/OTL/STL)
	print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath(mod_b, TEN_INSTANCE_ALL, 0, 0, 0, 7, 0, 7));

	print_status("ten_hsif_set_clk_40g",ten_hsif_set_clk_40g(mod_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1));
	print_status("ten_hsif_set_clk_40g",ten_hsif_set_clk_40g(mod_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1));

	print_status("ten_hsif_set_clk_40g", ten_hsif_set_clk_40g(mod_client, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1));
	print_status("ten_hsif_set_clk_40g", ten_hsif_set_clk_40g(mod_client, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1));

	print_status("ten_hsif_clk_40g", ten_hsif_clk_40g(1, 1, 0, 1, 0));

	if (ten_dev_is_t41(dev_id))
	{
		printf("ten_dev_is_t41 is true\n");
	}

	print_status("ten_glb_misc_xlos_inv_mr", ten_glb_misc_xlos_inv_mr(mod_line, slice_line, 1));

	print_status("ten_hl_config_sfi51", ten_hl_config_sfi51(mod_line));

	//print_status("ten_hl_config_sfi51", ten_hl_config_sfi51(mod_client));

	/*  Reset the optical module */
	TEN_MDELAY(2000);

	print_status("ten_glb_misc_xlos_inv_mr", ten_glb_misc_xlos_inv_mr(mod_client, slice_client, 1));

	print_status("ten_syncdsync_thread_set_cb_transcode", ten_syncdsync_thread_set_cb_transcode(dev_id, slice_client, 1, 1));

	printf("ten_dev_is_t41: %d\n", ten_dev_is_t41(dev_id));

	print_status("ten_syncdsync_set_cb_40g_transponder", ten_syncdsync_set_cb_40g_transponder(dev_id, 0, 1, 255, 236, 255, 237, 1, 1));

	print_status("ten_hl_syncdsync_datapath_config_t41",
			ten_hl_syncdsync_datapath_config_t41(mod_line, slice_line, mod_client, slice_client, 13, 13, TEN_40G_TRANSPONDER, 1, 64, TEN_MAP_GMP_HO, TEN_MAP_AMP, 8));

	print_status("ten_mpif_global_clock_disable_common", ten_mpif_global_clock_disable_common(dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON));
	print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON));
	print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS));

	//print_status("ten_syncdsync_config_1_to_1", ten_syncdsync_config_1_to_1(mod_client,TEN_SLICE_ALL, 4, CS_TX, 64));

	// Transponder configurations API
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	// OTU3 to OTU3 TRANSPONDER with OTL3.4 in client side
//	print_status("ten_hl_config_otu3v_otu3v_t41",
//			ten_hl_config_otu3v_otu3v_t41(mod_line, TEN_INITIAL_CONFIG, TEN_TRAFFIC_TYPE_OTU3, TEN_FEC_MODE_GFEC, TEN_TRAFFIC_TYPE_OTU3, TEN_FEC_MODE_GFEC, TEN_OTU_TERM_SECTION, 0,
//					0, 0, 1, TEN_MAP_GMP_HO));

	// OTU3 to 4x10G to OTU3 TRANSPONDER with OTL3.4 in client side
//	print_status("ten_hl_config_otu3v_odtu_otu3v_t41",
//			ten_hl_config_otu3v_odtu_otu3v_t41(mod_line, TEN_TRAFFIC_TYPE_OTU3, TEN_FEC_MODE_GFEC, TEN_TRAFFIC_TYPE_OTU3, TEN_FEC_MODE_GFEC, TEN_TRAFFIC_TYPE_OTU2,
//					TEN_OTU_TERM_SECTION, 0, 0, 0, 1, TEN_MAP_GMP_HO, TEN_MAP_GMP_HO));

	// 40GE to OTU3 TRANSPONDER
//	print_status("ten_hl_config_40ge_otu3v_t41",
//			ten_hl_config_40ge_otu3v_t41(mod_line, TEN_INITIAL_CONFIG, TEN_TRAFFIC_TYPE_OTU3, TEN_TRAFFIC_TYPE_SERIAL_40GE, TEN_PP40G_TX_XCON_40GESBI, TEN_PP40G_RX_40GESBI_XCON,
//					TEN_PP40G_TX_XCON_40GESBI, TEN_PP40G_RX_40GESBI_XCON, TEN_FEC_MODE_GFEC, 0, 0, 1, TEN_MAP_GMP_HO, 32, TEN_PP40G_DESKEW, sysclk_freq));

	// API for different Transponder configurations
	print_status("ten_hl_config_40g_monolithic",
			ten_hl_config_40g_monolithic(mod_line, mod_client, TEN_TRAFFIC_TYPE_OTU3, TEN_TRAFFIC_TYPE_OTU3, TEN_INITIAL_CONFIG, TEN_FEC_MODE_GFEC, 1, 0, 0, 0, 0,
					TEN_OC192_TERM_TRANSPARENT_CBR10));

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	// inverts the polarity of all rx data bits when set
	print_status("ten_hsif_slc0_mr10x4_sds_common_rx_config_bitinv", ten_hsif_slc0_mr10x4_sds_common_rx_config_bitinv(mod_client, TEN_INSTANCE_ALL, 1));

	//print_status("ten_hl_config_xaui", ten_hl_config_xaui(mod_client, TEN_SLICE0, 0, 0));

	/* ## The following code is used to enable the interrupt and register a handler for OTN Loss Of Frame */
	/* ## It is commented out so that customers can implement interrupt handler registration in their own way */
	/*  ten_n10g_otnr_intr_handler_enable (mod_line, slice, TEN_N10G_OTNR_INTR_ILOF); */
	/*  ten_n10g_otnr_intr_handler_enable (mod_client, slice_client, TEN_N10G_OTNR_INTR_ILOF); */

	print_status("ten_n40g_gblr4x_set_kpasel", ten_n40g_gblr4x_set_kpasel(mod_line, 1));

	//print_status("ten_n40g_gblr4x_set_kpasel", ten_n40g_gblr4x_set_kpasel(mod_client, 1));

	print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl(mod_line, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0));

	print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl(mod_client, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0));


	print_status("ten_hl_config_sfi51_40g_transponder", ten_hl_config_sfi51_40g_transponder(mod_client, TEN_MAP_BMP));

    // Internal pilot for XLAUI ?????????????????????????
	print_status("ten_hl_xfi_config_clockmux_t41", ten_hl_xfi_config_clockmux_t41(mod_client, TEN_SLICE_ALL, 0, 64, 5, 2))	;

	//print_status("ten_hl_config_xaui", ten_hl_hsif_config_xaui(mod_client, TEN_SLICE_ALL, 0, 0));

	// CODIGO AGREGADO PARA SFI4.2
	//print_status("ten_hl_config_sfi42_40g_transponder", ten_hl_config_sfi42_40g_transponder(mod_client, TEN_HSIF_CKREFDIV4, 0, 0, TEN_MAP_BMP));

	gpllx1_inst_client = 9;
	//Configure the CLOCKMUX for a 40G multi-rate interface, i.e., SFI-5.1 or 16-lane SFI-4.2.
	print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_client, TEN_SLICE_ALL, CS_TX, 0x0));
	print_status("ten_hl_mr_40g_config_clockmux", ten_hl_mr_40g_config_clockmux(mod_client));

	print_status("ten_hl_gpllx1_waitfor_gpll_lock_40g", ten_hl_gpllx1_waitfor_gpll_lock_40g(dev_id, gpllx1_inst_client));

	gpllx1_inst_line = 1;
	print_status("ten_hl_mr_40g_config_clockmux", ten_hl_mr_40g_config_clockmux(mod_line));
	print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_line, TEN_SLICE_ALL, CS_TX, 0x0));
	print_status("ten_hl_gpllx1_waitfor_gpll_lock_40g", ten_hl_gpllx1_waitfor_gpll_lock_40g(dev_id, gpllx1_inst_line));

	print_status("ten_n40g_set_global_resets", ten_n40g_set_global_resets(mod_a, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL));
	print_status("ten_n40g_set_global_resets", ten_n40g_set_global_resets(mod_b, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL));

	print_status("ten_hl_config_remove_soft_resets", ten_hl_config_remove_soft_resets(mod_line, slice_line, mod_client, slice_client, 1, 1));

	print_status("ten_mpif_global_reset_hsif", ten_mpif_global_reset_hsif(dev_id, mod_line & 1, CS_TX_AND_RX, CS_RESET_DEASSERT));
	print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_RX, CS_DISABLE));
	print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX, CS_DISABLE));

	print_status("ten_mpif_global_reset_hsif", ten_mpif_global_reset_hsif(dev_id, mod_client & 1, CS_TX_AND_RX, CS_RESET_DEASSERT));
	print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_RX, CS_DISABLE));
	print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, TEN_MODULE_A_AND_B, TEN_SLICE_ALL, CS_TX, CS_DISABLE));

	print_status("ten_hl_syncdsync_reset", ten_hl_syncdsync_reset(mod_client, slice_client));
	print_status("ten_syncdsynctx_set_configuration_init_force", ten_syncdsynctx_set_configuration_init_force(mod_client, slice_client, CS_RESET_TOGGLE));

	print_status("ten_hl_syncdsync_reset", ten_hl_syncdsync_reset(mod_line, TEN_SLICE_ALL));
	print_status("ten_syncdsynctx_set_configuration_init_force", ten_syncdsynctx_set_configuration_init_force(mod_line, TEN_SLICE_ALL, CS_RESET_TOGGLE));

	print_status("ten_cupll_reset_t41", ten_cupll_reset_t41(mod_client, slice_client, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE));
	print_status("ten_mpif_cupll_settle_force_t41", ten_mpif_cupll_settle_force_t41(dev_id, slice_client, 2, CS_ENABLE));
	print_status("ten_mpif_cupll_settle_force_t41", ten_mpif_cupll_settle_force_t41(dev_id, slice_client, 2, CS_DISABLE));

//	print_status("ten_hl_hsif_check_mr_filt_lock", ten_hl_hsif_check_mr_filt_lock(1, TEN_SLICE0, CS_TX));

	//KPGA
 	//print_status("ten_hsif_slc0_mr10x4_sds_common_prbsgen0_prbs_enable", ten_hsif_slc0_mr10x4_sds_common_prbsgen0_prbs_enable(1, TEN_INSTANCE_ALL, 1));

	//print_status("ten_hsif_slc0_mr10x4_sds_common_prbschk0_enable", ten_hsif_slc0_mr10x4_sds_common_prbschk0_enable(1, TEN_INSTANCE_ALL, 1));

//	print_status("ten_hl_n40g_config_trans_t41",
//			ten_hl_n40g_config_trans_t41(mod_client, TEN_TRAFFIC_TYPE_OTU3, TEN_TRAFFIC_TYPE_OTU3, TEN_FEC_MODE_GFEC, TEN_MAP_BMP, 16, 0, TEN_OTU_TERM_TRANSPARENT, 0, 1,
//					TEN_KPG_PN31));

	print_status("ten_hl_config_otu3_kpga", ten_hl_config_otu3_kpga(mod_client, TEN_TRAFFIC_TYPE_OTU3, TEN_KPG_PN31, 1));
	//print_status("ten_n40g_config_kpg", ten_n40g_config_kpg(mod_client, CS_DISABLE, CS_DISABLE, TEN_KPG_PN31, 0, 0, 0, 0, 0, 0, 0, 0));

	//LOOPBACK
	//print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback(mod_line, TEN_SLICE_ALL, TEN_HSIF_LOOPBACK_MR_RX2TX, CS_ENABLE));
  	print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback(mod_client, TEN_SLICE_ALL, TEN_HSIF_LOOPBACK_MR_SERIAL, CS_ENABLE));
  	//print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback(mod_client, TEN_SLICE_ALL, TEN_HSIF_LOOPBACK_FAR_END, CS_ENABLE));
}
