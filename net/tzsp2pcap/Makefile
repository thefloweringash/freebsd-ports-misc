# $FreeBSD$

PORTNAME=	tzsp2pcap
PORTVERSION=	0.0.1
CATEGORIES=	net

MAINTAINER=	lorne@cons.org.nz.
COMMENT=	Simple live TaZmen Sniffer Protocol to pcap converter

USE_GITHUB=	yes
GH_ACCOUNT=	thefloweringash
GH_TAGNAME=	f909420ed96211955fdcf283b5ad4821257ac612
GH_COMMIT=	f909420

ALL_TARGET=	tzsp2pcap

PLIST_FILES=	bin/tzsp2pcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tzsp2pcap ${PREFIX}/bin

.include <bsd.port.mk>
