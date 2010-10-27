#ifndef MUSHIREQUEST_H
#define MUSHIREQUEST_H

#include <QObject>
#include "mongoose.h"
class MushiRequest : public QObject
{
    Q_OBJECT
public:
    explicit MushiRequest(mg_connection *connection,const struct mg_request_info *request_info, QObject *parent = 0);
    QString getPost();
    QString getURI();
    QString getMethod();
    void write(QString data);
    void write(std::string data);
    void write(char *);
signals:

public slots:
private:
    bool read;
    QString readBuffer;
    mg_connection *conn;
    const struct mg_request_info *request_info;
};

#endif // MUSHIREQUEST_H
