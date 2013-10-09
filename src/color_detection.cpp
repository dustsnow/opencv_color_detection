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
	cv::inRange(img_hsv,cv::Scalar(0,0,0),cv::Scalar(0,255,255),img_mask);
	Mat dst, cdst;
	Canny(img_mask, dst, 50,200,3);
	cvtColor(dst,cdst,COLOR_GRAY2BGR);
	vector<Vec2f> lines;
    for( size_t i = 0; i < lines.size(); i++ )
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        line( cdst, pt1, pt2, Scalar(0,0,255), 3, CV_AA);
    }
	HoughLines(dst, lines, 1, CV_PI/180,160,0,0);
	namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
	imshow( "Display Image", img_mask);
	imshow( "Display Image 2", cdst);

  	waitKey(0);

  	return 0;
}
