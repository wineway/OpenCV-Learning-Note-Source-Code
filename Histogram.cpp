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

    Mat image4 = imread("/Users/wineway/Desktop/ques/ques4.PNG");
    Mat img(512,256,CV_8UC3,Scalar(0));

    MatND hist;
    int channels[] = {0,1,2};
    const int histSize[3] = {256,256,256};
    float rRange[] = {0,256};
    float gRange[] = {0,256};
    float bRange[] = {0,256};
    const float *ranges[] = {rRange,gRange,bRange};
    calcHist( &image4, 1, channels, Mat(), hist, 3, histSize, ranges);
    double tmp[3][255];
    for(int i = 0; i<256 ;i++)
        for(int j = 0; j<256 ;j++)
            for(int k = 0; k<256 ;k++){
                tmp[0][i] += hist.at<float>(k,j,i);
                tmp[1][i] += hist.at<float>(j,i,k);
                tmp[2][i] += hist.at<float>(i,k,j);

    }
    for (int i = 1; i<256; i+=1) {

        line(img, Point2f(i-1,tmp[1][i-1]/100), Point2f(i,tmp[1][i]/100),Scalar(0,255,0));
        line(img, Point2f(i-1,tmp[2][i-1]/100), Point2f(i,tmp[2][i]/100),Scalar(0,0,255));
        line(img, Point2f(i-1,tmp[0][i-1]/100), Point2f(i,tmp[0][i]/100),Scalar(255,0,0));

    }
    flip(img, img, 0);
    imshow("output", img);
    waitKey(0);



    return 0;
}
