include ../../Makefile.common
#CC=nios2-linux-gnu-gcc -g
#CXX=nios2-linux-gnu-g++


gcc -shared  -fPIC -DPIC  -I. -I/home/mkleiner/mxp40G/lib/fan \
-I/home/mkleiner/mxp40G/lib/hl_configs \
-I/home/mkleiner/mxp40G/lib/utils \
-I/home/mkleiner/mxp40G/lib/cs6041 \
-I/home/mkleiner/mxp40G/lib/xfp \
-I/home/mkleiner/mxp40G/lib/txp \
-I/home/mkleiner/mxp40G/lib/edfa \
-I/home/mkleiner/mxp40G/lib/rtc \
-I/home/mkleiner/mxp40G/lib/fan \
-I/home/mkleiner/mxp40G/lib/qsfp \
-I/home/mkleiner/mxp40G/lib/gpio \
-I/home/mkleiner/mxp40G/lib/tmp \
-I/home/mkleiner/mxp40G/lib/power_supply \
-I/home/mkleiner/mxp40G/lib/hmd \
-I/home/mkleiner/mxp40G/lib/i2c \
-I/home/mkleiner/mxp40G/lib/ltc \
-I/home/mkleiner/mxp40G/lib/led \
-I/home/mkleiner/mxp40G/lib/CS6041_Release_5.13/T41/modules/general/tenabo40.h \
-I/usr/include/yuma/agt -I/usr/include/yuma/ncx -I/usr/include/yuma/platform -I/usr/include/libxml2 -I/usr/include/libxml2/libxml \
-rdynamic cli-mxp.c /usr/lib/libyumancx.so /usr/lib/libyumaagt.so /usr/lib/x86_64-linux-gnu/libxml2.so -lz -ldl -O0 -o libcli-mxp.so


INCLUDES=			-I$(API_ROOT_DIR)/platform \
                    -I$(API_ROOT_DIR)/T41 \
                    -I../../../ncurses/include \
                    -I../../../aardvark/c \
                    -I../../../readline/include \
                    -I../../lib/hl_configs \
                    -I../../lib/utils \
                    -I../../lib/cs6041 \
                    -I../../lib/xfp \
                    -I../../lib/txp \
                    -I../../lib/edfa \
                    -I../../lib/rtc \
                    -I../../lib/fan \
                    -I../../lib/qsfp \
                    -I../../lib/gpio \
                    -I../../lib/tmp \
                    -I../../lib/power_supply \
                    -I../../lib/hmd \
                    -I../../lib/i2c \
                    -I../../lib/ltc \
                    -I../../lib/led \
                    -I../../include \
                    -I../../lib/logging
#INCLUDES=			-I$(API_ROOT_DIR)/platform -I$(API_ROOT_DIR)/T41 -I/usr/local/include/
INC=				general \
					stats \
                    mpif \
                    irq \
                    fec \
                    glb \
                    gpllx1 \
                    fracdiv \
                    hsif \
                    pp10g \
                    n40g \
                    n10g \
                    xcon \
                    pp40g \
                    ohpp \
                    syncdsync \
                    highlevel \
                    hl_config \
                    debug \
                    dm
INC_MODULES=		$(foreach d, $(INC), -I$(MODULES)/$(d))

API_ROOT_DIR=		$(LIB_DIR)CS6041_Release_5.13
LIB_DIR=            ../../lib/
LIBS=               -L../../../ncurses/lib \
                    -L../../../readline/lib \
                    -L../../../aardvark/c/_output \
                    -L$(API_ROOT_DIR)/T41/targets/Linux/ \
                    -lm -lrt -lpthread
#LIBS=				-lm -lreadline -L/usr/local/lib/  -L$(API_ROOT_DIR)/T41/targets/Linux/   

MODULES=			$(API_ROOT_DIR)/T41/modules

#TARGET=				traffic muxponder transponder monitor settings shmposix ff_muxponder_01

TARGET=				traffic muxponder transponder monitor loopback settings #test

all:	$(TARGET)

%: %.h %.c
	$(CC) $(INCLUDES) $(INC_MODULES) $@.c  $(LIBS) $(LIB_DIR)logging/logging.o $(LIB_DIR)xfp/xfp.o $(LIB_DIR)xfp/hl_xfp.o $(LIB_DIR)clk/clk.o $(LIB_DIR)rtc/rtc.o $(LIB_DIR)i2c/i2c.o  $(LIB_DIR)fan/fan.o $(LIB_DIR)qsfp/qsfp.o $(LIB_DIR)hmd/hmd.o $(LIB_DIR)tmp/tmp.o $(LIB_DIR)txp/txp.o $(LIB_DIR)txp/hl_txp.o $(LIB_DIR)silabs/silabs.o $(LIB_DIR)power_supply/power_supply.o $(LIB_DIR)edfa/edfa.o $(LIB_DIR)edfa/hl_edfa.o $(LIB_DIR)gpio/gpio.o $(LIB_DIR)ltc/ltc.o $(LIB_DIR)led/led.o $(LIB_DIR)bitman/bitman.o $(LIB_DIR)cs6041/cs6041.o $(LIB_DIR)util/util.o $(LIB_DIR)utils/utils.o $(LIB_DIR)utils/filelock.o $(LIB_DIR)hl_configs/hl_configs.o $(API_ROOT_DIR)/T41/targets/Linux/tenabo.a $(LIB_DIR)mxml-2.9/libmxml.a -o ../../bin/$@
clean:
	rm -rf 
