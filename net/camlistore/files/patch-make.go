--- make.go.orig	2013-12-26 07:58:46.000000000 +1300
+++ make.go	2014-01-31 02:30:08.747781618 +1300
@@ -210,7 +210,7 @@
 		baseArgs = append(baseArgs, "-race")
 	}
 	baseArgs = append(baseArgs,
-		"--ldflags=-X camlistore.org/pkg/buildinfo.GitInfo "+version,
+		"--ldflags=-extld clang -X camlistore.org/pkg/buildinfo.GitInfo "+version,
 		"--tags="+tags)
 
 	if buildAll {
