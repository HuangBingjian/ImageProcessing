#ifndef MORP_H
#define MORP_H

#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp> 
#include "opencv2/imgproc.hpp"

#include "header/ImgChange.h"
using namespace cv;

class Morp
{
public:
	Morp();
	~Morp();

	QImage Erode(QImage src, int elem,int kernel,int times);		// 腐蚀
	QImage Dilate(QImage src, int elem, int kernel, int times);		// 膨胀
	QImage Open(QImage src, int elem, int kernel, int times);		// 开运算
	QImage Close(QImage src, int elem, int kernel, int times);		// 闭运算
	QImage Grad(QImage src, int elem, int kernel);					// 形态学梯度
	QImage Tophat(QImage src, int elem, int kernel);				// 顶帽操作
	QImage Blackhat(QImage src, int elem, int kernel);				// 黑帽操作

private:
	ImgChange *imgchangeClass;
};

#endif// !MORP_H