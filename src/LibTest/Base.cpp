/**
 *------------------------------------------------------------------------------
 * @file        Base
 * @brief       Implements the LibTest integer-addition entry point.
 * @details     Returns the sum of the two inputs through the C linkage declared by the public
 *              header.
 *
 * @author      76426
 * @date        2025/10/29
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
 *    - Defined the integer addition symbol for the test library.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#include "Base.h"


int add(int a, int b)
{
    return a + b;
}