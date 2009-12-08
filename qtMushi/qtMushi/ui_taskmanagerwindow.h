/********************************************************************************
** Form generated from reading UI file 'taskmanagerwindow.ui'
**
** Created: Fri Dec 4 21:28:06 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGERWINDOW_H
#define UI_TASKMANAGERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManagerWindow
{
public:
    QAction *actionNew;
    QAction *actionDelete;
    QWidget *centralwidget;
    QVBoxLayout *centralWidgetLayout;
    QMenuBar *menubar;
    QMenu *menuTask;
    QStatusBar *statusbar;
    QDockWidget *TaskTreeContainer;
    QWidget *dockWidgetContents;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TaskManagerWindow)
    {
        if (TaskManagerWindow->objectName().isEmpty())
            TaskManagerWindow->setObjectName(QString::fromUtf8("TaskManagerWindow"));
        TaskManagerWindow->resize(800, 600);
        actionNew = new QAction(TaskManagerWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionDelete = new QAction(TaskManagerWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        centralwidget = new QWidget(TaskManagerWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralWidgetLayout = new QVBoxLayout(centralwidget);
        centralWidgetLayout->setObjectName(QString::fromUtf8("centralWidgetLayout"));
        TaskManagerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TaskManagerWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuTask = new QMenu(menubar);
        menuTask->setObjectName(QString::fromUtf8("menuTask"));
        TaskManagerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TaskManagerWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TaskManagerWindow->setStatusBar(statusbar);
        TaskTreeContainer = new QDockWidget(TaskManagerWindow);
        TaskTreeContainer->setObjectName(QString::fromUtf8("TaskTreeContainer"));
        TaskTreeContainer->setMinimumSize(QSize(250, 42));
        TaskTreeContainer->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        TaskTreeContainer->setWidget(dockWidgetContents);
        TaskManagerWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(4), TaskTreeContainer);
        toolBar = new QToolBar(TaskManagerWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        TaskManagerWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuTask->menuAction());
        menuTask->addAction(actionNew);
        menuTask->addAction(actionDelete);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionDelete);

        retranslateUi(TaskManagerWindow);

        QMetaObject::connectSlotsByName(TaskManagerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TaskManagerWindow)
    {
        TaskManagerWindow->setWindowTitle(QApplication::translate("TaskManagerWindow", "Mushi", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("TaskManagerWindow", "New", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("TaskManagerWindow", "Delete", 0, QApplication::UnicodeUTF8));
        menuTask->setTitle(QApplication::translate("TaskManagerWindow", "Task", 0, QApplication::UnicodeUTF8));
        TaskTreeContainer->setWindowTitle(QApplication::translate("TaskManagerWindow", "Tasks", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("TaskManagerWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskManagerWindow: public Ui_TaskManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGERWINDOW_H
