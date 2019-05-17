#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>

//robot pose
float odom_x = 0.0;
float odom_y = 0.0;
//pick up pose in map coordinate
float pickup_x = -7.64;
float pickup_y = 1.86;
float pickup_w = 1.0;
//drop down pose in map coordinate
float dropdown_x = -4.96;
float dropdown_y = 0.85;
float dropdown_w = 1.0;

// callback funtion to subcribe odometry
void sub_odom(const nav_msgs::Odometry::ConstPtr &msg)
{
    odom_x = msg->pose.pose.position.x;
    odom_y = msg->pose.pose.position.y;
    ROS_INFO("odometry data received");	
}




int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odom_sub = n.subscribe("/odom", 1, sub_odom);
  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;
  bool is_Loaded = false;
  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = pickup_x;
    marker.pose.position.y = pickup_y;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = pickup_w;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.25;
    marker.scale.y = 0.25;
    marker.scale.z = 0.25;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.3f;
    marker.color.g = 0.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN("Please create a subscriber to the marker");
      sleep(1);
    }
    ros::spinOnce();
    ROS_INFO("odom_x is %f, odom_y is %f", odom_x, odom_y);
    if (((odom_x<-1.01+0.2) && (odom_x>-1.01-0.2))&&((odom_y<2.85+0.2)&&(odom_y>2.85-0.2)))//if robot reaches drop down zone
    {
      is_Loaded = false;
      marker.pose.position.x = dropdown_x;
      marker.pose.position.y = dropdown_y;
      //marker.pose.position.z = 0;
      //marker.pose.orientation.x = 0.0;
      //marker.pose.orientation.y = 0.0;
      //marker.pose.orientation.z = 0.0;
      marker.pose.orientation.w = dropdown_w;
      //marker.scale.x = 0.25;
      //marker.scale.y = 0.25;
      //marker.scale.z = 0.25;
      //marker.color.r = 0.5f;
      //marker.color.g = 0.0f;
      //marker.color.b = 0.0f;
      marker.color.a = 1.0;
      marker_pub.publish(marker);
      sleep(5);
      ROS_INFO("Droped down!(set drop down point)");
      
    }else if ((((odom_x<1.31+0.2) && (odom_x>1.31-0.2))&&((odom_y<1.29+0.2)&&(odom_y>1.29-0.2)))||is_Loaded)//if robot reaches pick up zone or it is already load the cube
    {
      is_Loaded = true;
      marker.color.a = 0.0;
      marker_pub.publish(marker);
      sleep(5);
      ROS_INFO("Picked up!(hide pick up point)");
 
      
    }else 
    {
      marker_pub.publish(marker);
      ROS_INFO("set pick up point");
      sleep(5);
    }
      r.sleep();
  }
}
