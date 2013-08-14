# $FreeBSD$

PORTNAME=	plexconnect
PORTVERSION=	20130814
CATEGORIES=	multimedia

MAINTAINER=	lorne@cons.org.nz
COMMENT=	Plex client for AppleTV

USE_GITHUB=	yes
GH_ACCOUNT=	iBaa
GH_TAGNAME=	357655614faf7b7fd5dac6c0b8a64b6919e93eac
GH_COMMIT=	3576556

USE_PYTHON=	2.7

WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-PlexConnect-${GH_COMMIT}

PORTDOCS=README.md

USE_RC_SUBR=	plexconnect
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

USERS=	plexconnect
GROUPS=	plexconnect

post-patch:
	@${REINPLACE_CMD} -e '1s|#!/usr/bin/env python|#!${PYTHON_CMD}|' ${WRKSRC}/*.py

do-build:
	${PYTHON_CMD} ${WRKSRC}/Settings.py

do-install:
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} assets ${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/PlexConnect.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ATVSettings.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/DNSServer.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Debug.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/PlexGDM.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Settings.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/WebServer.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/XMLConverter.py ${DATADIR}

	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN}  ${WRKSRC}/README.md ${DOCSDIR}

	${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/Settings.cfg ${ETCDIR}/Settings.cfg.sample
	${LN} -sf ${ETCDIR}/Settings.cfg ${DATADIR}
	${INSTALL} -m 644 -o plexconnect -g plexconnect /dev/null ${ETCDIR}/ATVSettings.cfg.sample
	${LN} -sf ${ETCDIR}/ATVSettings.cfg ${DATADIR}

	${LN} -sf /var/log/PlexConnect.log ${DATADIR}

	@if [ ! -f ${ETCDIR}/Settings.cfg ]; then \
		${CP} -p ${ETCDIR}/Settings.cfg.sample ${ETCDIR}/Settings.cfg; \
	fi
	@if [ ! -f ${ETCDIR}/ATVSettings.cfg ]; then \
		${CP} -p ${ETCDIR}/ATVSettings.cfg.sample ${ETCDIR}/ATVSettings.cfg; \
	fi

.include <bsd.port.mk>
