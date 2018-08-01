#!/bin/bash
# Script for install YUMA.

echo "------- Copy sshd_config -------"

cp -r -f /root/usrapp/sshd_config /etc/ssh/sshd_config

echo "------- Restart ssh server -------"

# REINICIAR SSHD!

sh init_bridge_tx.sh
sh init_bridge_rx.sh


