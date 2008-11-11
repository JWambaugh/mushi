/*
 *  utils.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "time.h"
#include <unistd.h>
#include <string.h>

char *uID(){
	time_t t;
	char *id;
	t=time(&t);
	id=(char *)malloc(16);
	sprintf(id,"%X%X",t,random());
	return id;
}


/**
 *Returns the body of a post (stripts headers)
 **/
char *getPostBody(char *search){
	char* found;
	printf("%s\n",search);
	found=strstr(search, "\r\n");
	printf("%d", found);
	return search + 4;
}