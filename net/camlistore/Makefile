# $FreeBSD$

PORTNAME=	camlistore
PORTVERSION=	0.6
CATEGORIES=	net

MAINTAINER=	lorne@cons.org.nz
COMMENT=	Camlistore is your personal storage system for life

BUILD_DEPENDS=	go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	bradfitz
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	289be26

USE_SQLITE=	3

GO_ENV+=	CC=clang

do-build:
	cd ${WRKSRC} && ${SETENV} ${GO_ENV} go run make.go -v

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}    ${WRKSRC}/bin/README      ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/camlistored ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/camget      ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/camtool     ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/camput      ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/devcam      ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
