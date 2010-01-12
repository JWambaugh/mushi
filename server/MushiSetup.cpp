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
		MushiSetup::insertDefaults();
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
                                ",description"
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
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");


        db->query("create table if not exists right ("
                                "id integer PRIMARY KEY AUTOINCREMENT"
                                ",name"
                                ",description"
                                ",createDate datetime DEFAULT (datetime('NOW'))"
                                ")");

        db->query("create table if not exists roleRight ("
                                "id integer PRIMARY KEY AUTOINCREMENT"
                                "rightID integer REFERENCES right(id)"
                                "roleID integer REFERENCES role(id)"
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
                                ",reporterID"
				",ownerID"
				",projectID"
				",estimate"
                                ",originalEstimate"
				",statusID"
				",categoryID REFERENCES category(id)"
				",parentTaskID integer REFERENCES task(id)"
				",createDate datetime DEFAULT (datetime('NOW'))"
				")");
	
	
	db->query("create table if not exists note ("
				"id integer PRIMARY KEY AUTOINCREMENT"
				",someID int"
				",tableName"  //the name of the table to which it should be joined to
                                ",timeSpent" //amouunt of time spent on the task
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
	
	db->query("create table if not exists status ("
                          "id integer PRIMARY KEY AUTOINCREMENT"
			  ",name"
			  ",isOpen"
			  ",createDate datetime DEFAULT (datetime('NOW'))"
			  ")");
	return 0;
}



void MushiSetup::insertDefaults(){
	MushiDB *db = MushiServer::getInstance()->getDB();
	
	//add statuses
	db->query("insert into status (name, isOpen) VALUES ('New',1);"
			  "insert into status (name, isOpen) VALUES ('Accepted',1);"
			  "insert into status (name, isOpen) VALUES ('In Development',1);"
			  "insert into status (name, isOpen) VALUES ('Dev. Completed',1);"
			  "insert into status (name, isOpen) VALUES ('QA Testing',1);"
			  "insert into status (name, isOpen) VALUES ('QA Completed',1);"
			  "insert into status (name, isOpen) VALUES ('Closed',0);"
			  "insert into status (name, isOpen) VALUES ('Duplicate',0);"
			  "insert into status (name, isOpen) VALUES ('Rejected',0);"
			  "insert into status (name, isOpen) VALUES ('Won''t Fix',0);"
			  "insert into status (name, isOpen) VALUES ('Cannot Duplicate',0);");
	
	//temp user
	db->query("insert into user (firstName, lastName, password, email) values ('Jordan', 'Wambaugh', 'password', 'jordan@wambaugh.org')");

	//insert roles
	db->query("insert into role (name, description, isAdmin, createTask, modifyTask, deleteTask, modifyProject, deleteProject) values ('System Administrator','One who administers the system and thus requires full access to all', 1,1, 1, 1, 1, 1);"
			  "insert into role (name, description, isAdmin, createTask, modifyTask, deleteTask, modifyProject, deleteProject) values ('Developer','A regular developer, can''t delete projects', 0, 1, 1, 1, 1, 0);"
			  //template//  "('','', 1,1, 1, 1, 1, 1)	
	);
}

/*
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
*/
