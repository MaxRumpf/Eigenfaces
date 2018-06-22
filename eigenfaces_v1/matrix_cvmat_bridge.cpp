//
//  matrix_cvmat_bridge.cpp
//  eigenfaces_v1
//
//  Created by Max Rumpf on 22.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#include "matrix_cvmat_bridge.hpp"
#include "settings.hpp"
#include "matrix.hpp"
#include "capture.cpp"
#include <opencv2/core/core.hpp>
namespace matrix_cvmat {
    MATRIX_T mat_to_matrix(cv::Mat mat) {
        int input_rows = mat.rows;
        int input_columns = mat.cols;
        MATRIX_T multi_row_matrix;
        for(int r=0;r<input_rows;r++) {
            vector<NUM_T> row;
            for(int c=0;c<input_columns;c++) {
                NUM_T num = mat.at<NUM_T>(r, c);
                row.push_back(num);
            }
            matrix::add_row(&multi_row_matrix, row);
        }
        MATRIX_T single_dimension_matrix = matrix::concat(&multi_row_matrix);
        return single_dimension_matrix;
    };
    cv::Mat matrix_to_mat(MATRIX_T *matrix) {
        vector<NUM_T> column = matrix::column(matrix, 0);
        cv::Mat output = cv::Mat(PIC_SIZE, PIC_SIZE, CV_8UC1);
        for(COORD_T r=0;r<PIC_SIZE;r++) {
            for(COORD_T c=0;c<PIC_SIZE;c++) {
                output.at<NUM_T>(r, c) = column.at(PIC_SIZE * r + c);
            }
        }
        return output;
    };
}
