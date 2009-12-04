#include "MushiScriptConn.h"
#include <QDebug>
MushiScriptConn::MushiScriptConn(struct mg_connection *conn, const struct mg_request_info *ri, void *user_data):QObject(0)
{
    _conn=conn;
    _ri=ri;
    _user_data=user_data;
}



void MushiScriptConn::print(QString string){
    mg_printf(_conn,"%s",string.toStdString().c_str());
    qDebug() <<"Printing:" <<string;
    //0 printf("Print:%s\n",string.toStdString().c_str());
}

QString MushiScriptConn::userData(){
    return QString((char *)_user_data);
}

QString MushiScriptConn::queryString(){
    return QString(_ri->query_string);
}


QString MushiScriptConn::URI(){
    return QString(_ri->uri);
}


QString MushiScriptConn::getVar(QString key){
    return (QString (mg_get_var(_conn,key.toStdString().c_str())));
}
