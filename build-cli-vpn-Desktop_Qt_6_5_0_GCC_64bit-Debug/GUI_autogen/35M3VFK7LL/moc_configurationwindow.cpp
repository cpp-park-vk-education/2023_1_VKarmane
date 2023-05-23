/****************************************************************************
** Meta object code from reading C++ file 'configurationwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cli-vpn/gui/include/configurationwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configurationwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSConfigurationWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSConfigurationWindowENDCLASS = QtMocHelpers::stringData(
    "ConfigurationWindow",
    "backMainWindow",
    "",
    "valueChangedConfigAdded",
    "value",
    "btnSave",
    "btnBack",
    "saveConfig",
    "configURLS"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSConfigurationWindowENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[20];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[6];
    char stringdata5[8];
    char stringdata6[8];
    char stringdata7[11];
    char stringdata8[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSConfigurationWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSConfigurationWindowENDCLASS_t qt_meta_stringdata_CLASSConfigurationWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "ConfigurationWindow"
        QT_MOC_LITERAL(20, 14),  // "backMainWindow"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 23),  // "valueChangedConfigAdded"
        QT_MOC_LITERAL(60, 5),  // "value"
        QT_MOC_LITERAL(66, 7),  // "btnSave"
        QT_MOC_LITERAL(74, 7),  // "btnBack"
        QT_MOC_LITERAL(82, 10),  // "saveConfig"
        QT_MOC_LITERAL(93, 10)   // "configURLS"
    },
    "ConfigurationWindow",
    "backMainWindow",
    "",
    "valueChangedConfigAdded",
    "value",
    "btnSave",
    "btnBack",
    "saveConfig",
    "configURLS"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSConfigurationWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    1,   45,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   48,    2, 0x08,    4 /* Private */,
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    1,   50,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject ConfigurationWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSConfigurationWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSConfigurationWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSConfigurationWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ConfigurationWindow, std::true_type>,
        // method 'backMainWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'valueChangedConfigAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'btnSave'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'btnBack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveConfig'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void ConfigurationWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConfigurationWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backMainWindow(); break;
        case 1: _t->valueChangedConfigAdded((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->btnSave(); break;
        case 3: _t->btnBack(); break;
        case 4: _t->saveConfig((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConfigurationWindow::*)();
            if (_t _q_method = &ConfigurationWindow::backMainWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConfigurationWindow::*)(bool );
            if (_t _q_method = &ConfigurationWindow::valueChangedConfigAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *ConfigurationWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigurationWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSConfigurationWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IConfigurationWindow"))
        return static_cast< IConfigurationWindow*>(this);
    return QDialog::qt_metacast(_clname);
}

int ConfigurationWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ConfigurationWindow::backMainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ConfigurationWindow::valueChangedConfigAdded(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
