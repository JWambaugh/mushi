#include "quicktask.h"

QuickTask::QuickTask(QWidget *parent):QWidget(parent)
{

    this->editorLayout.addWidget(&this->editor);
    this->editorLayout.addWidget(&this->taskifyButton);
    this->taskifyButton.setText("Taskify");
    this->mainLayout.addLayout(&this->editorLayout);
    this->mainLayout.addLayout(&this->taskLayout);
    this->setLayout(&this->mainLayout);

     connect(&this->taskifyButton,SIGNAL(pressed()),this,SLOT(taskify2()));
}

void QuickTask::taskify(){
    QString text=this->editor.toPlainText();
    QRegExp rx("((\n|^)?\s*[\*-].+(\n[-\*]?|$))");
    rx.setMinimal(true);

    QStringList list;
    int pos = 0;

    while ((pos = rx.indexIn(text, pos)) != -1) {
       QString string =rx.cap(1);
        list << string;
        qDebug()<< string;
        //if we have 2 task, seperate them!

        if(list.length()>1){

            QTextEdit *edit=new QTextEdit(this);
            edit->setText(list.takeFirst());
            //this->editor.setText(text.mid(pos));
            //this->layout.removeWidget(&this->editor);
            //this->layout.addWidget(edit);
            //this->layout.addWidget(&this->editor);
            this->editor.moveCursor(QTextCursor::End);

        }


        pos += rx.matchedLength();
        if(text.at(pos-1)=='-' || text.at(pos-1)=='*')pos--;
    }


}

void QuickTask::taskify2(){
    QString text=this->editor.toPlainText();
    QRegExp rx("(.*)(\n|$)");
    int pos = 0;
    rx.setMinimal(true);
    //loop through each line
    QString currentTask;
    QStringList tasks;
    QRegExp newTask("^[ |\t|\s]*[-\*][ |\t|\s]*(.+)$");
    newTask.setMinimal(true);
    while ((pos = rx.indexIn(text, pos)) != -1) {
       if(rx.matchedLength()==0)pos++;
       QString line =rx.cap(1);
       pos += rx.matchedLength();
       qDebug()<<"line:" <<line;
       if(newTask.exactMatch(line)||line==""){
            if(currentTask!=""){

                currentTask.replace(QRegExp("^[ |\t|\s]+"),"");
                tasks << currentTask;
            }
            currentTask="";
            currentTask.append(newTask.cap(1));

       }else {
           if(currentTask!="")currentTask.append("\n");
            currentTask.append(line);
       }



   }
    //hanlde final task.
   if(currentTask!="")currentTask.append("\n");
    currentTask.append(rx.cap(1));
    if(currentTask!=""){
        currentTask.replace(QRegExp("^[ |\t|\s]+"),"");
        tasks<<currentTask;
    }
     //this->layout.removeWidget(&this->editor);
    for(int x=0;x<tasks.length();x++){
        qDebug()<<"Task: "<<tasks.at(x);
        QuickTaskTask *task=new QuickTaskTask(this);
            task->setDescription(tasks.at(x));


            this->taskLayout.addWidget(task);

    }
    //this->layout.addWidget(&this->editor);
    this->editor.moveCursor(QTextCursor::End);
}

