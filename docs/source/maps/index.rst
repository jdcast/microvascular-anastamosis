Maps
====

.. note::
  This page is under active development.




This package homes the details for maps.  To run just the `maps package` switch to the ``features/maps`` branch in your workspace using ``git checkout --track origin/features/maps``.

Package Structure
------------------

* maps_control

    (*future work*) will contain the control files for the maps.

* maps_description

    * launch

        `maps_bringup.launch`: contains launch file to start the `robot_state_publisher` for the maps.

        `maps_double.launch`: launches full maps system.

        `maps_double.launch`: launch half maps system.

    * meshes
    
        contains mesh files for the maps components.

    * urdf
        
        contains the URDF files for the maps system.

    * rviz
         
        contains the rviz config file.

* maps_gazebo

    * launch

        contains the launch file to start gazebo and rviz, adding the maps system.

        `maps_double_gazebo.launch`: launches the full maps system.

        `maps_single_gazebo.launch`: launches half the maps system.

    * worlds

        contains world file for gazebo.

Running the Suture Tool
------------------------

1. Build the packages ``colcon build``
2. ``source install/setup.bash``
3. Launch rviz and gazebo with the maps system ``ros2 launch maps_gazebo maps_double_gazebo.launch``

See below for example output.

.. list-table:: After: `ros2 launch maps_gazebo maps_double_gazebo.launch` 
   :widths: 50 50
   :header-rows: 1

   * - gazebo
     - rviz (with the Joint State Publisher gui)
   * - |suture-tool_gazebo.png|
     - |suture-tool_rviz.png|

It is possible to move the suture joints using the `Joint State Publisher` gui.

|tool_joints.png|




