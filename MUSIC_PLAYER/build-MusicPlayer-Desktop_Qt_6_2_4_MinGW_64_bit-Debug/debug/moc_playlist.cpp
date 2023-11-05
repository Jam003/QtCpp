/****************************************************************************
** Meta object code from reading C++ file 'playlist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MusicPlayer/playlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayList_t {
    const uint offsetsAndSize[40];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PlayList_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PlayList_t qt_meta_stringdata_PlayList = {
    {
QT_MOC_LITERAL(0, 8), // "PlayList"
QT_MOC_LITERAL(9, 14), // "currentChanged"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 5), // "Title"
QT_MOC_LITERAL(31, 4), // "Path"
QT_MOC_LITERAL(36, 6), // "Lyrics"
QT_MOC_LITERAL(43, 3), // "Pic"
QT_MOC_LITERAL(47, 25), // "on_listView_doubleClicked"
QT_MOC_LITERAL(73, 11), // "QModelIndex"
QT_MOC_LITERAL(85, 5), // "index"
QT_MOC_LITERAL(91, 19), // "on_actAdd_triggered"
QT_MOC_LITERAL(111, 22), // "on_actDelete_triggered"
QT_MOC_LITERAL(134, 22), // "on_actLyrics_triggered"
QT_MOC_LITERAL(157, 23), // "on_actPicture_triggered"
QT_MOC_LITERAL(181, 19), // "on_actTop_triggered"
QT_MOC_LITERAL(201, 18), // "on_actUp_triggered"
QT_MOC_LITERAL(220, 20), // "on_actDown_triggered"
QT_MOC_LITERAL(241, 22), // "on_actBottom_triggered"
QT_MOC_LITERAL(264, 13), // "do_toLastPath"
QT_MOC_LITERAL(278, 13) // "do_toNextPath"

    },
    "PlayList\0currentChanged\0\0Title\0Path\0"
    "Lyrics\0Pic\0on_listView_doubleClicked\0"
    "QModelIndex\0index\0on_actAdd_triggered\0"
    "on_actDelete_triggered\0on_actLyrics_triggered\0"
    "on_actPicture_triggered\0on_actTop_triggered\0"
    "on_actUp_triggered\0on_actDown_triggered\0"
    "on_actBottom_triggered\0do_toLastPath\0"
    "do_toNextPath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayList[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   86,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   95,    2, 0x08,    6 /* Private */,
      10,    0,   98,    2, 0x08,    8 /* Private */,
      11,    0,   99,    2, 0x08,    9 /* Private */,
      12,    0,  100,    2, 0x08,   10 /* Private */,
      13,    0,  101,    2, 0x08,   11 /* Private */,
      14,    0,  102,    2, 0x08,   12 /* Private */,
      15,    0,  103,    2, 0x08,   13 /* Private */,
      16,    0,  104,    2, 0x08,   14 /* Private */,
      17,    0,  105,    2, 0x08,   15 /* Private */,
      18,    0,  106,    2, 0x0a,   16 /* Public */,
      19,    0,  107,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
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

void PlayList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 1: _t->on_listView_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->on_actAdd_triggered(); break;
        case 3: _t->on_actDelete_triggered(); break;
        case 4: _t->on_actLyrics_triggered(); break;
        case 5: _t->on_actPicture_triggered(); break;
        case 6: _t->on_actTop_triggered(); break;
        case 7: _t->on_actUp_triggered(); break;
        case 8: _t->on_actDown_triggered(); break;
        case 9: _t->on_actBottom_triggered(); break;
        case 10: _t->do_toLastPath(); break;
        case 11: _t->do_toNextPath(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlayList::*)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayList::currentChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PlayList::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PlayList.offsetsAndSize,
    qt_meta_data_PlayList,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PlayList_t
, QtPrivate::TypeAndForceComplete<PlayList, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PlayList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayList.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PlayList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void PlayList::currentChanged(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
