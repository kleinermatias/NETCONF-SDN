#include "loopback.h"

///@ XFP: ./loopback --xfp --[0|1|2|3|4] --[habilitar|deshabilitar]
/// para loopback eléctrico en los módulos xfp (0 selecciona todos los módulos).

///@ TRANSPONDER: ./loopback --transponder --tipo --[habilitar|deshabilitar]
/// Para loopback en el modulo transponder --tipo puede ser diagnostico or linea.

///@ PROCESADOR: ./loopback --procesador --lado --tipo --[0|1|2|3|4] --[habilitar|deshabilitar]
/// Para loopback de procesador, donde el lado puede ser a o b;
/// y el tipo puede ser farend o facility. Los parámetros --[0|1|2|3|4] solo se utilizan para el lado b (0 selecciona todos los slices).

char help[1000] = "\n\nForma de uso:\n\n"
		"XFP: ./loopback --xfp --[0|1|2|3|4] --[habilitar|deshabilitar]\n"
		"para loopback eléctrico en los módulos xfp.\n"
		"La opción \"--0\" selecciona todos los módulos.\n\n"
		"TRANSPONDER: ./loopback --transponder --tipo --[habilitar|deshabilitar]\n"
		"Para loopback en el modulo transponder --tipo puede ser \"diagnostico\" o \"linea\".\n\n"
		"PROCESADOR: ./loopback --procesador --lado --tipo --[0|1|2|3|4] --[habilitar|deshabilitar]\n"
		"Para loopback de módulo de transporte, donde el lado puede ser \"a\" o \"b\", y el tipo puede ser \"farend\" o \"facility\".\n"
		"Los parámetros --[0|1|2|3|4] solo se utilizan para el lado b indicando el slice.\n"
		"La opción \"--0\" selecciona todos los slices.\n\n";

int main(int argc, char **argv)
{
	if (argc > 9)
	{
		printf("Error: Demasiados argumentos");
		return 0;
	}

	Loopback options;
	memset(options.slices, 0, sizeof(options.slices));
	options.enable = -1;

	// Struct to translate long options (--) to short options (-)
	struct option long_options[] =
	{
	{ "xfp", no_argument, NULL, 'x' },
	{ "procesador", no_argument, NULL, 'c' },
	{ "a", no_argument, NULL, 'a' },
	{ "b", no_argument, NULL, 'b' },
	{ "transponder", no_argument, NULL, 't' },
	{ "diagnostico", no_argument, NULL, 'o' },
	{ "linea", no_argument, NULL, 'l' },
	{ "farend", no_argument, NULL, 'i' },
	{ "facility", no_argument, NULL, 'e' },
	{ "1", no_argument, NULL, '1' },
	{ "2", no_argument, NULL, '2' },
	{ "3", no_argument, NULL, '3' },
	{ "4", no_argument, NULL, '4' },
	{ "0", no_argument, NULL, '0' },
	{ "habilitar", no_argument, NULL, 'h' },
	{ "deshabilitar", no_argument, NULL, 'd' },
	{ "version", no_argument, NULL, 'v' },
	{ "ayuda", no_argument, NULL, '?' },
	{ 0, 0, 0, 0 }, };

	int c;

	while (1)
	{
		int option_index = 0;

		c = getopt_long(argc, argv, "xcabtolie12340hdv?", long_options, &option_index);

		//Detect the end of the options.
		if (c == -1)
		{
			break;
		}

		switch (c)
		{
		case 'x':
		case 'c':
		case 't':
			strcpy(options.module, long_options[option_index].name);
			break;

		case 'a':
		case 'b':
			strcpy(options.side, long_options[option_index].name);
			break;

		case 'o':
		case 'l':
		case 'i':
		case 'e':
			strcpy(options.loopback, long_options[option_index].name);
			break;

		case 'h':
			options.enable = 1;
			break;

		case 'd':
			options.enable = 0;
			break;

		case '1':
			options.slices[1] = 1;
			break;

		case '2':
			options.slices[2] = 1;
			break;

		case '3':
			options.slices[3] = 1;
			break;

		case '4':
			options.slices[4] = 1;
			break;

		case '0':
			options.slices[0] = 1;
			break;

		case 'v':
			printf("\n\nVersion: %s\n\n", LOOPBACK);
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

	if (options.enable != 0 && options.enable != 1)
	{
		printf("No se especificó opción de habilitar o deshabilitar loopback, utilizar opción --ayuda para mas información.\n");
		return 0;
	}

	if (strcmp(options.module, "xfp") == 0)
	{
		if (argc < 4 || argc > 7)
		{
			printf("Error: argumentos erróneos para configurar loopback xfp, utilizar opción --ayuda para mas información.\n");
			return 0;
		}

		// habilita o deshabilita loopback eléctrico en módulos xfp
		xfp_set_loopback(options.enable, options.slices);
	}
	else if (strcmp(options.module, "transponder") == 0)
	{
		if (argc != 4)
		{
			printf("Error: argumentos erróneos para configurar loopback transponder, utilizar opción --ayuda para mas información.\n");
			return 0;
		}

		if (strcmp(options.loopback, "diagnostico") == 0)
		{

			if (options.enable)
			{
				hl_txp_config_40g_otu3(0, 1, 1);
				printf("Loopback de diagnóstico habilitado en modulo transponder\n");
			}
			else
			{
				hl_txp_config_40g_otu3(0, 0, 1);
				printf("Loopback de diagnóstico deshabilitado en modulo transponder\n");
			}
		}
		else if (strcmp(options.loopback, "linea") == 0)
		{
			if (options.enable)
			{
				hl_txp_config_40g_otu3(1, 0, 1);
				printf("Loopback de línea habilitado en modulo transponder\n");
			}
			else
			{
				hl_txp_config_40g_otu3(0, 0, 1);
				printf("Loopback de línea deshabilitado en modulo transponder\n");
			}
		}
		else
		{
			printf("No se especificó el tipo para realizar el loopback, utilizar opción --ayuda para mas información.\n");
		}
	}
	else if (strcmp(options.module, "procesador") == 0)
	{
		if (argc < 5 || argc > 9)
		{
			printf("Error: argumentos erróneos para configurar loopback en procesador, utilizar opción --ayuda para mas información.\n");
			return 0;
		}

		open_upie();

		int loopback_type;
		if (strcmp(options.loopback, "farend") == 0)
		{
			loopback_type = TEN_HSIF_LOOPBACK_FAR_END;
		}
		else if (strcmp(options.loopback, "facility") == 0)
		{
			if (strcmp(options.side, "a") == 0)
			{
				loopback_type = TEN_HSIF_LOOPBACK_FACILITY;
			}
			else
			{
				// For all slices
				if (options.slices[0] == 1)
				{
					loopback_type = TEN_HSIF_LOOPBACK_FACILITY;
				}
				// For individual slices
				else
				{
					loopback_type = TEN_HSIF_LOOPBACK_FACILITY_XFI;
				}
			}
		}
		else
		{
			printf("No se especificó el tipo para realizar el loopback, utilizar opción --ayuda para mas información.\n");
			return 0;
		}

		if (strcmp(options.side, "a") == 0)
		{
			set_cs6041_loopback(0, loopback_type, options.enable, options.slices);
		}
		else if (strcmp(options.side, "b") == 0)
		{
			set_cs6041_loopback(1, loopback_type, options.enable, options.slices);
		}
		else
		{
			printf("No se especificó el lado para realizar el loopback, utilizar opción --ayuda para mas información.\n");
			return 0;
		}

		close_upie();
	}
	else
	{
		printf("No se especificó el módulo para realizar el loopback, utilizar opción --ayuda para mas información.\n");
	}

	return 0;
}
