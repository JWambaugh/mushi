#ifndef SCRIPTCOMMAND_H
#define SCRIPTCOMMAND_H


#include "MushiCommand.h"
#include "MushiSession.h"
#include <stdio.h>
#include <sstream>
#include "../lib_json/value.h"
#include "MushiServer.h"
#include "utils.h"


class ScriptCommand : public MushiCommand
{
public:
    ScriptCommand(QString path);
    QString scriptPath;
    QString scriptCode;
};

#endif // SCRIPTCOMMAND_H
