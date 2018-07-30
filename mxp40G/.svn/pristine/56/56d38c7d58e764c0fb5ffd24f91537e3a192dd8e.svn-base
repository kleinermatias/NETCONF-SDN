#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "show.h"




int main (int argc, char **argv){
  
    
    /*!Variable para saber si existen mas opciones o no, recibe los datos del parseo.*/
    int next;  
  
    /*!Flags para saber si ya se ingreso un comando o no.*/
    int flagP,flagO,flagL,flagA,flagI,flagC,flagS;
    
    /*!
    *  Flags que indican si ya han sido ingresado los parametros.
    *   1 habilitado para recibir comando, 0 existe el comando
	*/
    flagP=flagO=flagL=flagA=flagI=flagC=flagS=1;
  
    /*!Numero de puerto, ya sea para XFP ó T41*/
    int port;
 
    /*! Especificamos las opciones que soporta nuestro programa y la cantidad de argumentos que recibe.*/
    const char* const op_cortas = "p:olacsi^" ;

    /*! Una estructura de varios arrays describiendo los valores largos */
    const struct option op_largas[] =
    {	  
          { "port", 1, NULL,'p'},
          { "optics", 0, NULL,'o'},
          { "line", 0, NULL,'l'},
          { "info", 0, NULL,'i'},
          { "status", 0, NULL,'s'},
          { "cond", 0, NULL,'c'},
          { "all", 0, NULL,'a'},
          { "help", 0, NULL,'^'},
          {  NULL,  0, NULL, 0 }
        
    };

	       
    /*! Si se ejecuta sin parámetros ni opciones */
    if (argc == 1) {
        doc();
        exit(EXIT_SUCCESS);
    }
  
	

    while (1)
    {
      /*! Llamamos a la función getopt */
      next = getopt_long (argc, argv, op_cortas, op_largas, NULL);
	  
        if (next == -1)
            break; /*! No hay más opciones. Rompemos el bucle */

        switch (next)
        {		 
            case '^': /*! port */
                printf("show");
                return 0;
            break;
                     
            case 'p': /*! port */
                        
                    if(flagP==1) 
                    {
                        flagP = 2;
                        flagL = 0;
                        flagA = 0;
                        flagI = 0;
                        flagC = 0;
                        
                        if(flagS==1)
                            flagS=0;
                            
                        port=charToInt(optarg);
                                               
                        if(port == -1) {                                
                            doc();
                        }
                            
                    }
                    else 
                    {
                        doc();
                    }
                        
                break;
                    
            case 'o': /* optics */
                    
                    if(flagO == 1 && flagP==2) {
                        
                        flagA = 0;
                        flagO = 2;
                        flagL = 0;
                        flagS = 0;
                        
                    }
                    else
                    {
                        doc();
                    }
                
                break;
                
            case 'l': /* line */
                    
                    if(flagL == 1) {
                        
                        flagL = 2;
                        flagP = 0;
                        flagA = 0;
                        
                        if(flagS==1)
                           flagS=0;
                    }
                    else
                    {
                        doc();
                    }
                
                break;
                
            case 'a': /* all */
                    
                    if(flagA == 1) {
                        
                        flagL = 0;
                        flagP = 0;  
                        flagA = 2;
                    }
                    else
                    {
                        doc();
                    }
                
                break;
            case 's': /*! status */
                    
                    
                    if(flagS==1) 
                    {
                            
                        flagS = 2;
                        flagA = 0;
                        flagI = 0;
                        flagC = 0;
                        flagO = 0;
                       
                            
                    }
                    else 
                    {
                        doc();
                    }
                    
                break;
                
            case 'i': /*! info */
                    if(flagI==1) 
                    {
                            
                       flagI = 2;
                       flagA = 0;
                       flagS = 0;
                       flagC = 0;
                       flagO = 0;
                       flagP = 0;
                       flagL = 0;
                            
                    }
                    else 
                    {
                        doc();
                    }
                break;
                
            case 'c': /*! phys */
                    if(flagC==1) 
                    {
                            
                       flagC = 2;
                       flagA = 0;
                       flagS = 0;
                       flagI = 0;
                       flagO = 0;
                       flagP = 0;
                       flagL = 0;
                            
                    }
                    else 
                    {
                        doc();
                    }
                break;
                
            case '?': /* opción no valida */
                        doc	(); 
                break;
            
            case -1: /* No hay más opciones */
                        doc();
                break;

            default: /* Algo más? No esperado. Abortamos */
                        doc();
                        abort();
        }
    }
	
    
    if(flagP == 2) {
       
       if(flagS==0) {
            initialize();
            printf("\n\n");
            show_otn(port);
            printf("\n\n");
            show_eth(port);
            printf("\n\n");
        
            if (flagO == 2) {
                show_optics_parameters(port);
                printf("\n\n");
            }
        }
        else
        {
           showStatus(0,port);
        }
    
    }
    
    if(flagL == 2) {
        
        if(flagS==0){
        printf("\n\n");
        showJDSU();
        showEdfa();
    }
    else
    {
         showStatus(1,0);
    }
    
    }
    
    if(flagA == 2) {
        initialize();
        printf("\n\n");
        show_otn(port);
        printf("\n\n");
        show_eth(port);
        printf("\n\n");
        show_optics_parameters(port);
        printf("\n\n");
        showJDSU();
    }
    
    if(flagI==2) {
       initialize();
       showInfo();
    }
     
    if(flagC==2) {
        showConditions();
    }
	return 0;
}

void doc ()
{
  /*  printf("Use: show  [ argumentos ...]\n");
    printf( "-p  --port   Select port 0-1-2-3\n"
            "-o  --optics Show optics parameters"
            "-l --line show line information"
            "--all   Show line, port and optics parameters\n");*/
    //printf("show: missing operand after `show'\n show: Try `help show' for more information.\n");
    printf("show: updated version of command show.\n");
            
	exit(EXIT_SUCCESS);
}

int charToInt(char *opt)
{
    
	if(strlen(opt)>1)
		
        return -1;
	
    else {
			if(strcmp(opt,"0")==0) return 0;
			if(strcmp(opt,"1")==0) return 1;
			if(strcmp(opt,"2")==0) return 2;
			if(strcmp(opt,"3")==0) return 3;
        }
	return -1;
}

void show_optics_parameters(int port)
{
	
	printf("Optics Status: \n\n"); 
    printf("	Encoding mechanism: ");
    
    int value;
    double value_real;
    
    xfp_get_optical_compatibility(port,&value);
        
    switch(value)
    {
		
		case 8:
			printf("RZ \n");
			break;
		case 16:
			printf("NRZ \n");
			break;
		case 32:
			printf("SONET Scrambled \n");
			break;
		case 64:
			printf("8B10B \n");
			break;
		case 128:
			printf("64B/66B \n");
			break;
		
	}
    
    
    xfp_get_wavelength(port, &value);
    printf("	Wavelength: %d nm\n", value); 
    
    xfp_get_tx_power(port, &value);
    value_real = ((double) value) * .0001;
    value_real = 10.0 * log10(value_real);
    printf("	TX Power:  %.2f dBm\n", value_real);
    
    xfp_get_rx_power(port, &value);
    value_real = ((double) value) * .0001;
    value_real = 10.0 * log10(value_real);
    printf("	RX Power:  %.2f dBm\n", value_real);
    
    xfp_get_loss_of_signal_status(port, &value);
    printf("	RX LOS:  %d\n", value);  	
    
    int ber,lsb,msb;
    xfp_get_actual_ber(port,&ber);
    
    lsb = 15;
    lsb &= ber; 		// 	get LSB
    msb = ber>>4; 	// 	get MSB
   	printf("        BER: %fx10E-%f\n",((float)msb/16),(float)lsb);
	
	
}

void show_eth(int port)
{

printf("ETH status:\n");
    printf  ("\nLoss of Signal: %i",
        ten_pp10g_pcs_rx_status(
                                module_client,
                                port,
                                TEN_PP10G_PCS_RX_SYNCDETS)
        );
        
    printf  ("	High BER: %i",
        ten_pp10g_pcs_rx_status(
                                module_client,
                                port,
                                TEN_PP10G_PCS_RX_BERHIGHS)
        );
        
    printf  ("		Loss of Pattern Sync: %i\n",
        ten_pp10g_pcs_rx_status(
                                module_client,
                                port,
                                TEN_PP10G_PCS_RX_PATSYNCS)
        );

    printf  ("RS Remote Fault: %i",
        ten_pp10g_rs_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_RS_RX_STATUS_RFS)
        );
        
    printf  ("	RS Local Fault: %i\n",
        ten_pp10g_rs_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_RS_RX_STATUS_LFS)
        );

    printf  ("\nUnknown ORDS: %i",
        ten_pp10g_rs_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_RS_RX_STATUS_UNKNOWNORDS)
        );
        
    printf  ("	Remote ORDS: %i",
        ten_pp10g_rs_rx_get_status(
                                module_client,
                                port,
                                TEN_PP10G_RS_RX_STATUS_REMOTEORDS)
        );
        
    printf  ("		Local ORDS: %i\n",
        ten_pp10g_rs_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_RS_RX_STATUS_LOCALORDS)
        );


    printf  ("\nXGXS Local Fault: %i",
        ten_pp10g_xaui_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_XAUI_RX_LOCALFAULT)
        );
        
    printf  ("	XGXS Remote Fault: %i\n",
        ten_pp10g_xaui_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_XAUI_RX_REMOTEFAULT)
        );

    printf  ("\nRX XGXS CPAT LOCK: %i",
        ten_pp10g_xaui_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_XAUI_RX_XGXS_CPAT_LOCK)
        );
        
    printf  ("	RX XGXS ALIGN DET: %i\n",
        ten_pp10g_xaui_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_XAUI_RX_XGXS_ALIGN_DET)
        );

    printf  ("\nRX_SYNCDET3: %i",
        ten_pp10g_xaui_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_XAUI_RX_SYNCDET3)
        );
        
    printf  ("	RX_SYNCDET2: %i",
        ten_pp10g_xaui_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_XAUI_RX_SYNCDET2)
        );
        
    printf  ("		RX_SYNCDET1: %i",
        ten_pp10g_xaui_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_XAUI_RX_SYNCDET1)
        );
        
    printf  ("			RX_SYNCDET0: %i\n",
        ten_pp10g_xaui_rx_get_status(
                                    module_client,
                                    port,
                                    TEN_PP10G_XAUI_RX_SYNCDET0)
        );

    //Ethernet Counters.
    /*int i;
    for(i=0;i<143;i++)
    ten_mod_print_unit_stats (module_client,TEN_ID_PP10G,port,i);
    */
    
    printf("\nRX:\n");

    printf  ("	Octets: %llu",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_RX_OCTETS_STAT,
                        CS_RX)
        );
        
    printf  ("		Good (Valid) Octets: %llu",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_RX_GOOD_OCTETS_STAT,
                        CS_RX)
        );
        
    printf  ("			Frames: %llu\n",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_RX_FRAMES_STAT,
                        CS_RX)
        );
        
    printf  ("	Pause Frames: %llu",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_RX_PAUSE_FRAMES_STAT,
                        CS_RX)
        );
        
    printf  ("		Errored Frames: %llu",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_RX_ERR_FRAMES_STAT,
                        CS_RX)
        );
        
    printf  ("			Jabbers: %llu\n",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_RX_JABBER_FRAMES_STAT,
                        CS_RX)
        );
        
    printf  ("	Undersize Frames: %llu",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_RX_UNDERSIZE_FRAMES_STAT,
                        CS_RX)
        );


    printf  ("\nTX:\n");
    
    printf  ("	Octets: %llu",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_TX_OCTETS_STAT,
                        CS_TX)
        );
        
    printf  ("		Good (Valid) Octets: %llu",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_TX_GOOD_OCTETS_STAT,
                        CS_TX)
        );
        
    printf  ("			Frames: %llu\n",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_TX_FRAMES_STAT,
                        CS_TX)
        );
        
    printf  ("	Pause Frames: %llu",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_TX_PAUSE_FRAMES_STAT,
                        CS_TX)
        );
        
    printf  ("		Errored Frames: %llu",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_PP10G,
                        port,
                        TEN_PP10G_MAC_TX_ERR_FRAMES_STAT,
                        CS_TX)
        );


}

void show_otn(int port)
{
    printf("\nOTN Status:\n");

	printf("\nOTN: \n");
	
	print_defects   ("	LOS  =", 
                    ten_n10g_get_global_losf_status (
                                                    module_client,
                                                    port)
                    ); // ok
	
	printf  ("	LOF  = %hu",   
            ten_n10g_get_otu_framer_status (
                                            module_client,
                                            port,
                                            TEN_NX0G_OTNR_OFSTAT_SLOF)
            ); //ok 
	
	print_defects   ("	LOM  =",
                    ten_n10g_oohr_get_sm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_SM_STATUS_LOM)
                    ); // ok
                    
	print_defects   ("	BDI  =",
                    ten_n10g_oohr_get_sm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_SM_STATUS_DBDI)
                    ); // ok
	
	print_defects   ("\n	IAE  =",
                    ten_n10g_oohr_get_sm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_SM_STATUS_DIAE)
                    ); // ó DBDIAE
	
	print_defects   ("	BIP  =",
                    ten_n10g_oohr_get_sm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_SM_STATUS_BIPSDS)
                    ); // ok
	
	print_defects   ("	BEI  =",
                    ten_n10g_oohr_get_sm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_SM_STATUS_BEISDS)
                    ); //no especificado en SDUG
	
	printf  ("	TIM  = @\n"); //no lo encuentro, esta este parametro?

	printf  ("\nODU:\n");

	print_defects   ("	AIS  =",
                    ten_n10g_oohr_get_pm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_PM_STATUS_DAIS)
                    );  // ok
	
	print_defects   ("	BDI  =",
                    ten_n10g_oohr_get_pm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_PM_STATUS_DBDI)
                    );  // ok
	
	print_defects   ("	OCI  =",
                    ten_n10g_oohr_get_pm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_PM_STATUS_DOCI)
                    );  // ok 
	
	print_defects   ("	LCK  =",
                    ten_n10g_oohr_get_pm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_PM_STATUS_DLCK)
                    );   // ok
	
	print_defects   ("	\n	BIP  =",
                    ten_n10g_oohr_get_pm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_PM_STATUS_BIPSDS)
                    );//no especificado en SDUG
	
	print_defects   ("	BEI  =",
                    ten_n10g_oohr_get_pm_status(
                                                module_client,
                                                port,
                                                TEN_NX0G_OOHR_PM_STATUS_BEISDS)
                    ); // no especificado en SDUG
	
	printf("	PTIM = @"); //no lo encuentro, esta este parametro?
	
	printf("	TIM  = @\n"); //no lo encuentro, esta este parametro?
	//TIM = type id mismatch
	
	/*printf("FEC Mode:\n");

    printf  ("\nByte Errors = %llu\n",
        ten_mod_read_stat(
                          module_client,
                          TEN_ID_GFEC_10G,
                          port,
                          TEN_GFEC10G_FRX_RBYTER0_STAT,
                          0)
        );

    printf  ("One-Bit Errors = %llu\n",
        ten_mod_read_stat(
                         module_client,
                        TEN_ID_GFEC_10G,
                        port,
                        TEN_GFEC10G_FRX_ROBTER0_STAT,
                        0)
        );

    printf  ("Zero-Bit Errors = %llu\n",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_GFEC_10G,
                        port,
                        TEN_GFEC10G_FRX_RZBTER0_STAT,
                        0)
        );

    printf  ("Uncorrectable Block Errors = %llu\n",
        ten_mod_read_stat(
                        module_client,
                        TEN_ID_GFEC_10G,
                        port,
                        TEN_GFEC10G_FRX_RBYTER0_STAT,
                        0)
        );        */  

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

void print_status(const char* msg, cs_status status)
{
    if (status == CS_OK) {
        
        printf("%s : OK\n", msg);
    
    } 
    else {
	 
        printf("%s : ERROR\n", msg);
    }
    
}

void print_defects(const char* msg, cs_status status)
{
  
  if (status == CS_OK) {
      
	 printf("%s 0", msg);
  
    } 
    else {
	 
     printf("%s 1", msg);
  }

}

void show_fec(int port)
{
    printf("FEC Mode:\n");
    printf("	EC(current second) = ");
    printf("		EC   =");
        
    printf("	pre-FEC BER < 2.35E-11");
    printf("		Q > 6.66");
    printf("			Q Margin > 7.52 dBQ\n"); 

}

void showJDSU()
{
   itu_channel_t itu;
   txp_read_laser_itu_channel(&itu);
     
   printf("\nLaser ITU Channel: \n");
    
   if(itu.band==0x43)
       printf("     Band: C-Band\n");
   else
       printf("     Band: L-Band\n");
        
   printf("     Units: %hu\n",itu.channel);           
   
   /*estimation_t estimation;
   txp_jdsu_read_all_estimation(&estimation);
    
   printf("\nDGD:\n");
   printf("     Current: %hu",estimation.dgd_cur); 
   printf("            Minimum: %hu",estimation.dgd_min); 
   printf("                Maximum: %hu\n",estimation.dgd_max); 
   
   printf("\nCD:\n");
   printf("     Current: %hu",estimation.cd_cur); 
   printf("            Minimum: %hu",estimation.cd_min);
   printf("                Maximum: %hu\n",estimation.cd_max); 
   
   printf("\nOSNR:\n");
   printf("     Current: %hu",estimation.osnr_cur); 
   printf("            Minimum: %hu",estimation.osnr_min); 
   printf("                Maximum: %hu\n",estimation.osnr_max); 
   */
   int aux;
   txp_read_laser_bias_current_monitor(&aux);
   printf("\nLaser Bias Current: %d µA\n",aux);   
   
   //int laser_output;
   txp_read_laser_output_power_monitor(&aux);
   printf("\nLaser Output Power: %d µW\n",aux);
   
   //int laser_temp;
   txp_read_laser_temperature_monitor(&aux);
   printf("\nLaser Temperature: %d m°C\n",aux);
   
   //int laser_temp;
   txp_read_laser_temperature_monitor(&aux);
   printf("\nReceiver Signal Monitor Average Optical Power: %d nW\n",aux);
      
   //int transponder;
   txp_read_transponder_temperature_monitor(&aux);
   printf("\nTransponder Temperature: %d m°C\n",aux);
      
   txp_read_modulator_bias_monitor(&aux);
   printf("\nModulator Bias: %d mV\n",aux);
      
   //printf("\nLaser Output Power:  0.01dBm\n");
   
   //printf("\nReceiver Signal Monitor Average Optical Power: 0.01dBm\n");
   
   //printf("\nLaser Absolute Temperature: m°C\n");
   
   printf("\nDQPSK Encoder: DQPSK\n");
   
   printf("\nData mapping: ITU-T G.709\n");
    
}

void showEdfa() {

    int value;
    float f;
    edfa_get_echo(&value);
    edfa_get_input_power(&f);
    edfa_get_output_power(&f);
    edfa_get_signal_gain(&f);
    edfa_get_signal_power(&f);
    edfa_get_los_mode(&value);
    edfa_get_amplifier_status(&value);
    
}

void showConditions() {

   int status;
   
   //---------------------FAN
   fan_get_alert(FAN1_ALERT,&status);
   fan_clear(FAN1_CLEAR);
   if(status)
    printf("FAN 1 Status: OK\n");
   else
    printf("FAN 1 Status: NO OK\n");

   fan_get_alert(FAN2_ALERT,&status);
   fan_clear(FAN2_CLEAR);
   if(status)
    printf("FAN 2 Status: OK\n");
   else
    printf("FAN 2 Status: NO OK\n");
    
   fan_get_alert(FAN3_ALERT,&status);
   fan_clear(FAN3_CLEAR);
   if(status)
    printf("FAN 3 Status: OK\n");
   else
    printf("FAN 3 Status: NO OK\n");
    
   fan_get_alert(FAN4_ALERT,&status);
   fan_clear(FAN4_CLEAR);
   if(status)
    printf("FAN 4 Status: OK\n");
   else
    printf("FAN 4 Status: NO OK\n");
    
    //-------------------TMP
    float tmp;
    
    tmp_get_ext_temp(TMP_REMOTE_1_REG,&tmp);
    printf("FPGA Temp: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_2_REG,&tmp);
    printf("JDSU Temp: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_3_REG,&tmp);
    printf("EDFA Temp: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_4_REG,&tmp);
    printf("T41 Temp: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_5_REG,&tmp);
    printf("T41 internal Temp 1: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_6_REG,&tmp);
    printf("T41 internal Temp 2: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_REMOTE_7_REG,&tmp);
    printf("T41 internal Temp 3: %.2f C\n",tmp);
    tmp_get_ext_temp(TMP_LOCAL_REG,&tmp);
    
    
    //-------------------HMD
    
    hmd_get_temp_comp_humidity(&status);
    printf("humidity: %d\n", &status);
    
}

void showStatus(int side, int port) {
    
    float temp;
    int status;
    double value_real;
    
    //side 0 = ports ------ 1 = line
    if (side == 0) {
        
        printf("Port %d:\n", port);
        
        switch(port) {
            case 0:
                port = XFP_MOD_0;
                break;
            case 1:
                port = XFP_MOD_1;
                break;
            case 2:
                port = XFP_MOD_2;
                break;
            case 3:
                port = XFP_MOD_3;
                break;
            default:
                break;
        }
        
        xfp_get_laser_status(port, &status);
        if (status == 0)
            printf("    Laser Status: UP\n");
        else
            printf("    Laser Status: DOWN\n");
           
        xfp_get_temperature(port, &temp);
        printf("    Temperature: %.2f C\n", temp);

        
        printf("    Optical laser power: \n");
            
        xfp_get_tx_power(port, &status);
        value_real = ((double) status) * .0001;
        value_real = 10.0 * log10(value_real);
        printf("        TX: %.2f dBm\n", value_real);
            
        xfp_get_rx_power(port, &status);
        value_real = ((double) status) * .0001;
	value_real = 10.0 * log10(value_real);
        printf("        RX: %.2f dBm ", value_real);
	if (value_real <= -40.0) printf("(no signal)");
	printf("\n");
                
    } else {
    
        printf("Line: \n");
        
        tx_cmd_t tx;
        int ls;
        
        txp_read_tx_cmd_reg(&tx);
        txp_get_ls_enable(&ls);
        
         
        if ((ls==0) && (tx.lsenable==0))
             printf("    Laser Status: UP\n");
        else
             printf("    Laser Status: DOWN\n");
        
        status = -1;
        
        if(txp_read_laser_temperature_monitor(&status)==0)
            printf("    Laser Temperature %i\n", status);
        
       
        
        printf("    Optical laser power: \n");
        
        status = -1;
        if(txp_read_laser_output_power_monitor_db(&status)==0)
            printf("        TX: %i\n", status); //0.01dBm
        
        status = -1;
        if(txp_read_receiver_signal_monitor_average_optical_power_db(&status)==0)
            printf("        RX: %i\n", status);//0.01dBm
        
        
    }
}

void showInfo() {
    
    int id;
    char info;
    
    printf("\nJDSU:\n");
    
    printf("\tProduct Identifier Code:");
    //txp_jdsu_get_product_identifier_code();
    printf("\n");
    
    printf("\tSerial Numbers:");
    //txp_jdsu_get_serial_number();
    printf("\n");
    
    printf("\tPart Number:");
    //txp_jdsu_get_part_number();
    printf("\n");
    
    printf("\tFirmware Revision:");
    //txp_jdsu_get_revision_number(0);
    printf("\n");
    
    printf("\tBoot Revision:");
    //txp_jdsu_get_revision_number(1);
    printf("\n");
    
    printf("\tFPGA Revision:");
    //txp_jdsu_get_revision_number(2);
    printf("\n\n");
    
    printf("XFP:\n");
    int i,wl;
    for(i=0;i<4;i++) {
        
        id=-1;
        wl=-1;
       
  

        printf("    XFP %d:\n",i);
//	This check changes the output in case an XFP interface is unavailable.  
        if( xfp_get_identifier(i,&id)>=0)
        {                
            printf("\tXFP Identifier: %d",id);
            printf("\n");
            
            xfp_get_wavelength(i,&wl);
            printf("\tWavelength: %d nm",wl);
            printf("\n");
            
            
            printf("\tVendor Name: ");
            xfp_get_vendor_name(i);
            printf("\n");
            
            printf("\tVendor OUI: ");
            xfp_get_vendor_oui(i);
            printf("\n");
            
            printf("\tVendor Part Number: ");
            xfp_get_part_number(i);
            printf("\n");
            
            printf("\tVendor Revision level: ");
            xfp_get_revision_level(i);
            printf("\n");
            
            printf("\tVendor's manufacturing date code: ");
            xfp_get_date_code(i);
            printf("\n");
        
            printf("\tVendor Serial Number: ");
            xfp_get_serial_number(i);
            printf("\n");
        } else {
            printf("\tDEVICE UNAVAILABLE\n");
	}
        
    }
   

    printf("\nEDFA:\n");
//    printf("    Configuration: Booster\n");
//    printf("    Firmware Vers: 763.0\n");
//    printf("    Serial Number: 23219\n");
//    printf("    Hardware Vers: 01A\n");
//    printf("    Firmware Date: Nov 26 2009\n");
//    printf("    Boot Version: 6.4\n");
//    printf("    Catalog Num.: 50-11-0118-01R\n");
//    printf("    Product Date: NOV 18 2009\n");
    edfa_get_information(NULL);
    
    
    int idq;
   
    
    printf("\nQSFP:\n");
    if(qsfp_get_id(&idq) >= 0) 
    {
        printf("\tIdentifier: %d",id);
        printf("\n");
         
        printf("\tVendor Name: ");
        qsfp_get_vendor_name();
        printf("\n");
         
        printf("\tVendor OUI: ");
        qsfp_get_vendor_oui();
        printf("\n");
         
        printf("\tVendor Part Number: ");
        qsfp_get_vendor_pn();
        printf("\n");
         
        printf("\tVendor revision: ");
        qsfp_get_vendor_rev();
        printf("\n");
        
        printf("\tVendor Serial Number: ");
        qsfp_get_vendor_sn();
        printf("\n");
         
        printf("\tVendor's manufacturing date code: ");
        qsfp_get_vendor_date_code();
        printf("\n");
    } else {
        printf("\tDEVICE UNAVAILABLE\n");
    }

    
    printf("\nT41:\n");
    printf("%s\n",ten_mpif_print_chip_id(dev_id));
    
}

