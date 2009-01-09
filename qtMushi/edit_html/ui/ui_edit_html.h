/********************************************************************************
** Form generated from reading ui file 'edit_html.ui'
**
** Created: Mon Jan 5 19:00:43 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_EDIT_HTML_H
#define UI_EDIT_HTML_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "qvimedit.h"

QT_BEGIN_NAMESPACE

class Ui_Edit_html
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout1;
    QVimedit *wtext;
    QWidget *tab_2;
    QGridLayout *gridLayout2;
    QHBoxLayout *hboxLayout;
    QTextEdit *sline;
    QTextEdit *stext;
    QHBoxLayout *hboxLayout1;
    QComboBox *list_ul;
    QFontComboBox *fontname;
    QComboBox *fontsize;
    QToolButton *vol_color;
    QToolButton *vol_br;
    QToolButton *vol_img;
    QToolButton *val_table;
    QPushButton *savecache;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout2;
    QToolButton *vol_print;
    QToolButton *vol_pdf;
    QToolButton *vol_html;
    QToolButton *vol_undo;
    QToolButton *vol_redo;
    QToolButton *vol_cut;
    QToolButton *vol_copy;
    QToolButton *mypaste;
    QToolButton *vol_link;
    QToolButton *vol_bold;
    QToolButton *vol_italic;
    QToolButton *vol_underline;
    QToolButton *vol_left;
    QToolButton *vol_center;
    QToolButton *vol_right;
    QToolButton *vol_justify;
    QToolButton *vol_source;
    QSpacerItem *spacerItem1;

    void setupUi(QWidget *Edit_html)
    {
    if (Edit_html->objectName().isEmpty())
        Edit_html->setObjectName(QString::fromUtf8("Edit_html"));
    Edit_html->resize(788, 485);
    gridLayout = new QGridLayout(Edit_html);
#ifndef Q_OS_MAC
    gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout->setMargin(9);
#endif
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    tabWidget = new QTabWidget(Edit_html);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    gridLayout1 = new QGridLayout(tab);
#ifndef Q_OS_MAC
    gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout1->setMargin(9);
#endif
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    wtext = new QVimedit(tab);
    wtext->setObjectName(QString::fromUtf8("wtext"));
    wtext->setAcceptDrops(false);
    wtext->setReadOnly(false);
    wtext->setOpenExternalLinks(true);

    gridLayout1->addWidget(wtext, 0, 0, 1, 1);

    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/img/icon.png")), QIcon::Normal, QIcon::Off);
    tabWidget->addTab(tab, icon, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    gridLayout2 = new QGridLayout(tab_2);
#ifndef Q_OS_MAC
    gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout2->setMargin(9);
#endif
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
    hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    hboxLayout->setMargin(0);
#endif
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    sline = new QTextEdit(tab_2);
    sline->setObjectName(QString::fromUtf8("sline"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(sline->sizePolicy().hasHeightForWidth());
    sline->setSizePolicy(sizePolicy);
    sline->setMinimumSize(QSize(75, 0));
    sline->setMaximumSize(QSize(75, 16777215));
    QPalette palette;
    QBrush brush(QColor(208, 208, 208, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Light, brush);
    QBrush brush1(QColor(0, 0, 0, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
    QBrush brush2(QColor(223, 223, 223, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Base, brush2);
    palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
    palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
    palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
    QBrush brush3(QColor(235, 233, 237, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
    palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
    sline->setPalette(palette);
    sline->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ForbiddenCursor)));
    sline->setFrameShadow(QFrame::Raised);
    sline->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sline->setReadOnly(true);

    hboxLayout->addWidget(sline);

    stext = new QTextEdit(tab_2);
    stext->setObjectName(QString::fromUtf8("stext"));
    stext->setAutoFormatting(QTextEdit::AutoAll);
    stext->setAcceptRichText(false);

    hboxLayout->addWidget(stext);


    gridLayout2->addLayout(hboxLayout, 0, 0, 1, 1);

    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/img/view-source.png")), QIcon::Normal, QIcon::Off);
    tabWidget->addTab(tab_2, icon1, QString());

    gridLayout->addWidget(tabWidget, 2, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
    hboxLayout1->setSpacing(6);
#endif
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    list_ul = new QComboBox(Edit_html);
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/img/unordered-list.png")), QIcon::Normal, QIcon::Off);
    list_ul->addItem(icon2, QString());
    list_ul->setObjectName(QString::fromUtf8("list_ul"));

    hboxLayout1->addWidget(list_ul);

    fontname = new QFontComboBox(Edit_html);
    fontname->setObjectName(QString::fromUtf8("fontname"));

    hboxLayout1->addWidget(fontname);

    fontsize = new QComboBox(Edit_html);
    fontsize->setObjectName(QString::fromUtf8("fontsize"));

    hboxLayout1->addWidget(fontsize);

    vol_color = new QToolButton(Edit_html);
    vol_color->setObjectName(QString::fromUtf8("vol_color"));
    QIcon icon3;
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/img/info.png")), QIcon::Normal, QIcon::Off);
    vol_color->setIcon(icon3);
    vol_color->setIconSize(QSize(22, 22));

    hboxLayout1->addWidget(vol_color);

    vol_br = new QToolButton(Edit_html);
    vol_br->setObjectName(QString::fromUtf8("vol_br"));
    QIcon icon4;
    icon4.addPixmap(QPixmap(QString::fromUtf8(":/img/document.png")), QIcon::Normal, QIcon::Off);
    vol_br->setIcon(icon4);
    vol_br->setIconSize(QSize(22, 22));

    hboxLayout1->addWidget(vol_br);

    vol_img = new QToolButton(Edit_html);
    vol_img->setObjectName(QString::fromUtf8("vol_img"));
    QIcon icon5;
    icon5.addPixmap(QPixmap(QString::fromUtf8(":/img/pictures.png")), QIcon::Normal, QIcon::Off);
    vol_img->setIcon(icon5);
    vol_img->setIconSize(QSize(22, 22));

    hboxLayout1->addWidget(vol_img);

    val_table = new QToolButton(Edit_html);
    val_table->setObjectName(QString::fromUtf8("val_table"));
    QIcon icon6;
    icon6.addPixmap(QPixmap(QString::fromUtf8(":/img/table.png")), QIcon::Normal, QIcon::Off);
    val_table->setIcon(icon6);
    val_table->setIconSize(QSize(22, 22));

    hboxLayout1->addWidget(val_table);

    savecache = new QPushButton(Edit_html);
    savecache->setObjectName(QString::fromUtf8("savecache"));
    QIcon icon7;
    icon7.addPixmap(QPixmap(QString::fromUtf8(":/img/filesave.png")), QIcon::Normal, QIcon::Off);
    savecache->setIcon(icon7);
    savecache->setIconSize(QSize(22, 22));

    hboxLayout1->addWidget(savecache);

    spacerItem = new QSpacerItem(141, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);


    gridLayout->addLayout(hboxLayout1, 1, 0, 1, 1);

    hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
    hboxLayout2->setSpacing(6);
#endif
    hboxLayout2->setMargin(0);
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    vol_print = new QToolButton(Edit_html);
    vol_print->setObjectName(QString::fromUtf8("vol_print"));
    QIcon icon8;
    icon8.addPixmap(QPixmap(QString::fromUtf8(":/img/fileprint.png")), QIcon::Normal, QIcon::Off);
    vol_print->setIcon(icon8);
    vol_print->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_print);

    vol_pdf = new QToolButton(Edit_html);
    vol_pdf->setObjectName(QString::fromUtf8("vol_pdf"));
    QIcon icon9;
    icon9.addPixmap(QPixmap(QString::fromUtf8(":/img/exportpdf.png")), QIcon::Normal, QIcon::Off);
    vol_pdf->setIcon(icon9);
    vol_pdf->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_pdf);

    vol_html = new QToolButton(Edit_html);
    vol_html->setObjectName(QString::fromUtf8("vol_html"));
    vol_html->setIcon(icon7);
    vol_html->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_html);

    vol_undo = new QToolButton(Edit_html);
    vol_undo->setObjectName(QString::fromUtf8("vol_undo"));
    QIcon icon10;
    icon10.addPixmap(QPixmap(QString::fromUtf8(":/img/editundo.png")), QIcon::Normal, QIcon::Off);
    vol_undo->setIcon(icon10);
    vol_undo->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_undo);

    vol_redo = new QToolButton(Edit_html);
    vol_redo->setObjectName(QString::fromUtf8("vol_redo"));
    QIcon icon11;
    icon11.addPixmap(QPixmap(QString::fromUtf8(":/img/editredo.png")), QIcon::Normal, QIcon::Off);
    vol_redo->setIcon(icon11);
    vol_redo->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_redo);

    vol_cut = new QToolButton(Edit_html);
    vol_cut->setObjectName(QString::fromUtf8("vol_cut"));
    QIcon icon12;
    icon12.addPixmap(QPixmap(QString::fromUtf8(":/img/cut.png")), QIcon::Normal, QIcon::Off);
    vol_cut->setIcon(icon12);
    vol_cut->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_cut);

    vol_copy = new QToolButton(Edit_html);
    vol_copy->setObjectName(QString::fromUtf8("vol_copy"));
    QIcon icon13;
    icon13.addPixmap(QPixmap(QString::fromUtf8(":/img/copy.png")), QIcon::Normal, QIcon::Off);
    vol_copy->setIcon(icon13);
    vol_copy->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_copy);

    mypaste = new QToolButton(Edit_html);
    mypaste->setObjectName(QString::fromUtf8("mypaste"));
    QIcon icon14;
    icon14.addPixmap(QPixmap(QString::fromUtf8(":/img/paste.png")), QIcon::Normal, QIcon::Off);
    mypaste->setIcon(icon14);
    mypaste->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(mypaste);

    vol_link = new QToolButton(Edit_html);
    vol_link->setObjectName(QString::fromUtf8("vol_link"));
    QIcon icon15;
    icon15.addPixmap(QPixmap(QString::fromUtf8(":/img/link.png")), QIcon::Normal, QIcon::Off);
    vol_link->setIcon(icon15);
    vol_link->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_link);

    vol_bold = new QToolButton(Edit_html);
    vol_bold->setObjectName(QString::fromUtf8("vol_bold"));
    QIcon icon16;
    icon16.addPixmap(QPixmap(QString::fromUtf8(":/img/textbold.png")), QIcon::Normal, QIcon::Off);
    vol_bold->setIcon(icon16);
    vol_bold->setIconSize(QSize(22, 22));
    vol_bold->setCheckable(true);

    hboxLayout2->addWidget(vol_bold);

    vol_italic = new QToolButton(Edit_html);
    vol_italic->setObjectName(QString::fromUtf8("vol_italic"));
    QIcon icon17;
    icon17.addPixmap(QPixmap(QString::fromUtf8(":/img/textitalic.png")), QIcon::Normal, QIcon::Off);
    vol_italic->setIcon(icon17);
    vol_italic->setIconSize(QSize(22, 22));
    vol_italic->setCheckable(true);

    hboxLayout2->addWidget(vol_italic);

    vol_underline = new QToolButton(Edit_html);
    vol_underline->setObjectName(QString::fromUtf8("vol_underline"));
    QIcon icon18;
    icon18.addPixmap(QPixmap(QString::fromUtf8(":/img/textunder.png")), QIcon::Normal, QIcon::Off);
    vol_underline->setIcon(icon18);
    vol_underline->setIconSize(QSize(22, 22));
    vol_underline->setCheckable(true);

    hboxLayout2->addWidget(vol_underline);

    vol_left = new QToolButton(Edit_html);
    vol_left->setObjectName(QString::fromUtf8("vol_left"));
    QIcon icon19;
    icon19.addPixmap(QPixmap(QString::fromUtf8(":/img/textleft.png")), QIcon::Normal, QIcon::Off);
    vol_left->setIcon(icon19);
    vol_left->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_left);

    vol_center = new QToolButton(Edit_html);
    vol_center->setObjectName(QString::fromUtf8("vol_center"));
    QIcon icon20;
    icon20.addPixmap(QPixmap(QString::fromUtf8(":/img/textcenter.png")), QIcon::Normal, QIcon::Off);
    vol_center->setIcon(icon20);
    vol_center->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_center);

    vol_right = new QToolButton(Edit_html);
    vol_right->setObjectName(QString::fromUtf8("vol_right"));
    QIcon icon21;
    icon21.addPixmap(QPixmap(QString::fromUtf8(":/img/textright.png")), QIcon::Normal, QIcon::Off);
    vol_right->setIcon(icon21);
    vol_right->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_right);

    vol_justify = new QToolButton(Edit_html);
    vol_justify->setObjectName(QString::fromUtf8("vol_justify"));
    QIcon icon22;
    icon22.addPixmap(QPixmap(QString::fromUtf8(":/img/textjustify.png")), QIcon::Normal, QIcon::Off);
    vol_justify->setIcon(icon22);
    vol_justify->setIconSize(QSize(22, 22));

    hboxLayout2->addWidget(vol_justify);

    vol_source = new QToolButton(Edit_html);
    vol_source->setObjectName(QString::fromUtf8("vol_source"));
    vol_source->setIcon(icon1);
    vol_source->setIconSize(QSize(22, 22));
    vol_source->setCheckable(true);

    hboxLayout2->addWidget(vol_source);

    spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout2->addItem(spacerItem1);


    gridLayout->addLayout(hboxLayout2, 0, 0, 1, 1);


    retranslateUi(Edit_html);

    tabWidget->setCurrentIndex(1);


    QMetaObject::connectSlotsByName(Edit_html);
    } // setupUi

    void retranslateUi(QWidget *Edit_html)
    {
    Edit_html->setWindowTitle(QApplication::translate("Edit_html", "Form", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Edit_html", "Edit and View", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Edit_html", "Source View", 0, QApplication::UnicodeUTF8));
    list_ul->setItemText(0, QApplication::translate("Edit_html", "New Item", 0, QApplication::UnicodeUTF8));

    fontsize->clear();
    fontsize->insertItems(0, QStringList()
     << QApplication::translate("Edit_html", "12", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("Edit_html", "15", 0, QApplication::UnicodeUTF8)
    );

#ifndef QT_NO_TOOLTIP
    vol_color->setToolTip(QApplication::translate("Edit_html", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Font color</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_WHATSTHIS
    vol_color->setWhatsThis(QApplication::translate("Edit_html", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Font color</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_color->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_br->setToolTip(QApplication::translate("Edit_html", "Break Line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_br->setStatusTip(QApplication::translate("Edit_html", "Break Line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_br->setWhatsThis(QApplication::translate("Edit_html", "Break Line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_br->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_img->setToolTip(QApplication::translate("Edit_html", "New Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_img->setStatusTip(QApplication::translate("Edit_html", "New Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_img->setWhatsThis(QApplication::translate("Edit_html", "New Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_img->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    val_table->setToolTip(QApplication::translate("Edit_html", "New Table", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    val_table->setStatusTip(QApplication::translate("Edit_html", "New Table", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    val_table->setWhatsThis(QApplication::translate("Edit_html", "New Table", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    val_table->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));
    savecache->setText(QApplication::translate("Edit_html", "Save HTML ", 0, QApplication::UnicodeUTF8));
    savecache->setShortcut(QApplication::translate("Edit_html", "Ctrl+F", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_print->setToolTip(QApplication::translate("Edit_html", "Print File", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_print->setStatusTip(QApplication::translate("Edit_html", "Print File", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_print->setWhatsThis(QApplication::translate("Edit_html", "Print File", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_print->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_pdf->setToolTip(QApplication::translate("Edit_html", "Export as PDF", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_pdf->setStatusTip(QApplication::translate("Edit_html", "Export as PDF", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_pdf->setWhatsThis(QApplication::translate("Edit_html", "Export as PDF", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_pdf->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_html->setToolTip(QApplication::translate("Edit_html", "Export as html", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_html->setStatusTip(QApplication::translate("Edit_html", "Export as html", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_html->setWhatsThis(QApplication::translate("Edit_html", "Export as html", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_html->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_undo->setToolTip(QApplication::translate("Edit_html", "Undo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_undo->setStatusTip(QApplication::translate("Edit_html", "Undo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_undo->setWhatsThis(QApplication::translate("Edit_html", "Undo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_undo->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_redo->setToolTip(QApplication::translate("Edit_html", "Redo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_redo->setStatusTip(QApplication::translate("Edit_html", "Redo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_redo->setWhatsThis(QApplication::translate("Edit_html", "Redo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_redo->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_cut->setToolTip(QApplication::translate("Edit_html", "Cut", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_cut->setStatusTip(QApplication::translate("Edit_html", "Cut", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_cut->setWhatsThis(QApplication::translate("Edit_html", "Cut", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_cut->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_copy->setToolTip(QApplication::translate("Edit_html", "Copy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_copy->setStatusTip(QApplication::translate("Edit_html", "Copy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_copy->setWhatsThis(QApplication::translate("Edit_html", "Copy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_copy->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    mypaste->setToolTip(QApplication::translate("Edit_html", "Paste", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    mypaste->setStatusTip(QApplication::translate("Edit_html", "Paste", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    mypaste->setWhatsThis(QApplication::translate("Edit_html", "Paste", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    mypaste->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_link->setToolTip(QApplication::translate("Edit_html", "Link", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_link->setStatusTip(QApplication::translate("Edit_html", "Link", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_link->setWhatsThis(QApplication::translate("Edit_html", "Link", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_link->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_bold->setToolTip(QApplication::translate("Edit_html", "Bold", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_bold->setStatusTip(QApplication::translate("Edit_html", "Bold", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_bold->setWhatsThis(QApplication::translate("Edit_html", "Bold", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_bold->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_italic->setToolTip(QApplication::translate("Edit_html", "Italic", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_italic->setStatusTip(QApplication::translate("Edit_html", "Italic", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_italic->setWhatsThis(QApplication::translate("Edit_html", "Italic", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_italic->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_underline->setToolTip(QApplication::translate("Edit_html", "Underline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_underline->setStatusTip(QApplication::translate("Edit_html", "Underline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_underline->setWhatsThis(QApplication::translate("Edit_html", "Underline", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_underline->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_left->setToolTip(QApplication::translate("Edit_html", "Text align Left", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_left->setStatusTip(QApplication::translate("Edit_html", "Text align Left", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_left->setWhatsThis(QApplication::translate("Edit_html", "Text align Left", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_left->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_center->setToolTip(QApplication::translate("Edit_html", "Text align Center", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_center->setStatusTip(QApplication::translate("Edit_html", "Text align Center", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_center->setWhatsThis(QApplication::translate("Edit_html", "Text align Center", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_center->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_right->setToolTip(QApplication::translate("Edit_html", "Text align Center", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_right->setStatusTip(QApplication::translate("Edit_html", "Text align Center", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_right->setWhatsThis(QApplication::translate("Edit_html", "Text align Center", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_right->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_justify->setToolTip(QApplication::translate("Edit_html", "Text align Justify", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_justify->setStatusTip(QApplication::translate("Edit_html", "Text align Justify", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_justify->setWhatsThis(QApplication::translate("Edit_html", "Text align Justify", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_justify->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    vol_source->setToolTip(QApplication::translate("Edit_html", "Source View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP


#ifndef QT_NO_STATUSTIP
    vol_source->setStatusTip(QApplication::translate("Edit_html", "Source View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP


#ifndef QT_NO_WHATSTHIS
    vol_source->setWhatsThis(QApplication::translate("Edit_html", "Source View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS

    vol_source->setText(QApplication::translate("Edit_html", "...", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Edit_html);
    } // retranslateUi

};

namespace Ui {
    class Edit_html: public Ui_Edit_html {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_HTML_H
