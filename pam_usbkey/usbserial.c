#include <stdio.h>
#include <libusb.h>

int main(int argc, char* argv[]) {
	libusb_init(NULL);

	libusb_device** list;
	int n = libusb_get_device_list(NULL, &list);

	int i, match = 0;
	for(i = 0; i < n; i++) {
		struct libusb_device_descriptor desc;
		libusb_device_handle* dev;

		libusb_get_device_descriptor(list[i], &desc);
		if(libusb_open(list[i], &dev)) break;

		char buffer[256] = {0};
		libusb_get_string_descriptor_ascii(dev, 
			desc.iSerialNumber, buffer, 255);
		puts(buffer);

		libusb_close(dev);
	}
	libusb_free_device_list(list, 1);
	libusb_exit(NULL);

	return 0;
}
