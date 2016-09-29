// InvertColor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "highgui.h"

int main(int argc, char* argv[])
{
	//IplImage* pFrame = NULL; //声明IplImage指针
	cvNamedWindow("video", 1);
    CvCapture* pCapture =cvCaptureFromAVI("D://Hugo.avi");
	/*
	if( argc == 1 || (argc == 2 && strlen(argv[1]) == 1 && isdigit(argv[1][0])))
		pCapture = cvCaptureFromCAM( argc == 2 ? argv[1][0] - '0' : 0 );
	else if( argc == 2 ) 		
		pCapture = cvCaptureFromAVI( argv[1] ); 
*/
	if( !pCapture ) //打开视频文件
	{
		fprintf(stderr,"Could not initialize capturing...\n");
		return -1;
	}
	int numFrames=(int) cvGetCaptureProperty(pCapture,CV_CAP_PROP_FRAME_COUNT);
    //获取当前帧的宽度
    int frameW=(int) cvGetCaptureProperty(pCapture,CV_CAP_PROP_FRAME_WIDTH);
    //获取高度、帧率等等
	int frameH=(int) cvGetCaptureProperty(pCapture,CV_CAP_PROP_FRAME_HEIGHT);

	//逐帧读取视频
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
		
		cvShowImage("video", pFrame); //显示图像
		//如果有按键事件，则跳出循环
		if( cvWaitKey(2) >= 0 )		
			break;
			
		cvShowImage("video", pFrame); //显示图像
	}
	*/
	cvShowImage("video", pFrame); //显示图像

	cvDestroyWindow("video"); //销毁窗口
    cvReleaseCapture(&pCapture);
	return 0;
}

