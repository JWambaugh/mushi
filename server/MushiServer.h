/*
 *  MushiServer.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/6/08.
 *
 */
#ifndef MUSHI_SERVER_H
#define MUSHI_SERVER_H
#include <vector>
#include "sqlite3.h"
#include "URLHandlers.h"
#include "MushiDB.h"
#include "MushiCommand.h"
#include "MushiConfig.h"
#include "mongoose.h"
#include "utils.h"
#include "../lib_json/json.h"
#include <QtScript>

#include "ScriptEngine.h"
#ifndef JSON_WRITE_CLASS
#define JSON_WRITE_CLASS Json::StyledWriter
#endif


#define MUSHI_SERVER_VERSION "0.-1.6"
#define MUSHI_SERVER_NAME "Mushi - Server (Premortal)"
#define MUSHI_PROTOCOL_VERSION "0.-1"
#define MUSHI_AUTHOR "Jordan CM Wambaugh"
#define MUSHI_LICENSE "Mushi - Server Copyright(C) 2008 Jordan CM Wambaugh. All rights reserved."
#define MUSHI_ABOUT "Mushi - Server is the server behind Mushi. \
It is a completely stand-alone application that depends on no external libraries or services.\
The Mushi Server communicates with clients via JSON. JSON is a very \
simple format for passing data between applications. The use of this simple yet powerful format for transmitting data, and the fact that Mushi - Server is written in 100 percent c/c++ code allows Mushi to be very fast, simple, yet feature-rich.\
<br>\
<em>This is a premortal version of Mushi - Server. It is unstable and should not be used where a reliable system is required.</em>"


class MushiServer	{
public:
	void startup(int argc, char *argv[]);
	static MushiServer *getInstance();
	MushiDB *getDB();
	static MushiServer *instance;
	
        Json::Value runCommand(Json::Value command,MushiScriptEngine &engine, MushiDB &db);
	
	int registerCommand(MushiCommand *command);

private:
	MushiServer();
	mg_context	*ctx;
	MushiDB *db;
	std::vector<class MushiCommand *> commands;
	void defineHandlers();
	void installCommands();
};
#endif
