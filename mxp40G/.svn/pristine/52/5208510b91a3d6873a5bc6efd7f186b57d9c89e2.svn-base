library := cs6041

CHIP            =    TENABO
CHIPROOT        =    $(shell cd ../CS6041_Release_5.13/T41; pwd)
include $(CHIPROOT)/Makefile.common

include ../../Makefile.common

all: $(library).o

$(library).o: $(library).c $(library).h
	$(CC) $(API_CFLAGS) $(INC) -c $<

clean:
	$(RM) $(library).o
