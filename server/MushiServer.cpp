/*
 *  MushiServer.cpp
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
#include <string>
#include <sstream>
#include "mongoose.h"
#include "commands/AddTaskCommand.h"
#include "commands/FindTaskCommand.h"
#include "commands/EditTaskCommand.h"
#include "commands/DeleteTaskCommand.h"
#include "commands/ScriptCommand.h"
#include "commands/GetStatusesCommand.h"
#include "MushiServer.h"
#include "URLHandlers.h"
#include "MushiDB.h"
#include "MushiSetup.h"
#include "MushiConfig.h"
#include "MushiCommand.h"
#include "MushiSession.h"
#include "ScriptEngine.h"
#include "../lib_json/json.h"
#include "utils.h"



MushiServer::MushiServer(){

}





void MushiServer::installCommands(){

        //built-in commands
        this->registerCommand(new AddTaskCommand);
	this->registerCommand(new FindTaskCommand);
	this->registerCommand(new EditTaskCommand);
        this->registerCommand(new DeleteTaskCommand);
        this->registerCommand(new GetStatusesCommand);
        //install mjscript commands
        QDir scriptDir(MushiConfig::getValue("commandDirectory"));
        QFileInfoList files;
        files=scriptDir.entryInfoList(QStringList("*.mjs"));
        for(int  x=0;x<files.size();x++){
            if(files.at(x).isFile()){
               // qDebug()<<"Loading "<<files.at(x).absoluteFilePath();
                this->registerCommand(new ScriptCommand(files.at(x).absoluteFilePath()));
            }
        }


}




MushiServer * MushiServer::instance = 0;
MushiDB * MushiServer::getDB(){
	return db;
}

MushiServer * MushiServer::getInstance(){
		if (instance == 0)  // is it the first call?
		{  
			instance = new MushiServer; // create sole instance
		}
		return instance; // address of sole instance
	
}	

int MushiServer::registerCommand(MushiCommand *command){
	commands.push_back(command);
	return 1;
}



Json::Value MushiServer::runCommand(Json::Value command,MushiScriptEngine &engine){
	
	MushiSession session;
	

	//check for a session id
	if(!command["sessionID"]){
		session.load();
	}else{
		
		session.load(command["sessionID"].asString());
	}
	
	

		
        Json::Value ret;
        ret["status"]="failure";
	//give the command to command handlers for handling
	try{
		for(int x=0;x<commands.size();x++){
                        ret = commands.at(x)->run(session, command, ret, engine.engine);
		}
	} catch (Json::Value val){
            return val;
	}
	session.save();
        if(ret.get("status","")=="failure" && ret.get("reason","")==""){
            ret["reason"]="Command not found";
        }
	return ret;
}




void MushiServer::startup(int argc, char *argv[]){
	printf("\n\n%s version %s\n", MUSHI_SERVER_NAME,MUSHI_SERVER_VERSION);
	/* Get rid of warnings */
	argc = argc;
	argv = argv;
	
	
	db=new MushiDB();
	db->init();
	//build our tables!
	MushiSetup::checkStatus();	
	
	this->installCommands();
	
        ctx = mg_start();
        mg_set_option(ctx, "root",MushiConfig::getValue("interfaceDirectory").toStdString().c_str() );  // Set document root
        mg_set_option(ctx, "ports", MushiConfig::getValue("listenPort").toStdString().c_str());
        char *port = (char *)MushiConfig::getValue("listenPort").toStdString().c_str();
	printf("listening on port %s.\n",port);
        //free(port);
	
	
	defineHandlers();
	
    printf("Server started.\n");
	
	
	/*
	Json::Value test;
	test["column1"]="This is a value";
	test["column2"]="this is the value of 'column2'";
	std::vector<std::string> columns;
	columns.push_back("column1");
	columns.push_back("column2");
	
	
	printf("%s\n",db->json2update(test,columns,"id = '23'","myTable").c_str());
	printf("%s\n",db->json2insert(test,columns,"myTable").c_str());
	*/
	
}	

