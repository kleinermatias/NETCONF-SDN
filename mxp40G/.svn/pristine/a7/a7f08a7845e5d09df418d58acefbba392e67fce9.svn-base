#include "traffic.h"

T41_t Chips;

cs_uint16 dev_id = 0;
cs_uint16 mod_a;
cs_uint16 mod_b;
cs_uint8 dyn_repro;

const char *nombre_programa;
struct timespec traffic_start = { 0, 0 }, traffic_end = { 0, 0 };

#define SILABS_SLAVE_ADDRESS 0x50
#define SILABS_BUS 0x50

//@Brief This script configure Pbert on an specific elastic store of the cross-connect.
// Configures OTU3 traffic, sfi5.1 interface on slice 0 if Module A is selected.
// Configures OTU2/XGE traffic, xfi interface for an specific slice if Module B is selected..

// @USE
// Forma de uso:\n\n"
// ./traffic --procesador --[b|a] --[0|1|2|3|4] --[gfec|cerofec] --[gfec_cliente|cerofec_cliente|nulofec_cliente] --fecstats --[otu2|xge (10GbE 7.3)] --tiempo 'valor_en_segundos' --canal "value" --potencia "value" --cd_compensacion "value"\n"
// ./traffic --mixto --[0|1|2|3|4] --[otu2| xge] --[gfec|cerofec] --[gfec_cliente|cerofec_cliente|nulofec_cliente] --fecstats --tiempo 'valor_en_segundos' --canal "value" --potencia "value" --cd_compensacion "value"\n"
// Los parámetros --[0|1|2|3|4] solo se utilizan para el lado b indicando el slice.\n"
// La opción \"--0\" selecciona todos los slices.\n"
// En caso de no ingresar la opción --tiempo la generación de tráfico será sin limite alguno \n"
// Ej : ./traffic --procesador --b --0 --otu2 --gfec --tiempo 3600 \n"
// Ej : ./traffic --procesador --a --cerofec --fecstats --otu3 \n"
// Ej : ./traffic --mixto --1 --2 --otu2 --gfec --tiempo 3600 \n";

char help[1000] =
		"\nForma de uso:\n\n"
				"./traffic --procesador --[b|a] --[0|1|2|3|4] --[gfec|cerofec] --[gfec_cliente|cerofec_cliente|nulofec_cliente] --fecstats --[otu2|xge (10GbE 7.3)] --tiempo 'valor_en_segundos' --canal 'valor_de_canal' --potencia 'valor_de_potencia' --cd_compensacion 'valor_de_compensacion'\n"
				"./traffic --mixto --[0|1|2|3|4] --[otu2| xge] --[gfec|cerofec] --[gfec_cliente|cerofec_cliente|nulofec_cliente] --fecstats --tiempo 'valor_en_segundos' --canal 'valor_de_canal' --potencia 'valor_de_potencia' --cd_compensacion 'valor_de_compensacion'\n"
				"Los parámetros --[0|1|2|3|4] solo se utilizan para el lado b indicando el slice.\n"
				"La opción \"--0\" selecciona todos los slices.\n"
				"En caso de no ingresar la opción --tiempo la generación de tráfico será sin limite alguno \n"
				"Ej : ./traffic --procesador --b --0 --otu2 --gfec --tiempo 3600 \n"
				"Ej : ./traffic --procesador --a --cerofec --fecstats --otu3 \n"
				"Ej : ./traffic --mixto --1 --2 --otu2 --gfec --tiempo 3600 \n";

int main(int argc, char **argv)
{

	// init GPIO
	pio_init();

	clk_set_osc_400_mhz(1);
	clk_set_osc_684_28_mhz(1);
	clk_set_mux_a(0);
	clk_set_mux_b(1);

	int next_opt;
	int sysclk_freq;
	int sysrefclk = 400;
	cs_uint8 slice_line = 0;
	cs_uint8 slice_client = 0;
	int diagloop = 0;
	int laser40 = 0;
	int slice = 0;
	int protocol = 0;
	int gen_time = 0;
	sysclk_freq = sysrefclk * 1000000;

	int ports[5];
	char configuration[15];
	char module[5];
	int timeset = 0;
	char time[100];
	char traffic_type[10];
	char option[100];
	char value[100];

	Traffic parameters;
	Muxponder mxp;

	// Load default traffic parameters
	parameters.line_fec = 13;
	parameters.client_fec = 16;

	// Load default configuration from file
	load_configuration_file(&mxp);

	// Por defecto desactivar estadisticas de FEC
	parameters.fec_monitor = 0;
	mxp.fec_monitor = 0;

	open_upie();

	memset(ports, 0, sizeof(ports));

	// Struct to translate long options (--) to short options (-)
	struct option long_options[] =
	{
	{ "procesador", no_argument, NULL, 'p' },
	{ "mixto", no_argument, NULL, 'm' },
	{ "a", no_argument, NULL, 'a' },
	{ "b", no_argument, NULL, 'b' },
	{ "0", no_argument, NULL, '0' },
	{ "1", no_argument, NULL, '1' },
	{ "2", no_argument, NULL, '2' },
	{ "3", no_argument, NULL, '3' },
	{ "4", no_argument, NULL, '4' },
	{ "otu2", no_argument, NULL, 'o' },
	{ "xge", no_argument, NULL, 'x' },
	{ "otu3", no_argument, NULL, 'u' },
	{ "tiempo", required_argument, NULL, 't' },
	{ "cerofec", no_argument, NULL, 'n' },
	{ "gfec", no_argument, NULL, 'g' },
	{ "cerofec_cliente", no_argument, NULL, 'h' },
	{ "gfec_cliente", no_argument, NULL, 'j' },
	{ "nulofec_cliente", no_argument, NULL, 'k' },
	{ "fecstats", no_argument, NULL, 'f' },
	{ "canal", required_argument, NULL, 'i' },
	{ "potencia", required_argument, NULL, 'w' },
	{ "cd_compensacion", required_argument, NULL, 'd' },
	{ "version", no_argument, NULL, 'v' },
	{ "ayuda", no_argument, NULL, '?' },
	{ 0, 0, 0, 0 } };

	int c;
	int option_index = 0;

	while (1)
	{
		option_index = 0;

		c = getopt_long(argc, argv, "pmab01234oxut:nghjkfi:w:d:v?", long_options, &option_index);

		//Detect the end of the options.
		if (c == -1)
		{
			break;
		}

		switch (c)
		{
		case 'm':
		case 'p':
			strcpy(configuration, long_options[option_index].name);
			break;

		case 'a':
		case 'b':
			strcpy(module, long_options[option_index].name);
			break;

		case '0':
			ports[0] = 1;
			break;
		case '1':
			ports[1] = 1;
			break;
		case '2':
			ports[2] = 1;
			break;
		case '3':
			ports[3] = 1;
			break;
		case '4':
			ports[4] = 1;
			break;

		case 'o':
		case 'x':
		case 'u':
			strcpy(traffic_type, long_options[option_index].name);
			break;

		case 't':
			timeset = 1;
			parameters.generation_time = (int) strtol(optarg, NULL, 10);
			parameters.console_output = 1;
			break;

		case 'f':
			parameters.fec_monitor = 1;
			mxp.fec_monitor = 1;
			break;

		case 'g':
			mxp.cs6041_line_fec = 13;
			parameters.line_fec = 13;
			break;

		case 'n':
			mxp.cs6041_line_fec = 14;
			parameters.line_fec = 14;
			break;

		case 'h':
			mxp.cs6041_client_fec = 14;
			parameters.client_fec = 14;
			break;
		case 'j':
			mxp.cs6041_client_fec = 13;
			parameters.client_fec = 13;
			break;
		case 'k':
			mxp.cs6041_client_fec = 16;
			parameters.client_fec = 16;
			break;

		case 'i':
			mxp.txp_channel = atoi(optarg);
			break;

		case 'w':
			mxp.edfa_pout = atof(optarg);
			break;

		case 'd':
			mxp.txp_min_bulk_cd_comp = atoi(strtok(optarg, ","));
			mxp.txp_max_bulk_cd_comp = atoi(strtok(NULL, ","));
			break;

		case 'v':
			printf("\n\nVersion: %s\n\n", TRAFFIC);
			return 0;

		case '?':
			printf("%s", help);
			return 0;
		default:
			return 0;
		}
	}

	if (optind < argc)
	{
		printf("Argumentos no reconocidos: ");
		while (optind < argc)
			printf("%s ", argv[optind++]);
		putchar('\n');
		printf("Utilizar opción --ayuda para mas información.\n");
		return 0;
	}

	// Si el usuario no ingresa la opcion de tiempo debe correr tráfico sin limites de tiempo
	if (!timeset)
	{
		parameters.generation_time = -1;
	}

	if (ports[0] == 0 && ports[1] == 0 && ports[2] == 0 && ports[3] == 0 && ports[4] == 0 && (strcmp(module, "b") == 0))
	{
		printf("Error: No se especifico puerto para la generación de tráfico, ver --ayuda para mas información.\n");
		return 0;
	}

	if (strcmp(traffic_type, "otu2") != 0 && strcmp(traffic_type, "xge") != 0 && strcmp(traffic_type, "otu3") != 0)
	{
		printf("Error: No se especifico un tipo de tráfico correcto para la configuración, ver --ayuda para mas información.\n");
		return 0;
	}

	if (strcmp(configuration, "procesador") == 0)
	{
		if (argc < 5 || argc > 14)
		{
			printf("Error: Opciones erróneas para configurar tráfico, ver --ayuda para mas información.\n");
			return 0;
		}

		if (strcmp(module, "a") == 0)
		{
			parameters.module = 0;
			printf("Modulo A Selected \n");
			if (strcmp(traffic_type, "otu3") == 0)
				printf("OTU3 Traffic Selected \n");
			else
			{
				printf("Error: Opciones erróneas para configurar tráfico, ver --ayuda para mas información.\n");
				return 0;
			}

			// Se inicializa el EDFA
			printf("Potencia de salida: %d dBm\n", mxp.edfa_pout);

            hl_edfa_init(mxp.edfa_pout);

            txp_reset(); //40G module and register reset. Set the register in default value

            printf("Waiting 40G Module Reset \n");
           	while (txp_reset_time() != 1);

			hl_txp_set_tx_rx_laser_itu_channel(mxp.txp_channel);

			hl_txp_set_bulk_cd_compensation(mxp.txp_min_bulk_cd_comp, mxp.txp_max_bulk_cd_comp);

			// Configure the 40 G module
			hl_txp_config_40g_otu3(0, 0, 1);

		}
		else if (strcmp(module, "b") == 0)
		{
			parameters.module = 1;
			printf("Modulo B Selected \n");
			int module_id;
			for (module_id = 1; module_id < 5; module_id++)
			{
				if (ports[module_id] == 1 || ports[0] == 1)
				{
					printf("Configuring XFP %d ...\n", module_id);

					ltc_enable_latch();

					xfp_enable_communication(module_id - 1);

					xfp_mask_bit(module_id - 1);

					xfp_read_interruption_flags(module_id - 1);

					xfp_reset(module_id - 1);

					xfp_read_interruption_flags(module_id - 1);

					xfp_demask_bit(module_id - 1);
					printf("XFP %d reinitialized \n", module_id);
					if (strcmp(traffic_type, "otu2") == 0)
					{
						parameters.traffic[module_id - 1] = 0;
						hl_xfp_setup(module_id - 1, 0, parameters.traffic[module_id - 1]);
					}
					else if (strcmp(traffic_type, "xge") == 0)
					{
						parameters.traffic[module_id - 1] = 1;
						hl_xfp_setup(module_id - 1, 0, parameters.traffic[module_id - 1]);
					}
				}
				else
				{
					parameters.traffic[module_id - 1] = -1;
				}
			}

		}
		else
		{
			printf("Error: Opciones erróneas para configurar tráfico, ver --ayuda para mas información.\n");
			return 0;
		}

		// Resetea el chip de cortina para hacer una configuracion limpia
		cs6041_reset();

		printf("Parametro de FEC de línea: %d\n", parameters.line_fec);
		printf("Parametro de FEC de cliente: %d\n", parameters.client_fec);

		// Inicializa la generación de tráfico según los parámetros que configuró el usuario
		traffic_initialize(parameters);
	}
	else if (strcmp(configuration, "mixto") == 0)
	{
		clock_gettime(CLOCK_MONOTONIC, &traffic_start);

		// Se inicializa la variable de tipo de tráfico (por defecto sin trafico)
		int traffic = -1;

		if (argc < 4 || argc > 14)
		{
			printf("Error: Opciones erróneas para configurar tráfico en modo MIXTO, ver --ayuda para mas información.\n");
			return 0;
		}

		unsigned int slice_client;
		if (strcmp(traffic_type, "otu2") == 0)
		{
			traffic = 0;
		}
		else if (strcmp(traffic_type, "xge") == 0)
		{
			traffic = 1;
		}
		else
		{
			printf("Error: Tipo de tráfico incorrecto en modo MIXTO, ver --ayuda para mas información.\n");
			return 0;
		}

		printf("Parametro de Trafico: %s\n", traffic_type);

		for (slice_client = 0; slice_client < 4; slice_client++)
		{
			mxp.xfp_loopback[slice_client] = 0; //not electrical loopback

			mxp.slice_protocol[slice_client] = traffic;
		}

		mxp.txp_diagnostic_loopback = 0; //not diagnostic loopback
		mxp.txp_line_loopback = 0; //not line loopback
		mxp.txp_laser_enable = 1;

		printf("Parametro de FEC de línea: %d\n", mxp.cs6041_line_fec);
		printf("Parametro de FEC de cliente: %d\n", mxp.cs6041_client_fec);
		printf("Potencia de salida: %f dBm\n", mxp.edfa_pout);

		// Se llama a la configuracion del muxponder
		mxp_reconfiguration(mxp);

		clock_gettime(CLOCK_MONOTONIC, &traffic_end);
		printf("Tiempo de configuración %.5f segundos\n", ((double) traffic_end.tv_sec + 1.0e-9 * traffic_end.tv_nsec) - ((double) traffic_start.tv_sec + 1.0e-9 * traffic_start.tv_nsec));

		// Se llama a la configuración de pbert para half-half
		pbert_config_half_half_test(traffic, ports, parameters);

		}
	else
	{
		printf("No se especificó una acción correcta a realizar, utilizar opción --ayuda para mas información.\n");
	}

	close_upie();
	return 0;

}
