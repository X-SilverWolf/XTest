/**
 *------------------------------------------------------------------------------
 * @file        LoggerDefines
 * @brief       Defines logging configuration types for the logging-system prototype.
 * @details     Describes severity, target masks, rolling policies and sink settings shared by
 *              the logger API.
 *
 * @author      76426
 * @date        2025/11/10
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
 *    - Added severity, destination and file-rotation configuration types.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#ifndef XTEST_LOGGER_DEFINES_H
#define XTEST_LOGGER_DEFINES_H

#include <string>

namespace LoggerSystem
{
    //Define Log Lever
    enum class LogLevel : int8_t
    {
        LOG_TRACE = 0,
        LOG_DEBUG = 1,
        LOG_INFO = 2,
        LOG_WARN = 3,
        LOG_ERROR = 4,
        LOG_CRITICAL = 5,
        LOG_OFF = 6
    };

    //Log Output Target
    enum class OutputTarget
    {
        CONSOLE = 0x01,
        FILE = 0x02,
        NETWORK = 0x04,
        ALL = CONSOLE | FILE | NETWORK
    };

    enum class FileRollingPolicy
    {
        NONE,           //  NO Rolling
        DAILY,
        HOURLY,
        SIZE_BASED,
        SIZE_AND_TIME
    };

    // The module of log define
    struct LogModule {
        std::string name;
        LogLevel level;
        bool enabled;

        LogModule(const std::string& n, LogLevel l = LogLevel::LOG_INFO, bool e = true)
                : name(n), level(l), enabled(e) {}
    };


    struct LoggerConfig
    {
        // Base Config
        std::string name{"default"};
        LogLevel level{LogLevel::LOG_INFO};
        OutputTarget targets{OutputTarget::CONSOLE};

        // Form
        std::string pattern{"[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%n] [%s:%#] %v"};
        bool enable_color{true};

        // File Config
        std::string file_path{"logs/app.log"};
        FileRollingPolicy file_policy{FileRollingPolicy::SIZE_BASED};
        size_t max_file_size{100 * 1024 * 1024}; // 100MB
        size_t max_files{10};
        std::string file_extension{".log"};

        bool async_mode{true};
        size_t queue_size{8192};
        uint32_t flush_interval{3}; // seconds

        // 高级配置
        bool flush_on_error{true};
        bool auto_create_dir{true};
        bool truncate_file{false};
    };

    struct NetworkConfig
    {
        std::string host;
        uint16_t port;
        std::string endpoint;
        int timeout_sec{5};
    };
}


#endif //XTEST_LOGGER_DEFINES_H
