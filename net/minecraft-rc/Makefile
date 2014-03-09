# $FreeBSD$

PORTNAME=	minecraft-rc
PORTVERSION=	0.0.3
CATEGORIES=	net games java
DISTFILES=	# none

MAINTAINER=	lorne@cons.org.nz
COMMENT=	Minecraft RC script

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	tmux:${PORTSDIR}/sysutils/tmux

NO_BUILD=	yes
NO_INSTALL=	yes

USE_JAVA=	yes
USE_RC_SUBR=	minecraft
SUB_FILES+=	minecraft.8
SUB_LIST+=	JAVA=${JAVA}

PLIST_FILES+=	man/man8/minecraft.8.gz

do-install:
	${INSTALL_MAN} ${WRKDIR}/minecraft.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
