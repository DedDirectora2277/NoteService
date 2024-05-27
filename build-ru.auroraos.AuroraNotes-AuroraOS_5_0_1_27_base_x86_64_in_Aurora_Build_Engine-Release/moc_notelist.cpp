/****************************************************************************
** Meta object code from reading C++ file 'notelist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AuroraNotes/src/notelist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notelist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NoteList_t {
    QByteArrayData data[20];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NoteList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NoteList_t qt_meta_stringdata_NoteList = {
    {
QT_MOC_LITERAL(0, 0, 8), // "NoteList"
QT_MOC_LITERAL(1, 9, 11), // "noteRemoved"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "index"
QT_MOC_LITERAL(4, 28, 17), // "filterTextChanged"
QT_MOC_LITERAL(5, 46, 18), // "filterColorChanged"
QT_MOC_LITERAL(6, 65, 7), // "addNote"
QT_MOC_LITERAL(7, 73, 5), // "Note*"
QT_MOC_LITERAL(8, 79, 5), // "title"
QT_MOC_LITERAL(9, 85, 4), // "text"
QT_MOC_LITERAL(10, 90, 5), // "color"
QT_MOC_LITERAL(11, 96, 10), // "removeNote"
QT_MOC_LITERAL(12, 107, 10), // "updateNote"
QT_MOC_LITERAL(13, 118, 4), // "note"
QT_MOC_LITERAL(14, 123, 16), // "clearFilterColor"
QT_MOC_LITERAL(15, 140, 15), // "exportNoteToTxt"
QT_MOC_LITERAL(16, 156, 8), // "filePath"
QT_MOC_LITERAL(17, 165, 17), // "importNoteFromTxt"
QT_MOC_LITERAL(18, 183, 10), // "filterText"
QT_MOC_LITERAL(19, 194, 11) // "filterColor"

    },
    "NoteList\0noteRemoved\0\0index\0"
    "filterTextChanged\0filterColorChanged\0"
    "addNote\0Note*\0title\0text\0color\0"
    "removeNote\0updateNote\0note\0clearFilterColor\0"
    "exportNoteToTxt\0filePath\0importNoteFromTxt\0"
    "filterText\0filterColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NoteList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    0,   62,    2, 0x06 /* Public */,
       5,    0,   63,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    3,   64,    2, 0x02 /* Public */,
      11,    1,   71,    2, 0x02 /* Public */,
      12,    1,   74,    2, 0x02 /* Public */,
      14,    0,   77,    2, 0x02 /* Public */,
      15,    2,   78,    2, 0x02 /* Public */,
      17,    1,   83,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    0x80000000 | 7, QMetaType::QString, QMetaType::QString, QMetaType::QColor,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 7,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString,   13,   16,
    QMetaType::Void, QMetaType::QString,   16,

 // properties: name, type, flags
      18, QMetaType::QString, 0x00495103,
      19, QMetaType::QColor, 0x00495103,

 // properties: notify_signal_id
       1,
       2,

       0        // eod
};

void NoteList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NoteList *_t = static_cast<NoteList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->noteRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->filterTextChanged(); break;
        case 2: _t->filterColorChanged(); break;
        case 3: { Note* _r = _t->addNote((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< Note**>(_a[0]) = _r; }  break;
        case 4: _t->removeNote((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateNote((*reinterpret_cast< Note*(*)>(_a[1]))); break;
        case 6: _t->clearFilterColor(); break;
        case 7: _t->exportNoteToTxt((*reinterpret_cast< Note*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->importNoteFromTxt((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Note* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Note* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NoteList::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NoteList::noteRemoved)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NoteList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NoteList::filterTextChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NoteList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NoteList::filterColorChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        NoteList *_t = static_cast<NoteList *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->filterText(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->filterColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        NoteList *_t = static_cast<NoteList *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFilterText(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setFilterColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject NoteList::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_NoteList.data,
      qt_meta_data_NoteList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NoteList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoteList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NoteList.stringdata0))
        return static_cast<void*>(const_cast< NoteList*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int NoteList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void NoteList::noteRemoved(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NoteList::filterTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void NoteList::filterColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
