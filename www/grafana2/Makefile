# $FreeBSD$

PORTNAME=	grafana2
PORTVERSION=	2.0.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	thomas@bartelmess.io
COMMENT=	Dashboard and graph editor for Graphite, InfluxDB & OpenTSDB

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	grafana

USES=	compiler

OPTIONS_SINGLE=	COMPILE_JSCSS
OPTIONS_SINGLE_COMPILE_JSCSS=	PRECOMPILEDCSSJS COMPILECSSJS
PRECOMPILEDCSSJS_DESC=	Use precompiled assets
COMPILECSSJS_DESC=	Run Javascript and CSS preprocessors locally
OPTIONS_DEFAULT=	PRECOMPILEDCSSJS

USE_GITHUB=	yes
GH_ACCOUNT=	grafana BurntSushi:toml Unknwon:unknwon_com,macaron davecgh:go_spew \
	go-ldap:ldap go-sql-driver:mysql go-xorm:xormcore go-xorm:xorm gosimple:slug \
	jtolds:gls lib:pq macaron-contrib:binding,session mattn:go_sqlite3 \
	rainycape:unidecode smartystreets:goconvey streadway:amqp golang:oauth2,net \
	go-asn1-ber:asn1_ber go-bufio:bufio go-ini:ini go-redis:redis_v2
GH_PROJECT=	grafana toml:toml com:unknwon_com macaron:macaron \
	go-spew:go_spew ldap:ldap mysql:mysql core:xormcore xorm:xorm \
	slug:slug gls:gls pq:pq binding:binding session:session go-sqlite3:go_sqlite3 \
	unidecode:unidecode goconvey:goconvey amqp:amqp oauth2:oauth2 net:net asn1-ber:asn1_ber \
	bufio:bufio ini:ini redis:redis_v2
GH_TAGNAME=	v2.0.2 056c9bc:toml d9bcf40:unknwon_com 93de4f3:macaron \
	2df1748:go_spew 83e6542:ldap 9543750:mysql be6e7ac:xormcore e2889e5:xorm 8d25846:slug f1ac7f4:gls \
	19eeca3:pq 0fbe4b9:binding 31e841d:session e28cd44:go_sqlite3 836ef0a:unidecode fbc0a1c8:goconvey \
	150b7f2:amqp 972f0c5:net c58fcf0:oauth2 9eae18c:asn1_ber 567b2bf:bufio 1772191:ini e617904:redis_v2

GRAFANA_USER?=	grafana
GRAFANA_GROUP?=	grafana

USERS=	${GRAFANA_USER}
GROUPS=	${GRAFANA_GROUP}

GRAFANAHOMEDIR=	${PREFIX}/share/grafana/
GRAFANADATADIR=	${PREFIX}/var/db/grafana/
GRAFANALOGDIR=	${PREFIX}/var/log/grafana/
GRAFANAPIDDIR=	${PREFIX}/var/run/grafana/

SUB_FILES=	grafana grafana.conf
SUB_LIST+=	GRAFANA_USER=${GRAFANA_USER} \
	GRAFANA_GROUP=${GRAFANA_GROUP} \
	GRAFANADATADIR=${GRAFANADATADIR} \
	GRAFANALOGDIR=${GRAFANALOGDIR} \
	GRAFANAPIDDIR=${GRAFANAPIDDIR} \
	GRAFANAHOMEDIR=${GRAFANAHOMEDIR}

PLIST_SUB+=	GRAFANAHOMEDIR=${GRAFANAHOMEDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPRECOMPILEDCSSJS}
MASTER_SITES+=	http://files.bartelmess.io/public/:static_assets
DISTFILES+=	grafana-static-2.0.1.tar.gz:static_assets
.endif

.if ${PORT_OPTIONS:MCOMPILECSSJS}
BUILD_DEPENDS+=	npm>=0:${PORTSDIR}/www/npm
.endif

post-fetch:
	echo "Post-fetch"

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana
.for src in .bra.toml .jscs.json CHANGELOG.md Gruntfile.js README.md build.go docker main.go pkg tasks \
	.gitignore .jsfmtrc CONTRIBUTING.md LICENSE.md appveyor.yml circle.yml docs package.json public tests \
	.hooks .jshintrc Godeps NOTICE.md benchmarks conf latest.json packaging vendor
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/BurntSushi
	@${MKDIR} ${WRKSRC}/src/github.com/Unknwon
	@${MKDIR} ${WRKSRC}/src/github.com/davecgh/go-spew
	@${MKDIR} ${WRKSRC}/src/github.com/go-ldap
	@${MKDIR} ${WRKSRC}/src/github.com/go-sql-driver
	@${MKDIR} ${WRKSRC}/src/github.com/go-xorm
	@${MKDIR} ${WRKSRC}/src/github.com/gosimple
	@${MKDIR} ${WRKSRC}/src/github.com/jtolds
	@${MKDIR} ${WRKSRC}/src/github.com/lib
	@${MKDIR} ${WRKSRC}/src/github.com/macaron-contrib
	@${MKDIR} ${WRKSRC}/src/github.com/mattn
	@${MKDIR} ${WRKSRC}/src/github.com/rainycape
	@${MKDIR} ${WRKSRC}/src/github.com/smartystreets
	@${MKDIR} ${WRKSRC}/src/github.com/streadway
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/gopkg.in
	@${MV} ${WRKSRC_toml} ${WRKSRC}/src/github.com/BurntSushi/toml
	@${MV} ${WRKSRC_unknwon_com} ${WRKSRC}/src/github.com/Unknwon/com
	@${MV} ${WRKSRC_macaron} ${WRKSRC}/src/github.com/Unknwon/macaron
	@${MV} ${WRKSRC_go_spew} ${WRKSRC}/src/github.com/davecgh/go-spew
	@${MV} ${WRKSRC_ldap} ${WRKSRC}/src/github.com/go-ldap/ldap
	@${MV} ${WRKSRC_mysql} ${WRKSRC}/src/github.com/go-sql-driver/mysql
	@${MV} ${WRKSRC_xormcore} ${WRKSRC}/src/github.com/go-xorm/core
	@${MV} ${WRKSRC_xorm} ${WRKSRC}/src/github.com/go-xorm/xorm
	@${MV} ${WRKSRC_slug} ${WRKSRC}/src/github.com/gosimple/slug
	@${MV} ${WRKSRC_gls} ${WRKSRC}/src/github.com/jtolds/gls
	@${MV} ${WRKSRC_pq} ${WRKSRC}/src/github.com/lib/pq
	@${MV} ${WRKSRC_binding} ${WRKSRC}/src/github.com/macaron-contrib/binding/
	@${MV} ${WRKSRC_session} ${WRKSRC}/src/github.com/macaron-contrib/session/
	@${MV} ${WRKSRC_go_sqlite3} ${WRKSRC}/src/github.com/mattn/go-sqlite3
	@${MV} ${WRKSRC_unidecode} ${WRKSRC}/src/github.com/rainycape/unidecode
	@${MV} ${WRKSRC_goconvey} ${WRKSRC}/src/github.com/smartystreets/goconvey
	@${MV} ${WRKSRC_amqp} ${WRKSRC}/src/github.com/streadway/amqp
	@${MV} ${WRKSRC_oauth2} ${WRKSRC}/src/golang.org/x/oauth2
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_asn1_ber} ${WRKSRC}/src/gopkg.in/asn1-ber.v1
	@${MV} ${WRKSRC_bufio} ${WRKSRC}/src/gopkg.in/bufio.v1
	@${MV} ${WRKSRC_ini} ${WRKSRC}/src/gopkg.in/ini.v1
	@${MV} ${WRKSRC_redis_v2} ${WRKSRC}/src/gopkg.in/redis.v2
.if ${PORT_OPTIONS:MPRECOMPILEDCSSJS}
	${RM} -rf ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/public
	${MV} ${WRKDIR}/public  ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|master|${PORTVERSION}|g'\
	 ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/main.go

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o bin/grafana
.if ${PORT_OPTIONS:MCOMPILECSSJS}
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana; npm install
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana; \
	${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/node_modules/grunt-cli/bin/grunt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/bin/grafana \
	${STAGEDIR}${PREFIX}/bin/grafana
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana && \
	${COPYTREE_SHARE} public ${STAGEDIR}${PREFIX}/share/grafana
	${MKDIR} ${STAGEDIR}${GRAFANAPIDDIR}
	${MKDIR} ${STAGEDIR}${GRAFANALOGDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}
	${MKDIR} ${STAGEDIR}${GRAFANADATADIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/conf
	${INSTALL_DATA} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/conf/defaults.ini \
	${STAGEDIR}${GRAFANAHOMEDIR}/conf/defaults.ini
	${INSTALL_DATA} ${WRKDIR}/grafana.conf ${STAGEDIR}${PREFIX}/etc/grafana.conf

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900044 && ${ARCH} == i386
BROKEN=	Does not build
.endif

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
