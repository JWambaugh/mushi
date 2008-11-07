/*
 * This file is an example of how to embed web-server functionality
 * into existing application.
 * Compilation line:
 * cc example.c shttpd.c -DEMBEDDED
 */

#ifdef _WIN32
#include <winsock.h>
#define	snprintf			_snprintf

#ifndef _WIN32_WCE
#ifdef _MSC_VER /* pragmas not valid on MinGW */
#endif /* _MSC_VER */

#else /* _WIN32_WCE */
/* Windows CE-specific definitions */
#pragma comment(lib,"ws2")
//#include "compat_wince.h"
#endif /* _WIN32_WCE */

#else
#include <sys/types.h>
#include <sys/select.h>
#include <sys/wait.h>
#endif

#ifndef _WIN32_WCE /* Some ANSI #includes are not available on Windows CE */
#include <time.h>
#include <errno.h>
#include <signal.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "./shttpd/shttpd.h"
#include "mushiServer.h"

void getVar(char *name, struct shttpd_arg *arg){
}






/*
 * Handler for the / (root) of the server
 */
static void
show_index(struct shttpd_arg *arg)
{


	shttpd_printf(arg, "%s",
		"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
		"<html><body><h1>MushiServer " MUSHI_SERVER_VERSION "</h1>");
    shttpd_printf(arg, "The Mushi Bug tracking system is a full-featured, platform "
    		"independent bug tracking system for the web and desktop."
    		"<hr><br />Server status: <strong>OK</strong>. The server is running correctly");

	shttpd_printf(arg, "%s", "</body></html>");
	arg->flags |= SHTTPD_END_OF_OUTPUT;
}

/*
 * Make sure we have ho zombies from CGIs
 */
static void
signal_handler(int sig_num)
{
	switch (sig_num) {
#ifndef _WIN32
	case SIGCHLD:
		while (waitpid(-1, &sig_num, WNOHANG) > 0) ;
		break;
#endif /* !_WIN32 */
	default:
		break;
	}
}




int main(int argc, char *argv[])
{
	int			data = 1234567;
	struct shttpd_ctx	*ctx;
	printf("\n\nMushi Tracker server version %s\n", MUSHI_SERVER_VERSION);
	/* Get rid of warnings */
	argc = argc;
	argv = argv;

#ifndef _WIN32
	signal(SIGPIPE, SIG_IGN);
	signal(SIGCHLD, &signal_handler);
#endif /* !_WIN32 */

	/*
	 * Initialize SHTTPD context.
	 * Attach folder c:\ to the URL /my_c  (for windows), and
	 * /etc/ to URL /my_etc (for UNIX). These are Apache-like aliases.
	 * Set WWW root to current directory.
	 * Start listening on ports 8080 and 8081
	 */
	ctx = shttpd_init(argc, argv);
//	shttpd_set_option(ctx, "ssl_cert", "shttpd.pem");
	shttpd_set_option(ctx, "ports", "8080");

	/* Register an index page under two URIs */
	shttpd_register_uri(ctx, "/", &show_index, (void *) &data);


	//shttpd_handle_error(ctx, 404, show_404, NULL);


    printf("Server started.\n");

	/* Serve connections infinitely until someone kills us */
	while(1){
		shttpd_poll(ctx, 1000);
	}
	/* Probably unreached, because we will be killed by a signal */
	shttpd_fini(ctx);

	return (EXIT_SUCCESS);
}
