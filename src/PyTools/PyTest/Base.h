//
// Created by 76426 on 2025/10/29.
//

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
