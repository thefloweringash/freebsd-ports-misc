--- src/zm_timer.h.orig	2014-05-27 00:35:01.810079928 +1200
+++ src/zm_timer.h	2014-05-27 00:35:10.754078990 +1200
@@ -30,7 +30,7 @@
     class TimerException : public Exception
     {
     public:
-        TimerException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)syscall(224) ) )
+        TimerException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)({ long lwpid; thr_self(&lwpid); lwpid; }) ) )
         {
         }
     };
