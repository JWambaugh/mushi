/*
 *  MushiDBResult.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */
#ifndef MUSHIDB_RESULT
#define MUSHIDB_RESULT

class MushiDBResult{
public:
	~MushiDBResult();
	MushiDBResult();
	char *sql;     /* SQL to be evaluated */
	char **result;    /* Results of the query */
	int row;           /* Number of result rows written here */
	int column;        /* Number of result columns written here */
	char *errMsg;       /* Error msg written here */
	char *getCell(int,int);
private:
	int currentRow;
	
};
#endif