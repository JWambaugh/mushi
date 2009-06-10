#include "ScriptCommand.h"
#include "ScriptEngine.h"
#include <QScriptValueList>
ScriptCommand::ScriptCommand(QString path)
{
    this->scriptPath = path;
    //load the code, prepare it for execution
    this->scriptCode=getFileContents(path);
    precompileMJS(this->scriptCode);

}


//TODO: Find a better way of converting objects between Json:Vlues and QSCriptValues (evaling JSON ATM)
Json::Value & ScriptCommand::run(MushiSession sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine){
   // qDebug()<<this->scriptCode;
    JSON_WRITE_CLASS writer;
    QScriptValue object=engine.evaluate(this->scriptCode,this->scriptPath);

    QStringList errors;

    //qDebug() << object.toString();

    if(!object.isFunction()){
      //  qDebug() << "Run function not found in command " <<this->scriptPath<< " run has value of:  "<<runFunction.toString()<<" Skipping...";
        ret["reason"]="Script error occured. Function not found.";
        return ret;
    }
    //Get arguments object
    QScriptValue commandObject = engine.evaluate(QString(writer.write(command).c_str()));
    if(commandObject.isError()){
        qDebug()<<"Command Object:"<< commandObject.toString();
        ret["reason"]="Script error occured.";
        return ret;
    }
    QScriptValue retObject=engine.evaluate(QString(writer.write(ret).c_str()));
    if(retObject.isError()){
        qDebug()<< "RetObject:"<< retObject.toString();
        ret["reason"]="Script error occured.";
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
        }

        ret["reason"]="A script error occurred";
        ret["error"]=errMsg.toStdString();
        return ret;
    }
    if(!rObject.isObject()||rObject.isArray()){
        qDebug()<<"Return value must be an object!";
        ret["reason"]="Script return value not an object";
        return ret;
    }
    ret=scriptValue2Json(rObject);
    return ret;
}
