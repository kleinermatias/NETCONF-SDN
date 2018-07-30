library := txp.o hl_txp.o

include ../../Makefile.common

all: $(library)

$(library): %.o: %.c %.h
	$(CC) $(API_CFLAGS) -I../../include -c $<

clean:
	$(RM) $(library)