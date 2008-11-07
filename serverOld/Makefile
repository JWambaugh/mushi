all:
	echo "make (unix|msvc)"

clean:
	rm -f mushiServer

./shttpd/libshttpd.a:
	cd ./shttpd && $(MAKE) unix

unix: ./shttpd/libshttpd.a
	$(CC) $(CFLAGS) main.c -I ./shttpd  ./shttpd/libshttpd.a -o mushiServer

WIN32_LIBS= user32.lib shell32.lib ws2_32.lib advapi32.lib .\shttpd\shttpd.lib
CL_FLAGS= /MD /DNDEBUG /nologo /Zi /I ./shttpd

msvc:
	cl $(CL_FLAGS) main.c $(WIN32_LIBS)
