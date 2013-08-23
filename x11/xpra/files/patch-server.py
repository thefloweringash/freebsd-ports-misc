--- ./xpra/scripts/server.py.orig	2013-07-26 20:27:21.000000000 +1200
+++ ./xpra/scripts/server.py	2013-08-23 17:10:06.000000000 +1200
@@ -9,6 +9,7 @@
 #  http://lists.partiwm.org/pipermail/parti-discuss/2008-September/000042.html
 # (also do not import anything that imports gtk)
 import gobject
+import glib
 import subprocess
 import sys
 import os.path
@@ -451,7 +452,7 @@
         # Now we can safely load gtk and connect:
         assert "gtk" not in sys.modules
         import gtk.gdk          #@Reimport
-        gtk.gdk.threads_init()
+        glib.threads_init()
         display = gtk.gdk.Display(display_name)
         manager = gtk.gdk.display_manager_get()
         default_display = manager.get_default_display()
