//
//  capture.hpp
//  eigenfaces_v1
//
//  Created by Max Rumpf on 16.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#ifndef capture_hpp
#define capture_hpp

#include "capture.hpp"
#include <vector>
#include "../matrix/matrix.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace capture {
    using namespace std;
    typedef uchar PIXEL_NUM_TYPE;
    cv::Mat capture_webcam_pic();
    m::MATRIX_T cv_mat_to_matrix(cv::Mat mat);
    void test();
}
#endif /* capture_hpp */
