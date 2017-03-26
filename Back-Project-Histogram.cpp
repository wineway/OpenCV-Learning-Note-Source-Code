//
//  calcHist.cpp
//  OpenCV
//
//  Created by WINEWAY on 2017/3/14.
//  Copyright © 2017年 WINEWAY. All rights reserved.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, const char * argv[]) {

    Mat image = imread("/Users/wineway/Desktop/ques/ques4.PNG");
    Mat dst(image.size().height,image.size().width,CV_8U);
    Mat img(512,256,CV_8UC3,Scalar(0));
    Mat image4(image(Rect(0,0,100,100)));
    MatND hist;
    imshow("output", image4);
    waitKey(0);

    int channels[] = {0,1,2};
    const int histSize[3] = {256,256,256};
    float rRange[] = {0,256};
    float gRange[] = {0,256};
    float bRange[] = {0,256};
    const float *ranges[] = {rRange,gRange,bRange};
    calcHist( &image4, 1, channels, Mat(), hist, 3, histSize, ranges);

    normalize(hist, hist, 1.0);

    calcBackProject(&image, 1, channels, hist, dst, ranges, 255.0);

    imshow("output", dst);
    waitKey(0);



    return 0;
}
