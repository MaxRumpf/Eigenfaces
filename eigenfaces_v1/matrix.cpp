//
//  2d-vects.cpp
//  eigenfaces_v1
//
//  Created by Max Rumpf on 15.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

/*
 *  outer vect: horizontal  ->  rows
 */

unsigned long matrix_rows(vector<vector<int>> *matrix) {
    return matrix->size();
};
unsigned long matrix_columns(vector<vector<int>> *matrix) {
    if(matrix_rows(matrix) == 0) {
        return 0;
    }
    return matrix->at(0).size();
};
int matrix_at(vector<vector<int>> *matrix, unsigned long row, unsigned long column) {
    assert(row <= matrix_rows(matrix));
    assert(column <= matrix_columns(matrix));
    return matrix->at(row).at(column);
}
void matrix_add_row(vector<vector<int>> *matrix, vector<int> new_row) {
    //incase rows already exist, number of items in new row must be same as number of columns
    if(matrix_rows(matrix)) assert(new_row.size() == matrix_columns(matrix));
    matrix->push_back(new_row);
};
void matrix_add_column(vector<vector<int>> *matrix, vector<int> column_data) {
    //by design of the matrix data type, in order to create a new column we have to add each element of new_column to end of each corresponding row vector
    unsigned long n = column_data.size();
    //check if any rows exist
    if(matrix->size() == 0) {
        //no rows exist, this means we need to create n rows each with their corresponding element
        for(unsigned long i=0;i<n;i++) {
            int e = column_data.at(i);
            vector<int> new_column;
            new_column.push_back(e);
            matrix->push_back(new_column);
        }
        return;
    }
    //check if matrix has same number of rows as new column has elements
    assert(matrix->size() == column_data.size());
    for(int i = 0; i<column_data.size();i++) {
        int e = column_data.at(i);
        matrix->at(i).push_back(e);
    }
};
void matrix_print(vector<vector<int>> *matrix) {
    cout << "--------------------" << endl;
    for(unsigned long r=0;r<matrix_rows(matrix);r++) {
        cout << "[";
        for(unsigned long c=0;c<matrix_columns(matrix);c++) {
            int e = matrix_at(matrix, r, c);
            cout << e << " ";
        };
        cout << "]" << endl;
    };
    cout << "--------------------" << endl;
};
void matrix_multiply(vector<vector<int>> *matrix1, vector<vector<int>> *matrix2) {
    
};
