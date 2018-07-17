#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma execution_character_set("utf-8")		// 中文编码
#include <QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include "ui_ImageProcessing.h"

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp>  

#include "header/CreateMenu.h"
#include "header/ImgChange.h"
#include "header/Geom.h"
#include "header/Gray.h"
#include "header/Enhance.h"
#include "header/Morp.h"
#include "header/PaintWidget.h"
#include "header/CustomWindow.h"

class Menu;
class CustomWindow;
class QTextEdit;
class QLabel;
class QScrollArea;

class ImageProcessing : public QMainWindow
{
	Q_OBJECT

public:
	explicit ImageProcessing(QWidget *parent = 0);
	~ImageProcessing();

	std::vector<std::vector<QImage>> imgVector;	// 存储图像的Vector容器
	std::vector<QImage>::iterator iter;			// Vector迭代器
	
	PaintWidget *imgLabel;						// 图像显示框
	PaintWidget *preLabel;						// 预览显示框
	QToolBar *I_ColorBar;						// 绘图工具栏
	QDockWidget *dock_Image,*dock_Tool, *dock_Output, *dock_Prop;		// 各窗口
	QDockWidget *dock_Geom, *dock_Gray,	*dock_Enhance, *dock_Morp, *dock_Color;

	void ShowImage(QImage Img, bool isSave);	// 显示图像
	void PreviewImage(QImage Img);				// 预览图像
	void UpdateImgName(QString name);			// 更新图像地址
	void UpdateProp(QImage src);				// 更新属性
	void output(QString information);			// 输出
		
public slots:
	// edit
	void undo();								// 撤销
	void redo();								// 重做
	void maxScreen();							// 最大化显示
	void fullScreen();							// 全屏显示
	// Geom
	void changeImageSize();						// 改变图像大小
	void defaultImageSize();					// 重置图像大小
	void enlargeReduce();						// 图像缩放
	void enlargeReduceOK();						// 确认
	void enlarge2();							// 长宽放大2倍
	void reduce2();								// 长宽缩小2倍
	void rotateImage();							// 图像旋转
	void rotateImageOK();						// 确认
	void rotateImage_90();						// 图像旋转90
	void rotateImage_180();						// 图像旋转180
	void rotateImage_270();						// 图像旋转270
	void flipImage_H();							// 水平镜像
	void flipImage_V();							// 垂直镜像
	void LeanImage();							// 图像倾斜
	void LeanImageOK();							// 图像倾斜
	// Gray
	void binImage();							// 二值图像
	void binImageOK();							// 确认
	void grayImage();							// 灰度图像
	void reverseImage();						// 图像反转
	void linearImage();							// 线性变换
	void linearImageOK();						// 确认
	void logImage();							// 对数变换
	void logImageOK();							// 确认
	void gammaImage();							// 伽马变换
	void gammaImageOK();						// 确认
	void histeqImage();							// 直方图均衡化
	// Enhance
	void normalizedImage();						// 简单滤波
	void gaussianImage();						// 高斯滤波
	void medianImage();							// 中值滤波
	void sobelImage();							// sobel边缘检测
	void laplacianImage();						// laplacian边缘检测
	void cannyImage();							// canny边缘检测
	void lineImage();							// line边缘检测
	void circleImage();							// circle边缘检测
	// Morp
	void erodeImage();							// 腐蚀
	void dilateImage();							// 膨胀
	void openImage();							// 开运算
	void closeImage();							// 闭运算
	void gradImage();							// 形态学梯度
	void tophatImage();							// 顶帽操作
	void blackhatImage();						// 黑帽操作
	// Color
	void splitR();								// R分量图
	void splitG();								// G分量图
	void splitB();								// B分量图
	void splitH_HSV();							// H分量图HSV
	void splitS_HSV();							// S分量图HSV
	void splitV_HSV();							// V分量图HSV
	void splitY_YUV();							// Y分量图YUV
	void splitU_YUV();							// U分量图YUV
	void splitV_YUV();							// V分量图YUV
	void splitH_HLS();							// H分量图HLS
	void splitL_HLS();							// L分量图HLS
	void splitS_HLS();							// S分量图HLS
	// 按钮组
	void toolButtonClicked(int id); 
	void preButtonClicked(int id);
	// 绘图工具栏
	void penWidth();							// 设置线宽
	void penColor();							// 显示所选颜色
	void whiteLayout();							// 白色布局
	void blackLayout();							// 黑色布局
	void fullSize();							// 图像铺满窗口
	void autoSize();							// 图像自适应窗口大小
	void changeSkin();							// 切换皮肤
	void option();								// 设置
	// 检测各窗口是否打开
	void isDockImage();
	void isDockTool();
	void isDockOutput();
	void isDockProp();
	void isDockGeom();
	void isDockGray();
	void isDockEnhance();
	void isDockMorp();
	void isDockColor();
	
private:
	// Main
	Ui::ImageProcessingClass ui;
	ImgChange *imgChangeClass;					// 图像改变类
	Geom *geomClass;							// 几何变换类
	Gray *grayClass;							// 灰度变换类
	Enhance *enhanceClass;						// 图像增强类
	Morp *morpClass;							// 形态学类
	Menu *I_menubar;							// 菜单栏
	QTextEdit *menuEdit;						// 下拉菜单
	QTextEdit *outputEdit;						// 输出框
	QScrollArea* ImgscrollArea;					// 图像窗口滑动条
	QWidget *widget_pre[7];						// 预览组件
	QString stylesheet;							// QSS样式表
	bool isSkin;								// 是否切换成黑色皮肤
	
	// Geom
	QSpinBox *spinbox_size;						// 缩放微调框
	QSpinBox *spinbox_rotate;					// 旋转微调框
	QSpinBox *spinbox_leanX, *spinbox_leanY;	// 图像移动距离

	QLineEdit *line_L, *line_W;					// 设置长宽
	QSpinBox *line_times;
	QSpinBox *line_degree;
	QSpinBox *line_leanX, *line_leanY;			// 倾斜角度

	// Gray
	QSpinBox *spinbox_bin;
	QSpinBox *spinbox_alpha, *spinbox_beta;		// 图像灰度变换
	QSpinBox *spinbox_gamma, *spinbox_c;		// 图像灰度变换
	QSpinBox *line_bin;
	QSpinBox *line_alpha, *line_beta;
	QSpinBox *line_gamma, *line_c;

	// Enhance
	QSpinBox *spinbox_canny;					// canny微调框
	QSpinBox *spinbox_lineThreshold, *spinbox_minLineLength, *spinbox_maxLineGap;// Line
	QSpinBox *spinbox_minRadius, *spinbox_maxRadius;	// circle
	QComboBox *combo_smooth, *combo_sharpen;	// 下拉选择框

	// Morp
	QSpinBox *spinbox_erode, *spinbox_dilate;
	QSpinBox *spinbox_open, *spinbox_close;
	QSpinBox *spinbox_tophat, *spinbox_blackhat;
	QSpinBox *spinbox_hitmiss;
	QComboBox *combo_kernel, *combo_elem;

	// Help
	QRadioButton *whiteRadio, *blackRadio;

	// 属性窗口
	QLineEdit *line_img;
	QLineEdit *line_length;
	QLineEdit *line_width;
	QLineEdit *line_depth;
	QLineEdit *line_isGray;

	// 预览窗口
	CustomWindow *preWin;						// 预览窗口
	QButtonGroup *preButtonGroup;

 	// 工具箱
	QButtonGroup *toolButtonGroup;
	int drawType;	
	
	// 绘图工具栏
	QSpinBox *spinbox_penWidth;
	QFrame *frame_color;

	void init();								// 初始化
	void Show();								// 界面
	void CreateLayout();						// 创建布局
	void InitImage();							// 初始化图像
	void ColorToolBar();						// 绘制工具栏

	void WinMain();								// 主体窗口
	void WinProp();								// 属性窗口
	void WinTool();								// 工具栏
	void WinPreview();							// 预览窗口
	void WinGeom();								// 几何变换窗口
	void WinGray();								// 灰度变换窗口
	void WinEnhance();							// 图像增强窗口
	void WinMorp();								// 形态学处理窗口
	void WinColor();							// 颜色模型窗口
};

#endif // MAINWINDOW_H
