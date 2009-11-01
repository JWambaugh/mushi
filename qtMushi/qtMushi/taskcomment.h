#ifndef TASKCOMMENT_H
#define TASKCOMMENT_H

#include <QWidget>

namespace Ui {
    class TaskComment;
}

class TaskComment : public QWidget {
    Q_OBJECT
public:
    TaskComment(QWidget *parent = 0);
    ~TaskComment();

private:
    Ui::TaskComment *ui;
};

#endif // TASKCOMMENT_H
