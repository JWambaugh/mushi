/*
 *  EditTaskCommand.h
 *  server
 *
 *  Created by Jordan Wambaugh on 1/14/09.

 *
 */

#include "../MushiCommand.h"
#include "../MushiSession.h"

class EditTaskCommand: public MushiCommand {
public:
        Json::Value &run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine, MushiDB &db);
	
	
private:
	
	
	
};
