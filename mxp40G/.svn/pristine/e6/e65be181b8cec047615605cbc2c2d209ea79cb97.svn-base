#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <arpa/inet.h>
#include "unistd.h"
#include "../../lib/edfa/hl_edfa.h"

#include "../../lib/xfp/hl_xfp.h"

#define RELEASE_PLATFORM
#define CS_LITTLE_ENDIAN

// Struct for information of the board.
typedef struct board_data
{
	char name[4];
	char serial_number[10];
	char version_number[10];

} Board;

// Take the Board Info Name from board_info.txt to put it into the logging files name.
void board_info(Board *info);

// Impression of lines to separate elements of a table.
// length: number of lines
// file: pointer to the file to store log data
// log_file: enable log into file
void print_frame(unsigned int length, FILE *file, unsigned int log_file, char table_data[]);

// Impression of header of a table.
// format: array to store the format of every column
// frame_length: number of lines for the title
// title: data of the title of the table
// columns: number of columns of the table
// file: pointer to the file to store log data
// log_file: enable log into file
void concatenate_header(char format[][100], unsigned int frame_length, char title[][100], unsigned int columns, FILE *file, unsigned int log_file, char table_data[]);

// Impression of columns of a table.
// format: array to store the format of every column
// title: data of the title of the table
// columns: number of columns of the table
// file: pointer to the file to store log data
// log_file: enable log into file
void concatenate_columns(char format[][100], char title[][100], unsigned int columns, FILE *file, unsigned int log_file, char table_data[]);

// Log out data to a file.
void logger(const char* msg, FILE *file, unsigned int log_file);

// Obtains the format for the impression of a table according to the size of the columns of the table.
// format: array to store the format of every column
// columns: number of columns of the table
// column_size: number of spaces needed per column
void get_format(char format[][100], int columns, int column_size[]);

// Obtains the size of impression necessary for the separation of rows of a table.
// column_size: number of spaces needed per column
// columns: number of columns of the table
int get_frame_length(int column_size[], int columns);

// Obtains the necessary size to represent every column of the table.
// ! array column_size must be initialized to 0.
// column_size: number of spaces needed per column
// columns: number of columns of the table
// data: array with the data to show
void compute_column_size(int column_size[], int columns, char data[][100]);

// Clear the console.
void clear_screen(void);

// Obtains the current time.
// ts_system_time: struct to store current time.
void get_time(struct tm *ts_system_time);

// Converts a time struct to char.
// ts_system_time: struct to get the time to be converted to char.
// buffer_system_time: char to store the converted time.
void get_string_from_time(struct tm *tm, char* buffer_system_time);

// Obtains the difference between time structs ts_tim1 and ts_time2 and saves the result in the struct diff.
// ts_time1: first time to compute the difference.
// ts_time2: second time to compute the difference.
// diff: struct to store the difference (ts_time1 - ts_time2).
void get_time_difference(struct tm *ts_time1, struct tm *ts_time2, struct tm *diff);

// Prints hardware information of modules
void print_hardware_information(void);

// Prints hardware information of the muxponder
void mxp_hardware_information(void);

// Check if the input IP has a valid format
int is_valid_ip_address(char *ipAddress);


#endif /* UTILS_H_ */
