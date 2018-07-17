#ifndef GRAY_H
#define GRAY_H

#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp> 
#include "opencv2/imgproc.hpp"

#include "header/ImgChange.h"
using namespace cv;

class Gray
{
public:
	Gray();
	~Gray();

	QImage Bin(QImage src, int threshold);
	QImage Graylevel(QImage src);
	QImage Reverse(QImage src);								// 图像反转
	QImage Linear(QImage src, int alpha, int beta);			// 线性变换
	QImage Gamma(QImage src, int gamma);					// 伽马变换(指数变换)
	QImage Log(QImage src, int c);							// 对数变换
	QImage Histeq(QImage src);								// 直方图均衡化
		
private:
	ImgChange *imgchangeClass;
};	

#endif// !GRAY_H