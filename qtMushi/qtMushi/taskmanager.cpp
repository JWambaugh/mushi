#include "taskmanager.h"

#include "taskEditor.h"
TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent){
    setupUi(this);

    finder = new taskFinder();
    this->taskFinderLayout->addWidget(finder);
    connect(this->newButton,SIGNAL(clicked()),this,SLOT(newTask()));
}

void TaskManager::changeEvent(QEvent *e)
{
    switch(e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}


void TaskManager::newTask(){
    TaskEditor* task = new TaskEditor();
    connect(task,SIGNAL(saveComplete()),this->finder,SLOT(search()));
    task->show();
}
