#ifndef TASKEDITOR_H
#define TASKEDITOR_H

#include "ui_taskeditor.h"
#include "../../lib_json/value.h"
#include "../../lib_json/writer.h"
#include "qtMushi.h"
class TaskEditor : public QWidget, private Ui::TaskEditor {
    Q_OBJECT
    Q_DISABLE_COPY(TaskEditor)
public:
    explicit TaskEditor(QWidget *parent = 0);
    Json::Value store;
protected:
    virtual void changeEvent(QEvent *e);
    QNetworkReply *reply;



public slots:
    void save();
    void updateStore();
    void updateFromStore();
    void networkResponse();
    void setStore(Json::Value &);
signals:
     void saveComplete();

};

#endif // TASKEDITOR_H
