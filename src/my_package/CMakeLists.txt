cmake_minimum_required(VERSION 3.8)
project(my_package)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Add an executable for my_node
add_executable(my_node src/my_node.cpp)
target_include_directories(my_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(my_node
  ${rclcpp_LIBRARIES}
)

# Install my_node executable to lib/${PROJECT_NAME}
install(TARGETS my_node
  DESTINATION lib/${PROJECT_NAME})

# Install Python launch script
install(PROGRAMS
  launch/my_package.launch.py
  DESTINATION share/${PROJECT_NAME})

ament_package()
