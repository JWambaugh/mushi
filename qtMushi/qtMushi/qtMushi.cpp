

#include "qtMushi.h"

#include <QMainWindow>
#include "quicktaskcreator.h"
#include "quicktask.h"
#include "taskManager.h"
#include "taskmanagerwindow.h"
QNetworkAccessManager * qtMushi::netManager = new QNetworkAccessManager();

qtMushi::qtMushi( int &argc, char **argv )  : QApplication(argc, argv) {
		

        //Edit_html *w = new Edit_html();
        //w->set_XHTML("<p></p>");
        //w->show();
    QuickTaskCreator *quick= new QuickTaskCreator();
    quick->show();

    //QuickTask *task=new QuickTask();
    //task->show();
    //TaskManager *manager = new TaskManager();
    //manager->show();
    TaskManagerWindow *managerWindow = new TaskManagerWindow();
    managerWindow->show();

}



