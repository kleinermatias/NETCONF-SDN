#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "help.h"



int main (int argc, char **argv)
{
    int c;
    FILE *file;
    char name[256];

    if (argc > 1) {
        
        /*strcpy(name, MAN_DIR);
        strcat(name, argv[1]);
        strcat(name, MAN_EXT);*/    
        if(strcmp(argv[1],"-^")==0)
            {
                printf("help");
                return 0;
            }
       
       strcpy(name,"/opt/doc/");
       strcat(name, argv[1]);
       strcat(name, ".txt");
        file = fopen(name, "r");
        if (file) {
            while ((c = getc(file)) != EOF) {
                putchar(c);
            }
            fclose(file);
        }
    }

    return 0;
}










