/*
 *  MushiSession.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/10/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */
#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include "utils.h"
#include "MushiSession.h"
#include "MushiServer.h"

void MushiSession::load(QString id){
        char query[200];
	MushiDBResult *r;
	
        sprintf(query,"select * from session where id ='%s'", id.toStdString().c_str());
	r=MushiServer::getInstance()->getDB()->query(query);
	if(r->row > 0){
		
                sprintf(query,"update session set lastSeen=datetime('NOW') where id ='%s'", id.toStdString().c_str());
		
                MushiServer::getInstance()->getDB()->query(query);
		
		
	try {
			Json::Reader reader;
			reader.parse(r->getCell(1,1), this->data);
		} catch (std::exception& e) {
                        printf("Error loading session data for session %s", id.toStdString().c_str());
		}
                data["sessionID"]=id.toStdString();
		
	}else{	//invalid session id
		this->load();
	}
}



void MushiSession::load(){
	std::string id;
	id=uID();
	char query[300];
	sprintf(query,"insert into session (id, data, lastSeen) VALUES ('%s','{}',datetime('NOW'))",id.c_str());
        MushiServer::getInstance()->getDB()->query(query);
	
        this->load(QString(id.c_str()));
}


void MushiSession::save(){
	JSON_WRITE_CLASS writer;
	std::stringstream stream;
	
	std::string jsonCode=writer.write(data);
	stream << "update session set data='"<<jsonCode<<"' where id = '" << data["sessionID"].asString() <<"'";
}




MushiSession::MushiSession(QString id){
        //load(id);
}

MushiSession::MushiSession(QObject *parent) :QObject(parent){
        //load();
}



QString MushiSession::get(QString key){
    return QString(this->data.get(key.toStdString(),"").asCString());
}

void MushiSession::set(QString key, QString value){
    this->data[key.toStdString().c_str()]=value.toStdString();
}
QString MushiSession::getID(){

}

