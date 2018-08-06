# NETCONF -  MXP - YUMA123

**REQUIERE INICIAR MONITOR EN EL MXP PREVIAMENTE**

Iniciamos netconfd, especificando que levante desde el inicio el modulo del mxp.

    $ cd ~/usrapp/sbin/
    $ ./netconfd --module=cli-mxp --log-level="debug4" --superuser=root --with-startup=true
    
Nos conectamos al servidor NETCONF: 

    $ yangcli --user=root --server=172.16.0.41 --pass=123 --timeout=120

Unicamente 3 datos de estado por el momento. 


 1. **fpga_temperature_state**
 2. **board_humidity_state**
 3. **edfa_output_power_state**

Para ver los datos de ESTADO, desde yangcli:

    $ xget /mux-state/*
    
Para ver los datos de CONFIGURACION, desde yangcli:

    $ xget /mux-config/*

> **NOTA 1**: Todavia no hay un archivo startup definido, por lo que estos valores de configuracion estan nulos. El xget, no devuelve nada en el inicio. El siguiente paso unicamente es necesario ahora que no hay definido un archivo startup.

Para crear los valores: 

    $ create /mux-config/edfa_output_power_config
    $ ENTER VALUE
    
    $ create /mux-config/tipo_trafico
    $ ENTER VALUE
    
    $ create /mux-config/tipo_fec_linea
    $ ENTER VALUE
    
    $ create /mux-config/tipo_fec_cliente
    $ ENTER VALUE
    
> **NOTA 2**: Desde yang se verifica que por ejemplo, tipo_trafico solo pueda tener valores como otu2 o xge, restringiendo cualquier otra posibilidad para este parametro. (same para tipo_fec_linea, tipo_fec_cliente, etc).


## RPC Disponibles.

Por el momento:

**mux-notify-activate**: Activa las notificaciones si edfa_output_power_config se configura por encima de 5.

**mux-notify-deactivate**: Desactiva las notificaciones, ignorando si edfa_output_power_config se configura por encima de 5.

**mux-apply-config**: RPC que ejecuta el binario "muxponder --configuracion" aplicando los parametros configurados previamente.

**mux-settings**: RPC que ejecuta el binario "settings --potencia $edfa_output_power_config".

Como usarlos? desde yangcli:

    $ mux-notify-activate
    
## TODO. 

1. Conectar a onos.
2. Completar la cli. ?
3. Probar RPC 'mux-apply-config'.
4. Respuestas RPC mas detalladas. 
5. Mas..
