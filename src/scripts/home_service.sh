#!/bin/sh
xterm -e " source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch;bash" &

sleep 5

xterm -e " source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch;bash" &

sleep 5

xterm -e " source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch;bash" &

sleep 5

xterm -e " source /home/workspace/catkin_ws/devel/setup.bash; rosrun pick_objects pick_objects;bash" &

sleep 1

xterm -e " source /home/workspace/catkin_ws/devel/setup.bash; rosrun add_markers add_markers;bash"
