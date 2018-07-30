SRC=hwcheck

include ../../Makefile.common

API_ROOT_DIR:=../../lib/CS6041_Release_5.13
INCLUDES:=-I $(API_ROOT_DIR)/platform -I $(API_ROOT_DIR)/T41
MODULES:=$(API_ROOT_DIR)/T41/modules
INC=general stats mpif irq fec glb gpllx1 fracdiv hsif pp10g n40g n10g xcon pp40g ohpp syncdsync highlevel hl_config debug dm
INC_MODULES=$(foreach d, $(INC), -I$(MODULES)/$(d))

TEN_LIBPATH=-L $(API_ROOT_DIR)/T41/targets/Linux
LIBTENABO=$(API_ROOT_DIR)/T41/targets/Linux/tenabo.a

API_LIBS=../../lib/bitman/bitman.o ../../lib/i2c/i2c.o ../../lib/tmp/tmp.o ../../lib/hmd/hmd.o ../../lib/gpio/gpio.o ../../lib/ltc/ltc.o ../../lib/xfp/xfp.o ../../lib/qsfp/qsfp.o ../../lib/txp/txp.o ../../lib/clk/clk.o ../../lib/edfa/edfa.o ../../lib/led/led.o

all:
	$(CC) $(INCLUDES) $(INC_MODULES) -I../../include $(SRC).c -o $(SRC).o -c
	$(CC) $(SRC).o $(TEN_LIBPATH) $(LIBTENABO) $(API_LIBS) -lm -o ../../bin/$(SRC)

clean:
	rm -f $(SRC).o ../../bin/$(SRC)
