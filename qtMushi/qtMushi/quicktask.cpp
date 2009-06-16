#include "quicktask.h"

QuickTask::QuickTask(QWidget *parent):QWidget(parent)
{

    this->layout.addWidget(&this->editor);
     this->setLayout(&this->layout);
     connect(&this->editor,SIGNAL(textChanged()),this,SLOT(textChanged()));
}

void QuickTask::textChanged(){
    QString text=this->editor.toPlainText();
    QRegExp rx("((\n|^)?\s*[\*-].+(\n[-\*]|$))");
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
            this->editor.setText(text.mid(pos));
            this->layout.removeWidget(&this->editor);
            this->layout.addWidget(edit);
            this->layout.addWidget(&this->editor);
            this->editor.moveCursor(QTextCursor::End);

        }


        pos += rx.matchedLength();
        if(text.at(pos-1)=='-' || text.at(pos-1)=='*')pos--;
    }


}



