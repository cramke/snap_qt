#!/usr/bin/env python3

import launch
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # Specify your package name and node executable
    package_name = "my_package"
    node_executable = "my_node"
    
    # Create a ROS 2 launch description object
    ld = LaunchDescription()

    # Add the ROS 2 node to the launch description
    node = Node(
        package=package_name,
        executable=node_executable,
        name=node_executable,
        output='screen'
    )
    ld.add_action(node)

    return ld

if __name__ == "__main__":
    generate_launch_description()
