/*
 *  FindTaskCommand.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *
 */
#include <stdio.h>
#include <sstream>
#include "../lib_json/value.h"
#include "FindTaskCommand.h"
#include "MushiServer.h"

Json::Value  FindTaskCommand::run(MushiSession sess, Json::Value command, Json::Value ret){
	
	
	
	if(command["command"].asString()=="findTask"){
		Json::Value results(Json::arrayValue);
		std::ostringstream query;
		MushiDBResult *r;
		MushiDB *db = MushiServer::getInstance()->getDB();
		
		query	<< "SELECT t.title, t.description, t.percentComplete, t.estimate, t.createDate" 
				<< " , t.reporterId, r.firstName as reporterFirstName, r.lastName as reporterLastName, r.email as reporterEmail "
				<< " ,t.ownerId, o.firstName as ownerFirstName, o.lastName as ownerLastName, o.email as ownerEmail "
				<< " ,s.name as status, s.isOpen as isOpen"
				<< " FROM task t"
				<< " LEFT JOIN user r on r.id = t.reporterId"
				<< " LEFT JOIN user o on o.id = t.ownerId"
				<< " LEFT JOIN status s on s.id = t.statusID"
				<< " WHERE 1";
		printf("%s\n",query.str().c_str());
		r=db->query(query.str());
		
		
		ret["status"]="success";
	
		for(int x=1; x<=r->row;x++){
			Json::Value task;
			
			task["title"] = r->getCell(x, 0);
			task["description"] = r->getCell(x, 1);
			task["percentComplete"] = r->getCell(x, 2);
			task["estimate"] = r->getCell(x, 3);
			task["createDate"] = r->getCell(x, 4);
		//	task["percentComplete"] = r->getCell(x, 2);
			
			//reporter object
			Json::Value reporter;
			reporter["id"]=r->getCell(x,5);
			reporter["firstName"]=r->getCell(x,6);
			reporter["lastName"]=r->getCell(x,7);
			reporter["email"]=r->getCell(x,8);
			task["reporter"]=reporter;
			
			//owner object
			Json::Value owner;
			owner["id"]=r->getCell(x,9);
			owner["firstName"]=r->getCell(x,10);
			owner["lastName"]=r->getCell(x,11);
			owner["email"]=r->getCell(x,12);
			task["owner"]=owner;
			
			
			task["status"]=r->getCell(x,13);
			task["isOpen"]=r->getCell(x,14);
			
			
			results.append(task);
}
		ret["results"]=results;
		
	}
	return ret;
}