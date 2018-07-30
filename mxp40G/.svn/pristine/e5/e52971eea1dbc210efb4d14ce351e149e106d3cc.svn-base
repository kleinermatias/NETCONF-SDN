SRC=logger
TEST_FILE=test_logger_log

include ../../Makefile.common

CXX=g++

API_ROOT_DIR:=../../lib/CS6041_Release_5.13
INCLUDES:=-I $(API_ROOT_DIR)/platform -I $(API_ROOT_DIR)/T41
MODULES:=$(API_ROOT_DIR)/T41/modules
INC=general stats mpif irq fec glb gpllx1 fracdiv hsif pp10g n40g n10g xcon pp40g ohpp syncdsync highlevel hl_config debug dm
INC_MODULES=$(foreach d, $(INC), -I$(MODULES)/$(d))
INC_TEST=-I$(GTEST_DIR)/include/

LIBS=-lpthread
TEN_LIBPATH=-L $(API_ROOT_DIR)/T41/targets/Linux
LIBTENABO=$(API_ROOT_DIR)/T41/targets/Linux/tenabo.a
TEST_LIBS=$(GTEST_DIR)/src/gtest-all.o $(GTEST_DIR)/libgtest.a
API_LIBS=../../lib/bitman/bitman.o parser.o ini.o
MOKED_API_LIBS= ../../lib/i2c/i2c.o ../../lib/tmp/tmp.o ../../lib/hmd/hmd.o ../../lib/gpio/gpio.o ../../lib/ltc/ltc.o ../../lib/xfp/xfp.o ../../lib/qsfp/qsfp.o ../../lib/txp/txp.o

all: clean
	$(MAKE) -C ../../lib/bitman
	$(CC) ../../include/ini.c -o ini.o -c
	$(CC) parser.c -I../../include -o parser.o -c
	$(CC) $(INCLUDES) $(INC_MODULES) -I../../include $(SRC).c -o $(SRC).o -c
	$(CC) mond.c -o mond.o -c
	$(CC) mond.o $(SRC).o $(TEN_LIBPATH) $(LIBTENABO) $(API_LIBS) $(MOKED_API_LIBS) -lm -o ../../bin/mond

test: clean
	$(MAKE) -C ../../lib/bitman
	$(CC) ../../include/ini.c -o ini.o -c
	$(CC) parser.c -I../../include -o parser.o -c
	$(CC) $(INCLUDES) $(INC_MODULES) -I../../include $(SRC).c -o $(SRC).o -c -DTESTING
	$(CC) $(INC_TEST) $(TEST_FILE).cpp -o $(TEST_FILE).o -c
	$(CXX) $(TEST_FILE).o $(SRC).o $(TEN_LIBPATH) $(LIBTENABO) $(TEST_LIBS) $(API_LIBS) -o $(TEST_FILE) $(LIBS)

test1: clean parser.o $(SRC).o $(TEST_FILE).o
	$(CXX) $(TEST_FILE).o $(SRC).o $(TEN_LIBPATH) $(LIBTENABO) $(TEST_LIBS) $(API_LIBS) -o $(TEST_FILE) $(LIBS)

$(SRC).o: $(SRC).c $(SRC).h
	$(CC) $(INCLUDES) $(INC_MODULES) -c -DTESTING $<

$(TEST_FILE).o: $(TEST_FILE).cpp
	$(CC) $(INC_TEST) -c $<

parser.o: parser.c
	$(CC) -I../../include -c $<

clean:
	rm -f ../../bin/mond ../../bin/mond.conf mond.o $(TEST_FILE) $(TEST_FILE).o $(SRC) $(SRC).o $(API_LIBS)

run: 
	./$(TEST_FILE) > $(TEST_FILE).rpt 2>&1

# Todas las dependencias que incluyamos en el objetivo .PHONY obviarán la presencia de un fichero que coincida con su nombre
.PHONY : clean
