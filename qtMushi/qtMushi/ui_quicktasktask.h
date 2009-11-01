/********************************************************************************
** Form generated from reading UI file 'quicktasktask.ui'
**
** Created: Fri Oct 23 15:45:56 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUICKTASKTASK_H
#define UI_QUICKTASKTASK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuickTaskTask
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *title;
    QToolButton *deleteButton;
    QToolButton *saveButton;
    QTextEdit *description;

    void setupUi(QWidget *QuickTaskTask)
    {
        if (QuickTaskTask->objectName().isEmpty())
            QuickTaskTask->setObjectName(QString::fromUtf8("QuickTaskTask"));
        QuickTaskTask->resize(400, 136);
        verticalLayout = new QVBoxLayout(QuickTaskTask);
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        title = new QLineEdit(QuickTaskTask);
        title->setObjectName(QString::fromUtf8("title"));

        horizontalLayout->addWidget(title);

        deleteButton = new QToolButton(QuickTaskTask);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        saveButton = new QToolButton(QuickTaskTask);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout);

        description = new QTextEdit(QuickTaskTask);
        description->setObjectName(QString::fromUtf8("description"));

        verticalLayout->addWidget(description);


        retranslateUi(QuickTaskTask);
        QObject::connect(deleteButton, SIGNAL(clicked()), QuickTaskTask, SLOT(close()));

        QMetaObject::connectSlotsByName(QuickTaskTask);
    } // setupUi

    void retranslateUi(QWidget *QuickTaskTask)
    {
        QuickTaskTask->setWindowTitle(QApplication::translate("QuickTaskTask", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("QuickTaskTask", "Delete Task", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QApplication::translate("QuickTaskTask", "X", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("QuickTaskTask", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QuickTaskTask: public Ui_QuickTaskTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUICKTASKTASK_H
