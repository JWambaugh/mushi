#include "homepage.h"
#include "ui_homepage.h"
#include <QDebug>
#include <QNetworkRequest>
#include "qtMushi.h"
HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    QNetworkRequest request(QUrl(SERVER_LOCATION "/index.mjs"));
    request.setRawHeader("Connection" ,"close");

    ui->webView->load(request);
    //ui->webView->load();
}

HomePage::~HomePage()
{
    qDebug()<<"DELETED!!!!!!";
    delete ui;
}
