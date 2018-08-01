# Only install YUMA123 - General.

> **NOTA**: Esta imagen Docker unicamente instala yuma123 (agente y cliente NETCONF). No es de utilidad para compilar y instalar de forma remota en otro dispositivo.

Iniciamos la construccion de la imagen docker: 

    $ docker build -t fulgor/yuma123 .

Iniciamos el docker: 

    $ docker run -it fulgor/yuma123

El cliente NETCONF de yuma (yangcli) va a conectarse al usuario 'root' y necesita una contraseña para 
el mismo. La contraseña del usuario root es 'fulgor'.

    $ netconfd &
    $ yangcli --user=root --server=localhost --pass=fulgor

