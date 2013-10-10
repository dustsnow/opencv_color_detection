#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int LowerH = 0;
int LowerS = 0;
int LowerV = 0;
int UpperH = 180;
int UpperS = 256;
int UpperV = 256;

int main( int argc, char** argv )
{
 	namedWindow("Control");
	createTrackbar("LowerH","Control",&LowerH,180,NULL);
	createTrackbar("UpperH","Control",&UpperH,180,NULL);
	createTrackbar("LowerS","Control",&LowerS,256,NULL);
	createTrackbar("UpperS","Control",&UpperS,256,NULL);
	createTrackbar("LowerV","Control",&LowerV,256,NULL);
	createTrackbar("UpperV","Control",&UpperV,256,NULL);
 
  	Mat img_hsv,img_rgb,img_mask;
	while(1){
  	img_rgb = imread( argv[1], 1 );

    	if( !img_rgb.data )
    	{
    	  printf( "No image data \n" );
    	  return -1;
    	}

	cv::cvtColor(img_rgb,img_hsv,CV_BGR2GRAY);
	//cv::inRange(img_hsv,cv::Scalar(155,0,0),cv::Scalar(255,130,130),img_mask);
	cv::inRange(img_hsv,cv::Scalar(LowerH,LowerS,LowerV),cv::Scalar(UpperH,UpperS,UpperV),img_mask);
	std::cout << LowerH << std::endl;

	imshow( "Processed Image", img_mask );
	imshow( "Original Image", img_rgb);
  	waitKey(50);//Has to wait more than 0, otherwise the HSV Control panel doesn't work
	}
  	return 0;
}
