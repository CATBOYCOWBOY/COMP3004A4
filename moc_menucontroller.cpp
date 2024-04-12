/****************************************************************************
** Meta object code from reading C++ file 'menucontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "menucontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menucontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuController_t {
    QByteArrayData data[7];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuController_t qt_meta_stringdata_MenuController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MenuController"
QT_MOC_LITERAL(1, 15, 17), // "onUpButtonPressed"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "onDownButtonPressed"
QT_MOC_LITERAL(4, 54, 19), // "onPlayButtonPressed"
QT_MOC_LITERAL(5, 74, 20), // "onPauseButtonPressed"
QT_MOC_LITERAL(6, 95, 19) // "onStopButtonPressed"

    },
    "MenuController\0onUpButtonPressed\0\0"
    "onDownButtonPressed\0onPlayButtonPressed\0"
    "onPauseButtonPressed\0onStopButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       3,    1,   42,    2, 0x0a /* Public */,
       4,    1,   45,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       6,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void MenuController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onUpButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onDownButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onPlayButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onPauseButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onStopButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MenuController::staticMetaObject = { {
    QMetaObject::SuperData::link<NeuresetController::staticMetaObject>(),
    qt_meta_stringdata_MenuController.data,
    qt_meta_data_MenuController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MenuController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuController.stringdata0))
        return static_cast<void*>(this);
    return NeuresetController::qt_metacast(_clname);
}

int MenuController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NeuresetController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
