/****************************************************************************
** Meta object code from reading C++ file 'showpr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Easy_LPR/showpr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showpr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_showpr_t {
    QByteArrayData data[15];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_showpr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_showpr_t qt_meta_stringdata_showpr = {
    {
QT_MOC_LITERAL(0, 0, 6), // "showpr"
QT_MOC_LITERAL(1, 7, 14), // "ReleaseClicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "PressClicked"
QT_MOC_LITERAL(4, 36, 16), // "ReleaseClicked_8"
QT_MOC_LITERAL(5, 53, 14), // "PressClicked_8"
QT_MOC_LITERAL(6, 68, 16), // "ReleaseClicked_6"
QT_MOC_LITERAL(7, 85, 14), // "PressClicked_6"
QT_MOC_LITERAL(8, 100, 16), // "ReleaseClicked_7"
QT_MOC_LITERAL(9, 117, 14), // "PressClicked_7"
QT_MOC_LITERAL(10, 132, 8), // "Resnigez"
QT_MOC_LITERAL(11, 141, 8), // "targ_dir"
QT_MOC_LITERAL(12, 150, 10), // "ListRowNum"
QT_MOC_LITERAL(13, 161, 21), // "on_listWidget_clicked"
QT_MOC_LITERAL(14, 183, 5) // "index"

    },
    "showpr\0ReleaseClicked\0\0PressClicked\0"
    "ReleaseClicked_8\0PressClicked_8\0"
    "ReleaseClicked_6\0PressClicked_6\0"
    "ReleaseClicked_7\0PressClicked_7\0"
    "Resnigez\0targ_dir\0ListRowNum\0"
    "on_listWidget_clicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_showpr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    1,   77,    2, 0x0a /* Public */,
      12,    1,   80,    2, 0x0a /* Public */,
      13,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QModelIndex,   14,

       0        // eod
};

void showpr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        showpr *_t = static_cast<showpr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReleaseClicked(); break;
        case 1: _t->PressClicked(); break;
        case 2: _t->ReleaseClicked_8(); break;
        case 3: _t->PressClicked_8(); break;
        case 4: _t->ReleaseClicked_6(); break;
        case 5: _t->PressClicked_6(); break;
        case 6: _t->ReleaseClicked_7(); break;
        case 7: _t->PressClicked_7(); break;
        case 8: _t->Resnigez((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->ListRowNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_listWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject showpr::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_showpr.data,
      qt_meta_data_showpr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *showpr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showpr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_showpr.stringdata0))
        return static_cast<void*>(const_cast< showpr*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int showpr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
