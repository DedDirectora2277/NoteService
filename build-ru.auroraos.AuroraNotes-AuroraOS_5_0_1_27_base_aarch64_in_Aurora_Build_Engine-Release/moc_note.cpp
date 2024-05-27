/****************************************************************************
** Meta object code from reading C++ file 'note.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AuroraNotes/src/note.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'note.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Note_t {
    QByteArrayData data[13];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Note_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Note_t qt_meta_stringdata_Note = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Note"
QT_MOC_LITERAL(1, 5, 12), // "titleChanged"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "textChanged"
QT_MOC_LITERAL(4, 31, 12), // "colorChanged"
QT_MOC_LITERAL(5, 44, 23), // "modificationDateChanged"
QT_MOC_LITERAL(6, 68, 19), // "creationDateChanged"
QT_MOC_LITERAL(7, 88, 5), // "title"
QT_MOC_LITERAL(8, 94, 4), // "text"
QT_MOC_LITERAL(9, 99, 5), // "color"
QT_MOC_LITERAL(10, 105, 16), // "modificationDate"
QT_MOC_LITERAL(11, 122, 12), // "creationDate"
QT_MOC_LITERAL(12, 135, 2) // "id"

    },
    "Note\0titleChanged\0\0textChanged\0"
    "colorChanged\0modificationDateChanged\0"
    "creationDateChanged\0title\0text\0color\0"
    "modificationDate\0creationDate\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Note[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       6,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::QColor, 0x00495103,
      10, QMetaType::QDate, 0x00495103,
      11, QMetaType::QDate, 0x00495103,
      12, QMetaType::QString, 0x00095103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       0,

       0        // eod
};

void Note::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Note *_t = static_cast<Note *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->titleChanged(); break;
        case 1: _t->textChanged(); break;
        case 2: _t->colorChanged(); break;
        case 3: _t->modificationDateChanged(); break;
        case 4: _t->creationDateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Note::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Note::titleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Note::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Note::textChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Note::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Note::colorChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Note::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Note::modificationDateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Note::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Note::creationDateChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Note *_t = static_cast<Note *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->title(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->text(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->color(); break;
        case 3: *reinterpret_cast< QDate*>(_v) = _t->modificationDate(); break;
        case 4: *reinterpret_cast< QDate*>(_v) = _t->creationDate(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->id(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Note *_t = static_cast<Note *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setModificationDate(*reinterpret_cast< QDate*>(_v)); break;
        case 4: _t->setCreationDate(*reinterpret_cast< QDate*>(_v)); break;
        case 5: _t->setId(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject Note::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Note.data,
      qt_meta_data_Note,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Note::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Note::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Note.stringdata0))
        return static_cast<void*>(const_cast< Note*>(this));
    return QObject::qt_metacast(_clname);
}

int Note::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Note::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Note::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Note::colorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Note::modificationDateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Note::creationDateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
