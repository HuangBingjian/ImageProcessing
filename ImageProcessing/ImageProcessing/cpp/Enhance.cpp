#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp> 
#include "header/Enhance.h"

using namespace cv;
using namespace std;

Enhance::Enhance()
{
	imgchangeClass = new ImgChange;
}

Enhance::~Enhance()
{
}

QImage Enhance::Normalized(QImage src,int kernel_length)								// 简单滤波
{
	Mat srcImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);
	blur(srcImg, dstImg, Size(kernel_length, kernel_length), Point(-1, -1));
	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Enhance::Gaussian(QImage src, int kernel_length)									// 高斯滤波
{
	Mat srcImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);
	GaussianBlur(srcImg, dstImg, Size(kernel_length, kernel_length), 0, 0);
	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Enhance::Median(QImage src, int kernel_length)									// 中值滤波
{
	Mat srcImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);	
	medianBlur(srcImg, dstImg, kernel_length);
	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Enhance::HoughLine(QImage src, int threshold, double minLineLength, double maxLineGap)			// 线检测
{
	Mat srcImg, dstImg, cdstPImg;
	srcImg = imgchangeClass->QImage2cvMat(src);

	cv::Canny(srcImg, dstImg, 50, 200, 3);                // Canny算子边缘检测
	if (srcImg.channels() != 1)
		cvtColor(dstImg, cdstPImg, COLOR_GRAY2BGR);        // 转换灰度图像
	else
		cdstPImg = srcImg;

	vector<Vec4i> linesP;
	HoughLinesP(dstImg, linesP, 1, CV_PI / 180, threshold, minLineLength, maxLineGap);// 50,50,10
	for (size_t i = 0; i < linesP.size(); i++)
	{
		Vec4i l = linesP[i];
		line(cdstPImg, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, LINE_AA);
	}

	QImage dst = imgchangeClass->cvMat2QImage(cdstPImg);
	return dst;

}

QImage Enhance::HoughCircle(QImage src, int minRadius, int maxRadius)		// 圆检测
{
	Mat srcImg, dstImg;
	srcImg = imgchangeClass->QImage2cvMat(src);

	Mat gray;
	if (srcImg.channels() != 1)
		cvtColor(srcImg, gray, COLOR_BGR2GRAY);
	else
		gray = srcImg;
	medianBlur(gray, gray, 5);              // 中值滤波，滤除噪声，避免错误检测

	vector<Vec3f> circles;
	HoughCircles(gray, circles, HOUGH_GRADIENT, 1, gray.rows / 16, 100, 30, minRadius, maxRadius); // Hough圆检测,100, 30, 1, 30
	dstImg = srcImg.clone();

	for (size_t i = 0; i < circles.size(); i++)
	{
		Vec3i c = circles[i];
		Point center = Point(c[0], c[1]);
		circle(dstImg, center, 1, Scalar(0, 100, 100), 3, LINE_AA);                    // 画圆
		int radius = c[2];
		circle(dstImg, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
	}

	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Enhance::Sobel(QImage src, int kernel_length)							// sobel
{
	Mat srcImg, dstImg, src_gray;
	srcImg = imgchangeClass->QImage2cvMat(src);

	GaussianBlur(srcImg, srcImg, Size(3, 3), 0, 0, BORDER_DEFAULT);     // 高斯模糊
	if (srcImg.channels() != 1)
		cvtColor(srcImg, src_gray, COLOR_BGR2GRAY);                        // 转换灰度图像
	else
		src_gray = srcImg;

	Mat grad_x, grad_y, abs_grad_x, abs_grad_y;

	cv::Sobel(src_gray, grad_x, CV_16S, 1, 0, kernel_length, 1, 0, BORDER_DEFAULT);
	cv::Sobel(src_gray, grad_y, CV_16S, 0, 1, kernel_length, 1, 0, BORDER_DEFAULT);

	convertScaleAbs(grad_x, abs_grad_x);            // 缩放，计算绝对值，并将结果转换为8位
	convertScaleAbs(grad_y, abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dstImg);

	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Enhance::Laplacian(QImage src, int kernel_length)						// laplacian
{
	Mat srcImg, dstImg, src_gray;
	srcImg = imgchangeClass->QImage2cvMat(src);

	GaussianBlur(srcImg, srcImg, Size(3, 3), 0, 0, BORDER_DEFAULT);       // 高斯模糊

	if (srcImg.channels() != 1)
		cvtColor(srcImg, src_gray, COLOR_BGR2GRAY);                        // 转换灰度图像
	else
		src_gray = srcImg;

	Mat abs_dst;                                                    // 拉普拉斯二阶导数
	cv::Laplacian(src_gray, dstImg, CV_16S, kernel_length, 1, 0, BORDER_DEFAULT);

	convertScaleAbs(dstImg, dstImg);                                  // 绝对值8位
	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}

QImage Enhance::Canny(QImage src, int kernel_length ,int lowThreshold)							// canny
{
	Mat srcImg, dstImg, src_gray, detected_edges;
	srcImg = imgchangeClass->QImage2cvMat(src);

	dstImg.create(srcImg.size(), srcImg.type());
	if (srcImg.channels() != 1)
		cvtColor(srcImg, src_gray, COLOR_BGR2GRAY);                        // 转换灰度图像
	else
		src_gray = srcImg;
	blur(src_gray, detected_edges, Size(3, 3));     // 平均滤波平滑
	cv::Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * 3, kernel_length);
	dstImg = Scalar::all(0);
	srcImg.copyTo(dstImg, detected_edges);

	QImage dst = imgchangeClass->cvMat2QImage(dstImg);
	return dst;
}
