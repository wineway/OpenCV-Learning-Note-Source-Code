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

MatND histogram(Mat image4,int *channels, MatND hist, const int *histSize, const float **ranges);
int main(int argc, const char * argv[]) {

    Mat image4 = imread("/Users/wangyuwei/Desktop/ques/ques4.PNG",0);
    Mat img(256,256,CV_8U,Scalar(0));
    MatND hist;
    int channels[] = {0};
    const int histSize[] = {256};
    float rRange[] = {0,256};

    const float *ranges[] = {rRange};

    calcHist( &image4, 1, channels, Mat(), hist, 1, histSize, ranges);
     imshow("origin",histogram(image4, channels, hist, histSize, ranges));



    double p[256];
    Mat lut(1, 256, CV_8U);
    p[0] = hist.at<float>(0);
    for(int i = 0; i < 256; i++){
        p[i] = p[i-1] + hist.at<float>(i);

    }
    for(int i = 0; i < 256; i++){
        lut.at<uchar>(i) = p[i]/p[255]*255;
    }
    Mat dst(image4.size().height, image4.size().width, CV_8U);
    LUT(image4, lut, dst);
    imshow("convers", histogram(dst, channels, hist, histSize, ranges));
    waitKey(0);

    return 0;
}
MatND histogram(Mat image4,int *channels, MatND hist, const int *histSize, const float **ranges){
    Mat img(256,256,CV_8U,Scalar(0));


    calcHist( &image4, 1, channels, Mat(), hist, 1, histSize, ranges);

    for (int i = 1; i<256; i+=1) {

        line(img, Point2f(i-1,hist.at<float>(i-1)/100), Point2f(i,hist.at<float>(i)/100),Scalar(255));


    }
    flip(img, img, 0);

    return img;}
