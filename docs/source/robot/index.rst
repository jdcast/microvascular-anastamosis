Robot
=====

.. note::
  This page is under active development.

Run Example
-----------

1. ``ros2 launch robot robot.launch.xml``
2. In rviz, change fixed frame to `oct_link`
3. In gazebo, move model `vessel` over tool-tip.
   LaserScans will display in rviz in two different colors that represent each lidar sensor composing the OCT sensor, respectively.
   Each lidar sensor responds to a different part of the `vessel` i.e. one lidar responds to the smaller cylinder only while the other responds to only the larger cylinder.

