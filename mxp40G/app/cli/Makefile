include ../../Makefile.common
#CC=nios2-linux-gnu-gcc -g
#CXX=nios2-linux-gnu-g++

INCLUDES=			-I$(API_ROOT_DIR)/platform \
                    -I$(API_ROOT_DIR)/T41 \
                    -I../../../ncurses/include \
                    -I../../../readline/include
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
                    -L$(API_ROOT_DIR)/T41/targets/Linux/ \
                    -lm -lreadline -lncurses 
#LIBS=				-lm -lreadline -L/usr/local/lib/  -L$(API_ROOT_DIR)/T41/targets/Linux/   


MODULES=			$(API_ROOT_DIR)/T41/modules

#TARGET=				show config xfi otu2 10ge help cli
TARGET=				show config help cli setdate debugjdsu debugi2c debugt41 logs loopback setrtc cs6041

all:	$(TARGET)

%: %.h %.c
	$(CC) $(INCLUDES) $(INC_MODULES) $@.c  $(LIBS) $(LIB_DIR)xfp/xfp.o $(LIB_DIR)rtc/rtc.o $(LIB_DIR)i2c/i2c.o  $(LIB_DIR)fan/fan.o $(LIB_DIR)qsfp/qsfp.o $(LIB_DIR)hmd/hmd.o $(LIB_DIR)tmp/tmp.o $(LIB_DIR)edfa/edfa.o $(LIB_DIR)txp/txp.o $(LIB_DIR)gpio/gpio.o $(LIB_DIR)ltc/ltc.o  $(LIB_DIR)bitman/bitman.o $(API_ROOT_DIR)/T41/targets/Linux/tenabo.a -o ../../bin/$@
clean:
	rm -rf ../../bin/show ../../bin/config ../../bin/help ../../bin/cli ../../bin/setdate ../../bin/debugjdsu ../../bin/debugi2c ../../bin/debugt41 ../../bin/logs ../../bin/loopback ../../bin/setrtc ../bin/cs6041
