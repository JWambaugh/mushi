/********************************************************************************
** Form generated from reading ui file 'quicktasktask.ui'
**
** Created: Tue Jun 16 15:33:01 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
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
    QToolButton *deleteButton;
    QLineEdit *title;
    QTextEdit *description;

    void setupUi(QWidget *QuickTaskTask)
    {
        if (QuickTaskTask->objectName().isEmpty())
            QuickTaskTask->setObjectName(QString::fromUtf8("QuickTaskTask"));
        QuickTaskTask->resize(400, 136);
        verticalLayout = new QVBoxLayout(QuickTaskTask);
        verticalLayout->setMargin(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        deleteButton = new QToolButton(QuickTaskTask);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        title = new QLineEdit(QuickTaskTask);
        title->setObjectName(QString::fromUtf8("title"));

        horizontalLayout->addWidget(title);


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
        Q_UNUSED(QuickTaskTask);
    } // retranslateUi

};

namespace Ui {
    class QuickTaskTask: public Ui_QuickTaskTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUICKTASKTASK_H
