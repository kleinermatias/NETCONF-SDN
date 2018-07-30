#include "utils.h"
#include "../../lib/txp/hl_txp.h"

void board_info(Board *info)
{
	char name[4];
	FILE * fp;

	fp = fopen("board_info.txt", "rt");

	if (fp != NULL)
	{
		fscanf(fp, "%s%s%s", info->name, info->serial_number, info->version_number);

		fclose(fp);
	}
}

void print_frame(unsigned int length, FILE *file, unsigned int log_file, char table_data[])
{
	unsigned int i;

	char lines[500] =
	{ 0 };

	for (i = 0; i < length; i++)
	{
		strcat(lines, "-");
	}
	logger(lines, file, log_file);
	logger("\n", file, log_file);

	strcat(table_data, lines);
	strcat(table_data, "\n");
}

void concatenate_header(char format[][100], unsigned int frame_length, char title[][100], unsigned int columns, FILE *file, unsigned int log_file, char table_data[])
{

	print_frame(frame_length, file, log_file, table_data);

	concatenate_columns(format, title, columns, file, log_file, table_data);

	print_frame(frame_length, file, log_file, table_data);

}

void concatenate_columns(char format[][100], char title[][100], unsigned int columns, FILE *file, unsigned int log_file, char table_data[])
{
	unsigned int i;
	char msg[300] =
	{ 0 };

	logger("|", file, log_file);

	for (i = 0; i < columns; i++)
	{
		sprintf(msg, format[i], title[i], '|');

		logger(msg, file, log_file);
		strcat(table_data, msg);
	}

	logger("\n", file, log_file);
	strcat(table_data, "\n");
}

void logger(const char* msg, FILE *file, unsigned int log_file)
{

	if ((log_file) && (file != NULL))
	{
		fprintf(file, "%s", msg);
	}
}

void get_format(char format[][100], int columns, int column_size[])
{

	char first[100]={0};
	char second[100]={0};
	unsigned long long width;

	int g;
	for (g = 0; g < columns; g++)
	{
		width=column_size[g] + 2;
		sprintf(first, "%llu", width);
		width=column_size[g] / 2;
		sprintf(second, "%llu", width);

		char format_str[100] =
		{ 0 };
		strcat(format_str, "%");

		strcat(format_str, first);

		strcat(format_str, "s%");

		strcat(format_str, second);

		strcat(format_str, "c");

		strcpy(format[g], format_str);
	}
}

int get_frame_length(int column_size[], int columns)
{
	int frame_length = 0;

	int i;
	for (i = 0; i < columns; i++)
	{
		frame_length += ((column_size[i] + 2) + column_size[i] / 2);
	}

	return frame_length;
}

void compute_column_size(int column_size[], int columns, char data[][100])
{

	int i;
	for (i = 0; i < columns; i++)
	{

		if (strlen(data[i]) > (unsigned) column_size[i])
		{
			column_size[i] = strlen(data[i]) + 5;
		}
	}
}

void get_time(struct tm *ts_system_time)
{
	struct tm *tim = ts_system_time; //This line is just to fix a problem with Eclipse toolchain
	time_t t = time(0);
	*tim = *localtime(&t);
	tim->tm_year += 1900;
	tim->tm_mon += 1;
}

void get_string_from_time(struct tm *tm, char* buffer_system_time)
{
	sprintf(buffer_system_time, "%d-%d-%d %d:%d:%d", tm->tm_year, tm->tm_mon, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
}

void get_time_difference(struct tm *ts_time1, struct tm *ts_time2, struct tm *diff)
{
	int seconds_t1 = (ts_time1->tm_mday * 24 * 3600) + (ts_time1->tm_hour * 3600) + (ts_time1->tm_min * 60) + ts_time1->tm_sec;
	int seconds_t2 = (ts_time2->tm_mday * 24 * 3600) + (ts_time2->tm_hour * 3600) + (ts_time2->tm_min * 60) + ts_time2->tm_sec;

	int seconds = seconds_t1 - seconds_t2;

	diff->tm_year = ts_time1->tm_year - ts_time2->tm_year;
	diff->tm_mon = ts_time1->tm_mon - ts_time2->tm_mon;
	diff->tm_mday = seconds / 60 / 60 / 24;
	diff->tm_hour = (seconds / 60 / 60) % 24;
	diff->tm_min = (seconds / 60) % 60;
	diff->tm_sec = seconds % 60;
}

void clear_screen()
{
	printf("\e[1;1H\e[2J");
}

void print_hardware_information()
{
	printf("\n\nInformación de Hardware: \n\n");

	printf("·············  Muxponder  ············· \n\n");
	mxp_hardware_information();

	printf("············· Modulos xfp ············· \n\n");
	hl_xfp_hardware_information();

	printf("············· Transponder ············· \n\n");
	hl_txp_hardware_information();

	printf("·············    Edfa     ············· \n\n");
	edfa_hardware_information();

	printf("············· Procesador  ············· \n\n");
	cs6041_hardware_information();

	printf("\n\n");

}

void mxp_hardware_information()
{
   Board info;

   board_info(&info);

   printf("Número de serie: %s\n", info.serial_number);
   printf("Número de versión: %s\n\n", info.version_number);
}

int is_valid_ip_address(char *ipAddress)
{
	struct sockaddr_in sa;
	int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));

	if (result != 0)
	{
		return 1;
	}
	else
	{
		printf("Por favor revise la dirección IP ingresada \n");
		return 0;
	}

}
