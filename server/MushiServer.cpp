/*
 *  MushiServer.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/6/08.
 *
 */

#ifdef _WIN32
#include <winsock.h>
#define	snprintf			_snprintf

#ifndef _WIN32_WCE
#ifdef _MSC_VER /* pragmas not valid on MinGW */
#endif /* _MSC_VER */

#else /* _WIN32_WCE */
/* Windows CE-specific definitions */
#pragma comment(lib,"ws2")
//#include "compat_wince.h"
#endif /* _WIN32_WCE */

#else
#include <sys/types.h>
#include <sys/select.h>
#include <sys/wait.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


#include "../shttpd/shttpd.h"
#include "MushiServer.h"
#include "URLHandlers.h"
#include "MushiDB.h"
#include "MushiSetup.h"


MushiServer::MushiServer(){

}




MushiServer * MushiServer::instance = 0;


MushiDB * MushiServer::getDB(){
	return db;
}

MushiServer * MushiServer::getInstance(){
		if (instance == 0)  // is it the first call?
		{  
			instance = new MushiServer; // create sole instance
		}
		return instance; // address of sole instance
	
}	


void MushiServer::defineHandlers(){
	
	shttpd_register_uri(ctx, "/", &::m_show_index,NULL);

}





void MushiServer::startup(int argc, char *argv[]){
	printf("\n\nMushi Tracker server version %s\n", MUSHI_SERVER_VERSION);
	/* Get rid of warnings */
	argc = argc;
	argv = argv;
	
	
	db=new MushiDB();
	db->init();
	//build our tables!
	MushiSetup::createTables();
	
	
	ctx = shttpd_init(argc, argv);
	//	shttpd_set_option(ctx, "ssl_cert", "shttpd.pem");
	shttpd_set_option(ctx, "ports", "8080");
	
		
	
	//shttpd_handle_error(ctx, 404, show_404, NULL);
	defineHandlers();
	
    printf("Server started.\n");
	
	
	

	
	
	
	/* Serve connections infinitely until someone kills us */
	while(1){
		shttpd_poll(ctx, 1000);
	}
	/* Probably unreached, because we will be killed by a signal */
	shttpd_fini(ctx);
	
}	

