#ifndef QUICKTASK_H
#define QUICKTASK_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QPushButton>
#include "quicktasktask.h"

class QuickTask : public QWidget
{
    Q_OBJECT
public:
    QuickTask(QWidget *parent=0);

private:

    QTextEdit editor;
    QHBoxLayout mainLayout;
    QVBoxLayout editorLayout;
    QVBoxLayout taskLayout;
    QPushButton taskifyButton;
private slots:
    void taskify();
    void taskify2();
};

#endif // QUICKTASK_H
