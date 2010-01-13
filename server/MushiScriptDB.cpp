#include "MushiScriptDB.h"
#include "MushiServer.h"
#include "MushiDB.h"



MushiScriptDB::MushiScriptDB(){

    this->db.init();
}

QScriptValue MushiScriptDB::select(QString query){
    JSON_WRITE_CLASS writer;
   
    MushiDBResult *r;
    //MushiDB *db = MushiServer::getInstance()->getDB();
    r=db.query(query.toStdString());

    QScriptValue val;
    val = this->engine()->evaluate(QString(writer.write(r->getJson()).c_str()));




    delete r;
    return val;
}


QScriptValue MushiScriptDB::nestedSelect(QString query){
    JSON_WRITE_CLASS writer;
    
    MushiDBResult *r;
  //  MushiDB *db = MushiServer::getInstance()->getDB();
    r=db.query(query.toStdString());

    QScriptValue val;
    val = this->engine()->evaluate(QString(writer.write(r->getNestedJson()).c_str()));
    delete r;
    return val;
}


 QScriptValue getProperty(QScriptContext *ctx, QScriptEngine *eng)
 {
     QString name = ctx->argument(0).toString();
     return ctx->thisObject().property(name);
 }

 QScriptValue MushiScriptDB::execute(QString query){
    //MushiDB *db = MushiServer::getInstance()->getDB();
    db.query(query.toStdString());
    QScriptValue val;
    return val;
}

 QScriptValue MushiScriptDB::escapeQuotes(QString value){
  //  MushiDB *db = MushiServer::getInstance()->getDB();
    QScriptValue val(this->engine(),db.escapeQuotes(value));
    return val;
}
