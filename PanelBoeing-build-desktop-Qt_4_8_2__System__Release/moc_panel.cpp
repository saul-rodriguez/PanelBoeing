/****************************************************************************
** Meta object code from reading C++ file 'panel.h'
**
** Created: Tue Apr 29 21:23:18 2014
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
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,   24,   30,   30, 0x0a,
      31,   24,   30,   30, 0x0a,
      49,   70,   30,   30, 0x0a,
      80,   70,   30,   30, 0x0a,
     101,   70,   30,   30, 0x0a,
     122,   70,   30,   30, 0x0a,
     143,   70,   30,   30, 0x0a,
     164,   70,   30,   30, 0x0a,
     185,   70,   30,   30, 0x0a,
     206,   70,   30,   30, 0x0a,
     227,   70,   30,   30, 0x0a,
     248,   70,   30,   30, 0x0a,
     269,   70,   30,   30, 0x0a,
     290,   70,   30,   30, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Panel[] = {
    "Panel\0ext1_intA(quint8)\0value\0\0"
    "ext1_intB(quint8)\0enc1_changed(quint8)\0"
    "direction\0enc2_changed(quint8)\0"
    "enc3_changed(quint8)\0enc4_changed(quint8)\0"
    "but1_changed(quint8)\0but2_changed(quint8)\0"
    "but3_changed(quint8)\0but4_changed(quint8)\0"
    "but5_changed(quint8)\0but6_changed(quint8)\0"
    "but7_changed(quint8)\0but8_changed(quint8)\0"
};

void Panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Panel *_t = static_cast<Panel *>(_o);
        switch (_id) {
        case 0: _t->ext1_intA((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 1: _t->ext1_intB((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 2: _t->enc1_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 3: _t->enc2_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 4: _t->enc3_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 5: _t->enc4_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 6: _t->but1_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 7: _t->but2_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 8: _t->but3_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 9: _t->but4_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 10: _t->but5_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 11: _t->but6_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 12: _t->but7_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 13: _t->but8_changed((*reinterpret_cast< quint8(*)>(_a[1]))); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
