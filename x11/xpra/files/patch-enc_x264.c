--- ./xpra/codecs/enc_x264/enc_x264.c.orig	2013-08-06 21:11:22.000000000 +1200
+++ ./xpra/codecs/enc_x264/enc_x264.c	2013-08-23 17:08:56.000000000 +1200
@@ -17,7 +17,7 @@
 #ifdef _WIN32
 #define _STDINT_H
 #endif
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
