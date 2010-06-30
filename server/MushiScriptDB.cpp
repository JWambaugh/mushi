#include "MushiScriptDB.h"
#include "MushiServer.h"
#include "MushiDB.h"
#include <vector>
#include <string>


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


QScriptValue getProperty(QScriptContext *ctx, QScriptEngine *eng){
     QString name = ctx->argument(0).toString();
     return ctx->thisObject().property(name);
}

QScriptValue MushiScriptDB::exec(QString query){
    //MushiDB *db = MushiServer::getInstance()->getDB();
    db.query(query.toStdString());
    QScriptValue val;
    return val;
}

QScriptValue MushiScriptDB::json2Update(QScriptValue cmd,QScriptValue cols, QString where,QString table ){
  //  MushiDB *db = MushiServer::getInstance()->getDB();
    Json::Value command = scriptValue2Json(cmd);

    std::vector<std::string> columns;
    QScriptValueIterator it(cols);
    while(it.hasNext()){
        it.next();
        columns.push_back(it.value().toString().toStdString());
    }

    std::string _where = where.toStdString();
    std::string _table = table.toStdString();

    QScriptValue val(this->engine(),QString( db.json2update(command,columns,_where,_table).c_str()));
    return val;
}

QScriptValue MushiScriptDB::json2Insert(QScriptValue cmd,QScriptValue cols, QString table ){
  //  MushiDB *db = MushiServer::getInstance()->getDB();
    Json::Value command = scriptValue2Json(cmd);

    std::vector<std::string> columns;
    QScriptValueIterator it(cols);
    while(it.hasNext()){
        it.next();
        columns.push_back(it.value().toString().toStdString());
    }


    std::string _table = table.toStdString();

    QScriptValue val(this->engine(),QString( db.json2insert(command,columns,_table).c_str()));
    return val;
}

QScriptValue MushiScriptDB::escapeQuotes(QString value){
  //  MushiDB *db = MushiServer::getInstance()->getDB();
    QScriptValue val(this->engine(),db.escapeQuotes(value));
    return val;
}
