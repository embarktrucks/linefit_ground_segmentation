cmake_minimum_required(VERSION 2.8.3)
project(linefit_ground_segmentation)

find_program(CCACHE_FOUND ccache)
if (CCACHE_FOUND)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)


find_package(catkin COMPONENTS roscpp velodyne_pointcloud utils_point_cloud)

add_definitions(-std=c++11)

find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

include_directories(include ${catkin_INCLUDE_DIRS})

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
    )

add_library(${PROJECT_NAME} src/ground_segmentation.cc src/segment.cc src/bin.cc)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

#add_doxygen(NOT_AUTOMATIC)

#############
# QTCREATOR #
#############
FILE(GLOB_RECURSE LibFiles "include/*")
add_custom_target(${PROJECT_NAME}_headers SOURCES ${LibFiles})
