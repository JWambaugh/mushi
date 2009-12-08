/*
 *  DeleteTaskCommand.h
 *  server
 *
 *  Created by Jordan Wambaugh on 1/19/09.
 *
 */

#include "../MushiCommand.h"
#include "../MushiSession.h"

class DeleteTaskCommand: public MushiCommand {
public:
        Json::Value &run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine);
	
	
private:
	
	
	
};
