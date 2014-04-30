/****************************************************************************
** Meta object code from reading C++ file 'qttelnet.h'
**
** Created: Wed Apr 30 15:12:32 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Qtraspberrylib/qttelnet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qttelnet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtTelnet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,   25,   25,   25, 0x05,
      26,   25,   25,   25, 0x05,
      40,   25,   25,   25, 0x05,
      51,   25,   25,   25, 0x05,
      63,  109,   25,   25, 0x05,
     115,  132,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
     137,   25,   25,   25, 0x0a,
     145,   25,   25,   25, 0x0a,
     154,  175,   25,   25, 0x0a,
     180,  132,   25,   25, 0x0a,
     198,   25,   25,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QtTelnet[] = {
    "QtTelnet\0loginRequired()\0\0loginFailed()\0"
    "loggedIn()\0loggedOut()\0"
    "connectionError(QAbstractSocket::SocketError)\0"
    "error\0message(QString)\0data\0close()\0"
    "logout()\0sendControl(Control)\0ctrl\0"
    "sendData(QString)\0sendSync()\0"
};

void QtTelnet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtTelnet *_t = static_cast<QtTelnet *>(_o);
        switch (_id) {
        case 0: _t->loginRequired(); break;
        case 1: _t->loginFailed(); break;
        case 2: _t->loggedIn(); break;
        case 3: _t->loggedOut(); break;
        case 4: _t->connectionError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->close(); break;
        case 7: _t->logout(); break;
        case 8: _t->sendControl((*reinterpret_cast< Control(*)>(_a[1]))); break;
        case 9: _t->sendData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->sendSync(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QtTelnet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QtTelnet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtTelnet,
      qt_meta_data_QtTelnet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtTelnet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtTelnet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtTelnet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtTelnet))
        return static_cast<void*>(const_cast< QtTelnet*>(this));
    return QObject::qt_metacast(_clname);
}

int QtTelnet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QtTelnet::loginRequired()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QtTelnet::loginFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QtTelnet::loggedIn()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QtTelnet::loggedOut()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QtTelnet::connectionError(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QtTelnet::message(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
