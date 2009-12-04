#ifndef MUSHISCRIPTGLOBAL_H
#define MUSHISCRIPTGLOBAL_H
#include <QTScript>
#include <QScriptEngine>
#include "utils.h"
#include "smtp.h"
#include "MushiConfig.h"
QScriptValue MushiScriptGlobalInclude(QScriptContext *ctx, QScriptEngine *eng);
QScriptValue MushiScriptGlobalLog(QScriptContext *ctx, QScriptEngine *eng);
QScriptValue MushiScriptGlobalSendMail(QScriptContext *ctx, QScriptEngine *engine);
#endif // MUSHISCRIPTGLOBAL_H
