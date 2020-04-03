// 6_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:\\lena.jpg", 1);
	if (srcMat.empty()) return -1;

	float angel = -10.0, scale = 1;
	cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angel, scale);
	
	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());

	cv::imshow("src", srcMat);
	cv::imshow("dat", dstMat);
	cv::waitKey(0);
    return 0;
}

