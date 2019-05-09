/****************************************************************************
** Meta object code from reading C++ file 'form1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../identifition_dice/form1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Form1_t {
    QByteArrayData data[13];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Form1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Form1_t qt_meta_stringdata_Form1 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Form1"
QT_MOC_LITERAL(1, 6, 15), // "on_imageshowMax"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 40, 19), // "on_updatelistwidget"
QT_MOC_LITERAL(5, 60, 8), // "filepath"
QT_MOC_LITERAL(6, 69, 1), // "p"
QT_MOC_LITERAL(7, 71, 18), // "on_finishalgorithm"
QT_MOC_LITERAL(8, 90, 10), // "dicenumber"
QT_MOC_LITERAL(9, 101, 5), // "index"
QT_MOC_LITERAL(10, 107, 5), // "psrc1"
QT_MOC_LITERAL(11, 113, 5), // "psrc2"
QT_MOC_LITERAL(12, 119, 5) // "psrc3"

    },
    "Form1\0on_imageshowMax\0\0QListWidgetItem*\0"
    "on_updatelistwidget\0filepath\0p\0"
    "on_finishalgorithm\0dicenumber\0index\0"
    "psrc1\0psrc2\0psrc3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Form1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    2,   32,    2, 0x08 /* Private */,
       7,    5,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QPixmap,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QPixmap, QMetaType::QPixmap, QMetaType::QPixmap,    8,    9,   10,   11,   12,

       0        // eod
};

void Form1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Form1 *_t = static_cast<Form1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_imageshowMax((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->on_updatelistwidget((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QPixmap(*)>(_a[2]))); break;
        case 2: _t->on_finishalgorithm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QPixmap(*)>(_a[3])),(*reinterpret_cast< QPixmap(*)>(_a[4])),(*reinterpret_cast< QPixmap(*)>(_a[5]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Form1::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Form1.data,
    qt_meta_data_Form1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Form1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Form1.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
