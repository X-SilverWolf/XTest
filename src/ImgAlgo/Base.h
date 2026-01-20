//
// Created by 76426 on 2025/10/29.
//

#ifndef IMGALGO_BASE_H
#define IMGALGO_BASE_H

#ifdef PLAT_LINUX

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
