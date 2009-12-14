#include "homepage.h"
#include "ui_homepage.h"
#include <QDebug>
HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    qDebug()<<"DELETED!!!!!!";
    delete ui;
}
