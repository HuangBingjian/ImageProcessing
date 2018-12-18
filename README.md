# ImageProcessing
图像处理自编软件 by 笔尖

C++  OpenCV  QT 
实现细节见：https://blog.csdn.net/u013165921/column/info/18269

界面
--
<center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/1.png"  width="100%"/>
<center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/2.png"  width="100%"/>

----------

工具栏、菜单栏
-------
  <center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/3.png"  width="50%"/>
  
&emsp;&emsp;文件工具栏中是常见的新建(new)、打开(open)、保存(save)、撤销(undo)、重做(redo)，实现方法将会在后续教程中给出。

&emsp;&emsp;绘图工具栏可以设置画笔的线宽及颜色，其中设置画笔颜色用的是QT自带的QColorDialog。

&emsp;&emsp;当载入的图像过大时，图像窗口虽然会出现滚动条，但是不方便查看，所以设置了“铺满窗口”和“自适应窗口”两个按钮，会根据窗口大小自动调节图像的显示效果。

&emsp;&emsp;一键换肤是切换QSS，默认的白色样式是setStyleSheet(0)即不加QSS，而黑色皮肤是采用Github中JetBrains Dracula设计的[QSS样式表](https://github.com/Kojoley/qss-dracula)，自己有稍作修改。

  <center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/4.png"  width="60%"/>

&emsp;&emsp;文件菜单是新建、打开、保存、另存为、关闭，有相应的快捷按键。

  <center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/5.png"  width="60%"/>

&emsp;&emsp;编辑菜单有撤销、重做、全屏显示和退出全屏。全屏显示是指没有标题栏即“图像处理自编软件 by 笔尖”那一栏，当切换为黑色皮肤时全屏显示更协调。

  <center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/6.png"  width="60%"/>

&emsp;&emsp;视图菜单监控各个窗口的状态——显示或隐藏。通过点击菜单可以切换窗口状态， 免得关闭窗口后不知从何找起。至于图像窗口，由于该软件只能处理单张图像，不支持同时对多张图像进行处理，所以图像窗口一直保持显示状态，如果隐藏那还怎么实时查看处理结果...
 
  <center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/7.png"  width="60%"/>

&emsp;&emsp;帮助窗口的话，就是软件的基本信息以及基本设置。

  <center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/8.png"  width="40%"/>
  <center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/9.png"  width="40%"/></center>

----------

功能窗口
----

<img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/10.png"  width="30%"/> <img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/11.png"  width="30%"/> <img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/12.png"  width="30%"/> 
<img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/13.png"  width="30%"/> <img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/14.png"  width="30%"/>

----------

其他窗口
----
  <center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/15.png"  width="10%"/>

&emsp;&emsp;工具箱里是简单的图形绘制工具，有钢笔、线条、圆形、椭圆、三角形、菱形、矩形、正方形、六边形。点击即可绘制，支持切换，再次点击同个按钮可以退出绘制模式。

  <center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/16.png"  width="50%"/>

&emsp;&emsp;输出窗口显示的是图像的操作记录，便于了解之前有哪些操作以及目前处于什么状态。
  <center><img src="https://github.com/HuangBingjian/ImageProcessing/blob/master/fig/17.png"  width="50%"/>

&emsp;&emsp;属性窗口是对输入图像的路径、长度、宽度、深度、是否灰度进行检测辨别，直观显示图像的基本信息。
