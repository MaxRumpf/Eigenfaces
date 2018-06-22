//
//  photometrics.hpp
//  eigenfaces_v1
//
//  Created by Max Rumpf on 22.06.18.
//  Copyright © 2018 Max Rumpf. All rights reserved.
//

#ifndef photometrics_hpp
#define photometrics_hpp
#include "constants.hpp"
#include <opencv2/core/core.hpp>

namespace photometrics {
    cv::Mat downscalify_and_grayscalify(cv::Mat picture);
}

#endif /* photometrics_hpp */
