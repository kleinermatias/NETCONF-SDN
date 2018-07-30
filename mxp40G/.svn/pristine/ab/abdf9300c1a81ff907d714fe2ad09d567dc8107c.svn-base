#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

#include "../../lib/gpio/gpio.h"

int main (int argc, char **argv)
{
	int next_opt, ret_code;
	int power=2;
	int flag_p=0;

	const char* const short_opt = "p:" ;
    
	const struct option long_opt[] = {
		{ "power", 1, NULL,'p'},
		{  NULL, 0, NULL, 0 }
	};

	/* Si se ejecuta sin parámetros ni opciones */
	if (argc == 1) {
		doc();
	}

	while (1) {
		next_opt = getopt_long (argc, argv, short_opt, long_opt, NULL);

		if (next_opt == -1) break;

		switch (next_opt) {
		
			case 'p': //seconds
            
			if (flag_p==1) {
				doc();
			}
			
			else {
				flag_p=1;	
			
				if(strcmp("up",optarg)==0) {
					power=1;
				}
				else if (strcmp("down",optarg)==0) {
					power = 0;
				}
				else {
					return 0;
				}
			}
                       
            		break;
            
			case '?':
				doc ();
				exit(1);
				break;
			
			case -1:
				doc ();
				exit(1);
				break;
				
			default:
				abort();
				break;
		}
	}
    
	if(power==1) {
		cs6041_power_up();
	}
	else {
		cs6041_power_down();
	}

return 0;
}

void doc() {
    printf("USAGE: cs6041 --power [state] \n");
}

int cs6041_power_up () {

	int high = 1;
	unsigned int usecs = 200000;

	printf("\n Inicializando secuencia de encendido chip Cortina cs6041... \n");

	gpio_write_bit(PWR_1_V_EN, high);

	usleep(usecs);

	gpio_write_bit(PWR_1_8_V_EN, high);

	usleep(usecs);

	gpio_write_bit(PWR_2_5_V_EN, high);
	
	printf("\n ...Secuencia de encendido chip Cortina cs6041 finalizada. \n");
	
	printf("\n Habilitando oscilador de 400 MHz... \n");

	usleep(usecs);

	//gpio_write_bit(CLK_OSC_400MHZ_EN, high);
	
	printf("\n ...Oscilador de 400 MHz habilitado. \n");

return 0; 
}

cs6041_power_down () {

	int down = 0;
	unsigned int usecs = 200000;
	
	printf("\n Desabilitando oscilador de 400 MHz... \n");

	//gpio_write_bit(CLK_OSC_400MHZ_EN, down);

	usleep(usecs);
	
	printf("\n ...Oscilador de 400 MHz dehabilitado. \n");

	printf("\n Inicializando secuencia de apagado chip Cortina cs6041... \n");

	gpio_write_bit(PWR_2_5_V_EN, down);

	usleep(usecs);

	gpio_write_bit(PWR_1_8_V_EN, down);

	usleep(usecs);

	gpio_write_bit(PWR_1_V_EN, down);
	
	printf("\n ...Secuencia de apagado chip Cortina cs6041 finalizada. \n");

return 0;
}
