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
#include "mushirequest.h"
#include "../lib_json/json.h"
/*
void MushiServer::defineHandlers(){
        mg_set_uri_callback(ctx, "/", &m_showIndex,NULL);
        mg_set_uri_callback(ctx, "/version", &m_showVersion,NULL);
        mg_set_uri_callback(ctx, "/config", &m_showConfig,NULL);
        mg_set_uri_callback(ctx, "/plugin/*", &m_pluginWebRequest,NULL);
        mg_set_uri_callback(ctx, "*.mjs", &m_script,NULL);
        mg_set_uri_callback(ctx, "/command", &m_receiveCommand,NULL);

}*/

void *MushiServer::eventHandler(enum mg_event event,
                              struct mg_connection *conn,
                              const struct mg_request_info *request_info){

    MushiRequest request(conn,request_info);
    if(event==MG_NEW_REQUEST){

        if(request.getURI().contains(QRegExp("^/$"))){
            m_showIndex(request);
            return (void*)"processed";
        }else if(request.getURI().contains(QRegExp("\.mjs"))){
            m_script(request);
            return (void*)"processed";
        } else if(request.getURI().contains(QRegExp("^/command"))){
            m_receiveCommand(request);
            return (void*)"processed";
        }else{
            //serve file if its available

        }



    } else{
        return NULL;
    }


}



static void
m_receiveCommand(MushiRequest &request)
{
        QTime timer;

	Json::Reader reader;
	JSON_WRITE_CLASS writer;
	Json::Value cmd;



        if(request.getPost()==""){
                request.write("data wasn't posted.");
		return;
	}
        //url_decode(data,strlen(data),data,strlen(data)+1 );
        //qDebug()<<request.getMethod();
        if (request.getMethod()== "POST") {
                timer.start();
                //get a database handle
                MushiDB db;
                db.init();
                //init a script engine
                MushiScriptEngine engine(request);
                //qDebug()<<"Time to initialize engine: "<<timer.elapsed();
               // printf("Received POST: %s\n",data);

		
		

		

		
                QString data=QUrl::fromPercentEncoding(request.getPost().toAscii());

                //deprecated calls prefix data with 'data=' so remove that if its there.
                data=data.replace(QRegExp("^data="),"");

                reader.parse(data.toStdString(), cmd);
                // qDebug()<<"completed parse at: "<<timer.elapsed();
		
               // char *buff = (char *)writer.write(MushiServer::getInstance()->runCommand(cmd,engine)).c_str();
                QString response;

                response.append("HTTP/1.1 200 OK\r\n"
                                "Content-Type: text/html\r\n"
                                "Connection: close\r\n\r\n");

                response.append(writer.write(MushiServer::getInstance()->runCommand(cmd,engine,db)).c_str());
              //  qDebug()<<"completed commands at: "<<timer.elapsed();
                //mg_printf(conn, "%s",buff);
                request.write(response);
               // qDebug()<<"Time to complete command request: "<<timer.elapsed();

                                  //free(buff);
		//free(request_method);
		//free(data);
	} 
	//not a POST
	else{
	
                request.write( "Commands may only be POSTed.");
	}
}

static void m_showConfig(MushiRequest &request){
	Json::Value val;
	JSON_WRITE_CLASS writer;
	val["version"] = MUSHI_SERVER_VERSION;
	
	MushiDB *db = MushiServer::getInstance()->getDB();
	MushiDBResult *r;
	
	r=db->query("select key,value from config");
	for (int x=1;x<=r->row;x++){
		val[r->getCell(x,0)]=r->getCell(x,1);
	}
	
        request.write(writer.write(val));
}


static void m_showVersion(MushiRequest &request){
	Json::Value val;
	JSON_WRITE_CLASS writer;
	val["version"] = MUSHI_SERVER_VERSION;
	val["author"] = MUSHI_AUTHOR;
	val["license"] = MUSHI_LICENSE;

	val["protocolVersion"] = MUSHI_PROTOCOL_VERSION;
	val["name"] = MUSHI_SERVER_NAME;
        val["about"] = MUSHI_ABOUT;
        request.write(writer.write(val));
}



static void m_pluginWebRequest(MushiRequest &request){
    //std::ostringstream dirName;
    //dirName << MushiConfig::getValue("pluginsDirectory","../script/plugin").toStdString() <<ri->uri;

    QString uri(request.getURI());
    uri.replace("/plugin","");

    QString fileName(MushiConfig::getValue("pluginsDirectory","../script/plugin"));
    fileName.append(uri);
    //qDebug()<<"File name:"<<fileName;
    if(!QFile::exists (fileName)){
         request.write( "HTTP/1.1 404 FILE NOT FOUND\r\nContent-Type: text/html\r\n\r\nThe file at this location cannot be found.");
         return;
    }



    QString contents;
    //Load and eval the called script
    contents= getFileContents(fileName);
    if(contents==""){
        request.write("HTTP/1.1 404 FILE NOT FOUND\r\nContent-Type: text/html\r\n\r\nThe file at this location cannot be found.");
        return;
    }
    request.write( "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");

    //if its an mjs script
    if(fileName.contains(".mjs")){
        MushiScriptEngine engine(request);
        precompileMJS(contents);
        //qDebug()<<contents;
        //printf("%s\n",contents.toStdString().c_str());
        engine.engine.evaluate(contents,fileName);

        QStringList errors;
        errors = engine.engine.uncaughtExceptionBacktrace();
        if(errors.size()){
            printf("%s\n",engine.engine.uncaughtException().toString().toStdString().c_str());
            for (int i = 0; i < errors.size(); ++i)
                  printf("%s\n",errors.at(i).toLocal8Bit().constData());
        }
    } else {//other file types
       request.write(contents.toStdString());
    }

}


/*
 * Handler for the / (root) of the server
 */
static void m_showIndex(MushiRequest &request){
    request.write( "HTTP/1.1 301 Moved Permanently\r\nLocation: /index.mjs\r\n\r\n");

}

/**
Javascript handler
*/
static void m_script(MushiRequest &request){
    QTime timer;
    timer.start();

    //mg_printf(conn,"Script called!");

    std::ostringstream fileName;
    fileName << MushiConfig::getValue("interfaceDirectory").toStdString() <<request.getURI().toStdString();
   // mg_printf(conn,"%s",getFileContents(buffer.str()).c_str());




    MushiScriptEngine engine(request);

    QString contents;
    //Load and eval the called script
    contents= getFileContents(QString(fileName.str().c_str()));
    if(contents==""){
        request.write( "HTTP/1.1 404 FILE NOT FOUND\r\nContent-Type: text/html\r\n\r\nThe file at this location cannot be found.");
        return;
    }
    request.write("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
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
    //qDebug()<<"time elapsed to run script: "<<timer.elapsed();
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




