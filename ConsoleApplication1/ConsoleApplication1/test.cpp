#include <opencv2\opencv.hpp>  
#include<iostream>
using namespace cv;

IplImage *g_pGrayImage = NULL;
IplImage *g_pBinaryImage = NULL;

int g_pos = 0;

void on_trackbar(int pos)  
{
	g_pos = pos;
} 

void main()
{
	// ��ȡ��һ������ͷ
	CvCapture *capture;
	capture = cvCreateCameraCapture( 0 );
	assert( capture != NULL );

	 // ������ֵͼ����  
    cvNamedWindow( "��ֵ��", CV_WINDOW_AUTOSIZE );  

	// ������    
	int nThreshold = g_pos; 
    cvCreateTrackbar( "��ֵͼ��ֵ", "��ֵ��", &nThreshold, 254, on_trackbar );
	
	IplImage *frame; // ������ͼ��
	cvNamedWindow( "camera", 1 );// ��������Ϊcamera�Ĵ���
	while( 1 )
	{
		frame = cvQueryFrame( capture ); // ������ͷ��ץȡ������һ֡
		if( !frame )
		{
			break;
		}
		cvShowImage( "camera", frame ); // ��camera�Ĵ�������ʾframeͼ��

		// תΪ�Ҷ�ͼ  
		g_pGrayImage = cvCreateImage( cvGetSize( frame ), IPL_DEPTH_8U, 1 );  
		cvCvtColor( frame, g_pGrayImage, CV_BGR2GRAY );

		// ������ֵͼ
		g_pBinaryImage = cvCreateImage( cvGetSize( g_pGrayImage ), IPL_DEPTH_8U, 1 );
		// תΪ��ֵͼ  
        cvThreshold( g_pGrayImage, g_pBinaryImage, g_pos, 255, CV_THRESH_BINARY );
		cvShowImage( "��ֵ��", g_pBinaryImage );
  
		if( cvWaitKey( 32 ) >= 0 )
		{
			break;
		}
	}

	cvReleaseImage( &frame ); // �ͷŸղ�����ͼ����ڴ�ռ�
	cvReleaseImage( &g_pGrayImage );
    cvReleaseImage( &g_pBinaryImage );
	cvDestroyWindow( "camera" ); // ����������Ϊcamera�Ĵ��ڡ�
	cvDestroyWindow( "��ֵ��" );
}
