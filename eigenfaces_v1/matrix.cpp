//
//  2d-vects.cpp
//  eigenfaces_v1
//
//  Created by Max Rumpf on 15.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#include "matrix.hpp"
#include "constants.hpp"
#include <vector>
#include <iostream>
using namespace std;
/*
 *  outer vect: horizontal  ->  rows
 */
namespace matrix {
    COORD_T rows(MATRIX_T *matrix) {
        return matrix->size();
    };
    COORD_T columns(MATRIX_T *matrix) {
        if(rows(matrix) == 0) {
            return 0;
        }
        return matrix->at(0).size();
    };
    NUM_T at(MATRIX_T *matrix, COORD_T row, COORD_T column) {
        assert(row <= rows(matrix) - 1);
        assert(column <= columns(matrix) - 1);
        return matrix->at(row).at(column);
    };
    vector<NUM_T> row(MATRIX_T *matrix, COORD_T row_num) {
        assert(row_num <= rows(matrix) - 1);
        return matrix->at(row_num);
    };
    vector<NUM_T> column(MATRIX_T *matrix, COORD_T column_num) {
        assert(column_num <= columns(matrix) - 1);
        vector<NUM_T> result;
        COORD_T num_rows = rows(matrix);
        for(COORD_T r=0;r<num_rows;r++) {
            int e = at(matrix, r, column_num);
            result.push_back(e);
        }
        return result;
    }
    void add_row(MATRIX_T *matrix, vector<NUM_T> new_row) {
        //incase rows already exist, number of items in new row must be same as number of columns
        if(rows(matrix)) assert(new_row.size() == columns(matrix));
        matrix->push_back(new_row);
    };
    void add_column(MATRIX_T *matrix, vector<NUM_T> column_data) {
        //by design of the matrix data type, in order to create a new column we have to add each element of new_column to end of each corresponding row vector
        COORD_T n = column_data.size();
        //check if any rows exist
        if(matrix->size() == 0) {
            //no rows exist, this means we need to create n rows each with their corresponding element
            for(COORD_T i=0;i<n;i++) {
                int e = column_data.at(i);
                vector<NUM_T> new_column;
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
    void print(MATRIX_T *matrix) {
        cout << "--------------------" << endl;
        for(COORD_T r=0;r<rows(matrix);r++) {
            cout << "[";
            for(COORD_T c=0;c<columns(matrix);c++) {
                int e = at(matrix, r, c);
                cout << e << " ";
            };
            cout << "]" << endl;
        };
        cout << "--------------------" << endl;
    };
    MATRIX_T multiply(MATRIX_T *A, MATRIX_T *B) {
        //check if A rows equals B columns
        COORD_T A_ROWS=rows(A);
        COORD_T A_COLUMNS=columns(A);
        COORD_T B_ROWS=rows(B);
        COORD_T B_COLUMNS=columns(B);
        assert(A_COLUMNS==B_ROWS);
        MATRIX_T result;
        //iterate over all rows and columns of the resulting matrix
        //which will be of size A_rows x B_columns
        for(COORD_T ar=0;ar<A_ROWS;ar++){
            //create currently empty vect of int's which will be our resulting row
            vector<NUM_T> resulting_row;
            for(COORD_T bc=0;bc<B_COLUMNS;bc++) {
                int result = 0;
                //for every ar = bc in resulting matrix we multiply
                for(COORD_T acbr=0;acbr<A_COLUMNS;acbr++) {
                    result = result + (at(A, ar, acbr) * at(B, acbr, bc));
                }
                resulting_row.push_back(result);
            }
            result.push_back(resulting_row);
        }
        return result;
    };
    MATRIX_T concat(MATRIX_T *matrix) {
        MATRIX_T result;
        COORD_T num_rows = rows(matrix);
        vector<NUM_T> final_column;
        for(COORD_T r=0;r<num_rows;r++) {
            vector<NUM_T> curr_row = row(matrix, r);
            final_column.insert(final_column.end(), curr_row.begin(), curr_row.end());
        }
        add_column(&result, final_column);
        return result;
    }
}
