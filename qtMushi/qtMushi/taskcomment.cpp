#include "taskcomment.h"
#include "ui_taskcomment.h"

TaskComment::TaskComment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskComment)
{
    ui->setupUi(this);
    //this->connect(this->ui->note->document(),SIGNAL(contentsChanged()),this,SLOT(sizeToContents()));
    this->connect(this->ui->note->document()->documentLayout(),SIGNAL(documentSizeChanged(QSizeF)),this,SLOT(sizeToContents()));
}

TaskComment::~TaskComment()
{
    delete ui;
}


void TaskComment::updateStore(){


    this->store["text"]=this->ui->note->toHtml().toStdString();
}
void TaskComment::updateFromStore(){
    this->ui->note->setHtml(this->store.get("text","").asCString());
    this->ui->authorLabel->setText(this->store.get("noteCreateDate","").asCString());
}

void TaskComment::setParentTaskID(int taskID){
    if(taskID<1){
        qDebug()<<"Cannot set note parent taskID to value less than 1";
        return;
    }
    this->store["taskID"]=taskID;
}

void TaskComment::save(){
    if(this->store.get("id","")!="")return;
    this->updateStore();
    if (this->store.get("taskID","")==""){
        qDebug()<<"Cannot save task note because no parent taskID is set";
        return;
    }
    qDebug()<<"saving task";
    //this->val["command"]="editTask";

    ServerCommand *command= new ServerCommand(this->store,this);
    command->connect(command,SIGNAL(saveComplete(Json::Value)),command,SLOT(deleteLater()));


    command->set("command","addNoteToTask");
    command->send();
}

void TaskComment::sizeToContents(){
    int height = this->ui->note->document()->documentLayout()->documentSize().height();
   // qDebug()<<height;
    if (height<10)return;

    this->setMinimumHeight(height+40);

}




void TaskComment::setReadOnly(bool readOnly){
    this->ui->note->setReadOnly(readOnly);
}
