#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>

class PaintWidget :public QLabel
{
	Q_OBJECT
public:
	explicit PaintWidget(QWidget *parent = 0);
	enum shape {
		Pen = 1,Line,Ellipse,Circle, Triangle, Rhombus, 
		Rect, Square, Hexagon, Null
	};
	void paint(QImage &theImage);
	void setImage(QImage img);
	QImage getImage(); // 外部获取图像

	void setShape(PaintWidget::shape ); 					// 设置绘制类型
	void setPenWidth(int w);								// 设置画笔宽度
	void setPenColor(QColor c);								// 设置画笔颜色

protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);

private:
	PaintWidget::shape type;
	int penWidth; 
	QColor penColor;
	QImage image;
	QImage tempImage;
	QPoint lastPoint;
	QPoint endPoint;
	bool isDrawing;
};

#endif// !PAINTWIDGET_H