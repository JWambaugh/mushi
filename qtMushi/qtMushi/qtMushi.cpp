

#include "qtMushi.h"




#include "taskManager.h"
QNetworkAccessManager * qtMushi::netManager = new QNetworkAccessManager();

qtMushi::qtMushi( int &argc, char **argv )  : QApplication(argc, argv) {
		

        //Edit_html *w = new Edit_html();
        //w->set_XHTML("<p></p>");
        //w->show();
    TaskManager *manager = new TaskManager();
    manager->show();

}



