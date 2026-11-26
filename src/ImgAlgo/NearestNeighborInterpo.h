/**
 *------------------------------------------------------------------------------
 * @file        NearestNeighborInterpo
 * @brief       Declares the nearest-neighbor image scaling prototype.
 * @details     Accepts source and destination OpenCV matrices and per-axis scale factors. The
 *              body is a stub.
 *
 * @author      XSilver
 * @date        2026/1/21
 * @version     V1.0.0
 *
 * @copyright   Copyright (c) 2026 [XSilverWolf]
 *              This project is licensed under the MIT License.
 *              See the LICENSE file in the project root for license information.
 *              SPDX-License-Identifier: MIT
 *
 * ------------------------------------------------------------------------------
 *  REVISION HISTORY (Modify)
 * ------------------------------------------------------------------------------
 *  [6d8631d] - 2026/1/21 by XSilver
 *    - Added the nearest-neighbor interpolation prototype.
 *  [1703129] - 2026/11/26 by 骇客速成计划
 *    - Narrowed the OpenCV dependency to the matrix header.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#ifndef IMGALOG_NEAREST_NEIGHBOR_INTERPOLATION_H
#define IMGALOG_NEAREST_NEIGHBOR_INTERPOLATION_H

#include "Base.h"
#include <opencv2/core/mat.hpp>

namespace imgalgo
{

inline void nearest(cv::Mat& src, cv::Mat& dst, float sx, float sy)
{
    return;
}


}// imgalgo


#endif //IMGALOG_NEAREST_NEIGHBOR_INTERPOLATION_H
