#ifndef USER_DIRECOTRY_H
#define USER_DIRECOTRY_H
#include <QObject>
#include <QList>
#include "servercommand.h"
#include "../../lib_json/value.h"
#include "../../lib_json/reader.h"
class UserDirectory : public QObject
{
Q_OBJECT
public:
    UserDirectory();
    QList<Json::Value> *getAllUsers();
    Json::Value getUserByID(QString id);
public slots:
    void refresh();
private slots:
    void refreshComplete(Json::Value root);
private:
    QList <Json::Value> statuses;
signals:
    void updated();
};

#endif // User_DIRECOTRY_H
