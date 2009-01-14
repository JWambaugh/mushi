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

/*
 Returns the results as a json array of json objects
 */
Json::Value MushiDBResult::getJson(){
	Json::Value rslt(Json::arrayValue);
	for(int r=1;r<this->row+1;r++){
		Json::Value row;
		for(int c=0;c<this->column;c++){
			row[this->getCell(0, c)] =this->getCell(r, c); 
		}
		rslt.append(row);
	}
	return rslt;
}

/*
 * Returns the result as a json array of json objects.
 * Each json object may have nested json objects. 
 * The column names specify the path to the nested object, with each object name seperated by an underscore.
 */
Json::Value MushiDBResult::getNestedJson(){
	Json::Value rslt(Json::arrayValue);
	for(int r=1;r<this->row+1;r++){
		Json::Value row;
		for(int c=0;c<this->column;c++){
			Json::Value obj;
			this->setNestedJsonObjectValue(row,this->getCell(0, c),this->getCell(r, c));
			
		}
		rslt.append(row);
	}
	return rslt;
}




void MushiDBResult::setNestedJsonObjectValue(Json::Value &parent,std::string name,std::string setValue){
	int endPos=0;
	std::string subName;
	
	endPos=name.find('_',0);
	if(std::string::npos!=endPos){
		subName=name.substr(0,endPos);
		Json::Value val;
		
		if(!parent.isMember(subName)){
			parent[subName]=val;
		}
		this->setNestedJsonObjectValue(parent[subName],name.substr(endPos+1),setValue);
	}
	else {
		parent[name]=setValue;
	}
	
}






