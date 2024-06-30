cmake_minimum_required(VERSION 3.16)
project(gui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(Qt5 COMPONENTS Core Quick Location REQUIRED)

include_directories(
  ${ament_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  ${Qt5Core_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
  ${Qt5Location_INCLUDE_DIRS}
)

# Include the Qt resource system
qt5_add_resources(QT_RESOURCES src/resources.qrc)

# Add your executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    ${QT_RESOURCES}
)

ament_target_dependencies(${PROJECT_NAME}
    rclcpp
    std_msgs
)

# Link Qt modules and ROS2 libraries
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Quick
    Qt5::Location
)

# Install the executable
install(TARGETS ${PROJECT_NAME}
    DESTINATION lib/${PROJECT_NAME}
)

# Install Python launch script
install(PROGRAMS
  launch/gui.launch.py
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
