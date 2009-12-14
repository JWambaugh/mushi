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
//#include <fstream>
#include <sstream>
#include <QTime>
#include "mongoose.h"
#include "utils.h"
#include "MushiServer.h"
#include "URLHandlers.h"
#include "MushiDB.h"
#include "ScriptEngine.h"
#include "../lib_json/json.h"

void MushiServer::defineHandlers(){
        mg_set_uri_callback(ctx, "/", &m_showIndex,NULL);
        mg_set_uri_callback(ctx, "/version", &m_showVersion,NULL);
        mg_set_uri_callback(ctx, "/config", &m_showConfig,NULL);
        mg_set_uri_callback(ctx, "*.mjs", &m_script,NULL);
        mg_set_uri_callback(ctx, "/command", &m_receiveCommand,NULL);
}


static void
m_receiveCommand(struct mg_connection *conn, const struct mg_request_info *ri, void *user_data)
{
        QTime timer;
	Json::Reader reader;
	JSON_WRITE_CLASS writer;
	Json::Value cmd;
	char	 *request_method;
	char *data= ri->post_data;
	request_method = ri->request_method;
	if(data==0){
		mg_printf(conn,"data wasn't posted.");
		return;
	}
	url_decode(data,strlen(data),data,strlen(data)+1 );
        if (!strcmp(request_method, "POST")) {
                timer.start();
                MushiScriptEngine engine(conn,ri,user_data);
                qDebug()<<"Time to initialize engine: "<<timer.elapsed();
                printf("Received POST: %s\n",data);

		
		
		std::string input =data;
		
		//TODO: Remove this after testing!
		input=replaceOnce(input,"data=", "");
		
		
		reader.parse(input, cmd);
		
		
               // char *buff = (char *)writer.write(MushiServer::getInstance()->runCommand(cmd,engine)).c_str();
                std::string response;

                response.append("HTTP/1.1 200 OK\r\n"
                                "Content-Type: text/html\r\n"
                                "Connection: close\r\n\r\n");

                response.append(writer.write(MushiServer::getInstance()->runCommand(cmd,engine)));
                //mg_printf(conn, "%s",buff);
                mg_write(conn, response.c_str(),response.length());

                                  //free(buff);
		//free(request_method);
		//free(data);
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

	val["protocolVersion"] = MUSHI_PROTOCOL_VERSION;
	val["name"] = MUSHI_SERVER_NAME;
        val["about"] = MUSHI_ABOUT;
	mg_printf(conn, "%s",(char *)writer.write(val).c_str());
}


/*
 * Handler for the / (root) of the server
 */
static void m_showIndex(struct mg_connection *conn, const struct mg_request_info *ri, void *user_data){
	
	MushiDBResult *r;
	MushiDB *db = MushiServer::getInstance()->getDB();
	
	r=db->query("select count(*) from task");
	
	mg_printf(conn, "%s",
				  "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
                                  "<html><head><title>Mushi Server Status</title></head><body><img src='/mushiLogo.png'/><br>");
    mg_printf(conn, MUSHI_ABOUT
				"<hr><table border='1'>"
				"<tr><td>Server version: </td><td><strong>" MUSHI_SERVER_VERSION "</strong></td></tr>"
				"<tr><td>Mushi Protocol Version: </td><td><strong>" MUSHI_PROTOCOL_VERSION "</strong></td></tr>"
				"<tr><td>Server status:</td><td> <strong>OK</strong></td></tr>"
				"<tr><td>Number of tasks in database:</td><td> <strong>%s</strong></td></tr>"
				"</table><br />The server is running correctly", r->getCell(1, 0));
	
	delete r;
	mg_printf(conn, "%s", "</body></html>");
}

/**
Javascript handler
*/
static void m_script(struct mg_connection *conn, const struct mg_request_info *ri,void *user_data){
    QTime timer;
    timer.start();
    mg_printf(conn, "%s", "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    //mg_printf(conn,"Script called!");

    std::ostringstream fileName;
    fileName << MushiConfig::getValue("interfaceDirectory").toStdString() <<ri->uri;
   // mg_printf(conn,"%s",getFileContents(buffer.str()).c_str());




    MushiScriptEngine engine(conn,ri,user_data);

    QString contents;
    //Load and eval the called script
    contents= getFileContents(QString(fileName.str().c_str()));
    precompileMJS(contents);
    //printf("%s\n",contents.toStdString().c_str());
    engine.engine.evaluate(contents,QString(fileName.str().c_str()));

    QStringList errors;
    errors = engine.engine.uncaughtExceptionBacktrace();
    if(errors.size()){
        printf("%s\n",engine.engine.uncaughtException().toString().toStdString().c_str());
        for (int i = 0; i < errors.size(); ++i)
              printf("%s\n",errors.at(i).toLocal8Bit().constData());
        }
    qDebug()<<"time elapsed to run script: "<<timer.elapsed();
}


static size_t url_decode(const char *src, size_t src_len, char *dst, size_t dst_len)
{
	size_t	i, j;
	int	a, b;
#define	HEXTOI(x)  (isdigit(x) ? x - '0' : x - 'W')
	
	for (i = j = 0; i < src_len && j < dst_len - 1; i++, j++)
		switch (src[i]) {
			case '%':
				if (isxdigit(((unsigned char *) src)[i + 1]) &&
					isxdigit(((unsigned char *) src)[i + 2])) {
					a = tolower(((unsigned char *)src)[i + 1]);
					b = tolower(((unsigned char *)src)[i + 2]);
					dst[j] = ((HEXTOI(a) << 4) | HEXTOI(b)) & 0xff;
					i += 2;
				} else {
					dst[j] = '%';
				}
				break;
			case '+':dst[j] =' ';break;
			default:
				dst[j] = src[i];
				break;
		}
	
	dst[j] = '\0';	/* Null-terminate the destination */
	
	return (j);
}




