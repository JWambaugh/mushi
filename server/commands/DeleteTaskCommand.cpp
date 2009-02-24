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
#include "../lib_json/value.h"

#include "MushiServer.h"
#include "EditTaskCommand.h"


Json::Value &DeleteTaskCommand::run(MushiSession sess, Json::Value &command, Json::Value &ret){
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
		MushiDB *db = MushiServer::getInstance()->getDB();
		
		
		
		
		std::ostringstream query;
                //query << "id = '" << dbin(command["id"].asString()) << "'";
		
                //db->query(MushiDB::json2update(command, columns,where.str(),"task"));
		
		
		ret["status"]="success";
	}
	return ret;
}
