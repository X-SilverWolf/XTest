/**
 *------------------------------------------------------------------------------
 * @file        main
 * @brief       Runs the XGui window example with XBasic logging.
 * @details     Creates a 1024-by-768 window, enters the main loop and shuts down logging after
 *              the loop ends.
 *
 * @author      XSilver
 * @date        2026/5/26
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
 *  [3cbf04e] - 2026/6/7 by 骇客速成计划
 *    - Added a console example for the XBasic log timestamp type.
 *  [1703129] - 2026/11/26 by 骇客速成计划
 *    - Switched window includes to XGui and derived the log path from the working directory.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 *    - Use XBasic's deployed log directory and honor explicit logging overrides.
 *  [V1.0.0] - 2026/11/27 by XSilver
 *    - Validate the deployed logging settings before opening the test window.
 * ------------------------------------------------------------------------------
 */

#include "XBasic/XLog.h"
#if __has_include("XBasic/XLog/LogOptions.h")
#include <iostream>
#include "XBasic/Config/Config.h"
#include "XBasic/XLog/LogOptions.h"
#endif
#include "XGui/App/AppBase.h"
#include "XGui/App/GLWindow.h"
#include "XGui/App/MainLoop.h"
#include "XBasic/EventSystem/Event.h"


int main(int argc, char** argv) {

#if __has_include("XBasic/XLog/LogOptions.h")
    xbasic::xlog::LogOptions options;
    xbasic::ConfigError configError;
    if (!options.loadDefault(configError))
    {
        std::cerr << configError.describe() << '\n';
        return 1;
    }
    std::error_code error;
    if (!xbasic::xlog::InitLogging(argv[0], options, error))
    {
        std::cerr << "Could not initialize logging: " << error.message() << '\n';
        return 1;
    }
#else
    // Standalone builds may still use a published SDK that predates LogOptions.
    xbasic::xlog::InitLogging(argv[0]);
#endif
    xbasic::GLWindowSettings settings;
    settings.setSize(1024, 768);
    settings.windowMode = xbasic::eWindowMode_Window;
    std::shared_ptr<xbasic::MainLoop> mainLoop = std::shared_ptr<xbasic::MainLoop>(new xbasic::MainLoop);
    auto window = mainLoop->createWindow(settings);
    mainLoop->run(window, std::make_shared<xbasic::AppBase>());
    mainLoop->loop();
    xbasic::xlog::ShutdownLogging();

    return 0;
}
