#ifndef TASK_FINDER_H
#define TASK_FINDER_H
#include <QObject>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QBUffer.h>
#include <QVBoxLayout>
#include <QTreeWidget>
#include "../../lib_json/value.h"
#include "../../lib_json/reader.h"
#include <qtMushi.h>
#include "tasktreewidgetitem.h"

class taskFinder : public QWidget {
        Q_OBJECT
private:
     QTreeWidget *treeWidget;
     QVBoxLayout *layout;
    QNetworkReply *reply;
    void addChildrenToTree(taskTreeWidgetItem *parent);
public:	
	taskFinder(QWidget *parent=0);
        Json::Value getSelectedRecord();
        Json::Value tickets;
        QAction *hideClosed;
public slots:
        void networkResponse();
        void search();
        void search(QString text);
        void itemActivated(QTreeWidgetItem *item,int);
    private slots:
       // void hideClosedToggled(bool checked);
signals:
        void taskSelected(Json::Value);

};
#endif


