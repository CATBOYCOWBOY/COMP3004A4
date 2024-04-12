/****************************************************************************
** Meta object code from reading C++ file 'eegsensor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "eegsensor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eegsensor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EEGSensor_t {
    QByteArrayData data[18];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EEGSensor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EEGSensor_t qt_meta_stringdata_EEGSensor = {
    {
QT_MOC_LITERAL(0, 0, 9), // "EEGSensor"
QT_MOC_LITERAL(1, 10, 7), // "shutOff"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 16), // "treatmentStarted"
QT_MOC_LITERAL(4, 36, 14), // "treatmentEnded"
QT_MOC_LITERAL(5, 51, 16), // "frequencyUpdated"
QT_MOC_LITERAL(6, 68, 13), // "cycleComplete"
QT_MOC_LITERAL(7, 82, 23), // "fiveMinutesDisconnected"
QT_MOC_LITERAL(8, 106, 3), // "run"
QT_MOC_LITERAL(9, 110, 12), // "onBatteryLow"
QT_MOC_LITERAL(10, 123, 12), // "onDisconnect"
QT_MOC_LITERAL(11, 136, 16), // "onTreatmentStart"
QT_MOC_LITERAL(12, 153, 16), // "onTreatmentPause"
QT_MOC_LITERAL(13, 170, 19), // "onTreatmentUnpaused"
QT_MOC_LITERAL(14, 190, 18), // "onTreatmentStopped"
QT_MOC_LITERAL(15, 209, 14), // "onBatteryReset"
QT_MOC_LITERAL(16, 224, 17), // "onConnectionReset"
QT_MOC_LITERAL(17, 242, 9) // "onShutOff"

    },
    "EEGSensor\0shutOff\0\0treatmentStarted\0"
    "treatmentEnded\0frequencyUpdated\0"
    "cycleComplete\0fiveMinutesDisconnected\0"
    "run\0onBatteryLow\0onDisconnect\0"
    "onTreatmentStart\0onTreatmentPause\0"
    "onTreatmentUnpaused\0onTreatmentStopped\0"
    "onBatteryReset\0onConnectionReset\0"
    "onShutOff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EEGSensor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    1,   95,    2, 0x06 /* Public */,
       4,    1,   98,    2, 0x06 /* Public */,
       5,    1,  101,    2, 0x06 /* Public */,
       6,    0,  104,    2, 0x06 /* Public */,
       7,    0,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  106,    2, 0x0a /* Public */,
       9,    0,  107,    2, 0x0a /* Public */,
      10,    0,  108,    2, 0x0a /* Public */,
      11,    0,  109,    2, 0x0a /* Public */,
      12,    0,  110,    2, 0x0a /* Public */,
      13,    0,  111,    2, 0x0a /* Public */,
      14,    0,  112,    2, 0x0a /* Public */,
      15,    0,  113,    2, 0x0a /* Public */,
      16,    0,  114,    2, 0x0a /* Public */,
      17,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EEGSensor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EEGSensor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->shutOff(); break;
        case 1: _t->treatmentStarted((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->treatmentEnded((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->frequencyUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->cycleComplete(); break;
        case 5: _t->fiveMinutesDisconnected(); break;
        case 6: _t->run(); break;
        case 7: _t->onBatteryLow(); break;
        case 8: _t->onDisconnect(); break;
        case 9: _t->onTreatmentStart(); break;
        case 10: _t->onTreatmentPause(); break;
        case 11: _t->onTreatmentUnpaused(); break;
        case 12: _t->onTreatmentStopped(); break;
        case 13: _t->onBatteryReset(); break;
        case 14: _t->onConnectionReset(); break;
        case 15: _t->onShutOff(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EEGSensor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EEGSensor::shutOff)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EEGSensor::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EEGSensor::treatmentStarted)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EEGSensor::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EEGSensor::treatmentEnded)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EEGSensor::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EEGSensor::frequencyUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (EEGSensor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EEGSensor::cycleComplete)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (EEGSensor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EEGSensor::fiveMinutesDisconnected)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EEGSensor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EEGSensor.data,
    qt_meta_data_EEGSensor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EEGSensor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EEGSensor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EEGSensor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EEGSensor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void EEGSensor::shutOff()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EEGSensor::treatmentStarted(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EEGSensor::treatmentEnded(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EEGSensor::frequencyUpdated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EEGSensor::cycleComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void EEGSensor::fiveMinutesDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
