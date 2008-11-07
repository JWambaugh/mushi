/*
 *  URLHandlers.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/6/08.
 *
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
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../shttpd/shttpd.h"

#include "MushiServer.h"
#include "URLHandlers.h"
#include "MushiDB.h"



/*
 * Handler for the / (root) of the server
 */
void m_show_index(struct shttpd_arg *arg){
	MushiDBResult *r;
	r=MushiServer::getInstance()->getDB()->query("select * from test");
	
	shttpd_printf(arg, "%s",
				  "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
				  "<html><body><h1>Mushi</h1>");
    shttpd_printf(arg, "The Mushi Bug tracking system is a full-featured, platform "
				  "independent bug tracking system for the web and desktop."
				  "<hr>"
				  "<br />Server version: <strong>" MUSHI_SERVER_VERSION "</strong>."
				  "<br />Server status: <strong>OK</strong>."
				  "<br />The server is running correctly");
	shttpd_printf(arg, "Test table: %s", r->getCell(1,0));
	delete r;
	
	shttpd_printf(arg, "%s", "</body></html>");
	arg->flags |= SHTTPD_END_OF_OUTPUT;
}
