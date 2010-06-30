#ifndef MUSHISCRIPTDB_H
#define MUSHISCRIPTDB_H
#include <QtScript>
#include <QObject>

#include <QScriptable>
#include "MushiDB.h"

class MushiScriptDB :public QObject, protected QScriptable{
    Q_OBJECT
private:

public:
     MushiDB db;
     MushiScriptDB();
public slots:
    QScriptValue select(QString);
    QScriptValue nestedSelect(QString);
    QScriptValue exec(QString);
    QScriptValue escapeQuotes(QString);
    QScriptValue json2Update(QScriptValue cmd,QScriptValue cols, QString where,QString table );
    QScriptValue json2Insert(QScriptValue cmd,QScriptValue cols, QString table );
};



#endif // MUSHISCRIPTDB_H
