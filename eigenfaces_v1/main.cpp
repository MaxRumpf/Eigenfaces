//
//  main.cpp
//  eigenfaces_v1
//
//  Created by Max Rumpf on 15.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#include "settings.hpp"
#include "matrix.hpp"
#include "capture.hpp"
#include "photometrics.hpp"
#include "matrix_cvmat_bridge.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cv::VideoCapture cap(0);
    cv::Mat img;
    cap.read(img);
    cv::imshow("original image", img);
    cv::Mat img2 = photometrics::downscalify_and_grayscalify(img);
    cv::imshow("img2", img2);
    MATRIX_T mat = matrix_cvmat::mat_to_matrix(img2);
    cv::Mat img3 = matrix_cvmat::matrix_to_mat(&mat);
    cv::imshow("img3", img3);
    cv::waitKey(0);
    return 0;
}
