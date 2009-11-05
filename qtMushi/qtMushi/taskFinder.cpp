
#include "taskFinder.h"

#include "taskeditor.h"
taskFinder::taskFinder(QWidget *parent) : QWidget(parent){


        this->reply=0;
        treeWidget = new QTreeWidget(this);
        treeWidget->setColumnCount(3);
        QStringList header;

        header<<"Title"<<"Owner"<<"Status";
        treeWidget->setHeaderLabels(header);

        layout = new QVBoxLayout();
        layout->addWidget(treeWidget);
        this->setLayout(layout);
        search();
        connect(treeWidget,SIGNAL(itemActivated(QTreeWidgetItem*,int)),this,SLOT(itemActivated(QTreeWidgetItem*,int)));
        connect(&static_cast <qtMushi *>(qApp)->taskDirectory,SIGNAL(updated()),this,SLOT(networkResponse()));

}

void taskFinder::search(){
        //attempt to get all tickets
        static_cast <qtMushi *>(qApp)->taskDirectory.refresh();
}


void taskFinder::search(QString text){
        static_cast <qtMushi *>(qApp)->taskDirectory.refresh();
}

QString html2plaintext(QString string);

void taskFinder::networkResponse(){
        QList<Json::Value> *list;
        list=static_cast <qtMushi *>(qApp)->taskDirectory.getTopLevelTasks();
        treeWidget->clear();
        taskTreeWidgetItem *item;
        for(int index=0;index<list->size();index++){
            item =  new taskTreeWidgetItem(treeWidget);
            item->taskValue = list->at(index);
            item->setText(0,item->taskValue.get("title","NULL").asCString());
            item->setText(1,item->taskValue.get("owner","").get("firstName","").asCString());
           // item->setText(2,html2plaintext(item->taskValue.get("description","NULL").asCString()).left(100).replace("\n"," "));
            item->setText(2,item->taskValue.get("status","NULL").asCString());
            treeWidget->addTopLevelItem(item);
            this->addChildrenToTree(item);
        }

}

void taskFinder::addChildrenToTree(taskTreeWidgetItem *parent){
    QList<Json::Value> *list;
    list=static_cast <qtMushi *>(qApp)->taskDirectory.getChildrenOfTask(parent->taskValue);
    taskTreeWidgetItem *item;
    for(int x=0;x<list->count();x++){
        parent->setExpanded(true);
        item =  new taskTreeWidgetItem();
        item->taskValue = list->at(x);
        item->setText(0,item->taskValue.get("title","NULL").asCString());
        item->setText(1,item->taskValue.get("owner","").get("firstName","").asCString());
       // item->setText(2,html2plaintext(item->taskValue.get("description","NULL").asCString()).left(100).replace("\n"," "));
        item->setText(2,item->taskValue.get("status","NULL").asCString());
        parent->addChild(item);
        this->addChildrenToTree(item);
    }
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
    emit this->taskSelected(tItem->taskValue);
   /* TaskEditor *editor=new TaskEditor();
    editor->setStore(tItem->taskValue);
    connect(editor,SIGNAL(saveComplete()),this,SLOT(search()));
    editor->show();*/
}
