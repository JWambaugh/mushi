#include "taskmanager.h"

#include "taskEditor.h"
TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent){
    setupUi(this);

    finder = new taskFinder();
    this->taskFinderLayout->addWidget(finder);
    connect(this->newButton,SIGNAL(clicked()),this,SLOT(newTask()));
    connect(this->deleteButton,SIGNAL(clicked()),this,SLOT(deleteTask()));
    connect(this->quickSearchButton,SIGNAL(clicked()),this,SLOT(quickSearch()));
}

void TaskManager::changeEvent(QEvent *e)
{
    switch(e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}


void TaskManager::newTask(){
    TaskEditor* task = new TaskEditor();
    connect(task,SIGNAL(saveComplete()),this->finder,SLOT(search()));
    task->show();
}

void TaskManager::deleteTask(){
    ServerCommand *command = new ServerCommand(this);
    Json::Value task = this->finder->getSelectedRecord();

    command->set("command","deleteTask");
    command->set("id",task.get("id","").asString().c_str());
    command->send();
    connect(command,SIGNAL(saveComplete(Json::Value)),this->finder,SLOT(search()));
    connect(command,SIGNAL(saveComplete(Json::Value)),command,SLOT(deleteLater()));
}

void TaskManager::quickSearch(){
    this->finder->search(this->quickSearchEdit->text());
}

/*
void TaskManager::quickSearch(){

}*/
