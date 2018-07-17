/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../header/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageProcessing_t {
    QByteArrayData data[74];
    char stringdata0[845];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageProcessing_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageProcessing_t qt_meta_stringdata_ImageProcessing = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ImageProcessing"
QT_MOC_LITERAL(1, 16, 4), // "undo"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "redo"
QT_MOC_LITERAL(4, 27, 6), // "option"
QT_MOC_LITERAL(5, 34, 11), // "whiteLayout"
QT_MOC_LITERAL(6, 46, 11), // "blackLayout"
QT_MOC_LITERAL(7, 58, 15), // "changeImageSize"
QT_MOC_LITERAL(8, 74, 16), // "defaultImageSize"
QT_MOC_LITERAL(9, 91, 13), // "enlargeReduce"
QT_MOC_LITERAL(10, 105, 15), // "enlargeReduceOK"
QT_MOC_LITERAL(11, 121, 8), // "enlarge2"
QT_MOC_LITERAL(12, 130, 7), // "reduce2"
QT_MOC_LITERAL(13, 138, 11), // "rotateImage"
QT_MOC_LITERAL(14, 150, 13), // "rotateImageOK"
QT_MOC_LITERAL(15, 164, 14), // "rotateImage_90"
QT_MOC_LITERAL(16, 179, 15), // "rotateImage_180"
QT_MOC_LITERAL(17, 195, 15), // "rotateImage_270"
QT_MOC_LITERAL(18, 211, 11), // "flipImage_H"
QT_MOC_LITERAL(19, 223, 11), // "flipImage_V"
QT_MOC_LITERAL(20, 235, 9), // "LeanImage"
QT_MOC_LITERAL(21, 245, 11), // "LeanImageOK"
QT_MOC_LITERAL(22, 257, 8), // "binImage"
QT_MOC_LITERAL(23, 266, 10), // "binImageOK"
QT_MOC_LITERAL(24, 277, 9), // "grayImage"
QT_MOC_LITERAL(25, 287, 12), // "reverseImage"
QT_MOC_LITERAL(26, 300, 11), // "linearImage"
QT_MOC_LITERAL(27, 312, 13), // "linearImageOK"
QT_MOC_LITERAL(28, 326, 8), // "logImage"
QT_MOC_LITERAL(29, 335, 10), // "logImageOK"
QT_MOC_LITERAL(30, 346, 10), // "gammaImage"
QT_MOC_LITERAL(31, 357, 12), // "gammaImageOK"
QT_MOC_LITERAL(32, 370, 11), // "histeqImage"
QT_MOC_LITERAL(33, 382, 15), // "normalizedImage"
QT_MOC_LITERAL(34, 398, 13), // "gaussianImage"
QT_MOC_LITERAL(35, 412, 11), // "medianImage"
QT_MOC_LITERAL(36, 424, 10), // "sobelImage"
QT_MOC_LITERAL(37, 435, 14), // "laplacianImage"
QT_MOC_LITERAL(38, 450, 10), // "cannyImage"
QT_MOC_LITERAL(39, 461, 9), // "lineImage"
QT_MOC_LITERAL(40, 471, 11), // "circleImage"
QT_MOC_LITERAL(41, 483, 10), // "erodeImage"
QT_MOC_LITERAL(42, 494, 11), // "dilateImage"
QT_MOC_LITERAL(43, 506, 9), // "openImage"
QT_MOC_LITERAL(44, 516, 10), // "closeImage"
QT_MOC_LITERAL(45, 527, 9), // "gradImage"
QT_MOC_LITERAL(46, 537, 11), // "tophatImage"
QT_MOC_LITERAL(47, 549, 13), // "blackhatImage"
QT_MOC_LITERAL(48, 563, 6), // "splitR"
QT_MOC_LITERAL(49, 570, 6), // "splitG"
QT_MOC_LITERAL(50, 577, 6), // "splitB"
QT_MOC_LITERAL(51, 584, 10), // "splitH_HSV"
QT_MOC_LITERAL(52, 595, 10), // "splitS_HSV"
QT_MOC_LITERAL(53, 606, 10), // "splitV_HSV"
QT_MOC_LITERAL(54, 617, 10), // "splitY_YUV"
QT_MOC_LITERAL(55, 628, 10), // "splitU_YUV"
QT_MOC_LITERAL(56, 639, 10), // "splitV_YUV"
QT_MOC_LITERAL(57, 650, 10), // "splitH_HLS"
QT_MOC_LITERAL(58, 661, 10), // "splitL_HLS"
QT_MOC_LITERAL(59, 672, 10), // "splitS_HLS"
QT_MOC_LITERAL(60, 683, 17), // "toolButtonClicked"
QT_MOC_LITERAL(61, 701, 2), // "id"
QT_MOC_LITERAL(62, 704, 16), // "preButtonClicked"
QT_MOC_LITERAL(63, 721, 8), // "penWidth"
QT_MOC_LITERAL(64, 730, 8), // "penColor"
QT_MOC_LITERAL(65, 739, 11), // "isDockImage"
QT_MOC_LITERAL(66, 751, 10), // "isDockTool"
QT_MOC_LITERAL(67, 762, 12), // "isDockOutput"
QT_MOC_LITERAL(68, 775, 10), // "isDockProp"
QT_MOC_LITERAL(69, 786, 10), // "isDockGeom"
QT_MOC_LITERAL(70, 797, 10), // "isDockGray"
QT_MOC_LITERAL(71, 808, 13), // "isDockEnhance"
QT_MOC_LITERAL(72, 822, 10), // "isDockMorp"
QT_MOC_LITERAL(73, 833, 11) // "isDockColor"

    },
    "ImageProcessing\0undo\0\0redo\0option\0"
    "whiteLayout\0blackLayout\0changeImageSize\0"
    "defaultImageSize\0enlargeReduce\0"
    "enlargeReduceOK\0enlarge2\0reduce2\0"
    "rotateImage\0rotateImageOK\0rotateImage_90\0"
    "rotateImage_180\0rotateImage_270\0"
    "flipImage_H\0flipImage_V\0LeanImage\0"
    "LeanImageOK\0binImage\0binImageOK\0"
    "grayImage\0reverseImage\0linearImage\0"
    "linearImageOK\0logImage\0logImageOK\0"
    "gammaImage\0gammaImageOK\0histeqImage\0"
    "normalizedImage\0gaussianImage\0medianImage\0"
    "sobelImage\0laplacianImage\0cannyImage\0"
    "lineImage\0circleImage\0erodeImage\0"
    "dilateImage\0openImage\0closeImage\0"
    "gradImage\0tophatImage\0blackhatImage\0"
    "splitR\0splitG\0splitB\0splitH_HSV\0"
    "splitS_HSV\0splitV_HSV\0splitY_YUV\0"
    "splitU_YUV\0splitV_YUV\0splitH_HLS\0"
    "splitL_HLS\0splitS_HLS\0toolButtonClicked\0"
    "id\0preButtonClicked\0penWidth\0penColor\0"
    "isDockImage\0isDockTool\0isDockOutput\0"
    "isDockProp\0isDockGeom\0isDockGray\0"
    "isDockEnhance\0isDockMorp\0isDockColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcessing[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      71,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  369,    2, 0x0a /* Public */,
       3,    0,  370,    2, 0x0a /* Public */,
       4,    0,  371,    2, 0x0a /* Public */,
       5,    0,  372,    2, 0x0a /* Public */,
       6,    0,  373,    2, 0x0a /* Public */,
       7,    0,  374,    2, 0x0a /* Public */,
       8,    0,  375,    2, 0x0a /* Public */,
       9,    0,  376,    2, 0x0a /* Public */,
      10,    0,  377,    2, 0x0a /* Public */,
      11,    0,  378,    2, 0x0a /* Public */,
      12,    0,  379,    2, 0x0a /* Public */,
      13,    0,  380,    2, 0x0a /* Public */,
      14,    0,  381,    2, 0x0a /* Public */,
      15,    0,  382,    2, 0x0a /* Public */,
      16,    0,  383,    2, 0x0a /* Public */,
      17,    0,  384,    2, 0x0a /* Public */,
      18,    0,  385,    2, 0x0a /* Public */,
      19,    0,  386,    2, 0x0a /* Public */,
      20,    0,  387,    2, 0x0a /* Public */,
      21,    0,  388,    2, 0x0a /* Public */,
      22,    0,  389,    2, 0x0a /* Public */,
      23,    0,  390,    2, 0x0a /* Public */,
      24,    0,  391,    2, 0x0a /* Public */,
      25,    0,  392,    2, 0x0a /* Public */,
      26,    0,  393,    2, 0x0a /* Public */,
      27,    0,  394,    2, 0x0a /* Public */,
      28,    0,  395,    2, 0x0a /* Public */,
      29,    0,  396,    2, 0x0a /* Public */,
      30,    0,  397,    2, 0x0a /* Public */,
      31,    0,  398,    2, 0x0a /* Public */,
      32,    0,  399,    2, 0x0a /* Public */,
      33,    0,  400,    2, 0x0a /* Public */,
      34,    0,  401,    2, 0x0a /* Public */,
      35,    0,  402,    2, 0x0a /* Public */,
      36,    0,  403,    2, 0x0a /* Public */,
      37,    0,  404,    2, 0x0a /* Public */,
      38,    0,  405,    2, 0x0a /* Public */,
      39,    0,  406,    2, 0x0a /* Public */,
      40,    0,  407,    2, 0x0a /* Public */,
      41,    0,  408,    2, 0x0a /* Public */,
      42,    0,  409,    2, 0x0a /* Public */,
      43,    0,  410,    2, 0x0a /* Public */,
      44,    0,  411,    2, 0x0a /* Public */,
      45,    0,  412,    2, 0x0a /* Public */,
      46,    0,  413,    2, 0x0a /* Public */,
      47,    0,  414,    2, 0x0a /* Public */,
      48,    0,  415,    2, 0x0a /* Public */,
      49,    0,  416,    2, 0x0a /* Public */,
      50,    0,  417,    2, 0x0a /* Public */,
      51,    0,  418,    2, 0x0a /* Public */,
      52,    0,  419,    2, 0x0a /* Public */,
      53,    0,  420,    2, 0x0a /* Public */,
      54,    0,  421,    2, 0x0a /* Public */,
      55,    0,  422,    2, 0x0a /* Public */,
      56,    0,  423,    2, 0x0a /* Public */,
      57,    0,  424,    2, 0x0a /* Public */,
      58,    0,  425,    2, 0x0a /* Public */,
      59,    0,  426,    2, 0x0a /* Public */,
      60,    1,  427,    2, 0x0a /* Public */,
      62,    1,  430,    2, 0x0a /* Public */,
      63,    0,  433,    2, 0x0a /* Public */,
      64,    0,  434,    2, 0x0a /* Public */,
      65,    0,  435,    2, 0x0a /* Public */,
      66,    0,  436,    2, 0x0a /* Public */,
      67,    0,  437,    2, 0x0a /* Public */,
      68,    0,  438,    2, 0x0a /* Public */,
      69,    0,  439,    2, 0x0a /* Public */,
      70,    0,  440,    2, 0x0a /* Public */,
      71,    0,  441,    2, 0x0a /* Public */,
      72,    0,  442,    2, 0x0a /* Public */,
      73,    0,  443,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,   61,
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

void ImageProcessing::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageProcessing *_t = static_cast<ImageProcessing *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->undo(); break;
        case 1: _t->redo(); break;
        case 2: _t->option(); break;
        case 3: _t->whiteLayout(); break;
        case 4: _t->blackLayout(); break;
        case 5: _t->changeImageSize(); break;
        case 6: _t->defaultImageSize(); break;
        case 7: _t->enlargeReduce(); break;
        case 8: _t->enlargeReduceOK(); break;
        case 9: _t->enlarge2(); break;
        case 10: _t->reduce2(); break;
        case 11: _t->rotateImage(); break;
        case 12: _t->rotateImageOK(); break;
        case 13: _t->rotateImage_90(); break;
        case 14: _t->rotateImage_180(); break;
        case 15: _t->rotateImage_270(); break;
        case 16: _t->flipImage_H(); break;
        case 17: _t->flipImage_V(); break;
        case 18: _t->LeanImage(); break;
        case 19: _t->LeanImageOK(); break;
        case 20: _t->binImage(); break;
        case 21: _t->binImageOK(); break;
        case 22: _t->grayImage(); break;
        case 23: _t->reverseImage(); break;
        case 24: _t->linearImage(); break;
        case 25: _t->linearImageOK(); break;
        case 26: _t->logImage(); break;
        case 27: _t->logImageOK(); break;
        case 28: _t->gammaImage(); break;
        case 29: _t->gammaImageOK(); break;
        case 30: _t->histeqImage(); break;
        case 31: _t->normalizedImage(); break;
        case 32: _t->gaussianImage(); break;
        case 33: _t->medianImage(); break;
        case 34: _t->sobelImage(); break;
        case 35: _t->laplacianImage(); break;
        case 36: _t->cannyImage(); break;
        case 37: _t->lineImage(); break;
        case 38: _t->circleImage(); break;
        case 39: _t->erodeImage(); break;
        case 40: _t->dilateImage(); break;
        case 41: _t->openImage(); break;
        case 42: _t->closeImage(); break;
        case 43: _t->gradImage(); break;
        case 44: _t->tophatImage(); break;
        case 45: _t->blackhatImage(); break;
        case 46: _t->splitR(); break;
        case 47: _t->splitG(); break;
        case 48: _t->splitB(); break;
        case 49: _t->splitH_HSV(); break;
        case 50: _t->splitS_HSV(); break;
        case 51: _t->splitV_HSV(); break;
        case 52: _t->splitY_YUV(); break;
        case 53: _t->splitU_YUV(); break;
        case 54: _t->splitV_YUV(); break;
        case 55: _t->splitH_HLS(); break;
        case 56: _t->splitL_HLS(); break;
        case 57: _t->splitS_HLS(); break;
        case 58: _t->toolButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->preButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->penWidth(); break;
        case 61: _t->penColor(); break;
        case 62: _t->isDockImage(); break;
        case 63: _t->isDockTool(); break;
        case 64: _t->isDockOutput(); break;
        case 65: _t->isDockProp(); break;
        case 66: _t->isDockGeom(); break;
        case 67: _t->isDockGray(); break;
        case 68: _t->isDockEnhance(); break;
        case 69: _t->isDockMorp(); break;
        case 70: _t->isDockColor(); break;
        default: ;
        }
    }
}

const QMetaObject ImageProcessing::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImageProcessing.data,
      qt_meta_data_ImageProcessing,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ImageProcessing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageProcessing::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcessing.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ImageProcessing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 71)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 71;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 71)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 71;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
