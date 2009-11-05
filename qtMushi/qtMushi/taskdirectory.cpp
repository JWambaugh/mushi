#include "taskdirectory.h"

TaskDirectory::TaskDirectory()
{
    this->refresh();
}


/**
  Refreshes the contents of the directory from the server.
  */
void TaskDirectory::refresh(){
    ServerCommand *command= new ServerCommand(this);

    command->set("command","findTask");

    connect(command,SIGNAL(saveComplete(Json::Value)),this,SLOT(refreshComplete(Json::Value)));
    connect(command,SIGNAL(saveComplete(Json::Value)),command,SLOT(deleteLater()));
    command->send();
}

void TaskDirectory::refreshComplete(Json::Value root){
    Json::Value tickets = root["results"];

    this->tasks.clear();
    for(int index=0;index<tickets.size();++index){
        this->tasks.append(tickets[index]);
    }
    emit updated();
}

QList<Json::Value> *TaskDirectory::getAllTasks(){
    return &this->tasks;
}

QList<Json::Value> *TaskDirectory::getTopLevelTasks(){
    QList<Json::Value> *found=new QList<Json::Value>;
    for(int i =0; i<this->tasks.count();i++){
        if(this->tasks.at(i).get("parentTaskID","").asString()==""){
            found->append(this->tasks.at(i));
        }
    }
    return found;
}

QList<Json::Value> *TaskDirectory::getChildrenOfTask(Json::Value &task){
    QList<Json::Value> *found=new QList<Json::Value>;
    for(int i =0; i<this->tasks.count();i++){
        if(this->tasks.at(i).get("parentTaskID","").asString()==task.get("id","").asString()){
            found->append(this->tasks.at(i));
        }
    }
    return found;

}

Json::Value TaskDirectory::getTaskById(int id){
    for(int i =0; i<this->tasks.count();i++){
        if(this->tasks.at(i).get("parentTaskID","").asInt()==id){
            return this->tasks.at(i);
        }
    }
    Json::Value ret;
    return ret;
}
