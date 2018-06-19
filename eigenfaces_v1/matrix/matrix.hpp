//
//  matrix.h
//  eigenfaces_v1
//
//  Created by Max Rumpf on 16.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <vector>
using namespace std;

namespace m {
    typedef unsigned int NUM_T;
    typedef vector<vector<NUM_T>> MATRIX_T;
    typedef unsigned long COORD_T;
    
    COORD_T rows(MATRIX_T *matrix);
    COORD_T columns(MATRIX_T *matrix);
    NUM_T at(MATRIX_T *matrix, COORD_T row, COORD_T column);
    vector<NUM_T> row(MATRIX_T *matrix, COORD_T row_num);
    vector<NUM_T> column(MATRIX_T *matrix, COORD_T column_num);
    void add_row(MATRIX_T *matrix, vector<NUM_T> new_row);
    void add_column(MATRIX_T *matrix, vector<NUM_T> column_data);
    void print(MATRIX_T *matrix);
    MATRIX_T multiply(MATRIX_T *A, vector<vector<int>> *B);
    MATRIX_T concat(MATRIX_T *matrix);
}

#endif /* matrix_hpp */
