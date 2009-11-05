#ifndef TASKDIRECTORY_H
#define TASKDIRECTORY_H
#include <QObject>
#include <QList>
#include "servercommand.h"
#include "../../lib_json/value.h"
#include "../../lib_json/reader.h"
class TaskDirectory : public QObject
{
Q_OBJECT
public:
    TaskDirectory();
    QList<Json::Value> *getAllTasks();
    QList<Json::Value> *getTopLevelTasks();
    QList<Json::Value> *getChildrenOfTask(Json::Value &task);
    Json::Value getTaskById(int id);
public slots:
    void refresh();
private slots:
    void refreshComplete(Json::Value root);
private:
    QList <Json::Value> tasks;
signals:
    void updated();
};

#endif // TASKDIRECTORY_H
