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

#include "MushiDBResult.h"

class MushiDB {
public:
	void init();
	sqlite3 *getHandle();
	MushiDBResult * query(const char *sql);
	
private:
	sqlite3 *db;

	
	};
				 
				 
 
				 
				 
				 
#endif