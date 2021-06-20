project(Multi_SLAM_Forest)

cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE RELEASE)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}
    "/usr/include/eigen3")

set(dependency ${OpenCV_LIBS})

add_subdirectory(core)
add_subdirectory(test)