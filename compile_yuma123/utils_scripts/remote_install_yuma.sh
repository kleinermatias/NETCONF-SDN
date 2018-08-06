#!/bin/bash
# Script for install YUMA.

echo "------- Start install YUMA123 script... -------"

echo 'Introduzca el usuario remoto:'
read user

echo 'Introduzca la direccion del host:'
read host

echo 'Introduzca la arquitectura a instalar (nios2 - arm - x86_64):'
read arch

cp -r -f ../$arch/output/usrapp ../$arch/output/tmp

rm -r -f ../$arch/output/tmp/certs
rm -r -f ../$arch/output/tmp/include
rm -r -f ../$arch/output/tmp/misc
rm -r -f ../$arch/output/tmp/private
rm -r -f ../$arch/output/tmp/openssl.cnf

rm -r -f ../$arch/output/tmp/bin/c_rehash
rm -r -f ../$arch/output/tmp/bin/openssl
rm -r -f ../$arch/output/tmp/bin/yangcli
rm -r -f ../$arch/output/tmp/bin/yangdump
rm -r -f ../$arch/output/tmp/bin/yangrpc-example
rm -r -f ../$arch/output/tmp/bin/yangrpc-parse-example

rm -r -f ../$arch/output/tmp/share/aclocal
rm -r -f ../$arch/output/tmp/share/doc
rm -r -f ../$arch/output/tmp/share/gtk-doc
rm -r -f ../$arch/output/tmp/share/info
rm -r -f ../$arch/output/tmp/share/man
rm -r -f ../$arch/output/tmp/share/pkgconfig
rm -r -f ../$arch/output/tmp/share/readline

rm -r -f ../$arch/output/tmp/lib/libhistory.*
rm -r -f ../$arch/output/tmp/lib/libcrypto.*
rm -r -f ../$arch/output/tmp/lib/libssl.*
rm -r -f ../$arch/output/tmp/lib/libreadline.*
rm -r -f ../$arch/output/tmp/lib/libz.*
rm -r -f ../$arch/output/tmp/lib/*.la
rm -r -f ../$arch/output/tmp/lib/*.a
rm -r -f ../$arch/output/tmp/lib/yuma/*.la
rm -r -f ../$arch/output/tmp/lib/yuma/*.a

cp -r -f ./ssh_script.sh ../$arch/output/tmp/
cp -r -f ./sshd_config ../$arch/output/tmp/

scp -r ../$arch/output/tmp $user@$host:/root/usrapp
ssh $user@$host 'tmux new-session -d -s myTempSession bash /root/usrapp/ssh_script.sh'
rm -r -f ../$arch/output/tmp


## etc/sshd
## echo "export PATH=$PATH:/root/usrapp/sbin" >> ~/.bashrc
## . ~/.bashrc



echo "------- Done! -------"
