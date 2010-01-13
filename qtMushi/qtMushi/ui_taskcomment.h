/********************************************************************************
** Form generated from reading UI file 'taskcomment.ui'
**
** Created: Tue Jan 12 15:54:42 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKCOMMENT_H
#define UI_TASKCOMMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskComment
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLabel *authorLabel;
    QLabel *dateLabel;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;

    void setupUi(QWidget *TaskComment)
    {
        if (TaskComment->objectName().isEmpty())
            TaskComment->setObjectName(QString::fromUtf8("TaskComment"));
        TaskComment->resize(400, 300);
        gridLayout = new QGridLayout(TaskComment);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(TaskComment);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 3, 1, 1, 2);

        authorLabel = new QLabel(TaskComment);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));

        gridLayout->addWidget(authorLabel, 1, 1, 1, 1);

        dateLabel = new QLabel(TaskComment);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(dateLabel, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton = new QToolButton(TaskComment);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 2);


        retranslateUi(TaskComment);

        QMetaObject::connectSlotsByName(TaskComment);
    } // setupUi

    void retranslateUi(QWidget *TaskComment)
    {
        TaskComment->setWindowTitle(QApplication::translate("TaskComment", "Form", 0, QApplication::UnicodeUTF8));
        authorLabel->setText(QApplication::translate("TaskComment", "Author", 0, QApplication::UnicodeUTF8));
        dateLabel->setText(QApplication::translate("TaskComment", "Date", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("TaskComment", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskComment: public Ui_TaskComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKCOMMENT_H
