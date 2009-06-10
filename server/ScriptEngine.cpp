#include "ScriptEngine.h"
#include "MushiConfig.h"
MushiScriptEngine::MushiScriptEngine(struct mg_connection *conn, const struct mg_request_info *ri,void *user_data)
{
    //expose conn object to script userspace
    MushiScriptConn *connObject = new MushiScriptConn(conn,ri,user_data);
    QScriptValue connObjectValue= engine.newQObject(connObject,QScriptEngine::QtOwnership,0);

    QScriptValue globalObject=engine.globalObject();
    globalObject.setProperty("_conn", connObjectValue);



    //expose MushiScriptDB to javascript!


    //QScriptValue dbObjectValue= engine.newQObject(new MushiScriptDB(),QScriptEngine::QtOwnership,0);
    //globalObject.setProperty("_db", dbObjectValue);

    QScriptValue dbObject = engine.newObject();
    dbObject.setProperty("select", engine.newFunction(MushiScriptDBSelect));
    dbObject.setProperty("nestedSelect", engine.newFunction(MushiScriptDBNestedSelect));
    dbObject.setProperty("exec", engine.newFunction(MushiScriptDBExecute));
    globalObject.setProperty("_db",dbObject);


    QScriptValue configObject = engine.newQObject(new MushiConfig);


    globalObject.setProperty("_config",configObject);


    //expose global functions

    globalObject.setProperty("include",engine.newFunction(MushiScriptGlobalInclude));
    globalObject.setProperty("_log",engine.newFunction(MushiScriptGlobalLog));
    QString contents;




    //load startup script
    QString startupFileName=MushiConfig::getValue("scriptDirectory");
    startupFileName.append("/startup.mjs");
    contents=getFileContents(startupFileName);
    engine.evaluate(contents);
}
