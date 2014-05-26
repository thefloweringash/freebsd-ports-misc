--- src/zm_threaddata.cpp.orig	2014-05-27 00:41:16.750054141 +1200
+++ src/zm_threaddata.cpp	2014-05-27 00:41:45.040052019 +1200
@@ -17,6 +17,9 @@
 // Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 // 
 
+template class ThreadData<bool>;
+template class ThreadData<int>;
+
 void neverCalled()
 {
     ThreadData<bool> dummy1;
