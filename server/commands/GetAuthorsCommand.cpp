/*
 *  GetAuthorsCommand.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *
 */
#include <stdio.h>
#include <sstream>
#include <QStringList>
#include "../../lib_json/value.h"
#include "GetAuthorsCommand.h"
#include "../MushiServer.h"


Json::Value &GetAuthorsCommand::run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine){



        if(command["command"].asString()=="getUsers"){
                Json::Value results(Json::arrayValue);
                std::ostringstream query;
                MushiDBResult *r;
                MushiDB *db = MushiServer::getInstance()->getDB();

                query	<< "SELECT * from user";


                r=db->query(query.str());
                results=r->getNestedJson();

                ret["status"]="success";

                ret["results"]=results;

        }
        return ret;
}
