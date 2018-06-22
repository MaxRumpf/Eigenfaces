//
//  photometrics.cpp
//  eigenfaces_v1
//
//  Created by Max Rumpf on 22.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#include "photometrics.hpp"
#include "settings.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace photometrics {
    cv::Mat downscalify_and_grayscalify(cv::Mat picture) {
        cv::Mat picture_gray;
        cv::Mat picture_gray_downscaled;
        cv::Size downscaled_size = cv::Size(PIC_SIZE,PIC_SIZE);
        cv::cvtColor(picture, picture_gray, CV_BGR2GRAY);
        cv::resize(picture_gray, picture_gray_downscaled, downscaled_size);
        return picture_gray_downscaled;
    }
}
