/*
 *  GetStatusesCommand.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *
 */
#include <stdio.h>
#include <sstream>
#include <QStringList>
#include "../../lib_json/value.h"
#include "GetStatusesCommand.h"
#include "../MushiServer.h"


Json::Value &GetStatusesCommand::run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine, MushiDB &db){



        if(command["command"].asString()=="getStatuses"){
                Json::Value results(Json::arrayValue);
                std::ostringstream query;
                MushiDBResult *r;


                query	<< "SELECT * from status";


                r=db.query(query.str());
                results=r->getNestedJson();

                ret["status"]="success";

                ret["results"]=results;

        }
        return ret;
}
