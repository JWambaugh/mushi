/*
 *  utils.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.

 *
 */


char *uID();

char *getPostBody(char *);
std::string replaceOnce(
						std::string result, 
						const std::string& replaceWhat, 
						const std::string& replaceWithWhat);