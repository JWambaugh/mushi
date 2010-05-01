#ifndef TASKEDITOR_H
#define TASKEDITOR_H

#include "ui_taskeditor.h"
#include "../../lib_json/value.h"
#include "../../lib_json/writer.h"
#include "qtMushi.h"
#include "taskcomment.h"
class TaskEditor : public QWidget, private Ui::TaskEditor {
    Q_OBJECT
    Q_DISABLE_COPY(TaskEditor)
public:
    explicit TaskEditor(QWidget *parent = 0);
    Json::Value store;
protected:
    virtual void changeEvent(QEvent *e);
    QNetworkReply *reply;
    QList<TaskComment *> notes;
    QVBoxLayout *noteLayout;


public slots:
    void save();
    void updateStore();
    void updateFromStore();
    void saveCompleted(Json::Value);
    void setStore(Json::Value &);
    void addNote();
    void saveNotes();
    void getNotesResponse(Json::Value);
signals:
     void saveComplete();

};

#endif // TASKEDITOR_H
