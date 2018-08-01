# Compilacion YUMA123 - General.

Para iniciar la compilacion, nos situamos en el directorio NETCONF-SDN/compile_yuma123/ y ejecutamos 

    $ make all TARGET=$TARGET_ARCH

Ejemplo: 

    $ cd ~/NETCONF-SDN/compile/
    $ make all TARGET=nios2
    $ make all TARGET=arm
    $ make all TARGET=x86_64

Una vez finalizada la construccion de la imagen, dentro del directorio **/NETCONF-SDN/compile/$TARGET_ARCH** se 
encontrara la carpeta **usrapp**.

**usrapp:** Carpeta que contiene los archivos necesarios para ejecutar YUMA en el dispositivo target.

## Pasos para iniciar el servidor yuma (netconfd).

Independientemente de la arquitectura (target), se deben realizar los siguientes pasos:

 1. Iniciar la compilacion: **make all TARGET=$TARGET_ARCH**
 2. Una vez finalizado, copiamos la carpeta **/usrapp** al directorio **/root** del target. 

### Automatizacion. 

Para facilitar y automatizar la instalacion o desinstalacion del agente NETCONF en el dispositivo, se anexan los siguientes scripts (ver carpeta **utils_scripts**).

**remote_install_yuma.sh :** Copia el contenido de la carpeta /usrapp (resultante de la compilacion) al directorio /root/usrapp del dispositivo de forma remota. Solicita tres parametros: host - direccion ip del host - arquitectura.

**remote_clean_yuma.sh :** Elimina completamente la herramienta YUMA del dispositivo. Solicita dos parametros: host - direccion ip del host.

> **NOTA 1**: las herramientas nombradas anteriormente estan preparadas y adaptadas al MUXPONDER (arquitectura NIOS II), copiando unicamente las librerias minimas necesarias para ejecutar YUMA. El peso total del contenido que se instala en el dispositivo es de 20mb.  
