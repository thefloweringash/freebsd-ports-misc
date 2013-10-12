# $FreeBSD$

PORTNAME=	plexconnect
PORTVERSION=	0.2
CATEGORIES=	multimedia

MAINTAINER=	lorne@cons.org.nz
COMMENT=	Plex client for AppleTV

USE_GITHUB=	yes
GH_ACCOUNT=	iBaa
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	0f08d8a

USE_PYTHON=	2.7

WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-PlexConnect-${GH_COMMIT}

USE_RC_SUBR=	plexconnect
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PORTDOCS=*

USERS=	plexconnect
GROUPS=	plexconnect

post-patch:
	@${REINPLACE_CMD} -e '1s|#!/usr/bin/env python|#!${PYTHON_CMD}|' ${WRKSRC}/*.py

do-build:
	${PYTHON_CMD} ${WRKSRC}/Settings.py

do-install:
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} assets ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/PlexConnect.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ATVSettings.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/DNSServer.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Debug.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Localize.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/PlexGDM.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Settings.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/WebServer.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/XMLConverter.py ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN}  ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/Settings.cfg ${STAGEDIR}${ETCDIR}/Settings.cfg.sample

	${LN} -sf ${ETCDIR}/Settings.cfg ${STAGEDIR}${DATADIR}
	${LN} -sf ${ETCDIR}/ATVSettings.cfg ${STAGEDIR}${DATADIR}

	${LN} -sf /var/log/PlexConnect.log ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
