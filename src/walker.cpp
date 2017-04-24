#include <vector>
#include "ros/ros.h"
#include "walker.h"


/**
 * Checks to see if avg values in ranges is below the provided threshold
 * or if the min seen is half the value of the min_dist
 */
bool closeToObstacle(std::vector<float> ranges, float distance) {

  for (float curPos : ranges) {
    if (curPos < distance) {
      return true;
    }
  }
  return false;
}

Walker::Walker(ros::NodeHandle nh) {
  movement = 0;
  pub = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1000);
  ros::Subscriber sub = nh.subscribe("scan", 500, &Walker::getLaserData, this);
  ros::spin();

}

void Walker::getLaserData(const sensor_msgs::LaserScan::ConstPtr& scan) {
 if(movement == 2){
   vel.angular.z = 0.0;
 }
  if (closeToObstacle(scan->ranges, 0.5)) {
    stopRobot();
    ROS_INFO("%s", " close ");

    turn();

    stopRobot();
  } else {
    vel.linear.x = 0.3;
    pub.publish(vel);
    //ROS_DEBUG_STREAM("moving forward by: " << movement << " for time " << vel.linear.z);
    ROS_INFO("%d", movement);


    if(++movement > 50){
      ROS_INFO("%s", " greater than 50 ");

      stopRobot();
      turn();
      movement = 0;
     }
  }
}


void Walker::stopRobot() {
  vel.angular.x = 0;
  vel.angular.y = 0;
  vel.angular.z = 0;
  vel.linear.x = 0;
  vel.linear.y = 0;
  vel.linear.z = 0;
  pub.publish(vel);
}

void Walker::turn() {
  stopRobot();
  vel.angular.z = 1.0;
  vel.linear.x = 0.3;
  pub.publish(vel);
 // vel.angular.z = 0.0;

}


int main(int argc, char **argv) {
  ros::init(argc, argv, "walker");
  ros::NodeHandle n;
  Walker walker(n);

  return 0;
}
