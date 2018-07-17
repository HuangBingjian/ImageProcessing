/****************************************************************************
** Meta object code from reading C++ file 'CreateMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../header/CreateMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Menu_t {
    QByteArrayData data[18];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Menu_t qt_meta_stringdata_Menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Menu"
QT_MOC_LITERAL(1, 5, 8), // "File_new"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 9), // "File_open"
QT_MOC_LITERAL(4, 25, 9), // "File_save"
QT_MOC_LITERAL(5, 35, 11), // "File_saveas"
QT_MOC_LITERAL(6, 47, 11), // "View_output"
QT_MOC_LITERAL(7, 59, 9), // "View_tool"
QT_MOC_LITERAL(8, 69, 9), // "View_geom"
QT_MOC_LITERAL(9, 79, 9), // "View_gray"
QT_MOC_LITERAL(10, 89, 12), // "View_enhance"
QT_MOC_LITERAL(11, 102, 9), // "View_morp"
QT_MOC_LITERAL(12, 112, 10), // "View_color"
QT_MOC_LITERAL(13, 123, 10), // "View_image"
QT_MOC_LITERAL(14, 134, 9), // "View_prop"
QT_MOC_LITERAL(15, 144, 12), // "View_fileBar"
QT_MOC_LITERAL(16, 157, 13), // "View_colorBar"
QT_MOC_LITERAL(17, 171, 9) // "Help_info"

    },
    "Menu\0File_new\0\0File_open\0File_save\0"
    "File_saveas\0View_output\0View_tool\0"
    "View_geom\0View_gray\0View_enhance\0"
    "View_morp\0View_color\0View_image\0"
    "View_prop\0View_fileBar\0View_colorBar\0"
    "Help_info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Menu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Menu *_t = static_cast<Menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->File_new(); break;
        case 1: _t->File_open(); break;
        case 2: _t->File_save(); break;
        case 3: _t->File_saveas(); break;
        case 4: _t->View_output(); break;
        case 5: _t->View_tool(); break;
        case 6: _t->View_geom(); break;
        case 7: _t->View_gray(); break;
        case 8: _t->View_enhance(); break;
        case 9: _t->View_morp(); break;
        case 10: _t->View_color(); break;
        case 11: _t->View_image(); break;
        case 12: _t->View_prop(); break;
        case 13: _t->View_fileBar(); break;
        case 14: _t->View_colorBar(); break;
        case 15: _t->Help_info(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Menu::staticMetaObject = {
    { &QMenuBar::staticMetaObject, qt_meta_stringdata_Menu.data,
      qt_meta_data_Menu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Menu.stringdata0))
        return static_cast<void*>(this);
    return QMenuBar::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
