/*
 *  MushiConfig.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/7/08.
 *  Copyright 2008 Solitex Networks. All rights reserved.
 *
 */


class MushiConfig{
public:
	static char *getValue(char *key);
	static int setValue(char *key, char*value);
	
	static void setDefaults();
};
