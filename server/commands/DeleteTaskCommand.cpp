/*
 *  DeleteTaskCommand.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 1/19/09.
 *
 */

#include "DeleteTaskCommand.h"



#include <stdio.h>
#include <sstream>
#include <vector>
#include "../../lib_json/value.h"

#include "../MushiServer.h"
#include "EditTaskCommand.h"


Json::Value &DeleteTaskCommand::run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine, MushiDB &db){
	/*
	 //debug command
	 Json::Value::Members members;
	 members=command.getMemberNames();
	 for(int x=0;x<members.size();x++){
	 printf(":%s\n",members.at(x).c_str());
	 }*/
	
	if(command["command"].asString()=="deleteTask"){
		
		
		if(command.get("id","")==""){
			ret["status"]= "error";
			ret["command"]="deleteTask";
			ret["message"]="Must have an ID to delete a task";
			throw ret;
		}
		//std::string query;

		
		
		
		
		std::ostringstream query;
                query << "delete from task where id = '" << dbin(command["id"].asString()) << "'";
		


                db.query(query.str());
		
		
		ret["status"]="success";
	}
	return ret;
}
