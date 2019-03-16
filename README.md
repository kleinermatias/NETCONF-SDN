# ONOS and NETCONF project.
In this repository you can find the API code in C for the NETCONF server called "YUMA123".

## About this repo.

* [compile_yuma123](https://github.com/ragnar-l/NETCONF-SDN/tree/master/compile_yuma123) - Tools and misc to facilitate the compilation and installation of the YUMA123 server in the different devices.
* [examples_modules](https://github.com/ragnar-l/NETCONF-SDN/tree/master/examples_modules) - API C to manage the configuration of the mxp40gb in YUMA123.
* [mxp40G](https://github.com/ragnar-l/NETCONF-SDN/tree/master/mxp40G) - Headers and libs used by the API in c.
* [onos](https://github.com/ragnar-l/NETCONF-SDN/tree/master/onos) - Northbound API Extension for ONOS controller to communicate with the device driver.
* [python-app](https://github.com/ragnar-l/NETCONF-SDN/tree/master/python-app) - GUI (python web flask + bootstrap).


### Prerequisites

 - Ver cuales son las dependencias de YUMA123 - 

```
Give examples
```

### Installing

1) Compile the NETCONF YUMA123 server for the desired architecture. In [compile_yuma123](https://github.com/ragnar-l/NETCONF-SDN/tree/master/compile_yuma123) you cand find a tutorial for this.
Example for nios2 target:

```
$ cd .../NETCONF-SDN/compile_yuma123/
$ make all TARGET=nios2
```

You must install the previously compiled server on the device. For this, you can use the script for remote installation. All the corresponding files are installed in ~/usrapp in the device.

```
$ cd .../NETCONF-SDN/compile_yuma123/utils_scripts/
$ bash ./remote_install_yuma.sh @user @host @arch
```

2) Now you must install the module (API C) in the device. You can use the script to compile the C module and install it remotely on the device. (Requires having the netconf server compiled in the corresponding architecture). 

```
$ cd .../NETCONF-SDN/examples_modules/utils_scripts/
$ bash ./remote_install_yuma.sh @user @host @module @arch
```

This is all! on the device you must start the server

```
$ cd ~/usrapp/sbin/
$ ./netconfd --module=cli-mxp --log-level="debug4" --target=running --superuser=root --with-startup=true
```

And connect with some netconf client, for example YANGCLI.
```
$ yangcli --user=@user --server=@host --pass=@pass --timeout=@time_out_for_reply
```

## Authors

* **Kleiner Matias** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)
See also the list of [contributors](https://github.com/ragnar-l/NETCONF-SDN/graphs/contributors) who participated in this project.


## TODO. 

| Task | Estimated date |
| ------ | ------ |
| Dar un valor inicial a las variables de NETCONF en startup. | 16/03/2019 |
| ONOS debe borrar tanto las alarmas del device local como las del vecino, si la configuacion es la misma. | 16/03/2019 |
| ONOS debe realizar una sola consulta al dispositivo local sobre el tipo de trafico y comparar con los tipos de traficos de sus vecinos. | 16/03/2019 |
| Se debe corregir el problema de consistencia en las alarmas del mxp40gb. (API C) | -- |
| Realizar SCRIPT y simulacion. | -- |
| Terminar GUI. | -- |
| Documentar. | -- |
| Mover el driver ALTURA a una carpeta separada en ONOS. | -- |
| Mover comportamientos fuera del core de ONOS. | -- |
| Revisar el docker del MXP40gb. | -- |
| Actualizar servidores yuma123. | -- |
| Release en git. | -- |
| Actualizar README en git. | -- |
| Corregir linkDiscovery en ONOS. | -- |
| El mxp40gb debe iniciar el servidor yuma123 y el modulo correspondiente. | -- |

PING:

    $ sudo ping6 -f -I enp1s0f0 2607:f0d0:2001:a::
    
    
    

    NOTA1: Para correr los test:
    $ cd $ONOS_ROOT && tools/build/onos-buck test

    NOTA2: Para compilar y correr el onos localmente (sin docker):
    $ cd $ONOS_ROOT && tools/build/onos-buck run onos-local -- clean debug

    NOTA3: To attach to the ONOS CLI console, run:
    $ cd $ONOS_ROOT && tools/test/bin/onos karaf@localhost

curl -X POST -H "content-type:application/json" http://127.0.0.1:8181/onos/v1/network/configuration -d @/home/mkleiner/Escritorio/NETCONF-SDN/onos/dispositivo.json --user onos:rocks


