#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugt41.h"

void doc();


int main (int argc, char **argv){
  
    
    /*!Variable para saber si existen mas opciones o no, recibe los datos del parseo.*/
    int next,operacion;
  
    /*!Flags para saber si ya se ingreso un comando o no.*/
    int flagS,flagE,flagO,flagV;
    
    /*!
    *  Flags que indican si ya han sido ingresado los parametros.
    *   1 habilitado para recibir comando, 0 existe el comando
	*/
    flagS=flagE=flagO=flagV=0;
  
    /*!Numero de puerto, ya sea para XFP ó T41*/
    int port;
    int start_address, end_address;
    int valor;
    /*! Especificamos las opciones que soporta nuestro programa y la cantidad de argumentos que recibe.*/
    const char* const op_cortas = "s:e:o:v:h" ;

    /*! Una estructura de varios arrays describiendo los valores largos */
    const struct option op_largas[] =
    {	  
          { "start", 1, NULL,'s'},
          { "end", 1, NULL,'e'},
          { "operation", 1, NULL,'o'},
          { "value", 1, NULL,'v'},
          { "help", 0, NULL,'h'},
          {  NULL,  0, NULL, 0 }
        
    };

	       
    /*! Si se ejecuta sin parámetros ni opciones */
    if (argc == 1) {
        doc();
       
    }
  
	

    while (1)
    {
      /*! Llamamos a la función getopt */
      next = getopt_long (argc, argv, op_cortas, op_largas, NULL);
	  
        if (next == -1)
            break; /*! No hay más opciones. Rompemos el bucle */

        switch (next)
        {		 
             case 'v':
                    
                    if((flagO==1) || (operacion==1) || (flagV==2))
                    {
                        doc();
                    }
                     
                    flagV==2;
                    valor = atoi(optarg);
             break;
             
            case 'o':
            
                   if(flagO==2)
                   {
                        doc();
                   }
                   
                   flagO = 2;
                   
                   if(strncmp(optarg,"read",4)==0){
                       operacion=1;
                   }
                    
                   if(strncmp(optarg,"write",5)==0)
                   { 
                       operacion=2;
                   }
                      
                    
            break;
                     
            case 's':
                    if(flagS==2)
                    {
                        doc();
                    }
                    
                    flagS = 2;
                    start_address = atoi(optarg);
            break;
            
            case 'e':
                        
                    if((flagS==1)||(flagE==2))
                    {
                      doc();
                    }
                    
                    flagE=2;
                    end_address = atoi(optarg);
            break;
            
            case 'h': /* opción no valida */
                        doc(); 
                break;
                
            case '?': /* opción no valida */
                        doc(); 
                break;
                
            
            
            case -1: /* No hay más opciones */
                        doc();
                break;

            default: /* Algo más? No esperado. Abortamos */
                     doc();
        }
    }
    initialize();
	printf("\n\n");
    if(operacion==1)
    {
        if((flagS ==2) && (flagE ==2)){
            printf("    Read Range: %d -  %d\n", start_address,end_address);
            ten_reg_dump_range(dev_id,start_address,end_address);
        }
        else
        {
            printf("    Read : %d\n", start_address);
            ten_reg_dump_range(dev_id,start_address,start_address);
        }
    }
    
    if(operacion==2)
    {
        //printf("    Escribir - Registro %d - Valor: %d\n", start_address,valor);
        if(ten_reg_write(dev_id,start_address,valor)==CS_OK) {
            printf("    La escritura se realizo correctamente\n");
            ten_reg_dump_range(dev_id,start_address,start_address);
        }
        else
        {
           printf("     se produjo un error al escribir el registro\n");
        }
    }
	return 0;
}



int initialize()
{
	
	//Cargamos el Driver.	
	if (ten_drvr_load() != CS_OK)
	{
		printf("Error al cargar el driver\n");		
		return -1;
	}
	
	ten_drvr_ctl_stats_hex_format(1);

	//establecemos los valores iniciales:
	Chips.mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft; 
	Chips.mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;
	dev_id = 0;	
	module_line = dev_id <<8;
  	module_client = module_line | 1;
		
		//Registramos el Device.:	
	if(ten_dev_register(dev_id,(cs_uint32)&Chips) != CS_OK)
		{
			printf("CS604x device registration failed; provisioning aborted\n");
            return -1;
		}
	
	/*  Initialize the device driver */
		if (ten_dev_main_init(dev_id) != CS_OK) 
			{
			    printf("CS604x device initialization failed; provisioning aborted\n");
				/*la funcion tira un error inesperado*/
			    return -1;
       			}
       ten_mpif_get_chip_jtag_id(dev_id);
       	
       	/* * * *
	 * Scratch pad register = registro para hacer pruebas de escritura 
	 * y lectura como un bloc para apuntes 
	 *	* * */	
	ten_mpif_scratch_pad2(dev_id, 0xAA55);
	ten_mpif_read_scratch_pad2(dev_id);
	
	module_client = ten_mod_main_init( dev_id, TEN_MODULE_A );
	module_line = ten_mod_main_init( dev_id, TEN_MODULE_B );
				
	ten_hl_config_global( dev_id, 0, 1, 0, 1, 1 );
	ten_hl_ohpp_and_shadow_ram_init(dev_id);
		
	/*
	Config Top level	
	*/
	ten_hl_config_global(
						dev_id, 					//Device ID	
						TEN_GLOBAL_MODE_S_40G,		//Line Mode
						TEN_GLOBAL_MODE_QUAD_10G,	//Client Mode
						0,							//mbclksel
						1,							//Multi-Rate Mode not SFI41 Line
						1							//Multi-Rate Mode not SFI41 Client
						);
	
	ten_hsif_provision_datapath(module_line,			// module_id 
                                TEN_INSTANCE_ALL, 			// instance: Specified as 0..3 or TEN_INSTANCE_ALL 
								1, 						// tx_xfiselect: 1 = XFI or 0 = protocol selected by rx_mrprotocol (default)
								1, 						// rx_xfiselect: 1 = XFI or 0 = protocol selected by rx_mrprotocol (default)
								0, 						// tx_pswtchen: 1 = Disable or 0 = Enabled:  Data is driven from remote interface 
								0, 						// tx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled
								0,							// rx_pswtchen: 1 = Disable or 0 = Enabled:  Data is driven from remote interface
								0);
																	// rx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled
		
    ten_hsif_provision_datapath(module_client, 			// module_id
											TEN_INSTANCE_ALL,		// instance: Specified as 0..3 or TEN_INSTANCE_ALL
											1, 						// tx_xfiselect: 1 = XFI or 0 = protocol selected by rx_mrprotocol (default)
											1, 						// rx_xfiselect: 1 = XFI or 0 = protocol selected by rx_mrprotocol (default)
											0, 						// tx_pswtchen: 0 = Disable or 1 = Enabled:  Data is driven from remote interface 
											0, 						// tx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled
											0,							// rx_pswtchen: 0 = Disable or 1 = Enabled:  Data is driven from remote interface
											0);						// rx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled

	
		//no hace control de errores, siempre devuelve ok
    ten_hl_hsif_powerdown_mr(module_client,			// module_id
                            TEN_SLICE_ALL,		// slice
                            CS_ENABLE);			// ctl
	

    ten_hl_n40g_config(module_line,						// module_id: module_id_a, module_id_b
                        TEN_N40G_RX_OTU3_ODTU23,			// mode_rx: Table 9, row 2 -> TEN_N40G_RX_OTU3_ODTU23 = 7
                        TEN_N40G_TX_ODTU2_OTU3);			// mode_tx: Table 10, row 2 -> TEN_N40G_TX_ODTU2_OTU3 = 11
							
							
							
	


    ten_hl_config_otu2v_otu3v_t41(
                                 module_line,			//Line Module Id
                                 TEN_SLICE1,				//Line Slice
                                 TEN_SLICE1,				//Client Slice
                                 TEN_INITIAL_CONFIG,		//Dynamic Reprovision Type
                                 TEN_TRAFFIC_TYPE_OTU3,		//TEN_TRAFFIC_TYPE_OTU3E4,	//Traffic Type Line
                                 TEN_FEC_MODE_ZEROFEC,		//FEC Type Line
                                 TEN_TRAFFIC_TYPE_OTU2,		//Traffic Type Client
                                 TEN_FEC_MODE_NOFEC,		//FEC Type Client
                                 TEN_OTU_TERM_SECTION,		//Term OTU
                                 CS_DISABLE,				//TCM Line		
                                 CS_DISABLE,				//TCM Client	
                                 CS_ENABLE,					//MLD Line   	
                                 TEN_MAP_AMP,			//Mapping Method ODTU
                                 TEN_MAP_AMP,				//Mapping Method OXUV
                                 8,							//Timeslots
                                 1							//GMP Timeslot Mask
                                 );


    ten_hl_config_10ge_otu3v_t41(
                                module_line, 			//Line Module Id
                                TEN_SLICE0,					//Line Slice
                                TEN_SLICE0,					//Client Slice
                                TEN_INITIAL_CONFIG,			//Dynamic Reprovision Type
                                TEN_TRAFFIC_TYPE_OTU3,		//Traffic Type Line
                                TEN_FEC_MODE_NOFEC,			//FEC Type Line
                                TEN_TRAFFIC_TYPE_10GE_7_1,	//Traffic Type Client
                                400,						//System Clock
                                CS_DISABLE,					//TCM Line
                                CS_ENABLE,					//MLD Line
                                TEN_MAP_GMP_HO,				//Mapping Method ODTU
                                TEN_MAP_BMP,				//Mapping Method OXUV
                                8,							//Timeslots
                                0,							//GMP Frame Format
                                2							//Flow Control Mode
                                );
                            
        return 0;

}


void doc() {

printf("use Read Range: --start [start_address] --end [end_address] --operation [read] \n\n");
printf("use Read Register: --start [start_address]  --operation [read] \n\n");
printf("use Write Register: --start [start_address]  --operation [write] --value [register_value]\n\n");
exit(EXIT_FAILURE);
}

