#ifndef TASK_FINDER_H
#define TASK_FINDER_H
#include <QObject>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QBUffer.h>
#include "../../lib_json/value.h"
#include <qtMushi.h>

class taskFinder : public QWidget {
	Q_OBJECT
public:	
	taskFinder(QWidget *parent=0);

        Json::Value tickets;
public slots:
	void networkResponse(QNetworkReply*);



};
#endif


