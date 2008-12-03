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
#include <iostream>
#include "../shttpd/shttpd.h"
#include "../shttpd/defs.h"
#include "utils.h"
#include "MushiServer.h"
#include "URLHandlers.h"
#include "MushiDB.h"
#include "../lib_json/json.h"

void MushiServer::defineHandlers(){
	shttpd_register_uri(ctx, "/", &::m_showIndex,NULL);
	shttpd_register_uri(ctx, "/version", &::m_showVersion,NULL);
	shttpd_register_uri(ctx, "/config", &::m_showConfig,NULL);
	shttpd_register_uri(ctx, "/command", &::m_receiveCommand,NULL);
}


void m_receiveCommand(struct shttpd_arg *arg){
	Json::Reader reader;
	JSON_WRITE_CLASS writer;
	Json::Value cmd;
	const char	 *request_method;
	
	request_method = shttpd_get_env(arg, "REQUEST_METHOD");
	

	if (!strcmp(request_method, "POST")) {
	//	printf("Received POST\n");
		/* If not all data is POSTed, wait for the rest */
		if (arg->flags & SHTTPD_MORE_POST_DATA)
			return;
		_shttpd_url_decode(arg->in.buf,arg->in.len,arg->in.buf,arg->in.len+1 );
		std::string input = arg->in.buf;
		
		//TODO: Remove this after testing!
		input=replaceOnce(input,"hmm=", "");
		
		
		reader.parse(input, cmd);
		
		
		char *buff = (char *)writer.write(MushiServer::getInstance()->runCommand(cmd)).c_str();
		
		shttpd_printf(arg, "%s",buff);
	} 
	//not a POST
	else{
	
		shttpd_printf(arg, "Commands may only be POSTed.");
	}
	
	arg->flags |= SHTTPD_END_OF_OUTPUT;
	
}

void m_showConfig(struct shttpd_arg *arg){
	Json::Value val;
	JSON_WRITE_CLASS writer;
	val["version"] = MUSHI_SERVER_VERSION;
	
	MushiDB *db = MushiServer::getInstance()->getDB();
	MushiDBResult *r;
	
	r=db->query("select key,value from config");
	for (int x=1;x<=r->row;x++){
		val[r->getCell(x,0)]=r->getCell(x,1);
	}
	
	shttpd_printf(arg, "%s",(char *)writer.write(val).c_str());
	arg->flags |= SHTTPD_END_OF_OUTPUT;
}


void m_showVersion(struct shttpd_arg *arg){
	Json::Value val;
	JSON_WRITE_CLASS writer;
	val["version"] = MUSHI_SERVER_VERSION;
	val["author"] = MUSHI_AUTHOR;
	val["license"] = MUSHI_LICENSE;
	val["about"] = MUSHI_ABOUT;
	val["protocolVersion"] = MUSHI_PROTOCOL_VERSION;
	val["name"] = MUSHI_SERVER_NAME;
	
	shttpd_printf(arg, "%s",(char *)writer.write(val).c_str());
	arg->flags |= SHTTPD_END_OF_OUTPUT;
}


/*
 * Handler for the / (root) of the server
 */
void m_showIndex(struct shttpd_arg *arg){
	
	printf("Loding root\n");
	shttpd_printf(arg, "%s",
				  "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
				  "<html><body><h1>Mushi</h1>");
    shttpd_printf(arg, MUSHI_ABOUT
				  "<hr>"
				  "<br />Server version: <strong>" MUSHI_SERVER_VERSION "</strong>."
				  "<br />Server status: <strong>OK</strong>."
				  "<br />The server is running correctly");
	
	
	
	shttpd_printf(arg, "%s", "</body></html>");
	arg->flags |= SHTTPD_END_OF_OUTPUT;
}
