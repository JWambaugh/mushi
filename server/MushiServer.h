/*
 *  MushiServer.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/6/08.
 *
 */
#include <vector>
#include "sqlite3.h"
#include "URLHandlers.h"
#include "MushiDB.h"
#include "MushiCommand.h"
#include "utils.h"
#include "../lib_json/json.h"
#ifndef JSON_WRITE_CLASS
#define JSON_WRITE_CLASS Json::StyledWriter
#endif


#define MUSHI_SERVER_VERSION "0.0.-1"
#define MUSHI_SERVER_NAME "Mushi Tracker - server (Premortal)"
#define MUSHI_PROTOCOL_VERSION "1"
#define MUSHI_AUTHOR "Jordan CM Wambaugh"
#define MUSHI_LICENSE "Mushi Bug Tracking System Server Copyright(C) 2008 Jordan CM Wambaugh. All rights reserved."
#define MUSHI_ABOUT "Mushi Tracker - server is the server behind the Mushi Bug Tracking System. \\
It is a completely stand-alone application that depends on no external libraries or services.\\
The Mushi Server communicates with clients via JSON. JSON is a very \\
simple format for passing data between applications. The use of this simple yet powerful format for transmitting data, and the fact that mushi server is written in 100% c/c++ code allows Mushi to be very fast, simple, yet feature-rich."


class MushiServer	{
public:
	void startup(int argc, char *argv[]);
	static MushiServer *getInstance();
	MushiDB *getDB();
	static MushiServer *instance;
	
	Json::Value runCommand(Json::Value command);
	
	int registerCommand(MushiCommand *command);
	
private:
	MushiServer();
	struct shttpd_ctx	*ctx;
	MushiDB *db;
	std::vector<class MushiCommand *> commands;
	void defineHandlers();
	void installCommands();
};