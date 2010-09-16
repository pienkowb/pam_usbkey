CC=gcc
CFLAGS=-fPIC
LDFLAGS=-lusb

OUTPUT=pam_usbkey.so usbserial
OBJECTS=pam_usbkey.o serial.o

all: $(OUTPUT)

pam_usbkey.so: $(OBJECTS)
	ld -x --shared $(LDFLAGS) $(OBJECTS) -o $@

install:
	cp pam_usbkey.so /lib/security/

clean:
	rm -f *.o $(OUTPUT)

.PHONY: all install clean
