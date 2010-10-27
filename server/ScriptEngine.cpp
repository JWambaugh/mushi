#include "ScriptEngine.h"
#include "MushiConfig.h"
#ifndef MUSHI_SERVER_H
#include "MushiServer.h"
#endif



MushiScriptEngine::MushiScriptEngine()
{


    this->init();
    this->initScripts();

}


void MushiScriptEngine::init(){
    //create global Mushi object
    QScriptValue mushiObject = engine.newObject();
    QScriptValue globalObject=engine.globalObject();




    scriptDB = new MushiScriptDB();
     //expose MushiScriptDB to javascript!
    QScriptValue dbObject = engine.newQObject(scriptDB);

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


    globalObject.setProperty("Mushi",mushiObject);




}

MushiScriptEngine::MushiScriptEngine(MushiRequest &request){
    this->init();
    this->setConnData(request);
    this->initScripts();
}

void MushiScriptEngine::setConnData(MushiRequest &request){
    QScriptValue globalObject=engine.globalObject();

    //get global Mushi object
    QScriptValue mushiObject = globalObject.property("Mushi");
    //expose conn object to script userspace
    MushiScriptConn *connObject = new MushiScriptConn(request);
    QScriptValue connObjectValue= engine.newQObject(connObject,QScriptEngine::QtOwnership,0);
    mushiObject.setProperty("conn", connObjectValue);


}


void MushiScriptEngine::initScripts(){
     QString contents;
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

    //load plugins

    QDir scriptDir(MushiConfig::getValue("pluginsDirectory","../script/plugin"));
    QFileInfoList files;
    //qDebug()<<scriptDir.absolutePath();
    files=scriptDir.entryInfoList(QStringList("*.mjs"));
   // qDebug()<<files.size();
    for(int  x=0;x<files.size();x++){
        if(files.at(x).isFile()){
            //qDebug()<<"loading"<<files.at(x).absoluteFilePath();
            contents=getFileContents(files.at(x).absoluteFilePath());
            precompileMJS(contents);
            //qDebug()<<contents;
            engine.evaluate(contents);
            errors = engine.uncaughtExceptionBacktrace();
            if(errors.size()){
                printf("%s\n",engine.uncaughtException().toString().toStdString().c_str());
                for (int i = 0; i < errors.size(); ++i)
                     qDebug()<<errors.at(i);
                qDebug()<<contents;
            }
        }
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



