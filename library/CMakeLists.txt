cmake_minimum_required(VERSION 3.19) #cmake 版本确定
set(library_include ${CMAKE_CURRENT_SOURCE_DIR}/include/show_picture.h)
#include_directories(${OpenCV_INCLUDE_DIRS})
add_library(cv_library ${CMAKE_CURRENT_SOURCE_DIR}/src/show_picture.cpp)
