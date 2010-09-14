CC=gcc
CFLAGS=-fPIC
LDFLAGS=-lusb
OUTPUT=pam_usbkey.so usbserial

all: $(OUTPUT)

pam_usbkey.so: pam_usbkey.o serial.o
	ld -x --shared $(LDFLAGS) $^ -o $@

install:
	cp pam_usbkey.so /lib/security/

clean:
	rm -f *.o $(OUTPUT)

.PHONY: all install clean
