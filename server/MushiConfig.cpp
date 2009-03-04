/*
 *  MushiConfig.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MushiServer.h"
#include "MushiConfig.h"

QString MushiConfig::getValue(QString key){
	MushiDB *db = MushiServer::getInstance()->getDB();
	MushiDBResult *r;
	char query[1000];
        QString cell;
        sprintf(query,"select value from config where key = '%s'",key.toStdString().c_str());
	
	r=db->query(query);
	//free(query);

        cell = r->getCell(1, 0);
	delete r;

        return cell;
}


int MushiConfig::setValue(QString key, QString value){
	MushiDB *db = MushiServer::getInstance()->getDB();
	MushiDBResult *r;
	char query[1000];

	//check to see if the key already exists
        sprintf(query,"select * from config where key='%s'",value.toStdString().c_str(),key.toStdString().c_str());
	
	r=db->query(query);
	delete r;
	if(r->row>0){
                sprintf(query,"update config set value='%s' where key='%s'",value.toStdString().c_str(),key.toStdString().c_str());
		r=db->query(query);
	} else {
        sprintf(query,"insert into config (key,value) VALUES ('%s','%s')",key.toStdString().c_str(),value.toStdString().c_str());
		
		r=db->query(query);
		
	}
	
	
	delete r;
	return 1;
}








void MushiConfig::setDefaults(){
	setValue("listenPort","8080");
	setValue("trackerName","Mushi");
	setValue("membersOnly","1");
	setValue("webAddess","http://www.example.com");
	setValue("adminEmail","admin@example.com");
        setValue("defaultStatusID","1");

        //default directory settings
        setValue("interfaceDirectory","../interface");
        setValue("binDirectory",".");
        setValue("scriptDirectory","../script");
        setValue("commandDirectory","../script/command");
        setValue("databaseDirectory","../data");
	
	
}	




