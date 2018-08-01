# Only install YUMA123 - General.

> **NOTA**: Esta imagen Docker unicamente instala yuma123 (agente y cliente NETCONF). No es de utilidad para compilar y instalar de forma remota en otro dispositivo.

Iniciamos la construccion de la imagen docker: 

    $ docker build -t fulgor/yuma123 .

Iniciamos el docker: 

    $ docker run -it fulgor/yuma123

El cliente Netconf de yuma (yangcli) va a conectarse al usuario 'root' y necesita una contraseña para 
el mismo. Para ello, ejecutamos los siguientes comandos:

    $ passwd $PASS
    $ /etc/init.d/ssh restart
    $ netconfd &
    $ yangcli --user=root --server=localhost --pass=$PASS

