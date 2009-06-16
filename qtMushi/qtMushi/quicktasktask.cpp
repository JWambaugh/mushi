#include "quicktasktask.h"
#include "ui_quicktasktask.h"

QuickTaskTask::QuickTaskTask(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::QuickTaskTask)
{
    m_ui->setupUi(this);
}

QuickTaskTask::~QuickTaskTask()
{
    delete m_ui;
}

void QuickTaskTask::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
