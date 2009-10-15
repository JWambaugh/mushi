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

class taskFinder : public QWidget {
        Q_OBJECT
private:
     QTreeWidget *treeWidget;
     QVBoxLayout *layout;
    QNetworkReply *reply;
public:	
	taskFinder(QWidget *parent=0);
        Json::Value getSelectedRecord();
        Json::Value tickets;
public slots:
        void networkResponse();
        void search();
        void search(QString text);
        void itemActivated(QTreeWidgetItem *item,int);

};
#endif


