if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.28)
    project(TestTool VERSION 1.0.0 LANGUAGES CXX)
    include("${CMAKE_CURRENT_LIST_DIR}/cmake/Standalone.cmake")
    x_enable_business_releases()
endif()

include("${CMAKE_CURRENT_LIST_DIR}/cmake/Dependencies.cmake")
qt_add_executable(TestTool
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.ui")
set_target_properties(TestTool PROPERTIES AUTOMOC ON AUTOUIC ON WIN32_EXECUTABLE ON)
target_compile_features(TestTool PRIVATE cxx_std_23)
target_link_libraries(TestTool PRIVATE Qt6::Widgets)
if(COMMAND x_vscode_debug_environment)
    x_vscode_debug_environment(TestTool QT_WIDGETS)
endif()
if(MSVC)
    target_compile_options(TestTool PRIVATE /Zc:__cplusplus /permissive-)
endif()
