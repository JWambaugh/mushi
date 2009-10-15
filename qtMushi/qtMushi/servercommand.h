#ifndef SERVERCOMMAND_H
#define SERVERCOMMAND_H
#include "../../lib_json/value.h"
#include "../../lib_json/writer.h"
#include <QObject>
#include <QNetworkAccessManager>
class ServerCommand : public QObject
{
    Q_OBJECT
public:
    ServerCommand(QObject *parent);
    ServerCommand(Json::Value val, QObject *parent);
    QString get(QString key);
    void set(QString key, QString value);
    void send();
private:
    Json::Value jsonObject;

private slots:
    void saveComplete(QNetworkReply*);

signals:
    void saveComplete(Json::Value);
};

#endif // SERVERCOMMAND_H
