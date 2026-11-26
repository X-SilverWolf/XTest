/**
 *------------------------------------------------------------------------------
 * @file        main
 * @brief       Exercises the XRunTime build-tool entry point.
 * @details     Constructs BuildTool and calls Init from a standalone test executable.
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
 *  [1fa8d01] - 2026/5/27 by 骇客速成计划
 *    - Added the runtime build-tool initialization smoke program.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#include <iostream>
#include <thread>

#include "XRunTime/BuildTool.h"

int main() {
  xRunTime::BuildTool build_tool;
  build_tool.Init();
  return 0;
}
