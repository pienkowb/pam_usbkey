# Linux PAM 

wget http://www.kernel.org/pub/linux/libs/pam/library/Linux-PAM-1.1.1.tar.bz2
tar xf Linux-PAM-1.1.1.tar.bz2 2> /dev/null

cp -r Linux-PAM-1.1.1/libpam/include/security /usr/include/

rm -r Linux-PAM-1.1.1*


# libusb

wget http://sourceforge.net/projects/libusb/files/libusb-1.0/libusb-1.0.8/libusb-1.0.8.tar.bz2/download
tar xf libusb-1.0.8.tar.bz2 2> /dev/null

cd libusb-1.0.8
./configure --prefix=/usr
make
make install
cd ..

mv /usr/include/libusb-1.0/libusb.h /usr/include/
ln -s /usr/lib/libusb-1.0.so /usr/lib/libusb.so

rm -r libusb-1.0.8*
