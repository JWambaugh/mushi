/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created: Tue Jan 12 15:54:42 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QString::fromUtf8("HomePage"));
        HomePage->resize(400, 300);
        gridLayout = new QGridLayout(HomePage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(HomePage);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(HomePage);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);


        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        HomePage->setWindowTitle(QApplication::translate("HomePage", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HomePage", "Home", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
