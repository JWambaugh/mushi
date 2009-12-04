#include "statusdirectory.h"

StatusDirectory::StatusDirectory()
{
    this->refresh();
}


/**
  Refreshes the contents of the directory from the server.
  */
void StatusDirectory::refresh(){
    ServerCommand *command= new ServerCommand(this);

    command->set("command","getStatuses");

    connect(command,SIGNAL(saveComplete(Json::Value)),this,SLOT(refreshComplete(Json::Value)));
    connect(command,SIGNAL(saveComplete(Json::Value)),command,SLOT(deleteLater()));
    command->send();
}

void StatusDirectory::refreshComplete(Json::Value root){
    Json::Value tickets = root["results"];

    this->statuses.clear();
    for(int index=0;index<tickets.size();++index){
        this->statuses.append(tickets[index]);
    }
    emit updated();
}


QList<Json::Value> *StatusDirectory::getAllStatuses(){
    return &this->statuses;
}


Json::Value StatusDirectory::getStatusByID(QString id){
    for(int x=0;x< this->statuses.count();x++){
        if(this->statuses.at(x).get("id","").asString()==id.toStdString()){
            return this->statuses.at(x);
        }
    }
    Json::Value blank;
    return blank;
}
