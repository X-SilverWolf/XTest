/**
 *------------------------------------------------------------------------------
 * @file        Base
 * @brief       Declares the native addition function used by the Python binding.
 * @details     Keeps its C linkage and shared-library visibility available to native callers of
 *              the example.
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
 *    - Added the native function declaration for the PyTest module.
 *  [1703129] - 2026/11/26 by 骇客速成计划
 *    - Aligned shared-library visibility with the Windows and non-Windows build flags.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#ifndef XVISION_BASE_H
#define XVISION_BASE_H

#if !defined(_WIN32)
#ifdef TEST_BUILD_DLL
#define TEST_API __attribute__((visibility("default")))
#else
#define TEST_API
#endif
#define TEST_CALL
#else
#if defined(TEST_BUILD_DLL) || defined(DMAI_API_SHARED)
#define TEST_API __declspec(dllexport)
#else
#define TEST_API __declspec(dllimport)
#endif
#define TEST_CALL __stdcall
#endif

// Expose the same entry point to C and C++ callers.
#ifdef __cplusplus
extern "C"
{
#endif
    TEST_API int add(int a, int b);
#ifdef __cplusplus
}
#endif

#endif // XVISION_BASE_H
