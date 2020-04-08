PROG=		usbserial
SRCS=		${PROG}.c serial.c
LDADD=		-lusb

BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man/pl.UTF-8/man

beforeinstall:
	mkdir -p ${DESTDIR}${MANDIR}1

.include <bsd.prog.mk>
