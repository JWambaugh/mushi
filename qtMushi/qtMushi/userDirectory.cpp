#include "userDirectory.h"

UserDirectory::UserDirectory()
{
    this->refresh();
}


/**
  Refreshes the contents of the directory from the server.
  */
void UserDirectory::refresh(){
    ServerCommand *command= new ServerCommand(this);

    command->set("command","getUsers");

    connect(command,SIGNAL(saveComplete(Json::Value)),this,SLOT(refreshComplete(Json::Value)));
    connect(command,SIGNAL(saveComplete(Json::Value)),command,SLOT(deleteLater()));
    command->send();
}

void UserDirectory::refreshComplete(Json::Value root){
    Json::Value tickets = root["results"];

    this->statuses.clear();
    for(int index=0;index<tickets.size();++index){
        this->statuses.append(tickets[index]);
    }
    emit updated();
}


QList<Json::Value> *UserDirectory::getAllUsers(){
    return &this->statuses;
}


Json::Value UserDirectory::getUserByID(QString id){
    for(int x=0;x< this->statuses.count();x++){
        if(this->statuses.at(x).get("id","").asString()==id.toStdString()){
            return this->statuses.at(x);
        }
    }
    Json::Value blank;
    return blank;
}
