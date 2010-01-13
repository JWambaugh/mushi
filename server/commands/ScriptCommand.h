#ifndef SCRIPTCOMMAND_H
#define SCRIPTCOMMAND_H


#include "../MushiCommand.h"
#include "../MushiSession.h"
#include <stdio.h>
#include <sstream>
#include <qmutex>
#include "../../lib_json/value.h"
#include "../MushiServer.h"
#include "../utils.h"
#include "../ScriptEngine.h"

class ScriptCommand : public MushiCommand
{
public:
    QMutex mutex;
    ScriptCommand(QString path);
    QString scriptPath;
    QString scriptCode;
    QScriptProgram *program;
    Json::Value &run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine, MushiDB &db);
};

#endif // SCRIPTCOMMAND_H
