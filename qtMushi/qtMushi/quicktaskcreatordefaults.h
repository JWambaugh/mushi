#ifndef QUICKTASKCREATORDEFAULTS_H
#define QUICKTASKCREATORDEFAULTS_H

#include <QWidget>
#include "qtMushi.h"
namespace Ui {
    class QuickTaskCreatorDefaults;
}

class QuickTaskCreatorDefaults : public QWidget {
    Q_OBJECT
public:
    QuickTaskCreatorDefaults(QWidget *parent = 0);
    ~QuickTaskCreatorDefaults();
    QString getParent();
    QString getStatus();
    QString getOwner();
private:
    Ui::QuickTaskCreatorDefaults *ui;
};

#endif // QUICKTASKCREATORDEFAULTS_H
