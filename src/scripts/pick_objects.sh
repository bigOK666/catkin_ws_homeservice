#!/bin/sh
xterm -e " source /home/kevin/workspace/catkin_ws_homeservice/devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch;bash" &

sleep 5

xterm -e " source /home/kevin/workspace/catkin_ws_homeservice/devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch;bash" &

sleep 5

xterm -e " source /home/kevin/workspace/catkin_ws_homeservice/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch;bash" &

sleep 5

xterm -e " source /home/kevin/workspace/catkin_ws_homeservice/devel/setup.bash; rosrun pick_objects pick_objects;bash"
