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
#include "AddTaskCommand.h"
#include "FindTaskCommand.h"
#include "EditTaskCommand.h"
#include "MushiServer.h"
#include "URLHandlers.h"
#include "MushiDB.h"
#include "MushiSetup.h"
#include "MushiConfig.h"
#include "MushiCommand.h"
#include "MushiSession.h"
#include "../lib_json/json.h"
#include "utils.h"



MushiServer::MushiServer(){

}





void MushiServer::installCommands(){
	this->registerCommand(new AddTaskCommand);
	this->registerCommand(new FindTaskCommand);
	this->registerCommand(new EditTaskCommand);
	
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



Json::Value MushiServer::runCommand(Json::Value command){
	
	MushiSession session;
	

	//check for a session id
	if(!command["sessionID"]){
		session.load();
	}else{
		
		session.load(command["sessionID"].asString());
	}
	
	

		
	Json::Value ret;
	//give the command to command handlers for handling
	try{
		for(int x=0;x<commands.size();x++){
			ret = commands.at(x)->run(session, command, ret);
		}
	} catch (Json::Value val){
			 return val;
	}
	session.save();
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
	mg_set_option(ctx, "ports", "8080"/*MushiConfig::getValue("listenPort")*/);
	char *port = MushiConfig::getValue("listenPort");
	printf("listening on port %s.\n",port);
	free(port);
	
	
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

