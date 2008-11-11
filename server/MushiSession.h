/*
 *  MushiSession.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *
 */
#ifndef MUSHISESSION
#define MUSHISESSION

#include <string>

#include "../lib_json/json.h"
#include "MushiDBResult.h"





class MushiSession {
public:
	MushiSession(std::string id);
	MushiSession();
	void save();
	void load(std::string id);
	void load();
	std::string getID();
	Json::Value data;
	
private:
		
};



#endif