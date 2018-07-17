#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/opencv.hpp"    
#include <opencv2/core/core.hpp> 
#include "header/Geom.h"

using namespace cv;

Geom::Geom()
{
	imgchangeClass = new ImgChange;
}

Geom::~Geom()
{
}

QImage Geom::Resize(QImage src, int length, int width)		// 改变大小
{
	Mat matSrc, matDst;
	matSrc = imgchangeClass->QImage2cvMat(src);
	resize(matSrc, matDst, Size(length, width), 0, 0, INTER_LINEAR);// 线性插值
	QImage dst = imgchangeClass->cvMat2QImage(matDst);
	return dst;
}

QImage Geom::Enlarge_Reduce(QImage src, int times)			// 缩放
{
	Mat matSrc, matDst;
	matSrc = imgchangeClass->QImage2cvMat(src);
	if (times > 0)
	{
		resize(matSrc, matDst, Size(matSrc.cols * abs(times+1), matSrc.rows * abs(times+1)), 0, 0, INTER_LINEAR);
		QImage dst = imgchangeClass->cvMat2QImage(matDst);
		return dst;
	}
	else if (times < 0)
	{		
		resize(matSrc, matDst, Size(matSrc.cols / abs(times-1), matSrc.rows / abs(times-1)), 0, 0, INTER_AREA);
		QImage dst = imgchangeClass->cvMat2QImage(matDst);
		return dst;
	}
	else
	{
		return src;
	}
}

QImage Geom::Rotate(QImage src, int angle)							// 旋转
{
	Mat matSrc, matDst,M;
	matSrc = imgchangeClass->QImage2cvMat(src);
	cv::Point2f center(matSrc.cols / 2, matSrc.rows / 2);
	cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1);
	cv::Rect bbox = cv::RotatedRect(center, matSrc.size(), angle).boundingRect();

	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	cv::warpAffine(matSrc, matDst, rot, bbox.size());
	QImage dst = imgchangeClass->cvMat2QImage(matDst);
	return dst;
}

QImage Geom::Rotate_fixed(QImage src, int angle)					// 旋转90，180，270
{
	Mat matSrc, matDst, M;
	matSrc = imgchangeClass->QImage2cvMat(src);
	M = getRotationMatrix2D(Point2i(matSrc.cols / 2, matSrc.rows / 2), angle, 1);
	warpAffine(matSrc, matDst, M, Size(matSrc.cols, matSrc.rows));
	QImage dst = imgchangeClass->cvMat2QImage(matDst);
	return dst;
}

QImage Geom::Flip(QImage src, int flipcode)							// 镜像
{
	Mat matSrc, matDst;
	matSrc = imgchangeClass->QImage2cvMat(src);
	flip(matSrc, matDst, flipcode);			// flipCode==0 垂直翻转（沿X轴翻转）,flipCode>0 水平翻转（沿Y轴翻转）
											// flipCode<0 水平垂直翻转（先沿X轴翻转，再沿Y轴翻转，等价于旋转180°）
	QImage dst = imgchangeClass->cvMat2QImage(matDst);
	return dst;
}

QImage Geom::Lean(QImage src, int x, int y)						// 倾斜
{
	Mat matSrc, matTmp, matDst;
	matSrc = imgchangeClass->QImage2cvMat(src);
	matTmp = Mat::zeros(matSrc.rows, matSrc.cols, matSrc.type());

	Mat map_x, map_y;
	Point2f src_point[3], tmp_point[3], x_point[3], y_point[3];
	double angleX = x / 180.0 * CV_PI ;
	double angleY = y / 180.0 * CV_PI;

	src_point[0] = Point2f(0, 0);	
	src_point[1] = Point2f(matSrc.cols, 0);
	src_point[2] = Point2f(0, matSrc.rows);

	x_point[0] = Point2f(matSrc.rows * tan(angleX), 0);
	x_point[1] = Point2f(matSrc.cols + matSrc.rows * tan(angleX), 0);
	x_point[2] = Point2f(0, matSrc.rows);
	
	map_x = getAffineTransform(src_point, x_point);
	warpAffine(matSrc, matTmp, map_x, Size(matSrc.cols + matSrc.rows * tan(angleX), matSrc.rows));

	tmp_point[0] = Point2f(0, 0);
	tmp_point[1] = Point2f(matTmp.cols, 0);
	tmp_point[2] = Point2f(0, matTmp.rows);

	y_point[0] = Point2f(0, 0);
	y_point[1] = Point2f(matTmp.cols, matTmp.cols * tan(angleY));
	y_point[2] = Point2f(0, matTmp.rows);

	map_y = getAffineTransform(tmp_point, y_point);
	warpAffine(matTmp, matDst, map_y, Size(matTmp.cols, matTmp.rows + matTmp.cols * tan(angleY)));

	QImage dst = imgchangeClass->cvMat2QImage(matDst);
	return dst;
}

// 平移
//Mat t_mat = cv::Mat::zeros(2, 3, CV_32FC1);
//Size size = Size(matSrc.cols + x, matSrc.rows + y);
//t_mat.at<float>(0, 0) = 1;
//t_mat.at<float>(0, 2) = x; //水平平移量  
//t_mat.at<float>(1, 1) = 1;
//t_mat.at<float>(1, 2) = y; //竖直平移量  								 
//cv::warpAffine(matSrc, matDst, t_mat, size);//根据平移矩阵进行仿射变换 