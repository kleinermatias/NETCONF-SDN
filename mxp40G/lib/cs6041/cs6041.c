/*
 * cs6041.c
 *
 *  Created on: Jun 9, 2015
 *      Author: Guille
 */

#include "cs6041.h"
#include "stdio.h"
#include "../utils/utils.h"
#include "../utils/filelock.h"

struct tm test_begin_time;

int columns = 4;
int column_size[4];
int counted_slices = 0;

char title[4][100] = { { "" }, { "RX Units" }, { "TX Units" }, { "Error Units" } };
char slice_0[4][100] = { { "slice1" }, { "" }, { "" }, { "" } };
char slice_1[4][100] = { { "slice2" }, { "" }, { "" }, { "" } };
char slice_2[4][100] = { { "slice3" }, { "" }, { "" }, { "" } };
char slice_3[4][100] = { { "slice4" }, { "" }, { "" }, { "" } };

unsigned int cs6041_protect_action(FILE *file, unsigned int condition)
{
	if (condition)
	{
		cs6041_reset();
		printf("\nCS6041 device was reset to protect it over temperature.\n");

		if (file != NULL)
		{
			char message[100] = "\nCS6041 device was reset to protect it over temperature.\n";
			fprintf(file, message);
		}

		return 1;
	}
	else
	{
		return 0;
	}
}

void cs6041_reset()
{
	//Initialize with RSTN Low. After power is stable and the SYS_REFCLK_IN input pin is stable,
	gpio_write_bit(47, 0);

	//continue to assert RSTN Low for an additional 1 ms minimum.
	sleep(1);

	//Assert RSTN High
	gpio_write_bit(47, 1);

	// then wait 250 ms before general register access.
	sleep(1);
}

void cs6041_init(cs_uint16 dev_id, T41_t *Chips, cs_uint16 *module_line, cs_uint16 *module_client)
{
	//Initialize the Device Driver

	//Driver instantiation

	//cs_status ten_drvr_load (void), PAGE 270

	print_status("Driver loaded", ten_drvr_load()); //The driver is loaded

	// Value initialization.
	(*Chips).mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft;
	(*Chips).mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;

	//Device registration

	//cs_status ten_dev_register (cs_uint16 dev_id, cs_uint32 base_addr), PAGE 255

	print_status("Device registered", ten_dev_register(dev_id, (cs_uint32) Chips));

	//Initialize the device driver

	//cs_status ten_dev_main_init (cs_uint16 dev_id), PAGE 247

	print_status("Device init", ten_dev_main_init(dev_id));
	printf("Device Chip Id = %08X\n", ten_mpif_get_chip_jtag_id(dev_id));

	//cs_uint16 ten_mod_main_init (cs_uint16 dev_id, cs_uint8 mod_num), PAGE 281

	*module_line = ten_mod_main_init(dev_id, TEN_MODULE_A);
	printf("Module A: %d\n", *module_line);

	*module_client = ten_mod_main_init(dev_id, TEN_MODULE_B);
	printf("Module B: %d\n", *module_client);

}

void cs6041_init_gcc_tx_rx(cs_uint16 dev_id, cs_uint16 module_line, int gcc)
{
	if(gcc == 1)
	{
		//cs6041_init_gcc_tx

		ten_ohpp_sfu_sreset(module_line, CS_RESET_DEASSERT);

		cs_uint16 otnohen = 16;
		ten_ohpp_sfu_set_otnohen(module_line, otnohen);

		cs_uint16 cct1fpl = 0;
		cs_uint16 cct1fpp = 0;
		cs_uint16 cct1col = 0;
		cs_uint16 cct1dol = 0;
		cs_uint16 cct1ln = 0;
		cs_uint16 cct1cmp = 0;
		ten_ohpp_sfu_cct1cfg0(module_line, cct1fpl, cct1fpp, cct1col, cct1dol, cct1ln, cct1cmp);

		cs_uint16 cct1ss = 8;
		cs_uint16 cct1frq = 2;
		ten_ohpp_sfu_cct1cfg1(module_line, cct1ss, cct1frq);

		cs_uint16 cct1md = 2;
		cs_uint16 cct1bs = 14;
		ten_ohpp_sfu_cct1cfg2(module_line, cct1md, cct1bs);

		cs_uint16 cct1mux = 1;
		ten_ohpp_sfu_cct1cfg1_cct1mux_t41(module_line, cct1mux);

		//cs6041_init_gcc_rx

		ten_ohpp_sfu_set_doaum(module_line, 0, 0);

		cs_uint16 ccr1fpl = 0;
		cs_uint16 ccr1fpp = 0;
		cs_uint16 ccr1col = 0;
		cs_uint16 ccr1dol = 0;
		cs_uint16 ccr1ln = 0;
		cs_uint16 ccr1cmp = 0;
		ten_ohpp_sfu_ccr1cfg0(module_line, ccr1fpl, ccr1fpp, ccr1col, ccr1dol, ccr1ln, ccr1cmp);

		cs_uint16 ccr1ss = 8;
		cs_uint16 ccr1frq = 2;
		ten_ohpp_sfu_ccr1cfg1(module_line, ccr1ss, ccr1frq);

		cs_uint16 ccr1md = 2;
		cs_uint16 ccr1bs = 14;
		ten_ohpp_sfu_ccr1cfg2(module_line, ccr1md, ccr1bs);

		cs_uint16 ccr1mux = 1;
		ten_ohpp_sfu_ccr1cfg1_ccr1mux_t41(module_line, ccr1mux);

		printf("GCC Tx/Rx channel clocks were set up.\n");
	}

	else
	{
		printf("GCC Tx/Rx channel clocks not were set up.\n");
	}
}

/* GENERAL Client TRAFFIC CONFIG (OTU2 or XGE)- OTU3 ON THE LINE SIDE */

void general_client_traffic_config_line_otu3(cs_uint16 dev_id, cs_uint16 mod_a, cs_uint16 mod_b, cs_uint8 slice_line, cs_uint8 slice_client, cs_uint32 sysclk_freq,
		cs_uint8 dyn_repro, Muxponder mxp)
{
	cs_uint16 module;
	cs_uint8 mbclksel;
	cs_uint8 provision_line;
	cs_uint8 provision_client;
	cs_uint8 slice;
	cs_uint8 dir;
	cs_uint8 inv;
	cs_uint16 fracdiv_module;
	cs_uint8 fracdiv_slice;
	cs_uint8 inst;
	cs_uint16 silab_mod_line;
	cs_uint16 silab_mod_client;
	cs_uint16 silab_module;
	cs_uint8 silab_slice;
	cs_uint8 gpllx1_inst_line;
	cs_uint8 gpllx1_inst_client;
	cs_uint32 rdiv_divider;
	cs_uint16 tmp_mod_line;
	cs_uint16 tmp_mod_client;
	cs_uint16 ar_mod;
	cs_uint16 ar_slice;
	cs_uint32 clk_rate;
	cs_uint16 mod_hsif;
	cs_uint8 slice_hsif;
	cs_uint8 clock_ch;
	cs_uint8 clock_card;
	cs_uint8 side;
	cs_uint8 mr_optical_module_type;
	unsigned int i;

	// Rates Variables
	double client_rate = 0;
	cs_uint32 desired_freq_line = 0;
	cs_uint32 desired_freq_client = 0;
	cs_uint32 desired_freq_client_xcon = 0;

	// Mpif Variables
	int rxdiv_mode = 0;
	cs_uint16 traffic_type = 0;

	// SyncDsync Variables
	cs_uint8 num_pjo_oxu3 = 0;
	cs_uint16 P_client = 0;
	cs_uint16 Q_client = 0;
	cs_uint16 method = 0;
	cs_uint8 map_odtu = 0;
	cs_uint8 gmp_timeslots = 0;

	/* Default KPGA patterns that can be changed or turned into a parameter */
	cs_uint16 hsif_kpga = TEN_HSIF_PRBS_PN31;
	cs_uint16 kpga = TEN_KPG_PN31;

	cs_uint16 mod_line = (mod_a) | 0;
	cs_uint16 mod_client = (mod_b) | 1;

	provision_line = dyn_repro != 1;
	provision_client = 1;

	typedef enum
	{
		OTU2, XGE,
	} traffic_;

	traffic_ client_traffic_type;

	if (mxp.slice_protocol[0] == 0 && mxp.slice_protocol[0] == 0 && mxp.slice_protocol[0] == 0 && mxp.slice_protocol[0] == 0)
	{
		printf("Traffic Type = OTU2 = \n");
		client_traffic_type = OTU2;
	}
	else if ((mxp.slice_protocol[0] == 1 && mxp.slice_protocol[0] == 1 && mxp.slice_protocol[0] == 1 && mxp.slice_protocol[0] == 1))
	{
		printf("Traffic Type = XGE = \n");
		client_traffic_type = XGE;
	}

	if ((dyn_repro == 0) || (dyn_repro == 3))
	{
		print_status("ten_hl_config_global", ten_hl_config_global(dev_id, TEN_GLOBAL_MODE_S_40G, TEN_GLOBAL_MODE_QUAD_10G, 1, 1, 1));
		print_status("ten_hl_ohpp_and_shadow_ram_init", ten_hl_ohpp_and_shadow_ram_init(dev_id));
		print_status("ten_hl_hsif_power_down_serdes", ten_hl_hsif_power_down_serdes(mod_a));
		print_status("ten_hl_hsif_power_down_serdes", ten_hl_hsif_power_down_serdes(mod_b));
	}
	else
	{
		if (provision_client)
		{
			print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_client & 1, slice_client, CS_TX, 1));
		}
		if (provision_line)
		{
			print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 1));
		}
	}

	slice = 1 ? slice_client : slice_line;

	// Rates Configuration
	if (client_traffic_type == OTU2)
	{
		client_rate = 10709225320.0;
		desired_freq_line = 9802025;
		desired_freq_client = 334663291;
		desired_freq_client_xcon = 10458227;
		rxdiv_mode = 0; // RXDIV from RX controllable divider & protection mux t40 mode
		traffic_type = 0x5;
		num_pjo_oxu3 = 1;
		P_client = 255;
		Q_client = 237;
		method = 1;
		map_odtu = 6;
		gmp_timeslots = 8;
	}
	else if (client_traffic_type == XGE)
	{
		client_rate = 10312500000.0;
		desired_freq_line = 10070800;
		desired_freq_client = 322265625;
		desired_freq_client_xcon = 10070800;
		rxdiv_mode = 2; // RXDIV from internal pilot, after divider & mux
		traffic_type = 12;
		num_pjo_oxu3 = 2;
		P_client = 65535;
		Q_client = 65535;
		method = 3;
		map_odtu = 0;
		gmp_timeslots = 4;
	}

	print_status("ten_cb_rates", ten_cb_rates(dev_id, 43793920000.0, client_rate)); //684.28 Mhz * 16 * 4

	if (provision_line)
	{
		fracdiv_module = mod_line;
		fracdiv_slice = slice_line;
		inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice : fracdiv_slice + 4;

		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 0, sysclk_freq, 342140000));
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 1, sysclk_freq, 342140000));
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 2, sysclk_freq, 342140000));
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 3, sysclk_freq, 342140000));
	}

	if (provision_client)
	{
		fracdiv_module = mod_line;
		fracdiv_slice = slice_client;
		inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice + 8 : fracdiv_slice + 12;
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, inst, sysclk_freq, desired_freq_line));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE));
	}

	if (provision_client)
	{
		fracdiv_module = mod_client;
		fracdiv_slice = slice_client;
		inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice : fracdiv_slice + 4;
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, inst, sysclk_freq, desired_freq_client));
		fracdiv_module = mod_client;
		fracdiv_slice = slice_client;
		inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice + 8 : fracdiv_slice + 12;
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, inst, sysclk_freq, desired_freq_client_xcon));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE));
	}

	print_status("ten_mpif_global_reset_sds_xfi_mpif", ten_mpif_global_reset_sds_xfi_mpif(dev_id, slice_client, CS_RESET_TOGGLE));

	print_status("ten_mpif_rxdiv_cfg0_mode_t41", ten_mpif_rxdiv_cfg0_mode_t41(dev_id, mod_line * 4 + slice_line, 0x0));
	//TEN_MDELAY(5000);

	if (client_traffic_type == XGE)
	{
		// Only for the XGE
		print_status("ten_mpif_pilot_div", ten_mpif_pilot_div(dev_id, (mod_client * 4 + slice_client), 4));
		print_status("ten_mpif_rxdiv_cfg0_pilot_t41", ten_mpif_rxdiv_cfg0_pilot_t41(dev_id, (mod_client * 4 + slice_client), (mod_client * 4 + slice_client)));
	}

	print_status("ten_mpif_rxdiv_cfg0_mode_t41", ten_mpif_rxdiv_cfg0_mode_t41(dev_id, (mod_client * 4 + slice_client), rxdiv_mode));
	//TEN_MDELAY(5000);

	print_status("ten_set_cb_cupll_calc_t41", ten_set_cb_cupll_calc_t41(dev_id, client_rate, 0x1, 0x40, sysclk_freq, 0x320));

	print_status("ten_hl_cupll_config_t41", ten_hl_cupll_config_t41(mod_client, slice_client));

	if ((dyn_repro == 0) || (dyn_repro == 3))
	{
		print_status("ten_hl_cupll_calibrate_config_t41", ten_hl_cupll_calibrate_config_t41(dev_id, slice_client));
	}

	print_status("ten_xfi_cupll_pdcal_t41", ten_xfi_cupll_pdcal_t41(mod_client, slice_client, 0, 0x080));

	if ((dyn_repro == 0) || (dyn_repro == 3))
	{
		print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath(mod_a, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0));
		print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath(mod_b, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0));
	}

	if (provision_line)
	{
		ten_hsif_set_clk_40g(mod_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1);
		ten_hsif_set_clk_40g(mod_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1);
	}

	if (dyn_repro == 0)
	{
		if (ten_dev_is_t41(dev_id))
		{
			printf("ten_dev_is_t41 is true\n");
		}
	}

	if (provision_line)
	{
		ten_glb_misc_xlos_inv_mr(mod_line, slice_line, 1);

		ten_hl_config_sfi51(mod_line);

		/*  Reset the optical module */
		//TEN_MDELAY(2000);
	}

	if (provision_client)
	{

		ten_glb_misc_xlos_inv_mr(mod_client, slice_client, 1);

		if ((slice_client == 0) || (slice_client == 2))
		{
			print_status("ten_hl_config_xfi_t41",
					ten_hl_config_xfi_t41(mod_client, slice_client, traffic_type, 0x2, 0x1, sysclk_freq, 0x1, 0x0, 0x0, 0x1, TEN_HSIF_XFI_DIV_BY_64_REF, 0x1, 0x0, 0x0));
		}
		else
		{
			print_status("ten_hl_config_xfi_t41",
					ten_hl_config_xfi_t41(mod_client, slice_client, traffic_type, 0x2, 0x0, sysclk_freq, 0x1, 0x0, 0x0, 0x1, TEN_HSIF_XFI_DIV_BY_64_REF, 0x1, 0x0, 0x0));
		}
	}
	print_status("ten_syncdsync_thread_set_cb_transcode", ten_syncdsync_thread_set_cb_transcode(dev_id, slice_client, 1, 1));
	print_status("ten_syncdsync_set_cb_40g_muxponder_t41",
			ten_syncdsync_set_cb_40g_muxponder_t41(dev_id, slice_client, 0, 1, 0, num_pjo_oxu3, 255, 236, P_client, Q_client, client_rate, 10037273920.0, 43793920000.0)); //chequear valores ya que cambia el line_rate

	print_status("ten_hl_syncdsync_datapath_config_t41",
			ten_hl_syncdsync_datapath_config_t41(mod_line, slice, mod_client, slice_client, mxp.cs6041_line_fec, mxp.cs6041_client_fec, 1, method, 64, map_odtu, 1, gmp_timeslots)); //Fijarse que el fec es diferente que en OTU2

	if ((dyn_repro == 0) || (dyn_repro == 3))
	{
		print_status("ten_mpif_global_clock_disable_common", ten_mpif_global_clock_disable_common(dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON));
		print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON));
		print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS));
	}

	if (client_traffic_type == OTU2)
	{
		print_status("ten_hl_config_otu2v_otu3v_t41",
				ten_hl_config_otu2v_otu3v_t41(mod_line, slice, slice_client, dyn_repro, 1, mxp.cs6041_line_fec, 5, mxp.cs6041_client_fec, 1, 0, 0, 0, 6, 1, 8, 255)); //ojo otu2v
	}
	else if (client_traffic_type == XGE)
	{
		print_status("ten_hl_config_10ge_otu3v_t41",
				ten_hl_config_10ge_otu3v_t41(mod_line, slice, slice_client, dyn_repro, 1, mxp.cs6041_line_fec, 12, sysclk_freq, 0, 0, 0, 1, 4, TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4,
						2));
	}

	print_status("ten_n40g_gblr4x_set_kpasel", ten_n40g_gblr4x_set_kpasel(mod_line, 1));

	/*  Set the unused channels to 'idle' */
	if ((dyn_repro == 0) || (dyn_repro == 0))
	{
		for (i = 0; i < 4; i++)
		{
			if (i != slice_client)
			{
				print_status("ten_hl_config_aggregation_idle", ten_hl_config_aggregation_idle(mod_line, i, mod_client, i));
			}
		}
	}

	if (provision_line)
	{
		print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl(mod_line, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0));
	}

	if (provision_client)
	{
		print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl(mod_client, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0));
	}

	gpllx1_inst_client = 9;

	/*  The following clockmux code is written for CS604x only in order to simplify it */
	if (provision_client)
	{
		print_status("ten_hl_xfi_config_clockmux_t41", ten_hl_xfi_config_clockmux_t41(mod_client, slice_client, 0, 64, 1, 1));
		print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_client & 1, slice_client, CS_TX, 0)); /*  Bugzilla 30856 */
		print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock(dev_id, gpllx1_inst_client + slice_client));
	}

	gpllx1_inst_line = 1;

	/*  The following clockmux code is written for CS604x only in order to simplify it */
	if (provision_line)
	{
		print_status("ten_hl_mr_40g_config_clockmux", ten_hl_mr_40g_config_clockmux(mod_line));
		print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 0x0));
		print_status("ten_hl_gpllx1_waitfor_gpll_lock_40g", ten_hl_gpllx1_waitfor_gpll_lock_40g(dev_id, gpllx1_inst_line));
	}

	gpllx1_inst_client = (mod_client & 1) == TEN_MODULE_A ? 1 : 9;
	print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock(dev_id, gpllx1_inst_client + slice_client));

	if (provision_line)
	{
		print_status("ten_n40g_set_global_resets", ten_n40g_set_global_resets(mod_a, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL));
		print_status("ten_n40g_set_global_resets", ten_n40g_set_global_resets(mod_b, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL));
	}

	print_status("ten_hl_config_remove_soft_resets", ten_hl_config_remove_soft_resets(mod_line, slice_line, mod_client, slice_client, traffic_type, 1));

	if (provision_line)
	{
		print_status("ten_mpif_global_reset_hsif", ten_mpif_global_reset_hsif(dev_id, mod_line & 1, CS_TX_AND_RX, CS_RESET_DEASSERT));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, mod_line & 1, TEN_SLICE_ALL, CS_RX, CS_DISABLE));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, CS_DISABLE));
	}

	if (provision_client)
	{
		print_status("ten_mpif_global_reset_hsif", ten_mpif_global_reset_hsif(dev_id, mod_client & 1, CS_TX_AND_RX, CS_RESET_DEASSERT));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, mod_client, slice_client, CS_RX, CS_DISABLE));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, TEN_MODULE_A_AND_B, slice_client, CS_TX, CS_DISABLE));
	}

	print_status("ten_hl_syncdsync_reset", ten_hl_syncdsync_reset(mod_client, slice_client));

	print_status("ten_syncdsynctx_set_configuration_init_force", ten_syncdsynctx_set_configuration_init_force(mod_client, slice_client, CS_RESET_TOGGLE));

	if (provision_line)
	{
		print_status("ten_hl_syncdsync_reset", ten_hl_syncdsync_reset(mod_line, slice));
		print_status("ten_syncdsynctx_set_configuration_init_force", ten_syncdsynctx_set_configuration_init_force(mod_line, slice, CS_RESET_TOGGLE));
	}

	print_status("ten_cupll_reset_t41", ten_cupll_reset_t41(mod_client, slice_client, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE));
	print_status("ten_mpif_cupll_settle_force_t41", ten_mpif_cupll_settle_force_t41(dev_id, slice_client, 2, CS_ENABLE));
	print_status("ten_mpif_cupll_settle_force_t41", ten_mpif_cupll_settle_force_t41(dev_id, slice_client, 2, CS_DISABLE));
}

//// OC192_OTU3 ////
// Code taken from Evaluation Board config examples

void oc192_msregen_bmp_amp_xfi_b_ccupll_400_otu3_gfec_sfi5_1_a_k_64(cs_uint16 dev_id, cs_uint16 mod_a, cs_uint16 mod_b, cs_uint8 slice_line, cs_uint8 slice_client,
		cs_uint32 sysclk_freq, /* freq in Hz */
		cs_uint8 dyn_repro, /* 0 = static, 1 = DR client only, 2 = DR line and client */
		Muxponder mxp)
{
	cs_uint16 module;
	cs_uint8 mbclksel;
	cs_uint8 provision_line;
	cs_uint8 provision_client;
	cs_uint8 slice;
	cs_uint8 dir;
	cs_uint8 inv;
	cs_uint16 fracdiv_module;
	cs_uint8 fracdiv_slice;
	cs_uint8 inst;
	cs_uint16 silab_mod_line;
	cs_uint16 silab_mod_client;
	cs_uint16 silab_module;
	cs_uint8 silab_slice;
	cs_uint8 gpllx1_inst_line;
	cs_uint8 gpllx1_inst_client;
	cs_uint32 rdiv_divider;
	cs_uint16 tmp_mod_line;
	cs_uint16 tmp_mod_client;
	cs_uint16 ar_mod;
	cs_uint16 ar_slice;
	cs_uint32 clk_rate;
	cs_uint16 mod_hsif;
	cs_uint8 slice_hsif;
	cs_uint8 clock_ch;
	cs_uint8 clock_card;
	cs_uint8 side;
	cs_uint8 mr_optical_module_type;
	int i;

	/* Default KPGA patterns that can be changed or turned into a parameter */
	cs_uint16 hsif_kpga = TEN_HSIF_PRBS_PN31;
	cs_uint16 kpga = TEN_KPG_PN31;

	cs_uint16 mod_line = (mod_a) | 0;
	cs_uint16 mod_client = (mod_b) | 1;

	provision_line = dyn_repro != 1;
	provision_client = 1;

	if ((dyn_repro == 0) || (dyn_repro == 3))
	{
//		reset();
//		cs6041_init(dev_id, &Chips, &mod_a, &mod_b);

		print_status("ten_hl_config_global", ten_hl_config_global(dev_id, TEN_GLOBAL_MODE_S_40G, TEN_GLOBAL_MODE_QUAD_10G, 1, 1, 1));
		print_status("ten_hl_ohpp_and_shadow_ram_init", ten_hl_ohpp_and_shadow_ram_init(dev_id));
		print_status("ten_hl_hsif_power_down_serdes", ten_hl_hsif_power_down_serdes(mod_a)); //Carlos fijate que pueden ir comentadas
		print_status("ten_hl_hsif_power_down_serdes", ten_hl_hsif_power_down_serdes(mod_b)); //Carlos fijate que pueden ir comentadas

	}
	else
	{
		if (provision_client)
		{
			print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_client & 1, slice_client, CS_TX, 1));
		}
		if (provision_line)
		{
			print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 1));
		}
	}

	/* This will enable logging
	 ten_drvr_ctl_logging (CS_ENABLE);
	 */

	slice = 1 ? slice_client : slice_line;

//    gpllx1_inst_line   = 1;
//    gpllx1_inst_client = 9;

	print_status("ten_cb_rates", ten_cb_rates(dev_id, 43793920000.0, 9953280000.0)); //684.28 Mhz * 16 * 4

	if (provision_line)
	{
		fracdiv_module = mod_line;
		fracdiv_slice = slice_line;
		inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice : fracdiv_slice + 4;

		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 0, sysclk_freq, 342140000));
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 1, sysclk_freq, 342140000));
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 2, sysclk_freq, 342140000));
		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, 3, sysclk_freq, 342140000));
	}

	if (provision_client)
	{
		fracdiv_module = mod_line;
		fracdiv_slice = slice_client;
		inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice + 8 : fracdiv_slice + 12;

		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, inst, sysclk_freq, 9720000));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE));
	}

	if (provision_client)
	{
		fracdiv_module = mod_client;
		fracdiv_slice = slice_client;
		inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice : fracdiv_slice + 4;

		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, inst, sysclk_freq, 311040000));

		fracdiv_module = mod_client;
		fracdiv_slice = slice_client;

		inst = ((fracdiv_module & 1) == TEN_MODULE_A) ? fracdiv_slice + 8 : fracdiv_slice + 12;

		print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, inst, sysclk_freq, 9720000));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE));
	}

//    print_status("ten_mpif_global_reset_sds_xfi_mpif", ten_mpif_global_reset_sds_xfi_mpif( dev_id, slice_client, CS_RESET_TOGGLE ));

	if (dyn_repro != 1)
	{
		print_status("ten_mpif_rxdiv_cfg0_mode_t41", ten_mpif_rxdiv_cfg0_mode_t41(dev_id, mod_line * 4 + slice_line, 0x0));
		TEN_MDELAY(5000);
	}

//    print_status("ten_mpif_pilot_div", ten_mpif_pilot_div( dev_id, ( mod_client * 4 + slice_client ), 4 ));
//    print_status("ten_mpif_rxdiv_cfg0_pilot_t41", ten_mpif_rxdiv_cfg0_pilot_t41( dev_id, ( mod_client * 4 + slice_client ), ( mod_client * 4 + slice_client ) ));

	print_status("ten_mpif_rxdiv_cfg0_mode_t41", ten_mpif_rxdiv_cfg0_mode_t41(dev_id, (mod_client * 4 + slice_client), 0)); //en prbs_xfi.c (dev_id, instance, 0x2 )
	TEN_MDELAY(5000);

	print_status("ten_set_cb_cupll_calc_t41", ten_set_cb_cupll_calc_t41(dev_id, 9953280000.0, 1, 64, sysclk_freq, 0x320));

	print_status("ten_hl_cupll_config_t41", ten_hl_cupll_config_t41(mod_client, slice_client));

	if ((dyn_repro == 0) || (dyn_repro == 3))
	{
		print_status("ten_hl_cupll_calibrate_config_t41", ten_hl_cupll_calibrate_config_t41(dev_id, slice_client));
	}

	print_status("ten_xfi_cupll_pdcal_t41", ten_xfi_cupll_pdcal_t41(mod_client, slice_client, 0, 0x080));

	if ((dyn_repro == 0) || (dyn_repro == 3))
	{
		print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath(mod_a, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0));
		print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath(mod_b, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0));
	}

	if (provision_line)
	{
		ten_hsif_set_clk_40g(mod_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1);
		ten_hsif_set_clk_40g(mod_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1);
	}

	if (dyn_repro == 0)
	{
		if (ten_dev_is_t41(dev_id))
		{
			printf("ten_dev_is_t41 is true\n");
		}
	}

//    printf("ten_dev_is_t41: %d\n", ten_dev_is_t41(dev_id));

	if (provision_line)
	{
		ten_glb_misc_xlos_inv_mr(mod_line, slice_line, 1);

		ten_hl_config_sfi51(mod_line);

		/*  Reset the optical module */
		TEN_MDELAY(2000);
	}

	if (provision_client)
	{
//        ten_hl_config_xfi_t41( mod_hsif, slice_hsif, 8, dir, inv, sysclk_freq, 1, 0, auxclk, 1, TEN_HSIF_XFI_DIV_BY_64_REF, xfi_clk_dist, 0, 0 );

		ten_glb_misc_xlos_inv_mr(mod_client, slice_client, 1);

		if ((slice_client == 0) || (slice_client == 2))
		{
			print_status("ten_hl_config_xfi_t41",
					ten_hl_config_xfi_t41(mod_client, slice_client, 8, 0x2, 0x1, sysclk_freq, 0x1, 0x0, 0x0, 0x1, TEN_HSIF_XFI_DIV_BY_64_REF, 0x1, 0x0, 0x0));
		}
		else
		{
			print_status("ten_hl_config_xfi_t41",
					ten_hl_config_xfi_t41(mod_client, slice_client, 8, 0x2, 0x0, sysclk_freq, 0x1, 0x0, 0x0, 0x1, TEN_HSIF_XFI_DIV_BY_64_REF, 0x1, 0x0, 0x0));
		}
	}

	print_status("ten_syncdsync_thread_set_cb_transcode", ten_syncdsync_thread_set_cb_transcode(dev_id, slice_client, 1, 1));

	print_status("ten_syncdsync_set_cb_40g_muxponder_t41",
			ten_syncdsync_set_cb_40g_muxponder_t41(dev_id, slice_client, 64, 1, 0, 1, 255, 227, 65535, 65535, 9953280000.0, 10037273920.0, 43793920000.0)); //chequear valores ya que cambia el line_rate

//    print_status("ten_hl_syncdsync_datapath_config_t41", ten_hl_syncdsync_datapath_config_t41( mod_line, slice, mod_client, slice_client, 13, 16, 1, 0, 64, 0, 1, 4 ));	//Fijarse que el fec es diferente en prbs_xfi
	print_status("ten_hl_syncdsync_datapath_config_t41",
			ten_hl_syncdsync_datapath_config_t41(mod_line, slice_line, mod_client, slice_client, mxp.cs6041_line_fec, mxp.cs6041_client_fec, 1, 0, 64, 6, 1, 8)); //Fijarse que el fec es diferente en prbs_xfi

	if ((dyn_repro == 0) || (dyn_repro == 3))
	{
		print_status("ten_mpif_global_clock_disable_common", ten_mpif_global_clock_disable_common(dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON));
		print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON));
		print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS));
	}

	print_status("ten_hl_config_oc192_otu3v_t41", ten_hl_config_oc192_otu3v_t41(mod_line, slice, slice_client, dyn_repro, 1, mxp.cs6041_line_fec, 4, 0, 0, 0, 1, 4, 255));

	/* ## The following code is used to enable the interrupt and register a handler for OTN Loss Of Frame */
	/* ## It is commented out so that customers can implement interrupt handler registration in their own way */
	/*  ten_n10g_otnr_intr_handler_enable (mod_line, slice, TEN_N10G_OTNR_INTR_ILOF); */
	/*  ten_n10g_otnr_intr_handler_enable (mod_client, slice_client, TEN_N10G_OTNR_INTR_ILOF); */

	print_status("ten_n40g_gblr4x_set_kpasel", ten_n40g_gblr4x_set_kpasel(mod_line, 1));

	print_status("ten_hl_n40g_config_lom_from_bps", ten_hl_n40g_config_lom_from_bps(mod_line, 43793920000.0));

	/*  Set the unused channels to 'idle' */
	if ((dyn_repro == 0) || (dyn_repro == 0))
	{
		for (i = 0; i < 4; i++)
		{
			if (i != slice_client)
			{
				print_status("ten_hl_config_aggregation_idle", ten_hl_config_aggregation_idle(mod_line, i, mod_client, i));
			}
		}
	}

	if (provision_line)
	{
		print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl(mod_line, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0));
	}

	if (provision_client)
	{
		print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl(mod_client, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0));
	}

	gpllx1_inst_client = 1;

	/*  The following clockmux code is written for CS604x only in order to simplify it */
	if (provision_client)
	{
		print_status("ten_hl_xfi_config_clockmux_t41", ten_hl_xfi_config_clockmux_t41(mod_client, slice_client, 0, 64, 1, 1));
		print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_client & 1, slice_client, CS_TX, 0)); /*  Bugzilla 30856 */
//    	print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock( dev_id, gpllx1_inst_client + slice_client ));
	}

	gpllx1_inst_line = 1;

	/*  The following clockmux code is written for CS604x only in order to simplify it */
	if (provision_line)
	{
		print_status("ten_hl_mr_40g_config_clockmux", ten_hl_mr_40g_config_clockmux(mod_line));
		print_status("ten_hl_gpllx1_waitfor_gpll_lock_40g", ten_hl_gpllx1_waitfor_gpll_lock_40g(dev_id, gpllx1_inst_line));
		print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 0x0));
	}

	print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, mod_client & 1, slice_client, CS_TX, 0));

	gpllx1_inst_client = (mod_client & 1) == TEN_MODULE_A ? 1 : 9;
	print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock(dev_id, gpllx1_inst_client + slice_client));

//    print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback( mod_client, slice_client, TEN_HSIF_LOOPBACK_FACILITY_XFI, CS_ENABLE ));
//    print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback( mod_line, TEN_SLICE_ALL, TEN_HSIF_LOOPBACK_MR_TX2RX, CS_ENABLE ));
//    print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback( mod_client, TEN_SLICE0, TEN_HSIF_LOOPBACK_FACILITY_XFI, CS_ENABLE ));
//    print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback( mod_line, slice_line, TEN_HSIF_LOOPBACK_FAR_END, CS_ENABLE ));
//    print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback( mod_client, slice_client, TEN_HSIF_LOOPBACK_FACILITY_XFI, CS_ENABLE ));
//    print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback( mod_client, slice_client, TEN_HSIF_LOOPBACK_MR_RX2TX, CS_ENABLE ));

	if (provision_line)
	{
		print_status("ten_n40g_set_global_resets", ten_n40g_set_global_resets(mod_a, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL));
		print_status("ten_n40g_set_global_resets", ten_n40g_set_global_resets(mod_b, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL));
	}

	print_status("ten_hl_config_remove_soft_resets", ten_hl_config_remove_soft_resets(mod_line, slice_line, mod_client, slice_client, 8, 1));

	if (provision_line)
	{
		print_status("ten_mpif_global_reset_hsif", ten_mpif_global_reset_hsif(dev_id, mod_line & 1, CS_TX_AND_RX, CS_RESET_DEASSERT));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, mod_line & 1, TEN_SLICE_ALL, CS_RX, CS_DISABLE));
		//    	print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, CS_DISABLE ));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, CS_DISABLE));
	}

	if (provision_client)
	{
		print_status("ten_mpif_global_reset_hsif", ten_mpif_global_reset_hsif(dev_id, mod_client & 1, CS_TX_AND_RX, CS_RESET_DEASSERT));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, mod_client, slice_client, CS_RX, CS_DISABLE));
		print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, TEN_MODULE_A_AND_B, slice_client, CS_TX, CS_DISABLE));
	}

	print_status("ten_hl_syncdsync_reset", ten_hl_syncdsync_reset(mod_client, slice_client));

	print_status("ten_syncdsynctx_set_configuration_init_force", ten_syncdsynctx_set_configuration_init_force(mod_client, slice_client, CS_RESET_TOGGLE));

	if (provision_line)
	{
		print_status("ten_hl_syncdsync_reset", ten_hl_syncdsync_reset(mod_line, slice));
		print_status("ten_syncdsynctx_set_configuration_init_force", ten_syncdsynctx_set_configuration_init_force(mod_line, slice, CS_RESET_TOGGLE));
	}

	print_status("ten_cupll_reset_t41", ten_cupll_reset_t41(mod_client, slice_client, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE));
	print_status("ten_mpif_cupll_settle_force_t41", ten_mpif_cupll_settle_force_t41(dev_id, slice_client, 2, CS_ENABLE));
	print_status("ten_mpif_cupll_settle_force_t41", ten_mpif_cupll_settle_force_t41(dev_id, slice_client, 2, CS_DISABLE));
}

int traffic_initialize(Traffic parameters)
{
	// Column size initialization to 0
	memset(column_size, 0, sizeof(column_size));

	const char *t[5];
	t[0] = "OTU2";
	t[1] = "XGE 7.3";
	t[2] = "OC192";

	cs_uint16 status;
	cs_uint8 instance;
	cs_uint8 slice;

	T41_t Chips;
	cs_uint16 dev_id = 0;
	cs_uint16 mod_a;
	cs_uint16 mod_b;

	cs6041_init(dev_id, &Chips, &mod_a, &mod_b);

	double rate_10g = 10709225320.000000;
	double rate_40g = 43793920000.0;

	double rate_otu2 = 10709225320.0; // OTU2
	double rate_xge = 10312500000.0; // 10 GbE 7.3
	double rate_oc192 = 9953280000.0; // OC192

	double rate_otu2_frac = 334663291; // OTU2
	double rate_xge_frac = 322265625; // 10 GbE 7.3
	double rate_oc192_frac = 311040000; // OC192 (CHECK)

	int sysclk_freq;
	int sysrefclk = 400;
	sysclk_freq = sysrefclk * 1000000;

	// Module A
	if (!parameters.module)
	{
		// slice 0 for sfi_5.1
		slice = 0;
	}

	printf("Selected module: %d\n", parameters.module);

	if (parameters.module)
	{
		int slice_b;
		for (slice_b = 0; slice_b < 4; slice_b++)
		{
			if (parameters.traffic[slice_b] != -1)
			{
				printf("Selected traffic: %s for slice %i\n", t[parameters.traffic[slice_b]], slice_b);
			}
		}

	}
	else
	{
		printf("Selected traffic: OTU3\n");
	}

	printf("Console_output: %d\n", parameters.console_output);

	print_status("ten_hl_config_global", ten_hl_config_global(dev_id, TEN_GLOBAL_MODE_S_40G, TEN_GLOBAL_MODE_QUAD_10G, 1, 1, 1));

	print_status("ten_hl_ohpp_and_shadow_ram_init", ten_hl_ohpp_and_shadow_ram_init(dev_id));

	// Module B
	if (parameters.module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (parameters.traffic[slice_mod_b] != -1)
			{
				instance = slice_mod_b + 4; //INSTANCE 0-15
				printf("Instance: %d\n", instance);

				switch (parameters.traffic[slice_mod_b])
				{
				case 0: // OTU2
					print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, instance, sysclk_freq, rate_otu2_frac));
					break;
				case 1: // XGE
					print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, instance, sysclk_freq, rate_xge_frac));
					break;
				case 2: // OC192
					print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, instance, sysclk_freq, rate_oc192_frac));
					break;
				default:
					break;
				}

				ten_dev_is_ws_in_progress(dev_id);

				print_status("ten_mpif_pilot_div", ten_mpif_pilot_div(dev_id, instance, 0x4));
				printf("Instance: %d\n", instance);

				print_status("ten_mpif_rxdiv_cfg0_pilot_t41", ten_mpif_rxdiv_cfg0_pilot_t41(dev_id, instance, 0x4));
				printf("Instance: %d\n", instance);

				print_status("ten_mpif_rxdiv_cfg0_mode_t41", ten_mpif_rxdiv_cfg0_mode_t41(dev_id, instance, 0x2));
				printf("Instance: %d\n", instance);

				switch (parameters.traffic[slice_mod_b])
				{
				case 0:
					print_status("ten_set_cb_cupll_calc_t41", ten_set_cb_cupll_calc_t41(dev_id, rate_otu2, 0x1, 0x40, sysclk_freq, 0x320));
					break;
				case 1:
					print_status("ten_set_cb_cupll_calc_t41", ten_set_cb_cupll_calc_t41(dev_id, rate_xge, 0x1, 0x40, sysclk_freq, 0x320));
					break;
				case 2:
					print_status("ten_set_cb_cupll_calc_t41", ten_set_cb_cupll_calc_t41(dev_id, rate_oc192, 0x1, 0x40, sysclk_freq, 0x320));
					break;
				default:
					break;
				}
			}
		}

	}
	// Module A
	else
	{
		print_status("ten_cb_rates", ten_cb_rates(dev_id, rate_40g, 0.000000));

		instance = slice; //INSTANCE 0-15

		int i;
		for (i = 0; i < 4; i++)
		{
			print_status("ten_hl_fracdiv_config", ten_hl_fracdiv_config(dev_id, i, sysclk_freq, 2 * 171070000));
		}

		ten_dev_is_ws_in_progress(dev_id);

		instance = slice; //INSTANCE 0-7
		print_status("ten_mpif_pilot_div", ten_mpif_pilot_div(dev_id, instance, 0x4));
		printf("Instance: %d\n", instance);

		instance = slice; //INSTANCE 0-7
		print_status("ten_mpif_rxdiv_cfg0_pilot_t41", ten_mpif_rxdiv_cfg0_pilot_t41(dev_id, instance, 0x0));
		printf("Instance: %d\n", instance);

		print_status("ten_set_cb_cupll_calc_t41", ten_set_cb_cupll_calc_t41(dev_id, rate_40g, 0x1, 0x40, sysclk_freq, 0x320));
	}

	// For module A
	if (!parameters.module)
	{
		print_status("ten_hl_cupll_config_t41", ten_hl_cupll_config_t41(parameters.module, slice));

		print_status("ten_hl_cupll_calibrate_config_t41", ten_hl_cupll_calibrate_config_t41(dev_id, slice));

		print_status("ten_xfi_cupll_pdcal_t41", ten_xfi_cupll_pdcal_t41(parameters.module, slice, 0x0, 0x80));
	}
	// For module B in all slices
	else if (parameters.module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (parameters.traffic[slice_mod_b] != -1)
			{
				printf("Slice_b: %d\n", slice_mod_b);

				print_status("ten_hl_cupll_config_t41", ten_hl_cupll_config_t41(parameters.module, slice_mod_b));

				print_status("ten_hl_cupll_calibrate_config_t41", ten_hl_cupll_calibrate_config_t41(dev_id, slice_mod_b));

				print_status("ten_xfi_cupll_pdcal_t41", ten_xfi_cupll_pdcal_t41(parameters.module, slice_mod_b, 0x0, 0x80));
			}
		}
	}

	print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath(0x0, TEN_INSTANCE_ALL, 0x0, 0x0, 0x0, 0x1, 0x0, 0x1));

	print_status("ten_hsif_provision_datapath", ten_hsif_provision_datapath(0x1, TEN_INSTANCE_ALL, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0));

	printf("ten_dev_is_t41: %d\n", ten_dev_is_t41(dev_id));

	print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl(parameters.module, 0xff, 0x0, 0x0));

	// For module A
	if (!parameters.module)
	{
		// Configure a PP10G transmit/receive path.
		print_status("ten_hl_pp10g_config", ten_hl_pp10g_config(parameters.module, slice, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0));
	}
	// For module B in all slices
	else if (parameters.module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (parameters.traffic[slice_mod_b] != -1)
			{
				printf("Slice_b: %d\n", slice_mod_b);
			}

			// Configure a PP10G transmit/receive path according to selected traffic
			switch (parameters.traffic[slice_mod_b])
			{
			case 0: // OTU2
				print_status("ten_hl_pp10g_config", ten_hl_pp10g_config(parameters.module, slice_mod_b, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0));
				break;
			case 1: // XGE 7.3, COULD EVENTUALLY BE ETH_0? (NO PREAMBLE, NO SFD)
				print_status("ten_hl_pp10g_config", ten_hl_pp10g_config(parameters.module, slice_mod_b, TEN_PP10G_RX_ETH_2, TEN_PP10G_TX_ETH_2));
				break;
			case 2: // OC192
				print_status("ten_hl_pp10g_config", ten_hl_pp10g_config(parameters.module, slice_mod_b, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0));
				break;
			default:
				break;
			}
		}
	}

	cs_uint8 traf[4];

	int g;
	for (g = 0; g < 4; g++)
	{
		switch (parameters.traffic[g])
		{
		case 0:
			traf[g] = 5;
			break; // OTU2
		case 1:
			traf[g] = 12;
			break; // XGE
		case 2:
			traf[g] = 8;
			break; // OC192
		default:
			break;
		}
	}

	// Module B
	if (parameters.module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			// Configures an N10G transmit/receive path according to selected traffic type
			switch (parameters.traffic[slice_mod_b])
			{
			case 0: // OTU2
				print_status("ten_hl_n10g_config", ten_hl_n10g_config(parameters.module, slice_mod_b, TEN_N10G_RX_OTU2_10GE, TEN_N10G_TX_10GE_OTU2, 1));
				break;
			case 1: // XGE 7.3
				print_status("ten_hl_n10g_config", ten_hl_n10g_config(parameters.module, slice_mod_b, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 1));
				break;
			case 2: // OC192
				print_status("ten_hl_n10g_config", ten_hl_n10g_config(parameters.module, slice_mod_b, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 1));
				break;
			default:
				break;
			}

			if (parameters.traffic[slice_mod_b] != -1)
			{
				// XFI High Level configuration
				if ((slice_mod_b == 0) || (slice_mod_b == 2))
				{
					print_status("ten_hl_config_xfi_t41",
							ten_hl_config_xfi_t41(parameters.module, slice_mod_b, traf[slice_mod_b], 0x2, 0x1, sysclk_freq, 0x1, 0x0, 0x0, 0x1, 0x2, 0x1, 0x0, 0x0));
				}
				else
				{
					print_status("ten_hl_config_xfi_t41",
							ten_hl_config_xfi_t41(parameters.module, slice_mod_b, traf[slice_mod_b], 0x2, 0x0, sysclk_freq, 0x1, 0x0, 0x0, 0x1, 0x2, 0x1, 0x0, 0x0));
				}
			}
		}

	}

	// Module A
	else
	{
		print_status("ten_hl_n10g_config", ten_hl_n10g_config(parameters.module, TEN_SLICE_ALL, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, TEN_INITIAL_CONFIG));

		print_status("ten_hl_n40g_config", ten_hl_n40g_config(parameters.module, TEN_N40G_RX_OTU3_ODTU23, TEN_N40G_TX_ODTU2_OTU3));

		print_status("ten_hsif_set_clk_40g", ten_hsif_set_clk_40g(parameters.module, 0x1, 0x1));

		print_status("ten_hsif_set_clk_40g", ten_hsif_set_clk_40g(parameters.module, 0x3, 0x1));

		//Sets external LOS Filter input polarity configuration MR XLOS
		print_status("ten_glb_misc_xlos_inv_mr", ten_glb_misc_xlos_inv_mr(parameters.module, TEN_SLICE0, 0x0));

		print_status("ten_hl_config_sfi51", ten_hl_config_sfi51(parameters.module));
	}

	printf("ten_dev_is_t41: %d\n", ten_dev_is_t41(dev_id));

	// Far-End loopback
	// print_status("ten_hsif_far_end_loopback", ten_hsif_far_end_loopback(parameters.module, TEN_INSTANCE_ALL, CS_ENABLE));

	// Module B
	if (parameters.module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (parameters.traffic[slice_mod_b] != -1)
			{
				print_status("ten_hl_syncdsync_datapath_config_t41",
				//ten_hl_syncdsync_datapath_config_t41(mod_b, slice_mod_b, mod_a, 0x0, 0xd, 0x10, TEN_40G_MUXPONDER, 0x3, 0x40, 0xff, 0x0, 0x4));
						ten_hl_syncdsync_datapath_config_t41(mod_b, slice_mod_b, mod_a, 0x0, parameters.line_fec, parameters.client_fec, TEN_40G_MUXPONDER, 0x3, 0x40, 0xff, 0x0,
								0x4));
			}
		}

	}
	// Module A
	else
	{
		print_status("ten_hl_syncdsync_datapath_config_t41",
				ten_hl_syncdsync_datapath_config_t41(mod_a, slice, mod_b, 0x0, parameters.line_fec, parameters.client_fec, TEN_40G_MUXPONDER, 0x3, 0x40, 0xff, 0x0, 0x4));
	}

	print_status("ten_mpif_global_clock_disable_common", ten_mpif_global_clock_disable_common(dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON));

	//Performs a hard reset on the specified selections. The selections that are masked off will not be affected.
	//cs_status ten_mpif_global_reset_common (cs_uint16 dev_id, cs_reset_action_t act, cs_uint16 bitfield), PAGE 1382
	print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON));

	print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS));

	// Module B
	if (parameters.module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (parameters.traffic[slice_mod_b] != -1)
			{
				print_status("ten_hl_config_fec_t41", ten_hl_config_fec_t41(parameters.module, slice_mod_b, 0x0, parameters.client_fec));

				print_status("ten_hl_n10g_config_lof_from_traffic", ten_hl_n10g_config_lof_from_traffic(parameters.module, slice_mod_b, 0x5, parameters.client_fec));

				print_status("ten_hl_n10g_config_lom_from_traffic", ten_hl_n10g_config_lom_from_traffic(parameters.module, slice_mod_b, 0x5, parameters.client_fec));
			}
		}

	}
	// Module A
	else
	{
		print_status("ten_hl_config_fec_t41", ten_hl_config_fec_t41(parameters.module, slice, TEN_SLICE_40G, parameters.line_fec));
	}

	//Controls the OK signals sent to PP10G/N40G
	print_status("ten_hsif_set_ok_ctrl", ten_hsif_set_ok_ctrl(parameters.module, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0x0));

	// Module B
	if (parameters.module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (parameters.traffic[slice_mod_b] != -1)
			{
				print_status("ten_hl_xfi_config_clockmux_t41", ten_hl_xfi_config_clockmux_t41(parameters.module, slice_mod_b, 0x0, 0x40, 0x1, 0x1));
			}
		}

	}
	// Module A
	else
	{
		//Configure the CLOCKMUX for a 40G multi-rate interface, i.e., SFI-5.1 or 16-lane SFI-4.2
		print_status("ten_hl_mr_40g_config_clockmux", ten_hl_mr_40g_config_clockmux(parameters.module));
	}

	//Select between the HSIF output clocks. This is the 1st stage of top level clock muxing.
	print_status("ten_mpif_clock_select_gpll_in", ten_mpif_clock_select_gpll_in(dev_id, parameters.module, TEN_SLICE_ALL, CS_TX, 0x0));

	// Module B
	if (parameters.module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (parameters.traffic[slice_mod_b] != -1)
			{
				// 9 + slice for Module B.
				instance = slice_mod_b + 9;
				print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock(dev_id, instance));

				print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock(dev_id, instance));

				print_status("ten_hl_config_remove_module_soft_resets", ten_hl_config_remove_module_soft_resets(parameters.module, slice_mod_b, TEN_TRAFFIC_TYPE_OTU2));
			}
		}

	}
	// Module A
	else
	{
		// 1 + slice for Module A.
		instance = slice + 1;

		print_status("ten_hl_gpllx1_waitfor_gpll_lock", ten_hl_gpllx1_waitfor_gpll_lock(dev_id, instance));

		print_status("ten_n40g_set_global_resets", ten_n40g_set_global_resets(parameters.module, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL));

		print_status("ten_n10g_set_global_resets", ten_n10g_set_global_resets(parameters.module, TEN_SLICE0, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL));
		print_status("ten_n10g_set_global_resets", ten_n10g_set_global_resets(parameters.module, TEN_SLICE1, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL));
		print_status("ten_n10g_set_global_resets", ten_n10g_set_global_resets(parameters.module, TEN_SLICE2, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL));
		print_status("ten_n10g_set_global_resets", ten_n10g_set_global_resets(parameters.module, TEN_SLICE3, CS_RESET_DEASSERT, TEN_N10G_GLOBAL_RESETS_ALL));

		print_status("ten_xcon_datapath_reset", ten_xcon_datapath_reset(dev_id, CS_RESET_DEASSERT));

		print_status("ten_xcon_es_reset", ten_xcon_es_reset(dev_id, 0x0, 0x0));
		print_status("ten_xcon_es_reset", ten_xcon_es_reset(dev_id, 0x1, 0x0));
		print_status("ten_xcon_es_reset", ten_xcon_es_reset(dev_id, 0x2, 0x0));
		print_status("ten_xcon_es_reset", ten_xcon_es_reset(dev_id, 0x3, 0x0));
		print_status("ten_xcon_es_reset", ten_xcon_es_reset(dev_id, 0x4, 0x0));
		print_status("ten_xcon_es_reset", ten_xcon_es_reset(dev_id, 0x5, 0x0));
		print_status("ten_xcon_es_reset", ten_xcon_es_reset(dev_id, 0x6, 0x0));
		print_status("ten_xcon_es_reset", ten_xcon_es_reset(dev_id, 0x7, 0x0));

		print_status("ten_mpif_global_reset_syncdsync", ten_mpif_global_reset_syncdsync(dev_id, TEN_MODULE_A, TEN_SLICE_ALL, CS_TX_AND_RX, CS_RESET_DEASSERT));

		print_status("ten_hl_resets_block", ten_hl_resets_block(parameters.module, slice, CS_RESET_DEASSERT, TEN_HL_RESETS_BLOCK_SYNCDSYNC));
	}

	print_status("ten_mpif_set_clock_switch_force", ten_mpif_set_clock_switch_force(dev_id, parameters.module, TEN_SLICE_ALL, CS_TX_AND_RX, 0x0));

	print_status("ten_mpif_global_reset_hsif", ten_mpif_global_reset_hsif(dev_id, parameters.module, CS_TX_AND_RX, 0x0));

	// Module A
	if (!parameters.module)
	{
		print_status("ten_n40g_sdfr_select_global_timing_source", ten_n40g_sdfr_select_global_timing_source(parameters.module, 0x6));

		print_status("ten_glb_misc_set_gsti", ten_glb_misc_set_gsti(dev_id, 0x0, 0x17d7, 0x8400));

		print_status("ten_mpif_global_reset_common", ten_mpif_global_reset_common(dev_id, CS_RESET_DEASSERT, 0x20));
	}

	// If module A
	if (!parameters.module)
	{
		// Configure Xcon Pbert
		hl_xcon_pbert_config(dev_id, parameters.module, slice);
	}
	// If module B in all slices
	else if (parameters.module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (parameters.traffic[slice_mod_b] != -1)
			{
				// Configure Xcon Pbert
				hl_xcon_pbert_config(dev_id, parameters.module, slice_mod_b);
			}
		}
	}

	if (parameters.fec_monitor)
	{
		cs6041_fecstats_init(parameters.module); // Initialize FEC statistics
	}

	pbert_traffic_control(parameters);

	return 0;
}

void wait_for_synchronization(int module, int traffic[4])
{
	int dev_id = 0;

	cs_uint64 rx_good = 0;
	cs_uint64 rx_error = 0;

	cs_uint64 rx_good_0 = 0;
	cs_uint64 rx_good_1 = 0;
	cs_uint64 rx_good_2 = 0;
	cs_uint64 rx_good_3 = 0;

	cs_uint64 rx_error_0 = 0;
	cs_uint64 rx_error_1 = 0;
	cs_uint64 rx_error_2 = 0;
	cs_uint64 rx_error_3 = 0;

	// If module A
	if (!module)
	{
		int slice = 0;
		hl_xcon_pbert_generator_control(dev_id, module, slice, CS_ENABLE);

		read_rx_pbert_counters(dev_id, module, slice, &rx_good, &rx_error);

		int in_sync = 0;
		while (!in_sync)
		{
			read_rx_pbert_counters(dev_id, module, slice, &rx_good, &rx_error);

			if (rx_good != 0 || rx_error != 0)
			{
				sleep(2);
				read_rx_pbert_counters(dev_id, module, slice, &rx_good, &rx_error);

				if (rx_error != 0)
				{
					// errors received, clean registers and check again
					ten_dev_clear_stats(dev_id);
				}
				else
				{
					// Synchronized
					in_sync = 1;
				}
			}
		}

		printf("Synchronized !\n");
		hl_xcon_pbert_generator_control(dev_id, module, slice, CS_DISABLE);
		ten_dev_clear_stats(dev_id);

		// Enable Pbert Generator
		hl_xcon_pbert_generator_control(dev_id, module, slice, CS_ENABLE);
	}
	// If module B in all slices
	else if (module)
	{
		int slice_mod_b;
		int sync_all = 0;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (traffic[slice_mod_b] != -1)
			{
				// Enable Pbert Generator
				hl_xcon_pbert_generator_control(dev_id, module, slice_mod_b, CS_ENABLE);
			}
		}

		// Wait for the slices to sync
		while (!sync_all)
		{
			if (traffic[0] != -1)
			{
				read_rx_pbert_counters(dev_id, module, 0, &rx_good_0, &rx_error_0);
			}

			if (rx_good_0 != 0 || rx_error_0 != 0 || traffic[0] == -1)
			{
				if (traffic[1] != -1)
				{
					read_rx_pbert_counters(dev_id, module, 1, &rx_good_1, &rx_error_1);
				}

				if (rx_good_1 != 0 || rx_error_1 != 0 || traffic[1] == -1)
				{

					if (traffic[2] != -1)
					{
						read_rx_pbert_counters(dev_id, module, 2, &rx_good_2, &rx_error_2);
					}

					if (rx_good_2 != 0 || rx_error_2 != 0 || traffic[2] == -1)
					{

						if (traffic[3] != -1)
						{
							read_rx_pbert_counters(dev_id, module, 3, &rx_good_3, &rx_error_3);
						}

						if (rx_good_3 != 0 || rx_error_3 != 0 || traffic[3] == -1)
						{
							sleep(2);
							if (traffic[0] != -1)
							{
								read_rx_pbert_counters(dev_id, module, 0, &rx_good_0, &rx_error_0);
							}
							if (traffic[1] != -1)
							{
								read_rx_pbert_counters(dev_id, module, 1, &rx_good_1, &rx_error_1);
							}
							if (traffic[2] != -1)
							{
								read_rx_pbert_counters(dev_id, module, 2, &rx_good_2, &rx_error_2);
							}
							if (traffic[3] != -1)
							{
								read_rx_pbert_counters(dev_id, module, 3, &rx_good_3, &rx_error_3);
							}

							if (rx_error_0 != 0 || rx_error_1 != 0 || rx_error_2 != 0 || rx_error_3 != 0)
							{
								// errors received, clean registers and check again
								ten_dev_clear_stats(dev_id);
							}
							else
							{
								// Synchronized
								sync_all = 1;
							}

						}
					}
				}
			}
		}

		printf("Synchronized !\n");
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (traffic[slice_mod_b] != -1)
			{
				// Enable Pbert Generator
				hl_xcon_pbert_generator_control(dev_id, module, slice_mod_b, CS_DISABLE);
			}
		}

		ten_dev_clear_stats(dev_id);
		sleep(1);

		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (traffic[slice_mod_b] != -1)
			{
				// Enable Pbert Generator
				hl_xcon_pbert_generator_control(dev_id, module, slice_mod_b, CS_ENABLE);
			}
		}
	}
}

void pbert_error_injection(int module, int traffic[4])
{
	int dev_id = 0;

	// Elastic Store
	int ES;

	// Module B
	if (module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (traffic[slice_mod_b] != -1)
			{
				ES = slice_mod_b + 4;

				// Parameters
				// dev_id: device id
				// ES: Elastic Store
				// Err_type: Error type (XCON_CONTINUOUS_PRBS_ERROR, XCON_SINGLE_PRBS_ERROR, XCON_CONTINUOUS_FCS_ERROR, XCON_SINGLE_FCS_ERROR)
				// Duration: Time for error generation
				print_status("ten_xcon_pbert_inject_err", ten_xcon_pbert_inject_err(dev_id, ES, XCON_CONTINUOUS_PRBS_ERROR, 1));
			}
		}

	}
	// Module A
	else
	{
		int slice = 0;
		ES = slice;
		// Parameters
		// dev_id: device id
		// ES: Elastic Store
		// Err_type: Error type (XCON_CONTINUOUS_PRBS_ERROR, XCON_SINGLE_PRBS_ERROR, XCON_CONTINUOUS_FCS_ERROR, XCON_SINGLE_FCS_ERROR)
		// Duration: Time for error generation
		print_status("ten_xcon_pbert_inject_err", ten_xcon_pbert_inject_err(dev_id, ES, XCON_CONTINUOUS_PRBS_ERROR, 1));
	}
}

void hl_xcon_pbert_config(int dev_id, int module_id, int slice)
{

	cs_uint8 ES;
	cs_uint8 module_channel;

	print_status("ten_n10g_set_pktie", ten_n10g_set_pktie(module_id, slice, 1));

	// Module B
	if (module_id)
	{
		// Elastic Store
		ES = slice + 4;
		// Channel for module B
		module_channel = slice + 4;
	}
	// Module A
	else
	{
		ES = slice;
		// Channel for module A
		module_channel = slice;
	}

	printf("Elastic Store: %i\n", ES);

	print_status("ten_xcon_es_select_source", ten_xcon_es_select_source(dev_id, ES, module_channel, XCON_PP10G));

	// dev_id, ES input_channel, read source select 2=pbert
	print_status("ten_xcon_es_select_read_source", ten_xcon_es_select_read_source(0, module_channel, 2));

	// dev_id, elastic_store_id, multi_frame_mode, gfp_mode, sf_mode -cthru,s&f, pkt_mode
	print_status("ten_xcon_config_es_mode", ten_xcon_config_es_mode(0, ES, 0, 0, 1, 1));

	print_status("ten_xcon_select_bert", ten_xcon_select_bert(0, module_channel, 2));

	print_status("ten_xcon_control_pbert_frame_payload", ten_xcon_control_pbert_frame_payload(0, ES, 0, 0));

	// Random unit length generated by using 15 bits of a PRBS23 or FIXED
	print_status("ten_xcon_control_pbert_unit_len", ten_xcon_control_pbert_unit_len(0, ES, 0, 0x07ff, 0x040, 0x05ee));

	print_status("ten_xcon_pbert_control_traffic", ten_xcon_pbert_control_traffic(0, ES, 0));

	print_status("ten_xcon_pbert_control_ifg", ten_xcon_pbert_control_ifg(0, ES, 0, 5));

	// DeAssert pbert reset
	print_status("ten_xcon_pbert_tx_reset", ten_xcon_pbert_tx_reset(0, ES, 0));

	print_status("ten_xcon_pbert_rx_reset", ten_xcon_pbert_rx_reset(0, ES, 0));

	//print_status("ten_pp10g_pcs_rx_status", ten_pp10g_pcs_rx_status(module_id, slice, 2));

	print_status("ten_hl_pp10g_tx_reset", ten_hl_pp10g_tx_reset(module_id, slice, 1));

	print_status("ten_hl_pp10g_rx_reset", ten_hl_pp10g_rx_reset(module_id, slice, 1));

	print_status("ten_xcon_es_reset", ten_xcon_es_reset(0, ES, 1));

	print_status("ten_xcon_es_reset", ten_xcon_es_reset(0, ES, 0));

	print_status("ten_hl_pp10g_tx_reset", ten_hl_pp10g_tx_reset(module_id, slice, 0));

	print_status("ten_hl_pp10g_rx_reset", ten_hl_pp10g_rx_reset(module_id, slice, 0));

	//print_status("ten_pp10g_pcs_rx_status", ten_pp10g_pcs_rx_status(module_id, slice, 2));

}

void hl_xcon_pbert_generator_control(int dev_id, int module_id, int slice, cs_ctl_t status)
{
	cs_uint8 ES;

	// Module B
	if (module_id)
	{
		// Elastic Store
		ES = slice + 4;
	}
	// Module A
	else
	{
		ES = slice;
	}

	// Enable/Disable Pbert Generator
	ten_xcon_pbert_control_generator(0, ES, status);
}

void read_rx_pbert_counters(cs_uint16 dev_id, cs_uint16 module_id, cs_uint8 slice, cs_uint64 *rx_good_unit, cs_uint64 *rx_error_unit)
{
	cs_uint8 ES;

	// Module B
	if (module_id)
	{
		// Elastic Store
		ES = slice + 4;
	}
	// Module A
	else
	{
		ES = slice;
	}

	*rx_good_unit = ten_dev_read_stat(dev_id, TEN_ID_XCON, ES, TEN_XCON_PBERT_GOOD_UCNT_STAT, CS_RX);
	*rx_error_unit = ten_dev_read_stat(dev_id, TEN_ID_XCON, ES, TEN_XCON_PBERT_RX_UERRCNT_STAT, CS_RX);
}

void pbert_traffic_control(Traffic parameters)
{
	// Column size initialization to 0
	memset(column_size, 0, sizeof(column_size));

	int dev_id = 0;
	int endless = 0;

	printf("Module: %i\n", parameters.module);

	if (parameters.fec_monitor)
	{
		ten_dev_clear_stats(dev_id);
	}

	printf("Waiting for synchronization...\n");

	// Synchronization wait
	wait_for_synchronization(parameters.module, parameters.traffic);

	// Pbert Error Injection
	//pbert_error_injection(module, slice);

	if (parameters.generation_time == -1)
		printf("Generación de PBERT sin tiempo limite \n");
	else
		printf("Generación de PBERT durante %i seconds...\n", parameters.generation_time);

	// start time for pbert generation
	time_t start_time;
	// end time for pbert generation
	time_t end_time;
	start_time = time(0);

	struct tm *start_st;
	char buffer_start[80];
	start_st = localtime(&start_time);
	strftime(buffer_start, sizeof(buffer_start), "%Y-%m-%d %H:%M:%S", start_st);

	printf("Start Time: %s\n", buffer_start);

	if (parameters.generation_time == -1)
	{
		endless = 1;
		end_time = start_time;
	}
	else
	{
		end_time = start_time + parameters.generation_time;
	}

	struct tm *end_st;

	char buffer_end[80];

	if (parameters.generation_time != -1)
	{
		end_st = localtime(&end_time);

		strftime(buffer_end, sizeof(buffer_end), "%Y-%m-%d %H:%M:%S", end_st);

		printf("End Time: %s\n", buffer_end);
	}
	// Current time
	time_t current_time = time(0);

	// File pointers for log files
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	FILE *fp3 = NULL;
	FILE *fp4 = NULL;

	// Struct for board info
	Board info;

	// Get board info
	board_info(&info);

	// File names
	char file_slice_1[80] = { "../../../var/log/mxp/" };
	char file_slice_2[80] = { "../../../var/log/mxp/" };
	char file_slice_3[80] = { "../../../var/log/mxp/" };
	char file_slice_4[80] = { "../../../var/log/mxp/" };

	// For module B
	if (parameters.module)
	{
		if (parameters.traffic[0] != -1)
		{
			strncat(file_slice_1, info.name, sizeof(info.name));
			strcat(file_slice_1, "_pbert_stats_modB_slice_0_(");
			strcat(file_slice_1, buffer_start);
			strcat(file_slice_1, ").txt");

			fp1 = fopen(file_slice_1, "w+");
			if (fp1 == NULL)
			{
				printf("Failed to Open the Log File \n");
				exit(EXIT_FAILURE);
			}
		}

		if (parameters.traffic[1] != -1)
		{
			strncat(file_slice_2, info.name, sizeof(info.name));
			strcat(file_slice_2, "_pbert_stats_modB_slice_1_(");
			strcat(file_slice_2, buffer_start);
			strcat(file_slice_2, ").txt");

			fp2 = fopen(file_slice_2, "w+");
			if (fp2 == NULL)
			{
				printf("Failed to Open the Log File \n");
				exit(EXIT_FAILURE);
			}
		}

		if (parameters.traffic[2] != -1)
		{
			strncat(file_slice_3, info.name, sizeof(info.name));
			strcat(file_slice_3, "_pbert_stats_modB_slice_2_(");
			strcat(file_slice_3, buffer_start);
			strcat(file_slice_3, ").txt");

			fp3 = fopen(file_slice_3, "w+");
			if (fp3 == NULL)
			{
				printf("Failed to Open the Log File \n");
				exit(EXIT_FAILURE);
			}
		}

		if (parameters.traffic[3] != -1)
		{
			strncat(file_slice_4, info.name, sizeof(info.name));
			strcat(file_slice_4, "_pbert_stats_modB_slice_3_(");
			strcat(file_slice_4, buffer_start);
			strcat(file_slice_4, ").txt");

			fp4 = fopen(file_slice_4, "w+");
			if (fp4 == NULL)
			{
				printf("Failed to Open the Log File \n");
				exit(EXIT_FAILURE);
			}
		}

	}
	// For module A
	else
	{
		strncat(file_slice_1, info.name, sizeof(info.name));
		strcat(file_slice_1, "_pbert_stats_modA_(");
		strcat(file_slice_1, buffer_start);
		strcat(file_slice_1, ").txt");

		fp1 = fopen(file_slice_1, "w+");
		if (fp1 != NULL)
		{
			printf("Failed to Open the Log File \n");
			exit(EXIT_FAILURE);
		}
	}

	unsigned int count = 0;
	int log_count = 0;

	// Initialize time for close and open log file
	time_t last_close = current_time;

	// Count the active slices
	int active_slices = 0;
	int x;
	for (x = 0; x < 4; x++)
	{
		if (parameters.traffic[x] != -1)
		{
			active_slices++;
		}
	}

	printf("Active Slices: %i\n", active_slices);

	// Start time of the test
	get_time(&test_begin_time);

	char time_A[80];
	get_string_from_time(&test_begin_time, time_A);

	char table_data[1000];

	// Pbert generation
	while (current_time < end_time || endless)
	{
		// Count
		count = log_count + 1;
		sleep(1);

		// If module A
		if (!parameters.module)
		{
			int slice = 0;
			if (log_count > 0)
			{
				// Log Out Pbert info
				check_pbert_counters(dev_id, parameters.module, slice, 0, count, fp1, parameters.console_output, 1, table_data);
			}
			else
			{
				// Log Out Pbert info
				check_pbert_counters(dev_id, parameters.module, slice, 1, count, fp1, parameters.console_output, 1, table_data);
			}

			printf("%s", table_data);
			memset(table_data, 0, sizeof(table_data));

			if (parameters.fec_monitor)
			{

				printf("\n");

				// FEC statistics
				ten_gfec_40g_stats_t stats_40ga;
				ten_gfec_40g_stats_t stats_40gb;
				ten_gfec_10g_stats_t stats_10g;
				ten_glb_misc_gsti_update(0, 1, 0);
				ten_mod_get_blk_stats(0, TEN_ID_GFEC_40G, &stats_40ga, sizeof(stats_40ga));
				ten_mod_get_blk_stats(1, TEN_ID_GFEC_40G, &stats_40gb, sizeof(stats_40gb));
				ten_mod_get_blk_stats(1, TEN_ID_GFEC_10G, &stats_10g, sizeof(stats_10g));

				printf("-------------------------------------------------------\n");
				printf("               ESTADISTICAS FEC LADO LINEA             \n");
				printf("-------------------------------------------------------\n");
				ten_mod_print_blk_stats(0, TEN_ID_GFEC_40G);

				printf("\n\n");
				printf("-------------------------------------------------------\n");
				printf("               ESTADISTICAS FEC LADO CLIENTES          \n");
				printf("-------------------------------------------------------\n");
				ten_mod_print_blk_stats(1, TEN_ID_GFEC_40G);
				ten_mod_print_blk_stats(1, TEN_ID_GFEC_10G);

				ten_mod_clear_blk_stats(0, TEN_ID_GFEC_40G);
				ten_mod_clear_blk_stats(1, TEN_ID_GFEC_40G);
				ten_mod_clear_blk_stats(1, TEN_ID_GFEC_10G);

				// FEC statistics
			}

		}
		// If module B in all slices
		else if (parameters.module)
		{
			int slice_mod_b;
			for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
			{
				// Normal count
				if (log_count > 0)
				{
					if (slice_mod_b == 0 && parameters.traffic[slice_mod_b] != -1)
					{

						// Log Out Pbert info
						check_pbert_counters(dev_id, parameters.module, slice_mod_b, 0, count, fp1, parameters.console_output, active_slices, table_data);

					}
					else if (slice_mod_b == 1 && parameters.traffic[slice_mod_b] != -1)
					{

						// Log Out Pbert info
						check_pbert_counters(dev_id, parameters.module, slice_mod_b, 0, count, fp2, parameters.console_output, active_slices, table_data);

					}
					else if (slice_mod_b == 2 && parameters.traffic[slice_mod_b] != -1)
					{

						// Log Out Pbert info
						check_pbert_counters(dev_id, parameters.module, slice_mod_b, 0, count, fp3, parameters.console_output, active_slices, table_data);

					}
					else if (slice_mod_b == 3 && parameters.traffic[slice_mod_b] != -1)
					{

						// Log Out Pbert info
						check_pbert_counters(dev_id, parameters.module, slice_mod_b, 0, count, fp4, parameters.console_output, active_slices, table_data);

					}

				}
				// First time add header for log file
				else
				{
					if (slice_mod_b == 0 && parameters.traffic[slice_mod_b] != -1)
					{
						// Log Out Pbert info
						check_pbert_counters(dev_id, parameters.module, slice_mod_b, 1, count, fp1, parameters.console_output, active_slices, table_data);
					}
					else if (slice_mod_b == 1 && parameters.traffic[slice_mod_b] != -1)
					{
						// Log Out Pbert info
						check_pbert_counters(dev_id, parameters.module, slice_mod_b, 1, count, fp2, parameters.console_output, active_slices, table_data);
					}
					else if (slice_mod_b == 2 && parameters.traffic[slice_mod_b] != -1)
					{
						// Log Out Pbert info
						check_pbert_counters(dev_id, parameters.module, slice_mod_b, 1, count, fp3, parameters.console_output, active_slices, table_data);
					}
					else if (slice_mod_b == 3 && parameters.traffic[slice_mod_b] != -1)
					{
						// Log Out Pbert info
						check_pbert_counters(dev_id, parameters.module, slice_mod_b, 1, count, fp4, parameters.console_output, active_slices, table_data);
					}
				}
			}

			printf("%s", table_data);
			memset(table_data, 0, sizeof(table_data));

			if (parameters.fec_monitor)
			{
				printf("\n");

				// FEC statistics
				ten_gfec_40g_stats_t stats_40ga;
				ten_gfec_40g_stats_t stats_40gb;
				ten_gfec_10g_stats_t stats_10g;
				ten_glb_misc_gsti_update(0, 1, 0);
				ten_mod_get_blk_stats(0, TEN_ID_GFEC_40G, &stats_40ga, sizeof(stats_40ga));
				ten_mod_get_blk_stats(1, TEN_ID_GFEC_40G, &stats_40gb, sizeof(stats_40gb));
				ten_mod_get_blk_stats(1, TEN_ID_GFEC_10G, &stats_10g, sizeof(stats_10g));

				printf("-------------------------------------------------------\n");
				printf("               ESTADISTICAS FEC LADO LINEA             \n");
				printf("-------------------------------------------------------\n");
				ten_mod_print_blk_stats(0, TEN_ID_GFEC_40G);

				printf("\n\n");
				printf("-------------------------------------------------------\n");
				printf("               ESTADISTICAS FEC LADO CLIENTES          \n");
				printf("-------------------------------------------------------\n");
				ten_mod_print_blk_stats(1, TEN_ID_GFEC_40G);
				ten_mod_print_blk_stats(1, TEN_ID_GFEC_10G);

				ten_mod_clear_blk_stats(0, TEN_ID_GFEC_40G);
				ten_mod_clear_blk_stats(1, TEN_ID_GFEC_40G);
				ten_mod_clear_blk_stats(1, TEN_ID_GFEC_10G);
				// FEC statistics

			}

			// clear the screen for the next console log
			clear_screen();

		}

		log_count++;

		// Update current time
		current_time = time(0);

		// Close file after 5 min and open again
		if (current_time - last_close > 300)
		{
			// If module A
			if (!parameters.module)
			{
				if (fp1 != NULL)
				{
					fclose(fp1);
					fp1 = fopen(file_slice_1, "a");
				}
			}
			// If module B in all slices
			else if (parameters.module)
			{
				// Close open files
				if (fp1 != NULL && parameters.traffic[0] != -1)
				{
					fclose(fp1);
					fp1 = fopen(file_slice_1, "a");
				}
				if (fp2 != NULL && parameters.traffic[1] != -1)
				{
					fclose(fp2);
					fp2 = fopen(file_slice_2, "a");
				}
				if (fp3 != NULL && parameters.traffic[2] != -1)
				{
					fclose(fp3);
					fp3 = fopen(file_slice_3, "a");
				}
				if (fp4 != NULL && parameters.traffic[3] != -1)
				{
					fclose(fp4);
					fp4 = fopen(file_slice_4, "a");
				}
			}

			// Save last close time
			last_close = current_time;
			// printf("File saved\n");
		}

		//pbert_error_injection(parameters.module, parameters.traffic);
	}

	// Last time
	++count;

	// If module A
	if (!parameters.module)
	{
		int slice = 0;
		// Enalbe Pbert Generator
		hl_xcon_pbert_generator_control(dev_id, parameters.module, slice, CS_DISABLE);
		// Read Pbert Statistics
		check_pbert_counters(dev_id, parameters.module, slice, 0, count, fp1, parameters.console_output, slice, table_data);
		printf("%s", table_data);
		memset(table_data, 0, sizeof(table_data));
	}
	// If module B in all slices
	else if (parameters.module)
	{
		int slice_mod_b;
		for (slice_mod_b = 0; slice_mod_b < 4; slice_mod_b++)
		{
			if (parameters.traffic[slice_mod_b] != -1)
			{
				// Enable Pbert Generator
				hl_xcon_pbert_generator_control(dev_id, parameters.module, slice_mod_b, CS_DISABLE);
			}

			// Read Pbert Statistics

			if (slice_mod_b == 0 && parameters.traffic[slice_mod_b] != -1)
			{
				// Log Out Pbert info
				check_pbert_counters(dev_id, parameters.module, slice_mod_b, 0, count, fp1, parameters.console_output, active_slices, table_data);
			}
			else if (slice_mod_b == 1 && parameters.traffic[slice_mod_b] != -1)
			{
				// Log Out Pbert info
				check_pbert_counters(dev_id, parameters.module, slice_mod_b, 0, count, fp2, parameters.console_output, active_slices, table_data);
			}
			else if (slice_mod_b == 2 && parameters.traffic[slice_mod_b] != -1)
			{
				// Log Out Pbert info
				check_pbert_counters(dev_id, parameters.module, slice_mod_b, 0, count, fp3, parameters.console_output, active_slices, table_data);
			}
			else if (slice_mod_b == 3 && parameters.traffic[slice_mod_b] != -1)
			{
				// Log Out Pbert info
				check_pbert_counters(dev_id, parameters.module, slice_mod_b, 0, count, fp4, parameters.console_output, active_slices, table_data);
			}
		}

		printf("%s", table_data);
		memset(table_data, 0, sizeof(table_data));
	}

	// Close open files
	if (fp1 != NULL && parameters.traffic[0] != -1)
	{
		fclose(fp1);
	}

	if (fp2 != NULL && parameters.traffic[1] != -1)
	{
		fclose(fp2);
	}

	if (fp3 != NULL && parameters.traffic[2] != -1)
	{
		fclose(fp3);
	}

	if (fp4 != NULL && parameters.traffic[3] != -1)
	{
		fclose(fp4);
	}
}

cs_status check_pbert_counters(cs_uint16 dev_id, cs_uint16 module_id, cs_uint8 slice, int addHeader, int timeCount, FILE *fp, int console_output, int number_of_slices,
		char table_data[])
{
	cs_uint8 ES;

	time_t system_time;
	char buffer_system_time[80];
	system_time = time(0);

	// For module B
	if (module_id)
	{
		ES = slice + 4;
	}
	// For module A
	else
	{
		ES = slice;
	}

	// Header for log file
	if (addHeader && fp != NULL)
	{
		// Secure first time creation and Header File Creation
		char count[] = "COUNT";
		char rx_units[] = "RX_UNITS";
		char tx_units[] = "TX_UNITS";
		char rx_unit_octets[] = "RX_UNIT_OCTETS";
		char tx_unit_octets[] = "TX_UNIT_OCTETS";
		char error_units[] = "ERROR_UNITS";
		char error_unit_octets[] = "ERROR_UNIT_OCTETS";
		char ber[] = "BER";
		char time_title[] = "TIME";

		fprintf(fp, "%-17s\t%-15s\t%-15s\t%-15s\t%-15s\t%-15s\t%-15s\t%-15s\t%-15s \n", time_title, count, rx_units, tx_units, rx_unit_octets, tx_unit_octets, error_units,
				error_unit_octets, ber);
	}

	cs_uint64 tx_unit = ten_dev_read_stat(dev_id, TEN_ID_XCON, ES, TEN_XCON_PBERT_GOOD_UCNT_STAT, CS_TX);
	cs_uint64 tx_octet = ten_dev_read_stat(dev_id, TEN_ID_XCON, ES, TEN_XCON_PBERT_GOOD_UOCNT_STAT, CS_TX);
	cs_uint64 rx_good_unit = ten_dev_read_stat(dev_id, TEN_ID_XCON, ES, TEN_XCON_PBERT_GOOD_UCNT_STAT, CS_RX);
	cs_uint64 rx_good_octet = ten_dev_read_stat(dev_id, TEN_ID_XCON, ES, TEN_XCON_PBERT_GOOD_UOCNT_STAT, CS_RX);
	cs_uint64 rx_error_unit = ten_dev_read_stat(dev_id, TEN_ID_XCON, ES, TEN_XCON_PBERT_RX_UERRCNT_STAT, CS_RX);
	cs_uint64 rx_error_octet = ten_dev_read_stat(dev_id, TEN_ID_XCON, ES, TEN_XCON_PBERT_RX_UOERRCNT_STAT, CS_RX);

	// Current time
	struct tm current;
	get_time(&current);
	get_string_from_time(&current, buffer_system_time);

	// Time elapsed since the start of the test
	struct tm diff_time;
	char time_since_start[80];
	get_time_difference(&current, &test_begin_time, &diff_time);

	get_string_from_time(&diff_time, time_since_start);

	float ber_value = 0;

	if (rx_good_octet != 0)
	{
		ber_value = (float) (rx_error_octet * 8) / (rx_good_octet * 8);
	}

	// Print log info on screen
	if (console_output != 0)
	{
		char txU[100];
		char rxU[100];
		char errU[100];

		// For one slice
		if (number_of_slices == 1)
		{

			sprintf(txU, "%llu", tx_octet);
			sprintf(rxU, "%llu", rx_good_octet);
			sprintf(errU, "%llu", rx_error_octet);

			int y;

			FILE *file = NULL;

			compute_column_size(column_size, columns, title);

			char format[columns][100];

			int frame_length = get_frame_length(column_size, columns);

			strcpy(title[0], time_since_start);

			get_format(format, columns, column_size);
			concatenate_header(format, frame_length, title, columns, file, 0, table_data);

			slice_data(slice, rxU, txU, errU, format, table_data);

			// clear the screen for the next console log
			clear_screen();
		}
		else
		{

			sprintf(txU, "%llu", tx_octet);
			sprintf(rxU, "%llu", rx_good_octet);
			sprintf(errU, "%llu", rx_error_octet);

			int y;

			FILE *file = NULL;

			compute_column_size(column_size, columns, title);

			char format[columns][100];

			int frame_length = get_frame_length(column_size, columns);

			if (counted_slices == 0)
			{
				// Add elapsed time since the start of the test
				strcpy(title[0], time_since_start);
				get_format(format, columns, column_size);
				concatenate_header(format, frame_length, title, columns, file, 0, table_data);
			}

			slice_data(slice, rxU, txU, errU, format, table_data);

			counted_slices++;
			if (number_of_slices == counted_slices)
			{

				// clear the screen for the next console log
//				clear_screen();

				// reset counted slices
				counted_slices = 0;
			}
		}
	}

	// Log data to file
	if (fp != NULL)
	{

		fprintf(fp, "%-15s\t%-15i\t%-15llu\t%-15llu\t%-15llu\t%-15llu\t%-15llu\t%-15llu\t%-15e \n", buffer_system_time, timeCount, rx_good_unit, tx_unit, rx_good_octet, tx_octet,
				rx_error_unit, rx_error_octet, ber_value);
	}
	else
	{
		printf("Cannot open file: NULL POINTER\n");
	}

	return CS_OK;
}

void slice_data(int slice, char rxU[], char txU[], char errU[], char format[][100], char table_data[])
{
	FILE *file = NULL;
	int y;
	if (slice == 0)
	{
		for (y = 1; y < 4; y++)
		{

			switch (y)
			{
			case 1:
				strcpy(slice_0[y], rxU);
				break;
			case 2:
				strcpy(slice_0[y], txU);
				break;
			case 3:
				strcpy(slice_0[y], errU);
				break;
			default:
				break;
			}
		}

		compute_column_size(column_size, columns, slice_0);
		get_format(format, columns, column_size);
		concatenate_columns(format, slice_0, columns, file, 0, table_data);

	}
	else if (slice == 1)
	{
		for (y = 1; y < 4; y++)
		{

			switch (y)
			{
			case 1:
				strcpy(slice_1[y], rxU);
				break;
			case 2:
				strcpy(slice_1[y], txU);
				break;
			case 3:
				strcpy(slice_1[y], errU);
				break;
			default:
				break;
			}
		}

		compute_column_size(column_size, columns, slice_1);
		get_format(format, columns, column_size);
		concatenate_columns(format, slice_1, columns, file, 0, table_data);

	}
	else if (slice == 2)
	{
		for (y = 1; y < 4; y++)
		{

			switch (y)
			{
			case 1:
				strcpy(slice_2[y], rxU);
				break;
			case 2:
				strcpy(slice_2[y], txU);
				break;
			case 3:
				strcpy(slice_2[y], errU);
				break;
			default:
				break;
			}
		}

		compute_column_size(column_size, columns, slice_2);
		get_format(format, columns, column_size);
		concatenate_columns(format, slice_2, columns, file, 0, table_data);

	}
	else if (slice == 3)
	{
		for (y = 1; y < 4; y++)
		{

			switch (y)
			{
			case 1:
				strcpy(slice_3[y], rxU);
				break;
			case 2:
				strcpy(slice_3[y], txU);
				break;
			case 3:
				strcpy(slice_3[y], errU);
				break;
			default:
				break;
			}
		}

		compute_column_size(column_size, columns, slice_3);
		get_format(format, columns, column_size);
		concatenate_columns(format, slice_3, columns, file, 0, table_data);

	}

}

void pbert_config_half_half_test(int protocol, int ports[5], Traffic parameters)
{
//	Traffic parameters;
	int i;

	for (i = 1; i < 5; i++)
	{
		if (ports[0] == 1 || ports[i] == 1)
		{
			parameters.traffic[i - 1] = protocol;
		}
		else
		{
			parameters.traffic[i - 1] = -1;
		}
	}

	parameters.module = 1;
//	parameters.generation_time = gen_time;

	if (parameters.generation_time != -1)
	{
		parameters.console_output = 1;
	}
	else
	{
		parameters.console_output = 0;

	}
	unsigned int j;
	for (j = 0; j < 4; j++)
	{
		if (parameters.traffic[j] != -1)
		{
			if (parameters.traffic[j] == 0)
			{
				print_status("ten_hl_pp10g_config", ten_hl_pp10g_config(parameters.module, j, TEN_PP10G_RX_ETH_0, TEN_PP10G_TX_ETH_0));
				print_status("ten_hl_n10g_config", ten_hl_n10g_config(parameters.module, j, TEN_N10G_RX_OTU2_10GE, TEN_N10G_TX_10GE_OTU2, 1));
			}
			else
			{
				print_status("ten_hl_pp10g_config", ten_hl_pp10g_config(parameters.module, j, TEN_PP10G_RX_ETH_2, TEN_PP10G_TX_ETH_2));
				print_status("ten_hl_n10g_config", ten_hl_n10g_config(parameters.module, j, TEN_N10G_RX_BYPASS, TEN_N10G_TX_BYPASS, 1));
			}
		}
	}

	for (i = 0; i < 4; i++)
	{
		if (parameters.traffic[i] != -1)
		{
			hl_xcon_pbert_config(0, parameters.module, i);
		}
	}

	pbert_traffic_control(parameters);
}

void set_cs6041_loopback(int module, int loopback, int enable, int slices[])
{
	T41_t Chips;
	cs_uint16 dev_id = 0;
	cs_uint16 mod_a;
	cs_uint16 mod_b;

	//Driver initialization
	cs6041_init(dev_id, &Chips, &mod_a, &mod_b);

	// module B
	if (module)
	{
		if (slices[0] == 1)
		{
			if (enable)
			{
				print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback(module, TEN_SLICE_ALL, loopback, CS_ENABLE));
				printf("Enabled loopback in side B in all slices \n");
			}
			else
			{
				print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback(module, TEN_SLICE_ALL, loopback, CS_DISABLE));
				printf("Disabled loopback in side B in all slices \n");
			}
		}
		else
		{
			int slice;
			for (slice = 0; slice < 4; slice++)
			{
				// If the slice is active
				// active then enable or disable loopback
				if (slices[slice + 1] == 1)
				{
					if (enable)
					{
						print_status("ten_hl_hsif_control_loopback", ten_hsif_facility_loopback(module, slice, CS_ENABLE));
						//print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback(module, slice, loopback, CS_ENABLE));
						printf("Enabled loopback in side B in slice %i\n", slice + 1);
					}
					else
					{
						print_status("ten_hl_hsif_control_loopback", ten_hsif_facility_loopback(module, slice, CS_DISABLE));
						//print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback(module, slice, loopback, CS_DISABLE));
						printf("Disabled loopback in side B in slice %i\n", slice + 1);
					}
				}
			}
		}
	}
	// module A
	else
	{
		if (enable)
		{
			print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback(module, TEN_SLICE_ALL, loopback, CS_ENABLE));
			printf("Enabled loopback in side A\n");
		}
		else
		{
			print_status("ten_hl_hsif_control_loopback", ten_hl_hsif_control_loopback(module, TEN_SLICE_ALL, loopback, CS_DISABLE));
			printf("Disabled loopback in side A\n");
		}
	}
}

void cs6041_fecstats_init(int module)
{
	//  CS6041 performance monitoring
	ten_drvr_ctl_stats_hex_format(0);

	ten_drvr_ctl_stats_timing_interval(CS_DISABLE);

	switch (module)
	{
	case 0: // lado de linea
		ten_gfec_40g_set_gi_sel(0, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(0, TEN_ID_GFEC_40G);
		break;
	case 1: // lado de clientes
		ten_gfec_10g_set_excess_error_flag(1, TEN_SLICE_ALL, 0, 0, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(1, TEN_ID_GFEC_10G);
		ten_gfec_40g_set_gi_sel(1, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(1, TEN_ID_GFEC_40G);
		break;
	case 2: // ambos lados
		ten_gfec_40g_set_gi_sel(0, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(0, TEN_ID_GFEC_40G);
		ten_gfec_10g_set_excess_error_flag(1, TEN_SLICE_ALL, 0, 0, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(1, TEN_ID_GFEC_10G);
		ten_gfec_40g_set_gi_sel(1, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(1, TEN_ID_GFEC_40G);
		break;
	default:
		break;
	}

//	ten_gfec_10g_set_excess_error_flag(0, TEN_SLICE_ALL, 0, 0, TEN_SW_TIME_SOURCE);

	// End of CS6041 performance monitoring configuration

}

void cs6041_hardware_information()
{
	T41_t Chips;
	cs_uint16 dev_id = 0;
	cs_uint16 mod_a;
	cs_uint16 mod_b;

	clk_set_osc_400_mhz(1);
	clk_set_osc_684_28_mhz(1);
	clk_set_mux_a(0);
	clk_set_mux_b(1);
	open_upie();

	cs6041_reset();

	ten_drvr_load();

	// Value initialization.
	Chips.mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft;
	Chips.mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;

	ten_dev_register(dev_id, (cs_uint32) &Chips);

	ten_dev_main_init(dev_id);

	cs_uint32 rev_id = ten_mpif_get_chip_rev_id(dev_id);
	cs_uint16 sku = ten_mpif_get_chip_dev_id_code_sku(dev_id);

	switch (sku)
	{
	case 1:
		printf("Número de parte: CS6041 \n");
		break;
	case 2:
		printf("Número de parte: CS6042 \n");
		break;
	case 3:
		printf("Número de parte: CS6043 \n");
		break;
	case 5:
		printf("Número de parte: CS6045 \n");
		break;
	case 6:
		printf("Número de parte: CS6046 \n");
		break;
	case 7:
		printf("Número de parte: CS6049 \n");
		break;
	case 8:
		printf("Número de parte: CS6048 \n");
		break;
	default:
		printf("Número de parte: Unknown \n");
		break;
	}

	printf("Número de revision: %llu\n", rev_id);

	close_upie();
}

void print_status(const char *msg, cs_status status)
{
	if (status == CS_OK)
	{
		printf("%s : CS_OK\n", msg);
	}
	else
	{
		printf("%s : CS_ERROR\n", msg);
	}
}

void print_defects(const char* msg, cs_status status)
{
	if (status == CS_OK)
	{
		printf("%s 0\n", msg);
	}
	else
	{
		printf("%s 1\n", msg);
	}
}

