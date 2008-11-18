/*
 *  MushiSetup.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *
 */

#include <stdio.h>
#include "MushiServer.h"
#include "MushiSetup.h"
#include "MushiConfig.h"
#include "MushiDB.h"


int MushiSetup::checkStatus(){
	MushiDBResult *r;
	MushiDB *db = MushiServer::getInstance()->getDB();
	
	
	//determine if this is a fresh install. if it is, this query should return an error
	r=db->query("select * from config LIMIT 1");
	if(r->row<1){
		printf("This must be a fresh Mushi Server install. Setting up/initializing with defaults...\n");
		MushiSetup::createTables();
		MushiConfig::setDefaults();
		printf("Completed setup. Have a nice day.\n");
		delete r;
		return 1;
	}
	delete r;
	return 1;
}



int MushiSetup::createTables(){
	MushiDBResult *r;
	MushiDB *db = MushiServer::getInstance()->getDB();
	
	
	db->query("create table if not exists config ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",key"
				",value"
				",createDate datetime DEFAULT (datetime('NOW'))"
				
				")");
	
	
	db->query("create table if not exists user ("
				  "id integer PRIMARY KEY AUTOINCREMENT"
				  ",firstName"
				  ",lastName"
				  ",password"
				  ",email"
				  ",createDate datetime DEFAULT (datetime('NOW'))"
				
				  ")");
	db->query("create table if not exists role ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",name"
				",description"
				",isAdmin bit DEFAULT 0"
				",createTask bit DEFAULT 0"
				",modifyTask bit DEFAULT 0"
				",deleteTask bit DEFAULT 0"
				",modifyProject bit DEFAULT 0"
				",deleteProject bit DEFAULT 0"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	
	
	db->query("create table if not exists category ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",name"
				",description"
				",defaultOwnerID integer REFERENCES user(id)"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	
	db->query("create table if not exists project ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",name"
				",description"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");

	
	r=db->query("create table if not exists projectUser ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",projectID REFERENCES project(id)"
				",userID REFERENCES user(id)"
				",roleID REFERENCES role(id)"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	
	
	db->query("create table if not exists task ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",title"
				",description"
				",percentComplete"
				",reporterId"
				",ownerID"
				",projectID"
				",estimate"
				",categoryID REFERENCES category(id)"
				",parentTaskID integer REFERENCES task(id)"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	
	
	db->query("create table if not exists note ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",someID int"
				",tableName"  //the name of the table to which it should be joined to
				",authorID REFERENCES user(id)"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	
	
	db->query("create table if not exists textHistory ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",someID int"
				",tableName"  //the name of the table to which it should be joined to
				",type"
				",text"
				",originalCreateDate datetime"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	
	db->query("create table if not exists attachment ("
			  "id integer PRIMARY KEY AUTOINCREMENT"
			  ",someID int"
			  ",tableName"  //the name of the table to which it should be joined to
			  ",fileName"
			  ",createDate datetime DEFAULT (datetime('NOW'))"
			  ")");
	
	db->query("create table if not exists session ("
				"id PRIMARY KEY"
				",data"
				",lastSeen datetime"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	
	return 0;
}