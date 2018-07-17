#ifndef  GEOM_H
#define GEOM_H

#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp> 
#include "opencv2/imgproc.hpp"

#include "header/ImgChange.h"
using namespace cv;

class Geom			// 图像几何变换
{
public:
	Geom();
	~Geom();

	QImage Resize(QImage src, int length, int width);
	QImage Enlarge_Reduce(QImage src, int times);
	QImage Rotate(QImage src, int angle);
	QImage Rotate_fixed(QImage src, int angle);
	QImage Flip(QImage src, int flipcode);
	QImage Lean(QImage src, int x, int y);

private:
	ImgChange *imgchangeClass;			// 大小类

};

#endif // ! GEOM_H

