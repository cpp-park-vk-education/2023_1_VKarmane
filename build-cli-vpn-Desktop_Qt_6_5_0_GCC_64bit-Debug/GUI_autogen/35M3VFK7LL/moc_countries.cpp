/****************************************************************************
** Meta object code from reading C++ file 'countries.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cli-vpn/gui/include/countries.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'countries.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCountriesENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCountriesENDCLASS = QtMocHelpers::stringData(
    "Countries",
    "valueChangedNameTun",
    "",
    "std::string",
    "value",
    "backMainWindow",
    "valueChangedButtonCountryClicked",
    "valueChangedDefaultConfiguration",
    "btnBack",
    "readLEServerIP",
    "deleteServerIP",
    "chooseServerIP"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCountriesENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[10];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[6];
    char stringdata5[15];
    char stringdata6[33];
    char stringdata7[33];
    char stringdata8[8];
    char stringdata9[15];
    char stringdata10[15];
    char stringdata11[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCountriesENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCountriesENDCLASS_t qt_meta_stringdata_CLASSCountriesENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "Countries"
        QT_MOC_LITERAL(10, 19),  // "valueChangedNameTun"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 11),  // "std::string"
        QT_MOC_LITERAL(43, 5),  // "value"
        QT_MOC_LITERAL(49, 14),  // "backMainWindow"
        QT_MOC_LITERAL(64, 32),  // "valueChangedButtonCountryClicked"
        QT_MOC_LITERAL(97, 32),  // "valueChangedDefaultConfiguration"
        QT_MOC_LITERAL(130, 7),  // "btnBack"
        QT_MOC_LITERAL(138, 14),  // "readLEServerIP"
        QT_MOC_LITERAL(153, 14),  // "deleteServerIP"
        QT_MOC_LITERAL(168, 14)   // "chooseServerIP"
    },
    "Countries",
    "valueChangedNameTun",
    "",
    "std::string",
    "value",
    "backMainWindow",
    "valueChangedButtonCountryClicked",
    "valueChangedDefaultConfiguration",
    "btnBack",
    "readLEServerIP",
    "deleteServerIP",
    "chooseServerIP"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCountriesENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       5,    0,   65,    2, 0x06,    3 /* Public */,
       6,    1,   66,    2, 0x06,    4 /* Public */,
       7,    1,   69,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   72,    2, 0x08,    8 /* Private */,
       9,    0,   73,    2, 0x08,    9 /* Private */,
      10,    0,   74,    2, 0x08,   10 /* Private */,
      11,    0,   75,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Countries::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSCountriesENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCountriesENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCountriesENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Countries, std::true_type>,
        // method 'valueChangedNameTun'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        // method 'backMainWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'valueChangedButtonCountryClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'valueChangedDefaultConfiguration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        // method 'btnBack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readLEServerIP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteServerIP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chooseServerIP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Countries::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Countries *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChangedNameTun((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 1: _t->backMainWindow(); break;
        case 2: _t->valueChangedButtonCountryClicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->valueChangedDefaultConfiguration((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 4: _t->btnBack(); break;
        case 5: _t->readLEServerIP(); break;
        case 6: _t->deleteServerIP(); break;
        case 7: _t->chooseServerIP(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Countries::*)(const std::string & );
            if (_t _q_method = &Countries::valueChangedNameTun; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Countries::*)();
            if (_t _q_method = &Countries::backMainWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Countries::*)(bool );
            if (_t _q_method = &Countries::valueChangedButtonCountryClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Countries::*)(const std::string & );
            if (_t _q_method = &Countries::valueChangedDefaultConfiguration; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *Countries::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Countries::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCountriesENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ICountriesWindow"))
        return static_cast< ICountriesWindow*>(this);
    return QDialog::qt_metacast(_clname);
}

int Countries::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Countries::valueChangedNameTun(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Countries::backMainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Countries::valueChangedButtonCountryClicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Countries::valueChangedDefaultConfiguration(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
