/****************************************************************************
** Meta object code from reading C++ file 'timecontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "timecontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timecontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimeController_t {
    QByteArrayData data[10];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeController_t qt_meta_stringdata_TimeController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TimeController"
QT_MOC_LITERAL(1, 15, 16), // "deviceTimeUpdate"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "shutOff"
QT_MOC_LITERAL(4, 41, 18), // "onDeviceTimeUpdate"
QT_MOC_LITERAL(5, 60, 17), // "onUpButtonPressed"
QT_MOC_LITERAL(6, 78, 19), // "onDownButtonPressed"
QT_MOC_LITERAL(7, 98, 19), // "onPlayButtonPressed"
QT_MOC_LITERAL(8, 118, 20), // "onPauseButtonPressed"
QT_MOC_LITERAL(9, 139, 19) // "onStopButtonPressed"

    },
    "TimeController\0deviceTimeUpdate\0\0"
    "shutOff\0onDeviceTimeUpdate\0onUpButtonPressed\0"
    "onDownButtonPressed\0onPlayButtonPressed\0"
    "onPauseButtonPressed\0onStopButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x0a /* Public */,
       5,    1,   57,    2, 0x0a /* Public */,
       6,    1,   60,    2, 0x0a /* Public */,
       7,    1,   63,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void TimeController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TimeController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->deviceTimeUpdate(); break;
        case 1: _t->shutOff(); break;
        case 2: _t->onDeviceTimeUpdate(); break;
        case 3: _t->onUpButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onDownButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onPlayButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onPauseButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onStopButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TimeController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TimeController::deviceTimeUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TimeController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TimeController::shutOff)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TimeController::staticMetaObject = { {
    QMetaObject::SuperData::link<NeuresetController::staticMetaObject>(),
    qt_meta_stringdata_TimeController.data,
    qt_meta_data_TimeController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TimeController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TimeController.stringdata0))
        return static_cast<void*>(this);
    return NeuresetController::qt_metacast(_clname);
}

int TimeController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NeuresetController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TimeController::deviceTimeUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TimeController::shutOff()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
