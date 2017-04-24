##Walker
This Project is a Simulation of how the iRobot Roomba works. A turtlebot model that can be found at  [Turtlbot](http://wiki.ros.org/Robots/TurtleBot) that is used  within Gazebo to show a working  algoirthm. The algorithm that the turtle bot uses is go forward until it's laser scanner is too close to an obstacle then turn and repeat. This will alow the turtlebt to go on a random walk within the environment.


##Instalation
While in a terminal run this command. 
```
- sudo apt-get install ros-indigo-turtlebot-gazebo ros-indigo-turtlebot-apps ros-indigo-turtlebot-rviz-launchers
- cd <PATH_TO_YOUR_DIRECTORY>
- mkdir -p catkin_ws/src
- cd catkin_ws
- catkin_make
- source devel/setup.bash
```

##Building 
To build this project run this command at the catkin_ws root directory
```
- catkin_make
```

##Launching
To run this project run the commands below:
```
- roslaunch walker walker.launch record:=true
- roslaunch walker walker.launch record:=false
```

##Recording 
rosbag is a tool that allows the recording of node events it an be launched using the following command.
```
- roslaunch walker walker.launch record:=true
```





