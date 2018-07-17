#ifndef CREATEMENU_H
#define CREATEMENU_H

#include <QtGui>
#include <QtWidgets>
#include <QMenuBar>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp> 

#include "header/MainWindow.h"
#include "header/CustomWindow.h"
class ImageProcessing;

using namespace cv;


class Menu : public QMenuBar
{
	Q_OBJECT

public:
	Menu(QWidget *parent, ImageProcessing *p);
	~Menu();

	CustomWindow *helpWin;
	QAction *Act_view_tool, *Act_view_image,*Act_view_geom, *Act_view_gray, *Act_view_enhance, *Act_view_morp,
		*Act_view_color, *Act_view_output, *Act_view_prop, *Act_edit_file, *Act_edit_paint;
	QAction *Act_edit_undo, *Act_edit_redo, *Act_help_option;
	void setMenuQSS(bool);		// 设置二级菜单的QSS

private slots :
	// 界面目录
	void File_new();		// 新建
	void File_open();		// 打开
	void File_save();		// 保存
	void File_saveas();		// 另存为

	void View_output();
	void View_tool();
	void View_geom();
	void View_gray();
	void View_enhance();
	void View_morp();
	void View_color();
	void View_image();
	void View_prop();	
	void View_fileBar();
	void View_colorBar();
	void Help_info();		

private:
	ImageProcessing *I_MainWindow;
	QToolBar *I_ToolBar;
	QString currentPath;	// 当前图像路径
	void setSubMenu(QMenu *menu, bool flag);		// 设置qss

	void Menu_File();		// 文件菜单
	void Menu_Edit();		// 编辑菜单
	void Menu_View();		// 视图菜单
	void Menu_Geom();		// 几何变换
	void Menu_Gray();		// 灰度变换
	void Menu_Enhance();	// 图像增强
	void Menu_Morp();		// 形态学
	void Menu_Color();		// 颜色模型
	void Menu_Help();		// 帮助菜单

	// 二级菜单
	QMenu *menu_resize, *menu_rotate, *menu_flip, *menu_nolinear, *menu_detect, *menu_smooth, *menu_sharpen;
	QMenu *menu_RGB, *menu_HSV, *menu_YUV, *menu_HLS;
};

#endif
