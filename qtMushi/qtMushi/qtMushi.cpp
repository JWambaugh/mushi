

#include "qtMushi.h"


qtMushi::qtMushi( int &argc, char **argv )  : QApplication(argc, argv) {
		
	netManager = new QNetworkAccessManager();
		
	Edit_html *w = new Edit_html();
	w->set_XHTML("<p></p>");
	w->show();	
}



