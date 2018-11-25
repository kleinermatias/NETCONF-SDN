# NETCONF -  MXP - YUMA123

**REQUIERE INICIAR MONITOR EN EL MXP PREVIAMENTE**

Iniciamos netconfd, especificando que levante desde el inicio el modulo del mxp.

    $ cd ~/usrapp/sbin/
    $ ./netconfd --module=cli-mxp --log-level="debug4" --target=running --superuser=root --with-startup=true
    
Ruta al archivo startup:
/root/.yuma/startup-cfg.xml  

Nos conectamos al servidor NETCONF: 

    $ yangcli --user=root --server=172.16.0.41 --pass=123 --timeout=120

    
## TODO. 

1. Completar las variables faltantes del monitor - Modulo YANG.
2. Completar las variables faltantes del monitor - Aplicacion C.
3. Completar las variables faltantes del monitor - Driver behaviour.
4. Conectar hosts al onos. **(?)**.
5. Desarrollar aplicacion de usuario que muestre informacion del estado de los MXP en una GUI.


## TODO 29/10. 
Se pretende completar las tareas 1, 2 y 3. 


PING:

    $ sudo ping6 -f -I enp1s0f0 2607:f0d0:2001:a::
    
    
    

    NOTA1: Para correr los test:
    $ cd $ONOS_ROOT && tools/build/onos-buck test

    NOTA2: Para compilar y correr el onos localmente (sin docker):
    $ cd $ONOS_ROOT && tools/build/onos-buck run onos-local -- clean debug

    NOTA3: To attach to the ONOS CLI console, run:
    $ cd $ONOS_ROOT && tools/test/bin/onos karaf@localhost

curl -X POST -H "content-type:application/json" http://127.0.0.1:8181/onos/v1/network/configuration -d @/home/mkleiner/Escritorio/NETCONF-SDN/onos/dispositivo.json --user onos:rocks

