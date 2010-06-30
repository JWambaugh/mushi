#include "tasktreewidgetitem.h"
#include <QDate>
taskTreeWidgetItem::taskTreeWidgetItem( QTreeWidget * parent):QTreeWidgetItem(parent,5001)
{

}
taskTreeWidgetItem::taskTreeWidgetItem():QTreeWidgetItem(5001)
{

}

void taskTreeWidgetItem::setValue(Json::Value val){
    this->taskValue=val;

    if(val.get("dueDate","")!=""){
        QDate due;
        due = QDate::fromString(QString(val.get("dueDate","").asString().c_str()),"yyyy-MM-dd");
        //qDebug()<< due.toString("yyy-MM-dd") << " - " QDate::currentDate() ;
        if(due < QDate::currentDate()){
            QBrush brush (QColor(255,200,200));
            this->setBackground(0,brush);
            this->setBackground(1,brush);
            this->setBackground(2,brush);
        }
    }

}


Json::Value taskTreeWidgetItem::getValue(){
    return this->taskValue;
}
