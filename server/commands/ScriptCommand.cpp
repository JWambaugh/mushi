#include "ScriptCommand.h"
#include "../ScriptEngine.h"
#include <QScriptValueList>
#include <QTime>
ScriptCommand::ScriptCommand(QString path)
{
    this->scriptPath = path;
    //load the code, prepare it for execution
    this->scriptCode=getFileContents(path);
    precompileMJS(this->scriptCode);
    //this->program = new QScriptProgram(this->scriptCode,this->scriptPath);

}


//TODO: Find a better way of converting objects between Json:Vlues and QSCriptValues (evaling JSON ATM)
Json::Value & ScriptCommand::run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine){

    QTime timer;
    this->mutex.lock(); //get exclusive lock on this command object (can't run a program twice on different engines)
   // qDebug()<<this->scriptCode;
    JSON_WRITE_CLASS writer;
    QScriptValue object;
   // qDebug()<<"before eval";

    timer.start();
    object=engine.evaluate(this->scriptCode);
    qDebug()<<"time taken to evaluate " <<this->scriptPath <<":"<<timer.elapsed();


    //qDebug()<<"after eval";
    QStringList errors;

   // qDebug()<<"object " << object.toString();

    if(object.isError()){
        qDebug() << "Error running script " <<this->scriptPath;
        errors = engine.uncaughtExceptionBacktrace();
        //if there are any errors, don't use the ret value.
        QString errMsg;
        for (int i = 0; i < errors.size(); ++i){
            errMsg.append(errors.at(i));
        }

        qDebug()<<errMsg;
        ret["reason"]="Script error occured.";
        return ret;
    }
    else if(!object.isFunction()){
        qDebug() << "Run function not found in command " <<this->scriptPath<<" Skipping...";
        ret["reason"]="Script error occured. Function not found.";
        return ret;
    }
    //Get arguments object
    QScriptValue commandObject = engine.evaluate(QString(writer.write(command).c_str()).prepend("(").append(")"));
    if(commandObject.isError()){
        qDebug()<<"Command Object:"<< commandObject.toString();
        ret["reason"]="Script error occured.";
        return ret;
    }
    QScriptValue retObject=engine.evaluate(QString(writer.write(ret).c_str()).prepend("(").append(")"));
    if(retObject.isError()){
        qDebug()<< "RetObject:"<< retObject.toString();
        ret["reason"]="Script error occured while evaluating response.";
        return ret;
    }

   // qDebug()<<retObject.toString();

    QScriptValueList args;
    args << commandObject << retObject;
    QScriptValue rObject=object.call(object, args);
    errors = engine.uncaughtExceptionBacktrace();
    //if there are any errors, don't use the ret value.
    if(errors.size()){
       QString errMsg;
        for (int i = 0; i < errors.size(); ++i){
              errMsg.append(errors.at(i));
              errMsg.append(engine.uncaughtException().toString());
        }

        ret["reason"]="A script error occurred";
        qDebug()<<errMsg;
        ret["error"]=errMsg.toStdString();
        return ret;
    }
    if(!rObject.isObject()||rObject.isArray()){
        qDebug()<<"Return value must be an object!";
        ret["reason"]="Script return value not an object";
        return ret;
    }
    ret=scriptValue2Json(rObject);
    this->mutex.unlock();

    return ret;
}
