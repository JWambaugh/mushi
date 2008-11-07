/*
 *  MushiDB.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */
#include <string.h>
#include <stdio.h>
#include "sqlite3.h"
#include "MushiServer.h"
#include "MushiDBResult.h"


sqlite3 * MushiDB::getHandle(){
	return db;
}



void MushiDB::init(){
	//load the database
	if(sqlite3_open("mushiServer.data", &db) != SQLITE_OK){
		printf("An error occured while loading the database: %s\n",sqlite3_errmsg(db));
	} else{
		printf("Successfully loaded database.\n");
	}
}
	
MushiDBResult* MushiDB::query(const char *sql){
	MushiDBResult *r = new MushiDBResult;
	r->sql=(char *)sql;
	
	sqlite3_get_table(db,sql,&r->result,&r->row,&r->column,&r->errMsg);
	if(r->errMsg && strlen(r->errMsg) > 0){
		printf("db error: %s\n",r->errMsg);
	}
	return r;
}



