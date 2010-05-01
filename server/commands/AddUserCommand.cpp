
#include <stdio.h>
#include <sstream>
#include "../../lib_json/value.h"
#include "AddUserCommand.h"
#include "../MushiServer.h"
#include <vector>





Json::Value  &AddUserCommand::run(MushiSession &sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine, MushiDB &db){


        if(command["command"].asString()=="addUser"){


                if(command.get("firstName","")==""){
                        ret["status"]= "error";
                        ret["command"]="addUser";
                        ret["message"]="Cannot create a user without a first name.";
                        throw ret;
                }
                std::ostringstream query;

                std::vector<std::string> columns;
                columns.push_back("firstName");
                columns.push_back("lastName");
                columns.push_back("password");
                columns.push_back("email");
                db.query(db.json2insert(command,columns,"user"));

                db.query(query.str());


                ret["status"]="success";
        }
        return ret;
}
