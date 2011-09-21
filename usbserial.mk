PROG=		usbserial
SRCS=		${PROG}.c serial.c
LDADD=		-lusb

NO_MAN=		yes

BINDIR=		${PREFIX}/sbin
#MANDIR=	${PREFIX}/man

.include <bsd.prog.mk>
