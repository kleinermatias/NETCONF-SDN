#!/bin/bash
# Script for uninstall YUMA.

echo "------- Start uninstall YUMA123 script... -------"

echo 'Introduzca el usuario remoto:'
read user

echo 'Introduzca la direccion del host:'
read host

ssh $user@$host rm -r -f /root/usrapp

echo "------- Done! -------"
