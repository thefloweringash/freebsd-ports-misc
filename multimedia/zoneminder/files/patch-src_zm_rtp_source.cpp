--- src/zm_rtp_source.cpp.orig	2014-05-27 00:36:51.146072420 +1200
+++ src/zm_rtp_source.cpp	2014-05-27 00:37:03.801071395 +1200
@@ -23,6 +23,7 @@
 #include "zm_rtp_data.h"
 
 #include <arpa/inet.h>
+#include <unistd.h>
 
 RtpSource::RtpSource( int id, const std::string &localHost, int localPortBase, const std::string &remoteHost, int remotePortBase, uint32_t ssrc, uint16_t seq, uint32_t rtpClock, uint32_t rtpTime ) :
     mId( id ),
