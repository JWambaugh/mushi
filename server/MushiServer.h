/*
 *  MushiServer.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/6/08.
 *
 */
#include "sqlite3.h"
#include "URLHandlers.h"
#include "MushiDB.h"

#define MUSHI_SERVER_VERSION "0.0.-1 (Premortal)"

class MushiServer	{
public:
	void startup(int argc, char *argv[]);
	static MushiServer *getInstance();
	MushiDB *getDB();
	static MushiServer *instance;
private:
	MushiServer();
	struct shttpd_ctx	*ctx;
	MushiDB *db;

	void MushiServer::defineHandlers();

};