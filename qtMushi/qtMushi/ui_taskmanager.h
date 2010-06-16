/********************************************************************************
** Form generated from reading UI file 'taskmanager.ui'
**
** Created: Tue Jun 15 23:44:54 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManager
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *taskFinderLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *quickSearchEdit;
    QToolButton *quickSearchButton;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *newButton;
    QToolButton *deleteButton;

    void setupUi(QWidget *TaskManager)
    {
        if (TaskManager->objectName().isEmpty())
            TaskManager->setObjectName(QString::fromUtf8("TaskManager"));
        TaskManager->resize(724, 494);
        TaskManager->setCursor(QCursor(Qt::ArrowCursor));
        gridLayout_2 = new QGridLayout(TaskManager);
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        taskFinderLayout = new QVBoxLayout();
        taskFinderLayout->setObjectName(QString::fromUtf8("taskFinderLayout"));

        gridLayout_2->addLayout(taskFinderLayout, 2, 2, 1, 2);

        frame_2 = new QFrame(TaskManager);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        quickSearchEdit = new QLineEdit(frame_2);
        quickSearchEdit->setObjectName(QString::fromUtf8("quickSearchEdit"));

        horizontalLayout_3->addWidget(quickSearchEdit);

        quickSearchButton = new QToolButton(frame_2);
        quickSearchButton->setObjectName(QString::fromUtf8("quickSearchButton"));

        horizontalLayout_3->addWidget(quickSearchButton);


        gridLayout_2->addWidget(frame_2, 0, 3, 1, 1);

        frame = new QFrame(TaskManager);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        newButton = new QToolButton(frame);
        newButton->setObjectName(QString::fromUtf8("newButton"));

        horizontalLayout_2->addWidget(newButton);

        deleteButton = new QToolButton(frame);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout_2->addWidget(deleteButton);


        gridLayout_2->addWidget(frame, 0, 2, 1, 1);


        retranslateUi(TaskManager);

        QMetaObject::connectSlotsByName(TaskManager);
    } // setupUi

    void retranslateUi(QWidget *TaskManager)
    {
        TaskManager->setWindowTitle(QApplication::translate("TaskManager", "Task Finder", 0, QApplication::UnicodeUTF8));
        quickSearchButton->setText(QApplication::translate("TaskManager", "Search", 0, QApplication::UnicodeUTF8));
        newButton->setText(QApplication::translate("TaskManager", "New", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("TaskManager", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskManager: public Ui_TaskManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
