PROG=		usbserial
SRCS=		${PROG}.c serial.c
LDADD=		-lusb

BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man/pl.UTF-8/man

.include <bsd.prog.mk>
