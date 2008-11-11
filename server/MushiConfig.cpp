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

char * MushiConfig::getValue(char *key){
	MushiDB *db = MushiServer::getInstance()->getDB();
	MushiDBResult *r;
	char query[1000];
	char *cell;
	sprintf(query,"select value from config where key = '%s'",key);
	
	r=db->query(query);
	//free(query);
	cell =(char *) malloc(1000);
	strcpy( cell,r->getCell(1, 0));
	delete r;
	return cell;
}


int MushiConfig::setValue(char *key, char *value){
	MushiDB *db = MushiServer::getInstance()->getDB();
	MushiDBResult *r;
	char query[1000];

	//check to see if the key already exists
	sprintf(query,"select * from config where key='%s'",value,key);
	
	r=db->query(query);
	delete r;
	if(r->row>0){
		sprintf(query,"update config set value='%s' where key='%s'",value,key);
		r=db->query(query);
	} else {
	sprintf(query,"insert into config (key,value) VALUES ('%s','%s')",key,value);
		
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
	
}	




