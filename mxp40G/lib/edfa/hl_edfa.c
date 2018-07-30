#include "hl_edfa.h"


void edfa_hardware_information()
{
	unsigned char edfa_info[500];
	unsigned char serial_number[20];
	unsigned char part_number[20];

	int fd = 0;

	char tty[] = "/dev/ttyAL2";

	fd = open(tty, O_RDWR | O_NOCTTY | O_NONBLOCK);

	char *token;

	if (fd != -1)
	{
		edfa_set_terminal(fd);
		edfa_clean_fifo(fd);
		edfa_get_information(fd, edfa_info);

		token = strtok(edfa_info, ":\n");

		while (token != NULL)
		{
			if (strcmp(token, "Serial Number") == 0)
			{
				token = strtok(NULL, ":\n");
				printf("Número de serie:%s\n", token);
			}

			if (strcmp(token, "Catalog  Num.") == 0)
			{
				token = strtok(NULL, ":\n");
				printf("Número de parte:%s\n", token);
			}

			token = strtok(NULL, ":\n");
		}

		printf("\n");

		//Close File
		close(fd);
	}
}

void update_edfa_alarm_configuration(Edfa edfa_struct, mxml_node_t *alarms)
{
	mxml_node_t *edfa = mxmlNewElement(alarms, "edfa");

	mxml_node_t *node;

	node = mxmlNewElement(edfa, "amp_status");
	mxmlNewInteger(node, edfa_struct.severity.amp_status);
	node = mxmlNewElement(edfa, "input_power");
	mxmlNewInteger(node, edfa_struct.severity.input_power);
	node = mxmlNewElement(edfa, "lop");
	mxmlNewInteger(node, edfa_struct.severity.lop);
	node = mxmlNewElement(edfa, "los");
	mxmlNewInteger(node, edfa_struct.severity.los);
	node = mxmlNewElement(edfa, "output_power");
	mxmlNewInteger(node, edfa_struct.severity.output_power);
	node = mxmlNewElement(edfa, "temperature");
	mxmlNewInteger(node, edfa_struct.severity.temperature);
}

void load_edfa_alarm_data(Edfa *edfa_struct, char *alarm_name, int alarm_value)
{
	if(strcmp(alarm_name, "amp_status") == 0)
	{
        edfa_struct->severity.amp_status = alarm_value;
	}
	else if(strcmp(alarm_name, "input_power") == 0)
	{
		edfa_struct->severity.input_power = alarm_value;
	}
	else if(strcmp(alarm_name, "lop") == 0)
	{
		edfa_struct->severity.lop = alarm_value;
	}
	else if(strcmp(alarm_name, "los") == 0)
	{
		edfa_struct->severity.los = alarm_value;
	}
	else if(strcmp(alarm_name, "output_power") == 0)
	{
		edfa_struct->severity.output_power = alarm_value;
	}
	else if(strcmp(alarm_name, "temperature") == 0)
	{
		edfa_struct->severity.temperature = alarm_value;
	}
}

void load_default_edfa_alarms_parameters(Edfa *edfa_struct)
{
	edfa_struct->severity.amp_status = 1;
	edfa_struct->severity.input_power = 1;
	edfa_struct->severity.lop = 1;
	edfa_struct->severity.los = 1;
	edfa_struct->severity.output_power = 1;
	edfa_struct->severity.temperature = 1;
}
