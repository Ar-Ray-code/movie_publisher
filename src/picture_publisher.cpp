#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char** argv) {
	ros::init (argc, argv, "camera");
	ros::NodeHandle nh("~"); 

	std::string name;
	nh.getParam("pictureName",name);

	image_transport::ImageTransport it(nh);
	image_transport::Publisher image_pub = it.advertise("color/image_raw", 10);
    // ROS_INFO(name.c_str());
	cv::Mat image = cv::imread(name.c_str());

	if (image.empty() == true) {
		ROS_INFO("failed to open picture.");
		return -1;
	}
	ros::Rate looprate (10); // capture image at 10Hz
	while(ros::ok()) {
		sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
		image_pub.publish(msg);
		ros::spinOnce();
		looprate.sleep();
	}
	return 0;
}
