# $FreeBSD$

PORTNAME=	augeas
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	https://fedorahosted.org/released/python-augeas/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-augeas-${PORTVERSION}

MAINTAINER=	lorne@cons.org.nz
COMMENT=	Pure python bindings for augeas

LIB_DEPENDS=	libaugeas.so:${PORTSDIR}/textproc/augeas

USES=python
USE_PYTHON=distutils autoplist

.include <bsd.port.mk>
