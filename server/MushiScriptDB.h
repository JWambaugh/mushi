#ifndef MUSHISCRIPTDB_H
#define MUSHISCRIPTDB_H
#include <QtScript>
#include <QObject>

#include <QScriptable>
#include "MushiDB.h"

class MushiScriptDB :public QObject, protected QScriptable{
    Q_OBJECT
private:
    MushiDB db;
public:
     MushiScriptDB();
public slots:
    QScriptValue select(QString);
    QScriptValue nestedSelect(QString);
    QScriptValue execute(QString);
    QScriptValue escapeQuotes(QString);
};



#endif // MUSHISCRIPTDB_H
