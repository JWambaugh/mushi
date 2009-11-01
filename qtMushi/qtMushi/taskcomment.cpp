#include "taskcomment.h"
#include "ui_taskcomment.h"

TaskComment::TaskComment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskComment)
{
    ui->setupUi(this);
}

TaskComment::~TaskComment()
{
    delete ui;
}
