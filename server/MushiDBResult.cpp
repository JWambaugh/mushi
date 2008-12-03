/*
 *  MushiDBResult.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.

 *
 */
#include <stdio.h>
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
	if(_row > row)return "";
	if(_column > column)return "";
	char * row = *(result+((_row*this->column)+_column));
	if(row==0){
		return "";
	} else{
		return row;
	}
}