cmake_minimum_required(VERSION 2.8.3)
project(movie_publisher)

## Compile as C++11, supported in ROS Kinetic and newer

## set Opencv library path

find_package(OpenCV REQUIRED)

set(OpenCV_INCLUDE_DIRS)
set(OpenCV_LIB_DIR)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(catkin REQUIRED COMPONENTS
    cv_bridge
    image_transport
    roscpp
    rospy
    sensor_msgs
    std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES webcam_publisher
#  CATKIN_DEPENDS cv_bridge image_transport roscpp rospy sensor_msgs std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/webcam_publisher.cpp
# )

add_executable(webcam_pub src/webcam_publisher.cpp)
add_executable(movie_pub src/movie_publisher.cpp)
add_executable(picture_pub src/picture_publisher.cpp)

target_link_libraries(webcam_pub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ${OpenCV_LIBS})
target_link_libraries(movie_pub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ${OpenCV_LIBS})
target_link_libraries(picture_pub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ${OpenCV_LIBS})