#ifndef PLUGINCOMMAND_H
#define PLUGINCOMMAND_H

/*
 *  GetAuthorsCommand.h
 *  server
 *
 *  Created by Jordan Wambaugh on 11/18/08.
 *
 */

#include "../MushiCommand.h"
#include "../MushiSession.h"

class PluginCommand: public MushiCommand {
public:
        Json::Value &run(MushiSession &sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine, MushiDB &db);


private:



};

#endif // PLUGINCOMMAND_H
