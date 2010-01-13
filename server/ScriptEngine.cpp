#include "ScriptEngine.h"
#include "MushiConfig.h"
MushiScriptEngine::MushiScriptEngine(struct mg_connection *conn, const struct mg_request_info *ri,void *user_data)
{

    //create global Mushi object
    QScriptValue mushiObject = engine.newObject();
    //expose conn object to script userspace
    MushiScriptConn *connObject = new MushiScriptConn(conn,ri,user_data);
    QScriptValue connObjectValue= engine.newQObject(connObject,QScriptEngine::QtOwnership,0);

    QScriptValue globalObject=engine.globalObject();
    mushiObject.setProperty("conn", connObjectValue);




    scriptDB = new MushiScriptDB();
     //expose MushiScriptDB to javascript!
    QScriptValue dbObject = engine.newQObject(scriptDB);
    /*dbObject.setProperty("select", engine.newFunction(MushiScriptDBSelect));
    dbObject.setProperty("nestedSelect", engine.newFunction(MushiScriptDBNestedSelect));
    dbObject.setProperty("exec", engine.newFunction(MushiScriptDBExecute));
    dbObject.setProperty("escapeQuotes",engine.newFunction(MushiScriptDBEscapeQuotes));
*/
    mushiObject.setProperty("db",dbObject);


    QScriptValue configObject = engine.newQObject(new MushiConfig);


    mushiObject.setProperty("config",configObject);


    //expose global functions

    mushiObject.setProperty("include",engine.newFunction(MushiScriptGlobalInclude));
    mushiObject.setProperty("log",engine.newFunction(MushiScriptGlobalLog));
    mushiObject.setProperty("sendMail",engine.newFunction(MushiScriptGlobalSendMail));
    QString contents;

    globalObject.setProperty("Mushi",mushiObject);


    //load startup script
    QString startupFileName=MushiConfig::getValue("scriptDirectory");
    startupFileName.append("/startup.mjs");
    contents=getFileContents(startupFileName);
    engine.evaluate(contents);
}


MushiScriptEngine::~MushiScriptEngine(){
    delete this->scriptDB;
}
