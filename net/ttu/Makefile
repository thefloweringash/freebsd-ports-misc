# Created by: Andrew Childs <lorne@cons.org.nz>
# $FreeBSD$

PORTNAME=	ttu
PORTVERSION=	20150808
CATEGORIES=	net

MAINTAINER=	lorne@cons.org.nz
COMMENT=	Small tool that silently converts TCP sockets to Unix sockets

USE_GITHUB=	yes
GH_ACCOUNT=	cyphar
GH_TAGNAME=	cab33b

USES=	gmake

MAKE_ENV+=	\
	IDLIB=${STAGEDIR}/${PREFIX}/lib \
	IDBIN=${STAGEDIR}/${PREFIX}/bin


PLIST_FILES=	\
	lib/libttu.so \
	bin/ttu

.include <bsd.port.mk>
