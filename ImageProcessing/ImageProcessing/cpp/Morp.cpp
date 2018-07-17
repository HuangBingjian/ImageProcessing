#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp> 
#include "header/Morp.h"

using namespace cv;

Morp::Morp()
{
	imgchangeClass = new ImgChange;
}

Morp::~Morp()
{
}

QImage Morp::Erode(QImage src, int elem, int kernel, int times)		// ¸¯Ê´
{
	Mat srcImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);
	int erosion_type = 0;
	if (elem == 0) { erosion_type = MORPH_RECT; }
	else if (elem == 1) { erosion_type = MORPH_CROSS; }
	else if (elem == 2) { erosion_type = MORPH_ELLIPSE; }
	Mat element = getStructuringElement(erosion_type,Size(2 * kernel + 3, 2 * kernel + 3), Point(kernel+1, kernel+1));
	erode(srcImg, dstImg, element, Point(-1, -1), times);
	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Morp::Dilate(QImage src, int elem, int kernel, int times)		// ÅòÕÍ
{
	Mat srcImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);
	int dilation_type = 0;
	if (elem == 0) { dilation_type = MORPH_RECT; }
	else if (elem == 1) { dilation_type = MORPH_CROSS; }
	else if (elem == 2) { dilation_type = MORPH_ELLIPSE; }
	Mat element = getStructuringElement(dilation_type, Size(2 * kernel + 3, 2 * kernel + 3), Point(kernel + 1, kernel + 1));
	dilate(srcImg, dstImg, element, Point(-1, -1), times);
	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Morp::Open(QImage src, int elem, int kernel, int times)		// ¿ªÔËËã
{
	Mat srcImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);
	Mat element = getStructuringElement(elem,Size(2 * kernel + 3, 2 * kernel + 3), Point(kernel + 1, kernel + 1));
	morphologyEx(srcImg, dstImg, MORPH_OPEN, element, Point(-1, -1), times);
	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Morp::Close(QImage src, int elem, int kernel, int times)		// ±ÕÔËËã
{
	Mat srcImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);
	Mat element = getStructuringElement(elem,Size(2 * kernel + 3, 2 * kernel + 3), Point(kernel + 1, kernel + 1));
	morphologyEx(srcImg, dstImg, MORPH_CLOSE, element, Point(-1, -1), times);
	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Morp::Grad(QImage src, int elem, int kernel)		// ÐÎÌ¬Ñ§ÌÝ¶È
{
	Mat srcImg, grayImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);
	Mat element = getStructuringElement(elem,Size(2 * kernel + 3, 2 * kernel + 3), Point(kernel + 1, kernel + 1));

	if (srcImg.channels() != 1)
		cvtColor(srcImg, grayImg, CV_BGR2GRAY);
	else
		grayImg = srcImg.clone();
	morphologyEx(grayImg, dstImg, MORPH_GRADIENT, element);

	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Morp::Tophat(QImage src, int elem, int kernel)		// ¶¥Ã±²Ù×÷
{
	Mat srcImg, grayImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);
	Mat element = getStructuringElement(elem,Size(2 * kernel + 3, 2 * kernel + 3), Point(kernel + 1, kernel + 1));
	if (srcImg.channels() != 1)
		cvtColor(srcImg, grayImg, CV_BGR2GRAY);
	else
		grayImg = srcImg.clone();

	morphologyEx(grayImg, dstImg, MORPH_TOPHAT, element);
	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Morp::Blackhat(QImage src, int elem, int kernel)	// ºÚÃ±²Ù×÷
{
	Mat srcImg, grayImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);
	Mat element = getStructuringElement(elem,Size(2 * kernel + 3, 2 * kernel + 3), Point(kernel + 1, kernel + 1));	
	if (srcImg.channels() != 1)
		cvtColor(srcImg, grayImg, CV_BGR2GRAY);
	else
		grayImg = srcImg.clone();
	morphologyEx(grayImg, dstImg, MORPH_BLACKHAT, element);
	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}


