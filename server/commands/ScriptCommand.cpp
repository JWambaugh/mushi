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
    qDebug()<<this->scriptCode;
    JSON_WRITE_CLASS writer;
    QScriptValue object=engine.evaluate(this->scriptCode,this->scriptPath);

    QStringList errors;
    errors = engine.uncaughtExceptionBacktrace();
    printf("%s\n",engine.uncaughtException().toString().toStdString().c_str());
    for (int i = 0; i < errors.size(); ++i)
          printf("%s\n",errors.at(i).toLocal8Bit().constData());

    qDebug() << object.toString();

    if(!object.isFunction()){
      //  qDebug() << "Run function not found in command " <<this->scriptPath<< " run has value of:  "<<runFunction.toString()<<" Skipping...";
        return ret;
    }
    //Get arguments object
    QScriptValue commandObject = engine.evaluate(QString(writer.write(command).c_str()));
    QScriptValue retObject=engine.evaluate(QString(writer.write(ret).c_str()));
    QScriptValueList args;
    args << commandObject << retObject;
    QScriptValue rObject=object.call(object, args);
    Json::Reader reader;
    reader.parse(rObject.toString().toStdString(),ret);
    return ret;
}
