//
//  capture.cpp
//  eigenfaces_v1
//
//  Created by Max Rumpf on 16.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#include "capture.hpp"
#include <vector>
#include <iostream>
#include "../matrix/matrix.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

//uniform resolution for all pictures we use
#define RESOLUTION 100
//define Pixel Value type to convert to here, should be same as m::NUM_T
typedef uchar PIXEL_NUM_TYPE;

namespace capture {
    cv::VideoCapture cap(0);
    cv::Mat transform_pic(cv::Mat input) {
        cv::Mat pic_gray;
        cv::Mat pic_gray_downscaled;
        cv::Size downscaled_size = cv::Size(RESOLUTION,RESOLUTION);
        cv::cvtColor(input, pic_gray, CV_BGR2GRAY);
        cv::resize(pic_gray, pic_gray_downscaled, downscaled_size);
        return pic_gray_downscaled;
    }
    cv::Mat capture_webcam_pic() {
        cv::Mat pic;
        cap.read(pic);
        return transform_pic(pic);
    }
    m::MATRIX_T cv_mat_to_matrix(cv::Mat mat) {
        int input_rows = mat.rows;
        int input_columns = mat.cols;
        m::MATRIX_T multi_row_matrix;
        for(int r=0;r<input_rows;r++) {
            vector<m::NUM_T> row;
            for(int c=0;c<input_columns;c++) {
                m::NUM_T num = mat.at<PIXEL_NUM_TYPE>(r, c);
                row.push_back(num);
            }
            m::add_row(&multi_row_matrix, row);
        }
        m::MATRIX_T single_dimension_matrix = m::concat(&multi_row_matrix);
        return single_dimension_matrix;
    }
    void test() {
        cv::Mat pic = capture_webcam_pic();
        m::MATRIX_T mat = cv_mat_to_matrix(pic);
        vector<m::MATRIX_T> pics;
        for(int i = 0;i<50;i++) {
            m::MATRIX_T pic = cv_mat_to_matrix(capture_webcam_pic());
            pics.push_back(pic);
        }
    }
}
