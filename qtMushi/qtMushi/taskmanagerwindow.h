#ifndef TASKMANAGERWINDOW_H
#define TASKMANAGERWINDOW_H

#include <QtGui/QMainWindow>
#include <QVBoxLayout>
#include "taskFinder.h"
#include "homepage.h"
#include "taskeditor.h"
#include "servercommand.h"
namespace Ui {
    class TaskManagerWindow;
}

class TaskManagerWindow : public QMainWindow {
    Q_OBJECT
public:
    TaskManagerWindow(QWidget *parent = 0);
    ~TaskManagerWindow();

private:

    QTabWidget *centralTabWidget;
    taskFinder *finder;
    Ui::TaskManagerWindow *m_ui;

private slots:
    void closeCentralTab(int index);
    void openTask(Json::Value);
    void newTask();
    void deleteTask();
    void removeCentralTab(QObject *page);
  //  void setCentralWidgetFocus(QWidget widget);
};

#endif // TASKMANAGERWINDOW_H
