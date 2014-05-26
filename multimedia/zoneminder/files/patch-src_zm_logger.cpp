--- src/zm_logger.cpp.orig	2011-06-28 23:07:35.000000000 +1200
+++ src/zm_logger.cpp	2014-05-27 00:42:23.057049557 +1200
@@ -33,6 +33,8 @@
 #include <signal.h>
 #include <stdarg.h>
 #include <errno.h>
+#include <unistd.h>
+#include <sys/thr.h>
 
 bool Logger::smInitialised = false;
 Logger *Logger::smInstance = 0;
@@ -515,8 +517,12 @@
     #endif
 
         pid_t tid;
+	long lwpid;
+	thr_self(&lwpid);
+	tid = lwpid;
+
 #ifdef HAVE_SYSCALL
-        if ( (tid = syscall(SYS_gettid)) < 0 ) // Thread/Process id
+        if (tid < 0 ) // Thread/Process id
 #endif // HAVE_SYSCALL
         tid = getpid(); // Process id
 
