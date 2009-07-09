#include "taskmanagerwindow.h"
#include "ui_taskmanagerwindow.h"

TaskManagerWindow::TaskManagerWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::TaskManagerWindow)
{
    m_ui->setupUi(this);
}

TaskManagerWindow::~TaskManagerWindow()
{
    delete m_ui;
}
