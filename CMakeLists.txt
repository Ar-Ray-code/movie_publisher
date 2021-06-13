cmake_minimum_required(VERSION 3.5)
project(movie_publisher)

set(CMAKE_CXX_STANDARD 14)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(image_transport REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(sensor_msgs REQUIRED)

## Set PATH

set(OpenCV_INCLUDE_DIRS)
set(OpenCV_LIB_DIR)

set(RCL_PKG
  rclcpp
  image_transport
  cv_bridge
  sensor_msgs
#  example_interfaces
)

include_directories(
  ${RECORD_BASE_INCLUDE}
  ${OpenCV_INCLUDE_DIRS}
)

## movie_pub -------------------------------

add_executable(movie_pub
  src/movie_publisher.cpp
  ${RECORD_BASE_API}
)

ament_target_dependencies(movie_pub ${RCL_PKG})

install(TARGETS
  movie_pub
  DESTINATION lib/${PROJECT_NAME}
)

#### ---------------------------------

# install(DIRECTORY
#   launch/
#   DESTINATION lib/${PROJECT_NAME}
# )

ament_package()
