
library := txp_comm

include ../../../Makefile.common

all: $(library).o

$(library).o: $(library).c $(library).h
	$(CC) $(API_CFLAGS) -I../../../include -c $*.c

clean:
	$(RM) $(library).o