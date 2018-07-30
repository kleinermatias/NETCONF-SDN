#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "configJDSU.h"

int clean_stdin();

int main(int argc, char **argv)
{
    tx_cmd_t tx;
    rx_cmd_t rx;
    int value;
    char c;
         
    do
    {  
       printf("PRBSEN: 0 for framed PRBS mode \n        1 for normal operation\n");
       scanf("%d%c", &tx.prbsen, &c);
             
    } while ((tx.prbsen != 0) && (tx.prbsen != 1));
       
    printf("\n\nPRBSEN: %i\n",tx.prbsen);
    
    printf("\nSelects framed PRBS pattern length:\n Pat1  Pat0  Pattern \n  0     0      2^7 \n  0     1      2^15 \n  1     0      2^23 \n  1     1      2^31 \n");
    
    do
    {  
       printf("\Pat0: \n");
       scanf("%d%c", &tx.prbspat0, &c);
             
    } while ((tx.prbspat0 != 0) && (tx.prbspat0 != 1));
    
     do
    {  
       printf("\Pat1: \n");
       scanf("%d%c", &tx.prbspat1, &c);
             
    } while ((tx.prbspat1 != 0) && (tx.prbspat1 != 1));
   
    do
    {  
       printf("\nEnables Tx SFI-5 deskew algorithm:\n   0 for disable\n   1 for enable\n");
       scanf("%d%c", &tx.txdeskewen, &c);
             
    } while ((tx.txdeskewen != 0) && (tx.txdeskewen != 1));
    
    do
    {  
       printf("\nSelects TxTxDCK frequency:\n   0 for TxDCK = fedata/4 \n   1 for TxDCK = fedata\n");
       scanf("%d%c", &tx.txdcksel, &c);
             
    } while ((tx.txdcksel != 0) && (tx.txdcksel != 1));
    
    do
    {  
       printf("\nSelects line timing mode:\n   0 for line timing \n   1 for normal operation\n");
       scanf("%d%c", &tx.txlinetimsel, &c);
             
    } while ((tx.txlinetimsel != 0) && (tx.txlinetimsel != 1));
    
    do
    {  
       printf("\nEnables line loopback:\n   0 enable line loopback \n   1 for normal operation\n");
       scanf("%d%c", &tx.txlloopenb, &c);
             
    } while ((tx.txlloopenb != 0) && (tx.txlloopenb != 1));
    
    do
    {  
       printf("\nMux FIFO reset:\n   0 for Reset \n   1 for normal operation\n");
       scanf("%d%c", &tx.txfifores, &c);
             
    } while ((tx.txfifores != 0) && (tx.txfifores != 1));
    
    do
    {  
       printf("\nAutomatic Mux FIFO reset:\n   0 for auto reset on error enabled \n   1 for auto reset not enabled\n");
       scanf("%d%c", &tx.autotxfifores, &c);
             
    } while ((tx.autotxfifores != 0) && (tx.autotxfifores != 1));
    
    do
    {  
       printf("\nSelf-Clearing Mux system reset:\n   0 for Reset \n   1 for normal operation\n");
       scanf("%d%c", &tx.sctxreset, &c);
             
    } while ((tx.sctxreset != 0) && (tx.sctxreset != 1));
    
    do
    {  
       printf("\nTx Mute Mon Clk:\n   0 for mute \n   1 for normal operation\n");
       scanf("%d%c", &tx.txmutemonclk, &c);
             
    } while ((tx.txmutemonclk != 0) && (tx.txmutemonclk != 1));
    
    do
    {  
       printf("\nLaser enabled or disabled:\n   0 for normal operation \n   1 for laser disable\n");
       scanf("%d%c", &tx.lsenable, &c);
             
    } while ((tx.lsenable != 0) && (tx.lsenable != 1));
      
    //asegurarnos de poner el pin en 0.
    txp_set_ls_enable(0);
      
    do
    {  
       printf("\nSelects TxREFCLK frequency:\n   0 for TxDCK = fedata/4 \n   1 for TxDCK = fedata\n");
       scanf("%d%c", &tx.txrefsel, &c);
             
    } while ((tx.txrefsel != 0) && (tx.txrefsel != 1));
    
    //tx.prbsen = 1;
    //tx.prbspat0 = 1;
    //tx.prbspat1 = 1; 
    //tx.txdeskewen = 1;                  
    //tx.txdcksel = 0;
    //tx.txlinetimsel = 1; 
    //tx.txlloopenb =1;
    //tx.txreset = 1;                 
    //tx.txfifores = 1;               
    //tx.autotxfifores = 0;
    //tx.sctxreset = 1;               
    //tx.txmutemonclk = 1;
    //tx.lsenable  = 1;
    tx.txratesel0 = 1;              
    tx.txratesel1 = 1;              
    //tx.txrefsel = 0;          
        
  /* if( txp_set_tx_cmd_reg(tx) < 0) {
        printf("Error(initJDSU):txp_set_tx_cmd_reg\n");
        return -1;
    }*/
    
    do
    {  
       printf("\nMutes the RxDout[0:15]:\n   0 for Mute \n   1 for normal operation\n");
       scanf("%d%c", &rx.rxmute, &c);
             
    } while ((rx.rxmute != 0) && (rx.rxmute != 1));
    
    do
    {  
       printf("\nDiagnostic client loopback:\n   0 for diagnostic loopback \n   1 for normal operation\n");
       scanf("%d%c", &rx.rxdloopenb, &c);
             
    } while ((rx.rxdloopenb != 0) && (rx.rxdloopenb != 1));
    
    do
    {  
       printf("\nSelf-Clearing DeMux system reset:\n   0 for Reset \n   1 for normal operation\n");
       scanf("%d%c", &rx.scrxreset, &c);
             
    } while ((rx.scrxreset != 0) && (rx.scrxreset != 1));
    
    do
    {  
       printf("\nEnables PRBS checker:\n   0 for PRBS mode \n   1 for normal operation\n");
       scanf("%d%c", &rx.prbsen, &c);
             
    } while ((rx.prbsen != 0) && (rx.prbsen != 1));
        
     printf("\nSelects framed PRBS pattern length:\n Pat1  Pat0  Pattern \n  0     0      2^7 \n  0     1      2^15 \n  1     0      2^23 \n  1     1      2^31 \n");
    
    do
    {  
       printf("\Pat0: \n");
       scanf("%d%c", &rx.prbspat0, &c);
             
    } while ((rx.prbspat0 != 0) && (rx.prbspat0 != 1));
    
     do
    {  
       printf("\Pat1: \n");
       scanf("%d%c", &rx.prbspat1, &c);
             
    } while ((rx.prbspat1 != 0) && (rx.prbspat1 != 1));
    
     printf("\nSelects rate selection of system:\n");
     printf("RxRATESEL1    RxRATESEL0    MSA Nominal Bit-Rate[Gbps]   PLL Locking Bit-Rate Range[Gbps]\n");
     printf("    0             0                   FFU                          > 45.4\n");
     printf("    0             1                   44.6                      [44.8 - 45.4]\n");
     printf("    1             0                   43.1                      [43.0 - 44.8]\n");
     printf("    1             1                   39.8                      Unused for PLL\n");
    
    do
    {  
      printf("\nRxRATESEL0: \n");
       scanf("%d%c", &rx.rxratesel0, &c);
             
    } while ((rx.rxratesel0 != 0) && (rx.rxratesel0 != 1));
    
    do
    {  
      printf("\nRxRATESEL1: \n");
       scanf("%d%c", &rx.rxratesel1, &c);
             
    } while ((rx.rxratesel1 != 0) && (rx.rxratesel1 != 1));
    
    
    
     do
    {  
      printf("\nSelects RxREFCLK frequency:\n   0 for RxREFCLK = fedata/4 \n   1 for RxREFCLK = fedata\n");
       scanf("%d%c", &rx.rxrefsel, &c);
             
    } while ((rx.rxrefsel != 0) && (rx.rxrefsel != 1));
    
     do
    {  
      printf("\nLocks RxDCK to RxREFCLK:\n   0 Locks RxDCK to RxREFCLK \n   1 for normal operation\n");
       scanf("%d%c", &rx.rxlckref, &c);
             
    } while ((rx.rxlckref != 0) && (rx.rxlckref != 1));
    
    do
    {  
      printf("\nselects RxMONCLK frequency:\n   0 for RxMONCLK = fedata/4 \n   1 for RxMONCLK = fedata\n");
       scanf("%d%c", &rx.rxmonclksel, &c);
             
    } while ((rx.rxmonclksel != 0) && (rx.rxmonclksel != 1));
    
    do
    {  
      printf("\nDeMux system reset:\n   0 for Reset \n   1 for Normal operation\n");
       scanf("%d%c", &rx.rxreset, &c);
             
    } while ((rx.rxreset != 0) && (rx.rxreset != 1));
    
    do
    {  
      printf("\nmutes the RxMONCLK:\n   0 for RxMONCLK mute \n   1 for Normal operation\n");
       scanf("%d%c", &rx.rxmutemonclk, &c);
             
    } while ((rx.rxmutemonclk != 0) && (rx.rxmutemonclk != 1));
    
    //rx.rxmute = 1;
    //rx.rxdloopenb = 1;
    //rx.scrxreset = 1; 
    //rx.prbsen = 1;
    //rx.prbspat0 = 1;
    //rx.prbspat1 = 1;
    //rx.rxratesel0 = 1; 
    //rx.rxratesel1 = 0;
    //rx.rxrefsel = 0;
    //rx.rxlckref = 1;
    //rx.rxmonclksel = 0; 
    //rx.rxreset = 1;
    //rx.rxmutemonclk = 1;
        
   if(txp_set_rx_cmd_reg(rx)<0) {
        printf("Error(initJDSU):txp_set_rx_cmd_reg\n");
        return -1;
    }
    if( txp_set_tx_cmd_reg(tx) < 0) {
        printf("Error(initJDSU):txp_set_tx_cmd_reg\n");
        return -1;
    }
    return 0;
}

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}


