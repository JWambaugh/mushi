
#include <stdio.h>
#include <sstream>
#include <QStringList>
#include "../../lib_json/value.h"

#include "../MushiServer.h"
#include "PluginCommand.h"

Json::Value &PluginCommand::run(MushiSession &sess, Json::Value &command, Json::Value &ret, QScriptEngine &engine, MushiDB &db){
    JSON_WRITE_CLASS writer;
    QScriptValue pluginObject;
    pluginObject=engine.globalObject().property("Mushi");

    if(!pluginObject.isValid()){
        qDebug()<<"PluginCommand error: could not get Mushi object from global scope";\
        return ret;
    }

    pluginObject=pluginObject.property("Plugin");
    if(!pluginObject.isValid()){
        qDebug()<<"PluginCommand error: there is no Plugin object within Mushi global object";\
        return ret;
    }

    //Get list of plugins
    QScriptValue plugins;
    plugins = pluginObject.property("registeredPlugins");
    if(!plugins.isArray()){
        qDebug()<<"PluginCommand error: Mushi.Plugin.registeredPlugins is not a valid array";
        return ret;
    }

    QScriptValueIterator pluginIterator(plugins);
    //leave if there aren't any plugins
    if(!pluginIterator.hasNext()){
        qDebug()<<"No plugins. Exiting PluginCommand.";
        return ret;
    }


    //Get command object
    QScriptValue commandObject = engine.evaluate(QString(writer.write(command).c_str()).prepend("(").append(")"));
    if(commandObject.isError()){
        //qDebug()<<"Command Object:"<< commandObject.toString();
        ret["reason"]="Script error occured.";
        return ret;
    }

    //get results object
    QScriptValue retObject=engine.evaluate(QString(writer.write(ret).c_str()).prepend("(").append(")"));
    if(retObject.isError()){
        //qDebug()<< "RetObject:"<< retObject.toString();
        ret["reason"]="Script error occured while evaluating response.";
        return ret;
    }



    while(pluginIterator.hasNext()){
        pluginIterator.next();
        QScriptValue cmd = pluginIterator.value().property("_commandHandler");
        if(!cmd.isFunction()){
           // qDebug()<<"PluginCommand warning: _commandHandler is not a function in plugin " << pluginIterator.value().property("_name").toString()<<". Skipping...";
            continue;
        }
        QScriptValueList args;
        args << commandObject << retObject;
        retObject=cmd.call(pluginIterator.value(),args);
    }

    //Check for interpreter errors
    QStringList errors = engine.uncaughtExceptionBacktrace();
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

   ret=scriptValue2Json(retObject);

   return ret;

}
