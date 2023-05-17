.. rsp-final-project documentation master file, created by
   sphinx-quickstart on Sat Apr 29 15:15:50 2023.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

.. note::
  This project is under active development.

Welcome to `microvascular-anastamosis's <https://github.com/jdcast/microvascular-anastamosis>`_ documentation!
==============================================================================================================


.. toctree::
   :maxdepth: 1
   :hidden:
   :caption: Tutorials:
   :glob:

   installation/index

.. toctree::
   :maxdepth: 5
   :hidden:
   :caption: Packages:
   :glob:

   suture-tool/index
   kuka/index
   maps/index
   oct/index
   robot/index
   ros2_img_to_bag_py/index

..
   Indices and tables
   ==================

   * :ref:`genindex`
   * :ref:`modindex`
   * :ref:`search`

The purpose of this project was to create ros packages for each component for an automoated microvascular anastamosis process.  This project makes use of a Kuka arm robot on which a suture tool is attached, a MAPs system - which autonomously rotates the blood vessel as required.  We also implemented a simulated OCT scanner using 2 lidar sensors.

In this documentation we go over the install instructions as well as how to load and run each individual package.

For the install instructions click on the `Installation` link on the side.

The project is made up of five packages: the suture tool, kuka robot, maps, oct and robot.  The robot packages combines that of the other four.  To see details about each package click on the package's link on the side.
