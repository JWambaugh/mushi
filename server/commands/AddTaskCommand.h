/*
 *  addTaskCommand.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */

#include "MushiCommand.h"
#include "MushiSession.h"

class AddTaskCommand: public MushiCommand {
public:
	Json::Value run(MushiSession sess, Json::Value command, Json::Value ret);

	
private:
	
	

};