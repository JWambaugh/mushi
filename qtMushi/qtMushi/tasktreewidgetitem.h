#ifndef TASKTREEWIDGETITEM_H
#define TASKTREEWIDGETITEM_H

#include <QTreeWidgetItem>
#include "../../lib_json/value.h"

class taskTreeWidgetItem : public QObject, public QTreeWidgetItem
{
    Q_OBJECT
public:
    taskTreeWidgetItem( QTreeWidget * parent);
    taskTreeWidgetItem();
    void setValue(Json::Value);
    Json::Value getValue();
private:
    Json::Value taskValue;

};

#endif // TASKTREEWIDGETITEM_H
