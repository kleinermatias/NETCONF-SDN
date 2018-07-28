# Compilacion Modulos - General.

Para iniciar la compilacion, nos situamos en el directorio del modulo y ejecutamos: 

    $ gcc -shared  -fPIC -DPIC  -I. -I/usr/include/yuma/agt -I/usr/include/yuma/ncx -I/usr/include/yuma/platform -I/usr/include/libxml2 -I/usr/include/libxml2/libxml -rdynamic alarma-fulgor.c /usr/lib/libyumancx.so /usr/lib/libyumaagt.so /usr/lib/libxml2.so -lz -ldl -O0 -o alarma-fulgor.so

En la misma carpeta, se genera un archivo con extension .so 

### Automatizacion para la instalacion del modulo en el dispositivo remoto. 

Para facilitar y automatizar la instalacion o desinstalacion de los modulos en el dispositivo, se anexan los siguientes scripts.

**remote_install_module.sh :** Copia el modulo compilado al dispositivo de forma remota. Solicita dos parametros: host - direccion ip del host. 

**remote_clean_module.sh :** Elimina completamente el modulo del dispositivo. Solicita dos parametros: host - direccion ip del host.
