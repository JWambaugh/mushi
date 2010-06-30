/********************************************************************************
** Form generated from reading UI file 'taskeditor.ui'
**
** Created: Mon Jun 28 12:11:09 2010
**      by: Qt User Interface Compiler version 4.6.3
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
#include <QtGui/QDateEdit>
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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *title;
    QLabel *label_3;
    QComboBox *taskCombo;
    QLabel *label_6;
    QComboBox *statusCombo;
    QLabel *label_7;
    QComboBox *ownerCombo;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *percentComplete;
    QLabel *label_2;
    QDoubleSpinBox *originalEstimate;
    QLabel *label_5;
    QDoubleSpinBox *currentEstimate;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSplitter *noteSplitter;
    QTextEdit *description;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QDateEdit *dueDate;
    QPushButton *saveButton;
    QPushButton *addNoteButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *TaskEditor)
    {
        if (TaskEditor->objectName().isEmpty())
            TaskEditor->setObjectName(QString::fromUtf8("TaskEditor"));
        TaskEditor->resize(833, 584);
        TaskEditor->setStyleSheet(QString::fromUtf8("QWidget#TaskEditor, QWidget#scrollAreaWidgetContents {\n"
"background-color: #fff;\n"
"}"));
        gridLayout = new QGridLayout(TaskEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(TaskEditor);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 805, 522));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        title = new QLineEdit(scrollAreaWidgetContents);
        title->setObjectName(QString::fromUtf8("title"));

        gridLayout_2->addWidget(title, 0, 1, 1, 7);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        taskCombo = new QComboBox(scrollAreaWidgetContents);
        taskCombo->setObjectName(QString::fromUtf8("taskCombo"));

        gridLayout_2->addWidget(taskCombo, 1, 1, 1, 7);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        statusCombo = new QComboBox(scrollAreaWidgetContents);
        statusCombo->setObjectName(QString::fromUtf8("statusCombo"));

        gridLayout_2->addWidget(statusCombo, 2, 1, 1, 1);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 2, 2, 1, 1);

        ownerCombo = new QComboBox(scrollAreaWidgetContents);
        ownerCombo->setObjectName(QString::fromUtf8("ownerCombo"));
        ownerCombo->setEnabled(true);

        gridLayout_2->addWidget(ownerCombo, 2, 3, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        percentComplete = new QSpinBox(scrollAreaWidgetContents);
        percentComplete->setObjectName(QString::fromUtf8("percentComplete"));
        percentComplete->setMaximum(100);

        horizontalLayout_2->addWidget(percentComplete);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        originalEstimate = new QDoubleSpinBox(scrollAreaWidgetContents);
        originalEstimate->setObjectName(QString::fromUtf8("originalEstimate"));
        originalEstimate->setDecimals(1);
        originalEstimate->setMaximum(100);
        originalEstimate->setSingleStep(0.5);

        horizontalLayout_2->addWidget(originalEstimate);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        currentEstimate = new QDoubleSpinBox(scrollAreaWidgetContents);
        currentEstimate->setObjectName(QString::fromUtf8("currentEstimate"));
        currentEstimate->setDecimals(1);
        currentEstimate->setSingleStep(0.5);

        horizontalLayout_2->addWidget(currentEstimate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 1, 1, 8);

        horizontalSpacer_2 = new QSpacerItem(381, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 6, 3, 1, 1);

        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        noteSplitter = new QSplitter(widget);
        noteSplitter->setObjectName(QString::fromUtf8("noteSplitter"));
        noteSplitter->setOrientation(Qt::Vertical);
        noteSplitter->setOpaqueResize(true);
        noteSplitter->setChildrenCollapsible(false);
        description = new QTextEdit(noteSplitter);
        description->setObjectName(QString::fromUtf8("description"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy1);
        description->setMinimumSize(QSize(0, 100));
        noteSplitter->addWidget(description);

        verticalLayout->addWidget(noteSplitter);


        gridLayout_2->addWidget(widget, 4, 0, 1, 9);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 8, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 8, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 8, 1, 1);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 2, 5, 1, 1);

        dueDate = new QDateEdit(scrollAreaWidgetContents);
        dueDate->setObjectName(QString::fromUtf8("dueDate"));
        dueDate->setCalendarPopup(true);

        gridLayout_2->addWidget(dueDate, 2, 6, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 3);

        saveButton = new QPushButton(TaskEditor);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 1, 0, 1, 1);

        addNoteButton = new QPushButton(TaskEditor);
        addNoteButton->setObjectName(QString::fromUtf8("addNoteButton"));

        gridLayout->addWidget(addNoteButton, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        retranslateUi(TaskEditor);

        QMetaObject::connectSlotsByName(TaskEditor);
    } // setupUi

    void retranslateUi(QWidget *TaskEditor)
    {
        TaskEditor->setWindowTitle(QApplication::translate("TaskEditor", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TaskEditor", "Title", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TaskEditor", "Subtask Of", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TaskEditor", "Status", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TaskEditor", "Owner", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TaskEditor", "Complete", 0, QApplication::UnicodeUTF8));
        percentComplete->setSuffix(QApplication::translate("TaskEditor", "%", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TaskEditor", "Original Est.", 0, QApplication::UnicodeUTF8));
        originalEstimate->setSuffix(QApplication::translate("TaskEditor", " Hrs.", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TaskEditor", "Remaining Est.", 0, QApplication::UnicodeUTF8));
        currentEstimate->setSuffix(QApplication::translate("TaskEditor", " Hrs.", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TaskEditor", "Due Date:", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("TaskEditor", "Save", 0, QApplication::UnicodeUTF8));
        addNoteButton->setText(QApplication::translate("TaskEditor", "Add Comment", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskEditor: public Ui_TaskEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKEDITOR_H
