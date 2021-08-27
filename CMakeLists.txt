cmake_minimum_required(VERSION 3.19) #cmake 版本确定
project(cmake_opencv VERSION 1.0)               #project名确定


set(show_picture True)
set(use_addlibrary True)
configure_file (
        "${CMAKE_CURRENT_SOURCE_DIR}/config.h.in"       #需要自己编写
        "${CMAKE_CURRENT_SOURCE_DIR}/config.h"
)
option(showtopic "show picture" ON)
if(WIN32) #判断是否在win32上编译
    set(OpenCV_DIR D:\\opencv-4.5.3\\mingw) #确定opencv库位置，如果已经加入系统环境变量就不需要
    set(include_file ${CMAKE_SOURCE_DIR}/library/include ${CMAKE_SOURCE_DIR} )
elseif(UNIX)
    set(include_file ${CMAKE_SOURCE_DIR}/library/include)
endif()
find_package(OpenCV REQUIRED) #寻找opencv包
if(use_addlibrary)
    include_directories(${include_file} ${OpenCV_INCLUDE_DIRS})
    add_subdirectory(library) #通过路径寻找库
    message(STATUS ${include_file}) #信息输出
    add_executable(output_2 main.cpp)
    target_link_libraries(output_2 cv_library ${OpenCV_LIBS})#链接库
else(use_addlibrary)
    if(showtopic)
        include_directories(${OpenCV_INCLUDE_DIRS} ${include_file})     #寻找目录位置，并将目录包含进我们构建的目标
        file(GLOB_RECURSE source_files ${CMAKE_SOURCE_DIR}/library/src/*.?pp) #file操作，意为加入cpp文件进入source_files
        add_executable(output_2 main.cpp ${source_files})
    else(showtopic)
        add_executable(output_2 main.cpp)
    endif(showtopic)
    target_link_libraries(output_2 ${OpenCV_LIBS})
endif(use_addlibrary)



