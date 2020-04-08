MKOBJDIRS=auto

.include <auto.obj.mk>

default:
	@${MAKE} -C ${.CURDIR} -f pam_usbkey.mk
	@${MAKE} -C ${.CURDIR} -f usbserial.mk

.DEFAULT:
	@${MAKE} -C ${.CURDIR} -f pam_usbkey.mk $@
	@${MAKE} -C ${.CURDIR} -f usbserial.mk $@

.PHONY: default
