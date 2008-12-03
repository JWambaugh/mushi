#ifndef HTML_LOADER_H
#define HTML_LOADER_H
#include "base_modul.h"
#include <QTextDocument>

#if defined Q_WS_MAC
#define WEBAGENTNAME "Mac QT4 / PPK_W @ciz.ch"
#endif
#if defined Q_WS_WIN
#define WEBAGENTNAME "Windows QT4 / PPK_W @ciz.ch"
#endif
#if defined Q_WS_X11
#define WEBAGENTNAME "Unix QT4 / PPK_W @ciz.ch"
#endif

typedef QMap<int, QStringList> Loadurl;
//
/*  Save file as html_loader.h  */
/*  incomming class name Html_Loader */
//

//
class Html_Loader : public QObject, public Base_Modul
{
    Q_OBJECT
//
public: Html_Loader( QString stream , const QString imagetmpdir , const QString baseref )
{
 html = stream;
 baserefpath = baseref;
 image_tmp_path = imagetmpdir;
 QString indeximg  = QString( "%1list.xml" ).arg(image_tmp_path); 
 fwriteutf8(indeximg,UmanTimeFromUnix(QTime_Null()));
 originalhtml = stream;
 doc = new QTextDocument();
 dimage.clear();
 dlink.clear();
 localfilelist.clear();
 errorlist.clear();
 imposi = 0;
 actual_loop = -1;
 NeededFile.clear();
 connect(this, SIGNAL(NextGrabList(int)), this, SLOT(LoadPosition(int)));
 Load_Image_Connector();
}
QTextDocument * GetDoc()
{
  return doc;
}
void Clean_File()
{
    int remotefiletolocal = rmrfimage.size();
    for (int i = 0; i < remotefiletolocal; ++i) {
          QString localfile = rmrfimage.at(i);
          qt_unlink(localfile);
          
    }
}
QStringList GetErrors()
{
    return errorlist;
}
protected:
private:
    int getid;
    int actual_loop;
    QHttp *wwwget;
    QTextDocument *doc;
    QString html;
    QString image_tmp_path;
    QString baserefpath;
    QString originalhtml;
    QString actualurlerror;
    QStringList dimage;
    QStringList localfilelist;
    QStringList errorlist;
    QStringList rmrfimage;
    QStringList dlink;
    QFile *logFile;
    int imposi;
    Loadurl NeededFile;
 void Load_Image_Connector()
{
    ///////////////////qDebug() << "### Load_Image_Connector";
    
    QRegExp expression( "src=[\"\'](.*)[\"\']", Qt::CaseInsensitive );
    expression.setMinimal(true);
    int iPosition = 0;
    int canna = 0;
    while( (iPosition = expression.indexIn( html , iPosition )) != -1 ) {
        QString semi1 = expression.cap( 1 );
        canna++;
        dimage.append(semi1);    /* image lista 1 */
        AppendImage(semi1);     /* image lista 2 */
        ////////////////////qDebug() << "### canna MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM " << canna << " img->" << semi1;
        iPosition += expression.matchedLength();
        ////////////////////qDebug() << "### iPosition " << iPosition;
    }
    ///////////GetRemoteFile();
    QTimer::singleShot(100, this, SLOT(GetRemoteFile()));
    
}

void Register_File()
{
    int remotefiletolocal = rmrfimage.size();
    
    ////////////////////qDebug() << "### summ to register   " << remotefiletolocal;
    
    
   for (int i = 0; i < remotefiletolocal; ++i) {
          QString localfile = rmrfimage.at(i);
          if (is_file(localfile)) {
               imposi++;
               QFileInfo locinfo(localfile);
               QString filefullpath = locinfo.absoluteFilePath();
               html = html.replace(localfile,filefullpath);
               localfilelist.append(filefullpath);
               QString registername = ":";
               registername.append(locinfo.baseName());
               doc->addResource( QTextDocument::ImageResource, QUrl(filefullpath), QPixmap(QString("%1%_%2").arg(registername).arg(imposi)) );
               /////////////////////////qDebug() << "### register downloaded file " << filefullpath;
          }
   }
   
   doc->setHtml( html ); 
   emit LoadedFlush();
}

void AppendImage( const QString foundfile )
{
    
    QString ifile = foundfile;
    if (!ifile.startsWith(baserefpath,Qt::CaseInsensitive) ) {
        ////////////////ifile = ifile.prepend(baserefpath);
    }
    
    qDebug() << "### ifile  " << ifile;
    /////////////qDebug() << "### baserefpath  " << baserefpath;
    
    
    
    /* se sono gia in cache non copiare */
    
    
    bool localfile = is_file(ifile);
    ////////qDebug() << "### localfile  " << localfile;
    
    ///////////qDebug() << "### presente!!!!!  " << localfile;
    QString shema,registername,filefullpath,filename,path,geturl;
    QUrl img;
    if (localfile) {
      img.fromLocalFile(ifile);   /* da locale pc */
    } else {
      img.setUrl(ifile);   /* da rete */  
    }
    
     //////////////qDebug() << "### img.isValid()  " << img.isValid();
     ///////////////qDebug() << "### ifile  " << ifile;
    
    
    QFile localrec(ifile);
    shema = img.scheme();
    ////////////qDebug() << "### shema  " << shema;
    /* file da locale pc */
    if (shema != "http" or shema != "ftp" ) {
        if (localrec.exists(ifile)) {
                   imposi++;
                   QFileInfo locinfo(ifile);
                   filefullpath = locinfo.absoluteFilePath();
                   filename = filefullpath;
                   if (!filefullpath.contains(image_tmp_path)) {
                       filename = QString( "%1%2" ).arg(image_tmp_path).arg(locinfo.fileName()); 
                       bool iscopy = Copy_To(filefullpath,filename);
                       ////////////qDebug() << "### iscopy  " << iscopy;
                   }
                   html = html.replace(foundfile,filename);
                   localfilelist.append(filefullpath);
                   registername = ":";
                   registername.append(locinfo.baseName());
                   QUrl img2;
                        img2.fromLocalFile(filename);
                   ///////////qDebug() << "### registername  " << registername;
                   ///////////////qDebug() << "### img2.isValid()  " << img2.isValid();
                   doc->addResource( QTextDocument::ImageResource,img2, QPixmap(QString("%1%_%2").arg(registername).arg(imposi)) );
        }
    }
    
    if (shema == "http" or shema == "ftp" ) {
        if (img.isValid()) {
         geturl = ifile;
         path = ifile.left(ifile.lastIndexOf("/"))+"/";  /* pah from url */
         filename = QString( "%1%2" ).arg(image_tmp_path).arg(geturl.replace(path,"")); 
         rmrfimage.append(filename);
         html = html.replace(ifile,filename);
         int numera = NeededFile.size();
           //////////////////qDebug() << "### POOhttpOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO   " << numera; 
         NeededFile.insert(numera,QStringList() << ifile << filename);
        }
    }
    
}

int  StartGetFile( QString fileremote , QString localfile  , int actposizion )
{
    actual_loop = actposizion;
    actualurlerror = QString("Unable to load url %1... to local %2").arg(fileremote).arg(localfile);
    QUrl urlg(fileremote);
    qt_unlink(localfile);
    wwwget = new QHttp();
    wwwget->setUser("","");
    connect(wwwget, SIGNAL(requestFinished(int, bool)), this, SLOT(Method_Get_Finish(int, bool)));
    connect(wwwget, SIGNAL(done(bool)), this, SLOT(LastWakeUpGet(bool)));
    ////////connect(wwwget, SIGNAL(dataReadProgress(int, int)), this, SLOT(SendStatus(int, int)));
    /////////connect(wwwget, SIGNAL(responseHeaderReceived(const QHttpResponseHeader &)), this, SLOT(RegisterCookie(const QHttpResponseHeader &)));
    wwwget->setHost(urlg.host(), 80); 
    logFile = new QFile(localfile);
    /////////////////logFile->open(QIODevice::ReadWrite);
    
    //////////////qDebug() << "### StartGetFile  to  " << localfile;
    if (!logFile->open(QIODevice::ReadWrite)) {
        errorlist.append(QString("Unable to write on file %2 from remote url %1").arg(fileremote).arg(localfile));
        if (actual_loop == 0 or actual_loop > 0 ) {
            emit NextGrabList(actual_loop + 1);
            return 0;
        }
    return 0;
    }
    QHttpRequestHeader header("GET", urlg.path(),1,1);   /* header */
    header.setValue("Host", urlg.host());
    header.setValue("Accept-Charset", "ISO-8859-1,utf-8;q=0.7,*;q=0.7");
    header.setValue("Accept-Language", "it,de-de;q=0.8,it-it;q=0.6,en-us;q=0.4,en;q=0.2");
    header.setValue("Connection", "keep-alive");
    header.setValue("User-Agent", WEBAGENTNAME );
    getid = wwwget->request(header,0,logFile);
    ////////////////////qDebug() << "### GrabMapidstart  " << getid;
    return getid;  
}

signals:
  void NextGrabList( int pos );
  void LoadedFlush();
public slots:
    

void LoadPosition( int now )
{
    int bigmap = NeededFile.size();
    
    //////////////qDebug() << "### actual get on ->" << now << " sumsize->"  << bigmap;
    
    if (now >= bigmap) {
    //////////qDebug() << "### stop get on   " << now;
    Register_File();
    return;
    }
    Loadurl::Iterator it;
            for ( it = NeededFile.begin(); it != NeededFile.end(); ++it ) { 
                              QStringList itemsetter = it.value(); 
                              int posi = it.key();
                              if (now == posi) {
                              //////////////qDebug() << "### GrabMap " << now;
                              StartGetFile(itemsetter.at(0),itemsetter.at(1),now);
                              return;
                              }
            }
    
}


void Method_Get_Finish(int requestId, bool error)
{
   if (requestId != getid) {
      return;
   }
   ///////////////qDebug() << "### GrabMapidfinisch  " << requestId <<  " error="  << error;
   if (error) {
   logFile->remove();
   /////////////errorlist.append(actualurlerror);
   return;
   }
   logFile->close();
}


void LastWakeUpGet(bool error)
{
    ///////////////////qDebug() << "### GrabMapidfinisch error="  << error;
    
   if (error) {
   logFile->remove();
   
   ///////////errorlist.append(actualurlerror);
   }
   if (actual_loop == 0 or actual_loop > 0 ) {
    emit NextGrabList(actual_loop + 1);
    return;
   }
   actual_loop = -1;
}


void GetRemoteFile()
{
    int remotefiletolocal = rmrfimage.size();
    if (remotefiletolocal > 0) {
        LoadPosition(0);
        return;
    } else {
        /* no remote file ....  */
       doc->setHtml( html ); 
       emit LoadedFlush(); 
       return;
    }
    
}

};
//
#endif // HTML_LOADER_H

