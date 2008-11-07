/*
 *  MushiDBResult.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.

 *
 */
#include "sqlite3.h"
#include "MushiDBResult.h"

MushiDBResult::~MushiDBResult(){
	if(this->result!=0);
	sqlite3_free_table(this->result);
}

MushiDBResult::MushiDBResult(){
	currentRow=0;
	result=0;
}


char * MushiDBResult::getCell(int _row, int _column){
	if(_row > row)return 0;
	if(_column > column)return 0;
	return *(result+((_row*this->column)+_column));
}