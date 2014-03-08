# $FreeBSD$

PORTNAME=	minecraft-rc
PORTVERSION=	0.0.1
CATEGORIES=	net
DISTFILES=	# none

MAINTAINER=	lorne@cons.org.nz
COMMENT=	Minecraft RC script

NO_BUILD=	yes
NO_INSTALL=	yes


RUN_DEPENDS=	tmux:${PORTSDIR}/sysutils/tmux

USE_JAVA=	yes
USE_RC_SUBR=	minecraft
SUB_LIST+=	JAVA=${JAVA}

.include <bsd.port.mk>
