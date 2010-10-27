#include "mushirequest.h"

MushiRequest::MushiRequest(mg_connection *connection,const struct mg_request_info *request_info,QObject *parent) : QObject(parent){
    this->conn=connection;
    this->read=false;
    this->request_info=request_info;

}


QString MushiRequest::getPost(){
    if(this->read){
        return this->readBuffer;
    }
    char buffer[1000];

    while(mg_read(this->conn,&buffer,1000) > 0){
        this->readBuffer.append(buffer);
    }
    this->read=true;
    return this->readBuffer;
}

QString MushiRequest::getURI(){
    return QString(this->request_info->uri);
}

QString MushiRequest::getMethod(){
    return QString(this->request_info->request_method);
}


void MushiRequest::write(QString data){
    mg_write(this->conn,data.toStdString().c_str(),data.length());
}

void MushiRequest::write(std::string data){

    mg_write(this->conn,data.c_str(),data.length());
}

void MushiRequest::write(char *data){

    mg_write(this->conn,data,strlen(data));
}







