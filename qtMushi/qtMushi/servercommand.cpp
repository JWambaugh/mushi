#include "servercommand.h"
#include <QApplication>
#include "qtMushi.h"



ServerCommand::ServerCommand(QObject *parent=0):QObject(parent)
{
}

ServerCommand::ServerCommand(Json::Value val, QObject *parent=0):QObject(parent){
    this->jsonObject=val;
}



QString ServerCommand::get(QString key){
    return QString(this->jsonObject.get(key.toStdString(),"").asString().c_str());
}

void ServerCommand::set(QString key, QString value){
    this->jsonObject[key.toStdString().c_str()]=value.toStdString().c_str();
}

void ServerCommand::send(){
    qtMushi *mushi = static_cast<qtMushi *>(QApplication::instance());
    Json::StyledWriter writer;
    QString serverLocation=mushi->getServerLocation();

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(saveComplete(QNetworkReply*)));
    QNetworkRequest request(QUrl(serverLocation.append("/command")));

    manager->post(request,QUrl::toPercentEncoding("data="+QString(writer.write(this->jsonObject).c_str())));

}


void ServerCommand::saveComplete(QNetworkReply *reply){
    Json::Reader reader;
    Json::Value root;
    QString r = reply->readAll();
    qDebug()<<"Server Response: "<<r;
    reader.parse(r.toStdString(),root);
    emit saveComplete(root);
}
