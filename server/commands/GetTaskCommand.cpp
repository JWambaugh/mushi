/*
 *  GetTaskCommand.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *
 */
#include <stdio.h>
#include <sstream>
#include <QStringList>
#include "../../lib_json/value.h"
#include "GetTaskCommand.h"
#include "../MushiServer.h"


Json::Value &GetTaskCommand::run(MushiSession &sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine, MushiDB &db){
	
	
	
        if(command["command"].asString()=="getTask"){
            if (command.get("taskID","")==""){
                ret["status"]= "error";
                ret["command"]="getTask";
                ret["message"]="Must have an ID to get a task";
                throw ret;
                return ret;
            }
		Json::Value results(Json::arrayValue);
		std::ostringstream query;
		MushiDBResult *r;

		
                query	<< "SELECT t.id, t.title, t.description, t.percentComplete, t.estimate, t.createDate, t.originalEstimate"
                                << " , t.reporterID, r.firstName as reporter_firstName, r.lastName as reporter_lastName, r.email as reporter_email "
                                << " ,t.ownerId as ownerID, t.parentTaskID, o.firstName as owner_firstName, o.lastName as owner_lastName, o.email as owner_email "
                                << " ,s.name as status_name, s.isOpen as status_isOpen, s.id as status_id"
                                << " ,ty.id as type_id,ty.name as type_name, ty.description as type_description"
                                << " ,p.id as priority_id, p.name as priority_name, p.description as priority_description"
				<< " FROM task t"
                                << " LEFT JOIN user r on r.id = t.reporterID"
                                << " LEFT JOIN user o on o.id = t.ownerID"
                                << " LEFT JOIN status s on s.id = t.statusID"
                                << " LEFT JOIN type ty on t.typeID = ty.id"
                                << " LEFT JOIN Priority p on p.id = t.priorityID";

                query << " WHERE t.id = " << db.escapeQuotes(command.get("taskID","").asCString()).toStdString().c_str();


                r=db.query(query.str());
		results=r->getNestedJson();
		
		ret["status"]="success";
	
		ret["results"]=results;
		
	}
	return ret;
}
