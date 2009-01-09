#include "taskmanager.h"
#include "taskFinder.h"
TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent){
    setupUi(this);

    taskFinder *finder = new taskFinder();
    this->taskFinderLayout->addWidget(finder);
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
