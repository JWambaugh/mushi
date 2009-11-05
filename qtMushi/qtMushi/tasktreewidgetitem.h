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
    Json::Value taskValue;
private:

};

#endif // TASKTREEWIDGETITEM_H
