if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.28)
    project(Tests VERSION 1.0.0 LANGUAGES C CXX)
    include("${CMAKE_CURRENT_LIST_DIR}/cmake/Standalone.cmake")
    x_enable_business_releases()
    include("${CMAKE_CURRENT_LIST_DIR}/cmake/Dependencies.cmake")
endif()

# The demo queries devices through the host-side CUDA runtime API.
add_executable(Tests "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/CudaTest.h")
target_compile_features(Tests PRIVATE cxx_std_23)
target_link_libraries(Tests PRIVATE X::OpenGL glfw CUDA::cudart)
x_link_google_test(Tests OWN_MAIN)
if(x_workspace_cudart_dll)
    add_custom_command(TARGET Tests POST_BUILD COMMAND "${CMAKE_COMMAND}" -E
        copy_if_different "${x_workspace_cudart_dll}" "$<TARGET_FILE_DIR:Tests>" VERBATIM)
endif()
