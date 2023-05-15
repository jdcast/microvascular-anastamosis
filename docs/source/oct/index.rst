OCT
===

.. note::
  This page is under active development.

This package homes the details for the OCT system.  This package simulates an OCT imaging system.  To run just the `oct package` switch to the ``features/oct`` branch in your workspace using ``git checkout --track origin/features/oct``.

Package Structure
------------------

* oct_description

  * config

    contains the rviz config file.

  * launch

    contains the launch file to start the `robot_state_publisher` for the OCT system.

  * meshes

    contains the mesh files required for the OCT packages.

  * urdf

    contains the URDF files for the OCT system.

* oct_gazebo

    * config

      contains the the rviz config file.

    * launch
    
      contains the launch file to start gazebo and rviz, adding the oct system.

    * worlds
        
      contains the world files for gazebo.

* oct_plugin

  contains the gazebo plugin files for OCT sensor

Running the OCT
----------------

1. Build the packages ``colcon build``
2. ``source install/setup.bash``
3. Launch rviz and gazebo with the suture tool ``ros2 launch oct_gazebo oct.launch.xml``

See below for example output.







