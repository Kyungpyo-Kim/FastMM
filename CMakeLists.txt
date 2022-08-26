cmake_minimum_required(VERSION 3.14)
project(fast_mm)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)


#===============
#  Dependencies
#===============
find_package(OpenCV REQUIRED)
find_package (Eigen3 REQUIRED)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
include_directories( ${OpenCV_INCLUDE_DIRS} )


#==============
#  Build Setup
#==============
add_executable( fast_mm
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cc
)
target_link_libraries( fast_mm 
    ${OpenCV_LIBS}
    Eigen3::Eigen
)
