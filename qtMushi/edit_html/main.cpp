#include <QFile>
#include <QApplication>
#include <QtGui>
#include <QtCore> 
#include <QTextCodec>
#include <QCoreApplication>
#include <QApplication>
#include <QtGui>
#include "main.h"
#include "edit_html.h"
#include "base_modul.h"
#include <QDesktopServices>

#define AUTORPDF \
               QString( "%1Xhtml_Edit_Autor.pdf" ).arg(WORK_CACHEDIR) 
               

#if defined(_USE_STATIC_BUILDS_)
  #include <QtPlugin>
  #if defined(_USE_qjpeg)
  Q_IMPORT_PLUGIN(qjpeg)
  #endif
  #if defined(_USE_qgif)
  Q_IMPORT_PLUGIN(qgif)
  #endif
  #if defined(_USE_qmng)
  Q_IMPORT_PLUGIN(qmng)
  #endif
  #if defined(_USE_qtiff)
  Q_IMPORT_PLUGIN(qtiff)
  #endif
  
#endif

static inline bool Copy_To(QString inputfile, const QString outfile)
{
    bool succ;
    QString ultimacartellaaperta = outfile.left(outfile.lastIndexOf("/"))+"/";
    QDir dira(ultimacartellaaperta);
    dira.mkpath(ultimacartellaaperta);
    
    if (inputfile.startsWith(":/")) {
        QResource actual(inputfile);
        /////qDebug() << "rvalid->" << actual.isValid() << "|" << actual.absoluteFilePath();
        QFile fr(actual.absoluteFilePath());
        succ = fr.copy(outfile);
        if (!succ) {
        QMessageBox::warning(0,"Error \"XHTML Editor\" ",QString("Unable to copy \"%1\" ").arg(inputfile)); 
        }
        return succ;
    }
    
    QFile Imaged(inputfile); 
    succ =  Imaged.copy(outfile);
    if (!succ) {
    QMessageBox::warning(0,"Error \"XHTML Editor\" ",QString("Unable to copy \"%1\" ").arg(inputfile)); 
    }
    return succ;
    
}

static inline bool fwriteutf8(QString fullFileName,QString xml)
{
    if (fullFileName.contains("/", Qt::CaseInsensitive)) {
    QString ultimacartellaaperta = fullFileName.left(fullFileName.lastIndexOf("/"))+"/";
    QDir dira(ultimacartellaaperta);
    if ( dira.mkpath(ultimacartellaaperta) ) { } else {
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


static inline QString UserLanguage()
{
     /////////////QSettings setter;
     QString languser,languagesistem,langqt; 
	QLocale loci = QLocale::system();
             languser = getenv("LANG");
             languser = languser.toLower();
             languagesistem = loci.name();
             languagesistem = languagesistem.toLower();
	     languagesistem = languagesistem.left(2);
     /* Window XP Prof MUI Multiuser == stay only "c" language && user setting setenv !!! */
     if (languagesistem == "c") { 
         if (languser.size() > 2 && languser.contains("_")) {
             languagesistem = languser.left(2);
         }
     }
     return languagesistem;
}


#define osApplication \
    (static_cast<OS_application*>(QCoreApplication::instance()))
    
class OS_application : public QApplication
{
    Q_OBJECT
//
public:
    public:
 OS_application( int &argc, char **argv )
  : QApplication(argc, argv)
{
        QString localedirfile,openfile;
        #if defined Q_WS_MAC
        QStringList path;
        path.append(QApplication::applicationDirPath());
        QDir dir(QApplication::applicationDirPath());
        dir.cdUp();
        path.append(dir.absolutePath());
        dir.cd("plugins");
        path.append(dir.absolutePath());
        dir.cdUp();
        path.append(dir.absolutePath());
        QApplication::setLibraryPaths(path);
        QDir::setCurrent(dir.absolutePath());   /* here down -> Frameworks */
    
        
       
    
        #endif
        #if defined Q_WS_MAC
        localedirfile = QString("%1/locale/edit_%2.qm").arg(QDir::currentPath()).arg(UserLanguage()); 
        #endif
        #if defined Q_WS_WIN
        localedirfile = QString("%1/locale/edit_%2.qm").arg(QCoreApplication::applicationDirPath()).arg(UserLanguage());
        #endif
        #if defined Q_WS_X11
        localedirfile = QString("%1/locale/edit_%2.qm").arg(WORK_CACHEDIR).arg(UserLanguage()); 
        #endif
        QTranslator translator;
        translator.load(localedirfile);
        installTranslator(&translator);
        mainWin = new QMainWindow();
        w = new Edit_html();
        w->set_Cache(IMM_BUILD);
        QRect screenSize = desktop()->availableGeometry();
        mainWin->setMinimumSize ( screenSize.width() - 300 , screenSize.height() );
        /* to enable QT Setting QSetting setup save x11 session language and other  */
        setOrganizationName(_ORGANIZATION_NAME_);
        setOrganizationDomain(_PROGRAM_NAME_DOMAINE_);
        setApplicationName(_PROGRAM_NAME_);
        mainWin->setWindowTitle(_PROGRAM_TITLE_);
        QMenu *menu = mainWin->menuBar()->addMenu(QObject::tr("&File"));
        menu->addAction(QObject::tr("Open File"),w, SLOT(OpenNewDoc()));
        menu->addSeparator();
        menu->addAction(QObject::tr("&Quit"),this, SLOT(quit()));
        
        QMenu *menu0 = mainWin->menuBar()->addMenu(QObject::tr("&About"));
        menu0->addAction(QObject::tr("About Programm %1").arg(_PROGRAM_NAME_),this, SLOT(Aboutp()));
        menu0->addAction(QObject::tr("Autor Home Page"),this, SLOT(Link0()));
        menu0->addAction(QObject::tr("Check update..."),this, SLOT(Link1()));
        
        
        QStringList files = arguments();
         if (files.size() > 1) {
           for (int i = 0; i < files.size(); ++i) {  
              if (i > 0) {           
              const QString onef = files.at(i);
              if (is_file(onef)) {
                  defaultfile = onef;
              }
            }
           }
          }

        if (!is_file(defaultfile))  {
        defaultfile = QString("%2/index.html").arg(QDir::homePath());
        fwriteutf8(defaultfile,"<p>Hello World!</p>");  
        }
        OpenFile(defaultfile);
        mainWin->show();
        connect(w, SIGNAL(statusMessage(QString)),mainWin->statusBar(), SLOT(showMessage(QString)));
        mainWin->setCentralWidget(w);
}
    
void OpenFile( const QString file )
{
        QFileInfo fi(file);
        QString ext = fi.suffix();
        ext = ext.toLower();
        if (ext == "xhtml" || ext == "html" || ext == "xml" || ext == "xcms") {
        w->SetFileBase(file);
        } else {
        QMessageBox::warning(0,"Error \"XHTML Editor\" ",QString("The file \"%1\" is not xhtml or html").arg(fi.fileName())); 
        } 
}
protected:
void OpenDesktop( QUrl loc )
{
     bool r = QDesktopServices::openUrl(loc);
    if (!r) {
    QMessageBox::warning(0, tr("Error"),tr("Unable to open file or dir  %1").arg(loc.toString()));
    }
}
bool event(QEvent *ev)
{
    bool eaten;
    switch (ev->type()) {
    case QEvent::FileOpen:
        /* on or more from drag event to icon mac linux win */
        defaultfile = static_cast<QFileOpenEvent *>(ev)->file();
        OpenFile(defaultfile);
        eaten = true;
        break;
    case QEvent::Close: {
        /* order and save setting */
        //////quit();
        eaten = true;
        break;
    }
    default:
        eaten = QApplication::event(ev);
        break;
    }
    return eaten;
}
Edit_html *w;
QMainWindow *mainWin;
QString defaultfile;
public slots:
void Aboutp()
{
       if (!is_file(AUTORPDF)) {
        Copy_To(QString(":/locale_m/autor.pdf"),AUTORPDF);
        /* first time setup */
        }
        
    OpenDesktop( QUrl(AUTORPDF));
    
}
void Link0()
{
    OpenDesktop( QUrl("http://www.swisse.net/"));
    
}

void Link1()
{
    OpenDesktop( QUrl("http://www.qt-apps.org/usermanager/search.php?username=patrik08&action=contents"));
    OpenDesktop( QUrl("http://code.google.com/p/qxhtml-edit/"));
    
}




};



int main(int argc, char *argv[]) {
     OS_application a( argc, argv );
     a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}



#include "main.moc"


