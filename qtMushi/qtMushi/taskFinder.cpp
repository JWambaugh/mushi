
#include "taskFinder.h"
taskFinder::taskFinder(QWidget *parent) : QWidget(parent){

	//attempt to get all tickets
	
	connect(qtMushi::netManager, SIGNAL(finished(QNetworkReply*)),
        this, SLOT(networkResponse(QNetworkReply*)));
        QNetworkRequest request(QUrl(SERVER_LOCATION "/command"));
        request.setRawHeader("Connection" ,"close");
        qtMushi::netManager->post(request, QByteArray("data=%7B%0D%0A%22command%22%3A%22findTask%22%0D%0A%0D%0A%7D" ) );
		


}



void taskFinder::networkResponse(QNetworkReply *reply){
	qDebug() << reply->readAll();
}


