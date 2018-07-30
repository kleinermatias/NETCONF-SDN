#!/bin/bash

# PATHS
BUILD_OUTPUT="~/workspace/mxp_head/lib/net-snmp-5.7.3"
#BUILD_SNMP_FOLDER=${BUILD_OUTPUT}"/mxp/app/snmp"
BUILD_SNMP_FOLDER=${BUILD_OUTPUT}"/mnt/app/snmp"

# Path in Muxponder board when 'snmp' folder will be copied.
# 'snmp' folder will contain agent with its config files
#BOARD_SNMP="/mxp/app"
BOARD_SNMP="/mnt/app"

# IP for Muxponder board
BOARD_IP=172.16.0.42

# User that connects to Muxponder board.
# By now we only support root user (ene2017)
BOARD_USER="root"

# Cross-compile net-snmp agent and send output files to muxponder board
pwd
./configure --host=nios2-linux-gnu --prefix=/mnt/app/snmp --with-cc=nios2-linux-gnu-gcc  --disable-manuals --with-endianness=little --with-cflags=-lrt --with-ldflags=-elf2flt --disable-embedded-perl --without-perl-modules --enable-mini-agent --with-defaults --with-default-snmp-version=2 --without-openssl --with-out-mib-modules=example/ucdDemoPublic --without-kmem-usage --disable-applications --with-mibdirs= --with-mibs= --disable-mib-loading --disable-mibs --with-mib-modules="edfaSeverityTable txpSeverityTable xfp1SeverityTable xfp2SeverityTable xfp3SeverityTable xfp4SeverityTable tpLineSeverityTable tpClient1SeverityTable tpClient2SeverityTable tpClient3SeverityTable tpClient4SeverityTable edfaTable fanTable mxpEnvTable powerTable txpAlrmRxTable txpAlrmTxTable txpBandTable txpChannelTable txpDSPCompensationTable txpDSPErrorsTable txpDSPStatusTable txpPhyspadTable txpPowerTable txpPowSupplyAlrmTable txpTempTable xfp1Table xfp2Table xfp3Table xfp4Table trafficProcessorTable FTNC-MIB/notifications/ftnc_notifications "
#./configure --host=nios2-linux-gnu --prefix=/mxp/app/snmp --with-cc=nios2-linux-gnu-gcc  --disable-manuals --with-endianness=little --with-cflags=-lrt --with-ldflags=-elf2flt --disable-embedded-perl --without-perl-modules --enable-mini-agent --with-defaults --with-default-snmp-version=2 --without-openssl --with-out-mib-modules=example/ucdDemoPublic --without-kmem-usage --disable-applications --with-mibdirs= --with-mibs= --disable-mib-loading --disable-mibs --with-mib-modules="edfaSeverityTable txpSeverityTable xfp1SeverityTable xfp2SeverityTable xfp3SeverityTable xfp4SeverityTable tpLineSeverityTable tpClient1SeverityTable tpClient2SeverityTable tpClient3SeverityTable tpClient4SeverityTable edfaTable fanTable mxpEnvTable powerTable txpAlrmRxTable txpAlrmTxTable txpBandTable txpChannelTable txpDSPCompensationTable txpDSPErrorsTable txpDSPStatusTable txpPhyspadTable txpPowerTable txpPowSupplyAlrmTable txpTempTable xfp1Table xfp2Table xfp3Table xfp4Table trafficProcessorTable FTNC-MIB/notifications/ftnc_notifications "
make
make install DESTDIR=~/workspace/mxp_head/lib/net-snmp-5.7.3
#make install DESTDIR=$(BUILD_OUTPUT)

# add mibs files to agent (this files will be sent to the board)
#cp -r mibs/ mxp/app/snmp/share/snmp/
cp -r mibs/ mnt/app/snmp/share/snmp/

echo "Send agent files to board"
#scp -r ~/workspace/mxp_head/lib/net-snmp-5.7.3/mxp/app/snmp root@172.16.0.41:/mxp/app
#scp -r ${BUILD_SNMP_FOLDER} ${BOARD_USER}@${BOARD_IP}:${BOARD_SNMP}

echo "scp -r "${BUILD_SNMP_FOLDER}" "${BOARD_USER}"@"${BOARD_IP}":"${BOARD_SNMP}
eval "scp -r "${BUILD_SNMP_FOLDER}" "${BOARD_USER}"@"${BOARD_IP}":"${BOARD_SNMP}

echo "NET-SNMP agent loaded in Muxponder"
