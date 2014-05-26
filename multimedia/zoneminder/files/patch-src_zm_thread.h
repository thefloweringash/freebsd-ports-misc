--- src/zm_thread.h.orig	2014-05-27 00:33:29.371086629 +1200
+++ src/zm_thread.h	2014-05-27 00:34:15.674083284 +1200
@@ -21,13 +21,14 @@
 #define ZM_THREAD_H
 
 #include <pthread.h>
+#include <sys/thr.h>
 #include "zm_exception.h"
 #include "zm_utils.h"
 
 class ThreadException : public Exception
 {
 public:
-    ThreadException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)syscall(224) ) )
+    ThreadException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)({ long lwpid; thr_self(&lwpid); lwpid; }) ) )
     {
     }
 };
@@ -200,7 +201,7 @@
 
     pid_t id() const
     {
-        return( (pid_t)syscall(224) );
+        return( (pid_t)({ long lwpid; thr_self(&lwpid); lwpid; }) );
     }
     void exit( int status = 0 )
     {
