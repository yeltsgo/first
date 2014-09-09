#include <opencv2\opencv.hpp>  
#include<iostream>
using namespace cv;

IplImage *g_pGrayImage = NULL;  
IplImage *g_pBinaryImage = NULL;  
void on_trackbar(int pos)  
{  
    // 转为二值图  
    cvThreshold(g_pGrayImage, g_pBinaryImage, pos, 255, CV_THRESH_BINARY);  
    // 显示二值图  
    cvShowImage("二值化", g_pBinaryImage);  
} 

void main()
{
	//获取第一个摄像头
	CvCapture* capture;
	capture=cvCreateCameraCapture(0);
	assert(capture!=NULL);
	 // 创建二值图窗口  
    cvNamedWindow("二值化", CV_WINDOW_AUTOSIZE);  

	// 滑动条    
    int nThreshold = 0; 
    cvCreateTrackbar("二值图阈值", "二值化", &nThreshold, 254, on_trackbar);  
	

	IplImage* frame;//待载入图像
	cvNamedWindow("camera",1);//创建名称为camera的窗口。
	while(1)
	{
		
		frame=cvQueryFrame(capture);//从摄像头中抓取并返回一帧
		if(!frame)
			break;
		// 转为灰度图  
		g_pGrayImage =  cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);  
		cvCvtColor(frame, g_pGrayImage, CV_BGR2GRAY);  
		cvShowImage("camera",frame);//在camera的窗口中显示frame图像
		// 创建二值图  
		g_pBinaryImage = cvCreateImage(cvGetSize(g_pGrayImage), IPL_DEPTH_8U, 1);  
		
		on_trackbar(1); 
		 
  
		if(cvWaitKey(32)>=0)
		   break;
	}
	cvReleaseImage(&frame);//释放刚才载入图像的内存空间
	cvReleaseImage(&g_pGrayImage);  
    cvReleaseImage(&g_pBinaryImage); 
	cvDestroyWindow("camera");//用来销毁名为camera的窗口。
	cvDestroyWindow("二值化");

	
}
