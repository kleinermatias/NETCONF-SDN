#!/bin/bash
# Script for install YUMA.

echo "------- Copy sshd_config -------"

cp -r -f /root/usrapp/sshd_config /etc/ssh/

echo "------- Restart ssh server -------"

/etc/init.d/S50sshd restart

sh /root/init_bridge_tx.sh
sh /root/init_bridge_rx.sh

echo "------- EXPORT PATH -------"

echo "export PATH=$PATH:/root/usrapp/sbin" >> ~/.bashrc
. ~/.bashrc

echo "------- DONE! -------"
