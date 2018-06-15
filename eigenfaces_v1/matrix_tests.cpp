//
//  matrix_tests.cpp
//  eigenfaces_v1
//
//  Created by Max Rumpf on 15.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#include <stdio.h>
#include "main.cpp"

void test_general_functionality() {
    vector<vector<int>> *matrix = new vector<vector<int>>();
    matrix_add_row(matrix, vector<int>{1, 2, 3, 4, 5, 6, 7});
    matrix_add_row(matrix, vector<int>{5, 8, 4, 1, 5, 2, 6});
    matrix_add_column(matrix, vector<int>{8, 88});
    matrix_add_row(matrix, vector<int>{10, 20, 30, 40, 50, 60, 70, 80});
    cout << "at (0|0): " << matrix_at(matrix, 0, 0) << "." << endl;
    matrix_print(matrix);
}
void test() {
    
}
