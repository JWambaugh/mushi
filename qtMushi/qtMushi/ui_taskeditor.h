/********************************************************************************
** Form generated from reading ui file 'taskeditor.ui'
**
** Created: Wed Jul 8 15:49:08 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TASKEDITOR_H
#define UI_TASKEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskEditor
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *title;
    QTextEdit *description;
    QLabel *label_2;
    QPushButton *saveButton;

    void setupUi(QWidget *TaskEditor)
    {
        if (TaskEditor->objectName().isEmpty())
            TaskEditor->setObjectName(QString::fromUtf8("TaskEditor"));
        TaskEditor->resize(636, 422);
        gridLayout = new QGridLayout(TaskEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(TaskEditor);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        title = new QLineEdit(TaskEditor);
        title->setObjectName(QString::fromUtf8("title"));

        gridLayout->addWidget(title, 0, 1, 1, 1);

        description = new QTextEdit(TaskEditor);
        description->setObjectName(QString::fromUtf8("description"));

        gridLayout->addWidget(description, 1, 1, 1, 1);

        label_2 = new QLabel(TaskEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        saveButton = new QPushButton(TaskEditor);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 2, 1, 1, 1);


        retranslateUi(TaskEditor);

        QMetaObject::connectSlotsByName(TaskEditor);
    } // setupUi

    void retranslateUi(QWidget *TaskEditor)
    {
        TaskEditor->setWindowTitle(QApplication::translate("TaskEditor", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TaskEditor", "Title", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TaskEditor", "Description", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("TaskEditor", "Save", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(TaskEditor);
    } // retranslateUi

};

namespace Ui {
    class TaskEditor: public Ui_TaskEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKEDITOR_H
