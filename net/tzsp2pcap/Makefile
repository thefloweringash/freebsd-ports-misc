# $FreeBSD$

PORTNAME=	tzsp2pcap
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	lorne@cons.org.nz.
COMMENT=	Simple live TaZmen Sniffer Protocol to pcap converter

USE_GITHUB=	yes
GH_ACCOUNT=	thefloweringash
GH_TAGNAME=	e2e5d914fd17121f72abca1f65bc03cc416969a6

ALL_TARGET=	tzsp2pcap

PLIST_FILES=	bin/tzsp2pcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tzsp2pcap ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
