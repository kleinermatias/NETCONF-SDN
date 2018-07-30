#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "config.h"
#define _XOPEN_SOURCE 500

    itu_channel_t itu;  
    int mode = 0;
    int side;
    int port;
    float rxnm,txnm;
    unsigned short channelRx, channelTx;
    hashtable_t *hashtableTX;
    hashtable_t *hashtableRX;
    
int main (int argc, char **argv)
{
    
    
    int next_opt;
    int ret_code;
    char eth[4]="eth\0";
    char otu[4]="otn\0";
    //const char* const short_opt = "p:c:b:m:s:r:t:l^" ;   
    const char* const short_opt = "p:m:s:r:t:l^" ;
    
    const struct option long_opt[] =
    {
        { "port", 1, NULL,'p'},
        { "line", 0, NULL,'l'},
        { "mode", 1, NULL,'m'},
        //{ "channel", 1, NULL,'c'},
       // { "band", 1, NULL,'b'},
        { "status", 1, NULL,'s'},
        { "channeltx", 1, NULL,'t'},
        { "channelrx", 1, NULL,'r'},
        { "help", 0, NULL,'^'},
        {  NULL,  0, NULL, 0 }

    };

    int flagP, flagL, flagM, flagC, flagS, flagRX, flagTX;
    
    flagP=flagL=flagM=flagC=flagS=flagRX=flagTX=1;
    
    /* Si se ejecuta sin parámetros ni opciones */
    if (argc == 1) 
    {
        doc();
    }

    hashtableTX = ht_create( 65536 );
    hashtableRX = ht_create( 65536 );
    crear_tabla();
    
    while (1) 
    {
        
        next_opt = getopt_long (argc, argv, short_opt, long_opt, NULL);
        if (next_opt == -1) break;

        switch (next_opt)
        {
        case '^': /*! port */
                printf("config");
                return 0;
            break;
   
            case 'p': //port
                    if (flagP==1)
                    {
                        flagP=2;
                        flagL=0;
                        flagC=0;
                       
                        port=charToInt(optarg);
                       
                        if(port == -1) 
                        {                                
                            doc();
                        }
                    }
                    else
                    {
                        doc();
                    }
                
            break;
             
            case 'l': //line
                    if (flagL==1)
                    {
                        
                        flagL=2;
                        flagP=0; //Si se activa la bandera Line no permitir configurar ls puertos
                        flagM=0; //por ende, tampoco el modo en configurar los puertos.
                                   
                    }
                    else
                    {
                        doc();
                    }
                                   
            break;
                
           /* case 'c': //chanel
                   
                    if ((flagC == 1) && (flagL==2))
                    {
                        flagC=2;
                        flagP=0;
                        flagM=0;
                        flagS = 0;
                      
                        ret_code = getChannel(optarg);
                        if (ret_code == -2 ) {
                            doc();
                        } else if (ret_code == -1) {
                            exit(EXIT_FAILURE);
                        }
                    }
                    else
                    {
                        doc();
                    }
                    
            break;*/
                
            /*case 'b': //band
                    if (flagL == 2 && flagB == 1)
                    {
                        flagB=2;
                        flagP=0;
                        flagM=0;
                        flagS = 0;
                        
                        if(getBand(optarg) < 0) {
                            doc();
                        }
                    }
                    else
                    {
                        doc();
                    }
            
            break;*/
            
            case 'm': //mode
                    if ((flagM == 1) && (flagP==2) ) //si no se ingreso ya el comando -m y se ingreso el comando -p
                    {
                        flagM = 2;
                        flagS = 0;
                        
                        if (strlen(optarg) < 4) 
                        {
                            if (strncmp("eth", optarg, 3) == 0) 
                            {
                                mode = 1;
                            } 
                            else if (strncmp("otu", optarg, 3) == 0) 
                            {
                                mode = 2;
                            } 
                            else if(strncmp("txp", optarg, 3) == 0)
                            {
                                mode = 3;
                            }
                            else
                            {
                                doc();
                            }
                        } 
                        else 
                        {
                            if (strncmp(eth, optarg, strlen(optarg)) == 0) 
                            {
                                mode = 1;
                                                               
                            } 
                            else if (strncmp(otu, optarg, strlen(optarg)) == 0) 
                            {
                                mode = 2;
                            }
                            else if(strncmp("txp", optarg, 3) == 0)
                            {
                                mode = 3;
                            }
                            else 
                            {   
                                doc();
                            }
                        }
                    }
            
            break;
            
            case 's':
                if(flagS==1) {
                   
                  
                   flagC = 0;
                   flagM = 0;
                   flagS = 2;
                   
                   if ((strncmp("down", optarg, 4) == 0) && strlen(optarg)==4) 
                    {
                        mode = 0;
                    } 
                    else if ((strncmp("up", optarg, 2) == 0) && strlen(optarg)==2) 
                    {
                     mode = 1;
                     } 
                     else 
                    {
                     doc();
                    }
                }
                else
                {
                    doc();
                }
            
            break;
            
            case 'r':
            
                    if((flagL==1)||(flagRX==2))
                        doc();
                    
                    rxnm = (floorf(atof(optarg) * 100)) / 100; 
                    
                    if((rxnm<1568.77)||(rxnm>1610.49))
                    {
                       printf("Not a valid RX wavelength. Valid Range: [1568.77nm - 1610.49nm]\n");
                       break;
                    }
                     flagRX = 2;
                     
                     if (ht_get( hashtableRX, optarg) != NULL) {
                    
                        float hz = atof(ht_get( hashtableRX, optarg));
                        float cn = ((205.00000-hz)/0.05)+1;
                        int d23 = (int)cn;
                        int d4 = (int)(((cn-d23))*100);
                        float d4f = (float)(((cn-d23))*100);
                        float comp = d4+0.5;  
                        
                        d4 = (d4*256)/100;       
                        if(comp>=d4f){
                            d4++;
                        }
                        channelRx = d4;
                        channelRx = channelRx | (d23<<8);          
                        
                        printf("RX: %.2f nm\n",rxnm);
                        printf("RX: %.2f Thz\n",hz);
                        //printf("Channel number: %.2f \n",cn);
                        //printf("Registro: 0x%x\n\n\n\n\n",channelRx);
                    }
                    else
                    {   
                        float hz = (299790)/rxnm;
                        float cn = ((205.00000-hz)/0.05)+1;
                        int d23 = (int)cn;
                        int d4 = (int)(((cn-d23))*100);
                        float d4f = (float)(((cn-d23))*100);
                        float comp = d4+0.5;  
                        
                        d4 = (d4*256)/100;       
                        if(comp>=d4f){
                            d4++;
                        }
                        channelRx = d4;
                        channelRx = channelRx | (d23<<8);          
                        
                        printf("RX: %.2f nm\n",rxnm);
                        printf("RX: %.2f Thz\n",hz);
                        printf("Warning: RX Wavelength entered is not in the grid. \n");
                        //printf("Channel number: %.2f \n",cn);
                        //printf("Registro: 0x%x\n\n\n\n\n",channelRx);
                    
                    }
            break;
            
            case 't':
            
                    if((flagL==1)||(flagTX==2))
                        doc(); 
                        
                    txnm = (floorf(atof(optarg) * 100)) / 100; 
                    
                    if((txnm<1528.77)||(txnm>1568.36))
                    {
                       printf("Not a valid TX wavelength. Valid Range: [1528.77nm - 1568.36nm]\n");
                       doc();
                    }
                    
                    flagTX = 2;
                    
                    if (ht_get( hashtableTX, optarg) != NULL) {
                    
                        float hz = atof(ht_get( hashtableTX, optarg));
                        float cn = ((196.1-hz)/0.05)+1;
                        int d23 = (int)cn;
                        int d4 = (int)(((cn-d23))*100);
                        float d4f = (float)(((cn-d23))*100);
                        float comp;
                        
                        d4 = (d4*16)/100;      
                        d4f = (d4f*16)/100;
                        comp = ((float)d4)+0.5;         
                                                
                        if(comp <= d4f){
                            d4++;
                        }
                        channelTx = d4;
                        channelTx = channelTx | (d23<<4);          
                        
                        printf("TX: %.2f nm\n",txnm);
                        printf("TX: %.2f Thz\n",hz);
                        printf("Channel number: %.2f \n",cn);
                    }
                    
                    else
                    
                    {   
                        
                        float hz = (299790)/txnm;
                        float cn = ((196.1-hz)/0.05)+1;
                        int d23 = (int)cn;
                        int d4 = (int)(((cn-d23))*100);
                        float d4f = (float)(((cn-d23))*100);
                        float comp;
                        
                        d4 = (d4*16)/100;      
                        d4f = (d4f*16)/100;
                        comp = ((float)d4)+0.5;         
                                                
                        if(comp <= d4f){
                            d4++;
                        }
                        channelTx = d4;
                        channelTx = channelTx | (d23<<4);          
                        
                        printf("TX: %.2f nm\n",txnm);
                        printf("TX: %.2f Thz\n",hz);
                        printf("Channel number: %.2f \n",cn);
                        printf("Warning: TX Wavelength entered is not in the grid. \n");
                        
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
                
            default:    // Invalid outcome
                abort();
            break;
        }
    }

    if( ((flagL==2) || (flagP==2)) && (flagS==2) )
    {
        if(flagP==2) {
            if(mode==0) {
                xfp_disable_laser(port);
                printf("Port %d disable\n",port);
                print_xfp_info(port);
            }
            else
            {
                printf("Port %d enable\n",port);
                xfp_enable_laser(port);
                print_xfp_info(port);
            }
                
        }
        else
        {
            if(mode==0) {
                tx_cmd_t tx;
                txp_read_tx_cmd_reg(&tx);
                tx.lsenable = 1;
                txp_set_tx_cmd_reg(tx);
                txp_set_ls_enable(1);
            }
            else
            {
                tx_cmd_t tx;
                txp_read_tx_cmd_reg(&tx);
                tx.lsenable = 0;
                txp_set_tx_cmd_reg(tx);
                txp_set_ls_enable(0);
            }
        }
    }
    else if( (flagP==2) && (flagM==2) )
    {
        //config T41
        printf("T41 configuration: \n");
        configT41();
    }
    else if ((flagL==2) && ((flagRX==2) || (flagTX==2))) 
    {
       if(flagRX==2) {
          configJdsuChannel(channelRx,rxnm,0);
       }
       if(flagTX==2) {
          configJdsuChannel(channelTx,txnm,1);
       }
       
       
    }
    else
    {
      doc();
    }
    return 0;
}
void configT41()
{
    initialize();
  
    if (mode==1) 
    {
        eth10g(dev_id,  port,  port, 400, 0, 0, 0);
        //eth10g(dev_id,  module_id_line,  module_id_client, 400, 0, 0, 0);
        
        
    }
    else if(mode==2)
    {
        //otu2_gfec_transparent_bmp_amp_xfi_b_ccupll_400_otu3_gfec_sfi5_1_a_k_64(
        //    dev_id, module_id_line, module_id_client, 400, 0, 1, 0);
        otu2_gfec_transparent_bmp_amp_xfi_b_ccupll_400_otu3_gfec_sfi5_1_a_k_64(
            dev_id, port, port, 400, 0, 1, 0);    
    }
    else
    {
        printf("CONFGIURAR EL MODO TXP\n");
    }
    
}

int initJDSU() 
{
        int mode;      
        
        /*if(txp_jdsu_read_protected_mode(&mode)<0) {
            
            printf("Error(initJDSU):txp_jdsu_read_protected_mode\n");
            return -1;
        } 
                
        if(!mode) {*/
            
                if(txp_enter_protected_mode()<0) {
                    printf("Error(initJDSU):txp_enter_protected_mode\n");
                    return -1;
                }
        //}
                
        tx_cmd_t tx;
        tx.prbsen = 1;
        tx.prbspat0 = 1;
        tx.prbspat1 = 1; 
        tx.txdeskewen = 1;                  
        tx.txdcksel = 0;
        tx.txlinetimsel = 1; 
        tx.txlloopenb =1;
        tx.txreset = 1;                 
        tx.txfifores = 1;               
        tx.autotxfifores = 0;
        tx.sctxreset = 1;               
        tx.txmutemonclk = 1;
        tx.lsenable  = 1;
        tx.txratesel0 = 1;              
        tx.txratesel1 = 1;              
        tx.txrefsel = 0;          
        
        if( txp_set_tx_cmd_reg(tx) < 0) {
            printf("Error(initJDSU):txp_set_tx_cmd_reg\n");
            return -1;
        }
        
        rx_cmd_t rx;
        rx.rxmute = 1;
        rx.rxdloopenb = 1;
        rx.scrxreset = 1; 
        rx.prbsen = 1;
        rx.prbspat0 = 1;
        rx.prbspat1 = 1;
        rx.rxratesel0 = 1; 
        rx.rxratesel1 = 0;
        rx.rxrefsel = 0;
        rx.rxlckref = 1;
        rx.rxmonclksel = 0; 
        rx.rxreset = 1;
        rx.rxmutemonclk = 1;
        
        if(txp_set_rx_cmd_reg(rx)<0) {
            printf("Error(initJDSU):txp_set_rx_cmd_reg\n");
            return -1;
        }
    
    return 0;
}

int configJDSU()
{
    int mode;      
    
    /*if(txp_jdsu_read_protected_mode(&mode)<0) {
    
        printf("Error(configJDSU): txp_jdsu_read_protected_mode\n");
        return -1;
    }
    
    if(!mode) {
     */   
        if(txp_enter_protected_mode() < 0) {
            
            printf("Error(configJDSU): txp_enter_protected_mode\n");
            return -1;
        }
     //}   
         
    if(txp_set_laser_itu_channel(itu) < 0) {
            
        printf("Error(configJDSU): txp_set_laser_itu_channel\n");
        return -1;
    }
        
    return 0;
}

int getChannel(char *arg) 
{
    itu_channel_t min,max;
    
    if(txp_read_last_laser_itu_channel(&max)<0) {
        printf("Error(getChannel): txp_read_last_laser_itu_channel\n");
        return -1;
    }
    
    if(txp_read_first_laser_itu_channel(&min)<0) {
        printf("Error(getChannel): txp_read_first_laser_itu_channel\n");
        return -1;
    }
    
    int channel = (int) arg;
    
    if((channel < min.channel) || (channel > max.channel)) {
        printf("Error(getChannel): Channel out of range\n");
        return -2;
    }
    
    itu.channel = channel;
    
    return 0;
}

int getBand(char *arg)
{
    if(strlen(arg) > 1) {
        return -1;
    }
    
    if(strncmp(arg,"L",1)==0) {
        itu.band = 0x4C;
        return 0;
    }
    
    if(strncmp(arg,"C",1)==0) {
        itu.band = 0x43;
        return 0;
    }
    
    return -1;    
}

void doc()
{
    /*printf("Usage: config (argument value)+\n\n");

    printf("Argument        Value       Description\n");
    printf("---------------------------------------------\n");
    printf("-m | --mode     eth | otn   Select OTU or ETH\n\n");
    printf("-p | --port     [0,1,2,3]   Select Port\n\n");
    printf("-l | --line     -           flag to configure line\n\n");
    printf("-c | --channel  -           Channel value\n\n");
    printf("-b | --band     C | L       Select Band\n\n");*/
    
    printf("config: missing operand after `config'\n");
    printf("config: Try `help config' for more information.\n");
    exit(EXIT_FAILURE);
}

int initialize()
{
    // Driver loading.
    if (ten_drvr_load() != CS_OK) {
        printf("Error: could not load Cortina driver!\n");
        return -1;
    }

    ten_drvr_ctl_stats_hex_format(1);

    // Value initialization.
    Chips.mpif.CHIP_ID_LSB.wrd = TEN_MPIF_CHIP_ID_LSB_dft;
    Chips.mpif.CHIP_ID_MSB.wrd = TEN_MPIF_CHIP_ID_MSB_dft;
    dev_id = 0;
    module_id_line = dev_id << 8;
    module_id_client = module_id_client | 1;

    // Device registration.
    if(ten_dev_register(dev_id,(cs_uint32)&Chips) != CS_OK) {
        printf("Error: CS604x device registration failed!\n");
        return -1;
    }

    // Initialize the device driver
    if (ten_dev_main_init(dev_id) != CS_OK) {
        printf("Error: CS604x device initialization failed!\n");
        return -1;
    }
    printf("Device Chip Id = %08X\n", ten_mpif_get_chip_jtag_id(dev_id));

    /* * * *
     * Scratch pad register = register for read/write tests.
     *  * * */
    print_status("FF - Scratchpad", ten_mpif_scratch_pad2(dev_id, 0xAA55));
    printf("Read scratchpad = %04X\n", ten_mpif_read_scratch_pad2(dev_id));

    module_id_client = ten_mod_main_init( dev_id, TEN_MODULE_A );
    module_id_line = ten_mod_main_init( dev_id, TEN_MODULE_B );

    ten_hl_config_global( dev_id, 0, 1, 0, 1, 1 );
    ten_hl_ohpp_and_shadow_ram_init(dev_id);

    // Config top level.
    ten_hl_config_global(
            dev_id,                     //Device ID
            TEN_GLOBAL_MODE_S_40G,      //Line Mode
            TEN_GLOBAL_MODE_QUAD_10G,   //Client Mode
            0,                          //mbclksel
            1,                          //Multi-Rate Mode not SFI41 Line
            1                           //Multi-Rate Mode not SFI41 Client
            );

    // -- Parameters -- ten_hsif_provision_datapath --
    // module_id: line or client
    // instance: specified as 0-3 | TEN_INSTANCE_ALL
    // tx_xfiselect: 
    //      1: XFI
    //      0: protocol selected by rx_mrprotocol (default)
    // rx_xfiselect: 
    //      1: XFI
    //      0: protocol selected by rx_mrprotocol (default)
    // tx_pswtchen: 
    //      1: disable
    //      0: enable (data is driven from remote interface)
    // tx_mrprotocol: 
    //      XAUI
    //      SFI4.2 (40G)
    //      SFI4.2 (10G)
    //      SFI4.1
    //      SFI5 (default)
    //      disabled
    // rx_pswtchen: 
    //      1: disable
    //      0: enable (data is driven from remote interface)
    // rx_mrprotocol: 
    //      XAUI
    //      SFI4.2 (40G)
    //      SFI4.2 (10G)
    //      SFI4.1
    //      SFI5 (default)
    //      disabled   
    print_status("FF - Override the default datapath state",
                 ten_hsif_provision_datapath(
                    module_id_line, TEN_INSTANCE_ALL, 1, 1, 0, 0, 0, 0));
    // rx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled

    // -- Parameters -- ten_hsif_provision_datapath --
    // module_id: line or client
    // instance: specified as 0-3 | TEN_INSTANCE_ALL
    // tx_xfiselect: 
    //      1: XFI
    //      0: protocol selected by rx_mrprotocol (default)
    // rx_xfiselect: 
    //      1: XFI
    //      0: protocol selected by rx_mrprotocol (default)
    // tx_pswtchen: 
    //      1: disable
    //      0: enable (data is driven from remote interface)
    // tx_mrprotocol: 
    //      XAUI
    //      SFI4.2 (40G)
    //      SFI4.2 (10G)
    //      SFI4.1
    //      SFI5 (default)
    //      disabled
    // rx_pswtchen: 
    //      1: disable
    //      0: enable (data is driven from remote interface)
    // rx_mrprotocol: 
    //      XAUI
    //      SFI4.2 (40G)
    //      SFI4.2 (10G)
    //      SFI4.1
    //      SFI5 (default)
    //      disabled   
    print_status("FF - Override the Default Datapath State",
                 ten_hsif_provision_datapath(
                    module_id_client, TEN_INSTANCE_ALL, 1, 1, 0, 0, 0, 0));
    // rx_mrprotocol: XAUI, SFI4. 2 (40G), SFI4. 2 (10G), SFI4. 1, SFI5 (default), disabled

    // -- Parameters -- ten_hl_hsif_powerdown_mr --
    // module_id
    // slice
    // ctl
    print_status("FF - Controls MR SERDES Powerdown",
                 ten_hl_hsif_powerdown_mr(
                    module_id_client, 
                    TEN_SLICE_ALL, 
                    CS_ENABLE));

    // -- Parameters -- ten_hl_n40g_config --
    // module_id: 
    //      module_id_a
    //      module_id_b
    // mode_rx: 
    //      (table, row) = (9, 2) -> TEN_N40G_RX_OTU3_ODTU23 (=7)
    // mode_tx: 
    //      (table, row) = (10, 2) -> TEN_N40G_TX_ODTU2_OTU3 (=11)
    print_status("FF - Config the N40G Block",
                 ten_hl_n40g_config(
                    module_id_line, 
                    TEN_N40G_RX_OTU3_ODTU23, 
                    TEN_N40G_TX_ODTU2_OTU3));


   // ten_mod_print_blk_stats (module_id_client,13);

    //ten_mod_get_blk_stats (module_id_line,TEN_ID_PP10G,pStats,len);
    //printf("%i\n",ten_hl_hsif_cfp_get_current_traffic(module_id_line,0));
    //printf("%d\n",ten_hl_hsif_cfp_get_current_traffic(module_id_client,0));
    //ten_mod_print_cfg (module_id_line);
    //ten_dev_print_cfg (dev_id);
    //ten_debug_n10g_oohr_dump_settings(dev_id,module_id_client);
    //ten_debug_slice_dump_settings (module_id_line,0);
    //ten_debug_n10g_oohr_dump_settings (module_id_line,0);

    return 0;

}

void print_status(const char *msg, cs_status status)
{
    if (status == CS_OK) {
        printf("%s : OK\n", msg);
    } else {
        printf("%s : ERROR\n", msg);
    }
}

void print_defects(const char* msg, cs_status status)
{
    if (status == CS_OK) {
        printf("%s 0\n", msg);
    } else {
        printf("%s 1\n", msg);
    }
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

void eth10g (
    cs_uint16 dev_id,
    cs_uint8  slice_line,
    cs_uint8  slice_client,
    cs_uint16 sysrefclk,        /* freq in MHz */
    cs_uint8  dyn_repro,        /* 0 = static, 1 = DR client only, 2 = DR line and client */
    cs_uint8  auxclk,           /* 0 = don't use auxclk, 1 = use auxclk */
    cs_uint8  xfi_clk_dist )    /* 0 = internal fan-out clock distribution, 1 otherwise */
{
    cs_uint16 module;
    cs_uint32 sysclk_freq;
    cs_uint8  mbclksel;
    cs_uint8  provision_line;
    cs_uint8  provision_client;
    cs_uint8  slice;
    cs_uint8  dir;
    cs_uint8  inv;
    cs_uint16 fracdiv_module;
    cs_uint8  fracdiv_slice;
    cs_uint8  inst;
    cs_uint16 silab_mod_line;
    cs_uint16 silab_mod_client;
    cs_uint16 silab_module;
    cs_uint8  silab_slice;
    cs_uint8  gpllx1_inst_line;
    cs_uint8  gpllx1_inst_client;
    cs_uint32 rdiv_divider;
    cs_uint16 tmp_mod_line;
    cs_uint16 tmp_mod_client;
    cs_uint16 ar_mod;
    cs_uint16 ar_slice;
    cs_uint32 clk_rate;
    cs_uint16 mod_hsif;
    cs_uint8  slice_hsif;
    cs_uint8  clock_ch;
    cs_uint8  clock_card;
    cs_uint8  side;
    cs_uint8  mr_optical_module_type;
    int       i;

    cs_uint16 mod_a = dev_id << 8;
    cs_uint16 mod_b = mod_a | 1;

    /* Default KPGA patterns that can be changed or turned into a parameter */
    cs_uint16 hsif_kpga = TEN_HSIF_PRBS_PN31;
    cs_uint16 kpga = TEN_KPG_PN31;

    cs_uint16 mod_line = ( dev_id << 8 ) | 0;
    cs_uint16 mod_client = ( dev_id << 8 ) | 1;
    sysclk_freq = sysrefclk * 1000000;

    provision_line   = dyn_repro != 1;
    provision_client = 1;

    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {

        /*  Hard-reset the CS604x device and set the sysrefclk */
        //tb_init(sysclk_freq, &mbclksel);
        ten_dev_register(dev_id, (cs_uint32) &Chips);
        /*  Initialize the device driver */
        if (ten_dev_main_init(dev_id) != CS_OK) {
            printf("CS604x device initialization failed; provisioning aborted\n");
            return;
        }

        mod_a = ten_mod_main_init( dev_id, TEN_MODULE_A );
        mod_b = ten_mod_main_init( dev_id, TEN_MODULE_B );

        /*  ten_drvr_ctl_logging(1); */

        /*  Reset the EVB */
        //tb_reset(sysclk_freq);
        ten_hl_config_global( dev_id, 0, 1, mbclksel, 1, 1 );
        ten_hl_ohpp_and_shadow_ram_init(dev_id);
        ten_hl_hsif_power_down_serdes(mod_a);
        ten_hl_hsif_power_down_serdes(mod_b);
    } else {
        if (provision_client) {
            ten_mpif_clock_select_gpll_in( dev_id, mod_client & 1, slice_client, CS_TX, 1 );
        }
        if (provision_line) {
            ten_mpif_clock_select_gpll_in( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 1 );
        }
    }
    /* This will enable logging
       ten_drvr_ctl_logging (CS_ENABLE);
     */
    sysclk_freq        = sysclk_freq > 200000000 ? sysclk_freq : sysclk_freq * 4;
    gpllx1_inst_line   = 1;
    gpllx1_inst_client = 9;
    
    /*
       if (t100) {
       if ( board_type == 11 ) {
       t40fpga_write_reg( 432, 0x4802, 0x0020 );
       }
       else if ( board_type == 8 ) {
       t40fpga_crosspoint( 432, 0, 2, 3 );
       }
       }
     */

    slice = 1 ? slice_client : slice_line;
    ten_cb_rates( dev_id, 43018413560.0, 10312500000.0 );
    
    if (provision_line) {
        fracdiv_module = mod_line;
        fracdiv_slice  = slice_line;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice : fracdiv_slice + 4;
        ten_hl_fracdiv_config( dev_id, 0, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 1, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 2, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 3, sysclk_freq, 336081355 );
    }
    
    if (provision_client) {
        fracdiv_module = mod_line;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice + 8 : fracdiv_slice + 12;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 10070800 );
        ten_mpif_set_clock_switch_force( dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE );
    }
    
    if (provision_client) {
        fracdiv_module = mod_client;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice : fracdiv_slice + 4;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 322265625 );
        fracdiv_module = mod_client;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice + 8 : fracdiv_slice + 12;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 10070800 );
        ten_mpif_set_clock_switch_force( dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE );
    }
    
    ten_mpif_global_reset_sds_xfi_mpif( dev_id, slice_client, CS_RESET_TOGGLE );
    silab_mod_client   = mod_client;
    silab_mod_line     = mod_line;
    cs_uint8 silab_slice_line   = slice_line;
    cs_uint8 silab_slice_client = slice_client;

    if ( dyn_repro != 1 ) {
        silab_module = silab_mod_line;
        silab_slice  = silab_slice_line;
    }

    silab_module = silab_mod_client;
    silab_slice  = silab_slice_client;

    /*  Clocks on the different Cortina EVBs are programmed differently. */
    /*  This code will check the board type and program the SiLabs appropriately. */

    //tb_ical( silab_module, silab_slice );
    TEN_MDELAY(5000);
    ten_set_cb_cupll_calc_t41( dev_id, 10312500000.0, 1, 64, 400000000, 800 );
    ten_hl_cupll_config_t41( mod_client, slice_client );
    
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_hl_cupll_calibrate_config_t41( dev_id, slice_client );
    }
    ten_xfi_cupll_pdcal_t41( mod_client, slice_client, 0, 0x080 );
    
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_hsif_provision_datapath( mod_a, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 );
        ten_hsif_provision_datapath( mod_b, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 );
    }

    if (provision_line) {
        tmp_mod_line = mod_line;
        ten_hsif_set_clk_40g( tmp_mod_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1 );
        ten_hsif_set_clk_40g( tmp_mod_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1 );
    }
    
    
    /*  This is to invert the SERDES lanes for the Cortina EVB; change as necessary. #1 */

    //  dir = evb_xfi{xfi_board_type}[slice_line][0];
    //inv = evb_xfi{xfi_board_type}[slice_line][1];
    if (provision_line) {
        mod_hsif               = mod_line;
        slice_hsif             = slice_line;
        //mr_optical_module_type = t40fpga_msa_detect( 432, mod_hsif & 1 );

        if (
                ( mr_optical_module_type == 0 ) ||  /*  msa_loopback = 0 */
                ( mr_optical_module_type == 1 ) ||  /*  msa_bridge = 1 */
                ( mr_optical_module_type == 2 ) ||  /*  msa_breakout = 2 */
                ( mr_optical_module_type == 4 ) ||  /*  msa_sfi41_loopback = 4 */
                ( mr_optical_module_type == 10 ) || /*  msa_fpga_loopback = 10 */
                ( mr_optical_module_type == 12 ) || /*  msa_none = 12 */
                ( mr_optical_module_type == 0xFF )  /*  msa_error = 0xFF */
           ) {                                           
            /*  Optical module is not present, so there will be no loss of signal indication */
            /*  10G lane OK status signal will NOT take external LOS into consideration. */
            ten_hsif_set_ok_ctrl( mod_hsif, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );

        } else {

            /*  This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been */
            /*  changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin, */
            /*  generated by the FPGA which in turn gets a signal from the optical module. It causes */
            /*  the dewrapper to disable justifications and N10G to go in and out of frame. */
            /*  This needs to be fixed in the FPGA */
            ten_glb_misc_xlos_inv_mr( mod_hsif, slice_hsif, 1 );
        }

        ten_hl_config_sfi51(mod_hsif);

        /*  Reset the optical module */
        //dev_reg_write( 432, 0, 20480, 0x80a );
        TEN_MDELAY(2000);
        //dev_reg_write( 432, 0, 20480, 0x803 );

    }

    if (provision_client) {

        /*  This is to invert the SERDES lanes for the Cortina EVB; change as necessary. #4 */
        // dir                    = evb_xfi{xfi_board_type}[slice_client][0];
        // inv                    = evb_xfi{xfi_board_type}[slice_client][1];
        mod_hsif               = mod_client;
        slice_hsif             = slice_client;
        // mr_optical_module_type = t40fpga_msa_detect( 432, mod_hsif & 1 );

        if (
                ( mr_optical_module_type == 0 ) ||  /*  msa_loopback = 0 */
                ( mr_optical_module_type == 1 ) ||  /*  msa_bridge = 1 */
                ( mr_optical_module_type == 2 ) ||  /*  msa_breakout = 2 */
                ( mr_optical_module_type == 4 ) ||  /*  msa_sfi41_loopback = 4 */
                ( mr_optical_module_type == 10 ) || /*  msa_fpga_loopback = 10 */
                ( mr_optical_module_type == 12 ) || /*  msa_none = 12 */
                ( mr_optical_module_type == 0xFF )  /*  msa_error = 0xFF */
           ) {                                           
            /*  Optical module is not present, so there will be no loss of signal indication */
            /*  10G lane OK status signal will NOT take external LOS into consideration. */
            ten_hsif_set_ok_ctrl( mod_hsif, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );

        } else {

            /*  This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been */
            /*  changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin, */
            /*  generated by the FPGA which in turn gets a signal from the optical module. It causes */
            /*  the dewrapper to disable justifications and N10G to go in and out of frame. */
            /*  This needs to be fixed in the FPGA */
            ten_glb_misc_xlos_inv_mr( mod_hsif, slice_hsif, 1 );
        }

        ten_hl_config_xfi_t41( mod_hsif, slice_hsif, 12, dir, inv, sysclk_freq, 1, 0, auxclk, 1, TEN_HSIF_XFI_DIV_BY_64_REF, xfi_clk_dist, 0, 0 );
    }

    ten_syncdsync_thread_set_cb_transcode( dev_id, slice_client, 1, 1 );
    
    if ( !ten_dev_is_t41(dev_id) ) {
        ten_syncdsync_thread_set_cb_40g_muxponder( dev_id, slice_client, 0, 1, 0, 2, 255, 236, 65535, 65535 );
    } else {
        ten_syncdsync_set_cb_40g_muxponder_t41( dev_id, slice_client, 0, 1, 0, 2, 255, 236, 65535, 65535, 10312500000, 10037273920, 43018413560 );
    }

    if ( !ten_dev_is_t41(dev_id) ) {
        ten_hl_syncdsync_threadsafe_datapath_config( mod_line, slice, mod_client, slice_client, 1, 0, 3, 64, 13, 16 );
    } else {
        ten_hl_syncdsync_datapath_config_t41( mod_line, slice, mod_client, slice_client, 13, 16, 1, 3, 64, 0, 1, 4 );
    }

    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_mpif_global_clock_disable_common( dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON );
        ten_mpif_global_reset_common( dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON );
        ten_mpif_global_reset_common( dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS );
    }

    ten_hl_config_10ge_otu3v_t41( mod_line, slice, slice_client, dyn_repro, 1, 13, 12, sysrefclk, 0, 0, 0, 1, 4, TEN_28_BLOCKS_5_SUPERBLOCKS_CRC4, 2 );
    ten_n40g_gblr4x_set_kpasel( mod_line, 1 );

    /*  Set the unused channels to 'idle' */
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 0 ) ) {
        for ( i = 0 ; i < 4 ; i++ ) {
            if ( i != slice_client ) {
                ten_hl_config_aggregation_idle( mod_line, i, mod_client, i );
            }
        }
    }

    if (provision_line) {
        ten_hsif_set_ok_ctrl( mod_line, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );
    }

    if (provision_client) {
        ten_hsif_set_ok_ctrl( mod_client, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );
    }

    /*  The following clockmux code is written for CS604x only in order to simplify it */
    if (provision_client) {
        ten_hl_xfi_config_clockmux_t41( mod_client, slice_client, auxclk, 64, 1, 1 );
        ten_mpif_clock_select_gpll_in( dev_id, mod_client & 1, slice_client, CS_TX, 0 );    /*  Bugzilla 30856 */
        ten_hl_gpllx1_waitfor_gpll_lock( dev_id, gpllx1_inst_client + slice_client );
    }

    /*  The following clockmux code is written for CS604x only in order to simplify it */
    if (provision_line) {
        ten_hl_mr_40g_config_clockmux(mod_line);
        ten_mpif_clock_select_gpll_in( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 0x0 );
        ten_hl_gpllx1_waitfor_gpll_lock_40g( dev_id, gpllx1_inst_line );
    }
    gpllx1_inst_client = ( mod_client & 1 ) == TEN_MODULE_A ? 1 : 9;
    ten_hl_gpllx1_waitfor_gpll_lock( dev_id, gpllx1_inst_client + slice_client );
    
    if (provision_line) {
        ten_n40g_set_global_resets( mod_a, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL );
        ten_n40g_set_global_resets( mod_b, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL );
    }
    ten_hl_config_remove_soft_resets( mod_line, slice_line, mod_client, slice_client, 12, 1 );
    
    if (provision_line) {
        ten_mpif_global_reset_hsif( dev_id, mod_line & 1, CS_TX_AND_RX, CS_RESET_DEASSERT );
        ten_mpif_set_clock_switch_force( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_RX, CS_DISABLE );
        ten_mpif_set_clock_switch_force( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, CS_DISABLE );
    }
    
    if (provision_client) {
        ten_mpif_global_reset_hsif( dev_id, mod_client & 1, CS_TX_AND_RX, CS_RESET_DEASSERT );
        ten_mpif_set_clock_switch_force( dev_id, mod_client,        slice_client, CS_RX, CS_DISABLE );
        ten_mpif_set_clock_switch_force( dev_id, TEN_MODULE_A_AND_B, slice_client, CS_TX, CS_DISABLE );
    }
    ten_hl_syncdsync_reset( mod_client, slice_client );
    ten_syncdsynctx_set_configuration_init_force( mod_client, slice_client, CS_RESET_TOGGLE );
    
    if (provision_line) {
        ten_hl_syncdsync_reset( mod_line, slice );
        ten_syncdsynctx_set_configuration_init_force( mod_line, slice, CS_RESET_TOGGLE );
    }
    ten_cupll_reset_t41( mod_client, slice_client, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE );
    ten_mpif_cupll_settle_force_t41( dev_id, slice_client, 2, CS_ENABLE );
    ten_mpif_cupll_settle_force_t41( dev_id, slice_client, 2, CS_DISABLE );
}

int otu2_gfec_transparent_bmp_amp_xfi_b_ccupll_400_otu3_gfec_sfi5_1_a_k_64(
    cs_uint16 dev_id,
    cs_uint8  slice_line,
    cs_uint8  slice_client,
    cs_uint16 sysrefclk,        /* freq in MHz */
    cs_uint8  dyn_repro,        /* 0 = static, 1 = DR client only, 2 = DR line and client */
    cs_uint8  auxclk,           /* 0 = don't use auxclk, 1 = use auxclk */
    cs_uint8  xfi_clk_dist )    /* 0 = internal fan-out clock distribution, 1 otherwise */
{
    cs_uint16 module;
    cs_uint32 sysclk_freq;
    cs_uint8  mbclksel;
    cs_uint8  provision_line;
    cs_uint8  provision_client;
    cs_uint8  slice;
    cs_uint8  dir;
    cs_uint8  inv;
    cs_uint16 fracdiv_module;
    cs_uint8  fracdiv_slice;
    cs_uint8  inst;
    cs_uint16 silab_mod_line;
    cs_uint16 silab_mod_client;
    cs_uint16 silab_module;
    cs_uint8  silab_slice;
    cs_uint8  gpllx1_inst_line;
    cs_uint8  gpllx1_inst_client;
    cs_uint32 rdiv_divider;
    cs_uint16 tmp_mod_line;
    cs_uint16 tmp_mod_client;
    cs_uint16 ar_mod;
    cs_uint16 ar_slice;
    cs_uint32 clk_rate;
    cs_uint16 mod_hsif;
    cs_uint8  slice_hsif;
    cs_uint8  clock_ch;
    cs_uint8  clock_card;
    cs_uint8  side;
    cs_uint8  mr_optical_module_type;
    int       i, t100, board_type;


    t100 = board_type = 0;
    cs_uint16 mod_a = dev_id << 8;
    cs_uint16 mod_b = mod_a | 1;

    // Default KPGA patterns that can be changed or turned into a parameter
    cs_uint16 hsif_kpga = TEN_HSIF_PRBS_PN31;
    cs_uint16 kpga = TEN_KPG_PN31;

    cs_uint16 mod_line = ( dev_id << 8 ) | 0;
    cs_uint16 mod_client = ( dev_id << 8 ) | 1;
    sysclk_freq = sysrefclk * 1000000;

    provision_line   = dyn_repro != 1;
    provision_client = 1;

    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_dev_register(dev_id, (cs_uint32)&Chips);

        // Initialize the device driver
        if (ten_dev_main_init(dev_id) != CS_OK) {
            printf("Error: CS604x device initialization failed!\n");
            return -1;
        }

        mod_a = ten_mod_main_init( dev_id, TEN_MODULE_A );
        mod_b = ten_mod_main_init( dev_id, TEN_MODULE_B );

        ten_hl_config_global( dev_id, 0, 1, mbclksel, 1, 1 );
        ten_hl_ohpp_and_shadow_ram_init(dev_id);
        ten_hl_hsif_power_down_serdes(mod_a);
        ten_hl_hsif_power_down_serdes(mod_b);
    } else {
        if (provision_client) {
            ten_mpif_clock_select_gpll_in( dev_id, mod_client & 1, slice_client, CS_TX, 1 );
        }
        if (provision_line) {
            ten_mpif_clock_select_gpll_in( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 1 );
        }
    }
    
    sysclk_freq        = sysclk_freq > 200000000 ? sysclk_freq : sysclk_freq * 4;
    gpllx1_inst_line   = 1;
    gpllx1_inst_client = 9;
    
    slice = 1 ? slice_client : slice_line;
    if (provision_line) {
        fracdiv_module = mod_line;
        fracdiv_slice  = slice_line;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice : fracdiv_slice + 4;
        ten_hl_fracdiv_config( dev_id, 0, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 1, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 2, sysclk_freq, 336081355 );
        ten_hl_fracdiv_config( dev_id, 3, sysclk_freq, 336081355 );
    }

    if (provision_client) {
        fracdiv_module = mod_line;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice + 8 : fracdiv_slice + 12;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 9802025 );
        ten_mpif_set_clock_switch_force( dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE );
    }

    if (provision_client) {
        fracdiv_module = mod_client;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice : fracdiv_slice + 4;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 334663291 );
        fracdiv_module = mod_client;
        fracdiv_slice  = slice_client;
        inst           = ( ( fracdiv_module & 1 ) == TEN_MODULE_A ) ? fracdiv_slice + 8 : fracdiv_slice + 12;
        ten_hl_fracdiv_config( dev_id, inst, sysclk_freq, 10458227 );
        ten_mpif_set_clock_switch_force( dev_id, fracdiv_module & 1, fracdiv_slice, CS_TX, CS_ENABLE );
    }

    ten_mpif_global_reset_sds_xfi_mpif( dev_id, slice_client, CS_RESET_TOGGLE );
    silab_mod_client   = mod_client;
    silab_mod_line     = mod_line;
    cs_uint8 silab_slice_line   = slice_line;
    cs_uint8 silab_slice_client = slice_client;

    if ( dyn_repro != 1 ) {
        silab_module = silab_mod_line;
        silab_slice  = silab_slice_line;

        ten_mpif_rxdiv_cfg0_mode_t41( dev_id, ( silab_module * 4 + silab_slice ), 0 );
        TEN_MDELAY(5000);
    
        silab_module = silab_mod_client;
        silab_slice  = silab_slice_client;
    }

    /*  Clocks on the different Cortina EVBs are programmed differently. */
    /*  This code will check the board type and program the SiLabs appropriately. */
    if ( !(( board_type == 8 ) && ( silab_module == 1 ) && ( 5 != 5 )) ) {
        ten_mpif_rxdiv_cfg0_mode_t41( dev_id, ( silab_module * 4 + silab_slice ), 0 );
    }
    
    TEN_MDELAY(5000);
    ten_set_cb_cupll_calc_t41( dev_id, 10709225320.0, 1, 64, 400000000, 800 );
    ten_hl_cupll_config_t41( mod_client, slice_client );
    
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_hl_cupll_calibrate_config_t41( dev_id, slice_client );
    }
    
    ten_xfi_cupll_pdcal_t41( mod_client, slice_client, 0, 0x080 );
    
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_hsif_provision_datapath( mod_a, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 );
        ten_hsif_provision_datapath( mod_b, TEN_INSTANCE_ALL, 0, 0, 0, 0, 0, 0 );
    }
    
    if (provision_line) {
        tmp_mod_line = mod_line;
        ten_hsif_set_clk_40g( tmp_mod_line, TEN_HSIF_CLK_40G_RX_AGGR_MODE, 0x1 );
        ten_hsif_set_clk_40g( tmp_mod_line, TEN_HSIF_CLK_40G_TX_AGGR_MODE, 0x1 );
    }

    if (provision_line) {
        mod_hsif               = mod_line;
        slice_hsif             = slice_line;
        if (
                ( mr_optical_module_type == 0 ) ||  //  msa_loopback = 0
                ( mr_optical_module_type == 1 ) ||  //  msa_bridge = 1
                ( mr_optical_module_type == 2 ) ||  //  msa_breakout = 2
                ( mr_optical_module_type == 4 ) ||  //  msa_sfi41_loopback = 4
                ( mr_optical_module_type == 10 ) || //  msa_fpga_loopback = 10
                ( mr_optical_module_type == 12 ) || //  msa_none = 12
                ( mr_optical_module_type == 0xFF )  //  msa_error = 0xFF
           ) {                                           
            // Optical module is not present, so there will be no loss of signal indication */
            // 10G lane OK status signal will NOT take external LOS into consideration. */
            ten_hsif_set_ok_ctrl( mod_hsif, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );

        } else {
            // This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been
            // changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin,
            // generated by the FPGA which in turn gets a signal from the optical module. It causes
            // the dewrapper to disable justifications and N10G to go in and out of frame.
            // This needs to be fixed in the FPGA
            ten_glb_misc_xlos_inv_mr( mod_hsif, slice_hsif, 1 );
        }

        ten_hl_config_sfi51(mod_hsif);

        TEN_MDELAY(2000);
    }

    if (provision_client) {

        /*  This is to invert the SERDES lanes for the Cortina EVB; change as necessary. #4 */
        // dir                    = evb_xfi{xfi_board_type}[slice_client][0];
        // inv                    = evb_xfi{xfi_board_type}[slice_client][1];
        mod_hsif               = mod_client;
        slice_hsif             = slice_client;
        // mr_optical_module_type = t40fpga_msa_detect( 432, mod_hsif & 1 );

        if (
                ( mr_optical_module_type == 0 ) ||     /*  msa_loopback = 0 */
                ( mr_optical_module_type == 1 ) ||     /*  msa_bridge = 1 */
                ( mr_optical_module_type == 2 ) ||     /*  msa_breakout = 2 */
                ( mr_optical_module_type == 4 ) ||     /*  msa_sfi41_loopback = 4 */
                ( mr_optical_module_type == 10 ) ||    /*  msa_fpga_loopback = 10 */
                ( mr_optical_module_type == 12 ) ||    /*  msa_none = 12 */
                ( mr_optical_module_type == 0xFF )
           ) {                                           /*  msa_error = 0xFF */
            /*  Optical module is not present, so there will be no loss of signal indication */
            /*  10G lane OK status signal will NOT take external LOS into consideration. */
            ten_hsif_set_ok_ctrl( mod_hsif, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );

        } else {

            /*  This is a temporary fix. The N40G_OTNR4X_ODWCFG:LINKALM_JCNOM bit default has been */
            /*  changed to 1 in T41. This bit gets set if an XLOS is detected on the hardware pin, */
            /*  generated by the FPGA which in turn gets a signal from the optical module. It causes */
            /*  the dewrapper to disable justifications and N10G to go in and out of frame. */
            /*  This needs to be fixed in the FPGA */
            ten_glb_misc_xlos_inv_mr( mod_hsif, slice_hsif, 1 );
        }
        ten_hl_config_xfi_t41( mod_hsif, slice_hsif, 5, dir, inv, sysclk_freq, 1, 0, auxclk, 1, TEN_HSIF_XFI_DIV_BY_64_REF, xfi_clk_dist, 0, 0 );
    }

    ten_syncdsync_thread_set_cb_transcode( dev_id, slice_client, 1, 1 );
    
    if ( !ten_dev_is_t41(dev_id) ) {
        ten_syncdsync_thread_set_cb_40g_muxponder( dev_id, slice_client, 0, 1, 0, 2, 255, 236, 255, 237 );
    } else {
        ten_syncdsync_set_cb_40g_muxponder_t41( dev_id, slice_client, 0, 1, 0, 2, 255, 236, 255, 237, 10709225320, 10037273920, 43018413560 );
    }

    if ( !ten_dev_is_t41(dev_id) ) {
        ten_hl_syncdsync_threadsafe_datapath_config( mod_line, slice, mod_client, slice_client, 1, 0, 1, 64, 13, 13 );
    } else {
        ten_hl_syncdsync_datapath_config_t41( mod_line, slice, mod_client, slice_client, 13, 13, 1, 1, 64, 0, 1, 4 );
    }

    if ( ( dyn_repro == 0 ) || ( dyn_repro == 3 ) ) {
        ten_mpif_global_clock_disable_common( dev_id, CS_ENABLE, TEN_MPIF_GLOBAL_CLOCK_DISABLE_COMMON_XCON );
        ten_mpif_global_reset_common( dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_XCON );
        ten_mpif_global_reset_common( dev_id, CS_RESET_DEASSERT, TEN_MPIF_GLOBAL_RESET_COMMON_TOPSYS );
    }
    
    ten_hl_config_otu2v_otu3v_t41( mod_line, slice, slice_client, dyn_repro, 1, 13, 5, 13, 0, 0, 0, 0, 0, 1, 4, 255 );

    /* ## The following code is used to enable the interrupt and register a handler for OTN Loss Of Frame */
    /* ## It is commented out so that customers can implement interrupt handler registration in their own way */
    /*  ten_n10g_otnr_intr_handler_enable (mod_line, slice, TEN_N10G_OTNR_INTR_ILOF); */
    /*  ten_n10g_otnr_intr_handler_enable (mod_client, slice_client, TEN_N10G_OTNR_INTR_ILOF); */
    ar_mod   = mod_client & 1;
    ar_slice = slice_client;
    ar_mod   = mod_line & 1;
    ar_slice = 0;
    ten_n40g_gblr4x_set_kpasel( mod_line, 1 );

    /*  Set the unused channels to 'idle' */
    if ( ( dyn_repro == 0 ) || ( dyn_repro == 0 ) ) {
        for ( i = 0 ; i < 4 ; i++ ) {
            if ( i != slice_client ) {
                ten_hl_config_aggregation_idle( mod_line, i, mod_client, i );
            }
        }
    }

    if (provision_line) {
        ten_hsif_set_ok_ctrl( mod_line, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );
    }
    
    if (provision_client) {
        ten_hsif_set_ok_ctrl( mod_client, TEN_SLICE_ALL, TEN_HSIF_OK_CTRL_XLOS_EN, 0 );
    }

    /*  The following clockmux code is written for CS604x only in order to simplify it */
    if (provision_client) {
        ten_hl_xfi_config_clockmux_t41( mod_client, slice_client, auxclk, 64, 1, 1 );
        ten_mpif_clock_select_gpll_in( dev_id, mod_client & 1, slice_client, CS_TX, 0 );    /*  Bugzilla 30856 */
        ten_hl_gpllx1_waitfor_gpll_lock( dev_id, gpllx1_inst_client + slice_client );
    }

    /*  The following clockmux code is written for CS604x only in order to simplify it */
    if (provision_line) {
        ten_hl_mr_40g_config_clockmux(mod_line);
        ten_mpif_clock_select_gpll_in( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, 0x0 );
        ten_hl_gpllx1_waitfor_gpll_lock_40g( dev_id, gpllx1_inst_line );
    }
    
    gpllx1_inst_client = ( mod_client & 1 ) == TEN_MODULE_A ? 1 : 9;
    ten_hl_gpllx1_waitfor_gpll_lock( dev_id, gpllx1_inst_client + slice_client );
    
    if (provision_line) {
        ten_n40g_set_global_resets( mod_a, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL );
        ten_n40g_set_global_resets( mod_b, CS_RESET_DEASSERT, TEN_N40G_GLOBAL_RESETS_ALL );
    }
    
    ten_hl_config_remove_soft_resets( mod_line, slice_line, mod_client, slice_client, 5, 1 );
    
    if (provision_line) {
        ten_mpif_global_reset_hsif( dev_id, mod_line & 1, CS_TX_AND_RX, CS_RESET_DEASSERT );
        ten_mpif_set_clock_switch_force( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_RX, CS_DISABLE );
        ten_mpif_set_clock_switch_force( dev_id, mod_line & 1, TEN_SLICE_ALL, CS_TX, CS_DISABLE );
    }
    
    if (provision_client) {
        ten_mpif_global_reset_hsif( dev_id, mod_client & 1, CS_TX_AND_RX, CS_RESET_DEASSERT );
        ten_mpif_set_clock_switch_force( dev_id, mod_client,        slice_client, CS_RX, CS_DISABLE );
        ten_mpif_set_clock_switch_force( dev_id, TEN_MODULE_A_AND_B, slice_client, CS_TX, CS_DISABLE );
    }
    
    ten_hl_syncdsync_reset( mod_client, slice_client );
    ten_syncdsynctx_set_configuration_init_force( mod_client, slice_client, CS_RESET_TOGGLE );
    
    if (provision_line) {
        ten_hl_syncdsync_reset( mod_line, slice );
        ten_syncdsynctx_set_configuration_init_force( mod_line, slice, CS_RESET_TOGGLE );
    }
    
    ten_cupll_reset_t41( mod_client, slice_client, TEN_XFI_CUPLL_RESET_CUPLL_DIG, CS_RESET_TOGGLE );
    ten_mpif_cupll_settle_force_t41( dev_id, slice_client, 2, CS_ENABLE );
    ten_mpif_cupll_settle_force_t41( dev_id, slice_client, 2, CS_DISABLE );
}

void configEDFA() 
{



}


int configJdsuChannel(unsigned char channel, float wl, int side) {


    int mode; 
    itu_channel_t itu;
    
  /*  if(txp_jdsu_read_protected_mode(&mode)<0) {
    
        printf("Error(configJdsuChannel): txp_jdsu_read_protected_mode\n");
        return -1;
    }
    */
    itu.channel = channel;
    
    if(wl<1568.77)
    {
        //configuramos C-Band
        itu.band = 0x43;
        printf("C-Band\n");
    }
    else
    {
        //configuramos L-Band
        itu.band = 0x4C;
        printf("L-Band\n");
    }
   
   if(side==0)
   {
       //configuramos RX ó LO.
       if(txp_oclaro_set_receiver_laser_itu_channel(itu)<0) {
        printf("Error(configJdsuChannel): txp_jdsu_set_rx_laser_itu_channel\n");
        return -1;
       }
   }
   else
   {
       //configuramos TX.
       if(txp_set_laser_itu_channel(itu)<0) {
    
        printf("Error(configJdsuChannel): txp_set_laser_itu_channel\n");
        return -1;
    }
   }
    
    
    
    
    return 0;
}

void print_xfp_info(int port) {
    
    float temp;
    int status;
    double value_real;
    
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
	if (value_real <= -40.0) 
        printf("(no signal)");
	printf("\n");


}



 
 
/* Create a new hashtable. */
hashtable_t *ht_create( int size ) {
 
	hashtable_t *hashtable = NULL;
	int i;
 
	if( size < 1 ) return NULL;
 
	/* Allocate the table itself. */
	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}
 
	/* Allocate pointers to the head nodes. */
	if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}
 
	hashtable->size = size;
 
	return hashtable;	
}
 
/* Hash a string for a particular hash table. */
int ht_hash( hashtable_t *hashtable, char *key ) {
 
	unsigned long int hashval;
	int i = 0;
 
	/* Convert our string to an integer */
	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		hashval = hashval << 8;
		hashval += key[ i ];
		i++;
	}
 
	return hashval % hashtable->size;
}
 
/* Create a key-value pair. */
entry_t *ht_newpair( char *key, char *value ) {
	entry_t *newpair;
 
	if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}
 
	if( ( newpair->key = strdup( key ) ) == NULL ) {
		return NULL;
	}
 
	if( ( newpair->value = strdup( value ) ) == NULL ) {
		return NULL;
	}
 
	newpair->next = NULL;
 
	return newpair;
}
 
/* Insert a key-value pair into a hash table. */
void ht_set( hashtable_t *hashtable, char *key, char *value ) {
	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;
 
	bin = ht_hash( hashtable, key );
 
	next = hashtable->table[ bin ];
 
	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}
 
	/* There's already a pair.  Let's replace that string. */
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {
 
		free( next->value );
		next->value = strdup( value );
 
	/* Nope, could't find it.  Time to grow a pair. */
	} else {
		newpair = ht_newpair( key, value );
 
		/* We're at the start of the linked list in this bin. */
		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;
	
		/* We're at the end of the linked list in this bin. */
		} else if ( next == NULL ) {
			last->next = newpair;
	
		/* We're in the middle of the list. */
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	}
}
 
/* Retrieve a key-value pair from a hash table. */
char *ht_get( hashtable_t *hashtable, char *key ) {
	int bin = 0;
	entry_t *pair;
 
	bin = ht_hash( hashtable, key );
 
	/* Step through the bin, looking for our value. */
	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		pair = pair->next;
	}
 
	/* Did we actually find anything? */
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return NULL;
 
	} else {
		return pair->value;
	}
	
}

void crear_tabla() {

 
		ht_set( hashtableTX, "1528.77", "196.10" );
		ht_set( hashtableTX, "1529.55", "196.00" );
		ht_set( hashtableTX, "1530.33", "195.90" );
		ht_set( hashtableTX, "1531.12", "195.80" );
    	ht_set( hashtableTX, "1531.90", "195.70" );
		ht_set( hashtableTX, "1532.68", "195.60" );
		ht_set( hashtableTX, "1533.47", "195.50" );
		ht_set( hashtableTX, "1534.25", "195.40" );
    	ht_set( hashtableTX, "1535.04", "195.30" );
		ht_set( hashtableTX, "1535.82", "195.20" );
		ht_set( hashtableTX, "1536.61", "195.10" );
		ht_set( hashtableTX, "1537.40", "195.00" );
    	ht_set( hashtableTX, "1538.19", "194.90" );
		ht_set( hashtableTX, "1538.98", "194.80" );
		ht_set( hashtableTX, "1539.77", "194.70" );
		ht_set( hashtableTX, "1540.56", "194.60" );
    	ht_set( hashtableTX, "1541.35", "194.50" );
		ht_set( hashtableTX, "1542.14", "194.40" );
		ht_set( hashtableTX, "1542.94", "194.30" );
		ht_set( hashtableTX, "1543.73", "194.20" );
    	ht_set( hashtableTX, "1544.53", "194.10" );
		ht_set( hashtableTX, "1545.32", "194.00" );
		ht_set( hashtableTX, "1546.12", "193.90" );
		ht_set( hashtableTX, "1546.92", "193.80" );
    	ht_set( hashtableTX, "1547.72", "193.70" );
		ht_set( hashtableTX, "1548.51", "193.60" );
		ht_set( hashtableTX, "1549.32", "193.50" );
		ht_set( hashtableTX, "1550.12", "193.40" );
    	ht_set( hashtableTX, "1550.92", "193.30" );
		ht_set( hashtableTX, "1551.72", "193.20" );
		ht_set( hashtableTX, "1552.52", "193.10" );
		ht_set( hashtableTX, "1553.33", "193.00" );
		ht_set( hashtableTX, "1554.13", "192.90" );
		ht_set( hashtableTX, "1554.94", "192.80" );
		ht_set( hashtableTX, "1555.75", "192.70" );
		ht_set( hashtableTX, "1556.55", "192.60" );
    	ht_set( hashtableTX, "1557.36", "192.50" );
		ht_set( hashtableTX, "1558.17", "192.40" );
		ht_set( hashtableTX, "1558.98", "192.30" );
		ht_set( hashtableTX, "1559.79", "192.20" );
    	ht_set( hashtableTX, "1560.61", "192.10" );
		ht_set( hashtableTX, "1561.42", "192.00" );
		ht_set( hashtableTX, "1562.23", "191.90" );
		ht_set( hashtableTX, "1563.05", "191.80" );
    	ht_set( hashtableTX, "1563.86", "191.70" );
		ht_set( hashtableTX, "1564.68", "191.60" );
		ht_set( hashtableTX, "1565.50", "191.50" );
		ht_set( hashtableTX, "1566.31", "191.40" );
    	ht_set( hashtableTX, "1567.13", "191.30" );
		ht_set( hashtableTX, "1567.95", "191.20" );
		ht_set( hashtableTX, "1529.16", "196.05" );
		ht_set( hashtableTX, "1529.94", "195.95" );
    	ht_set( hashtableTX, "1530.72", "195.85" );
    	ht_set( hashtableTX, "1531.51", "195.75" );
    	ht_set( hashtableTX, "1532.29", "195.65" );
    	ht_set( hashtableTX, "1533.07", "195.55" );
		ht_set( hashtableTX, "1533.86", "195.45" );
    	ht_set( hashtableTX, "1534.64", "195.35" );
    	ht_set( hashtableTX, "1535.43", "195.25" );
    	ht_set( hashtableTX, "1536.22", "195.15" );
    	ht_set( hashtableTX, "1537.00", "195.05" );
    	ht_set( hashtableTX, "1537.79", "194.95" );
    	ht_set( hashtableTX, "1538.58", "194.85" );
    	ht_set( hashtableTX, "1539.37", "194.75" );
    	ht_set( hashtableTX, "1540.16", "194.65" );
    	ht_set( hashtableTX, "1540.95", "194.55" );
    	ht_set( hashtableTX, "1541.75", "194.45" );
    	ht_set( hashtableTX, "1542.54", "194.35" );
    	ht_set( hashtableTX, "1543.33", "194.25" );
    	ht_set( hashtableTX, "1544.13", "194.15" );
    	ht_set( hashtableTX, "1544.92", "194.05" );
    	ht_set( hashtableTX, "1545.72", "193.95" );
    	ht_set( hashtableTX, "1546.52", "193.85" );
    	ht_set( hashtableTX, "1547.32", "193.75" );
    	ht_set( hashtableTX, "1548.11", "193.65" );
    	ht_set( hashtableTX, "1548.91", "193.55" );
    	ht_set( hashtableTX, "1549.72", "193.45" );
    	ht_set( hashtableTX, "1550.52", "193.35" );
    	ht_set( hashtableTX, "1551.32", "193.25" );
    	ht_set( hashtableTX, "1552.12", "193.15" );
    	ht_set( hashtableTX, "1552.93", "193.05" );
		ht_set( hashtableTX, "1553.73", "192.95" );
		ht_set( hashtableTX, "1554.54", "192.85" );
		ht_set( hashtableTX, "1555.34", "192.75" );
		ht_set( hashtableTX, "1556.15", "192.65" );
		ht_set( hashtableTX, "1556.96", "192.55" );
		ht_set( hashtableTX, "1557.77", "192.45" );
		ht_set( hashtableTX, "1558.58", "192.35" );
		ht_set( hashtableTX, "1559.39", "192.25" );
		ht_set( hashtableTX, "1560.20", "192.15" );
		ht_set( hashtableTX, "1561.01", "192.05" );
		ht_set( hashtableTX, "1561.83", "191.95" );
		ht_set( hashtableTX, "1562.64", "191.85" );
		ht_set( hashtableTX, "1563.45", "191.75" );
		ht_set( hashtableTX, "1564.27", "191.65" );
		ht_set( hashtableTX, "1565.09", "191.55" );
		ht_set( hashtableTX, "1565.90", "191.45" );
		ht_set( hashtableTX, "1566.72", "191.35" );
		ht_set( hashtableTX, "1567.54", "191.25" );
		ht_set( hashtableTX, "1568.36", "191.15" );
		
		
		
		//Hashtable RX
		ht_set( hashtableRX, "1568.77", "191.10" );
		ht_set( hashtableRX, "1569.59", "191.00" );
		ht_set( hashtableRX, "1570.42", "190.90" );
		ht_set( hashtableRX, "1571.24", "190.80" );
    	ht_set( hashtableRX, "1572.06", "190.70" );
		ht_set( hashtableRX, "1572.89", "190.60" );
		ht_set( hashtableRX, "1573.71", "190.50" );
		ht_set( hashtableRX, "1574.54", "190.40" );
    	ht_set( hashtableRX, "1575.37", "190.30" );
		ht_set( hashtableRX, "1576.20", "190.20" );
		ht_set( hashtableRX, "1577.03", "190.10" );
		ht_set( hashtableRX, "1577.86", "190.00" );
    	ht_set( hashtableRX, "1578.69", "189.90" );
		ht_set( hashtableRX, "1579.52", "189.80" );
		ht_set( hashtableRX, "1580.35", "189.70" );
		ht_set( hashtableRX, "1581.18", "189.60" );
    	ht_set( hashtableRX, "1582.02", "189.50" );
		ht_set( hashtableRX, "1582.85", "189.40" );
		ht_set( hashtableRX, "1583.69", "189.30" );
		ht_set( hashtableRX, "1584.53", "189.20" );
    	ht_set( hashtableRX, "1585.36", "189.10" );
		ht_set( hashtableRX, "1586.20", "189.00" );
		ht_set( hashtableRX, "1587.04", "188.90" );
		ht_set( hashtableRX, "1587.88", "188.80" );
    	ht_set( hashtableRX, "1588.73", "188.70" );
		ht_set( hashtableRX, "1589.57", "188.60" );
		ht_set( hashtableRX, "1590.41", "188.50" );
		ht_set( hashtableRX, "1591.26", "188.40" );
    	ht_set( hashtableRX, "1592.10", "188.30" );
		ht_set( hashtableRX, "1592.95", "188.30" );
		ht_set( hashtableRX, "1593.79", "188.20" );
		ht_set( hashtableRX, "1594.64", "188.10" );
		ht_set( hashtableRX, "1595.49", "187.90" );
		ht_set( hashtableRX, "1596.34", "187.80" );
		ht_set( hashtableRX, "1597.19", "187.70" );
		ht_set( hashtableRX, "1598.04", "187.60" );
    	ht_set( hashtableRX, "1598.89", "187.50" );
		ht_set( hashtableRX, "1599.75", "187.40" );
		ht_set( hashtableRX, "1600.60", "187.30" );
		ht_set( hashtableRX, "1601.46", "187.20" );
    	ht_set( hashtableRX, "1602.31", "187.10" );
		ht_set( hashtableRX, "1603.17", "187.00" );
		ht_set( hashtableRX, "1604.03", "186.90" );
		ht_set( hashtableRX, "1604.88", "186.80" );
    	ht_set( hashtableRX, "1605.74", "186.70" );
		ht_set( hashtableRX, "1606.60", "186.60" );
		ht_set( hashtableRX, "1607.47", "186.50" );
		ht_set( hashtableRX, "1608.33", "186.40" );
    	ht_set( hashtableRX, "1609.19", "186.30" );
		ht_set( hashtableRX, "1610.06", "186.20" );
		ht_set( hashtableRX, "1569.18", "191.05" );
		ht_set( hashtableRX, "1570.01", "190.95" );
    	ht_set( hashtableRX, "1570.83", "190.85" );
    	ht_set( hashtableRX, "1571.65", "190.75" );
    	ht_set( hashtableRX, "1572.48", "190.65" );
    	ht_set( hashtableRX, "1573.30", "190.55" );
		ht_set( hashtableRX, "1574.13", "190.45" );
    	ht_set( hashtableRX, "1574.95", "190.35" );
    	ht_set( hashtableRX, "1575.78", "190.25" );
    	ht_set( hashtableRX, "1576.61", "190.15" );
    	ht_set( hashtableRX, "1577.44", "190.05" );
    	ht_set( hashtableRX, "1578.27", "189.95" );
    	ht_set( hashtableRX, "1579.10", "189.85" );
    	ht_set( hashtableRX, "1579.93", "189.75" );
    	ht_set( hashtableRX, "1580.77", "189.65" );
    	ht_set( hashtableRX, "1581.60", "189.55" );
    	ht_set( hashtableRX, "1582.44", "189.45" );
    	ht_set( hashtableRX, "1583.27", "189.35" );
    	ht_set( hashtableRX, "1584.11", "189.25" );
    	ht_set( hashtableRX, "1584.95", "189.15" );
    	ht_set( hashtableRX, "1585.78", "189.05" );
    	ht_set( hashtableRX, "1586.62", "188.95" );
    	ht_set( hashtableRX, "1587.46", "188.85" );
    	ht_set( hashtableRX, "1588.30", "188.75" );
    	ht_set( hashtableRX, "1589.15", "188.65" );
    	ht_set( hashtableRX, "1589.99", "188.55" );
    	ht_set( hashtableRX, "1590.83", "188.45" );
    	ht_set( hashtableRX, "1591.68", "188.35" );
    	ht_set( hashtableRX, "1592.52", "188.25" );
    	ht_set( hashtableRX, "1593.37", "188.15" );
    	ht_set( hashtableRX, "1594.22", "188.05" );
		ht_set( hashtableRX, "1595.06", "187.95" );
		ht_set( hashtableRX, "1595.91", "187.85" );
		ht_set( hashtableRX, "1596.76", "187.75" );
		ht_set( hashtableRX, "1597.62", "187.65" );
		ht_set( hashtableRX, "1598.47", "187.55" );
		ht_set( hashtableRX, "1599.32", "187.45" );
		ht_set( hashtableRX, "1600.17", "187.35" );
		ht_set( hashtableRX, "1601.03", "187.25" );
		ht_set( hashtableRX, "1601.88", "187.15" );
		ht_set( hashtableRX, "1602.74", "187.05" );
		ht_set( hashtableRX, "1603.60", "186.95" );
		ht_set( hashtableRX, "1604.46", "186.85" );
		ht_set( hashtableRX, "1605.31", "186.75" );
		ht_set( hashtableRX, "1606.17", "186.65" );
		ht_set( hashtableRX, "1607.04", "186.55" );
		ht_set( hashtableRX, "1607.90", "186.45" );
		ht_set( hashtableRX, "1608.76", "186.35" );
		ht_set( hashtableRX, "1609.62", "186.25" );
		ht_set( hashtableRX, "1610.49", "186.15" );
}
