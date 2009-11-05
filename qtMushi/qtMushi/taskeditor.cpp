#include "taskeditor.h"
#include <QDebug>

TaskEditor::TaskEditor(QWidget *parent) :
    QWidget(parent){
    setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->taskCombo->addItem("");
    connect(this->saveButton,SIGNAL(clicked()),this,SLOT(save()));
    QList<Json::Value>*tasks=static_cast <qtMushi *>(qApp)->taskDirectory.getAllTasks();
    for(int x=0;x<tasks->count();x++){
        this->taskCombo->addItem(tasks->at(x).get("title","").asString().c_str(),QVariant(tasks->at(x).get("id","").asCString()));
    }


}

void TaskEditor::changeEvent(QEvent *e)
{
    switch(e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}


void TaskEditor::save(){


    this->updateStore();

    if(this->store["id"].asString()==""){
        this->store["command"]="addTask";
    }else{
        this->store["command"]="editTask";
    }

    QNetworkRequest request(QUrl(SERVER_LOCATION "/command"));
    request.setRawHeader("Connection" ,"close");
    JSON_WRITE_CLASS writer;

    std::string output="data=";
    std::string buff = writer.write(this->store);
    QByteArray encodedValue=QUrl::toPercentEncoding(QString(buff.c_str()));

    output.append(encodedValue);


    qDebug() << output.c_str();


    reply=qtMushi::netManager->post(request, QByteArray( output.c_str()) );

    connect(this->reply, SIGNAL(finished()), this, SLOT(networkResponse()));
    qDebug()<<"saved.";
}


void TaskEditor::updateStore(){

    this->store["title"]=this->title->text().toStdString();
    this->store["description"]=this->description->toHtml().toStdString();
    this->store["parentTaskID"]=this->taskCombo->itemData(this->taskCombo->currentIndex()).toString().toStdString();
}


void TaskEditor::networkResponse(){
    this->close();
    emit saveComplete();
}


void TaskEditor::updateFromStore(){
    this->title->setText(this->store["title"].asString().c_str());
    this->description->setHtml(this->store["description"].asString().c_str());
    for(int x=0;x<this->taskCombo->count();x++){
        if(this->taskCombo->itemData(x).toString().toStdString()==this->store["parentTaskID"].asString()){
            this->taskCombo->setCurrentIndex(x);
        }
    }
}


void TaskEditor::setStore(Json::Value &s){
    this->store=s;
    this->updateFromStore();
}
