LIB=		pam_usbkey
SHLIB_MAJOR=	1
SHLIB_NAME=	${LIB}.so.${SHLIB_MAJOR}
SRCS=		${LIB}.c serial.c
LDADD+=		-lusb

MK_INSTALLLIB=	no
MK_PROFILE=	no

MAN=		${LIB}.8

LIBDIR=		${PREFIX}/lib
MANDIR=		${PREFIX}/man/pl.UTF-8/man

beforeinstall:
	mkdir -p ${DESTDIR}${MANDIR}8

.include <bsd.lib.mk>
