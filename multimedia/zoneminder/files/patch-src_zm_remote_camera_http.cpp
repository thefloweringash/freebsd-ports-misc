--- src/zm_remote_camera_http.cpp.orig	2014-05-27 00:35:59.734075913 +1200
+++ src/zm_remote_camera_http.cpp	2014-05-27 00:36:14.014075085 +1200
@@ -24,6 +24,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <errno.h>
+#include <unistd.h>
 
 RemoteCameraHttp::RemoteCameraHttp( int p_id, const std::string &p_method, const std::string &p_host, const std::string &p_port, const std::string &p_path, int p_width, int p_height, int p_colours, int p_brightness, int p_contrast, int p_hue, int p_colour, bool p_capture ) :
     RemoteCamera( p_id, "http", p_host, p_port, p_path, p_width, p_height, p_colours, p_brightness, p_contrast, p_hue, p_colour, p_capture )
