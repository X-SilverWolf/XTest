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
 * ------------------------------------------------------------------------------
 */

#include <filesystem>

#include "XBasic/XLog.h"
#include "XGui/App/AppBase.h"
#include "XGui/App/GLWindow.h"
#include "XGui/App/MainLoop.h"
#include "XBasic/EventSystem/Event.h"


int main(int argc, char** argv) {

    xbasic::xlog::InitLogging(argv[0]);
    xbasic::xlog::XFlags_log_dir = (std::filesystem::current_path() / "Log").string();
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
