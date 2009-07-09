#ifndef TASKMANAGERWINDOW_H
#define TASKMANAGERWINDOW_H

#include <QtGui/QMainWindow>

namespace Ui {
    class TaskManagerWindow;
}

class TaskManagerWindow : public QMainWindow {
    Q_OBJECT
public:
    TaskManagerWindow(QWidget *parent = 0);
    ~TaskManagerWindow();

private:
    Ui::TaskManagerWindow *m_ui;
};

#endif // TASKMANAGERWINDOW_H
