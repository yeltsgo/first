#include <opencv2\opencv.hpp>  
#include<iostream>
using namespace cv;
void main()
{
	IplImage *src;
	src = cvLoadImage("lena.jpg"); //���ｫlena.jpg��lena.cpp�ļ�����ͬһ���ļ�����
	cvNamedWindow("lena",CV_WINDOW_AUTOSIZE);
	cvShowImage("lena",src);
	cvWaitKey(0);
	cvDestroyWindow("lena");
	cvReleaseImage(&src);
}