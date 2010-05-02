#include <QApplication>
#include <QWidget>
#include <QFile>
#include <QString>
#include <QDir>
#include "../edit_html/edit_html.h"
#include "qtMushi.h"
#include <QTableWidget>
//#include "manhattanstyle.h"

static inline bool is_file(QString fullFileName)
{
    if (!fullFileName.size() > 3) {
      return false;  
    }
    QFile f( fullFileName );
	if ( f.exists(fullFileName) ) {
    return true;  
	} else {
	return false;
    }
}

static inline bool fwriteutf8(QString fullFileName,QString xml)
{
    if (fullFileName.contains("/", Qt::CaseInsensitive)) {
        QString ultimacartellaaperta = fullFileName.left(fullFileName.lastIndexOf("/"))+"/";
        QDir dira(ultimacartellaaperta);
        if ( dira.mkpath(ultimacartellaaperta) ) {
        }
        else {
            return false;
        }
    }
    
        QTextCodec *codecx;
        codecx = QTextCodec::codecForMib(106);
        QFile f( fullFileName );
        if ( f.open( QFile::WriteOnly | QFile::Text ) )
        {
        QTextStream sw( &f );
        sw.setCodec(codecx);
        sw << xml;
        f.close();
        return true;
        }
        return false;
}




int main(int argc, char *argv[])
{
	qtMushi *app = new qtMushi(argc, argv);
     //   app->setStyle(new ManhattanStyle(app->style()->objectName()));
	return app->exec();
}
