/****************************************************************************
** Meta object code from reading C++ file 'paint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../paint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Paint_t {
    QByteArrayData data[12];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Paint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Paint_t qt_meta_stringdata_Paint = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Paint"
QT_MOC_LITERAL(1, 6, 11), // "signalColor"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "signalBrush"
QT_MOC_LITERAL(4, 31, 10), // "signalInfo"
QT_MOC_LITERAL(5, 42, 11), // "signalTrans"
QT_MOC_LITERAL(6, 54, 11), // "PaintScene*"
QT_MOC_LITERAL(7, 66, 5), // "scene"
QT_MOC_LITERAL(8, 72, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 94, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(10, 127, 5), // "value"
QT_MOC_LITERAL(11, 133, 11) // "readingData"

    },
    "Paint\0signalColor\0\0signalBrush\0"
    "signalInfo\0signalTrans\0PaintScene*\0"
    "scene\0on_pushButton_clicked\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "readingData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Paint[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       4,    3,   55,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void Paint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Paint *_t = static_cast<Paint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->signalBrush((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 2: _t->signalInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 3: _t->signalTrans((*reinterpret_cast< PaintScene*(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 6: _t->readingData(); break;
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Paint::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Paint::signalColor)) {
                *result = 0;
            }
        }
        {
            typedef void (Paint::*_t)(qint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Paint::signalBrush)) {
                *result = 1;
            }
        }
        {
            typedef void (Paint::*_t)(QString , QColor , qint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Paint::signalInfo)) {
                *result = 2;
            }
        }
        {
            typedef void (Paint::*_t)(PaintScene * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Paint::signalTrans)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Paint::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Paint.data,
      qt_meta_data_Paint,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Paint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Paint::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Paint.stringdata0))
        return static_cast<void*>(const_cast< Paint*>(this));
    return QWidget::qt_metacast(_clname);
}

int Paint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Paint::signalColor(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Paint::signalBrush(qint32 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Paint::signalInfo(QString _t1, QColor _t2, qint32 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Paint::signalTrans(PaintScene * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
