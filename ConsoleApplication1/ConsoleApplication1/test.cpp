#include <opencv2\opencv.hpp>  
#include<iostream>
using namespace cv;
void main()
{
	IplImage *src;
	src = cvLoadImage("lena.jpg"); //这里将lena.jpg和lena.cpp文件放在同一个文件夹下
	cvNamedWindow("lena",CV_WINDOW_AUTOSIZE);
	cvShowImage("lena",src);
	cvWaitKey(0);
	cvDestroyWindow("lena");
	cvReleaseImage(&src);
}