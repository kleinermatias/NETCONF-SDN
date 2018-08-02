#!/bin/bash
# Script for install YUMA.

echo "------- Start install module script... -------"

user=$1

host=$2

module=$3

arch=$4

if test "$#" -ne 4; then
    echo "Illegal number of parameters"
    echo "Example: @user @host @module @arch"
    exit
fi


libmodule=lib$module

if [ "$arch" == "nios2" ]; then
	nios2-linux-gnu-gcc -shared  -fPIC -DPIC  -I. -I../../compile_yuma123/$arch/output/usrapp/include/yuma/agt -I../../compile_yuma123/$arch/output/usrapp/include/yuma/ncx -I../../compile_yuma123/$arch/output/usrapp/include/yuma/platform -I../../compile_yuma123/$arch/output/usrapp/include/libxml2 -I../../compile_yuma123/$arch/output/usrapp/include/libxml2/libxml -rdynamic ../$module/$module.c ../../compile_yuma123/$arch/output/usrapp/lib/libyumancx.so ../../compile_yuma123/$arch/output/usrapp/lib/libyumaagt.so ../../compile_yuma123/$arch/output/usrapp/lib/libxml2.so -lz -ldl -O0 -o ../$module/$libmodule.so
elif [ "$arch" == "arm" ]; then
	gcc -shared  -fPIC -DPIC  -I. -I../../compile_yuma123/$arch/output/usrapp/include/yuma/agt -I../../compile_yuma123/$arch/output/usrapp/include/yuma/ncx -I../../compile_yuma123/$arch/output/usrapp/include/yuma/platform -I../../compile_yuma123/$arch/output/usrapp/include/libxml2 -I../../compile_yuma123/$arch/output/usrapp/include/libxml2/libxml -rdynamic ../$module/$module.c ../../compile_yuma123/$arch/output/usrapp/lib/libyumancx.so ../../compile_yuma123/$arch/output/usrapp/lib/libyumaagt.so ../../compile_yuma123/$arch/output/usrapp/lib/libxml2.so -lz -ldl -O0 -o ../$module/$libmodule.so
elif [ "$arch" == "x86_64" ]; then
	gcc -shared  -fPIC -DPIC  -I. -I../../compile_yuma123/$arch/output/usrapp/include/yuma/agt -I../../compile_yuma123/$arch/output/usrapp/include/yuma/ncx -I../../compile_yuma123/$arch/output/usrapp/include/yuma/platform -I../../compile_yuma123/$arch/output/usrapp/include/libxml2 -I../../compile_yuma123/$arch/output/usrapp/include/libxml2/libxml -rdynamic ../$module/$module.c ../../compile_yuma123/$arch/output/usrapp/lib/libyumancx.so ../../compile_yuma123/$arch/output/usrapp/lib/libyumaagt.so ../../compile_yuma123/$arch/output/usrapp/lib/libxml2.so -lz -ldl -O0 -o ../$module/$libmodule.so
fi

scp -r ../$module/$libmodule.so $user@$host:/root/usrapp/lib/yuma
scp -r ../$module/$module.yang $user@$host:/root/usrapp/share/yuma/modules