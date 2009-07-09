#ifndef QUICKTASKTASK_H
#define QUICKTASKTASK_H

#include <QtGui/QWidget>

namespace Ui {
    class QuickTaskTask;
}

class QuickTaskTask : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(QuickTaskTask)
public:
    explicit QuickTaskTask(QWidget *parent = 0);
    virtual ~QuickTaskTask();
    QString getDescription();
    void setDescription(QString);
    QString getTitle();
    void setTitle(QString);

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::QuickTaskTask *m_ui;
};

#endif // QUICKTASKTASK_H
