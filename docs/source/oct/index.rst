OCT
===

.. note::
  This page is under active development.

.. |oct_gazebo.png| image:: ../_static/images/oct/oct_gazebo.png
  :width: 100%
  :alt: gazebo after ros2 launch oct_gazebo oct.launch.xml

.. |oct_rviz.png| image:: ../_static/images/oct/oct_rviz.png
  :width: 100%
  :alt: rviz after ros2 launch oct_gazebo oct.launch.xml


This package homes the details for the OCT system.  This package simulates an OCT imaging system of a blood vessel by using two lidar sensors.  To run just the `oct package` switch to the ``features/oct`` branch in your workspace using ``git checkout --track origin/features/oct``.

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
4. In rviz, change the fixed frame from *world* to *oct_link*

You should see the sensor output in rviz.  The vessel in gazebo represents the blood vessel.  Each lidar sensor responds to a different part of the vessel - one lidar responds to the smaller cylinder *only*, while the other response to the larger cylinder *only*.

The below shows an example output.

.. list-table:: After: `ros2 launch oct_gazebo oct.launch.xml` 
   :widths: 50 50
   :header-rows: 1

   * - gazebo (showing simulates blood vessel)
     - rviz
   * - |oct_gazebo.png|
     - |oct_rviz.png|





