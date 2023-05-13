.. rsp-final-project documentation master file, created by
   sphinx-quickstart on Sat Apr 29 15:15:50 2023.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

.. note::
  This project is under active development.

Welcome to rsp-final-project's documentation!
=============================================

.. toctree::
   :maxdepth: 4
   :hidden:
   :caption: Packages:
   :glob:

   robot/index
   oct/index

..
   Indices and tables
   ==================

   * :ref:`genindex`
   * :ref:`modindex`
   * :ref:`search`

Getting Started
---------------

1. Create a new workspace ``mkdir -p <workspace_dir>/src``
2. ``cd <workspace_dir>/src``
3. Clone the git repo ``git clone  https://github.com/jdcast/rsp-final-project.git``
4. Add required repos ``vcs import --recursive < rsp-final-project/galactic.repos``
5. ``cd ..``
6. Install dependencies ``rosdep -v install --from-paths src/rsp-final-project/ -y --ignore-src --skip-key="orocos_toolchain orocos_kdl rtt_ros2_services rtt_ros2_sensor_msgs rtt_ros2_std_msgs rtt_ros2_geometry_msgs rtt_ros2_topics rtt_ros2_params rtt_ros2_node rtt_ros2 kdl_typekit reflexxestype2 robot_joint_publisher_gui"``
7. Build `orocos_toolchain` ``colcon build --packages-select orocos_toolchain``
8. ``source install/setup.bash``
9. ``sudo apt install ros-galactic-moveit-common && sudo apt install ros-galactic-moveit && sudo apt install ros-galactic-moveit-servo``
10. Build everything else ``colcon build --executor sequential``
11. ``source install/setup.bash``
12. ``rsp_rtt``

   * NOTE: `rsp_rtt` should be defined in the ``.bashrc`` as: ``alias rsp_rtt='export RTT_COMPONENT_PATH=$COLCON_PREFIX_PATH/kdl_typekit/lib/orocos:
     $COLCON_PREFIX_PATH/orocos_toolchain/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2_builtin_interfaces/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2_geometry_msgs/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2_interfaces/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_node/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2_params/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2_primitives_typekit/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2_rclcpp_typekit/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2_std_msgs/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2_topics/lib/orocos:
     $COLCON_PREFIX_PATH/rsp_week07/lib/orocos:$COLCON_PREFIX_PATH/rtt_ur_trajectory/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2_sensor_msgs/lib/orocos:
     $COLCON_PREFIX_PATH/rtt_ros2_services/lib/orocos'``

13. Start complete robot simulation (rviz and gazebo) ``ros2 launch robot robot.launch.xml``

To see more details about a specific package, click on the links on the side!
