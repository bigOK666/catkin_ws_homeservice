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
* test slam using script ```test_slam.sh```
  ```
  cd src/scripts
  ./test_slam.sh
  ```
  use the ```turtlebot_teleop``` to control the robot to mapping the environment
* test navigation using script ```test_navigation.sh```
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
* 
## Contents
### Used ros pkgs
### Modified files
