#ifndef MUSHISCRIPTCONN_H
#define MUSHISCRIPTCONN_H

#include <QObject>
#include "mongoose.h"
class MushiScriptConn : public QObject
{
    Q_OBJECT
public:
    MushiScriptConn(struct mg_connection *conn, const struct mg_request_info *ri, void *user_data);
    ~MushiScriptConn(){};
public slots:
    void print(QString string);
    QString userData();
    QString queryString();
    QString URI();
    QString getVar(QString key);
private:
    struct mg_connection *_conn;
    const struct mg_request_info *_ri;
    void *_user_data;
};

#endif // MUSHISCRIPTCONN_H
