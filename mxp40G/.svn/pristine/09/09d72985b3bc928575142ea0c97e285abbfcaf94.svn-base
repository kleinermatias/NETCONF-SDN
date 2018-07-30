library := i2c

include ../../Makefile.common

all: $(library).o

$(library).o: i2cbusses.c i2crw.c i2cbusses.h i2crw.h $(library).c $(library).h
	$(CC) $(API_CFLAGS) -I../../include -c $*.c

#%.o: %.c %.h
#	$(CC) $(API_CFLAGS) -I../../include -c $*.c

clean:
	$(RM) i2crw.o i2cbusses.o $(library).o
