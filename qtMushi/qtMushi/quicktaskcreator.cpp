#include "quicktaskcreator.h"
#include "ui_quicktaskcreator.h"

QuickTaskCreator::QuickTaskCreator(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::QuickTaskCreator)
{
    m_ui->setupUi(this);
    taskifyAction = new QAction(tr("&Taskify..."), this);
    connect(taskifyAction,SIGNAL(activated()),this,SLOT(taskify()));
    taskLayout = new QVBoxLayout();
    this->m_ui->toolBar->addAction(taskifyAction);
    taskLayout->setMargin(2);
    this->m_ui->taskListWidget->setLayout(taskLayout);
    this->defaultsWidget=new QuickTaskCreatorDefaults;
    this->m_ui->defaultsArea->setWidget(this->defaultsWidget);
//    this->connect(this->m_ui->editor,SIGNAL(textChanged()),this,SLOT(taskify()));

    this->connect(this->m_ui->saveAllButton,SIGNAL(clicked()),this,SLOT(saveAll()));
}

QuickTaskCreator::~QuickTaskCreator()
{
    delete m_ui;
}

void QuickTaskCreator::taskify(){
    QString text=this->m_ui->editor->toPlainText();
    QRegExp rx("(.*)(\n|$)");
    int pos = 0;
    rx.setMinimal(true);
    //loop through each line
    QString currentTask;
    QStringList tasks;
    QRegExp newTask("^[ |\t|\\s]*([-\\*]|[0-9]+\\.)[ |\t|\\s]*(.+)$");

    newTask.setMinimal(true);
    while ((pos = rx.indexIn(text, pos)) != -1) {
       if(rx.matchedLength()==0)pos++;
       QString line =rx.cap(1);
       pos += rx.matchedLength();
       qDebug()<<"line:" <<line;
       if(newTask.exactMatch(line)||line==""){
            if(currentTask!=""){

                currentTask.replace(QRegExp("^[ |\t|\\s]+"),"");
                tasks << currentTask;
            }
            currentTask="";
            currentTask.append(newTask.cap(2));

       }else {
           if(currentTask!="")currentTask.append("\n");
            currentTask.append(line);
       }



   }
    //handle final task.
   if(currentTask!="")currentTask.append("\n");
    currentTask.append(rx.cap(1));
    if(currentTask!=""){
        currentTask.replace(QRegExp("^[ |\t|\\s]+"),"");
        tasks<<currentTask;
    }

    //remove all widgets if we already have some
    while (this->taskWidgets.count()){
        QuickTaskTask *task;
        task = this->taskWidgets.takeFirst();
        this->taskLayout->removeWidget(task);
        task->deleteLater();
    }
    //add new widgets
    for(int x=0;x<tasks.length();x++){
        qDebug()<<"Task: "<<tasks.at(x);
        QuickTaskTask *task=new QuickTaskTask(this);
            task->setDescription(tasks.at(x));

            task->val["parentTaskID"]=this->defaultsWidget->getParent().toStdString();
            task->val["statusID"]=this->defaultsWidget->getStatus().toStdString();
            task->val["ownerID"]=this->defaultsWidget->getOwner().toStdString();
            this->taskLayout->addWidget(task);
            this->taskWidgets.append(task);
    }
    //this->layout.addWidget(&this->editor);
    this->m_ui->editor->moveCursor(QTextCursor::End);
}


void QuickTaskCreator::saveAll(){
    for(int x=0; x<this->taskWidgets.count();x++){
        QuickTaskTask *task;
        //task = static_cast<QuickTaskTask>(this->taskWidgets.at(x));
        task=this->taskWidgets.at(x);
        task->save();
    }

}
