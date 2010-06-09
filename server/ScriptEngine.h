#ifndef SCRIPTENGINE_H
#define SCRIPTENGINE_H

#include <QObject>
#include <QScriptable>
#include "mongoose.h"
#include "utils.h"

#include "MushiScriptDB.h"
#include "MushiScriptConn.h"
#include "MushiScriptGlobal.h"


class MushiScriptEngine : public QObject, protected QScriptable
{
    Q_OBJECT
private:
    MushiScriptDB *scriptDB;
    void setConnData(struct mg_connection *conn, const struct mg_request_info *ri,void *user_data);
    void init();
    void initScripts();
public:
    MushiScriptEngine(struct mg_connection *conn, const struct mg_request_info *ri,void *user_data);
    MushiScriptEngine();

    ~MushiScriptEngine();
    QScriptEngine engine;

public slots:
    QScriptValue runCommand(QScriptValue);
};

#endif // SCRIPTENGINE_H
