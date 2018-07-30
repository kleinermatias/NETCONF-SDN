#include "monitor.h"

void INThandler(int);
static FILE *file = 0;
static int edfa_fd;
Monitor *pt_monitor_struct;
char table_data[8000];
int shmfd;

char help[1000] = "\n\nForma de uso:\n\n"
		"MONITOR: ./monitor --modulos --fecstats\n";

unsigned int cant_access_value_to_log = 0;
unsigned int cant_access_check_status_to_log = 0;
unsigned int init_cant_access_value_to_log = 0;
unsigned int init_cant_access_check_status_to_log = 0;
unsigned int wday1 = -1;
unsigned int wday2 = -1;

char msg_status_initious [3000] = "";
char msg_values_initious [3000] = "";
char msg_status[3000] = "";
char msg_value [3000] = "";

unsigned int refresh_time = 3;


typedef struct logging_monitor_struct
{
	char status_power_and_fan[8][100];
	char general_status_temperature[7][100];
	char board_humidity[7][100];

	char presence_xfp[5][100];
	char rx_loss_xfp[5][100];
	char ready_xfp[5][100];
	char interrupt_xfp[5][100];
	char low_tx_power_alarm_xfp[5][100];
	char high_tx_power_alarm_xfp[5][100];
	char low_rx_power_alarm_xfp[5][100];
	char high_rx_power_alarm_xfp[5][100];
	char rx_cdr_loss_of_lock_xfp[5][100];
	char tx_cdr_loss_of_lock_xfp[5][100];
	char laser_fault_condition_xfp[5][100];
	char xfp_tx_power[5][100];	
	char xfp_rx_power[5][100];
	char xfp_temperature[5][100];

	char row_1_edfa[7][100];

	char m40g_row_1[11][100];
	char m40g_row_2[11][100];
	char m40g_row_3[11][100];
	char m40g_row_4[11][100];
	char m40g_row_5[11][100];
	char m40g_row_6[11][100];
	char m40g_row_7[11][100];
	char m40g_row_8[11][100];
	char m40g_row_9[11][100];
	char m40g_row_10[11][100];
	char m40g_row_11[11][100];
	char m40g_row_12[11][100];
	char m40g_row_13[11][100];
	char m40g_row_14[11][100];
	char m40g_row_15[11][100];
	char m40g_row_16[11][100];
	char m40g_row_17[11][100];
	char m40g_row_18[11][100];
	char m40g_row_19[11][100];

} Logging_Monitor;

Logging_Monitor logging_monitor = {0};

int main(int argc, char **argv)
{
	CHECK_PARAM(1,LOG_ERR, 0, "Inicia app monitor",LOG_USER);

	shmfd = shm_open(SHMOBJ_PATH, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
	if (shmfd < 0)
	{
		printf("Error in SHM_OPEN () \n");
		perror("In shm_open()");
		exit(1);
	}

	ftruncate(shmfd, SHM_SIZE);

	pt_monitor_struct = (Monitor *) mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
	if (pt_monitor_struct == NULL)
	{
		printf("Error in mmap() \n");
		perror("In mmap()");
		exit(1);
	}

	// init GPIO
	pio_init();

	// Initialize severity dirty flag
	pt_monitor_struct->sev_dirty_flag = 0;

	// load alarm configuration
	load_alarm_configuration(pt_monitor_struct);

	char message[100];
	char ofim[100];
	char offm[100];
	char ofsm[100];

	struct tm initial_time ={ 0 };
	char buffer_system_time[80] = { 0 };
	char buffer_diff[80] = { 0 };
	char time_stamp[200] = { 0 };
	struct tm current_time = { 0 };
	struct tm diff_time = { 0 };

	T41_t Chips;
	cs_uint16 dev_id = 0;
	cs_uint16 mod_a;
	cs_uint16 mod_b;

	int c;

	unsigned int over_temp_led_status = 0;

	unsigned char xfp_monitor = 0;
	unsigned char env_monitor = 0;
	unsigned char power_fan_monitor = 0;
	unsigned char cs6041_monitor = 0;
	unsigned char edfa_monitor = 0;
	unsigned char mod_40g_monitor = 0;
	unsigned char fpga_monitor = 0;
	unsigned char summary = 0;
	unsigned char general = 0;
	unsigned char fec_monitor = 0;
	unsigned char mod_monitor = 0;
	unsigned char stats_monitor = 0;

	int option_index = 0;
	// Struct to translate long options (--) to short options (-)
	struct option long_options[] =
	{
			{ "modulos", no_argument, NULL, 'm' },
			{ "fecstats", no_argument, NULL, 'f' },
			{ "version", no_argument, NULL, 'v' },
			{ "ayuda", no_argument, NULL, '?' },
			{ 0, 0, 0, 0 }, };

	while (1)
	{
		option_index = 0;

		c = getopt_long(argc, argv, "mfv?", long_options, &option_index);

		//Detect the end of the options.
		if (c == -1)
		{
			break;
		}

		switch (c)
		{
		case 'm':
			mod_monitor = 1;
			break;

		case 'f':
			stats_monitor = 1;
			break;

		case 'v':
			printf("\n\nVersion: %s\n\n", MONITOR);
			return 0;

		case '?':
			printf("%s", help);
			return 0;

		case 'r':
			refresh_time = atoi(optarg);
			break;

		default:
			return 0;
		}
	}

	int fd_lock;
	fd_lock=filelock_open("fec_lock");

	printf("table refresh time '%d'\n", refresh_time);

	time_t start_time;
	start_time = time(0);

	struct tm *start_st;
	char buffer_start[80];
	start_st = localtime(&start_time);
	strftime(buffer_start, sizeof(buffer_start), "%Y-%m-%d %H:%M:%S", start_st);

	if (mod_monitor == 1 && stats_monitor == 1)
	{
		xfp_monitor = 1;
		env_monitor = 1;
		power_fan_monitor = 1;
		cs6041_monitor = 1;
		edfa_monitor = 1;
		mod_40g_monitor = 1;
		fpga_monitor = 1;
		summary = 1;
		general = 1;
		fec_monitor = 1;
	}
	else if (stats_monitor == 1)
	{
		xfp_monitor = 0;
		env_monitor = 0;
		power_fan_monitor = 0;
		cs6041_monitor = 0;
		edfa_monitor = 0;
		mod_40g_monitor = 0;
		fpga_monitor = 0;
		summary = 0;
		general = 0;
		fec_monitor = 1;
	}
	else
	{
		xfp_monitor = 1;
		env_monitor = 1;
		power_fan_monitor = 1;
		cs6041_monitor = 1;
		edfa_monitor = 1;
		mod_40g_monitor = 1;
		fpga_monitor = 1;
		summary = 1;
		general = 1;
		fec_monitor = 0;
	}

	txp_enable_debug(0);
	get_time(&initial_time);

	unsigned int log_file = 0;

	signal(SIGINT, INThandler);

	int log_count = 0;
	int free_memory_count = 0;

	char edfa_tty[] = "/dev/ttyAL2";
	edfa_fd = open(edfa_tty, O_RDWR | O_NOCTTY | O_NONBLOCK);
	edfa_set_terminal(edfa_fd);
	edfa_clean_fifo(edfa_fd);

	int xfp_initial_config = 1;
	int hmd_tmp_initial_config = 1;

	if (fec_monitor)
	{
		// Configure FEC statistics
		open_upie();
		sleep(1);
		//	ten_drvr_unload();
		cs6041_init(dev_id, &Chips, &mod_a, &mod_b);
		sleep(1);

		cs6041_fecstats_init(2); // FEC statistics from both modules

		/*
		// N40G STATISTICS (MODULE 0, A)
		ten_n40g_otnr4x_select_global_timing_source(0, TEN_SW_TIME_SOURCE);
		ten_n40g_sdfr_select_global_timing_source(0, TEN_SW_TIME_SOURCE);
		ten_n40g_oohr_cfg5_bipssel(0, TEN_SW_TIME_SOURCE);
		ten_n40g_oohr_cfg5_beissel(0, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(0, TEN_ID_N40G);

		// N10G STATISTICS (MODULE 1, B)
		ten_n10g_otnr_select_global_timing_source(1, TEN_SLICE_ALL, TEN_SW_TIME_SOURCE);
		ten_n10g_sdfr_select_global_timing_source(1, TEN_SLICE_ALL, TEN_SW_TIME_SOURCE);
		ten_n10g_oohr_cfg5_bipssel(1, TEN_SLICE_ALL, TEN_SW_TIME_SOURCE);
		ten_n10g_oohr_cfg5_beissel(1, TEN_SLICE_ALL, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(1, TEN_ID_N10G);
		 */

		// SYNCDSYNC STATISTICS (MODULE 1, B)
		//		ten_syncdsyncrx_select_global_timing_source(1, TEN_SLICE_ALL, TEN_SW_TIME_SOURCE);
		//		ten_syncdsynctx_select_global_timing_source(1, TEN_SLICE_ALL, TEN_SW_TIME_SOURCE);
		//		ten_mod_clear_blk_stats(1, TEN_ID_SYNCDSYNC);
		//		ten_syncdsync_stats_t stats_syncdsync;


		// GFEC STATISTICS (10G / 40G)
		ten_gfec_40g_set_gi_sel(0, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(0, TEN_ID_GFEC_40G);
		ten_gfec_10g_set_excess_error_flag(1, TEN_SLICE_ALL, 0, 0, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(1, TEN_ID_GFEC_10G);
		ten_gfec_40g_set_gi_sel(1, TEN_SW_TIME_SOURCE);
		ten_mod_clear_blk_stats(1, TEN_ID_GFEC_40G);
	}

	while (1)
	{
		clear_screen();
		get_time(&current_time);
		get_string_from_time(&current_time, buffer_system_time);

		get_time_difference(&current_time, &initial_time, &diff_time);
		get_string_from_time(&diff_time, buffer_diff);

		sprintf(time_stamp, "%25s%3c%20s\n", buffer_system_time, '|', buffer_diff);

		logger(time_stamp, file, log_file);

		// If a change was made on the severity alarm values
		// rewrite the alarms xml file
		if (pt_monitor_struct->sev_dirty_flag == 1)
		{
			update_alarm_configuration_file(*pt_monitor_struct);

			// Set dirty flag down
			pt_monitor_struct->sev_dirty_flag = 0;
		}

		if (power_fan_monitor)
		{
			unsigned int ps_id;
			unsigned int fan_led_status = 0;
			unsigned int fan_id;

			for (ps_id = STDBY_48V_ONE; ps_id >= STDBY_48V_TWO; ps_id--)
			{
				ps_get_status(ps_id, &pt_monitor_struct->general_struct.power_value[STDBY_48V_ONE - ps_id]);
			}

			set_led_status(LED_POWER_1, !pt_monitor_struct->general_struct.power_value[0]);
			set_led_status(LED_POWER_2, !pt_monitor_struct->general_struct.power_value[1]);

			for (fan_id = FAN1_ALERT; fan_id >= FAN5_ALERT; fan_id--)
			{
				fan_get_alert(fan_id, &pt_monitor_struct->general_struct.fan_value[FAN1_ALERT - fan_id]);
				fan_led_status += !pt_monitor_struct->general_struct.fan_value[FAN1_ALERT - fan_id];
			}

			set_led_status(LED_FAN_1, !fan_led_status);

			power_and_fan_status(pt_monitor_struct->general_struct.power_value, pt_monitor_struct->general_struct.fan_value, file, log_file);
		}

		if (xfp_monitor)
		{
			int i;
			int xfp_module;
			unsigned int xfp_led_status = 0;

			for (xfp_module = XFP_MOD_0; xfp_module <= XFP_MOD_3; xfp_module++)
			{
				xfp_led_status = 0;

				for (i = 0; i < 7; i++)
					pt_monitor_struct->xfp_struct.xfp_interruption_flags[xfp_module][i] = 0;

				if (xfp_initial_config)
				{
					xfp_enable_communication(xfp_module);
					ltc_enable_latch();
					xfp_get_interruption_flags(xfp_module, pt_monitor_struct->xfp_struct.xfp_interruption_flags);
				}

				//Indicates Module is not present. Grounded in the Module.
				xfp_get_presence_status(xfp_module, &pt_monitor_struct->xfp_struct.xfp_presence[xfp_module]);
				xfp_led_status += pt_monitor_struct->xfp_struct.xfp_presence[xfp_module];

				//Receiver Loss of Signal Indicator. The RX_LOS when High indicates insufficient optical power for reliable signal reception.
				xfp_get_loss_of_signal_status(xfp_module, &pt_monitor_struct->xfp_struct.xfp_rx_loss[xfp_module]);
				xfp_led_status += pt_monitor_struct->xfp_struct.xfp_rx_loss[xfp_module];

				//Module Not Ready; Indicating Module Operational Fault. When High, indicates that the module has detected a condition
				//that renders transmitter and or receiver data invalid, shall consist of logical OR of the following signals:
				//A) Transmit Signal Conditioner Loss of Lock.
				//B) Transmitter Laser Fault.
				//C) Receiver Signal Conditioner Loss of Lock.
				xfp_get_ready_status(xfp_module, &pt_monitor_struct->xfp_struct.xfp_ready[xfp_module]);
				xfp_led_status += pt_monitor_struct->xfp_struct.xfp_ready[xfp_module];

				//Indicates presence of an important condition which can be read over the 2-wire serial interface
				//When “Low”, indicates possible module operational fault or a status critical to the host system.
				xfp_read_interruption(xfp_module, &pt_monitor_struct->xfp_struct.xfp_interrupt[xfp_module]);
				xfp_led_status += !pt_monitor_struct->xfp_struct.xfp_interrupt[xfp_module];

				//Reads interruption flags only for incoming interruptions
				if (!pt_monitor_struct->xfp_struct.xfp_interrupt[xfp_module])
				{
					xfp_get_interruption_flags(xfp_module, pt_monitor_struct->xfp_struct.xfp_interruption_flags);
				}

				//Reads the tx power.
				xfp_get_tx_power(xfp_module, &pt_monitor_struct->xfp_struct.xfp_tx_power[xfp_module]);

				//Reads the rx power.
				xfp_get_rx_power(xfp_module, &pt_monitor_struct->xfp_struct.xfp_rx_power[xfp_module]);

				set_led_status(xfp_led_green[xfp_module], xfp_led_status);
				set_led_status(xfp_led_red[xfp_module], !xfp_led_status);

				//Gets the temperature of XFP modules.
				xfp_get_temperature(xfp_module, &pt_monitor_struct->xfp_struct.xfp_temperature[xfp_module]);

				over_temp_led_status += xfp_protect_action(file, pt_monitor_struct->xfp_struct.xfp_temperature[xfp_module] >= XFP_OVERTEMP, xfp_module);
			}

			xfp_initial_config = 0;

			xfp_status(pt_monitor_struct->xfp_struct.xfp_presence, pt_monitor_struct->xfp_struct.xfp_rx_loss, pt_monitor_struct->xfp_struct.xfp_ready,
					pt_monitor_struct->xfp_struct.xfp_interrupt, pt_monitor_struct->xfp_struct.xfp_tx_power, pt_monitor_struct->xfp_struct.xfp_rx_power,
					pt_monitor_struct->xfp_struct.xfp_temperature, pt_monitor_struct->xfp_struct.xfp_interruption_flags, file, log_file);
		}

		if (general)
		{
			unsigned int i;
			pt_monitor_struct->general_struct.board_temperature = 0;

			if (hmd_tmp_initial_config)
			{
				hmd_enable_chip_select();
				hmd_tmp_initial_config = 0;
			}

			for (i = 0; i < 4; i++)
			{
				tmp_get_ext_temp(TMP_REMOTE_6_REG - i, &pt_monitor_struct->general_struct.cs6041_temperature[i]);

				if (i != 0)
				{
					over_temp_led_status += cs6041_protect_action(file, pt_monitor_struct->general_struct.cs6041_temperature[i] >= CS6041_OVERTEMP);
				}
			}

			//cs6041_status(cs6041_temperature, file, log_file);

			tmp_get_ext_temp(TMP_REMOTE_7_REG, &pt_monitor_struct->general_struct.fpga_temperature);
			//fpga_status(&fpga_temperature, file, log_file);



			hmd_get_temperature(&pt_monitor_struct->general_struct.board_temperature);
			hmd_get_temp_comp_humidity(&pt_monitor_struct->general_struct.board_humidity);

			//board_status(&board_temperature, &board_humidity, file, log_file);

			general_status(pt_monitor_struct->general_struct.cs6041_temperature, &pt_monitor_struct->general_struct.fpga_temperature,
					&pt_monitor_struct->general_struct.board_temperature, &pt_monitor_struct->general_struct.board_humidity, file, log_file);
		}

		if (edfa_monitor)
		{
			int i;

			int fd_lock_edfa;
			fd_lock_edfa = filelock_open("edfa_lock");
			if(filelock_lock_timeout(fd_lock_edfa, 0) != -1){
				for (i = 0; i < sizeof(pt_monitor_struct->edfa_struct.edfa_output_power); i++)
					pt_monitor_struct->edfa_struct.edfa_output_power[i] = '\0';

				edfa_get_output_power(edfa_fd, pt_monitor_struct->edfa_struct.edfa_output_power);
				edfa_clean_data(pt_monitor_struct->edfa_struct.edfa_output_power);

				for (i = 0; i < sizeof(pt_monitor_struct->edfa_struct.edfa_input_power); i++)
					pt_monitor_struct->edfa_struct.edfa_input_power[i] = '\0';

				edfa_get_input_power(edfa_fd, pt_monitor_struct->edfa_struct.edfa_input_power);
				edfa_clean_data(pt_monitor_struct->edfa_struct.edfa_input_power);

				for (i = 0; i < sizeof(pt_monitor_struct->edfa_struct.edfa_temperature); i++)
					pt_monitor_struct->edfa_struct.edfa_temperature[i] = '\0';

				edfa_get_case_temperature(edfa_fd, pt_monitor_struct->edfa_struct.edfa_temperature);
				edfa_clean_data(pt_monitor_struct->edfa_struct.edfa_temperature);

				for (i = 0; i < sizeof(pt_monitor_struct->edfa_struct.edfa_los); i++)
					pt_monitor_struct->edfa_struct.edfa_los[i] = '\0';

				edfa_get_alarm_information(edfa_fd, EDFA_ALARM_LOS, EDFA_ALARM_PARAM_STA, pt_monitor_struct->edfa_struct.edfa_los);
				edfa_clean_data(pt_monitor_struct->edfa_struct.edfa_los);

				for (i = 0; i < sizeof(pt_monitor_struct->edfa_struct.edfa_lop); i++)
					pt_monitor_struct->edfa_struct.edfa_lop[i] = '\0';

				edfa_get_alarm_information(edfa_fd, EDFA_ALARM_LOP, EDFA_ALARM_PARAM_STA, pt_monitor_struct->edfa_struct.edfa_lop);
				edfa_clean_data(pt_monitor_struct->edfa_struct.edfa_lop);

				for (i = 0; i < sizeof(pt_monitor_struct->edfa_struct.edfa_amp_status); i++)
					pt_monitor_struct->edfa_struct.edfa_amp_status[i] = '\0';

				edfa_get_amplifier_status(edfa_fd, pt_monitor_struct->edfa_struct.edfa_amp_status);
				edfa_clean_data(pt_monitor_struct->edfa_struct.edfa_amp_status);

				//report_fault_condition(!edfa_loss_alarm, " Loss Of Signal at EDFA input port.", format_status_msg(ofsm, " The Loss Of Signal at EDFA input port %s OK.\n", edfa_loss_alarm));
			}

			filelock_close(fd_lock_edfa);

			edfa_status(&pt_monitor_struct->edfa_struct, file, log_file);
		}

		if (mod_40g_monitor)
		{
			tmp_get_ext_temp(TMP_REMOTE_1_REG, &pt_monitor_struct->txp_struct.txp_temperature[0]);

			txp_read_transponder_temperature_monitor(&pt_monitor_struct->txp_struct.txp_temperature[1]);
			over_temp_led_status += txp_protect_action(file, pt_monitor_struct->txp_struct.txp_temperature[1] >= TXP_CASE_OVERTEMP);

			txp_read_transmit_laser_transponder_temperature_monitor(&pt_monitor_struct->txp_struct.txp_temperature[2]);
			over_temp_led_status += txp_protect_action(file, pt_monitor_struct->txp_struct.txp_temperature[2] >= TXP_TX_LASER_OVERTEMP);

			txp_read_receive_laser_transponder_temperature_monitor(&pt_monitor_struct->txp_struct.txp_temperature[3]);

			// Read loss input alarm at Oclaro pin MOD_40G_LOS.
			txp_read_loss_input_alarm(&pt_monitor_struct->txp_struct.txp_loss);
			// Read interrupt at Oclaro pin STAT_INT.
			txp_read_interrupt_input_alarm(&pt_monitor_struct->txp_struct.txp_interrupt);

			// Read Laser Output Power Monitor
			txp_read_transmit_laser_power_monitor(&pt_monitor_struct->txp_struct.txp_tx_power);
			txp_read_receiver_laser_power_monitor(&pt_monitor_struct->txp_struct.txp_rx_power);

			// Read TX Alarm Status Register 0x80
			txp_read_tx_alarm_status_register(&pt_monitor_struct->txp_struct.txp_tx_alarm);
			// Read RX Alarm Status Register 0x81
			txp_read_rx_alarm_status_register(&pt_monitor_struct->txp_struct.txp_rx_alarm);

			txp_read_power_supply_alarm_status_register(&pt_monitor_struct->txp_struct.txp_power_alarm);

			txp_read_dsp_status(&pt_monitor_struct->txp_struct.txp_dspstat);

			txp_read_mean_squared_error(&pt_monitor_struct->txp_struct.txp_mse);

			txp_read_ber_estimate(&pt_monitor_struct->txp_struct.txp_ber_estimate);

			txp_read_laser_itu_channel(&pt_monitor_struct->txp_struct.txp_tx_laser_itu_channel);
			txp_read_receiver_itu_channel(&pt_monitor_struct->txp_struct.txp_rx_laser_itu_channel);

			txp_read_bulk_cd_compensation(&pt_monitor_struct->txp_struct.txp_bulk_cd);

			hl_txp_get_chromatic_dispersion(&pt_monitor_struct->txp_struct.txp_chromatic_dispersion);

			m40g_status(&pt_monitor_struct->txp_struct, file, log_file);
		}

		set_led_status(LED_TEMP, !over_temp_led_status);

		if (free_memory_count >= 3600)
		{
			system("sync && sysctl -w vm.drop_caches=3");

			free_memory_count = 0;
		}
		free_memory_count++;

		printf("%s", table_data);
		memset(table_data, 0, sizeof(table_data));

		sleep(refresh_time);

		if (fec_monitor)
		{
			int flockto_status;
			flockto_status = filelock_lock_timeout(fd_lock, 1);
			if (flockto_status != -1) {

				clear_screen();

				// FEC statistics
				ten_gfec_40g_stats_t stats_40ga;
				ten_gfec_40g_stats_t stats_40gb;
				ten_gfec_10g_stats_t stats_10g;
				ten_glb_misc_gsti_update(0, 1, 0);

				// READ GFEC STATISTICS
				ten_mod_get_blk_stats(0, TEN_ID_GFEC_40G, &stats_40ga, sizeof(stats_40ga));
				ten_mod_get_blk_stats(1, TEN_ID_GFEC_40G, &stats_40gb, sizeof(stats_40gb));
				ten_mod_get_blk_stats(1, TEN_ID_GFEC_10G, &stats_10g, sizeof(stats_10g));

				printf("-------------------------------------------------------\n");
				printf("               ESTADISTICAS FEC LADO LINEA             \n");
				printf("-------------------------------------------------------\n");
				ten_mod_print_blk_stats(0, TEN_ID_GFEC_40G);

				printf("\n\n");
				printf("-------------------------------------------------------\n");
				printf("              ESTADISTICAS FEC LADO CLIENTES           \n");
				printf("-------------------------------------------------------\n");
				ten_mod_print_blk_stats(1, TEN_ID_GFEC_40G);
				ten_mod_print_blk_stats(1, TEN_ID_GFEC_10G);

				//			ten_mod_clear_blk_stats(0, TEN_ID_GFEC_40G);
				//			ten_mod_clear_blk_stats(1, TEN_ID_GFEC_40G);
				//			ten_mod_clear_blk_stats(1, TEN_ID_GFEC_10G);

				printf("\n\n");

				// Read Defects
				pt_monitor_struct->tp_defects_struct.tp_line_los_status.data = ten_n40g_get_global_los_status(0);
				pt_monitor_struct->tp_defects_struct.tp_line_framer_status.data = ten_n40g_otnr4x_get_otu_framer_status(0);
				pt_monitor_struct->tp_defects_struct.tp_line_section_mon.data = ten_n40g_oohr_get_sm_status(0, TEN_NX0G_OOHR_SM_STATUS_ALL);
				pt_monitor_struct->tp_defects_struct.tp_line_path_mon.data = ten_n40g_oohr_get_pm_status(0, TEN_NX0G_OOHR_SM_STATUS_ALL);

				pt_monitor_struct->tp_defects_struct.tp_client_los_status[0].data = ten_n10g_get_global_losf_status(1, TEN_SLICE0);
				pt_monitor_struct->tp_defects_struct.tp_client_framer_status[0].data = ten_n10g_get_otu_framer_status(1, TEN_SLICE0, TEN_NX0G_OTNR_OFSTAT_ALL);
				pt_monitor_struct->tp_defects_struct.tp_client_section_mon[0].data = ten_n10g_oohr_get_sm_status(1, TEN_SLICE0, TEN_NX0G_OOHR_SM_STATUS_ALL);
				pt_monitor_struct->tp_defects_struct.tp_client_path_mon[0].data = ten_n10g_oohr_get_pm_status(1, TEN_SLICE0, TEN_NX0G_OOHR_PM_STATUS_ALL);

				pt_monitor_struct->tp_defects_struct.tp_client_los_status[1].data = ten_n10g_get_global_losf_status(1, TEN_SLICE1);
				pt_monitor_struct->tp_defects_struct.tp_client_framer_status[1].data = ten_n10g_get_otu_framer_status(1, TEN_SLICE1, TEN_NX0G_OTNR_OFSTAT_ALL);
				pt_monitor_struct->tp_defects_struct.tp_client_section_mon[1].data = ten_n10g_oohr_get_sm_status(1, TEN_SLICE1, TEN_NX0G_OOHR_SM_STATUS_ALL);
				pt_monitor_struct->tp_defects_struct.tp_client_path_mon[1].data = ten_n10g_oohr_get_pm_status(1, TEN_SLICE1, TEN_NX0G_OOHR_PM_STATUS_ALL);

				pt_monitor_struct->tp_defects_struct.tp_client_los_status[2].data = ten_n10g_get_global_losf_status(1, TEN_SLICE2);
				pt_monitor_struct->tp_defects_struct.tp_client_framer_status[2].data = ten_n10g_get_otu_framer_status(1, TEN_SLICE2, TEN_NX0G_OTNR_OFSTAT_ALL);
				pt_monitor_struct->tp_defects_struct.tp_client_section_mon[2].data = ten_n10g_oohr_get_sm_status(1, TEN_SLICE2, TEN_NX0G_OOHR_SM_STATUS_ALL);
				pt_monitor_struct->tp_defects_struct.tp_client_path_mon[2].data = ten_n10g_oohr_get_pm_status(1, TEN_SLICE2, TEN_NX0G_OOHR_PM_STATUS_ALL);

				pt_monitor_struct->tp_defects_struct.tp_client_los_status[3].data = ten_n10g_get_global_losf_status(1, TEN_SLICE3);
				pt_monitor_struct->tp_defects_struct.tp_client_framer_status[3].data = ten_n10g_get_otu_framer_status(1, TEN_SLICE3, TEN_NX0G_OTNR_OFSTAT_ALL);
				pt_monitor_struct->tp_defects_struct.tp_client_section_mon[3].data = ten_n10g_oohr_get_sm_status(1, TEN_SLICE3, TEN_NX0G_OOHR_SM_STATUS_ALL);
				pt_monitor_struct->tp_defects_struct.tp_client_path_mon[3].data = ten_n10g_oohr_get_pm_status(1, TEN_SLICE3, TEN_NX0G_OOHR_PM_STATUS_ALL);

				// PRINT DEFECTS
				printf("-----------------------------------------------------------\n");
				printf("               DEFECTOS LADO LINEA             \n");
				printf("-----------------------------------------------------------\n");
				printf("LOS STATUS:                             %u\n", (int)pt_monitor_struct->tp_defects_struct.tp_line_los_status.data);
				printf("OTU Framer Status:              	"); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_line_framer_status.data); printf("\n");
				printf("OTUk Section Monitoring Status: 	"); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_line_section_mon.data); printf("\n");
				printf("ODUk Path Monitoring Status: 	 	"); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_line_path_mon.data); printf("\n");

				printf("-----------------------------------------------------------\n");
				printf("               DEFECTOS LADO CLIENTES               \n");
				printf("-----------------------------------------------------------\n");
				printf("LOS STATUS:                             S0: %u \t S1: %u \t S2: %u \t S3: %u\n\n", (int)pt_monitor_struct->tp_defects_struct.tp_client_los_status[0].data
						, (int)pt_monitor_struct->tp_defects_struct.tp_client_los_status[1].data
						, (int)pt_monitor_struct->tp_defects_struct.tp_client_los_status[2].data
						, (int)pt_monitor_struct->tp_defects_struct.tp_client_los_status[3].data);
				printf("OTU Framer Status:\n");
				printf ("S0: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_framer_status[0].data); printf ("    ");
				printf ("S1: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_framer_status[1].data); printf ("    ");
				printf ("S2: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_framer_status[2].data); printf ("    ");
				printf ("S3: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_framer_status[3].data); printf("\n\n");
				printf("OTUk Section Monitoring Status:\n");
				printf ("S0: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_section_mon[0].data); printf ("    ");
				printf ("S1: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_section_mon[1].data); printf ("    ");
				printf ("S2: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_section_mon[2].data); printf ("    ");
				printf ("S3: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_section_mon[3].data); printf("\n\n");
				printf("ODUk Path Monitoring Status:\n");
				printf ("S0: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_path_mon[0].data); printf ("    ");
				printf ("S1: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_path_mon[1].data); printf ("    ");
				printf ("S2: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_path_mon[2].data); printf ("    ");
				printf ("S3: "); bin_prnt_int((int)pt_monitor_struct->tp_defects_struct.tp_client_path_mon[3].data); printf("\n\n");

				printf("\n\n");

				// READ N40G STATISTICS
				//			ten_n40g_stats_t stats_n40ga;
				//			ten_glb_misc_gsti_update(0, 1, 0);
				//			ten_mod_get_blk_stats(0, TEN_ID_N40G, &stats_n40ga, sizeof(stats_n40ga));
				//			ten_mod_print_blk_stats(0, TEN_ID_N40G);

				/*
			// READ N10G STATISTICS
			ten_n10g_stats_t stats_n10gb;
			ten_glb_misc_gsti_update(1, 1, 0);
			ten_mod_get_blk_stats(1, TEN_ID_N10G, &stats_n10gb, sizeof(stats_n10gb));
			ten_mod_print_blk_stats(1, TEN_ID_N10G);

			printf("\n\n");
				 */

				// READ SYNCDSYNC STATISTICS
				//			ten_glb_misc_gsti_update(1, 1, 0);
				//			ten_mod_get_blk_stats(1, TEN_ID_SYNCDSYNC, &stats_syncdsync, sizeof(stats_syncdsync));
				//			ten_mod_print_blk_stats(1, TEN_ID_SYNCDSYNC);

				/*
			// READ 10G WAN STATISTICS
			printf("10GE WAN GFP Interrupt Status Register: \n");
			printf("SLICE 0: \n"); bin_prnt_int((int)ten_pp10g_gfp_rx_get_status(1, TEN_SLICE0, TEN_PP10G_GFP_RX_STATUS_ALL)); printf("\n");
			printf("SLICE 1: \n"); bin_prnt_int((int)ten_pp10g_gfp_rx_get_status(1, TEN_SLICE1, TEN_PP10G_GFP_RX_STATUS_ALL)); printf("\n");
			printf("SLICE 2: \n"); bin_prnt_int((int)ten_pp10g_gfp_rx_get_status(1, TEN_SLICE2, TEN_PP10G_GFP_RX_STATUS_ALL)); printf("\n");
			printf("SLICE 3: \n"); bin_prnt_int((int)ten_pp10g_gfp_rx_get_status(1, TEN_SLICE3, TEN_PP10G_GFP_RX_STATUS_ALL)); printf("\n");
				 */
				//			ten_mod_print_stats(0);
				filelock_unlock(fd_lock);

				sleep (MONITOR_SLEEP_TIME);
			}

		}
	}
	filelock_close(fd_lock);

	return 0;
}


void bin_prnt_byte(char x)
{
	int n;
	for(n=0; n<8; n++)
	{
		if((x & 0x80) !=0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		if (n==3)
		{
			printf(" "); /* insert a space between nybbles */
		}
		x = x<<1;
	}
}

void bin_prnt_int(int x)
{
	int hi, lo;
	hi=(x>>8) & 0xff;
	lo=x&0xff;
	bin_prnt_byte(hi);
	printf(" ");
	bin_prnt_byte(lo);
}

void INThandler(int sig)
{
	char c;

	signal(sig, SIG_IGN);

	printf("\nDo you really want to quit? [y/n]:\n");

	c = getchar();

	if (c == 'y' || c == 'Y')
	{
		if (file != 0)
		{
			if (close(shmfd) != 0)
			{
				printf("Error closing the SHM \n");
			}
			else
			{
				shm_unlink(SHMOBJ_PATH);
			}

			fclose(file);
			close(edfa_fd);

			printf("\n Close log file and exit.\n");
			exit(0);
		}
		else
			exit(0);
	}
	else
	{
		signal(SIGINT, INThandler);
	}

	getchar();
}

char* format_int_msg(char* ofim, char* msg, int value)
{
	sprintf(ofim, msg, value);

	return ofim;
}

char* format_float_msg(char* offm, char* msg, float value)
{
	sprintf(offm, msg, value);

	return offm;
}

char* format_status_msg(char* ofsm, char* msg, unsigned int value)
{
	if (value)
		sprintf(ofsm, msg, "is");
	else
		sprintf(ofsm, msg, "is not");

	return ofsm;
}

unsigned int hardware_check(unsigned int device)
{
	unsigned int hw_led_status;
	int identifier;

	device = QSFP;

	ltc_enable_latch();

	switch (device)
	{
	case QSFP:

		qsfp_reset();
		qsfp_enable_communication();
		qsfp_get_id(&identifier);
		printf("Qsfp identifier: %X\n", identifier);
		break;

	case ALL_DEV:

		break;

	default:

		break;
	}

	return hw_led_status;
}

/*
void power_supply_status(unsigned int power_a, unsigned int power_b, FILE *file, unsigned int log_file)
{

	char general_status[2][100] =
	{ "Off", "On" };
	char title[3][100] = {{ "       " }, { "Power A" }, { "Power B" } };
	char power_status[3][100] =
	{
			{ "Status" } };
	char format[3][100] =
	{
			{ "%20s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" } };

	strcpy(power_status[1], general_status[power_a]);
	strcpy(power_status[2], general_status[power_b]);

	concatenate_header(format, 89, title, 3, file, log_file, table_data);
	concatenate_columns(format, power_status, 3, file, log_file, table_data);
}

void fan_status(unsigned int* fan_value, FILE *file, unsigned int log_file)
{
	unsigned int i;

	char general_status[2][100] =
	{ "Off", "On" };
	char title[6][100] =
	{
			{ "       " },
			{ "Fan 1" },
			{ "Fan 2" },
			{ "Fan 3" },
			{ "Fan 4" },
			{ "Fan 5" } };
	char fan_status[6][100] =
	{
			{ "Status" } };
	char format[6][100] =
	{
			{ "%20s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" } };

	for (i = 1; i <= 5; i++)
	{
		strcpy(fan_status[i], general_status[fan_value[i - 1]]);
	}

	concatenate_header(format, 89, title, 6, file, log_file, table_data);
	concatenate_columns(format, fan_status, 6, file, log_file, table_data);

}
 */

void power_and_fan_status(unsigned int* power_value, unsigned int* fan_value, FILE *file, unsigned int log_file)
{
	unsigned int i;
	char general_status[2][100] =
	{ "Off", "On" };

	char msg [100] ="";

	char title[8][100] =
	{
			{ "       " },
			{ "Power B" },
			{ "Power A" },
			{ "Fan 1" },
			{ "Fan 2" },
			{ "Fan 3" },
			{ "Fan 4" },
			{ "Fan 5" } };

	char status[8][100] =
	{
			{ "Status" } };

	char format[8][100] =
	{
			{ "%20s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" } };

	for (i = 1; i <= 2; i++)
	{
		strcpy(status[i], general_status[!power_value[i - 1]]);
		check_status_to_log(logging_monitor.status_power_and_fan[i] ,status[i], title[i], "");
	}

	for (i = 3; i <= 7; i++)
	{
		strcpy(status[i], general_status[fan_value[i - 3]]);
		check_status_to_log(logging_monitor.status_power_and_fan[i],status[i], title[i], "");
	}

	concatenate_header(format, 115, title, 8, file, log_file, table_data);
	concatenate_columns(format, status, 8, file, log_file, table_data);
}

void xfp_status(unsigned int* xfp_presence, unsigned int* xfp_rx_loss, unsigned int* xfp_ready, unsigned int* xfp_interrupt, float* xfp_tx_power, float* xfp_rx_power,
		float* xfp_temperature, unsigned int xfp_interruption_flags[4][7], FILE *file, unsigned int log_file)
{
	unsigned int i, j;

	char msg [100] ="";

	char general_status[2][100] =
	{ "No", "Yes" };
	char title[5][100] =
	{
			{ "       " },
			{ "XFP 1" },
			{ "XFP 2" },
			{ "XFP 3" },
			{ "XFP 4" } };
	char presence[5][100] =
	{
			{ "Presence" } };
	char rx_loss[5][100] =
	{
			{ "Loss" } };
	char ready[5][100] =
	{
			{ "Ready" } };
	char interrupt[5][100] =
	{
			{ "Interrupt" } };
	char tx_power[5][100] =
	{
			{ "Tx Power [dBm]" } };
	char rx_power[5][100] =
	{
			{ "Rx Power [dBm]" } };
	char temperature[5][100] =
	{
			{ "Temp. [C]" } };
	char format[5][100] =
	{
			{ "%20s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" } };

	char low_tx_power_alarm[5][100] =
	{ "Low Tx Power Alarm" };
	char high_tx_power_alarm[5][100] =
	{ "High Tx Power Alarm" };
	char low_rx_power_alarm[5][100] =
	{ "Low Rx Power Alarm" };
	char high_rx_power_alarm[5][100] =
	{ "High Rx Power Alarm" };
	char rx_cdr_loss_of_lock[5][100] =
	{ "Rx CDR Loss of Lock" };
	char tx_cdr_loss_of_lock[5][100] =
	{ "Tx CDR Loss of Lock" };
	char laser_fault_condition[5][100] =
	{ "Laser Fault" };
	char alarm[2][100] =
	{ "--", "Alarm" };

	for (i = 1; i <= 4; i++)
	{
		strcpy(presence[i], general_status[!xfp_presence[i - 1]]);
		check_status_to_log(logging_monitor.presence_xfp[i], presence[i], title[i],presence[0]);

		strcpy(rx_loss[i], general_status[xfp_rx_loss[i - 1]]);
		check_status_to_log(logging_monitor.rx_loss_xfp[i], rx_loss[i],title[i], rx_loss[0]);

		strcpy(ready[i], general_status[!xfp_ready[i - 1]]);
		check_status_to_log(logging_monitor.ready_xfp[i], ready[i], title[i], ready[0]);

		strcpy(interrupt[i], general_status[!xfp_interrupt[i - 1]]);
		check_status_to_log(logging_monitor.interrupt_xfp[i], interrupt[i], title[i], interrupt[0]);

		sprintf(tx_power[i], "%.2f", xfp_tx_power[i - 1]);
		value_to_log(logging_monitor.xfp_tx_power[i],tx_power[i], title[i], tx_power[0]);

		sprintf(rx_power[i], "%.2f", xfp_rx_power[i - 1]);
		value_to_log(logging_monitor.xfp_rx_power[i],rx_power[i], title[i], rx_power[0]);

		sprintf(temperature[i], "%.2f", xfp_temperature[i - 1]);
		value_to_log(logging_monitor.xfp_temperature[i],temperature[i], title[i], temperature[0]);
	}

	unsigned int aux;
	for (i = 1; i <= 4; i++)
	{
		strcpy(low_tx_power_alarm[i], alarm[xfp_interruption_flags[i - 1][0]]);
		check_status_to_log(logging_monitor.low_tx_power_alarm_xfp[i], low_tx_power_alarm[i], title[i], low_tx_power_alarm[0]);

		strcpy(high_tx_power_alarm[i], alarm[xfp_interruption_flags[i - 1][1]]);
		check_status_to_log(logging_monitor.high_tx_power_alarm_xfp[i], high_tx_power_alarm[i], title[i], high_tx_power_alarm[0]);

		strcpy(low_rx_power_alarm[i], alarm[xfp_interruption_flags[i - 1][2]]);
		check_status_to_log(logging_monitor.low_rx_power_alarm_xfp[i], low_rx_power_alarm[i],title[i], low_rx_power_alarm[0]);

		strcpy(high_rx_power_alarm[i], alarm[xfp_interruption_flags[i - 1][3]]);
		check_status_to_log(logging_monitor.high_rx_power_alarm_xfp[i], high_rx_power_alarm[i],title[i], high_rx_power_alarm[0]);

		strcpy(rx_cdr_loss_of_lock[i], alarm[xfp_interruption_flags[i - 1][4]]);
		check_status_to_log(logging_monitor.rx_cdr_loss_of_lock_xfp[i], rx_cdr_loss_of_lock[i],title[i], rx_cdr_loss_of_lock[0]);

		strcpy(tx_cdr_loss_of_lock[i], alarm[xfp_interruption_flags[i - 1][5]]);
		check_status_to_log(logging_monitor.tx_cdr_loss_of_lock_xfp[i], tx_cdr_loss_of_lock[i],title[i], tx_cdr_loss_of_lock[0]);

		strcpy(laser_fault_condition[i], alarm[xfp_interruption_flags[i - 1][6]]);
		check_status_to_log(logging_monitor.laser_fault_condition_xfp[i], laser_fault_condition[i], title[i], laser_fault_condition[0]);
	}

	concatenate_header(format, 76, title, 5, file, log_file, table_data);
	concatenate_columns(format, presence, 5, file, log_file, table_data);
	concatenate_columns(format, rx_loss, 5, file, log_file, table_data);
	concatenate_columns(format, ready, 5, file, log_file, table_data);
	concatenate_columns(format, interrupt, 5, file, log_file, table_data);
	concatenate_columns(format, tx_power, 5, file, log_file, table_data);
	concatenate_columns(format, rx_power, 5, file, log_file, table_data);
	concatenate_columns(format, temperature, 5, file, log_file, table_data);

	concatenate_columns(format, low_tx_power_alarm, 5, file, log_file, table_data);
	concatenate_columns(format, high_tx_power_alarm, 5, file, log_file, table_data);
	concatenate_columns(format, low_rx_power_alarm, 5, file, log_file, table_data);
	concatenate_columns(format, high_rx_power_alarm, 5, file, log_file, table_data);
	concatenate_columns(format, rx_cdr_loss_of_lock, 5, file, log_file, table_data);
	concatenate_columns(format, tx_cdr_loss_of_lock, 5, file, log_file, table_data);
	concatenate_columns(format, laser_fault_condition, 5, file, log_file, table_data);
}

unsigned int xfp_protect_action(FILE *file, unsigned int condition, unsigned int xfp_module)
{
	if (condition)
	{
		xfp_disable_laser(xfp_module);
		char msg [100] ="";
		sprintf(msg,"The laser of XFP Module %d was turned off to protect it over temperature. \n", xfp_module);
		printf(msg);
		JUST_LOG(LOG_ERR,0,msg,LOG_USER);
		/*
		if (file != NULL)
		{
			char message[100] = "\n The laser of XFP Module ";
			char number_xfp[20];

			sprintf(number_xfp, "%d", xfp_module);
			strcat(message, number_xfp);
			strcat(message, " was turned off to protect it over temperature. \n");
			fprintf(file, message);
		}
		 */
		return 1;
	}

	else
	{
		return 0;
	}
}

/*
void cs6041_status(float* cs6041_temperature, FILE *file, unsigned int log_file)
{
	unsigned int i;

	char title[5][100] =
	{
			{ "       " },
			{ "Around" },
			{ "TS0" },
			{ "TS1" },
			{ "TS2" } };
	char temperature[5][100] =
	{
			{ "6041 Temp. [C]" } };
	char format[5][100] =
	{
			{ "%20s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" } };



	for (i = 1; i <= 4; i++)
	{
		sprintf(temperature[i], "%.2f", cs6041_temperature[i - 1]);
		value_to_log(logging_monitor.general_status_temperature[i],temperature[i], title[i],temperature[0]);
	}

	concatenate_header(format, 89, title, 5, file, log_file, table_data);
	concatenate_columns(format, temperature, 5, file, log_file, table_data);
}
 */

void edfa_status(Edfa *edfa_struct, FILE *file, unsigned int log_file)
{
	char title[7][100] =
	{
			{ "EDFA" },
			{ "POUT [dBm]" },
			{ "PIN [dBm]" },
			{ "Temp. [C]" },
			{ "LOS" },
			{ "LOP" },
			{ "Amp. stat" } };
	char row_1[7][100] =
	{
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "" } };
	char format[7][100] =
	{
			{ "%20s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" } };

	strcpy(row_1[1], edfa_struct->edfa_output_power);
	strcpy(row_1[2], edfa_struct->edfa_input_power);
	strcpy(row_1[3], edfa_struct->edfa_temperature);

	for(int ii = 1; ii<=3; ii++)
	{
		value_to_log(logging_monitor.row_1_edfa[ii], row_1[ii], title[0],title[ii]);
	}

	strcpy(row_1[4], edfa_struct->edfa_los);
	strcpy(row_1[5], edfa_struct->edfa_lop);
	strcpy(row_1[6], edfa_struct->edfa_amp_status);

	for(int jj = 4; jj<=6; jj++)
	{
		check_status_to_log(logging_monitor.row_1_edfa[jj], row_1[jj], title[0],title[jj]);
	}

	concatenate_header(format, 101, title, 7, file, log_file, table_data);
	concatenate_columns(format, row_1, 7, file, log_file, table_data);
}
/*
void fpga_status(float* fpga_temperature, FILE *file, unsigned int log_file)
{

	char title[2][100] =
	{
			{ "       " },
			{ "FPGA" } };
	char temperature[2][100] =
	{
			{ "Temp. [C]" } };
	char format[2][100] =
	{
			{ "%20s%3c" },
			{ "%10s%3c" } };


	sprintf(temperature[1], "%.2f", fpga_temperature[0]);
	value_to_log(temperature[1], title[1],temperature[0]);

	concatenate_header(format, 89, title, 2, file, log_file, table_data);
	concatenate_columns(format, temperature, 2, file, log_file, table_data);
}

void board_status(int* board_temperature, int* board_humidity, FILE *file, unsigned int log_file)
{
	char title[2][100] =
	{
			{ "       " },
			{ "BOARD" } };
	char temperature[2][100] =
	{
			{ "Temp. [C]" } };
	char humidity[2][100] =
	{
			{ "Humidity [%RH]" } };
	char format[2][100] =
	{
			{ "%20s%3c" },
			{ "%10s%3c" } };

	sprintf(temperature[1], "%d", board_temperature[0]);
	value_to_log(temperature[1], title[1],temperature[0]);

	sprintf(humidity[1], "%d", board_humidity[0]);
	value_to_log(humidity[1], title[1],humidity[0]);

	concatenate_header(format, 89, title, 2, file, log_file, table_data);
	concatenate_columns(format, temperature, 2, file, log_file, table_data);
	concatenate_columns(format, humidity, 2, file, log_file, table_data);
}
 */

void general_status(float* cs6041_temperature, float* fpga_temperature, int* board_temperature, int* board_humidity, FILE *file, unsigned int log_file)
{
	unsigned int i;

	char title[7][100] =
	{
			{ "       " },
			{ "T41 Around" },
			{ "T41 TS0" },
			{ "T41 TS1" },
			{ "T41 TS2" },
			{ "FPGA" },
			{ "BOARD" } };
	char temperature[7][100] =
	{
			{ "Temp. [C]" } };
	char humidity[7][100] =
	{
			{ "Humidity [%RH]" } };
	char format[7][100] =
	{
			{ "%20s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" },
			{ "%10s%3c" } };



	for (i = 1; i <= 4; i++)
	{
		sprintf(temperature[i], "%.2f", cs6041_temperature[i - 1]);
		value_to_log(logging_monitor.general_status_temperature[i],temperature[i], title[i],temperature[0]);
	}

	sprintf(temperature[5], "%.2f", fpga_temperature[0]);
	value_to_log(logging_monitor.general_status_temperature[5],temperature[5], title[5],temperature[0]);

	sprintf(temperature[6], "%d", board_temperature[0]);
	value_to_log(logging_monitor.general_status_temperature[6],temperature[6], title[6],temperature[0]);

	sprintf(humidity[6], "%d", board_humidity[0]);
	value_to_log(logging_monitor.board_humidity[6], humidity[6], title[6],humidity[0]);

	concatenate_header(format, 101, title, 7, file, log_file, table_data);
	concatenate_columns(format, temperature, 7, file, log_file, table_data);
	concatenate_columns(format, humidity, 7, file, log_file, table_data);
}

void m40g_status(Txp *txp_struct, FILE *file, unsigned int log_file)
{
	unsigned int i;
	char general_status[2][100] =
	{ "Yes", "No" };
	char alarm[2][100] =
	{ "Alarm", "--" };
	char title[11][100] =
	{
			{ "Tx/Rx" },
			{ "Alarm" },
			{ "Power" },
			{ "Alarm" },
			{ "Misc." },
			{ "Value" },
			{ "DSP" },
			{ "Value" },
			{ "" },
			{ "" },
			{ "" } };
	char temperature[11][100] =
	{
			{ "40G Temp. [C]" } };
	char miscellaneous[11][100] =
	{
			{ "40G Misc." } };

	char row_1[11][100] =
	{
			{ "EOL ALM" },
			{ "" },
			{ "PSUMMARY" },
			{ "" },
			{ "Temp. Around" },
			{ "" },
			{ "DSP running" },
			{ "" } };
	char row_2[11][100] =
	{
			{ "Mod TEMP ALM" },
			{ "" },
			{ "P5VANALOG" },
			{ "" },
			{ "Temp. Case" },
			{ "" },
			{ "CONVERGED" },
			{ "" } };
	char row_3[11][100] =
	{
			{ "TxOOA" },
			{ "" },
			{ "N5V2ANALOG" },
			{ "" },
			{ "Temp. Tx Laser" },
			{ "" },
			{ "MSE below threshold" },
			{ "" } };
	char row_4[11][100] =
	{
			{ "Tx LOF ALM" },
			{ "" },
			{ "P3P3VANALOG" },
			{ "" },
			{ "Temp. Rx Laser" },
			{ "" },
			{ "BCD Enabled" },
			{ "" } };
	char row_5[11][100] =
	{
			{ "Tx DSC ERR" },
			{ "" },
			{ "P3P3VDIGITAL" },
			{ "" },
			{ "Loss" },
			{ "" },
			{ "Coarse Carrier Lock" },
			{ "" } };
	char row_6[11][100] =
	{
			{ "Ls WAV ALM" },
			{ "" },
			{ "LVDIGITAL" },
			{ "" },
			{ "Interrupt" },
			{ "" },
			{ "Collision" },
			{ "" } };
	char row_7[11][100] =
	{
			{ "Tx ALM INT" },
			{ "" },
			{ "N5P2VDIGITAL" },
			{ "" },
			{ "Tx Power" },
			{ "" },
			{ "DSP Initialized" },
			{ "" } };
	char row_8[11][100] =
	{
			{ "Ls BIAS ALM" },
			{ "" },
			{ "" },
			{ "" },
			{ "Rx Power" },
			{ "" },
			{ "Presence of light" },
			{ "" } };
	char row_9[11][100] =
	{
			{ "Ls TEMP ALM" },
			{ "" },
			{ "" },
			{ "" },
			{ "Tx Laser ITU Band" },
			{ "" },
			{ "Local Oscillator running" },
			{ "" } };
	char row_10[11][100] =
	{
			{ "Tx LOCK ERR" },
			{ "" },
			{ "" },
			{ "" },
			{ "Tx Laser ITU Channel" },
			{ "" },
			{ "Transmit Laser running" },
			{ "" } };
	char row_11[11][100] =
	{
			{ "Ls POW ALM" },
			{ "" },
			{ "" },
			{ "" },
			{ "Rx Laser ITU Band" },
			{ "" },
			{ "MSE XI" },
			{ "" } };
	char row_12[11][100] =
	{
			{ "Mod BIAS ALM" },
			{ "" },
			{ "" },
			{ "" },
			{ "Rx Laser ITU Channel" },
			{ "" },
			{ "MSE XQ" },
			{ "" } };
	char row_13[11][100] =
	{
			{ "LATCHED TxFIFO ERR" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "MSE YI" },
			{ "" } };
	char row_14[11][100] =
	{
			{ "RxALM INT" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "MSE YQ" },
			{ "" } };
	char row_15[11][100] =
	{
			{ "Rx POW ALM" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "BER Estimate" },
			{ "" } };
	char row_16[11][100] =
	{
			{ "Rx LOS" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "Min. Bulk CD Compensation [ps/nm]" } };
	char row_17[11][100] =
	{
			{ "Rx LOCK ERR" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "Max. Bulk CD Compensation [ps/nm]" },
			{ "" } };
	char row_18[11][100] =
	{
			{ "RXS" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "Step Size [ps/nm]" },
			{ "" } };
	char row_19[11][100] =
	{
			{ "PRBS ERR DET" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "" },
			{ "CD Compensation [ps/nm]" },
			{ "" } };

	char format[11][100] =
	{
			{ "%20s%3c" },
			{ "%10s%3c" },
			{ "%12s%3c" },
			{ "%10s%3c" },
			{ "%20s%3c" },
			{ "%12s%3c" },
			{ "%34s%3c" },
			{ "%10s%3c" } };

	strcpy(row_1[1], alarm[txp_struct->txp_tx_alarm.fields.eolalm]);
	check_status_to_log(logging_monitor.m40g_row_1[1],row_1[1],title[0],row_1[0]);
	strcpy(row_2[1], alarm[txp_struct->txp_tx_alarm.fields.modtempalm]);
	check_status_to_log(logging_monitor.m40g_row_2[1],row_2[1],title[0],row_2[0]);
	strcpy(row_3[1], alarm[txp_struct->txp_tx_alarm.fields.txooa]);
	check_status_to_log(logging_monitor.m40g_row_3[1],row_3[1],title[0],row_3[0]);
	strcpy(row_4[1], alarm[txp_struct->txp_tx_alarm.fields.txlofalm]);
	check_status_to_log(logging_monitor.m40g_row_4[1],row_4[1],title[0],row_4[0]);
	strcpy(row_5[1], alarm[txp_struct->txp_tx_alarm.fields.txdscerr]);
	check_status_to_log(logging_monitor.m40g_row_5[1],row_5[1],title[0],row_5[0]);
	strcpy(row_6[1], alarm[txp_struct->txp_tx_alarm.fields.lswavalm]);
	check_status_to_log(logging_monitor.m40g_row_6[1],row_6[1],title[0],row_6[0]);
	strcpy(row_7[1], alarm[txp_struct->txp_tx_alarm.fields.txalmint]);
	check_status_to_log(logging_monitor.m40g_row_7[1],row_7[1],title[0],row_7[0]);
	strcpy(row_8[1], alarm[txp_struct->txp_tx_alarm.fields.lsbiasalm]);
	check_status_to_log(logging_monitor.m40g_row_8[1],row_8[1],title[0],row_8[0]);
	strcpy(row_9[1], alarm[txp_struct->txp_tx_alarm.fields.lstempalm]);
	check_status_to_log(logging_monitor.m40g_row_9[1],row_9[1],title[0],row_9[0]);
	strcpy(row_10[1], alarm[txp_struct->txp_tx_alarm.fields.txlockerr]);
	check_status_to_log(logging_monitor.m40g_row_10[1],row_10[1],title[0],row_10[0]);
	strcpy(row_11[1], alarm[txp_struct->txp_tx_alarm.fields.lspowalm]);
	check_status_to_log(logging_monitor.m40g_row_11[1],row_11[1],title[0],row_11[0]);
	strcpy(row_12[1], alarm[txp_struct->txp_tx_alarm.fields.modbiasalm]);
	check_status_to_log(logging_monitor.m40g_row_12[1],row_12[1],title[0],row_12[0]);
	strcpy(row_13[1], alarm[txp_struct->txp_tx_alarm.fields.latchedtxfifoerr]);
	check_status_to_log(logging_monitor.m40g_row_13[1],row_13[1],title[0],row_13[0]);
	strcpy(row_14[1], alarm[txp_struct->txp_rx_alarm.fields.rxalmint]);
	check_status_to_log(logging_monitor.m40g_row_14[1],row_14[1],title[0],row_14[0]);
	strcpy(row_15[1], alarm[txp_struct->txp_rx_alarm.fields.rxpowalm]);
	check_status_to_log(logging_monitor.m40g_row_15[1],row_15[1],title[0],row_15[0]);
	strcpy(row_16[1], alarm[txp_struct->txp_rx_alarm.fields.rxlos]);
	check_status_to_log(logging_monitor.m40g_row_16[1],row_16[1],title[0],row_16[0]);
	strcpy(row_17[1], alarm[txp_struct->txp_rx_alarm.fields.rxlockerr]);
	check_status_to_log(logging_monitor.m40g_row_17[1],row_17[1],title[0],row_17[0]);
	strcpy(row_18[1], alarm[txp_struct->txp_rx_alarm.fields.rxs]);
	check_status_to_log(logging_monitor.m40g_row_18[1],row_18[1],title[0],row_18[0]);
	strcpy(row_19[1], alarm[txp_struct->txp_rx_alarm.fields.prbserrdet]);
	check_status_to_log(logging_monitor.m40g_row_19[1],row_19[1],title[0],row_19[0]);

	strcpy(row_1[3], alarm[txp_struct->txp_power_alarm.fields.psummary]);
	check_status_to_log(logging_monitor.m40g_row_1[3],row_1[3],title[2],row_1[2]);
	strcpy(row_2[3], alarm[txp_struct->txp_power_alarm.fields.p5vanalog]);
	check_status_to_log(logging_monitor.m40g_row_2[3],row_2[3],title[2],row_2[2]);
	strcpy(row_3[3], alarm[txp_struct->txp_power_alarm.fields.n5v2analog]);
	check_status_to_log(logging_monitor.m40g_row_3[3],row_3[3],title[2],row_3[2]);
	strcpy(row_4[3], alarm[txp_struct->txp_power_alarm.fields.p3p3vanalog]);
	check_status_to_log(logging_monitor.m40g_row_4[3],row_4[3],title[2],row_4[2]);
	strcpy(row_5[3], alarm[txp_struct->txp_power_alarm.fields.p3p3vdigital]);
	check_status_to_log(logging_monitor.m40g_row_5[3],row_5[3],title[2],row_5[2]);
	strcpy(row_6[3], alarm[txp_struct->txp_power_alarm.fields.lvdigital]);
	check_status_to_log(logging_monitor.m40g_row_6[3],row_6[3],title[2],row_6[2]);
	strcpy(row_7[3], alarm[txp_struct->txp_power_alarm.fields.n5p2vdigital]);
	check_status_to_log(logging_monitor.m40g_row_7[3],row_7[3],title[2],row_7[2]);

	sprintf(row_1[5], "%.2f", txp_struct->txp_temperature[0]);
	value_to_log(logging_monitor.m40g_row_1[5],row_1[5],title[4],row_1[4]);
	sprintf(row_2[5], "%.2f", txp_struct->txp_temperature[1]);
	value_to_log(logging_monitor.m40g_row_2[5],row_2[5],title[4],row_2[4]);
	sprintf(row_3[5], "%.2f", txp_struct->txp_temperature[2]);
	value_to_log(logging_monitor.m40g_row_3[5],row_3[5],title[4],row_3[4]);
	sprintf(row_4[5], "%.2f", txp_struct->txp_temperature[3]);
	value_to_log(logging_monitor.m40g_row_4[5],row_4[5],title[4],row_4[4]);

	strcpy(row_5[5], general_status[txp_struct->txp_loss]);
	check_status_to_log(logging_monitor.m40g_row_5[5],row_5[5],title[4],row_5[4]);
	strcpy(row_6[5], general_status[txp_struct->txp_interrupt]);
	check_status_to_log(logging_monitor.m40g_row_6[5],row_6[5],title[4],row_6[4]);

	sprintf(row_7[5], " %.2f dBm", txp_struct->txp_tx_power);
	value_to_log(logging_monitor.m40g_row_7[5],row_7[5],title[4],row_7[4]);
	sprintf(row_8[5], " %.2f dBm", txp_struct->txp_rx_power);
	value_to_log(logging_monitor.m40g_row_8[5],row_8[5],title[4],row_8[4]);
	sprintf(row_9[5], "%c", txp_struct->txp_tx_laser_itu_channel.fields.band);
	value_to_log(logging_monitor.m40g_row_9[5],row_9[5],title[4],row_9[4]);
	sprintf(row_10[5], "%.2f", txp_struct->txp_tx_laser_itu_channel.fields.channel);
	value_to_log(logging_monitor.m40g_row_10[5],row_10[5],title[4],row_10[4]);
	sprintf(row_11[5], "%c", txp_struct->txp_rx_laser_itu_channel.fields.band);
	value_to_log(logging_monitor.m40g_row_11[5],row_11[5],title[4],row_11[4]);
	sprintf(row_12[5], "%.2f", txp_struct->txp_rx_laser_itu_channel.fields.channel);
	value_to_log(logging_monitor.m40g_row_10[5],row_12[5],title[4],row_12[4]);

	strcpy(row_1[7], general_status[!txp_struct->txp_dspstat.fields.GO]);
	check_status_to_log(logging_monitor.m40g_row_1[7],row_1[7],title[6],row_1[6]);
	strcpy(row_2[7], general_status[!txp_struct->txp_dspstat.fields.CONVERGED]);
	check_status_to_log(logging_monitor.m40g_row_2[7],row_2[7],title[6],row_2[6]);
	strcpy(row_3[7], general_status[!txp_struct->txp_dspstat.fields.MSEBLTHR]);
	check_status_to_log(logging_monitor.m40g_row_3[7],row_3[7],title[6],row_3[6]);
	strcpy(row_4[7], general_status[!txp_struct->txp_dspstat.fields.BCDEN]);
	check_status_to_log(logging_monitor.m40g_row_4[7],row_4[7],title[6],row_4[6]);
	strcpy(row_5[7], general_status[!txp_struct->txp_dspstat.fields.LOCK]);
	check_status_to_log(logging_monitor.m40g_row_5[7],row_5[7],title[6],row_5[6]);
	strcpy(row_6[7], general_status[txp_struct->txp_dspstat.fields.COLLISION]);
	check_status_to_log(logging_monitor.m40g_row_6[7],row_6[7],title[6],row_6[6]);
	strcpy(row_7[7], general_status[!txp_struct->txp_dspstat.fields.DSPINIT]);
	check_status_to_log(logging_monitor.m40g_row_7[7],row_7[7],title[6],row_7[6]);
	strcpy(row_8[7], general_status[!txp_struct->txp_dspstat.fields.POL]);
	check_status_to_log(logging_monitor.m40g_row_8[7],row_8[7],title[6],row_8[6]);
	strcpy(row_9[7], general_status[!txp_struct->txp_dspstat.fields.OSC]);
	check_status_to_log(logging_monitor.m40g_row_9[7],row_9[7],title[6],row_9[6]);
	strcpy(row_10[7], general_status[!txp_struct->txp_dspstat.fields.TXLASER]);
	check_status_to_log(logging_monitor.m40g_row_10[7],row_10[7],title[6],row_10[6]);

	sprintf(row_11[7], "%d", txp_struct->txp_mse.fields.mse_xi);
	value_to_log(logging_monitor.m40g_row_11[7],row_11[7],title[6],row_11[6]);
	sprintf(row_12[7], "%d", txp_struct->txp_mse.fields.mse_xq);
	value_to_log(logging_monitor.m40g_row_12[7],row_12[7],title[6],row_12[6]);
	sprintf(row_13[7], "%d", txp_struct->txp_mse.fields.mse_yi);
	value_to_log(logging_monitor.m40g_row_13[7],row_13[7],title[6],row_13[6]);
	sprintf(row_14[7], "%d", txp_struct->txp_mse.fields.mse_yq);
	value_to_log(logging_monitor.m40g_row_14[7],row_14[7],title[6],row_14[6]);
	sprintf(row_15[7], "%.4e", txp_struct->txp_ber_estimate);
	value_to_log(logging_monitor.m40g_row_15[7],row_15[7],title[6],row_15[6]);
	sprintf(row_16[7], "%d", txp_struct->txp_bulk_cd.fields.minimum_compensation);
	value_to_log(logging_monitor.m40g_row_16[7],row_16[7],title[6],row_16[6]);
	sprintf(row_17[7], "%d", txp_struct->txp_bulk_cd.fields.maximum_compensation);
	value_to_log(logging_monitor.m40g_row_17[7],row_17[7],title[6],row_17[6]);
	sprintf(row_18[7], "%d", txp_struct->txp_bulk_cd.fields.step_size);
	value_to_log(logging_monitor.m40g_row_18[7],row_18[7],title[6],row_18[6]);
	sprintf(row_19[7], "%.3f", txp_struct->txp_chromatic_dispersion);
	value_to_log(logging_monitor.m40g_row_19[7],row_19[7],title[6],row_19[6]);

	concatenate_header(format, 154, title, 11, file, log_file, table_data);
	concatenate_columns(format, row_1, 11, file, log_file, table_data);
	concatenate_columns(format, row_2, 11, file, log_file, table_data);
	concatenate_columns(format, row_3, 11, file, log_file, table_data);
	concatenate_columns(format, row_4, 11, file, log_file, table_data);
	concatenate_columns(format, row_5, 11, file, log_file, table_data);
	concatenate_columns(format, row_6, 11, file, log_file, table_data);
	concatenate_columns(format, row_7, 11, file, log_file, table_data);
	concatenate_columns(format, row_8, 11, file, log_file, table_data);
	concatenate_columns(format, row_9, 11, file, log_file, table_data);
	concatenate_columns(format, row_10, 11, file, log_file, table_data);
	concatenate_columns(format, row_11, 11, file, log_file, table_data);
	concatenate_columns(format, row_12, 11, file, log_file, table_data);
	concatenate_columns(format, row_13, 11, file, log_file, table_data);

	concatenate_columns(format, row_14, 11, file, log_file, table_data);
	concatenate_columns(format, row_15, 11, file, log_file, table_data);
	concatenate_columns(format, row_16, 11, file, log_file, table_data);
	concatenate_columns(format, row_17, 11, file, log_file, table_data);
	concatenate_columns(format, row_18, 11, file, log_file, table_data);
	concatenate_columns(format, row_19, 11, file, log_file, table_data);

}

unsigned int txp_protect_action(FILE *file, unsigned int condition)
{
	if (condition)
	{
		txp_reset();
		printf("40G module was reset to protect it over temperature");

		if (file != NULL)
		{
			char message[100] = "\n40G module was reset to protect it over temperature.\n";
			fprintf(file, message);
		}

		return 1;
	}
	else
	{
		return 0;
	}
}


void check_status_to_log (char * pre_status, char * current_status, char * title1, char * title2){

	char msg_status_initial_tag [100]= "Alarms;";
	char init_msg_status_initial_tag [100]= "InitialAlarmsStatus;";

	monitor_log_func(&wday1, &cant_access_check_status_to_log, &init_cant_access_check_status_to_log, CANT_ALARMS, pre_status, current_status, msg_status, msg_status_initial_tag, msg_status_initious, init_msg_status_initial_tag, title1, title2);

}

void value_to_log (char * init_value, char * value, char * title1, char * title2){

	char msg_value_initial_tag [100]= "NumVal;";
	char init_msg_value_initial_tag [100]= "InitialValues;";

	monitor_log_func(&wday2, &cant_access_value_to_log, &init_cant_access_value_to_log, CANT_VALUES, init_value, value, msg_value, msg_value_initial_tag, msg_values_initious, init_msg_value_initial_tag, title1, title2);

}

void monitor_log_func (unsigned int * wday, unsigned int * global_counter, unsigned int * init_global_counter, unsigned int counter_limit, char * init_value, char * value, char * total_msg, char * initial_tag, char * init_total_msg, char * init_initial_tag, char * title1, char * title2){

	char new_msg [100] = "";
	char title [10] = "";
	unsigned int counter = *global_counter;
	unsigned int init_counter = *init_global_counter;

	sprintf(title,"%d",counter);

	if (counter == 0){
		memset(total_msg,0,strlen(total_msg));
		strcpy(total_msg, initial_tag);
	}

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	if(tm.tm_wday != *wday){

		strcpy(init_value,value);

		if (init_counter == 0){
			memset(init_total_msg,0,strlen(init_total_msg));
			strcpy(init_total_msg, init_initial_tag);
		}

		if (init_counter >= 0) {
			sprintf(new_msg,"%s/%s;", title, value);
			strcat(init_total_msg,new_msg);
		}

		init_counter ++;

		if(init_counter == counter_limit){
			if(strcmp(init_total_msg,init_initial_tag) != 0){
				JUST_LOG(LOG_ERR, 0, init_total_msg, LOG_USER);
				*wday = tm.tm_wday;
			}
			init_counter = 0;
		}

		*init_global_counter = init_counter;
	}

	else if (strcmp(init_value,value) != 0){

		strcpy(init_value,value);

		if(counter >= 0){
			sprintf(new_msg, "%s/%s;", title, value);
			strcat(total_msg,new_msg);
		}
	}
	counter++;

	if(counter == counter_limit ){
		if (strcmp(total_msg,initial_tag) != 0)
			JUST_LOG(LOG_ERR, 0, total_msg, LOG_USER);
		counter = 0;
	}

	*global_counter = counter;
}
