if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.28)
    project(ImgAlgo VERSION 1.0.0 LANGUAGES C CXX)
    include("${CMAKE_CURRENT_LIST_DIR}/cmake/Standalone.cmake")
    x_enable_business_releases()
    include("${CMAKE_CURRENT_LIST_DIR}/cmake/Dependencies.cmake")
endif()

add_library(ImgAlgo INTERFACE)
add_library(X::ImgAlgo ALIAS ImgAlgo)
target_sources(ImgAlgo INTERFACE FILE_SET HEADERS BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}"
    FILES "${CMAKE_CURRENT_SOURCE_DIR}/Base.h" "${CMAKE_CURRENT_SOURCE_DIR}/NearestNeighborInterpo.h")
target_compile_features(ImgAlgo INTERFACE cxx_std_23)
target_link_libraries(ImgAlgo INTERFACE opencv_core)
