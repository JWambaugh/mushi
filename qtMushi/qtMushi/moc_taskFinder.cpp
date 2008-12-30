/****************************************************************************
** Meta object code from reading C++ file 'taskFinder.h'
**
** Created: Fri Dec 5 20:51:21 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "taskFinder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'taskFinder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_taskFinder[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_taskFinder[] = {
    "taskFinder\0\0networkResponse(QNetworkReply*)\0"
};

const QMetaObject taskFinder::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_taskFinder,
      qt_meta_data_taskFinder, 0 }
};

const QMetaObject *taskFinder::metaObject() const
{
    return &staticMetaObject;
}

void *taskFinder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_taskFinder))
        return static_cast<void*>(const_cast< taskFinder*>(this));
    return QWidget::qt_metacast(_clname);
}

int taskFinder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: networkResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
