/********************************************************************************
** Form generated from reading UI file 'taskeditor.ui'
**
** Created: Thu Nov 12 13:23:28 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKEDITOR_H
#define UI_TASKEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskEditor
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *title;
    QLabel *label_3;
    QComboBox *taskCombo;
    QComboBox *statusCombo;
    QLabel *label_7;
    QComboBox *authorCombo;
    QTextEdit *description;
    QLabel *label_4;
    QSpinBox *percentComplete;
    QLabel *label_2;
    QDoubleSpinBox *originalEstimate;
    QLabel *label_5;
    QDoubleSpinBox *currentEstimate;
    QPushButton *saveButton;
    QLabel *label_6;

    void setupUi(QWidget *TaskEditor)
    {
        if (TaskEditor->objectName().isEmpty())
            TaskEditor->setObjectName(QString::fromUtf8("TaskEditor"));
        TaskEditor->resize(833, 499);
        gridLayout = new QGridLayout(TaskEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(TaskEditor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        title = new QLineEdit(TaskEditor);
        title->setObjectName(QString::fromUtf8("title"));

        gridLayout->addWidget(title, 1, 1, 1, 5);

        label_3 = new QLabel(TaskEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        taskCombo = new QComboBox(TaskEditor);
        taskCombo->setObjectName(QString::fromUtf8("taskCombo"));

        gridLayout->addWidget(taskCombo, 5, 1, 1, 5);

        statusCombo = new QComboBox(TaskEditor);
        statusCombo->setObjectName(QString::fromUtf8("statusCombo"));

        gridLayout->addWidget(statusCombo, 6, 1, 1, 3);

        label_7 = new QLabel(TaskEditor);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 6, 4, 1, 1);

        authorCombo = new QComboBox(TaskEditor);
        authorCombo->setObjectName(QString::fromUtf8("authorCombo"));

        gridLayout->addWidget(authorCombo, 6, 5, 1, 1);

        description = new QTextEdit(TaskEditor);
        description->setObjectName(QString::fromUtf8("description"));

        gridLayout->addWidget(description, 9, 0, 1, 6);

        label_4 = new QLabel(TaskEditor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        percentComplete = new QSpinBox(TaskEditor);
        percentComplete->setObjectName(QString::fromUtf8("percentComplete"));
        percentComplete->setMaximum(100);

        gridLayout->addWidget(percentComplete, 7, 1, 1, 1);

        label_2 = new QLabel(TaskEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 7, 2, 1, 1);

        originalEstimate = new QDoubleSpinBox(TaskEditor);
        originalEstimate->setObjectName(QString::fromUtf8("originalEstimate"));
        originalEstimate->setDecimals(1);
        originalEstimate->setMaximum(100);
        originalEstimate->setSingleStep(0.5);

        gridLayout->addWidget(originalEstimate, 7, 3, 1, 1);

        label_5 = new QLabel(TaskEditor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 7, 4, 1, 1);

        currentEstimate = new QDoubleSpinBox(TaskEditor);
        currentEstimate->setObjectName(QString::fromUtf8("currentEstimate"));
        currentEstimate->setDecimals(1);
        currentEstimate->setSingleStep(0.5);

        gridLayout->addWidget(currentEstimate, 7, 5, 1, 1);

        saveButton = new QPushButton(TaskEditor);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 10, 0, 1, 1);

        label_6 = new QLabel(TaskEditor);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);
        gridLayout->setColumnStretch(4, 1);
        gridLayout->setColumnStretch(5, 1);

        retranslateUi(TaskEditor);

        QMetaObject::connectSlotsByName(TaskEditor);
    } // setupUi

    void retranslateUi(QWidget *TaskEditor)
    {
        TaskEditor->setWindowTitle(QApplication::translate("TaskEditor", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TaskEditor", "Title", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TaskEditor", "Subtask Of", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TaskEditor", "Author", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TaskEditor", "Complete", 0, QApplication::UnicodeUTF8));
        percentComplete->setSuffix(QApplication::translate("TaskEditor", "%", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TaskEditor", "Original Est.", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TaskEditor", "Remaining Est.", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("TaskEditor", "Save", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TaskEditor", "Status", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskEditor: public Ui_TaskEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKEDITOR_H
