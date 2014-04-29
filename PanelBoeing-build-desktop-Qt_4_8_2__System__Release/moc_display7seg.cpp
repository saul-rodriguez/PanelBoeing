/****************************************************************************
** Meta object code from reading C++ file 'display7seg.h'
**
** Created: Sun Apr 27 12:01:47 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Qtraspberrylib/display7seg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display7seg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Display7seg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Display7seg[] = {
    "Display7seg\0"
};

void Display7seg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Display7seg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Display7seg::staticMetaObject = {
    { &Ht16k33::staticMetaObject, qt_meta_stringdata_Display7seg,
      qt_meta_data_Display7seg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Display7seg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Display7seg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Display7seg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Display7seg))
        return static_cast<void*>(const_cast< Display7seg*>(this));
    return Ht16k33::qt_metacast(_clname);
}

int Display7seg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Ht16k33::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
