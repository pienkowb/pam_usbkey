default:
	@${MAKE} -f pam_usbkey.mk
	@${MAKE} -f usbserial.mk

.DEFAULT:
	@${MAKE} -f pam_usbkey.mk $@
	@${MAKE} -f usbserial.mk $@

.PHONY: default
