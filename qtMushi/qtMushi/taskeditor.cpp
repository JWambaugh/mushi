#include "taskeditor.h"
#include <QDebug>

TaskEditor::TaskEditor(QWidget *parent) :
    QWidget(parent){
    setupUi(this);

    connect(this->saveButton,SIGNAL(clicked()),this,SLOT(save()));


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
    QNetworkRequest request(QUrl(SERVER_LOCATION "/command"));
    request.setRawHeader("Connection" ,"close");
    JSON_WRITE_CLASS writer;
    this->store["command"]="addTask";
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
}


void TaskEditor::networkResponse(){
    this->close();
    emit saveComplete();
}

