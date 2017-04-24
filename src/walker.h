#ifndef SRC_WALKER_H_
#define SRC_WALKER_H_

#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

/*
*@brief This class handles the functions needed to perform a random walk.
*/
class Walker {
 private:
  ros::NodeHandle n;
  ros::Publisher pub;
  geometry_msgs::Twist vel;
  int movement;

 public:
  /**
   * @brief Constructor that initializes node, and class values.
   * @param Nh standard node object.
   */
   Walker(ros::NodeHandle nh);

   /**
    *@brief getLaserData gets laser data and turn on the z axis if an obstacle is close.
    *@param sensor_msgs::LaserScan::ConstPtr& scan
    */
  void getLaserData(const sensor_msgs::LaserScan::ConstPtr& scan);

  void walk();
  /**
   *@brief getLaserData gets laser data and turn on the z axis if an obstacle is close.
   *@param sensor_msgs::LaserScan::ConstPtr& scan
  */
  void setRobotVelocity(geometry_msgs::Twist vel);
  /**
   *@brief Stops Robot Motion
   *
   */
  void stopRobot();

  /**
     *@brief Turns on Z-axis
    */
  void turn();


  /**
  *@brief get twist velocity for current position.
  */
  geometry_msgs::Twist  getRobotVelocity();

};

#endif
