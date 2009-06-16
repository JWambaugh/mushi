#ifndef QUICKTASK_H
#define QUICKTASK_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QDebug>

class QuickTask : public QWidget
{
    Q_OBJECT
public:
    QuickTask(QWidget *parent=0);

private:

    QTextEdit editor;
    QVBoxLayout layout;
private slots:
    void textChanged();
};

#endif // QUICKTASK_H
