#ifndef STATUS_DIRECOTRY_H
#define STATUS_DIRECOTRY_H
#include <QObject>
#include <QList>
#include "servercommand.h"
#include "../../lib_json/value.h"
#include "../../lib_json/reader.h"
class StatusDirectory : public QObject
{
Q_OBJECT
public:
    StatusDirectory();
    QList<Json::Value> *getAllStatuses();
    Json::Value getStatusByID(QString id);
public slots:
    void refresh();
private slots:
    void refreshComplete(Json::Value root);
private:
    QList <Json::Value> statuses;
signals:
    void updated();
};

#endif // STATUS_DIRECOTRY_H
