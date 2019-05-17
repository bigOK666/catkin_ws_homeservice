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
## Contents
### Used ros pkgs
### Modified files
