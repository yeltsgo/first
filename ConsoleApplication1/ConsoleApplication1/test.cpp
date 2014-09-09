#include <opencv2\opencv.hpp>  
#include<iostream>
using namespace cv;
void main()
{
	//��ȡ��һ������ͷ
	CvCapture* capture;
	capture=cvCreateCameraCapture(0);
	assert(capture!=NULL);
	
	IplImage* frame;//������ͼ��
	cvNamedWindow("camera",1);//��������Ϊcamera�Ĵ��ڡ�
	while(1)
	{
		
		frame=cvQueryFrame(capture);//������ͷ��ץȡ������һ֡
		if(!frame)
			break;
		cvShowImage("camera",frame);//��camera�Ĵ�������ʾframeͼ��
		
		if(cvWaitKey(32)>=0)
		   break;
	}
	cvReleaseImage(&frame);//�ͷŸղ�����ͼ����ڴ�ռ�
	cvDestroyWindow("camera");//����������Ϊcamera�Ĵ��ڡ�

}