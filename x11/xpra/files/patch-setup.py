--- setup.py.orig	2013-08-09 15:46:08.000000000 +0000
+++ setup.py	2013-08-23 08:03:02.462925406 +0000
@@ -861,7 +861,7 @@
     scripts = ["scripts/xpra", "scripts/xpra_launcher"]
     man_pages = ["man/xpra.1", "man/xpra_launcher.1"]
     data_files += [
-                    ("share/man/man1", man_pages),
+                    ("man/man1", man_pages),
                     ("share/xpra", ["README", "COPYING"]),
                     ("share/xpra/icons", glob.glob("icons/*")),
                     ("share/applications", ["xdg/xpra_launcher.desktop", "xdg/xpra.desktop"]),
