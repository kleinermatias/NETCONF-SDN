#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hl_config_edfa.h"
#include "../../lib/gpio/gpio.h"
#include "../../lib/edfa/edfa.h"

int main (int argc, char **argv)
{
	gpio_write_bit(LTC_BIT_STATUS, 1);
	usleep(250000);
	gpio_write_bit(EDFA_PIN_RESET, 1);
	usleep(250000);

	int command, argument, parameter, stage;
	float pump_mA, value;

	if(argc == 2)
	{
		if(strcmp(argv[1],"ver") == 0)
		{
			edfa_set_echo(0);
			edfa_get_information();
		}

		else if(strcmp(argv[1],"echo") == 0)
		{
			edfa_get_echo();
		}

		else if(strcmp(argv[1],"mode") == 0)
		{
			edfa_set_echo(0);
			edfa_get_mode();
		}

		else if(strcmp(argv[1],"baud") == 0)
		{
			edfa_set_echo(0);
			edfa_get_baud_rate();
		}

		else if(strcmp(argv[1],"pin") == 0)
		{
			edfa_set_echo(0);
			edfa_get_input_power();
		}

		else if(strcmp(argv[1],"pout") == 0)
		{
			edfa_set_echo(0);
			edfa_get_output_power();
		}

		else if(strcmp(argv[1],"psig") == 0)
		{
			edfa_set_echo(0);
			edfa_get_signal_power();
		}

		else if(strcmp(argv[1],"gain") == 0)
		{
			edfa_set_echo(0);
			edfa_get_signal_gain();
		}

		else if(strcmp(argv[1],"mt") == 0)
		{
			edfa_set_echo(0);
			edfa_get_temperature_case();
		}

		else if(strcmp(argv[1],"pump") == 0)
		{
			edfa_set_echo(0);
			edfa_get_pump_status(EDFA_PUMP_ALL);
		}

		else if(strcmp(argv[1],"ast") == 0)
		{
			edfa_set_echo(0);
			edfa_list_all_alarm();
		}

		else if(strcmp(argv[1],"alrm") == 0)
		{
			edfa_set_echo(0);
			edfa_get_alarm_information(EDFA_ALARM_ALL, EDFA_ALARM_PARAM_ALL);
		}

		else if(strcmp(argv[1],"mst") == 0)
		{
			edfa_set_echo(0);
			edfa_get_amplifier_status();
		}

		else if(strcmp(argv[1],"los") == 0)
		{
			edfa_set_echo(0);
			edfa_get_los_mode();
		}

		else if(strcmp(argv[1],"rst") == 0)
		{
			//edfa_set_echo(0);
			edfa_reset_factory_default_values();
		}

		else if(strcmp(argv[1],"boot") == 0)
		{
			//edfa_set_echo(0);
			edfa_reset_firmware();
		}

		else if(strcmp(argv[1],"astm") == 0)
		{
			edfa_set_echo(0);
			edfa_get_alarm_mode();
		}

		else
		{
			printf("Wrong command. Options: ./hl_config_edfa ver | ./hl_config_edfa mode |./hl_config_edfa echo \n");
			return -1;
		}
	}

	else if (argc == 3)
	{
		if(strcmp(argv[1],"echo") == 0)
		{
			if(strcmp(argv[2],"on") == 0)
					edfa_set_echo(1);
			else if (strcmp(argv[2],"off") == 0)
				edfa_set_echo(0);
			else
			{
				printf("Wrong argument. Options: ./hl_config_edfa echo on | ./hl_config_edfa echo off \n");
				return -1;
			}
		}

		else if(strcmp(argv[1],"astm") == 0)
		{
			if(strcmp(argv[2],"n") == 0)
				argument = EDFA_ALARM_MODE_NORMAL;
			else if (strcmp(argv[2],"s") == 0)
				argument = EDFA_ALARM_MODE_STICKY;
			else
			{
				printf("Wrong argument. Options: ./hl_config_edfa astm n | ./hl_config_edfa astm s \n");
				return -1;
			}
			edfa_set_alarm_mode(argument);
		}

		else if(strcmp(argv[1],"los") == 0)
		{
			if(strcmp(argv[2],"a") == 0)
				argument = EDFA_LOS_MODE_A;
			else if (strcmp(argv[2],"i") == 0)
				argument = EDFA_LOS_MODE_I;
			else if (strcmp(argv[2],"p") == 0)
				argument = EDFA_LOS_MODE_P;
			else if (strcmp(argv[2],"n") == 0)
				argument = EDFA_LOS_MODE_N;
			else
			{
				printf("Wrong argument. Options: ./hl_config_edfa los a | i | p | n \n");
				return -1;
			}
			edfa_set_los_mode(argument);
		}

		else if(strcmp(argv[1],"mode") == 0)
		{
			if(strcmp(argv[2],"d") == 0)
				argument = EDFA_MODE_D;
			else if (strcmp(argv[2],"m") == 0)
				argument = EDFA_MODE_M;
			else
			{
				printf("Wrong argument. Options: ./hl_config_edfa mode d | m \n");
				return -1;
			}
			edfa_set_mode(argument);
		}

		else if(strcmp(argv[1],"pump") == 0)
		{
			if(strcmp(argv[2],"ild") == 0)
				argument = EDFA_PUMP_ILD;
			else if (strcmp(argv[2],"eol") == 0)
				argument = EDFA_PUMP_EOL;
			else if (strcmp(argv[2],"tmp") == 0)
				argument = EDFA_PUMP_TMP;
			else
			{
				printf("Wrong argument. Options: ./hl_config_edfa pump ild | eol | tmp \n");
				return -1;
			}
			edfa_get_pump_status(argument);
		}

		else if (strcmp(argv[1],"sglim") == 0)
		{
			stage = atoi(argv[2]);

			edfa_get_sglim(stage);
		}

		else if (strcmp(argv[1],"splim") == 0)
		{
			stage = atoi(argv[2]);

			edfa_get_splim(stage);
		}

		else
		{
			printf("Wrong argument. Options: ./hl_config_edfa command argument \n");
			return -1;
		}
	}

	else if (argc == 4)
	{
		if(strcmp(argv[1],"alrm") == 0)
		{
			if(strcmp(argv[2],"ild") == 0)
				argument = EDFA_ALARM_ILD;

			else if(strcmp(argv[2],"tmp") == 0)
				argument = EDFA_ALARM_TMP;

			else if(strcmp(argv[2],"mth") == 0)
				argument = EDFA_ALARM_MTH;

			else if(strcmp(argv[2],"mtl") == 0)
				argument = EDFA_ALARM_MTL;

			else if(strcmp(argv[2],"los") == 0)
				argument = EDFA_ALARM_LOS;

			else if(strcmp(argv[2],"lop") == 0)
				argument = EDFA_ALARM_LOP;

			else
			{
				printf("Wrong argument. Options: ild | tmp | mth | mtl | los | lop \n");
				return -1;
			}

			if(strcmp(argv[3],"sta") == 0)
				parameter = EDFA_ALARM_PARAM_STA;

			else if(strcmp(argv[3],"sst") == 0)
				parameter = EDFA_ALARM_PARAM_SST;

			else if(strcmp(argv[3],"thr") == 0)
				parameter = EDFA_ALARM_PARAM_THR;

			else if(strcmp(argv[3],"hys") == 0)
				parameter = EDFA_ALARM_PARAM_HYS;

			else
			{
				printf("Wrong parameter. Options: sta | sst | thr | hys \n");
				return -1;
			}
			edfa_set_echo(0);
			edfa_get_alarm_information(argument, parameter);
		}

		else if(strcmp(argv[1],"mode") == 0)
		{
			if(strcmp(argv[2],"g") == 0)
				argument = EDFA_MODE_G;
			else if(strcmp(argv[2],"p") == 0)
				argument = EDFA_MODE_P;
			else
			{
				printf("Wrong argument. Options: g | p \n");
				return -1;
			}

			char value[32];
			int i;

			for (i = 0; i < 32; ++i)
				value[i] = '\0';

			sprintf(value, "%f\n", argv[3]);
			edfa_set_echo(0);
			edfa_set_mode_and_gain(argument, parameter);
		}

		else if(strcmp(argv[1],"pump") == 0)
		{
			if(strcmp(argv[2],"isp") == 0)
				pump_mA = atof(argv[3]);
			else
			{
				printf("Wrong argument. Options: ./hl_config_edfa pump isp cur [mA] \n");
				return -1;
			}

			printf("String value = %s, Float value = %f\n", argv[3], pump_mA);
			//limitar umbrales antes de habilitar la siguiente función
			//edfa_set_pump_mA(pump_mA);
		}

		else if (strcmp(argv[1],"sglim") == 0)
		{
			stage = atoi(argv[2]);
			value = atof(argv[3]);

			printf("sglim stage = %d, sglim value = %f\n", stage, value);
			//limitar umbrales antes de habilitar la siguiente función
			//edfa_set_sglim(stage, value);
		}

		else if (strcmp(argv[1],"splim") == 0)
		{
			stage = atoi(argv[2]);
			value = atof(argv[3]);

			printf("splim stage = %d, splim value = %f\n", stage, value);
			//limitar umbrales antes de habilitar la siguiente función
			//edfa_set_splim(stage, value);
		}

		else
		{
			printf("Wrong argument. Options: ./hl_config_edfa command argument parameter\n");
			return -1;
		}
	}

	else if (argc == 5)
	{
		if(strcmp(argv[1],"alrm") == 0)
		{
			int alrm;

			if(strcmp(argv[2],"ild") == 0)
				alrm = EDFA_ALARM_ILD;

			else if(strcmp(argv[2],"tmp") == 0)
				alrm = EDFA_ALARM_TMP;

			else if(strcmp(argv[2],"mth") == 0)
				alrm = EDFA_ALARM_MTH;

			else if(strcmp(argv[2],"mtl") == 0)
				alrm = EDFA_ALARM_MTL;

			else if(strcmp(argv[2],"los") == 0)
				alrm = EDFA_ALARM_LOS;

			else if(strcmp(argv[2],"lop") == 0)
				alrm = EDFA_ALARM_LOP;

			else
			{
				printf("Wrong argument. Options: ild | tmp | mth | mtl | los | lop \n");
				return -1;
			}

			if(strcmp(argv[3],"thr") != 0)
			{
				printf("Wrong argument. Options: thr \n");
				return -1;
			}

			float level = atof(argv[4]);

			printf("alrm = %d, level = %f\n", alrm, level);
			//limitar umbrales antes de habilitar la siguiente función
			//edfa_set_threshold_level(alrm, level);
		}

		else
		{
			printf("Wrong argument. Options: ./hl_config_edfa command argument argument value\n");
			return -1;
		}
	}

	else
	{
		printf("Wrong command. Options: ./hl_config_edfa ver | ./hl_config_edfa MODE mode |./hl_config_edfa ALRM alrm param \n");
		return -1;
	}

return 0;
}
