#ifndef MUSHISCRIPTCONN_H
#define MUSHISCRIPTCONN_H

#include <QObject>
#include "mongoose.h"
#include "mushirequest.h"
class MushiScriptConn : public QObject
{
    Q_OBJECT
public:
    MushiScriptConn(MushiRequest &request);
    ~MushiScriptConn(){}
public slots:
    void print(QString string);
    QString userData();
    QString queryString();
    QString URI();
    QString getVar(QString key);
private:
    MushiRequest *request;
};

#endif // MUSHISCRIPTCONN_H
