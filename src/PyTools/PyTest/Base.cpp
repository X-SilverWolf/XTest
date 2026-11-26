/**
 *------------------------------------------------------------------------------
 * @file        Base
 * @brief       Registers the addition example in the Python extension module.
 * @details     Declares pymodule through pybind11 and exposes the native add function to Python
 *              callers.
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
 *    - Bound the integer addition function to pymodule.add.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#include "Base.h"
#include <pybind11/pybind11.h>

int add(int a, int b)
{
    return a + b;
}

PYBIND11_MODULE(pymodule, m)
{
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
}