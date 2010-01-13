#ifndef SCRIPTENGINE_H
#define SCRIPTENGINE_H

#include <QObject>
#include "mongoose.h"
#include "utils.h"

#include "MushiScriptDB.h"
#include "MushiScriptConn.h"
#include "MushiScriptGlobal.h"

class MushiScriptEngine : public QObject
{
    Q_OBJECT
private:
    MushiScriptDB *scriptDB;
public:
    MushiScriptEngine(struct mg_connection *conn, const struct mg_request_info *ri,void *user_data);
    ~MushiScriptEngine();
    QScriptEngine engine;
};

#endif // SCRIPTENGINE_H
