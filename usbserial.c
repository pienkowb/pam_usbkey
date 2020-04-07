#include <libusb.h>

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	unsigned char bus, device;

	if(argc < 3 || sscanf(argv[1], "%hhu", &bus) != 1
			|| sscanf(argv[2], "%hhu", &device) != 1)
	{
		puts("usage: usbserial bus_number device_address");
		return 1;
	}

	libusb_init(NULL);

	libusb_device** list;
	int i, n = libusb_get_device_list(NULL, &list);

	for(i = 0; i < n; i++) {
		struct libusb_device_descriptor desc;
		libusb_device_handle* dev;

		if(libusb_get_bus_number(list[i]) != bus)
			continue;
		if(libusb_get_device_address(list[i]) != device)
			continue;

		if(libusb_get_device_descriptor(list[i], &desc)) break;
		if(libusb_open(list[i], &dev)) break;

		char buffer[256] = {0};
		libusb_get_string_descriptor_ascii(dev, desc.iSerialNumber,
				(unsigned char*) buffer, 255);
		puts(buffer);

		libusb_close(dev);
	}

	libusb_free_device_list(list, 1);
	libusb_exit(NULL);

	return 0;
}
