/*
 *  utils.cpp
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "time.h"
#include <unistd.h>
#include <string.h>

std::string uID(){
	std::ostringstream str;
	time_t t;
	t=time(&t);
	str << t << random();
	return str.str();
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


std::string replaceOnce(
						std::string result, 
						const std::string& replaceWhat, 
						const std::string& replaceWithWhat)
{
	const int pos = result.find(replaceWhat);
	if (pos==-1) return result;
	result.replace(pos,replaceWhat.size(),replaceWithWhat);
	return result;
}

std::string dbin(std::string str){
	int pos=0;
	while((pos= str.find("'", pos))!=-1){
		
		str.replace(pos,1,"''");
		pos+=2;
	}
	return str;
}




