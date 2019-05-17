# catkin_ws_homeservice

## How to use it

First thing is to build the workspace on your playground:)
```
git clone https://github.com/zerenlu/catkin_ws_homeservice.git
cd catkin_ws_homeservice
rm -r build devel
cd ..
mv catkin_ws_homeservice catkin_ws
cd catkin_ws
catkin_make
source devel/setup.bash
```
Then you are good to play it:
* test slam using script `test_slam.sh`
  ```
  cd src/scripts
  ./test_slam.sh
  ```
  use the `turtlebot_teleop` to control the robot to mapping the environment
* test navigation using script `test_navigation.sh`
  ```
  cd src/scripts
  ./test_navigation.sh
  ```
  use _2D Nav Goal_ to set goals in _Rviz_
* perform pick objects functionality using `pick_objects.sh`
  ```
  cd src/scripts
  ./pick_objects.sh
  ```
  the robot will reach the first goal, rest for 5 seconds and then go to the second goal. Status information will be printed in console
* performe home service robot functionality using `home_service.sh`
  ```
  cd src/scripts
  ./home_service.sh
  ```  
  the robot will go to pick up zone for 5 seconds to pick up the cube in pick up zone. Then the robot carry the cube to drop down zone and drop the cube down
* add markers in Rviz using `add_markers.sh`. But `add_markers_showANDhide.cpp` must be compiled first. Change the name of `add_markers_showANDhide.cpp` to `add_markers.cpp` then 
  ```
  catkin_make
  source devel/setup.bash
  cd src/scripts
  ./add_markers.sh
  ```
  a cube will be shown in pick up zone for 5 seconds. Then disappear for 5 seconds. At last be shown in dropdown zone for 5 seconds
  
## Contents
### Used ros pkgs
* `slam_gmapping` is used for slam mapping.
* `turtlebot` is used for drive the robot.
* `turtlebot_interactions` is used for visulize in Rviz.
* `turtlebot_simulator` is used for load the robot and environments in gazebo world and perform amcl localization.
### Modified files
* `/src/turtlebot_interactions/turtlebot_rviz_launchers/rviz/navigation.rviz` subcribes visulization_marker topic now to show markers.
* `/src/turtlebot_simulator/turtlebot_gazebo/launch/amcl_demo.launch` loads new _map.yaml_ file from `/src/map/map.yaml`
 and changes initial pose of the robot.
* `/src/turtlebot_simulator/turtlebot_gazebo/launch/includes/kobuki.launch.xml` changes robot pose.
* `/src/turtlebot_simulator/turtlebot_gazebo/launch/turtlebot_world.launch` loads new world file frome `/src/map/home.world`.
