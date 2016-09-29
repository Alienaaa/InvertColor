// InvertColor.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "highgui.h"

int main(int argc, char* argv[])
{
	//IplImage* pFrame = NULL; //����IplImageָ��
	cvNamedWindow("video", 1);
    CvCapture* pCapture =cvCaptureFromAVI("D://Hugo.avi");
	/*
	if( argc == 1 || (argc == 2 && strlen(argv[1]) == 1 && isdigit(argv[1][0])))
		pCapture = cvCaptureFromCAM( argc == 2 ? argv[1][0] - '0' : 0 );
	else if( argc == 2 ) 		
		pCapture = cvCaptureFromAVI( argv[1] ); 
*/
	if( !pCapture ) //����Ƶ�ļ�
	{
		fprintf(stderr,"Could not initialize capturing...\n");
		return -1;
	}
	int numFrames=(int) cvGetCaptureProperty(pCapture,CV_CAP_PROP_FRAME_COUNT);
    //��ȡ��ǰ֡�Ŀ��
    int frameW=(int) cvGetCaptureProperty(pCapture,CV_CAP_PROP_FRAME_WIDTH);
    //��ȡ�߶ȡ�֡�ʵȵ�
	int frameH=(int) cvGetCaptureProperty(pCapture,CV_CAP_PROP_FRAME_HEIGHT);

	//��֡��ȡ��Ƶ
	IplImage* pFrame=cvQueryFrame(pCapture);
	if(!pFrame) {
    printf("could not grab a frame\n");
    return -1;
}
	/*
	while(pFrame =cvQueryFrame(pCapture))
	{
		for(int i=0;i<frameH;i++)
		{
			for(int k=0;k<frameW;k++)
			{
				for(int j=0;j<3;j++)
				{
					pFrame->imageData[i*frameW*3+j*3+k] = 
	               255- pFrame->imageData[i*frameW*3+j*3+k];

				}
			}
		}
		
		cvShowImage("video", pFrame); //��ʾͼ��
		//����а����¼���������ѭ��
		if( cvWaitKey(2) >= 0 )		
			break;
			
		cvShowImage("video", pFrame); //��ʾͼ��
	}
	*/
	cvShowImage("video", pFrame); //��ʾͼ��

	cvDestroyWindow("video"); //���ٴ���
    cvReleaseCapture(&pCapture);
	return 0;
}

