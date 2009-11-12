/*
 *  FindTaskCommand.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *
 */
#include <stdio.h>
#include <sstream>
#include <QStringList>
#include "../lib_json/value.h"
#include "FindTaskCommand.h"
#include "MushiServer.h"


Json::Value &FindTaskCommand::run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine){
	
	
	
	if(command["command"].asString()=="findTask"){
		Json::Value results(Json::arrayValue);
		std::ostringstream query;
		MushiDBResult *r;
		MushiDB *db = MushiServer::getInstance()->getDB();
		
                query	<< "SELECT t.id, t.title, t.description, t.percentComplete, t.estimate, t.createDate, t.originalEstimate"
				<< " , t.reporterId as reporterId, r.firstName as reporter_firstName, r.lastName as reporter_lastName, r.email as reporter_email "
                                << " ,t.ownerId as ownerId, t.parentTaskID, o.firstName as owner_firstName, o.lastName as owner_lastName, o.email as owner_email "
                                << " ,s.name as status, s.isOpen as isOpen"
				<< " FROM task t"
				<< " LEFT JOIN user r on r.id = t.reporterId"
				<< " LEFT JOIN user o on o.id = t.ownerId"
                                << " LEFT JOIN status s on s.id = t.statusID";

		//printf("%s\n",query.str().c_str());
                QString operat(command.get("operator","AND").asString().c_str());
                if(operat=="AND"){
                    query <<" WHERE 1";
                }

                //query <<"WHERE 1=0";


                QStringList params;
                params.append("title");
                for(int x=0; x<params.size();x++){
                    QString paramVal(command.get(params.at(x).toStdString(),"").asString().c_str());
                    if(paramVal!=""){

                        query << " AND " << params.at(x).toStdString() << " like '%" << paramVal.toStdString() << "%'";
                  }
                }

		r=db->query(query.str());
		results=r->getNestedJson();
		
		ret["status"]="success";
	
		ret["results"]=results;
		
	}
	return ret;
}
