#include "serial.h"

#include <libusb.h>

#include <stdio.h>
#include <string.h>

#define LINE_SIZE 1024

int get_serial(const char* user, char* buffer, unsigned int size) {
	FILE* config = fopen("/etc/security/usbkey.conf", "r");

	if(config != NULL) {
		while(feof(config) == 0) {
			char line[LINE_SIZE] = {0};

			fgets(line, LINE_SIZE, config);
			if(strchr(line, '\n'))
				*strchr(line, '\n') = 0;

			char* result = strtok(line, ":");

			if(result && !strcmp(result, user)) {
				if((result = strtok(NULL, "\n"))) {
					strncpy(buffer, result, size);
					return 0;
				}
			}
		}
		fclose(config);
	}
	return -1;
}

int check_serial(const char* serial) {
	libusb_init(NULL);

	libusb_device** list;
	int n = libusb_get_device_list(NULL, &list);

	int i, match = 0;
	for(i = 0; i < n; i++) {
		struct libusb_device_descriptor desc;
		libusb_device_handle* dev;

		if(libusb_get_device_descriptor(list[i], &desc)) break;
		if(libusb_open(list[i], &dev)) break;

		char buffer[256] = {0};
		libusb_get_string_descriptor_ascii(dev, desc.iSerialNumber,
				(unsigned char*) buffer, 255);

		if(strcmp(serial, buffer) == 0)
			match = 1;

		libusb_close(dev);
	}

	libusb_free_device_list(list, 1);
	libusb_exit(NULL);

	return match;
}
