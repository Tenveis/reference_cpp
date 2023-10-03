cmake_minimum_required(VERSION 3.5)
project(reference_cpp)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED std_msgs)

#include '.h' files
include_directories(include)


add_executable(publish_node nodes/topic/publish_node.cpp src/topic/publish.cpp)
ament_target_dependencies(publish_node rclcpp std_msgs)

add_executable(subscribe_node nodes/topic/subscribe_node.cpp src/topic/subscribe.cpp)
ament_target_dependencies(subscribe_node rclcpp std_msgs)


install(TARGETS
publish_node
subscribe_node
DESTINATION lib/${PROJECT_NAME}
)

ament_package()
