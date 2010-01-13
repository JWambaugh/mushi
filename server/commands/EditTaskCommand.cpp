/*
 *  EditTaskCommand.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 1/14/09.
 *
 */


#include <stdio.h>
#include <sstream>
#include <vector>
#include "../../lib_json/value.h"

#include "../MushiServer.h"
#include "EditTaskCommand.h"


Json::Value &EditTaskCommand::run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine, MushiDB &db){
	/*
	 //debug command
	 Json::Value::Members members;
	 members=command.getMemberNames();
	 for(int x=0;x<members.size();x++){
	 printf(":%s\n",members.at(x).c_str());
	 }*/
	
	if(command["command"].asString()=="editTask"){
		
		
		if(command.get("title","")==""){
			ret["status"]= "error";
			ret["command"]="addTask";
			ret["message"]="Cannot save a task with an empty title.";
			throw ret;
		}
		//std::string query;

		
		std::vector<std::string> columns;
		columns.push_back("title");
                columns.push_back("originalEstimate");
		columns.push_back("description");
		columns.push_back("percentComplete");
                columns.push_back("reporterID");
		columns.push_back("ownerID");
		columns.push_back("projectID");
		columns.push_back("estimate");
		columns.push_back("categoryID");
		columns.push_back("parentTaskID");
		columns.push_back("statusID");
		
		std::ostringstream where;
		where << "id = '" << dbin(command["id"].asString()) << "'";
				
                db.query(MushiDB::json2update(command, columns,where.str(),"task"));
		
		
		ret["status"]="success";
	}
	return ret;
}
