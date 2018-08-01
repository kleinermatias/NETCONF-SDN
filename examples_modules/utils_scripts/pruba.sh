#!/bin/bash
# Script for install YUMA.

echo "------- Start install module script... -------"

echo 'Introduzca el usuario remoto:'
read user

echo 'Introduzca la direccion del host:'
read host

echo 'Modulo a instalar:'
read module

echo 'Introduzca la arquitectura a instalar (nios2 - arm - x86_64):'
read arch

libmodule=lib$module

if [ "$arch" == "nios2" ]; then
	echo "You have access!"
elif [ "$arch" == "arm" ]; then
	echo "ACCESS DENIED!"
elif [ "$arch" == "x86_64" ]; then
	gcc -shared  -fPIC -DPIC  -I. -I../../compile_yuma123/$arch/output/usrapp/include/yuma/agt -I../../compile_yuma123/$arch/output/usrapp/include/yuma/ncx -I../../compile_yuma123/$arch/output/usrapp/include/yuma/platform -I../../compile_yuma123/$arch/output/usrapp/include/libxml2 -I../../compile_yuma123/$arch/output/usrapp/include/libxml2/libxml -rdynamic ../$module/$module.c ../../compile_yuma123/$arch/output/usrapp/lib/libyumancx.so ../../compile_yuma123/$arch/output/usrapp/lib/libyumaagt.so ../../compile_yuma123/$arch/output/usrapp/lib/libxml2.so -lz -ldl -O0 -o ../$module/$libmodule.so
fi