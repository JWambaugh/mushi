/*
 *  MushiDB.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */
#ifndef MUSHIDB
#define MUSHIDB

#include <string>
#include "MushiDBResult.h"
#include "sqlite3.h"
#include "../lib_json/json.h"
#include <vector>
#include <QString>

class MushiDB {

public:
	void init();
	sqlite3 *getHandle();
	MushiDBResult * query(const std::string sql);
	static std::string json2update(Json::Value &val, std::vector<std::string>&columns, std::string where, std::string table);
	static std::string json2insert(Json::Value &val, std::vector<std::string>&columns, std::string table);
        QString escapeQuotes(QString value);
private:
	sqlite3 *db;

	
	};
				 
				 
 

				 
				 
#endif
