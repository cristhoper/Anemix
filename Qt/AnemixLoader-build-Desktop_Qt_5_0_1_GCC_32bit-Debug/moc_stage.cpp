/****************************************************************************
** Meta object code from reading C++ file 'stage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AnemixLoader/stage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Stage_t {
    QByteArrayData data[9];
    char stringdata[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Stage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Stage_t qt_meta_stringdata_Stage = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 8),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 10),
QT_MOC_LITERAL(4, 27, 9),
QT_MOC_LITERAL(5, 37, 6),
QT_MOC_LITERAL(6, 44, 3),
QT_MOC_LITERAL(7, 48, 8),
QT_MOC_LITERAL(8, 57, 7)
    },
    "Stage\0redValue\0\0greenValue\0blueValue\0"
    "setRed\0val\0setGreen\0setBlue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Stage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x05,
       3,    2,   49,    2, 0x05,
       4,    2,   54,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    1,   59,    2, 0x08,
       7,    1,   62,    2, 0x08,
       8,    1,   65,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void Stage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Stage *_t = static_cast<Stage *>(_o);
        switch (_id) {
        case 0: _t->redValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->greenValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->blueValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->setRed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setGreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setBlue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Stage::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Stage::redValue)) {
                *result = 0;
            }
        }
        {
            typedef void (Stage::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Stage::greenValue)) {
                *result = 1;
            }
        }
        {
            typedef void (Stage::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Stage::blueValue)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Stage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Stage.data,
      qt_meta_data_Stage,  qt_static_metacall, 0, 0}
};


const QMetaObject *Stage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Stage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Stage.stringdata))
        return static_cast<void*>(const_cast< Stage*>(this));
    return QWidget::qt_metacast(_clname);
}

int Stage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Stage::redValue(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Stage::greenValue(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Stage::blueValue(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
