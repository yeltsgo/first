#include <opencv2\opencv.hpp>  
#include<iostream>
using namespace cv;
void main()
{
	//获取第一个摄像头
	CvCapture* capture;
	capture=cvCreateCameraCapture(0);
	assert(capture!=NULL);
	
	IplImage* frame;//待载入图像
	cvNamedWindow("camera",1);//创建名称为camera的窗口。
	while(1)
	{
		
		frame=cvQueryFrame(capture);//从摄像头中抓取并返回一帧
		if(!frame)
			break;
		cvShowImage("camera",frame);//在camera的窗口中显示frame图像
		
		if(cvWaitKey(32)>=0)
		   break;
	}
	cvReleaseImage(&frame);//释放刚才载入图像的内存空间
	cvDestroyWindow("camera");//用来销毁名为camera的窗口。

}