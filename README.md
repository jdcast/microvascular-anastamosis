# microvascular-anastamosis
RSP Final Project

## Installation

1. `mkdir -p <workspace_dir>/src`
2. `cd <workspace_dir>/src`
3. `git clone git@github.com:jdcast/rsp-final-project.git`
4. `vcs import --recursive < rsp-final-project/galactic.repos`
5. `cd ..`
6. `rosdep -v install --from-paths src/rsp-final-project/ -y --ignore-src --skip-key="orocos_toolchain orocos_kdl rtt_ros2_services rtt_ros2_sensor_msgs rtt_ros2_std_msgs rtt_ros2_geometry_msgs rtt_ros2_topics rtt_ros2_params rtt_ros2_node rtt_ros2 kdl_typekit reflexxestype2 robot_joint_publisher_gui ign_ros2_control ign_ros2_control_demos"`
7. `colcon build --packages-select orocos_toolchain`
8. `source install/setup.bash`
9. `sudo apt install ros-galactic-moveit-common && sudo apt install ros-galactic-moveit && sudo apt install ros-galactic-moveit-servo`
10. `export IGNITION_VERSION=fortress`
11. `colcon build && source install/setup.bash && export COLCON_PREFIX_PATH=<path_to_workspace_dir>/install && rsp_rtt && echo $COLCON_PREFIX_PATH && echo $RTT_COMPONENT_PATH`
    1. NOTE: make sure to replace *<workspace_dir>* with your workspace directory in the paths above
    2. NOTE: *rsp_rtt* should be defined in the `.bashrc` as: `alias rsp_rtt='export RTT_COMPONENT_PATH=$COLCON_PREFIX_PATH/kdl_typekit/lib/orocos:$COLCON_PREFIX_PATH/orocos_toolchain/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_builtin_interfaces/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_geometry_msgs/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_interfaces/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_node/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_params/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_primitives_typekit/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_rclcpp_typekit/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_std_msgs/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_topics/lib/orocos:$COLCON_PREFIX_PATH/rsp_week07/lib/orocos:$COLCON_PREFIX_PATH/rtt_ur_trajectory/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_sensor_msgs/lib/orocos:$COLCON_PREFIX_PATH/rtt_ros2_services/lib/orocos'`
12. `ros2 launch robot robot.launch.py`

## Updating if installed repository before vcs/rosdep 
1. `rm -rf install/ build/ log/`
2. *follow steps 1-10 above*

## Workflow
- `git checkout <branch_name>`
- `<do work>`
- `git add -A`
- `git commit -am "<descriptive commit message beginning with action verb>"`
- `git push`
- `form Pull Request (PR) in github`
- `await others to review`
- `merge PR into main`
- if further work on <branch_name> needs to be done after merging its PR into `main`: (let's not use `git rebase` to save possible headaches...https://stackoverflow.com/questions/3876977/update-git-branches-from-master)
  - `git checkout main`
  - `git pull` # update local main from remote main
  - `git checkout feature/<branch_name>`
  - `git merge main` # solve merge conflicts if you have
  - `git push`

## Documentation
- [Project Documenation Website](https://jdcast-microvascular-anastamosis.readthedocs.io/en/latest/)

### Documentation Tools
- [Read the Docs](https://docs.readthedocs.io/en/stable/tutorial/index.html#getting-started)
- [Reproducible Builds](https://docs.readthedocs.io/en/stable/guides/reproducible-builds.html)
- [pip-tools](https://pip-tools.readthedocs.io/en/latest/)
- [sphinx](https://www.sphinx-doc.org/en/master/tutorial/getting-started.html#setting-up-your-project-and-development-environment)
- [Read the Docs Sphinx Theme](https://sphinx-rtd-theme.readthedocs.io/en/stable/)
- Pushes on `main` will trigger rebuilds at for [Project Documenation](https://jdcast-rsp-final-project.readthedocs.io/en/latest/index.html#)
- To View Locally:
  - cd `docs/source`
  - `sphinx-build -b html . ../build/html/`
  - point browser to `build/html/index.html`
