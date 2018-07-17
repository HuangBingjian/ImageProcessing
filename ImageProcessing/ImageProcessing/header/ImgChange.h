#ifndef IMGCHANGE_H
#define IMGCHANGE_H

#include <QtGui>
#include <QtWidgets>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"   
#include <opencv2/core/core.hpp>  
using namespace cv;

class QImage;
class ImgChange				// 图像改变
{
public:
	ImgChange();
	~ImgChange();

	QImage cvMat2QImage(const Mat& mat);     // Mat 改成 QImage
	Mat QImage2cvMat(QImage image);			// QImage 改成 Mat
	
	QImage splitBGR(QImage src, int color);			// 提取RGB分量
	QImage splitColor(QImage src, String model, int color);		// 提取分量

private:
	//int rgb2hsi(Mat &image, Mat &hsi);
	//int rgb2cmyk(Mat &image, Mat &cmyk);
};

#endif // !IMGCHANGE_H

