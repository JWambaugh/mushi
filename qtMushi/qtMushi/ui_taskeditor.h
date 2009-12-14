/********************************************************************************
** Form generated from reading UI file 'taskeditor.ui'
**
** Created: Mon Dec 14 14:32:21 2009
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
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
    QComboBox *ownerCombo;
    QLabel *label_4;
    QPushButton *saveButton;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTextEdit *description;
    QScrollArea *notesScrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *percentComplete;
    QLabel *label_2;
    QDoubleSpinBox *originalEstimate;
    QLabel *label_5;
    QDoubleSpinBox *currentEstimate;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *TaskEditor)
    {
        if (TaskEditor->objectName().isEmpty())
            TaskEditor->setObjectName(QString::fromUtf8("TaskEditor"));
        TaskEditor->resize(833, 499);
        gridLayout = new QGridLayout(TaskEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(TaskEditor);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        title = new QLineEdit(TaskEditor);
        title->setObjectName(QString::fromUtf8("title"));

        gridLayout->addWidget(title, 1, 1, 1, 5);

        label_3 = new QLabel(TaskEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        taskCombo = new QComboBox(TaskEditor);
        taskCombo->setObjectName(QString::fromUtf8("taskCombo"));

        gridLayout->addWidget(taskCombo, 5, 1, 1, 5);

        statusCombo = new QComboBox(TaskEditor);
        statusCombo->setObjectName(QString::fromUtf8("statusCombo"));

        gridLayout->addWidget(statusCombo, 6, 1, 1, 2);

        ownerCombo = new QComboBox(TaskEditor);
        ownerCombo->setObjectName(QString::fromUtf8("ownerCombo"));

        gridLayout->addWidget(ownerCombo, 6, 4, 1, 2);

        label_4 = new QLabel(TaskEditor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        saveButton = new QPushButton(TaskEditor);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 9, 0, 1, 1);

        label_6 = new QLabel(TaskEditor);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        label_7 = new QLabel(TaskEditor);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 6, 3, 1, 1);

        widget = new QWidget(TaskEditor);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(widget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        description = new QTextEdit(splitter);
        description->setObjectName(QString::fromUtf8("description"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy1);
        splitter->addWidget(description);
        notesScrollArea = new QScrollArea(splitter);
        notesScrollArea->setObjectName(QString::fromUtf8("notesScrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(notesScrollArea->sizePolicy().hasHeightForWidth());
        notesScrollArea->setSizePolicy(sizePolicy2);
        notesScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 781, 113));
        notesScrollArea->setWidget(scrollAreaWidgetContents);
        splitter->addWidget(notesScrollArea);

        verticalLayout->addWidget(splitter);


        gridLayout->addWidget(widget, 8, 0, 1, 6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        percentComplete = new QSpinBox(TaskEditor);
        percentComplete->setObjectName(QString::fromUtf8("percentComplete"));
        percentComplete->setMaximum(100);

        horizontalLayout_2->addWidget(percentComplete);

        label_2 = new QLabel(TaskEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        originalEstimate = new QDoubleSpinBox(TaskEditor);
        originalEstimate->setObjectName(QString::fromUtf8("originalEstimate"));
        originalEstimate->setDecimals(1);
        originalEstimate->setMaximum(100);
        originalEstimate->setSingleStep(0.5);

        horizontalLayout_2->addWidget(originalEstimate);

        label_5 = new QLabel(TaskEditor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        currentEstimate = new QDoubleSpinBox(TaskEditor);
        currentEstimate->setObjectName(QString::fromUtf8("currentEstimate"));
        currentEstimate->setDecimals(1);
        currentEstimate->setSingleStep(0.5);

        horizontalLayout_2->addWidget(currentEstimate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 7, 1, 1, 5);

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
        label_4->setText(QApplication::translate("TaskEditor", "Complete", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("TaskEditor", "Save", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TaskEditor", "Status", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TaskEditor", "Owner", 0, QApplication::UnicodeUTF8));
        percentComplete->setSuffix(QApplication::translate("TaskEditor", "%", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TaskEditor", "Original Est.", 0, QApplication::UnicodeUTF8));
        originalEstimate->setSuffix(QApplication::translate("TaskEditor", " Hrs.", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TaskEditor", "Remaining Est.", 0, QApplication::UnicodeUTF8));
        currentEstimate->setSuffix(QApplication::translate("TaskEditor", " Hrs.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskEditor: public Ui_TaskEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKEDITOR_H
