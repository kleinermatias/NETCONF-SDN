#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "debugjdsu.h"
#include "../../lib/i2c/i2crw.h"

int main(int argc, char **argv)
{
  unsigned char trama[argc-1];
  int i;
  
  int len =atoi(argv[1]);
  
 
  /*
  for(i=2;i<argc;i++)
    trama[i-2] = strtol(argv[i], NULL, 16);

  if (txp_cmd_chk_byte(trama)<0)
    return -1;
  
  printf("Trama a enviar: 0x%x",trama[0]);
 
  for(i=1;i<sizeof(trama)-1;i++){
    if((int)trama[i]<10)
     printf(" 0x0%x", trama[i]);
    else
     printf(" 0x%x", trama[i]);
  }
  
  printf(" 0x%x\n",trama[sizeof(trama)-1]);
    
  //printf("\nLongitud esperada: %d\n\n",len);
   //printf("\nRespuesta: \n");
  unsigned char reply[len];
  int j;
  if(txp_send_cmd(trama,reply,len)!=-1)
    for(j=0;j<len;j++)
            printf(" %x ",reply[j]);
  printf("\n");
  /*unsigned short reply_len = atoi(argv[1]);
  unsigned char reply[reply_len];
  
 int i;
  if (i2c_read(TXP_BUS, TXP_ADDRESS, -1,I2C_SMBUS_BLOCK_DATA, (int*)reply, reply_len) == 0)
    for(i=0;i<reply_len;i++)
            printf("%x\n",reply[i]);
    */
  return 0;
}




