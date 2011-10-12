LIB=		pam_usbkey
SHLIB_MAJOR=	1
SHLIB_NAME=	${LIB}.so.${SHLIB_MAJOR}
SRCS=		${LIB}.c serial.c
LDADD=		-lusb

MAN=		${LIB}.8

LIBDIR=		${PREFIX}/lib
MANDIR=		${PREFIX}/man/pl.UTF-8/man

.include <bsd.lib.mk>
