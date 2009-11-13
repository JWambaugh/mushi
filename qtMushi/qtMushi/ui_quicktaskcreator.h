/********************************************************************************
** Form generated from reading UI file 'quicktaskcreator.ui'
**
** Created: Thu Nov 12 11:03:57 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUICKTASKCREATOR_H
#define UI_QUICKTASKCREATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuickTaskCreator
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *editor;
    QStatusBar *statusbar;
    QDockWidget *tasksWindow;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *saveAllButton;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *taskListWidget;
    QToolBar *toolBar;
    QDockWidget *defaultsWindow;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QMainWindow *QuickTaskCreator)
    {
        if (QuickTaskCreator->objectName().isEmpty())
            QuickTaskCreator->setObjectName(QString::fromUtf8("QuickTaskCreator"));
        QuickTaskCreator->resize(800, 600);
        centralwidget = new QWidget(QuickTaskCreator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        editor = new QPlainTextEdit(centralwidget);
        editor->setObjectName(QString::fromUtf8("editor"));
        editor->setBaseSize(QSize(300, 0));

        verticalLayout->addWidget(editor);

        QuickTaskCreator->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QuickTaskCreator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QuickTaskCreator->setStatusBar(statusbar);
        tasksWindow = new QDockWidget(QuickTaskCreator);
        tasksWindow->setObjectName(QString::fromUtf8("tasksWindow"));
        tasksWindow->setMinimumSize(QSize(350, 210));
        tasksWindow->setBaseSize(QSize(400, 0));
        tasksWindow->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveAllButton = new QToolButton(dockWidgetContents);
        saveAllButton->setObjectName(QString::fromUtf8("saveAllButton"));

        horizontalLayout->addWidget(saveAllButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(150, 0));
        scrollArea->setWidgetResizable(true);
        taskListWidget = new QWidget();
        taskListWidget->setObjectName(QString::fromUtf8("taskListWidget"));
        taskListWidget->setGeometry(QRect(0, 0, 342, 364));
        scrollArea->setWidget(taskListWidget);

        verticalLayout_2->addWidget(scrollArea);

        tasksWindow->setWidget(dockWidgetContents);
        QuickTaskCreator->addDockWidget(static_cast<Qt::DockWidgetArea>(2), tasksWindow);
        toolBar = new QToolBar(QuickTaskCreator);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMinimumSize(QSize(0, 10));
        QuickTaskCreator->addToolBar(Qt::TopToolBarArea, toolBar);
        defaultsWindow = new QDockWidget(QuickTaskCreator);
        defaultsWindow->setObjectName(QString::fromUtf8("defaultsWindow"));
        defaultsWindow->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        scrollArea_2 = new QScrollArea(dockWidgetContents_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 772, 76));
        scrollArea_2->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea_2);

        defaultsWindow->setWidget(dockWidgetContents_2);
        QuickTaskCreator->addDockWidget(static_cast<Qt::DockWidgetArea>(8), defaultsWindow);

        retranslateUi(QuickTaskCreator);

        QMetaObject::connectSlotsByName(QuickTaskCreator);
    } // setupUi

    void retranslateUi(QMainWindow *QuickTaskCreator)
    {
        QuickTaskCreator->setWindowTitle(QApplication::translate("QuickTaskCreator", "Quick Task Creator", 0, QApplication::UnicodeUTF8));
        tasksWindow->setWindowTitle(QApplication::translate("QuickTaskCreator", "Tasks", 0, QApplication::UnicodeUTF8));
        saveAllButton->setText(QApplication::translate("QuickTaskCreator", "Save All", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("QuickTaskCreator", "toolBar", 0, QApplication::UnicodeUTF8));
        defaultsWindow->setWindowTitle(QApplication::translate("QuickTaskCreator", "Defaults", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QuickTaskCreator: public Ui_QuickTaskCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUICKTASKCREATOR_H
