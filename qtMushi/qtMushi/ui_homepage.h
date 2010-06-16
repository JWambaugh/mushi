/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created: Tue Jun 15 23:44:54 2010
**      by: Qt User Interface Compiler version 4.6.3
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
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QGridLayout *gridLayout;
    QWebView *webView;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QString::fromUtf8("HomePage"));
        HomePage->resize(400, 300);
        gridLayout = new QGridLayout(HomePage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webView = new QWebView(HomePage);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl("http://localhost:8080/index.mjs"));

        gridLayout->addWidget(webView, 0, 0, 1, 1);


        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        HomePage->setWindowTitle(QApplication::translate("HomePage", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
