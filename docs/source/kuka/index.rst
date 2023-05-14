Kuka
=====

.. |kuka_gazebo.png| image:: ../_static/images/kuka/kuka_gazebo.png
  :width: 100%
  :alt: gazebo after ros2 launch kuka_gazebo kuka_gazebo.launch.xml

.. |kuka_rviz.png| image:: ../_static/images/kuka/kuka_rviz.png
  :width: 100%
  :alt: rviz after ros2 launch kuka_gazebo kuka_gazebo.launch.xml

.. |kuka_joint_state.png| image:: ../_static/images/kuka/kuka_joint_state.png
  :width: 100%
  :alt: adjusting the kuka joints using the joint state publisher


.. note::
  This page is under active development.


This package homes the details for the kuka robot used in this project.  To run just the `kuka package` switch to the ``features/kuka`` branch in your workspace using ``git checkout --track origin/features/kuka``.

Package Structure
------------------

* kuka_control

    (*future work*) will contain the control files for the kuka.

* kuka_description

    * launch

        contains launch file to start the `robot_state_publisher` and `joint_state_publisher` for the kuka.

    * meshes
    
        contains mesh files for the kuka robot.

    * urdf
        
        contains the URDF files for the kuka robot.

* kuka_gazebo

    * launch

        contains the launch file to start gazebo and rviz, adding the kuka.

    * worlds

        contains world file for gazebo and the rviz config file.

Running the Kuka
----------------

1. Build the packages ``colcon build``
2. ``source install/setup.bash``
3. Launch rviz and gazebo with the kuka ``ros2 launch kuka_gazebo kuka_gazebo.launch.xml``

See below for example output.

.. list-table:: After: `ros2 launch kuka_gazebo kuka_gazebo.launch.xml` 
   :widths: 50 50
   :header-rows: 1

   * - gazebo
     - rviz
   * - |kuka_gazebo.png|
     - |kuka_rviz.png|

It is possible to move the kuka joints using the `Joint State Publisher` gui.

|kuka_joint_state.png|




