#include "smtp.h"

Smtp::Smtp( const QString &from, const QString &to, const QString &subject, const QString &body,QString server, QString headers="", quint16 port=25 )
{

    socket = new QTcpSocket( this );
    qRegisterMetaType<QAbstractSocket::SocketState>("SocketState");
    connect( socket, SIGNAL( readyRead() ), this, SLOT( readyRead() ) );
    connect( socket, SIGNAL( connected() ), this, SLOT( connected() ) );
    //connect( socket, SIGNAL(error(ErrorState)), this,
      //  SLOT(errorReceived(ErrorState)));
   // connect( socket, SIGNAL(stateChanged(SocketState)), this,
    //    SLOT(stateChanged(SocketState)));
    connect(socket, SIGNAL(disconnected()), this,
        SLOT(disconnected()));;

    message = "To: " + to + "\n";
    message.append("From: " + from + "\n");
    message.append("Subject: " + subject + "\n");
    message.append(headers);
    message.append(body);
    message.replace( QString::fromLatin1( "\n" ), QString::fromLatin1( "\r\n" ) );
    message.replace( QString::fromLatin1( "\r\n.\r\n" ),
    QString::fromLatin1( "\r\n..\r\n" ) );
    this->from = from;
    rcpt = to;
    state = Init;
    socket->connectToHost( server, port);
    if(socket->waitForConnected ( 30000 ))  {qDebug("connected");   }

    t = new QTextStream( socket );
    loop.exec(QEventLoop::ExcludeUserInputEvents);
}
Smtp::~Smtp()
{
    delete t;
    delete socket;
    loop.quit(); // end our little event loop

}
void Smtp::stateChanged(QTcpSocket::SocketState socketState)
{

    //qDebug() <<"stateChanged " << socketState;
}

void Smtp::errorReceived(QTcpSocket::SocketError socketError)
{
   // qDebug() << "error " <<socketError;
   // exit(1);
}

void Smtp::disconnected()
{

    //qDebug() <<"disconnected";
    //qDebug() << "error "  << socket->errorString();
    //exit(1);
}

void Smtp::connected()
{
    //output->append("connected");
    //qDebug() << "Connected ";
}

void Smtp::readyRead()
{

     //qDebug() <<"readyRead";
    // SMTP is line-oriented

    QString responseLine;
    do
    {
        responseLine = socket->readLine();
        response += responseLine;
    }
    while ( socket->canReadLine() && responseLine[3] != ' ' );
    //qDebug()<<response;
    responseLine.truncate( 3 );


    if ( state == Init && responseLine[0] == '2' )
    {
        // banner was okay, let's go on

        *t << "HELO there\r\n";
        t->flush();

        state = Mail;
    }
    else if ( state == Mail && responseLine[0] == '2' )
    {
        // HELO response was okay (well, it has to be)

        *t << "MAIL FROM: " << from << "\r\n";
        t->flush();
        state = Rcpt;
    }
    else if ( state == Rcpt && responseLine[0] == '2' )
    {

        *t << "RCPT TO: " << rcpt << "\r\n"; //r
        t->flush();
        state = Data;
    }
    else if ( state == Data && responseLine[0] == '2' )
    {

        *t << "DATA\r\n";
        t->flush();
        state = Body;
    }
    else if ( state == Body && responseLine[0] == '3' )
    {

        *t << message << "\r\n.\r\n";
        t->flush();
        state = Quit;
    }
    else if ( state == Quit && responseLine[0] == '2' )
    {

        *t << "QUIT\r\n";
        t->flush();
        // here, we just close.
        state = Close;
        emit status( tr( "Message sent" ) );
    }
    else if ( state == Close )
    {
        deleteLater();
        //exit(1);
        return;
    }
    else
    {
        // something broke.
        qDebug() << response;
        //QMessageBox::warning( 0, tr( "Qt Mail Example" ), tr( "Unexpected reply from SMTP server:\n\n" ) + response );
        state = Close;
    }
    response = "";
}
