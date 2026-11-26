/**
 *------------------------------------------------------------------------------
 * @file        Base
 * @brief       Defines import, export and calling-convention macros for ImgAlgo.
 * @details     Selects Windows DLL attributes or default symbol visibility for other supported
 *              platforms.
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
 *  [6d8631d] - 2026/1/21 by XSilver
 *    - Added symbol visibility and calling-convention macros for ImgAlgo.
 *  [1703129] - 2026/11/26 by 骇客速成计划
 *    - Selected the non-Windows visibility branch using the compiler's platform macro.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#ifndef IMGALGO_BASE_H
#define IMGALGO_BASE_H

#if !defined(_WIN32)

    #ifdef IMGALGO_BUILD_DLL
        #define IMGALGO_API __attribute__((visibility("default")))
    #else
        #define IMGALGO_API
    #endif
    #define IMGALGO_CALL
#else

#ifdef DMAI_API_SHARED
#define IMGALGO_API __declspec(dllexport)
#else
#define IMGALGO_API __declspec(dllimport)
#endif
#define IMGALGO_CALL __stdcall
#endif


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#endif //IMGALGO_BASE_H
