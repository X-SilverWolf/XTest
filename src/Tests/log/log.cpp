/**
 *------------------------------------------------------------------------------
 * @file        log
 * @brief       Creates a named spdlog logger for the test fixture.
 * @details     Keeps the new logger in the fixture wrapper and initializes it with spdlog.
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
 *    - Implemented creation and initialization of a named logger.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#include "log.h"
logger::logger()
{

}

void logger::initialize(std::string name)
{
    spdlog::info("Create a logger, the log's name is {}",name.c_str());
    m_log = std::make_shared<spdlog::logger>(name);
    spdlog::initialize_logger(m_log);
}