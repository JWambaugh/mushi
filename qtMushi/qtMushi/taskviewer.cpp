#include "taskviewer.h"
#include "ui_taskviewer.h"

taskViewer::taskViewer(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::taskViewer)
{
    m_ui->setupUi(this);
}

taskViewer::~taskViewer()
{
    delete m_ui;
}

void taskViewer::changeEvent(QEvent *e)
{
    switch(e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
