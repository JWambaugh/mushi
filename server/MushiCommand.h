/*
 *  MushiCommand.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */
#include "../lib_json/json.h"
#include "MushiDB.h"
#include "MushiSession.h"
#include "utils.h"

#ifndef MUSHICOMMAND
#define MUSHICOMMAND

class MushiCommand{
public:
	virtual Json::Value &run(MushiSession sess, Json::Value &command, Json::Value &ret)=0;

};


#endif