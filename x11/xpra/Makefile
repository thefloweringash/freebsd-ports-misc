# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpra
PORTVERSION=	0.10.1
CATEGORIES=	x11
MASTER_SITES=	http://xpra.org/src/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Xpra gives you persistent remote applications for X

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython \
	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS= \
	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
	${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
	Xvfb:${PORTSDIR}/x11-servers/xorg-vfbserver \
	xauth:${PORTSDIR}/x11/xauth \
	setxkbmap:${PORTSDIR}/x11/setxkbmap \
	pulseaudio:${PORTSDIR}/audio/pulseaudio
LIB_DEPENDS= x264:${PORTSDIR}/multimedia/x264 \
	avcodec1:${PORTSDIR}/multimedia/ffmpeg1 \
	vpx:${PORTSDIR}/multimedia/libvpx

MANCOMPRESSED=	no
MAN1=		xpra.1 xpra_launcher.1

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_XORG=	x11 xtst xfixes xcomposite xdamage xrandr

USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	xpra_all

NO_STAGE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/xpra/Xvfb/xpra.conf ${ETCDIR}/xpra.conf.sample
	if [ ! -f ${ETCDIR}/xpra.conf ]; then \
		${CP} -p ${ETCDIR}/xpra.conf.sample ${ETCDIR}/xpra.conf; \
	fi

.include <bsd.port.mk>
