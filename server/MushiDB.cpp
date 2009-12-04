/*
 *  MushiDB.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */
#include <string>
#include <string.h>
#include <stdio.h>
#include "sqlite3.h"
#include "MushiServer.h"
#include "MushiDBResult.h"
#include <vector>
#include <sstream>
#include "utils.h"
sqlite3 * MushiDB::getHandle(){
	return db;
}



void MushiDB::init(){
	//load the database
        if(sqlite3_open("../data/mushiServer.data", &db) != SQLITE_OK){
		printf("An error occured while loading the database: %s\n",sqlite3_errmsg(db));
	} else{
		printf("Successfully loaded database.\n");
	}
}
	
MushiDBResult* MushiDB::query(const std::string sql){
        printf("%s\n",sql.c_str());
	MushiDBResult *r = new MushiDBResult;
	r->sql=(char *)sql.c_str();
	
	sqlite3_get_table(db,r->sql,&r->result,&r->row,&r->column,&r->errMsg);
	if(r->errMsg && strlen(r->errMsg) > 0){
		printf("db error: %s\n",r->errMsg);
	}
	return r;
}

QString MushiDB::escapeQuotes(QString value){
    return value.replace("'","''");
}


/**
 * Creates an update statement from a json value
 */
std::string  MushiDB::json2update(Json::Value &val, std::vector<std::string> &columns,std::string where,std::string table){
	std::vector <std::string>::iterator iter;
	std::ostringstream query;
	query << "UPDATE "<<table<<" SET ";
	for (iter=columns.begin(); iter!=columns.end();iter++){
		if(iter!=columns.begin()){
			query << ", ";
		}
		query << *iter << "='"<< dbin(val.get(*iter,"").asString()) << "'";
		
	}
	if(where!="")
		query << " WHERE " << where;
	query << ";";
	return query.str();
}

/**
 * Creates an insert statement from a json value
 */
std::string  MushiDB::json2insert(Json::Value &val, std::vector<std::string> &columns, std::string table){
	std::vector <std::string>::iterator iter;
	std::ostringstream query;
	query << "INSERT INTO "<<table<<" (";
	for (iter=columns.begin(); iter!=columns.end();iter++){
		if(iter!=columns.begin()){
			query << ", ";
		}
		query << *iter ;
		
	}
	query << ") VALUES (";
	for (iter=columns.begin(); iter!=columns.end();iter++){
		if(iter!=columns.begin()){
			query << ", ";
		}
		query <<  "'"<< dbin(val.get(*iter,"").asString()) << "'";
		
	}
	query << ");";
	
	return query.str();
}

