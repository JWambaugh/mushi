/*
 *  FindTaskCommand.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/18/08.
 *
 */

#include "MushiCommand.h"
#include "MushiSession.h"

class FindTaskCommand: public MushiCommand {
public:
        Json::Value &run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine);
	
	
private:
	
	
	
};
