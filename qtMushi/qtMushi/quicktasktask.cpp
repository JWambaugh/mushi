#include "quicktasktask.h"
#include "ui_quicktasktask.h"

QuickTaskTask::QuickTaskTask(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::QuickTaskTask)
{
    m_ui->setupUi(this);
    this->connect(this->m_ui->saveButton,SIGNAL(clicked()),this,SLOT(save()));
}

QuickTaskTask::~QuickTaskTask()
{
    delete m_ui;
}


QString QuickTaskTask::getDescription(){
    return m_ui->description->toPlainText();
}

void QuickTaskTask::setDescription(QString desc){
    m_ui->description->setPlainText(desc);
    if(m_ui->title->text()==""){
        QRegExp rx("(.*)(\n|$)");
        rx.setMinimal(true);
        rx.indexIn(desc, 0);
        this->setTitle(rx.cap(1));
    }
}


QString QuickTaskTask::getTitle(){
    return m_ui->title->text();
}

void QuickTaskTask::setTitle(QString t){
    m_ui->title->setText(t);
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


void QuickTaskTask::updateStore(){

    this->val["title"]=this->m_ui->title->text().toStdString();
    this->val["description"]=this->m_ui->description->toHtml().toStdString();
}


void QuickTaskTask::save(){
    this->updateStore();
    qDebug()<<"saving task";
    //this->val["command"]="editTask";

    ServerCommand *command= new ServerCommand(val,this);
    command->connect(command,SIGNAL(saveComplete(Json::Value)),command,SLOT(deleteLater()));
    command->connect(command,SIGNAL(saveComplete(Json::Value)),this,SLOT(deleteLater()));
    command->connect(command,SIGNAL(saveComplete(Json::Value)),&static_cast <qtMushi *>(qApp)->taskDirectory,SLOT(refresh()));

    command->set("command","addTask");
    command->send();
}
