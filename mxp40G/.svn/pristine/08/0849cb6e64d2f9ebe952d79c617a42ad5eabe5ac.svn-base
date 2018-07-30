/*
 * cs6041.c
 *
 *  Created on: Jun 9, 2015
 *      Author: Guille
 */
#include "muxponder.h"
#include "hl_configs.h"
#include "txp.h"
#include "edfa.h"
#include "gpio.h"

///@ MUXPONDER: ./muxponder --configuracion --[otu2|xge] --[gfec|cerofec] --[gfec_cliente|cerofec_cliente|nulofec_cliente] --canal "value" --potencia "value" --cd_compensacion "value"
///             ./muxponder --guardar --[otu2|xge] --[gfec|cerofec] --[gfec_cliente|cerofec_cliente|nulofec_cliente] --canal "value" --potencia "value" --cd_compensacion "value"
/// para configuración completa en modo muxponder (--configuracion) o guardar configuración en archivo de inicio (--guardar).
///	[otu2|xge] especifica el tipo de tráfico.
///	[gfec|cerofec] especifica el uso de fec.
///	canal especifica el canal óptico del módulo transponder.
///	potencia especifica la potencia de salida del amplificador óptico (edfa).
///	cd_compensacion especifica la compensación de dispersion cromática.

char help[2000] =
		"\n\nForma de uso:\n\n"
				"Configuración Muxponder: ./muxponder --configuracion --[otu2|xge] --[gfec|cerofec] --[gfec_cliente|cerofec_cliente|nulofec_cliente] --canal valor --potencia valor[dBm] --cd_compensacion minimo,maximo --gcc [0|1]\n"
				"Reconfiguración:./muxponder --reconfiguracion --[otu2|xge] --[gfec|cerofec] --[gfec_cliente|cerofec_cliente|nulofec_cliente] --canal valor --potencia valor[dBm] --cd_compensacion minimo,maximo\n"
				"Modificar archivo de configuración inicial: ./muxponder --guardar --[otu2|xge] --[gfec|cerofec] --[gfec_cliente|cerofec_cliente|nulofec_cliente] --canal valor --potencia valor[dBm] --cd_compensacion minimo,maximo\n"
				"configuración completa en modo muxponder (--configuracion) o guardar configuración en archivo de inicio (--guardar).\n"
				"[otu2|xge] especifica el tipo de tráfico.\n"
				"[gfec|cerofec] especifica el uso de fec.\n"
				"canal especifica el canal óptico del módulo transponder.\n"
				"potencia especifica la potencia de salida del amplificador óptico (edfa).\n"
				"cd_compensacion especifica la compensación de dispersion cromática.\n\n";

struct timespec tstart = { 0, 0 }, tend = { 0, 0 };

int main(int argc, char **argv)
{
	Muxponder mxp;
	char option[100];
	int traffic;
	int boot = 0;

	// init GPIO
	pio_init();

	// Load default configuration from file
	load_configuration_file(&mxp);

	// Struct to translate long options (--) to short options (-)
	struct option long_options[] =
	{
	{ "configuracion", no_argument, NULL, 'c' },
	{ "reconfiguracion", no_argument, NULL, 'r' },
	{ "clear", no_argument, NULL, 'q' },
	{ "guardar", no_argument, NULL, 's' },
	{ "canal", required_argument, NULL, 'i' },
	{ "potencia", required_argument, NULL, 'p' },
	{ "cd_compensacion", required_argument, NULL, 'd' },
	{ "otu2", no_argument, NULL, 'o' },
	{ "xge", no_argument, NULL, 'x' },
	{ "cerofec", no_argument, NULL, 'n' },
	{ "gfec", no_argument, NULL, 'g' },
	{ "ufec", no_argument, NULL, 'u' },
	{ "cerofec_cliente", no_argument, NULL, 'h' },
	{ "gfec_cliente", no_argument, NULL, 'j' },
	{ "nulofec_cliente", no_argument, NULL, 'k' },
	{ "gfec", no_argument, NULL, 'g' },
	{ "gcc", required_argument, NULL, 'e' },
	{ "informacion", no_argument, NULL, 'z' },
	{ "boot", no_argument, NULL, 'b' },
	{ "version", no_argument, NULL, 'v' },
	{ "ayuda", no_argument, NULL, '?' },
	{ 0, 0, 0, 0 }, };

	int c;

	while (1)
	{
		int option_index = 0;

		c = getopt_long(argc, argv, "csi:p:d:e:oxnghuqrjkzbv?", long_options, &option_index);

		//Detect the end of the options.
		if (c == -1)
		{
			break;
		}

		switch (c)
		{
		case 'q':
		case 'c':
		case 'r':
		case 's':
			strcpy(option, long_options[option_index].name);
			break;

		case 'b':
			// Boot Flag for network configuration
			boot = 1;
			break;

		case 'i':
			mxp.txp_channel = atoi(optarg);
			break;

		case 'p':
			mxp.edfa_pout = atof(optarg);
			break;

		case 'd':
			mxp.txp_min_bulk_cd_comp = atoi(strtok(optarg, ","));
			mxp.txp_max_bulk_cd_comp = atoi(strtok(NULL, ","));
			break;

		case 'o':
			mxp.slice_protocol[0] = 0;
			mxp.slice_protocol[1] = 0;
			mxp.slice_protocol[2] = 0;
			mxp.slice_protocol[3] = 0;
			break;

		case 'x':
			mxp.slice_protocol[0] = 1;
			mxp.slice_protocol[1] = 1;
			mxp.slice_protocol[2] = 1;
			mxp.slice_protocol[3] = 1;
			break;

		case 'g':
			mxp.cs6041_line_fec = 13;
			break;

		case 'n':
			mxp.cs6041_line_fec = 14;
			break;

		case 'h':
			mxp.cs6041_client_fec = 14;
			break;
		case 'j':
			mxp.cs6041_client_fec = 13;
			break;
		case 'u':
			mxp.cs6041_client_fec = 0;
			break;

		case 'k':
			mxp.cs6041_client_fec = 16;
			break;

		case 'e':
			mxp.gcc = atoi(optarg);
			break;

		case 'v':
			printf("\n\nVersion: %s\n\n", MUXPONDER);
			return 0;

		case 'z':
			printf("\n\n######### Información de configuración #########\n");
			if (mxp.slice_protocol[0] == 0)
			{
				printf("trafico: otu2\n");
			}
			else if (mxp.slice_protocol[0] == 1)
			{
				printf("trafico: xge\n");
			}
			printf("canal: %i\n", mxp.txp_channel);
			printf("potencia: %f\n", mxp.edfa_pout);
			printf("min_cd_compensacion: %i\n", mxp.txp_min_bulk_cd_comp);
			printf("max_cd_compensacion: %i\n", mxp.txp_max_bulk_cd_comp);
			printf("canal gcc: %i\n", mxp.gcc);

			switch (mxp.cs6041_line_fec)
			{
			case 13:
				printf("fec: gfec\n");
				break;
			case 14:
				printf("fec: cerofec\n");
				break;
			default:
				break;
			}

			switch (mxp.cs6041_client_fec)
			{
			case 13:
				printf("fec_cliente: gfec\n");
				break;
			case 14:
				printf("fec_cliente: cerofec\n");
				break;
			case 16:
				printf("fec_cliente: nulofec\n");
				break;
			default:
				break;
			}

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

	if (strcmp(option, "configuracion") == 0)
	{
		clock_gettime(CLOCK_MONOTONIC, &tstart);

		if (boot == 1)
		{
			// Load the network information saved in the initial_config
			network_configuration(mxp, 0);
		}

		clk_set_osc_400_mhz(1);
		clk_set_osc_684_28_mhz(1);
		clk_set_mux_a(0);
		clk_set_mux_b(1);

		open_upie();

		unsigned int slice_client;
		for (slice_client = 0; slice_client < 4; slice_client++)
		{
			mxp.xfp_loopback[slice_client] = 0; //not electrical loopback
		}

		mxp.txp_diagnostic_loopback = 0; //not diagnostic loopback
		mxp.txp_line_loopback = 0; //not line loopback
		mxp.txp_laser_enable = 1;
		mxp.fec_monitor = 0;

		mxp_configuration(mxp);

		close_upie();

		clock_gettime(CLOCK_MONOTONIC, &tend);
		printf("Tiempo de configuración %.5f segundos\n", ((double) tend.tv_sec + 1.0e-9 * tend.tv_nsec) - ((double) tstart.tv_sec + 1.0e-9 * tstart.tv_nsec));

	}
	else if (strcmp(option, "reconfiguracion") == 0)
	{
		clock_gettime(CLOCK_MONOTONIC, &tstart);
		clk_set_osc_400_mhz(1);
		clk_set_osc_684_28_mhz(1);
		clk_set_mux_a(0);
		clk_set_mux_b(1);

		open_upie();

		unsigned int slice_client;
		for (slice_client = 0; slice_client < 4; slice_client++)
		{
			mxp.xfp_loopback[slice_client] = 0; //not electrical loopback
		}

		mxp.txp_diagnostic_loopback = 0; //not diagnostic loopback
		mxp.txp_line_loopback = 0; //not line loopback
		mxp.txp_laser_enable = 1;
		mxp.fec_monitor = 0;

		mxp_reconfiguration(mxp);

		close_upie();
		clock_gettime(CLOCK_MONOTONIC, &tend);
		printf("Tiempo de configuración %.5f segundos\n", ((double) tend.tv_sec + 1.0e-9 * tend.tv_nsec) - ((double) tstart.tv_sec + 1.0e-9 * tstart.tv_nsec));

	}
	else if (strcmp(option, "guardar") == 0)
	{
		if (!CHECK_EDFA_POUT(mxp.edfa_pout))
		{
			printf(EDFA_POUT_RANGE_ERROR);
			return 0;
		}

		if (!CHECK_CD_COMPENSATION(mxp.txp_min_bulk_cd_comp, mxp.txp_max_bulk_cd_comp))
		{
			printf(CD_COMPENSATION_RANGE_ERROR);
			return 0;
		}

		if (!CHECK_CHANNEL(mxp.txp_channel))
		{
			printf(CHANNEL_RANGE_ERROR);
			return 0;
		}

		update_initial_configuration_file(mxp);
		printf("Configuración guardada en archivo.\n");
	}
	else
	{
		printf("No se especificó la acción a realizar, utilizar opción --ayuda para mas información.\n");
	}

	return 0;
}
