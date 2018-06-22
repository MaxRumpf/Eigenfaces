//
//  matrix_cvmat_bridge.hpp
//  eigenfaces_v1
//
//  Created by Max Rumpf on 22.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#import "matrix.hpp"
#include "settings.hpp"
#import <opencv2/core/core.hpp>

#ifndef matrix_cvmat_bridge_hpp
#define matrix_cvmat_bridge_hpp

namespace matrix_cvmat {
    MATRIX_T mat_to_matrix(cv::Mat mat);
    cv::Mat matrix_to_mat(MATRIX_T *matrix);
}

#endif /* matrix_cvmat_bridge_hpp */
