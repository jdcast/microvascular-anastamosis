 ## Minimal gpu_lidar example for seletively sensing objects in gazebo

 -- terminal
 colcon build && source install/setup.bash && export COLCON_PREFIX_PATH=/home/nightrider/Documents/JHU/rsp/rsp_fp_ws/install && rsp_rtt && echo $COLCON_PREFIX_PATH && echo $RTT_COMPONENT_PATH

 -- terminal
 source install/setup.bash && export COLCON_PREFIX_PATH=/home/nightrider/Documents/JHU/rsp/rsp_fp_ws/install && rsp_rtt && echo $COLCON_PREFIX_PATH && echo $RTT_COMPONENT_PATH
 ign gazebo src/rsp-final-project/oct/oct_gazebo/worlds/oct.world.sdf -v 4
 
 -- terminal
 ign service -s /world/empty/create --reqtype ignition.msgs.EntityFactory --reptype ignition.msgs.Boolean --timeout 1000 --req 'sdf_filename: "/home/nightrider/Documents/JHU/rsp/rsp_fp_ws/src/rsp-final-project/oct/oct_description/urdf/camera.urdf", name: "camera"'
 ros2 run ros_ign_bridge parameter_bridge /sonar@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan

 -- terminal 
 ros2 run rviz2 rviz2 
 Add LaserScane and set topic to /sonar
 Then switch fixed frame to /left_tool -> robot model will be white and have errors, but the LaserScan will show up
 Proceed to move tower models in Gazebo -> Tower A is invisible to sensor while Tower B will show up
