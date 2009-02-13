#include "MushiScriptDB.h"
#include "MushiServer.h"
#include "MushiDB.h"





QScriptValue MushiScriptDBselect(QScriptContext *ctx, QScriptEngine *eng){
    JSON_WRITE_CLASS writer;
    QString query =ctx->argument(0).toString();
    MushiDBResult *r;
    MushiDB *db = MushiServer::getInstance()->getDB();
    r=db->query(query.toStdString());

    QScriptValue val;
    val = eng->evaluate(QString(writer.write(r->getJson()).c_str()));




    delete r;
    return val;
}
 QScriptValue getProperty(QScriptContext *ctx, QScriptEngine *eng)
 {
     QString name = ctx->argument(0).toString();
     return ctx->thisObject().property(name);
 }

void MushiScriptDBexecute(QScriptContext *ctx, QScriptEngine *eng){
    MushiDB *db = MushiServer::getInstance()->getDB();
    db->query(ctx->argument(0).toString().toStdString());

}
