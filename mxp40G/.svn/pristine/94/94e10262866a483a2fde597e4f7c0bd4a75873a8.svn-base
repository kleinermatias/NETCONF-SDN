#include "settings.h"

///@ SETTINGS: ./settings --date --year [] --month [] --day [] --hours [] --minutes [] --seconds []
struct tm start_time;
struct tm end_time;
struct tm diff_time;
char buffer_time[80];
int seconds;
struct timespec tstart={0,0}, tend={0,0};

char help[2000] = "\n Forma de uso:\n\n"
		" Ejemplo: Para configurar la fecha y hora del equipo.\n"
		" ./settings --date --year [] --month [] --day [] --hours [] --minutes [] --seconds [] \n\n"
		" ./settings --date -y 15 -m 12 -d 10 -h 15 -t 30 -s 00 \n\n"
		" Ejemplo: Para configurar el canal del lado linea.\n"
		" ./settings --canal valor \n\n"
		" ./settings --canal 2 \n\n "
		" Ejemplo: Para configurar la potencia del lado linea.\n"
		" ./settings --potencia valor \n\n"
		" ./settings --potencia 5 \n\n"
		" Ejemplo: Para configurar la compensacion de dispersion cromatica del lado linea.\n"
		" ./settings --cd_compensacion minimo,maximo \n\n"
		" ./settings --cd_compensacion -1000,1000 \n\n"
		" ./settings --version \n\n"
		" Ejemplo: Para solicitar la información de hardware de los modulos.\n"
		" ./settings --hw_informacion \n\n"
		" Ejemplo: Para configurar direccion ip (br0) \n\n"
		" ./settings --configurar_ip --br0_ip 192.168.1.100 --br0_netmask 255.255.255.0 --br0_broadcast 192.168.1.255 --br0_gateway 192.168.1.1 \n\n"
		" Ejemplo: Para configuracion direccion ip asutomatica (DHCP) \n\n"
		" ./settings --configurar_ip --br0_auto \n\n"
		" Ejemplo: Para guardar direccion ip \n\n"
		" ./settings --guardar_ip --br0_ip 192.168.1.100 --br0_netmask 255.255.255.0 --br0_broadcast 192.168.1.255 --br0_gateway 192.168.2.2 \n\n"
		" Ejemplo: Para configuracion guardar ip automatica (DHCP) \n\n"
		" ./settings --guardar_ip --br0_auto \n\n"
		" Ejemplo: Para solicitar la información de configuracion de red guardada.\n"
		" ./settings --nw_informacion \n\n";

int main(int argc, char **argv)
{
	char option[100];
	char value[100];
	char argument[40];
	int c;
	int flag_y, flag_m, flag_d, flag_h, flag_t, flag_s;
	int eth0_ch = 0;
	int eth1_ch = 0;

	date_now d;
	time_now t;

	// init GPIO
	pio_init();

	// Load default configuration from file
	Muxponder mxp;
	load_configuration_file(&mxp);

	// Struct to translate long options (--) to short options (-)
	struct option long_options[] =
	{
	{ "date", no_argument, NULL, 'n' },
	{ "year", required_argument, NULL, 'y' },
	{ "month", required_argument, NULL, 'm' },
	{ "day", required_argument, NULL, 'd' },
	{ "hours", required_argument, NULL, 'h' },
	{ "minutes", required_argument, NULL, 't' },
	{ "seconds", required_argument, NULL, 's' },
	{ "canal", required_argument, NULL, 'c' },
	{ "potencia", required_argument, NULL, 'p' },
	{ "cd_compensacion", required_argument, NULL, 'x' },
	{ "hw_informacion", no_argument, NULL, 'w' },
	{ "nw_informacion", no_argument, NULL, 'r' },
	{ "br0_auto", no_argument, NULL, 'a' },
	{ "br0_ip", required_argument, NULL, 'i' },
	{ "br0_netmask", required_argument, NULL, 'e' },
	{ "br0_broadcast", required_argument, NULL, 'g' },
	{ "br0_gateway", required_argument, NULL, 'f' },
	{ "configurar_ip", no_argument, NULL, 'q' },
	{ "guardar_ip", no_argument, NULL, 'k' },
	{ "version", no_argument, NULL, 'v' },
	{ "ayuda", no_argument, NULL, '?' },
	{ 0, 0, 0, 0 }, };

	flag_y = flag_m = flag_d = flag_h = flag_t = flag_s = 0;
	d.year = d.month = d.day = t.hours = t.minutes = t.seconds = 0;

	while (1)
	{
		int option_index = 0;

		c = getopt_long(argc, argv, "ny:m:d:h:t:s:c:p:x:wrai:e:g:f:bl:o:i:z:u:qkv?", long_options, &option_index);

		//Detect the end of the options.
		if (c == -1)
		{
			break;
		}

		switch (c)
		{
		case 'n':
			if (flag_y == 1)
				rtc_set_years(d.year);
			if (flag_m == 1)
				rtc_set_months(d.month);
			if (flag_d == 1)
				rtc_set_date(d.day);
			if (flag_h == 1)
				rtc_set_hour(t.hours);
			if (flag_t == 1)
				rtc_set_minutes(t.minutes);
			if (flag_s == 1)
				rtc_set_seconds(t.seconds);

			set_date_from_rtc();
			break;

		case 'y':
			if (flag_y == 1)
				doc();
			else
			{
				flag_y = 1;
				d.year = atoi(optarg);
				if (d.year < 0)
				{
					d.year = 0;
					doc();
				}
			}
			break;

		case 'm':
			if (flag_m == 1)
				doc();
			else
			{
				flag_m = 1;
				d.month = atoi(optarg);
				if (d.month > 12 || d.month < 1)
				{
					d.month = 0;
					doc();
				}
			}
			break;

		case 'd':
			if (flag_d == 1)
				doc();
			else
			{
				flag_d = 1;
				d.day = atoi(optarg);
				if (d.day > 31 || d.day < 1)
				{
					d.day = 0;
					doc();
				}
			}
			break;

		case 'h':
			if (flag_h == 1)
				doc();
			else
			{
				flag_h = 1;
				t.hours = atoi(optarg);
				if (t.hours > 23 || t.hours < 0)
				{
					t.hours = 0;
					doc();
				}
			}
			break;

		case 't':
			if (flag_t == 1)
				doc();
			else
			{
				flag_t = 1;
				t.minutes = atoi(optarg);
				if (t.minutes > 59 || t.minutes < 0)
				{
					t.minutes = 0;
					doc();
				}
			}
			break;

		case 's':
			if (flag_s == 1)
				doc();
			else
			{
				flag_s = 1;
				t.seconds = atoi(optarg);
				if (t.seconds > 59 || t.seconds < 0)
				{
					t.seconds = 0;
					doc();
				}
			}
			break;

		case 'c':
			strcpy(value, optarg);
			float canal = atof(value);

			clock_gettime(CLOCK_MONOTONIC, &tstart);

			hl_txp_set_tx_rx_laser_itu_channel(canal);

			clock_gettime(CLOCK_MONOTONIC, &tend);
			printf("Tiempo de configuración %.5f segundos\n", ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

			return 0;

		case 'p':
			strcpy(value, optarg);
			float power = atof(value);


			clock_gettime(CLOCK_MONOTONIC, &tstart);

    		hl_edfa_set_pout(power);

			clock_gettime(CLOCK_MONOTONIC, &tend);
			printf("Tiempo de configuración %.5f segundos\n", ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

			return 0;

		case 'x':
			strcpy(value, optarg);
			int min_bulk_cd_comp = atoi(strtok(value, ","));
			int max_bulk_cd_comp = atoi(strtok(NULL, ","));

			clock_gettime(CLOCK_MONOTONIC, &tstart);

			hl_txp_set_bulk_cd_compensation(min_bulk_cd_comp, max_bulk_cd_comp);

			clock_gettime(CLOCK_MONOTONIC, &tend);
			printf("Tiempo de configuración %.5f segundos\n", ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

			return 0;

		case 'w':
			print_hardware_information();
			return 0;

		case 'a':
			mxp.network[0].eth_auto = 1;
			eth0_ch = 1;
			break;

		case 'i':
			strcpy(argument, optarg);
			if (is_valid_ip_address(argument))
			{
				mxp.network[0].eth_auto = 0;
				strcpy(mxp.network[0].ip, argument);
				eth0_ch = 1;
			}
			break;

		case 'e':
			strcpy(argument, optarg);
			if (is_valid_ip_address(argument))
			{
				mxp.network[0].eth_auto = 0;
				strcpy(mxp.network[0].netmask, argument);
				eth0_ch = 1;
			}
			break;

		case 'g':
			strcpy(argument, optarg);
			if (is_valid_ip_address(argument))
			{
				mxp.network[0].eth_auto = 0;
				strcpy(mxp.network[0].broadcast, argument);
				eth0_ch = 1;
			}
			break;

		case 'f':
			strcpy(argument, optarg);
			if (is_valid_ip_address(argument))
			{
				mxp.network[0].eth_auto = 0;
				strcpy(mxp.network[0].gateway, argument);
				eth0_ch = 1;
			}
			break;


		case 'r':
			printf("Configuración de Red guardada \n");

			int i;
			for (i = 0; i < sizeof(mxp.network) / sizeof(mxp.network[0]); i++)
			{
				char port_number[5] = "br";

				char number[5] =
				{ 0 };

				sprintf(number, "%d", i);

				strncat(port_number, number, sizeof(number));

				printf("%s DHCP : %d \n", port_number, mxp.network[i].eth_auto);
				printf("%s IP : %s \n", port_number, mxp.network[i].ip);
				printf("%s NETMASK : %s \n", port_number, mxp.network[i].netmask);
				printf("%s BROADCAST : %s \n", port_number, mxp.network[i].broadcast);
				printf("%s GATEWAY : %s \n", port_number, mxp.network[i].gateway);
			}

			return 0;

		case 'q':
		case 'k':
			strcpy(option, long_options[option_index].name);
			break;

		case 'v':
			printf("\n\nVersion: %s\n\n", SETTINGS);
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
		printf("Utilizar opcion --ayuda para mas informacion.\n");
		return 0;
	}

	if (strcmp(option, "configurar_ip") == 0)
	{
		if (eth0_ch == 1)
		{
			network_configuration(mxp, 0);
		}
		printf("Ip configurada.\n");
	}
	else if (strcmp(option, "guardar_ip") == 0)
	{
		if (eth0_ch == 1)
		{
			update_initial_configuration_file(mxp);
			printf("Configuración guardada en archivo.\n");
		}
	}
	else
	{
		printf("No se especifico la accion a realizar, utilizar opcion --ayuda para mas informacion.\n");
	}

	return 0;
}

