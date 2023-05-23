/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cli-vpn/gui/include/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "lightMode",
    "",
    "darkMode",
    "connectionPoland",
    "connectionNetherlands",
    "showStatics",
    "showAuthorization",
    "showConfiguration",
    "turnOnVPN",
    "showCountries",
    "setValueButtonCountryClicked",
    "value",
    "setValueDefaultConfiguration",
    "std::string",
    "setValueConfigAdded",
    "setValueNameTun",
    "clearConfig",
    "filePath"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[38];
    char stringdata0[11];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[17];
    char stringdata5[22];
    char stringdata6[12];
    char stringdata7[18];
    char stringdata8[18];
    char stringdata9[10];
    char stringdata10[14];
    char stringdata11[29];
    char stringdata12[6];
    char stringdata13[29];
    char stringdata14[12];
    char stringdata15[20];
    char stringdata16[16];
    char stringdata17[12];
    char stringdata18[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 9),  // "lightMode"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 8),  // "darkMode"
        QT_MOC_LITERAL(31, 16),  // "connectionPoland"
        QT_MOC_LITERAL(48, 21),  // "connectionNetherlands"
        QT_MOC_LITERAL(70, 11),  // "showStatics"
        QT_MOC_LITERAL(82, 17),  // "showAuthorization"
        QT_MOC_LITERAL(100, 17),  // "showConfiguration"
        QT_MOC_LITERAL(118, 9),  // "turnOnVPN"
        QT_MOC_LITERAL(128, 13),  // "showCountries"
        QT_MOC_LITERAL(142, 28),  // "setValueButtonCountryClicked"
        QT_MOC_LITERAL(171, 5),  // "value"
        QT_MOC_LITERAL(177, 28),  // "setValueDefaultConfiguration"
        QT_MOC_LITERAL(206, 11),  // "std::string"
        QT_MOC_LITERAL(218, 19),  // "setValueConfigAdded"
        QT_MOC_LITERAL(238, 15),  // "setValueNameTun"
        QT_MOC_LITERAL(254, 11),  // "clearConfig"
        QT_MOC_LITERAL(266, 8)   // "filePath"
    },
    "MainWindow",
    "lightMode",
    "",
    "darkMode",
    "connectionPoland",
    "connectionNetherlands",
    "showStatics",
    "showAuthorization",
    "showConfiguration",
    "turnOnVPN",
    "showCountries",
    "setValueButtonCountryClicked",
    "value",
    "setValueDefaultConfiguration",
    "std::string",
    "setValueConfigAdded",
    "setValueNameTun",
    "clearConfig",
    "filePath"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    0,  105,    2, 0x08,    8 /* Private */,
      10,    0,  106,    2, 0x08,    9 /* Private */,
      11,    1,  107,    2, 0x08,   10 /* Private */,
      13,    1,  110,    2, 0x08,   12 /* Private */,
      15,    1,  113,    2, 0x08,   14 /* Private */,
      16,    1,  116,    2, 0x08,   16 /* Private */,
      17,    1,  119,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, 0x80000000 | 14,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, 0x80000000 | 14,   12,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'lightMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'darkMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectionPoland'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectionNetherlands'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showStatics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAuthorization'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showConfiguration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'turnOnVPN'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showCountries'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setValueButtonCountryClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setValueDefaultConfiguration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        // method 'setValueConfigAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setValueNameTun'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        // method 'clearConfig'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->lightMode(); break;
        case 1: _t->darkMode(); break;
        case 2: _t->connectionPoland(); break;
        case 3: _t->connectionNetherlands(); break;
        case 4: _t->showStatics(); break;
        case 5: _t->showAuthorization(); break;
        case 6: _t->showConfiguration(); break;
        case 7: _t->turnOnVPN(); break;
        case 8: _t->showCountries(); break;
        case 9: _t->setValueButtonCountryClicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->setValueDefaultConfiguration((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 11: _t->setValueConfigAdded((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->setValueNameTun((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 13: _t->clearConfig((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
