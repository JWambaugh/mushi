#include "MushiScriptConn.h"
#include <QDebug>


MushiScriptConn::MushiScriptConn(MushiRequest &request):QObject(0)
{
    this->request=&request;
}



void MushiScriptConn::print(QString string){
    //mg_printf(_conn,"%s",string.toStdString().c_str());
    request->write(string);
    //qDebug() <<"Printing:" <<string;
    //0 printf("Print:%s\n",string.toStdString().c_str());
}

QString MushiScriptConn::userData(){
    return this->request->getPost();
}

QString MushiScriptConn::queryString(){
    //todo:IMPLEMENT querystring
    return QString();
}


QString MushiScriptConn::URI(){
    return this->request->getURI();
}


QString MushiScriptConn::getVar(QString key){
    //TODO: implement getvar
    return QString();
}
