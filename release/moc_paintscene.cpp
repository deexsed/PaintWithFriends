/****************************************************************************
** Meta object code from reading C++ file 'paintscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../paintscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PaintScene_t {
    QByteArrayData data[12];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PaintScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PaintScene_t qt_meta_stringdata_PaintScene = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PaintScene"
QT_MOC_LITERAL(1, 11, 9), // "slotColor"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 1), // "a"
QT_MOC_LITERAL(4, 24, 9), // "slotBrush"
QT_MOC_LITERAL(5, 34, 14), // "drawFromOnline"
QT_MOC_LITERAL(6, 49, 13), // "setCoordinate"
QT_MOC_LITERAL(7, 63, 10), // "brushColor"
QT_MOC_LITERAL(8, 74, 9), // "brushSize"
QT_MOC_LITERAL(9, 84, 10), // "sceneTrans"
QT_MOC_LITERAL(10, 95, 11), // "PaintScene*"
QT_MOC_LITERAL(11, 107, 5) // "scene"

    },
    "PaintScene\0slotColor\0\0a\0slotBrush\0"
    "drawFromOnline\0setCoordinate\0brushColor\0"
    "brushSize\0sceneTrans\0PaintScene*\0scene"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PaintScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    3,   40,    2, 0x0a /* Public */,
       9,    1,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void PaintScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PaintScene *_t = static_cast<PaintScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->slotBrush((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 2: _t->drawFromOnline((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 3: _t->sceneTrans((*reinterpret_cast< PaintScene*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PaintScene* >(); break;
            }
            break;
        }
    }
}

const QMetaObject PaintScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_PaintScene.data,
      qt_meta_data_PaintScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PaintScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PaintScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PaintScene.stringdata0))
        return static_cast<void*>(const_cast< PaintScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int PaintScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
