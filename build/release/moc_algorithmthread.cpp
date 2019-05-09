/****************************************************************************
** Meta object code from reading C++ file 'algorithmthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../identifition_dice/algorithmthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'algorithmthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAlgorithmThread_t {
    QByteArrayData data[9];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAlgorithmThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAlgorithmThread_t qt_meta_stringdata_CAlgorithmThread = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CAlgorithmThread"
QT_MOC_LITERAL(1, 17, 16), // "finish_algorithm"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10), // "dicenumber"
QT_MOC_LITERAL(4, 46, 5), // "index"
QT_MOC_LITERAL(5, 52, 5), // "psrc1"
QT_MOC_LITERAL(6, 58, 5), // "psrc2"
QT_MOC_LITERAL(7, 64, 5), // "psrc3"
QT_MOC_LITERAL(8, 70, 10) // "finish_all"

    },
    "CAlgorithmThread\0finish_algorithm\0\0"
    "dicenumber\0index\0psrc1\0psrc2\0psrc3\0"
    "finish_all"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAlgorithmThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   24,    2, 0x06 /* Public */,
       8,    0,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QPixmap, QMetaType::QPixmap, QMetaType::QPixmap,    3,    4,    5,    6,    7,
    QMetaType::Void,

       0        // eod
};

void CAlgorithmThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAlgorithmThread *_t = static_cast<CAlgorithmThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finish_algorithm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QPixmap(*)>(_a[3])),(*reinterpret_cast< QPixmap(*)>(_a[4])),(*reinterpret_cast< QPixmap(*)>(_a[5]))); break;
        case 1: _t->finish_all(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CAlgorithmThread::*)(int , int , QPixmap , QPixmap , QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAlgorithmThread::finish_algorithm)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CAlgorithmThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CAlgorithmThread::finish_all)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CAlgorithmThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_CAlgorithmThread.data,
    qt_meta_data_CAlgorithmThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CAlgorithmThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAlgorithmThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAlgorithmThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int CAlgorithmThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CAlgorithmThread::finish_algorithm(int _t1, int _t2, QPixmap _t3, QPixmap _t4, QPixmap _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CAlgorithmThread::finish_all()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
