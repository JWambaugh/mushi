/********************************************************************************
** Form generated from reading UI file 'taskcomment.ui'
**
** Created: Tue Jun 15 23:44:54 2010
**      by: Qt User Interface Compiler version 4.6.3
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskComment
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *dateBox;
    QGridLayout *gridLayout;
    QLabel *authorLabel;
    QTextEdit *note;

    void setupUi(QWidget *TaskComment)
    {
        if (TaskComment->objectName().isEmpty())
            TaskComment->setObjectName(QString::fromUtf8("TaskComment"));
        TaskComment->resize(676, 65);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(150);
        sizePolicy.setHeightForWidth(TaskComment->sizePolicy().hasHeightForWidth());
        TaskComment->setSizePolicy(sizePolicy);
        TaskComment->setMinimumSize(QSize(100, 65));
        TaskComment->setBaseSize(QSize(0, 200));
        verticalLayout = new QVBoxLayout(TaskComment);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dateBox = new QGroupBox(TaskComment);
        dateBox->setObjectName(QString::fromUtf8("dateBox"));
        gridLayout = new QGridLayout(dateBox);
        gridLayout->setContentsMargins(1, 1, 1, 1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        authorLabel = new QLabel(dateBox);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));

        gridLayout->addWidget(authorLabel, 0, 0, 1, 1);

        note = new QTextEdit(dateBox);
        note->setObjectName(QString::fromUtf8("note"));
        note->setMinimumSize(QSize(0, 20));
        note->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout->addWidget(note, 1, 0, 1, 2);


        verticalLayout->addWidget(dateBox);


        retranslateUi(TaskComment);

        QMetaObject::connectSlotsByName(TaskComment);
    } // setupUi

    void retranslateUi(QWidget *TaskComment)
    {
        TaskComment->setWindowTitle(QApplication::translate("TaskComment", "Form", 0, QApplication::UnicodeUTF8));
        dateBox->setTitle(QString());
        authorLabel->setText(QApplication::translate("TaskComment", "Author - Date", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskComment: public Ui_TaskComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKCOMMENT_H
