#!/bin/bash
# Script for install YUMA.

echo "------- Copy sshd_config -------"

#Copio el archivo sshd_config que se encuentra en la carpeta NETCONF-SDN/compile_yuma123/utils_scripts/
cp -r -f /root/usrapp/sshd_config /etc/ssh/

echo "------- Restart ssh server -------"

#Reinicio el servicio ssh
/etc/init.d/S50sshd restart

#Ejecuto los scripts
sh /root/init_bridge_tx.sh
sh /root/init_bridge_rx.sh

echo "------- EXPORT PATH -------"


echo "export PATH=$PATH:/root/usrapp/sbin" >> ~/.bashrc
. ~/.bashrc

echo "------- DONE! -------"
