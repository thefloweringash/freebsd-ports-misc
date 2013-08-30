# $FreeBSD$

PORTNAME=	augeas
PORTVERSION=	0.4.1
CATEGORIES=	textproc python
MASTER_SITES=	https://fedorahosted.org/released/python-augeas/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-augeas-${PORTVERSION}

MAINTAINER=	lorne@cons.org.nz
COMMENT=	Pure python bindings for augeas

USE_PYTHON=yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=python-augeas

PLIST_FILES= %%PYTHON_SITELIBDIR%%/augeas.py \
	%%PYTHON_SITELIBDIR%%/augeas.pyc \
	%%PYTHON_SITELIBDIR%%/augeas.pyo

.include <bsd.port.mk>
