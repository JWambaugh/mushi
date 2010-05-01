/********************************************************************************
** Form generated from reading UI file 'taskmanagerwindow.ui'
**
** Created: Fri Apr 30 14:06:41 2010
**      by: Qt User Interface Compiler version 4.6.2
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
    QAction *actionQuickTaskCreator;
    QAction *actionRefresh;
    QWidget *centerWidget;
    QVBoxLayout *centerWidgetLayout;
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/filenew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionDelete = new QAction(TaskManagerWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon1);
        actionQuickTaskCreator = new QAction(TaskManagerWindow);
        actionQuickTaskCreator->setObjectName(QString::fromUtf8("actionQuickTaskCreator"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/mode_Reference.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuickTaskCreator->setIcon(icon2);
        actionRefresh = new QAction(TaskManagerWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon3);
        centerWidget = new QWidget(TaskManagerWindow);
        centerWidget->setObjectName(QString::fromUtf8("centerWidget"));
        centerWidgetLayout = new QVBoxLayout(centerWidget);
        centerWidgetLayout->setContentsMargins(0, 0, 0, 0);
        centerWidgetLayout->setObjectName(QString::fromUtf8("centerWidgetLayout"));
        TaskManagerWindow->setCentralWidget(centerWidget);
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
        TaskTreeContainer->setMinimumSize(QSize(250, 60));
        TaskTreeContainer->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        TaskTreeContainer->setWidget(dockWidgetContents);
        TaskManagerWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(4), TaskTreeContainer);
        toolBar = new QToolBar(TaskManagerWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(24, 24));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        TaskManagerWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuTask->menuAction());
        menuTask->addAction(actionNew);
        menuTask->addAction(actionDelete);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionQuickTaskCreator);
        toolBar->addAction(actionRefresh);

        retranslateUi(TaskManagerWindow);

        QMetaObject::connectSlotsByName(TaskManagerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TaskManagerWindow)
    {
        TaskManagerWindow->setWindowTitle(QApplication::translate("TaskManagerWindow", "Mushi", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("TaskManagerWindow", "New", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("TaskManagerWindow", "Delete", 0, QApplication::UnicodeUTF8));
        actionQuickTaskCreator->setText(QApplication::translate("TaskManagerWindow", "QuickTask", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionQuickTaskCreator->setToolTip(QApplication::translate("TaskManagerWindow", "Quick Task", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRefresh->setText(QApplication::translate("TaskManagerWindow", "refresh", 0, QApplication::UnicodeUTF8));
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
