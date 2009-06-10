#include "MushiScriptGlobal.h"


QScriptValue MushiScriptGlobalInclude(QScriptContext *ctx, QScriptEngine *engine){
   QScriptValue val;
   QString fileName= ctx->argument(0).toString();

   QString contents= getFileContents(fileName);
   precompileMJS(contents);
 //  printf("%s\n",contents.toStdString().c_str());
   //go up one in scope
   ctx->setActivationObject(ctx->parentContext()->activationObject());
   ctx->setThisObject(ctx->parentContext()->thisObject());
    //eval the code
   engine->evaluate(contents,fileName);

    return val;
}


QScriptValue MushiScriptGlobalLog(QScriptContext *ctx, QScriptEngine *engine){
   QScriptValue val;
   qDebug()<<"Script Log: "<< ctx->argument(0).toString();

    return val;
}
