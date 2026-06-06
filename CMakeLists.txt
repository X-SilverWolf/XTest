cmake_minimum_required(VERSION 3.15)

set(XTEST_VERSION 1.0.0)
#定义项目名称,设置项目版本为变量 指定项目语言为
project(XTest VERSION ${XTEST_VERSION})
#定义项目名称为 XTest
set(PROJECT_NAME_CAPITALIZED "XTest")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(XTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(cmake/Utility.cmake)
if(NOT X_SIGNER)
  include(cmake/XTestEnv.cmake)
  include(cmake/ManageThirdPartyLibrary.cmake)
endif()

set(GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/x64/GTest")
list(APPEND CMAKE_PREFIX_PATH ${GTEST_DIR})
find_package(GTest REQUIRED)

add_subdirectory(TBasic)
add_subdirectory(TRunTime)

#这是AddressSanitizer（ASan）的一部分，用于检测内存泄漏。
#在程序退出时，它会报告哪些内存块被分配了但没有被释放。
#if(WITH_CMAKE_LEAK)
#  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fasnitize=leak")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fasnitize=leak")
#endif ()
#if(WITH_CMAKE_ADDRESS)
#  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fasnitize=address")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fasnitize=address")
#endif ()
#一个调试相关的选项。它告诉编译器不要省略帧指针 编译器可能会省略帧指针以节省一个寄存器（通常用于提高性能）。
#if(WITH_CMAKE_POINIER)
#  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-omit-frame-pointer")
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
#endif ()

#set(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -Wno-psabi")
#set(CMAKE_CXX_FLAGS_DEBUG  "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -Wno-psabi")

#主程序构建
