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
@@ -909,7 +909,11 @@
             if not use_Xdummy_wrapper and "scripts/xpra_Xdummy" in scripts:
                 #if we're not using the wrapper, don't install it
                 scripts.remove("scripts/xpra_Xdummy")
-            etc_files.append(xorg_conf)
+            ## FreeBSD ports: we want to install this as xpra.conf.sample
+            ## Prevent it here, handle in post-install target
+            #etc_files.append(xorg_conf)
+            ## FreeBSD ports: override etc_prefix
+            etc_prefix='etc/xpra'
         data_files.append((etc_prefix, etc_files))
     setup_options["scripts"] = scripts
 
@@ -1020,7 +1024,7 @@
 toggle_packages(dec_avcodec_ENABLED, "xpra.codecs.dec_avcodec")
 if dec_avcodec_ENABLED:
     make_constants("xpra", "codecs", "dec_avcodec", "constants")
-    avcodec_pkgconfig = pkgconfig("libavcodec")
+    avcodec_pkgconfig = pkgconfig("libavcodec1")
     cython_add(Extension("xpra.codecs.dec_avcodec.decoder",
                 ["xpra/codecs/dec_avcodec/decoder.pyx", "xpra/codecs/dec_avcodec/dec_avcodec.c", "xpra/codecs/memalign/memalign.c"],
                 **avcodec_pkgconfig), min_version=(0, 19))
@@ -1028,7 +1032,7 @@
 toggle_packages(csc_swscale_ENABLED, "xpra.codecs.csc_swscale")
 if csc_swscale_ENABLED:
     make_constants("xpra", "codecs", "csc_swscale", "constants")
-    swscale_pkgconfig = pkgconfig("libswscale")
+    swscale_pkgconfig = pkgconfig("libswscale1")
     cython_add(Extension("xpra.codecs.csc_swscale.colorspace_converter",
                 ["xpra/codecs/csc_swscale/colorspace_converter.pyx", "xpra/codecs/csc_swscale/csc_swscale.c", "xpra/codecs/memalign/memalign.c"],
                 **swscale_pkgconfig), min_version=(0, 19))
