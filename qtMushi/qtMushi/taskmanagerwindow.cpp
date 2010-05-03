#include "taskmanagerwindow.h"
#include "ui_taskmanagerwindow.h"

TaskManagerWindow::TaskManagerWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::TaskManagerWindow)
{
    this->currentActiveCentralWidget=0;
    m_ui->setupUi(this);
    QVBoxLayout *taskListLayout=new QVBoxLayout;
    taskListLayout->setContentsMargins(1,1,1,1);

    this->finder=new taskFinder(this);
    taskListLayout->addWidget(this->finder);
    this->m_ui->dockWidgetContents->setLayout(taskListLayout);


   // this->centralTabWidget=new QTabWidget();
    //this->centralTabWidget->setTabsClosable(true);


    HomePage *page = new HomePage();
    //this->centralTabWidget->addTab(page,"Home");
    this->setActiveCentralWidget(page);
    //this->setCentralWidget(page);
    //this->centralWidgetLayout->addWidget(this->centralTabWidget);
    //this->m_ui->centralwidget->setLayout(this->centralWidgetLayout);


    //make connections
    connect(finder,SIGNAL(taskSelected(Json::Value)),this,SLOT(openTask(Json::Value))); //connect finder activating opening an editor

    //connect(this->centralTabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(closeCentralTab(int)));
    connect(this->m_ui->actionNew,SIGNAL(triggered()),this,SLOT(newTask()));
    connect(this->m_ui->actionDelete,SIGNAL(triggered()),this,SLOT(deleteTask()));
    connect(this->m_ui->actionQuickTaskCreator,SIGNAL(triggered()),this,SLOT(showQuickTaskCreator()));
    connect(this->m_ui->actionRefresh,SIGNAL(triggered()),this->finder,SLOT(search()));
    connect(this->m_ui->actionHome,SIGNAL(triggered()),this,SLOT(showHome()));

}

TaskManagerWindow::~TaskManagerWindow()
{
    delete m_ui;
}


void TaskManagerWindow::openTask(Json::Value value){



    TaskEditor* editor;

    editor=new TaskEditor();
    editor->setStore(value);
    connect(editor,SIGNAL(saveComplete()),this->finder,SLOT(search()));
    //editor->show();
    this->setActiveCentralWidget(editor);
    //this->m_ui->centralWidgetLayout->addWidget(editor);
    //this->setCentralWidget(editor);
    //connect(editor,SIGNAL(destroyed(QObject*)),this,SLOT(removeCentralTab(QObject*)));
}


void TaskManagerWindow::removeCentralTab(QObject *page){

   // this->centralTabWidget->removeTab(this->centralTabWidget->indexOf(static_cast<QWidget *>(page)));

}

void TaskManagerWindow::showQuickTaskCreator(){
    QuickTaskCreator *creator;
    creator = new QuickTaskCreator;
    creator->show();
}


void TaskManagerWindow::closeCentralTab(int index){
    QWidget *page;
    //page=this->centralTabWidget->widget(index);
    //this->centralTabWidget->removeTab(index);
    //page->deleteLater();
}


void TaskManagerWindow::newTask(){

    TaskEditor *task = new TaskEditor();
    connect(task,SIGNAL(saveComplete()),this->finder,SLOT(search()));

    //this->setCentralWidget(task);
    this->setActiveCentralWidget(task);
}

/**
 * Sets the  current active main widget.
 * Automatically deletes previous widget, if there was one.
 */
void TaskManagerWindow::setActiveCentralWidget(QWidget *widget){


    if(this->currentActiveCentralWidget){
       this->m_ui->centerWidgetLayout->removeWidget(this->currentActiveCentralWidget);
       this->currentActiveCentralWidget->deleteLater();
    }

    this->currentActiveCentralWidget=widget;
    this->m_ui->centerWidgetLayout->addWidget(widget);
}

void TaskManagerWindow::deleteTask(){
    ServerCommand *command = new ServerCommand(this);
    Json::Value task = this->finder->getSelectedRecord();
    //if the task doesn't have an id, it can't be deleted. don't worry about it.
    if (task.get("id","")=="")return;

    command->set("command","deleteTask");
    command->set("id",task.get("id","").asString().c_str());
    command->send();
    connect(command,SIGNAL(saveComplete(Json::Value)),this->finder,SLOT(search()));
    connect(command,SIGNAL(saveComplete(Json::Value)),command,SLOT(deleteLater()));
    //find and close any editors of the deleted task
    TaskEditor* editor;
   /* for(int x=0;x<this->centralTabWidget->count();x++){
        editor=dynamic_cast<TaskEditor*>(this->centralTabWidget->widget(x));
        if(editor!=NULL){
            if(editor->store==task){
                editor->deleteLater();
            }
        }
    }*/
}


void TaskManagerWindow::showHome(){
    HomePage *page = new HomePage();
    this->setActiveCentralWidget(page);
}
