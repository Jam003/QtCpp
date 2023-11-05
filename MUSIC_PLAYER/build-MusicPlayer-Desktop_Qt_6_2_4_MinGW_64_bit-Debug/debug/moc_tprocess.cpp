/****************************************************************************
** Meta object code from reading C++ file 'tprocess.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MusicPlayer/tprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TProcess_t {
    const uint offsetsAndSize[26];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TProcess_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TProcess_t qt_meta_stringdata_TProcess = {
    {
QT_MOC_LITERAL(0, 8), // "TProcess"
QT_MOC_LITERAL(9, 17), // "do_currentChanged"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 5), // "Title"
QT_MOC_LITERAL(34, 4), // "Path"
QT_MOC_LITERAL(39, 6), // "Lyrics"
QT_MOC_LITERAL(46, 3), // "Pic"
QT_MOC_LITERAL(50, 9), // "set_pause"
QT_MOC_LITERAL(60, 1), // "p"
QT_MOC_LITERAL(62, 10), // "set_volumn"
QT_MOC_LITERAL(73, 1), // "v"
QT_MOC_LITERAL(75, 11), // "set_process"
QT_MOC_LITERAL(87, 2) // "pr"

    },
    "TProcess\0do_currentChanged\0\0Title\0"
    "Path\0Lyrics\0Pic\0set_pause\0p\0set_volumn\0"
    "v\0set_process\0pr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TProcess[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   38,    2, 0x0a,    1 /* Public */,
       7,    1,   47,    2, 0x0a,    6 /* Public */,
       9,    1,   50,    2, 0x0a,    8 /* Public */,
      11,    1,   53,    2, 0x0a,   10 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void TProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TProcess *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->do_currentChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 1: _t->set_pause((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->set_volumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->set_process((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TProcess::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_TProcess.offsetsAndSize,
    qt_meta_data_TProcess,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TProcess_t
, QtPrivate::TypeAndForceComplete<TProcess, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *TProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TProcess.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int TProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
