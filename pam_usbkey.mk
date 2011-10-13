LIB=		pam_usbkey
SHLIB_MAJOR=	1
SHLIB_NAME=	${LIB}.so.${SHLIB_MAJOR}
SRCS=		${LIB}.c serial.c
LDADD=		-lusb

NO_INSTALLLIB=	yes
NO_PROFILE=	yes

MAN=		${LIB}.8

LIBDIR=		${PREFIX}/lib
MANDIR=		${PREFIX}/man/pl.UTF-8/man

beforeinstall:
	mkdir -p ${MANDIR}8

.include <bsd.lib.mk>
