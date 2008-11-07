/*
 *  MushiSetup.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *
 */
#include "MushiServer.h"
#include "MushiSetup.h"
#include "MushiDB.h"

int MushiSetup::createTables(){
	MushiDBResult *r;
	MushiDB *db = MushiServer::getInstance()->getDB();
	
	r=db->query("create table if not exists user ("
				  "id integer PRIMARY KEY AUTOINCREMENT"
				  ",firstName"
				  ",lastName"
				  ",password"
				  ",email"
				  ",createDate datetime DEFAULT (datetime('NOW'))"
				
				  ")");
	delete r;
	
	
	r=db->query("create table if not exists role ("
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
	delete r;
	
	r=db->query("create table if not exists category ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",name"
				",description"
				",defaultOwnerID integer REFERENCES user(id)"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	delete r;
	
		
	r=db->query("create table if not exists project ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",name"
				",description"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	delete r;
	
	
	r=db->query("create table if not exists projectUser ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",projectID REFERENCES project(id)"
				",userID REFERENCES user(id)"
				",roleID REFERENCES role(id)"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	delete r;
	
	
	r=db->query("create table if not exists task ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",title"
				",description"
				",percentComplete"
				",reporterId"
				",ownerID"
				",projectID"
				",categoryID REFERENCES category(id)"
				",parentTaskID integer REFERENCES task(id)"
				 ",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	delete r;
	
	r=db->query("create table if not exists note ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",someID int"
				",tableName"  //the name of the table to which it should be joined to
				",authorID REFERENCES user(id)"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	delete r;
	
	r=db->query("create table if not exists textHistory ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",someID int"
				",tableName"  //the name of the table to which it should be joined to
				",type"
				",text"
				",originalCreateDate datetime"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	delete r;
	
	
	return 0;
}