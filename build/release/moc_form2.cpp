/****************************************************************************
** Meta object code from reading C++ file 'form2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../identifition_dice/form2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Form2_t {
    QByteArrayData data[15];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Form2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Form2_t qt_meta_stringdata_Form2 = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Form2"
QT_MOC_LITERAL(1, 6, 15), // "update_filelist"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "filelist"
QT_MOC_LITERAL(4, 32, 17), // "on_updatefilelist"
QT_MOC_LITERAL(5, 50, 8), // "filepath"
QT_MOC_LITERAL(6, 59, 13), // "on_updateshow"
QT_MOC_LITERAL(7, 73, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 85, 4), // "file"
QT_MOC_LITERAL(9, 90, 14), // "on_updateimage"
QT_MOC_LITERAL(10, 105, 10), // "dicenumber"
QT_MOC_LITERAL(11, 116, 5), // "index"
QT_MOC_LITERAL(12, 122, 2), // "p1"
QT_MOC_LITERAL(13, 125, 2), // "p2"
QT_MOC_LITERAL(14, 128, 2) // "p3"

    },
    "Form2\0update_filelist\0\0filelist\0"
    "on_updatefilelist\0filepath\0on_updateshow\0"
    "QModelIndex\0file\0on_updateimage\0"
    "dicenumber\0index\0p1\0p2\0p3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Form2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       9,    5,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QPixmap, QMetaType::QPixmap, QMetaType::QPixmap,   10,   11,   12,   13,   14,

       0        // eod
};

void Form2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Form2 *_t = static_cast<Form2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_filelist((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->on_updatefilelist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_updateshow((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_updateimage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QPixmap(*)>(_a[3])),(*reinterpret_cast< QPixmap(*)>(_a[4])),(*reinterpret_cast< QPixmap(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Form2::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form2::update_filelist)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Form2::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Form2.data,
    qt_meta_data_Form2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Form2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Form2.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Form2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Form2::update_filelist(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
