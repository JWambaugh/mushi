#ifndef TASKCOMMENT_H
#define TASKCOMMENT_H

#include <QWidget>
#include "../../lib_json/value.h"
#include "../../lib_json/writer.h"
#include "qtMushi.h"
namespace Ui {
    class TaskComment;
}

class TaskComment : public QWidget {
    Q_OBJECT
public:
    TaskComment(QWidget *parent = 0);
    ~TaskComment();
    Json::Value store;
    void setParentTaskID(int taskID);
    void updateFromStore();
public slots:
    void save();
    void updateStore();
    void sizeToContents();
private:
    Ui::TaskComment *ui;



};

#endif // TASKCOMMENT_H
