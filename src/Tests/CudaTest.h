/**
 *------------------------------------------------------------------------------
 * @file        CudaTest
 * @brief       Reports CUDA runtime and device information for the test program.
 * @details     Queries the runtime version and lists device names and compute capabilities,
 *              including API errors.
 *
 * @author      XSilver
 * @date        2026/1/9
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
 *    - Added CUDA runtime and device enumeration diagnostics.
 *  [1703129] - 2026/11/26 by 骇客速成计划
 *    - Guarded the example kernel so host C++ compilers can include the header.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#ifndef CUDA_TEST_H
#define CUDA_TEST_H

#include <cuda_runtime.h>
#include <iostream>

#ifdef __CUDACC__
__global__ void test_cuda_kernel()
{

}
#endif

void test_cuda()
{
    int runtimeVersion = 0;
    cudaError_t err = cudaRuntimeGetVersion(&runtimeVersion);
    if (err == cudaSuccess)
    {
        std::cout << "CUDA Runtime Version: " << runtimeVersion / 1000 << "." 
                  << (runtimeVersion % 100) / 10 << std::endl;
    }
    else
    {
        std::cout << "Failed to get CUDA runtime version: " 
                  << cudaGetErrorString(err) << std::endl;
        return;
    }

    int deviceCount = 0;
    err = cudaGetDeviceCount(&deviceCount);
    if (err != cudaSuccess)
    {
        std::cout << "Failed to get device count: " << cudaGetErrorString(err) << std::endl;
        return;
    }

    std::cout << "CUDA Device Count: " << deviceCount << std::endl;
    
    for (int i = 0; i < deviceCount; i++)
    {
        cudaDeviceProp deviceProp;
        err = cudaGetDeviceProperties(&deviceProp, i);
        if (err == cudaSuccess)
        {
            std::cout << "Device " << i << ": " << deviceProp.name 
                      << " (Compute Capability: " << deviceProp.major << "." 
                      << deviceProp.minor << ")" << std::endl;
        }
        else
        {
            std::cout << "Failed to get properties for device " << i << ": " 
                      << cudaGetErrorString(err) << std::endl;
        }
    }
    
}

#endif
