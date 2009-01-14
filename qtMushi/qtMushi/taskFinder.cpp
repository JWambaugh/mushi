
#include "taskFinder.h"
#include "tasktreewidgetitem.h"
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



}

void taskFinder::search(){
        //attempt to get all tickets
        if(this->reply)return;
        QNetworkRequest request(QUrl(SERVER_LOCATION "/command"));
        request.setRawHeader("Connection" ,"close");

        reply = qtMushi::netManager->post(request, QByteArray("data=%7B%0D%0A%22command%22%3A%22findTask%22%0D%0A%0D%0A%7D" ) );
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
            item->setText(2,html2plaintext(item->taskValue.get("description","NULL").asCString()));
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
