# NETCONF -  MXP - YUMA123

Iniciamos netconfd, especificando que levante desde el inicio el modulo del mxp.

    $ cd ~/usrapp/sbin/
    $ ./netconfd --module=cli-mxp --log-level="debug4" --superuser=root
    
Nos conectamos al servidor NETCONF: 

    $ yangcli --user=root --server=172.16.0.41 --pass=123

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
    
    $ create /mux-config/edfa_output_power_config
    $ ENTER VALUE
    
    $ create /mux-config/edfa_output_power_config
    $ ENTER VALUE
