# $FreeBSD$

PORTNAME=	vitamtp
PORTVERSION=	2.0.0
CATEGORIES=	net

MAINTAINER=	lorne@cons.org.nz
COMMENT=	Library to interact with Vita's USB MTP protocol

USE_GITHUB=	yes
GH_ACCOUNT=	yifanlu
GH_PROJECT=	VitaMTP
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	605c209

USES=	pkgconfig pathfix iconv gettext:build

LIB_DEPENDS+=	xml2:${PORTSDIR}/textproc/libxml2

USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--add-missing
ACLOCAL_ARGS=	-I ./m4

PATHFIX_MAKEFILEIN=	Makefile.am

CFLAGS+=	"-I${LOCALBASE}/include"
LIBS+=	"-L${LOCALBASE}/lib"
CONFIGURE_ENV+=	LIBUSB_CFLAGS=" -I/usr/include" LIBUSB_LIBS="-lusb"

post-patch:
	@${TOUCH} ${WRKSRC}/config.rpath
	@${REINPLACE_CMD} -e 's|libusb-1.0/libusb.h|libusb.h|' ${WRKSRC}/src/usb.c

.include <bsd.port.mk>
