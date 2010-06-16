#ifndef TASKFILTER_HIDECLOSED_H
#define TASKFILTER_HIDECLOSED_H
#include "taskfilter.h"
class TaskFilter_HideClosed : private TaskFilter
{
    Q_OBJECT
public:
    bool filter(taskFinder *finder,Json::Value value );
    TaskFilter_HideClosed();
};

#endif // TASKFILTER_HIDECLOSED_H
