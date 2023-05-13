Suture Tool
===========

.. note::
  This page is under active development.

To run just the `suture-tool package` switch to the ``feature/suture-tool`` branch in your workspace using ``git checkout --track origin/features/suture-tool``.

Package Structure
------------------

* suture_tool_control

    (*future work*) will contain the control files for the suture tool.

* suture_tool_description

    * launch

        contains launch file to start the `robot_state_publisher` for the suture tool

    * meshes
    
        contains mesh files for endo360 tool and circular needle.

    * urdf
        
        contains the URDF files for the suture tool (endo360).

* suture_tool_gazebo

    * config

        contains the rviz config file.

    * launch

        contains the launch file to start gazebo and rviz, adding the suture tool.

    * worlds

        contains world file for gazebo.

Running the Suture Tool
------------------------

1. Build the packages ``colcon build``
2. ``source install/setup.bash``
3. Launch rviz and gazebo with the suture tool ``ros2 launch suture_tool_gazebo suture_tool.launch``






