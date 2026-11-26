/**
 *------------------------------------------------------------------------------
 * @file        log
 * @brief       Declares the logger wrapper used in the logging fixture.
 * @details     Exposes named initialization and holds the resulting spdlog logger in a shared
 *              pointer.
 *
 * @author      76426
 * @date        2025/11/8
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
 *  [81761c6] - 2026/1/9 by 骇客速成计划
 *    - Declared the logging fixture's lightweight logger wrapper.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#ifndef XTEST_LOG_H
#define XTEST_LOG_H

#include <spdlog/spdlog.h>

class logger {
public:
    logger();

    void initialize(std::string name = "");

private:
    std::shared_ptr<spdlog::logger> m_log;

};


#endif //XTEST_LOG_H
