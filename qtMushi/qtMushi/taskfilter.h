#ifndef TASKFILTER_H
#define TASKFILTER_H

#include <QObject>
#include "taskFinder.h"

class TaskFilter : public QObject
{
public:
    virtual bool filter(taskFinder *finder,Json::Value value )=0;
    TaskFilter();
};

#endif // TASKFILTER_H
