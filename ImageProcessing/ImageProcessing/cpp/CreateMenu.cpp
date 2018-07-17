#pragma execution_character_set("utf-8")		// 中文编码


//#include <QMainWindow>
//#include "ui_ImageProcessing.h"
#include <QtGui>
#include <QtWidgets>
#include <string>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp>  

#include "header/MainWindow.h"
#include "header/CreateMenu.h"
#include "header/ImgChange.h" 
#include "header/CustomWindow.h"

using namespace cv;
using namespace std;

Menu::Menu(QWidget *parent, ImageProcessing *p)
	: QMenuBar(parent)
{
	I_MainWindow = (ImageProcessing*)p;
	
	I_ToolBar = new QToolBar ;
	I_ToolBar = I_MainWindow->addToolBar(tr("文件工具栏"));
	I_ToolBar->setMovable(false);
	
	Menu_File();
	Menu_Edit();
	Menu_View();
	Menu_Geom();
	Menu_Gray();
	Menu_Enhance();
	Menu_Morp();	
	Menu_Color();
	Menu_Help();
}

Menu::~Menu()
{
}

void Menu::Menu_File()
{
	QAction *Act_file_new = new QAction(QIcon("../Image/file/New.png"), tr("新建"), this);
	Act_file_new->setShortcut(Qt::Key_Control & Qt::Key_N);
	//Act_file_new->setStatusTip(tr("新建图像"));
	connect(Act_file_new, SIGNAL(triggered()), this, SLOT(File_new()));

	QAction *Act_file_open = new QAction(QIcon("../Image/file/Open.png"), tr("打开"), this);
	Act_file_open->setShortcuts(QKeySequence::Open);
	//Act_file_open->setStatusTip(tr("打开图像"));
	connect(Act_file_open, SIGNAL(triggered()), this, SLOT(File_open()));

	QAction *Act_file_save = new QAction(QIcon("../Image/file/Save.png"), tr("保存"), this);
	Act_file_save->setShortcuts(QKeySequence::Save);
	//Act_file_save->setStatusTip(tr("保存图像"));
	connect(Act_file_save, SIGNAL(triggered()), this, SLOT(File_save()));

	QAction *Act_file_saveas = new QAction(QIcon("../Image/file/SaveAs.png"), tr("另存为"), this);
	Act_file_saveas->setShortcuts(QKeySequence::SaveAs);
	//Act_file_saveas->setStatusTip(tr("图像另存为"));
	connect(Act_file_saveas, SIGNAL(triggered()), this, SLOT(File_saveas()));

	QAction *Act_file_close = new QAction(QIcon("../Image/file/Close.png"), tr("关闭"), this);
	Act_file_close->setShortcuts(QKeySequence::Close);
	//Act_file_close->setStatusTip(tr("关闭软件"));
	connect(Act_file_close, SIGNAL(triggered()), I_MainWindow, SLOT(close()));

	QMenu *file = addMenu(tr("文件"));
	file->addAction(Act_file_new);
	file->addAction(Act_file_open);
	file->addAction(Act_file_save);
	file->addAction(Act_file_saveas);
	file->addSeparator();						//添加一个分割器
	file->addAction(Act_file_close);

	I_ToolBar->addAction(Act_file_new);
	I_ToolBar->addAction(Act_file_open);
	I_ToolBar->addAction(Act_file_save);
}

void Menu::Menu_Edit()
{
	Act_edit_undo = new QAction(QIcon("../Image/edit/Edit_Cancel.png"), tr("撤销"), this);
	Act_edit_undo->setShortcuts(QKeySequence::Undo);
	connect(Act_edit_undo, SIGNAL(triggered()), I_MainWindow, SLOT(undo()));
	
	Act_edit_redo = new QAction(QIcon("../Image/edit/Edit_Resume.png"), tr("重做"), this);
	Act_edit_redo->setShortcuts(QKeySequence::Redo);
	connect(Act_edit_redo, SIGNAL(triggered()), I_MainWindow, SLOT(redo()));

	QAction *Act_edit_full = new QAction(QIcon("../Image/edit/Edit_Full.png"), tr("全屏显示"), this);
	Act_edit_full->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
	connect(Act_edit_full, SIGNAL(triggered()), I_MainWindow, SLOT(fullScreen()));

	QAction *Act_edit_back = new QAction(QIcon("../Image/edit/Edit_Max.png"), tr("退出全屏"), this);
	Act_edit_back->setShortcut(QKeySequence(Qt::Key_Escape));
	connect(Act_edit_back, SIGNAL(triggered()), I_MainWindow, SLOT(maxScreen()));

	QMenu *edit = addMenu(tr("编辑"));
	edit->addAction(Act_edit_undo);
	edit->addAction(Act_edit_redo);
	edit->addAction(Act_edit_full);
	edit->addAction(Act_edit_back);

	I_ToolBar->addAction(Act_edit_undo);
	I_ToolBar->addAction(Act_edit_redo);
}

void Menu::Menu_View()
{
	Act_view_tool = new QAction(QIcon("../Image/view/Check.png"), tr("工具箱"), this);
	connect(Act_view_tool, SIGNAL(triggered()), this, SLOT(View_tool()));
	Act_view_geom = new QAction(QIcon("../Image/view/Check.png"), tr("几何变换"), this);
	connect(Act_view_geom, SIGNAL(triggered()), this, SLOT(View_geom()));
	Act_view_gray = new QAction(QIcon("../Image/view/Check.png"), tr("灰度变换"), this);
	connect(Act_view_gray, SIGNAL(triggered()), this, SLOT(View_gray()));
	Act_view_enhance = new QAction(QIcon("../Image/view/Check.png"), tr("图像增强"), this);
	connect(Act_view_enhance, SIGNAL(triggered()), this, SLOT(View_enhance()));
	Act_view_morp = new QAction(QIcon("../Image/view/Check.png"), tr("形态学处理"), this);
	connect(Act_view_morp, SIGNAL(triggered()), this, SLOT(View_morp()));
	Act_view_color = new QAction(QIcon("../Image/view/Check.png"), tr("颜色模型"), this);
	connect(Act_view_color, SIGNAL(triggered()), this, SLOT(View_color()));
	Act_view_image = new QAction(QIcon("../Image/view/Check.png"), tr("图像窗口"), this);
	connect(Act_view_image, SIGNAL(triggered()), this, SLOT(View_image()));
	Act_view_output = new QAction(QIcon("../Image/view/Check.png"), tr("输出窗口"), this);
	connect(Act_view_output, SIGNAL(triggered()), this, SLOT(View_output()));
	Act_view_prop = new QAction(QIcon("../Image/view/Check.png"), tr("属性窗口"), this);
	connect(Act_view_prop, SIGNAL(triggered()), this, SLOT(View_prop()));
	Act_edit_file = new QAction(QIcon("../Image/view/Check.png"), tr("文件工具栏"), this);
	connect(Act_edit_file, SIGNAL(triggered()), this, SLOT(View_fileBar()));
	Act_edit_paint = new QAction(QIcon("../Image/view/Check.png"), tr("绘图工具栏"), this);
	connect(Act_edit_paint, SIGNAL(triggered()), this, SLOT(View_colorBar()));

	QMenu *view = addMenu(tr("视图"));
	view->addAction(Act_view_tool);
	view->addAction(Act_view_geom);
	view->addAction(Act_view_gray);
	view->addAction(Act_view_enhance);
	view->addAction(Act_view_morp);
	view->addAction(Act_view_color);
	view->addAction(Act_view_output);
	view->addAction(Act_view_prop);
	view->addAction(Act_edit_file);
	view->addAction(Act_edit_paint);
}

void Menu::Menu_Geom()
{
	// 二级菜单
	QAction *Act_geom_size = new QAction(QIcon("../Image/geom/Geom_Default.png"), tr("自适应窗口"), this);
	connect(Act_geom_size, SIGNAL(triggered()), I_MainWindow, SLOT(autoSize()));
	QAction *Act_geom_enlarge = new QAction(QIcon("../Image/geom/Geom_Enlarge.png"), tr("放大一倍"), this);
	connect(Act_geom_enlarge, SIGNAL(triggered()), I_MainWindow, SLOT(enlarge2()));
	QAction *Act_geom_reduce = new QAction(QIcon("../Image/geom/Geom_Reduce.png"), tr("缩小一倍"), this);
	connect(Act_geom_reduce, SIGNAL(triggered()), I_MainWindow, SLOT(reduce2()));

	menu_resize = new QMenu();
	menu_resize->setIcon(QIcon("../Image/geom/Geom_EnlargeReduce.png"));
	menu_resize->setTitle(tr("图像缩放"));
	menu_resize->addAction(Act_geom_size);
	menu_resize->addAction(Act_geom_enlarge);
	menu_resize->addAction(Act_geom_reduce);

	QAction *Act_geom_left = new QAction(QIcon("../Image/geom/Geom_RotateRight.png"), tr("顺时针旋转"), this);
	connect(Act_geom_left, SIGNAL(triggered()), I_MainWindow, SLOT(rotateImage_270()));
	QAction *Act_geom_right = new QAction(QIcon("../Image/geom/Geom_RotateLeft.png"), tr("逆时针旋转"), this);
	connect(Act_geom_right, SIGNAL(triggered()), I_MainWindow, SLOT(rotateImage_90()));
	QAction *Act_geom_180 = new QAction(QIcon("../Image/geom/Geom_RotateCenter.png"), tr("中心旋转"), this);
	connect(Act_geom_180, SIGNAL(triggered()), I_MainWindow, SLOT(rotateImage_180()));

	menu_rotate = new QMenu();
	menu_rotate->setIcon(QIcon("../Image/geom/Geom_Rotate.png"));
	menu_rotate->setTitle(tr("图像旋转"));
	menu_rotate->addAction(Act_geom_left);
	menu_rotate->addAction(Act_geom_right);
	menu_rotate->addAction(Act_geom_180);

	QAction *Act_geom_H = new QAction(QIcon("../Image/geom/Geom_FlipX.png"), tr("水平翻转"), this);
	connect(Act_geom_H, SIGNAL(triggered()), I_MainWindow, SLOT(flipImage_H()));
	QAction *Act_geom_V = new QAction(QIcon("../Image/geom/Geom_FlipY.png"), tr("垂直翻转"), this);
	connect(Act_geom_V, SIGNAL(triggered()), I_MainWindow, SLOT(flipImage_V()));

	menu_flip = new QMenu();
	menu_flip->setIcon(QIcon("../Image/geom/Geom_Flip.png"));
	menu_flip->setTitle(tr("图像翻转"));
	menu_flip->addAction(Act_geom_H);
	menu_flip->addAction(Act_geom_V);
	
	QMenu *geom = addMenu(tr("几何变换"));
	geom->addMenu(menu_resize);
	geom->addMenu(menu_rotate);
	geom->addMenu(menu_flip);
}

void Menu::Menu_Gray()		// 灰度变换
{
	// 二级菜单
	QAction *Act_gray_log = new QAction(QIcon("../Image/gray/Gray_Log.png"), tr("对数变换"), this);
	connect(Act_gray_log, SIGNAL(triggered()), I_MainWindow, SLOT(logImageOK()));
	QAction *Act_gray_gamma = new QAction(QIcon("../Image/gray/Gray_Gamma.png"),tr("伽马变换"), this);
	connect(Act_gray_gamma, SIGNAL(triggered()), I_MainWindow, SLOT(gammaImageOK()));
	QAction *Act_gray_histeq = new QAction(QIcon("../Image/gray/Gray_Histeq.png"), tr("直方图均衡化"), this);
	connect(Act_gray_histeq, SIGNAL(triggered()), I_MainWindow, SLOT(histeqImage()));

	menu_nolinear = new QMenu();
	menu_nolinear->addAction(Act_gray_log);
	menu_nolinear->addAction(Act_gray_gamma);
	menu_nolinear->addAction(Act_gray_histeq);
	
	// 一级菜单
	QAction *Act_gray_bin = new QAction(QIcon("../Image/gray/Gray_Bin.png"), tr("二值图"), this);
	connect(Act_gray_bin, SIGNAL(triggered()), I_MainWindow, SLOT(binImageOK()));
	QAction *Act_gray_gray = new QAction(QIcon("../Image/gray/Gray_Gray.png"), tr("灰度图"), this);
	connect(Act_gray_gray, SIGNAL(triggered()), I_MainWindow, SLOT(grayImage()));
	QAction *Act_gray_reverse = new QAction(QIcon("../Image/gray/Gray_Reverse.png"), tr("反转变换"), this);
	connect(Act_gray_reverse, SIGNAL(triggered()), I_MainWindow, SLOT(reverseImage()));
	QAction *Act_gray_linear = new QAction(QIcon("../Image/gray/Gray_Linear.png"), tr("线性变换"), this);
	connect(Act_gray_linear, SIGNAL(triggered()), I_MainWindow, SLOT(linearImageOK()));
	QAction *Act_gray_nolinear = new QAction(QIcon("../Image/gray/Gray_Nolinear.png"), tr("非线性变换"), this);
	Act_gray_nolinear->setMenu(menu_nolinear);
	
	QMenu *gray = addMenu(tr("灰度变换"));
	gray->addAction(Act_gray_bin);
	gray->addAction(Act_gray_gray);
	gray->addAction(Act_gray_reverse);
	gray->addAction(Act_gray_linear);
	gray->addAction(Act_gray_nolinear);
}

void Menu::Menu_Enhance()
{
	// 三级菜单
	QAction *Act_enhance_circles = new QAction(tr("圆检测"), this);
	connect(Act_enhance_circles, SIGNAL(triggered()), I_MainWindow, SLOT(circleImage()));
	QAction *Act_enhance_lines = new QAction(tr("直线检测"), this);
	connect(Act_enhance_lines, SIGNAL(triggered()), I_MainWindow, SLOT(lineImage()));

	menu_detect = new QMenu();
	menu_detect->addAction(Act_enhance_circles);
	menu_detect->addAction(Act_enhance_lines);
	
	// 二级菜单
	QAction *Act_enhance_normalize = new QAction(tr("简单滤波"));
	connect(Act_enhance_normalize, SIGNAL(triggered()), I_MainWindow, SLOT(normalizedImage()));
	QAction *Act_enhance_gaussian = new QAction(tr("高斯滤波"));
	connect(Act_enhance_gaussian, SIGNAL(triggered()), I_MainWindow, SLOT(gaussianImage()));
	QAction *Act_enhance_median = new QAction(tr("中值滤波"));
	connect(Act_enhance_median, SIGNAL(triggered()), I_MainWindow, SLOT(medianImage()));

	menu_smooth = new QMenu();
	menu_smooth->addAction(Act_enhance_normalize);
	menu_smooth->addAction(Act_enhance_gaussian);
	menu_smooth->addAction(Act_enhance_median);

	QAction *Act_enhance_sobel = new QAction(tr("Sobel算子"));
	connect(Act_enhance_sobel, SIGNAL(triggered()), I_MainWindow, SLOT(sobelImage()));
	QAction *Act_enhance_laplacian = new QAction(tr("Laplacian算子"));
	connect(Act_enhance_laplacian, SIGNAL(triggered()), I_MainWindow, SLOT(laplacianImage()));
	QAction *Act_enhance_canny = new QAction(tr("Canny算子"));
	connect(Act_enhance_canny, SIGNAL(triggered()), I_MainWindow, SLOT(cannyImage()));
	QAction *Act_enhance_hough = new QAction(tr("Hough算子"));
	Act_enhance_hough->setMenu(menu_detect);

	menu_sharpen = new QMenu();
	menu_sharpen->addAction(Act_enhance_sobel);
	menu_sharpen->addAction(Act_enhance_laplacian);
	menu_sharpen->addAction(Act_enhance_canny);
	menu_sharpen->addAction(Act_enhance_hough);
		
	// 一级菜单
	QAction *Act_enhance_smooth = new QAction(tr("平滑"), this);
	Act_enhance_smooth->setMenu(menu_smooth);
	QAction *Act_enhance_sharpen = new QAction(tr("锐化"), this);
	Act_enhance_sharpen->setMenu(menu_sharpen);

	QMenu *enhance = addMenu(tr("图像增强"));
	enhance->addAction(Act_enhance_smooth);
	enhance->addAction(Act_enhance_sharpen);
}

void Menu::Menu_Morp()
{
	QAction *Act_morp_erode = new QAction(tr("腐蚀"), this);
	connect(Act_morp_erode, SIGNAL(triggered()), I_MainWindow, SLOT(erodeImage()));
	QAction *Act_morp_dilate = new QAction(tr("膨胀"), this);
	connect(Act_morp_dilate, SIGNAL(triggered()), I_MainWindow, SLOT(dilateImage()));
	QAction *Act_morp_open = new QAction(tr("开运算"), this);
	connect(Act_morp_open, SIGNAL(triggered()), I_MainWindow, SLOT(openImage()));
	QAction *Act_morp_close = new QAction(tr("闭运算"), this);
	connect(Act_morp_close, SIGNAL(triggered()), I_MainWindow, SLOT(closeImage()));
	QAction *Act_morp_tophat = new QAction(tr("顶帽操作"), this);
	connect(Act_morp_tophat, SIGNAL(triggered()), I_MainWindow, SLOT(tophatImage()));
	QAction *Act_morp_blackhat = new QAction(tr("黑帽操作"), this);
	connect(Act_morp_blackhat, SIGNAL(triggered()), I_MainWindow, SLOT(blackhatImage()));
	QAction *Act_morp_grad = new QAction(tr("形态学梯度"), this);
	connect(Act_morp_grad, SIGNAL(triggered()), I_MainWindow, SLOT(gradImage()));

	QMenu *morp = addMenu(tr("形态学处理"));
	morp->addAction(Act_morp_erode);
	morp->addAction(Act_morp_dilate);
	morp->addAction(Act_morp_open);
	morp->addAction(Act_morp_close);
	morp->addAction(Act_morp_tophat);
	morp->addAction(Act_morp_blackhat);
	morp->addAction(Act_morp_grad);
}

void  Menu::Menu_Color()
{
	QAction *Act_RGB_R = new QAction(tr("R分量图"), this);
	connect(Act_RGB_R, SIGNAL(triggered()), I_MainWindow, SLOT(splitR()));
	QAction *Act_RGB_G = new QAction(tr("G分量图"), this);
	connect(Act_RGB_G, SIGNAL(triggered()), I_MainWindow, SLOT(splitG()));
	QAction *Act_RGB_B = new QAction(tr("B分量图"), this);
	connect(Act_RGB_B, SIGNAL(triggered()), I_MainWindow, SLOT(splitB()));
	
	menu_RGB = new QMenu();
	menu_RGB->addAction(Act_RGB_R);
	menu_RGB->addAction(Act_RGB_G);
	menu_RGB->addAction(Act_RGB_B);
	QAction *Act_color_RGB = new QAction(tr("RGB模型"), this);
	Act_color_RGB->setMenu(menu_RGB);
	
	QAction *Act_HSV_H = new QAction(tr("H分量图"), this);
	connect(Act_HSV_H, SIGNAL(triggered()), I_MainWindow, SLOT(splitH_HSV()));
	QAction *Act_HSV_S = new QAction(tr("S分量图"), this);
	connect(Act_HSV_S, SIGNAL(triggered()), I_MainWindow, SLOT(splitS_HSV()));
	QAction *Act_HSV_V = new QAction(tr("V分量图"), this);
	connect(Act_HSV_V, SIGNAL(triggered()), I_MainWindow, SLOT(splitV_HSV()));

	menu_HSV = new QMenu();
	menu_HSV->addAction(Act_HSV_H);
	menu_HSV->addAction(Act_HSV_S);
	menu_HSV->addAction(Act_HSV_V);
	QAction *Act_color_HSV = new QAction(tr("HSV模型"), this);
	Act_color_HSV->setMenu(menu_HSV);
	
	QAction *Act_YUV_Y = new QAction(tr("Y分量图"), this);
	connect(Act_YUV_Y, SIGNAL(triggered()), I_MainWindow, SLOT(splitY_YUV()));
	QAction *Act_YUV_U = new QAction(tr("U分量图"), this);
	connect(Act_YUV_U, SIGNAL(triggered()), I_MainWindow, SLOT(splitU_YUV()));
	QAction *Act_YUV_V = new QAction(tr("V分量图"), this);
	connect(Act_YUV_V, SIGNAL(triggered()), I_MainWindow, SLOT(splitV_YUV()));
	
	menu_YUV = new QMenu();
	menu_YUV->addAction(Act_YUV_Y);
	menu_YUV->addAction(Act_YUV_U);
	menu_YUV->addAction(Act_YUV_V);
	QAction *Act_color_YUV = new QAction(tr("YUV模型"), this);
	Act_color_YUV->setMenu(menu_YUV);

	QAction *Act_HLS_H = new QAction(tr("H分量图"), this);
	connect(Act_HLS_H, SIGNAL(triggered()), I_MainWindow, SLOT(splitH_HLS()));
	QAction *Act_HLS_L = new QAction(tr("L分量图"), this);
	connect(Act_HLS_L, SIGNAL(triggered()), I_MainWindow, SLOT(splitL_HLS()));
	QAction *Act_HLS_S = new QAction(tr("S分量图"), this);
	connect(Act_HLS_S, SIGNAL(triggered()), I_MainWindow, SLOT(splitS_HLS()));

	menu_HLS = new QMenu();
	menu_HLS->addAction(Act_HLS_H);
	menu_HLS->addAction(Act_HLS_L);
	menu_HLS->addAction(Act_HLS_S);
	QAction *Act_color_HLS = new QAction(tr("HLS模型"), this);
	Act_color_HLS->setMenu(menu_HLS);

	QMenu *color = addMenu(tr("颜色模型"));
	color->addAction(Act_color_RGB);
	color->addAction(Act_color_HSV);
	color->addAction(Act_color_YUV);
	color->addAction(Act_color_HLS);
}

void Menu::Menu_Help()
{
	QAction *Act_help_info = new QAction(QIcon("../Image/help/Help_Info.png"), tr("关于"), this);
	connect(Act_help_info, SIGNAL(triggered()), this, SLOT(Help_info()));

	Act_help_option = new QAction(QIcon("../Image/edit/Edit_Option.png"), tr("设置"), this);
	connect(Act_help_option, SIGNAL(triggered()), I_MainWindow, SLOT(option()));
	
	QMenu *help = addMenu(tr("帮助"));
	help->addAction(Act_help_info);
	help->addAction(Act_help_option);
}

// -------------------文件-------------------------------------------

void Menu::File_new()		// 新建文件
{
	// 主窗口显示
	QImage image = QImage(500, 500, QImage::Format_RGB32);
	image.fill(qRgb(255, 255, 255));
	I_MainWindow->ShowImage(image,true);
	I_MainWindow->output("新建图像: 长500，宽500");
	I_MainWindow->UpdateImgName("新图像");
	currentPath = "";
}

void Menu::File_open()		// 打开文件
{
	QString path = QFileDialog::getOpenFileName(this, tr("选择图像"), ".", tr("Images(*.jpg *.png *.bmp)"));
	if (!path.isEmpty())
	{
		QImage* img = new QImage();
		if (!(img->load(path)))
		{
			QMessageBox::information(this, tr("错误"), tr("打开图像失败！"));
			delete img;
			return;
		}
		I_MainWindow->ShowImage(*img, true);
		I_MainWindow->output("打开图像: "+ path );
		I_MainWindow->UpdateImgName(path);
		currentPath = path;
	}
}

void Menu::File_save()			// 保存文件
{
	ImgChange *imgchange = new ImgChange();

	if (currentPath.isEmpty())
	{
		QString path = QFileDialog::getSaveFileName(this, tr("保存图像"), ".", tr("Images(*.jpg *.png *.bmp)"));
		{
			if (!path.isEmpty())
			{
				QImage img = I_MainWindow->imgLabel->getImage();
				img.save(path);
				I_MainWindow->output("图像保存: " + path);
				I_MainWindow->UpdateImgName(path);
				currentPath = path;
				I_MainWindow->ShowImage(img, true);
			}
		}
	}
	else
	{
		QImage img = I_MainWindow->imgLabel->getImage();
		img.save(currentPath);
		I_MainWindow->output("保存图像：图像已保存");
		I_MainWindow->ShowImage(img, true);
	}
}

void Menu::File_saveas()			// 另存为文件
{
	QString path = QFileDialog::getSaveFileName(this, tr("图像另存为"), ".", tr("Images(*.jpg *.png *.bmp)"));
	if (!path.isEmpty())
	{
		ImgChange *imgchange = new ImgChange();
		QImage img = I_MainWindow->imgLabel->getImage();
		img.save(path);
		I_MainWindow->output("图像另存为: " + path );
		I_MainWindow->UpdateImgName(path);
		I_MainWindow->ShowImage(img, true);
	}
}

// -------------------视图-------------------------------------------

void Menu::View_output()
{
	if (I_MainWindow->dock_Output->isHidden() == true)
	{
		I_MainWindow->dock_Output->show();
		I_MainWindow->output("窗口显示：输出窗口");
	}
	else
	{
		I_MainWindow->dock_Output->hide();
		I_MainWindow->output("窗口关闭：输出窗口");
	}
}

void Menu::View_tool()
{
	if (I_MainWindow->dock_Tool->isHidden() == true)
	{
	I_MainWindow->dock_Tool->show();
	I_MainWindow->output("窗口显示：工具栏窗口");
	}
	else
	{
		I_MainWindow->dock_Tool->hide();
		I_MainWindow->output("窗口关闭：工具栏窗口");
	}
}

void Menu::View_geom()
{
	if (I_MainWindow->dock_Geom->isHidden() == true)
	{
		I_MainWindow->dock_Geom->show();
		I_MainWindow->output("窗口显示：几何变换窗口");
	}
	else
	{
		I_MainWindow->dock_Geom->hide();
		I_MainWindow->output("窗口关闭：几何变换窗口");
	}
}

void Menu::View_gray()
{
	if (I_MainWindow->dock_Gray->isHidden() == true)
	{
		I_MainWindow->dock_Gray->show();
		I_MainWindow->output("窗口显示：灰度变换窗口");
	}
	else
	{
		I_MainWindow->dock_Gray->hide();
		I_MainWindow->output("窗口关闭：灰度变换窗口");
	}
}

void Menu::View_enhance()
{
	if (I_MainWindow->dock_Enhance->isHidden() == true)
	{
		I_MainWindow->dock_Enhance->show();
		I_MainWindow->output("窗口显示：图像增强窗口");
	}
	else
	{
		I_MainWindow->dock_Enhance->hide();
		I_MainWindow->output("窗口关闭：图像增强窗口");
	}
}

void Menu::View_morp()
{
	if (I_MainWindow->dock_Morp->isHidden() == true)
	{
		I_MainWindow->dock_Morp->show();
		I_MainWindow->output("窗口显示：形态学窗口");
	}
	else
	{
		I_MainWindow->dock_Morp->hide();
		I_MainWindow->output("窗口关闭：形态学窗口");
	}
}

void Menu::View_color()
{
	if (I_MainWindow->dock_Color->isHidden() == true)
	{
		I_MainWindow->dock_Color->show();
		I_MainWindow->output("窗口显示：颜色模型窗口");
	}
	else
	{
		I_MainWindow->dock_Color->hide();
		I_MainWindow->output("窗口关闭：颜色模型窗口");
	}
}

void Menu::View_image()
{
	if (I_MainWindow->dock_Image->isHidden() == true)
	{
		I_MainWindow->dock_Image->show();
		I_MainWindow->output("窗口显示：图像窗口");
	}
	else
	{
		I_MainWindow->dock_Image->hide();
		I_MainWindow->output("窗口关闭：图像窗口");
	}
}

void Menu::View_prop()
{
	if (I_MainWindow->dock_Prop->isHidden() == true)
	{
		I_MainWindow->dock_Prop->show();
		I_MainWindow->output("窗口显示：属性窗口");
	}
	else
	{
		I_MainWindow->dock_Prop->hide();
		I_MainWindow->output("窗口关闭：属性窗口");
	}
}

void Menu::View_fileBar()
{
	if (I_ToolBar->isHidden() == true)
	{
		I_ToolBar->show();
		Act_edit_file->setIcon(QIcon("../Image/view/Check.png"));
		I_MainWindow->output("显示：文件工具栏");
	}
	else
	{
		I_ToolBar->hide();
		Act_edit_file->setIcon(QIcon(""));
		I_MainWindow->output("隐藏：文件工具栏");
	}
}

void Menu::View_colorBar()
{
	if (I_MainWindow->I_ColorBar->isHidden() == true)
	{
		I_MainWindow->I_ColorBar->show();
		Act_edit_paint->setIcon(QIcon("../Image/view/Check.png"));
		I_MainWindow->output("显示：绘图工具栏");
	}
	else
	{
		I_MainWindow->I_ColorBar->hide();
		Act_edit_paint->setIcon(QIcon(""));
		I_MainWindow->output("隐藏：绘图工具栏");
	}
}

// -------------------帮助-------------------------------------------

void Menu::Help_info()
{
	helpWin = new CustomWindow();
	helpWin->resize(600, 400);

	QLabel *label_about = new QLabel(helpWin);
	label_about->setText(tr("图像处理自编软件 1.0 版"));
	QLabel *label_right = new QLabel(helpWin);
	label_right->setText(tr("Copyright (C) 2018  深圳 ATR"));
	QLabel *label_author = new QLabel(helpWin);
	label_author->setText(tr("作者：笔尖	  http://blog.csdn.net/u013165921"));
	QPushButton *button_ok = new QPushButton(helpWin);
	button_ok->setText(tr("确定"));
	connect(button_ok, SIGNAL(clicked()), helpWin, SLOT(close()));

	label_about->move(100, 100);
	label_right->move(100, 180);
	label_author->move(100, 260);
	button_ok->move(400, 180);

	helpWin->exec();
}


void Menu::setMenuQSS(bool flag)		// 设置二级菜单QSS
{
	setSubMenu(menu_resize,flag);
	setSubMenu(menu_rotate, flag);
	setSubMenu(menu_flip, flag);
	setSubMenu(menu_nolinear, flag);
	setSubMenu(menu_detect, flag);
	setSubMenu(menu_smooth, flag);
	setSubMenu(menu_sharpen, flag);
	setSubMenu(menu_RGB, flag);
	setSubMenu(menu_HSV, flag);
	setSubMenu(menu_YUV, flag);
	setSubMenu(menu_HLS, flag);
}

void Menu::setSubMenu(QMenu *menu, bool flag)		// 设置qss
{
	if (flag == true)
		menu->setStyleSheet("background-color: rgba(74, 79, 81, 1); color: rgb(187, 187, 187);selection-background-color:#4b6eaf; ");
	else
		menu->setStyleSheet(0);
}