--- ./xpra/codecs/memalign/memalign.c.orig	2013-07-26 20:27:21.000000000 +1200
+++ ./xpra/codecs/memalign/memalign.c	2013-08-23 17:08:56.000000000 +1200
@@ -13,7 +13,7 @@
 #ifdef _WIN32
 #define _STDINT_H
 #endif
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
