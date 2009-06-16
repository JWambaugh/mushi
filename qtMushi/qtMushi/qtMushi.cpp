

#include "qtMushi.h"



#include "quicktask.h"
#include "taskManager.h"
QNetworkAccessManager * qtMushi::netManager = new QNetworkAccessManager();

qtMushi::qtMushi( int &argc, char **argv )  : QApplication(argc, argv) {
		

        //Edit_html *w = new Edit_html();
        //w->set_XHTML("<p></p>");
        //w->show();
    QuickTask *task=new QuickTask();
    task->show();
    TaskManager *manager = new TaskManager();
    manager->show();

}



