#ifndef SCRIPTENGINE_H
#define SCRIPTENGINE_H

#include <QObject>
#include <QScriptable>
#include "mongoose.h"
#include "utils.h"

#include "MushiScriptDB.h"
#include "MushiScriptConn.h"
#include "MushiScriptGlobal.h"
#include "mushirequest.h"

class MushiScriptEngine : public QObject, protected QScriptable
{
    Q_OBJECT
private:
    MushiScriptDB *scriptDB;
    void setConnData(MushiRequest &request);
    void init();
    void initScripts();
    MushiRequest *request;
public:
    MushiScriptEngine(MushiRequest &request);
    MushiScriptEngine();

    ~MushiScriptEngine();
    QScriptEngine engine;

public slots:
    QScriptValue runCommand(QScriptValue);
};

#endif // SCRIPTENGINE_H
