library := rtc

include ../../Makefile.common

all: $(library).o

$(library).o: $(library).c $(library).h
	$(CC) $(API_CFLAGS) -I../../include -c $<

clean:
	$(RM) $(library).o
