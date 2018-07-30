#include <sys/statvfs.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

#define COMANDO "df /var/log/ | tail -1 | awk '{print $5}' | cut -f 1 -d '%'"

int df ();
int test_app(char nombre[]);

int main( int argc, char *argv[] )
{
  //system("df -h /home/ | tail -1 | awk '{print $4}' | cut -f 1 -d 'G'");
   
   int used_space = df();
   printf("Espacio disponible: %d %\n",(100-used_space));
   printf("Espacio utilizado: %d %\n",(used_space));
   
   //primer paso, borrar todo los archivos de la carpeta /var/log/rsyslog/backups/
   if ( used_space >= 15 ) {
   
        system("rm -r /var/log/rsyslog/backups/*");
        printf("rm /var/log/rsyslog/backups/*\n");
   } 
     
   //segundo paso, limpiar los logs.
   
   return 0;
}

int df ()
{

  FILE *fp;
  char path[256];

  /* Open the command for reading. */
  fp = popen(COMANDO, "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    return -1;
  }

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path)-1, fp) != NULL) {
    //printf("%s", path);
    //printf("%d", atoi(path));
  }
    //printf("len: %d\n", strlen(path));
    //printf("%c\n", path[4]);
    
  pclose(fp);

  return atoi(path);
}





    
