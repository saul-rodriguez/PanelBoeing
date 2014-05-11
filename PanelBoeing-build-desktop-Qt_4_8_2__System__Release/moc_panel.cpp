/****************************************************************************
** Meta object code from reading C++ file 'panel.h'
**
** Created: Sun May 11 21:10:47 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PanelBoeing/panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Panel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,   22,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
      27,   22,   26,   26, 0x0a,
      50,   26,   26,   26, 0x0a,
     102,  120,   26,   26, 0x0a,
     126,  120,   26,   26, 0x0a,
     144,  120,   26,   26, 0x0a,
     162,  120,   26,   26, 0x0a,
     180,  201,   26,   26, 0x0a,
     211,  201,   26,   26, 0x0a,
     232,  201,   26,   26, 0x0a,
     253,  201,   26,   26, 0x0a,
     274,  201,   26,   26, 0x0a,
     295,  201,   26,   26, 0x0a,
     316,  201,   26,   26, 0x0a,
     337,  201,   26,   26, 0x0a,
     358,  201,   26,   26, 0x0a,
     379,  201,   26,   26, 0x0a,
     400,  201,   26,   26, 0x0a,
     421,  201,   26,   26, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Panel[] = {
    "Panel\0telMes(QString)\0msg\0\0"
    "telnetMessage(QString)\0"
    "telnetConnectionError(QAbstractSocket::SocketError)\0"
    "ext1_intA(quint8)\0value\0ext1_intB(quint8)\0"
    "ext2_intA(quint8)\0ext2_intB(quint8)\0"
    "enc1_changed(quint8)\0direction\0"
    "enc2_changed(quint8)\0enc3_changed(quint8)\0"
    "enc4_changed(quint8)\0but1_changed(quint8)\0"
    "but2_changed(quint8)\0but3_changed(quint8)\0"
    "but4_changed(quint8)\0but5_changed(quint8)\0"
    "but6_changed(quint8)\0but7_changed(quint8)\0"
    "but8_changed(quint8)\0"
};

void Panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Panel *_t = static_cast<Panel *>(_o);
        switch (_id) {
        case 0: _t->telMes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->telnetMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->telnetConnectionError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 3: _t->ext1_intA((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 4: _t->ext1_intB((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 5: _t->ext2_intA((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 6: _t->ext2_intB((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 7: _t->enc1_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 8: _t->enc2_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 9: _t->enc3_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 10: _t->enc4_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 11: _t->but1_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 12: _t->but2_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 13: _t->but3_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 14: _t->but4_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 15: _t->but5_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 16: _t->but6_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 17: _t->but7_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 18: _t->but8_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Panel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Panel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Panel,
      qt_meta_data_Panel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Panel))
        return static_cast<void*>(const_cast< Panel*>(this));
    return QObject::qt_metacast(_clname);
}

int Panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Panel::telMes(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
