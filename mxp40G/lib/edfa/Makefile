library := edfa.o hl_edfa.o

include ../../Makefile.common

all: $(library)

$(library): %.o: %.c %.h
	$(CC) $(API_CFLAGS) -I../../include -c $<

clean:
	$(RM) $(library)