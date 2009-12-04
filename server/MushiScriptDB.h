#ifndef MUSHISCRIPTDB_H
#define MUSHISCRIPTDB_H
#include <QtScript>
#include <QObject>


 QScriptValue MushiScriptDBSelect(QScriptContext *ctx, QScriptEngine *eng);
 QScriptValue MushiScriptDBNestedSelect(QScriptContext *ctx, QScriptEngine *eng);
 QScriptValue MushiScriptDBExecute(QScriptContext *ctx, QScriptEngine *eng);
 QScriptValue MushiScriptDBEscapeQuotes(QScriptContext *ctx, QScriptEngine *eng);

#endif // MUSHISCRIPTDB_H
