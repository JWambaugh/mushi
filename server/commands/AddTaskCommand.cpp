/*
 *  addTaskCommand.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *
 */
#include <stdio.h>
#include <sstream>
#include "../../lib_json/value.h"
#include "AddTaskCommand.h"
#include "../MushiServer.h"

Json::Value  &AddTaskCommand::run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine){
	/*
	//debug command
	Json::Value::Members members;
	members=command.getMemberNames();
	for(int x=0;x<members.size();x++){
		printf(":%s\n",members.at(x).c_str());
	}*/
	
	if(command["command"].asString()=="addTask"){
		
		
		if(command.get("title","")==""){
			ret["status"]= "error";
			ret["command"]="addTask";
			ret["message"]="Cannot create a task with an empty title.";
			throw ret;
		}
		std::ostringstream query;
		MushiDB *db = MushiServer::getInstance()->getDB();

		query << "insert into task (title,description,percentComplete,reporterID, ownerID, projectID,estimate,categoryID,parentTaskID, statusID ) VALUES("
					"'"<<dbin(command.get("title","").asString())
					<<"','"<<dbin(command.get("description","").asString())
					<<"','"<<dbin(command.get("percentComplete","").asString())
					<<"','"<<dbin(command.get("reporterID","").asString())
					<<"','"<<dbin(command.get("ownerID","").asString())
					<<"','"<<dbin(command.get("projectID","").asString())
					<<"','"<<dbin(command.get("estimate","").asString())
					<<"','"<<dbin(command.get("categoryID","").asString())
					<<"','"<<dbin(command.get("parentTaskID","").asString())
                <<"','"<<dbin(command.get("statusID",MushiConfig::getValue("defaultStatusID").toStdString().c_str()).asString())
		
					<< "')";
		
		db->query(query.str());
		
		
		ret["status"]="success";
	}
	return ret;
}
