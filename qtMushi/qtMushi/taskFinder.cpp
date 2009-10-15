
#include "taskFinder.h"
#include "tasktreewidgetitem.h"
#include "taskeditor.h"
taskFinder::taskFinder(QWidget *parent) : QWidget(parent){


        this->reply=0;
        treeWidget = new QTreeWidget(this);
        treeWidget->setColumnCount(2);
        QStringList header;

        header<<"Title"<<"Owner"<<"Description"<<"status";
        treeWidget->setHeaderLabels(header);

        layout = new QVBoxLayout();
        layout->addWidget(treeWidget);
        this->setLayout(layout);
        search();
        connect(treeWidget,SIGNAL(itemActivated(QTreeWidgetItem*,int)),this,SLOT(itemActivated(QTreeWidgetItem*,int)));


}

void taskFinder::search(){
        //attempt to get all tickets
        if(this->reply)return;
        QNetworkRequest request(QUrl(SERVER_LOCATION "/command"));
        request.setRawHeader("Connection" ,"close");

        reply = qtMushi::netManager->post(request, QUrl::toPercentEncoding("data={\"command\":\"findTask\"}" ) );
        connect(this->reply, SIGNAL(finished()), this, SLOT(networkResponse()));
}


void taskFinder::search(QString text){
        //attempt to get all tickets
        if(this->reply)return;
        QNetworkRequest request(QUrl(SERVER_LOCATION "/command"));
        request.setRawHeader("Connection" ,"close");
        QStringList command;
        command<<"data={\"command\":\"findTask\",\"title\":\""<< text <<"\"}";
        reply = qtMushi::netManager->post(request, QUrl::toPercentEncoding(command.join("") ));
        connect(this->reply, SIGNAL(finished()), this, SLOT(networkResponse()));
}

QString html2plaintext(QString string);

void taskFinder::networkResponse(){
        QString r = reply->readAll();
        qDebug() << r;
        Json::Reader reader;
        Json::Value root;
        reader.parse(r.toStdString(),root);
        tickets = root["results"];

        treeWidget->clear();
        taskTreeWidgetItem *item;
        for(int index=0;index<tickets.size();++index){
            item =  new taskTreeWidgetItem(treeWidget);
            item->taskValue = tickets[index];
            item->setText(0,item->taskValue.get("title","NULL").asCString());
            item->setText(1,item->taskValue.get("owner","").get("firstName","").asCString());
            item->setText(2,html2plaintext(item->taskValue.get("description","NULL").asCString()).left(100).replace("\n"," "));
            item->setText(3,item->taskValue.get("status","NULL").asCString());
            treeWidget->addTopLevelItem(item);
        }
        delete this->reply;
        this->reply=0;
}

QString html2plaintext(QString string){
    QTextEdit *editor=new QTextEdit();
    editor->setHtml(string);
    string = editor->toPlainText();
    delete editor;
    return string;
}

Json::Value taskFinder::getSelectedRecord(){
    taskTreeWidgetItem *item = static_cast<taskTreeWidgetItem *>(this->treeWidget->currentItem());
    return item->taskValue;
}

void taskFinder::itemActivated(QTreeWidgetItem *item,int column){
    taskTreeWidgetItem *tItem = static_cast<taskTreeWidgetItem *> (item);
    TaskEditor *editor=new TaskEditor();
    editor->setStore(tItem->taskValue);
    connect(editor,SIGNAL(saveComplete()),this,SLOT(search()));
    editor->show();
}
