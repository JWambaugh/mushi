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
#include "mongoose.h"
#include "utils.h"
#include "MushiServer.h"
#include "URLHandlers.h"
#include "MushiDB.h"
#include "../lib_json/json.h"

void MushiServer::defineHandlers(){
	mg_bind_to_uri(ctx, "/", &m_showIndex,NULL);
	mg_bind_to_uri(ctx, "/version", &m_showVersion,NULL);
	mg_bind_to_uri(ctx, "/config", &m_showConfig,NULL);
	
	mg_bind_to_uri(ctx, "/command", &m_receiveCommand,NULL);
}


static void
m_receiveCommand(struct mg_connection *conn, const struct mg_request_info *ri, void *user_data)
{
	Json::Reader reader;
	JSON_WRITE_CLASS writer;
	Json::Value cmd;
	char	 *request_method;
	char *data= mg_get_var(conn,"data");
	request_method = ri->request_method;
	if(data==0){
		mg_printf(conn,"data wasn't posted.");
		return;
	}

	if (!strcmp(request_method, "POST")) {
		printf("Received POST: %s\n",data);
		/* If not all data is POSTed, wait for the rest */
		
		//_shttpd_url_decode(arg->in.buf,arg->in.len,arg->in.buf,arg->in.len+1 );
		std::string input =data;
		
		//TODO: Remove this after testing!
		//input=replaceOnce(input,"hmm=", "");
		
		
		reader.parse(input, cmd);
		
		
		char *buff = (char *)writer.write(MushiServer::getInstance()->runCommand(cmd)).c_str();
		
		mg_printf(conn, "%s",
				  "HTTP/1.1 200 OK\r\n"
				  "Content-Type: text/html\r\n"
				  "Connection: close\r\n\r\n");
		mg_printf(conn, "%s",buff);
		free(data);
	} 
	//not a POST
	else{
	
		mg_printf(conn, "Commands may only be POSTed.");
	}
}

static void m_showConfig(struct mg_connection *conn, const struct mg_request_info *ri, void *user_data){
	Json::Value val;
	JSON_WRITE_CLASS writer;
	val["version"] = MUSHI_SERVER_VERSION;
	
	MushiDB *db = MushiServer::getInstance()->getDB();
	MushiDBResult *r;
	
	r=db->query("select key,value from config");
	for (int x=1;x<=r->row;x++){
		val[r->getCell(x,0)]=r->getCell(x,1);
	}
	
	mg_printf(conn, "%s",(char *)writer.write(val).c_str());
}


static void m_showVersion(struct mg_connection *conn, const struct mg_request_info *ri, void *user_data){
	Json::Value val;
	JSON_WRITE_CLASS writer;
	val["version"] = MUSHI_SERVER_VERSION;
	val["author"] = MUSHI_AUTHOR;
	val["license"] = MUSHI_LICENSE;
	val["about"] = MUSHI_ABOUT;
	val["protocolVersion"] = MUSHI_PROTOCOL_VERSION;
	val["name"] = MUSHI_SERVER_NAME;
	
	mg_printf(conn, "%s",(char *)writer.write(val).c_str());
}


/*
 * Handler for the / (root) of the server
 */
static void m_showIndex(struct mg_connection *conn, const struct mg_request_info *ri, void *user_data){
	
	printf("Loding root\n");
	mg_printf(conn, "%s",
				  "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
				  "<html><body><h1>Mushi</h1>");
    mg_printf(conn, MUSHI_ABOUT
				  "<hr>"
				  "<br />Server version: <strong>" MUSHI_SERVER_VERSION "</strong>."
				  "<br />Server status: <strong>OK</strong>."
				  "<br />The server is running correctly");
	
	
	mg_printf(conn, "%s", "</body></html>");
}
