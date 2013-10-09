#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main( int argc, char** argv )
{
  
  Mat img_hsv,img_rgb,img_mask;

  img_rgb = imread( argv[1], 1 );

 	

    if( argc != 2 || !img_rgb.data )
    {
      printf( "No image data \n" );
      return -1;
    }

	cv::cvtColor(img_rgb,img_hsv,CV_RGB2HSV);
	cv::inRange(img_hsv,cv::Scalar(155,0,0),cv::Scalar(255,130,130),img_mask);

	namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
	imshow( "Display Image", img_mask );

  	waitKey(0);

  	return 0;
}
