#ifndef ADDUSERCOMMAND_H
#define ADDUSERCOMMAND_H
#include "../MushiCommand.h"
#include "../MushiSession.h"
class AddUserCommand : public MushiCommand
{

public:

      Json::Value &run(MushiSession &sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine, MushiDB &db);
signals:

public slots:

};

#endif // ADDUSERCOMMAND_H
