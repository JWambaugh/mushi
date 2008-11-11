/*
 *  addTicketCommand.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */
#include <stdio.h>
#include "addTicketCommand.h"

Json::Value  AddTicketCommand::run(MushiSession sess, Json::Value command, Json::Value ret){
	printf("%s\n",command["command"].asString().c_str());
	if(command["command"].asString()=="addTicket"){
	
		ret["status"]=="success";
	
	
	}
	return ret;
}
