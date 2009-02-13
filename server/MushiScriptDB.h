#ifndef MUSHISCRIPTDB_H
#define MUSHISCRIPTDB_H
#include <QtScript>
#include <QObject>


 QScriptValue MushiScriptDBselect(QScriptContext *ctx, QScriptEngine *eng);
   void execute(QString query);

#endif // MUSHISCRIPTDB_H
