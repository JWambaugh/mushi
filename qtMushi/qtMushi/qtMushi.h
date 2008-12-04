

#include <QObject>
#include <QApplication>
#include <QNetworkAccessManager>


#include "../edit_html/edit_html.h"
class qtMushi : public QApplication{
	Q_OBJECT
public:
	qtMushi( int &argc, char **argv ); 
		


	QNetworkAccessManager *netManager;


};


