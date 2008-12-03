#ifndef MAIN_H
#define MAIN_H

#include <QTextTable>
#include <QInputDialog>
#include <QMenu>
#include <QString>
#include <QDesktopServices>
#include <QString>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QHeaderView>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QMap>
#include <QList>
#include <QStringList>
#include <QObject>
#include <QDateTime>
#include <QDate>
#include <QImageReader>
#include <QPixmap>
#include <QSettings>
#include <QTimer>
#include <QProgressDialog>
#include <QPainter>
#include <QPixmap>
#include <QUrl>
#include <QColorDialog>
#include <QSqlField>
#include <QFileDialog>
#include <QMessageBox>
#include <QWorkspace>
#include <QDockWidget>
#include <QTcpSocket>
#include <QString>
#include <QDebug>
#include <QObject>
#include <QFileInfo>
#include <QObject>
#include <QHttp>
#include <QFile>
#include <QBuffer> 
#include <QTcpSocket>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QAbstractSocket>
#include <QDateTime>
#include <QDate>
#include <QLocale>
#include <QObject>
#include <QFileInfo>
#include <QObject>
#include <QHttp>
#include <QFile>
#include <QBuffer>

#if defined(_USE_STATIC_BUILDS_)
/* mac have config only release */
#else
#include <QDebug>
#endif





typedef QMap<QString, QString> Appsetting; 
typedef QMap<int, QStringList> resultMap;
typedef QMap<QString, QString> Vario;
typedef QMap<QString, QString> sqlr;

#define _PROGRAM_NAME_ "XHTML Editor PPK-Screendesign/Webprogramm di Peter Hohl"
#define _PROGRAM_NAME_DOMAINE_ "ciz.ch"
#define _ORGANIZATION_NAME_ "PPK-Screendesign/Webprogramm"
#define _PROGRAM_VERSION_ "version 3.8 / 2007-g6"
#define _PROGRAM_OWNER_ "version 3.8"
#define _PROGRAM_TITLE_  _PROGRAM_NAME_" - "_PROGRAM_VERSION_
#define Q_WORKS_PEND "open"
#define _PROGRAM_SHORT_NAME "qt_xhtmledit"
#define _WATERMARK_ "www.pulitzer.ch"
#define TUMNAIL_SIZE 120
#define PICS_SIZE_LIMIT 740
#define PICS_DISPLAY_LIMIT 300



#define WORK_CACHEDIR \
               QString( "%1/.%2/" ).arg(QDir::homePath(),_PROGRAM_SHORT_NAME) 
               
#define IMM_BUILD \
               QString( "%1pics/" ).arg(WORK_CACHEDIR) 
               
               
#define CURL_DIR \
               QString( "%1curl/" ).arg(WORK_CACHEDIR) 
#define IMAGE_TMP_DIR \
               QString( "%1imgtmp/" ).arg(WORK_CACHEDIR) 
                   
#define LOGCURLSTDOUT \
               QString( "%1curl.log" ).arg(CURL_DIR)            
               
#define _BASEDBDIR_ \
               QString( "%1user/" ).arg(WORK_CACHEDIR)   
#define APPLICATION_SETTING \
               QString( "%1config.xml" ).arg(WORK_CACHEDIR) 

#define APPLICATION_LOGS \
               QString( "%1/logfile.txt" ).arg(WORK_CACHEDIR) 
#define UNZIPDIR \
               QString( "%1tmp/" ).arg(WORK_CACHEDIR) 
#define _XML_STREAMS_ \
               QString( "%1/streams.xml" ).arg(WORK_CACHEDIR) 

#define DEBUGFILE \
               QString( "%1/saypath.txt" ).arg(QDir::homePath()) 


#define LOGSQLERROR \
               QString( "%1curl.log" ).arg(QDir::currentPath())   






#endif

