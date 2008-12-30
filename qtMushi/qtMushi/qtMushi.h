
#ifndef QTMUSHI_H
#define QTMUSHI_H
#include <QObject>
#include <QApplication>
#include <QNetworkAccessManager>
#include "taskFinder.h"

#define SERVER_LOCATION "http://localhost:8080"

#include "../edit_html/edit_html.h"
class qtMushi : public QApplication{
	Q_OBJECT
public:
	qtMushi( int &argc, char **argv ); 
		


	static QNetworkAccessManager *netManager;


};

#endif
