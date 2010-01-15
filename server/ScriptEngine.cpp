#include "ScriptEngine.h"
#include "MushiConfig.h"
#ifndef MUSHI_SERVER_H
#include "MushiServer.h"
#endif
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


    //add script engine to script space
    QScriptValue engineObject =engine.newQObject(this);
    mushiObject.setProperty("engine",engineObject);


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
    QStringList errors;
    errors = engine.uncaughtExceptionBacktrace();
    if(errors.size()){
        printf("%s\n",engine.uncaughtException().toString().toStdString().c_str());
        for (int i = 0; i < errors.size(); ++i)
             qDebug()<<errors.at(i);
    }
}


MushiScriptEngine::~MushiScriptEngine(){
    delete this->scriptDB;
}



QScriptValue MushiScriptEngine::runCommand(QScriptValue command){
    Json::Value response;
    QScriptValue val;
    JSON_WRITE_CLASS writer;
    response= MushiServer::getInstance()->runCommand(scriptValue2Json(command), *this, this->scriptDB->db);
   // qDebug()<<"here"<<writer.write(response).c_str();
    val=this->engine.evaluate(QString(writer.write(response).c_str()).prepend("(").append(")"));
    return val;
}



