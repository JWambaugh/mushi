

#include "qtMushi.h"

QNetworkAccessManager * qtMushi::netManager = new QNetworkAccessManager();

qtMushi::qtMushi( int &argc, char **argv )  : QApplication(argc, argv) {
		
	taskFinder *finder = new taskFinder();

	Edit_html *w = new Edit_html();
	w->set_XHTML("<p></p>");
	w->show();	
}



