#ifndef QUICKTASKCREATOR_H
#define QUICKTASKCREATOR_H

#include <QtGui/QMainWindow>
#include <QVBoxLayout>
#include <QDebug>
#include "quicktasktask.h"
namespace Ui {
    class QuickTaskCreator;
}

class QuickTaskCreator : public QMainWindow {
    Q_OBJECT
public:
    QuickTaskCreator(QWidget *parent = 0);
    ~QuickTaskCreator();

private:
    QVBoxLayout *taskLayout;
    Ui::QuickTaskCreator *m_ui;
    QAction *taskifyAction;
private slots:
    void taskify();
};

#endif // QUICKTASKCREATOR_H
