--- src/ttu.c.orig	2015-08-08 06:08:37 UTC
+++ src/ttu.c
@@ -43,6 +43,8 @@
 #include <ohmic.h>
 #include <ttu.h>
 
+#define EXPORT __attribute__((visibility("default")))
+
 static void *_dlhandle;
 
 static int (*_bind)(int, const struct sockaddr *, socklen_t);
@@ -152,7 +154,7 @@ static char *_find_sockmap(struct ohm_t 
 	return sockfile;
 } /* _find_sockmap() */
 
-int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
+EXPORT int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
 	if(addr->sa_family == AF_INET || addr->sa_family == AF_INET6) {
 		struct sockaddr_in *iaddr = (struct sockaddr_in *) addr;
 		char *sockfile = _find_sockmap(_bindmap, iaddr->sin_addr, htons(iaddr->sin_port));
@@ -174,7 +176,7 @@ int bind(int sockfd, const struct sockad
 	return _bind(sockfd, addr, addrlen);
 } /* bind() */
 
-int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
+EXPORT int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
 	if(addr->sa_family == AF_INET || addr->sa_family == AF_INET6) {
 		struct sockaddr_in *iaddr = (struct sockaddr_in *) addr;
 		char *sockfile = _find_sockmap(_connectmap, iaddr->sin_addr, htons(iaddr->sin_port));
@@ -267,7 +269,7 @@ static void _etohm(struct ohm_t *hm, cha
 } /* _etohm() */
 
 void __attribute__((constructor)) init(void) {
-	_dlhandle = dlopen("libc.so.6", RTLD_LAZY | RTLD_LOCAL);
+	_dlhandle = dlopen("libc.so.7", RTLD_LAZY | RTLD_LOCAL);
 
 	if(!_dlhandle)
 		_bail(dlerror());
